/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccvQuickSort.c
// Desc: This file contains the code for the vectorUtils routine xccvQuickSort.
// Hist: When       Who  What
//       04/15/2005 ptb  Initial Code.
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
PERL_PREPROCESS  XXXXX x;
PERL_PREPROCESS  XXXXX y;
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS  INT32 jj;
PERL_PREPROCESS
PERL_PREPROCESS  ii = left;
PERL_PREPROCESS  jj = rght;
PERL_PREPROCESS  x = a[(left+rght)/2];
PERL_PREPROCESS
PERL_PREPROCESS  do
PERL_PREPROCESS  {
PERL_PREPROCESS    while( (a[ii] < x) && (ii < rght) ) ii++;
PERL_PREPROCESS    while( (x < a[jj]) && (jj > left) ) jj--;
PERL_PREPROCESS
PERL_PREPROCESS    if(ii<=jj)
PERL_PREPROCESS    {
PERL_PREPROCESS      y = a[ii];
PERL_PREPROCESS      a[ii] = a[jj];
PERL_PREPROCESS      a[jj] = y;
PERL_PREPROCESS      ii++;
PERL_PREPROCESS      jj--;
PERL_PREPROCESS    }
PERL_PREPROCESS  }while(ii<=jj);
PERL_PREPROCESS
PERL_PREPROCESS  if(left < jj) 
PERL_PREPROCESS  {
PERL_PREPROCESS    xccvQuickSortXXXXX(a, left, jj);
PERL_PREPROCESS  }
PERL_PREPROCESS  if(ii < rght)
PERL_PREPROCESS  {
PERL_PREPROCESS    xccvQuickSortXXXXX(a, ii, rght);
PERL_PREPROCESS  }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID xccvQuickSortFLT32( FLT32 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE FLT32           START.
  FLT32 x;
  FLT32 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii] < x) && (ii < rght) ) ii++;
    while( (x < a[jj]) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortFLT32(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortFLT32(a, ii, rght);
  }
//------------------------------- COMMON-CODE FLT32            STOP.
}

VOID xccvQuickSortFLT64( FLT64 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE FLT64          START.
  FLT64 x;
  FLT64 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii] < x) && (ii < rght) ) ii++;
    while( (x < a[jj]) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortFLT64(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortFLT64(a, ii, rght);
  }
//------------------------------- COMMON-CODE FLT64           STOP.
}

VOID xccvQuickSortFLT96( FLT96 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE FLT96          START.
  FLT96 x;
  FLT96 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii] < x) && (ii < rght) ) ii++;
    while( (x < a[jj]) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortFLT96(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortFLT96(a, ii, rght);
  }
//------------------------------- COMMON-CODE FLT96           STOP.
}

VOID xccvQuickSortINT08( INT08 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE INT08          START.
  INT08 x;
  INT08 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii] < x) && (ii < rght) ) ii++;
    while( (x < a[jj]) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortINT08(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortINT08(a, ii, rght);
  }
//------------------------------- COMMON-CODE INT08           STOP.
}

VOID xccvQuickSortINT16( INT16 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE INT16          START.
  INT16 x;
  INT16 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii] < x) && (ii < rght) ) ii++;
    while( (x < a[jj]) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortINT16(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortINT16(a, ii, rght);
  }
//------------------------------- COMMON-CODE INT16           STOP.
}

VOID xccvQuickSortINT32( INT32 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE INT32          START.
  INT32 x;
  INT32 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii] < x) && (ii < rght) ) ii++;
    while( (x < a[jj]) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortINT32(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortINT32(a, ii, rght);
  }
//------------------------------- COMMON-CODE INT32           STOP.
}

VOID xccvQuickSortINT64( INT64 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE INT64          START.
  INT64 x;
  INT64 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii] < x) && (ii < rght) ) ii++;
    while( (x < a[jj]) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortINT64(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortINT64(a, ii, rght);
  }
//------------------------------- COMMON-CODE INT64           STOP.
}

