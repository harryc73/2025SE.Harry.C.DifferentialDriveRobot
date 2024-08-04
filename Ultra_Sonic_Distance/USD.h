#ifndef USD_H
#define USD_H

#include <Ultrasonic.h>
#include <Arduino.h>

class USD
{
private:
  byte _USDPin;
  Ultrasonic myUSD;

  const unsigned int maxDistThreshold = 25; // needs to be tested
  long RangeInCentimeters;


public:

  USD() {}

  USD(byte pin);

  void init();

  long getDistVal();

  bool isCollision();

  
};

#endif