#ifndef COMMON_H
#define COMMON_H

#include "custom_types.h"
#include "vector.h"

//~~~~~~~~~~~~~~~~~~~~~~~~
//Constants/Magic Numbers
//~~~~~~~~~~~~~~~~~~~~~~~~

#define SCREEN_LEFT_EDGE 0x0
#define SCREEN_RIGHT_EDGE 0x200
#define SCREEN_TOP_EDGE 0x0
#define SCREEN_BOTTOM_EDGE 0xE8

#define FPS 30

#define WORLD_UNIT 4096
#define GAME_UNIT 64

typedef enum Direction
{
    LEFT,
    RIGHT
}Direction;

typedef enum Buttons
{
    X_BUTTON = 0x0040,
    SQUARE_BUTTON = 0x0080,
    CIRCLE_BUTTON = 0x0020,
    TRIANGLE_BUTTON = 0x0010,

    UP_BUTTON = 0x1000,
    RIGHT_BUTTON = 0x2000,
    DOWN_BUTTON = 0x4000,
    LEFT_BUTTON = 0x8000,

    SELECT_BUTTON = 0x0100,
    START_BUTTON = 0x0800,

    R1_BUTTON = 0x0008,
    L1_BUTTON = 0x0004,
    R2_BUTTON = 0x0002,
    L2_BUTTON = 0x0001,

    L3_BUTTON = 0x0200,
    R3_BUTTON = 0x0400
}Buttons;

typedef enum GameState
{
    GAMESTATE_GAMEPLAY = 0,
    GAMESTATE_LOADING = 0x1,
    GAMESTATE_PAUSED = 0x2,
    GAMESTATE_INVENTORY = 0x3,
    GAMESTATE_DEATH = 0x4,
    GAMESTATE_GAME_OVER = 0x5,
    GAMESTATE_BETA_DRAGON_TEXTBOX_MAYBE = 0x6,
    GAMESTATE_FLIGHT_LEVEL_MENU = 0x7,
    GAMESTATE_DRAGON_STATE = 0x8,
    GAMESTATE_FLY_IN = 0x9,
    GAMESTATE_EXITING_LEVEL = 0xA,
    GAMESTATE_DRAGON_FAIRY_TEXTBOX = 0xB,
    GAMESTATE_BALLOONIST = 0xC,
    GAMESTATE_TITLE_SCREEN = 0xD,
    GAMESTATE_CUTSCENE = 0xE,
    GAMESTATE_CREDITS = 0xF
}GameState;

typedef enum SpyroHealthStates
{
    YELLOW_SPARX = 3,
    BLUE_SPARX = 2,
    GREEN_SPARX = 1,
    NO_SPARX = 0
}SpyroHealthStates;

typedef enum LevelIDS
{
    ARTISANS_ID = 0xA,
    STONE_HILL_ID = 0xB,
    TOWN_SQUARE_ID = 0xD,
    DARK_HALLOW_ID = 0xC,
    TOASTY_ID = 0xE,
    SUNNY_FLIGHT_ID = 0xF,

    PEACE_KEEPERS_ID = 0x14,
    DRY_CANYON_ID = 0x15,
    CLIFF_TOWN_ID = 0x16,
    ICE_CAVERN_ID = 0x17,
    SHEMP_ID = 0x18,
    NIGHT_FLIGHT_ID = 0x19,

    MAGIC_CRAFTERS_ID = 0x1E,
    ALPINE_RIDGE_ID = 0x1F,
    HIGH_CAVES_ID = 0x20,
    WIZARD_PEAK_ID = 0x21,
    BLOWHARD_ID = 0x22,
    CRYSTAL_FLIGHT_ID = 0x23,

    BEAST_MAKERS_ID = 0x28,
    TERRACE_VILLAGE_ID = 0x29,
    MISTY_BOG_ID = 0x2A,
    TREE_TOPS_ID = 0x2B,
    METALHEAD_ID = 0x2C,
    WILD_FLIGHT_ID = 0x2C,

    DREAM_WEAVERS_ID = 0x32,
    HAUNTED_TOWERS_ID = 0x35,
    DARK_PASSAGE_ID = 0x33,
    LOFTY_CASTLE_ID = 0x34,
    JACQUES_ID = 0x36,
    ICY_FLIGHT_ID = 0x37,

    GNASTYS_WORLD_ID = 0x3C,
    GNORC_COVE_ID = 0x3D,
    TWILIGHT_HARBOR_ID = 0x3E,
    GNASTY_GNORC_ID = 0x3F,
    GNASTYS_LOOT_ID = 0x40
}LevelIDS;

