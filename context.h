#ifndef CUSTOM_TYPES_H
#define CUSTOM_TYPES_H

typedef int                     bool;
#define TRUE 1
#define FALSE 0
#define true 1
#define false 0

#define NULL (void*)0

#define DECIMAL 10
#define HEXIDECIMAL 16
#define BINARY 2


typedef unsigned int            uint;

typedef unsigned char           byte;

typedef signed char             s8;
typedef unsigned char           u8;
typedef signed short int        s16;

typedef unsigned short int      u16;
typedef signed int              s32;
typedef unsigned int            u32;

typedef unsigned char           uint8;
typedef unsigned short          uint16;
typedef unsigned int            uint32;

typedef signed char             int8;
typedef signed short            int16;
typedef signed int              int32;


#endif /* CUSTOM_TYPES_H */



#ifndef VECTOR_H
#define VECTOR_H


//~~~~~~~
//Structs
//~~~~~~~
typedef struct Vec3
{
    int x;
    int y;
    int z;
}Vec3;

typedef struct Vec2
{
    int x;
    int y;

}Vec2;

typedef struct Vec3Padding
{
    int x;
    int y;
    int z;
    int padding;
}Vec3Padding;

typedef struct Vec3_u16
{
    unsigned short x;
    unsigned short y;
    unsigned short z;
}Vec3_u16;

typedef struct Vec3_u8
{
    unsigned char x;
    unsigned char y;
    unsigned char z;
}Vec3_u8;


typedef struct Vec2_u16
{
    unsigned short x;
    unsigned short y;
}Vec2_u16;

typedef struct Vec2_u8
{
    unsigned char x;
    unsigned char y;
}Vec2_u8;

typedef struct Angle
{
    int yaw;
    int pitch;
    int roll;
}Angle;

typedef struct Angle_u16
{
    short yaw;
    short pitch;
    short roll;
}Angle_u16;

typedef struct SpyroHeadAngle
{
    short roll;
    short pad1;

    short pitch;
    short pad2;

    short yaw;
    short pad3;
}SpyroHeadAngle;;

typedef struct CameraAngle
{
    short roll;
    short pitch;
    short yaw;
}CameraAngle;

typedef struct Angle_u8
{
    char yaw;
    char pitch;
    char roll;
}Angle_u8;

typedef struct MATRIX3BY3
{

    short matrix[3][3];

}MATRIX3BY3;


//~~~~~~~~~
//In Game Functions
//~~~~~~~~~

void Vec3Subtract(Vec3* destVector, Vec3* a, Vec3* b);

void Vec3Scale(Vec3* result, Vec3* vector, int multiplier);                 //Scales the s

void Vec3ScaleDownByPowerOfTwo(Vec3* vector, unsigned int pot);

void Vec3ScaleDownBy4(Vec3_u16 result, Vec3* source);                        //Scales down the source vector by 4, then stores it in a short vector. 

void Vec3ScaleByFractionPowerOfTwo(Vec3* param_1, int numerator, unsigned int denominatorExponent);               //80017614     
void Vec3ScaleByFraction(Vec3* param_1, int denominator, int numerator);

unsigned int Vec3CalculateLengthE(Vec3* vector, bool flag3D);

void Vec3ApplyRotationMatrix(int* rotationMatrix, unsigned int* inputVector, int* outputVector);

void MatrixTranspose(unsigned int *dest, unsigned int *src);

void Vec3Swap(int *param_1,int *param_2);




#endif /* VECTOR_H */



#ifndef COMMON_H
#define COMMON_H


//~~~~~~~~~
//Constants
//~~~~~~~~~

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

typedef enum LevelFlyInAnimations
{
    FACING_LEFT = 0xCA6C,
    FACING_RIGHT = 0xCA3C,
    FACING_FORWARD = 0xCA24,
    FACING_BACKWARDS = 0xCA84,
    FACING_DIAGONAL = 0xCA9C,   // wizard peak specific
    RETURNING_HOME = 0xCA54
}LevelFlyInAnimations;

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

//Pre-Reqs for other functions

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

void CopyHudToShaded();

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
extern int _ptrTextUnk; //0x800720f4                          //? Not too sure.
extern char* _ptr_hudMobys; //0x80075710                      //? A pointer to a dynamic downwards growing array of moby structs to render that gets rendered to the hud every frame.

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



#ifndef MOBY_H
#define MOBY_H

//~~~~~~~~~
//Constants
//~~~~~~~~~
#define MOBY_SIZE 0x58

#define ARROW_RIGHT 0
#define ARROW_LEFT 1

enum HudMobyTypes
{
    MOBY_ID_WATERFALL_PARTICLE_SPAWNER = 0xB,
    MOBY_ID_LIFE_FIGURINE = 0xE,
    MOBY_ID_EGG = 0x22,
    MOBY_ID_SPYRO_HEAD = 0x3A,
    MOBY_ID_EXCAILMATION = 0x4B,
    MOBY_ID_COMMA = 0x4C,
    MOBY_ID_KEY = 0xAD,
    MOBY_ID_DRAGON_FIGURINE = 0x1FA,
    MOBY_ID_GEM_CHEST = 0x1D7,
    MOBY_ID_GEM_CHEST_2 = 0x1D9,
    MOBY_ID_VOLUME_BAR = 0x1B2,

