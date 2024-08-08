#include <Servo.h>
#include "LineSensor.h"
#include "Motor.h"
#include "CarController.h"
#include <Arduino.h>
#include "LedArray.h"

CarController::CarController(LineSensor* lineSensor, Motor* motor, LedArray* VersionStatus)
{
  this->lineSensor = lineSensor;
  this->motor = motor;
  this->VersionStatus = VersionStatus;
}

  void CarController::init()
  {
    lineSensor->init();
    motor->init();
    VersionStatus->printVersion();

  }

  void CarController::followLine()
  {
    if((lineSensor->isLeftLine()) && (lineSensor->isRightLine())){
      motor->brake();
    }
    else if((!lineSensor->isLeftLine()) && (lineSensor->isRightLine())){
      motor->turnRight();
    }
    else if((lineSensor->isLeftLine()) && (!lineSensor->isRightLine())){
      motor->turnLeft();
    }
    else{
      motor->accelerate();
    }
  }