#include <common.h>
#include <custom_types.h>

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


/** @} */ // end of reveresed_functions
