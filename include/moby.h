#ifndef MOBY_H
#define MOBY_H

#include <common.h>

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

    char color;                                     // Determines the color of the shaded moby. (01 red, 02 green, etc.) This can be poked outside of its normal range to get some awesome colors.

    short requiredHUD2;

    char UNK19;

    char heldValue;

    short UNK20;

    short scale;                                    // Determines the scale of the moby. Range from 0x0000 - 0xFFFF. (0 normal sized, 0xFFFF smallest size)

}Moby;

//* ~~~ Functions ~~~

extern Moby* _ptrTextUnk; //0x800720f4                        //? Not too sure.
extern Moby* _ptr_hudMobys; //0x80075710                      //? A pointer to a dynamic downwards growing array of moby structs to render that gets rendered to the hud every frame.
extern Moby* _ptr_hudMobysQueue; //0x800756fc                 //? A pointer to a what seems to be a global queue of moby structs to process. _ptr_hudMobys are added to this.
extern Moby* _ptr_hudMobysHead; //0x800720f8                  //? A pointer to the head of the HUD mobys queue.

#endif /* MOBY_H */
