## Symbol Map
[Click here to see the in-game varialbes & functions we have labeled](symbol_map.html)

## Ghidra Project
[Click here to download our Ghidra project](ghidra_project.html)

## Overview
At a high level, this is the way this reverse engineering project is set up currently: 

We are attempting to recompile assembly functions from spyro the dragon using C. The recompiled functions should be **functionally equivalent** and the **same amount or less** assembly opcodes. We are using a modern mips compiler. We are **not** aiming for byte for byte matches; instead **functionally equivalent matches** with an emphasis on *readability*, and ensuring the same or less amount of assembly opcodes from our compiled functions. 

We are currently placing our re-created functions in extra 8mb developer ram that *most ps1's do not have*, then replacing the first assembly instruction of the original function with a simple jump to our re-created function in the extra ram area. This current approach does not rebuild 
the game, but allows us to test our compiled code very easily. This is because everytime the game tries to run the original function, it simply jumps to our re-created version that is in the extra ram area instead. 

So long we aim for the same/less assembly opcodes, we should theoretically be able to place these recompiled functions into their correct spots eventually.

## Recommended Tools:
1. Ghidra: Very useful general reverse engineering/decompilation tool.
2. PCSX-Redux: Debugging emulator for easy testing of compiled code
3. Bizhawk: General purpose emulator with great memory search/memory view
4. spimdisasm: Command line utility for disassembling mips opcodes into a format decomp.me can understand

[Here is a guide for setting up some of these tools](https://docs.google.com/document/d/1hX7SrIHD35QESLQdDki3KHT-sHRcJ61hrNL_sEI3oww/edit#heading=h.6rhd60yzzk7r)

## Outline of our current workflow
1. Copy decompiled function from Ghidra into new, or relavent .c file

2. Compare C code against assembly on decomp.me until same amount of instructions or less 
    - Can use "Copy Special... Byte String (No Spaces)" from Ghidra to get the asm opcodes, and then paste them into spimdisasm to disassemble the opcodes into the correct format for decomp.me
3. Refactor to look more readable
4. Repeat 2 & 3 until as readable as possible, while maintaining same amount of instructions or less.

5. Create .s file for replacing the original functions first instruction with a jump to our function

6. Associate address of original functions first instruction with our .s file in buildlist.txt using this format:
NTSC, exe, 0x80xxxxxx, 0x0, asm/xxx.s

7. Create function prototype in relavent .h file

8. Document Function in .c file using this syntax:
```
/**
 * @brief Brief explaination of function
 * @details More detailed explaination of function.

 * @param char* arg1 - first parameter
 * @param int* arg2 - second parameter.
 * @param int arg3 - third parameter.
 * @return int ret - return value.

 * @note Function: FunctionName \n
 * Original Address: 0x80xxxxxx \n
 * Hook File: hool_file.s \n
 * Prototype: header.h \n
 * Prototype: header.h \n
 * Amount of instructions: Same/Less/More/Untested (https://decomp.me/link) \n
*/
```

9. Ensure function & hook have been placed successfully by setting execution breakpoint on original function's address in redux. 
10. Test your recreated function obvious issues in redux.