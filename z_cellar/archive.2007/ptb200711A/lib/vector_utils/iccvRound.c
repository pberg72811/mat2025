/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvRound.c
// Desc: This file contains the code for the vector_utils routine vRound.
// Hist: When       Who  What
//       04/28/2004 ptb  Initial Code.
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
PERL_PREPROCESS    if(*pa>0) *pb = (YYYYY)(*pa+0.5); // For positive values.
PERL_PREPROCESS    else      *pb = (YYYYY)(*pa-0.5); // For negative values.
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS    pb+=j;
PERL_PREPROCESS  }                
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccvRoundFLT32INT08( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 INT08   START.
  FLT32  *pa=a;
  INT08  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (INT08)(*pa+0.5); // For positive values.
    else      *pb = (INT08)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 INT08    STOP.
}

VOID iccvRoundFLT32INT16( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 INT16   START.
  FLT32  *pa=a;
  INT16  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (INT16)(*pa+0.5); // For positive values.
    else      *pb = (INT16)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 INT16    STOP.
}

VOID iccvRoundFLT32INT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 INT32   START.
  FLT32  *pa=a;
  INT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (INT32)(*pa+0.5); // For positive values.
    else      *pb = (INT32)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 INT32    STOP.
}

VOID iccvRoundFLT32INT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 INT64   START.
  FLT32  *pa=a;
  INT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (INT64)(*pa+0.5); // For positive values.
    else      *pb = (INT64)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 INT64    STOP.
}

VOID iccvRoundFLT32UNT08( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 UNT08   START.
  FLT32  *pa=a;
  UNT08  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (UNT08)(*pa+0.5); // For positive values.
    else      *pb = (UNT08)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 UNT08    STOP.
}

VOID iccvRoundFLT32UNT16( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 UNT16   START.
  FLT32  *pa=a;
  UNT16  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (UNT16)(*pa+0.5); // For positive values.
    else      *pb = (UNT16)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 UNT16    STOP.
}

VOID iccvRoundFLT32UNT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 UNT32   START.
  FLT32  *pa=a;
  UNT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (UNT32)(*pa+0.5); // For positive values.
    else      *pb = (UNT32)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 UNT32    STOP.
}

VOID iccvRoundFLT32UNT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 UNT64   START.
  FLT32  *pa=a;
  UNT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (UNT64)(*pa+0.5); // For positive values.
    else      *pb = (UNT64)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 UNT64    STOP.
}

VOID iccvRoundFLT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 FLT32   START.
  FLT32  *pa=a;
  FLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (FLT32)(*pa+0.5); // For positive values.
    else      *pb = (FLT32)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 FLT32    STOP.
}

VOID iccvRoundFLT32FLT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 FLT64   START.
  FLT32  *pa=a;
  FLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (FLT64)(*pa+0.5); // For positive values.
    else      *pb = (FLT64)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 FLT64    STOP.
}

VOID iccvRoundFLT32FLT96( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 FLT96   START.
  FLT32  *pa=a;
  FLT96  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (FLT96)(*pa+0.5); // For positive values.
    else      *pb = (FLT96)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT32 FLT96    STOP.
}

VOID iccvRoundFLT64INT08( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64 INT08   START.
  FLT64  *pa=a;
  INT08  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (INT08)(*pa+0.5); // For positive values.
    else      *pb = (INT08)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT64 INT08    STOP.
}

VOID iccvRoundFLT64INT16( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64 INT16   START.
  FLT64  *pa=a;
  INT16  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (INT16)(*pa+0.5); // For positive values.
    else      *pb = (INT16)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT64 INT16    STOP.
}

VOID iccvRoundFLT64INT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64 INT32   START.
  FLT64  *pa=a;
  INT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (INT32)(*pa+0.5); // For positive values.
    else      *pb = (INT32)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT64 INT32    STOP.
}

VOID iccvRoundFLT64INT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64 INT64   START.
  FLT64  *pa=a;
  INT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (INT64)(*pa+0.5); // For positive values.
    else      *pb = (INT64)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT64 INT64    STOP.
}

VOID iccvRoundFLT64UNT08( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64 UNT08   START.
  FLT64  *pa=a;
  UNT08  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (UNT08)(*pa+0.5); // For positive values.
    else      *pb = (UNT08)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT64 UNT08    STOP.
}