    MOBY_ID_ONE_GEM = 0x53,
    MOBY_ID_TWO_GEM = 0x54,
    MOBY_ID_FIVE_GEM = 0x55,
    MOBY_ID_TEN_GEM = 0x56,
    MOBY_ID_TWENTYFIVE_GEM = 0x57
};

enum FullMobyTypes
{
    DRAGON_MOBY_ID = 0xFA,
    CHEST_MOBY_ID = 0xC2,

    ARTISANS_GNORC = 0x72


};

enum MobyHeldValues
{
    ORB_HELD_ID = 0xFF,
    LIFE_HELD_ID = 0xE,
    BUTTERFLY_HELD_ID = 0x10,
    ONE_GEM_HELD_ID = 0x53,
    TWO_GEM_HELD_ID = 0x54,
    FIVE_GEM_HELD_ID = 0x55,
    TEN_GEM_HELD_ID = 0x56,
    TWENTYFIVE_GEM_HELD_ID = 0x57

};

enum MobyColors
{
    MOBY_COLOR_TRANSPARENT = 0x00,
    MOBY_COLOR_WHITE = 0x01,
    MOBY_COLOR_BLACK = 0x06,
    MOBY_COLOR_MATTE_GREY = 0x07,
    MOBY_COLOR_EMERALD_GREEN = 0x09,
    MOBY_COLOR_BLUE = 0x0A,
    MOBY_COLOR_GOLD = 0x0B,
    MOBY_COLOR_GREY = 0x0C,
    MOBY_COLOR_RED = 0x0D,
    MOBY_COLOR_GREEN = 0x0E,
    MOBY_COLOR_PURPLE = 0x17,
    MOBY_COLOR_NEON_YELLOW = 0x18,
    MOBY_COLOR_CHEESE_YELLOW = 0x19,
    MOBY_COLOR_DARK_RED = 0x1F,
    MOBY_COLOR_NEON_RED = 0x20,
    MOBY_COLOR_DARK_GREEN = 0x21,
    MOBY_COLOR_NEON_GREEN = 0x22,
    MOBY_COLOR_NEON_BLUE = 0x24,
    MOBY_COLOR_DARK_GOLD = 0x25,
    MOBY_COLOR_DARK_PURPLE = 0x27,
    MOBY_COLOR_NEON_PURPLE = 0x28,
    MOBY_COLOR_SHINY_RED = 0x29,
    MOBY_COLOR_SHINY_GREEN = 0x2A,
    MOBY_COLOR_SHINY_BLUE = 0x2B,
    MOBY_COLOR_SHINY_GOLD = 0x2C,
    MOBY_COLOR_SHINY_PURPLE = 0x2D,
    MOBY_COLOR_SILVER = 0x2E,
    MOBY_COLOR_MATTE_RED = 0x30,
    MOBY_COLOR_SKY_BLUE = 0x39,
    MOBY_COLOR_CYAN = 0x7E,
    MOBY_COLOR_PINK = 0xA5,
    MOBY_COLOR_INDIGO = 0xA6,
    MOBY_COLOR_MATTE_GREEN = 0xAC,
    MOBY_COLOR_NEON_LIME = 0xAD,
    MOBY_COLOR_BRIGHT_BLUE = 0xB1,
    MOBY_COLOR_VIOLET = 0xB2,
    MOBY_COLOR_BRIGHT_RED = 0xB3

};

enum GemColors
{
    GEM_COLOR_RED = 0x01,
    GEM_COLOR_GREEN = 0x02,
    GEM_COLOR_BLUE = 0x03,
    GEM_COLOR_YELLOW = 0x04,
    GEM_COLOR_PINK = 0x05,

    GEM_COLOR_BLACK = 0x00,
    GEM_COLOR_WHITE = 0x7c,
    GEM_COLOR_BROWN = 0x31,
    GEM_COLOR_ORANGE = 0x76,
    GEM_COLOR_PURPLE = 0x36,
    GEM_COLOR_MAGENTA = 0xA4,
    GEM_COLOR_VIOLET = 0x8D,
    GEM_COLOR_TURQUOISE = 0x3C,
    GEM_COLOR_SUNSET = 0x35,
    GEM_COLOR_BRONZE = 0x3B,
    GEM_COLOR_SILVER = 0x13,
    GEM_COLOR_GOLD = 0x78,
    GEM_COLOR_BLUE_PURPLE = 0x36,
    GEM_COLOR_DARK_PURPLE = 0x3A,
    GEM_COLOR_SKY_BLUE = 0x37,
    GEM_COLOR_LIGHT_PINK = 0xAE,
    GEM_COLOR_NEON_PINK = 0x40,
    GEM_COLOR_NEON_GREEN = 0x42,
    GEM_COLOR_WINE_RED = 0x0B,
    GEM_COLOR_CAMO_GREEN = 0x70,
    GEM_COLOR_LIME_GREEN = 0x74,
    GEM_COLOR_EMERALD_GREEN = 0xF6,
    GEM_COLOR_TAN_YELLOW = 0xAC,
    GEM_COLOR_BRIGHT_YELLOW = 0xFE
};


//~~~~~~~
//Structs
//~~~~~~~
typedef struct HudMobyInfo
{
    Vec3 position;                  // Coords in hud act different than in world space. X and Y act like 2D plane. Z is effective size in HUD.
}HudMobyInfo;


