#include <common.h>
#include <custom_types.h>
#include <vector.h>
#include <PSYQ_gte.h>
#include <PSYQ_gpu.h>
#include <draw_skybox.h>

/// @brief Load a camera rotation matrix and translation vector.
/// @param camera Rotation matrix.
static void LoadCameraMatrix(RotationMatrix* camera)
{
    gte_ldR11R12(camera->R11R12);
    gte_ldR13R21(camera->R13R21);
    gte_ldR22R23(camera->R22R23);
    gte_ldR31R32(camera->R31R32);
    gte_ldR33(camera->R33);
}

/// @brief Converts a bounded vector to a normal 2D vector.
/// @details Restores a vector that was scaled up (in order to hold additional metadata) back to it's original value.
/// @param boundedVector Vector that contains metadata about its visibility.
/// @return Restored 2D vector.
static Vec2_s16 ConvertToVector(BoundedVertex* boundedVector)
{
    int originalValue = (int)boundedVector->vector >> 5;
    return *(Vec2_s16*)&originalValue;
}

/// @brief Converts a vector to a bounded vector with metadata about the offscreen visibility.
/// @param vector 2D vector that is scaled up by 32x in order to hold metadata about the offscreen coordinate positions.
/// @return Vector with out of bounds information.
static BoundedVertex ConvertToBoundedVector(Vec2_s16* vector)
{
    // Scale the vector by 32 in or to make 5 bits to hold metadata about which coordinates are outside the camera range.
    BoundedVertex boundedVector = { .vector = *(uint*)vector << 5 };

    // The case where Y = 1 and X = 0 seems odd, but is technically correct, and satisfies ((int)(vector - 0x10000) < 1).
    if (vector->y <= 0 || vector->x == 0 && vector->y == 1)
    {
        boundedVector.flags |= OFFSCREEN_BOTTOM;
    }

    if (vector->y >= 256)
    {
        boundedVector.flags |= OFFSCREEN_TOP;
    }

    if (vector->x <= 0)
    {
        boundedVector.flags |= OFFSCREEN_LEFT;
    }

    if (vector->x >= 512)
    {
        boundedVector.flags |= OFFSCREEN_RIGHT;
    }

    return boundedVector;
}

/// @brief Performs RTPS on vertices contained within a model.
/// @param model 
/// @return 
static byte RunPerspectiveTransformations(SkyboxModel* model)
{
    uint vertexCount = model->VertexCount;
    PackedVertex* packs = (PackedVertex*)(model + 1);

    byte endFlags = 0x0F;
    BoundedVertex *storedVectors = &_ScratchpadDrawSkybox;

    // Iterate through all vertices and calculate RTPS.
    // Something to think about, maybe doing RTPT would be faster.
    for (uint i = 0; i <= vertexCount; i++)
    {
        PackedVertex* pv = &packs[i];

        // Calculate the X, Y, Z component from global values.
        uint xComp = model->GX - pv->X;
        uint yComp = model->GY - pv->Y;
        uint zComp = model->GZ + pv->Z;

        gte_ldVZ0(zComp);
        gte_ldVXY0(xComp + yComp * 0x10000);

        // This is here to satisfy testing requirements.
        // There is an extra load of VXYZ0 which is not necessary in the original code and gets discarded.
        // To ignore testing restrictions, remove this condition and modify the loop such that `i < vertexCount` instead of `i <= vertexCount`.
        if (i == vertexCount)
        {
            break;
        }

        // coordinate transformation and perspective transformation
        uint xy2 = 0;
        gte_rtps_b();
        gte_stSXY2(xy2);

        // Convert this vector to a structure that has out of bounds information.
        BoundedVertex bv = ConvertToBoundedVector((Vec2_s16*)&xy2);
            
        // Set flags based on the boundary metadata to make sure that a primitive can be drawn.
        endFlags = endFlags & bv.flags;

        // Save calculation to the scratchpad for later.
        *storedVectors++ = bv;
    }

    return endFlags;
}

/// @brief Adds primitives to a staging list.
/// @param polygon Primitive that gets added to the list.
/// @param current Unknown.
/// @param ptagMask Mask that needs to be applied to set the length of the primitive correctly.
static void StagePrimitive(P_TAG* polygon, P_TAG* current, uint ptagMask)
{
    P_TAG* head = _PrimitiveList;
    _PrimitiveList = polygon;

    if (polygon == current)
    {
        return;
    }

    // This is just setting the P_TAG length of the primitive and making certain that it doesn't clear the address.
    *(uint *)head = ptagMask ^ 0x80000000;

    // Add the primitive onto the staging linked list.
    P_TAG* tail = _PrimitiveStagingStart[0x7ff].Tail;
    if (tail == NULL) 
    {
        _PrimitiveStagingStart[0x7FF].Head = current;
    }
    else 
    {
        tail->addr = (u_long)current;
    }

    _PrimitiveStagingStart[0x7FF].Tail = head;
}

