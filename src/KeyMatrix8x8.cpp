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

#include "KeyMatrix8x8.h"

//constructor
KeyMatrix8x8::KeyMatrix8x8(byte row1,byte row2,byte row3,byte row4,byte column1,byte column2,byte column3,byte column4)
{
  ROW1=row1;
  ROW2=row2;
  ROW3=row3;
  ROW4=row4;
  COL1=column1;
  COL2=column2;
  COL3=column3;
  COL4=column4;
  ///declaring the row-pins as outputs
  pinMode(ROW1,OUTPUT);
  pinMode(ROW2,OUTPUT);
  pinMode(ROW3,OUTPUT);
  pinMode(ROW4,OUTPUT);
  //declaring the column-pins as inputs with pullup-resistors
  pinMode(COL1,INPUT_PULLUP);
  pinMode(COL2,INPUT_PULLUP);
  pinMode(COL3,INPUT_PULLUP);
  pinMode(COL4,INPUT_PULLUP);
};

//turns the Pin HIGH which was used when "readKeys()" returned the value
byte KeyMatrix8x8::readKeyMatrix()
{
  byte temp=readKeys();
  if(temp>0 && temp<5)
    digitalWrite(ROW1,HIGH);
  else if(temp>4 && temp<9)
    digitalWrite(ROW2,HIGH);
  else if(temp>8 && temp<13)
    digitalWrite(ROW3,HIGH);
  else if(temp>12 && temp<17)
    digitalWrite(ROW4,HIGH);
  return temp;
};

//goes thrue every line and looks for a pressed butten
byte KeyMatrix8x8::readKeys()
{
  //reading the first row
  digitalWrite(ROW1,LOW);
  if(!digitalRead(COL1))
    return 1;
  else if(!digitalRead(COL2))
    return 2;
  else if(!digitalRead(COL3))
    return 3;
  else if(!digitalRead(COL4))
    return 4;
  digitalWrite(ROW1,HIGH);
  //reading the second row
  digitalWrite(ROW2,LOW);
  if(!digitalRead(COL1))
    return 5;
  else if(!digitalRead(COL2))
    return 6;
  else if(!digitalRead(COL3))
    return 7;
  else if(!digitalRead(COL4))
    return 8;
  digitalWrite(ROW2,HIGH);
  //reading the third row
  digitalWrite(ROW3,LOW);
  if(!digitalRead(COL1))
    return 9;
  else if(!digitalRead(COL2))
    return 10;
  else if(!digitalRead(COL3))
    return 11;
  else if(!digitalRead(COL4))
    return 12;
  digitalWrite(ROW3,HIGH);
  //reading the fourth row
  digitalWrite(ROW4,LOW);
  if(!digitalRead(COL1))
    return 13;
  else if(!digitalRead(COL2))
    return 14;
  else if(!digitalRead(COL3))
    return 15;
  else if(!digitalRead(COL4))
    return 16;
  digitalWrite(ROW4,HIGH);
    return 0;
};
