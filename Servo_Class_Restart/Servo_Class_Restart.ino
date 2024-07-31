#define LEFT_SERVO_PIN 9
#define RIGHT_SERVO_PIN 10
#include <Servo.h>
#include "Motor.h"

Motor motor(LEFT_SERVO_PIN, RIGHT_SERVO_PIN);

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