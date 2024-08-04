#include "USD.h"
#include <Ultrasonic.h>
#include <Arduino.h>

USD::USD(byte pin) : myUSD(pin) //initialise both at the same time, as calling the US method by itself doesnt work in a cpp
{
  this->_USDPin = pin;
}


void USD::getDistVal()
=======
void USD::init()
{
  Ultrasonic myUSD(_USDPin);
}

long USD::getDistVal()
>>>>>>> Stashed changes
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