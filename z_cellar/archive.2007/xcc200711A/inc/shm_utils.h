/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccSHMUtils.h
// Desc: This is the include file for the xccSHMUtils code.
// Hist: When       Who  What
//       01/27/2005 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef SHM_UTILS_H
#define SHM_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "sys/ipc.h"
#include "sys/shm.h"
#include "xmc.h"
#include "malloc_utils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define DEBUG TRUE
#define BUFFER_SIZE 16777216

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/


typedef struct
{
  INT32 type;      // For XMidas.
  CHR08 format[2]; // For XMidas.
  INT08 WDWRDR;
  INT08 blank;
  FLT64 xstart;    // For XMidas.
  FLT64 xdelta;    // For XMidas.
  INT32 xunits;    // For XMidas.
  INT32 subsize;   // For XMidas.
  FLT64 ystart;    // For XMidas.
  FLT64 ydelta;    // For XMidas.
  FLT64 yunits;    // For XMidas.
  INT32 bpe;       // For XMidas.
 
  INT32 bSize;
  INT32 bIndx;
  UNT64 bLndx;
  INT08 bufferINT08[BUFFER_SIZE];
}shm_t;

typedef struct
{
  shm_t *shm;
  key_t shmKey;
  INT32 shmID;
}xccSHMSpec;

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
xccSHMSpec *xccSHMInit( INT32 type,
			const CHR08 *format,
			FLT64 xstart,
			FLT64 xdelta,
			INT32 xunits,
			INT32 subsize,
			FLT64 ystart,
			FLT64 ydelta,
			INT32 yunits,
			INT32 bpe);

xccSHMSpec *xccSHMAttach( VOID );
VOID  xccSHMTerm( xccSHMSpec *spec );
VOID  xccSHMWrite1M(INT08 *iData, xccSHMSpec *spec);
INT32 xccSHMRead(INT08 *iData, xccSHMSpec *spec);

/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/
