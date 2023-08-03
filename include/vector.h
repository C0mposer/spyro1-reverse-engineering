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
