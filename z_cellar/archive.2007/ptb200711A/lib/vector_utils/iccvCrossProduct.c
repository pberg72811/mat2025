/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvCrossProduct.c
// Desc: This file contains the code for the vectorUtils routine iccvCrossProduct.
// Hist: When       Who  What
//       09/10/2003 ptb  Initial Code.
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
PERL_PREPROCESS  c[0] = a[1]*b[2] - b[1]*a[2];
PERL_PREPROCESS  c[1] = a[2]*b[0] - b[2]*a[0];
PERL_PREPROCESS  c[2] = a[0]*b[1] - b[0]*a[1];
#endif

VOID iccvCrossProductFLT32(FLT32 *a, FLT32 *b, FLT32 *c)
{
//------------------------------- COMMON-CODE FLT32      START.
  c[0] = a[1]*b[2] - b[1]*a[2];
  c[1] = a[2]*b[0] - b[2]*a[0];
  c[2] = a[0]*b[1] - b[0]*a[1];
//------------------------------- COMMON-CODE FLT32       STOP.
}

VOID iccvCrossProductFLT64(FLT64 *a, FLT64 *b, FLT64 *c)
{
//------------------------------- COMMON-CODE FLT64      START.
  c[0] = a[1]*b[2] - b[1]*a[2];
  c[1] = a[2]*b[0] - b[2]*a[0];
  c[2] = a[0]*b[1] - b[0]*a[1];
//------------------------------- COMMON-CODE FLT64       STOP.
}

VOID iccvCrossProductFLT96(FLT96 *a, FLT96 *b, FLT96 *c)
{
//------------------------------- COMMON-CODE FLT96      START.
  c[0] = a[1]*b[2] - b[1]*a[2];
  c[1] = a[2]*b[0] - b[2]*a[0];
  c[2] = a[0]*b[1] - b[0]*a[1];
//------------------------------- COMMON-CODE FLT96       STOP.
}

VOID iccvCrossProductINT08(INT08 *a, INT08 *b, INT08 *c)
{
//------------------------------- COMMON-CODE INT08      START.
  c[0] = a[1]*b[2] - b[1]*a[2];
  c[1] = a[2]*b[0] - b[2]*a[0];
  c[2] = a[0]*b[1] - b[0]*a[1];
//------------------------------- COMMON-CODE INT08       STOP.
}

VOID iccvCrossProductINT16(INT16 *a, INT16 *b, INT16 *c)
{
//------------------------------- COMMON-CODE INT16      START.
  c[0] = a[1]*b[2] - b[1]*a[2];
  c[1] = a[2]*b[0] - b[2]*a[0];
  c[2] = a[0]*b[1] - b[0]*a[1];
//------------------------------- COMMON-CODE INT16       STOP.
}

VOID iccvCrossProductINT32(INT32 *a, INT32 *b, INT32 *c)
{
//------------------------------- COMMON-CODE INT32      START.
  c[0] = a[1]*b[2] - b[1]*a[2];
  c[1] = a[2]*b[0] - b[2]*a[0];
  c[2] = a[0]*b[1] - b[0]*a[1];
//------------------------------- COMMON-CODE INT32       STOP.
}

VOID iccvCrossProductINT64(INT64 *a, INT64 *b, INT64 *c)
{
//------------------------------- COMMON-CODE INT64      START.
  c[0] = a[1]*b[2] - b[1]*a[2];
  c[1] = a[2]*b[0] - b[2]*a[0];
  c[2] = a[0]*b[1] - b[0]*a[1];
//------------------------------- COMMON-CODE INT64       STOP.
}

VOID iccvCrossProductUNT08(UNT08 *a, UNT08 *b, UNT08 *c)
{
//------------------------------- COMMON-CODE UNT08      START.
  c[0] = a[1]*b[2] - b[1]*a[2];
  c[1] = a[2]*b[0] - b[2]*a[0];
  c[2] = a[0]*b[1] - b[0]*a[1];
//------------------------------- COMMON-CODE UNT08       STOP.
}

