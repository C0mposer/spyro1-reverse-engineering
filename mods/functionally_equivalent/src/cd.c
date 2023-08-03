#include <custom_types.h>
#include <common.h>

/**
 * @brief Returns the status of the CD Drive.

 * @return byte - The CD drive status.

 * @note Function: CdStatus \n
 * Original Address: 0x80063a8c \n
 * Hook File: cd_status.s \n
 * Prototype: cd.h \n
 * Amount of instructions: Same Amount (https://decomp.me/scratch/C9fPW) \n

*/
byte CdStatus(void)

{
  return _cdStatus;
}