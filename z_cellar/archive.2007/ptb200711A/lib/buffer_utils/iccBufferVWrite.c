/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: iccBufferVWrite.c
// Desc: This file contains the code for the iccBufferVWrite routine.
// Hist: When       Who  What
//       04/27/2003 ptb  Initial Code.
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include "buffer_utils.h" 
 
/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa = a;
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS
PERL_PREPROCESS  for(ii=0; ii < n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    b->index+=j;
PERL_PREPROCESS    b->index %= b->size;
PERL_PREPROCESS    b->pndex+=j;
PERL_PREPROCESS    b->pndex %= b->size;
PERL_PREPROCESS    b->theBuffer[b->index] = *pa;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS  }
#endif


/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
VOID iccBufferVWriteFLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32        START.
  FLT32 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE FLT32         STOP.
}

VOID iccBufferVWriteFLT64( VOID *a, INT32 i, iccBufferFLT64_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64        START.
  FLT64 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE FLT64         STOP.
}

VOID iccBufferVWriteFLT96( VOID *a, INT32 i, iccBufferFLT96_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64        START.
  FLT64 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE FLT64         STOP.
}

VOID iccBufferVWriteINT08( VOID *a, INT32 i, iccBufferINT08_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT08        START.
  INT08 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT08         STOP.
}

VOID iccBufferVWriteINT16( VOID *a, INT32 i, iccBufferINT16_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT16        START.
  INT16 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT16         STOP.
}

VOID iccBufferVWriteINT32( VOID *a, INT32 i, iccBufferINT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT32        START.
  INT32 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT32         STOP.
}

VOID iccBufferVWriteINT64( VOID *a, INT32 i, iccBufferINT64_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT64        START.
  INT64 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT64         STOP.
}

VOID iccBufferVWriteUNT08( VOID *a, INT32 i, iccBufferUNT08_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT08        START.
  UNT08 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT08         STOP.
}

VOID iccBufferVWriteUNT16( VOID *a, INT32 i, iccBufferUNT16_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT16        START.
  UNT16 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT16         STOP.
}

VOID iccBufferVWriteUNT32( VOID *a, INT32 i, iccBufferUNT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT32        START.
  UNT32 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT32         STOP.
}

VOID iccBufferVWriteUNT64( VOID *a, INT32 i, iccBufferUNT64_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT64        START.
  UNT64 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT64         STOP.
}

VOID iccBufferVWriteCFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT32        START.
  CFLT32 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE CFLT32         STOP.
}

VOID iccBufferVWriteCFLT64( VOID *a, INT32 i, iccBufferCFLT64_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT64        START.
  CFLT64 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE CFLT64         STOP.
}

VOID iccBufferVWriteCFLT96( VOID *a, INT32 i, iccBufferCFLT96_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT96      START.
  CFLT96 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE CFLT96       STOP.
}

VOID iccBufferVWriteCINT08( VOID *a, INT32 i, iccBufferCINT08_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CINT08        START.
  CINT08 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE CINT08         STOP.
}

VOID iccBufferVWriteCINT16( VOID *a, INT32 i, iccBufferCINT16_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CINT16        START.
  CINT16 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE CINT16         STOP.
}

VOID iccBufferVWriteCINT32( VOID *a, INT32 i, iccBufferCINT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CINT32        START.
  CINT32 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE CINT32         STOP.
}

VOID iccBufferVWriteCINT64( VOID *a, INT32 i, iccBufferCINT64_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CINT64        START.
  CINT64 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE CINT64         STOP.
}

VOID iccBufferVWriteCUNT08( VOID *a, INT32 i, iccBufferCUNT08_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT08        START.
  CUNT08 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE CUNT08         STOP.
}

VOID iccBufferVWriteCUNT16( VOID *a, INT32 i, iccBufferCUNT16_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT16        START.
  CUNT16 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE CUNT16         STOP.
}

VOID iccBufferVWriteCUNT32( VOID *a, INT32 i, iccBufferCUNT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT32        START.
  CUNT32 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE CUNT32         STOP.
}

VOID iccBufferVWriteCUNT64( VOID *a, INT32 i, iccBufferCUNT64_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT64        START.
  CUNT64 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE CUNT64         STOP.
}

// Handle 3 element vector.
//------------------------------------------------------------------------------
VOID iccBufferVWriteVFLT32( VOID *a, INT32 i, iccBufferVFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE VFLT32        START.
  VFLT32 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE VFLT32         STOP.
}

VOID iccBufferVWriteVFLT64( VOID *a, INT32 i, iccBufferVFLT64_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE VFLT64        START.
  VFLT64 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE VFLT64         STOP.
}

VOID iccBufferVWriteVFLT96( VOID *a, INT32 i, iccBufferVFLT96_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE VFLT96       START.
  VFLT96 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE VFLT96        STOP.
}

