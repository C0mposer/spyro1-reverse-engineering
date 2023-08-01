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
  if ((timer % 32) < 16)                                    // Alternate from being visible, and not every 16 frames
  {  
    _ptr_hudMobys = _ptr_hudMobys + -0x58;                  // Make space in the array of moby structs to be drawn to the hud
    memset(_ptr_hudMobys,'\0',0x58);                        // 0 out the area

    *(short *)(_ptr_hudMobys + 0x36) = 0x105;               // Set Moby Type to the ascii number 1 for an arrow

    Vec3Copy((_ptr_hudMobys + 0xc), hudMobyInfo);           // Set Moby Position from info struct (Z represents size/depth in 2D)

    if (leftOrRightArrow < 2) {
      _ptr_hudMobys[0x44] = 64;                             // Setting default roll rotation for a right arrow
      _ptr_hudMobys[0x46] = (char)(leftOrRightArrow * 128); // Bitshifting the arrow choice by 7 (multiplying by 128) to result in
                                                            // the yaw rotation of the number 1 to a left arrow.
    }
    _ptr_hudMobys[0x47] = 0x7f;                             // Required for hud? Must be positive
    _ptr_hudMobys[0x4f] = 11;                               // Setting the color to gold
    _ptr_hudMobys[0x50] = -1;                               // Required for hud 2? Must be negative
  }
  return;
}

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

void DrawTextbox(int xBound1,int xBound2,int yBound1,int yBound2)

{
  int iVar1;
  
  iVar1 = _ptr_graphicsRelated;                         //trasparent background vv
  DrawShapePreReq(_ptr_graphicsRelated,1,0,0x40,0);      
  DrawPrimitive(iVar1);
  *(int *)(iVar1 + 0xc) = 0x5000000;
  *(char *)(iVar1 + 0x13) = 0x2a;
  *(short *)(iVar1 + 0x14) = (short)xBound1;
  *(short *)(iVar1 + 0x18) = (short)xBound2;
  *(short *)(iVar1 + 0x1c) = (short)xBound1;
  *(short *)(iVar1 + 0x20) = (short)xBound2;
  *(short *)(iVar1 + 0x16) = (short)yBound1;
  *(short *)(iVar1 + 0x1a) = (short)yBound1;
  *(short *)(iVar1 + 0x1e) = (short)yBound2;
  *(short *)(iVar1 + 0x22) = (short)yBound2;
  *(char *)(iVar1 + 0x10) = 0x70;
  *(char *)(iVar1 + 0x11) = 0x70;
  *(char *)(iVar1 + 0x12) = 0x70;
  DrawPrimitive(iVar1 + 0xc);
  _ptr_graphicsRelated = iVar1 + 0x24;
  DrawLine(xBound1,yBound1,xBound2,yBound1);          //box outline vv
  DrawLine(xBound2,yBound1,xBound2,yBound2);
  DrawLine(xBound2,yBound2,xBound1,yBound2);
  DrawLine(xBound1,yBound2,xBound1,yBound1);
  return;
}