// ~~~ FULL MOBY STRUCT ~~~

/**
 * @brief  This is the main moby/object struct.
 * @details This is what most objects use for position, type, color, animation, scale, etc
 */ 
typedef struct Moby
{
    void* ptr_mobySpecificData;

    int empty1;
    int* ptr_colision;

    struct Vec3 position;

    short UNK21;                              
    
    short interactState;                            //0 for alive, 1 for flamed, 2 for charged. 

    int UNK2;
    int UNK3;
    int UNK4;
    int UNK5;
    int UNK6;
    int UNK7;

    short subType;                                  // Research this more
    short type;                                     // Determines what type of moby it is

    short UNK10;
    char canDropObject;                             //7D and lower yes, 80 and higher no
    char UNK22;


    char currentAnimation;                          //Should use next animation for setting animations.
    char nextAnimation;                             
    char currentKeyFrame;
    char nextKeyFrame;

    char speedRelated;
    char animationSpeed;


    char UNK13;
    char active;                                    //FF for yes, 0 for no

    struct Vec3_u8 rotation;

    char requiredHUD1;

    unsigned char state;                            // 00 still active, FD picked up. Had to make unsinged because, apparently its negative, so I have to force it to be positive.

    union
    {
        char howPickedUp;                           // 01 picked up by spyro, 03 picked up by sparx
        char subState;                             
    };

    char visable;                                   // FF visable, any other value not

    char UNK_shadowRelated;                         // 1-10 only shadow appears?

    struct BGR_u8 RGB;

    char color;                                     // Determines the color of the moby. (01 red, 02 green, etc.) This can be poked outside of its normal range to get some awesome colors.

    short requiredHUD2;

    char UNK19;

    char heldValue;

    short UNK20;

    short scale;                                    // Determines the scale of the gem. Range from 0x0000 - 0xFFFF. (0 normal sized, 0xFFFF smallest size)

}Moby;

//* ~~~ Functions ~~~


#endif /* MOBY_H */


#ifndef OPTIONS_H
#define OPTIONS_H

enum CameraMode
{
    CAMERA_MODE_ACTIVE = 0x02, 
    CAMERA_MODE_PASSIVE = 0x52
};

enum SpeakerSetup
{
    STEREO = 0x0,
    MONO = 0x1
};

enum PauseMenuState
{
    PAUSED_MAIN,
    PAUSED_OPTIONS,
    PAUSED_QUIT_GAME
};

#endif /* OPTIONS_H */


#ifndef PARTICLES_H
#define PARTICLES_H

struct Particle
{
    char type;                      //0x0
    char subtype;                   //0x1

    char decayTimer;                //0x2     0 longest, bigger number shorter duration
    char unk1;                      //0x3

    struct Vec3_u16 position;        //0x4 X POS, 0x6 Y POS, 0x8 Z POS

    struct Vec2_u8 scale;            //0xA X SCALE, 0xB Y SCALE

    struct RGB_u8 color;             //0xC RED, 0xD BLUE, 0xE GREEN

    char unk2;                      //0xF

    short unk3;                     //0x10
    short unk4;                     //0x12
    short unk5;                     //0x14
};

#endif //PARTICLES_H

#ifndef CD_H
#define CD_H


enum CdControlPrimatives
{
    CdlNop = 0x01,
    CdlSetloc = 0x02,
    CdlPlay = 0x03,
    CdlForward = 0x04,
    CdlBackward = 0x05,
    CdlReadN = 0x06,
    CdlStandby = 0x07,
    CdlStop = 0x08,
    CdlPause = 0x09,
    CdlMute = 0x0B,
    CdlDemute = 0x0C,
    CdlSetfilter = 0x0D,
    CdlSetmode = 0x0E,
    CdlGetparam = 0x0F,
    CdlGetlocL = 0x10,
    CdlGetlocP = 0x11,
    CdlSeekL = 0x15,
    CdlSeekP = 0x16,
    CdlReadS = 0x1B
};

typedef void (*CdlCB)(unsigned char,unsigned char *);

typedef struct CdlFILTER{
    unsigned char file;         //File ID, Always 1
    unsigned char chan;         //Channel ID, Picks a song from the current music file (goes up to 7)
    unsigned short pad;         //System reserved
} CdlFILTER; 

typedef struct CdlLOC{
	unsigned char minute;		/* minute (BCD) */
	unsigned char second;		/* second (BCD) */
	unsigned char sector;		/* sector (BCD) */
	unsigned char track;		/* track (void) */
} CdlLOC;

int CdRead(int sectors, unsigned int * buf, int mode);
int CdInit();
CdlCB CdReadCallback(CdlCB func);
//int CdStatus(void);
int CdSync(int mode, unsigned char * result);
int CdControl(unsigned char com, unsigned char * param, unsigned char * result);  //Tells the CD-DRIVE to do a primitive function, and someimes allows concurrent cd functions
int CdControlB(unsigned char com, unsigned char * param, unsigned char * result); //Tells the CD-DRIVE to do a primitive function, and ONLY that one function. 
void *CdDataCallback(void (*func)());
CdlLOC *CdIntToPos(int i, CdlLOC * p);
int CdPosToInt(CdlLOC * p);
int CdSync_(int mode, unsigned char * result);

