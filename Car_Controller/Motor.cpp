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
    leftServo.writeMicroseconds(leftWheelGoSpeed);
    rightServo.writeMicroseconds(rightWheelGoSpeed);
    // must add delay to methods like these
    delay(100);
  }

  void Motor::brake()
  {
    leftServo.writeMicroseconds(leftWheelStopSpeed);
    rightServo.writeMicroseconds(rightWheelStopSpeed);

    delay(100);
  }

  void Motor::reverse()
  {
    leftServo.writeMicroseconds(leftWheelReverseSpeed);
    rightServo.writeMicroseconds(rightWheelReverseSpeed);

    delay(100);
  }

  void Motor::turnLeft()
  {
    leftServo.writeMicroseconds(leftWheelStopSpeed);
    rightServo.writeMicroseconds(rightWheelGoSpeed);

    delay(100);
  }

  void Motor::turnRight()
  {
    leftServo.writeMicroseconds(leftWheelGoSpeed);
    rightServo.writeMicroseconds(rightWheelStopSpeed);

    delay(100);
  }