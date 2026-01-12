/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvConvert.c
// Desc: This file contains the code for the vector_utils routine vconvertN.
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
PERL_PREPROCESS  XXXXX  *pa=a;
PERL_PREPROCESS  FLT32  *pb=b;
PERL_PREPROCESS  UNT32  kk;
PERL_PREPROCESS
PERL_PREPROCESS  for(kk=0; kk<n; kk++)
PERL_PREPROCESS  {
PERL_PREPROCESS    *pb = *pa * XXXXX_NORMALIZE_FACTOR;
PERL_PREPROCESS    pa+=ii;
PERL_PREPROCESS    pb+=jj;
PERL_PREPROCESS  }                
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccvINT08ToFLT32N( INT08 *a, INT32 ii, FLT32 *b, INT32 jj, UNT32 n )
{
//COMMON-CODE INT08 START.
  INT08  *pa=a;
  FLT32  *pb=b;
  UNT32  kk;

  for(kk=0; kk<n; kk++)
  {
    *pb = *pa * INT08_NORMALIZE_FACTOR;
    pa+=ii;
    pb+=jj;
  }                
//COMMON-CODE INT08  STOP.
}

VOID iccvINT16ToFLT32N( INT16 *a, INT32 ii, FLT32 *b, INT32 jj, UNT32 n )
{
//COMMON-CODE INT16 START.
  INT16  *pa=a;
  FLT32  *pb=b;
  UNT32  kk;

  for(kk=0; kk<n; kk++)
  {
    *pb = *pa * INT16_NORMALIZE_FACTOR;
    pa+=ii;
    pb+=jj;
  }                
//COMMON-CODE INT16  STOP.
}

VOID iccvINT32ToFLT32N( INT32 *a, INT32 ii, FLT32 *b, INT32 jj, UNT32 n )
{
//COMMON-CODE INT32 START.
  INT32  *pa=a;
  FLT32  *pb=b;
  UNT32  kk;

  for(kk=0; kk<n; kk++)
  {
    *pb = *pa * INT32_NORMALIZE_FACTOR;
    pa+=ii;
    pb+=jj;
  }                
//COMMON-CODE INT32  STOP.
}

VOID iccvUNT08ToFLT32N( UNT08 *a, INT32 ii, FLT32 *b, INT32 jj, UNT32 n )
{
//COMMON-CODE UNT08 START.
  UNT08  *pa=a;
  FLT32  *pb=b;
  UNT32  kk;

  for(kk=0; kk<n; kk++)
  {
    *pb = *pa * UNT08_NORMALIZE_FACTOR;
    pa+=ii;
    pb+=jj;
  }                
//COMMON-CODE UNT08  STOP.
}

VOID iccvUNT16ToFLT32N( UNT16 *a, INT32 ii, FLT32 *b, INT32 jj, UNT32 n )
{
//COMMON-CODE UNT16 START.
  UNT16  *pa=a;
  FLT32  *pb=b;
  UNT32  kk;

  for(kk=0; kk<n; kk++)
  {
    *pb = *pa * UNT16_NORMALIZE_FACTOR;
    pa+=ii;
    pb+=jj;
  }                
//COMMON-CODE UNT16  STOP.
}

VOID iccvUNT32ToFLT32N( UNT32 *a, INT32 ii, FLT32 *b, INT32 jj, UNT32 n )
{
//COMMON-CODE UNT32 START.
  UNT32  *pa=a;
  FLT32  *pb=b;
  UNT32  kk;

  for(kk=0; kk<n; kk++)
  {
    *pb = *pa * UNT32_NORMALIZE_FACTOR;
    pa+=ii;
    pb+=jj;
  }                
//COMMON-CODE UNT32  STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
