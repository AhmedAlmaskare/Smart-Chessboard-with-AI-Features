#include "Com.h"
//#include "MenuFunctions.h"
//#include "Colour.h"
//#include "PollMagnet.h"
#include "Globals.h"
#include "Colour.h"
#include "SetMux.h"
#include "ReadVoltage.h"
MenuFunctions menuFun;
//Colour colour;
PollMagnet pollMagnet;
//SetMux setMx;
//ReadVoltage readV;
Com::Com()
{
	Serial.begin(115200);

}

void Com::TeensyInput(String CommsInput) { //receiving comms from raspberry pi
  int Read = 0;
  int NeoLoc;
  int NumAvailableMoves;
  int Num = CommsInput.charAt(Read);
  String Selection = CommsInput.charAt(Read);

  //Serial.println(Num);
  CurrentLoc = (CommsInput.charAt(Read + 1) - 41) //-41 as the String of a is 97 and the NeoPixel Number at A1 = 56, B1 = 57, C1 = 58... H1 = 63
               - ((CommsInput.charAt(Read + 2) - 49) * 8); //-48 since String of 1 is seen as numerical value of 48 then additional -1 as NeoPixel's start from 0
  strip.setPixelColor(CurrentLoc, LocationColour);

  if (Selection == "A") { //Receive AI Move in the form of Current Location then Future Location eg. c2c3
    //CurrentLoc = NeoLoc;
    NeoLoc = (CommsInput.charAt(Read + 3) - 41) //-41 as the String of a is 97 and the NeoPixel Number at a1 = 56, b1 = 57, c1 = 58... h1 = 63
             - ((CommsInput.charAt(Read + 4) - 49) * 8); //-48 since String of 1 is seen as numerical value of 48 then additional -1 as NeoPixel's start from 0
    FutureLoc = NeoLoc;
    strip.setPixelColor(CurrentLoc, LocationColour);
    strip.setPixelColor(FutureLoc, AllowedColour);
    strip.show();
    //AILoc = FutureLoc;
    Display = 13;
    Menu = 130;
    OptionNum = 5; //originally 4
    ArrowPos = 1;
    display.fillScreen(Black);
    menuFun.MenuArrowDisplay(ArrowPos);
    menuFun.MenuTextDisplay(Display);
    // BoardSetup(ColourSelect1, ColourSelect2);
    //until sensor confirms move
  }
  else if (Selection == "H") { //Receive Hint in the form of Current Location then Future Location eg. c2c3
    NeoLoc = (CommsInput.charAt(Read + 3) - 41) //-41 as the String of a is 97 and the NeoPixel Number at a1 = 56, b1 = 57, c1 = 58... h1 = 63
             - ((CommsInput.charAt(Read + 4) - 49) * 8); //-48 since String of 1 is seen as numerical value of 48 then additional -1 as NeoPixel's start from 0
    FutureLoc = NeoLoc;
    Serial.println(CommsInput.charAt(Read + 3) - 41);
    strip.setPixelColor(FutureLoc, AllowedColour);
    strip.show();
    //until sensor confirms move
  }
  else if (Selection == "P") { //Receive Available Moves in the form of Current Location then available locations eg. c2c3c4 for the first move of a pawn located in c2
    NumAvailableMoves = (CommsInput.length() - 2) / 2;
    int j = 2;
    for (int i = 1; i <= NumAvailableMoves * 2; i = i + 2) {
      int Letter = CommsInput.charAt(i) - 41;
      int Number = (CommsInput.charAt(j) - 49) * 8;
      NeoLoc = Letter //-41 as the String of a is 97 and the NeoPixel Number at a1 = 56, b1 = 57, c1 = 58... h1 = 63
               - Number; //-48 since String of 1 is seen as numerical value of 48 then additional -1 as NeoPixel's start from 0
      strip.setPixelColor(NeoLoc, AllowedColour);
      strip.setPixelColor(CurrentLoc, LocationColour);
      strip.show();
      delay(2);
      j = j + 2;
    }
  }
  else if (Selection == "L") { //Legal move
    String Selection = CommsInput.charAt(Read + 1);
    if (Selection == "a") { //AI move
      Serial.println("a");
      Display = 19;
      AIMove = 1;
      display.fillScreen(Black);
      menuFun.MenuTextDisplay(Display);
      while (Serial.available()) Serial.read();
      while (!Serial.available());
      CommsInput = Serial.readStringUntil("*");
      colour.BoardSetup(ColourSelect1, ColourSelect2);
      TeensyInput(CommsInput);
    }
    else if (Selection == "h") { //Human move 
      AIMove = 0;
    }
  }
  else if (Selection == "I") { //Illegal move
    IllegalMoveFlag = 1;
    colour.BoardSetup(ColourSelect1, ColourSelect2);
    strip.setPixelColor(PrevLoc, LocationColour);
    strip.setPixelColor(NewLoc, CannotMove);
    strip.show();
    Display = 21;
    display.fillScreen(Black);
    menuFun.MenuTextDisplay(Display);
    IllegalMove1 = PrevLoc;
    Menu = 0;
    IllegalOverride = 0;
    while (IllegalMove1 != NewLoc) {
      pollMagnet.MagnetPoll();
      menuFun.MenuNavigation();
      if (IllegalOverride == 1) {
        break;
      }
    }
    IllegalOverride = 0;
    colour.BoardSetup(ColourSelect1, ColourSelect2);
    IllegalMoveFlag = 0;
    display.fillScreen(Black);
    if (AIMove == 1) {
      TeensyInput(CommsInput);
      Display = 19;
    }
    else {
      menuFun.MenuArrowDisplay(ArrowPos);
      Display = 13;
      Menu = 130;
      OptionNum = 5; //originally 4
      ArrowPos = 1;
    }
    menuFun.MenuTextDisplay(Display);
  }
  else if (Selection == "G") {
  }
  else if (Selection == "E") { //end game
    String Selection = CommsInput.charAt(Read + 1);
    display.fillScreen(Black);
    if (Selection == "w") { //white win
      Display = 22;
    }
    else if (Selection == "b") { //black win
      Display = 23;
    }
    else if (Selection == "d") { //draw
      Display = 24;
    }
    menuFun.MenuTextDisplay(Display);
    colour.rainbow(5);
    display.fillScreen(Black);
    Display = 1;
    Menu = 10;
    OptionNum = 3;
    ArrowPos = 1;
    menuFun.MenuArrowDisplay(ArrowPos);
    menuFun.MenuTextDisplay(Display);
    colour.BoardSetup(ColourSelect1, ColourSelect2);
  }
    //threats start here
  else if (Selection == "T"){//recived threats hints as string of algenum: a1b3d2
   NumAvailableMoves = (CommsInput.length() - 2) / 2;
    int j = 2;
    for (int i = 1; i <= NumAvailableMoves * 2; i = i + 2) {
      int Letter = CommsInput.charAt(i) - 41;
      int Number = (CommsInput.charAt(j) - 49) * 8;
      NeoLoc = Letter //-41 as the String of a is 97 and the NeoPixel Number at a1 = 56, b1 = 57, c1 = 58... h1 = 63
               - Number; //-48 since String of 1 is seen as numerical value of 48 then additional -1 as NeoPixel's start from 0
      strip.setPixelColor(NeoLoc, ThreatsColour);
      strip.show();
      delay(2);
      j = j + 2;
    }
  }
	 
}

