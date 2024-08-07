<<<<<<< Updated upstream
#include "LineSensor.h"
#include "Motor.h"
#include "CarController.h"

#include <Servo.h>

#define LEFT_SERVO_PIN 10
#define RIGHT_SERVO_PIN 9

#define LEFT_LINE_PIN 12
#define RIGHT_LINE_PIN 13

LineSensor lineSensor(LEFT_LINE_PIN, RIGHT_LINE_PIN);

Motor motor(LEFT_SERVO_PIN, RIGHT_SERVO_PIN);

CarController carController(lineSensor, motor);
=======
#include "CarController.h"
#include "LineSensor.h"
#include "Motor.h"

#define LEFT_SERVO_PIN 
>>>>>>> Stashed changes

void setup() {
  motor.init();
  lineSensor.init();
}

void loop() {
  carController.followLine();
}
