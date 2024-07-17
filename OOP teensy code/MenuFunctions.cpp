#include "MenuFunctions.h"
//#include "Colour.h"
#include "Com.h"
#include "Globals.h"
#include "Colour.h"
//Com com;

MenuFunctions::MenuFunctions()
{
  ;

}

void MenuFunctions::MenuTextDisplay(int Display) {
  switch (Display) {
    case 1: //Home Screen
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("  Start Game");
      display.setCursor(0, 40);  display.print ("  Colour Themes");
      display.setCursor(0, 60);  display.print ("  Settings");
      break;
    case 2: //Single Player Prestart
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("  Game Mode");
      display.setCursor(0, 40);  display.print ("  Player vs Player");
      display.setCursor(0, 60);  display.print ("  Player vs AI");
      display.setCursor(0, 80);  display.print ("  Back");
      break;
    case 3: //Two Player Prestart
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("  Player 1 is");
      display.setCursor(0, 40);  display.print ("  Black");
      display.setCursor(0, 60);  display.print ("  White");
      display.setCursor(0, 80);  display.print ("  Back");
      break;
    case 4: //Difficulty
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("  Difficulty");
      display.setCursor(0, 40);  display.print ("  Easy");
      display.setCursor(0, 60);  display.print ("  Medium");
      display.setCursor(0, 80);  display.print ("  Hard");
      display.setCursor(0, 100);  display.print ("  Back");
      break;
    case 5: //Colour Scroll 1
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("  Start Game");
      display.setCursor(0, 40);  display.print (GameModeDisplay);
      display.setCursor(0, 60);  display.print (P1ColourDisplay);
      display.setCursor(0, 80);  display.print (DifficultyDisplay);
      display.setCursor(0, 100);  display.print ("  Back");
      display.setCursor(0, 120);  display.print ("  Main Menu");
      break;
    case 6: //Colour Themes
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("  Colour 1");
      display.setCursor(0, 40);  display.print ("  Colour 2");
      display.setCursor(0, 60);  display.print ("  Back");
      break;
    case 7: //Colour Scroll 1
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("  No Colour");
      display.setCursor(0, 40);  display.print ("  White");
      display.setCursor(0, 60);  display.print ("  Red");
      display.setCursor(0, 80);  display.print ("  Green");
      display.setCursor(0, 100);  display.print ("  Blue");
      display.setCursor(0, 120);  display.print ("  Yellow");
      break;
    case 8: //Colour Scroll 2
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("  Orange");
      display.setCursor(0, 40);  display.print ("  Pink");
      display.setCursor(0, 60);  display.print ("  Purple");
      display.setCursor(0, 80);  display.print ("  Teal");
      display.setCursor(0, 100);  display.print ("  Light Blue");
      display.setCursor(0, 120);  display.print ("  Olive");
      break;
    case 9: //Settings
      display.setTextColor(TColour);
      //display.setCursor(0, 20);  display.print ("  Move Timer"); //Move Timer not used
      display.setCursor(0, 20);  display.print ("  Brightness");
      display.setCursor(0, 40);  display.print ("  Power Saver");
      display.setCursor(0, 60);  display.print ("    "); display.print (PowerSaver);
      display.setCursor(0, 80);  display.print ("  Back");
      break;
    case 10: //Game Timer
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("  Set Timer");
      display.setCursor(0, 40);  display.print ("  No Timer");
      display.setCursor(0, 60);  display.print ("  Back");
      break;
    case 11: //Set Timer
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("  Increase");
      display.setCursor(0, 40);  display.print ("  "); display.print (MoveTimerDisplay);  display.print(" Mins");
      display.setCursor(0, 60);  display.print ("  Decrease");
      display.setCursor(0, 80);  display.print ("  Confirm");
      display.setCursor(0, 100);  display.print ("  Back");
      break;
    case 12: //Brightness
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("  Increase");
      display.setCursor(0, 40);  display.print ("  "); display.print (BrightnessDisplay * 2); display.print ("%");
      display.setCursor(0, 60);  display.print ("  Decrease");
      display.setCursor(0, 80);  display.print ("  Confirm");
      display.setCursor(0, 100);  display.print ("  Back");
      break;
    case 13: //In Game Menu
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("  Hint");
      display.setCursor(0, 40);  display.print ("  Player Assists");
      display.setCursor(0, 60);  display.print ("  Restart Game");
      display.setCursor(0, 80);  display.print ("  Exit Game");
	  display.setCursor(0, 100);  display.print ("  Threats");
      break;
    case 14: //Player Assists
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("  Player Assists");
      display.setCursor(0, 40);  display.print ("   ");  display.print (P1Assists);
      display.setCursor(0, 60);  display.print ("  Back");
      break;
    case 15: //Are you sure (Restart)
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("  Are you sure?");
      display.setCursor(0, 40);  display.print ("  Yes");
      display.setCursor(0, 60);  display.print ("  No");
      break;
    case 16: //Are you sure (Exit)
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("  Are you sure?");
      display.setCursor(0, 40);  display.print ("  Yes");
      display.setCursor(0, 60);  display.print ("  No");
      break;
    case 17: //Printing colour
      display.setTextColor(TColour);
      display.setCursor(0, 40);  display.print ("  Colour Printing");
      display.setCursor(0, 80);  display.print ("     Please Wait");
      break;
    case 18: //Requesting Hint
      display.setTextColor(TColour);
      display.setCursor(0, 40);  display.print ("  Requesting Hint");
      display.setCursor(0, 80);  display.print ("     Please Wait");
      break;
    case 19: //Calculating AI Move
      display.setTextColor(Green);
      display.setCursor(0, 40);  display.print ("      AI Move");
      display.setTextColor(TColour);
      display.setCursor(0, 80);  display.print ("    Please Wait");
      break;
    case 20: //Starting Game
      display.setTextColor(TColour);
      display.setCursor(0, 40);  display.print ("    Starting Game");
      display.setCursor(0, 80);  display.print ("     Please Wait");
      break;
    case 21: //Illegal Move
      display.setTextColor(Red);
      display.setCursor(0, 20);  display.print ("    Illegal Move");
      display.setTextColor(TColour);
      display.setCursor(0, 60);  display.print ("Please Return To");
      display.setCursor(0, 80);  display.print ("    Yellow Tile");
      break;
    case 22: //White wins
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("    White Wins");
      display.setCursor(0, 60);  display.print ("    Game Over");
      break;
    case 23: //Black wins
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("    Black Wins");
      display.setCursor(0, 60);  display.print ("    Game Over");
      break;
    case 24: //Draw
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("      Draw");
      display.setCursor(0, 60);  display.print ("    Game Over");
      break;
    case 25: //Pawn Promotion
      display.setTextColor(TColour);
      display.setCursor(0, 20);  display.print ("  Promote To");
      display.setCursor(0, 40);  display.print ("  Queen");
      display.setCursor(0, 60);  display.print ("  Bishop");
      display.setCursor(0, 80);  display.print ("  Rook");
      display.setCursor(0, 100);  display.print ("  Knight");
      break;
    default:
      break;
  }
}

