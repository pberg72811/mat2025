/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccStackTop.c
// Desc: This file contains the code for the iccStackTop routines.
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
FLT32 iccStackTopFLT32(iccStackFLT32_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the FLT64 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
FLT64 iccStackTopFLT64(iccStackFLT64_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the FLT96 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
FLT96 iccStackTopFLT96(iccStackFLT96_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the INT08 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
INT08 iccStackTopINT08(iccStackINT08_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the INT16 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
INT16 iccStackTopINT16(iccStackINT16_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the INT32 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
INT32 iccStackTopINT32(iccStackINT32_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the INT64 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
INT64 iccStackTopINT64(iccStackINT64_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the UNT08 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
UNT08 iccStackTopUNT08(iccStackUNT08_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the UNT16 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
UNT16 iccStackTopUNT16(iccStackUNT16_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the UNT32 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
UNT32 iccStackTopUNT32(iccStackUNT32_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the UNT64 stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
UNT64 iccStackTopUNT64(iccStackUNT64_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* Get the top value of the VOIDP stack --------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID *iccStackTopVOIDP(iccStackVOIDP_t *p2Stack)
{
  return( p2Stack->theStack[p2Stack->index] ); 
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
