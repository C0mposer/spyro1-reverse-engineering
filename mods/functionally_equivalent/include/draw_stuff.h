#ifndef DRAW_STUFF_H
#define DRAW_STUFF_H
#include <moby.h>
#include <custom_types.h>

/**
 * @brief Draws a ps1 primitive to the screen. 
 * @details Places a primitive struct ptr into the array of primitives to be drawn every frame (Somewhat unsure)
 * 
 * @param void* hudMobyInfo - pointer to basic info about the arrow you want to draw (x, y, size)

 * @note Function: DrawPrimitve \n
 * Original Address: 0x800168dc \n
 * Hook File: draw_primitive.s \n 
 * Prototype: draw_stuff.h \n
 * Amount of instructions: Same Amount (https://decomp.me/scratch/wd3wE) \n 
*/
void DrawPrimitive(void* primitive);



/**
 * @brief Draws a blinking arrow facing left or right. 
 * @details Fills out full moby struct into the pointer to the hud moby buffer
 
 * @param void* hudMobyInfo - pointer to basic info about the arrow you want to draw (x, y, size)
 * @param uint timer - timer that counts every frame to be used for the pre-determined 16 frame intervals.
 * @param int leftOrRightArrow - 0 for right, 1 for left
 
 * @note Function: DrawArrow \n
 * Original Address: 0x80018534 \n
 * Hook File: draw_arrow.s \n
 * Prototype: draw_stuff.h \n
 * Amount of instructions: Same Amount (https://decomp.me/scratch/IvMFp) \n
*/
void DrawArrow(HudMobyInfo* hudMobyInfo,  uint timer, int leftOrRightArrow);



/**
 * @brief Draws a black textbox with a gold border. You can specify the bounds
 * @details Calls Draw primitive with the interesting hack they use for the alpha channel to achieve the black background, and also 4 draw lines for the border.

 * @param int xBound1 - the first x boundry of the box
 * @param int xBound2 - the second x boundry of the box
 * @param int yBound1 - the first y boundry of the box
 * @param int yBound2 - the second y boundry of the box

 * @note Function: DrawTextbox \n
 * Original Address: 0x8001860C \n
 * Hook File: draw_textbox.s \n
 * Prototype: draw_stuff.h \n
 * Amount of instructions: MORE IN MODDERN GCC (https://decomp.me/scratch/MrfVL) \n
*/
void DrawTextbox(int xBound1, int xBound2, int yBound1, int yBound2);

#endif /* DRAW_STUFF_H */