typedef enum InventoryMenuSelections
{
    ARTISANS_MENU = 0,
    PEACE_KEEPERS_MENU = 1,
    MAGIC_CRAFTERS_MENU = 2,
    BEAST_MAKERS_MENU = 3,
    DREAM_WEAVERS_MENU = 4,
    GNASTYS_WORLD_MENU = 5
}InventoryMenuSelections;

typedef enum StartMenuSelections
{
    STARTMENU_CONTINUE = 0,
    STARTMENU_OPTIONS = 1,
    STARTMENU_INVENTORY = 2,
    STARTMENU_EXIT_LEVEL = 3,
    STARTMENU_QUIT_GAME = 3

}StartMenuSelections;

typedef enum MovementSubStates
{
    MOVEMENT_SUBSTATE_LOADING = 0x8,
    MOVEMENT_SUBSTATE_EXIT_PORTAL = 0x9,
    MOVEMENT_SUBSTATE_FLY_IN_LOOP = 0xA,
    MOVEMENT_SUBSTATE_FLY_IN_CAMERA_180 = 0xA
}MovementSubStates;

typedef enum BalloonistStates
{
    BALLOONIST_STATE_NEVER_TALKED_TO_BALLOONIST = 0x0,
    BALLOONIST_STATE_TEXTBOX = 0x1,
    BALLOONIST_STATE_JUMPING_ONTO_BALLOON = 0x2,
    BALLOONIST_STATE_BALLOON_RISING = 0x3,
    BALLOONIST_STATE_BALLOON_LOADING_PART_1 = 0x4,
    BALLOONIST_STATE_BALLOON_LOADING_PART_2 = 0x5,
    BALLOONIST_STATE_BALLOON_LOWERING = 0x6,
    BALLOONIST_STATE_JUMPING_OUT_OF_BALLOON = 0x7

}BalloonistStates;


typedef enum LevelFlyInAnimations
{
    FACING_LEFT = 0xCA6C,
    FACING_RIGHT = 0xCA3C,
    FACING_FORWARD = 0xCA24,
    FACING_BACKWARDS = 0xCA84,
    FACING_DIAGONAL = 0xCA9C,   // wizard peak specific
    RETURNING_HOME = 0xCA54
}LevelFlyInAnimations;


//~~~~~~~
//Structs
//~~~~~~~

typedef struct RECT 
{
    short x, y, w, h;
}RECT;

typedef struct RGBA_u8
{
    unsigned char R;
    unsigned char G;
    unsigned char B;
    unsigned char opacity;
}RGBA_u8;

typedef struct RGB_u8
{
    unsigned char R;
    unsigned char G;
    unsigned char B;
}RGB_u8;

typedef struct BGR_u8
{
    unsigned char B;
    unsigned char G;
    unsigned char R;
}BGR_u8;


//*~~~~~~~~~~~~~~~~~~~~~~~~
//*        SYMBOLS
//*~~~~~~~~~~~~~~~~~~~~~~~~



//*~~~~~~~~~~~~~~~~~~
//*In game Functions
//*~~~~~~~~~~~~~~~~~~

/** @defgroup psyq_functions PSY-Q Functions
 *  Functions from PSY-Q/C Standard Library.
 *  @{
 */
int printf (const char * format, ...);
int sprintf(char *output, const char *format, ...);
void memset(void *str, int c, int n);
int rand();
void srand(int seed);
/** @} */ // end of psyq_functions


/** @defgroup labeled_functions Labeled Functions
 *  Functions we have labeled but not yet re-implemented
 *  @{
 */
void Maybe_ArrayCopy(int *outputArray,int *inputArray,int arrayLength);                                       //? This function copies one array to another

