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
  unsigned long currentTime = millis();
  lastTimeBlink = 0;
  currentMovement = "";
}

  void CarController::init()
  {
    lineSensor->init();
    motor->init();
    VersionStatus->printVersion();

  }

  bool CarController::thresholdCheck()
  {
    unsigned long currentTime = millis();
    if(currentTime - turnStartTime > sharpTurnThreshold) {
      return true;
    } else {
      return false;
    }
  }

  void CarController::turnTime()
  {
    unsigned long currentTime = millis(); // gets current time
    if (turnStartTime == 0) { // checks if its starts counting
      turnStartTime = currentTime; // records at start time
    }
  }


  void CarController::followLine()
  {

   if(lineSensor->onLine()){
      motor->accelerate();
      currentMovement = "Go";
      turnStartTime = 0;
    }
    else if(lineSensor->onLeftLine()){
      turnTime();
      currentMovement = "Left";

      if (thresholdCheck()) {
        motor->sharpTurnLeft();
      } else {
        motor->turnLeft();
      }
    }
    else if(lineSensor->onRightLine()){
      turnTime();
      currentMovement = "Right"; 

      if (thresholdCheck()){
        motor->sharpTurnRight();
      } else {
        motor->turnRight();
      }
    }

    else {
      motor->brake();
      currentMovement = "Brake";
      turnStartTime = 0;
    }
    motor->update(); // while it looks different the values are given depending on the outcome of each loop to the update method which then writes the values to the motors, allowing for the delay
    updateLedMovements(); // if not working remove this
  }

  void CarController::updateLedMovements() 
  {
    unsigned long currentTime = millis();
    if (currentTime - lastTimeBlink >= blinkDelay) {
        if (currentMovement == "Go") {
          VersionStatus->printGo();
        } 
        else if (currentMovement == "Left") {
          VersionStatus->printLeft();
        } 
        else if (currentMovement == "Right") {
          VersionStatus->printRight();
        } else if (currentMovement == "Brake") {
          VersionStatus->printBrake();
        }
      lastTimeBlink = currentTime;
    }
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

  void CarController::testLedArray()
  {
    VersionStatus->printGo();
    delay(1000);
    VersionStatus->printLeft();
    delay(1000);
    VersionStatus->printRight();
    delay(1000);
    VersionStatus->printBrake();
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