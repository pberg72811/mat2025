/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvFlip.c
// Desc: This file contains the code for the iccvFlip routines.
// Hist: When       Who  What
//       11/20/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "vector_utils.h" 
 
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
PERL_PREPROCESS  XXXXX *pa=(XXXXX *)a;
PERL_PREPROCESS  XXXXX *pb=(XXXXX *)b;
PERL_PREPROCESS  INT32 m=n-1;
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS  INT32 midPoint;
PERL_PREPROCESS
PERL_PREPROCESS  if(n==1) return; /* Flipping a single element is a no op.*/
PERL_PREPROCESS
PERL_PREPROCESS  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
PERL_PREPROCESS  else         midPoint = (n+1)/2;/*If index is odd. */
PERL_PREPROCESS
PERL_PREPROCESS  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
PERL_PREPROCESS  {
PERL_PREPROCESS    t1 = pa[ii];
PERL_PREPROCESS    t2 = pa[m-ii];
PERL_PREPROCESS    pb[ii] = t2;
PERL_PREPROCESS    pb[m-ii]=t1;
PERL_PREPROCESS  }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccvFlipFLT32( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32    START.
  FLT32 t1;
  FLT32 t2;
  FLT32 *pa=(FLT32 *)a;
  FLT32 *pb=(FLT32 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE FLT32     STOP.
}

VOID iccvFlipFLT64( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64    START.
  FLT64 t1;
  FLT64 t2;
  FLT64 *pa=(FLT64 *)a;
  FLT64 *pb=(FLT64 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE FLT64     STOP.
}

VOID iccvFlipFLT96( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96    START.
  FLT96 t1;
  FLT96 t2;
  FLT96 *pa=(FLT96 *)a;
  FLT96 *pb=(FLT96 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE FLT96     STOP.
}

VOID iccvFlipINT08( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE INT08    START.
  INT08 t1;
  INT08 t2;
  INT08 *pa=(INT08 *)a;
  INT08 *pb=(INT08 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE INT08     STOP.
}

VOID iccvFlipINT16( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE INT16    START.
  INT16 t1;
  INT16 t2;
  INT16 *pa=(INT16 *)a;
  INT16 *pb=(INT16 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE INT16     STOP.
}

VOID iccvFlipINT32( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE INT32    START.
  INT32 t1;
  INT32 t2;
  INT32 *pa=(INT32 *)a;
  INT32 *pb=(INT32 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE INT32     STOP.
}

VOID iccvFlipINT64( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE INT64    START.
  INT64 t1;
  INT64 t2;
  INT64 *pa=(INT64 *)a;
  INT64 *pb=(INT64 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE INT64     STOP.
}
VOID iccvFlipUNT08( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE UNT08    START.
  UNT08 t1;
  UNT08 t2;
  UNT08 *pa=(UNT08 *)a;
  UNT08 *pb=(UNT08 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE UNT08     STOP.
}

VOID iccvFlipUNT16( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE UNT16    START.
  UNT16 t1;
  UNT16 t2;
  UNT16 *pa=(UNT16 *)a;
  UNT16 *pb=(UNT16 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE UNT16     STOP.
}

VOID iccvFlipUNT32( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE UNT32    START.
  UNT32 t1;
  UNT32 t2;
  UNT32 *pa=(UNT32 *)a;
  UNT32 *pb=(UNT32 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE UNT32     STOP.
}

VOID iccvFlipUNT64( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE UNT64    START.
  UNT64 t1;
  UNT64 t2;
  UNT64 *pa=(UNT64 *)a;
  UNT64 *pb=(UNT64 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE UNT64     STOP.
}

VOID iccvFlipCFLT32( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT32    START.
  CFLT32 t1;
  CFLT32 t2;
  CFLT32 *pa=(CFLT32 *)a;
  CFLT32 *pb=(CFLT32 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE CFLT32     STOP.
}

VOID iccvFlipCFLT64( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT64    START.
  CFLT64 t1;
  CFLT64 t2;
  CFLT64 *pa=(CFLT64 *)a;
  CFLT64 *pb=(CFLT64 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE CFLT64     STOP.
}

VOID iccvFlipCFLT96( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT96    START.
  CFLT96 t1;
  CFLT96 t2;
  CFLT96 *pa=(CFLT96 *)a;
  CFLT96 *pb=(CFLT96 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE CFLT96     STOP.
}

VOID iccvFlipCINT08( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE CINT08    START.
  CINT08 t1;
  CINT08 t2;
  CINT08 *pa=(CINT08 *)a;
  CINT08 *pb=(CINT08 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE CINT08     STOP.
}

VOID iccvFlipCINT16( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE CINT16    START.
  CINT16 t1;
  CINT16 t2;
  CINT16 *pa=(CINT16 *)a;
  CINT16 *pb=(CINT16 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE CINT16     STOP.
}

VOID iccvFlipCINT32( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE CINT32    START.
  CINT32 t1;
  CINT32 t2;
  CINT32 *pa=(CINT32 *)a;
  CINT32 *pb=(CINT32 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE CINT32     STOP.
}

VOID iccvFlipCINT64( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE CINT64    START.
  CINT64 t1;
  CINT64 t2;
  CINT64 *pa=(CINT64 *)a;
  CINT64 *pb=(CINT64 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE CINT64     STOP.
}
VOID iccvFlipCUNT08( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT08    START.
  CUNT08 t1;
  CUNT08 t2;
  CUNT08 *pa=(CUNT08 *)a;
  CUNT08 *pb=(CUNT08 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE CUNT08     STOP.
}

VOID iccvFlipCUNT16( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT16    START.
  CUNT16 t1;
  CUNT16 t2;
  CUNT16 *pa=(CUNT16 *)a;
  CUNT16 *pb=(CUNT16 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE CUNT16     STOP.
}

VOID iccvFlipCUNT32( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT32    START.
  CUNT32 t1;
  CUNT32 t2;
  CUNT32 *pa=(CUNT32 *)a;
  CUNT32 *pb=(CUNT32 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE CUNT32     STOP.
}

VOID iccvFlipCUNT64( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT64    START.
  CUNT64 t1;
  CUNT64 t2;
  CUNT64 *pa=(CUNT64 *)a;
  CUNT64 *pb=(CUNT64 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE CUNT64     STOP.
}

VOID iccvFlipVFLT32( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE VFLT32    START.
  VFLT32 t1;
  VFLT32 t2;
  VFLT32 *pa=(VFLT32 *)a;
  VFLT32 *pb=(VFLT32 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE VFLT32     STOP.
}

VOID iccvFlipVFLT64( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE VFLT64    START.
  VFLT64 t1;
  VFLT64 t2;
  VFLT64 *pa=(VFLT64 *)a;
  VFLT64 *pb=(VFLT64 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE VFLT64     STOP.
}

VOID iccvFlipVFLT96( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE VFLT96    START.
  VFLT96 t1;
  VFLT96 t2;
  VFLT96 *pa=(VFLT96 *)a;
  VFLT96 *pb=(VFLT96 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE VFLT96     STOP.
}

VOID iccvFlipVINT08( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE VINT08    START.
  VINT08 t1;
  VINT08 t2;
  VINT08 *pa=(VINT08 *)a;
  VINT08 *pb=(VINT08 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE VINT08     STOP.
}

VOID iccvFlipVINT16( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE VINT16    START.
  VINT16 t1;
  VINT16 t2;
  VINT16 *pa=(VINT16 *)a;
  VINT16 *pb=(VINT16 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE VINT16     STOP.
}

VOID iccvFlipVINT32( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE VINT32    START.
  VINT32 t1;
  VINT32 t2;
  VINT32 *pa=(VINT32 *)a;
  VINT32 *pb=(VINT32 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE VINT32     STOP.
}

VOID iccvFlipVINT64( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE VINT64    START.
  VINT64 t1;
  VINT64 t2;
  VINT64 *pa=(VINT64 *)a;
  VINT64 *pb=(VINT64 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE VINT64     STOP.
}
VOID iccvFlipVUNT08( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE VUNT08    START.
  VUNT08 t1;
  VUNT08 t2;
  VUNT08 *pa=(VUNT08 *)a;
  VUNT08 *pb=(VUNT08 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE VUNT08     STOP.
}

VOID iccvFlipVUNT16( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE VUNT16    START.
  VUNT16 t1;
  VUNT16 t2;
  VUNT16 *pa=(VUNT16 *)a;
  VUNT16 *pb=(VUNT16 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE VUNT16     STOP.
}

VOID iccvFlipVUNT32( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE VUNT32    START.
  VUNT32 t1;
  VUNT32 t2;
  VUNT32 *pa=(VUNT32 *)a;
  VUNT32 *pb=(VUNT32 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE VUNT32     STOP.
}

VOID iccvFlipVUNT64( VOID *a, VOID *b, UNT32 n )
{
//------------------------------- COMMON-CODE VUNT64    START.
  VUNT64 t1;
  VUNT64 t2;
  VUNT64 *pa=(VUNT64 *)a;
  VUNT64 *pb=(VUNT64 *)b;
  INT32 m=n-1;
  INT32 ii;
  INT32 midPoint;

  if(n==1) return; /* Flipping a single element is a no op.*/

  if((n%2)==0) midPoint = n/2;    /*If index is even.*/
  else         midPoint = (n+1)/2;/*If index is odd. */

  for( ii=0; ii<midPoint; ii++) /*Do the reversing.*/
  {
    t1 = pa[ii];
    t2 = pa[m-ii];
    pb[ii] = t2;
    pb[m-ii]=t1;
  }
//------------------------------- COMMON-CODE VUNT64     STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
