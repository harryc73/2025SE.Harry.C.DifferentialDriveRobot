#include <Servo.h>
#include "LineSensor.h"
#include "Motor.h"
#include "CarController.h"
#include <Arduino.h>

CarController::CarController(LineSensor &lineSensor, Motor &motor) 
{
  this->_lineSensor = lineSensor;
  this->_motor = motor;
}

  void CarController::followLine()
  {
    if((_lineSensor.isLeftLine()) && (_lineSensor.isRightLine()))
      _motor.accelerate();
    else
      _motor.brake();
  }