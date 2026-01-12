/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccvConvert.c
// Desc: This file contains the code for the vector_utils routine vconvert.
// Hist: When       Who  What
//       04/27/2001 ptb  Initial Code.
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
PERL_PREPROCESS  XXXXX  *pa=a;
PERL_PREPROCESS  YYYYY  *pb=b;
PERL_PREPROCESS  UNT32  ii;
PERL_PREPROCESS
PERL_PREPROCESS  for(ii=0; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    *pb = *pa ;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS    pb+=j;
PERL_PREPROCESS  }                
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
// Convert to FLT64
//------------------------------------------------------------------------------
VOID xccvINT08ToFLT64( INT08 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT08 FLT64        START.
  INT08  *pa=a;
  FLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE INT08 FLT64         STOP.
}

VOID xccvINT16ToFLT64( INT16 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT16 FLT64        START.
  INT16  *pa=a;
  FLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE INT16 FLT64         STOP.
}

VOID xccvINT32ToFLT64( INT32 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT32 FLT64        START.
  INT32  *pa=a;
  FLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE INT32 FLT64         STOP.
}

VOID xccvINT64ToFLT64( INT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT64 FLT64        START.
  INT64  *pa=a;
  FLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE INT64 FLT64         STOP.
}

VOID xccvUNT08ToFLT64( UNT08 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT08 FLT64        START.
  UNT08  *pa=a;
  FLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE UNT08 FLT64         STOP.
}

VOID xccvUNT16ToFLT64( UNT16 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT16 FLT64        START.
  UNT16  *pa=a;
  FLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE UNT16 FLT64         STOP.
}

VOID xccvUNT32ToFLT64( UNT32 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT32 FLT64        START.
  UNT32  *pa=a;
  FLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE UNT32 FLT64         STOP.
}

VOID xccvUNT64ToFLT64( UNT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT64 FLT64        START.
  UNT64  *pa=a;
  FLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE UNT64 FLT64         STOP.
}

VOID xccvFLT32ToFLT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 FLT64        START.
  FLT32  *pa=a;
  FLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 FLT64         STOP.
}

VOID xccvFLT64ToFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64 FLT64        START.
  FLT64  *pa=a;
  FLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT64 FLT64         STOP.
}


// Convert to FLT32
//------------------------------------------------------------------------------
VOID xccvINT08ToFLT32( VOID *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT08 FLT32        START.
  INT08  *pa=a;
  FLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE INT08 FLT32         STOP.
}

VOID xccvINT16ToFLT32( VOID *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT16 FLT32        START.
  INT16  *pa=a;
  FLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE INT16 FLT32         STOP.
}

VOID xccvINT32ToFLT32( VOID *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT32 FLT32        START.
  INT32  *pa=a;
  FLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE INT32 FLT32         STOP.
}

VOID xccvINT64ToFLT32( VOID *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT64 FLT32        START.
  INT64  *pa=a;
  FLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE INT64 FLT32         STOP.
}

VOID xccvUNT08ToFLT32( VOID *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT08 FLT32        START.
  UNT08  *pa=a;
  FLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE UNT08 FLT32         STOP.
}

VOID xccvUNT16ToFLT32( VOID *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT16 FLT32        START.
  UNT16  *pa=a;
  FLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE UNT16 FLT32         STOP.
}

VOID xccvUNT32ToFLT32( VOID *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT32 FLT32        START.
  UNT32  *pa=a;
  FLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE UNT32 FLT32         STOP.
}

VOID xccvUNT64ToFLT32( VOID *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT64 FLT32        START.
  UNT64  *pa=a;
  FLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE UNT64 FLT32         STOP.
}

VOID xccvFLT32ToFLT32( VOID *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 FLT32        START.
  FLT32  *pa=a;
  FLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 FLT32         STOP.

}

VOID xccvFLT64ToFLT32( VOID *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64 FLT32        START.
  FLT64  *pa=a;
  FLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT64 FLT32         STOP.
}

// Convert from FLT32
//------------------------------------------------------------------------------
VOID xccvFLT32ToINT08( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 INT08        START.
  FLT32  *pa=a;
  INT08  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 INT08         STOP.
}

