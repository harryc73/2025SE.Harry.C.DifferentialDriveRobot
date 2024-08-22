#include "LineSensor.h"

// if they both on the line both the analog 31 for left, 32 for right
//If the left is off the line it sits at 31-31, and right sits above 40
// if the right is off the line it sits at 31-32, and left is above 40

LineSensor::LineSensor(byte leftPin, byte rightPin)
{
  this->_leftPin = leftPin;
  this->_rightPin = rightPin;
}

void LineSensor::init()
{
  pinMode(_leftPin, INPUT);
  pinMode(_rightPin, INPUT);
  }

int LineSensor::readLeftState()
{
  leftState = analogRead(_leftPin);
  return leftState;
}

int LineSensor::readRightState()
{
  rightState = analogRead(_rightPin);
  return rightState;
}


void LineSensor::readState()
{
  leftState = analogRead(_leftPin);
  rightState = analogRead(_rightPin);
}

//void LineSensor::readState()
//{
  //leftState = analogRead(_leftPin);
  //rightState = analogRead(_rightPin);
//}




bool LineSensor::onLine()
{
  //readState()
  return (leftState < ValThreshold) && (rightState < ValThreshold);
}

bool LineSensor::onLeftLine()
{
  //readState()
  return (leftState > ValThreshold) && (rightState < ValThreshold);
}

bool LineSensor::onRightLine()
{
  //readState()
  return (leftState < ValThreshold) && (rightState > ValThreshold);
}