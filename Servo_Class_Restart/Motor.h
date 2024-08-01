#ifndef MOTOR_H
#define MOTOR_H

#include <Servo.h>
#include <Arduino.h>

class Motor
{
private:
  byte _pinLeft;
  byte _pinRight;
  Servo leftServo;
  Servo rightServo;

  // must add values here in here instead of cpp file to properly intitialise it for the R4 Board
  const unsigned long leftWheelGoSpeed = 2300;
  const unsigned long rightWheelGoSpeed = 2300;

  const unsigned long leftWheelStopSpeed = 1500;
  const unsigned long rightWheelStopSpeed = 1500;

  const unsigned long leftWheelReverseSpeed = 700;
  const unsigned long rightWheelReverseSpeed = 700;

public:

  Motor() {}

  Motor(byte leftPin, byte rightPin);

  void init();

  void accelerate();

  void brake();

  void reverse();

};
#endif