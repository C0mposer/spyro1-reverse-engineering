#include <common.h>
#include <custom_types.h>

//**********************************
// ** Function: DrawArrow
// ** Original Address: 0x80018534
// ** Hook File: draw_arrow.s 
// ** Prototype: n/a
// ** Amount of instructions: Same Amount (https://decomp.me/scratch/IvMFp) 
//**********************************
/*
 * Draws a blinking arrow facing left or right. Blink timer is customizable. (Fills out full moby struct into the pointer to the hud moby buffer)
 * @param void* hudMobyInfo - pointer to basic info about the arrow you want to draw (x, y, size)
 * @param unsigned int timer - frame interval for each blink
 * @param int leftOrRightArrow - 0 for left, 1 for right
*/

void DrawArrow(int *hudMobyInfo,uint timer,int leftOrRightArrow)

{
  int *dest;
  
  if ((timer & 0x1f) < 0x10) {
    _ptr_hudMobyData = _ptr_hudMobyData + -0x58;
    memset(_ptr_hudMobyData,'\0',0x58);
    dest = (int *)(_ptr_hudMobyData + 0xc);
    *(short *)(_ptr_hudMobyData + 0x36) = 0x105;
    Vec3Copy(dest,hudMobyInfo);
    if (leftOrRightArrow < 2) {
      _ptr_hudMobyData[0x44] = '@';
      _ptr_hudMobyData[0x46] = (unsigned char)(leftOrRightArrow << 7);
    }
    _ptr_hudMobyData[0x47] = '\x7f';
    _ptr_hudMobyData[0x4f] = '\v';
    _ptr_hudMobyData[0x50] = 0xff;
  }
  return;
}
