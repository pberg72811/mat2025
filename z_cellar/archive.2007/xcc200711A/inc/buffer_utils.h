/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: buffer_utils.h
// Desc: This is the header file for buffer_utils.
// Hist: When       Who  What
//       08/18/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef BUFFER_UTILS_H
#define BUFFER_UTILS_H
 
#ifdef __cplusplus 
extern "C" { 
#endif 
 
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "xmc.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define xcc_BUFFER_NAME_LENGTH 64
#define xcc_BUFFER_TYPE_LENGTH  8

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define COMMON_BUFFER_ELEMENTS  CHR08 name[xcc_BUFFER_NAME_LENGTH]; \
                                CHR08 type[xcc_BUFFER_TYPE_LENGTH]; \
                                UNT32 size;                         \
                                UNT32 index;                        \
                                UNT32 pndex;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  FLT32 *theBuffer;
  FLT32 theSum;
} xccBufferFLT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  FLT64 *theBuffer;
  FLT64 theSum;
} xccBufferFLT64_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  FLT96 *theBuffer;
  FLT96 theSum;
} xccBufferFLT96_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  INT08 *theBuffer;
  INT32 theSum;
} xccBufferINT08_t;
 
typedef struct
{
  COMMON_BUFFER_ELEMENTS
  INT16 *theBuffer;
  INT32 theSum;
} xccBufferINT16_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  INT32 *theBuffer;
  INT32 theSum;
} xccBufferINT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  INT64 *theBuffer;
  INT64 theSum;
} xccBufferINT64_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  UNT08 *theBuffer;
  UNT32 theSum;
} xccBufferUNT08_t;
 
typedef struct
{
  COMMON_BUFFER_ELEMENTS
  UNT16 *theBuffer;
  UNT32 theSum;
} xccBufferUNT16_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  UNT32 *theBuffer;
  UNT32 theSum;
} xccBufferUNT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  UNT64 *theBuffer;
  UNT64 theSum;
} xccBufferUNT64_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VOID **theBuffer;
} xccBufferVOIDP_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CFLT32 *theBuffer;
  CFLT32 theSum;
} xccBufferCFLT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CFLT64 *theBuffer;
  CFLT64 theSum;
} xccBufferCFLT64_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CFLT96 *theBuffer;
  CFLT96 theSum;
} xccBufferCFLT96_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CINT08 *theBuffer;
  CINT32 theSum;
} xccBufferCINT08_t;
 
typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CINT16 *theBuffer;
  CINT32 theSum;
} xccBufferCINT16_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CINT32 *theBuffer;
  CINT32 theSum;
} xccBufferCINT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CINT64 *theBuffer;
  CINT64 theSum;
} xccBufferCINT64_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CUNT08 *theBuffer;
  CUNT32 theSum;
} xccBufferCUNT08_t;
 
typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CUNT16 *theBuffer;
  CUNT32 theSum;
} xccBufferCUNT16_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CUNT32 *theBuffer;
  CUNT32 theSum;
} xccBufferCUNT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CUNT64 *theBuffer;
  CUNT64 theSum;
} xccBufferCUNT64_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VFLT32 *theBuffer;
  VFLT32 theSum;
} xccBufferVFLT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VFLT64 *theBuffer;
  VFLT64 theSum;
} xccBufferVFLT64_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VFLT96 *theBuffer;
  VFLT96 theSum;
} xccBufferVFLT96_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VINT08 *theBuffer;
  VINT32 theSum;
} xccBufferVINT08_t;
 
typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VINT16 *theBuffer;
  VINT32 theSum;
} xccBufferVINT16_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VINT32 *theBuffer;
  VINT32 theSum;
} xccBufferVINT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VINT64 *theBuffer;
  VINT64 theSum;
} xccBufferVINT64_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VUNT08 *theBuffer;
  VUNT32 theSum;
} xccBufferVUNT08_t;
 
typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VUNT16 *theBuffer;
  VUNT32 theSum;
} xccBufferVUNT16_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VUNT32 *theBuffer;
  VUNT32 theSum;
} xccBufferVUNT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VUNT64 *theBuffer;
  VUNT64 theSum;
} xccBufferVUNT64_t;

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

/* xccBufferClear ----------------------------------------------------------------*/
VOID  xccBufferClearFLT32 (xccBufferFLT32_t  *p);
VOID  xccBufferClearFLT64 (xccBufferFLT64_t  *p);
VOID  xccBufferClearFLT96 (xccBufferFLT96_t  *p);
VOID  xccBufferClearINT08 (xccBufferINT08_t  *p);
VOID  xccBufferClearINT16 (xccBufferINT16_t  *p);
VOID  xccBufferClearINT32 (xccBufferINT32_t  *p);
VOID  xccBufferClearINT64 (xccBufferINT64_t  *p);
VOID  xccBufferClearUNT08 (xccBufferUNT08_t  *p);
VOID  xccBufferClearUNT16 (xccBufferUNT16_t  *p);
VOID  xccBufferClearUNT32 (xccBufferUNT32_t  *p);
VOID  xccBufferClearUNT64 (xccBufferUNT64_t  *p);
VOID  xccBufferClearVOIDP (xccBufferVOIDP_t  *p);
VOID  xccBufferClearCFLT32(xccBufferCFLT32_t *p);
VOID  xccBufferClearCFLT64(xccBufferCFLT64_t *p);
VOID  xccBufferClearCFLT96(xccBufferCFLT96_t *p);
VOID  xccBufferClearCINT08(xccBufferCINT08_t *p);
VOID  xccBufferClearCINT16(xccBufferCINT16_t *p);
VOID  xccBufferClearCINT32(xccBufferCINT32_t *p);
VOID  xccBufferClearCINT64(xccBufferCINT64_t *p);
VOID  xccBufferClearCUNT08(xccBufferCUNT08_t *p);
VOID  xccBufferClearCUNT16(xccBufferCUNT16_t *p);
VOID  xccBufferClearCUNT32(xccBufferCUNT32_t *p);
VOID  xccBufferClearCUNT64(xccBufferCUNT64_t *p);
VOID  xccBufferClearVFLT32(xccBufferVFLT32_t *p);
VOID  xccBufferClearVFLT64(xccBufferVFLT64_t *p);
VOID  xccBufferClearVFLT96(xccBufferVFLT96_t *p);
VOID  xccBufferClearVINT08(xccBufferVINT08_t *p);
VOID  xccBufferClearVINT16(xccBufferVINT16_t *p);
VOID  xccBufferClearVINT32(xccBufferVINT32_t *p);
VOID  xccBufferClearVINT64(xccBufferVINT64_t *p);
VOID  xccBufferClearVUNT08(xccBufferVUNT08_t *p);
VOID  xccBufferClearVUNT16(xccBufferVUNT16_t *p);
VOID  xccBufferClearVUNT32(xccBufferVUNT32_t *p);
VOID  xccBufferClearVUNT64(xccBufferVUNT64_t *p);


