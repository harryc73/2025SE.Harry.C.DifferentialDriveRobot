#include "LineSensor.h"
#include "Motor.h"
#include "CarController.h"
#include "LedArray.h"
#include <Servo.h>

#define LEFT_SERVO_PIN 9
#define RIGHT_SERVO_PIN 10

#define LEFT_LINE_PIN 2
#define RIGHT_LINE_PIN 3

static const char* VersionNum = "V03.00.00";

LineSensor lineSensor(LEFT_LINE_PIN, RIGHT_LINE_PIN);
Motor motor(LEFT_SERVO_PIN, RIGHT_SERVO_PIN);
LedArray VersionStatus(VersionNum);
CarController carController(&lineSensor, &motor, &VersionStatus);


void setup() {
  carController.init();
}

void loop() {
  carController.followLine();
}