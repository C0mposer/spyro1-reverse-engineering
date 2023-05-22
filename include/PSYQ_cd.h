#ifndef CD_H
#define CD_H
#include <common.h>


enum CdControlPrimatives
{
    CdlNop = 0x01,
    CdlSetloc = 0x02,
    CdlPlay = 0x03,
    CdlForward = 0x04,
    CdlBackward = 0x05,
    CdlReadN = 0x06,
    CdlStandby = 0x07,
    CdlStop = 0x08,
    CdlPause = 0x09,
    CdlMute = 0x0B,
    CdlDemute = 0x0C,
    CdlSetfilter = 0x0D,
    CdlSetmode = 0x0E,
    CdlGetparam = 0x0F,
    CdlGetlocL = 0x10,
    CdlGetlocP = 0x11,
    CdlSeekL = 0x15,
    CdlSeekP = 0x16,
    CdlReadS = 0x1B
};

typedef void (*CdlCB)(unsigned char,unsigned char *);

typedef struct CdlFILTER{
    unsigned char file;         //File ID, Always 1
    unsigned char chan;         //Channel ID, Picks a song from the current music file (goes up to 7)
    unsigned short pad;         //System reserved
} CdlFILTER; 

typedef struct CdlLOC{
	unsigned char minute;		/* minute (BCD) */
	unsigned char second;		/* second (BCD) */
	unsigned char sector;		/* sector (BCD) */
	unsigned char track;		/* track (void) */
} CdlLOC;

int CdRead(int sectors, unsigned int * buf, int mode);
int CdInit();
CdlCB CdReadCallback(CdlCB func);
//int CdStatus(void);
int CdSync(int mode, unsigned char * result);
int CdControl(unsigned char com, unsigned char * param, unsigned char * result);  //Tells the CD-DRIVE to do a primitive function, and someimes allows concurrent cd functions
int CdControlB(unsigned char com, unsigned char * param, unsigned char * result); //Tells the CD-DRIVE to do a primitive function, and ONLY that one function. 
void *CdDataCallback(void (*func)());
CdlLOC *CdIntToPos(int i, CdlLOC * p);
int CdPosToInt(CdlLOC * p);
int CdSync_(int mode, unsigned char * result);

void read_cb(unsigned char status, unsigned char *result);

extern int _musicSectors;


#endif /* CD_H */
