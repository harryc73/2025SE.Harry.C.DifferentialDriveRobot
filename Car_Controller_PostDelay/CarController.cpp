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
    if((lineSensor->readLeftState() < 36) && (lineSensor->readRightState() < 36)){
      motor->accelerate();
    }
    else if((lineSensor->readLeftState() > 36) && (lineSensor->readRightState() < 36)){
      motor->turnLeft();
    }
    else if((lineSensor->readLeftState() < 36) && (lineSensor->readRightState() > 36)){
      motor->turnRight();
    }
    else{
      motor->brake();
    }
    motor->update(); // while it looks different the values are given depending on the outcome of each loop to the update method which then writes the values to the motors, allowing for the delay
  }

  void CarController::TestMotors()
  {
    motor->accelerate();
    motor->update();
  }

  void CarController::TestLines()
  {
    Serial.print(lineSensor->readLeftState());
    Serial.print(" ");
    Serial.println(lineSensor->readRightState());
  }