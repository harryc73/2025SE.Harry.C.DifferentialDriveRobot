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
    unsigned long currentTime = millis();
    int leftState = lineSensor->readLeftState();
    int rightState = lineSensor->readRightState();
  
    if((leftState < 36) && (rightState < 36)){
      motor->accelerate();
      turnStartTime = 0;
    }
    else if((leftState > 36) && (rightState < 36)){
      if (turnStartTime == 0) {
        turnStartTime = currentTime;
      }

      if (currentTime - turnStartTime > sharpTurnThreshold) {
        motor->sharpTurnLeft();
      } else {
        motor->turnLeft();
      }
    }
    else if((leftState < 36) && (rightState > 36)){
      if (turnStartTime == 0) {
        turnStartTime = currentTime;
      }

      if (currentTime - turnStartTime > sharpTurnThreshold){
        motor->sharpTurnRight();
      } else {
        motor->turnRight();
      }
    }
    else {
      motor->brake();
      turnStartTime = 0;
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
    int leftState = lineSensor->readLeftState();
    int rightState = lineSensor->readRightState();

    Serial.print(leftState);
    Serial.print(" ");
    Serial.println(rightState);
  }