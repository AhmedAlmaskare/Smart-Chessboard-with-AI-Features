#include "PollMagnet.h"
//#include "SetMux.h"
//#include "ReadVoltage.h"
//#include "Colour.h"
//#include "h"
#include "Globals.h"
ReadVoltage readV;
SetMux setMx;
Colour colour;
Com com;

PollMagnet::PollMagnet()
{


}

void PollMagnet::MagnetPoll() {
  for (int j = 1; j <= 4; j++)  {
    //MenuNavigation();
    if (j == 1) {
      for (int i = 1; i <= 16; i++)  {
        setMx.setMux(i - 1);
        float volt = readV.readVoltage(muxOut1);
        if (volt >= 1.10 || volt <= 0.90) { //piece is there
          pLayout1[i] = true;
        }
        else { //Empty (no piece)
          pLayout1[i] = false;
        }
      }
    }
    else if (j == 2) {
      for (int i = 1; i <= 16; i++)  {
        setMx.setMux(i - 1);
        float volt = readV.readVoltage(muxOut2);
        if (volt >= 1.10 || volt <= 0.90) { //piece is there
          pLayout1[i + 16] = true;
        }
        else { //Empty (no piece)
          pLayout1[i + 16] = false;
        }
      }
    }

    else if (j == 3) {
      for (int i = 1; i <= 16; i++)  {
        setMx.setMux(i - 1);
        float volt = readV.readVoltage(muxOut3);
        if (volt >= 1.10 || volt <= 0.90) { //piece is there
          pLayout1[i + 32] = true;
        }
        else { //Empty (no piece)
          pLayout1[i + 32] = false;
        }
      }
    }
    else if (j == 4) {
      for (int i = 1; i <= 16; i++)  {
        setMx.setMux(i - 1);
        float volt = readV.readVoltage(muxOut4);
        if (volt >= 1.10 || volt <= 0.90) { //piece is there
          pLayout1[i + 48] = true;
        }
        else { //Empty (no piece)
          pLayout1[i + 48] = false;
        }
      }
    }
  }
  for (int k = 1; k <= 64; k++) { //checks for
    if (pLayout1[k] == false && pLayout2[k] == true) {
      //Serial.MoveComplete("Piece removed from ");
      // BoardSetup(ColourSelect1, ColourSelect2);
      //delay(250);
      if (IllegalMoveFlag == 0) {
        colour.BoardSetup(ColourSelect1, ColourSelect2);
        strip.setPixelColor(k - 1, LocationColour);
        strip.show();
        PrevLoc = k - 1;
      }
      SensorReadState = 1;
      //Serial.println(k);
      MoveComplete = 0;
      com.TeensyToPi(k - 1);
      // PrevMove1 = k - 1;
      //break;
    }
  }

  //poll all sensors, put them into first array
  delay(50); //to ensure piece has been fully removed
  //array <bool, 16> pLayout2 = boardLayout(); //poll all sensors a second time, put into second array
  for (int j = 1; j <= 4; j++)  {
    //  MenuNavigation();
    if (j == 1) {
      for (int i = 1; i <= 16; i++)  {
        setMx.setMux(i - 1);
        float volt = readV.readVoltage(muxOut1);
        if (volt >= 1.10 || volt <= 0.90) { //piece is there
          pLayout2[i] = true;
        }
        else { //Empty (no piece)
          pLayout2[i] = false;
        }
      }
    }
    else if (j == 2) {
      for (int i = 1; i <= 16; i++)  {
        setMx.setMux(i - 1);
        float volt = readV.readVoltage(muxOut2);
        if (volt >= 1.10  || volt <= 0.90) { //piece is there
          pLayout2[i + 16] = true;
        }
        else { //Empty (no piece)
          pLayout2[i + 16] = false;
        }
      }
    }
    else if (j == 3) {
      for (int i = 1; i <= 16; i++)  {
        setMx.setMux(i - 1);
        float volt = readV.readVoltage(muxOut3);
        if (volt >= 1.10  || volt <= 0.90) { //piece is there
          pLayout2[i + 32] = true;
        }
        else { //Empty (no piece)
          pLayout2[i + 32] = false;
        }
      }
    }
    else if (j == 4) {
      for (int i = 1; i <= 16; i++)  {
        setMx.setMux(i - 1);
        float volt = readV.readVoltage(muxOut4);
        if (volt >= 1.10  || volt <= 0.90) { //piece is there
          pLayout2[i + 48] = true;
        }
        else { //Empty (no piece)
          pLayout2[i + 48] = false;
          //  Serial.println(i*j);
        }
      }
    }
  }
  for (int k = 1; k <= 64; k++) { //checks for
    if (pLayout1[k] == true && pLayout2[k] == false) {
      //Serial.MoveComplete("Piece removed from ");
      // BoardSetup(ColourSelect1, ColourSelect2);
      //delay(250);
      if (IllegalMoveFlag == 0) {
        colour.BoardSetup(ColourSelect1, ColourSelect2);
        strip.setPixelColor(k - 1, LocationColour);
        strip.show();
        PrevLoc = k - 1;
      }
      SensorReadState = 1;
      //Serial.println(k);
      MoveComplete = 0;
      com.TeensyToPi(k - 1);
      // PrevMove1 = k - 1;
      //break;
    }
  }
  while (SensorReadState == 1) { //looks for a piece to be returned (keep checking while tiles are still empty) //
    //pLayout = boardLayout();  //poll all sensors
    for (int j = 1; j <= 4; j++)  {
      //  MenuNavigation();
      if (j == 1) {
        for (int i = 1; i <= 16; i++)  {
          setMx.setMux(i - 1);
          float volt = readV.readVoltage(muxOut1);
          if (volt >= 1.10 || volt <= 0.90) { //piece is there
            pLayout1[i] = true;
          }
          else { //Empty (no piece)
            pLayout1[i] = false;
          }
        }
      }
      else if (j == 2) {
        for (int i = 1; i <= 16; i++)  {
          setMx.setMux(i - 1);
          float volt = readV.readVoltage(muxOut2);
          if (volt >= 1.10 || volt <= 0.90) { //piece is there
            pLayout1[i + 16] = true;
          }
          else { //Empty (no piece)
            pLayout1[i + 16] = false;
          }
        }
      }
      else if (j == 3) {
        for (int i = 1; i <= 16; i++)  {
          setMx.setMux(i - 1);
          float volt = readV.readVoltage(muxOut3);
          if (volt >= 1.10 || volt <= 0.90) { //piece is there
            pLayout1[i + 32] = true;
          }
          else { //Empty (no piece)
            pLayout1[i + 32] = false;
          }
        }
      }
      else if (j == 4) {
        for (int i = 1; i <= 16; i++)  {
          setMx.setMux(i - 1);
          float volt = readV.readVoltage(muxOut4);
          if (volt >= 1.10 || volt <= 0.90) { //piece is there
            pLayout1[i + 48] = true;
          }
          else { //Empty (no piece)
            pLayout1[i + 48] = false;
          }
        }
      }
    }
    for (int k = 1; k <= 64; k++)  {
      if (pLayout1[k] == true && pLayout2[k] == false) { //checks that a piece has been returned
        //  Serial.MoveComplete("Piece returned to ");
        SensorReadState = 0;
        if (IllegalMoveFlag == 0) {
          strip.setPixelColor(k - 1, AllowedColour);
          strip.show();
        }
        NewLoc = k - 1;
        MoveComplete = 1;
        com.TeensyToPi(k - 1);
        //PrevMove2 = k - 1;
        //delay(2000);
        // BoardSetup(ColourSelect1, ColourSelect2);
      }
    }
    delay(50);
    for (int j = 1; j <= 4; j++)  {
      // MenuNavigation();
      if (j == 1) {
        for (int i = 1; i <= 16; i++)  {
          setMx.setMux(i - 1);
          float volt = readV.readVoltage(muxOut1);
          if (volt >= 1.10  || volt <= 0.90) { //piece is there
            pLayout2[i] = true;
          }
          else { //Empty (no piece)
            pLayout2[i] = false;
          }
        }
      }
      else if (j == 2) {
        for (int i = 1; i <= 16; i++)  {
          setMx.setMux(i - 1);
          float volt = readV.readVoltage(muxOut2);
          if (volt >= 1.10  || volt <= 0.90) { //piece is there
            pLayout2[i + 16] = true;
          }
          else { //Empty (no piece)
            pLayout2[i + 16] = false;
          }
        }
      }
      else if (j == 3) {
        for (int i = 1; i <= 16; i++)  {
          setMx.setMux(i - 1);
          float volt = readV.readVoltage(muxOut3);
          if (volt >= 1.10  || volt <= 0.90) { //piece is there
            pLayout2[i + 32] = true;
          }
          else { //Empty (no piece)
            pLayout2[i + 32] = false;
          }
        }
      }
      else if (j == 4) {
        for (int i = 1; i <= 16; i++)  {
          setMx.setMux(i - 1);
          float volt = readV.readVoltage(muxOut4);
          if (volt >= 1.10  || volt <= 0.90) { //piece is there
            pLayout2[i + 48] = true;
          }
          else { //Empty (no piece)
            pLayout2[i + 48] = false;
          }
        }
      }
    }
    for (int k = 1; k <= 64; k++)  {
      if (pLayout1[k] == false && pLayout2[k] == true) { //checks that a piece has been returned
        //  Serial.MoveComplete("Piece returned to ");
        SensorReadState = 0;
        if (IllegalMoveFlag == 0) {
          strip.setPixelColor(k - 1, AllowedColour);
          strip.show();
        }
        NewLoc = k - 1;
        MoveComplete = 1;
        com.TeensyToPi(k - 1);
        //PrevMove2 = k - 1;
        //delay(2000);
        // BoardSetup(ColourSelect1, ColourSelect2);
      }
    }
  }
}