#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 LCD(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#define trigPin 2 //Sensor Echo pin connected to Arduino pin 13
#define echoPin 3 //Sensor Trip pin connected to Arduino pin 12
void setup() 
{  
LCD.begin(16, 2);  // initialize the lcd
LCD.setBacklight(255);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(12, OUTPUT);
 digitalWrite(  12, LOW);   // turn the LED on (HIGH is the voltage level)
 Serial.begin(9600);
}

void loop() 
{
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
LCD.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
LCD.print("WATER LEVEL: ");  //Print Message on First Row

LCD.setCursor(13,0);  //Set LCD cursor to upper left corner, column 0, row 0
LCD.print("   ");  //Print Message on First Row
LCD.setCursor(13,0);  //Set LCD cursor to upper left corner, column 0, row 0
LCD.print(distance);  //Print Message on First Row
  if(distance>8)
  {
  digitalWrite( 12, LOW);   // turn the LED on (HIGH is the voltage level
  }
  else
  if(distance<=5 )
  {
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  }
  delay(250); //pause to let things settle  
  }
