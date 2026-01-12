/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccStackFlip.c
// Desc: This file contains the code for the iccStackFlip routines.
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
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX t1;
PERL_PREPROCESS  XXXXX t2;
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS  INT32 midPoint;
PERL_PREPROCESS
PERL_PREPROCESS  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */
PERL_PREPROCESS
PERL_PREPROCESS  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/
PERL_PREPROCESS
PERL_PREPROCESS  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
PERL_PREPROCESS  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */
PERL_PREPROCESS
PERL_PREPROCESS  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
PERL_PREPROCESS  {
PERL_PREPROCESS    t1 = p2Stack->theStack[ii];
PERL_PREPROCESS    t2 = p2Stack->theStack[p2Stack->index-ii];
PERL_PREPROCESS    p2Stack->theStack[ii] = t2;
PERL_PREPROCESS    p2Stack->theStack[p2Stack->index-ii]=t1;
PERL_PREPROCESS  }
PERL_PREPROCESS  return(0);                 
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

INT32 iccStackFlipFLT32( iccStackFLT32_t *p2Stack )
{
//------------------------------- COMMON-CODE FLT32 START.
  FLT32 t1;
  FLT32 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE FLT32  STOP.
}

INT32 iccStackFlipFLT64( iccStackFLT64_t *p2Stack )
{
//------------------------------- COMMON-CODE FLT64 START.
  FLT64 t1;
  FLT64 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE FLT64  STOP.
}

INT32 iccStackFlipFLT96( iccStackFLT96_t *p2Stack )
{
//------------------------------- COMMON-CODE FLT96 START.
  FLT96 t1;
  FLT96 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE FLT96  STOP.
}

INT32 iccStackFlipINT08( iccStackINT08_t *p2Stack )
{
//------------------------------- COMMON-CODE INT08 START.
  INT08 t1;
  INT08 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE INT08  STOP.
}

INT32 iccStackFlipINT16( iccStackINT16_t *p2Stack )
{
//------------------------------- COMMON-CODE INT16 START.
  INT16 t1;
  INT16 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE INT16  STOP.
}

 
INT32 iccStackFlipINT32( iccStackINT32_t *p2Stack )
{
//------------------------------- COMMON-CODE INT32 START.
  INT32 t1;
  INT32 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE INT32  STOP.
}
 
INT32 iccStackFlipINT64( iccStackINT64_t *p2Stack )
{
//------------------------------- COMMON-CODE INT64 START.
  INT64 t1;
  INT64 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE INT64  STOP.
}
 
INT32 iccStackFlipUNT08( iccStackUNT08_t *p2Stack )
{
//------------------------------- COMMON-CODE UNT08 START.
  UNT08 t1;
  UNT08 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE UNT08  STOP.
}
 
INT32 iccStackFlipUNT16( iccStackUNT16_t *p2Stack )
{
//------------------------------- COMMON-CODE UNT16 START.
  UNT16 t1;
  UNT16 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE UNT16  STOP.
}

 
INT32 iccStackFlipUNT32( iccStackUNT32_t *p2Stack )
{
//------------------------------- COMMON-CODE UNT32 START.
  UNT32 t1;
  UNT32 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE UNT32  STOP.
}

 
INT32 iccStackFlipUNT64( iccStackUNT64_t *p2Stack )
{
//------------------------------- COMMON-CODE UNT64 START.
  UNT64 t1;
  UNT64 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE UNT64  STOP.
}


#define VOIDP VOID *

INT32 iccStackFlipVOIDP( iccStackVOIDP_t *p2Stack )
{
//------------------------------- COMMON-CODE VOIDP START.
  VOIDP t1;
  VOIDP t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE VOIDP  STOP.
}

INT32 iccStackFlipCFLT32( iccStackCFLT32_t *p2Stack )
{
//------------------------------- COMMON-CODE CFLT32 START.
  CFLT32 t1;
  CFLT32 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE CFLT32  STOP.
}

INT32 iccStackFlipCFLT64( iccStackCFLT64_t *p2Stack )
{
//------------------------------- COMMON-CODE CFLT64 START.
  CFLT64 t1;
  CFLT64 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE CFLT64  STOP.
}

INT32 iccStackFlipCFLT96( iccStackCFLT96_t *p2Stack )
{
//------------------------------- COMMON-CODE CFLT96 START.
  CFLT96 t1;
  CFLT96 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE CFLT96  STOP.
}

INT32 iccStackFlipCINT08( iccStackCINT08_t *p2Stack )
{
//------------------------------- COMMON-CODE CINT08 START.
  CINT08 t1;
  CINT08 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE CINT08  STOP.
}

