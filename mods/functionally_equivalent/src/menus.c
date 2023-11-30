#include <common.h>

/** @ingroup reveresed_functions
 *  @{
 */

/**
 * @brief Handles the required steps for exiting the inventory menu. 
 * @details Places texture back into vram, sets gamestate to gameplay, resets hud timers, continues music, etc

 * @note Function: ExitInventoryMenu \n
 * Original Address: 0x8002c7bc \n
 * Hook File: exit_inventory_menu.s \n 
 * Prototype: menus.h \n
 * Amount of instructions: Same Amount (https://decomp.me/scratch/HuLXz) \n 

*/
void ExitInventoryMenu(void)
{
    RECT screen_rect;
    
    screen_rect.x = 0x200;
    screen_rect.w = 0x100;
    screen_rect.y = 0;
    screen_rect.h = 0xe1;
    LoadImageOrTexture(&screen_rect,(int*)((char*)_maybe_ptr_levelTextureRelated + -0x1c200));
    DrawSync(0);
    _gameState = 0;
    Maybe_ResetHudTimers();
    _hudChestState = 0;
    _hudDragonState = 0;
    _hudLivesState = 0;
    _hudEggsState = 0;
    _hudAnimationState = 0;
    PlayMusicTrack(_musicLevelTrack,8);
    return;
}