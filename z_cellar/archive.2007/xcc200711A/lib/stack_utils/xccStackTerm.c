/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccStackTerm.c
// Desc: This file contains the code for the xccStackTerm routines.
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
VOID xccStackTermFLT32(xccStackFLT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the FLT64 stack
//------------------------------------------------------------------------------
VOID xccStackTermFLT64(xccStackFLT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the FLT96 stack
//------------------------------------------------------------------------------
VOID xccStackTermFLT96(xccStackFLT96_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the INT08 stack
//------------------------------------------------------------------------------
VOID xccStackTermINT08(xccStackINT08_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the INT16 stack
//------------------------------------------------------------------------------
VOID xccStackTermINT16(xccStackINT16_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the INT32 stack
//------------------------------------------------------------------------------
VOID xccStackTermINT32(xccStackINT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the INT64 stack
//------------------------------------------------------------------------------
VOID xccStackTermINT64(xccStackINT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the UNT08 stack
//------------------------------------------------------------------------------
VOID xccStackTermUNT08(xccStackUNT08_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the UNT16 stack
//------------------------------------------------------------------------------
VOID xccStackTermUNT16(xccStackUNT16_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the UNT32 stack.
//------------------------------------------------------------------------------
VOID xccStackTermUNT32(xccStackUNT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the UNT64 stack.
//------------------------------------------------------------------------------
VOID xccStackTermUNT64(xccStackUNT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VOIDP stack.
//------------------------------------------------------------------------------
VOID xccStackTermVOIDP(xccStackVOIDP_t *p2WS)
{
  INT32 ii;
  for(ii=0; ii<=p2WS->index; ii++) xmcFree(p2WS->theStack[ii]);
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CFLT32 stack.
//------------------------------------------------------------------------------
VOID xccStackTermCFLT32(xccStackCFLT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CFLT64 stack
//------------------------------------------------------------------------------
VOID xccStackTermCFLT64(xccStackCFLT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CFLT96 stack
//------------------------------------------------------------------------------
VOID xccStackTermCFLT96(xccStackCFLT96_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CINT08 stack
//------------------------------------------------------------------------------
VOID xccStackTermCINT08(xccStackCINT08_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CINT16 stack
//------------------------------------------------------------------------------
VOID xccStackTermCINT16(xccStackCINT16_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CINT32 stack
//------------------------------------------------------------------------------
VOID xccStackTermCINT32(xccStackCINT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CINT64 stack
//------------------------------------------------------------------------------
VOID xccStackTermCINT64(xccStackCINT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CUNT08 stack
//------------------------------------------------------------------------------
VOID xccStackTermCUNT08(xccStackCUNT08_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CUNT16 stack
//------------------------------------------------------------------------------
VOID xccStackTermCUNT16(xccStackCUNT16_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CUNT32 stack
//------------------------------------------------------------------------------
VOID xccStackTermCUNT32(xccStackCUNT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the CUNT64 stack
//------------------------------------------------------------------------------
VOID xccStackTermCUNT64(xccStackCUNT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VFLT32 stack
//------------------------------------------------------------------------------
VOID xccStackTermVFLT32(xccStackVFLT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VFLT64 stack
//------------------------------------------------------------------------------
VOID xccStackTermVFLT64(xccStackVFLT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VFLT96 stack
//------------------------------------------------------------------------------
VOID xccStackTermVFLT96(xccStackVFLT96_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VINT08 stack
//------------------------------------------------------------------------------
VOID xccStackTermVINT08(xccStackVINT08_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VINT16 stack
//------------------------------------------------------------------------------
VOID xccStackTermVINT16(xccStackVINT16_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VINT32 stack
//------------------------------------------------------------------------------
VOID xccStackTermVINT32(xccStackVINT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VINT64 stack
//------------------------------------------------------------------------------
VOID xccStackTermVINT64(xccStackVINT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VUNT08 stack
//------------------------------------------------------------------------------
VOID xccStackTermVUNT08(xccStackVUNT08_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VUNT16 stack
//------------------------------------------------------------------------------
VOID xccStackTermVUNT16(xccStackVUNT16_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VUNT32 stack
//------------------------------------------------------------------------------
VOID xccStackTermVUNT32(xccStackVUNT32_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// Terminate the VUNT64 stack
//------------------------------------------------------------------------------
VOID xccStackTermVUNT64(xccStackVUNT64_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

/* End preprocessor directives -----------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