VOID xccvQuickSortUNT08( UNT08 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE UNT08          START.
  UNT08 x;
  UNT08 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii] < x) && (ii < rght) ) ii++;
    while( (x < a[jj]) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortUNT08(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortUNT08(a, ii, rght);
  }
//------------------------------- COMMON-CODE UNT08           STOP.
}

VOID xccvQuickSortUNT16( UNT16 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE UNT16          START.
  UNT16 x;
  UNT16 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii] < x) && (ii < rght) ) ii++;
    while( (x < a[jj]) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortUNT16(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortUNT16(a, ii, rght);
  }
//------------------------------- COMMON-CODE UNT16           STOP.
}

VOID xccvQuickSortUNT32( UNT32 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE UNT32          START.
  UNT32 x;
  UNT32 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii] < x) && (ii < rght) ) ii++;
    while( (x < a[jj]) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortUNT32(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortUNT32(a, ii, rght);
  }
//------------------------------- COMMON-CODE UNT32           STOP.
}

VOID xccvQuickSortUNT64( UNT64 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE UNT64          START.
  UNT64 x;
  UNT64 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii] < x) && (ii < rght) ) ii++;
    while( (x < a[jj]) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortUNT64(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortUNT64(a, ii, rght);
  }
//------------------------------- COMMON-CODE UNT64           STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX x;
PERL_PREPROCESS  XXXXX y;
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS  INT32 jj;
PERL_PREPROCESS
PERL_PREPROCESS  ii = left;
PERL_PREPROCESS  jj = rght;
PERL_PREPROCESS  x = a[(left+rght)/2];
PERL_PREPROCESS
PERL_PREPROCESS  do
PERL_PREPROCESS  {
PERL_PREPROCESS    while( (a[ii].r < x.r) && (ii < rght) ) ii++;
PERL_PREPROCESS    while( (x.r < a[jj].r) && (jj > left) ) jj--;
PERL_PREPROCESS
PERL_PREPROCESS    if(ii<=jj)
PERL_PREPROCESS    {
PERL_PREPROCESS      y = a[ii];
PERL_PREPROCESS      a[ii] = a[jj];
PERL_PREPROCESS      a[jj] = y;
PERL_PREPROCESS      ii++;
PERL_PREPROCESS      jj--;
PERL_PREPROCESS    }
PERL_PREPROCESS  }while(ii<=jj);
PERL_PREPROCESS
PERL_PREPROCESS  if(left < jj) 
PERL_PREPROCESS  {
PERL_PREPROCESS    xccvQuickSortXXXXXr(a, left, jj);
PERL_PREPROCESS  }
PERL_PREPROCESS  if(ii < rght)
PERL_PREPROCESS  {
PERL_PREPROCESS    xccvQuickSortXXXXXr(a, ii, rght);
PERL_PREPROCESS  }
#endif

VOID xccvQuickSortCFLT32r( CFLT32 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CFLT32           START.
  CFLT32 x;
  CFLT32 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].r < x.r) && (ii < rght) ) ii++;
    while( (x.r < a[jj].r) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCFLT32r(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCFLT32r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CFLT32            STOP.
}

VOID xccvQuickSortCFLT64r( CFLT64 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CFLT64          START.
  CFLT64 x;
  CFLT64 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].r < x.r) && (ii < rght) ) ii++;
    while( (x.r < a[jj].r) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCFLT64r(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCFLT64r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CFLT64           STOP.
}

VOID xccvQuickSortCFLT96r( CFLT96 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CFLT96          START.
  CFLT96 x;
  CFLT96 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].r < x.r) && (ii < rght) ) ii++;
    while( (x.r < a[jj].r) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCFLT96r(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCFLT96r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CFLT96           STOP.
}

VOID xccvQuickSortCINT08r( CINT08 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CINT08          START.
  CINT08 x;
  CINT08 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].r < x.r) && (ii < rght) ) ii++;
    while( (x.r < a[jj].r) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCINT08r(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCINT08r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CINT08           STOP.
}

VOID xccvQuickSortCINT16r( CINT16 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CINT16          START.
  CINT16 x;
  CINT16 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].r < x.r) && (ii < rght) ) ii++;
    while( (x.r < a[jj].r) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCINT16r(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCINT16r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CINT16           STOP.
}

VOID xccvQuickSortCINT32r( CINT32 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CINT32          START.
  CINT32 x;
  CINT32 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].r < x.r) && (ii < rght) ) ii++;
    while( (x.r < a[jj].r) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCINT32r(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCINT32r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CINT32           STOP.
}

VOID xccvQuickSortCINT64r( CINT64 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CINT64          START.
  CINT64 x;
  CINT64 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].r < x.r) && (ii < rght) ) ii++;
    while( (x.r < a[jj].r) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCINT64r(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCINT64r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CINT64           STOP.
}

VOID xccvQuickSortCUNT08r( CUNT08 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CUNT08          START.
  CUNT08 x;
  CUNT08 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].r < x.r) && (ii < rght) ) ii++;
    while( (x.r < a[jj].r) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCUNT08r(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCUNT08r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CUNT08           STOP.
}

VOID xccvQuickSortCUNT16r( CUNT16 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CUNT16          START.
  CUNT16 x;
  CUNT16 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].r < x.r) && (ii < rght) ) ii++;
    while( (x.r < a[jj].r) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCUNT16r(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCUNT16r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CUNT16           STOP.
}

VOID xccvQuickSortCUNT32r( CUNT32 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CUNT32          START.
  CUNT32 x;
  CUNT32 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].r < x.r) && (ii < rght) ) ii++;
    while( (x.r < a[jj].r) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCUNT32r(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCUNT32r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CUNT32           STOP.
}

VOID xccvQuickSortCUNT64r( CUNT64 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CUNT64          START.
  CUNT64 x;
  CUNT64 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].r < x.r) && (ii < rght) ) ii++;
    while( (x.r < a[jj].r) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCUNT64r(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCUNT64r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CUNT64           STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX x;
PERL_PREPROCESS  XXXXX y;
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS  INT32 jj;
PERL_PREPROCESS
PERL_PREPROCESS  ii = left;
PERL_PREPROCESS  jj = rght;
PERL_PREPROCESS  x = a[(left+rght)/2];
PERL_PREPROCESS
PERL_PREPROCESS  do
PERL_PREPROCESS  {
PERL_PREPROCESS    while( (a[ii].i < x.i) && (ii < rght) ) ii++;
PERL_PREPROCESS    while( (x.i < a[jj].i) && (jj > left) ) jj--;
PERL_PREPROCESS
PERL_PREPROCESS    if(ii<=jj)
PERL_PREPROCESS    {
PERL_PREPROCESS      y = a[ii];
PERL_PREPROCESS      a[ii] = a[jj];
PERL_PREPROCESS      a[jj] = y;
PERL_PREPROCESS      ii++;
PERL_PREPROCESS      jj--;
PERL_PREPROCESS    }
PERL_PREPROCESS  }while(ii<=jj);
PERL_PREPROCESS
PERL_PREPROCESS  if(left < jj) 
PERL_PREPROCESS  {
PERL_PREPROCESS    xccvQuickSortXXXXXi(a, left, jj);
PERL_PREPROCESS  }
PERL_PREPROCESS  if(ii < rght)
PERL_PREPROCESS  {
PERL_PREPROCESS    xccvQuickSortXXXXXi(a, ii, rght);
PERL_PREPROCESS  }
#endif

VOID xccvQuickSortCFLT32i( CFLT32 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CFLT32           START.
  CFLT32 x;
  CFLT32 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].i < x.i) && (ii < rght) ) ii++;
    while( (x.i < a[jj].i) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCFLT32i(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCFLT32i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CFLT32            STOP.
}

VOID xccvQuickSortCFLT64i( CFLT64 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CFLT64          START.
  CFLT64 x;
  CFLT64 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].i < x.i) && (ii < rght) ) ii++;
    while( (x.i < a[jj].i) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCFLT64i(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCFLT64i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CFLT64           STOP.
}

VOID xccvQuickSortCFLT96i( CFLT96 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CFLT96          START.
  CFLT96 x;
  CFLT96 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].i < x.i) && (ii < rght) ) ii++;
    while( (x.i < a[jj].i) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCFLT96i(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCFLT96i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CFLT96           STOP.
}

VOID xccvQuickSortCINT08i( CINT08 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CINT08          START.
  CINT08 x;
  CINT08 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].i < x.i) && (ii < rght) ) ii++;
    while( (x.i < a[jj].i) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCINT08i(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCINT08i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CINT08           STOP.
}

VOID xccvQuickSortCINT16i( CINT16 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CINT16          START.
  CINT16 x;
  CINT16 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].i < x.i) && (ii < rght) ) ii++;
    while( (x.i < a[jj].i) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCINT16i(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCINT16i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CINT16           STOP.
}

VOID xccvQuickSortCINT32i( CINT32 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CINT32          START.
  CINT32 x;
  CINT32 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].i < x.i) && (ii < rght) ) ii++;
    while( (x.i < a[jj].i) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCINT32i(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCINT32i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CINT32           STOP.
}

VOID xccvQuickSortCINT64i( CINT64 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CINT64          START.
  CINT64 x;
  CINT64 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].i < x.i) && (ii < rght) ) ii++;
    while( (x.i < a[jj].i) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCINT64i(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCINT64i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CINT64           STOP.
}

VOID xccvQuickSortCUNT08i( CUNT08 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CUNT08          START.
  CUNT08 x;
  CUNT08 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].i < x.i) && (ii < rght) ) ii++;
    while( (x.i < a[jj].i) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCUNT08i(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCUNT08i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CUNT08           STOP.
}

VOID xccvQuickSortCUNT16i( CUNT16 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CUNT16          START.
  CUNT16 x;
  CUNT16 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].i < x.i) && (ii < rght) ) ii++;
    while( (x.i < a[jj].i) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCUNT16i(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCUNT16i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CUNT16           STOP.
}

VOID xccvQuickSortCUNT32i( CUNT32 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CUNT32          START.
  CUNT32 x;
  CUNT32 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].i < x.i) && (ii < rght) ) ii++;
    while( (x.i < a[jj].i) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCUNT32i(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCUNT32i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CUNT32           STOP.
}

VOID xccvQuickSortCUNT64i( CUNT64 *a, INT32 left, INT32 rght)
{
//------------------------------- COMMON-CODE CUNT64          START.
  CUNT64 x;
  CUNT64 y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = a[(left+rght)/2];

  do
  {
    while( (a[ii].i < x.i) && (ii < rght) ) ii++;
    while( (x.i < a[jj].i) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = a[ii];
      a[ii] = a[jj];
      a[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortCUNT64i(a, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortCUNT64i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CUNT64           STOP.
}



VOID xccvQuickSortString( CHR08 **string, INT32 left, INT32 rght)
{
  INT32 n;
  CHR08 *x;
  CHR08 *y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = string[(left+rght)/2];

  do
  {
    n = XMCMIN(strlen(string[ii]),strlen(x));
    while( (strncmp(string[ii], x, n) < 0) && (ii < rght) ) ii++; // while( (string[ii] < x) && (ii < rght) ) ii++;
    while( (strncmp(string[jj], x, n) > 0) && (jj > left) ) jj--; // while( (x < string[jj]) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = string[ii];
      string[ii] = string[jj];
      string[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortString(string, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortString(string, ii, rght);
  }
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
