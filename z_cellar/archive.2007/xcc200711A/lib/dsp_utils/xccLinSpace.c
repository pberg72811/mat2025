/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccLinSpace.c
// Desc: This file contains the code for the xccLinSpace.
// Hist: When       Who  What
//       04/26/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "dsp_utils.h" 
 
/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS  XXXXX l;
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS
PERL_PREPROCESS  l = x2-x1;
PERL_PREPROCESS  for(ii=0; ii<n; ii++) y[ii] = x1+ii*l/(n-1);
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID xccLinSpaceINT08(INT08 x1, INT08 x2, INT08 *y, INT32 n)
{
//COMMON-CODE INT08 START.
  INT08 l;
  INT32 ii;

  l = x2-x1;
  for(ii=0; ii<n; ii++) y[ii] = x1+ii*l/(n-1);
//COMMON-CODE INT08  STOP.
}

VOID xccLinSpaceINT16(INT16 x1, INT16 x2, INT16 *y, INT32 n)
{
//COMMON-CODE INT16 START.
  INT16 l;
  INT32 ii;

  l = x2-x1;
  for(ii=0; ii<n; ii++) y[ii] = x1+ii*l/(n-1);
//COMMON-CODE INT16  STOP.
}

VOID xccLinSpaceINT32(INT32 x1, INT32 x2, INT32 *y, INT32 n)
{
//COMMON-CODE INT32 START.
  INT32 l;
  INT32 ii;

  l = x2-x1;
  for(ii=0; ii<n; ii++) y[ii] = x1+ii*l/(n-1);
//COMMON-CODE INT32  STOP.
}

VOID xccLinSpaceINT64(INT64 x1, INT64 x2, INT64 *y, INT32 n)
{
//COMMON-CODE INT64 START.
  INT64 l;
  INT32 ii;

  l = x2-x1;
  for(ii=0; ii<n; ii++) y[ii] = x1+ii*l/(n-1);
//COMMON-CODE INT64  STOP.
}

VOID xccLinSpaceUNT08(UNT08 x1, UNT08 x2, UNT08 *y, INT32 n)
{
//COMMON-CODE UNT08 START.
  UNT08 l;
  INT32 ii;

  l = x2-x1;
  for(ii=0; ii<n; ii++) y[ii] = x1+ii*l/(n-1);
//COMMON-CODE UNT08  STOP.
}

VOID xccLinSpaceUNT16(UNT16 x1, UNT16 x2, UNT16 *y, INT32 n)
{
//COMMON-CODE UNT16 START.
  UNT16 l;
  INT32 ii;

  l = x2-x1;
  for(ii=0; ii<n; ii++) y[ii] = x1+ii*l/(n-1);
//COMMON-CODE UNT16  STOP.
}

VOID xccLinSpaceUNT32(UNT32 x1, UNT32 x2, UNT32 *y, INT32 n)
{
//COMMON-CODE UNT32 START.
  UNT32 l;
  INT32 ii;

  l = x2-x1;
  for(ii=0; ii<n; ii++) y[ii] = x1+ii*l/(n-1);
//COMMON-CODE UNT32  STOP.
}

VOID xccLinSpaceUNT64(UNT64 x1, UNT64 x2, UNT64 *y, INT32 n)
{
//COMMON-CODE UNT64 START.
  UNT64 l;
  INT32 ii;

  l = x2-x1;
  for(ii=0; ii<n; ii++) y[ii] = x1+ii*l/(n-1);
//COMMON-CODE UNT64  STOP.
}

VOID xccLinSpaceFLT32(FLT32 x1, FLT32 x2, FLT32 *y, INT32 n)
{
//COMMON-CODE FLT32 START.
  FLT32 l;
  INT32 ii;

  l = x2-x1;
  for(ii=0; ii<n; ii++) y[ii] = x1+ii*l/(n-1);
//COMMON-CODE FLT32  STOP.
}

VOID xccLinSpaceFLT64(FLT64 x1, FLT64 x2, FLT64 *y, INT32 n)
{
//COMMON-CODE FLT64 START.
  FLT64 l;
  INT32 ii;

  l = x2-x1;
  for(ii=0; ii<n; ii++) y[ii] = x1+ii*l/(n-1);
//COMMON-CODE FLT64  STOP.
}

VOID xccLinSpaceFLT96(FLT96 x1, FLT96 x2, FLT96 *y, INT32 n)
{
//COMMON-CODE FLT96 START.
  FLT96 l;
  INT32 ii;

  l = x2-x1;
  for(ii=0; ii<n; ii++) y[ii] = x1+ii*l/(n-1);
//COMMON-CODE FLT96  STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
