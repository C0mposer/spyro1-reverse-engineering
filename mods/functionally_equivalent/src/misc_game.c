#include <common.h>
#include <custom_types.h>

//**********************************
// ** Function: CalculateCompletionPercentage
// ** Original Address: 0x8002BB20
// ** Hook File: calculate_completion_percentage.s 
// ** Prototype: misc_game.h
//**********************************
/*
 * Returns the current completion percentage based on your gems, dragons, and eggs. (Except for when you are above 12000 gems.)
 * @return int - The current completion percentage.
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

