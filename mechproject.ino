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

// create a display object of type TM1637Display
TM1637Display display = TM1637Display(CLK,DIO);

int count = 0; // Object counter
bool objectPreviouslyDetected = false; // To avoid multiple counts for one object 
void setup() {
  display.clear();
  display.setBrightness(7); // set the brightness to 7 (0:dimmest, 7:brightest)
  pinMode(IRSensor, INPUT); //IR Sensor pin INPUT
 
}

void loop() {
  int sensorStatus = digitalRead(IRSensor); // Read IR Sensor
  if (sensorStatus == LOW && !objectPreviouslyDetected) 
  { 
    count++; // Increment count when object is detected
    objectPreviouslyDetected = true;
    display.showNumberDec(count,false); //display count
    delay(500); // Short delay to debounce
  }
  else if (sensorStatus==HIGH) {
    objectPreviouslyDetected=false; //Reset Detection state

  }
   // To prevent overflow ( ensures count stays within 0-9999) range
   if (count > 9999) {
    count = 0;
   }
}
