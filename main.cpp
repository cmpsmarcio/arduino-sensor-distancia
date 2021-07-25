/*
    Projeto codificado no Tinkercad
*/

#include <LiquidCrystal.h>

const int ledRed = 5;
const int ledYellow = 4;
const int ledGreen = 3;
const int pinTrig = 7;
const int pinEcho = 6;
const int buzzer = 2;

LiquidCrystal lcd(13, 11, 10, 9, 8, 12);

void setup()
{
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, LOW);
  
  digitalWrite(buzzer, LOW);
  
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);
  
  int distancia = pulseIn(pinEcho, HIGH);
  int cm = int (distancia * 0.01723);
  
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(cm / 100.0);
  
  lcd.setCursor(0, 0);
  
  if (cm < 3)
  {
    lcd.print("BATEU!! :(");
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYellow, HIGH);
    delay(1000);
  }
  else if (cm < 20)
  {
    lcd.print("Ei! vai bater!");
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledYellow, LOW);
    
    digitalWrite(buzzer, HIGH);
    
    digitalWrite(ledRed, HIGH);
    delay(100);
    digitalWrite(ledRed, LOW);
  } 
  else if (cm < 100)
  {
    lcd.print("Muito Perto");
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, HIGH);
    
    delay(1000);
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledYellow, LOW);
  } 
  else 
  {
    lcd.print("Distancia Segura");
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledRed, LOW);
  }
  
  delay(1000);
}