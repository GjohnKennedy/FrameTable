/* Stepper Motor Control */

#include <Stepper.h>
const int stepsPerRevolution = 19080;
// change this to fit the number of steps per revolution
// for your motor
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 2, 3, 4, 5);
String steps;
int steps_to_int;
void setup() {
  // set the speed at 60 rpm:

  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution in one direction:
  if (Serial.available() > 0)
  {
    steps = Serial.readString();
    steps_to_int = steps.toInt();
    Serial.println(steps_to_int);
    myStepper.setSpeed(2);
    myStepper.step(steps_to_int);
  }
}
