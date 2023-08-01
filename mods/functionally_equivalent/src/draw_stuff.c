#include <common.h>
#include <custom_types.h>
#include <moby.h>

//**********************************
// ** Function: DrawArrow
// ** Original Address: 0x80018534
// ** Hook File: draw_arrow.s 
// ** Prototype: draw_stuff.h
// ** Amount of instructions: Same Amount (https://decomp.me/scratch/IvMFp) 
//**********************************
/*
 * Draws a blinking arrow facing left or right. Blink timer is not customizable. (Fills out full moby struct into the pointer to the hud moby buffer)
 * @param void* hudMobyInfo - pointer to basic info about the arrow you want to draw (x, y, size)
 * @param unsigned int timer - timer that counts every frame to be used for the pre-determined interval.
 * @param int leftOrRightArrow - 0 for right, 1 for left
*/
void DrawArrow(int* hudMobyInfo, uint timer, int leftOrRightArrow)

{
  if ((timer % 32) < 16)                                                // Alternate from being visible, and not every 16 frames
  {  
    _ptr_hudMobys = _ptr_hudMobys - MOBY_SIZE;                          // Make space in the array of moby structs to be drawn to the hud
    memset(_ptr_hudMobys,'\0', MOBY_SIZE);                              // 0 out the area

    ((Moby*) _ptr_hudMobys)->type = 0x105;                              // Set Moby Type to the ascii number 1 for an arrow

    Vec3Copy(&((Moby*) _ptr_hudMobys)->position, hudMobyInfo);          // Set Moby Position from info struct (Z represents size/depth in 2D)

    if (leftOrRightArrow < 2) {
        ((Moby*) _ptr_hudMobys)->rotation.x = 64;                               // Setting default roll rotation for a right arrow
        ((Moby*) _ptr_hudMobys)->rotation.z = (byte)(leftOrRightArrow * 128);   // Bitshifting the arrow choice by 7 (multiplying by 128) to result in
                                                                                // the yaw rotation of the number 1 to a left arrow.
    }
    ((Moby*) _ptr_hudMobys)->requiredHUD1 = 0x7f;           // Required for hud? Must be positive
    ((Moby*) _ptr_hudMobys)->color = MOBY_COLOR_GOLD;       // Setting the color to gold
    ((Moby*) _ptr_hudMobys)->requiredHUD2 = -1;             // Required for hud 2? Must be negative
  }
  return;
}
