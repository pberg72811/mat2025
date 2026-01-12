/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvCopy.c
// Desc: This file contains the code for the vectorUtils routine iccvCopy.
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
PERL_PREPROCESS XXXXX *pa;
PERL_PREPROCESS XXXXX *pb;
PERL_PREPROCESS UNT32 k;
PERL_PREPROCESS pa = a;
PERL_PREPROCESS pb = b;
PERL_PREPROCESS for(k=0; k<n; k++)
PERL_PREPROCESS {
PERL_PREPROCESS   *pb = *pa; 
PERL_PREPROCESS   pa+=i; 
PERL_PREPROCESS   pb+=j;
PERL_PREPROCESS }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccvCopyFLT32( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32  START.
 FLT32 *pa;
 FLT32 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE FLT32   STOP.
}

VOID iccvCopyFLT64( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64  START.
 FLT64 *pa;
 FLT64 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE FLT64   STOP.
}

VOID iccvCopyFLT96( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96  START.
 FLT96 *pa;
 FLT96 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE FLT96   STOP.
}

VOID iccvCopyINT08( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT08  START.
 INT08 *pa;
 INT08 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE INT08   STOP.
}

VOID iccvCopyINT16( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT16  START.
 INT16 *pa;
 INT16 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE INT16   STOP.
}

VOID iccvCopyINT32( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT32  START.
 INT32 *pa;
 INT32 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE INT32   STOP.
}

VOID iccvCopyINT64( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT64  START.
 INT64 *pa;
 INT64 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE INT64   STOP.
}

VOID iccvCopyUNT08( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT08  START.
 UNT08 *pa;
 UNT08 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE UNT08   STOP.
}

VOID iccvCopyUNT16( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT16  START.
 UNT16 *pa;
 UNT16 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE UNT16   STOP.
}

VOID iccvCopyUNT32( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT32  START.
 UNT32 *pa;
 UNT32 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE UNT32   STOP.
}

VOID iccvCopyUNT64( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT64  START.
 UNT64 *pa;
 UNT64 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE UNT64   STOP.
}


VOID iccvCopyCFLT32( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT32  START.
 CFLT32 *pa;
 CFLT32 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE CFLT32   STOP.
}

VOID iccvCopyCFLT64( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT64  START.
 CFLT64 *pa;
 CFLT64 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE CFLT64   STOP.
}

VOID iccvCopyCFLT96( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE CFLT96  START.
 CFLT96 *pa;
 CFLT96 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE CFLT96   STOP.
}

VOID iccvCopyCINT08( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CINT08  START.
 CINT08 *pa;
 CINT08 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE CINT08   STOP.
}

VOID iccvCopyCINT16( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CINT16  START.
 CINT16 *pa;
 CINT16 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE CINT16   STOP.
}

VOID iccvCopyCINT32( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CINT32  START.
 CINT32 *pa;
 CINT32 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE CINT32   STOP.
}

VOID iccvCopyCINT64( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CINT64  START.
 CINT64 *pa;
 CINT64 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE CINT64   STOP.
}

VOID iccvCopyCUNT08( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT08  START.
 CUNT08 *pa;
 CUNT08 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE CUNT08   STOP.
}

VOID iccvCopyCUNT16( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT16  START.
 CUNT16 *pa;
 CUNT16 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE CUNT16   STOP.
}

VOID iccvCopyCUNT32( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT32  START.
 CUNT32 *pa;
 CUNT32 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE CUNT32   STOP.
}

VOID iccvCopyCUNT64( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT64  START.
 CUNT64 *pa;
 CUNT64 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE CUNT64   STOP.
}


VOID iccvCopyVFLT32( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE VFLT32  START.
 VFLT32 *pa;
 VFLT32 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE VFLT32   STOP.
}

VOID iccvCopyVFLT64( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE VFLT64  START.
 VFLT64 *pa;
 VFLT64 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE VFLT64   STOP.
}

VOID iccvCopyVFLT96( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE VFLT96  START.
 VFLT96 *pa;
 VFLT96 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE VFLT96   STOP.
}

VOID iccvCopyVINT08( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE VINT08  START.
 VINT08 *pa;
 VINT08 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE VINT08   STOP.
}

VOID iccvCopyVINT16( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE VINT16  START.
 VINT16 *pa;
 VINT16 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE VINT16   STOP.
}

VOID iccvCopyVINT32( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE VINT32  START.
 VINT32 *pa;
 VINT32 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE VINT32   STOP.
}

VOID iccvCopyVINT64( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE VINT64  START.
 VINT64 *pa;
 VINT64 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE VINT64   STOP.
}

VOID iccvCopyVUNT08( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT08  START.
 VUNT08 *pa;
 VUNT08 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE VUNT08   STOP.
}

VOID iccvCopyVUNT16( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT16  START.
 VUNT16 *pa;
 VUNT16 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE VUNT16   STOP.
}

VOID iccvCopyVUNT32( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT32  START.
 VUNT32 *pa;
 VUNT32 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE VUNT32   STOP.
}

VOID iccvCopyVUNT64( VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT64  START.
 VUNT64 *pa;
 VUNT64 *pb;
 UNT32 k;
 pa = a;
 pb = b;
 for(k=0; k<n; k++)
 {
   *pb = *pa; 
   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE VUNT64   STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
