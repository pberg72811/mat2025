/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccBufferClear.c
// Desc: This file contains the code for the iccBufferClear routines.
// Hist: When       Who  What
//       08/18/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "buffer_utils.h" 
 
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
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS
PERL_PREPROCESS  p2Buffer->index = 0;
PERL_PREPROCESS  p2Buffer->pndex = p2Buffer->size-1;
PERL_PREPROCESS
PERL_PREPROCESS  for(ii=0; ii<p2Buffer->size; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    p2Buffer->theBuffer[ii]=0;
PERL_PREPROCESS  }
#endif

// Clear the FLT32 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearFLT32( iccBufferFLT32_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;
  p2Buffer->pndex = p2Buffer->size-1;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii]=0;
  }
//------------------------------- COMMON-CODE      STOP.
}

// Clear the FLT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearFLT64( iccBufferFLT64_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;
  p2Buffer->pndex = p2Buffer->size-1;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii]=0;
  }
//------------------------------- COMMON-CODE      STOP.
}

// Clear the FLT96 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearFLT96( iccBufferFLT96_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;
  p2Buffer->pndex = p2Buffer->size-1;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii]=0;
  }
//------------------------------- COMMON-CODE      STOP.
}

// Clear the INT08 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearINT08( iccBufferINT08_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;
  p2Buffer->pndex = p2Buffer->size-1;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii]=0;
  }
//------------------------------- COMMON-CODE      STOP.
}

// Clear the INT16 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearINT16( iccBufferINT16_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;
  p2Buffer->pndex = p2Buffer->size-1;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii]=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the INT32 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearINT32( iccBufferINT32_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;
  p2Buffer->pndex = p2Buffer->size-1;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii]=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the INT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearINT64( iccBufferINT64_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;
  p2Buffer->pndex = p2Buffer->size-1;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii]=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the UNT08 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearUNT08( iccBufferUNT08_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;
  p2Buffer->pndex = p2Buffer->size-1;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii]=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the UNT16 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearUNT16( iccBufferUNT16_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;
  p2Buffer->pndex = p2Buffer->size-1;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii]=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the UNT32 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearUNT32( iccBufferUNT32_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;
  p2Buffer->pndex = p2Buffer->size-1;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii]=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the UNT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearUNT64( iccBufferUNT64_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;
  p2Buffer->pndex = p2Buffer->size-1;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii]=0;
  }
//------------------------------- COMMON-CODE      STOP.
}

// Clear the VOIDP buffer
//------------------------------------------------------------------------------
VOID iccBufferClearVOIDP( iccBufferVOIDP_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;
  p2Buffer->pndex = p2Buffer->size-1;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii]=0;
  }
//------------------------------- COMMON-CODE      STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS
PERL_PREPROCESS  p2Buffer->index = 0;
PERL_PREPROCESS
PERL_PREPROCESS  for(ii=0; ii<p2Buffer->size; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    p2Buffer->theBuffer[ii].r=0;
PERL_PREPROCESS    p2Buffer->theBuffer[ii].i=0;
PERL_PREPROCESS  }
#endif

// Clear the CFLT32 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearCFLT32( iccBufferCFLT32_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].r=0;
    p2Buffer->theBuffer[ii].i=0;
  }
//------------------------------- COMMON-CODE      STOP.
}

// Clear the CFLT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearCFLT64( iccBufferCFLT64_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].r=0;
    p2Buffer->theBuffer[ii].i=0;
  }
//------------------------------- COMMON-CODE      STOP.
}

// Clear the CFLT96 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearCFLT96( iccBufferCFLT96_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].r=0;
    p2Buffer->theBuffer[ii].i=0;
  }
//------------------------------- COMMON-CODE      STOP.
}

// Clear the CINT08 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearCINT08( iccBufferCINT08_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].r=0;
    p2Buffer->theBuffer[ii].i=0;
  }
//------------------------------- COMMON-CODE      STOP.
}

