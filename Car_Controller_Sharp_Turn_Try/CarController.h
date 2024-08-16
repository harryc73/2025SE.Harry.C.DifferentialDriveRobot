#ifndef CARCONTROLLER_H
#define CARCONTROLLER_H

#include <Servo.h>
#include <Arduino.h>

#include "LineSensor.h"
#include "Motor.h"
#include "LedArray.h"

class CarController
{

private:
  // the reason why there is pointers instead of a simple address is because you can't copy the object from the old class, and also you can't initialise 
  // right when the ControllerCar object is constructed, the pointers allow for intialisation to not happen immedeadtly and it to be later assigned
  // this is the reason why you can use the methods of other classes and their objects, as it assigns memory to it without immedeatly initialising
  LineSensor* lineSensor;
  Motor* motor;
  LedArray* VersionStatus;

  unsigned long turnStartTime = 0;
  const unsigned long sharpTurnThreshold = 200;

public:

  CarController () {}

  CarController(LineSensor* lineSensor, Motor* motor, LedArray* VersionStatus);

  void init();

  void followLine();

  void TestMotors();

  void TestLines();

};

#endif