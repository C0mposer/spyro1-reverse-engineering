#include <common.h>
#include <custom_types.h>

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
void DrawArrow(int *hudMobyInfo, uint timer, int leftOrRightArrow)

{
  if ((timer % 32) < 16) 
  {  
    _ptr_hudMobys = _ptr_hudMobys + -0x58;
    memset(_ptr_hudMobys,'\0',0x58);

    *(short *)(_ptr_hudMobys + 0x36) = 0x105;               // Set Moby Type to the ascii number 1 for an arrow

    Vec3Copy((_ptr_hudMobys + 0xc), hudMobyInfo);         // Set Moby Position from info struct (Z represents size/depth in 2D)

    if (leftOrRightArrow < 2) {
      _ptr_hudMobys[0x44] = 64;                             // Setting default roll rotation?
      _ptr_hudMobys[0x46] = (char)(leftOrRightArrow * 128); // Bitshifting the arrow choice by 7 (multiplying by 128) to result in
                                                            // the yaw rotation of the number 1 to on the oppisite side if.
    }
    _ptr_hudMobys[0x47] = '\x7f';
    _ptr_hudMobys[0x4f] = '\v';
    _ptr_hudMobys[0x50] = 0xff;
  }
  return;
}