VOID iccvCrossProductUNT16(UNT16 *a, UNT16 *b, UNT16 *c)
{
//------------------------------- COMMON-CODE UNT16      START.
  c[0] = a[1]*b[2] - b[1]*a[2];
  c[1] = a[2]*b[0] - b[2]*a[0];
  c[2] = a[0]*b[1] - b[0]*a[1];
//------------------------------- COMMON-CODE UNT16       STOP.
}

VOID iccvCrossProductUNT32(UNT32 *a, UNT32 *b, UNT32 *c)
{
//------------------------------- COMMON-CODE UNT32      START.
  c[0] = a[1]*b[2] - b[1]*a[2];
  c[1] = a[2]*b[0] - b[2]*a[0];
  c[2] = a[0]*b[1] - b[0]*a[1];
//------------------------------- COMMON-CODE UNT32       STOP.
}

VOID iccvCrossProductUNT64(UNT64 *a, UNT64 *b, UNT64 *c)
{
//------------------------------- COMMON-CODE UNT64      START.
  c[0] = a[1]*b[2] - b[1]*a[2];
  c[1] = a[2]*b[0] - b[2]*a[0];
  c[2] = a[0]*b[1] - b[0]*a[1];
//------------------------------- COMMON-CODE UNT64       STOP.
}

// Handle 3 element vector types.
//-------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX c;
PERL_PREPROCESS  c.x = a.y*b.z - b.y*a.z;
PERL_PREPROCESS  c.y = a.z*b.x - b.z*a.x;
PERL_PREPROCESS  c.z = a.x*b.y - b.x*a.y;
PERL_PREPROCESS  return c;
#endif

VFLT32 iccCrossProductVFLT32(VFLT32 a, VFLT32 b)
{
//------------------------------- COMMON-CODE VFLT32      START.
  VFLT32 c;
  c.x = a.y*b.z - b.y*a.z;
  c.y = a.z*b.x - b.z*a.x;
  c.z = a.x*b.y - b.x*a.y;
  return c;
//------------------------------- COMMON-CODE VFLT32       STOP.
}

VFLT64 iccCrossProductVFLT64(VFLT64 a, VFLT64 b)
{
//------------------------------- COMMON-CODE VFLT64      START.
  VFLT64 c;
  c.x = a.y*b.z - b.y*a.z;
  c.y = a.z*b.x - b.z*a.x;
  c.z = a.x*b.y - b.x*a.y;
  return c;
//------------------------------- COMMON-CODE VFLT64       STOP.
}

VFLT96 iccCrossProductVFLT96(VFLT96 a, VFLT96 b)
{
//------------------------------- COMMON-CODE VFLT96      START.
  VFLT96 c;
  c.x = a.y*b.z - b.y*a.z;
  c.y = a.z*b.x - b.z*a.x;
  c.z = a.x*b.y - b.x*a.y;
  return c;
//------------------------------- COMMON-CODE VFLT96       STOP.
}

VINT08 iccCrossProductVINT08(VINT08 a, VINT08 b)
{
//------------------------------- COMMON-CODE VINT08      START.
  VINT08 c;
  c.x = a.y*b.z - b.y*a.z;
  c.y = a.z*b.x - b.z*a.x;
  c.z = a.x*b.y - b.x*a.y;
  return c;
//------------------------------- COMMON-CODE VINT08       STOP.
}

VINT16 iccCrossProductVINT16(VINT16 a, VINT16 b)
{
//------------------------------- COMMON-CODE VINT16      START.
  VINT16 c;
  c.x = a.y*b.z - b.y*a.z;
  c.y = a.z*b.x - b.z*a.x;
  c.z = a.x*b.y - b.x*a.y;
  return c;
//------------------------------- COMMON-CODE VINT16       STOP.
}

VINT32 iccCrossProductVINT32(VINT32 a, VINT32 b)
{
//------------------------------- COMMON-CODE VINT32      START.
  VINT32 c;
  c.x = a.y*b.z - b.y*a.z;
  c.y = a.z*b.x - b.z*a.x;
  c.z = a.x*b.y - b.x*a.y;
  return c;
//------------------------------- COMMON-CODE VINT32       STOP.
}

