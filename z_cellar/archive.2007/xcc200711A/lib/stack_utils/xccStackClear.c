/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccStackClear.c
// Desc: This file contains the code for the xccStackClear routines.
// Hist: When       Who  What
//       05/01/2001 ptb  Initial Code.
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
#if 0
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS
PERL_PREPROCESS  p2Stack->index = -1;
PERL_PREPROCESS
PERL_PREPROCESS  for(ii=0; ii<p2Stack->size; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    p2Stack->theStack[ii]=0;
PERL_PREPROCESS  }
#endif
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

/* Clear the FLT32 stack -----------------------------------------------------*/
VOID xccStackClearFLT32( xccStackFLT32_t *p2Stack )
{
//COMMON-CODE START.
  INT32 ii;

  p2Stack->index = -1;

  for(ii=0; ii<p2Stack->size; ii++)
  {
    p2Stack->theStack[ii]=0;
  }
//COMMON-CODE  STOP.
}

/* Clear the FLT64 stack -----------------------------------------------------*/
VOID xccStackClearFLT64( xccStackFLT64_t *p2Stack )
{
//COMMON-CODE START.
  INT32 ii;

  p2Stack->index = -1;

  for(ii=0; ii<p2Stack->size; ii++)
  {
    p2Stack->theStack[ii]=0;
  }
//COMMON-CODE  STOP.
}

/* Clear the FLT96 stack -----------------------------------------------------*/
VOID xccStackClearFLT96( xccStackFLT96_t *p2Stack )
{
//COMMON-CODE START.
  INT32 ii;

  p2Stack->index = -1;

  for(ii=0; ii<p2Stack->size; ii++)
  {
    p2Stack->theStack[ii]=0;
  }
//COMMON-CODE  STOP.
}

/* Clear the INT08 stack -----------------------------------------------------*/
VOID xccStackClearINT08( xccStackINT08_t *p2Stack )
{
//COMMON-CODE START.
  INT32 ii;

  p2Stack->index = -1;

  for(ii=0; ii<p2Stack->size; ii++)
  {
    p2Stack->theStack[ii]=0;
  }
//COMMON-CODE  STOP.
}

/* Clear the INT16 stack -----------------------------------------------------*/
VOID xccStackClearINT16( xccStackINT16_t *p2Stack )
{
//COMMON-CODE START.
  INT32 ii;

  p2Stack->index = -1;

  for(ii=0; ii<p2Stack->size; ii++)
  {
    p2Stack->theStack[ii]=0;
  }
//COMMON-CODE  STOP.
}
 
/* Clear the INT32 stack -----------------------------------------------------*/
VOID xccStackClearINT32( xccStackINT32_t *p2Stack )
{
//COMMON-CODE START.
  INT32 ii;

  p2Stack->index = -1;

  for(ii=0; ii<p2Stack->size; ii++)
  {
    p2Stack->theStack[ii]=0;
  }
//COMMON-CODE  STOP.
}
 
/* Clear the INT64 stack -----------------------------------------------------*/
VOID xccStackClearINT64( xccStackINT64_t *p2Stack )
{
//COMMON-CODE START.
  INT32 ii;

  p2Stack->index = -1;

  for(ii=0; ii<p2Stack->size; ii++)
  {
    p2Stack->theStack[ii]=0;
  }
//COMMON-CODE  STOP.
}
 
/* Clear the UNT08 stack -----------------------------------------------------*/
VOID xccStackClearUNT08( xccStackUNT08_t *p2Stack )
{
//COMMON-CODE START.
  INT32 ii;

  p2Stack->index = -1;

  for(ii=0; ii<p2Stack->size; ii++)
  {
    p2Stack->theStack[ii]=0;
  }
//COMMON-CODE  STOP.
}
 
/* Clear the UNT16 stack -----------------------------------------------------*/
VOID xccStackClearUNT16( xccStackUNT16_t *p2Stack )
{
//COMMON-CODE START.
  INT32 ii;

  p2Stack->index = -1;

  for(ii=0; ii<p2Stack->size; ii++)
  {
    p2Stack->theStack[ii]=0;
  }
//COMMON-CODE  STOP.
}
 
/* Clear the UNT32 stack -----------------------------------------------------*/
VOID xccStackClearUNT32( xccStackUNT32_t *p2Stack )
{
//COMMON-CODE START.
  INT32 ii;

  p2Stack->index = -1;

  for(ii=0; ii<p2Stack->size; ii++)
  {
    p2Stack->theStack[ii]=0;
  }
//COMMON-CODE  STOP.
}
 
/* Clear the UNT64 stack -----------------------------------------------------*/
VOID xccStackClearUNT64( xccStackUNT64_t *p2Stack )
{
//COMMON-CODE START.
  INT32 ii;

  p2Stack->index = -1;

  for(ii=0; ii<p2Stack->size; ii++)
  {
    p2Stack->theStack[ii]=0;
  }
//COMMON-CODE  STOP.
}

/* Clear the VOIDP stack -----------------------------------------------------*/
VOID xccStackClearVOIDP( xccStackVOIDP_t *p2Stack )
{
//COMMON-CODE START.
  INT32 ii;

  p2Stack->index = -1;

  for(ii=0; ii<p2Stack->size; ii++)
  {
    p2Stack->theStack[ii]=0;
  }
//COMMON-CODE  STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
