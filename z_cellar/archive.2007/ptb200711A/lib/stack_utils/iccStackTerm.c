/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccStackTerm.c
// Desc: This file contains the code for the iccStackTerm routines.
// Hist: When       Who  What
//       04/27/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "stack_utils.h" 
 
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

// Terminate the FLT32 stack
//------------------------------------------------------------------------------
VOID iccStackTermFLT32(iccStackFLT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the FLT64 stack
//------------------------------------------------------------------------------
VOID iccStackTermFLT64(iccStackFLT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the FLT96 stack
//------------------------------------------------------------------------------
VOID iccStackTermFLT96(iccStackFLT96_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the INT08 stack
//------------------------------------------------------------------------------
VOID iccStackTermINT08(iccStackINT08_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the INT16 stack
//------------------------------------------------------------------------------
VOID iccStackTermINT16(iccStackINT16_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the INT32 stack
//------------------------------------------------------------------------------
VOID iccStackTermINT32(iccStackINT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the INT64 stack
//------------------------------------------------------------------------------
VOID iccStackTermINT64(iccStackINT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the UNT08 stack
//------------------------------------------------------------------------------
VOID iccStackTermUNT08(iccStackUNT08_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the UNT16 stack
//------------------------------------------------------------------------------
VOID iccStackTermUNT16(iccStackUNT16_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the UNT32 stack.
//------------------------------------------------------------------------------
VOID iccStackTermUNT32(iccStackUNT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the UNT64 stack.
//------------------------------------------------------------------------------
VOID iccStackTermUNT64(iccStackUNT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VOIDP stack.
//------------------------------------------------------------------------------
VOID iccStackTermVOIDP(iccStackVOIDP_t *p2WS)
{
  INT32 ii;
  for(ii=0; ii<=p2WS->index; ii++) xmcFree(p2WS->theStack[ii]);
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CFLT32 stack.
//------------------------------------------------------------------------------
VOID iccStackTermCFLT32(iccStackCFLT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CFLT64 stack
//------------------------------------------------------------------------------
VOID iccStackTermCFLT64(iccStackCFLT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CFLT96 stack
//------------------------------------------------------------------------------
VOID iccStackTermCFLT96(iccStackCFLT96_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CINT08 stack
//------------------------------------------------------------------------------
VOID iccStackTermCINT08(iccStackCINT08_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CINT16 stack
//------------------------------------------------------------------------------
VOID iccStackTermCINT16(iccStackCINT16_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CINT32 stack
//------------------------------------------------------------------------------
VOID iccStackTermCINT32(iccStackCINT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CINT64 stack
//------------------------------------------------------------------------------
VOID iccStackTermCINT64(iccStackCINT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CUNT08 stack
//------------------------------------------------------------------------------
VOID iccStackTermCUNT08(iccStackCUNT08_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CUNT16 stack
//------------------------------------------------------------------------------
VOID iccStackTermCUNT16(iccStackCUNT16_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CUNT32 stack
//------------------------------------------------------------------------------
VOID iccStackTermCUNT32(iccStackCUNT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CUNT64 stack
//------------------------------------------------------------------------------
VOID iccStackTermCUNT64(iccStackCUNT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VFLT32 stack
//------------------------------------------------------------------------------
VOID iccStackTermVFLT32(iccStackVFLT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VFLT64 stack
//------------------------------------------------------------------------------
VOID iccStackTermVFLT64(iccStackVFLT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VFLT96 stack
//------------------------------------------------------------------------------
VOID iccStackTermVFLT96(iccStackVFLT96_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VINT08 stack
//------------------------------------------------------------------------------
VOID iccStackTermVINT08(iccStackVINT08_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VINT16 stack
//------------------------------------------------------------------------------
VOID iccStackTermVINT16(iccStackVINT16_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VINT32 stack
//------------------------------------------------------------------------------
VOID iccStackTermVINT32(iccStackVINT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VINT64 stack
//------------------------------------------------------------------------------
VOID iccStackTermVINT64(iccStackVINT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VUNT08 stack
//------------------------------------------------------------------------------
VOID iccStackTermVUNT08(iccStackVUNT08_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VUNT16 stack
//------------------------------------------------------------------------------
VOID iccStackTermVUNT16(iccStackVUNT16_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VUNT32 stack
//------------------------------------------------------------------------------
VOID iccStackTermVUNT32(iccStackVUNT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VUNT64 stack
//------------------------------------------------------------------------------
VOID iccStackTermVUNT64(iccStackVUNT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

/* End preprocessor directives -----------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
