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
    state += "Line Detected";
  else
    state += "No Line Detected";

  state += " Right: ";
  
  if(rightState == HIGH)
    state += "No Line Detected";
  else
    state += "Line Detected";
  
  return state;
}