#include <common.h>
#include <custom_types.h>
#include <moby.h>

/** @ingroup reveresed_functions
 *  @{
 */

/**
 * @brief Returns the current completion percentage.
 * @details Returns the current completion percentage based on your gems, dragons, and eggs. (Except for when you are above 12000 gems.)
 
 * @return int - The current completion percentage.

 * @note Function: CalculateCompletionPercentage \n
 * Original Address: 0x8002BB20 \n
 * Hook File: calculate_completion_percentage.s \n 
 * Prototype: misc_game.h \n
 * Amount of instructions: Same Amount (https://decomp.me/scratch/8Lz9x) \n 
*/
int CalculateCompletionPercentage(void)
{
  int percentage;
  
  percentage = ((_globalGemCount * 50) + (_globalDragonCount * 6000) + (_globalEggCount * 10000)) / 12000;
  if (_globalGemCount > 12000) {
    percentage = (_globalGemCount - 12000) / 100 + 100;
  }
  return percentage;
}


/**
 * @brief 
 * @details 
 
 * @param uint - 
 * @return

 * @note Function: SinScaled \n
 * Original Address: 0x8002BB20 \n
 * Hook File: sin_scaled.s \n 
 * Prototype: misc_game.h \n
 * Amount of instructions: Same Amount (https://decomp.me/scratch/qiaz2) \n 
 
 * @see _sinArray
*/
int SinScaled(uint param_1)
{
  uint uVar1;
  
  uVar1 = (param_1 & 0xfff) >> 4;
  if ((param_1 & 0xf) != 0) {
    return ((int)((param_1 & 0xf) * ((int)_sinArray[uVar1 + 1] - (int)_sinArray[uVar1])) >>
           4) + (int)_sinArray[uVar1];
  }
  return (int)_sinArray[uVar1];
}


/**
 * @brief Alters the pixels in an image to produce a fade in effect.
 * @details Decompresses an image and reduces each RGBA pixel's contrast according to a specified value.
 * @param uint* source - pointer to a compressed image.
 * @param uint* destination - pointer to the desired destination memory to write the decompressed image.
 * @param int contrast - strength of dimming to apply to each pixel.
 * @note Function: ApplyImageFading \n
   Original Address: 0x80010AA8 \n
   Hook File: apply_image_fading.s \n
   Prototype: misc_game.h \n
   Amount of instructions: Less (https://decomp.me/scratch/S3aIo) \n
  * @see ApplyImageFading()
*/
void ApplyImageFading(uint *source, uint *destination, int contrast)
{
  while( true ) {
    uint instruction = *source++;

    // If the instruction is invalid, then finish decompressing.
    if ((int)instruction < 0) {
      break;
    }

    // The portion of the instruction on the right side is an offset into the destination memory to start writing to. Maybe some decompression.
    destination = (uint *)((int)destination + ((instruction << 0x0F) >> 0x0D));

    // The number of RGBA pixels this decompressed segment should take.
    uint size = instruction >> 0x11;
    uint *end = destination + size;

    while (destination != end) {
      uint data = *source++;
      byte *pixel = (byte*)&data;

      // Apply fading to each byte of the RGBA pixel, but clamp at zero.
      // This seems to result in less instructions, but is slower.
      for (uint i = 0; i < sizeof(RGBA_u8); i++) {
        int applied = (int)pixel[i] + contrast;
        pixel[i] = applied > 0 ? applied : 0;
      }

      // Save the modified pixel into the destination buffer.
      *destination++ = *(uint*)pixel;
    }
  }
}


/** @} */ // end of reveresed_functions
