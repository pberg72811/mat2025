/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvSum.c
// Desc: This file contains the code for the vectorUtils routine iccvSum.
// Hist: When       Who  What
//       11/14/2001 ptb  Initial Code.
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
PERL_PREPROCESS  XXXXX r=0.0;
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS  for(ii=0; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    r += *pa;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS  }
PERL_PREPROCESS  return(r);
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
FLT32 iccvSumFLT32( VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32   START.
  FLT32 *pa=a;
  FLT32 r=0.0;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r += *pa;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE FLT32    STOP.
}

FLT64 iccvSumFLT64( VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64   START.
  FLT64 *pa=a;
  FLT64 r=0.0;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r += *pa;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE FLT64    STOP.
}

FLT96 iccvSumFLT96( VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96   START.
  FLT96 *pa=a;
  FLT96 r=0.0;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r += *pa;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE FLT96    STOP.
}

INT08 iccvSumINT08( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE INT08   START.
  INT08 *pa=a;
  INT08 r=0.0;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r += *pa;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE INT08    STOP.
}

INT16 iccvSumINT16( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE INT16   START.
  INT16 *pa=a;
  INT16 r=0.0;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r += *pa;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE INT16    STOP.
}

INT32 iccvSumINT32( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE INT32   START.
  INT32 *pa=a;
  INT32 r=0.0;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r += *pa;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE INT32    STOP.
}

INT64 iccvSumINT64( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE INT64   START.
  INT64 *pa=a;
  INT64 r=0.0;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r += *pa;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE INT64    STOP.
}

UNT08 iccvSumUNT08( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE UNT08   START.
  UNT08 *pa=a;
  UNT08 r=0.0;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r += *pa;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE UNT08    STOP.
}

UNT16 iccvSumUNT16( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE UNT16   START.
  UNT16 *pa=a;
  UNT16 r=0.0;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r += *pa;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE UNT16    STOP.
}

UNT32 iccvSumUNT32( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE UNT32   START.
  UNT32 *pa=a;
  UNT32 r=0.0;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r += *pa;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE UNT32    STOP.
}

UNT64 iccvSumUNT64( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE UNT64   START.
  UNT64 *pa=a;
  UNT64 r=0.0;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r += *pa;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE UNT64    STOP.
}


#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa=a;
PERL_PREPROCESS  XXXXX r={0.0,0.0};
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS  for(ii=0; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    r.r += pa->r;
PERL_PREPROCESS    r.i += pa->i;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS  }
PERL_PREPROCESS  return(r);
#endif

