// Name: Horecia Williams
// Date: June 18, 2025
// This program will power a DC motor and will only work at the press on one of 2 buttons, the first button will enable the motor to move forward 
// and the second button will move it forward, additionally, the speed can be controlled using the "fixedSpeed" variable in the arduino program. In short the
// purpose is to control speed and direction of a DC Motor.


// declare variables
const int forwardPin = 8; 
const int backwardPin = 12;
const int enablePin = 11;      // EN2 pin on L293DNE
const int delayTime = 1000;
const int but1pin = 2;
const int but2pin = 3;

int but1;
int but2;
const int fixedSpeed = 200;    // Speed value from 0 to 255

void setup() {
  pinMode(forwardPin, OUTPUT);
  pinMode(backwardPin, OUTPUT);
  pinMode(enablePin, OUTPUT);

  pinMode(but1pin, INPUT_PULLUP); // INPUT_PULLUP Used so there's no need for a resistor
  pinMode(but2pin, INPUT_PULLUP); 
}

void loop() {
  but1 = digitalRead(but1pin);
  but2 = digitalRead(but2pin);

  if (but1 == LOW) {  // Button 1 pressed -> Forward
    digitalWrite(forwardPin, HIGH);
    digitalWrite(backwardPin, LOW);
    analogWrite(enablePin, fixedSpeed);
  }
  else if (but2 == LOW) {  // Button 2 pressed -> Backward
    digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, HIGH);
    analogWrite(enablePin, fixedSpeed);
  }
  else {  // No button pressed -> stop motor
    analogWrite(enablePin, 0);  // No power to motor
    digitalWrite(forwardPin, LOW);
    digitalWrite(backwardPin, LOW);
  }
}
