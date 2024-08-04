#ifndef USD_H
#define USD_H

#include <Ultrasonic.h>
#include <Arduino.h>

class USD
{
  private:

  byte _USDPin;
  Ultrasonic myUSD;

  const unsigned float maxDistThreshold = 25;


  public:

  USD() {}

  USD(byte pin)

  void init()

  void getDistVal()

  


}