void MenuFunctions::MenuArrowDisplay(int ArrowPos) {
  switch (ArrowPos) {
    case 1:
      display.setTextColor(TColour); display.setCursor(0, 20);  display.print (">"); //Highlighted option
      display.setTextColor(Black); display.setCursor(0, 40);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 60);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 80);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 100);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 120);  display.print (">");
      break;
    case 2:
      display.setTextColor(Black); display.setCursor(0, 20);  display.print (">");
      display.setTextColor(TColour); display.setCursor(0, 40);  display.print (">"); //Highlighted option
      display.setTextColor(Black); display.setCursor(0, 60);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 80);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 100);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 120);  display.print (">");
      break;
    case 3:
      display.setTextColor(Black); display.setCursor(0, 20);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 40);  display.print (">");
      display.setTextColor(TColour); display.setCursor(0, 60);  display.print (">"); //Highlighted option
      display.setTextColor(Black); display.setCursor(0, 80);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 100);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 120);  display.print (">");
      break;
    case 4:
      display.setTextColor(Black); display.setCursor(0, 20);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 40);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 60);  display.print (">");
      display.setTextColor(TColour); display.setCursor(0, 80);  display.print (">"); //Highlighted option
      display.setTextColor(Black); display.setCursor(0, 100);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 120);  display.print (">");
      break;
    case 5:
      display.setTextColor(Black); display.setCursor(0, 20);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 40);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 60);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 80);  display.print (">");
      display.setTextColor(TColour); display.setCursor(0, 100);  display.print (">"); //Highlighted option
      display.setTextColor(Black); display.setCursor(0, 120);  display.print (">");
      break;
    case 6:
      display.setTextColor(Black); display.setCursor(0, 20);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 40);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 60);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 80);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 100);  display.print (">");
      display.setTextColor(TColour); display.setCursor(0, 120);  display.print (">"); //Highlighted option
      break;
    case 7: //No Cursor
      display.setTextColor(Black); display.setCursor(0, 20);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 40);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 60);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 80);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 100);  display.print (">");
      display.setTextColor(Black); display.setCursor(0, 120);  display.print (">");
      break;
    default:
      break;
  }
}

