#include <Servo.h>
#include "LineSensor.h"
#include "Motor.h"
#include "CarController.h"
#include <Arduino.h>

CarController::CarController(LineSensor* lineSensor, Motor* motor)
{
  this->lineSensor = lineSensor;
  this->motor = motor;
}

  void CarController::init()
  {
    lineSensor->init();
    motor->init();
  }

  void CarController::followLine()
  {
    if((lineSensor->isLeftLine()) && (lineSensor->isRightLine())){
      motor->accelerate();
    }
    else if((!lineSensor->isLeftLine()) && (lineSensor->isRightLine())){
      motor->turnLeft();
    }
    else if((lineSensor->isLeftLine()) && (!lineSensor->isRightLine())){
      motor->turnRight();
    }
    else{
      motor->brake();
    }
  }