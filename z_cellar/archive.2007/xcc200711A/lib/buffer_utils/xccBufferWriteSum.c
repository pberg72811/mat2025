/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccBufferWriteSum.c
// Desc: This file contains the code for the xccBufferWriteSum routine.
// Hist: When       Who  What
//       07/11/2005 ptb  Initial Code.
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
PERL_PREPROCESS  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
PERL_PREPROCESS  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
PERL_PREPROCESS  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
PERL_PREPROCESS  pa->index++;                            // Update the index.                   -
PERL_PREPROCESS  pa->pndex++;                            // Update the end index.               -
PERL_PREPROCESS  pa->index %= pa->size;                  // Keep index in bounds.               -
PERL_PREPROCESS  pa->pndex %= pa->size;                  // Keep index in bounds.               -
#endif


/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
VOID xccBufferWriteSumFLT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferFLT32_t FLT32            START.
  xccBufferFLT32_t *pa = (xccBufferFLT32_t *) a;
  FLT32 *pb = (FLT32 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE xccBufferFLT32_t FLT32             STOP.
}

VOID xccBufferWriteSumFLT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferFLT64_t FLT64            START.
  xccBufferFLT64_t *pa = (xccBufferFLT64_t *) a;
  FLT64 *pb = (FLT64 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE xccBufferFLT64_t FLT64             STOP.
}

VOID xccBufferWriteSumFLT96( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferFLT96_t FLT64            START.
  xccBufferFLT96_t *pa = (xccBufferFLT96_t *) a;
  FLT64 *pb = (FLT64 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE xccBufferFLT96_t FLT64             STOP.
}

VOID xccBufferWriteSumINT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferINT08_t INT08            START.
  xccBufferINT08_t *pa = (xccBufferINT08_t *) a;
  INT08 *pb = (INT08 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE xccBufferINT08_t INT08             STOP.
}

VOID xccBufferWriteSumINT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferINT16_t INT16            START.
  xccBufferINT16_t *pa = (xccBufferINT16_t *) a;
  INT16 *pb = (INT16 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE xccBufferINT16_t INT16             STOP.
}

VOID xccBufferWriteSumINT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferINT32_t INT32            START.
  xccBufferINT32_t *pa = (xccBufferINT32_t *) a;
  INT32 *pb = (INT32 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE xccBufferINT32_t INT32             STOP.
}

VOID xccBufferWriteSumINT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferINT64_t INT64            START.
  xccBufferINT64_t *pa = (xccBufferINT64_t *) a;
  INT64 *pb = (INT64 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE xccBufferINT64_t INT64             STOP.
}

VOID xccBufferWriteSumUNT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferUNT08_t UNT08            START.
  xccBufferUNT08_t *pa = (xccBufferUNT08_t *) a;
  UNT08 *pb = (UNT08 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE xccBufferUNT08_t UNT08             STOP.
}

VOID xccBufferWriteSumUNT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferUNT16_t UNT16            START.
  xccBufferUNT16_t *pa = (xccBufferUNT16_t *) a;
  UNT16 *pb = (UNT16 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE xccBufferUNT16_t UNT16             STOP.
}

VOID xccBufferWriteSumUNT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferUNT32_t UNT32            START.
  xccBufferUNT32_t *pa = (xccBufferUNT32_t *) a;
  UNT32 *pb = (UNT32 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE xccBufferUNT32_t UNT32             STOP.
}

VOID xccBufferWriteSumUNT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferUNT64_t UNT64            START.
  xccBufferUNT64_t *pa = (xccBufferUNT64_t *) a;
  UNT64 *pb = (UNT64 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE xccBufferUNT64_t UNT64             STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa = (XXXXX *) a;
PERL_PREPROCESS  YYYYY *pb = (YYYYY *) b;
PERL_PREPROCESS
PERL_PREPROCESS  pa->theSum.r -= pa->theBuffer[pa->index].r;
PERL_PREPROCESS  pa->theSum.i -= pa->theBuffer[pa->index].i;
PERL_PREPROCESS  pa->theBuffer[pa->index] = *pb;
PERL_PREPROCESS  pa->theSum.r += pa->theBuffer[pa->index].r;
PERL_PREPROCESS  pa->theSum.i += pa->theBuffer[pa->index].i;
PERL_PREPROCESS  pa->index++;
PERL_PREPROCESS  pa->pndex++;
PERL_PREPROCESS  pa->index %= pa->size;
PERL_PREPROCESS  pa->pndex %= pa->size;
#endif

VOID xccBufferWriteSumCFLT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCFLT32_t CFLT32            START.
  xccBufferCFLT32_t *pa = (xccBufferCFLT32_t *) a;
  CFLT32 *pb = (CFLT32 *) b;

  pa->theSum.r -= pa->theBuffer[pa->index].r;
  pa->theSum.i -= pa->theBuffer[pa->index].i;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.r += pa->theBuffer[pa->index].r;
  pa->theSum.i += pa->theBuffer[pa->index].i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCFLT32_t CFLT32             STOP.
}

VOID xccBufferWriteSumCFLT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCFLT64_t CFLT64            START.
  xccBufferCFLT64_t *pa = (xccBufferCFLT64_t *) a;
  CFLT64 *pb = (CFLT64 *) b;

  pa->theSum.r -= pa->theBuffer[pa->index].r;
  pa->theSum.i -= pa->theBuffer[pa->index].i;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.r += pa->theBuffer[pa->index].r;
  pa->theSum.i += pa->theBuffer[pa->index].i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCFLT64_t CFLT64             STOP.
}

