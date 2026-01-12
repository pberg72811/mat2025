/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvMulSum.c
// Desc: This file contains the code for the vectorUtils routine iccvMulSum.
// Hist: When       Who  What
//       07/23/2003 ptb  Initial Code.  Taken from iccvConvolve.
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
PERL_PREPROCESS  XXXXX *pa=a;
PERL_PREPROCESS  XXXXX *pb=b;
PERL_PREPROCESS  XXXXX r = 0;
PERL_PREPROCESS  UNT32 k;
PERL_PREPROCESS  for(k=0; k<n; k++)
PERL_PREPROCESS  {
PERL_PREPROCESS    r +=(*pb * *pa);
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS    pb+=j;
PERL_PREPROCESS  }
PERL_PREPROCESS  return(r);
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
FLT32 iccvMulSumFLT32( FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32       START.
  FLT32 *pa=a;
  FLT32 *pb=b;
  FLT32 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa+=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE FLT32        STOP.
}

FLT64 iccvMulSumFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64       START.
  FLT64 *pa=a;
  FLT64 *pb=b;
  FLT64 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa+=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE FLT64        STOP.
}

FLT96 iccvMulSumFLT96( FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96       START.
  FLT96 *pa=a;
  FLT96 *pb=b;
  FLT96 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa+=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE FLT96        STOP.
}

INT08 iccvMulSumINT08( INT08 *a, INT32 i, INT08 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT08       START.
  INT08 *pa=a;
  INT08 *pb=b;
  INT08 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa+=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE INT08        STOP.
}

INT16 iccvMulSumINT16( INT16 *a, INT32 i, INT16 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT16       START.
  INT16 *pa=a;
  INT16 *pb=b;
  INT16 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa+=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE INT16        STOP.
}

INT32 iccvMulSumINT32( INT32 *a, INT32 i, INT32 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT32       START.
  INT32 *pa=a;
  INT32 *pb=b;
  INT32 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa+=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE INT32        STOP.
}

INT64 iccvMulSumINT64( INT64 *a, INT32 i, INT64 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT64       START.
  INT64 *pa=a;
  INT64 *pb=b;
  INT64 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa+=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE INT64        STOP.
}

UNT08 iccvMulSumUNT08( UNT08 *a, INT32 i, UNT08 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT08       START.
  UNT08 *pa=a;
  UNT08 *pb=b;
  UNT08 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa+=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE UNT08        STOP.
}

UNT16 iccvMulSumUNT16( UNT16 *a, INT32 i, UNT16 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT16       START.
  UNT16 *pa=a;
  UNT16 *pb=b;
  UNT16 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa+=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE UNT16        STOP.
}

UNT32 iccvMulSumUNT32( UNT32 *a, INT32 i, UNT32 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT32       START.
  UNT32 *pa=a;
  UNT32 *pb=b;
  UNT32 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa+=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE UNT32        STOP.
}

UNT64 iccvMulSumUNT64( UNT64 *a, INT32 i, UNT64 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT64       START.
  UNT64 *pa=a;
  UNT64 *pb=b;
  UNT64 r = 0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa+=i;
    pb+=j;
  }
  return(r);
//------------------------------- COMMON-CODE UNT64        STOP.
}

// Handle complex arrays.
//-------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa=a;
PERL_PREPROCESS  XXXXX *pb=b;
PERL_PREPROCESS  XXXXX c;
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS
PERL_PREPROCESS  c.r=0;
PERL_PREPROCESS  c.i=0;
PERL_PREPROCESS  for(ii=0; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    c.r += (pa->r * pb->r) - (pa->i * pb->i);
PERL_PREPROCESS    c.i += (pa->r * pb->i) + (pa->i * pb->r);
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS    pb+=j;
PERL_PREPROCESS  }
PERL_PREPROCESS  return(c);
#endif

CFLT32 iccvMulSumCFLT32( CFLT32 *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CFLT32       START.
  CFLT32 *pa=a;
  CFLT32 *pb=b;
  CFLT32 c;
  UNT32 ii;

  c.r=0;
  c.i=0;
  for(ii=0; ii<n; ii++)
  {
    c.r += (pa->r * pb->r) - (pa->i * pb->i);
    c.i += (pa->r * pb->i) + (pa->i * pb->r);
    pa+=i;
    pb+=j;
  }
  return(c);
//------------------------------- COMMON-CODE CFLT32        STOP.
}

CFLT64 iccvMulSumCFLT64( CFLT64 *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT64       START.
  CFLT64 *pa=a;
  CFLT64 *pb=b;
  CFLT64 c;
  UNT32 ii;

  c.r=0;
  c.i=0;
  for(ii=0; ii<n; ii++)
  {
    c.r += (pa->r * pb->r) - (pa->i * pb->i);
    c.i += (pa->r * pb->i) + (pa->i * pb->r);
    pa+=i;
    pb+=j;
  }
  return(c);
//------------------------------- COMMON-CODE CFLT64        STOP.
}

CFLT96 iccvMulSumCFLT96( CFLT96 *a, INT32 i, CFLT96 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT96       START.
  CFLT96 *pa=a;
  CFLT96 *pb=b;
  CFLT96 c;
  UNT32 ii;

  c.r=0;
  c.i=0;
  for(ii=0; ii<n; ii++)
  {
    c.r += (pa->r * pb->r) - (pa->i * pb->i);
    c.i += (pa->r * pb->i) + (pa->i * pb->r);
    pa+=i;
    pb+=j;
  }
  return(c);
//------------------------------- COMMON-CODE CFLT96        STOP.
}