/* xccBufferInit -----------------------------------------------------------------*/
xccBufferFLT32_t  *xccBufferInitFLT32 (UNT32 size, CCHAR *name);
xccBufferFLT64_t  *xccBufferInitFLT64 (UNT32 size, CCHAR *name);
xccBufferFLT96_t  *xccBufferInitFLT96 (UNT32 size, CCHAR *name);
xccBufferINT08_t  *xccBufferInitINT08 (UNT32 size, CCHAR *name);
xccBufferINT16_t  *xccBufferInitINT16 (UNT32 size, CCHAR *name);
xccBufferINT32_t  *xccBufferInitINT32 (UNT32 size, CCHAR *name);
xccBufferINT64_t  *xccBufferInitINT64 (UNT32 size, CCHAR *name);
xccBufferUNT08_t  *xccBufferInitUNT08 (UNT32 size, CCHAR *name);
xccBufferUNT16_t  *xccBufferInitUNT16 (UNT32 size, CCHAR *name);
xccBufferUNT32_t  *xccBufferInitUNT32 (UNT32 size, CCHAR *name);
xccBufferUNT64_t  *xccBufferInitUNT64 (UNT32 size, CCHAR *name);
xccBufferVOIDP_t  *xccBufferInitVOIDP (UNT32 size, CCHAR *name);
xccBufferCFLT32_t *xccBufferInitCFLT32(UNT32 size, CCHAR *name);
xccBufferCFLT64_t *xccBufferInitCFLT64(UNT32 size, CCHAR *name);
xccBufferCFLT96_t *xccBufferInitCFLT96(UNT32 size, CCHAR *name);
xccBufferCINT08_t *xccBufferInitCINT08(UNT32 size, CCHAR *name);
xccBufferCINT16_t *xccBufferInitCINT16(UNT32 size, CCHAR *name);
xccBufferCINT32_t *xccBufferInitCINT32(UNT32 size, CCHAR *name);
xccBufferCINT64_t *xccBufferInitCINT64(UNT32 size, CCHAR *name);
xccBufferCUNT08_t *xccBufferInitCUNT08(UNT32 size, CCHAR *name);
xccBufferCUNT16_t *xccBufferInitCUNT16(UNT32 size, CCHAR *name);
xccBufferCUNT32_t *xccBufferInitCUNT32(UNT32 size, CCHAR *name);
xccBufferCUNT64_t *xccBufferInitCUNT64(UNT32 size, CCHAR *name);
xccBufferVFLT32_t *xccBufferInitVFLT32(UNT32 size, CCHAR *name);
xccBufferVFLT64_t *xccBufferInitVFLT64(UNT32 size, CCHAR *name);
xccBufferVFLT96_t *xccBufferInitVFLT96(UNT32 size, CCHAR *name);
xccBufferVINT08_t *xccBufferInitVINT08(UNT32 size, CCHAR *name);
xccBufferVINT16_t *xccBufferInitVINT16(UNT32 size, CCHAR *name);
xccBufferVINT32_t *xccBufferInitVINT32(UNT32 size, CCHAR *name);
xccBufferVINT64_t *xccBufferInitVINT64(UNT32 size, CCHAR *name);
xccBufferVUNT08_t *xccBufferInitVUNT08(UNT32 size, CCHAR *name);
xccBufferVUNT16_t *xccBufferInitVUNT16(UNT32 size, CCHAR *name);
xccBufferVUNT32_t *xccBufferInitVUNT32(UNT32 size, CCHAR *name);
xccBufferVUNT64_t *xccBufferInitVUNT64(UNT32 size, CCHAR *name);

VOID xccBufferSumFLT32( VOID *a );
VOID xccBufferSumFLT64( VOID *a );
VOID xccBufferSumFLT96( VOID *a );
VOID xccBufferSumINT08( VOID *a );
VOID xccBufferSumINT16( VOID *a );
VOID xccBufferSumINT32( VOID *a );
VOID xccBufferSumINT64( VOID *a );
VOID xccBufferSumUNT08( VOID *a );
VOID xccBufferSumUNT16( VOID *a );
VOID xccBufferSumUNT32( VOID *a );
VOID xccBufferSumUNT64( VOID *a );
VOID xccBufferSumCFLT32( VOID *a );
VOID xccBufferSumCFLT64( VOID *a );
VOID xccBufferSumCFLT96( VOID *a );
VOID xccBufferSumCINT08( VOID *a );
VOID xccBufferSumCINT16( VOID *a );
VOID xccBufferSumCINT32( VOID *a );
VOID xccBufferSumCINT64( VOID *a );
VOID xccBufferSumCUNT08( VOID *a );
VOID xccBufferSumCUNT16( VOID *a );
VOID xccBufferSumCUNT32( VOID *a );
VOID xccBufferSumCUNT64( VOID *a );
VOID xccBufferSumVFLT32( VOID *a );
VOID xccBufferSumVFLT64( VOID *a );
VOID xccBufferSumVFLT96( VOID *a );
VOID xccBufferSumVINT08( VOID *a );
VOID xccBufferSumVINT16( VOID *a );
VOID xccBufferSumVINT32( VOID *a );
VOID xccBufferSumVINT64( VOID *a );
VOID xccBufferSumVUNT08( VOID *a );
VOID xccBufferSumVUNT16( VOID *a );
VOID xccBufferSumVUNT32( VOID *a );
VOID xccBufferSumVUNT64( VOID *a );

