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

  unsigned int leftSpeed;
  unsigned int rightSpeed;

  // must add values here in here instead of cpp file to properly intitialise it for the R4 Board
  // 1500 is stop
  // Right: above 1500 is reverse and below 1500 is accelerate
  // Left: above 1500 is accelrate and below 1500 is reverse
  const unsigned int leftWheelGoSpeed = 1520;
  const unsigned int rightWheelGoSpeed = 1490;

  const unsigned int leftWheelStopSpeed = 1500;
  const unsigned int rightWheelStopSpeed = 1500;

  const unsigned int leftWheelReverseSpeed = 1300;
  const unsigned int rightWheelReverseSpeed = 1680;

  const unsigned int leftWheelSlowReverseSpeed = 1480;
  const unsigned int rightWheelSlowReverseSpeed = 1510;

  const unsigned int leftWheelTurnSpeed = 1680;
  const unsigned int rightWheelTurnSpeed = 1330;
  

  unsigned long lastTimeGo;
  unsigned long goDelay;

  void setMotors(unsigned int leftSpeed, unsigned int rightSpeed); // this assigns the values to be passed to the update method

public:

  Motor() {}

  Motor(byte leftPin, byte rightPin);

  Motor(byte leftPin, byte rightPin, unsigned long goDelay);

  unsigned long getGoDelay();

  void init();

  void update(); 

  void accelerate();

  void brake();

  void reverse();

  void turnRight();

  void turnLeft();

  void sharpTurnLeft();

  void sharpTurnRight();

  void slowReverse();

};

#endif