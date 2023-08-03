#ifndef MENUS_H
#define MENUS_H

/**
 * @brief Handles the required steps for exiting the inventory menu. 
 * @details Places texture back into vram, sets gamestate to gameplay, resets hud timers, continues music, etc

 * @note Function: ExitInventoryMenu \n
 * Original Address: 0x8002c7bc \n
 * Hook File: exit_inventory_menu.s \n 
 * Prototype: CURRENTLY N/A \n
 * Amount of instructions: Same Amount (https://decomp.me/scratch/HuLXz) \n 

*/
void ExitInventoryMenu(void);

#endif /* MENUS_H */
