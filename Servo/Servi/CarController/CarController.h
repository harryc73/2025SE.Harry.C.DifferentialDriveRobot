#ifndef CARCONTROLLER_H
#define CARCONTROLLER_H
#include <Servo.h>

class CarController
{
private:
  Servo leftServo;
  Servo rightServo;

  const unsigned int leftWheelGoSpeed;
  const unsigned int rightWheelGoSpeedWheelSpeed;
  const unsigned int leftWheelStopSpeed;
  const unsigned int rightWheelStopSpeed;

public:

  CarController() {}

  void init();

  void accelerate();

  void brake();
};

#endif