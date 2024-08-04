#include <Ultrasonic.h>
#include "USD.h"
#define USD_PIN 5

USD usd(USD_PIN);

void setup() {
  Serial.begin(9600);
  usd.init();
}

void loop() {
  
  Serial.print(getDistVal())

  if (usd.isCollision()) 
    Serial.println("Collision detected!");
  else 
    Serial.println("No collision.");
}