VOID xccvFLT32ToINT16( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 INT16        START.
  FLT32  *pa=a;
  INT16  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 INT16         STOP.
}

VOID xccvFLT32ToINT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 INT32        START.
  FLT32  *pa=a;
  INT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 INT32         STOP.
}

VOID xccvFLT32ToINT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 INT64        START.
  FLT32  *pa=a;
  INT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 INT64         STOP.
}

VOID xccvFLT32ToUNT08( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 UNT08        START.
  FLT32  *pa=a;
  UNT08  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 UNT08         STOP.
}

VOID xccvFLT32ToUNT16( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 UNT16        START.
  FLT32  *pa=a;
  UNT16  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 UNT16         STOP.
}

VOID xccvFLT32ToUNT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 UNT32        START.
  FLT32  *pa=a;
  UNT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 UNT32         STOP.
}

VOID xccvFLT32ToUNT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 UNT64        START.
  FLT32  *pa=a;
  UNT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    *pb = *pa ;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 UNT64         STOP.
}

// 
//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX  *pa=(XXXXX *)a;
PERL_PREPROCESS  YYYYY  *pb=b;
PERL_PREPROCESS  UNT32  ii;
PERL_PREPROCESS
PERL_PREPROCESS  for(ii=0; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    pb->r = *pa;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS    pb+=j;
PERL_PREPROCESS  }                
#endif

// Convert some real value to CFLT32
//------------------------------------------------------------------------------
VOID xccvINT08ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT08 CFLT32      START.
  INT08  *pa=(INT08 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE INT08 CFLT32       STOP.
}

VOID xccvINT16ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT16 CFLT32      START.
  INT16  *pa=(INT16 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE INT16 CFLT32       STOP.
}

VOID xccvINT32ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT32 CFLT32      START.
  INT32  *pa=(INT32 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE INT32 CFLT32       STOP.
}

VOID xccvINT64ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT64 CFLT32      START.
  INT64  *pa=(INT64 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE INT64 CFLT32       STOP.
}

VOID xccvUNT08ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT08 CFLT32      START.
  UNT08  *pa=(UNT08 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE UNT08 CFLT32       STOP.
}

VOID xccvUNT16ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT16 CFLT32      START.
  UNT16  *pa=(UNT16 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE UNT16 CFLT32       STOP.
}

VOID xccvUNT32ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT32 CFLT32      START.
  UNT32  *pa=(UNT32 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE UNT32 CFLT32       STOP.
}

VOID xccvUNT64ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT64 CFLT32      START.
  UNT64  *pa=(UNT64 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE UNT64 CFLT32       STOP.
}

VOID xccvFLT32ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 CFLT32      START.
  FLT32  *pa=(FLT32 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 CFLT32       STOP.
}

VOID xccvFLT64ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64 CFLT32      START.
  FLT64  *pa=(FLT64 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT64 CFLT32       STOP.
}

// Convert some real value to CFLT64
//------------------------------------------------------------------------------
VOID xccvINT08ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT08 CFLT64      START.
  INT08  *pa=(INT08 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE INT08 CFLT64       STOP.
}

VOID xccvINT16ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT16 CFLT64      START.
  INT16  *pa=(INT16 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE INT16 CFLT64       STOP.
}

VOID xccvINT32ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT32 CFLT64      START.
  INT32  *pa=(INT32 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE INT32 CFLT64       STOP.
}

VOID xccvINT64ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE INT64 CFLT64      START.
  INT64  *pa=(INT64 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE INT64 CFLT64       STOP.
}

VOID xccvUNT08ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT08 CFLT64      START.
  UNT08  *pa=(UNT08 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE UNT08 CFLT64       STOP.
}

VOID xccvUNT16ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT16 CFLT64      START.
  UNT16  *pa=(UNT16 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE UNT16 CFLT64       STOP.
}

VOID xccvUNT32ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT32 CFLT64      START.
  UNT32  *pa=(UNT32 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE UNT32 CFLT64       STOP.
}

VOID xccvUNT64ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE UNT64 CFLT64      START.
  UNT64  *pa=(UNT64 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE UNT64 CFLT64       STOP.
}