VINT64 iccCrossProductVINT64(VINT64 a, VINT64 b)
{
//------------------------------- COMMON-CODE VINT64      START.
  VINT64 c;
  c.x = a.y*b.z - b.y*a.z;
  c.y = a.z*b.x - b.z*a.x;
  c.z = a.x*b.y - b.x*a.y;
  return c;
//------------------------------- COMMON-CODE VINT64       STOP.
}

VUNT08 iccCrossProductVUNT08(VUNT08 a, VUNT08 b)
{
//------------------------------- COMMON-CODE VUNT08      START.
  VUNT08 c;
  c.x = a.y*b.z - b.y*a.z;
  c.y = a.z*b.x - b.z*a.x;
  c.z = a.x*b.y - b.x*a.y;
  return c;
//------------------------------- COMMON-CODE VUNT08       STOP.
}

VUNT16 iccCrossProductVUNT16(VUNT16 a, VUNT16 b)
{
//------------------------------- COMMON-CODE VUNT16      START.
  VUNT16 c;
  c.x = a.y*b.z - b.y*a.z;
  c.y = a.z*b.x - b.z*a.x;
  c.z = a.x*b.y - b.x*a.y;
  return c;
//------------------------------- COMMON-CODE VUNT16       STOP.
}

VUNT32 iccCrossProductVUNT32(VUNT32 a, VUNT32 b)
{
//------------------------------- COMMON-CODE VUNT32      START.
  VUNT32 c;
  c.x = a.y*b.z - b.y*a.z;
  c.y = a.z*b.x - b.z*a.x;
  c.z = a.x*b.y - b.x*a.y;
  return c;
//------------------------------- COMMON-CODE VUNT32       STOP.
}

VUNT64 iccCrossProductVUNT64(VUNT64 a, VUNT64 b)
{
//------------------------------- COMMON-CODE VUNT64      START.
  VUNT64 c;
  c.x = a.y*b.z - b.y*a.z;
  c.y = a.z*b.x - b.z*a.x;
  c.z = a.x*b.y - b.x*a.y;
  return c;
//------------------------------- COMMON-CODE VUNT64       STOP.
}

// Handle 3 seperate element per vector.
//-------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  *c0 = a1*b2 - b1*a2;
PERL_PREPROCESS  *c1 = a2*b0 - b2*a0;
PERL_PREPROCESS  *c2 = a0*b1 - b0*a1;
#endif

VOID iccCrossProductFLT32(FLT32  a0, FLT32  a1, FLT32  a2,
                          FLT32  b0, FLT32  b1, FLT32  b2,
                          FLT32 *c0, FLT32 *c1, FLT32 *c2)
{
//------------------------------- COMMON-CODE      START.
  *c0 = a1*b2 - b1*a2;
  *c1 = a2*b0 - b2*a0;
  *c2 = a0*b1 - b0*a1;
//------------------------------- COMMON-CODE       STOP.
}

VOID iccCrossProductFLT64(FLT64  a0, FLT64  a1, FLT64  a2,
                          FLT64  b0, FLT64  b1, FLT64  b2,
                          FLT64 *c0, FLT64 *c1, FLT64 *c2)
{
//------------------------------- COMMON-CODE      START.
  *c0 = a1*b2 - b1*a2;
  *c1 = a2*b0 - b2*a0;
  *c2 = a0*b1 - b0*a1;
//------------------------------- COMMON-CODE       STOP.
}

VOID iccCrossProductFLT96(FLT96  a0, FLT96  a1, FLT96  a2,
                          FLT96  b0, FLT96  b1, FLT96  b2,
                          FLT96 *c0, FLT96 *c1, FLT96 *c2)
{
//------------------------------- COMMON-CODE      START.
  *c0 = a1*b2 - b1*a2;
  *c1 = a2*b0 - b2*a0;
  *c2 = a0*b1 - b0*a1;
//------------------------------- COMMON-CODE       STOP.
}

