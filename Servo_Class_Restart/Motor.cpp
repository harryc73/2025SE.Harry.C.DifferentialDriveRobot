#include "Motor.h"
#include <Servo.h>

Motor::Motor(byte pin)
  {
    this->_pin = pin;
  }

  void Motor::init()
  {
    _servo.attach(_pin, 700, 2300);
  }

  void Motor::accelerate()
  {
    _servo.writeMicroseconds(2300);
  }

  void Motor::brake()
  {
    _servo.writeMicroseconds(1500);
  }

  void Motor::reverse()
  {
    _servo.write(700);
  }