void MenuFunctions::MenuNavigation() {
  int readingUp = digitalRead(UpButton);
  int readingDown = digitalRead(DownButton);
  int readingBack = digitalRead(BackButton);
  int readingSelect = digitalRead(SelectButton);

  if (ButtonStateChanged(readingUp, lastButtonStateUp) || 
      ButtonStateChanged(readingDown, lastButtonStateDown) || 
      ButtonStateChanged(readingBack, lastButtonStateBack) || 
      ButtonStateChanged(readingSelect, lastButtonStateSelect)) {
    lastDebounceTime = millis();
  }

  if (IsDebounced()) {
    if (readingUp != buttonStateUp) {
      buttonStateUp = readingUp;
      HandleUpButtonPress();
	  MenuArrowDisplay(ArrowPos); // Update arrow position
    }

    if (readingDown != buttonStateDown) {
      buttonStateDown = readingDown;
      HandleDownButtonPress();
	  MenuArrowDisplay(ArrowPos); // Update arrow position
    }

    if (readingBack != buttonStateBack) {
      buttonStateBack = readingBack;
      HandleBackButtonPress();
	  MenuArrowDisplay(ArrowPos); // Update arrow position
    }

    if (readingSelect != buttonStateSelect) {
      buttonStateSelect = readingSelect;
      HandleSelectButtonPress();
	  MenuArrowDisplay(ArrowPos); // Update arrow position
    }
  }

  lastButtonStateUp = readingUp;
  lastButtonStateDown = readingDown;
  lastButtonStateBack = readingBack;
  lastButtonStateSelect = readingSelect;
  
  if (Menu != PrevMenu) {
    MenuTextDisplay(Display);
  }
  PrevMenu = Menu;
}

bool MenuFunctions::ButtonStateChanged(int current, int last) {
  return current != last;
}

bool MenuFunctions::IsDebounced() {
  return (millis() - lastDebounceTime) > debounceDelay;
}