/* xccBufferWrite -----------------------------------------------------------------*/
VOID xccBufferWriteFLT32 ( VOID *a, VOID *b );
VOID xccBufferWriteFLT64 ( VOID *a, VOID *b );
VOID xccBufferWriteFLT96 ( VOID *a, VOID *b );
VOID xccBufferWriteINT08 ( VOID *a, VOID *b );
VOID xccBufferWriteINT16 ( VOID *a, VOID *b );
VOID xccBufferWriteINT32 ( VOID *a, VOID *b );
VOID xccBufferWriteINT64 ( VOID *a, VOID *b );
VOID xccBufferWriteUNT08 ( VOID *a, VOID *b );
VOID xccBufferWriteUNT16 ( VOID *a, VOID *b );
VOID xccBufferWriteUNT32 ( VOID *a, VOID *b );
VOID xccBufferWriteUNT64 ( VOID *a, VOID *b );
VOID xccBufferWriteCFLT32( VOID *a, VOID *b );
VOID xccBufferWriteCFLT64( VOID *a, VOID *b );
VOID xccBufferWriteCFLT96( VOID *a, VOID *b );
VOID xccBufferWriteCINT08( VOID *a, VOID *b );
VOID xccBufferWriteCINT16( VOID *a, VOID *b );
VOID xccBufferWriteCINT32( VOID *a, VOID *b );
VOID xccBufferWriteCINT64( VOID *a, VOID *b );
VOID xccBufferWriteCUNT08( VOID *a, VOID *b );
VOID xccBufferWriteCUNT16( VOID *a, VOID *b );
VOID xccBufferWriteCUNT32( VOID *a, VOID *b );
VOID xccBufferWriteCUNT64( VOID *a, VOID *b );
VOID xccBufferWriteVFLT32( VOID *a, VOID *b );
VOID xccBufferWriteVFLT64( VOID *a, VOID *b );
VOID xccBufferWriteVFLT96( VOID *a, VOID *b );
VOID xccBufferWriteVINT08( VOID *a, VOID *b );
VOID xccBufferWriteVINT16( VOID *a, VOID *b );
VOID xccBufferWriteVINT32( VOID *a, VOID *b );
VOID xccBufferWriteVINT64( VOID *a, VOID *b );
VOID xccBufferWriteVUNT08( VOID *a, VOID *b );
VOID xccBufferWriteVUNT16( VOID *a, VOID *b );
VOID xccBufferWriteVUNT32( VOID *a, VOID *b );
VOID xccBufferWriteVUNT64( VOID *a, VOID *b );
VOID xccBufferWriteFLT32FLT64( VOID *a, VOID *b );
VOID xccBufferWriteFLT32INT08( VOID *a, VOID *b );
VOID xccBufferWriteFLT32INT16( VOID *a, VOID *b );
VOID xccBufferWriteFLT32INT32( VOID *a, VOID *b );
VOID xccBufferWriteFLT32INT64( VOID *a, VOID *b );
VOID xccBufferWriteFLT32UNT08( VOID *a, VOID *b );
VOID xccBufferWriteFLT32UNT16( VOID *a, VOID *b );
VOID xccBufferWriteFLT32UNT32( VOID *a, VOID *b );
VOID xccBufferWriteFLT32UNT64( VOID *a, VOID *b );
VOID xccBufferWriteCFLT32CFLT64( VOID *a, VOID *b );
VOID xccBufferWriteCFLT32CINT08( VOID *a, VOID *b );
VOID xccBufferWriteCFLT32CINT16( VOID *a, VOID *b );
VOID xccBufferWriteCFLT32CINT32( VOID *a, VOID *b );
VOID xccBufferWriteCFLT32CINT64( VOID *a, VOID *b );
VOID xccBufferWriteCFLT32CUNT08( VOID *a, VOID *b );
VOID xccBufferWriteCFLT32CUNT16( VOID *a, VOID *b );
VOID xccBufferWriteCFLT32CUNT32( VOID *a, VOID *b );
VOID xccBufferWriteCFLT32CUNT64( VOID *a, VOID *b );

