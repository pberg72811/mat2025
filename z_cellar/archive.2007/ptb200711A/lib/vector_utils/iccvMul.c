/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvMul.c
// Desc: This file contains the code for the vectorUtils routine iccvMul.
// Hist: When       Who  What
//       04/27/2001 ptb  Initial Code.
//       08/19/2003 ptb  Added complex code.
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
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa=a;
PERL_PREPROCESS  XXXXX *pb=b;
PERL_PREPROCESS  XXXXX *pc=c;
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS  for(ii=0; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    *pc = (*pa) * (*pb);
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS    pb+=j;
PERL_PREPROCESS    pc+=k;
PERL_PREPROCESS  }
#endif

VOID iccvMulFLT32( FLT32 *a, INT32 i, FLT32 *b, INT32 j, FLT32 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE FLT32       START.
  FLT32 *pa=a;
  FLT32 *pb=b;
  FLT32 *pc=c;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pc = (*pa) * (*pb);
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE FLT32        STOP.
}

VOID iccvMulFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, FLT64 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE FLT64       START.
  FLT64 *pa=a;
  FLT64 *pb=b;
  FLT64 *pc=c;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pc = (*pa) * (*pb);
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE FLT64        STOP.
}

VOID iccvMulFLT96( FLT96 *a, INT32 i, FLT96 *b, INT32 j,  FLT96 *c, INT32 k,UNT32 n)
{
//------------------------------- COMMON-CODE FLT96       START.
  FLT96 *pa=a;
  FLT96 *pb=b;
  FLT96 *pc=c;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pc = (*pa) * (*pb);
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE FLT96        STOP.
}

VOID iccvMulINT08( INT08 *a, INT32 i, INT08 *b, INT32 j, INT08 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE INT08       START.
  INT08 *pa=a;
  INT08 *pb=b;
  INT08 *pc=c;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pc = (*pa) * (*pb);
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE INT08        STOP.
}

VOID iccvMulINT16( INT16 *a, INT32 i, INT16 *b, INT32 j, INT16 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE INT16       START.
  INT16 *pa=a;
  INT16 *pb=b;
  INT16 *pc=c;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pc = (*pa) * (*pb);
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE INT16        STOP.
}

VOID iccvMulINT32( INT32 *a, INT32 i, INT32 *b, INT32 j, INT32 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE INT32       START.
  INT32 *pa=a;
  INT32 *pb=b;
  INT32 *pc=c;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pc = (*pa) * (*pb);
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE INT32        STOP.
}

VOID iccvMulINT64( INT64 *a, INT32 i, INT64 *b, INT32 j, INT64 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE INT64       START.
  INT64 *pa=a;
  INT64 *pb=b;
  INT64 *pc=c;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pc = (*pa) * (*pb);
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE INT64        STOP.
}

VOID iccvMulUNT08( UNT08 *a, INT32 i, UNT08 *b, INT32 j, UNT08 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE UNT08       START.
  UNT08 *pa=a;
  UNT08 *pb=b;
  UNT08 *pc=c;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pc = (*pa) * (*pb);
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE UNT08        STOP.
}

VOID iccvMulUNT16( UNT16 *a, INT32 i, UNT16 *b, INT32 j, UNT16 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE UNT16       START.
  UNT16 *pa=a;
  UNT16 *pb=b;
  UNT16 *pc=c;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pc = (*pa) * (*pb);
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE UNT16        STOP.
}

VOID iccvMulUNT32( UNT32 *a, INT32 i, UNT32 *b, INT32 j, UNT32 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE UNT32       START.
  UNT32 *pa=a;
  UNT32 *pb=b;
  UNT32 *pc=c;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pc = (*pa) * (*pb);
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE UNT32        STOP.
}

VOID iccvMulUNT64( UNT64 *a, INT32 i, UNT64 *b, INT32 j, UNT64 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE UNT64       START.
  UNT64 *pa=a;
  UNT64 *pb=b;
  UNT64 *pc=c;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    *pc = (*pa) * (*pb);
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE UNT64        STOP.
}


// Handle complex arrays.
//-------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa=a;
PERL_PREPROCESS  XXXXX *pb=b;
PERL_PREPROCESS  XXXXX *pc=c;
PERL_PREPROCESS  XXXXX temp;
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS  for(ii=0; ii<n; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    temp.r = (pa->r * pb->r) - (pa->i * pb->i);
PERL_PREPROCESS    temp.i = (pa->r * pb->i) + (pa->i * pb->r);
PERL_PREPROCESS    pc->r = temp.r;
PERL_PREPROCESS    pc->i = temp.i;
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS    pb+=j;
PERL_PREPROCESS    pc+=k;
PERL_PREPROCESS  }
#endif

VOID iccvMulCFLT32( CFLT32 *a, INT32 i, CFLT32 *b, INT32 j, CFLT32 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CFLT32       START.
  CFLT32 *pa=a;
  CFLT32 *pb=b;
  CFLT32 *pc=c;
  CFLT32 temp;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    temp.r = (pa->r * pb->r) - (pa->i * pb->i);
    temp.i = (pa->r * pb->i) + (pa->i * pb->r);
    pc->r = temp.r;
    pc->i = temp.i;
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE CFLT32        STOP.
}