/**
 * @brief Renders shaded moby objects in the world. (Gems, HUD Elements, etc.) \n Address: 0x80022a2c
*/
void RenderShadedMobys();

/**
 * @brief Renders normal moby objects in the world. (Enemies, Chests, Dragons, etc.) \n Address: 0x8001f798
*/
void RenderNormalMobys();

/**
 * @brief Renders all objects in the world. (Enemies, Chests, Dragons, etc.) \n Address: 0x8001f798
 * @details This is the main object rendering function. It calls all the other Render functions.
*/
void RenderAllObjects();

/**
 * @brief This is a weird hack that seems to be related to transparency for primitaves? \n Address: 0x80060670
*/
void PrimitiveAlphaHack(void* param_1, int param_2, int param_3, short colorSpace, int param_5);

/**
 * @brief Draws a golden line to the screen \n Address: 0x8001844c
 * @details Fills out a moby struct with the provided coordinate information, and puts it into the _ptr_primitivesArray. Automatically fills out color data, and has it shimmer by using the wobble timer.

 * @param int point1X - The X position of the first point of the line
 * @param int point1Y - The Y position of the first point of the line
 * @param int point2X - The X position of the second point of the line
 * @param int point2Y - The Y position of the second point of the line
*/
void DrawLine(int point1X, int point1Y, int point2X, int point2Y);                                      //? This function draws a yellow line.

void FillScreenColor(int colorSpace, char r, char g, char b);                                           //? Fills the screen with a specific color.

void PlayIntroCutscenes();                                                                              //? This function is related to the intro cutscenes.

void TheAdventureBegins();                                                                              //? This function calls the "The Adventure Begins" start sequence in the game.
void TheAdventureContinues();

void LockCameraToSpyro(void);

void Vec3IntToShortDiv4(short *Vec3ShortPTR,int *Vec3PTR);                                              //? This function takes an int vector, divides it by 4, then stores it as a short. Some things in spyro need to refer to position as a short rather than an int, like particles, this is where you'd convert them.

char* GetNextParticleSlot(char param_1);                                                                //? param_1 might be storing its subtype. It affects the way the particle looks ratio wise? It also stores the param value you pass into param_1 into the 1st element of the particle struct. NOT THE 0th.

void CreateParticle(int param_1, int param_2, int **ptrToMoby, int *param_4);                           //? This function creates a particle. param_1 amount of particles, param_2 Is the Particle ID, param_3 is a Vec3 to its Initial Spawn Position, param_4 Vec3 of Amount of Units to Travel from Inital POS

void UpdateMobyCollision(int param_1, unsigned int param_2);                                            //? Research this more.

int PlaySoundEffect(int soundEffectID, int ptrToMoby, int playbackMode, char *param_4);

/**
 * @brief Plays/Continues a music track \n Address: 0x800567f4
 * @details param_1 is the track to play. param_2 is the flags/mode. For param_2, 1 is to start at the beginning of the track, 8 is continue where it left off assuming it was saved.

 * @param int point1X - The X position of the first point of the line
 * @param int point1Y - The Y position of the first point of the line
 * @param int point2X - The X position of the second point of the line
 * @param int point2Y - The Y position of the second point of the line
*/
void PlayMusicTrack(int track_number, int flags);

int LoadImageOrTexture(RECT *rect, int *p);

int DrawSync(int mode);

void Maybe_ResetHudTimers(void);
/** @} */ // end of labeled_functions


//*~~~~~~~~~~~~~~~~~
//*In Game Variables
//*~~~~~~~~~~~~~~~~~
/** @defgroup labeled_global_variables Labeled Global Variables
 *  Functions we have labeled but not yet re-implemented
 *  @{
 */

// Booleans

/**
 * @brief If has started new game/continue game, then is 1 for true. Basically after you leave the title screen this is always 1. \n Address: 0x8007566c 
 */
extern bool _isPastTitleScreen;  

/**
 * @brief true/1 if is in loading screen. \n Address: 0x800756B0
 */              
extern bool _isLoading;  

/**
 * @brief true/1 If inside options menu in start menu. \n Address: 0x800757C8
 */                                   
