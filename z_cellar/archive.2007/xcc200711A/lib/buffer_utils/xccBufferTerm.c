/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccBufferTerm.c
// Desc: This file contains the code for the xccBufferTerm routines.
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

// Terminate the FLT32 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermFLT32( VOID *a )
{
  xccBufferFLT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the FLT64 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermFLT64( VOID *a )
{
  xccBufferFLT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the FLT96 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermFLT96( VOID *a )
{
  xccBufferFLT96_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the INT08 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermINT08( VOID *a )
{
  xccBufferINT08_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the INT16 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermINT16( VOID *a )
{
  xccBufferINT16_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the INT32 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermINT32( VOID *a )
{
  xccBufferINT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the INT64 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermINT64( VOID *a )
{
  xccBufferINT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the UNT08 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermUNT08( VOID *a )
{
  xccBufferUNT08_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the UNT16 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermUNT16( VOID *a )
{
  xccBufferUNT16_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the UNT32 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermUNT32( VOID *a )
{
  xccBufferUNT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the UNT64 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermUNT64( VOID *a )
{
  xccBufferUNT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VOIDP buffer
//------------------------------------------------------------------------------
VOID xccBufferTermVOIDP( VOID *a )
{
  xccBufferVOIDP_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CFLT32 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermCFLT32( VOID *a )
{
  xccBufferCFLT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CFLT64 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermCFLT64( VOID *a )
{
  xccBufferCFLT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CFLT96 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermCFLT96( VOID *a )
{
  xccBufferCFLT96_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CINT08 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermCINT08( VOID *a )
{
  xccBufferCINT08_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CINT16 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermCINT16( VOID *a )
{
  xccBufferCINT16_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CINT32 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermCINT32( VOID *a )
{
  xccBufferCINT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CINT64 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermCINT64( VOID *a )
{
  xccBufferCINT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CUNT08 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermCUNT08( VOID *a )
{
  xccBufferCUNT08_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CUNT16 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermCUNT16( VOID *a )
{
  xccBufferCUNT16_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CUNT32 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermCUNT32( VOID *a )
{
  xccBufferCUNT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CUNT64 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermCUNT64( VOID *a )
{
  xccBufferCUNT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VFLT32 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermVFLT32( VOID *a )
{
  xccBufferVFLT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VFLT64 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermVFLT64( VOID *a )
{
  xccBufferVFLT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VFLT96 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermVFLT96( VOID *a )
{
  xccBufferVFLT96_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VINT08 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermVINT08( VOID *a )
{
  xccBufferVINT08_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VINT16 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermVINT16( VOID *a )
{
  xccBufferVINT16_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VINT32 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermVINT32( VOID *a )
{
  xccBufferVINT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VINT64 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermVINT64( VOID *a )
{
  xccBufferVINT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VUNT08 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermVUNT08( VOID *a )
{
  xccBufferVUNT08_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VUNT16 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermVUNT16( VOID *a )
{
  xccBufferVUNT16_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VUNT32 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermVUNT32( VOID *a )
{
  xccBufferVUNT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VUNT64 buffer
//------------------------------------------------------------------------------
VOID xccBufferTermVUNT64( VOID *a )
{
  xccBufferVUNT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

 
/*-------------------------------UNCLASSIFIED---------------------------------*/
