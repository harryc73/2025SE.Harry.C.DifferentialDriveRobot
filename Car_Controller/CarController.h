#ifndef CARCONTROLLER_H
#define CARCONTROLLER_H

#include <Servo.h>
#include <Arduino.h>

#include "LineSensor.h"
#include "Motor.h"

class CarController
{

private:

  LineSensor _lineSensor;
  Motor _motor;

public:

  CarController () {}

  CarController(LineSensor &lineSensor, Motor &motor) 

  void followLine();
};

#endif