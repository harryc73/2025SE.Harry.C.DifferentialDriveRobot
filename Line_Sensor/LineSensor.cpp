#include "LineSensor.h"

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


byte LineSensor::readState()
{
  leftState = analogRead(_leftPin);
  rightState = analogRead(_rightPin);
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