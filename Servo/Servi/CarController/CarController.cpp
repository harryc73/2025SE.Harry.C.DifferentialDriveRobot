#include <Arduino.h>
#include "Servo.h"
#include "CarController.h"

CarController::CarController()
{
  // setting the different speeds
  const unsigned int leftWheelGoSpeed = 180;
  const unsigned int rightWheelGoSpeed = 180;
  const unsigned int leftWheelStopSpeed = 90;
  const unsigned int rightWheelStopSpeed = 90;

  // starting the ardunio board
  Serial.begin(9600);
  Serial.println("Debug Serial Monitor");
}

void CarController::init()
{
  leftServo.attach(LEFT_SERVO_PIN);
  rightServo.attach(RIGHT_SERVO_PIN);
}

void CarController::accelerate()
{
  leftServo.write(leftWheelGoSpeed);
  rightServo.write(rightWheelGoSpeed);
}

void CarController::brake()
{
  leftServo.write(leftWheelStopSpeed);
  rightServo.write(rightWheelStopSpeed);
}