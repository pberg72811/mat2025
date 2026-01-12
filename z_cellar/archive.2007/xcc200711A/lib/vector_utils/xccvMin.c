/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccvMin.c
// Desc: This file contains the code for the vectorUtils routine xccvMin.
// Hist: When       Who  What
//       12/03/2001 ptb  Initial Code.
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
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa= a;
PERL_PREPROCESS  XXXXX t  = *a;
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS  for(ii=0; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    if(t > *pa) t = *pa;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS  }
PERL_PREPROCESS  return(t);
#endif

FLT32 xccvMinFLT32( FLT32 *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32     START.
  FLT32 *pa= a;
  FLT32 t  = *a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    if(t > *pa) t = *pa;
    pa+=i;
  }
  return(t);
//------------------------------- COMMON-CODE FLT32      STOP.
}

FLT64 xccvMinFLT64( FLT64 *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64     START.
  FLT64 *pa= a;
  FLT64 t  = *a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    if(t > *pa) t = *pa;
    pa+=i;
  }
  return(t);
//------------------------------- COMMON-CODE FLT64      STOP.
}

FLT96 xccvMinFLT96( FLT96 *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96     START.
  FLT96 *pa= a;
  FLT96 t  = *a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    if(t > *pa) t = *pa;
    pa+=i;
  }
  return(t);
//------------------------------- COMMON-CODE FLT96      STOP.
}

INT08 xccvMinINT08( INT08 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE INT08     START.
  INT08 *pa= a;
  INT08 t  = *a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    if(t > *pa) t = *pa;
    pa+=i;
  }
  return(t);
//------------------------------- COMMON-CODE INT08      STOP.
}

INT16 xccvMinINT16( INT16 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE INT16     START.
  INT16 *pa= a;
  INT16 t  = *a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    if(t > *pa) t = *pa;
    pa+=i;
  }
  return(t);
//------------------------------- COMMON-CODE INT16      STOP.
}

INT32 xccvMinINT32( INT32 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE INT32     START.
  INT32 *pa= a;
  INT32 t  = *a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    if(t > *pa) t = *pa;
    pa+=i;
  }
  return(t);
//------------------------------- COMMON-CODE INT32      STOP.
}

INT64 xccvMinINT64( INT64 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE INT64     START.
  INT64 *pa= a;
  INT64 t  = *a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    if(t > *pa) t = *pa;
    pa+=i;
  }
  return(t);
//------------------------------- COMMON-CODE INT64      STOP.
}

UNT08 xccvMinUNT08( UNT08 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE UNT08     START.
  UNT08 *pa= a;
  UNT08 t  = *a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    if(t > *pa) t = *pa;
    pa+=i;
  }
  return(t);
//------------------------------- COMMON-CODE UNT08      STOP.
}

UNT16 xccvMinUNT16( UNT16 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE UNT16     START.
  UNT16 *pa= a;
  UNT16 t  = *a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    if(t > *pa) t = *pa;
    pa+=i;
  }
  return(t);
//------------------------------- COMMON-CODE UNT16      STOP.
}

UNT32 xccvMinUNT32( UNT32 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE UNT32     START.
  UNT32 *pa= a;
  UNT32 t  = *a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    if(t > *pa) t = *pa;
    pa+=i;
  }
  return(t);
//------------------------------- COMMON-CODE UNT32      STOP.
}

UNT64 xccvMinUNT64( UNT64 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE UNT64     START.
  UNT64 *pa= a;
  UNT64 t  = *a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    if(t > *pa) t = *pa;
    pa+=i;
  }
  return(t);
//------------------------------- COMMON-CODE UNT64      STOP.
}

// Handle complex arrays.  Not sure what to do for complex.  compare mag?
//-------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa= a;
PERL_PREPROCESS  XXXXX r={0,0};
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS  for(ii=0; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    r.r+=pa->r;
PERL_PREPROCESS    r.i+=pa->i;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS  }
PERL_PREPROCESS  r.r=r.r/((YYYYY)n);
PERL_PREPROCESS  r.i=r.i/((YYYYY)n);
PERL_PREPROCESS  return(r);
#endif

CFLT32 xccvMinCFLT32( CFLT32 *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT32 FLT32     START.
  CFLT32 *pa= a;
  CFLT32 r={0,0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r+=pa->r;
    r.i+=pa->i;
    pa+=i;
  }
  r.r=r.r/((FLT32)n);
  r.i=r.i/((FLT32)n);
  return(r);
//------------------------------- COMMON-CODE CFLT32 FLT32      STOP.
}

