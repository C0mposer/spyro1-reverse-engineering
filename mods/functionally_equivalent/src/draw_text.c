#include <common.h>
#include <moby.h>
#include <vector.h>
#include <custom_types.h>

/** @ingroup reveresed_functions
 *  @{
 */

/**
 * @brief Draws a text string to the screen (Only capital characters allowed) 
 * @details Fills out a moby struct in the hud mobys array, using arguments for Capital ASCII text
 
 * @param char* text - text to be drawn.
 * @param int* textInfo - pointer to the desired location and size of the text.
 * @param int spacing - how much space between characters.
 * @param char color - color.
 * @note Function: DrawTextCapitals \n
   Original Address: 0x80017fe4 \n
   Hook File: draw_text_capitals_hook.s \n
   Prototype: n/a \n
 * @see DrawTextAll()
*/
char* DrawTextCapitals(char *text,int *textInfo, int spacing, char color)
{
  unsigned int currentCharacter;                                                //? Needs to be unsigned lmao?

  currentCharacter = *text;                                                     // Puts first character of string in currentcCharacter

  while (currentCharacter != 0) {                                               // Not a NULL terminator
    if (currentCharacter != 0x20) {                                             // Not a space character
      _ptr_hudMobys -= 1;                                                       // Shifts the moby pointer to a new empty slot
      memset(_ptr_hudMobys, 0, sizeof(Moby));                                   // Clears the new slot
      Vec3Copy(&_ptr_hudMobys->position,textInfo);                              // Copy text x pos, y pos, and size(z pos) to the new moby
      currentCharacter = *text;                                                 // Puts each character of the string in currentCharacter each iteration of the loop
      if(currentCharacter - '0' < 10) {                                         // If currentCharacter 0-9
        _ptr_hudMobys->type = currentCharacter + 0xd4;         
      }
      else if(currentCharacter - 'A' < 26) {                                    // If currentCharacter is A-Z
        _ptr_hudMobys->type = currentCharacter + 0x169;        
      }
      else {          
        short mobyType;                                                          // Special Characters
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
        else {                                                                  // Default Character (_)
          mobyType = 0x147;
        }
        _ptr_hudMobys->type = mobyType;
      }
      _ptr_hudMobys->requiredHUD1 = 0x7F;
      _ptr_hudMobys->color = color;
      _ptr_hudMobys->requiredHUD2 = 0xff;
    }
    text++;                                                                     // Move to next char in String
    textInfo[0] += spacing;                                                     // The x position in the textInfo struct is increased by the spacing amount
    currentCharacter = *text;                                                   // currentCharacter is updated to the next character
  }
  //printf("my print: %X\n", _ptr_hudMobyData);
  return _ptr_hudMobys;
}

