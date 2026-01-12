/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccvConvolve.c
// Desc: This file contains the code for the vectorUtils routine xccvConvolve.
// Hist: When       Who  What
//       04/27/2001 ptb  Initial Code.
//       04/27/2001 ptb  Added time reversal for "a" vector.
//       05/11/2004 ptb  changed "*pa=a+(n*i-1)" to "*pa=a+(n*i-i)";
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
PERL_PREPROCESS  XXXXX *pa=a+(n*i-i); //Convolution means "time" reversal.
PERL_PREPROCESS  XXXXX *pb=b;
PERL_PREPROCESS  XXXXX r = 0;
PERL_PREPROCESS  UNT32 k;
PERL_PREPROCESS  for(k=0; k<n; k++)
PERL_PREPROCESS  {
PERL_PREPROCESS    r +=(*pb * *pa);
PERL_PREPROCESS    pa-=i;
PERL_PREPROCESS    pb+=j;
PERL_PREPROCESS  }
PERL_PREPROCESS  return(r);
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
FLT32 xccvConvolveFLT32( FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32     START.
  FLT32 *pa=a+(n*i-i); //Convolution means "time" reversal.
  FLT32 *pb=b;
  FLT32 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa-=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE FLT32      STOP.
}

FLT64 xccvConvolveFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64     START.
  FLT64 *pa=a+(n*i-i); //Convolution means "time" reversal.
  FLT64 *pb=b;
  FLT64 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa-=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE FLT64      STOP.
}

FLT96 xccvConvolveFLT96( FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96     START.
  FLT96 *pa=a+(n*i-i); //Convolution means "time" reversal.
  FLT96 *pb=b;
  FLT96 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa-=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE FLT96      STOP.
}

INT08 xccvConvolveINT08( INT08 *a, INT32 i, INT08 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT08     START.
  INT08 *pa=a+(n*i-i); //Convolution means "time" reversal.
  INT08 *pb=b;
  INT08 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa-=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE INT08      STOP.
}

INT16 xccvConvolveINT16( INT16 *a, INT32 i, INT16 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT16     START.
  INT16 *pa=a+(n*i-i); //Convolution means "time" reversal.
  INT16 *pb=b;
  INT16 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa-=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE INT16      STOP.
}

INT32 xccvConvolveINT32( INT32 *a, INT32 i, INT32 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT32     START.
  INT32 *pa=a+(n*i-i); //Convolution means "time" reversal.
  INT32 *pb=b;
  INT32 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa-=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE INT32      STOP.
}

INT64 xccvConvolveINT64( INT64 *a, INT32 i, INT64 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT64     START.
  INT64 *pa=a+(n*i-i); //Convolution means "time" reversal.
  INT64 *pb=b;
  INT64 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa-=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE INT64      STOP.
}

UNT08 xccvConvolveUNT08( UNT08 *a, INT32 i, UNT08 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT08     START.
  UNT08 *pa=a+(n*i-i); //Convolution means "time" reversal.
  UNT08 *pb=b;
  UNT08 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa-=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE UNT08      STOP.
}

UNT16 xccvConvolveUNT16( UNT16 *a, INT32 i, UNT16 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT16     START.
  UNT16 *pa=a+(n*i-i); //Convolution means "time" reversal.
  UNT16 *pb=b;
  UNT16 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa-=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE UNT16      STOP.
}

UNT32 xccvConvolveUNT32( UNT32 *a, INT32 i, UNT32 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT32     START.
  UNT32 *pa=a+(n*i-i); //Convolution means "time" reversal.
  UNT32 *pb=b;
  UNT32 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa-=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE UNT32      STOP.
}

UNT64 xccvConvolveUNT64( UNT64 *a, INT32 i, UNT64 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT64     START.
  UNT64 *pa=a+(n*i-i); //Convolution means "time" reversal.
  UNT64 *pb=b;
  UNT64 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa-=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE UNT64      STOP.
}

// Hybrids.

FLT32 xccvConvolveFLT32FLT64( FLT32 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
  FLT32 *pa=a+(n*i);
  FLT64 *pb=b;
  FLT32 r = 0.0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa-=i;
    pb+=j;
  }
  return(r);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
