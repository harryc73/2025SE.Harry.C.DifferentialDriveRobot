#include "Motor.h"
#include <Servo.h>


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
    // must add delay to methods like these
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