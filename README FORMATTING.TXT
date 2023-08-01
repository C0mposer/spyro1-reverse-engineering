At a high level the way this reverse engineering project is set up for right now, is we are attempting to recompile functions from Spyro to be the same amount, or less,
assembly opcodes using a modern mips compiler. We are not aiming for byte for byte matches; instead functionally equivalent matches with an emphasis on readability, 
and ensuring the same, or less amount of assembly opcodes from our compiled functions. We are currently placing our recompiled functions in extra 8mb developer ram 
that most ps1's do not have, and replacing the original functions with simple jumps to our functions in the extra ram area. This current approach does not rebuild 
the game, but allows us to test our recompiled code very easily, and so long we aim for the same/less opcodes, we can theoretically place these recompiled functions 
into their correct spots eventually.

Here is an outline of our current workflow:

RECOMMENDED TOOLS:
1. PCSX-Redux: Debugging emulator for easy testing of compiled code
2. spimdisasm: Command line utility for disassembling mips opcodes into a format decomp.me can understand

1. Copy Function from Ghidra into .c file

2. Compare against assembly on decomp.me until same amount of instructions (Can use spimdisasm, and "copy special" from ghidra to get asm instructions for decomp.me)
3. Refactor to look more readable
4. Repeat 2 & 3 until as readable as possible, while maintaining same amount of instructions.

5. Create .asm file for replacing the original function with a jump to our code

6. Associate address of function with .s file for hooking in buildlist.txt using this format:
NTSC, exe, 0x80xxxxxx, 0x0, asm/xxx.s

7. Create function prototype in relavent .h file

8. Document Function in .c file using this syntax:
//**********************************
// ** Function: <Function Name>
// ** Original Address: 0x80xxxxxx
// ** Hook File: xxx.asm 
// ** Prototype: xxx.h
// ** Amount of instructions: Same/Less/More (decomp.me link) 
//**********************************
/*
 * Description of the Function.
 * @param int arg0 - Description of arg0.
 * @param short* arg1 - Description of arg1.
 * @return int - Description of the return value.
*/

9. Test insertion of function & hook for any obvious issues in redux

10. Ensure function has actually been replaced by setting execution breakpoint on original function's address in redux. 