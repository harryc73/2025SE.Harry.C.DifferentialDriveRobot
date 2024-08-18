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
    int ValThreshold = 36;
    unsigned long currentTime = millis();
    int leftState = lineSensor->readLeftState();
    int rightState = lineSensor->readRightState();
  
    if((leftState < ValThreshold) && (rightState < ValThreshold)){
      motor->accelerate();
      turnStartTime = 0;
      VersionStatus->printGo();
    }
    else if((leftState > ValThreshold) && (rightState < ValThreshold)){
      if (turnStartTime == 0) {
        turnStartTime = currentTime;
      }

      if (currentTime - turnStartTime > sharpTurnThreshold) {
        motor->turnLeft();
      } else {
        motor->sharpTurnLeft();
      }
      VersionStatus->printLeft();
    }
    else if((leftState < ValThreshold) && (rightState > ValThreshold)){
      if (turnStartTime == 0) {
        turnStartTime = currentTime;
      }

      if (currentTime - turnStartTime > sharpTurnThreshold){
        motor->turnRight();
      } else {
        motor->sharpTurnRight();
      }
      VersionStatus->printRight();
    }

    else {
      motor->brake();
      turnStartTime = 0;
      VersionStatus->printBrake();
    }
    motor->update(); // while it looks different the values are given depending on the outcome of each loop to the update method which then writes the values to the motors, allowing for the delay
  }

  void CarController::TestMotors()
  {
    motor->accelerate();
    motor->update();
    delay(1000);
    motor->reverse();
    motor->update();
    delay(1000);
    motor->brake();
    motor->update();
    delay(1000);
  }

  void CarController::TestLines()
  {
    int leftState = lineSensor->readLeftState();
    int rightState = lineSensor->readRightState();

    Serial.print(leftState);
    Serial.print(" ");
    Serial.println(rightState);
  }