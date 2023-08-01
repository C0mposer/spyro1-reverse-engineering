1. Copy Function from Ghidra into .c file

2. Compare against assembly on decomp.me until same amount of instructions (Can use spimdisasm, and "copy special" from ghidra to get asm instructions for decomp.me)
3. Refactor to look more readable
4. Repeat 2 & 3 until as readable as possible, while maintaining same amount of instructions.

5. Create .asm file for replacing the original function

6. Associate address of function with .asm file for hooking in buildlist.txt using this format:
NTSC, exe, 0x80xxxxxx, 0x0, asm/xxx.s

7. Create function prototype in relavent .h file

8. Document Function in .c file using this syntax:
//**********************************
// ** Function: <Function Name>
// ** Original Address: 0x80xxxxxx
// ** Hook File: xxx.asm 
// ** Prototype: xxx.h
//**********************************
/*
 * Description of the Function.
 * @param int arg0 - Description of arg0.
 * @param short* arg1 - Description of arg1.
 * @return int - Description of the return value.
*/

9. Test insertion of function & hook for any obvious issues

10. Ensure function has actually been replaced by setting execution breakpoint on original function's address. 