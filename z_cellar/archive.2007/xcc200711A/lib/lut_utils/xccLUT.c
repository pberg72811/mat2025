/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccLUT.c
// Desc: This file contains the code for the lookup tables xccLUT.
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

FLT32 xccLUTFLT32(FLT32 whogi, xccLUTSpecFLT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

FLT64 xccLUTFLT64(FLT32 whogi, xccLUTSpecFLT64 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

FLT96 xccLUTFLT96(FLT32 whogi, xccLUTSpecFLT96 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

INT08 xccLUTINT08(FLT32 whogi, xccLUTSpecINT08 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

INT16 xccLUTINT16(FLT32 whogi, xccLUTSpecINT16 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

INT32 xccLUTINT32(FLT32 whogi, xccLUTSpecINT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

INT64 xccLUTINT64(FLT32 whogi, xccLUTSpecINT64 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

UNT08 xccLUTUNT08(FLT32 whogi, xccLUTSpecUNT08 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

UNT16 xccLUTUNT16(FLT32 whogi, xccLUTSpecUNT16 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

UNT32 xccLUTUNT32(FLT32 whogi, xccLUTSpecUNT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

UNT64 xccLUTUNT64(FLT32 whogi, xccLUTSpecUNT64 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CFLT32 xccLUTCFLT32(FLT32 whogi, xccLUTSpecCFLT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CFLT64 xccLUTCFLT64(FLT32 whogi, xccLUTSpecCFLT64 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CFLT96 xccLUTCFLT96(FLT32 whogi, xccLUTSpecCFLT96 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CINT08 xccLUTCINT08(FLT32 whogi, xccLUTSpecCINT08 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CINT16 xccLUTCINT16(FLT32 whogi, xccLUTSpecCINT16 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CINT32 xccLUTCINT32(FLT32 whogi, xccLUTSpecCINT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CINT64 xccLUTCINT64(FLT32 whogi, xccLUTSpecCINT64 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CUNT08 xccLUTCUNT08(FLT32 whogi, xccLUTSpecCUNT08 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CUNT16 xccLUTCUNT16(FLT32 whogi, xccLUTSpecCUNT16 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CUNT32 xccLUTCUNT32(FLT32 whogi, xccLUTSpecCUNT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

CUNT64 xccLUTCUNT64(FLT32 whogi, xccLUTSpecCUNT64 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}
  
VFLT32 xccLUTVFLT32(FLT32 whogi, xccLUTSpecVFLT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VFLT64 xccLUTVFLT64(FLT32 whogi, xccLUTSpecVFLT64 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VFLT96 xccLUTVFLT96(FLT32 whogi, xccLUTSpecVFLT96 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VINT08 xccLUTVINT08(FLT32 whogi, xccLUTSpecVINT08 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VINT16 xccLUTVINT16(FLT32 whogi, xccLUTSpecVINT16 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VINT32 xccLUTVINT32(FLT32 whogi, xccLUTSpecVINT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VINT64 xccLUTVINT64(FLT32 whogi, xccLUTSpecVINT64 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VUNT08 xccLUTVUNT08(FLT32 whogi, xccLUTSpecVUNT08 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VUNT16 xccLUTVUNT16(FLT32 whogi, xccLUTSpecVUNT16 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VUNT32 xccLUTVUNT32(FLT32 whogi, xccLUTSpecVUNT32 *spec)
{
//------------------------------- COMMON-CODE  START.
  FLT32 tableSize = spec->size;
  INT32 index = (INT32)(whogi*tableSize+0.5);
  while(index < 0         )index+=spec->size;
  while(index > spec->size)index-=spec->size;
  return spec->table[index];

//------------------------------- COMMON-CODE   STOP.
}

VUNT64 xccLUTVUNT64(FLT32 whogi, xccLUTSpecVUNT64 *spec)
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