CINT08 iccvMulSumCINT08( CINT08 *a, INT32 i, CINT08 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CINT08       START.
  CINT08 *pa=a;
  CINT08 *pb=b;
  CINT08 c;
  UNT32 ii;

  c.r=0;
  c.i=0;
  for(ii=0; ii<n; ii++)
  {
    c.r += (pa->r * pb->r) - (pa->i * pb->i);
    c.i += (pa->r * pb->i) + (pa->i * pb->r);
    pa+=i;
    pb+=j;
  }
  return(c);
//------------------------------- COMMON-CODE CINT08        STOP.
}

CINT16 iccvMulSumCINT16( CINT16 *a, INT32 i, CINT16 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CINT16       START.
  CINT16 *pa=a;
  CINT16 *pb=b;
  CINT16 c;
  UNT32 ii;

  c.r=0;
  c.i=0;
  for(ii=0; ii<n; ii++)
  {
    c.r += (pa->r * pb->r) - (pa->i * pb->i);
    c.i += (pa->r * pb->i) + (pa->i * pb->r);
    pa+=i;
    pb+=j;
  }
  return(c);
//------------------------------- COMMON-CODE CINT16        STOP.
}

CINT32 iccvMulSumCINT32( CINT32 *a, INT32 i, CINT32 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CINT32       START.
  CINT32 *pa=a;
  CINT32 *pb=b;
  CINT32 c;
  UNT32 ii;

  c.r=0;
  c.i=0;
  for(ii=0; ii<n; ii++)
  {
    c.r += (pa->r * pb->r) - (pa->i * pb->i);
    c.i += (pa->r * pb->i) + (pa->i * pb->r);
    pa+=i;
    pb+=j;
  }
  return(c);
//------------------------------- COMMON-CODE CINT32        STOP.
}

CINT64 iccvMulSumCINT64( CINT64 *a, INT32 i, CINT64 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CINT64       START.
  CINT64 *pa=a;
  CINT64 *pb=b;
  CINT64 c;
  UNT32 ii;

  c.r=0;
  c.i=0;
  for(ii=0; ii<n; ii++)
  {
    c.r += (pa->r * pb->r) - (pa->i * pb->i);
    c.i += (pa->r * pb->i) + (pa->i * pb->r);
    pa+=i;
    pb+=j;
  }
  return(c);
//------------------------------- COMMON-CODE CINT64        STOP.
}

CUNT08 iccvMulSumCUNT08( CUNT08 *a, INT32 i, CUNT08 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT08       START.
  CUNT08 *pa=a;
  CUNT08 *pb=b;
  CUNT08 c;
  UNT32 ii;

  c.r=0;
  c.i=0;
  for(ii=0; ii<n; ii++)
  {
    c.r += (pa->r * pb->r) - (pa->i * pb->i);
    c.i += (pa->r * pb->i) + (pa->i * pb->r);
    pa+=i;
    pb+=j;
  }
  return(c);
//------------------------------- COMMON-CODE CUNT08        STOP.
}

CUNT16 iccvMulSumCUNT16( CUNT16 *a, INT32 i, CUNT16 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT16       START.
  CUNT16 *pa=a;
  CUNT16 *pb=b;
  CUNT16 c;
  UNT32 ii;

  c.r=0;
  c.i=0;
  for(ii=0; ii<n; ii++)
  {
    c.r += (pa->r * pb->r) - (pa->i * pb->i);
    c.i += (pa->r * pb->i) + (pa->i * pb->r);
    pa+=i;
    pb+=j;
  }
  return(c);
//------------------------------- COMMON-CODE CUNT16        STOP.
}

CUNT32 iccvMulSumCUNT32( CUNT32 *a, INT32 i, CUNT32 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT32       START.
  CUNT32 *pa=a;
  CUNT32 *pb=b;
  CUNT32 c;
  UNT32 ii;

  c.r=0;
  c.i=0;
  for(ii=0; ii<n; ii++)
  {
    c.r += (pa->r * pb->r) - (pa->i * pb->i);
    c.i += (pa->r * pb->i) + (pa->i * pb->r);
    pa+=i;
    pb+=j;
  }
  return(c);
//------------------------------- COMMON-CODE CUNT32        STOP.
}

CUNT64 iccvMulSumCUNT64( CUNT64 *a, INT32 i, CUNT64 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT64       START.
  CUNT64 *pa=a;
  CUNT64 *pb=b;
  CUNT64 c;
  UNT32 ii;

  c.r=0;
  c.i=0;
  for(ii=0; ii<n; ii++)
  {
    c.r += (pa->r * pb->r) - (pa->i * pb->i);
    c.i += (pa->r * pb->i) + (pa->i * pb->r);
    pa+=i;
    pb+=j;
  }
  return(c);
//------------------------------- COMMON-CODE CUNT64        STOP.
}



// Hybrids.
//-------------------------------------------------------------------------------
FLT32 iccvMulSumFLT32FLT64( FLT32 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
  FLT32 *pa=a;
  FLT64 *pb=b;
  FLT32 r = 0.0;
  UNT32 k;
  for(k=0; k<n; k++)
  {
    r +=(*pb * *pa);
    pa+=i;
    pb+=j;
  }
  return(r);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
