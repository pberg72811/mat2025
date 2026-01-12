/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvZero.c
// Desc: This file contains the code for the vectorUtils routine iccvZero.
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
PERL_PREPROCESS  XXXXX *pa=a;
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS  for(ii=0; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    *pa = 0;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS  }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccvZeroFLT32( FLT32 *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32 START.
  FLT32 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = 0;
    pa+=i;
  }
//------------------------------- COMMON-CODE FLT32  STOP.
}

VOID iccvZeroFLT64( FLT64 *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64 START.
  FLT64 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = 0;
    pa+=i;
  }
//------------------------------- COMMON-CODE FLT64  STOP.
}

VOID iccvZeroFLT96( FLT96 *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96 START.
  FLT96 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = 0;
    pa+=i;
  }
//------------------------------- COMMON-CODE FLT96  STOP.
}

VOID iccvZeroINT08( INT08 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE INT08 START.
  INT08 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = 0;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT08  STOP.
}

VOID iccvZeroINT16( INT16 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE INT16 START.
  INT16 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = 0;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT16  STOP.
}

VOID iccvZeroINT32( INT32 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE INT32 START.
  INT32 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = 0;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT32  STOP.
}

VOID iccvZeroINT64( INT64 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE INT64 START.
  INT64 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = 0;
    pa+=i;
  }
//------------------------------- COMMON-CODE INT64  STOP.
}

VOID iccvZeroUNT08( UNT08 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE UNT08 START.
  UNT08 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = 0;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT08  STOP.
}

VOID iccvZeroUNT16( UNT16 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE UNT16 START.
  UNT16 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = 0;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT16  STOP.
}

VOID iccvZeroUNT32( UNT32 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE UNT32 START.
  UNT32 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = 0;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT32  STOP.
}

VOID iccvZeroUNT64( UNT64 *a, INT32 i, UNT32 n)
{
//------------------------------- COMMON-CODE UNT64 START.
  UNT64 *pa=a;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pa = 0;
    pa+=i;
  }
//------------------------------- COMMON-CODE UNT64  STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