void MenuFunctions::HandleUpButtonPress() {
  // Handle the Up button press here
  // ...
      if (readingUp != buttonStateUp) {
      buttonStateUp = readingUp;
      if (buttonStateUp == HIGH) { //up button pressed
        Menu = Menu - 1;
        ArrowPos--;
        if (Menu == 20 || Menu == 30 || Menu == 40 || Menu == 121 || Menu == 140 || Menu == 150 || Menu == 155 || Menu == 111 || Menu == 170) { //skip display line (move two positions)
          ArrowPos--;
          Menu = Menu - 1;
        }
        if (ArrowPos == 0) { //when arrow reaches the top of the screen drop to last available option
          ArrowPos = OptionNum;
        }
        if (Menu == 9 || Menu == 19 || Menu == 29 || Menu == 39 || Menu == 49 || Menu == 59 || Menu == 89 || Menu == 99 || Menu == 109 || Menu == 119 || Menu == 129 || Menu == 139 || Menu == 149 || Menu == 154 || Menu == 169) { //when it reaches the top of the screen drop to bottom menu option 
          Menu = Menu + OptionNum;
        }
        else if (Menu == 77) { // if it is in colour selection then scroll up
          Display = 7;
          display.fillScreen(Black);
          MenuTextDisplay(Display);
          Menu = 75;
          ArrowPos = OptionNum;
        }
        else if (Menu == 69) {
          Display = 8;
          display.fillScreen(Black);
          MenuTextDisplay(Display);
          Menu = 83;
          ArrowPos = OptionNum;
        }
      }
      MenuArrowDisplay(ArrowPos);
    }

}

void MenuFunctions::HandleDownButtonPress() {
  // Handle the Down button press here
  // ...
      if (readingDown != buttonStateDown) {
      buttonStateDown = readingDown;
      if (buttonStateDown == HIGH) {
        Menu = Menu + 1;
        ArrowPos++;
        if (Menu == 13 || Menu == 24 || Menu == 34 || Menu == 45 || Menu == 56 || Menu == 63 || Menu == 94 || Menu == 103 || Menu == 115 || Menu == 125 || Menu == 135 || Menu == 143 || Menu == 153 || Menu == 158 || Menu == 175) {
          Menu = Menu - OptionNum;
        }
        else if (Menu == 76) {
          Display = 8;
          ArrowPos = 1;
          display.fillScreen(Black);
          MenuTextDisplay(Display);
          Menu = 78;
        }
        else if (Menu == 64) {
          Display = 7;
          ArrowPos = 1;
          display.fillScreen(Black);
          MenuTextDisplay(Display);
          Menu = 70;
        }
        if (Menu == 111 || Menu == 121) { //skip the display line (move two positions
          ArrowPos++;
          Menu = Menu + 1;
        }
        if (ArrowPos == OptionNum + 1) { //when the arrow reaches the bottom go back to top
          ArrowPos = 1;
        }
        if (Menu == 20 || Menu == 30 || Menu == 40 || Menu == 140 || Menu == 150 || Menu == 155 || Menu == 170) {
          ArrowPos++;
          Menu = Menu + 1;
        }
      }
      MenuArrowDisplay(ArrowPos);
    }

}

void MenuFunctions::HandleBackButtonPress() {
  // Handle the Back button press here
  // ...
      if (readingBack != buttonStateBack) {
      buttonStateBack = readingBack;
      if (buttonStateBack == HIGH) {
        if (Menu > 9 && Menu < 24 || Menu > 59 && Menu < 63 || Menu > 89 && Menu < 95) { //Start Game, Colour Themes or Settings
          Display = 1;
          OptionNum = 3;
          Menu = 10;
        }
        else if (Menu > 19 && Menu < 24) { //Game Mode
          Display = 1;
          OptionNum = 3;
          Menu = 10;
        }
        else if (Menu > 29 && Menu < 34) { //Piece Colour
          Display = 2;
          OptionNum = 4;
          Menu = 21;
        }
        else if (Menu > 39 && Menu < 44) { //Difficulty
          Display = 3;
          OptionNum = 4;
          Menu = 31;
        }
        else if (Menu > 49 && Menu < 56) { //Start Game
          Display = 4;
          OptionNum = 5;
          Menu = 41;
        }
        else if (Menu > 69 && Menu < 84) { //Colour Selection
          Display = 6;
          OptionNum = 3;
          Menu = 60;
        }
        else if (Menu > 99 && Menu < 103 || Menu > 119 && Menu < 125) { //Game Timer or Brightness
          Display = 9;
          OptionNum = 4;
          Menu = 90;
        }
        else if (Menu == 0) {
          IllegalOverride = 1;
        }
        else if (Menu > 109 && Menu < 115) { //Set Timer
          Display = 10;
          OptionNum = 3;
          Menu = 100;
          MoveTimerDisplay = MoveTimer;
        }
        else if (Menu > 129 && Menu < 135) { //In Game Menu
          Menu = 130;
        }
        else if (Menu > 139 && Menu < 158) { //Player Assists, Restart Game or Exit Game
          Display = 13;
          OptionNum = 5;//used to be 4
          Menu = 130;
        }
        else if (Menu > 169 && Menu < 175) { //Player Assists, Restart Game or Exit Game
          Display = 25;
          OptionNum = 5;
          Menu = 171;
        }
      }
      display.fillScreen(Black);
      if (Menu == 21 || Menu == 31 || Menu == 41 || Menu == 151 || Menu == 156 || Menu == 171) { //setting arrow position for the different screens
        ArrowPos = 2;
      }
      else {
        ArrowPos = 1;
      }
      MenuArrowDisplay(ArrowPos);
      MenuTextDisplay(Display);
    }

}

