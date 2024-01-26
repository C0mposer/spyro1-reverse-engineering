#pragma once

#include <vector.h>
#include <shapes.h>

/// @brief Defines flags that represent whether a vector is outside of the visibility of the camera.
enum OffscreenStatus
{
    OFFSCREEN_BOTTOM = 1,
    OFFSCREEN_TOP = 2,
    OFFSCREEN_LEFT = 4,
    OFFSCREEN_RIGHT = 8,
};
typedef byte OffscreenStatus;
_Static_assert(sizeof(OffscreenStatus) == 1);

/// @brief Represents a 2D vector that is upscaled in order to hold metadata about its visibiility.
/// @details The flags member requires 5 bits of space.
typedef union 
{
    uint vector;
    OffscreenStatus flags;
} BoundedVertex;
_Static_assert(sizeof(BoundedVertex) == 4);

/// @brief Not entirely sure on this, but I think it is some kind of coordinate information that is used to determine if a model should be ignored.
/// @details The XYZ values are used to perform RTPS and get a Z value that is compared to the cutoff member. The result of which determines if model should be processed.
typedef struct
{
    int XY;
    short Cutoff;
    short Z;
} ClipCalculation;
_Static_assert(sizeof(ClipCalculation) == 8);

/// @brief Vector structure that gets transformed for a perspective.
typedef struct
{
    uint Y : 10;
    uint X : 11;
    uint Z : 11;
} PackedVertex;
_Static_assert(sizeof(PackedVertex) == 4);

/// @brief Packed vertex count.
typedef struct
{
    uint VertexIndexEnd : 13;
    uint Unused : 1;
    uint VertexIndexStart : 18;
} PackedCount;
_Static_assert(sizeof(PackedCount) == 4);

/// @brief This is the header or start of an entire model for drawing sky primitives.
/// @note Following this structure immediately adjacent in memory are a VertexIndex array, ColorIndex array, and then a PolyMeta array.
typedef struct
{
    ClipCalculation ClipCalculation;
    short GX;
    short GY;
    short VertexCount;
    short GZ;
    PackedCount PC;
    int U6;
} SkyboxModel;
_Static_assert(sizeof(SkyboxModel) == 24);

/// @brief Represents a structure that indexes where primitive RGB colors should be located.
/// @details These are byte offsets into the WAD to find colors. They come immediately after vertex information.
typedef struct
{
    uint Color2 : 10;
    uint Color1 : 10;
    uint Color0 : 12;
} ColorIndex;
_Static_assert(sizeof(ColorIndex) == 4);

/// @brief Indexes that show where to find vertex information for primitives.
/// @details These are byte offsets into the WAD to find vertices. They come immediately after SkyboxModel data.
typedef struct
{
    uint XY2 : 10;
    uint XY1 : 10;
    uint XY0 : 12;
} VertexIndex;
_Static_assert(sizeof(VertexIndex) == 4);

/// @brief Describes a structure that contains offsets to vertex and color information for building polygon primitives.
/// @details These are structures in the WAD that come after color index information.
typedef struct
{
    VertexIndex PU;
    ColorIndex ColorIndex;
} PolyMeta;
_Static_assert(sizeof(PolyMeta) == 8);

/// @brief RGB structure that also includes padding.
typedef struct
{
    byte Red;
    byte Green;
    byte Blue;
    byte Padding;
} RGBu8P;
_Static_assert(sizeof(RGBu8P) == 4);

/// @brief Sky models that are loaded from the WAD.
/// @note Address: 0x80078a44
extern SkyboxModel** _SkyboxWadModels;

/**
 * @brief Pointers that can be used to reference skybox WAD models directly instead of starting at the beginning of the WAD section. \n Address: 0x80078a4c
*/
extern byte** _SkyboxWadModelPointers;

/**
 * @brief Number of sky models that exist within a loaded section of the WAD. \n Address: 0x80077780
*/
extern int _SkyboxWadModelCount;

/**
 * @brief Sky models that have been selected to draw primitives from. \n Address: 0x8006fcf4
 * @details Models that are in view of the camera that we can draw primitives from.
*/
extern SkyboxModel* _SkyboxModelsToRender;

/**
 * @brief Scratchpad start in RAM used for storing skybox vectors. \n Address: 0x1f800000
*/
extern BoundedVertex _ScratchpadDrawSkybox;

/**
 * @brief Starting location to stage primitives. \n Address: 0x80075820
*/
extern PrimitiveLinkedList* _PrimitiveStagingStart;

/**
 * @brief Draws the sky for cutscenes and levels.
 * @details Draws the skybox rendering primitives from the WAD based on camera perspectives.
 * @param index Used for specifying a selection of sky models to render.
 * @param cameraA 
 * @param cameraB 
*/
void DrawSkybox(int index, RotationMatrix *cameraA, RotationMatrix *cameraB);