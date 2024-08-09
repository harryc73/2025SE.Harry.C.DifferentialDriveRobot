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
  const unsigned int leftWheelGoSpeed = 1600;
  const unsigned int rightWheelGoSpeed = 1400;

  const unsigned int leftWheelStopSpeed = 1500;
  const unsigned int rightWheelStopSpeed = 1500;

  const unsigned int leftWheelReverseSpeed = 1400;
  const unsigned int rightWheelReverseSpeed = 1600;

  unsigned long lastTimeGo;
  unsigned long goDelay;

public:

  Motor() {}

  Motor(byte leftPin, byte rightPin);

  Motor(byte leftPin, byte rightPin, unsigned long goDelay);

  void init();

  void accelerate();

  void brake();

  void reverse();

  void turnRight();

  void turnLeft();

};
#endif