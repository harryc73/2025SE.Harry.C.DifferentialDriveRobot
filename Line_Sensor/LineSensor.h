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

public:
  LineSensor() {}

  LineSensor(byte leftPin, byte rightPin);

  void init();

  int readLeftState();
  int readRightState();

  // need at some point
  bool isLeftLine();
  bool isRightLine();

  // testing methods
  byte readState();
  String getState();


};

#endif