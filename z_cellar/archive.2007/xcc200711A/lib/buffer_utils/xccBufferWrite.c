/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccBufferWrite.c
// Desc: This file contains the code for the xccBufferWrite routine.
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
PERL_PREPROCESS  XXXXX *pa = (XXXXX *) a;
PERL_PREPROCESS  YYYYY *pb = (YYYYY *) b;
PERL_PREPROCESS
PERL_PREPROCESS  pa->theBuffer[pa->index] = *pb;
PERL_PREPROCESS  pa->index++;
PERL_PREPROCESS  pa->pndex++;
PERL_PREPROCESS  pa->index %= pa->size;
PERL_PREPROCESS  pa->pndex %= pa->size;
#endif


/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
VOID xccBufferWriteFLT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferFLT32_t FLT32          START.
  xccBufferFLT32_t *pa = (xccBufferFLT32_t *) a;
  FLT32 *pb = (FLT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferFLT32_t FLT32           STOP.
}

VOID xccBufferWriteFLT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferFLT64_t FLT64          START.
  xccBufferFLT64_t *pa = (xccBufferFLT64_t *) a;
  FLT64 *pb = (FLT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferFLT64_t FLT64           STOP.
}

VOID xccBufferWriteFLT96( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferFLT96_t FLT64          START.
  xccBufferFLT96_t *pa = (xccBufferFLT96_t *) a;
  FLT64 *pb = (FLT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferFLT96_t FLT64           STOP.
}

VOID xccBufferWriteINT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferINT08_t INT08          START.
  xccBufferINT08_t *pa = (xccBufferINT08_t *) a;
  INT08 *pb = (INT08 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferINT08_t INT08           STOP.
}

VOID xccBufferWriteINT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferINT16_t INT16          START.
  xccBufferINT16_t *pa = (xccBufferINT16_t *) a;
  INT16 *pb = (INT16 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferINT16_t INT16           STOP.
}

VOID xccBufferWriteINT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferINT32_t INT32          START.
  xccBufferINT32_t *pa = (xccBufferINT32_t *) a;
  INT32 *pb = (INT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferINT32_t INT32           STOP.
}

VOID xccBufferWriteINT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferINT64_t INT64          START.
  xccBufferINT64_t *pa = (xccBufferINT64_t *) a;
  INT64 *pb = (INT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferINT64_t INT64           STOP.
}

VOID xccBufferWriteUNT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferUNT08_t UNT08          START.
  xccBufferUNT08_t *pa = (xccBufferUNT08_t *) a;
  UNT08 *pb = (UNT08 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferUNT08_t UNT08           STOP.
}

VOID xccBufferWriteUNT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferUNT16_t UNT16          START.
  xccBufferUNT16_t *pa = (xccBufferUNT16_t *) a;
  UNT16 *pb = (UNT16 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferUNT16_t UNT16           STOP.
}

VOID xccBufferWriteUNT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferUNT32_t UNT32          START.
  xccBufferUNT32_t *pa = (xccBufferUNT32_t *) a;
  UNT32 *pb = (UNT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferUNT32_t UNT32           STOP.
}

VOID xccBufferWriteUNT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferUNT64_t UNT64          START.
  xccBufferUNT64_t *pa = (xccBufferUNT64_t *) a;
  UNT64 *pb = (UNT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferUNT64_t UNT64           STOP.
}

VOID xccBufferWriteCFLT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCFLT32_t CFLT32          START.
  xccBufferCFLT32_t *pa = (xccBufferCFLT32_t *) a;
  CFLT32 *pb = (CFLT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCFLT32_t CFLT32           STOP.
}

VOID xccBufferWriteCFLT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCFLT64_t CFLT64          START.
  xccBufferCFLT64_t *pa = (xccBufferCFLT64_t *) a;
  CFLT64 *pb = (CFLT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCFLT64_t CFLT64           STOP.
}

VOID xccBufferWriteCFLT96( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCFLT96_t CFLT96        START.
  xccBufferCFLT96_t *pa = (xccBufferCFLT96_t *) a;
  CFLT96 *pb = (CFLT96 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCFLT96_t CFLT96         STOP.
}

VOID xccBufferWriteCINT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCINT08_t CINT08          START.
  xccBufferCINT08_t *pa = (xccBufferCINT08_t *) a;
  CINT08 *pb = (CINT08 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCINT08_t CINT08           STOP.
}

VOID xccBufferWriteCINT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCINT16_t CINT16          START.
  xccBufferCINT16_t *pa = (xccBufferCINT16_t *) a;
  CINT16 *pb = (CINT16 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCINT16_t CINT16           STOP.
}

VOID xccBufferWriteCINT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCINT32_t CINT32          START.
  xccBufferCINT32_t *pa = (xccBufferCINT32_t *) a;
  CINT32 *pb = (CINT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCINT32_t CINT32           STOP.
}

VOID xccBufferWriteCINT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCINT64_t CINT64          START.
  xccBufferCINT64_t *pa = (xccBufferCINT64_t *) a;
  CINT64 *pb = (CINT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCINT64_t CINT64           STOP.
}

VOID xccBufferWriteCUNT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCUNT08_t CUNT08          START.
  xccBufferCUNT08_t *pa = (xccBufferCUNT08_t *) a;
  CUNT08 *pb = (CUNT08 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCUNT08_t CUNT08           STOP.
}

VOID xccBufferWriteCUNT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCUNT16_t CUNT16          START.
  xccBufferCUNT16_t *pa = (xccBufferCUNT16_t *) a;
  CUNT16 *pb = (CUNT16 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCUNT16_t CUNT16           STOP.
}

VOID xccBufferWriteCUNT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCUNT32_t CUNT32          START.
  xccBufferCUNT32_t *pa = (xccBufferCUNT32_t *) a;
  CUNT32 *pb = (CUNT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCUNT32_t CUNT32           STOP.
}

VOID xccBufferWriteCUNT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCUNT64_t CUNT64          START.
  xccBufferCUNT64_t *pa = (xccBufferCUNT64_t *) a;
  CUNT64 *pb = (CUNT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCUNT64_t CUNT64           STOP.
}

// Handle 3 element vector.
//------------------------------------------------------------------------------
VOID xccBufferWriteVFLT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVFLT32_t VFLT32          START.
  xccBufferVFLT32_t *pa = (xccBufferVFLT32_t *) a;
  VFLT32 *pb = (VFLT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVFLT32_t VFLT32           STOP.
}

VOID xccBufferWriteVFLT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVFLT64_t VFLT64          START.
  xccBufferVFLT64_t *pa = (xccBufferVFLT64_t *) a;
  VFLT64 *pb = (VFLT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVFLT64_t VFLT64           STOP.
}

VOID xccBufferWriteVFLT96( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVFLT96_t VFLT96         START.
  xccBufferVFLT96_t *pa = (xccBufferVFLT96_t *) a;
  VFLT96 *pb = (VFLT96 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVFLT96_t VFLT96          STOP.
}

VOID xccBufferWriteVINT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVINT08_t VINT08          START.
  xccBufferVINT08_t *pa = (xccBufferVINT08_t *) a;
  VINT08 *pb = (VINT08 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVINT08_t VINT08           STOP.
}

VOID xccBufferWriteVINT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVINT16_t VINT16          START.
  xccBufferVINT16_t *pa = (xccBufferVINT16_t *) a;
  VINT16 *pb = (VINT16 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVINT16_t VINT16           STOP.
}

VOID xccBufferWriteVINT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVINT32_t VINT32          START.
  xccBufferVINT32_t *pa = (xccBufferVINT32_t *) a;
  VINT32 *pb = (VINT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVINT32_t VINT32           STOP.
}

VOID xccBufferWriteVINT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVINT64_t VINT64          START.
  xccBufferVINT64_t *pa = (xccBufferVINT64_t *) a;
  VINT64 *pb = (VINT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVINT64_t VINT64           STOP.
}

VOID xccBufferWriteVUNT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVUNT08_t VUNT08          START.
  xccBufferVUNT08_t *pa = (xccBufferVUNT08_t *) a;
  VUNT08 *pb = (VUNT08 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVUNT08_t VUNT08           STOP.
}

VOID xccBufferWriteVUNT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVUNT16_t VUNT16          START.
  xccBufferVUNT16_t *pa = (xccBufferVUNT16_t *) a;
  VUNT16 *pb = (VUNT16 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVUNT16_t VUNT16           STOP.
}

VOID xccBufferWriteVUNT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVUNT32_t VUNT32          START.
  xccBufferVUNT32_t *pa = (xccBufferVUNT32_t *) a;
  VUNT32 *pb = (VUNT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVUNT32_t VUNT32           STOP.
}

VOID xccBufferWriteVUNT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVUNT64_t VUNT64          START.
  xccBufferVUNT64_t *pa = (xccBufferVUNT64_t *) a;
  VUNT64 *pb = (VUNT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVUNT64_t VUNT64           STOP.
}

// Buffer write with conversion.
//------------------------------------------------------------------------------
VOID xccBufferWriteFLT32FLT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferFLT32_t FLT64          START.
  xccBufferFLT32_t *pa = (xccBufferFLT32_t *) a;
  FLT64 *pb = (FLT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferFLT32_t FLT64           STOP.
}

VOID xccBufferWriteFLT32INT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferFLT32_t INT08          START.
  xccBufferFLT32_t *pa = (xccBufferFLT32_t *) a;
  INT08 *pb = (INT08 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferFLT32_t INT08           STOP.
}

VOID xccBufferWriteFLT32INT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferFLT32_t INT16          START.
  xccBufferFLT32_t *pa = (xccBufferFLT32_t *) a;
  INT16 *pb = (INT16 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferFLT32_t INT16           STOP.
}

VOID xccBufferWriteFLT32INT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferFLT32_t INT32          START.
  xccBufferFLT32_t *pa = (xccBufferFLT32_t *) a;
  INT32 *pb = (INT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferFLT32_t INT32           STOP.
}

VOID xccBufferWriteFLT32INT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferFLT32_t INT64          START.
  xccBufferFLT32_t *pa = (xccBufferFLT32_t *) a;
  INT64 *pb = (INT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferFLT32_t INT64           STOP.
}

VOID xccBufferWriteFLT32UNT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferFLT32_t UNT08          START.
  xccBufferFLT32_t *pa = (xccBufferFLT32_t *) a;
  UNT08 *pb = (UNT08 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferFLT32_t UNT08           STOP.
}

VOID xccBufferWriteFLT32UNT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferFLT32_t UNT16          START.
  xccBufferFLT32_t *pa = (xccBufferFLT32_t *) a;
  UNT16 *pb = (UNT16 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferFLT32_t UNT16           STOP.
}

VOID xccBufferWriteFLT32UNT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferFLT32_t UNT32          START.
  xccBufferFLT32_t *pa = (xccBufferFLT32_t *) a;
  UNT32 *pb = (UNT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferFLT32_t UNT32           STOP.
}

VOID xccBufferWriteFLT32UNT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferFLT32_t UNT64          START.
  xccBufferFLT32_t *pa = (xccBufferFLT32_t *) a;
  UNT64 *pb = (UNT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferFLT32_t UNT64           STOP.
}

// Handle Complex with conversion.
//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa = a;
PERL_PREPROCESS  YYYYY *pb = b;
PERL_PREPROCESS
PERL_PREPROCESS  pa->theBuffer[pa->index].r = pb->r;
PERL_PREPROCESS  pa->theBuffer[pa->index].i = pb->i;
PERL_PREPROCESS  pa->index++;
PERL_PREPROCESS  pa->pndex++;
PERL_PREPROCESS  pa->index %= pa->size;
PERL_PREPROCESS  pa->pndex %= pa->size;
#endif

// Handle Complex with conversion.
//------------------------------------------------------------------------------
VOID xccBufferWriteCFLT32CFLT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCFLT32_t CFLT64          START.
  xccBufferCFLT32_t *pa = a;
  CFLT64 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCFLT32_t CFLT64           STOP.
}

VOID xccBufferWriteCFLT32CINT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCFLT32_t CINT08          START.
  xccBufferCFLT32_t *pa = a;
  CINT08 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCFLT32_t CINT08           STOP.
}

VOID xccBufferWriteCFLT32CINT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCFLT32_t CINT16          START.
  xccBufferCFLT32_t *pa = a;
  CINT16 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCFLT32_t CINT16           STOP.
}

VOID xccBufferWriteCFLT32CINT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCFLT32_t CINT32          START.
  xccBufferCFLT32_t *pa = a;
  CINT32 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCFLT32_t CINT32           STOP.
}

VOID xccBufferWriteCFLT32CINT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCFLT32_t CINT64          START.
  xccBufferCFLT32_t *pa = a;
  CINT64 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCFLT32_t CINT64           STOP.
}

VOID xccBufferWriteCFLT32CUNT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCFLT32_t CUNT08          START.
  xccBufferCFLT32_t *pa = a;
  CUNT08 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCFLT32_t CUNT08           STOP.
}

VOID xccBufferWriteCFLT32CUNT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCFLT32_t CUNT16          START.
  xccBufferCFLT32_t *pa = a;
  CUNT16 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCFLT32_t CUNT16           STOP.
}

VOID xccBufferWriteCFLT32CUNT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCFLT32_t CUNT32          START.
  xccBufferCFLT32_t *pa = a;
  CUNT32 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCFLT32_t CUNT32           STOP.
}

VOID xccBufferWriteCFLT32CUNT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCFLT32_t CUNT64          START.
  xccBufferCFLT32_t *pa = a;
  CUNT64 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCFLT32_t CUNT64           STOP.
}



/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
