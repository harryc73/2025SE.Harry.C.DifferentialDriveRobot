#include <Servo.h>
#include "motorControl.h"

#define LEFT_SERVO_PIN 9
#define RIGHT_SERVO_PIN 10 


MotorControl motorControl;

void setup() {
  motorControl.init();
}

void loop() {
  motorControl.accelerate();
  delay(500);
  motorControl.brake();
  delay(500);
}