VOID iccvMulCFLT64( CFLT64 *a, INT32 i, CFLT64 *b, INT32 j, CFLT64 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CFLT64       START.
  CFLT64 *pa=a;
  CFLT64 *pb=b;
  CFLT64 *pc=c;
  CFLT64 temp;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    temp.r = (pa->r * pb->r) - (pa->i * pb->i);
    temp.i = (pa->r * pb->i) + (pa->i * pb->r);
    pc->r = temp.r;
    pc->i = temp.i;
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE CFLT64        STOP.
}

VOID iccvMulCFLT96( CFLT96 *a, INT32 i, CFLT96 *b, INT32 j, CFLT96 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CFLT96      START.
  CFLT96 *pa=a;
  CFLT96 *pb=b;
  CFLT96 *pc=c;
  CFLT96 temp;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    temp.r = (pa->r * pb->r) - (pa->i * pb->i);
    temp.i = (pa->r * pb->i) + (pa->i * pb->r);
    pc->r = temp.r;
    pc->i = temp.i;
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE CFLT96       STOP.
}

VOID iccvMulCINT08( CINT08 *a, INT32 i, CINT08 *b, INT32 j, CINT08 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CINT08      START.
  CINT08 *pa=a;
  CINT08 *pb=b;
  CINT08 *pc=c;
  CINT08 temp;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    temp.r = (pa->r * pb->r) - (pa->i * pb->i);
    temp.i = (pa->r * pb->i) + (pa->i * pb->r);
    pc->r = temp.r;
    pc->i = temp.i;
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE CINT08       STOP.
}

VOID iccvMulCINT16( CINT16 *a, INT32 i, CINT16 *b, INT32 j, CINT16 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CINT16      START.
  CINT16 *pa=a;
  CINT16 *pb=b;
  CINT16 *pc=c;
  CINT16 temp;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    temp.r = (pa->r * pb->r) - (pa->i * pb->i);
    temp.i = (pa->r * pb->i) + (pa->i * pb->r);
    pc->r = temp.r;
    pc->i = temp.i;
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE CINT16       STOP.
}

VOID iccvMulCINT32( CINT32 *a, INT32 i, CINT32 *b, INT32 j, CINT32 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CINT32      START.
  CINT32 *pa=a;
  CINT32 *pb=b;
  CINT32 *pc=c;
  CINT32 temp;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    temp.r = (pa->r * pb->r) - (pa->i * pb->i);
    temp.i = (pa->r * pb->i) + (pa->i * pb->r);
    pc->r = temp.r;
    pc->i = temp.i;
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE CINT32       STOP.
}

VOID iccvMulCINT64( CINT64 *a, INT32 i, CINT64 *b, INT32 j, CINT64 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CINT64      START.
  CINT64 *pa=a;
  CINT64 *pb=b;
  CINT64 *pc=c;
  CINT64 temp;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    temp.r = (pa->r * pb->r) - (pa->i * pb->i);
    temp.i = (pa->r * pb->i) + (pa->i * pb->r);
    pc->r = temp.r;
    pc->i = temp.i;
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE CINT64       STOP.
}

VOID iccvMulCUNT08( CUNT08 *a, INT32 i, CUNT08 *b, INT32 j, CUNT08 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT08      START.
  CUNT08 *pa=a;
  CUNT08 *pb=b;
  CUNT08 *pc=c;
  CUNT08 temp;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    temp.r = (pa->r * pb->r) - (pa->i * pb->i);
    temp.i = (pa->r * pb->i) + (pa->i * pb->r);
    pc->r = temp.r;
    pc->i = temp.i;
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE CUNT08       STOP.
}

VOID iccvMulCUNT16( CUNT16 *a, INT32 i, CUNT16 *b, INT32 j, CUNT16 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT16      START.
  CUNT16 *pa=a;
  CUNT16 *pb=b;
  CUNT16 *pc=c;
  CUNT16 temp;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    temp.r = (pa->r * pb->r) - (pa->i * pb->i);
    temp.i = (pa->r * pb->i) + (pa->i * pb->r);
    pc->r = temp.r;
    pc->i = temp.i;
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE CUNT16       STOP.
}

VOID iccvMulCUNT32( CUNT32 *a, INT32 i, CUNT32 *b, INT32 j, CUNT32 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT32      START.
  CUNT32 *pa=a;
  CUNT32 *pb=b;
  CUNT32 *pc=c;
  CUNT32 temp;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    temp.r = (pa->r * pb->r) - (pa->i * pb->i);
    temp.i = (pa->r * pb->i) + (pa->i * pb->r);
    pc->r = temp.r;
    pc->i = temp.i;
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE CUNT32       STOP.
}

VOID iccvMulCUNT64( CUNT64 *a, INT32 i, CUNT64 *b, INT32 j, CUNT64 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT64      START.
  CUNT64 *pa=a;
  CUNT64 *pb=b;
  CUNT64 *pc=c;
  CUNT64 temp;
  UNT32 ii;
  for(ii=0; ii<n; ii++)
  {
    temp.r = (pa->r * pb->r) - (pa->i * pb->i);
    temp.i = (pa->r * pb->i) + (pa->i * pb->r);
    pc->r = temp.r;
    pc->i = temp.i;
    pa+=i;
    pb+=j;
    pc+=k;
  }
//------------------------------- COMMON-CODE CUNT64       STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
