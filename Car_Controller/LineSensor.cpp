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

byte LineSensor::readLeftState()
{
  leftState = digitalRead(_leftPin);
  return leftState;
}

byte LineSensor::readRightState()
{
  rightState = digitalRead(_rightPin);
  return rightState;
}


byte LineSensor::readState()
{
  leftState = digitalRead(_leftPin);
  rightState = digitalRead(_rightPin);
}

bool LineSensor::isLeftLine()
{
  readState();
  if(leftState == HIGH)
    return true;
  else
    return false;
}

bool LineSensor::isRightLine()
{
  readState();
  if(rightState == HIGH)
    return true;
  else
    return false;
}


String LineSensor::getState()
{
  readState();

  String state = "Left: "; // String so it can be a string

  if(leftState == HIGH)
    state += "No Line Detected";
  else
    state += "Line Detected";

  state += " Right: ";
  
  if(rightState == HIGH)
    state += "No Line Detected";
  else
    state += "Line Detected";
  
  return state;
}