/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccvFill.c
// Desc: This file contains the code for the vectorUtils routine xccvFill.
// Hist: When       Who  What
//       08/05/2002 ptb  Initial Code.
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
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS  for(ii=0; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    *pa = b;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS  }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID xccvFillFLT32( FLT32 *a, INT32 i, FLT32 b, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32   START.
  FLT32 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE FLT32    STOP.
}

VOID xccvFillFLT64( FLT64 *a, INT32 i, FLT64 b, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64   START.
  FLT64 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE FLT64    STOP.
}

VOID xccvFillFLT96( FLT96 *a, INT32 i, FLT96 b, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96   START.
  FLT96 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE FLT96    STOP.
}

VOID xccvFillINT08( INT08 *a, INT32 i, INT08 b, UNT32 n)
{
//------------------------------- COMMON-CODE INT08   START.
  INT08 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT08    STOP.
}

VOID xccvFillINT16( INT16 *a, INT32 i, INT16 b, UNT32 n)
{
//------------------------------- COMMON-CODE INT16   START.
  INT16 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT16    STOP.
}

VOID xccvFillINT32( INT32 *a, INT32 i, INT32 b, UNT32 n)
{
//------------------------------- COMMON-CODE INT32   START.
  INT32 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT32    STOP.
}

VOID xccvFillINT64( INT64 *a, INT32 i, INT64 b, UNT32 n)
{
//------------------------------- COMMON-CODE INT64   START.
  INT64 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT64    STOP.
}

VOID xccvFillUNT08( UNT08 *a, INT32 i, UNT08 b, UNT32 n)
{
//------------------------------- COMMON-CODE UNT08   START.
  UNT08 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT08    STOP.
}

VOID xccvFillUNT16( UNT16 *a, INT32 i, UNT16 b, UNT32 n)
{
//------------------------------- COMMON-CODE UNT16   START.
  UNT16 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT16    STOP.
}

VOID xccvFillUNT32( UNT32 *a, INT32 i, UNT32 b, UNT32 n)
{
//------------------------------- COMMON-CODE UNT32   START.
  UNT32 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT32    STOP.
}

VOID xccvFillUNT64( UNT64 *a, INT32 i, UNT64 b, UNT32 n)
{
//------------------------------- COMMON-CODE UNT64   START.
  UNT64 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT64    STOP.
}

// Handle complex arrays.
//-------------------------------------------------------------------------------
VOID xccvFillCFLT32( CFLT32 *a, INT32 i, CFLT32 b, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT32   START.
  CFLT32 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE CFLT32    STOP.
}

VOID xccvFillCFLT64( CFLT64 *a, INT32 i, CFLT64 b, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT64   START.
  CFLT64 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE CFLT64    STOP.
}

VOID xccvFillCFLT96( CFLT96 *a, INT32 i, CFLT96 b, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT96   START.
  CFLT96 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE CFLT96    STOP.
}

VOID xccvFillCINT08( CINT08 *a, INT32 i, CINT08 b, UNT32 n)
{
//------------------------------- COMMON-CODE CINT08   START.
  CINT08 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE CINT08    STOP.
}

VOID xccvFillCINT16( CINT16 *a, INT32 i, CINT16 b, UNT32 n)
{
//------------------------------- COMMON-CODE CINT16   START.
  CINT16 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE CINT16    STOP.
}

VOID xccvFillCINT32( CINT32 *a, INT32 i, CINT32 b, UNT32 n)
{
//------------------------------- COMMON-CODE CINT32   START.
  CINT32 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE CINT32    STOP.
}

VOID xccvFillCINT64( CINT64 *a, INT32 i, CINT64 b, UNT32 n)
{
//------------------------------- COMMON-CODE CINT64   START.
  CINT64 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE CINT64    STOP.
}

VOID xccvFillCUNT08( CUNT08 *a, INT32 i, CUNT08 b, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT08   START.
  CUNT08 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE CUNT08    STOP.
}

VOID xccvFillCUNT16( CUNT16 *a, INT32 i, CUNT16 b, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT16   START.
  CUNT16 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE CUNT16    STOP.
}

VOID xccvFillCUNT32( CUNT32 *a, INT32 i, CUNT32 b, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT32   START.
  CUNT32 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE CUNT32    STOP.
}

VOID xccvFillCUNT64( CUNT64 *a, INT32 i, CUNT64 b, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT64   START.
  CUNT64 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE CUNT64    STOP.
}

// Handle 3 element vectors.
//-------------------------------------------------------------------------------
VOID xccvFillVFLT32( VFLT32 *a, INT32 i, VFLT32 b, UNT32 n )
{
//------------------------------- COMMON-CODE VFLT32   START.
  VFLT32 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE VFLT32    STOP.
}

VOID xccvFillVFLT64( VFLT64 *a, INT32 i, VFLT64 b, UNT32 n )
{
//------------------------------- COMMON-CODE VFLT64   START.
  VFLT64 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE VFLT64    STOP.
}

VOID xccvFillVFLT96( VFLT96 *a, INT32 i, VFLT96 b, UNT32 n )
{
//------------------------------- COMMON-CODE VFLT96   START.
  VFLT96 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE VFLT96    STOP.
}

VOID xccvFillVINT08( VINT08 *a, INT32 i, VINT08 b, UNT32 n)
{
//------------------------------- COMMON-CODE VINT08   START.
  VINT08 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE VINT08    STOP.
}

VOID xccvFillVINT16( VINT16 *a, INT32 i, VINT16 b, UNT32 n)
{
//------------------------------- COMMON-CODE VINT16   START.
  VINT16 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE VINT16    STOP.
}

VOID xccvFillVINT32( VINT32 *a, INT32 i, VINT32 b, UNT32 n)
{
//------------------------------- COMMON-CODE VINT32   START.
  VINT32 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE VINT32    STOP.
}

VOID xccvFillVINT64( VINT64 *a, INT32 i, VINT64 b, UNT32 n)
{
//------------------------------- COMMON-CODE VINT64   START.
  VINT64 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE VINT64    STOP.
}

VOID xccvFillVUNT08( VUNT08 *a, INT32 i, VUNT08 b, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT08   START.
  VUNT08 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE VUNT08    STOP.
}

VOID xccvFillVUNT16( VUNT16 *a, INT32 i, VUNT16 b, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT16   START.
  VUNT16 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE VUNT16    STOP.
}

VOID xccvFillVUNT32( VUNT32 *a, INT32 i, VUNT32 b, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT32   START.
  VUNT32 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE VUNT32    STOP.
}

VOID xccvFillVUNT64( VUNT64 *a, INT32 i, VUNT64 b, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT64   START.
  VUNT64 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = b;
    pa+=i;
  }
//------------------------------- COMMON-CODE VUNT64    STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
