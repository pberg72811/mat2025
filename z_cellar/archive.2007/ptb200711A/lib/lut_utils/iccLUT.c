/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccLUT.c
// Desc: This file contains the code for the lookup tables iccLUT.
// Hist: When       Who  What
//       02/28/2005 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "lut_utils.h" 
 
/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  FLT32 tableSize = spec->size;
PERL_PREPROCESS  INT32 index = (INT32)(whogi*tableSize+0.5);
PERL_PREPROCESS  while(index < 0         )index+=spec->size;
PERL_PREPROCESS  while(index > spec->size)index-=spec->size;
PERL_PREPROCESS  return spec->table[index];
PERL_PREPROCESS
#endif

FLT32 iccLUTFLT32(FLT32 whogi, iccLUTSpecFLT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

FLT64 iccLUTFLT64(FLT32 whogi, iccLUTSpecFLT64 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

FLT96 iccLUTFLT96(FLT32 whogi, iccLUTSpecFLT96 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

INT08 iccLUTINT08(FLT32 whogi, iccLUTSpecINT08 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

INT16 iccLUTINT16(FLT32 whogi, iccLUTSpecINT16 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

INT32 iccLUTINT32(FLT32 whogi, iccLUTSpecINT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

INT64 iccLUTINT64(FLT32 whogi, iccLUTSpecINT64 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

UNT08 iccLUTUNT08(FLT32 whogi, iccLUTSpecUNT08 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

UNT16 iccLUTUNT16(FLT32 whogi, iccLUTSpecUNT16 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

UNT32 iccLUTUNT32(FLT32 whogi, iccLUTSpecUNT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

UNT64 iccLUTUNT64(FLT32 whogi, iccLUTSpecUNT64 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CFLT32 iccLUTCFLT32(FLT32 whogi, iccLUTSpecCFLT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CFLT64 iccLUTCFLT64(FLT32 whogi, iccLUTSpecCFLT64 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CFLT96 iccLUTCFLT96(FLT32 whogi, iccLUTSpecCFLT96 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CINT08 iccLUTCINT08(FLT32 whogi, iccLUTSpecCINT08 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CINT16 iccLUTCINT16(FLT32 whogi, iccLUTSpecCINT16 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CINT32 iccLUTCINT32(FLT32 whogi, iccLUTSpecCINT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CINT64 iccLUTCINT64(FLT32 whogi, iccLUTSpecCINT64 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CUNT08 iccLUTCUNT08(FLT32 whogi, iccLUTSpecCUNT08 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CUNT16 iccLUTCUNT16(FLT32 whogi, iccLUTSpecCUNT16 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CUNT32 iccLUTCUNT32(FLT32 whogi, iccLUTSpecCUNT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CUNT64 iccLUTCUNT64(FLT32 whogi, iccLUTSpecCUNT64 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}
  
VFLT32 iccLUTVFLT32(FLT32 whogi, iccLUTSpecVFLT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VFLT64 iccLUTVFLT64(FLT32 whogi, iccLUTSpecVFLT64 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VFLT96 iccLUTVFLT96(FLT32 whogi, iccLUTSpecVFLT96 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VINT08 iccLUTVINT08(FLT32 whogi, iccLUTSpecVINT08 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VINT16 iccLUTVINT16(FLT32 whogi, iccLUTSpecVINT16 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VINT32 iccLUTVINT32(FLT32 whogi, iccLUTSpecVINT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VINT64 iccLUTVINT64(FLT32 whogi, iccLUTSpecVINT64 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VUNT08 iccLUTVUNT08(FLT32 whogi, iccLUTSpecVUNT08 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VUNT16 iccLUTVUNT16(FLT32 whogi, iccLUTSpecVUNT16 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VUNT32 iccLUTVUNT32(FLT32 whogi, iccLUTSpecVUNT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VUNT64 iccLUTVUNT64(FLT32 whogi, iccLUTSpecVUNT64 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
