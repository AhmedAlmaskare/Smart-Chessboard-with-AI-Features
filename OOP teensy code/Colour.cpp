#include "Colour.h"
#define NeoPIN 0
Colour::Colour()
{

//Adafruit_NeoPixel strip = Adafruit_NeoPixel(64, NeoPIN, NEO_GRB + NEO_KHZ800);	

}

void Colour::colorWipe1(uint32_t c, uint8_t wait) {
  int j = 0;
  for (int i = 0; i < strip.numPixels(); i = i + 2) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
    j++;
    if (j == 4) {
      i = i + 1;
    }
    if (j == 8) {
      i = i - 1;
      j = 0;
    }
  }
}

void Colour::colorWipe2(uint32_t c, uint8_t wait) {
  int j = 0;
  for (int i = 1; i < strip.numPixels(); i = i + 2) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
    j++;
    if (j == 4) {
      i = i - 1;
    }
    if (j == 8) {
      i = i + 1;
      j = 0;
    }
  }
}

void Colour::rainbow(int wait) {
  // Hue of first pixel runs 5 complete loops through the color wheel.
  // Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
  // means we'll make 5*65536/256 = 1280 passes through this loop:
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    strip.rainbow(firstPixelHue);
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
	}
}

void Colour::BoardSetup(int ColourSelect1, int ColourSelect2) { //set the first colour depending on selection
  AllowedColour = strip.Color(0, 255, 0); //Show possible moves in Green
  LocationColour = strip.Color(255, 255, 0); //Show current location in Yellow
  CannotMove = strip.Color(255, 0, 0); //Show impossible move in Red
  ColourClash1 = 0;
  ColourClash2 = 0;
  ColourClash3 = 0;
  switch (ColourSelect1) {
    case 0:
      colorWipe1(strip.Color(0, 0, 0), 2); // No Colour
      break;
    case 1:
      colorWipe1(strip.Color(255, 255, 255), 2); // White
      ColourClash1++;
      break;
    case 2:
      colorWipe1(strip.Color(255, 0, 0), 2); // Red
      ColourClash3++;
      CannotMove = strip.Color(255, 128, 0); //Show Cannot Move colour in Orange
      break;
    case 3:
      colorWipe1(strip.Color(0, 255, 0), 2); // Green
      ColourClash1++;
      AllowedColour = strip.Color(255, 255, 255); //Show Allowed Moves in White not Green
      break;
    case 4:
      colorWipe1(strip.Color(0, 0, 255), 2); // Blue
      break;
    case 5:
      colorWipe1(strip.Color(255, 255, 0), 2); // Yellow
      ColourClash2++;
      LocationColour = strip.Color(0, 128, 128); //Show current location in Teal not Yellow
      break;
    case 8:
      colorWipe1(strip.Color(255, 128, 0), 2); // Orange
      ColourClash3++;
      break;
    case 9:
      colorWipe1(strip.Color(255, 0, 255), 2); // Pink
      break;
    case 10:
      colorWipe1(strip.Color(128, 0, 128), 2); // Purple
      break;
    case 11:
      colorWipe1(strip.Color(0, 128, 128), 2); // Teal
      ColourClash2++;
      break;
    case 12:
      colorWipe1(strip.Color(0, 255, 255), 2); // Light Blue
      break;
    case 13:
      colorWipe1(strip.Color(128, 128, 0), 2); // Olive
      break;
    default:
      break;
  }
  switch (ColourSelect2) {
    case 0:
      colorWipe2(strip.Color(0, 0, 0), 2); // No Colour
      break;
    case 1:
      colorWipe2(strip.Color(255, 255, 255), 2); // White
      if (ColourClash1 == 1) {  //If theme colour is Green & White
        AllowedColour = strip.Color(255, 0, 255); //Show allowed moves in Pink
        ColourClash1 = 0;
      }
      break;
    case 2:
      colorWipe2(strip.Color(255, 0, 0), 2); // Red
      CannotMove = strip.Color(255, 128, 0); //Show Cannot Move colour in Orange
      if (ColourClash3 == 1) { //If theme colour is Red & Orange
        CannotMove = strip.Color(0, 0, 128); //Show cannot move colour as Navy Blue
        ColourClash3 = 0;
      }
      break;
    case 3:
      colorWipe2(strip.Color(0, 255, 0), 2); // Green
      AllowedColour = strip.Color(255, 255, 255); //Show Allowed Moves in White
      if (ColourClash1 == 1) {  //If theme colour is Green & White
        AllowedColour = strip.Color(255, 0, 255); //Show allowed moves in Pink
        ColourClash1 = 0;
      }
      break;
    case 4:
      colorWipe2(strip.Color(0, 0, 255), 2); // Blue
      break;
    case 5:
      colorWipe2(strip.Color(255, 255, 0), 2); // Yellow
      LocationColour = strip.Color(0, 128, 128); //Show current location in Teal
      if (ColourClash2 == 1) { //If theme colour is Yellow & Teal
        LocationColour = strip.Color(128, 0, 128); //Show current location in Purple
        ColourClash2 = 0;
      }
      break;
    case 8:
      colorWipe2(strip.Color(255, 128, 0), 2); // Orange
      if (ColourClash3 == 1) { //If theme colour is Red & Orange
        CannotMove = strip.Color(0, 0, 128); //Show cannot move colour as Navy Blue
        ColourClash3 = 0;
      }
      break;
    case 9:
      colorWipe2(strip.Color(255, 0, 255), 2); // Pink
      break;
    case 10:
      colorWipe2(strip.Color(128, 0, 128), 2); // Purple
      break;
    case 11:
      colorWipe2(strip.Color(0, 128, 128), 2); // Teal
      if (ColourClash2 == 1) { //If theme colour is Yellow & Teal
        LocationColour = strip.Color(128, 0, 128); //Show current location in Purple
        ColourClash2 = 0;
      }
      break;
    case 12:
      colorWipe2(strip.Color(0, 255, 255), 2); // Light Blue
      break;
    case 13:
      colorWipe2(strip.Color(128, 128, 0), 2); // Olive
      break;
    default:
      break;
  }
}