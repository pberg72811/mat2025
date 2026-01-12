/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccStackClear.c
// Desc: This file contains the code for the iccStackClear routines.
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
VOID iccStackClearFLT32( iccStackFLT32_t *p2Stack )
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
VOID iccStackClearFLT64( iccStackFLT64_t *p2Stack )
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
VOID iccStackClearFLT96( iccStackFLT96_t *p2Stack )
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
VOID iccStackClearINT08( iccStackINT08_t *p2Stack )
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
VOID iccStackClearINT16( iccStackINT16_t *p2Stack )
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
VOID iccStackClearINT32( iccStackINT32_t *p2Stack )
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
VOID iccStackClearINT64( iccStackINT64_t *p2Stack )
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
VOID iccStackClearUNT08( iccStackUNT08_t *p2Stack )
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
VOID iccStackClearUNT16( iccStackUNT16_t *p2Stack )
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
VOID iccStackClearUNT32( iccStackUNT32_t *p2Stack )
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
VOID iccStackClearUNT64( iccStackUNT64_t *p2Stack )
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
VOID iccStackClearVOIDP( iccStackVOIDP_t *p2Stack )
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
