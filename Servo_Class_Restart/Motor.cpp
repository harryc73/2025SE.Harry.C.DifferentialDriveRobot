#include "Motor.h"
#include <Servo.h>

const unsigned long leftWheelGoSpeed = 2300;
const unsigned long rightWheelGoSpeed = 2300;

const unsigned long leftWheelStopSpeed = 1500;
const unsigned long rightWheelStopSpeed = 1500;

const unsigned long leftWheelReverseSpeed = 700;
const unsigned long rightWheelReverseSpeed = 700;


Motor::Motor(byte leftPin, byte rightPin)
  {
    this->_pinLeft = leftPin;
    this->_pinRight = rightPin;
  }

  void Motor::init()
  {
    leftServo.attach(_pinLeft, 700, 2300);
    rightServo.attach(_pinRight, 700, 2300);
  }

  void Motor::accelerate()
  {
    leftServo.writeMicroseconds(rightWheelGoSpeed);
    rightServo.writeMicroseconds(leftWheelGoSpeed);
  }

  void Motor::brake()
  {
    leftServo.writeMicroseconds(leftWheelStopSpeed);
    rightServo.writeMicroseconds(rightWheelStopSpeed);
  }

  void Motor::reverse()
  {
    leftServo.writeMicroseconds(leftWheelReverseSpeed);
    rightServo.writeMicroseconds(rightWheelReverseSpeed);
  }