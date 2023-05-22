#include <custom_types.h>
#include <cd.h>

//**********************************
// ** Function: CdStatys
// ** Original Address: 0x80063a8c
// ** Hook File: cd_status.s
// ** Prototype: cd.h
//**********************************
/*
 * Returns the status of the CD Drive.
 * @return byte - The CD drive status.
*/
byte CdStatus(void)

{
  return _cdStatus;
}