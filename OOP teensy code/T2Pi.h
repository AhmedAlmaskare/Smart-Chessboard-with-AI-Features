/*#ifndef T2Pi_h
#define T2Pi_h
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
#include "ReadVoltage.h"
#include "Com.h"
#include "Colour.h"
#include "MenuFunctions.h"
#include "PollMagnet.h"

// Screen dimensions
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 128 // Change this to 96 for 1.27" OLED.
// You can use any (4 or) 5 pins
#define SCLK_PIN 13
#define MOSI_PIN 11
#define DC_PIN   7
#define CS_PIN   8
#define RST_PIN  1
#define Black           0x0000

class T2Pi
{
	public:
		T2Pi();
		void TeensyToPi(int MagLoc);
		
    
    

	private:
		String NumStr;
};
#endif
*/