/* xccBufferWriteSum -----------------------------------------------------------------*/
VOID xccBufferWriteSumFLT32 ( VOID *a, VOID *b );
VOID xccBufferWriteSumFLT64 ( VOID *a, VOID *b );
VOID xccBufferWriteSumFLT96 ( VOID *a, VOID *b );
VOID xccBufferWriteSumINT08 ( VOID *a, VOID *b );
VOID xccBufferWriteSumINT16 ( VOID *a, VOID *b );
VOID xccBufferWriteSumINT32 ( VOID *a, VOID *b );
VOID xccBufferWriteSumINT64 ( VOID *a, VOID *b );
VOID xccBufferWriteSumUNT08 ( VOID *a, VOID *b );
VOID xccBufferWriteSumUNT16 ( VOID *a, VOID *b );
VOID xccBufferWriteSumUNT32 ( VOID *a, VOID *b );
VOID xccBufferWriteSumUNT64 ( VOID *a, VOID *b );
VOID xccBufferWriteSumCFLT32( VOID *a, VOID *b );
VOID xccBufferWriteSumCFLT64( VOID *a, VOID *b );
VOID xccBufferWriteSumCFLT96( VOID *a, VOID *b );
VOID xccBufferWriteSumCINT08( VOID *a, VOID *b );
VOID xccBufferWriteSumCINT16( VOID *a, VOID *b );
VOID xccBufferWriteSumCINT32( VOID *a, VOID *b );
VOID xccBufferWriteSumCINT64( VOID *a, VOID *b );
VOID xccBufferWriteSumCUNT08( VOID *a, VOID *b );
VOID xccBufferWriteSumCUNT16( VOID *a, VOID *b );
VOID xccBufferWriteSumCUNT32( VOID *a, VOID *b );
VOID xccBufferWriteSumCUNT64( VOID *a, VOID *b );
VOID xccBufferWriteSumVFLT32( VOID *a, VOID *b );
VOID xccBufferWriteSumVFLT64( VOID *a, VOID *b );
VOID xccBufferWriteSumVFLT96( VOID *a, VOID *b );
VOID xccBufferWriteSumVINT08( VOID *a, VOID *b );
VOID xccBufferWriteSumVINT16( VOID *a, VOID *b );
VOID xccBufferWriteSumVINT32( VOID *a, VOID *b );
VOID xccBufferWriteSumVINT64( VOID *a, VOID *b );
VOID xccBufferWriteSumVUNT08( VOID *a, VOID *b );
VOID xccBufferWriteSumVUNT16( VOID *a, VOID *b );
VOID xccBufferWriteSumVUNT32( VOID *a, VOID *b );
VOID xccBufferWriteSumVUNT64( VOID *a, VOID *b );
VOID xccBufferWriteSumFLT32FLT64( VOID *a, VOID *b );
VOID xccBufferWriteSumFLT32INT08( VOID *a, VOID *b );
VOID xccBufferWriteSumFLT32INT16( VOID *a, VOID *b );
VOID xccBufferWriteSumFLT32INT32( VOID *a, VOID *b );
VOID xccBufferWriteSumFLT32INT64( VOID *a, VOID *b );
VOID xccBufferWriteSumFLT32UNT08( VOID *a, VOID *b );
VOID xccBufferWriteSumFLT32UNT16( VOID *a, VOID *b );
VOID xccBufferWriteSumFLT32UNT32( VOID *a, VOID *b );
VOID xccBufferWriteSumFLT32UNT64( VOID *a, VOID *b );
VOID xccBufferWriteSumCFLT32CFLT64( VOID *a, VOID *b );
VOID xccBufferWriteSumCFLT32CINT08( VOID *a, VOID *b );
VOID xccBufferWriteSumCFLT32CINT16( VOID *a, VOID *b );
VOID xccBufferWriteSumCFLT32CINT32( VOID *a, VOID *b );
VOID xccBufferWriteSumCFLT32CINT64( VOID *a, VOID *b );
VOID xccBufferWriteSumCFLT32CUNT08( VOID *a, VOID *b );
VOID xccBufferWriteSumCFLT32CUNT16( VOID *a, VOID *b );
VOID xccBufferWriteSumCFLT32CUNT32( VOID *a, VOID *b );
VOID xccBufferWriteSumCFLT32CUNT64( VOID *a, VOID *b );

