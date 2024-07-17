#ifndef Com_h
#define Com_h
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
#include "T2Pi.h"
#include "ReadVoltage.h"
#include "Colour.h"
#include "SetMux.h"
#include "MenuFunctions.h"
#include "PollMagnet.h"


//===========================================================
#define Black           0x0000
#define Blue            0x001F
#define Red             0xF800
#define Green           0x07E0
#define Cyan            0x07FF
#define Magenta         0xF81F
#define Yellow          0xFFE0
#define White           0xFFFF
//===========================================================
class Com
{
	public:
		Com();
		//void send(String data);
		//String recieveData();
		//bool getReceiveComplete();
		//void setReceiveComplete(bool state);


		void TeensyInput(String CommsInput);
    void TeensyToPi(int MagLoc);


	private:
		String dataIn;
		//bool receiveComplete =false;


		int Read = 0;
  	int NeoLoc;
  	int NumAvailableMoves;
  	int Num;
  	String Selection;
  	int Number;
  	int Letter;

};
extern Com com;
#endif