extern bool _isInsideOptionsMenu;

/**
 * @brief true/1 If can fly in to level. This is always 1. If set to 0, will just fade in instead of flying in. I assume this is a leftover from prototypes? \n Address: 0x800756D0
 */         
extern bool _canFlyIn; 

// Timers

/**
 * @brief This is the global timer. It is running at all times from game boot up past BIOS. \n Address: 0x800749e0
 */         
extern int _globalTimer;

/**
 * @brief This is the pause/inventory menu timer. It is only running in those menus. \n Address: 0x800758B8
 */         
extern int _pausedTimer;   

/**
 * @brief This is the pause/inventory menu timer. It is only running in those menus. \n Address: 0x8007588c
 */  
extern int _loadingTimer;

/**
 * @brief This is a level specific timer. This timer is running when when you are able to control spyro, and doesn't reset until you enter a new level. \n Address: 0x8007572C 
 */ 
extern int _levelTimerWhenActive;   

/**
 * @brief This is a level specific timer that runs at 60fps. This timer is running at all times, and doesn't reset until you enter a new level. \n Address: 0x800758C8
 */ 
extern int _levelTimer_60fps; 

/**
 * @brief This is a global timer at 60fps. It is running at all times, and controls the vSync. If frozen, video freezes. Can be unfrozen. \n Address: 0x800749E0 
 */ 
extern int _vSyncTimer_60fps;

/**
 * @brief This is a timer that is often used for changing the opacity of things like lines, the shimmer of text, etc. \n Address: 0x800770f4 
 */ 
extern int _wobbleAndOpacityTimer;


// Important Stuff

/**
 * @brief Main gamestate. Gamestate values are stored in the GameState enums. \n Address: 0x800757D8 
 * @see GameState
 */ 
extern int _gameState;

/**
 * @brief Value coorsponding the the current button(s) being held. \n Address: 0x80077380 
 * @see Buttons
 */ 
extern unsigned short _currentButtonsHeld;

/**
 * @brief Value coorsponding the the current button(s) that were pressed for 1 frame. Goes back to 0 after 1 frame. \n Address: 0x80077378
 * @see Buttons
 */ 
extern unsigned short _currentButtonsPressed;

/**
 * @brief STILL RESEARCHING \n Address: 0x80078E50
 * @warning Need to research more
 */ 
extern int _secondController; 

/**
 * @brief Research this more. 0xA is the loop for example. \n Address: 0x80078AD4
 * @warning Need to research more
 */ 
extern int _movementSubState;

/**
 * @brief 0x5 for in portal, 0xF for loading afterwards. Stays on 0xF until next portal. \n Address: 0x80078C70
 * @warning Need to research more. Might be part of spyro struct
 */ 
extern int _isInPortal; 
                                                          
/**
 * @brief Total amount of global gems \n Address: 0x80075860
 */ 
extern short _globalGemCount;

/**
 * @brief Total amount of global dragons \n Address: 0x80075750
 */ 
extern int _globalDragonCount; 

/**
 * @brief Total amount of global eggs \n Address: 0x80075810
 */ 
extern int _globalEggCount;


/**
 * @brief Current Level ID according to the LevelIDS enum \n Address: 0x800758B4
 * @details This LevelID is used to determine which level will be loaded when in a loading screen, amung other things.
 * @see LevelIDS
 */ 
extern int _levelID;

/**
 * @brief Level ID for which portal to exit from in Homeworld. Uses same LevelIDS enum \n Address: 0x800758AC 
 * @details This LevelID is used to determine which level portal you will come out of when you exit a level back to the homeworld.
 * @see LevelIDS
 */ 
extern char _portalToExitFromInHW;   

/**
 * @brief This is what determines the fly in animation during the loading screen of a level \n Address: 0x80076EA8
 * @see LevelFlyInAnimations
 */ 
extern short _flyInAnimation;                 

/**
 * @brief Camera Position \n Address: 0x80076DF8 
 * @see Vec3
 */ 
extern Vec3 _cameraPosition;

/**
 * @brief Camera Angle (yaw, pitch, roll) \n Address: 0x80076E1C
 * @see CameraAngle
 */ 
