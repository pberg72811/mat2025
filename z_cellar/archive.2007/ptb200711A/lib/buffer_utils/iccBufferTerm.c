/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccBufferTerm.c
// Desc: This file contains the code for the iccBufferTerm routines.
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
VOID iccBufferTermFLT32( VOID *a )
{
  iccBufferFLT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the FLT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermFLT64( VOID *a )
{
  iccBufferFLT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the FLT96 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermFLT96( VOID *a )
{
  iccBufferFLT96_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the INT08 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermINT08( VOID *a )
{
  iccBufferINT08_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the INT16 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermINT16( VOID *a )
{
  iccBufferINT16_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the INT32 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermINT32( VOID *a )
{
  iccBufferINT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the INT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermINT64( VOID *a )
{
  iccBufferINT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the UNT08 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermUNT08( VOID *a )
{
  iccBufferUNT08_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the UNT16 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermUNT16( VOID *a )
{
  iccBufferUNT16_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the UNT32 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermUNT32( VOID *a )
{
  iccBufferUNT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the UNT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermUNT64( VOID *a )
{
  iccBufferUNT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VOIDP buffer
//------------------------------------------------------------------------------
VOID iccBufferTermVOIDP( VOID *a )
{
  iccBufferVOIDP_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CFLT32 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermCFLT32( VOID *a )
{
  iccBufferCFLT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CFLT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermCFLT64( VOID *a )
{
  iccBufferCFLT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CFLT96 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermCFLT96( VOID *a )
{
  iccBufferCFLT96_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CINT08 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermCINT08( VOID *a )
{
  iccBufferCINT08_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CINT16 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermCINT16( VOID *a )
{
  iccBufferCINT16_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CINT32 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermCINT32( VOID *a )
{
  iccBufferCINT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CINT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermCINT64( VOID *a )
{
  iccBufferCINT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CUNT08 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermCUNT08( VOID *a )
{
  iccBufferCUNT08_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CUNT16 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermCUNT16( VOID *a )
{
  iccBufferCUNT16_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CUNT32 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermCUNT32( VOID *a )
{
  iccBufferCUNT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the CUNT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermCUNT64( VOID *a )
{
  iccBufferCUNT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VFLT32 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermVFLT32( VOID *a )
{
  iccBufferVFLT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VFLT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermVFLT64( VOID *a )
{
  iccBufferVFLT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VFLT96 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermVFLT96( VOID *a )
{
  iccBufferVFLT96_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VINT08 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermVINT08( VOID *a )
{
  iccBufferVINT08_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VINT16 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermVINT16( VOID *a )
{
  iccBufferVINT16_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VINT32 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermVINT32( VOID *a )
{
  iccBufferVINT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VINT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermVINT64( VOID *a )
{
  iccBufferVINT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VUNT08 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermVUNT08( VOID *a )
{
  iccBufferVUNT08_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VUNT16 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermVUNT16( VOID *a )
{
  iccBufferVUNT16_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VUNT32 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermVUNT32( VOID *a )
{
  iccBufferVUNT32_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

// Terminate the VUNT64 buffer
//------------------------------------------------------------------------------
VOID iccBufferTermVUNT64( VOID *a )
{
  iccBufferVUNT64_t *spec=a;
  xmcFree( spec->theBuffer ); 
  xmcFree( spec ); 
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

 
/*-------------------------------UNCLASSIFIED---------------------------------*/
