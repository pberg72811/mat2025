/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvRamp.c
// Desc: This file contains the code for the vectorUtils routine iccvRamp.
// Hist: When       Who  What
//       07/25/2001 ptb  Initial Code.
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
PERL_PREPROCESS  *pa=strt;
PERL_PREPROCESS  pa+=i;
PERL_PREPROCESS  for(ii=1; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    *pa = pa[-i]+inc;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS  }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccvRampFLT32( FLT32 *a, INT32 i, FLT32 strt, FLT32 inc, UNT32 n)
{
//------------------------------- COMMON-CODE FLT32       START.
  FLT32 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    *pa = pa[-i]+inc;
    pa+=i;
  }
//------------------------------- COMMON-CODE FLT32        STOP.
}

VOID iccvRampFLT64( FLT64 *a, INT32 i, FLT64 strt, FLT64 inc, UNT32 n)
{
//------------------------------- COMMON-CODE FLT64       START.
  FLT64 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    *pa = pa[-i]+inc;
    pa+=i;
  }
//------------------------------- COMMON-CODE FLT64        STOP.
}

VOID iccvRampFLT96( FLT96 *a, INT32 i, FLT96 strt, FLT96 inc, UNT32 n)
{
//------------------------------- COMMON-CODE FLT96       START.
  FLT96 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    *pa = pa[-i]+inc;
    pa+=i;
  }
//------------------------------- COMMON-CODE FLT96        STOP.
}

VOID iccvRampINT08( INT08 *a, INT32 i, INT08 strt, INT08 inc, UNT32 n)
{
//------------------------------- COMMON-CODE INT08       START.
  INT08 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    *pa = pa[-i]+inc;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT08        STOP.
}

VOID iccvRampINT16( INT16 *a, INT32 i, INT16 strt, INT16 inc, UNT32 n)
{
//------------------------------- COMMON-CODE INT16      START.
  INT16 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    *pa = pa[-i]+inc;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT16       STOP.
}

VOID iccvRampINT32( INT32 *a, INT32 i, INT32 strt, INT32 inc, UNT32 n)
{
//------------------------------- COMMON-CODE INT32      START.
  INT32 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    *pa = pa[-i]+inc;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT32       STOP.
}

VOID iccvRampINT64( INT64 *a, INT32 i, INT64 strt, INT64 inc, UNT32 n)
{
//------------------------------- COMMON-CODE INT64       START.
  INT64 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    *pa = pa[-i]+inc;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT64        STOP.
}

VOID iccvRampUNT08( UNT08 *a, INT32 i, UNT08 strt, UNT08 inc, UNT32 n)
{
//------------------------------- COMMON-CODE UNT08       START.
  UNT08 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    *pa = pa[-i]+inc;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT08        STOP.
}

VOID iccvRampUNT16( UNT16 *a, INT32 i, UNT16 strt, UNT16 inc, UNT32 n)
{
//------------------------------- COMMON-CODE UNT16       START.
  UNT16 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    *pa = pa[-i]+inc;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT16        STOP.
}

VOID iccvRampUNT32( UNT32 *a, INT32 i, UNT32 strt, UNT32 inc, UNT32 n)
{
//------------------------------- COMMON-CODE UNT32       START.
  UNT32 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    *pa = pa[-i]+inc;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT32        STOP.
}

