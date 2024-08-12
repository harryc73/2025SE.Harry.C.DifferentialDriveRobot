#include "LineSensor.h"
#define LEFT_LINE_PIN 0
#define RIGHT_LINE_PIN 1

LineSensor lineSensor(LEFT_LINE_PIN, RIGHT_LINE_PIN);


void setup() {
  lineSensor.init();
}

void loop() {
  Serial.print(lineSensor.readLeftState());
  Serial.print(" ");
  Serial.print(lineSensor.readRightState());
  delay(100);
}
