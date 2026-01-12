/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccStackCopy.c
// Desc: This file contains the code for the xccStackCopy routine.
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
PERL_PREPROCESS  if( p2SrcStack->index < 0 ) return -1;  /*Return if Source Stack empty.*/
PERL_PREPROCESS
PERL_PREPROCESS  p2DesStack->index = p2SrcStack->index;  /*Copy the index.*/
PERL_PREPROCESS
PERL_PREPROCESS  for(ii=0; ii<(p2SrcStack->index+1);ii++)/*Copy the data.*/
PERL_PREPROCESS  {
PERL_PREPROCESS    p2DesStack->theStack[ii] = p2SrcStack->theStack[ii];
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  return(0);
#endif
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

/* Pop a value from the FLT32 stack ------------------------------------------*/
INT32 xccStackCopyFLT32( xccStackFLT32_t *p2SrcStack, xccStackFLT32_t *p2DesStack )
{
//COMMON-CODE START.
  INT32 ii;

  if( p2SrcStack->index < 0 ) return -1;  /*Return if Source Stack empty.*/

  p2DesStack->index = p2SrcStack->index;  /*Copy the index.*/

  for(ii=0; ii<(p2SrcStack->index+1);ii++)/*Copy the data.*/
  {
    p2DesStack->theStack[ii] = p2SrcStack->theStack[ii];
  }

  return(0);
//COMMON-CODE  STOP.
}

/* Pop a value from the FLT64 stack ------------------------------------------*/
INT32 xccStackCopyFLT64( xccStackFLT64_t *p2SrcStack, xccStackFLT64_t *p2DesStack )
{
//COMMON-CODE START.
  INT32 ii;

  if( p2SrcStack->index < 0 ) return -1;  /*Return if Source Stack empty.*/

  p2DesStack->index = p2SrcStack->index;  /*Copy the index.*/

  for(ii=0; ii<(p2SrcStack->index+1);ii++)/*Copy the data.*/
  {
    p2DesStack->theStack[ii] = p2SrcStack->theStack[ii];
  }

  return(0);
//COMMON-CODE  STOP.
}
 
/* Pop a value from the FLT96 stack ------------------------------------------*/
INT32 xccStackCopyFLT96( xccStackFLT96_t *p2SrcStack, xccStackFLT96_t *p2DesStack )
{
//COMMON-CODE START.
  INT32 ii;

  if( p2SrcStack->index < 0 ) return -1;  /*Return if Source Stack empty.*/

  p2DesStack->index = p2SrcStack->index;  /*Copy the index.*/

  for(ii=0; ii<(p2SrcStack->index+1);ii++)/*Copy the data.*/
  {
    p2DesStack->theStack[ii] = p2SrcStack->theStack[ii];
  }

  return(0);
//COMMON-CODE  STOP.
}

/* Pop a value from the INT08 stack ------------------------------------------*/
INT32 xccStackCopyINT08( xccStackINT08_t *p2SrcStack, xccStackINT08_t *p2DesStack )
{
//COMMON-CODE START.
  INT32 ii;

  if( p2SrcStack->index < 0 ) return -1;  /*Return if Source Stack empty.*/

  p2DesStack->index = p2SrcStack->index;  /*Copy the index.*/

  for(ii=0; ii<(p2SrcStack->index+1);ii++)/*Copy the data.*/
  {
    p2DesStack->theStack[ii] = p2SrcStack->theStack[ii];
  }

  return(0);
//COMMON-CODE  STOP.
}

/* Pop a value from the INT16 stack ------------------------------------------*/
INT32 xccStackCopyINT16( xccStackINT16_t *p2SrcStack, xccStackINT16_t *p2DesStack )
{
//COMMON-CODE START.
  INT32 ii;

  if( p2SrcStack->index < 0 ) return -1;  /*Return if Source Stack empty.*/

  p2DesStack->index = p2SrcStack->index;  /*Copy the index.*/

  for(ii=0; ii<(p2SrcStack->index+1);ii++)/*Copy the data.*/
  {
    p2DesStack->theStack[ii] = p2SrcStack->theStack[ii];
  }

  return(0);
//COMMON-CODE  STOP.
}
 
/* Pop a value from the INT32 stack ------------------------------------------*/
INT32 xccStackCopyINT32( xccStackINT32_t *p2SrcStack, xccStackINT32_t *p2DesStack )
{
//COMMON-CODE START.
  INT32 ii;

  if( p2SrcStack->index < 0 ) return -1;  /*Return if Source Stack empty.*/

  p2DesStack->index = p2SrcStack->index;  /*Copy the index.*/

  for(ii=0; ii<(p2SrcStack->index+1);ii++)/*Copy the data.*/
  {
    p2DesStack->theStack[ii] = p2SrcStack->theStack[ii];
  }

  return(0);
//COMMON-CODE  STOP.
}
 
/* Pop a value from the INT64 stack ------------------------------------------*/
INT32 xccStackCopyINT64( xccStackINT64_t *p2SrcStack, xccStackINT64_t *p2DesStack )
{
//COMMON-CODE START.
  INT32 ii;

  if( p2SrcStack->index < 0 ) return -1;  /*Return if Source Stack empty.*/

  p2DesStack->index = p2SrcStack->index;  /*Copy the index.*/

  for(ii=0; ii<(p2SrcStack->index+1);ii++)/*Copy the data.*/
  {
    p2DesStack->theStack[ii] = p2SrcStack->theStack[ii];
  }

  return(0);
//COMMON-CODE  STOP.
}
 
/* Pop a value from the UNT08 stack ------------------------------------------*/
INT32 xccStackCopyUNT08( xccStackUNT08_t *p2SrcStack, xccStackUNT08_t *p2DesStack )
{
//COMMON-CODE START.
  INT32 ii;

  if( p2SrcStack->index < 0 ) return -1;  /*Return if Source Stack empty.*/

  p2DesStack->index = p2SrcStack->index;  /*Copy the index.*/

  for(ii=0; ii<(p2SrcStack->index+1);ii++)/*Copy the data.*/
  {
    p2DesStack->theStack[ii] = p2SrcStack->theStack[ii];
  }

  return(0);
//COMMON-CODE  STOP.
}
 
/* Pop a value from the UNT16 stack ------------------------------------------*/
INT32 xccStackCopyUNT16( xccStackUNT16_t *p2SrcStack, xccStackUNT16_t *p2DesStack )
{
//COMMON-CODE START.
  INT32 ii;

  if( p2SrcStack->index < 0 ) return -1;  /*Return if Source Stack empty.*/

  p2DesStack->index = p2SrcStack->index;  /*Copy the index.*/

  for(ii=0; ii<(p2SrcStack->index+1);ii++)/*Copy the data.*/
  {
    p2DesStack->theStack[ii] = p2SrcStack->theStack[ii];
  }

  return(0);
//COMMON-CODE  STOP.
}
 
/* Pop a value from the UNT32 stack ------------------------------------------*/
INT32 xccStackCopyUNT32( xccStackUNT32_t *p2SrcStack, xccStackUNT32_t *p2DesStack )
{
//COMMON-CODE START.
  INT32 ii;

  if( p2SrcStack->index < 0 ) return -1;  /*Return if Source Stack empty.*/

  p2DesStack->index = p2SrcStack->index;  /*Copy the index.*/

  for(ii=0; ii<(p2SrcStack->index+1);ii++)/*Copy the data.*/
  {
    p2DesStack->theStack[ii] = p2SrcStack->theStack[ii];
  }

  return(0);
//COMMON-CODE  STOP.
}
 
/* Pop a value from the UNT64 stack ------------------------------------------*/
INT32 xccStackCopyUNT64( xccStackUNT64_t *p2SrcStack, xccStackUNT64_t *p2DesStack )
{
//COMMON-CODE START.
  INT32 ii;

  if( p2SrcStack->index < 0 ) return -1;  /*Return if Source Stack empty.*/

  p2DesStack->index = p2SrcStack->index;  /*Copy the index.*/

  for(ii=0; ii<(p2SrcStack->index+1);ii++)/*Copy the data.*/
  {
    p2DesStack->theStack[ii] = p2SrcStack->theStack[ii];
  }

  return(0);
//COMMON-CODE  STOP.
}

/* Pop a value from the VOIDP stack ------------------------------------------*/
INT32 xccStackCopyVOIDP( xccStackVOIDP_t *p2SrcStack, xccStackVOIDP_t *p2DesStack )
{
//COMMON-CODE START.
  INT32 ii;

  if( p2SrcStack->index < 0 ) return -1;  /*Return if Source Stack empty.*/

  p2DesStack->index = p2SrcStack->index;  /*Copy the index.*/

  for(ii=0; ii<(p2SrcStack->index+1);ii++)/*Copy the data.*/
  {
    p2DesStack->theStack[ii] = p2SrcStack->theStack[ii];
  }

  return(0);
//COMMON-CODE  STOP.
}
  
/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