VOID iccvRampUNT64( UNT64 *a, INT32 i, UNT64 strt, UNT64 inc, UNT32 n)
{
//------------------------------- COMMON-CODE UNT64       START.
  UNT64 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    *pa = pa[-i]+inc;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT64        STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa=a;
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS  *pa=strt;
PERL_PREPROCESS  pa+=i;
PERL_PREPROCESS  for(ii=1; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    pa->r = pa[-i].r+inc.r;
PERL_PREPROCESS    pa->i = pa[-i].i+inc.i;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS  }
#endif

// Handle complex arrays.
//-------------------------------------------------------------------------------
VOID iccvRampCFLT32( CFLT32 *a, INT32 i, CFLT32 strt, CFLT32 inc, UNT32 n)
{
//------------------------------- COMMON-CODE CFLT32     START.
  CFLT32 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->r = pa[-i].r+inc.r;
    pa->i = pa[-i].i+inc.i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CFLT32      STOP.
}

VOID iccvRampCFLT64( CFLT64 *a, INT32 i, CFLT64 strt, CFLT64 inc, UNT32 n)
{
//------------------------------- COMMON-CODE CFLT64       START.
  CFLT64 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->r = pa[-i].r+inc.r;
    pa->i = pa[-i].i+inc.i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CFLT64        STOP.
}

VOID iccvRampCFLT96( CFLT96 *a, INT32 i, CFLT96 strt, CFLT96 inc, UNT32 n)
{
//------------------------------- COMMON-CODE CFLT96       START.
  CFLT96 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->r = pa[-i].r+inc.r;
    pa->i = pa[-i].i+inc.i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CFLT96        STOP.
}

VOID iccvRampCINT08( CINT08 *a, INT32 i, CINT08 strt, CINT08 inc, UNT32 n)
{
//------------------------------- COMMON-CODE CINT08       START.
  CINT08 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->r = pa[-i].r+inc.r;
    pa->i = pa[-i].i+inc.i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CINT08        STOP.
}

VOID iccvRampCINT16( CINT16 *a, INT32 i, CINT16 strt, CINT16 inc, UNT32 n)
{
//------------------------------- COMMON-CODE CINT16      START.
  CINT16 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->r = pa[-i].r+inc.r;
    pa->i = pa[-i].i+inc.i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CINT16       STOP.
}

VOID iccvRampCINT32( CINT32 *a, INT32 i, CINT32 strt, CINT32 inc, UNT32 n)
{
//------------------------------- COMMON-CODE CINT32      START.
  CINT32 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->r = pa[-i].r+inc.r;
    pa->i = pa[-i].i+inc.i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CINT32       STOP.
}

VOID iccvRampCINT64( CINT64 *a, INT32 i, CINT64 strt, CINT64 inc, UNT32 n)
{
//------------------------------- COMMON-CODE CINT64       START.
  CINT64 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->r = pa[-i].r+inc.r;
    pa->i = pa[-i].i+inc.i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CINT64        STOP.
}

VOID iccvRampCUNT08( CUNT08 *a, INT32 i, CUNT08 strt, CUNT08 inc, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT08       START.
  CUNT08 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->r = pa[-i].r+inc.r;
    pa->i = pa[-i].i+inc.i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CUNT08        STOP.
}

VOID iccvRampCUNT16( CUNT16 *a, INT32 i, CUNT16 strt, CUNT16 inc, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT16       START.
  CUNT16 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->r = pa[-i].r+inc.r;
    pa->i = pa[-i].i+inc.i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CUNT16        STOP.
}

VOID iccvRampCUNT32( CUNT32 *a, INT32 i, CUNT32 strt, CUNT32 inc, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT32       START.
  CUNT32 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->r = pa[-i].r+inc.r;
    pa->i = pa[-i].i+inc.i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CUNT32        STOP.
}

VOID iccvRampCUNT64( CUNT64 *a, INT32 i, CUNT64 strt, CUNT64 inc, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT64       START.
  CUNT64 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->r = pa[-i].r+inc.r;
    pa->i = pa[-i].i+inc.i;
    pa+=i;
  }
//------------------------------- COMMON-CODE CUNT64        STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa=a;
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS  *pa=strt;
PERL_PREPROCESS  pa+=i;
PERL_PREPROCESS  for(ii=1; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    pa->x = pa[-i].x+inc.x;
PERL_PREPROCESS    pa->y = pa[-i].y+inc.y;
PERL_PREPROCESS    pa->z = pa[-i].z+inc.z;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS  }
#endif

// Handle 3 element vectors.
//-------------------------------------------------------------------------------
VOID iccvRampVFLT32( VFLT32 *a, INT32 i, VFLT32 strt, VFLT32 inc, UNT32 n)
{
//------------------------------- COMMON-CODE VFLT32     START.
  VFLT32 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->x = pa[-i].x+inc.x;
    pa->y = pa[-i].y+inc.y;
    pa->z = pa[-i].z+inc.z;
    pa+=i;
  }
//------------------------------- COMMON-CODE VFLT32      STOP.
}

