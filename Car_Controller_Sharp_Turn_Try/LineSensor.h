#ifndef LINE_SENSOR_H
#define LINE_SENSOR_H

#include <Arduino.h>

class LineSensor
{
private:
  byte _leftPin;
  byte _rightPin;

  byte leftState;
  byte rightState;

  const unsigned int ValThreshold = 32;

public:
  LineSensor() {}

  LineSensor(byte leftPin, byte rightPin);

  void init();

  int readLeftState();
  int readRightState();

  // need at some point
  bool isLeftLine();
  bool isRightLine();

  bool onLine();
  bool onLeftLine();
  bool onRightLine();

  // testing methods
  byte readState();


};

#endif