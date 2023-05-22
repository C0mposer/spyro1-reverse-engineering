
//**********************************
// ** Function: Vec3Add
// ** Original Address: 0x80017758
// ** Hook File: vec3_add.s 
// ** Prototype: vector.h
//**********************************
/*
 * Adds Vector 'a' and Vector 'b' together, and stores the resulting vector in 'result'
 * @param int* result - The resulting vector.
 * @param int* a - The first vector to add.
 * @param int* b - The second vector to add.
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


//**********************************
// ** Function: Vec3Copy
// ** Original Address: 0x80017700
// ** Hook File: vec3_copy.s
// ** Prototype: vector.h
//**********************************
/*
 * Copies the 'src' Vector to the 'dst' Vector.
 * @param int* src - The source vector.
 * @param int* dst - The destination vector.
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