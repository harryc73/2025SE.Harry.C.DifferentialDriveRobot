#ifndef LEDARRAY_H
#define LEDARRAY_H

#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

#include <Arduino.h>

class LedArray
{
  private:

  const char* _VersionNum;

  public:

  LedArray() {}

  LedArray(const char* VersionNum);

  void printVersion();

  void printLeftArrow();

  void printRightArrow();

  void printGo();

  void printBrake();
};

#endif