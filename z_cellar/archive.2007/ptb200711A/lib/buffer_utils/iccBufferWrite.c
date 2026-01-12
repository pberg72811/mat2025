/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: iccBufferWrite.c
// Desc: This file contains the code for the iccBufferWrite routine.
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
VOID iccBufferWriteFLT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferFLT32_t FLT32          START.
  iccBufferFLT32_t *pa = (iccBufferFLT32_t *) a;
  FLT32 *pb = (FLT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferFLT32_t FLT32           STOP.
}

VOID iccBufferWriteFLT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferFLT64_t FLT64          START.
  iccBufferFLT64_t *pa = (iccBufferFLT64_t *) a;
  FLT64 *pb = (FLT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferFLT64_t FLT64           STOP.
}

VOID iccBufferWriteFLT96( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferFLT96_t FLT64          START.
  iccBufferFLT96_t *pa = (iccBufferFLT96_t *) a;
  FLT64 *pb = (FLT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferFLT96_t FLT64           STOP.
}

VOID iccBufferWriteINT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferINT08_t INT08          START.
  iccBufferINT08_t *pa = (iccBufferINT08_t *) a;
  INT08 *pb = (INT08 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferINT08_t INT08           STOP.
}

VOID iccBufferWriteINT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferINT16_t INT16          START.
  iccBufferINT16_t *pa = (iccBufferINT16_t *) a;
  INT16 *pb = (INT16 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferINT16_t INT16           STOP.
}

VOID iccBufferWriteINT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferINT32_t INT32          START.
  iccBufferINT32_t *pa = (iccBufferINT32_t *) a;
  INT32 *pb = (INT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferINT32_t INT32           STOP.
}

VOID iccBufferWriteINT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferINT64_t INT64          START.
  iccBufferINT64_t *pa = (iccBufferINT64_t *) a;
  INT64 *pb = (INT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferINT64_t INT64           STOP.
}

VOID iccBufferWriteUNT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferUNT08_t UNT08          START.
  iccBufferUNT08_t *pa = (iccBufferUNT08_t *) a;
  UNT08 *pb = (UNT08 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferUNT08_t UNT08           STOP.
}

VOID iccBufferWriteUNT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferUNT16_t UNT16          START.
  iccBufferUNT16_t *pa = (iccBufferUNT16_t *) a;
  UNT16 *pb = (UNT16 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferUNT16_t UNT16           STOP.
}

VOID iccBufferWriteUNT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferUNT32_t UNT32          START.
  iccBufferUNT32_t *pa = (iccBufferUNT32_t *) a;
  UNT32 *pb = (UNT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferUNT32_t UNT32           STOP.
}

VOID iccBufferWriteUNT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferUNT64_t UNT64          START.
  iccBufferUNT64_t *pa = (iccBufferUNT64_t *) a;
  UNT64 *pb = (UNT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferUNT64_t UNT64           STOP.
}

VOID iccBufferWriteCFLT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCFLT32_t CFLT32          START.
  iccBufferCFLT32_t *pa = (iccBufferCFLT32_t *) a;
  CFLT32 *pb = (CFLT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCFLT32_t CFLT32           STOP.
}

VOID iccBufferWriteCFLT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCFLT64_t CFLT64          START.
  iccBufferCFLT64_t *pa = (iccBufferCFLT64_t *) a;
  CFLT64 *pb = (CFLT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCFLT64_t CFLT64           STOP.
}

VOID iccBufferWriteCFLT96( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCFLT96_t CFLT96        START.
  iccBufferCFLT96_t *pa = (iccBufferCFLT96_t *) a;
  CFLT96 *pb = (CFLT96 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCFLT96_t CFLT96         STOP.
}

VOID iccBufferWriteCINT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCINT08_t CINT08          START.
  iccBufferCINT08_t *pa = (iccBufferCINT08_t *) a;
  CINT08 *pb = (CINT08 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCINT08_t CINT08           STOP.
}

VOID iccBufferWriteCINT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCINT16_t CINT16          START.
  iccBufferCINT16_t *pa = (iccBufferCINT16_t *) a;
  CINT16 *pb = (CINT16 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCINT16_t CINT16           STOP.
}

VOID iccBufferWriteCINT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCINT32_t CINT32          START.
  iccBufferCINT32_t *pa = (iccBufferCINT32_t *) a;
  CINT32 *pb = (CINT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCINT32_t CINT32           STOP.
}

VOID iccBufferWriteCINT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCINT64_t CINT64          START.
  iccBufferCINT64_t *pa = (iccBufferCINT64_t *) a;
  CINT64 *pb = (CINT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCINT64_t CINT64           STOP.
}

VOID iccBufferWriteCUNT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCUNT08_t CUNT08          START.
  iccBufferCUNT08_t *pa = (iccBufferCUNT08_t *) a;
  CUNT08 *pb = (CUNT08 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCUNT08_t CUNT08           STOP.
}

VOID iccBufferWriteCUNT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCUNT16_t CUNT16          START.
  iccBufferCUNT16_t *pa = (iccBufferCUNT16_t *) a;
  CUNT16 *pb = (CUNT16 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCUNT16_t CUNT16           STOP.
}

VOID iccBufferWriteCUNT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCUNT32_t CUNT32          START.
  iccBufferCUNT32_t *pa = (iccBufferCUNT32_t *) a;
  CUNT32 *pb = (CUNT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCUNT32_t CUNT32           STOP.
}

VOID iccBufferWriteCUNT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCUNT64_t CUNT64          START.
  iccBufferCUNT64_t *pa = (iccBufferCUNT64_t *) a;
  CUNT64 *pb = (CUNT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCUNT64_t CUNT64           STOP.
}

// Handle 3 element vector.
//------------------------------------------------------------------------------
VOID iccBufferWriteVFLT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVFLT32_t VFLT32          START.
  iccBufferVFLT32_t *pa = (iccBufferVFLT32_t *) a;
  VFLT32 *pb = (VFLT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferVFLT32_t VFLT32           STOP.
}

VOID iccBufferWriteVFLT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVFLT64_t VFLT64          START.
  iccBufferVFLT64_t *pa = (iccBufferVFLT64_t *) a;
  VFLT64 *pb = (VFLT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferVFLT64_t VFLT64           STOP.
}

VOID iccBufferWriteVFLT96( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVFLT96_t VFLT96         START.
  iccBufferVFLT96_t *pa = (iccBufferVFLT96_t *) a;
  VFLT96 *pb = (VFLT96 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferVFLT96_t VFLT96          STOP.
}

VOID iccBufferWriteVINT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVINT08_t VINT08          START.
  iccBufferVINT08_t *pa = (iccBufferVINT08_t *) a;
  VINT08 *pb = (VINT08 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferVINT08_t VINT08           STOP.
}

VOID iccBufferWriteVINT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVINT16_t VINT16          START.
  iccBufferVINT16_t *pa = (iccBufferVINT16_t *) a;
  VINT16 *pb = (VINT16 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferVINT16_t VINT16           STOP.
}

VOID iccBufferWriteVINT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVINT32_t VINT32          START.
  iccBufferVINT32_t *pa = (iccBufferVINT32_t *) a;
  VINT32 *pb = (VINT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferVINT32_t VINT32           STOP.
}

VOID iccBufferWriteVINT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVINT64_t VINT64          START.
  iccBufferVINT64_t *pa = (iccBufferVINT64_t *) a;
  VINT64 *pb = (VINT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferVINT64_t VINT64           STOP.
}

VOID iccBufferWriteVUNT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVUNT08_t VUNT08          START.
  iccBufferVUNT08_t *pa = (iccBufferVUNT08_t *) a;
  VUNT08 *pb = (VUNT08 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferVUNT08_t VUNT08           STOP.
}

VOID iccBufferWriteVUNT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVUNT16_t VUNT16          START.
  iccBufferVUNT16_t *pa = (iccBufferVUNT16_t *) a;
  VUNT16 *pb = (VUNT16 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferVUNT16_t VUNT16           STOP.
}

VOID iccBufferWriteVUNT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVUNT32_t VUNT32          START.
  iccBufferVUNT32_t *pa = (iccBufferVUNT32_t *) a;
  VUNT32 *pb = (VUNT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferVUNT32_t VUNT32           STOP.
}

VOID iccBufferWriteVUNT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVUNT64_t VUNT64          START.
  iccBufferVUNT64_t *pa = (iccBufferVUNT64_t *) a;
  VUNT64 *pb = (VUNT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferVUNT64_t VUNT64           STOP.
}

// Buffer write with conversion.
//------------------------------------------------------------------------------
VOID iccBufferWriteFLT32FLT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferFLT32_t FLT64          START.
  iccBufferFLT32_t *pa = (iccBufferFLT32_t *) a;
  FLT64 *pb = (FLT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferFLT32_t FLT64           STOP.
}

VOID iccBufferWriteFLT32INT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferFLT32_t INT08          START.
  iccBufferFLT32_t *pa = (iccBufferFLT32_t *) a;
  INT08 *pb = (INT08 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferFLT32_t INT08           STOP.
}

VOID iccBufferWriteFLT32INT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferFLT32_t INT16          START.
  iccBufferFLT32_t *pa = (iccBufferFLT32_t *) a;
  INT16 *pb = (INT16 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferFLT32_t INT16           STOP.
}

VOID iccBufferWriteFLT32INT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferFLT32_t INT32          START.
  iccBufferFLT32_t *pa = (iccBufferFLT32_t *) a;
  INT32 *pb = (INT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferFLT32_t INT32           STOP.
}

VOID iccBufferWriteFLT32INT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferFLT32_t INT64          START.
  iccBufferFLT32_t *pa = (iccBufferFLT32_t *) a;
  INT64 *pb = (INT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferFLT32_t INT64           STOP.
}

VOID iccBufferWriteFLT32UNT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferFLT32_t UNT08          START.
  iccBufferFLT32_t *pa = (iccBufferFLT32_t *) a;
  UNT08 *pb = (UNT08 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferFLT32_t UNT08           STOP.
}

VOID iccBufferWriteFLT32UNT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferFLT32_t UNT16          START.
  iccBufferFLT32_t *pa = (iccBufferFLT32_t *) a;
  UNT16 *pb = (UNT16 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferFLT32_t UNT16           STOP.
}

VOID iccBufferWriteFLT32UNT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferFLT32_t UNT32          START.
  iccBufferFLT32_t *pa = (iccBufferFLT32_t *) a;
  UNT32 *pb = (UNT32 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferFLT32_t UNT32           STOP.
}

VOID iccBufferWriteFLT32UNT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferFLT32_t UNT64          START.
  iccBufferFLT32_t *pa = (iccBufferFLT32_t *) a;
  UNT64 *pb = (UNT64 *) b;

  pa->theBuffer[pa->index] = *pb;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferFLT32_t UNT64           STOP.
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
VOID iccBufferWriteCFLT32CFLT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCFLT32_t CFLT64          START.
  iccBufferCFLT32_t *pa = a;
  CFLT64 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCFLT32_t CFLT64           STOP.
}

VOID iccBufferWriteCFLT32CINT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCFLT32_t CINT08          START.
  iccBufferCFLT32_t *pa = a;
  CINT08 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCFLT32_t CINT08           STOP.
}

VOID iccBufferWriteCFLT32CINT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCFLT32_t CINT16          START.
  iccBufferCFLT32_t *pa = a;
  CINT16 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCFLT32_t CINT16           STOP.
}

