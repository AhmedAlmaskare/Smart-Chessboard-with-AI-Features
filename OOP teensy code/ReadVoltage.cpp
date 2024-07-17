#include "ReadVoltage.h"

ReadVoltage::ReadVoltage()
{
  ;

}

float ReadVoltage::readVoltage(const int muxOut) {
  float sensorVal = 0.0;
  float totalVal = 0.0;
  for (int x = 0; x < 3; x = x + 1) {
    sensorVal = analogRead(muxOut);
    totalVal += sensorVal;
  }
  float digitalAvg = totalVal / 3;
  float voltage = digitalAvg * (3.3 / 4095.0); //convert digital to analog (voltage) (5/1024 for arduino, 3.3?/8192 for teensy)
  return voltage;
}