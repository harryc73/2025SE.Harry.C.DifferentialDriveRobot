#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H
#include <Servo.h>

class MotorControl
{
private:

  Servo leftServo;
  Servo rightServo;

  const unsigned int leftWheelGoSpeed;
  const unsigned int rightWheelGoSpeedWheelSpeed;
  const unsigned int leftWheelStopSpeed;
  const unsigned int rightWheelStopSpeed;

public:

  MotorControl() {}

  void init();

  void accelerate();

  void brake();
};

#endif