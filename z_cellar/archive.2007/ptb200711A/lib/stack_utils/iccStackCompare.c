/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccStackCompare.c
// Desc: This file contains the code for the iccStackCompare routine.
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
PERL_PREPROCESS  INT32 ii=0;
PERL_PREPROCESS  INT32 tally=0;
PERL_PREPROCESS  INT32 total=0;
PERL_PREPROCESS
PERL_PREPROCESS  if( p2Stack1->index < 0 ) return -1;   /*Return if Stack1 empty.*/
PERL_PREPROCESS  if( p2Stack2->index < 0 ) return -1;   /*Return if Stack2 empty.*/
PERL_PREPROCESS  if( p2Stack1->index > p2Stack2->index ) total = p2Stack2->index+1;
PERL_PREPROCESS  else                                    total = p2Stack1->index+1;
PERL_PREPROCESS
PERL_PREPROCESS  for(ii=0; ii<total; ii++) /*Compare the data.*/
PERL_PREPROCESS  {
PERL_PREPROCESS    if (p2Stack2->theStack[ii] == p2Stack1->theStack[ii]) tally++;
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  return(tally);
#endif
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

/* Compare the values of two FLT32 stacks ------------------------------------*/
INT32 iccStackCompareFLT32( iccStackFLT32_t *p2Stack1, iccStackFLT32_t *p2Stack2 )
{
//COMMON-CODE START.
  INT32 ii=0;
  INT32 tally=0;
  INT32 total=0;

  if( p2Stack1->index < 0 ) return -1;   /*Return if Stack1 empty.*/
  if( p2Stack2->index < 0 ) return -1;   /*Return if Stack2 empty.*/
  if( p2Stack1->index > p2Stack2->index ) total = p2Stack2->index+1;
  else                                    total = p2Stack1->index+1;

  for(ii=0; ii<total; ii++) /*Compare the data.*/
  {
    if (p2Stack2->theStack[ii] == p2Stack1->theStack[ii]) tally++;
  }

  return(tally);
//COMMON-CODE  STOP.
}

/* Compare the values of two FLT64 stacks ------------------------------------*/
INT32 iccStackCompareFLT64( iccStackFLT64_t *p2Stack1, iccStackFLT64_t *p2Stack2 )
{
//COMMON-CODE START.
  INT32 ii=0;
  INT32 tally=0;
  INT32 total=0;

  if( p2Stack1->index < 0 ) return -1;   /*Return if Stack1 empty.*/
  if( p2Stack2->index < 0 ) return -1;   /*Return if Stack2 empty.*/
  if( p2Stack1->index > p2Stack2->index ) total = p2Stack2->index+1;
  else                                    total = p2Stack1->index+1;

  for(ii=0; ii<total; ii++) /*Compare the data.*/
  {
    if (p2Stack2->theStack[ii] == p2Stack1->theStack[ii]) tally++;
  }

  return(tally);
//COMMON-CODE  STOP.
}
 
/* Compare the values of two FLT96 stacks ------------------------------------*/
INT32 iccStackCompareFLT96( iccStackFLT96_t *p2Stack1, iccStackFLT96_t *p2Stack2 )
{
//COMMON-CODE START.
  INT32 ii=0;
  INT32 tally=0;
  INT32 total=0;

  if( p2Stack1->index < 0 ) return -1;   /*Return if Stack1 empty.*/
  if( p2Stack2->index < 0 ) return -1;   /*Return if Stack2 empty.*/
  if( p2Stack1->index > p2Stack2->index ) total = p2Stack2->index+1;
  else                                    total = p2Stack1->index+1;

  for(ii=0; ii<total; ii++) /*Compare the data.*/
  {
    if (p2Stack2->theStack[ii] == p2Stack1->theStack[ii]) tally++;
  }

  return(tally);
//COMMON-CODE  STOP.
}

/* Compare the values of two INT08 stacks ------------------------------------*/
INT32 iccStackCompareINT08( iccStackINT08_t *p2Stack1, iccStackINT08_t *p2Stack2 )
{
//COMMON-CODE START.
  INT32 ii=0;
  INT32 tally=0;
  INT32 total=0;

  if( p2Stack1->index < 0 ) return -1;   /*Return if Stack1 empty.*/
  if( p2Stack2->index < 0 ) return -1;   /*Return if Stack2 empty.*/
  if( p2Stack1->index > p2Stack2->index ) total = p2Stack2->index+1;
  else                                    total = p2Stack1->index+1;

  for(ii=0; ii<total; ii++) /*Compare the data.*/
  {
    if (p2Stack2->theStack[ii] == p2Stack1->theStack[ii]) tally++;
  }

  return(tally);
//COMMON-CODE  STOP.
}

/* Compare the values of two INT16 stacks ------------------------------------*/
INT32 iccStackCompareINT16( iccStackINT16_t *p2Stack1, iccStackINT16_t *p2Stack2 )
{
//COMMON-CODE START.
  INT32 ii=0;
  INT32 tally=0;
  INT32 total=0;

  if( p2Stack1->index < 0 ) return -1;   /*Return if Stack1 empty.*/
  if( p2Stack2->index < 0 ) return -1;   /*Return if Stack2 empty.*/
  if( p2Stack1->index > p2Stack2->index ) total = p2Stack2->index+1;
  else                                    total = p2Stack1->index+1;

  for(ii=0; ii<total; ii++) /*Compare the data.*/
  {
    if (p2Stack2->theStack[ii] == p2Stack1->theStack[ii]) tally++;
  }

  return(tally);
//COMMON-CODE  STOP.
}
 
/* Compare the values of two INT32 stacks ------------------------------------*/
INT32 iccStackCompareINT32( iccStackINT32_t *p2Stack1, iccStackINT32_t *p2Stack2 )
{
//COMMON-CODE START.
  INT32 ii=0;
  INT32 tally=0;
  INT32 total=0;

  if( p2Stack1->index < 0 ) return -1;   /*Return if Stack1 empty.*/
  if( p2Stack2->index < 0 ) return -1;   /*Return if Stack2 empty.*/
  if( p2Stack1->index > p2Stack2->index ) total = p2Stack2->index+1;
  else                                    total = p2Stack1->index+1;

  for(ii=0; ii<total; ii++) /*Compare the data.*/
  {
    if (p2Stack2->theStack[ii] == p2Stack1->theStack[ii]) tally++;
  }

  return(tally);
//COMMON-CODE  STOP.
}
 
/* Compare the values of two INT64 stacks ------------------------------------*/
INT32 iccStackCompareINT64( iccStackINT64_t *p2Stack1, iccStackINT64_t *p2Stack2 )
{
//COMMON-CODE START.
  INT32 ii=0;
  INT32 tally=0;
  INT32 total=0;

  if( p2Stack1->index < 0 ) return -1;   /*Return if Stack1 empty.*/
  if( p2Stack2->index < 0 ) return -1;   /*Return if Stack2 empty.*/
  if( p2Stack1->index > p2Stack2->index ) total = p2Stack2->index+1;
  else                                    total = p2Stack1->index+1;

  for(ii=0; ii<total; ii++) /*Compare the data.*/
  {
    if (p2Stack2->theStack[ii] == p2Stack1->theStack[ii]) tally++;
  }

  return(tally);
//COMMON-CODE  STOP.
}
 
/* Compare the values of two UNT08 stacks ------------------------------------*/
INT32 iccStackCompareUNT08( iccStackUNT08_t *p2Stack1, iccStackUNT08_t *p2Stack2 )
{
//COMMON-CODE START.
  INT32 ii=0;
  INT32 tally=0;
  INT32 total=0;

  if( p2Stack1->index < 0 ) return -1;   /*Return if Stack1 empty.*/
  if( p2Stack2->index < 0 ) return -1;   /*Return if Stack2 empty.*/
  if( p2Stack1->index > p2Stack2->index ) total = p2Stack2->index+1;
  else                                    total = p2Stack1->index+1;

  for(ii=0; ii<total; ii++) /*Compare the data.*/
  {
    if (p2Stack2->theStack[ii] == p2Stack1->theStack[ii]) tally++;
  }

  return(tally);
//COMMON-CODE  STOP.
}
 
/* Compare the values of two UNT16 stacks ------------------------------------*/
INT32 iccStackCompareUNT16( iccStackUNT16_t *p2Stack1, iccStackUNT16_t *p2Stack2 )
{
//COMMON-CODE START.
  INT32 ii=0;
  INT32 tally=0;
  INT32 total=0;

  if( p2Stack1->index < 0 ) return -1;   /*Return if Stack1 empty.*/
  if( p2Stack2->index < 0 ) return -1;   /*Return if Stack2 empty.*/
  if( p2Stack1->index > p2Stack2->index ) total = p2Stack2->index+1;
  else                                    total = p2Stack1->index+1;

  for(ii=0; ii<total; ii++) /*Compare the data.*/
  {
    if (p2Stack2->theStack[ii] == p2Stack1->theStack[ii]) tally++;
  }

  return(tally);
//COMMON-CODE  STOP.
}
 
/* Compare the values of two UNT32 stacks ------------------------------------*/
INT32 iccStackCompareUNT32( iccStackUNT32_t *p2Stack1, iccStackUNT32_t *p2Stack2 )
{
//COMMON-CODE START.
  INT32 ii=0;
  INT32 tally=0;
  INT32 total=0;

  if( p2Stack1->index < 0 ) return -1;   /*Return if Stack1 empty.*/
  if( p2Stack2->index < 0 ) return -1;   /*Return if Stack2 empty.*/
  if( p2Stack1->index > p2Stack2->index ) total = p2Stack2->index+1;
  else                                    total = p2Stack1->index+1;

  for(ii=0; ii<total; ii++) /*Compare the data.*/
  {
    if (p2Stack2->theStack[ii] == p2Stack1->theStack[ii]) tally++;
  }

  return(tally);
//COMMON-CODE  STOP.
}
 
/* Compare the values of two UNT64 stacks ------------------------------------*/
INT32 iccStackCompareUNT64( iccStackUNT64_t *p2Stack1, iccStackUNT64_t *p2Stack2 )
{
//COMMON-CODE START.
  INT32 ii=0;
  INT32 tally=0;
  INT32 total=0;

  if( p2Stack1->index < 0 ) return -1;   /*Return if Stack1 empty.*/
  if( p2Stack2->index < 0 ) return -1;   /*Return if Stack2 empty.*/
  if( p2Stack1->index > p2Stack2->index ) total = p2Stack2->index+1;
  else                                    total = p2Stack1->index+1;

  for(ii=0; ii<total; ii++) /*Compare the data.*/
  {
    if (p2Stack2->theStack[ii] == p2Stack1->theStack[ii]) tally++;
  }

  return(tally);
//COMMON-CODE  STOP.
}

/* Compare the values of two VOIDP stacks ------------------------------------*/
INT32 iccStackCompareVOIDP( iccStackVOIDP_t *p2Stack1, iccStackVOIDP_t *p2Stack2 )
{
//COMMON-CODE START.
  INT32 ii=0;
  INT32 tally=0;
  INT32 total=0;

  if( p2Stack1->index < 0 ) return -1;   /*Return if Stack1 empty.*/
  if( p2Stack2->index < 0 ) return -1;   /*Return if Stack2 empty.*/
  if( p2Stack1->index > p2Stack2->index ) total = p2Stack2->index+1;
  else                                    total = p2Stack1->index+1;

  for(ii=0; ii<total; ii++) /*Compare the data.*/
  {
    if (p2Stack2->theStack[ii] == p2Stack1->theStack[ii]) tally++;
  }

  return(tally);
//COMMON-CODE  STOP.
}
  
/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
