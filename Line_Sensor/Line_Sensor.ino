#include "LineSensor.h"
#define LEFT_LINE_PIN 12
#define RIGHT_LINE_PIN 13

LineSensor lineSensor(LEFT_LINE_PIN, RIGHT_LINE_PIN);


void setup() {
  Serial.begin(9600);
  lineSensor.init();
}

void loop() {
  Serial.println(lineSensor.getState());
  delay(100);
}
