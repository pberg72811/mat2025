/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: pic_utils.h
// Desc: This is the header file for xccPICUtils.
// Note: For possible hardware configuration entries see "~/steswd/cfg/itthwconfig.key"
// Hist: When       Who  What
//       06/27/2003 ptb  Initial Code.
//       01/20/2006 ptb  Taking out oversample parm.  Use OVSR=X flag instead.
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#ifndef PIC_UTILS_H
#define PIC_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include "xmc.h"
#include "icelib.h"
#include "malloc_utils.h"
#include "vector_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG    ( 0)
#define PLAYBACK (+1)
#define RECORD   (-1)
 
/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
typedef struct
{
  INT32 tunerDeci;
  FLT64 tunerFreq;
  INT32 tunerGain;
  INT32 tunerRatio;
  INT32 Direction;
  UNT32 PCIAddress;
  INT32 ChannelNumber;
  INT32 Samples;
  INT32 Bytes;
  INT32 Bits;
  DMAMAP dmaMap;
}xccPICIOSpec;

typedef struct
{
  PICSTRUCT picHandle;
  CHR08 devString[128];
  INT32 McBreak;
  INT32 status;
  FLT32 ifs;
  INT32 irate;
  INT32 type;
  INT32 nDMA;
  xccPICIOSpec dma[32];
}xccPICSpec;


/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
xccPICSpec *xccPICInit( const CHR08 *devString, FLT32 fs );

VOID xccPICIOInit(INT32 dmaBytes,
		  INT32 dmaBits,
		  INT32 dmaDirection,
		  FLT64 tfreq,
		  INT32 tdeci,
		  INT32 tgain,
		  xccPICSpec *spec);

INT32 xccPIC_DMA_CONTINUOUS(INT32 channelNumber, xccPICSpec *spec);
INT32 xccPIC_DMA_STATUS    (INT32 channelNumber, xccPICSpec *spec);
INT32 xccPIC_DMA_ONESHOT   (INT32 channelNumber, xccPICSpec *spec);
INT32 xccPIC_DMA_WAIT      (INT32 channelNumber, xccPICSpec *spec);
INT32 xccPIC_DMA_STOP      (INT32 channelNumber, xccPICSpec *spec);
INT32 xccPIC_DMA_CYCLE     (INT32 channelNumber, xccPICSpec *spec);
INT32 xccPIC_DMA_RESET     (INT32 channelNumber, xccPICSpec *spec);
INT32 xccPIC_DMA_CANCEL    (INT32 channelNumber, xccPICSpec *spec);
INT32 xccPICReset          (xccPICSpec *spec);
INT32 xccPICSniff          (xccPICSpec *spec); 
VOID  xccPICTerm           (xccPICSpec *spec);
INT32 xccPICTC(FLT64 offset, FLT64 delta, INT32 flag, xccPICSpec *spec);
INT32 xccPICTunerRatio(FLT64 ratio, INT32 channelNumber, xccPICSpec *spec);
INT32 xccPICDumpGC4016(xccPICSpec *spec);

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
