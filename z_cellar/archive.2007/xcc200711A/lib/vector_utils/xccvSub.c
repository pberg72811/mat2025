/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccvSub.c
// Desc: This file contains the code for the vectorUtils routine xccvSub.
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
PERL_PREPROCESS UNT32 l;
PERL_PREPROCESS XXXXX *pa = a;
PERL_PREPROCESS XXXXX *pb = b;
PERL_PREPROCESS XXXXX *pc = c;
PERL_PREPROCESS for(l=0; l<n; l++)
PERL_PREPROCESS {
PERL_PREPROCESS   *pc = (*pa) - (*pb);
PERL_PREPROCESS   pa+=i;pb+=j;pc+=k;
PERL_PREPROCESS }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID xccvSubFLT32( FLT32 *a, INT32 i, FLT32 *b, INT32 j, FLT32 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE FLT32  START.
 UNT32 l;
 FLT32 *pa = a;
 FLT32 *pb = b;
 FLT32 *pc = c;
 for(l=0; l<n; l++)
 {
   *pc = (*pa) - (*pb);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE FLT32   STOP.
}

VOID xccvSubFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, FLT64 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE FLT64  START.
 UNT32 l;
 FLT64 *pa = a;
 FLT64 *pb = b;
 FLT64 *pc = c;
 for(l=0; l<n; l++)
 {
   *pc = (*pa) - (*pb);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE FLT64   STOP.
}

VOID xccvSubFLT96( FLT96 *a, INT32 i, FLT96 *b, INT32 j, FLT96 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE FLT96  START.
 UNT32 l;
 FLT96 *pa = a;
 FLT96 *pb = b;
 FLT96 *pc = c;
 for(l=0; l<n; l++)
 {
   *pc = (*pa) - (*pb);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE FLT96   STOP.
}

VOID xccvSubINT08( INT08 *a, INT32 i, INT08 *b, INT32 j, INT08 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE INT08  START.
 UNT32 l;
 INT08 *pa = a;
 INT08 *pb = b;
 INT08 *pc = c;
 for(l=0; l<n; l++)
 {
   *pc = (*pa) - (*pb);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE INT08   STOP.
}

VOID xccvSubINT16( INT16 *a, INT32 i, INT16 *b, INT32 j, INT16 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE INT16  START.
 UNT32 l;
 INT16 *pa = a;
 INT16 *pb = b;
 INT16 *pc = c;
 for(l=0; l<n; l++)
 {
   *pc = (*pa) - (*pb);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE INT16   STOP.
}

VOID xccvSubINT32( INT32 *a, INT32 i, INT32 *b, INT32 j, INT32 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE INT32  START.
 UNT32 l;
 INT32 *pa = a;
 INT32 *pb = b;
 INT32 *pc = c;
 for(l=0; l<n; l++)
 {
   *pc = (*pa) - (*pb);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE INT32   STOP.
}

VOID xccvSubINT64( INT64 *a, INT32 i, INT64 *b, INT32 j, INT64 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE INT64  START.
 UNT32 l;
 INT64 *pa = a;
 INT64 *pb = b;
 INT64 *pc = c;
 for(l=0; l<n; l++)
 {
   *pc = (*pa) - (*pb);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE INT64   STOP.
}

VOID xccvSubUNT08( UNT08 *a, INT32 i, UNT08 *b, INT32 j, UNT08 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE UNT08  START.
 UNT32 l;
 UNT08 *pa = a;
 UNT08 *pb = b;
 UNT08 *pc = c;
 for(l=0; l<n; l++)
 {
   *pc = (*pa) - (*pb);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE UNT08   STOP.
}

VOID xccvSubUNT16( UNT16 *a, INT32 i, UNT16 *b, INT32 j, UNT16 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE UNT16  START.
 UNT32 l;
 UNT16 *pa = a;
 UNT16 *pb = b;
 UNT16 *pc = c;
 for(l=0; l<n; l++)
 {
   *pc = (*pa) - (*pb);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE UNT16   STOP.
}

VOID xccvSubUNT32( UNT32 *a, INT32 i, UNT32 *b, INT32 j, UNT32 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE UNT32  START.
 UNT32 l;
 UNT32 *pa = a;
 UNT32 *pb = b;
 UNT32 *pc = c;
 for(l=0; l<n; l++)
 {
   *pc = (*pa) - (*pb);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE UNT32   STOP.
}

VOID xccvSubUNT64( UNT64 *a, INT32 i, UNT64 *b, INT32 j, UNT64 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE UNT64  START.
 UNT32 l;
 UNT64 *pa = a;
 UNT64 *pb = b;
 UNT64 *pc = c;
 for(l=0; l<n; l++)
 {
   *pc = (*pa) - (*pb);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE UNT64   STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS UNT32 l;
PERL_PREPROCESS XXXXX *pa = a;
PERL_PREPROCESS XXXXX *pb = b;
PERL_PREPROCESS XXXXX *pc = c;
PERL_PREPROCESS for(l=0; l<n; l++)
PERL_PREPROCESS {
PERL_PREPROCESS   pc->r = (pa->r) - (pb->r);
PERL_PREPROCESS   pc->i = (pa->i) - (pb->i);
PERL_PREPROCESS   pa+=i;pb+=j;pc+=k;
PERL_PREPROCESS }
#endif

VOID xccvSubCFLT32( CFLT32 *a, INT32 i, CFLT32 *b, INT32 j, CFLT32 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CFLT32  START.
 UNT32 l;
 CFLT32 *pa = a;
 CFLT32 *pb = b;
 CFLT32 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->r = (pa->r) - (pb->r);
   pc->i = (pa->i) - (pb->i);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE CFLT32   STOP.
}

VOID xccvSubCFLT64( CFLT64 *a, INT32 i, CFLT64 *b, INT32 j, CFLT64 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CFLT64  START.
 UNT32 l;
 CFLT64 *pa = a;
 CFLT64 *pb = b;
 CFLT64 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->r = (pa->r) - (pb->r);
   pc->i = (pa->i) - (pb->i);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE CFLT64   STOP.
}

VOID xccvSubCFLT96( CFLT96 *a, INT32 i, CFLT96 *b, INT32 j, CFLT96 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CFLT96  START.
 UNT32 l;
 CFLT96 *pa = a;
 CFLT96 *pb = b;
 CFLT96 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->r = (pa->r) - (pb->r);
   pc->i = (pa->i) - (pb->i);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE CFLT96   STOP.
}

VOID xccvSubCINT08( CINT08 *a, INT32 i, CINT08 *b, INT32 j, CINT08 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CINT08  START.
 UNT32 l;
 CINT08 *pa = a;
 CINT08 *pb = b;
 CINT08 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->r = (pa->r) - (pb->r);
   pc->i = (pa->i) - (pb->i);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE CINT08   STOP.
}

VOID xccvSubCINT16( CINT16 *a, INT32 i, CINT16 *b, INT32 j, CINT16 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CINT16  START.
 UNT32 l;
 CINT16 *pa = a;
 CINT16 *pb = b;
 CINT16 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->r = (pa->r) - (pb->r);
   pc->i = (pa->i) - (pb->i);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE CINT16   STOP.
}

VOID xccvSubCINT32( CINT32 *a, INT32 i, CINT32 *b, INT32 j, CINT32 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CINT32  START.
 UNT32 l;
 CINT32 *pa = a;
 CINT32 *pb = b;
 CINT32 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->r = (pa->r) - (pb->r);
   pc->i = (pa->i) - (pb->i);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE CINT32   STOP.
}

VOID xccvSubCINT64( CINT64 *a, INT32 i, CINT64 *b, INT32 j, CINT64 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CINT64  START.
 UNT32 l;
 CINT64 *pa = a;
 CINT64 *pb = b;
 CINT64 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->r = (pa->r) - (pb->r);
   pc->i = (pa->i) - (pb->i);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE CINT64   STOP.
}

VOID xccvSubCUNT08( CUNT08 *a, INT32 i, CUNT08 *b, INT32 j, CUNT08 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT08  START.
 UNT32 l;
 CUNT08 *pa = a;
 CUNT08 *pb = b;
 CUNT08 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->r = (pa->r) - (pb->r);
   pc->i = (pa->i) - (pb->i);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE CUNT08   STOP.
}

VOID xccvSubCUNT16( CUNT16 *a, INT32 i, CUNT16 *b, INT32 j, CUNT16 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT16  START.
 UNT32 l;
 CUNT16 *pa = a;
 CUNT16 *pb = b;
 CUNT16 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->r = (pa->r) - (pb->r);
   pc->i = (pa->i) - (pb->i);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE CUNT16   STOP.
}

VOID xccvSubCUNT32( CUNT32 *a, INT32 i, CUNT32 *b, INT32 j, CUNT32 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT32  START.
 UNT32 l;
 CUNT32 *pa = a;
 CUNT32 *pb = b;
 CUNT32 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->r = (pa->r) - (pb->r);
   pc->i = (pa->i) - (pb->i);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE CUNT32   STOP.
}

VOID xccvSubCUNT64( CUNT64 *a, INT32 i, CUNT64 *b, INT32 j, CUNT64 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT64  START.
 UNT32 l;
 CUNT64 *pa = a;
 CUNT64 *pb = b;
 CUNT64 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->r = (pa->r) - (pb->r);
   pc->i = (pa->i) - (pb->i);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE CUNT64   STOP.
}



#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS UNT32 l;
PERL_PREPROCESS XXXXX *pa = a;
PERL_PREPROCESS XXXXX *pb = b;
PERL_PREPROCESS XXXXX *pc = c;
PERL_PREPROCESS for(l=0; l<n; l++)
PERL_PREPROCESS {
PERL_PREPROCESS   pc->x = (pa->x) - (pb->x);
PERL_PREPROCESS   pc->y = (pa->y) - (pb->y);
PERL_PREPROCESS   pc->z = (pa->z) - (pb->z);
PERL_PREPROCESS   pa+=i;pb+=j;pc+=k;
PERL_PREPROCESS }
#endif

VOID xccvSubVFLT32( VFLT32 *a, INT32 i, VFLT32 *b, INT32 j, VFLT32 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE VFLT32  START.
 UNT32 l;
 VFLT32 *pa = a;
 VFLT32 *pb = b;
 VFLT32 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->x = (pa->x) - (pb->x);
   pc->y = (pa->y) - (pb->y);
   pc->z = (pa->z) - (pb->z);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE VFLT32   STOP.
}

VOID xccvSubVFLT64( VFLT64 *a, INT32 i, VFLT64 *b, INT32 j, VFLT64 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE VFLT64  START.
 UNT32 l;
 VFLT64 *pa = a;
 VFLT64 *pb = b;
 VFLT64 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->x = (pa->x) - (pb->x);
   pc->y = (pa->y) - (pb->y);
   pc->z = (pa->z) - (pb->z);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE VFLT64   STOP.
}

VOID xccvSubVFLT96( VFLT96 *a, INT32 i, VFLT96 *b, INT32 j, VFLT96 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE VFLT96  START.
 UNT32 l;
 VFLT96 *pa = a;
 VFLT96 *pb = b;
 VFLT96 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->x = (pa->x) - (pb->x);
   pc->y = (pa->y) - (pb->y);
   pc->z = (pa->z) - (pb->z);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE VFLT96   STOP.
}

VOID xccvSubVINT08( VINT08 *a, INT32 i, VINT08 *b, INT32 j, VINT08 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE VINT08  START.
 UNT32 l;
 VINT08 *pa = a;
 VINT08 *pb = b;
 VINT08 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->x = (pa->x) - (pb->x);
   pc->y = (pa->y) - (pb->y);
   pc->z = (pa->z) - (pb->z);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE VINT08   STOP.
}

VOID xccvSubVINT16( VINT16 *a, INT32 i, VINT16 *b, INT32 j, VINT16 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE VINT16  START.
 UNT32 l;
 VINT16 *pa = a;
 VINT16 *pb = b;
 VINT16 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->x = (pa->x) - (pb->x);
   pc->y = (pa->y) - (pb->y);
   pc->z = (pa->z) - (pb->z);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE VINT16   STOP.
}

VOID xccvSubVINT32( VINT32 *a, INT32 i, VINT32 *b, INT32 j, VINT32 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE VINT32  START.
 UNT32 l;
 VINT32 *pa = a;
 VINT32 *pb = b;
 VINT32 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->x = (pa->x) - (pb->x);
   pc->y = (pa->y) - (pb->y);
   pc->z = (pa->z) - (pb->z);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE VINT32   STOP.
}

VOID xccvSubVINT64( VINT64 *a, INT32 i, VINT64 *b, INT32 j, VINT64 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE VINT64  START.
 UNT32 l;
 VINT64 *pa = a;
 VINT64 *pb = b;
 VINT64 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->x = (pa->x) - (pb->x);
   pc->y = (pa->y) - (pb->y);
   pc->z = (pa->z) - (pb->z);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE VINT64   STOP.
}

VOID xccvSubVUNT08( VUNT08 *a, INT32 i, VUNT08 *b, INT32 j, VUNT08 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT08  START.
 UNT32 l;
 VUNT08 *pa = a;
 VUNT08 *pb = b;
 VUNT08 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->x = (pa->x) - (pb->x);
   pc->y = (pa->y) - (pb->y);
   pc->z = (pa->z) - (pb->z);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE VUNT08   STOP.
}

VOID xccvSubVUNT16( VUNT16 *a, INT32 i, VUNT16 *b, INT32 j, VUNT16 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT16  START.
 UNT32 l;
 VUNT16 *pa = a;
 VUNT16 *pb = b;
 VUNT16 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->x = (pa->x) - (pb->x);
   pc->y = (pa->y) - (pb->y);
   pc->z = (pa->z) - (pb->z);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE VUNT16   STOP.
}

VOID xccvSubVUNT32( VUNT32 *a, INT32 i, VUNT32 *b, INT32 j, VUNT32 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT32  START.
 UNT32 l;
 VUNT32 *pa = a;
 VUNT32 *pb = b;
 VUNT32 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->x = (pa->x) - (pb->x);
   pc->y = (pa->y) - (pb->y);
   pc->z = (pa->z) - (pb->z);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE VUNT32   STOP.
}

VOID xccvSubVUNT64( VUNT64 *a, INT32 i, VUNT64 *b, INT32 j, VUNT64 *c, INT32 k, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT64  START.
 UNT32 l;
 VUNT64 *pa = a;
 VUNT64 *pb = b;
 VUNT64 *pc = c;
 for(l=0; l<n; l++)
 {
   pc->x = (pa->x) - (pb->x);
   pc->y = (pa->y) - (pb->y);
   pc->z = (pa->z) - (pb->z);
   pa+=i;pb+=j;pc+=k;
 }
//------------------------------- COMMON-CODE VUNT64   STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