VOID iccBufferWriteCFLT32CINT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCFLT32_t CINT32          START.
  iccBufferCFLT32_t *pa = a;
  CINT32 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCFLT32_t CINT32           STOP.
}

VOID iccBufferWriteCFLT32CINT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCFLT32_t CINT64          START.
  iccBufferCFLT32_t *pa = a;
  CINT64 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCFLT32_t CINT64           STOP.
}

VOID iccBufferWriteCFLT32CUNT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCFLT32_t CUNT08          START.
  iccBufferCFLT32_t *pa = a;
  CUNT08 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCFLT32_t CUNT08           STOP.
}

VOID iccBufferWriteCFLT32CUNT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCFLT32_t CUNT16          START.
  iccBufferCFLT32_t *pa = a;
  CUNT16 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCFLT32_t CUNT16           STOP.
}

VOID iccBufferWriteCFLT32CUNT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCFLT32_t CUNT32          START.
  iccBufferCFLT32_t *pa = a;
  CUNT32 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCFLT32_t CUNT32           STOP.
}

VOID iccBufferWriteCFLT32CUNT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCFLT32_t CUNT64          START.
  iccBufferCFLT32_t *pa = a;
  CUNT64 *pb = b;

  pa->theBuffer[pa->index].r = pb->r;
  pa->theBuffer[pa->index].i = pb->i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE iccBufferCFLT32_t CUNT64           STOP.
}



/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
