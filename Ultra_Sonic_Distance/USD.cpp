#include "USD.h"
#include <Ultrasonic.h>
#include <Arduino.h>

USD::USD(byte pin)
{
  this->_USDPin = pin;
}

void USD::init()
{
  Ultrasonic myUSD(_USDPin);
}

void USD::getDistVal()
{
  RangeInMillimeters = myUSD.MeasureInMillimeters();
  return RangeInMillimeters;
}

bool USD::isCollision()
{
  if(RangeInMillimeters <= maxDistThreshold)
    return true;
  else
    return false;
}