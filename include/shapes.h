#ifndef FILTERS_H
#define FILTERS_H

#include <common.h>
#include <PSYQ_gpu.h>

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

/// @brief Structure defining the beginning of a list of primitives and where it ends.
typedef struct PrimitiveLinkedList
{
    P_TAG *Tail;
    P_TAG *Head;
} PrimitiveLinkedList;

#endif //FILTERS_H