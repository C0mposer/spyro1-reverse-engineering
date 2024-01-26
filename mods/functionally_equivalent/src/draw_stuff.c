#include <common.h>
#include <custom_types.h>
#include <moby.h>
#include <shapes.h>

/** @ingroup reveresed_functions
 *  @{
 */

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
void DrawPrimitive(void* primitive)

{
  int* local_gfx_ptrs;
  short* unk_first_gfx_ptr;
  
  local_gfx_ptrs = _ptr_arrayGraphicsRelatedPointers;
  unk_first_gfx_ptr = (short*) *_ptr_arrayGraphicsRelatedPointers;
  *_ptr_arrayGraphicsRelatedPointers = (int*)primitive;
  if (unk_first_gfx_ptr != 0x0) {
    *unk_first_gfx_ptr = (short)primitive;
    *(char *)(unk_first_gfx_ptr + 1) = (char)((uint)primitive >> 0x10);
    return;
  }
  local_gfx_ptrs[1] = (int*)primitive;
  return;
}


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
void DrawArrow(HudMobyInfo* hudMobyInfo, uint timer, int leftOrRightArrow)
{
  if ((timer % 32) < 16)                                                        // Alternate from being visible, and not every 16 frames
  {  
    _ptr_hudMobys = _ptr_hudMobys - sizeof(Moby);                               // Make space in the array of moby structs to be drawn to the hud
    memset(_ptr_hudMobys,'\0', sizeof(Moby));                                   // 0 out the area

    ((Moby*) _ptr_hudMobys)->type = 0x105;                                      // Set Moby Type to the ascii number 1 for an arrow

    Vec3Copy(&((Moby*) _ptr_hudMobys)->position, hudMobyInfo);                  // Set Moby Position from info struct (Z represents size/depth in 2D)

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
void DrawTextbox(int xBound1,int xBound2,int yBound1,int yBound2)
{
  Poly4FPadded* ptr_prim = (Poly4FPadded*)_ptr_primitivesArray;          

  SetDrawMode(_ptr_primitivesArray,1,0,0x40,0);      // Trasparent black background hack
  DrawPrimitive(ptr_prim);
  ptr_prim->tag = 0x5000000;
  ptr_prim->code = POLY4F_TRANSPARENT;
  ptr_prim->point1Pos.x = xBound1;
  ptr_prim->point2Pos.x = xBound2;
  ptr_prim->point3Pos.x = xBound1;
  ptr_prim->point4Pos.x = xBound2;
  ptr_prim->point1Pos.y = yBound1;
  ptr_prim->point2Pos.y = yBound1;
  ptr_prim->point3Pos.y = yBound2;
  ptr_prim->point4Pos.y = yBound2;
  ptr_prim->color.R = 0x70;
  ptr_prim->color.G = 0x70;
  ptr_prim->color.B = 0x70;
  DrawPrimitive((byte*)ptr_prim + 0xC);
  _ptr_primitivesArray = (byte*)ptr_prim + 0x24;            // Make space in the array of primitives for the next one

  // Outline of textbox
  DrawLine(xBound1,yBound1,xBound2,yBound1);
  DrawLine(xBound2,yBound1,xBound2,yBound2);
  DrawLine(xBound2,yBound2,xBound1,yBound2);
  DrawLine(xBound1,yBound2,xBound1,yBound1);
  return;
}


/** @} */ // end of reveresed_functions