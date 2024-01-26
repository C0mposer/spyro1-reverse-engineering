#pragma once

#include <PSYQ_gte.h>

typedef struct P_TAG
{
    unsigned addr: 24;
    unsigned len: 8;
    byte r0;
    byte g0;
    byte b0;
    byte code;
} P_TAG;
_Static_assert(sizeof(P_TAG) == 8);

typedef struct
{
    P_TAG tag;
    short x0;
    short y0;
    u_char r1;
    u_char g1;
    u_char b1;
    u_char pad1;
    short x1;
    short y1;
    u_char r2;
    u_char g2;
    u_char b2;
    u_char pad2;
    short x2;
    short y2;
} POLY_G3;
_Static_assert(sizeof(POLY_G3) == 28);

typedef struct
{
    P_TAG tag;
    short x0;
    short y0;
    short x1;
    short y1;
    short x2;
    short y2;
} POLY_F3;
_Static_assert(sizeof(POLY_F3) == 20);