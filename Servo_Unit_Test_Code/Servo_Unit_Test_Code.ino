#include <Servo.h>

#define LEFT_SERVO_PIN 9
#define RIGHT_SERVO_PIN 10

Servo leftServo;
Servo rightServo;

void setup() {
  leftServo.attach(LEFT_SERVO_PIN, 700, 2300);
  rightServo.attach(RIGHT_SERVO_PIN, 700, 2300);
}

void loop() {
  leftServo.writeMicroseconds(2300); // accelerate speed
  rightServo.writeMicroseconds(700); // accelerate speed
  delay(100);
}
