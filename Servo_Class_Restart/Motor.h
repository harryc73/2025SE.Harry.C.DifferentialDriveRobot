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

  const unsigned long leftWheelGoSpeed;
  const unsigned long rightWheelGoSpeed;

  const unsigned long leftWheelStopSpeed;
  const unsigned long rightWheelStopSpeed;

  const unsigned long leftWheelReverseSpeed;
  const unsigned long rightWheelReverseSpeed;

public:

  Motor() {}

  Motor(byte leftPin, byte rightPin);

  void init();

  void accelerate();

  void brake();

  void reverse();

};
#endif