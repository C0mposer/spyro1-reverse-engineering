#include <custom_types.h>
#include <common.h>

/** @ingroup reveresed_functions
 *  @{
 */

/**
 * @brief Adds vector 'a' and vector 'b' together, and stores the resulting vector in 'result'

 * @param int* result - The resulting vector.
 * @param int* a - The first vector to add.
 * @param int* b - The second vector to add.
 
 * @note Function: Vec3Add \n
 * Original Address: 0x80017758 \n
 * Hook File: vec3_add.s \n
 * Prototype: vector.h \n
 * Amount of instructions: Same Amount (https://decomp.me/scratch/8OigK) \n
*/
void Vec3Add(int* result, int* a, int* b)
{
   int temp_a1 = a[1];
   int temp_a2 = a[2];
   int temp_b1 = b[1];
   int temp_b2 = b[2];

   result[0] = a[0] + b[0];
   result[1] = temp_a1 + temp_b1;
   result[2] = temp_a2 + temp_b2;

   return;
}


/**
 * @brief Copies the 'src' Vector to the 'dst' Vector.

 * @param int* src - The source vector.
 * @param int* dst - The destination vector.
 
 * @note Function: Vec3Copy \n
 * Original Address: 0x80017700 \n
 * Hook File: vec3_copy.s \n
 * Prototype: vector.h \n
 * Amount of instructions: Same Amount (https://decomp.me/scratch/ycHxN) \n
*/
void Vec3Copy(int* dst, int* src)
{
  int temp_src1 = src[1];
  int temp_src2 = src[2];

  dst[0] = src[0];
  dst[1] = temp_src1;
  dst[2] = temp_src2;

  return;
}

/**
 * @brief 
 * @details
 
 * @param uint* outputMatrix 
 * @param uint* inputMatrix 
  
 * @note
 */
void MatrixTranspose(uint* outputMatrix, uint* inputMatrix)

{
  uint A12;
  uint A23;
  uint A21;
  uint A31;
  uint A13;
  uint A23A22;
  uint A32;
  uint A33;

  uint B13;
  uint B32;
  
  A23A22 = inputMatrix[2];
  A12 = *inputMatrix & 0xffff0000;
  A21 = inputMatrix[1] & 0xffff0000;
  A13 = inputMatrix[1] ^ A21;
  B13 = A13 & 0xffff;
  A31 = inputMatrix[3] & 0xffff;
  A32 = inputMatrix[3] ^ A31;
  A23 = A23A22 & 0xffff0000;
  B32 = A32 & 0xffff0000;
  *outputMatrix = *inputMatrix ^ A12 | A21;
  outputMatrix[1] = (A13 | A12) ^ B13 | A31;
  outputMatrix[2] = A23A22 ^ A23 | B32;
  outputMatrix[3] = (A32 | B13) ^ B32 | A23;
  outputMatrix[4] = inputMatrix[4];
  return;
}

/**
 * @brief Calculates the arctan of a vector to get the estimated angle.
 * @details The returned value is a number where 64 = 90 degrees, and 256 = 360 degrees.
 * 
 * @param x 
 * @param y
 * 
 * @note Function: GetAngle \n
 * Original Address: 0x800169ac \n
 * Hook File: get_angle.s \n
 * Prototype: vector.h \n
 * Amount of instructions: LESS (https://decomp.me/scratch/oRTWr)
*/
int GetAngle(const int x, const int y)
{
    // Get the absolute values of both X and Y.
    int absX = x < 0 ? -x : x;
    int absY = y < 0 ? -y : y;

    // If ABS(X) > ABS(Y) then swap the index and divisor.
    int numerator = absX > absY ? absY : absX;
    int divisor = absX > absY ? absX : absY;

    // Make sure divisor is not zero to avoid division by zero.
    divisor = divisor == 0 ? 1 : divisor;

    int idx = (numerator << 6) / divisor;
    uint result = (uint) _AngleArray[idx];

    // Determine an offset multiplier based on the sign value of both X and Y.
    int multiplier = (x < 0)
        ? ((y < 0) ? 2 : 1)
        : ((y < 0) ? 3 : 0);

    // Determine the result from the glimmer array needs to be inverted.
    bool invert = absX < absY;

    // Handle a specific case when only one of either X and Y values are negative.
    if ((x < 0 && y >= 0) || (x >= 0 && y < 0))
    {
        invert = absX >=  absY;
    }

    // When inverted, the multiplier also gets adjusted forward.
    if (invert) 
    {
        multiplier++;
        result *= -1;
    }

    int offset = multiplier * 64;
    return offset + result;
}

// void MatrixTranspose(unsigned int *outputMatrix, unsigned int *inputMatrix)

// {

//   *outputMatrix = (*inputMatrix & 0xffff) + (inputMatrix[1] & 0xffff0000);
//   outputMatrix[1] = (inputMatrix[3] & 0xffff) + (*inputMatrix & 0xffff0000);
//   outputMatrix[2] = (inputMatrix[2] & 0xffff) + (inputMatrix[3] & 0xffff0000);
//   outputMatrix[3] = (inputMatrix[1] & 0xffff) + (inputMatrix[2] & 0xffff0000);
//   outputMatrix[4] = inputMatrix[4];
//   return;
// }


/** @} */ // end of reveresed_functions