void read_cb(unsigned char status, unsigned char *result);

extern int _musicSectors;


#endif /* CD_H */


#ifndef FILTERS_H
#define FILTERS_H


//~~~~~~~~~
//Constants
//~~~~~~~~~

typedef enum PrimitiveCode
{
    POLY3F_OPAQUE = 0x20,
    POLY3F_TRANSPARENT = 0x22,
    POLY3F_OPAQUE_SHADED = 0x30,
    POLY3F_TRANSPARENT_SHADED = 0x32,
    POLY3F_OPAQUE_TEXURED_RAW = 0x25,
    POLY3F_TRANSPARENT_TEXTURED_RAW = 0x27,
    POLY3F_OPAQUE_SHADEDANDTEXTURED_RAW = 0x34,
    POLY3F_TRANSPARENT_SHADEDANDTEXTURED_RAW = 0x36,

    POLY4F_OPAQUE = 0x28,
    POLY4F_TRANSPARENT = 0x2A,
    POLY4F_OPAQUE_SHADED = 0x38,
    POLY4F_TRANSPARENT_SHADED = 0x3A,
    POLY4F_OPAQUE_TEXTURED_RAW = 0x2D,
    POLY4F_TRANSPARENT_TEXTURED_RAW = 0x2F,
    POLY4F_OPAQUE_SHADEDANDTEXTURED_RAW = 0x3C,
    POLY4F_TRANSPARENT_SHADEDANDTEXTURED_RAW = 0x3E,

    LINE_OPAQUE = 0x40,
    LINE_TRANSPARENT = 0x42,
    LINE_OPAQUE_SHADED = 0x50,
    LINE_TRANSPARENT_SHADED = 0x52
}PrimitiveCode;

enum ColorModes
{
    COLORMODE_4BIT,
    COLORMODE_8BIT,
    COLORMODE_16BIT
};

// enum DrawOpaqueShapeColorSpaces
// {
//     RGB_DARK = 0x00,
//     RGB = 0x20,
//     CMY = 0x40
// };

//~~~~~~~
//Structs
//~~~~~~~

typedef struct Poly3F
{

    int tag;

    RGB_u8 color;
    char code;

    struct Vec2_u16 point1Pos;
    struct Vec2_u16 point2Pos;
    struct Vec2_u16 point3Pos;

} Poly3F;


typedef struct Poly4F 
{

    int tag;

    RGB_u8 color;
    char code;

    struct Vec2_u16 point1Pos;
    struct Vec2_u16 point2Pos;
    struct Vec2_u16 point3Pos;
    struct Vec2_u16 point4Pos;

} Poly4F;

typedef struct Poly3FShaded
{

    int tag;

    RGB_u8 color;
    char code;

    struct Vec2_u16 point1Pos;

    RGB_u8 color2;
    struct Vec2_u16 point2Pos;

    RGB_u8 color3;
    struct Vec2_u16 point3Pos;

} Poly3FShaded;

typedef struct Poly4FShaded
{

    int tag;

    RGB_u8 color;
    char code;

    struct Vec2_u16 point1Pos;

    RGB_u8 color2;
    struct Vec2_u16 point2Pos;

    RGB_u8 color3;
    struct Vec2_u16 point3Pos;
    
    RGB_u8 color4;
    struct Vec2_u16 point4Pos;

} Poly4FShaded;

typedef struct Poly4FTextured 
{

    int tag;

    RGB_u8 color;
    char code;

    struct Vec2_u16 point1Pos;

    struct Vec2_u8 texturePoint1Pos; // The X for compressed textures is doubled.
    short clut;

    struct Vec2_u16 point2Pos;

    struct Vec2_u8 texturePoint2Pos;
    short texturePage;

    struct Vec2_u16 point3Pos;
    struct Vec2_u8 texturePoint3Pos;
    short PADDING1;
    struct Vec2_u16 point4Pos;
    struct Vec2_u8 texturePoint4Pos;
    short PADDING2;

} Poly4FTextured;

typedef struct Poly4FShadedTextured 
{

    int tag;

    RGB_u8 color;
    char code;

    struct Vec2_u16 point1Pos;

    struct Vec2_u8 texturePoint1Pos; // The X for compressed textures is doubled.
    short clut;

    RGB_u8 color2;

    struct Vec2_u16 point2Pos;

    struct Vec2_u8 texturePoint2Pos;
    short texturePage;

    RGB_u8 color3;

    struct Vec2_u16 point3Pos;

    struct Vec2_u8 texturePoint3Pos;
    short PADDING1;

    RGB_u8 color4;

    struct Vec2_u16 point4Pos;
    struct Vec2_u8 texturePoint4Pos;
    short PADDING2;

} Poly4FShadedTextured;

typedef struct Line
{
    int tag;

    RGB_u8 color;                    //? 0x4 - 0x6
    char code;                      //? 0x7

    Vec2_u16 point1Pos;              //? 0x8-0xB
    Vec2_u16 point2Pos;              //? 0x10-0x13 

} Line;

typedef struct ShadedLine
{
    int tag;

    RGB_u8 colorP1;                  //? 0x4 - 0x6
    char code;                      //? 0x7

    Vec2_u16 point1Pos;              //? 0x8-0xB

    RGB_u8 colorP2;                  //? 0xC-0xE
    char PADDING5;                  //? 0xF

    Vec2_u16 point2Pos;              //? 0x10-0x13 
} ShadedLine;


