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
      _ptr_hudMobyData = _ptr_hudMobyData - MOBY_SIZE;                          //Shifts the moby pointer to a new empty slot
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
  char bVar1;
  bool bVar2;
  unsigned char *puVar3;
  int iVar4;
  unsigned int uVar5;
  
  bVar2 = TRUE;
  bVar1 = *text;
  while (bVar1 != 0) {
    if (bVar1 == 0x20) {
      iVar4 = *LowercaseTextInfo * 3;
      bVar2 = TRUE;
      if (iVar4 < 0) {
        iVar4 = iVar4 + 3;
      }
      *CapitalTextInfo = *CapitalTextInfo + (iVar4 >> 2);
    }
    else {
      _ptr_hudMobyData = _ptr_hudMobyData - MOBY_SIZE;
      memset(_ptr_hudMobyData, '\0', MOBY_SIZE);
      Vec3Copy((int *)(_ptr_hudMobyData + 0xc),CapitalTextInfo);
      puVar3 = _ptr_hudMobyData;
      if ((*text == 0x21) || (*text == 0x3f)) {
        bVar2 = TRUE;
      }
      if (!bVar2) {
        *(int *)(_ptr_hudMobyData + 0x10) = *(int *)(_ptr_hudMobyData + 0x10) + LowercaseTextInfo[1];
        *(int *)(puVar3 + 0x14) = LowercaseTextInfo[2];
      }
      puVar3 = _ptr_hudMobyData;
      bVar1 = *text;
      uVar5 = (uint)bVar1;
      if (uVar5 - 0x30 < 10) {
        *(short *)(_ptr_hudMobyData + 0x36) = bVar1 + 0xd4;
      }
      else if (uVar5 - 0x41 < 0x1a) {
        *(short *)(_ptr_hudMobyData + 0x36) = bVar1 + 0x169;
      }
      else if (uVar5 == 0x21) {
        *(short *)(_ptr_hudMobyData + 0x36) = 0x4b;
      }
      else if (uVar5 == 0x2c) {
        *(short *)(_ptr_hudMobyData + 0x36) = 0x4c;
      }
      else if (uVar5 == 0x3f) {
        *(short *)(_ptr_hudMobyData + 0x36) = 0x116;
      }
      else if (uVar5 == 0x2e) {
        *(short *)(_ptr_hudMobyData + 0x36) = 0x147;
      }
      else {
        *(short *)(_ptr_hudMobyData + 0x36) = 0x4c;
        *(int *)(puVar3 + 0x10) = *(int *)(puVar3 + 0x10) - (*LowercaseTextInfo << 1) / 3;
      }
      _ptr_hudMobyData[0x47] = '\x7f';
      _ptr_hudMobyData[0x4f] = color;
      _ptr_hudMobyData[0x50] = 0xff;
      if (bVar2) {
        iVar4 = *CapitalTextInfo + spacing;
      }
      else {
        iVar4 = *CapitalTextInfo + *LowercaseTextInfo;
      }
      *CapitalTextInfo = iVar4;
      bVar2 = *text - 0x30 < 10;
    }
    text = text + 1;
    bVar1 = *text;
  }
  return _ptr_hudMobyData;
}