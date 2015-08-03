/*This is free and unencumbered software released into the public domain.
 *
 *Anyone is free to copy, modify, publish, use, compile, sell, or
 *distribute this software, either in source code form or as a compiled
 *binary, for any purpose, commercial or non-commercial, and by any
 *means.
 *
 *In jurisdictions that recognize copyright laws, the author or authors
 *of this software dedicate any and all copyright interest in the
 *software to the public domain. We make this dedication for the benefit
 *of the public at large and to the detriment of our heirs and
 *successors. We intend this dedication to be an overt act of
 *relinquishment in perpetuity of all present and future rights to this
 *software under copyright law.
 *
 *For more information, please refer to <http://unlicense.org>
*/

#ifndef KeyMatrix8x8_h
#define KeyMatrix8x8_h

#include <avr/pgmspace.h>

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class KeyMatrix8x8
{
  private:
    //For storing the Pins for the Rows and the columns
    byte ROW1, ROW2, ROW3, ROW4, COL1, COL2, COL3, COL4;
    //for reading the keymatrix
    byte readKeys();
  
  public:
    //constructor
    KeyMatrix8x8(byte row1,byte row2,byte row3,byte row4,byte column1,byte column2,byte column3,byte column4);
    //for reading keymatrix inclusive some contolling code to keep the lines HIGH
    byte readKeyMatrix();
};

#endif
