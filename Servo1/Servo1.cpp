#include "Servo1.h"
#include <Servo.h>

Servo1::Servo1(byte pin)
  {
    this->_pin = pin;
  }

  void Servo1::init()
  {
    servo1.attach(SERVO_PIN)
  }