CFLT64 xccvMinCFLT64( CFLT64 *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT64 FLT64     START.
  CFLT64 *pa= a;
  CFLT64 r={0,0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r+=pa->r;
    r.i+=pa->i;
    pa+=i;
  }
  r.r=r.r/((FLT64)n);
  r.i=r.i/((FLT64)n);
  return(r);
//------------------------------- COMMON-CODE CFLT64 FLT64      STOP.
}

CFLT96 xccvMinCFLT96( CFLT96 *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT96 FLT96     START.
  CFLT96 *pa= a;
  CFLT96 r={0,0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r+=pa->r;
    r.i+=pa->i;
    pa+=i;
  }
  r.r=r.r/((FLT96)n);
  r.i=r.i/((FLT96)n);
  return(r);
//------------------------------- COMMON-CODE CFLT96 FLT96      STOP.
}

CINT08 xccvMinCINT08( CINT08 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE CINT08 INT08    START.
  CINT08 *pa= a;
  CINT08 r={0,0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r+=pa->r;
    r.i+=pa->i;
    pa+=i;
  }
  r.r=r.r/((INT08)n);
  r.i=r.i/((INT08)n);
  return(r);
//------------------------------- COMMON-CODE CINT08 INT08     STOP.
}

CINT16 xccvMinCINT16( CINT16 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE CINT16 INT16    START.
  CINT16 *pa= a;
  CINT16 r={0,0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r+=pa->r;
    r.i+=pa->i;
    pa+=i;
  }
  r.r=r.r/((INT16)n);
  r.i=r.i/((INT16)n);
  return(r);
//------------------------------- COMMON-CODE CINT16 INT16     STOP.
}

CINT32 xccvMinCINT32( CINT32 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE CINT32 INT32    START.
  CINT32 *pa= a;
  CINT32 r={0,0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r+=pa->r;
    r.i+=pa->i;
    pa+=i;
  }
  r.r=r.r/((INT32)n);
  r.i=r.i/((INT32)n);
  return(r);
//------------------------------- COMMON-CODE CINT32 INT32     STOP.
}

CINT64 xccvMinCINT64( CINT64 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE CINT64 INT64    START.
  CINT64 *pa= a;
  CINT64 r={0,0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r+=pa->r;
    r.i+=pa->i;
    pa+=i;
  }
  r.r=r.r/((INT64)n);
  r.i=r.i/((INT64)n);
  return(r);
//------------------------------- COMMON-CODE CINT64 INT64     STOP.
}

CUNT08 xccvMinCUNT08( CUNT08 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT08 UNT08    START.
  CUNT08 *pa= a;
  CUNT08 r={0,0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r+=pa->r;
    r.i+=pa->i;
    pa+=i;
  }
  r.r=r.r/((UNT08)n);
  r.i=r.i/((UNT08)n);
  return(r);
//------------------------------- COMMON-CODE CUNT08 UNT08     STOP.
}

CUNT16 xccvMinCUNT16( CUNT16 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT16 UNT16    START.
  CUNT16 *pa= a;
  CUNT16 r={0,0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r+=pa->r;
    r.i+=pa->i;
    pa+=i;
  }
  r.r=r.r/((UNT16)n);
  r.i=r.i/((UNT16)n);
  return(r);
//------------------------------- COMMON-CODE CUNT16 UNT16     STOP.
}

CUNT32 xccvMinCUNT32( CUNT32 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT32 UNT32    START.
  CUNT32 *pa= a;
  CUNT32 r={0,0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r+=pa->r;
    r.i+=pa->i;
    pa+=i;
  }
  r.r=r.r/((UNT32)n);
  r.i=r.i/((UNT32)n);
  return(r);
//------------------------------- COMMON-CODE CUNT32 UNT32     STOP.
}

CUNT64 xccvMinCUNT64( CUNT64 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT64 UNT64    START.
  CUNT64 *pa= a;
  CUNT64 r={0,0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r+=pa->r;
    r.i+=pa->i;
    pa+=i;
  }
  r.r=r.r/((UNT64)n);
  r.i=r.i/((UNT64)n);
  return(r);
//------------------------------- COMMON-CODE CUNT64 UNT64     STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
