#include "Motor.h"
#include <Servo.h>


Motor::Motor(byte leftPin, byte rightPin)
  {
    this->_pinLeft = leftPin;
    this->_pinRight = rightPin;
    goDelay = 200;
  }


Motor::Motor(byte leftPin, byte rightPin, unsigned long goDelay)
  {
    this->_pinLeft = leftPin;
    this->_pinRight = rightPin;
    lastTimeGo = millis();
    this->goDelay = goDelay;
  }

  void Motor::init()
  {
    leftServo.attach(_pinLeft, 700, 2300);
    rightServo.attach(_pinRight, 700, 2300);
  }

  void Motor::accelerate()
  {
  unsigned long timeNow = millis();
  if (timeNow - lastTimeGo >= goDelay) {
    lastTimeGo = timeNow;
    leftServo.writeMicroseconds(leftWheelGoSpeed);
    rightServo.writeMicroseconds(rightWheelGoSpeed);
    }
  }

  void Motor::brake()
  {
  unsigned long timeNow = millis();
  if (timeNow - lastTimeGo >= goDelay) {
    lastTimeGo = timeNow;
    leftServo.writeMicroseconds(leftWheelStopSpeed);
    rightServo.writeMicroseconds(rightWheelStopSpeed);
    }
  }

  void Motor::reverse()
  {
  unsigned long timeNow = millis();
  if (timeNow - lastTimeGo >= goDelay) {
    lastTimeGo = timeNow;
    leftServo.writeMicroseconds(leftWheelReverseSpeed);
    rightServo.writeMicroseconds(rightWheelReverseSpeed);
    }
  }

  void Motor::turnLeft()
  {
  unsigned long timeNow = millis();
  if (timeNow - lastTimeGo >= goDelay) {
    lastTimeGo = timeNow;
    leftServo.writeMicroseconds(leftWheelStopSpeed);
    rightServo.writeMicroseconds(rightWheelGoSpeed);
    }
  }

  void Motor::turnRight()
  {
  unsigned long timeNow = millis();
  if (timeNow - lastTimeGo >= goDelay) {
    lastTimeGo = timeNow;
    leftServo.writeMicroseconds(leftWheelGoSpeed);
    rightServo.writeMicroseconds(rightWheelStopSpeed);
    }
  }

  unsigned long Motor::getGoDelay()
  {
    return goDelay;
  }