#pragma once

#include <custom_types.h>

#define gte_ldVXY0(r0) __asm__ volatile("mtc2   %0, $0" : : "r"(r0))
#define gte_ldVZ0(r0) __asm__ volatile("mtc2   %0, $1" : : "r"(r0))
#define gte_lddp(r0) __asm__ volatile("mtc2   %0, $8" : : "r"(r0))
#define gte_ldIR1(r0) __asm__ volatile("mtc2   %0, $9" : : "r"(r0))
#define gte_ldIR2(r0) __asm__ volatile("mtc2   %0, $10" : : "r"(r0))
#define gte_ldIR3(r0) __asm__ volatile("mtc2   %0, $11" : : "r"(r0))
#define gte_ldMAC1(r0) __asm__ volatile("mtc2   %0, $25" : : "r"(r0))
#define gte_ldMAC2(r0) __asm__ volatile("mtc2   %0, $26" : : "r"(r0))
#define gte_ldMAC3(r0) __asm__ volatile("mtc2   %0, $27" : : "r"(r0))
#define gte_ldLZCS(r0) __asm__ volatile("mtc2   %0, $30" : : "r"(r0))

#define gte_ldR11R12(r0) __asm__ volatile("ctc2 %0, $0" : : "r"(r0))
#define gte_ldR13R21(r0) __asm__ volatile("ctc2 %0, $1" : : "r"(r0))
#define gte_ldR22R23(r0) __asm__ volatile("ctc2 %0, $2" : : "r"(r0))
#define gte_ldR31R32(r0) __asm__ volatile("ctc2 %0, $3" : : "r"(r0))
#define gte_ldR33(r0) __asm__ volatile("ctc2 %0, $4" : : "r"(r0))

#define	gte_ldIR0( r0 )	gte_lddp( r0 )

#define gte_rtps_b() __asm__ volatile("cop2 0x0180001;")

#define gte_stSXY2(r0) __asm__ volatile( \
    "mfc2 %0, $14" \
    : "=r"(r0))

#define read_mt(r0, r1, r2) __asm__ volatile( \
	"mfc2   %0, $25;"  \
	"mfc2   %1, $26;"  \
	"mfc2   %2, $27;"  \
	: "=r"(r0), "=r"(r1), "=r"(r2))

// I think this is different from gte_stsz3 (lowercase)
#define gte_stSZ3(r0) __asm__ volatile( \
    "mfc2  %0, $19" \
    : "=r"(r0))

#define gte_stMAC3(r0) __asm__ volatile( \
    "mfc2  %0, $27" \
    : "=r"(r0))

#define gte_sqr0()    \
    __asm__ volatile( \
        "nop;"        \
        "nop;"        \
        "cop2 0x0A00428;")

#define gte_stLZCR() ({ \
    unsigned int value; \
    __asm__ volatile("mfc2   %0, $31" : "=r"(value)); \
    value; \
})

#define gte_ldlvl(r0)          \
    __asm__ volatile(          \
        "lwc2   $9, 0( %0 );"  \
        "lwc2   $10, 4( %0 );" \
        "lwc2   $11, 8( %0 )"  \
        :                      \
        : "r"(r0))

#define gte_gpl0()    \
    __asm__ volatile( \
        "nop;"        \
        "nop;"        \
        "cop2 0x01A0003E")

#define gte_rtir()    \
    __asm__ volatile( \
        "nop;"        \
        "nop;"        \
        "cop2 0x049E012;")

#define gte_ldtr(r0, r1, r2) \
    __asm__ volatile(        \
        "ctc2   %0, $5;"     \
        "ctc2   %1, $6;"     \
        "ctc2   %2, $7"      \
        :                    \
        : "r"(r0), "r"(r1), "r"(r2))

