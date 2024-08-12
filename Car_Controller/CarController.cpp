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
    if((lineSensor->readLeftState() < 40) && (lineSensor->readRightState() < 40)){
      motor->accelerate();
    }
    else if((lineSensor->readLeftState() > 40) && (lineSensor->readRightState() < 40)){
      motor->turnLeft();
    }
    else if((lineSensor->readLeftState() < 40) && (lineSensor->readRightState() > 40)){
      motor->turnRight();
    }
    else{
      motor->brake();
    }
  }

  void CarController::TestMotors()
  {
    motor->accelerate();
  }

  void CarController::TestLines()
  {
    Serial.print(lineSensor->readLeftState());
    Serial.print(" ");
    Serial.println(lineSensor->readRightState());
  }