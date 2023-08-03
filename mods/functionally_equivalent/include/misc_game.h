#ifndef MISC_GAME_H
#define MISC_GAME_H


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
int CalculateCompletionPercentage(void);

/**
 * @brief 
 * @details 
 
 * @param 
 * @return

 * @note Function: SinScaled \n
 * Original Address: 0x8002BB20 \n
 * Hook File: sin_scaled.s \n 
 * Prototype: misc_game.h \n
 * Amount of instructions: Same Amount (https://decomp.me/scratch/qiaz2) \n 
*/
int SinScaled(uint param_1);

#endif /* MISC_GAME_H */
