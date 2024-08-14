#include "Motor.h"
#include <Servo.h>


Motor::Motor(byte leftPin, byte rightPin)
  {
    this->_pinLeft = leftPin;
    this->_pinRight = rightPin;
    goDelay = 100;
    lastTimeGo = 0;
    leftSpeed = leftWheelStopSpeed;
    rightSpeed = rightWheelStopSpeed;
  }


Motor::Motor(byte leftPin, byte rightPin, unsigned long goDelay)
  {
    this->_pinLeft = leftPin;
    this->_pinRight = rightPin;
    this->goDelay = goDelay;
    lastTimeGo = 0;
    leftSpeed = leftWheelStopSpeed;
    rightSpeed = rightWheelStopSpeed;
  }

  void Motor::init()
  {
    leftServo.attach(_pinLeft, 700, 2300);
    rightServo.attach(_pinRight, 700, 2300);
  }


  void Motor::setMotors(unsigned int leftSpeed, unsigned int rightSpeed)
  {
    this->leftSpeed = leftSpeed;
    this->rightSpeed = rightSpeed;
  }

  void Motor::update()
  {
    unsigned long currentTime = millis();
    if (currentTime - lastTimeGo >= goDelay)
    {
      leftServo.writeMicroseconds(leftSpeed);
      rightServo.writeMicroseconds(rightSpeed);
      lastTimeGo = currentTime;
  }
  }

  void Motor::accelerate()
  {
    setMotors(leftWheelGoSpeed, rightWheelGoSpeed);
  }

  void Motor::brake()
  {
    setMotors(leftWheelStopSpeed, rightWheelStopSpeed);
  }

  void Motor::reverse()
  {
    setMotors(leftWheelReverseSpeed, rightWheelReverseSpeed);
  }

  void Motor::turnLeft()
  {
    setMotors(leftWheelStopSpeed, rightWheelTurnSpeed);
  }

  void Motor::turnRight()
  {
    setMotors(leftWheelTurnSpeed, rightWheelStopSpeed);
  }

  void Motor::sharpTurnRight()
  {
    setMotors(leftWheelTurnSpeed, rightWheelReverseSpeed);
  }

  void Motor::sharpTurnLeft()
  {
    setMotors(leftWheelReverseSpeed, rightWheelTurnSpeed);
  }

  unsigned long Motor::getGoDelay()
  {
    return goDelay;
  }