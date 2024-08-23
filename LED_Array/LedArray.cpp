#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
#include "LedArray.h"

ArduinoLEDMatrix matrix;

LedArray::LedArray(const char* VersionNum)
{
  this->_VersionNum = VersionNum;
  this->status = status;
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

void LedArray::updateStatus(const char* status)
{
  matrix.begin();
  matrix.textFont(Font_5x7);
  matrix.stroke(0xFF, 0, 0);
  matrix.clear();  // Clear the display
  matrix.beginText(0, 1, 0xFF, 0, 0);  // Set the position
  matrix.print(status);
  matrix.endText();
}

void LedArray::printGo()
{
  updateStatus("GO");
}

void LedArray::printLeft()
{
  updateStatus("<-");
}

void LedArray::printRight()
{
  updateStatus("->");
}

void LedArray::printBrake()
{
  updateStatus("BRAKE");
}