VOID xccBufferWriteSumCFLT96( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCFLT96_t CFLT96          START.
  xccBufferCFLT96_t *pa = (xccBufferCFLT96_t *) a;
  CFLT96 *pb = (CFLT96 *) b;

  pa->theSum.r -= pa->theBuffer[pa->index].r;
  pa->theSum.i -= pa->theBuffer[pa->index].i;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.r += pa->theBuffer[pa->index].r;
  pa->theSum.i += pa->theBuffer[pa->index].i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCFLT96_t CFLT96           STOP.
}

VOID xccBufferWriteSumCINT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCINT08_t CINT08            START.
  xccBufferCINT08_t *pa = (xccBufferCINT08_t *) a;
  CINT08 *pb = (CINT08 *) b;

  pa->theSum.r -= pa->theBuffer[pa->index].r;
  pa->theSum.i -= pa->theBuffer[pa->index].i;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.r += pa->theBuffer[pa->index].r;
  pa->theSum.i += pa->theBuffer[pa->index].i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCINT08_t CINT08             STOP.
}

VOID xccBufferWriteSumCINT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCINT16_t CINT16            START.
  xccBufferCINT16_t *pa = (xccBufferCINT16_t *) a;
  CINT16 *pb = (CINT16 *) b;

  pa->theSum.r -= pa->theBuffer[pa->index].r;
  pa->theSum.i -= pa->theBuffer[pa->index].i;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.r += pa->theBuffer[pa->index].r;
  pa->theSum.i += pa->theBuffer[pa->index].i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCINT16_t CINT16             STOP.
}

VOID xccBufferWriteSumCINT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCINT32_t CINT32            START.
  xccBufferCINT32_t *pa = (xccBufferCINT32_t *) a;
  CINT32 *pb = (CINT32 *) b;

  pa->theSum.r -= pa->theBuffer[pa->index].r;
  pa->theSum.i -= pa->theBuffer[pa->index].i;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.r += pa->theBuffer[pa->index].r;
  pa->theSum.i += pa->theBuffer[pa->index].i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCINT32_t CINT32             STOP.
}

VOID xccBufferWriteSumCINT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCINT64_t CINT64            START.
  xccBufferCINT64_t *pa = (xccBufferCINT64_t *) a;
  CINT64 *pb = (CINT64 *) b;

  pa->theSum.r -= pa->theBuffer[pa->index].r;
  pa->theSum.i -= pa->theBuffer[pa->index].i;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.r += pa->theBuffer[pa->index].r;
  pa->theSum.i += pa->theBuffer[pa->index].i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCINT64_t CINT64             STOP.
}

VOID xccBufferWriteSumCUNT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCUNT08_t CUNT08            START.
  xccBufferCUNT08_t *pa = (xccBufferCUNT08_t *) a;
  CUNT08 *pb = (CUNT08 *) b;

  pa->theSum.r -= pa->theBuffer[pa->index].r;
  pa->theSum.i -= pa->theBuffer[pa->index].i;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.r += pa->theBuffer[pa->index].r;
  pa->theSum.i += pa->theBuffer[pa->index].i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCUNT08_t CUNT08             STOP.
}

VOID xccBufferWriteSumCUNT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCUNT16_t CUNT16            START.
  xccBufferCUNT16_t *pa = (xccBufferCUNT16_t *) a;
  CUNT16 *pb = (CUNT16 *) b;

  pa->theSum.r -= pa->theBuffer[pa->index].r;
  pa->theSum.i -= pa->theBuffer[pa->index].i;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.r += pa->theBuffer[pa->index].r;
  pa->theSum.i += pa->theBuffer[pa->index].i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCUNT16_t CUNT16             STOP.
}

VOID xccBufferWriteSumCUNT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCUNT32_t CUNT32            START.
  xccBufferCUNT32_t *pa = (xccBufferCUNT32_t *) a;
  CUNT32 *pb = (CUNT32 *) b;

  pa->theSum.r -= pa->theBuffer[pa->index].r;
  pa->theSum.i -= pa->theBuffer[pa->index].i;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.r += pa->theBuffer[pa->index].r;
  pa->theSum.i += pa->theBuffer[pa->index].i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCUNT32_t CUNT32             STOP.
}

