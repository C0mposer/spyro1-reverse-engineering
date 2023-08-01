#ifndef DRAW_STUFF_H
#define DRAW_STUFF_H
#include <custom_types.h>

//**********************************
// ** Function: DrawArrow
// ** Original Address: 0x80018534
// ** Hook File: draw_arrow.s 
// ** Prototype: draw_stuff.h
// ** Amount of instructions: Same Amount (https://decomp.me/scratch/IvMFp) 
//**********************************
/*
 * Draws a blinking arrow facing left or right. Blink timer is customizable. (Fills out full moby struct into the pointer to the hud moby buffer)
 * @param void* hudMobyInfo - pointer to basic info about the arrow you want to draw (x, y, size)
 * @param unsigned int timer - frame interval for each blink
 * @param int leftOrRightArrow - 0 for left, 1 for right
*/
void DrawArrow(int *hudMobyInfo, uint timer,int leftOrRightArrow);

//**********************************
// ** Function: DrawTextbox
// ** Original Address: 0x8001860C
// ** Hook File: draw_textbox.s
// ** Prototype: n/a
// ** Amount of instructions: SAME (https://decomp.me/scratch/MrfVL)
//**********************************
/*
 * Draws a default textbox that is filled in
 * @param int xBound1 - the first x boundry of the box
 * @param int xBound2 - the second x boundry of the box
 * @param int yBound1 - the first y boundry of the box
 * @param int yBound2 - the second y boundry of the box
*/
void DrawTextbox(int xBound1, int xBound2, int yBound1, int yBound2);

#endif /* DRAW_STUFF_H */
