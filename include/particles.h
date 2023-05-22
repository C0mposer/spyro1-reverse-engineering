#ifndef PARTICLES_H
#define PARTICLES_H

#include <common.h>

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