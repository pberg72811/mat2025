/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvQuickSort.c
// Desc: This file contains the code for the vectorUtils routine iccvQuickSort.
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
PERL_PREPROCESS    iccvQuickSortXXXXX(a, left, jj);
PERL_PREPROCESS  }
PERL_PREPROCESS  if(ii < rght)
PERL_PREPROCESS  {
PERL_PREPROCESS    iccvQuickSortXXXXX(a, ii, rght);
PERL_PREPROCESS  }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccvQuickSortFLT32( FLT32 *a, INT32 left, INT32 rght)
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
    iccvQuickSortFLT32(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortFLT32(a, ii, rght);
  }
//------------------------------- COMMON-CODE FLT32            STOP.
}

VOID iccvQuickSortFLT64( FLT64 *a, INT32 left, INT32 rght)
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
    iccvQuickSortFLT64(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortFLT64(a, ii, rght);
  }
//------------------------------- COMMON-CODE FLT64           STOP.
}

VOID iccvQuickSortFLT96( FLT96 *a, INT32 left, INT32 rght)
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
    iccvQuickSortFLT96(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortFLT96(a, ii, rght);
  }
//------------------------------- COMMON-CODE FLT96           STOP.
}

VOID iccvQuickSortINT08( INT08 *a, INT32 left, INT32 rght)
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
    iccvQuickSortINT08(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortINT08(a, ii, rght);
  }
//------------------------------- COMMON-CODE INT08           STOP.
}

VOID iccvQuickSortINT16( INT16 *a, INT32 left, INT32 rght)
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
    iccvQuickSortINT16(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortINT16(a, ii, rght);
  }
//------------------------------- COMMON-CODE INT16           STOP.
}

VOID iccvQuickSortINT32( INT32 *a, INT32 left, INT32 rght)
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
    iccvQuickSortINT32(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortINT32(a, ii, rght);
  }
//------------------------------- COMMON-CODE INT32           STOP.
}

VOID iccvQuickSortINT64( INT64 *a, INT32 left, INT32 rght)
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
    iccvQuickSortINT64(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortINT64(a, ii, rght);
  }
//------------------------------- COMMON-CODE INT64           STOP.
}

VOID iccvQuickSortUNT08( UNT08 *a, INT32 left, INT32 rght)
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
    iccvQuickSortUNT08(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortUNT08(a, ii, rght);
  }
//------------------------------- COMMON-CODE UNT08           STOP.
}

VOID iccvQuickSortUNT16( UNT16 *a, INT32 left, INT32 rght)
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
    iccvQuickSortUNT16(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortUNT16(a, ii, rght);
  }
//------------------------------- COMMON-CODE UNT16           STOP.
}

VOID iccvQuickSortUNT32( UNT32 *a, INT32 left, INT32 rght)
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
    iccvQuickSortUNT32(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortUNT32(a, ii, rght);
  }
//------------------------------- COMMON-CODE UNT32           STOP.
}

VOID iccvQuickSortUNT64( UNT64 *a, INT32 left, INT32 rght)
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
    iccvQuickSortUNT64(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortUNT64(a, ii, rght);
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
PERL_PREPROCESS    iccvQuickSortXXXXXr(a, left, jj);
PERL_PREPROCESS  }
PERL_PREPROCESS  if(ii < rght)
PERL_PREPROCESS  {
PERL_PREPROCESS    iccvQuickSortXXXXXr(a, ii, rght);
PERL_PREPROCESS  }
#endif

VOID iccvQuickSortCFLT32r( CFLT32 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCFLT32r(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCFLT32r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CFLT32            STOP.
}

VOID iccvQuickSortCFLT64r( CFLT64 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCFLT64r(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCFLT64r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CFLT64           STOP.
}

VOID iccvQuickSortCFLT96r( CFLT96 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCFLT96r(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCFLT96r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CFLT96           STOP.
}

VOID iccvQuickSortCINT08r( CINT08 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCINT08r(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCINT08r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CINT08           STOP.
}

VOID iccvQuickSortCINT16r( CINT16 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCINT16r(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCINT16r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CINT16           STOP.
}

VOID iccvQuickSortCINT32r( CINT32 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCINT32r(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCINT32r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CINT32           STOP.
}

VOID iccvQuickSortCINT64r( CINT64 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCINT64r(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCINT64r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CINT64           STOP.
}

VOID iccvQuickSortCUNT08r( CUNT08 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCUNT08r(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCUNT08r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CUNT08           STOP.
}

VOID iccvQuickSortCUNT16r( CUNT16 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCUNT16r(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCUNT16r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CUNT16           STOP.
}

VOID iccvQuickSortCUNT32r( CUNT32 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCUNT32r(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCUNT32r(a, ii, rght);
  }
//------------------------------- COMMON-CODE CUNT32           STOP.
}

VOID iccvQuickSortCUNT64r( CUNT64 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCUNT64r(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCUNT64r(a, ii, rght);
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
PERL_PREPROCESS    iccvQuickSortXXXXXi(a, left, jj);
PERL_PREPROCESS  }
PERL_PREPROCESS  if(ii < rght)
PERL_PREPROCESS  {
PERL_PREPROCESS    iccvQuickSortXXXXXi(a, ii, rght);
PERL_PREPROCESS  }
#endif

VOID iccvQuickSortCFLT32i( CFLT32 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCFLT32i(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCFLT32i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CFLT32            STOP.
}

VOID iccvQuickSortCFLT64i( CFLT64 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCFLT64i(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCFLT64i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CFLT64           STOP.
}

VOID iccvQuickSortCFLT96i( CFLT96 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCFLT96i(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCFLT96i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CFLT96           STOP.
}

VOID iccvQuickSortCINT08i( CINT08 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCINT08i(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCINT08i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CINT08           STOP.
}

VOID iccvQuickSortCINT16i( CINT16 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCINT16i(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCINT16i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CINT16           STOP.
}

VOID iccvQuickSortCINT32i( CINT32 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCINT32i(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCINT32i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CINT32           STOP.
}

VOID iccvQuickSortCINT64i( CINT64 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCINT64i(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCINT64i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CINT64           STOP.
}

VOID iccvQuickSortCUNT08i( CUNT08 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCUNT08i(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCUNT08i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CUNT08           STOP.
}

VOID iccvQuickSortCUNT16i( CUNT16 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCUNT16i(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCUNT16i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CUNT16           STOP.
}

VOID iccvQuickSortCUNT32i( CUNT32 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCUNT32i(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCUNT32i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CUNT32           STOP.
}

VOID iccvQuickSortCUNT64i( CUNT64 *a, INT32 left, INT32 rght)
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
    iccvQuickSortCUNT64i(a, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortCUNT64i(a, ii, rght);
  }
//------------------------------- COMMON-CODE CUNT64           STOP.
}



VOID iccvQuickSortString( CHR08 **string, INT32 left, INT32 rght)
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
    iccvQuickSortString(string, left, jj);
  }
  if(ii < rght)
  {
    iccvQuickSortString(string, ii, rght);
  }
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
