/*#include "T2Pi.h"
//#include "MenuFunctions.h"
//#include "Com.h"
//#include "SetMux.h"
//#include "ReadVoltage.h"
//#include "Colour.h"

T2Pi::T2Pi()
{
	;

}



void T2Pi::TeensyToPi(int MagLoc) { //converting magnet location into chess notation
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
      com.TeensyInput(CommsInput);
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
        com.TeensyInput(CommsInput);
        Display = 13;
        Menu = 130;
        ArrowPos = 1;
        OptionNum = 4;
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
        com.TeensyInput(CommsInput);
      }
    }
  }
}
*/


