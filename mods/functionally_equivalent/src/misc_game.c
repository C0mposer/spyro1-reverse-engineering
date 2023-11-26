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
 * @brief Copies generated moby structs to the end of a global list.
 * @details Appears to be something that is called often when working with text.
 
 * @note Function: CopyHudToShaded \n
   Original Address: 0x80018880 \n
   Hook File: copy_hud_to_shaded.s \n
   Prototype: n/a \n
   Amount of instructions: Same Amount (https://decomp.me/scratch/rbY0g) \n
  * @see CopyHudToShaded()
*/
void CopyHudToShaded() {
  char** ref = &_ptr_hudMobys;

  while (*ref != 0) {                                                           // iterate to get to the end of the list.
    ref += sizeof(MOBY_SIZE);
  }

  while (_ptr_hudMobys != _ptr_hudMobysQueue) {                                   // append all of the new mobys
    *ref = _ptr_hudMobys;
    _ptr_hudMobys += sizeof(MOBY_SIZE);
    ref += sizeof(MOBY_SIZE);
  }

  *ref = 0;                                                                     // make sure to set the end of the list to zero for iteration to work on the next call to this function. 
}

/** @} */ // end of reveresed_functions
