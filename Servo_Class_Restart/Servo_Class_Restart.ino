#define SERVO_PIN 11
#include <Servo.h>
#include "Motor.h"

Motor motor(SERVO_PIN);


void setup() {
  motor.init();
}

void loop() {
  motor.accelerate();
  delay(100);
  motor.brake();
  delay(100);
  motor.reverse();
  delay(100);
}
