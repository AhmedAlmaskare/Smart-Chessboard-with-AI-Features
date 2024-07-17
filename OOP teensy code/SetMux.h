#ifndef SetMux_h
#define SetMux_h
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


class SetMux
{
	public:
		SetMux();
		void setMux(int channel);
		const int s0 = 14;
		const int s1 = 15;
		const int s2 = 16;
		const int s3 = 17;

	private:
		int channel;
};
extern SetMux setMx;
#endif