void Com::TeensyToPi(int MagLoc) { //converting magnet location into chess notation
  int Num = 0;
  String NumStr;
  if (MagLoc == 56 || MagLoc == 48 || MagLoc == 40 || MagLoc == 32 || MagLoc == 24 || MagLoc == 16 || MagLoc == 8 || MagLoc == 0) {
    Num = 1 + (-(MagLoc - 56) / 8);
    ChessNot = "a" + String(Num);
  }
  else if (MagLoc == 57 || MagLoc == 49 || MagLoc == 41 || MagLoc == 33 || MagLoc == 25 || MagLoc == 17 || MagLoc == 9 || MagLoc == 1) {
    Num = 1 + (-(MagLoc - 57) / 8);
    ChessNot = "b" + String(Num);
  }
  else if (MagLoc == 58 || MagLoc == 50 || MagLoc == 42 || MagLoc == 34 || MagLoc == 26 || MagLoc == 18 || MagLoc == 10 || MagLoc == 2) {
    Num = 1 + (-(MagLoc - 58) / 8);
    ChessNot = "c" + String(Num);
  }
  else if (MagLoc == 59 || MagLoc == 51 || MagLoc == 43 || MagLoc == 35 || MagLoc == 27 || MagLoc == 19 || MagLoc == 11 || MagLoc == 3) {
    Num = 1 + (-(MagLoc - 59) / 8);
    ChessNot = "d" + String(Num);
  }
  else if (MagLoc == 60 || MagLoc == 52 || MagLoc == 44 || MagLoc == 36 || MagLoc == 28 || MagLoc == 20 || MagLoc == 12 || MagLoc == 4) {
    Num = 1 + (-(MagLoc - 60) / 8);
    ChessNot = "e" + String(Num);
  }
  else if (MagLoc == 61 || MagLoc == 53 || MagLoc == 45 || MagLoc == 37 || MagLoc == 29 || MagLoc == 21 || MagLoc == 13 || MagLoc == 5) {
    Num = 1 + (-(MagLoc - 61) / 8);
    ChessNot = "f" + String(Num);
  }
  else if (MagLoc == 62 || MagLoc == 54 || MagLoc == 46 || MagLoc == 38 || MagLoc == 30 || MagLoc == 22 || MagLoc == 14 || MagLoc == 6) {
    Num = 1 + (-(MagLoc - 62) / 8);
    ChessNot = "g" + String(Num);
  }
  else if (MagLoc == 63 || MagLoc == 55 || MagLoc == 47 || MagLoc == 39 || MagLoc == 31 || MagLoc == 23 || MagLoc == 15 || MagLoc == 7) {
    Num = 1 + (-(MagLoc - 63) / 8);
    ChessNot = "h" + String(Num);
  }
  if (MoveComplete == 0) {
    CurrentLocStr = ChessNot;
    // BoardSetup(ColourSelect1, ColourSelect2);
    if (P1Assists == "On") {
      Serial.println("p" + CurrentLocStr);
      while (Serial.available()) Serial.read();
      while (!Serial.available());
      CommsInput = Serial.readStringUntil("*");
      TeensyInput(CommsInput);
    }
  }
  else if (MoveComplete == 1) {
    if (MagLoc >= 0 && MagLoc <= 7) {
      setMx.setMux(MagLoc);
      float volt = readV.readVoltage(muxOut1);
      if (volt <= 0.90) { //piece is there
        PawnPromo = 1;
      }
      else { //Empty (no piece)
        PawnPromo = 0;
      }
    }
    else if (MagLoc >= 56 && MagLoc <= 63) {
      setMx.setMux(MagLoc - 48);
      float volt = readV.readVoltage(muxOut4);
      if (volt <= 0.90) { //piece is there
        PawnPromo = 1;
      }
      else { //Empty (no piece)
        PawnPromo = 0;
      }
    }
    if (NewLoc == PrevLoc) {
      if (P1Assists == "On") {
        colour.BoardSetup(ColourSelect1, ColourSelect2);
      }
    }
    else {
      FutureLocStr = ChessNot;
      if (P1Assists == "On") {
        colour.BoardSetup(ColourSelect1, ColourSelect2);
        strip.setPixelColor(PrevLoc, LocationColour);
        strip.setPixelColor(NewLoc, AllowedColour);
        strip.show();
      }
      if (IllegalMoveFlag == 1) {
        //CommsInput = " ";
      }
      else if (PawnPromo == 1) {
        Display = 25;
        Menu = 171;
        ArrowPos = 2;
        OptionNum = 5;
        display.fillScreen(Black);
        menuFun.MenuTextDisplay(Display);
        menuFun.MenuArrowDisplay(ArrowPos);
        WaitingSelection = 1;
        while (WaitingSelection != 0) {
          menuFun.MenuNavigation();
        }
        Serial.println("m" + CurrentLocStr + FutureLocStr + PromoSelection);
        while (Serial.available()) Serial.read();
        while (!Serial.available());
        CommsInput = Serial.readStringUntil("*");
        TeensyInput(CommsInput);
        Display = 13;
        Menu = 130;
        ArrowPos = 1;
        OptionNum = 5; //originally 4
        display.fillScreen(Black);
        menuFun.MenuTextDisplay(Display);
        menuFun.MenuArrowDisplay(ArrowPos);
        PawnPromo = 0;
      }
      else {
        Serial.println("m" + CurrentLocStr + FutureLocStr);
        while (Serial.available()) Serial.read();
        while (!Serial.available());
        CommsInput = Serial.readStringUntil("*");
        TeensyInput(CommsInput);
      }
    }
  }
}


