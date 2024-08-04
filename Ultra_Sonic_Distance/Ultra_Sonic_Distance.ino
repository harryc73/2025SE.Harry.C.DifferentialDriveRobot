#include <Ultrasonic.h>
#include "USD.h"
#define USD_PIN 5

USD usd(USD_PIN);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Dist Val: ");
  Serial.print(usd.getDistVal());
  Serial.print("Collision Status");

  if(usd.isCollision())
    Serial.print("Collision Impending");
  else
    Serial.print("No Impending Collison");
  delay(100);
}