VOID iccBufferVWriteVINT08( VOID *a, INT32 i, iccBufferVINT08_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE VINT08        START.
  VINT08 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE VINT08         STOP.
}

VOID iccBufferVWriteVINT16( VOID *a, INT32 i, iccBufferVINT16_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE VINT16        START.
  VINT16 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE VINT16         STOP.
}

VOID iccBufferVWriteVINT32( VOID *a, INT32 i, iccBufferVINT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE VINT32        START.
  VINT32 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE VINT32         STOP.
}

VOID iccBufferVWriteVINT64( VOID *a, INT32 i, iccBufferVINT64_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE VINT64        START.
  VINT64 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE VINT64         STOP.
}

VOID iccBufferVWriteVUNT08( VOID *a, INT32 i, iccBufferVUNT08_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE VUNT08        START.
  VUNT08 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE VUNT08         STOP.
}

VOID iccBufferVWriteVUNT16( VOID *a, INT32 i, iccBufferVUNT16_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE VUNT16        START.
  VUNT16 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE VUNT16         STOP.
}

VOID iccBufferVWriteVUNT32( VOID *a, INT32 i, iccBufferVUNT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE VUNT32        START.
  VUNT32 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE VUNT32         STOP.
}

VOID iccBufferVWriteVUNT64( VOID *a, INT32 i, iccBufferVUNT64_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE VUNT64        START.
  VUNT64 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE VUNT64         STOP.
}

// Buffer write with conversion.
//------------------------------------------------------------------------------
VOID iccBufferVWriteFLT64FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64        START.
  FLT64 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE FLT64         STOP.
}

VOID iccBufferVWriteINT08FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT08        START.
  INT08 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT08         STOP.
}

VOID iccBufferVWriteINT16FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT16        START.
  INT16 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT16         STOP.
}

VOID iccBufferVWriteINT32FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT32        START.
  INT32 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT32         STOP.
}

VOID iccBufferVWriteINT64FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT64        START.
  INT64 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT64         STOP.
}

VOID iccBufferVWriteUNT08FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT08        START.
  UNT08 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT08         STOP.
}

VOID iccBufferVWriteUNT16FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT16        START.
  UNT16 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT16         STOP.
}

VOID iccBufferVWriteUNT32FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT32        START.
  UNT32 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT32         STOP.
}

VOID iccBufferVWriteUNT64FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT64        START.
  UNT64 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index] = *pa;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT64         STOP.
}


#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa = a;
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS
PERL_PREPROCESS  for(ii=0; ii < n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    b->index+=j;
PERL_PREPROCESS    b->index %= b->size;
PERL_PREPROCESS    b->pndex+=j;
PERL_PREPROCESS    b->pndex %= b->size;
PERL_PREPROCESS    b->theBuffer[b->index].r = pa->r;
PERL_PREPROCESS    b->theBuffer[b->index].i = pa->i;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS  }
#endif


// Handle Complex with conversion.
//------------------------------------------------------------------------------
VOID iccBufferVWriteCFLT64CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT64        START.
  CFLT64 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index].r = pa->r;
    b->theBuffer[b->index].i = pa->i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CFLT64         STOP.
}

VOID iccBufferVWriteCINT08CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CINT08        START.
  CINT08 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index].r = pa->r;
    b->theBuffer[b->index].i = pa->i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CINT08         STOP.
}

VOID iccBufferVWriteCINT16CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CINT16        START.
  CINT16 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index].r = pa->r;
    b->theBuffer[b->index].i = pa->i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CINT16         STOP.
}

VOID iccBufferVWriteCINT32CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CINT32        START.
  CINT32 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index].r = pa->r;
    b->theBuffer[b->index].i = pa->i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CINT32         STOP.
}

VOID iccBufferVWriteCINT64CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CINT64        START.
  CINT64 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index].r = pa->r;
    b->theBuffer[b->index].i = pa->i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CINT64         STOP.
}

VOID iccBufferVWriteCUNT08CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT08        START.
  CUNT08 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index].r = pa->r;
    b->theBuffer[b->index].i = pa->i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CUNT08         STOP.
}

VOID iccBufferVWriteCUNT16CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT16        START.
  CUNT16 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index].r = pa->r;
    b->theBuffer[b->index].i = pa->i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CUNT16         STOP.
}

VOID iccBufferVWriteCUNT32CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT32        START.
  CUNT32 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index].r = pa->r;
    b->theBuffer[b->index].i = pa->i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CUNT32         STOP.
}

VOID iccBufferVWriteCUNT64CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT64        START.
  CUNT64 *pa = a;
  INT32 ii;

  for(ii=0; ii < n; ii++)
  {
    b->index+=j;
    b->index %= b->size;
    b->pndex+=j;
    b->pndex %= b->size;
    b->theBuffer[b->index].r = pa->r;
    b->theBuffer[b->index].i = pa->i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CUNT64         STOP.
}



/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
