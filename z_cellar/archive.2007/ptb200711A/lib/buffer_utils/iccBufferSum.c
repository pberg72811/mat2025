/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: iccBufferSum.c
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
VOID iccBufferSumFLT32( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferFLT32_t FLT32             START.
  iccBufferFLT32_t *pa = (iccBufferFLT32_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE iccBufferFLT32_t FLT32              STOP.
}

VOID iccBufferSumFLT64( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferFLT64_t FLT64             START.
  iccBufferFLT64_t *pa = (iccBufferFLT64_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE iccBufferFLT64_t FLT64              STOP.
}

VOID iccBufferSumFLT96( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferFLT96_t FLT64             START.
  iccBufferFLT96_t *pa = (iccBufferFLT96_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE iccBufferFLT96_t FLT64              STOP.
}

VOID iccBufferSumINT08( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferINT08_t INT08             START.
  iccBufferINT08_t *pa = (iccBufferINT08_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE iccBufferINT08_t INT08              STOP.
}

VOID iccBufferSumINT16( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferINT16_t INT16             START.
  iccBufferINT16_t *pa = (iccBufferINT16_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE iccBufferINT16_t INT16              STOP.
}

VOID iccBufferSumINT32( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferINT32_t INT32             START.
  iccBufferINT32_t *pa = (iccBufferINT32_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE iccBufferINT32_t INT32              STOP.
}

VOID iccBufferSumINT64( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferINT64_t INT64             START.
  iccBufferINT64_t *pa = (iccBufferINT64_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE iccBufferINT64_t INT64              STOP.
}

VOID iccBufferSumUNT08( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferUNT08_t UNT08             START.
  iccBufferUNT08_t *pa = (iccBufferUNT08_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE iccBufferUNT08_t UNT08              STOP.
}

VOID iccBufferSumUNT16( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferUNT16_t UNT16             START.
  iccBufferUNT16_t *pa = (iccBufferUNT16_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE iccBufferUNT16_t UNT16              STOP.
}

VOID iccBufferSumUNT32( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferUNT32_t UNT32             START.
  iccBufferUNT32_t *pa = (iccBufferUNT32_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE iccBufferUNT32_t UNT32              STOP.
}

VOID iccBufferSumUNT64( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferUNT64_t UNT64             START.
  iccBufferUNT64_t *pa = (iccBufferUNT64_t *) a;
  INT32 ii;

  pa->theSum = 0;                    // Zero out the sum.
  for(ii=0; ii<pa->size;ii++)        // For each element
  {                                  // in the buffer
    pa->theSum += pa->theBuffer[ii]; // Add element to the sum.
  }
//------------------------------- COMMON-CODE iccBufferUNT64_t UNT64              STOP.
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
VOID iccBufferSumCFLT32( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferCFLT32_t CFLT32             START.
  iccBufferCFLT32_t *pa = (iccBufferCFLT32_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE iccBufferCFLT32_t CFLT32              STOP.
}

VOID iccBufferSumCFLT64( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferCFLT64_t CFLT64             START.
  iccBufferCFLT64_t *pa = (iccBufferCFLT64_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE iccBufferCFLT64_t CFLT64              STOP.
}

VOID iccBufferSumCFLT96( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferCFLT96_t CFLT96           START.
  iccBufferCFLT96_t *pa = (iccBufferCFLT96_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE iccBufferCFLT96_t CFLT96            STOP.
}

VOID iccBufferSumCINT08( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferCINT08_t CINT08             START.
  iccBufferCINT08_t *pa = (iccBufferCINT08_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE iccBufferCINT08_t CINT08              STOP.
}

VOID iccBufferSumCINT16( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferCINT16_t CINT16             START.
  iccBufferCINT16_t *pa = (iccBufferCINT16_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE iccBufferCINT16_t CINT16              STOP.
}

VOID iccBufferSumCINT32( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferCINT32_t CINT32             START.
  iccBufferCINT32_t *pa = (iccBufferCINT32_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE iccBufferCINT32_t CINT32              STOP.
}

VOID iccBufferSumCINT64( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferCINT64_t CINT64             START.
  iccBufferCINT64_t *pa = (iccBufferCINT64_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE iccBufferCINT64_t CINT64              STOP.
}

VOID iccBufferSumCUNT08( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferCUNT08_t CUNT08             START.
  iccBufferCUNT08_t *pa = (iccBufferCUNT08_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE iccBufferCUNT08_t CUNT08              STOP.
}

VOID iccBufferSumCUNT16( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferCUNT16_t CUNT16             START.
  iccBufferCUNT16_t *pa = (iccBufferCUNT16_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE iccBufferCUNT16_t CUNT16              STOP.
}

VOID iccBufferSumCUNT32( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferCUNT32_t CUNT32             START.
  iccBufferCUNT32_t *pa = (iccBufferCUNT32_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE iccBufferCUNT32_t CUNT32              STOP.
}

VOID iccBufferSumCUNT64( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferCUNT64_t CUNT64             START.
  iccBufferCUNT64_t *pa = (iccBufferCUNT64_t *) a;
  INT32 ii;
  pa->theSum.r = 0;
  pa->theSum.i = 0;
  for(ii=0; ii<pa->size;ii++)
  {
    pa->theSum.r += pa->theBuffer[ii].r;
    pa->theSum.i += pa->theBuffer[ii].i;
  }
//------------------------------- COMMON-CODE iccBufferCUNT64_t CUNT64              STOP.
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
VOID iccBufferSumVFLT32( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferVFLT32_t VFLT32             START.
  iccBufferVFLT32_t *pa = (iccBufferVFLT32_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVFLT32_t VFLT32              STOP.
}

VOID iccBufferSumVFLT64( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferVFLT64_t VFLT64             START.
  iccBufferVFLT64_t *pa = (iccBufferVFLT64_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVFLT64_t VFLT64              STOP.
}

VOID iccBufferSumVFLT96( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferVFLT96_t VFLT96            START.
  iccBufferVFLT96_t *pa = (iccBufferVFLT96_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVFLT96_t VFLT96             STOP.
}

VOID iccBufferSumVINT08( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferVINT08_t VINT08             START.
  iccBufferVINT08_t *pa = (iccBufferVINT08_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVINT08_t VINT08              STOP.
}

VOID iccBufferSumVINT16( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferVINT16_t VINT16             START.
  iccBufferVINT16_t *pa = (iccBufferVINT16_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVINT16_t VINT16              STOP.
}

VOID iccBufferSumVINT32( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferVINT32_t VINT32             START.
  iccBufferVINT32_t *pa = (iccBufferVINT32_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVINT32_t VINT32              STOP.
}

VOID iccBufferSumVINT64( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferVINT64_t VINT64             START.
  iccBufferVINT64_t *pa = (iccBufferVINT64_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVINT64_t VINT64              STOP.
}

VOID iccBufferSumVUNT08( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferVUNT08_t VUNT08             START.
  iccBufferVUNT08_t *pa = (iccBufferVUNT08_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVUNT08_t VUNT08              STOP.
}

VOID iccBufferSumVUNT16( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferVUNT16_t VUNT16             START.
  iccBufferVUNT16_t *pa = (iccBufferVUNT16_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVUNT16_t VUNT16              STOP.
}

VOID iccBufferSumVUNT32( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferVUNT32_t VUNT32             START.
  iccBufferVUNT32_t *pa = (iccBufferVUNT32_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVUNT32_t VUNT32              STOP.
}

VOID iccBufferSumVUNT64( VOID *a )
{
//------------------------------- COMMON-CODE iccBufferVUNT64_t VUNT64             START.
  iccBufferVUNT64_t *pa = (iccBufferVUNT64_t *) a;
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
//------------------------------- COMMON-CODE iccBufferVUNT64_t VUNT64              STOP.
}


/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
