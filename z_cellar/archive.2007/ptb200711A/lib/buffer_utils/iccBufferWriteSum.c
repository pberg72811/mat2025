/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: iccBufferWriteSum.c
// Desc: This file contains the code for the iccBufferWriteSum routine.
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
VOID iccBufferWriteSumFLT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferFLT32_t FLT32            START.
  iccBufferFLT32_t *pa = (iccBufferFLT32_t *) a;
  FLT32 *pb = (FLT32 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE iccBufferFLT32_t FLT32             STOP.
}

VOID iccBufferWriteSumFLT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferFLT64_t FLT64            START.
  iccBufferFLT64_t *pa = (iccBufferFLT64_t *) a;
  FLT64 *pb = (FLT64 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE iccBufferFLT64_t FLT64             STOP.
}

VOID iccBufferWriteSumFLT96( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferFLT96_t FLT64            START.
  iccBufferFLT96_t *pa = (iccBufferFLT96_t *) a;
  FLT64 *pb = (FLT64 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE iccBufferFLT96_t FLT64             STOP.
}

VOID iccBufferWriteSumINT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferINT08_t INT08            START.
  iccBufferINT08_t *pa = (iccBufferINT08_t *) a;
  INT08 *pb = (INT08 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE iccBufferINT08_t INT08             STOP.
}

VOID iccBufferWriteSumINT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferINT16_t INT16            START.
  iccBufferINT16_t *pa = (iccBufferINT16_t *) a;
  INT16 *pb = (INT16 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE iccBufferINT16_t INT16             STOP.
}

VOID iccBufferWriteSumINT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferINT32_t INT32            START.
  iccBufferINT32_t *pa = (iccBufferINT32_t *) a;
  INT32 *pb = (INT32 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE iccBufferINT32_t INT32             STOP.
}

VOID iccBufferWriteSumINT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferINT64_t INT64            START.
  iccBufferINT64_t *pa = (iccBufferINT64_t *) a;
  INT64 *pb = (INT64 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE iccBufferINT64_t INT64             STOP.
}

VOID iccBufferWriteSumUNT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferUNT08_t UNT08            START.
  iccBufferUNT08_t *pa = (iccBufferUNT08_t *) a;
  UNT08 *pb = (UNT08 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE iccBufferUNT08_t UNT08             STOP.
}

VOID iccBufferWriteSumUNT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferUNT16_t UNT16            START.
  iccBufferUNT16_t *pa = (iccBufferUNT16_t *) a;
  UNT16 *pb = (UNT16 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE iccBufferUNT16_t UNT16             STOP.
}

VOID iccBufferWriteSumUNT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferUNT32_t UNT32            START.
  iccBufferUNT32_t *pa = (iccBufferUNT32_t *) a;
  UNT32 *pb = (UNT32 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE iccBufferUNT32_t UNT32             STOP.
}

VOID iccBufferWriteSumUNT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferUNT64_t UNT64            START.
  iccBufferUNT64_t *pa = (iccBufferUNT64_t *) a;
  UNT64 *pb = (UNT64 *) b;

  pa->theSum -= pa->theBuffer[pa->index]; // Subtract the old.                   -
  pa->theBuffer[pa->index] = *pb;         // Bring in the new.                   -
  pa->theSum += pa->theBuffer[pa->index]; // Add the new.                        -
  pa->index++;                            // Update the index.                   -
  pa->pndex++;                            // Update the end index.               -
  pa->index %= pa->size;                  // Keep index in bounds.               -
  pa->pndex %= pa->size;                  // Keep index in bounds.               -
//------------------------------- COMMON-CODE iccBufferUNT64_t UNT64             STOP.
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

VOID iccBufferWriteSumCFLT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCFLT32_t CFLT32            START.
  iccBufferCFLT32_t *pa = (iccBufferCFLT32_t *) a;
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
//------------------------------- COMMON-CODE iccBufferCFLT32_t CFLT32             STOP.
}

VOID iccBufferWriteSumCFLT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCFLT64_t CFLT64            START.
  iccBufferCFLT64_t *pa = (iccBufferCFLT64_t *) a;
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
//------------------------------- COMMON-CODE iccBufferCFLT64_t CFLT64             STOP.
}

VOID iccBufferWriteSumCFLT96( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCFLT96_t CFLT96          START.
  iccBufferCFLT96_t *pa = (iccBufferCFLT96_t *) a;
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
//------------------------------- COMMON-CODE iccBufferCFLT96_t CFLT96           STOP.
}

