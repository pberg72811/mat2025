/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccStackCopy.c
// Desc: This file contains the code for the iccStackCopy routine.
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
INT32 iccStackCopyFLT32( iccStackFLT32_t *p2SrcStack, iccStackFLT32_t *p2DesStack )
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
INT32 iccStackCopyFLT64( iccStackFLT64_t *p2SrcStack, iccStackFLT64_t *p2DesStack )
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
INT32 iccStackCopyFLT96( iccStackFLT96_t *p2SrcStack, iccStackFLT96_t *p2DesStack )
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
INT32 iccStackCopyINT08( iccStackINT08_t *p2SrcStack, iccStackINT08_t *p2DesStack )
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
INT32 iccStackCopyINT16( iccStackINT16_t *p2SrcStack, iccStackINT16_t *p2DesStack )
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
INT32 iccStackCopyINT32( iccStackINT32_t *p2SrcStack, iccStackINT32_t *p2DesStack )
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
INT32 iccStackCopyINT64( iccStackINT64_t *p2SrcStack, iccStackINT64_t *p2DesStack )
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
INT32 iccStackCopyUNT08( iccStackUNT08_t *p2SrcStack, iccStackUNT08_t *p2DesStack )
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
INT32 iccStackCopyUNT16( iccStackUNT16_t *p2SrcStack, iccStackUNT16_t *p2DesStack )
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
INT32 iccStackCopyUNT32( iccStackUNT32_t *p2SrcStack, iccStackUNT32_t *p2DesStack )
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
INT32 iccStackCopyUNT64( iccStackUNT64_t *p2SrcStack, iccStackUNT64_t *p2DesStack )
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
INT32 iccStackCopyVOIDP( iccStackVOIDP_t *p2SrcStack, iccStackVOIDP_t *p2DesStack )
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