// Handle complex arrays.
//-------------------------------------------------------------------------------
CFLT32 iccvSumCFLT32( VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT32   START.
  CFLT32 *pa=a;
  CFLT32 r={0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r += pa->r;
    r.i += pa->i;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE CFLT32    STOP.
}

CFLT64 iccvSumCFLT64( VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT64   START.
  CFLT64 *pa=a;
  CFLT64 r={0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r += pa->r;
    r.i += pa->i;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE CFLT64    STOP.
}

CFLT96 iccvSumCFLT96( VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT96   START.
  CFLT96 *pa=a;
  CFLT96 r={0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r += pa->r;
    r.i += pa->i;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE CFLT96    STOP.
}

CINT08 iccvSumCINT08( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE CINT08   START.
  CINT08 *pa=a;
  CINT08 r={0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r += pa->r;
    r.i += pa->i;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE CINT08    STOP.
}

CINT16 iccvSumCINT16( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE CINT16   START.
  CINT16 *pa=a;
  CINT16 r={0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r += pa->r;
    r.i += pa->i;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE CINT16    STOP.
}

CINT32 iccvSumCINT32( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE CINT32   START.
  CINT32 *pa=a;
  CINT32 r={0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r += pa->r;
    r.i += pa->i;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE CINT32    STOP.
}

CINT64 iccvSumCINT64( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE CINT64   START.
  CINT64 *pa=a;
  CINT64 r={0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r += pa->r;
    r.i += pa->i;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE CINT64    STOP.
}

CUNT08 iccvSumCUNT08( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT08   START.
  CUNT08 *pa=a;
  CUNT08 r={0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r += pa->r;
    r.i += pa->i;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE CUNT08    STOP.
}

CUNT16 iccvSumCUNT16( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT16   START.
  CUNT16 *pa=a;
  CUNT16 r={0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r += pa->r;
    r.i += pa->i;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE CUNT16    STOP.
}

CUNT32 iccvSumCUNT32( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT32   START.
  CUNT32 *pa=a;
  CUNT32 r={0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r += pa->r;
    r.i += pa->i;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE CUNT32    STOP.
}

CUNT64 iccvSumCUNT64( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT64   START.
  CUNT64 *pa=a;
  CUNT64 r={0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r += pa->r;
    r.i += pa->i;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE CUNT64    STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa=a;
PERL_PREPROCESS  XXXXX r={0.0,0.0,0.0};
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS  for(ii=0; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    r.x += pa->x;
PERL_PREPROCESS    r.y += pa->y;
PERL_PREPROCESS    r.z += pa->z;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS  }
PERL_PREPROCESS  return(r);
#endif

// Handle 3 element vector arrays.
//-------------------------------------------------------------------------------
VFLT32 iccvSumVFLT32( VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE VFLT32   START.
  VFLT32 *pa=a;
  VFLT32 r={0.0,0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.x += pa->x;
    r.y += pa->y;
    r.z += pa->z;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE VFLT32    STOP.
}

VFLT64 iccvSumVFLT64( VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE VFLT64   START.
  VFLT64 *pa=a;
  VFLT64 r={0.0,0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.x += pa->x;
    r.y += pa->y;
    r.z += pa->z;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE VFLT64    STOP.
}

VFLT96 iccvSumVFLT96( VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE VFLT96   START.
  VFLT96 *pa=a;
  VFLT96 r={0.0,0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.x += pa->x;
    r.y += pa->y;
    r.z += pa->z;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE VFLT96    STOP.
}

VINT08 iccvSumVINT08( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE VINT08   START.
  VINT08 *pa=a;
  VINT08 r={0.0,0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.x += pa->x;
    r.y += pa->y;
    r.z += pa->z;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE VINT08    STOP.
}

VINT16 iccvSumVINT16( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE VINT16   START.
  VINT16 *pa=a;
  VINT16 r={0.0,0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.x += pa->x;
    r.y += pa->y;
    r.z += pa->z;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE VINT16    STOP.
}

VINT32 iccvSumVINT32( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE VINT32   START.
  VINT32 *pa=a;
  VINT32 r={0.0,0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.x += pa->x;
    r.y += pa->y;
    r.z += pa->z;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE VINT32    STOP.
}

VINT64 iccvSumVINT64( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE VINT64   START.
  VINT64 *pa=a;
  VINT64 r={0.0,0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.x += pa->x;
    r.y += pa->y;
    r.z += pa->z;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE VINT64    STOP.
}

VUNT08 iccvSumVUNT08( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT08   START.
  VUNT08 *pa=a;
  VUNT08 r={0.0,0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.x += pa->x;
    r.y += pa->y;
    r.z += pa->z;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE VUNT08    STOP.
}

VUNT16 iccvSumVUNT16( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT16   START.
  VUNT16 *pa=a;
  VUNT16 r={0.0,0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.x += pa->x;
    r.y += pa->y;
    r.z += pa->z;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE VUNT16    STOP.
}

VUNT32 iccvSumVUNT32( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT32   START.
  VUNT32 *pa=a;
  VUNT32 r={0.0,0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.x += pa->x;
    r.y += pa->y;
    r.z += pa->z;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE VUNT32    STOP.
}

VUNT64 iccvSumVUNT64( VOID  *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT64   START.
  VUNT64 *pa=a;
  VUNT64 r={0.0,0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.x += pa->x;
    r.y += pa->y;
    r.z += pa->z;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE VUNT64    STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa=a;
PERL_PREPROCESS  YYYYY r=0.0;
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS  for(ii=0; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    r += *pa;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS  }
PERL_PREPROCESS  return(r);
#endif

// Handle some specialized conversions.
//-------------------------------------------------------------------------------
INT32 iccvSumINT08INT32( VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE INT08 INT32   START.
  INT08 *pa=a;
  INT32 r=0.0;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r += *pa;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE INT08 INT32    STOP.
}

INT32 iccvSumINT16INT32( VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE INT16 INT32   START.
  INT16 *pa=a;
  INT32 r=0.0;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r += *pa;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE INT16 INT32    STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa=a;
PERL_PREPROCESS  YYYYY r={0.0,0.0};
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS  for(ii=0; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    r.r += pa->r;
PERL_PREPROCESS    r.i += pa->i;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS  }
PERL_PREPROCESS  return(r);
#endif

// Handle some specialized conversions.
//-------------------------------------------------------------------------------
CINT32 iccvSumCINT08CINT32( VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE CINT08 CINT32   START.
  CINT08 *pa=a;
  CINT32 r={0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r += pa->r;
    r.i += pa->i;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE CINT08 CINT32    STOP.
}

CINT32 iccvSumCINT16CINT32( VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE CINT16 CINT32   START.
  CINT16 *pa=a;
  CINT32 r={0.0,0.0};
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    r.r += pa->r;
    r.i += pa->i;
    pa+=i;
  }
  return(r);
//------------------------------- COMMON-CODE CINT16 CINT32    STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
