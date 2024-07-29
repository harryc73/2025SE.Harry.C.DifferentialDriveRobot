#ifndef SERVO1_H //if not defined
#define SERVO1_H // used for the class to be written once
// there is the decleration of the class
#include <Arduino.h> // for header files, you need to include this to use arudino functionality

class Servo1
{
private:
  byte _pin;
public:

  Servo1() {}
  Servo1(byte pin);

  void init();

  void accelerate();

  void brake();
};

#endif