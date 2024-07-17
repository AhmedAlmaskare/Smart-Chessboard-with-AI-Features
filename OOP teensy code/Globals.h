#ifndef Globals_h
#define Globals_h

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1351.h>
#include <SPI.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <SD.h>

#include "T2Pi.h"
#include "ReadVoltage.h"
#include "Colour.h"
#include "SetMux.h"
#include "MenuFunctions.h"
#include "PollMagnet.h"
#include "Com.h"


//extern T2Pi t2pi;
// Global Variables
extern const int chipSelect;
extern int SDActive;

// Screen dimensions
#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT 128 // Change this to 96 for 1.27" OLED.
// You can use any (4 or) 5 pins
#define SCLK_PIN 13
#define MOSI_PIN 11
#define DC_PIN   7
#define CS_PIN   8
#define RST_PIN  1
// Color definitions
#define Black           0x0000
#define Blue            0x001F
#define Red             0xF800
#define Green           0x07E0
#define Cyan            0x07FF
#define Magenta         0xF81F
#define Yellow          0xFFE0
#define White           0xFFFF

extern Adafruit_SSD1351 display;

#define NeoPIN 0
extern Adafruit_NeoPixel strip;
extern uint32_t AllowedColour;
extern uint32_t LocationColour;
extern uint32_t CannotMove;
extern uint32_t ThreatsColour;
extern int ColourClash1;
extern int ColourClash2;
extern int ColourClash3;

extern const int muxOut1;
extern const int muxOut2;
extern const int muxOut3;
extern const int muxOut4;
extern const int s0;
extern const int s1;
extern const int s2;
extern const int s3;
extern bool SensorReadState;
extern bool pLayout1[64];
extern bool pLayout2[64];
extern int MagLoc;
extern String ChessNot;
extern String CurrentLocStr;
extern String FutureLocStr;
extern int IllegalMove1;
extern int IllegalMoveFlag;
extern int IllegalOverride;
extern int AIMove;
extern int AILoc;
extern int MoveComplete;
extern int MuxtoNeo;
extern int PrevLoc;
extern int NewLoc;
extern int CurrentLoc;
extern int FutureLoc;
extern int PrevMove1;
extern int PrevMove2;

extern unsigned long int TColour;
extern String CommsInput;

extern int Display;
extern int PrevDisplay;
extern int Menu;
extern int ArrowPos;
extern int OptionNum;
extern int PrevMenu;
extern int ColourMenu;
extern int ColourSelect1;
extern int ColourSelect2;

extern const int UpButton;
extern const int DownButton;
extern const int BackButton;
extern const int SelectButton;
extern int buttonStateUp;         // variable for reading the pushbutton status
extern int buttonStateDown;
extern int buttonStateBack;
extern int buttonStateSelect;
extern int lastButtonStateUp;   // the previous reading from the input pin
extern int lastButtonStateDown;
extern int lastButtonStateBack;
extern int lastButtonStateSelect;
extern unsigned long lastDebounceTime;  // the last time the output pin was toggled
extern unsigned long debounceDelay;    // the debounce time; increase if the output flickers

extern int GameType;
extern int MoveTimerDisplay;
extern int MoveTimer;
extern String P1Assists;
extern String P2Assists;
extern String PowerSaver;
extern int Brightness;
extern int BrightnessDisplay;

extern bool AIGame;
extern String GameSettings;
extern String GameMode;
extern String P1Colour;
extern String Difficulty;
extern String GameModeDisplay;
extern String P1ColourDisplay;
extern String DifficultyDisplay;

extern int PawnPromo;
extern int WaitingSelection;
extern String PromoSelection;

#endif
