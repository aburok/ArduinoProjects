/*
*  LCM1602 & Arduino Uno
*  VCC - > 5 V
*  GND - GND
*  SCL -> A5
*  SDA -> A4
*/

#include <Wire.h>   // standardowa biblioteka Arduino
#include <LiquidCrystal_I2C.h> // dolaczenie pobranej biblioteki I2C dla LCD

#include <Stepper.h>

#include <Timer.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Ustawienie adresu ukladu na 0x27

 int joyPin1 = 0;                 // slider variable connecetd to analog pin 0
 int joyPin2 = 1;                 // slider variable connecetd to analog pin 1
  int value1 = 0;                  // variable to read the value from the analog pin 0
 int value2 = 0;                  // variable to read the value from the analog pin 1

 #define motorPin1 8
 #define motorPin2 9
 #define motorPin3 10
 #define motorPin4 11

 #define STEPS_PER_MOTOR_REVOLUTION 32
 #define STEPS_PER_MOTOR_AND_GEAR_REVOLUTION 32 * 64

const int stepsPerRevolution = 200;

 Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);


void setup()  
{
  lcd.begin(16,2);   // Inicjalizacja LCD 2x16
  
  lcd.backlight(); // zalaczenie podwietlenia 
  lcd.setCursor(0,0); // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna)
  lcd.print("Dawid Korub1a!");
  delay(500);
  lcd.setCursor(0,1); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
  lcd.print("Hello World");

  Serial.begin(9600);

}

void loop() 
{
   value1 = analogRead(joyPin1);  
   delay(100); 
   value2 = analogRead(joyPin2);   
   delay(100);
//   digitalWrite(ledPin, HIGH);           
//  delay(value1);
//  digitalWrite(ledPin, LOW);
//  delay(value2);
  lcd.clear();

   int motorSpeed = map(value1, 0, 1023, 0, 500);

if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution / 100);
  }
  
  Serial.print('J - value1 = ');
  Serial.print(value1);
  Serial.print(", treatValue = ");
  Serial.print(treatValue(value1));
  
  
  lcd.setCursor(0,0); // Ustawienie kursora w pozycji 0,0 (pierwszy wiersz, pierwsza kolumna)
  lcd.print("X - ");
  lcd.print(treatValue(value1));
  
  Serial.println(treatValue(value2));
  Serial.println(value2);
   lcd.setCursor(0,1); //Ustawienie kursora w pozycji 0,0 (drugi wiersz, pierwsza kolumna)
  lcd.print("Y - ");
  lcd.print(treatValue(value2));
  delay(500);
}

 int treatValue(int data) {
  return (data * 9 / 1024) + 48;
 }
