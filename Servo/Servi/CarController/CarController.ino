#include <Servo.h>
#include "CarController.h"

#define LEFT_SERVO_PIN 9
#define RIGHT_SERVO_PIN 10 


CarController carController;

void setup() {
  carController.init();
}

void loop() {
  carController.accelerate();
  delay(500);
  carController.brake();
  delay(500)
}