void MenuFunctions::HandleSelectButtonPress() {
  // Handle the Select button press here
  // ...
      if (readingSelect != buttonStateSelect) {
      buttonStateSelect = readingSelect;
      if (buttonStateSelect == HIGH) {
        if (Menu == 10 || Menu == 33 || Menu == 51) { //Start Game or Back
          Display = 2;
          OptionNum = 4;
          Menu = 21;
        }
        else if (Menu == 11) { //Colour Themes
          Display = 6;
          OptionNum = 3;
          Menu = 60;
        }
        else if (Menu == 12 || Menu == 101 || Menu == 102 || Menu == 123 || Menu == 124) { //Settings
          if (Menu == 123) {
            Brightness = BrightnessDisplay;
          }
          else if (Menu == 124) {
            BrightnessDisplay = Brightness;
            strip.setBrightness(Brightness);
            strip.show(); // Initialize all pixels to 'off'
          }
          Display = 9;
          OptionNum = 4;
          Menu = 90;
        }
        else if (Menu == 21 || Menu == 22 || Menu == 44 || Menu == 52) { //Player vs Player, Player vs AI or Back
          if (Menu == 21) {
            GameMode = "p"; //raspberry pi communication
            GameModeDisplay = "  Player vs Player";
            AIGame = false;
          }
          else if (Menu == 22) {
            GameMode = "a"; //raspberry pi communication
            AIGame = true;
            GameModeDisplay = "  Player vs AI";
          }
          Display = 3;
          OptionNum = 4;
          Menu = 31;
        }
        else if (Menu == 0 || Menu == 23 || Menu == 55 || Menu == 62 || Menu == 93 || Menu == 156) { //Back to Main Menu
          Display = 1;
          OptionNum = 3;
          Menu = 10;
          if (Menu == 156) {
            colour.BoardSetup(ColourSelect1, ColourSelect2);
          }
        }
        else if (Menu == 31 || Menu == 32 || Menu == 53) { //Player 1 chose Black Pieces or Player 1 chose White Pieces
          if (Menu == 31) {
            P1Colour = "b"; //raspberry pi communication
            P1ColourDisplay = "  Black";
          }
          else if (Menu == 32) {
            P1Colour = "w"; //raspberry pi communication
            P1ColourDisplay = "  White";
          }
          if (AIGame == true) {
            Display = 4;
            OptionNum = 5;
            Menu = 41;
          }
          else if (AIGame == false) {
            Display = 5;
            OptionNum = 6;
            Menu = 50;
            DifficultyDisplay = "  N/A";
          }
        }
        else if (Menu == 41 || Menu == 42 || Menu == 43 || Menu == 54) { //Easy, Medium, Hard or back
          if (Menu == 41) {
            Difficulty = "e"; //raspberry pi communication
            DifficultyDisplay = "  Easy";
          }
          else if (Menu == 42) {
            Difficulty = "m"; //raspberry pi communication
            DifficultyDisplay = "  Medium";
          }
          else if (Menu == 43) {
            Difficulty = "h"; //raspberry pi communication
            DifficultyDisplay = "  Hard";
          }
          Display = 5;
          OptionNum = 6;
          Menu = 50;
        }
        else if (Menu == 50 || Menu == 151) {
          if (AIGame == true) {
            GameSettings = "s" + GameMode + P1Colour + Difficulty + "s"; //combine communication into one line
            Serial.println(GameSettings); //send raspberry pi communication
            Display = 20;
            display.fillScreen(Black);
            MenuTextDisplay(Display);
            while (Serial.available()) Serial.read();
            while (!Serial.available()); //wait for confirmation from pi
            if (P1Colour == "b") { //if player is black then AI starts
              Display = 19;
              AIMove = 1;
              display.fillScreen(Black);
              MenuTextDisplay(Display);
              colour.BoardSetup(ColourSelect1, ColourSelect2);
              Serial.println("-");
              Serial.println("a"); //request AI move
            }
            else {
              Serial.println("-");
            }
          }
          else if (AIGame == false) {
            GameSettings = "s" + GameMode + P1Colour + "s"; //combine communication into one line
            AIMove = 0;
            Serial.println(GameSettings); //send raspberry pi communication
            Display = 20;
            display.fillScreen(Black);
            MenuTextDisplay(Display);
            colour.BoardSetup(ColourSelect1, ColourSelect2);
            Serial.println("-");

          }
          while (Serial.available()) Serial.read();
          while (!Serial.available());
          CommsInput = Serial.readStringUntil("*");
          com.TeensyInput(CommsInput);
          //BoardSetup(ColourSelect1, ColourSelect2);
          Display = 13;
          OptionNum = 5;//used to be 4
          Menu = 130;
          for (int i = 0; i < 64; i++) { //set magnet array to 0
            pLayout1[i] = 0;
            pLayout2[i] = 0;
          }
        }
        else if (Menu == 142 || Menu == 152 || Menu == 157) { //Start Game
          Display = 13;
          OptionNum = 5;//used to be 4
          Menu = 130;
        }

        else if (Menu == 60 || Menu == 61) {
          if (Menu == 60) {
            ColourMenu = 1;
          }
          else if (Menu == 61) {
            ColourMenu = 2;
          }
          Display = 7;
          OptionNum = 6;
          Menu = 70;
        }
        else if (Menu > 69 && Menu < 84) {
          if (ColourMenu == 1) {
            ColourSelect1 = Menu - 70;
            //   Serial.println(ColourSelect1);
          }
          else if (ColourMenu == 2) {
            ColourSelect2 = Menu - 70;
          }
          Display = 17;
          display.fillScreen(Black);
          MenuTextDisplay(Display);
          if (SDActive == 1) { //printing to SD 
            SD.remove("Colours.txt");
            myFile = SD.open("Colours.txt", FILE_WRITE);
            // if the file opened okay, write to it:
            if (myFile) {
              myFile.print("Colour 1 = ");
              myFile.write(ColourSelect1);
              myFile.print(", Colour 2 = ");
              myFile.write(ColourSelect2);
              // close the file:
              myFile.close();
              //Serial.println("File Updated");
            } else {
              // if the file didn't open, print an error:
              Serial.println("error opening test.txt");
            }
          }
          colour.BoardSetup(ColourSelect1, ColourSelect2);
          Display = 6;
          Menu = 60;
          OptionNum = 3;
        }
        /*else if (Menu == 90 || Menu == 113 || Menu == 114) { //Move Timer Code not used
          Display = 10;
          OptionNum = 3;
          Menu = 100;
          if (Menu == 113) {
            MoveTimer = MoveTimerDisplay;
            Serial.print("Timer = ");
            Serial.println(MoveTimer);
          }
          else if (Menu == 114) {
            MoveTimerDisplay = MoveTimer;
          }
        } */ 
        else if (Menu == 90) {
          Display = 12;
          OptionNum = 5;
          Menu = 120;
        }
        else if (Menu == 91 || Menu == 92) {
          if (PowerSaver == "Off") {
            PowerSaver = "On";
            BrightnessDisplay = 20;
            Brightness = BrightnessDisplay / 2;
            strip.setBrightness(Brightness);
            strip.show();
          }
          else {
            PowerSaver = "Off";
            BrightnessDisplay = 35;
            Brightness = BrightnessDisplay;
            strip.setBrightness(Brightness);
            strip.show();
          }
        }
        else if (Menu == 100) {
          Display = 11;
          OptionNum = 5;
          Menu = 110;
        }
        else if (Menu == 110) {
          MoveTimerDisplay = MoveTimerDisplay + 5;
        }
        else if (Menu == 112) {
          MoveTimerDisplay = MoveTimerDisplay - 5;
          if (MoveTimerDisplay == -5) {
            MoveTimerDisplay = 0;
          }
        }
        else if (Menu == 120) {
          BrightnessDisplay = BrightnessDisplay + 5;
          if (BrightnessDisplay == 55) {
            BrightnessDisplay = 50;
          }
          strip.setBrightness(BrightnessDisplay);
          strip.show(); // Initialize all pixels to 'off'
        }
        else if (Menu == 122) {
          BrightnessDisplay = BrightnessDisplay - 5;
          if (BrightnessDisplay == -5) {
            BrightnessDisplay = 0;
          }
          strip.setBrightness(BrightnessDisplay);
          strip.show(); // Initialize all pixels to 'off'
        }
        else if (Menu == 130) {
          Display = 18;
          display.fillScreen(Black);
          MenuTextDisplay(Display);
          Serial.println("h");
          while (Serial.available()) Serial.read();
          while (!Serial.available());
          CommsInput = Serial.readStringUntil("*");
          com.TeensyInput(CommsInput);
          Display = 13;
          Menu = 130;
          OptionNum = 5;//used to be 4
        }
        else if (Menu == 131) {
          Display = 14;
          OptionNum = 3;
          Menu = 141;
        }
        else if (Menu == 132) {
          Display = 15;
          OptionNum = 3;
          Menu = 151;
        }
        else if (Menu == 133) {
          Display = 16;
          OptionNum = 3;
          Menu = 156;
        }
        else if (Menu == 134) {
		    //Display =18;
		      display.fillScreen(Black);
          MenuTextDisplay(Display);
          Serial.println("t");
          //Serial.println("zoinks");
          while (Serial.available()) Serial.read();
          while (!Serial.available());
          //Serial.println("zoinks");
          CommsInput = Serial.readStringUntil("*");
          //Serial.println("zoinks");
          com.TeensyInput(CommsInput);
		      Display = 13;
		      OptionNum = 5;
		      Menu = 130;
		}
        else if (Menu == 0) {
          IllegalOverride = 1;
        }
        else if (Menu == 140 || Menu == 141) { //Player assists
          if (P1Assists == "Off") {
            P1Assists = "On";
          }
          else {
            P1Assists = "Off";
          }
        }
        else if (Menu == 171) { //Pawn Promotion
          PromoSelection = "q";
          WaitingSelection = 0;
        }
        else if (Menu == 172) {
          PromoSelection = "b";
          WaitingSelection = 0;
        }
        else if (Menu == 173) {
          PromoSelection = "r";
          WaitingSelection = 0;
        }
        else if (Menu == 174) {
          PromoSelection = "n";
          WaitingSelection = 0;
        }
      }
      display.fillScreen(Black);
      if (Menu == 91 || Menu == 92 || Menu == 112 || Menu == 122) {

      }
      else if (Menu == 21 || Menu == 31 || Menu == 41 || Menu  == 141 || Menu == 151 || Menu == 156 || Menu == 170) {
        ArrowPos = 2;
      }
      else {
        ArrowPos = 1;
      }
      MenuArrowDisplay(ArrowPos);
      MenuTextDisplay(Display);
    }
  
}