/**
 * @brief Draws a text string to the screen (Capital & Lowercase allowed)
 * @details Fills out a moby struct in the hud mobys array, using arguments for ASCII text
 
 * @param char* text - text to be drawn.
 * @param int* capitalTextInfo - pointer to the desired location and size of the text.
 * @param int* lowercaseextInfo - pointer to the desired spacing and size of lowercase text.
 * @param int spacing - how much space between characters.
 * @param char color - color.
 * @note Function: DrawTextAll \n
   Original Address: 0x800181AC \n
   Hook File: draw_text_all_hook.s \n
   Prototype: n/a \n
  * @see DrawTextCapitals()
*/
int DrawTextAll(char *text,int *capitalTextInfo,int *lowercaseTextInfo,int spacing,char color)
{
  unsigned int currentCharacter;
  bool isCapital;
  int spaceSize;
  
  isCapital = TRUE;
  currentCharacter = *text;
  while (currentCharacter != 0) {                                               // While not a NULL terminator
    if (currentCharacter == 0x20) {                                             // If a space
      spaceSize = *lowercaseTextInfo * 3;                                       
      isCapital = TRUE;                                                         // Character is uppercase
      if (spaceSize < 0) {                                                      //? Weird Failsafe?   
        spaceSize = spaceSize + 3;
      }
      capitalTextInfo[0] += (spaceSize / 4);                                    // Updates X position using spaceSize
    }
    else {
      _ptr_hudMobys -= 1;                                                       // Shifts the moby pointer to a new empty slot
      memset(_ptr_hudMobys, '\0', sizeof(Moby));
      Vec3Copy(&_ptr_hudMobys->position,capitalTextInfo);
      if ((*text == '!') || (*text == '?')) {                                   // If ! or ? then make capital
        isCapital = TRUE;
      }
      if (!isCapital) {
        _ptr_hudMobys->position.y += lowercaseTextInfo[1];                      // Increases the Y position by the "y offset" for lowercase letters
        _ptr_hudMobys->position.z = lowercaseTextInfo[2];                       // sets the size to be the lowercase size
      }
      currentCharacter = *text;
      if (currentCharacter - '0' < 10) {                                        // If character is 0-9
        _ptr_hudMobys->type = currentCharacter + 0xd4;
      }
      else if (currentCharacter - 'A' < 26) {                                   // If character is A-Z
        _ptr_hudMobys->type = currentCharacter + 0x169;
      }
      else if (currentCharacter == '!') {
        _ptr_hudMobys->type = 0x4b;                                             // Special Characters
      }
      else if (currentCharacter == ',') {
        _ptr_hudMobys->type = 0x4c;
      }
      else if (currentCharacter == '?') {
        _ptr_hudMobys->type = 0x116;
      }
      else if (currentCharacter == '.') {
        _ptr_hudMobys->type = 0x147;
      }
      else {                                                                    // Default Case (apostrophe but it's really a comma up in the air lol)
        _ptr_hudMobys->type = 0x4c;
        _ptr_hudMobys->position.y -= (*lowercaseTextInfo * 2) / 3;              // Decreases y position (makes it go up) so the comma looks like an apostrophe
      }
      _ptr_hudMobys->requiredHUD1 = 0x7F;
      _ptr_hudMobys->color = color;
      _ptr_hudMobys->requiredHUD2 = 0xff;
      if (isCapital) {
        *capitalTextInfo += spacing;                                            // If capital increase X position using default spacing
      }
      else {
        *capitalTextInfo += *lowercaseTextInfo;                                 // If not capital increase X position using lowercase spacing
      }
      isCapital = (unsigned int)(*text - 0x30) < 10;                            // Sets isCapitral to false when the character is not a number
    }
    text++;
    currentCharacter = *text;
  }
  return _ptr_hudMobys;
}

/**
 * @brief Copies generated moby structs to the end of a global list.
 * @details Appears to be something that is called often when working with text.
 
 * @note Function: CopyHudToShaded \n
   Original Address: 0x80018880 \n
   Hook File: copy_hud_to_shaded.s \n
   Prototype: draw_text.h \n
   Amount of instructions: More (https://decomp.me/scratch/rbY0g) \n
  * @see CopyHudToShaded()
*/
void CopyHudToShaded() {
  Moby **entry = &_ptr_hudMobysHead;
  Moby **ref = &_ptrTextUnk;

  while (*ref != 0) {                                                           // iterate to get to the end of the list.
    ref = entry;
    entry = ref + 1;
  }

  while (_ptr_hudMobys != _ptr_hudMobysQueue) {                                 // append all of the new mobys
    *ref = _ptr_hudMobys;
    _ptr_hudMobys += 1;
    ref += 1;
  }

  *ref = 0;                                                                     // make sure to set the end of the list to zero for iteration to work on the next call to this function. 
}

/**
 * @brief Draws the demo text on the screen.
 * @details Creates HUD mobys for displaying the text "Demo Mode" with varying size text.
 
 * @note Function: DrawDemoText \n
   Original Address: 0x80018908 \n
   Hook File: draw_demo_text.s \n
   Prototype: draw_text.h \n
   Amount of instructions: More (https://decomp.me/scratch/vU390) \n
  * @see DrawDemoText()
*/
void DrawDemoText() {
  const Vec3 capitalTextInfo = { .x = 199, .y = 200, .z = 4352 };
  const Vec3 lowercaseTextInfo = { .x = 16, .y = 1, .z = 5120 };
  const byte spacing = 18;
  const char color = 2;
  const int sinArrayIncrement = 12;

  Moby* mobyPtr = _ptr_hudMobys;
  unsigned int sinArrayIndex = 0;
  
  DrawTextAll("DEMO MODE", &capitalTextInfo, &lowercaseTextInfo, spacing, color);
  mobyPtr--;
  
  while (_ptr_hudMobys <= mobyPtr) {
    mobyPtr->rotation.z = _sinArray[_levelTimer_60fps * 4 + sinArrayIndex & 0xFF] >> 7;
    mobyPtr--;
    sinArrayIndex += sinArrayIncrement;
  }

  CopyHudToShaded();
}
/** @} */ // end of reveresed_functions