/// @brief Draws either a POLY_F3 or POLY_G3 triangle if vertices exist on screen.
/// @param metadata 
/// @param ptagMask 
/// @param polygon 
/// @param vertexEnd 
static void DrawTriangle(PolyMeta* metadata, uint* ptagMask, P_TAG** polygon, uint* vertexEnd)
{
    // The vertex indexes XY1 and XY2 have the last two bits cleared in the original code to prevent accessing on an unaligned address.
    // This is removed, but can be added back if needed: XY1 & 0xFFFFFFFC, and XY2 & 0xFFFFFFFC.
    VertexIndex* pu = &metadata->PU;
    BoundedVertex* scaledXy0 = &_ScratchpadDrawSkybox + (pu->XY0 / sizeof(uint));
    BoundedVertex* scaledXy1 = &_ScratchpadDrawSkybox + (pu->XY1 / sizeof(uint));
    BoundedVertex* scaledXy2 = &_ScratchpadDrawSkybox + (pu->XY2 / sizeof(uint));

    // Skip drawing a triangle if all of three vertices exist off screen.
    if ((scaledXy0->flags & scaledXy1->flags & scaledXy2->flags & 0x1F) != 0)
    {
        return;
    }
    
    // Restore the vectors back to the unscaled version that does not have embedded screen boundary data.
    Vec2_s16 xy0 = ConvertToVector(scaledXy0);
    Vec2_s16 xy1 = ConvertToVector(scaledXy1);
    Vec2_s16 xy2 = ConvertToVector(scaledXy2);

    // The color indexes 1 and 2 have the last two bits cleared in the original code to prevent accessing on an unaligned address.
    // This is removed, but can be added back if needed: Color1 & 0xFFFFFFFC, and Color2 & 0xFFFFFFFC.
    ColorIndex* colorIndex = &metadata->ColorIndex;
    uint color0 = colorIndex->Color0;
    uint color1 = colorIndex->Color1;
    uint color2 = colorIndex->Color2;

    // The mask includes '8' in order to clear the address of the polygon.
    *(uint *)_PrimitiveList = *ptagMask ^ (uint)*polygon;
    _PrimitiveList = *polygon;

    // These are assigned here instead of the conditional because otherwise, test fails with a difference in memory.
    // It's probably a mistake from the developers where in the case of POLY_F3, additional bytes are added to the end.
    POLY_G3* polyG3 = (POLY_G3*)*polygon;

    polyG3->x0 = xy0.x;
    polyG3->y0 = xy0.y;

    polyG3->x1 = xy1.x;
    polyG3->y1 = xy1.y;
    
    polyG3->x2 = xy2.x;
    polyG3->y2 = xy2.y;

    // POLY_F3 and POLY_G3 have overlapping memory, so this can be set once here.
    RGBu8P rgb = *(RGBu8P*)(vertexEnd + (color0 / sizeof(RGBu8P)));
    polyG3->tag.r0 = rgb.Red;
    polyG3->tag.b0 = rgb.Blue;
    polyG3->tag.g0 = rgb.Green;
    polyG3->tag.code = rgb.Padding;

    // If all colors are the same draw POLY_F3.
    if ((color0 == color1) && (color0 == color2)) 
    {
        POLY_F3* polyF3 = (POLY_F3*)*polygon;

        // The length of the primitive is 4.
        *ptagMask = 0x84000000;

        // I am not sure why this is necessary. What is going on here??
        polyF3->tag.code -= 0x10;
        
        polyF3->x0 = xy0.x;
        polyF3->y0 = xy0.y;

        polyF3->x1 = xy1.x;
        polyF3->y1 = xy1.y;

        polyF3->x2 = xy2.x;
        polyF3->y2 = xy2.y;

        *polygon = (P_TAG*)(polyF3 + 1);
    }
    else 
    {
        // The length of the primitive is 6.
        *ptagMask = 0x86000000;

        rgb = *(RGBu8P*)(vertexEnd + (color1 / sizeof(RGBu8P)));

        polyG3->r1 = rgb.Red;
        polyG3->b1 = rgb.Blue;
        polyG3->g1 = rgb.Green;
        polyG3->pad1 = rgb.Padding;

        rgb = *(RGBu8P*)(vertexEnd + (color2 / sizeof(RGBu8P)));

        polyG3->r2 = rgb.Red;
        polyG3->b2 = rgb.Blue;
        polyG3->g2 = rgb.Green;
        polyG3->pad2 = rgb.Padding;

        *polygon = (P_TAG*)(polyG3 + 1);
    }
}

