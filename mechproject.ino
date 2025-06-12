
// Group members: Horecia Williams, Balvayne Fearon, and Daniel Bhagwandin
// Date: June 11,2025
// Course: MECH156
// The purpose of this program is to make a seven segment display count up to 9999, detect object passing using IR sensors. and 
// counts objects passing the IR sensor.

#include <TM1637Display.h> // if <> does not work use ""
// Define the connections to pins
#define CLK 11 //seven segment clock
#define DIO 10 //seven segment data
#define IRSensor 9 //IR pin
#define LED 8 //LED pin
// create a display object of type TM1637Display
TM1637Display display = TM1637Display(CLK,DIO);

int i = 0; //counter
void setup() {
  display.clear();
  display.setBrightness(7); // set the brightness to 7 (0:dimmest, 7:brightest)
  pinMode(IRSensor, INPUT); //IR Sensor pin INPUT
  pinMode(LED,OUTPUT);
}

void loop() {
  int sensorStatus = digitalRead(IRSensor); // Set the GPIO as Input
  if (sensorStatus ==1) //Check if the pin is high or not
  { 
    //if the pin is high turn off the  onboard led
    digitalWrite (LED,LOW); //LED high
  }
  else  {
    i = i + 1 ;  // increment the counter value when an oject detected
    //else turn off the onboard LED
    digitalWrite(LED,HIGH); //LED LOW
    delay(1000);
  }
}