typedef struct Poly4F_Vec3 
{
    struct Vec3 point1Pos;
    struct Vec3 point2Pos;
    struct Vec3 point3Pos;
    struct Vec3 point4Pos;

} Poly4F_Vec3;


typedef struct Poly4FPadded      //! FOR IN GAME
{
    int PADDING1;
    int PADDING2;
    int PADDING3;
    
    int tag;

    RGB_u8 color;
    char code;

    struct Vec2_u16 point1Pos;
    struct Vec2_u16 point2Pos;
    struct Vec2_u16 point3Pos;
    struct Vec2_u16 point4Pos;

} Poly4FPadded;

#endif //FILTERS_H

#ifndef SOUND_H
#define SOUND_H

enum SoundPlaybackModes
{
    SOUND_PLAYBACK_MODE_NORMAL = 0x10,
    SOUND_PLAYBACK_MODE_CONNECTED_TO_MOBY = 0x8
};

enum SoundEffectIDS
{
SOUND_EFFECT_SPYRO_WALKING_1 = 0x0,
SOUND_EFFECT_SPYRO_WALKING_2 = 0x1,
SOUND_EFFECT_SPYRO_WALKING_3 = 0x2,
SOUND_EFFECT_SPYRO_PIVOT = 0x3,
SOUND_EFFECT_SPYRO_STOP = 0x3,
SOUND_EFFECT_SPYRO_JUMP = 0x4,
SOUND_EFFECT_SPYRO_LAND = 0x5,
SOUND_EFFECT_SPYRO_LAND_FLOP = 0x6,
SOUND_EFFECT_SPYRO_FLAME = 0x7,
SOUND_EFFECT_SPYRO_ROLL = 0x8,
SOUND_EFFECT_SPYRO_BONK = 0x9,
SOUND_EFFECT_UNK_SWIPE = 0xA,
SOUND_EFFECT_UNK_WOOD = 0xB,
SOUND_EFFECT_UNK_LIQUID = 0xC,
SOUND_EFFECT_UNK_LIQUID_2 = 0xD,
SOUND_EFFECT_UNK_LIQUID_3 = 0xE,
SOUND_EFFECT_UNK_HIT = 0xF,
SOUND_EFFECT_UNK_HIT_2 = 0x10,
SOUND_EFFECT_GEM_COLLECTED_DING = 0x11,
SOUND_EFFECT_DRAGON_PEDISTOOL_DING = 0x11,
SOUND_EFFECT_GEM_HIT_FLOOR = 0x12,
SOUND_EFFECT_SPARX_GRAB_GEM = 0x12,
SOUND_EFFECT_CHARGING = 0x13,
SOUND_EFFECT_FLAME_TOUCH_SURFACE = 0x14,
SOUND_EFFECT_SPYRO_DIZZY = 0x15,
SOUND_EFFECT_ENEMY_DISAPEAR = 0x16,
SOUND_EFFECT_PORTAL_SHIMMER = 0x17,
SOUND_EFFECT_UNK_GRASS = 0x18,
SOUND_EFFECT_GOOP = 0x19,
SOUND_EFFECT_OPEN_PAUSE_MENU_DING = 0x1A,
SOUND_EFFECT_OPEN_INVENTORY_MENU = 0x1A,
SOUND_EFFECT_PAUSE_MENU_CHANGE_SELECTION_DING = 0x1B,
SOUND_EFFECT_PAUSE_MENU_CHANGE_MENU_DING = 0x1C,
SOUND_EFFECT_PAUSE_MENU_EXIT_DING = 0x1C,
SOUND_EFFECT_DRAGON_FREE = 0x1D,
SOUND_EFFECT_DRAGON_BREAK_OPEN = 0x1E,
SOUND_EFFECT_DRAGON_RUMBLE = 0x1F,
SOUND_EFFECT_DRAGON_DISAPEAR = 0x20,
SOUND_EFFECT_DRAGON_BEGIN_DISAPEAR = 0x21,
SOUND_EFFECT_DRAGON_UNK = 0x22,
SOUND_EFFECT_TITLE_SCREEN_MEMORY_CARD_SELECTION = 0x23,
SOUND_EFFECT_SPYRO_HIT = 0x24,
SOUND_EFFECT_UNK_DING = 0x25,
SOUND_EFFECT_DEEP_WIND = 0x26,
SOUND_EFFECT_SUNNY_FLIGHT_WALL_LOWERS = 0x26,
SOUND_EFFECT_WATERFALL = 0x27,
SOUND_EFFECT_BIRD_1 = 0x28,
SOUND_EFFECT_BIRD_2 = 0x29,
SOUND_EFFECT_BIRD_3 = 0x2A,
SOUND_EFFECT_BIRD_4 = 0x2B,
SOUND_EFFECT_BIRD_5 = 0x2C,
SOUND_EFFECT_BIRD_6 = 0x2D,
SOUND_EFFECT_HAWK_1 = 0x2E,
SOUND_EFFECT_HAWK_2 = 0x2F,
SOUND_EFFECT_SEAGULL_1 = 0x30,
SOUND_EFFECT_SEAGULL_2 = 0x31,
SOUND_EFFECT_WHIRLWIND = 0x32,
SOUND_EFFECT_MONEYBAG_GNORC_BELTCH = 0x33,
SOUND_EFFECT_UNK_GRASS_2 = 0x34,
SOUND_EFFECT_UNK_GRASS_3 = 0x35,
SOUND_EFFECT_MONEYBAG_GNORC_HIT = 0x36,
SOUND_EFFECT_MONEYBAG_GNORC_GEMS_SHAKE_1 = 0x37,
SOUND_EFFECT_MONEYBAG_GNORC_GEMS_SHAKE_2 = 0x38,
SOUND_EFFECT_MONEYBAG_GNORC_DEATH_GROAN_1 = 0x39,
SOUND_EFFECT_MONEYBAG_GNORC_DEATH_GRAON_2 = 0x3A,
SOUND_EFFECT_ARTISANS_GNORC_SCARED = 0x3B,
SOUND_EFFECT_ARTISANS_GNORC_SHIVERING_1 = 0x3C,
SOUND_EFFECT_ARTISANS_GNORC_SHIVERING_2 = 0x3D,
SOUND_EFFECT_ARTISANS_GNORC_HIT = 0x3E,
SOUND_EFFECT_UNK_HIT_3 = 0x3F,
SOUND_EFFECT_UNK_HIT_4 = 0x40,
SOUND_EFFECT_WOODEN_CHEST_BREAK = 0x41,
SOUND_EFFECT_LIFE_CHEST_OPEN = 0x42,
SOUND_EFFECT_LIFE_CHEST_RUMBLE = 0x43,
SOUND_EFFECT_LIFE_CHEST_BREAK = 0x44,
SOUND_EFFECT_LIFE_CHEST_CLOSE = 0x45,
SOUND_EFFECT_SHEEP_BOUNCE = 0x46,
SOUND_EFFECT_SHEEP_HIT = 0x47,
SOUND_EFFECT_SPYRO_2_POWERUP = 0x48,
SOUND_EFFECT_SPARX_EAT = 0x49,
SOUND_EFFECT_SPARX_FULL_EAT = 0x4A,
SOUND_EFFECT_LIFE_CHEST_BLINK = 0x4B,
SOUND_EFFECT_DRAGON_IDLE_SHAKE = 0x4C
};

