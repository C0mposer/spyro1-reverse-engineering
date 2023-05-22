#include <common.h>

//**********************************
// ** Function: DrawTextCaoutals
// ** Original Address: 0x80017fe4
// ** Hook File: draw_text_capitals.s 
// ** Prototype: n/a
//**********************************
/*
 * Draws capital text to the screen (technically fills out the moby structs from arguments)
 * @param char* text - text to be drawn.
 * @param int* textInfo - pointer to the desired location and size of the text.
 * @param int spacing - how much space between characters.
 * @param char color - color.
*/

//extern struct MobyStruct ptr_mobys;
#define MOBY_SIZE 0x58

char* DrawTextCapitals(char *text,int *textInfo, int spacing, char color)

{
  char currentCharacter;
  short uVar2;
  
  currentCharacter = *text;
  while (currentCharacter != 0) {                                       //Not an end character
    if (currentCharacter != 0x20) {                                     //Not a space
      _ptr_HudMobyData = _ptr_HudMobyData - MOBY_SIZE;                                //Shifts the moby pointer to a new empty slot
      memset(_ptr_HudMobyData, 0, MOBY_SIZE);                                  //Clears the new slot
      Vec3Copy((int *)(_ptr_HudMobyData + 0xc),textInfo);                      //Copy text x pos, y pos, and size to the new moby
      currentCharacter = *text;                                         //Puts the first character into a new variable
      if (currentCharacter - '0' < 10) {                                //If the character is 0-9
        *(short *)(_ptr_HudMobyData + 0x36) = currentCharacter + 0xd4;         //
      }
      else if (currentCharacter - 'A' < 26) {                           //If the character is A-Z
        *(short *)(_ptr_HudMobyData + 0x36) = currentCharacter + 0x169;        //
      }
      else {
        if (currentCharacter == '/') {
          uVar2 = 0x115;
        }
        else if (currentCharacter == '?') {
          uVar2 = 0x116;
        }
        else if (currentCharacter == '%') {
          uVar2 = 0x110;
        }
        else if (currentCharacter == '^') {
          uVar2 = 0x141;
        }
        else {
          uVar2 = 0x147;
          if (currentCharacter == '+') {
            uVar2 = 0x13d;
          }
        }
        *(short *)(_ptr_HudMobyData + 0x36) = uVar2;
      }
      _ptr_HudMobyData[0x47] = '\x7f';
      _ptr_HudMobyData[0x4f] = color;
      _ptr_HudMobyData[0x50] = 0xff;
    }
    text = (char *)((char *)text + 1);                                  //textBuf pointer is moved to the next character
    *textInfo = *textInfo + spacing;                                    //The x position in the textInfo struct is increased by the spacing amount
    currentCharacter = *text;                                           //currentCharacter is updated to the next character
  }
  return _ptr_HudMobyData;
}