// Clear the CINT16 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearCINT16( iccBufferCINT16_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].r=0;
    p2Buffer->theBuffer[ii].i=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the CINT32 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearCINT32( iccBufferCINT32_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].r=0;
    p2Buffer->theBuffer[ii].i=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the CINT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearCINT64( iccBufferCINT64_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].r=0;
    p2Buffer->theBuffer[ii].i=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the CUNT08 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearCUNT08( iccBufferCUNT08_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].r=0;
    p2Buffer->theBuffer[ii].i=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the CUNT16 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearCUNT16( iccBufferCUNT16_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].r=0;
    p2Buffer->theBuffer[ii].i=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the CUNT32 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearCUNT32( iccBufferCUNT32_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].r=0;
    p2Buffer->theBuffer[ii].i=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the CUNT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearCUNT64( iccBufferCUNT64_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].r=0;
    p2Buffer->theBuffer[ii].i=0;
  }
//------------------------------- COMMON-CODE      STOP.
}


#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS
PERL_PREPROCESS  p2Buffer->index = 0;
PERL_PREPROCESS
PERL_PREPROCESS  for(ii=0; ii<p2Buffer->size; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    p2Buffer->theBuffer[ii].x=0;
PERL_PREPROCESS    p2Buffer->theBuffer[ii].y=0;
PERL_PREPROCESS    p2Buffer->theBuffer[ii].z=0;
PERL_PREPROCESS  }
#endif

// Clear the VFLT32 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearVFLT32( iccBufferVFLT32_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].x=0;
    p2Buffer->theBuffer[ii].y=0;
    p2Buffer->theBuffer[ii].z=0;
  }
//------------------------------- COMMON-CODE      STOP.
}

// Clear the VFLT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearVFLT64( iccBufferVFLT64_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].x=0;
    p2Buffer->theBuffer[ii].y=0;
    p2Buffer->theBuffer[ii].z=0;
  }
//------------------------------- COMMON-CODE      STOP.
}

// Clear the VFLT96 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearVFLT96( iccBufferVFLT96_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].x=0;
    p2Buffer->theBuffer[ii].y=0;
    p2Buffer->theBuffer[ii].z=0;
  }
//------------------------------- COMMON-CODE      STOP.
}

// Clear the VINT08 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearVINT08( iccBufferVINT08_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].x=0;
    p2Buffer->theBuffer[ii].y=0;
    p2Buffer->theBuffer[ii].z=0;
  }
//------------------------------- COMMON-CODE      STOP.
}

// Clear the VINT16 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearVINT16( iccBufferVINT16_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].x=0;
    p2Buffer->theBuffer[ii].y=0;
    p2Buffer->theBuffer[ii].z=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the VINT32 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearVINT32( iccBufferVINT32_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].x=0;
    p2Buffer->theBuffer[ii].y=0;
    p2Buffer->theBuffer[ii].z=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the VINT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearVINT64( iccBufferVINT64_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].x=0;
    p2Buffer->theBuffer[ii].y=0;
    p2Buffer->theBuffer[ii].z=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the VUNT08 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearVUNT08( iccBufferVUNT08_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].x=0;
    p2Buffer->theBuffer[ii].y=0;
    p2Buffer->theBuffer[ii].z=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the VUNT16 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearVUNT16( iccBufferVUNT16_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].x=0;
    p2Buffer->theBuffer[ii].y=0;
    p2Buffer->theBuffer[ii].z=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the VUNT32 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearVUNT32( iccBufferVUNT32_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].x=0;
    p2Buffer->theBuffer[ii].y=0;
    p2Buffer->theBuffer[ii].z=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
 
// Clear the VUNT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferClearVUNT64( iccBufferVUNT64_t *p2Buffer )
{
//------------------------------- COMMON-CODE     START.
  INT32 ii;

  p2Buffer->index = 0;

  for(ii=0; ii<p2Buffer->size; ii++)
  {
    p2Buffer->theBuffer[ii].x=0;
    p2Buffer->theBuffer[ii].y=0;
    p2Buffer->theBuffer[ii].z=0;
  }
//------------------------------- COMMON-CODE      STOP.
}