#endif //SOUND_H

#ifndef SPYRO_H
#define SPYRO_H


//*~~~~~~~~~
//*Constants
//*~~~~~~~~~

typedef enum SpyroStates
{
    IDLE_STANDING = 0x0,
    BEGIN_WALK = 0x1,
    WALKING = 0x2,
    END_WALK = 0x3,
    PIVOT = 0x4,
    JUMP = 0x5,
    FLOP = 0x6,
    HURT_ZAPPED = 0x7,
    ROLL_LEFT = 0x9,
    ROLL_RIGHT = 0xA,
    CHARGE = 0xB,
    BONK = 0xC,
    LEDGE_PEER = 0xD,
    HURT_PITCH_HIGH = 0xE,
    GLIDE = 0xF,
    TRIANGLE_DROP = 0x10,
    WHIRLWIND = 0x11,
    IDLE_LOOK_AROUND = 0x12,
    ROLL_DOWN_SLOPE = 0x13,
    CHARGING_AIR = 0x14,
    UPHILL_WALK = 0x15,
    HURT_ROLL = 0x16,
    PULL_BACK_GLIDE = 0x17,
    CHARGING_AIR_SC_JUMP = 0x18,
    HURT_SQUISHED = 0x19,
    CANNON_ROTATE = 0x1A,
    HURT_YAW = 0x1B,
    HURT_PITCH_LOW = 0x1C,
    DROWNING = 0x1D,
    DEATH_SPIN = 0x1E,
    DEATH_SQUISHED = 0x1F,
    SUPERFLY = 0x20,
    SUPERFLY_ASCENDING = 0x21,
    SUPERFLY_DESCENDING = 0x22,
    IDLE_SIT = 0x27,
    SUPERCHARGE = 0x2C
}SpyroStates;

/**
 * @brief  This is the main Spyro struct.
 * @details This is what Spyro uses for most of his data: position, velocity, animations, color filter, angle, etc.
 */ 
