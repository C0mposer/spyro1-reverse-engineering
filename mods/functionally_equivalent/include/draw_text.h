#ifndef DRAW_TEXT_H
#define DRAW_TEXT_H

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
char* DrawTextCapitals(char *text,int *textInfo, int spacing, char color);



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
int DrawTextAll(char *text,int *capitalTextInfo,int *lowercaseTextInfo,int spacing,char color);

#endif /* DRAW_TEXT_H */
