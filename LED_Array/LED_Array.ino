#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
#include "LedArray.h"

ArduinoLEDMatrix matrix; // is this required

static const char* VersionNum = "V00.00.01";

LedArray VersionStatus(VersionNum);


void setup() {
  Serial.begin(9600);
  VersionStatus.printVersion();
}

void loop() {


}