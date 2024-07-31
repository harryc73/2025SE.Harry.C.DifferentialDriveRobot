#include <Arduino.h>
#include "Servo.h"
#include "MotorControl.h"

MotorControl::MotorControl()
{
  // setting the different speeds
  const unsigned int leftWheelGoSpeed = 2300;
  const unsigned int rightWheelGoSpeed = 2300;

  const unsigned int leftWheelStopSpeed = 1500;
  const unsigned int rightWheelStopSpeed = 1500;

  // starting the ardunio board
  Serial.begin(9600);
  Serial.println("Debug Serial Monitor");
}

void MotorControl::init()
{
  leftServo.attach(LEFT_SERVO_PIN, 700, 2300);
  rightServo.attach(RIGHT_SERVO_PIN, 700, 2300);
}

void MotorControl::accelerate()
{
  leftServo.writeMicroseconds(leftWheelGoSpeed);
  rightServo.writeMicroseconds(rightWheelGoSpeed);
}

void MotorControl::brake()
{
  leftServo.writeMicroseconds(leftWheelStopSpeed);
  rightServo.writeMicroseconds(rightWheelStopSpeed);
}