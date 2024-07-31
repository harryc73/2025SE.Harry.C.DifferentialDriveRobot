#ifndef MOTOR_H
#define MOTOR_H

#include <Servo.h>
#include <Arduino.h>

class Motor
{
private:
  byte _pin;
  Servo _servo;
public:

  Motor() {}

  Motor(byte pin);

  void init();

  void accelerate();

  void brake();

  void reverse();

};
#endif