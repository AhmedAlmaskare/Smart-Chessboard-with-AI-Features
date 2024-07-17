#ifndef PollMagnet_h
#define PollMagnet_h
#include "Arduino.h"
#include "Globals.h"
#include "ReadVoltage.h"
#include "SetMux.h"
#include "Colour.h"
//#include "T2Pi.h"


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <SD.h>


class PollMagnet
{
	public:
		PollMagnet();
		
		void MagnetPoll();
		
	private:
		int j;
		int i;
		int k;
};
extern PollMagnet pollMagnet;
#endif