/* xccBufferVWrite ----------------------------------------------------------------*/
VOID xccBufferVWriteFLT32 ( VOID *a, INT32 i, xccBufferFLT32_t *b,  INT32 j, UNT32 n );
VOID xccBufferVWriteFLT64 ( VOID *a, INT32 i, xccBufferFLT64_t *b,  INT32 j, UNT32 n );
VOID xccBufferVWriteFLT96 ( VOID *a, INT32 i, xccBufferFLT96_t *b,  INT32 j, UNT32 n );

VOID xccBufferVWriteINT08 ( VOID *a, INT32 i, xccBufferINT08_t *b,  INT32 j, UNT32 n );
VOID xccBufferVWriteINT16 ( VOID *a, INT32 i, xccBufferINT16_t *b,  INT32 j, UNT32 n );
VOID xccBufferVWriteINT32 ( VOID *a, INT32 i, xccBufferINT32_t *b,  INT32 j, UNT32 n );
VOID xccBufferVWriteINT64 ( VOID *a, INT32 i, xccBufferINT64_t *b,  INT32 j, UNT32 n );
VOID xccBufferVWriteUNT08 ( VOID *a, INT32 i, xccBufferUNT08_t *b,  INT32 j, UNT32 n );
VOID xccBufferVWriteUNT16 ( VOID *a, INT32 i, xccBufferUNT16_t *b,  INT32 j, UNT32 n );
VOID xccBufferVWriteUNT32 ( VOID *a, INT32 i, xccBufferUNT32_t *b,  INT32 j, UNT32 n );
VOID xccBufferVWriteUNT64 ( VOID *a, INT32 i, xccBufferUNT64_t *b,  INT32 j, UNT32 n );

