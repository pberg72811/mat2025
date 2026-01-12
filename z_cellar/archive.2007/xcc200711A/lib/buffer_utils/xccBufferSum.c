/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccBufferSum.c
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
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS
PERL_PREPROCESS  pa->theSum = 0;                    // Zero out the sum.
PERL_PREPROCESS  for(ii=0; ii<pa->size;ii++)        // For each element
PERL_PREPROCESS  {                                  // in the buffer
PERL_PREPROCESS    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
PERL_PREPROCESS  }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID xccBufferSumFLT32( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferFLT32_t FLT32             START.
  xccBufferFLT32_t *pa = (xccBufferFLT32_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE xccBufferFLT32_t FLT32              STOP.
}

VOID xccBufferSumFLT64( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferFLT64_t FLT64             START.
  xccBufferFLT64_t *pa = (xccBufferFLT64_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE xccBufferFLT64_t FLT64              STOP.
}

VOID xccBufferSumFLT96( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferFLT96_t FLT64             START.
  xccBufferFLT96_t *pa = (xccBufferFLT96_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE xccBufferFLT96_t FLT64              STOP.
}

VOID xccBufferSumINT08( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferINT08_t INT08             START.
  xccBufferINT08_t *pa = (xccBufferINT08_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE xccBufferINT08_t INT08              STOP.
}

VOID xccBufferSumINT16( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferINT16_t INT16             START.
  xccBufferINT16_t *pa = (xccBufferINT16_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE xccBufferINT16_t INT16              STOP.
}

VOID xccBufferSumINT32( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferINT32_t INT32             START.
  xccBufferINT32_t *pa = (xccBufferINT32_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE xccBufferINT32_t INT32              STOP.
}

VOID xccBufferSumINT64( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferINT64_t INT64             START.
  xccBufferINT64_t *pa = (xccBufferINT64_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE xccBufferINT64_t INT64              STOP.
}

VOID xccBufferSumUNT08( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferUNT08_t UNT08             START.
  xccBufferUNT08_t *pa = (xccBufferUNT08_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE xccBufferUNT08_t UNT08              STOP.
}

VOID xccBufferSumUNT16( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferUNT16_t UNT16             START.
  xccBufferUNT16_t *pa = (xccBufferUNT16_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE xccBufferUNT16_t UNT16              STOP.
}

VOID xccBufferSumUNT32( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferUNT32_t UNT32             START.
  xccBufferUNT32_t *pa = (xccBufferUNT32_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE xccBufferUNT32_t UNT32              STOP.
}

VOID xccBufferSumUNT64( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferUNT64_t UNT64             START.
  xccBufferUNT64_t *pa = (xccBufferUNT64_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE xccBufferUNT64_t UNT64              STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa = (XXXXX *) a;
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS  pa->theSum.r = 0;
PERL_PREPROCESS  pa->theSum.i = 0;
PERL_PREPROCESS  for(ii=0; ii<pa->size;ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    pa->theSum.r += pa->theBuffer[ii].r;
PERL_PREPROCESS    pa->theSum.i += pa->theBuffer[ii].i;
PERL_PREPROCESS  }
#endif

// Handle complex numbers.
//------------------------------------------------------------------------------
VOID xccBufferSumCFLT32( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferCFLT32_t CFLT32             START.
  xccBufferCFLT32_t *pa = (xccBufferCFLT32_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE xccBufferCFLT32_t CFLT32              STOP.
}

VOID xccBufferSumCFLT64( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferCFLT64_t CFLT64             START.
  xccBufferCFLT64_t *pa = (xccBufferCFLT64_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE xccBufferCFLT64_t CFLT64              STOP.
}

VOID xccBufferSumCFLT96( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferCFLT96_t CFLT96           START.
  xccBufferCFLT96_t *pa = (xccBufferCFLT96_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE xccBufferCFLT96_t CFLT96            STOP.
}

VOID xccBufferSumCINT08( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferCINT08_t CINT08             START.
  xccBufferCINT08_t *pa = (xccBufferCINT08_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE xccBufferCINT08_t CINT08              STOP.
}

VOID xccBufferSumCINT16( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferCINT16_t CINT16             START.
  xccBufferCINT16_t *pa = (xccBufferCINT16_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE xccBufferCINT16_t CINT16              STOP.
}

VOID xccBufferSumCINT32( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferCINT32_t CINT32             START.
  xccBufferCINT32_t *pa = (xccBufferCINT32_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE xccBufferCINT32_t CINT32              STOP.
}

VOID xccBufferSumCINT64( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferCINT64_t CINT64             START.
  xccBufferCINT64_t *pa = (xccBufferCINT64_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE xccBufferCINT64_t CINT64              STOP.
}

VOID xccBufferSumCUNT08( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferCUNT08_t CUNT08             START.
  xccBufferCUNT08_t *pa = (xccBufferCUNT08_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE xccBufferCUNT08_t CUNT08              STOP.
}

VOID xccBufferSumCUNT16( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferCUNT16_t CUNT16             START.
  xccBufferCUNT16_t *pa = (xccBufferCUNT16_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE xccBufferCUNT16_t CUNT16              STOP.
}

VOID xccBufferSumCUNT32( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferCUNT32_t CUNT32             START.
  xccBufferCUNT32_t *pa = (xccBufferCUNT32_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE xccBufferCUNT32_t CUNT32              STOP.
}

VOID xccBufferSumCUNT64( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferCUNT64_t CUNT64             START.
  xccBufferCUNT64_t *pa = (xccBufferCUNT64_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE xccBufferCUNT64_t CUNT64              STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa = (XXXXX *) a;
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS  pa->theSum.x = 0;
PERL_PREPROCESS  pa->theSum.y = 0;
PERL_PREPROCESS  pa->theSum.z = 0;
PERL_PREPROCESS  for(ii=0; ii<pa->size;ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    pa->theSum.x += pa->theBuffer[ii].x;
PERL_PREPROCESS    pa->theSum.y += pa->theBuffer[ii].y;
PERL_PREPROCESS    pa->theSum.z += pa->theBuffer[ii].z;
PERL_PREPROCESS  }
#endif

// Handle 3 element vector.
//------------------------------------------------------------------------------
VOID xccBufferSumVFLT32( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferVFLT32_t VFLT32             START.
  xccBufferVFLT32_t *pa = (xccBufferVFLT32_t *) a;
  INT32 ii;
  pa->theSum.x = 0;
  pa->theSum.y = 0;
  pa->theSum.z = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.x += pa->theBuffer[ii].x;
    pa->theSum.y += pa->theBuffer[ii].y;
    pa->theSum.z += pa->theBuffer[ii].z;
  }
//------------------------------- COMMON-CODE xccBufferVFLT32_t VFLT32              STOP.
}

VOID xccBufferSumVFLT64( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferVFLT64_t VFLT64             START.
  xccBufferVFLT64_t *pa = (xccBufferVFLT64_t *) a;
  INT32 ii;
  pa->theSum.x = 0;
  pa->theSum.y = 0;
  pa->theSum.z = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.x += pa->theBuffer[ii].x;
    pa->theSum.y += pa->theBuffer[ii].y;
    pa->theSum.z += pa->theBuffer[ii].z;
  }
//------------------------------- COMMON-CODE xccBufferVFLT64_t VFLT64              STOP.
}

VOID xccBufferSumVFLT96( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferVFLT96_t VFLT96            START.
  xccBufferVFLT96_t *pa = (xccBufferVFLT96_t *) a;
  INT32 ii;
  pa->theSum.x = 0;
  pa->theSum.y = 0;
  pa->theSum.z = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.x += pa->theBuffer[ii].x;
    pa->theSum.y += pa->theBuffer[ii].y;
    pa->theSum.z += pa->theBuffer[ii].z;
  }
//------------------------------- COMMON-CODE xccBufferVFLT96_t VFLT96             STOP.
}

VOID xccBufferSumVINT08( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferVINT08_t VINT08             START.
  xccBufferVINT08_t *pa = (xccBufferVINT08_t *) a;
  INT32 ii;
  pa->theSum.x = 0;
  pa->theSum.y = 0;
  pa->theSum.z = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.x += pa->theBuffer[ii].x;
    pa->theSum.y += pa->theBuffer[ii].y;
    pa->theSum.z += pa->theBuffer[ii].z;
  }
//------------------------------- COMMON-CODE xccBufferVINT08_t VINT08              STOP.
}

VOID xccBufferSumVINT16( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferVINT16_t VINT16             START.
  xccBufferVINT16_t *pa = (xccBufferVINT16_t *) a;
  INT32 ii;
  pa->theSum.x = 0;
  pa->theSum.y = 0;
  pa->theSum.z = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.x += pa->theBuffer[ii].x;
    pa->theSum.y += pa->theBuffer[ii].y;
    pa->theSum.z += pa->theBuffer[ii].z;
  }
//------------------------------- COMMON-CODE xccBufferVINT16_t VINT16              STOP.
}

VOID xccBufferSumVINT32( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferVINT32_t VINT32             START.
  xccBufferVINT32_t *pa = (xccBufferVINT32_t *) a;
  INT32 ii;
  pa->theSum.x = 0;
  pa->theSum.y = 0;
  pa->theSum.z = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.x += pa->theBuffer[ii].x;
    pa->theSum.y += pa->theBuffer[ii].y;
    pa->theSum.z += pa->theBuffer[ii].z;
  }
//------------------------------- COMMON-CODE xccBufferVINT32_t VINT32              STOP.
}

VOID xccBufferSumVINT64( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferVINT64_t VINT64             START.
  xccBufferVINT64_t *pa = (xccBufferVINT64_t *) a;
  INT32 ii;
  pa->theSum.x = 0;
  pa->theSum.y = 0;
  pa->theSum.z = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.x += pa->theBuffer[ii].x;
    pa->theSum.y += pa->theBuffer[ii].y;
    pa->theSum.z += pa->theBuffer[ii].z;
  }
//------------------------------- COMMON-CODE xccBufferVINT64_t VINT64              STOP.
}

VOID xccBufferSumVUNT08( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferVUNT08_t VUNT08             START.
  xccBufferVUNT08_t *pa = (xccBufferVUNT08_t *) a;
  INT32 ii;
  pa->theSum.x = 0;
  pa->theSum.y = 0;
  pa->theSum.z = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.x += pa->theBuffer[ii].x;
    pa->theSum.y += pa->theBuffer[ii].y;
    pa->theSum.z += pa->theBuffer[ii].z;
  }
//------------------------------- COMMON-CODE xccBufferVUNT08_t VUNT08              STOP.
}

VOID xccBufferSumVUNT16( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferVUNT16_t VUNT16             START.
  xccBufferVUNT16_t *pa = (xccBufferVUNT16_t *) a;
  INT32 ii;
  pa->theSum.x = 0;
  pa->theSum.y = 0;
  pa->theSum.z = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.x += pa->theBuffer[ii].x;
    pa->theSum.y += pa->theBuffer[ii].y;
    pa->theSum.z += pa->theBuffer[ii].z;
  }
//------------------------------- COMMON-CODE xccBufferVUNT16_t VUNT16              STOP.
}

VOID xccBufferSumVUNT32( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferVUNT32_t VUNT32             START.
  xccBufferVUNT32_t *pa = (xccBufferVUNT32_t *) a;
  INT32 ii;
  pa->theSum.x = 0;
  pa->theSum.y = 0;
  pa->theSum.z = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.x += pa->theBuffer[ii].x;
    pa->theSum.y += pa->theBuffer[ii].y;
    pa->theSum.z += pa->theBuffer[ii].z;
  }
//------------------------------- COMMON-CODE xccBufferVUNT32_t VUNT32              STOP.
}

VOID xccBufferSumVUNT64( VOID *a )
{
//------------------------------- COMMON-CODE xccBufferVUNT64_t VUNT64             START.
  xccBufferVUNT64_t *pa = (xccBufferVUNT64_t *) a;
  INT32 ii;
  pa->theSum.x = 0;
  pa->theSum.y = 0;
  pa->theSum.z = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.x += pa->theBuffer[ii].x;
    pa->theSum.y += pa->theBuffer[ii].y;
    pa->theSum.z += pa->theBuffer[ii].z;
  }
//------------------------------- COMMON-CODE xccBufferVUNT64_t VUNT64              STOP.
}


/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