VOID iccvRampVFLT64( VFLT64 *a, INT32 i, VFLT64 strt, VFLT64 inc, UNT32 n)
{
//------------------------------- COMMON-CODE VFLT64       START.
  VFLT64 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->x = pa[-i].x+inc.x;
    pa->y = pa[-i].y+inc.y;
    pa->z = pa[-i].z+inc.z;
    pa+=i;
  }
//------------------------------- COMMON-CODE VFLT64        STOP.
}

VOID iccvRampVFLT96( VFLT96 *a, INT32 i, VFLT96 strt, VFLT96 inc, UNT32 n)
{
//------------------------------- COMMON-CODE VFLT96       START.
  VFLT96 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->x = pa[-i].x+inc.x;
    pa->y = pa[-i].y+inc.y;
    pa->z = pa[-i].z+inc.z;
    pa+=i;
  }
//------------------------------- COMMON-CODE VFLT96        STOP.
}

VOID iccvRampVINT08( VINT08 *a, INT32 i, VINT08 strt, VINT08 inc, UNT32 n)
{
//------------------------------- COMMON-CODE VINT08       START.
  VINT08 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->x = pa[-i].x+inc.x;
    pa->y = pa[-i].y+inc.y;
    pa->z = pa[-i].z+inc.z;
    pa+=i;
  }
//------------------------------- COMMON-CODE VINT08        STOP.
}

VOID iccvRampVINT16( VINT16 *a, INT32 i, VINT16 strt, VINT16 inc, UNT32 n)
{
//------------------------------- COMMON-CODE VINT16      START.
  VINT16 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->x = pa[-i].x+inc.x;
    pa->y = pa[-i].y+inc.y;
    pa->z = pa[-i].z+inc.z;
    pa+=i;
  }
//------------------------------- COMMON-CODE VINT16       STOP.
}

VOID iccvRampVINT32( VINT32 *a, INT32 i, VINT32 strt, VINT32 inc, UNT32 n)
{
//------------------------------- COMMON-CODE VINT32      START.
  VINT32 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->x = pa[-i].x+inc.x;
    pa->y = pa[-i].y+inc.y;
    pa->z = pa[-i].z+inc.z;
    pa+=i;
  }
//------------------------------- COMMON-CODE VINT32       STOP.
}

VOID iccvRampVINT64( VINT64 *a, INT32 i, VINT64 strt, VINT64 inc, UNT32 n)
{
//------------------------------- COMMON-CODE VINT64       START.
  VINT64 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->x = pa[-i].x+inc.x;
    pa->y = pa[-i].y+inc.y;
    pa->z = pa[-i].z+inc.z;
    pa+=i;
  }
//------------------------------- COMMON-CODE VINT64        STOP.
}

VOID iccvRampVUNT08( VUNT08 *a, INT32 i, VUNT08 strt, VUNT08 inc, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT08       START.
  VUNT08 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->x = pa[-i].x+inc.x;
    pa->y = pa[-i].y+inc.y;
    pa->z = pa[-i].z+inc.z;
    pa+=i;
  }
//------------------------------- COMMON-CODE VUNT08        STOP.
}

VOID iccvRampVUNT16( VUNT16 *a, INT32 i, VUNT16 strt, VUNT16 inc, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT16       START.
  VUNT16 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->x = pa[-i].x+inc.x;
    pa->y = pa[-i].y+inc.y;
    pa->z = pa[-i].z+inc.z;
    pa+=i;
  }
//------------------------------- COMMON-CODE VUNT16        STOP.
}

VOID iccvRampVUNT32( VUNT32 *a, INT32 i, VUNT32 strt, VUNT32 inc, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT32       START.
  VUNT32 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->x = pa[-i].x+inc.x;
    pa->y = pa[-i].y+inc.y;
    pa->z = pa[-i].z+inc.z;
    pa+=i;
  }
//------------------------------- COMMON-CODE VUNT32        STOP.
}

VOID iccvRampVUNT64( VUNT64 *a, INT32 i, VUNT64 strt, VUNT64 inc, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT64       START.
  VUNT64 *pa=a;
  UNT32 ii;
  *pa=strt;
  pa+=i;
  for(ii=1; ii<n; ii++)
  {
    pa->x = pa[-i].x+inc.x;
    pa->y = pa[-i].y+inc.y;
    pa->z = pa[-i].z+inc.z;
    pa+=i;
  }
//------------------------------- COMMON-CODE VUNT64        STOP.
}
/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