/// @brief Draws and creates primitives while performing perspective transformations.
static void CreatePolygons()
{
    uint *vertexEnd;
    PackedCount* packedCount;
    SkyboxModel** modelsToRender = &_SkyboxModelsToRender;

    P_TAG *ptagB = (P_TAG *)((int)_PrimitiveList + 4);
    P_TAG* polygon = ptagB;
    uint ptagMask = 0;

    while (true)
    {
        while (true) 
        {
            SkyboxModel *model = *modelsToRender++;

            if (model == NULL) 
            {
                StagePrimitive(polygon, ptagB, ptagMask);
                return;
            }

            // Perform RTPS and if it results in at least some set of vertices that are visible, then move on to building polygons.
            // The comparison of 0xF is to handle out of bounds flags that can be set.
            if ((RunPerspectiveTransformations(model) & 0xF) == 0)
            {
                packedCount = &model->PC;
                PackedVertex* packs = (PackedVertex*)(model + 1);
                vertexEnd = (uint*)(packs + model->VertexCount);
                break;
            }
        }

        // Get the address of the end of all the vertices.
        PolyMeta* metadataStart = (PolyMeta*)((int)vertexEnd + packedCount->VertexIndexStart);
        PolyMeta* metadataCursor = metadataStart;

        while(metadataCursor != (PolyMeta*)(((uint*)metadataStart) + packedCount->VertexIndexEnd * 2)) 
        {
            // Not sure what this is. Could it be prioritizing HUD primitives and making sure sky ones appear behind them?
            int unkPtag = _DrawSkyboxU4 - 0x400;
            if (unkPtag - (int)polygon < 1) 
            {
                _DrawSkyboxU3 = 1;
                StagePrimitive(polygon, ptagB, ptagMask);
                return;
            }

            DrawTriangle(metadataCursor, &ptagMask, &polygon, vertexEnd);
            metadataCursor++;
        }
    }
}

/// @brief Performs RTPS and stores sky models to a list for rendering if they are not clipped from view.
/// @param modelsToRender List of sky models that will need to be transformed into primitives.
/// @param model Sky model to process.
static void CalculateModelsToRender(SkyboxModel*** modelsToRender, SkyboxModel* model)
{
    // store 3 screen coordinates to non-continuous addresses. Store screen z 0, 1, 2
    int SZ3;

    gte_ldVXY0(model->ClipCalculation.XY);
    gte_ldVZ0(model->ClipCalculation.Z);
    gte_rtps_b();
    gte_stMAC3(SZ3);

    // This could be far/near plane clipping?
    // The SZ3 result needs to be greater than zero to draw; otherwise, clipping and distortion might happen?
    if (SZ3 - model->ClipCalculation.Cutoff > 0)
    {
        *(*modelsToRender)++ = model;
    }
}

/**
 * @brief Draws the sky for cutscenes and levels.
 * @details Draws the skybox rendering primitives from the WAD based on camera perspectives.
 * 
 * @param index Used for specifying a selection of sky models to render.
 * @param cameraA 
 * @param cameraB 
 * 
 * @note Function: DrawSkybox \n
 * Original Address: 0x8004eba8 \n
 * Hook File: draw_skybox.s \n
 * Prototype: draw_skybox.h \n
 * Amount of instructions: MORE (https://decomp.me/scratch/gYOM3)
*/
void DrawSkybox(int index, RotationMatrix *cameraA, RotationMatrix *cameraB)
{   
    // Store registers. (This doesn't seem to have an effect on the game working, but it's needed for testing.)
    register int s0 asm("$16");
    register int s1 asm("$17");
    register int s2 asm("$18");
    register int s3 asm("$19");
    register int s4 asm("$20");
    register int s5 asm("$21");
    register int s6 asm("$22");
    register int s7 asm("$23");
    register int gp asm("$28");
    register int sp asm("$29");
    register int fp asm("$30");
    register int ra asm("$31");

    _RegisterStorage.S0 = s0;
    _RegisterStorage.S1 = s1;
    _RegisterStorage.S2 = s2;
    _RegisterStorage.S3 = s3;
    _RegisterStorage.S4 = s4;
    _RegisterStorage.S5 = s5;
    _RegisterStorage.S6 = s6;
    _RegisterStorage.S7 = s7;
    _RegisterStorage.SP = sp;
    _RegisterStorage.FP = fp;
    _RegisterStorage.RA = ra;
    _RegisterStorage.GP = gp;

    // Load the camera and clear the translation vector to do clip calculations.
    LoadCameraMatrix(cameraA);
    gte_ldtr(0, 0, 0);

    // Create a list of models that will need to be rendered depending on the camera state.
    SkyboxModel** modelsToRender = &_SkyboxModelsToRender;
    
    if (index < 0)
    {
        SkyboxModel** cursor = _SkyboxWadModels;

        // Iterate through all models loaded from the WAD.
        while (cursor != (_SkyboxWadModels + _SkyboxWadModelCount))
        {
            SkyboxModel *model = *cursor++;
            CalculateModelsToRender(&modelsToRender, model);
        }
    }
    else 
    {
        byte* tableIndex = _SkyboxWadModelPointers[index];

        // Iterate through a select number of models loaded based on some kind of index.
        while (*tableIndex != 0xFF)
        {
            SkyboxModel *model = _SkyboxWadModels[*tableIndex];
            CalculateModelsToRender(&modelsToRender, model);
            tableIndex++;
        }
    }

    // Explitly set the end of the list of models to render.
    *modelsToRender = 0;
    LoadCameraMatrix(cameraB);
    CreatePolygons();
}