extern CameraAngle _cameraAngle;

extern short _cameraRotationMatrix[3][3];
extern short _cameraPureRotationMatrix[3][3];

/**
 * @brief A scaled up sin lookup table \n Address: 0x8006cbf8
 * @see SinScaled()
 */ 
extern short _sinArray[256];

/**
 * @brief This is the current state of the main menu. Should make an enum for this \n Address: 0x80078D88
 */ 
extern char _mainMenuState;

/**
 * @brief The State for the balloonist. Should make an enum for this. \n Address: 0x800777e8
 */ 
extern int _balloonistState;

/**
 * @brief This is the current option selected in the main start menu, according to the StartMenuSelections enum. \n Address: 0x80075720
 * @see StartMenuSelections
 */ 
extern int _startMenuSelection;

/**
 * @brief This is the current homeworld menu in the inventory menu according to the InventoryMenuSelections enum's. \n Address: 0x80075744
 * @see InventoryMenuSelections
 */ 
extern int _inventoryMenuScreen;

/**
 * @brief Which cutscene is currently being played \n Address: 0x80078D94
 */ 
extern char _whichCutscene;

/**
 * @brief This is what determines how much to fill the screen with a black fade in effect. \n Address: 0x80075918 
 * @details Will automatically decrement the fade back to 0 by 1 every frame until 0
 */ 
extern char _effect_ScreenFadeIn;

/**
 * @brief This is what determines how much to fill the screen with the top and bottom letterbox effect. \n Address: 0x800756C0
 * @details Will automatically decrement the letterbox effect by 1 every frame until 0
 */ 
extern char _effect_ScreenLetterBox;

/**
 * @brief The array for what collectables you have collected globally so far. \n Address: 0x80077900
 * @details This is what the game references for loading gems/dragons into a level or not when you load into it/respawn. This is also the memory location for when you load a game from a save file. This is immediately where the data gets stored.
 */ 
extern char _collectablesStateFlags[1231];

/**
 * @brief This is a pointer to the start of the level moby's array of stucts. \n Address: 0x80075828 
 */ 
extern int* _ptr_levelMobys;

/**
 * @brief  This is a pointer to the start of the dynamic level moby's array. \n Address: 0x8007573C 
 * @details Dynamic level moby's are the ones that don't spawn immediatly, but spawn from gameplay. Gems from chests/enemies, lives, etc.
 */ 
extern int* _ptr_dynamicLevelMobys;

/**
 * @brief  This is a pointer to the start of the level moby's special data array of structs. \n Address: 0x80075930
 * @details The special data is any data that is unique to that particular moby. The special data pointer is always the first element of any moby struct.
 */ 
extern int* _ptr_levelMobySpecialData;

// #define _ptr_levelMobySpecialData _ptr_endDynamicMobys //0x80075930        //? Just giving it another name, since it also could be used to indicate the end of dynamic mobys, instead of just being used to indicate the start of levelMobyData.



extern int* _ptr_primitivesArray; //0x800757b0                //? Not too sure.
extern int* _ptr_arrayGraphicsRelatedPointers; //0x8007581c   //? Ptr the the array of primitives structs to be drawn every frame

extern char* _ptr_particleLinkedList; //0x80075738           //? This is a pointer to the next available particle slot.

extern char _hudChestState;  //0x80077FA8
extern char _hudDragonState; //0x80077FA9
extern char _hudLivesState;  //0x80077FAA
extern char _hudEggsState;   //0x80077FAB
extern char _hudAnimationState;   //0x80077FAC

extern int _hudElementsSpinTimer; //0x80077fe4
extern int _unk_spinRelated;    //0x8006cc78
extern char* _localSoundEffects; //0x800761D4

/**
 * @brief The music track that is associated with the level you're currently in. \n Address: 0x80075828 
 * @details This variable is used to play the correct music track for the level you're in
 */ 
extern int _musicLevelTrack;  //0x0x800774b0

extern int* _maybe_ptr_levelTextureRelated; //0x800785f0

extern byte _cdStatus; //0x80074e44
/** @} */ // end of labeled_global_variables

#endif /* COMMON_H */