VOID xccBufferWriteSumCUNT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferCUNT64_t CUNT64            START.
  xccBufferCUNT64_t *pa = (xccBufferCUNT64_t *) a;
  CUNT64 *pb = (CUNT64 *) b;

  pa->theSum.r -= pa->theBuffer[pa->index].r;
  pa->theSum.i -= pa->theBuffer[pa->index].i;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.r += pa->theBuffer[pa->index].r;
  pa->theSum.i += pa->theBuffer[pa->index].i;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferCUNT64_t CUNT64             STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa = (XXXXX *) a;
PERL_PREPROCESS  YYYYY *pb = (YYYYY *) b;
PERL_PREPROCESS
PERL_PREPROCESS  pa->theSum.x -= pa->theBuffer[pa->index].x;
PERL_PREPROCESS  pa->theSum.y -= pa->theBuffer[pa->index].y;
PERL_PREPROCESS  pa->theSum.z -= pa->theBuffer[pa->index].z;
PERL_PREPROCESS  pa->theBuffer[pa->index] = *pb;
PERL_PREPROCESS  pa->theSum.x += pa->theBuffer[pa->index].x;
PERL_PREPROCESS  pa->theSum.y += pa->theBuffer[pa->index].y;
PERL_PREPROCESS  pa->theSum.z += pa->theBuffer[pa->index].z;
PERL_PREPROCESS  pa->index++;
PERL_PREPROCESS  pa->pndex++;
PERL_PREPROCESS  pa->index %= pa->size;
PERL_PREPROCESS  pa->pndex %= pa->size;
#endif
// Handle 3 element vector.
//------------------------------------------------------------------------------
VOID xccBufferWriteSumVFLT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVFLT32_t VFLT32            START.
  xccBufferVFLT32_t *pa = (xccBufferVFLT32_t *) a;
  VFLT32 *pb = (VFLT32 *) b;

  pa->theSum.x -= pa->theBuffer[pa->index].x;
  pa->theSum.y -= pa->theBuffer[pa->index].y;
  pa->theSum.z -= pa->theBuffer[pa->index].z;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.x += pa->theBuffer[pa->index].x;
  pa->theSum.y += pa->theBuffer[pa->index].y;
  pa->theSum.z += pa->theBuffer[pa->index].z;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVFLT32_t VFLT32             STOP.
}

VOID xccBufferWriteSumVFLT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVFLT64_t VFLT64            START.
  xccBufferVFLT64_t *pa = (xccBufferVFLT64_t *) a;
  VFLT64 *pb = (VFLT64 *) b;

  pa->theSum.x -= pa->theBuffer[pa->index].x;
  pa->theSum.y -= pa->theBuffer[pa->index].y;
  pa->theSum.z -= pa->theBuffer[pa->index].z;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.x += pa->theBuffer[pa->index].x;
  pa->theSum.y += pa->theBuffer[pa->index].y;
  pa->theSum.z += pa->theBuffer[pa->index].z;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVFLT64_t VFLT64             STOP.
}

VOID xccBufferWriteSumVFLT96( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVFLT96_t VFLT96           START.
  xccBufferVFLT96_t *pa = (xccBufferVFLT96_t *) a;
  VFLT96 *pb = (VFLT96 *) b;

  pa->theSum.x -= pa->theBuffer[pa->index].x;
  pa->theSum.y -= pa->theBuffer[pa->index].y;
  pa->theSum.z -= pa->theBuffer[pa->index].z;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.x += pa->theBuffer[pa->index].x;
  pa->theSum.y += pa->theBuffer[pa->index].y;
  pa->theSum.z += pa->theBuffer[pa->index].z;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVFLT96_t VFLT96            STOP.
}

VOID xccBufferWriteSumVINT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVINT08_t VINT08            START.
  xccBufferVINT08_t *pa = (xccBufferVINT08_t *) a;
  VINT08 *pb = (VINT08 *) b;

  pa->theSum.x -= pa->theBuffer[pa->index].x;
  pa->theSum.y -= pa->theBuffer[pa->index].y;
  pa->theSum.z -= pa->theBuffer[pa->index].z;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.x += pa->theBuffer[pa->index].x;
  pa->theSum.y += pa->theBuffer[pa->index].y;
  pa->theSum.z += pa->theBuffer[pa->index].z;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVINT08_t VINT08             STOP.
}

