#ifndef Colour_h
#define Colour_h
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

#define NeoPIN 0

class Colour
{
	public:
		Colour();
		
		void colorWipe1(uint32_t c, uint8_t wait);
		void colorWipe2(uint32_t c, uint8_t wait);
		void rainbow(int wait);
		void BoardSetup(int ColourSelect1, int ColourSelect2);

	private:
		uint32_t c;
		uint8_t wait;
		int j;
		int i;
		long firstPixelHue;

};

extern Colour colour;
#endif