typedef struct Spyro
{

struct Vec3 position;                               //? Spyro's position vector.

struct Angle_u8 RelativeSparxAngle;                  //? Something to do with sparx's rotation based on spyros angle I think.

char pad1;
int unkown1;
int unkown2;

char currentAnim;                                   //? Spyros current animation.
char nextAnim;                                      //? Spyros next animation.

char maybe_currentAnimDupe;
char maybe_nextAnimDupe;
char maybe_currentAnimDupe2;
char maybe_nextAnimDupe2;

char currentKeyfame;                                //? The current animation keyframe.
char nextKeyframe;                                  //? The next animation keyframe.

char maybe_keyframeDupe1;
char maybe_keyframeDupe2;
char maybe_keyframeDupe3;
char maybe_keyframeDupe4;
char maybe_AnimSpeedRelated;
char maybe_animSpeedRelatedDupe1;
char maybe_animSpeedRelatedDupe2;
char unkown3;


RGBA_u8 colorFilter;                       //? The color filter to apply to spyro. Used during fairy kiss, electric shock, etc.

short maybe_weirdDamageAnimRelated;
short unkown4;
int pad2;
int unkown5;
int unkown6;
int unkown7;
int unkown8;
int unkown9;
int pad3;
int pad4;
int pad5;
int maybe_animUpdateRelated;

char animSpeed;                                     //? The speed at which to play the animations.

char unkown10;
char unkown11;
char unkown12;
int maybe_animStateRelated;
int maybe_headAnimRelated;
int unkown_anim1;
int maybe_headAnimRelated2;
int maybe_tailAnimRelated;
int unkown13;
int maybe_tailAnimRelated2;

int state;                                          //? Spyro's current state.

int subState;                                       //? Spyro's current substate.

int framesInCurrentState;	                        //? The amount of frames spent in the current state. Used for calculations for jumping, boking, damage, time sensitive states, etc

int unkown14;
int unkown15;

struct Vec3 maybe_positionRelative;

int timer_framesIdle;                               //? The amount of frames you have spent idleing.

int timer_framesInAir;                              //? The amount of frames spyro has spent in the air.


int unkown_heightRelated;
int unkown_angleRelated;
int unkown_angleRelated2;
int unkown_angleRelated3;
int unkown_angleRelated4;
int unkown_angleRelated5;
int unkown_portalRelated;
int unkown_portalRelated2;
int unkown_portalRelated3;
int unkown_landingMomentumRelated;
int unkown_angleRelated6;
int unkown_angleRelated7;



struct Vec3 groundedChargeMomentum;                 //? Spyro's grounded charge momentum vector.

struct Vec3 walkingMomentum;                        //? Spyro's walking momentum vector.

struct Vec3 groundedChargeMomentum2;                //? Spyro's groundedChargeMomentum vector again? Unsure.

struct Vec3 airMomentum;                            //? Spyro's air momentum vector.

int unkown_angleRelated8;
int unkown16;
int unkown17;
int unkown18;
int unkown19;
int maybe_glideAndWalkOffLedgeZMomentum;

int absoluteMomentum;

struct Angle angle;                                 //? Spyro's angle vector.

int maybe_speedRelated;
int unkown21;                               
int unkown22;
int unkown23;
int unkown24;
int unkown25;
int unkown26;

int walkingAcceleration;                            //? Spyro's walking acceleration.

int turnAcceleration;
int z_Acceleration;

int hasUsedGlide;                                   //? bool for if Spyro has used glide or not yet, since can only use once in this game.     

int isGliding;                                      //? bool for if Spyro is currently gliding.

int neutralJumpZPos;

int isGrounded;                                     //? bool for if Spyro is currently grounded.

int iFramesTimer;                                   //? Timer for the amount of invincibility frames Spyro should have. Counts down to 0 every frame unless set every frame to a value.

int health;                                         //? Spyro's health value. Sparx's color get's set based on this value.

int drownTimer;                                     //? Timer for the amount of time left to drown I think, I didn't double check lol.

int maybe_superchargeRelated;

int isOverGoop;                                     //? bool for if Spyro is currently over goop.

int maybe_drowningRelated;

int unkown32;

struct Vec3 lastGroundedPosition;                   //? Spyro's last grounded position vector.

int unkown33;
int unkown34;
int unkown35;

int autoFlameRelated;

int maybe_isFlaming;
int unkown36;
int maybe_flameChargeTimerRelated;

SpyroHeadAngle TargetHeadAngle;                     //? Spyro's target head angle vector.

SpyroHeadAngle headAngle;                           //? Spyro's head angle vector.

int maybe_headRollTransitionSpeed;
int maybe_headPitchTransitionSpeed;
int maybe_headYawTransitionSpeed;

int maybe_smokeFlameStuff1;
int maybe_smokeFlameStuff2;
int maybe_smokeFlameStuff3;
int maybe_smokeFlameStuff4;
int maybe_smokeFlameStuff5;

int unkown37;
int unkown38;
int unkown39;

int maybe_tailRelated;
int maybe_chargeTimerRelated;

int isMovementLocked;                               //? Value for if spyro can input or not. Counts down from any value to 0 every frame if not set every frame to a value manually.

int maybe_weirdResearchThis;

int unkownOops;
int unkown40;
int unkown41;
int unkown42;
int unkown43;
int unkown44;
int unkown45;
int unkown46;
int unkown47;
int unkown48;
int unkown49;
int unkown50;
int unkown51;
int unkown52;
int unkown53;
int unkown54;
int unkown55;
int unkown56;
int unkown57;
int unkown58;
int unkown59;

int canSuperfly;                                           //? bool for if Spyro can superfly or not.
int isOnSuperchargeGround;                                 //? bool for if Spyro is on supercharge ground or not.

int maybe_pitchRelatedFlag;

int rollMomentum;                                           //? Spyro's roll momentum.
int pitchMomentum;                                          //? Spyro's pitch momentum.


}Spyro;

//*~~~~~~~~~~~~~~~~~
//*In Game Variables
//*~~~~~~~~~~~~~~~~~

/**
 * @brief  This is where spyro is in ram. This is the 1 instance of the spyro struct
 * @note Address: 0x80078A58
 * @see Spyro
 */ 
extern Spyro _spyro;


