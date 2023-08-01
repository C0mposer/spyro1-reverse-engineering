#ifndef DRAW_STUFF_H
#define DRAW_STUFF_H
#include <moby.h>

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
void DrawArrow(HudMobyInfo* hudMobyInfo, uint timer, int leftOrRightArrow);

#endif /* DRAW_STUFF_H */
