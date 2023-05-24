#include <common.h>
#include <moby.h>

//**********************************
// ** Function: DrawTextCaoutals
// ** Original Address: 0x80017fe4
// ** Hook File: draw_text_capitals_hook.s 
// ** Prototype: n/a
//**********************************
/*
 * Draws capital text string to the screen (technically fills out the moby structs from arguments)
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
      _ptr_hudMobyData -= MOBY_SIZE;                          //Shifts the moby pointer to a new empty slot
      memset(_ptr_hudMobyData, 0, MOBY_SIZE);                                   //Clears the new slot
      Vec3Copy((int *)(_ptr_hudMobyData + 0xc),textInfo);                       //Copy text x pos, y pos, and size(z pos) to the new moby
      currentCharacter = *text;                                                 //Puts each character of the string in currentCharacter each iteration of the loop
      if(currentCharacter - '0' < 10) {                                         //If currentCharacter 0-9
        *(unsigned short *)(_ptr_hudMobyData + 0x36) = currentCharacter + 0xd4;         
      }
      else if(currentCharacter - 'A' < 26) {                                    //If currentCharacter is A-Z
        *(unsigned short *)(_ptr_hudMobyData + 0x36) = currentCharacter + 0x169;        
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
        *(short *)(_ptr_hudMobyData + 0x36) = mobyType;
      }
      _ptr_hudMobyData[0x47] = 0x7f;
      _ptr_hudMobyData[0x4f] = color;
      _ptr_hudMobyData[0x50] = 0xff;
    }
    text++;                                                                     //Move to next char in String
    textInfo[0] += spacing;                                                     //The x position in the textInfo struct is increased by the spacing amount
    currentCharacter = *text;                                                   //currentCharacter is updated to the next character
  }
  //printf("my print: %X\n", _ptr_hudMobyData);
  return _ptr_hudMobyData;
}


int DrawTextAll(char *text,int *CapitalTextInfo,int *LowercaseTextInfo,int spacing,char color)

{
  unsigned int currentCharacter;
  bool isCapital;
  int spaceSize;
  
  isCapital = TRUE;
  currentCharacter = *text;
  while (currentCharacter != 0) {                                                          //While not an end character
    if (currentCharacter == 0x20) {                                                        //If a space
      spaceSize = *LowercaseTextInfo * 3;                                           //sets spaceSize
      isCapital = TRUE;                                                         //Character is uppercase
      if (spaceSize < 0) {                                                          
        spaceSize = spaceSize + 3;
      }
      *CapitalTextInfo += (spaceSize / 4);                       //Updates x position using spaceSize
    }
    else {
      _ptr_hudMobyData -= MOBY_SIZE;                          //Shifts the moby pointer to a new empty slot
      memset(_ptr_hudMobyData, '\0', MOBY_SIZE);
      Vec3Copy((int *)(_ptr_hudMobyData + 0xc),CapitalTextInfo);
      if ((*text == '!') || (*text == '?')) {                                   //If ! or ? then make capital
        isCapital = TRUE;
      }
      if (!isCapital) {
        *(int *)(_ptr_hudMobyData + 0x10) += LowercaseTextInfo[1];         //increases the y position by the "y offset" for lowercase letters
        *(int *)(_ptr_hudMobyData + 0x14) = LowercaseTextInfo[2];                                                       //sets the size to be the lowercase size
      }
      currentCharacter = *text;
      if (currentCharacter - '0' < 10) {                                                   //If character is 0-9
        *(short *)(_ptr_hudMobyData + 0x36) = currentCharacter + 0xd4;
      }
      else if (currentCharacter - 'A' < 26) {                                            //If character is A-Z
        *(short *)(_ptr_hudMobyData + 0x36) = currentCharacter + 0x169;
      }
      else if (currentCharacter == '!') {
        *(short *)(_ptr_hudMobyData + 0x36) = 0x4b;                             //Special Characters
      }
      else if (currentCharacter == ',') {
        *(short *)(_ptr_hudMobyData + 0x36) = 0x4c;
      }
      else if (currentCharacter == '?') {
        *(short *)(_ptr_hudMobyData + 0x36) = 0x116;
      }
      else if (currentCharacter == '.') {
        *(short *)(_ptr_hudMobyData + 0x36) = 0x147;
      }
      else {                                                                    //Default Case (apostrophe but it's really a comma up in the air lol)
        *(short *)(_ptr_hudMobyData + 0x36) = 0x4c;
        *(int *)(_ptr_hudMobyData + 0x10) -= (*LowercaseTextInfo * 2) / 3;      //decreases y position (makes it go up) so the comma looks like an apostrophe
      }
      _ptr_hudMobyData[0x47] = '\x7f';
      _ptr_hudMobyData[0x4f] = color;
      _ptr_hudMobyData[0x50] = 0xff;
      if (isCapital) {
        *CapitalTextInfo += spacing;                                            //If capital increases x position using default spacing
      }
      else {
        *CapitalTextInfo += *LowercaseTextInfo;                                 //If not capital increases x position using lowercase spacing
      }
      isCapital = (unsigned int)(*text - 0x30) < 10;                            //Sets bool to false when the character is not a number
    }
    text++;
    currentCharacter = *text;
  }
  return _ptr_hudMobyData;
}