INT32 iccStackFlipCINT16( iccStackCINT16_t *p2Stack )
{
//------------------------------- COMMON-CODE CINT16 START.
  CINT16 t1;
  CINT16 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE CINT16  STOP.
}

 
INT32 iccStackFlipCINT32( iccStackCINT32_t *p2Stack )
{
//------------------------------- COMMON-CODE CINT32 START.
  CINT32 t1;
  CINT32 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE CINT32  STOP.
}
 
INT32 iccStackFlipCINT64( iccStackCINT64_t *p2Stack )
{
//------------------------------- COMMON-CODE CINT64 START.
  CINT64 t1;
  CINT64 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE CINT64  STOP.
}
 
INT32 iccStackFlipCUNT08( iccStackCUNT08_t *p2Stack )
{
//------------------------------- COMMON-CODE CUNT08 START.
  CUNT08 t1;
  CUNT08 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE CUNT08  STOP.
}
 
INT32 iccStackFlipCUNT16( iccStackCUNT16_t *p2Stack )
{
//------------------------------- COMMON-CODE CUNT16 START.
  CUNT16 t1;
  CUNT16 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE CUNT16  STOP.
}

 
INT32 iccStackFlipCUNT32( iccStackCUNT32_t *p2Stack )
{
//------------------------------- COMMON-CODE CUNT32 START.
  CUNT32 t1;
  CUNT32 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE CUNT32  STOP.
}

 
INT32 iccStackFlipCUNT64( iccStackCUNT64_t *p2Stack )
{
//------------------------------- COMMON-CODE CUNT64 START.
  CUNT64 t1;
  CUNT64 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE CUNT64  STOP.
}


INT32 iccStackFlipVFLT32( iccStackVFLT32_t *p2Stack )
{
//------------------------------- COMMON-CODE VFLT32 START.
  VFLT32 t1;
  VFLT32 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE VFLT32  STOP.
}

INT32 iccStackFlipVFLT64( iccStackVFLT64_t *p2Stack )
{
//------------------------------- COMMON-CODE VFLT64 START.
  VFLT64 t1;
  VFLT64 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE VFLT64  STOP.
}

INT32 iccStackFlipVFLT96( iccStackVFLT96_t *p2Stack )
{
//------------------------------- COMMON-CODE VFLT96 START.
  VFLT96 t1;
  VFLT96 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE VFLT96  STOP.
}

INT32 iccStackFlipVINT08( iccStackVINT08_t *p2Stack )
{
//------------------------------- COMMON-CODE VINT08 START.
  VINT08 t1;
  VINT08 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE VINT08  STOP.
}

INT32 iccStackFlipVINT16( iccStackVINT16_t *p2Stack )
{
//------------------------------- COMMON-CODE VINT16 START.
  VINT16 t1;
  VINT16 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE VINT16  STOP.
}

INT32 iccStackFlipVINT32( iccStackVINT32_t *p2Stack )
{
//------------------------------- COMMON-CODE VINT32 START.
  VINT32 t1;
  VINT32 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE VINT32  STOP.
}
 
INT32 iccStackFlipVINT64( iccStackVINT64_t *p2Stack )
{
//------------------------------- COMMON-CODE VINT64 START.
  VINT64 t1;
  VINT64 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE VINT64  STOP.
}
 
INT32 iccStackFlipVUNT08( iccStackVUNT08_t *p2Stack )
{
//------------------------------- COMMON-CODE VUNT08 START.
  VUNT08 t1;
  VUNT08 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE VUNT08  STOP.
}
 
INT32 iccStackFlipVUNT16( iccStackVUNT16_t *p2Stack )
{
//------------------------------- COMMON-CODE VUNT16 START.
  VUNT16 t1;
  VUNT16 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE VUNT16  STOP.
}

 
INT32 iccStackFlipVUNT32( iccStackVUNT32_t *p2Stack )
{
//------------------------------- COMMON-CODE VUNT32 START.
  VUNT32 t1;
  VUNT32 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE VUNT32  STOP.
}

 
INT32 iccStackFlipVUNT64( iccStackVUNT64_t *p2Stack )
{
//------------------------------- COMMON-CODE VUNT64 START.
  VUNT64 t1;
  VUNT64 t2;
  INT32 ii;
  INT32 midPoint;

  if(p2Stack->index==-1) return(-1); /* Can't reverse an empty stack.     */

  if(p2Stack->index== 0) return( 0); /* Reverse single element is a no op.*/

  if((p2Stack->index%2)==0) midPoint = p2Stack->index/2;    /*If index is even.*/
  else                      midPoint = (p2Stack->index+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = p2Stack->theStack[ii];
    t2 = p2Stack->theStack[p2Stack->index-ii];
    p2Stack->theStack[ii] = t2;
    p2Stack->theStack[p2Stack->index-ii]=t1;
  }
  return(0);                 
//------------------------------- COMMON-CODE VUNT64  STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
