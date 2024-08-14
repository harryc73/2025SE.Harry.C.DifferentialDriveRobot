#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
#include "LedArray.h"

ArduinoLEDMatrix matrix;

LedArray::LedArray(const char* VersionNum)
{
  this->_VersionNum = VersionNum;
}


void LedArray::printVersion()
{
  matrix.begin();
  matrix.textFont(Font_5x7);
  matrix.textScrollSpeed(100);
  matrix.stroke(0xFF, 0, 0);
  matrix.beginText(0, 1, 0xFF, 0, 0);
  matrix.print(_VersionNum);
  matrix.endText(SCROLL_LEFT);
}