VOID xccBufferWriteSumVINT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVINT16_t VINT16            START.
  xccBufferVINT16_t *pa = (xccBufferVINT16_t *) a;
  VINT16 *pb = (VINT16 *) b;

  pa->theSum.x -= pa->theBuffer[pa->index].x;
  pa->theSum.y -= pa->theBuffer[pa->index].y;
  pa->theSum.z -= pa->theBuffer[pa->index].z;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.x += pa->theBuffer[pa->index].x;
  pa->theSum.y += pa->theBuffer[pa->index].y;
  pa->theSum.z += pa->theBuffer[pa->index].z;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVINT16_t VINT16             STOP.
}

VOID xccBufferWriteSumVINT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVINT32_t VINT32            START.
  xccBufferVINT32_t *pa = (xccBufferVINT32_t *) a;
  VINT32 *pb = (VINT32 *) b;

  pa->theSum.x -= pa->theBuffer[pa->index].x;
  pa->theSum.y -= pa->theBuffer[pa->index].y;
  pa->theSum.z -= pa->theBuffer[pa->index].z;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.x += pa->theBuffer[pa->index].x;
  pa->theSum.y += pa->theBuffer[pa->index].y;
  pa->theSum.z += pa->theBuffer[pa->index].z;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVINT32_t VINT32             STOP.
}

VOID xccBufferWriteSumVINT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVINT64_t VINT64            START.
  xccBufferVINT64_t *pa = (xccBufferVINT64_t *) a;
  VINT64 *pb = (VINT64 *) b;

  pa->theSum.x -= pa->theBuffer[pa->index].x;
  pa->theSum.y -= pa->theBuffer[pa->index].y;
  pa->theSum.z -= pa->theBuffer[pa->index].z;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.x += pa->theBuffer[pa->index].x;
  pa->theSum.y += pa->theBuffer[pa->index].y;
  pa->theSum.z += pa->theBuffer[pa->index].z;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVINT64_t VINT64             STOP.
}

VOID xccBufferWriteSumVUNT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVUNT08_t VUNT08            START.
  xccBufferVUNT08_t *pa = (xccBufferVUNT08_t *) a;
  VUNT08 *pb = (VUNT08 *) b;

  pa->theSum.x -= pa->theBuffer[pa->index].x;
  pa->theSum.y -= pa->theBuffer[pa->index].y;
  pa->theSum.z -= pa->theBuffer[pa->index].z;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.x += pa->theBuffer[pa->index].x;
  pa->theSum.y += pa->theBuffer[pa->index].y;
  pa->theSum.z += pa->theBuffer[pa->index].z;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVUNT08_t VUNT08             STOP.
}

VOID xccBufferWriteSumVUNT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVUNT16_t VUNT16            START.
  xccBufferVUNT16_t *pa = (xccBufferVUNT16_t *) a;
  VUNT16 *pb = (VUNT16 *) b;

  pa->theSum.x -= pa->theBuffer[pa->index].x;
  pa->theSum.y -= pa->theBuffer[pa->index].y;
  pa->theSum.z -= pa->theBuffer[pa->index].z;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.x += pa->theBuffer[pa->index].x;
  pa->theSum.y += pa->theBuffer[pa->index].y;
  pa->theSum.z += pa->theBuffer[pa->index].z;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVUNT16_t VUNT16             STOP.
}

VOID xccBufferWriteSumVUNT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVUNT32_t VUNT32            START.
  xccBufferVUNT32_t *pa = (xccBufferVUNT32_t *) a;
  VUNT32 *pb = (VUNT32 *) b;

  pa->theSum.x -= pa->theBuffer[pa->index].x;
  pa->theSum.y -= pa->theBuffer[pa->index].y;
  pa->theSum.z -= pa->theBuffer[pa->index].z;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.x += pa->theBuffer[pa->index].x;
  pa->theSum.y += pa->theBuffer[pa->index].y;
  pa->theSum.z += pa->theBuffer[pa->index].z;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVUNT32_t VUNT32             STOP.
}

VOID xccBufferWriteSumVUNT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE xccBufferVUNT64_t VUNT64            START.
  xccBufferVUNT64_t *pa = (xccBufferVUNT64_t *) a;
  VUNT64 *pb = (VUNT64 *) b;

  pa->theSum.x -= pa->theBuffer[pa->index].x;
  pa->theSum.y -= pa->theBuffer[pa->index].y;
  pa->theSum.z -= pa->theBuffer[pa->index].z;
  pa->theBuffer[pa->index] = *pb;
  pa->theSum.x += pa->theBuffer[pa->index].x;
  pa->theSum.y += pa->theBuffer[pa->index].y;
  pa->theSum.z += pa->theBuffer[pa->index].z;
  pa->index++;
  pa->pndex++;
  pa->index %= pa->size;
  pa->pndex %= pa->size;
//------------------------------- COMMON-CODE xccBufferVUNT64_t VUNT64             STOP.
}


/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
