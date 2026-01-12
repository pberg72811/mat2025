/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccBufferVWrite.c
// Desc: This file contains the code for the xccBufferVWrite routine.
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
VOID xccBufferVWriteFLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteFLT64( VOID *a, INT32 i, xccBufferFLT64_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteFLT96( VOID *a, INT32 i, xccBufferFLT96_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteINT08( VOID *a, INT32 i, xccBufferINT08_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteINT16( VOID *a, INT32 i, xccBufferINT16_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteINT32( VOID *a, INT32 i, xccBufferINT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteINT64( VOID *a, INT32 i, xccBufferINT64_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteUNT08( VOID *a, INT32 i, xccBufferUNT08_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteUNT16( VOID *a, INT32 i, xccBufferUNT16_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteUNT32( VOID *a, INT32 i, xccBufferUNT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteUNT64( VOID *a, INT32 i, xccBufferUNT64_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCFLT64( VOID *a, INT32 i, xccBufferCFLT64_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCFLT96( VOID *a, INT32 i, xccBufferCFLT96_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCINT08( VOID *a, INT32 i, xccBufferCINT08_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCINT16( VOID *a, INT32 i, xccBufferCINT16_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCINT32( VOID *a, INT32 i, xccBufferCINT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCINT64( VOID *a, INT32 i, xccBufferCINT64_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCUNT08( VOID *a, INT32 i, xccBufferCUNT08_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCUNT16( VOID *a, INT32 i, xccBufferCUNT16_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCUNT32( VOID *a, INT32 i, xccBufferCUNT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCUNT64( VOID *a, INT32 i, xccBufferCUNT64_t *b, INT32 j, UNT32 n )
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
VOID xccBufferVWriteVFLT32( VOID *a, INT32 i, xccBufferVFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteVFLT64( VOID *a, INT32 i, xccBufferVFLT64_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteVFLT96( VOID *a, INT32 i, xccBufferVFLT96_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteVINT08( VOID *a, INT32 i, xccBufferVINT08_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteVINT16( VOID *a, INT32 i, xccBufferVINT16_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteVINT32( VOID *a, INT32 i, xccBufferVINT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteVINT64( VOID *a, INT32 i, xccBufferVINT64_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteVUNT08( VOID *a, INT32 i, xccBufferVUNT08_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteVUNT16( VOID *a, INT32 i, xccBufferVUNT16_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteVUNT32( VOID *a, INT32 i, xccBufferVUNT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteVUNT64( VOID *a, INT32 i, xccBufferVUNT64_t *b, INT32 j, UNT32 n )
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
VOID xccBufferVWriteFLT64FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteINT08FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteINT16FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteINT32FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteINT64FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteUNT08FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteUNT16FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteUNT32FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteUNT64FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n )
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
VOID xccBufferVWriteCFLT64CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCINT08CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCINT16CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCINT32CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCINT64CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCUNT08CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCUNT16CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCUNT32CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n )
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

VOID xccBufferVWriteCUNT64CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n )
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