VOID iccvRoundFLT64UNT16( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64 UNT16   START.
  FLT64  *pa=a;
  UNT16  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (UNT16)(*pa+0.5); // For positive values.
    else      *pb = (UNT16)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT64 UNT16    STOP.
}

VOID iccvRoundFLT64UNT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64 UNT32   START.
  FLT64  *pa=a;
  UNT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (UNT32)(*pa+0.5); // For positive values.
    else      *pb = (UNT32)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT64 UNT32    STOP.
}

VOID iccvRoundFLT64UNT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64 UNT64   START.
  FLT64  *pa=a;
  UNT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (UNT64)(*pa+0.5); // For positive values.
    else      *pb = (UNT64)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT64 UNT64    STOP.
}

VOID iccvRoundFLT64FLT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64 FLT32   START.
  FLT64  *pa=a;
  FLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (FLT32)(*pa+0.5); // For positive values.
    else      *pb = (FLT32)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT64 FLT32    STOP.
}

VOID iccvRoundFLT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64 FLT64   START.
  FLT64  *pa=a;
  FLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (FLT64)(*pa+0.5); // For positive values.
    else      *pb = (FLT64)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT64 FLT64    STOP.
}

VOID iccvRoundFLT64FLT96( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64 FLT96   START.
  FLT64  *pa=a;
  FLT96  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (FLT96)(*pa+0.5); // For positive values.
    else      *pb = (FLT96)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT64 FLT96    STOP.
}

VOID iccvRoundFLT96INT08( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96 INT08   START.
  FLT96  *pa=a;
  INT08  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (INT08)(*pa+0.5); // For positive values.
    else      *pb = (INT08)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT96 INT08    STOP.
}

VOID iccvRoundFLT96INT16( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96 INT16   START.
  FLT96  *pa=a;
  INT16  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (INT16)(*pa+0.5); // For positive values.
    else      *pb = (INT16)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT96 INT16    STOP.
}

VOID iccvRoundFLT96INT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96 INT32   START.
  FLT96  *pa=a;
  INT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (INT32)(*pa+0.5); // For positive values.
    else      *pb = (INT32)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT96 INT32    STOP.
}

VOID iccvRoundFLT96INT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96 INT64   START.
  FLT96  *pa=a;
  INT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (INT64)(*pa+0.5); // For positive values.
    else      *pb = (INT64)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT96 INT64    STOP.
}

VOID iccvRoundFLT96UNT08( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96 UNT08   START.
  FLT96  *pa=a;
  UNT08  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (UNT08)(*pa+0.5); // For positive values.
    else      *pb = (UNT08)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT96 UNT08    STOP.
}

VOID iccvRoundFLT96UNT16( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96 UNT16   START.
  FLT96  *pa=a;
  UNT16  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (UNT16)(*pa+0.5); // For positive values.
    else      *pb = (UNT16)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT96 UNT16    STOP.
}

VOID iccvRoundFLT96UNT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96 UNT32   START.
  FLT96  *pa=a;
  UNT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (UNT32)(*pa+0.5); // For positive values.
    else      *pb = (UNT32)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT96 UNT32    STOP.
}

VOID iccvRoundFLT96UNT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96 UNT64   START.
  FLT96  *pa=a;
  UNT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (UNT64)(*pa+0.5); // For positive values.
    else      *pb = (UNT64)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT96 UNT64    STOP.
}

VOID iccvRoundFLT96FLT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96 FLT32   START.
  FLT96  *pa=a;
  FLT32  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (FLT32)(*pa+0.5); // For positive values.
    else      *pb = (FLT32)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT96 FLT32    STOP.
}

VOID iccvRoundFLT96FLT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96 FLT64   START.
  FLT96  *pa=a;
  FLT64  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (FLT64)(*pa+0.5); // For positive values.
    else      *pb = (FLT64)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT96 FLT64    STOP.
}

VOID iccvRoundFLT96( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96 FLT96   START.
  FLT96  *pa=a;
  FLT96  *pb=b;
  UNT32  ii;

  for(ii=0; ii<n; ii++)
  {
    if(*pa>0) *pb = (FLT96)(*pa+0.5); // For positive values.
    else      *pb = (FLT96)(*pa-0.5); // For negative values.
    pa+=i;
    pb+=j;
  }                
//------------------------------- COMMON-CODE FLT96 FLT96    STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
