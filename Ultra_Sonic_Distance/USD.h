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
  long RangeInMillimeters;


public:

  // USD() {} removed this method because I don't need to call the class without parameters and its fued with the Ultrasonic libary

  USD(byte pin);

  // void init() I dont really need to initialise anything

  long getDistVal();

  bool isCollision();

  //testing class
  
  String readState();
  
};

#endif