//! All of these below can be accessed through the spyro struct above, but I figuerd it be helpful to have all these addresses labled for the documentation
/**
 * @brief  Spyro's X Position Coordinate
 * @note Address: 0x80078A58
 * @see Spyro
 */ 
extern int _spyroXPosition;

/**
 * @brief  Spyro's Y Position Coordinate
 * @note Address: 0x80078A5C
 * @see Spyro
 */ 
extern int _spyroYPosition;

/**
 * @brief  Spyro's Z Position Coordinate
 * @note Address: 0x80078A60
 * @see Spyro
 */ 
extern int _spyroZPosition;

/**
 * @brief  Spyro's Yaw Rotation Angle
 * @note Address: 0x80078b74
 * @see Spyro
 */ 
extern int _spyroAngleYaw;

/**
 * @brief  Spyro's Pitch Rotation Angle
 * @note Address: 0x80078b78
 * @see Spyro
 */ 
extern int _spyroAnglePitch;

/**
 * @brief  Spyro's Roll Rotation Angle
 * @note Address: 0x80078b7C
 * @see Spyro
 */ 
extern int _spyroAngleRoll;

/**
 * @brief  This is the color filter applied on top of spyro in RGBA format
 * @details  This is what gets applied to spyro during superflame.
 * @note Address: 0x80078a80
 * @see Spyro RGBA_u8
 */ 
extern RGBA_u8 _spyroColorFilter;

/**
 * @brief  This is spyro's current active state.
 * @details  Full list of states in the SpyroStates enum. (Walking, Gliding, Charging, etc.)
 * @note Address: 0x80078ad0
 * @see Spyro SpyroStates
 */ 
extern int _spyroState;

/**
 * @brief  This is spyro's current active sub-state.
 * @details  Need to research sub-state more.
 * @note Address: 0x80078ad4
 * @see Spyro SpyroStates
 */ 
extern int _spyroSubState;

/**
 * @brief  The amount of time in frames spent in the current state. Used for calculations for jumping, boking, damage, time sensitive states, etc
 * @details  Need to research sub-state more.
 * @note Address: 0x80078ad8
 * @see Spyro
 */ 
extern int _spyroFramesInCurrentState;

/**
 * @brief  Spyros grouded charging momentum vector.
 * @note Address: 0x80078b28
 * @see Spyro
 */ 
extern Vec3 _spyroGroundedChargeMomentum;

/**
 * @brief  Spyros walking momentum vector.
 * @note Address: 0x80078b34
 * @see Spyro
 */ 
extern Vec3 _spyroWalkingChargeMomentum;

/**
 * @brief  Spyros air momentum vector.
 * @note Address: 0x80078b4c
 * @see Spyro
 */ 
extern Vec3 _spyroAirMomentum;

/**
 * @brief  Spyros absolute momentum as a scalar.
 * @note Address: 0x80078b70
 * @see Spyro
 */ 
extern int _spyroAbsoluteMomentum;

/**
 * @brief bool for if Spyro has used his glide or not yet.
 * @details This is used to only let you glide out of a charge once. 
 * @note Address: 0x80078ba8
 * @see Spyro
 */ 
extern int _spyroHasUsedGlide;

/**
 * @brief bool for if Spyro is currently gliding or not.
 * @note Address: 0x80078bac
 * @see Spyro
 */ 
extern int _spyroIsGliding;

/**
 * @brief bool for if Spyro is currently grounded or not.
 * @note Address: 0x80078bb4
 * @see Spyro
 */ 
extern int _spyroIsGrounded;

/**
 * @brief Timer for how many more frames spyro should have invulnerability. 
 * @details Automatically decrements by 1 every frame until 0. Spyro will have invulnerability if it is any number above 0.
 * @note Address: 0x80078bb8
 * @see Spyro
 */ 
extern int _spyroIFramesTimer;

/**
 * @brief Spyros current health 
 * @details This value is tied to sparx's color also. If spyro health reaches 0, sparx will disapear.
 * @note Address: 0x80078bbc
 * @see Spyro
 */ 
extern int _spyroHealth;

/**
 * @brief A timer that stops the player from being able to move spyro.
 * @details This timer decrements by 1 every frame until it reaches 0. Once it reaches 0 the player can input again.
 * @note Address: 0x80078c48
 * @see Spyro
 */ 
extern int _spyroIsMovementLocked;

/**
 * 
 * @brief A bool for if spyro can superfly currently.
 * @details This can be set to true in any level
 * @note Address: 0x80078ca4
 * @see Spyro
 */ 
extern int _spyroCanSuperFly;

/**
 * 
 * @brief A bool for if spyro is currently on supercharge ground.
 * @details This doesn't give spyro supercharge state, but gives him the weird properties of being on a supercharge ground, like the extra charge in air height.
 * @note Address: 0x80078ca8
 * @see Spyro
 */ 
extern int _spyroIsOnSuperchargeGround;


#endif //SPYRO_H

#ifndef TEXT_H
#define TEXT_H

//~~~~~~~
//Structs
//~~~~~~~
typedef struct CapitalTextInfo
{
    int x;                                  
    int y;                                  
    int size;                                        //Higher number, smaller size

}CapitalTextInfo;


typedef struct LowercaseTextInfo
{
    int spacing;
    int yOffset;
    int size;                                        //Higher number, smaller size
}LowercaseTextInfo;

#endif /* TEXT_H */





