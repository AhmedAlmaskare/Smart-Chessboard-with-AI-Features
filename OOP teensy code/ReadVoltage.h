#ifndef ReadVoltage_h
#define ReadVoltage_h
#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <SD.h>

#include "Globals.h"
#include "SetMux.h"

class ReadVoltage
{
	public:
		ReadVoltage();
		const int muxOut;
		float readVoltage(const int muxOut);
		

		

	private:
		float sensorVal;
		float totalVal;
		int x;
		float digitalAvg;
		float voltage;


};
extern ReadVoltage readV;
#endif