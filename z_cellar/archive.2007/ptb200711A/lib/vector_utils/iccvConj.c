/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvConj.c
// Desc: This file contains the code for the vectorUtils routine iccvConj.
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
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
// Handle complex case.
//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa=a;
PERL_PREPROCESS  XXXXX *pb=b;
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS  for(ii=0; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    pb->r =  (pa->r);
PERL_PREPROCESS    pb->i = -(pa->i);
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS    pb+=j;
PERL_PREPROCESS  }
#endif

VOID iccvConjCFLT32( CFLT32 *a, INT32 i, CFLT32 *b, INT32 j,  UNT32 n)
{
//------------------------------- COMMON-CODE CFLT32      START.
  CFLT32 *pa=a;
  CFLT32 *pb=b;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    pb->r =  (pa->r);
    pb->i = -(pa->i);
    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE CFLT32       STOP.
}

VOID iccvConjCFLT64( CFLT64 *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CFLT64   START.
  CFLT64 *pa=a;
  CFLT64 *pb=b;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    pb->r =  (pa->r);
    pb->i = -(pa->i);
    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE CFLT64    STOP.
}

VOID iccvConjCFLT96( CFLT96 *a, INT32 i, CFLT96 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CFLT96   START.
  CFLT96 *pa=a;
  CFLT96 *pb=b;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    pb->r =  (pa->r);
    pb->i = -(pa->i);
    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE CFLT96    STOP.
}

VOID iccvConjCINT08( CINT08 *a, INT32 i, CINT08 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CINT08   START.
  CINT08 *pa=a;
  CINT08 *pb=b;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    pb->r =  (pa->r);
    pb->i = -(pa->i);
    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE CINT08    STOP.
}

VOID iccvConjCINT16( CINT16 *a, INT32 i, CINT16 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CINT16   START.
  CINT16 *pa=a;
  CINT16 *pb=b;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    pb->r =  (pa->r);
    pb->i = -(pa->i);
    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE CINT16    STOP.
}

VOID iccvConjCINT32( CINT32 *a, INT32 i, CINT32 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CINT32   START.
  CINT32 *pa=a;
  CINT32 *pb=b;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    pb->r =  (pa->r);
    pb->i = -(pa->i);
    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE CINT32    STOP.
}

VOID iccvConjCINT64( CINT64 *a, INT32 i, CINT64 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CINT64   START.
  CINT64 *pa=a;
  CINT64 *pb=b;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    pb->r =  (pa->r);
    pb->i = -(pa->i);
    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE CINT64    STOP.
}

VOID iccvConjCUNT08( CUNT08 *a, INT32 i, CUNT08 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT08   START.
  CUNT08 *pa=a;
  CUNT08 *pb=b;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    pb->r =  (pa->r);
    pb->i = -(pa->i);
    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE CUNT08    STOP.
}

VOID iccvConjCUNT16( CUNT16 *a, INT32 i, CUNT16 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT16   START.
  CUNT16 *pa=a;
  CUNT16 *pb=b;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    pb->r =  (pa->r);
    pb->i = -(pa->i);
    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE CUNT16    STOP.
}

VOID iccvConjCUNT32( CUNT32 *a, INT32 i, CUNT32 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT32   START.
  CUNT32 *pa=a;
  CUNT32 *pb=b;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    pb->r =  (pa->r);
    pb->i = -(pa->i);
    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE CUNT32    STOP.
}

VOID iccvConjCUNT64( CUNT64 *a, INT32 i, CUNT64 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT64   START.
  CUNT64 *pa=a;
  CUNT64 *pb=b;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    pb->r =  (pa->r);
    pb->i = -(pa->i);
    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE CUNT64    STOP.
}



/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