VOID iccCrossProductINT08(INT08  a0, INT08  a1, INT08  a2,
                          INT08  b0, INT08  b1, INT08  b2,
                          INT08 *c0, INT08 *c1, INT08 *c2)
{
//------------------------------- COMMON-CODE      START.
  *c0 = a1*b2 - b1*a2;
  *c1 = a2*b0 - b2*a0;
  *c2 = a0*b1 - b0*a1;
//------------------------------- COMMON-CODE       STOP.
}

VOID iccCrossProductINT16(INT16  a0, INT16  a1, INT16  a2,
                          INT16  b0, INT16  b1, INT16  b2,
                          INT16 *c0, INT16 *c1, INT16 *c2)
{
//------------------------------- COMMON-CODE      START.
  *c0 = a1*b2 - b1*a2;
  *c1 = a2*b0 - b2*a0;
  *c2 = a0*b1 - b0*a1;
//------------------------------- COMMON-CODE       STOP.
}

VOID iccCrossProductINT32(INT32  a0, INT32  a1, INT32  a2,
                          INT32  b0, INT32  b1, INT32  b2,
                          INT32 *c0, INT32 *c1, INT32 *c2)
{
//------------------------------- COMMON-CODE      START.
  *c0 = a1*b2 - b1*a2;
  *c1 = a2*b0 - b2*a0;
  *c2 = a0*b1 - b0*a1;
//------------------------------- COMMON-CODE       STOP.
}

VOID iccCrossProductINT64(INT64  a0, INT64  a1, INT64  a2,
                          INT64  b0, INT64  b1, INT64  b2,
                          INT64 *c0, INT64 *c1, INT64 *c2)
{
//------------------------------- COMMON-CODE      START.
  *c0 = a1*b2 - b1*a2;
  *c1 = a2*b0 - b2*a0;
  *c2 = a0*b1 - b0*a1;
//------------------------------- COMMON-CODE       STOP.
}

VOID iccCrossProductUNT08(UNT08  a0, UNT08  a1, UNT08  a2,
                          UNT08  b0, UNT08  b1, UNT08  b2,
                          UNT08 *c0, UNT08 *c1, UNT08 *c2)
{
//------------------------------- COMMON-CODE      START.
  *c0 = a1*b2 - b1*a2;
  *c1 = a2*b0 - b2*a0;
  *c2 = a0*b1 - b0*a1;
//------------------------------- COMMON-CODE       STOP.
}

VOID iccCrossProductUNT16(UNT16  a0, UNT16  a1, UNT16  a2,
                          UNT16  b0, UNT16  b1, UNT16  b2,
                          UNT16 *c0, UNT16 *c1, UNT16 *c2)
{
//------------------------------- COMMON-CODE      START.
  *c0 = a1*b2 - b1*a2;
  *c1 = a2*b0 - b2*a0;
  *c2 = a0*b1 - b0*a1;
//------------------------------- COMMON-CODE       STOP.
}

VOID iccCrossProductUNT32(UNT32  a0, UNT32  a1, UNT32  a2,
                          UNT32  b0, UNT32  b1, UNT32  b2,
                          UNT32 *c0, UNT32 *c1, UNT32 *c2)
{
//------------------------------- COMMON-CODE      START.
  *c0 = a1*b2 - b1*a2;
  *c1 = a2*b0 - b2*a0;
  *c2 = a0*b1 - b0*a1;
//------------------------------- COMMON-CODE       STOP.
}

VOID iccCrossProductUNT64(UNT64  a0, UNT64  a1, UNT64  a2,
                          UNT64  b0, UNT64  b1, UNT64  b2,
                          UNT64 *c0, UNT64 *c1, UNT64 *c2)
{
//------------------------------- COMMON-CODE      START.
  *c0 = a1*b2 - b1*a2;
  *c1 = a2*b0 - b2*a0;
  *c2 = a0*b1 - b0*a1;
//------------------------------- COMMON-CODE       STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
