/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccBufferClear.c
// Desc: This file contains the code for the xccBufferClear routines.
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
VOID xccBufferClearFLT32( xccBufferFLT32_t *p2Buffer )
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
VOID xccBufferClearFLT64( xccBufferFLT64_t *p2Buffer )
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
VOID xccBufferClearFLT96( xccBufferFLT96_t *p2Buffer )
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
VOID xccBufferClearINT08( xccBufferINT08_t *p2Buffer )
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
VOID xccBufferClearINT16( xccBufferINT16_t *p2Buffer )
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
VOID xccBufferClearINT32( xccBufferINT32_t *p2Buffer )
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
VOID xccBufferClearINT64( xccBufferINT64_t *p2Buffer )
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
VOID xccBufferClearUNT08( xccBufferUNT08_t *p2Buffer )
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
VOID xccBufferClearUNT16( xccBufferUNT16_t *p2Buffer )
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
VOID xccBufferClearUNT32( xccBufferUNT32_t *p2Buffer )
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
VOID xccBufferClearUNT64( xccBufferUNT64_t *p2Buffer )
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
VOID xccBufferClearVOIDP( xccBufferVOIDP_t *p2Buffer )
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
VOID xccBufferClearCFLT32( xccBufferCFLT32_t *p2Buffer )
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
VOID xccBufferClearCFLT64( xccBufferCFLT64_t *p2Buffer )
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
VOID xccBufferClearCFLT96( xccBufferCFLT96_t *p2Buffer )
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
VOID xccBufferClearCINT08( xccBufferCINT08_t *p2Buffer )
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
VOID xccBufferClearCINT16( xccBufferCINT16_t *p2Buffer )
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
VOID xccBufferClearCINT32( xccBufferCINT32_t *p2Buffer )
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
VOID xccBufferClearCINT64( xccBufferCINT64_t *p2Buffer )
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
VOID xccBufferClearCUNT08( xccBufferCUNT08_t *p2Buffer )
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
VOID xccBufferClearCUNT16( xccBufferCUNT16_t *p2Buffer )
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
VOID xccBufferClearCUNT32( xccBufferCUNT32_t *p2Buffer )
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
VOID xccBufferClearCUNT64( xccBufferCUNT64_t *p2Buffer )
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
VOID xccBufferClearVFLT32( xccBufferVFLT32_t *p2Buffer )
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
VOID xccBufferClearVFLT64( xccBufferVFLT64_t *p2Buffer )
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
VOID xccBufferClearVFLT96( xccBufferVFLT96_t *p2Buffer )
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
VOID xccBufferClearVINT08( xccBufferVINT08_t *p2Buffer )
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
VOID xccBufferClearVINT16( xccBufferVINT16_t *p2Buffer )
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
VOID xccBufferClearVINT32( xccBufferVINT32_t *p2Buffer )
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
VOID xccBufferClearVINT64( xccBufferVINT64_t *p2Buffer )
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
VOID xccBufferClearVUNT08( xccBufferVUNT08_t *p2Buffer )
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
VOID xccBufferClearVUNT16( xccBufferVUNT16_t *p2Buffer )
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
VOID xccBufferClearVUNT32( xccBufferVUNT32_t *p2Buffer )
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
VOID xccBufferClearVUNT64( xccBufferVUNT64_t *p2Buffer )
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
