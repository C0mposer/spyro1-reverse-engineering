#include <common.h>
#include <moby.h>

//**********************************
// ** Function: DrawTextCaoutals
// ** Original Address: 0x80017fe4
// ** Hook File: draw_text_capitals_hook.s 
// ** Prototype: n/a
//**********************************
/*
 * Draws capital text to the screen (technically fills out the moby structs from arguments)
 * @param char* text - text to be drawn.
 * @param int* textInfo - pointer to the desired location and size of the text.
 * @param int spacing - how much space between characters.
 * @param char color - color.
*/

char* DrawTextCapitals(char *text,int *textInfo, int spacing, char color)

{
  unsigned int currentCharacter;                                                //? Needs to be unsigned lmao?

  currentCharacter = *text;                                                     //Puts first character of string in currentcCharacter

  while (currentCharacter != 0) {                                               //Not a NULL terminator
    if (currentCharacter != 0x20) {                                             //Not a space character
      _ptr_HudMobyData = _ptr_HudMobyData - MOBY_SIZE;                          //Shifts the moby pointer to a new empty slot
      memset(_ptr_HudMobyData, 0, MOBY_SIZE);                                   //Clears the new slot
      Vec3Copy((int *)(_ptr_HudMobyData + 0xc),textInfo);                       //Copy text x pos, y pos, and size(z pos) to the new moby
      currentCharacter = *text;                                                 //Puts each character of the string in currentCharacter each iteration of the loop
      if(currentCharacter - '0' < 10) {                                         //If currentCharacter 0-9
        *(unsigned short *)(_ptr_HudMobyData + 0x36) = currentCharacter + 0xd4;         
      }
      else if(currentCharacter - 'A' < 26) {                                    //If currentCharacter is A-Z
        *(unsigned short *)(_ptr_HudMobyData + 0x36) = currentCharacter + 0x169;        
      }
      else {          
        short mobyType;                                                          //Special Characters
        if(currentCharacter == '/') {
          mobyType = 0x115;
        }
        else if(currentCharacter == '?') {
          mobyType = 0x116;
        }
        else if(currentCharacter == '%') {
          mobyType = 0x110;
        }
        else if(currentCharacter == '^') {
          mobyType = 0x141;
        }
        else if(currentCharacter == '+') {
          mobyType = 0x13d;
          }
        else {                                                                  //Default Character (_)
          mobyType = 0x147;
        }
        *(short *)(_ptr_HudMobyData + 0x36) = mobyType;
      }
      _ptr_HudMobyData[0x47] = 0x7f;
      _ptr_HudMobyData[0x4f] = color;
      _ptr_HudMobyData[0x50] = 0xff;
    }
    text++;                                                                     //Move to next char in String
    textInfo[0] += spacing;                                                     //The x position in the textInfo struct is increased by the spacing amount
    currentCharacter = *text;                                                   //currentCharacter is updated to the next character
  }
  //printf("my print: %X\n", _ptr_HudMobyData);
  return _ptr_HudMobyData;
}