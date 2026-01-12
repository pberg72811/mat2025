/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccStackTop.c
// Desc: This file contains the code for the xccStackTop routines.
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

/* Get the top value of the FLT32 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
FLT32 xccStackTopFLT32(xccStackFLT32_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the FLT64 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
FLT64 xccStackTopFLT64(xccStackFLT64_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the FLT96 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
FLT96 xccStackTopFLT96(xccStackFLT96_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the INT08 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
INT08 xccStackTopINT08(xccStackINT08_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the INT16 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
INT16 xccStackTopINT16(xccStackINT16_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the INT32 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
INT32 xccStackTopINT32(xccStackINT32_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the INT64 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
INT64 xccStackTopINT64(xccStackINT64_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the UNT08 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
UNT08 xccStackTopUNT08(xccStackUNT08_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the UNT16 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
UNT16 xccStackTopUNT16(xccStackUNT16_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the UNT32 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
UNT32 xccStackTopUNT32(xccStackUNT32_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the UNT64 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
UNT64 xccStackTopUNT64(xccStackUNT64_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the VOIDP stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID *xccStackTopVOIDP(xccStackVOIDP_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
