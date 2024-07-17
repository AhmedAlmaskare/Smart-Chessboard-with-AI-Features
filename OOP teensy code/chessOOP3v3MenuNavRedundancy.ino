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
//#include "T2Pi.h" <======== i got rid of it and merged it to Com
#include "ReadVoltage.h"
#include "Colour.h"
#include "SetMux.h"
#include "MenuFunctions.h"
#include "PollMagnet.h"
#include "Com.h"
File myFile;



void setup() {
  // put your setup code here, to run once:
  display.begin();
  display.fillScreen(Black);
  display.setCursor(1, 50);
  display.setFont(&FreeSerif9pt7b);
  display.setTextColor(TColour);
  display.setTextSize(1);
  display.print("Chess Game");
  while (Serial.available()) Serial.read();
  while (!Serial.available());
  display.fillScreen(Black);
  delay(1000);
  pinMode(UpButton, INPUT_PULLUP);    // SETS THE leftButtonPin AS AN INPUT
  pinMode(DownButton, INPUT_PULLUP);   // SETS THE rightButtonPin AS AN INPUT
  pinMode(BackButton, INPUT_PULLUP);      // SETS THE upButtonPin AS AN INPUT
  pinMode(SelectButton, INPUT_PULLUP);
  analogReadResolution(12); //teensy only
  pinMode(muxOut1, INPUT);
  pinMode(muxOut2, INPUT);
  pinMode(muxOut3, INPUT);
  pinMode(muxOut4, INPUT);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);

  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed!");
    SDActive = 0;
  }
  if (SDActive == 1) {
    // re-open the file for reading:
    myFile = SD.open("Colours.txt");
    if (myFile) {
      myFile.seek(11);
      //Serial.write(myFile.read());
      ColourSelect1 = myFile.read();
      myFile.seek(25);
      //Serial.write(myFile.read());
      ColourSelect2 = myFile.read();
      Serial.write(myFile.read());
      myFile.close();
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening Colours.txt");
    }
  }
  strip.begin();
  strip.setBrightness(Brightness);
  strip.show(); // Initialize all pixels to 'off'
  colour.BoardSetup(ColourSelect1, ColourSelect2); //set up 2 global variables to 1 that checks AllowedColour and other that checks LocationColour, use if statements for secondary colour
  Menu = 0;
  OptionNum = 3;
  Serial.begin(115200);
  Serial.println("Hello");
}

void loop() {
  // put your main code here, to run repeatedly:
    // put your main code here, to run repeatedly:
  if (Menu > 129 && Menu < 158) {
    pollMagnet.MagnetPoll();
  }

  menuFun.MenuNavigation();
}
