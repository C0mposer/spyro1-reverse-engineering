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

/**
 * @brief Appends generated text objects to the list of HUD mobys.
 * @details
 * @note Function: CopyHudToShaded \n
 * Original Address: 0x80018880 \n
 * Hook File: copy_hud_to_shaded.s \n 
 * Prototype: misc_game.h \n
 * Amount of instructions: Same Amount (https://decomp.me/scratch/rbY0g) \n 
*/
void CopyHudToShaded();

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
void ApplyImageFading(uint *source, uint *destination, int contrast);

#endif /* MISC_GAME_H */