VOID iccBufferWriteSumCINT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCINT08_t CINT08            START.
  iccBufferCINT08_t *pa = (iccBufferCINT08_t *) a;
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
//------------------------------- COMMON-CODE iccBufferCINT08_t CINT08             STOP.
}

VOID iccBufferWriteSumCINT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCINT16_t CINT16            START.
  iccBufferCINT16_t *pa = (iccBufferCINT16_t *) a;
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
//------------------------------- COMMON-CODE iccBufferCINT16_t CINT16             STOP.
}

VOID iccBufferWriteSumCINT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCINT32_t CINT32            START.
  iccBufferCINT32_t *pa = (iccBufferCINT32_t *) a;
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
//------------------------------- COMMON-CODE iccBufferCINT32_t CINT32             STOP.
}

VOID iccBufferWriteSumCINT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCINT64_t CINT64            START.
  iccBufferCINT64_t *pa = (iccBufferCINT64_t *) a;
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
//------------------------------- COMMON-CODE iccBufferCINT64_t CINT64             STOP.
}

VOID iccBufferWriteSumCUNT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCUNT08_t CUNT08            START.
  iccBufferCUNT08_t *pa = (iccBufferCUNT08_t *) a;
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
//------------------------------- COMMON-CODE iccBufferCUNT08_t CUNT08             STOP.
}

VOID iccBufferWriteSumCUNT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCUNT16_t CUNT16            START.
  iccBufferCUNT16_t *pa = (iccBufferCUNT16_t *) a;
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
//------------------------------- COMMON-CODE iccBufferCUNT16_t CUNT16             STOP.
}

VOID iccBufferWriteSumCUNT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCUNT32_t CUNT32            START.
  iccBufferCUNT32_t *pa = (iccBufferCUNT32_t *) a;
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
//------------------------------- COMMON-CODE iccBufferCUNT32_t CUNT32             STOP.
}

VOID iccBufferWriteSumCUNT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferCUNT64_t CUNT64            START.
  iccBufferCUNT64_t *pa = (iccBufferCUNT64_t *) a;
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
//------------------------------- COMMON-CODE iccBufferCUNT64_t CUNT64             STOP.
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
VOID iccBufferWriteSumVFLT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVFLT32_t VFLT32            START.
  iccBufferVFLT32_t *pa = (iccBufferVFLT32_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVFLT32_t VFLT32             STOP.
}

VOID iccBufferWriteSumVFLT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVFLT64_t VFLT64            START.
  iccBufferVFLT64_t *pa = (iccBufferVFLT64_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVFLT64_t VFLT64             STOP.
}

VOID iccBufferWriteSumVFLT96( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVFLT96_t VFLT96           START.
  iccBufferVFLT96_t *pa = (iccBufferVFLT96_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVFLT96_t VFLT96            STOP.
}

VOID iccBufferWriteSumVINT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVINT08_t VINT08            START.
  iccBufferVINT08_t *pa = (iccBufferVINT08_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVINT08_t VINT08             STOP.
}

VOID iccBufferWriteSumVINT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVINT16_t VINT16            START.
  iccBufferVINT16_t *pa = (iccBufferVINT16_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVINT16_t VINT16             STOP.
}

VOID iccBufferWriteSumVINT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVINT32_t VINT32            START.
  iccBufferVINT32_t *pa = (iccBufferVINT32_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVINT32_t VINT32             STOP.
}

VOID iccBufferWriteSumVINT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVINT64_t VINT64            START.
  iccBufferVINT64_t *pa = (iccBufferVINT64_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVINT64_t VINT64             STOP.
}

VOID iccBufferWriteSumVUNT08( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVUNT08_t VUNT08            START.
  iccBufferVUNT08_t *pa = (iccBufferVUNT08_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVUNT08_t VUNT08             STOP.
}

VOID iccBufferWriteSumVUNT16( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVUNT16_t VUNT16            START.
  iccBufferVUNT16_t *pa = (iccBufferVUNT16_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVUNT16_t VUNT16             STOP.
}

VOID iccBufferWriteSumVUNT32( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVUNT32_t VUNT32            START.
  iccBufferVUNT32_t *pa = (iccBufferVUNT32_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVUNT32_t VUNT32             STOP.
}

VOID iccBufferWriteSumVUNT64( VOID *a, VOID *b )
{
//------------------------------- COMMON-CODE iccBufferVUNT64_t VUNT64            START.
  iccBufferVUNT64_t *pa = (iccBufferVUNT64_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVUNT64_t VUNT64             STOP.
}


/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