VOID xccvFLT32ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 CFLT64      START.
  FLT32  *pa=(FLT32 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 CFLT64       STOP.
}

VOID xccvFLT64ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64 CFLT64      START.
  FLT64  *pa=(FLT64 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = *pa;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT64 CFLT64       STOP.
}

// 
//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX  *pa=(XXXXX *)a;
PERL_PREPROCESS  YYYYY  *pb=b;
PERL_PREPROCESS  UNT32  ii;
PERL_PREPROCESS
PERL_PREPROCESS  for(ii=0; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    pb->r = pa->r;
PERL_PREPROCESS    pb->i = pa->i;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS    pb+=j;
PERL_PREPROCESS  }                
#endif

// Convert some complex value to CFLT64
//------------------------------------------------------------------------------
VOID xccvCINT08ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CINT08 CFLT32      START.
  CINT08  *pa=(CINT08 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CINT08 CFLT32       STOP.
}

VOID xccvCINT16ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CINT16 CFLT32      START.
  CINT16  *pa=(CINT16 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CINT16 CFLT32       STOP.
}

VOID xccvCINT32ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CINT32 CFLT32      START.
  CINT32  *pa=(CINT32 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CINT32 CFLT32       STOP.
}

VOID xccvCINT64ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CINT64 CFLT32      START.
  CINT64  *pa=(CINT64 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CINT64 CFLT32       STOP.
}

VOID xccvCUNT08ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT08 CFLT32      START.
  CUNT08  *pa=(CUNT08 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CUNT08 CFLT32       STOP.
}

VOID xccvCUNT16ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT16 CFLT32      START.
  CUNT16  *pa=(CUNT16 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CUNT16 CFLT32       STOP.
}

VOID xccvCUNT32ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT32 CFLT32      START.
  CUNT32  *pa=(CUNT32 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CUNT32 CFLT32       STOP.
}

VOID xccvCUNT64ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT64 CFLT32      START.
  CUNT64  *pa=(CUNT64 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CUNT64 CFLT32       STOP.
}

VOID xccvCFLT32ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT32 CFLT32      START.
  CFLT32  *pa=(CFLT32 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CFLT32 CFLT32       STOP.
}

VOID xccvCFLT64ToCFLT32( VOID *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT64 CFLT32      START.
  CFLT64  *pa=(CFLT64 *)a;
  CFLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CFLT64 CFLT32       STOP.
}

// Convert some complex value to CFLT64
//------------------------------------------------------------------------------
VOID xccvCINT08ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CINT08 CFLT64      START.
  CINT08  *pa=(CINT08 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CINT08 CFLT64       STOP.
}

VOID xccvCINT16ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CINT16 CFLT64      START.
  CINT16  *pa=(CINT16 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CINT16 CFLT64       STOP.
}

VOID xccvCINT32ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CINT32 CFLT64      START.
  CINT32  *pa=(CINT32 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CINT32 CFLT64       STOP.
}

VOID xccvCINT64ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CINT64 CFLT64      START.
  CINT64  *pa=(CINT64 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CINT64 CFLT64       STOP.
}

VOID xccvCUNT08ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT08 CFLT64      START.
  CUNT08  *pa=(CUNT08 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CUNT08 CFLT64       STOP.
}

VOID xccvCUNT16ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT16 CFLT64      START.
  CUNT16  *pa=(CUNT16 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CUNT16 CFLT64       STOP.
}

VOID xccvCUNT32ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT32 CFLT64      START.
  CUNT32  *pa=(CUNT32 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CUNT32 CFLT64       STOP.
}

VOID xccvCUNT64ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CUNT64 CFLT64      START.
  CUNT64  *pa=(CUNT64 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CUNT64 CFLT64       STOP.
}

VOID xccvCFLT32ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT32 CFLT64      START.
  CFLT32  *pa=(CFLT32 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CFLT32 CFLT64       STOP.
}

VOID xccvCFLT64ToCFLT64( VOID *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT64 CFLT64      START.
  CFLT64  *pa=(CFLT64 *)a;
  CFLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    pb->r = pa->r;
    pb->i = pa->i;
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE CFLT64 CFLT64       STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
