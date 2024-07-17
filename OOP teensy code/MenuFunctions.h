#ifndef MenuFunctions_h
#define MenuFunctions_h
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
#include "Colour.h"
#include "Com.h"
extern File myFile;


#define Red             0xF800
#define Green           0x07E0
class MenuFunctions
{
	public:
		MenuFunctions();
		void MenuTextDisplay(int Display);
		void MenuArrowDisplay(int ArrowPos);
		void MenuNavigation();
    bool ButtonStateChanged(int current, int last);
    bool IsDebounced();
    void HandleUpButtonPress();
    void HandleDownButtonPress();
    void HandleBackButtonPress();
    void HandleSelectButtonPress();
		
		

	private:
		String dataIn;
		bool receiveComplete =false;
		int readingUp;
		int readingDown;
		int readingBack;
		int readingSelect;



};
extern MenuFunctions menuFun;
#endif