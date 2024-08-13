#include <Servo.h>

Servo leftServo;
Servo rightServo;

void setup() {
  leftServo.attach(9, 700, 2300);
  rightServo.attach(10, 700, 2300);
}

void loop() {
  leftServo.writeMicroseconds(2300);
  rightServo.writeMicroseconds(2300);
}
