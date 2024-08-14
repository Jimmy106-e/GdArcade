/*************************************************************************
 * Header file for GameTutorial - 
 * Contains bitmaps that determine appearance of sprites
 * 
 * Written by: Brandon Farmer for TinyCircuits
 * 
 * Initiated: 03/27/2017 
 * Updated: 07/05/2018
 ************************************************************************/

#include <TinyScreen.h> // Used for the color variables available on the TinyScreen+

extern const uint8_t ALPHA;

unsigned char GDCUBE8[64] = {
  TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black,
  TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black,
  TS_8b_Black, TS_8b_Yellow, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, TS_8b_Yellow, TS_8b_Black,
  TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black,
  TS_8b_Black, TS_8b_Yellow, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, TS_8b_Yellow, TS_8b_Black,
  TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black, TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black,
  TS_8b_Black, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Yellow, TS_8b_Black,
  TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black,
};

unsigned char spike[64] = {
  ALPHA, ALPHA, ALPHA, TS_8b_Black, TS_8b_Black, ALPHA, ALPHA, ALPHA,
  ALPHA, ALPHA, ALPHA, TS_8b_Black, TS_8b_Black, ALPHA, ALPHA, ALPHA,
  ALPHA, ALPHA, TS_8b_Black, TS_8b_Gray, TS_8b_Gray, TS_8b_Black, ALPHA, ALPHA,
  ALPHA, ALPHA, TS_8b_Black, TS_8b_Gray, TS_8b_Gray, TS_8b_Black, ALPHA, ALPHA,
  ALPHA, TS_8b_Black, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Black, ALPHA,
  ALPHA, TS_8b_Black, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Black, ALPHA,
  TS_8b_Black, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Black,
  TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, 
};

unsigned char block[64] = {
  TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, 
  TS_8b_Black, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Black,
  TS_8b_Black, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Black,
  TS_8b_Black, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Black,
  TS_8b_Black, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Black,
  TS_8b_Black, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Black,
  TS_8b_Black, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Gray, TS_8b_Black,
  TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black, TS_8b_Black,
};

