#ifndef LEDARRAY_H
#define LEDARRAY_H

#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

#include <Arduino.h>

class LedArray
{
  private:

  const char* _VersionNum;
  const char* status;

  public:

  LedArray() {}

  LedArray(const char* VersionNum);

  void printVersion();

  void updateStatus(const char* status);

  void printLeft();

  void printRight();

  void printGo();

  void printBrake();

};

#endif