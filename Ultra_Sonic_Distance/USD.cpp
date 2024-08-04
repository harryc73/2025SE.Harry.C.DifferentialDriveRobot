#include "USD.h"
#include <Ultrasonic.h>
#include <Arduino.h>

USD::USD(byte pin) : myUSD(pin) //initialise both at the same time, as calling the US method by itself doesnt work in a cpp
{
  this->_USDPin = pin;
}

long USD::getDistVal()
{
  RangeInMillimeters = myUSD.MeasureInMillimeters();
  return RangeInMillimeters;
}

bool USD::isCollision()
{
  getDistVal();
  if(RangeInMillimeters <= maxDistThreshold)
    return true;
  else
    return false;
}

String USD::readState()
{
  getDistVal();
  isCollision();
}