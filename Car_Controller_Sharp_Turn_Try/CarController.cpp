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
    unsigned int lineVal = 40;
    int leftState = lineSensor->readLeftState();
    int rightState = lineSensor->readRightState();
  
    if((leftState < lineVal) && (rightState < lineVal)){
      motor->accelerate();
      turnStartTime = 0;
    }
    else if((leftState > lineVal) && (rightState < lineVal)){
      if (turnStartTime == 0) {
        turnStartTime = currentTime;
      }

      if (currentTime - turnStartTime > sharpTurnThreshold) {
        motor->turnLeft();
      } else {
        motor->sharpTurnLeft();
        delay(20);
      }
    }
    else if((leftState < lineVal) && (rightState > lineVal)){
      if (turnStartTime == 0) {
        turnStartTime = currentTime;
      }

      if (currentTime - turnStartTime > sharpTurnThreshold){
        motor->turnRight();
      } else {
        motor->sharpTurnRight();
        delay(20);
      }
    }

    else if((leftState > lineVal) && (rightState > lineVal)){
      motor->slowReverse();
      turnStartTime = 0;
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