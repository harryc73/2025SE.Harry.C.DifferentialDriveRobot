#ifndef CARCONTROLLER_H
#define CARCONTROLLER_H

#include <Servo.h>
#include <Arduino.h>

#include "LineSensor.h"
#include "Motor.h"

#include "LedArray.h"

class CarController
{

private:

  LineSensor* lineSensor;
  Motor* motor;
  LedArray* VersionStatus;

public:

  CarController () {}

  CarController(LineSensor* lineSensor, Motor* motor, LedArray* VersionStatus);

  void init();

  void followLine();


};

#endif