VOID xccBufferVWriteCFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteCFLT64( VOID *a, INT32 i, xccBufferCFLT64_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteCFLT96( VOID *a, INT32 i, xccBufferCFLT96_t *b, INT32 j, UNT32 n );

VOID xccBufferVWriteCINT08( VOID *a, INT32 i, xccBufferCINT08_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteCINT16( VOID *a, INT32 i, xccBufferCINT16_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteCINT32( VOID *a, INT32 i, xccBufferCINT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteCINT64( VOID *a, INT32 i, xccBufferCINT64_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteCUNT08( VOID *a, INT32 i, xccBufferCUNT08_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteCUNT16( VOID *a, INT32 i, xccBufferCUNT16_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteCUNT32( VOID *a, INT32 i, xccBufferCUNT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteCUNT64( VOID *a, INT32 i, xccBufferCUNT64_t *b, INT32 j, UNT32 n );

VOID xccBufferVWriteVFLT32( VOID *a, INT32 i, xccBufferVFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteVFLT64( VOID *a, INT32 i, xccBufferVFLT64_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteVFLT96( VOID *a, INT32 i, xccBufferVFLT96_t *b, INT32 j, UNT32 n );

VOID xccBufferVWriteVINT08( VOID *a, INT32 i, xccBufferVINT08_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteVINT16( VOID *a, INT32 i, xccBufferVINT16_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteVINT32( VOID *a, INT32 i, xccBufferVINT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteVINT64( VOID *a, INT32 i, xccBufferVINT64_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteVUNT08( VOID *a, INT32 i, xccBufferVUNT08_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteVUNT16( VOID *a, INT32 i, xccBufferVUNT16_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteVUNT32( VOID *a, INT32 i, xccBufferVUNT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteVUNT64( VOID *a, INT32 i, xccBufferVUNT64_t *b, INT32 j, UNT32 n );

/* xccBufferVWrite with conversion ------------------------------------------------*/
VOID xccBufferVWriteFLT64FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteINT08FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteINT16FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteINT32FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteINT64FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteUNT08FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteUNT16FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteUNT32FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteUNT64FLT32( VOID *a, INT32 i, xccBufferFLT32_t *b, INT32 j, UNT32 n );

VOID xccBufferVWriteCFLT64CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteCINT08CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteCINT16CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteCINT32CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteCINT64CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteCUNT08CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteCUNT16CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteCUNT32CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID xccBufferVWriteCUNT64CFLT32( VOID *a, INT32 i, xccBufferCFLT32_t *b, INT32 j, UNT32 n );

/* xccBufferTerm -----------------------------------------------------------------*/
VOID  xccBufferTermFLT32 ( VOID *a );
VOID  xccBufferTermFLT64 ( VOID *a );
VOID  xccBufferTermFLT96 ( VOID *a );
VOID  xccBufferTermINT08 ( VOID *a );
VOID  xccBufferTermINT16 ( VOID *a );
VOID  xccBufferTermINT32 ( VOID *a );
VOID  xccBufferTermINT64 ( VOID *a );
VOID  xccBufferTermUNT08 ( VOID *a );
VOID  xccBufferTermUNT16 ( VOID *a );
VOID  xccBufferTermUNT32 ( VOID *a );
VOID  xccBufferTermUNT64 ( VOID *a );
VOID  xccBufferTermVOIDP ( VOID *a );
VOID  xccBufferTermCFLT32( VOID *a );
VOID  xccBufferTermCFLT64( VOID *a );
VOID  xccBufferTermCFLT96( VOID *a );
VOID  xccBufferTermCINT08( VOID *a );
VOID  xccBufferTermCINT16( VOID *a );
VOID  xccBufferTermCINT32( VOID *a );
VOID  xccBufferTermCINT64( VOID *a );
VOID  xccBufferTermCUNT08( VOID *a );
VOID  xccBufferTermCUNT16( VOID *a );
VOID  xccBufferTermCUNT32( VOID *a );
VOID  xccBufferTermCUNT64( VOID *a );
VOID  xccBufferTermVFLT32( VOID *a );
VOID  xccBufferTermVFLT64( VOID *a );
VOID  xccBufferTermVFLT96( VOID *a );
VOID  xccBufferTermVINT08( VOID *a );
VOID  xccBufferTermVINT16( VOID *a );
VOID  xccBufferTermVINT32( VOID *a );
VOID  xccBufferTermVINT64( VOID *a );
VOID  xccBufferTermVUNT08( VOID *a );
VOID  xccBufferTermVUNT16( VOID *a );
VOID  xccBufferTermVUNT32( VOID *a );
VOID  xccBufferTermVUNT64( VOID *a );

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus 
} 
#endif 
 
#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/
