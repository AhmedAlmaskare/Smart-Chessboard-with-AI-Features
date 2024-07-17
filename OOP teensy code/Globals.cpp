#include "Globals.h"

// Define global variables
const int chipSelect = BUILTIN_SDCARD;
int SDActive = 1;

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

//extern Com com;
//extern Colour colour;
//extern PollMagnet pollMagnet;
//extern MenuFunctions menuFun;
//extern ReadVoltage readV;
//extern SetMux setMx;

Adafruit_SSD1351 display = Adafruit_SSD1351(SCREEN_WIDTH, SCREEN_HEIGHT, CS_PIN, DC_PIN, MOSI_PIN, SCLK_PIN, RST_PIN);

#define NeoPIN 0
Adafruit_NeoPixel strip = Adafruit_NeoPixel(64, NeoPIN, NEO_GRB + NEO_KHZ800);
uint32_t AllowedColour = strip.Color(0, 255, 0); //Show allowed moves in Green
uint32_t LocationColour = strip.Color(255, 255, 0); //Show current location in Yellow
uint32_t CannotMove = strip.Color(255, 0, 0); //Show impossible move in Red

uint32_t ThreatsColour = strip.Color(255, 165, 0); //orange for threats

int ColourClash1 = 0; //Colour clash between theme colour & AllowedColour Variable
int ColourClash2 = 0; //Colour clash between theme colour & LocationColour Variable
int ColourClash3 = 0; //Colour clash between theme colour & CannotMove Variable

const int muxOut1 = 18;
const int muxOut2 = 21;
const int muxOut3 = 38;
const int muxOut4 = 19;
const int s0 = 14;
const int s1 = 15;
const int s2 = 16;
const int s3 = 17;
bool SensorReadState = 0;
bool pLayout1[64];
bool pLayout2[64];
int MagLoc = 0;
String ChessNot;
String CurrentLocStr;
String FutureLocStr;
int IllegalMove1;
int IllegalMoveFlag = 0;
int IllegalOverride = 0;
int AIMove = 0;
int AILoc;
int MoveComplete;
int MuxtoNeo;
int PrevLoc;
int NewLoc;
int CurrentLoc;
int FutureLoc;
int PrevMove1;
int PrevMove2;

unsigned long int TColour = White;
String CommsInput;

int Display = 1;
int PrevDisplay = 0;
int Menu = 10;
int ArrowPos = 1;
int OptionNum;
int PrevMenu = 10;
int ColourMenu;
int ColourSelect1 = 1;
int ColourSelect2 = 11;

const int UpButton = 10;
const int DownButton = 9;
const int BackButton = 6;
const int SelectButton = 5;
int buttonStateUp = 0;         // variable for reading the pushbutton status
int buttonStateDown = 0;
int buttonStateBack = 0;
int buttonStateSelect = 0;
int lastButtonStateUp = LOW;   // the previous reading from the input pin
int lastButtonStateDown = LOW;
int lastButtonStateBack = LOW;
int lastButtonStateSelect = LOW;
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 25;    // the debounce time; increase if the output flickers

int GameType;
int MoveTimerDisplay = 5;
int MoveTimer = 5;
String P1Assists = "On";
String P2Assists = "On";
String PowerSaver = "Off";
int Brightness = 30;
int BrightnessDisplay = 30;

bool AIGame;
String GameSettings;
String GameMode;
String P1Colour;
String Difficulty;
String GameModeDisplay;
String P1ColourDisplay;
String DifficultyDisplay;

int PawnPromo;
int WaitingSelection;
String PromoSelection;
