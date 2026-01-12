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
#define icc_BUFFER_NAME_LENGTH 64
#define icc_BUFFER_TYPE_LENGTH  8

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define COMMON_BUFFER_ELEMENTS  CHR08 name[icc_BUFFER_NAME_LENGTH]; \
                                CHR08 type[icc_BUFFER_TYPE_LENGTH]; \
                                UNT32 size;                         \
                                UNT32 index;                        \
                                UNT32 pndex;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  FLT32 *theBuffer;
  FLT32 theSum;
} iccBufferFLT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  FLT64 *theBuffer;
  FLT64 theSum;
} iccBufferFLT64_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  FLT96 *theBuffer;
  FLT96 theSum;
} iccBufferFLT96_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  INT08 *theBuffer;
  INT32 theSum;
} iccBufferINT08_t;
 
typedef struct
{
  COMMON_BUFFER_ELEMENTS
  INT16 *theBuffer;
  INT32 theSum;
} iccBufferINT16_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  INT32 *theBuffer;
  INT32 theSum;
} iccBufferINT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  INT64 *theBuffer;
  INT64 theSum;
} iccBufferINT64_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  UNT08 *theBuffer;
  UNT32 theSum;
} iccBufferUNT08_t;
 
typedef struct
{
  COMMON_BUFFER_ELEMENTS
  UNT16 *theBuffer;
  UNT32 theSum;
} iccBufferUNT16_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  UNT32 *theBuffer;
  UNT32 theSum;
} iccBufferUNT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  UNT64 *theBuffer;
  UNT64 theSum;
} iccBufferUNT64_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VOID **theBuffer;
} iccBufferVOIDP_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CFLT32 *theBuffer;
  CFLT32 theSum;
} iccBufferCFLT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CFLT64 *theBuffer;
  CFLT64 theSum;
} iccBufferCFLT64_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CFLT96 *theBuffer;
  CFLT96 theSum;
} iccBufferCFLT96_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CINT08 *theBuffer;
  CINT32 theSum;
} iccBufferCINT08_t;
 
typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CINT16 *theBuffer;
  CINT32 theSum;
} iccBufferCINT16_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CINT32 *theBuffer;
  CINT32 theSum;
} iccBufferCINT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CINT64 *theBuffer;
  CINT64 theSum;
} iccBufferCINT64_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CUNT08 *theBuffer;
  CUNT32 theSum;
} iccBufferCUNT08_t;
 
typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CUNT16 *theBuffer;
  CUNT32 theSum;
} iccBufferCUNT16_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CUNT32 *theBuffer;
  CUNT32 theSum;
} iccBufferCUNT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  CUNT64 *theBuffer;
  CUNT64 theSum;
} iccBufferCUNT64_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VFLT32 *theBuffer;
  VFLT32 theSum;
} iccBufferVFLT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VFLT64 *theBuffer;
  VFLT64 theSum;
} iccBufferVFLT64_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VFLT96 *theBuffer;
  VFLT96 theSum;
} iccBufferVFLT96_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VINT08 *theBuffer;
  VINT32 theSum;
} iccBufferVINT08_t;
 
typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VINT16 *theBuffer;
  VINT32 theSum;
} iccBufferVINT16_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VINT32 *theBuffer;
  VINT32 theSum;
} iccBufferVINT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VINT64 *theBuffer;
  VINT64 theSum;
} iccBufferVINT64_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VUNT08 *theBuffer;
  VUNT32 theSum;
} iccBufferVUNT08_t;
 
typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VUNT16 *theBuffer;
  VUNT32 theSum;
} iccBufferVUNT16_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VUNT32 *theBuffer;
  VUNT32 theSum;
} iccBufferVUNT32_t;

typedef struct
{
  COMMON_BUFFER_ELEMENTS
  VUNT64 *theBuffer;
  VUNT64 theSum;
} iccBufferVUNT64_t;

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

/* iccBufferClear ----------------------------------------------------------------*/
VOID  iccBufferClearFLT32 (iccBufferFLT32_t  *p);
VOID  iccBufferClearFLT64 (iccBufferFLT64_t  *p);
VOID  iccBufferClearFLT96 (iccBufferFLT96_t  *p);
VOID  iccBufferClearINT08 (iccBufferINT08_t  *p);
VOID  iccBufferClearINT16 (iccBufferINT16_t  *p);
VOID  iccBufferClearINT32 (iccBufferINT32_t  *p);
VOID  iccBufferClearINT64 (iccBufferINT64_t  *p);
VOID  iccBufferClearUNT08 (iccBufferUNT08_t  *p);
VOID  iccBufferClearUNT16 (iccBufferUNT16_t  *p);
VOID  iccBufferClearUNT32 (iccBufferUNT32_t  *p);
VOID  iccBufferClearUNT64 (iccBufferUNT64_t  *p);
VOID  iccBufferClearVOIDP (iccBufferVOIDP_t  *p);
VOID  iccBufferClearCFLT32(iccBufferCFLT32_t *p);
VOID  iccBufferClearCFLT64(iccBufferCFLT64_t *p);
VOID  iccBufferClearCFLT96(iccBufferCFLT96_t *p);
VOID  iccBufferClearCINT08(iccBufferCINT08_t *p);
VOID  iccBufferClearCINT16(iccBufferCINT16_t *p);
VOID  iccBufferClearCINT32(iccBufferCINT32_t *p);
VOID  iccBufferClearCINT64(iccBufferCINT64_t *p);
VOID  iccBufferClearCUNT08(iccBufferCUNT08_t *p);
VOID  iccBufferClearCUNT16(iccBufferCUNT16_t *p);
VOID  iccBufferClearCUNT32(iccBufferCUNT32_t *p);
VOID  iccBufferClearCUNT64(iccBufferCUNT64_t *p);
VOID  iccBufferClearVFLT32(iccBufferVFLT32_t *p);
VOID  iccBufferClearVFLT64(iccBufferVFLT64_t *p);
VOID  iccBufferClearVFLT96(iccBufferVFLT96_t *p);
VOID  iccBufferClearVINT08(iccBufferVINT08_t *p);
VOID  iccBufferClearVINT16(iccBufferVINT16_t *p);
VOID  iccBufferClearVINT32(iccBufferVINT32_t *p);
VOID  iccBufferClearVINT64(iccBufferVINT64_t *p);
VOID  iccBufferClearVUNT08(iccBufferVUNT08_t *p);
VOID  iccBufferClearVUNT16(iccBufferVUNT16_t *p);
VOID  iccBufferClearVUNT32(iccBufferVUNT32_t *p);
VOID  iccBufferClearVUNT64(iccBufferVUNT64_t *p);


/* iccBufferInit -----------------------------------------------------------------*/
iccBufferFLT32_t  *iccBufferInitFLT32 (UNT32 size, CCHAR *name);
iccBufferFLT64_t  *iccBufferInitFLT64 (UNT32 size, CCHAR *name);
iccBufferFLT96_t  *iccBufferInitFLT96 (UNT32 size, CCHAR *name);
iccBufferINT08_t  *iccBufferInitINT08 (UNT32 size, CCHAR *name);
iccBufferINT16_t  *iccBufferInitINT16 (UNT32 size, CCHAR *name);
iccBufferINT32_t  *iccBufferInitINT32 (UNT32 size, CCHAR *name);
iccBufferINT64_t  *iccBufferInitINT64 (UNT32 size, CCHAR *name);
iccBufferUNT08_t  *iccBufferInitUNT08 (UNT32 size, CCHAR *name);
iccBufferUNT16_t  *iccBufferInitUNT16 (UNT32 size, CCHAR *name);
iccBufferUNT32_t  *iccBufferInitUNT32 (UNT32 size, CCHAR *name);
iccBufferUNT64_t  *iccBufferInitUNT64 (UNT32 size, CCHAR *name);
iccBufferVOIDP_t  *iccBufferInitVOIDP (UNT32 size, CCHAR *name);
iccBufferCFLT32_t *iccBufferInitCFLT32(UNT32 size, CCHAR *name);
iccBufferCFLT64_t *iccBufferInitCFLT64(UNT32 size, CCHAR *name);
iccBufferCFLT96_t *iccBufferInitCFLT96(UNT32 size, CCHAR *name);
iccBufferCINT08_t *iccBufferInitCINT08(UNT32 size, CCHAR *name);
iccBufferCINT16_t *iccBufferInitCINT16(UNT32 size, CCHAR *name);
iccBufferCINT32_t *iccBufferInitCINT32(UNT32 size, CCHAR *name);
iccBufferCINT64_t *iccBufferInitCINT64(UNT32 size, CCHAR *name);
iccBufferCUNT08_t *iccBufferInitCUNT08(UNT32 size, CCHAR *name);
iccBufferCUNT16_t *iccBufferInitCUNT16(UNT32 size, CCHAR *name);
iccBufferCUNT32_t *iccBufferInitCUNT32(UNT32 size, CCHAR *name);
iccBufferCUNT64_t *iccBufferInitCUNT64(UNT32 size, CCHAR *name);
iccBufferVFLT32_t *iccBufferInitVFLT32(UNT32 size, CCHAR *name);
iccBufferVFLT64_t *iccBufferInitVFLT64(UNT32 size, CCHAR *name);
iccBufferVFLT96_t *iccBufferInitVFLT96(UNT32 size, CCHAR *name);
iccBufferVINT08_t *iccBufferInitVINT08(UNT32 size, CCHAR *name);
iccBufferVINT16_t *iccBufferInitVINT16(UNT32 size, CCHAR *name);
iccBufferVINT32_t *iccBufferInitVINT32(UNT32 size, CCHAR *name);
iccBufferVINT64_t *iccBufferInitVINT64(UNT32 size, CCHAR *name);
iccBufferVUNT08_t *iccBufferInitVUNT08(UNT32 size, CCHAR *name);
iccBufferVUNT16_t *iccBufferInitVUNT16(UNT32 size, CCHAR *name);
iccBufferVUNT32_t *iccBufferInitVUNT32(UNT32 size, CCHAR *name);
iccBufferVUNT64_t *iccBufferInitVUNT64(UNT32 size, CCHAR *name);

VOID iccBufferSumFLT32( VOID *a );
VOID iccBufferSumFLT64( VOID *a );
VOID iccBufferSumFLT96( VOID *a );
VOID iccBufferSumINT08( VOID *a );
VOID iccBufferSumINT16( VOID *a );
VOID iccBufferSumINT32( VOID *a );
VOID iccBufferSumINT64( VOID *a );
VOID iccBufferSumUNT08( VOID *a );
VOID iccBufferSumUNT16( VOID *a );
VOID iccBufferSumUNT32( VOID *a );
VOID iccBufferSumUNT64( VOID *a );
VOID iccBufferSumCFLT32( VOID *a );
VOID iccBufferSumCFLT64( VOID *a );
VOID iccBufferSumCFLT96( VOID *a );
VOID iccBufferSumCINT08( VOID *a );
VOID iccBufferSumCINT16( VOID *a );
VOID iccBufferSumCINT32( VOID *a );
VOID iccBufferSumCINT64( VOID *a );
VOID iccBufferSumCUNT08( VOID *a );
VOID iccBufferSumCUNT16( VOID *a );
VOID iccBufferSumCUNT32( VOID *a );
VOID iccBufferSumCUNT64( VOID *a );
VOID iccBufferSumVFLT32( VOID *a );
VOID iccBufferSumVFLT64( VOID *a );
VOID iccBufferSumVFLT96( VOID *a );
VOID iccBufferSumVINT08( VOID *a );
VOID iccBufferSumVINT16( VOID *a );
VOID iccBufferSumVINT32( VOID *a );
VOID iccBufferSumVINT64( VOID *a );
VOID iccBufferSumVUNT08( VOID *a );
VOID iccBufferSumVUNT16( VOID *a );
VOID iccBufferSumVUNT32( VOID *a );
VOID iccBufferSumVUNT64( VOID *a );

/* iccBufferWrite -----------------------------------------------------------------*/
VOID iccBufferWriteFLT32 ( VOID *a, VOID *b );
VOID iccBufferWriteFLT64 ( VOID *a, VOID *b );
VOID iccBufferWriteFLT96 ( VOID *a, VOID *b );
VOID iccBufferWriteINT08 ( VOID *a, VOID *b );
VOID iccBufferWriteINT16 ( VOID *a, VOID *b );
VOID iccBufferWriteINT32 ( VOID *a, VOID *b );
VOID iccBufferWriteINT64 ( VOID *a, VOID *b );
VOID iccBufferWriteUNT08 ( VOID *a, VOID *b );
VOID iccBufferWriteUNT16 ( VOID *a, VOID *b );
VOID iccBufferWriteUNT32 ( VOID *a, VOID *b );
VOID iccBufferWriteUNT64 ( VOID *a, VOID *b );
VOID iccBufferWriteCFLT32( VOID *a, VOID *b );
VOID iccBufferWriteCFLT64( VOID *a, VOID *b );
VOID iccBufferWriteCFLT96( VOID *a, VOID *b );
VOID iccBufferWriteCINT08( VOID *a, VOID *b );
VOID iccBufferWriteCINT16( VOID *a, VOID *b );
VOID iccBufferWriteCINT32( VOID *a, VOID *b );
VOID iccBufferWriteCINT64( VOID *a, VOID *b );
VOID iccBufferWriteCUNT08( VOID *a, VOID *b );
VOID iccBufferWriteCUNT16( VOID *a, VOID *b );
VOID iccBufferWriteCUNT32( VOID *a, VOID *b );
VOID iccBufferWriteCUNT64( VOID *a, VOID *b );
VOID iccBufferWriteVFLT32( VOID *a, VOID *b );
VOID iccBufferWriteVFLT64( VOID *a, VOID *b );
VOID iccBufferWriteVFLT96( VOID *a, VOID *b );
VOID iccBufferWriteVINT08( VOID *a, VOID *b );
VOID iccBufferWriteVINT16( VOID *a, VOID *b );
VOID iccBufferWriteVINT32( VOID *a, VOID *b );
VOID iccBufferWriteVINT64( VOID *a, VOID *b );
VOID iccBufferWriteVUNT08( VOID *a, VOID *b );
VOID iccBufferWriteVUNT16( VOID *a, VOID *b );
VOID iccBufferWriteVUNT32( VOID *a, VOID *b );
VOID iccBufferWriteVUNT64( VOID *a, VOID *b );
VOID iccBufferWriteFLT32FLT64( VOID *a, VOID *b );
VOID iccBufferWriteFLT32INT08( VOID *a, VOID *b );
VOID iccBufferWriteFLT32INT16( VOID *a, VOID *b );
VOID iccBufferWriteFLT32INT32( VOID *a, VOID *b );
VOID iccBufferWriteFLT32INT64( VOID *a, VOID *b );
VOID iccBufferWriteFLT32UNT08( VOID *a, VOID *b );
VOID iccBufferWriteFLT32UNT16( VOID *a, VOID *b );
VOID iccBufferWriteFLT32UNT32( VOID *a, VOID *b );
VOID iccBufferWriteFLT32UNT64( VOID *a, VOID *b );
VOID iccBufferWriteCFLT32CFLT64( VOID *a, VOID *b );
VOID iccBufferWriteCFLT32CINT08( VOID *a, VOID *b );
VOID iccBufferWriteCFLT32CINT16( VOID *a, VOID *b );
VOID iccBufferWriteCFLT32CINT32( VOID *a, VOID *b );
VOID iccBufferWriteCFLT32CINT64( VOID *a, VOID *b );
VOID iccBufferWriteCFLT32CUNT08( VOID *a, VOID *b );
VOID iccBufferWriteCFLT32CUNT16( VOID *a, VOID *b );
VOID iccBufferWriteCFLT32CUNT32( VOID *a, VOID *b );
VOID iccBufferWriteCFLT32CUNT64( VOID *a, VOID *b );

/* iccBufferWriteSum -----------------------------------------------------------------*/
VOID iccBufferWriteSumFLT32 ( VOID *a, VOID *b );
VOID iccBufferWriteSumFLT64 ( VOID *a, VOID *b );
VOID iccBufferWriteSumFLT96 ( VOID *a, VOID *b );
VOID iccBufferWriteSumINT08 ( VOID *a, VOID *b );
VOID iccBufferWriteSumINT16 ( VOID *a, VOID *b );
VOID iccBufferWriteSumINT32 ( VOID *a, VOID *b );
VOID iccBufferWriteSumINT64 ( VOID *a, VOID *b );
VOID iccBufferWriteSumUNT08 ( VOID *a, VOID *b );
VOID iccBufferWriteSumUNT16 ( VOID *a, VOID *b );
VOID iccBufferWriteSumUNT32 ( VOID *a, VOID *b );
VOID iccBufferWriteSumUNT64 ( VOID *a, VOID *b );
VOID iccBufferWriteSumCFLT32( VOID *a, VOID *b );
VOID iccBufferWriteSumCFLT64( VOID *a, VOID *b );
VOID iccBufferWriteSumCFLT96( VOID *a, VOID *b );
VOID iccBufferWriteSumCINT08( VOID *a, VOID *b );
VOID iccBufferWriteSumCINT16( VOID *a, VOID *b );
VOID iccBufferWriteSumCINT32( VOID *a, VOID *b );
VOID iccBufferWriteSumCINT64( VOID *a, VOID *b );
VOID iccBufferWriteSumCUNT08( VOID *a, VOID *b );
VOID iccBufferWriteSumCUNT16( VOID *a, VOID *b );
VOID iccBufferWriteSumCUNT32( VOID *a, VOID *b );
VOID iccBufferWriteSumCUNT64( VOID *a, VOID *b );
VOID iccBufferWriteSumVFLT32( VOID *a, VOID *b );
VOID iccBufferWriteSumVFLT64( VOID *a, VOID *b );
VOID iccBufferWriteSumVFLT96( VOID *a, VOID *b );
VOID iccBufferWriteSumVINT08( VOID *a, VOID *b );
VOID iccBufferWriteSumVINT16( VOID *a, VOID *b );
VOID iccBufferWriteSumVINT32( VOID *a, VOID *b );
VOID iccBufferWriteSumVINT64( VOID *a, VOID *b );
VOID iccBufferWriteSumVUNT08( VOID *a, VOID *b );
VOID iccBufferWriteSumVUNT16( VOID *a, VOID *b );
VOID iccBufferWriteSumVUNT32( VOID *a, VOID *b );
VOID iccBufferWriteSumVUNT64( VOID *a, VOID *b );
VOID iccBufferWriteSumFLT32FLT64( VOID *a, VOID *b );
VOID iccBufferWriteSumFLT32INT08( VOID *a, VOID *b );
VOID iccBufferWriteSumFLT32INT16( VOID *a, VOID *b );
VOID iccBufferWriteSumFLT32INT32( VOID *a, VOID *b );
VOID iccBufferWriteSumFLT32INT64( VOID *a, VOID *b );
VOID iccBufferWriteSumFLT32UNT08( VOID *a, VOID *b );
VOID iccBufferWriteSumFLT32UNT16( VOID *a, VOID *b );
VOID iccBufferWriteSumFLT32UNT32( VOID *a, VOID *b );
VOID iccBufferWriteSumFLT32UNT64( VOID *a, VOID *b );
VOID iccBufferWriteSumCFLT32CFLT64( VOID *a, VOID *b );
VOID iccBufferWriteSumCFLT32CINT08( VOID *a, VOID *b );
VOID iccBufferWriteSumCFLT32CINT16( VOID *a, VOID *b );
VOID iccBufferWriteSumCFLT32CINT32( VOID *a, VOID *b );
VOID iccBufferWriteSumCFLT32CINT64( VOID *a, VOID *b );
VOID iccBufferWriteSumCFLT32CUNT08( VOID *a, VOID *b );
VOID iccBufferWriteSumCFLT32CUNT16( VOID *a, VOID *b );
VOID iccBufferWriteSumCFLT32CUNT32( VOID *a, VOID *b );
VOID iccBufferWriteSumCFLT32CUNT64( VOID *a, VOID *b );

/* iccBufferVWrite ----------------------------------------------------------------*/
VOID iccBufferVWriteFLT32 ( VOID *a, INT32 i, iccBufferFLT32_t *b,  INT32 j, UNT32 n );
VOID iccBufferVWriteFLT64 ( VOID *a, INT32 i, iccBufferFLT64_t *b,  INT32 j, UNT32 n );
VOID iccBufferVWriteFLT96 ( VOID *a, INT32 i, iccBufferFLT96_t *b,  INT32 j, UNT32 n );

VOID iccBufferVWriteINT08 ( VOID *a, INT32 i, iccBufferINT08_t *b,  INT32 j, UNT32 n );
VOID iccBufferVWriteINT16 ( VOID *a, INT32 i, iccBufferINT16_t *b,  INT32 j, UNT32 n );
VOID iccBufferVWriteINT32 ( VOID *a, INT32 i, iccBufferINT32_t *b,  INT32 j, UNT32 n );
VOID iccBufferVWriteINT64 ( VOID *a, INT32 i, iccBufferINT64_t *b,  INT32 j, UNT32 n );
VOID iccBufferVWriteUNT08 ( VOID *a, INT32 i, iccBufferUNT08_t *b,  INT32 j, UNT32 n );
VOID iccBufferVWriteUNT16 ( VOID *a, INT32 i, iccBufferUNT16_t *b,  INT32 j, UNT32 n );
VOID iccBufferVWriteUNT32 ( VOID *a, INT32 i, iccBufferUNT32_t *b,  INT32 j, UNT32 n );
VOID iccBufferVWriteUNT64 ( VOID *a, INT32 i, iccBufferUNT64_t *b,  INT32 j, UNT32 n );

VOID iccBufferVWriteCFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteCFLT64( VOID *a, INT32 i, iccBufferCFLT64_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteCFLT96( VOID *a, INT32 i, iccBufferCFLT96_t *b, INT32 j, UNT32 n );

VOID iccBufferVWriteCINT08( VOID *a, INT32 i, iccBufferCINT08_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteCINT16( VOID *a, INT32 i, iccBufferCINT16_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteCINT32( VOID *a, INT32 i, iccBufferCINT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteCINT64( VOID *a, INT32 i, iccBufferCINT64_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteCUNT08( VOID *a, INT32 i, iccBufferCUNT08_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteCUNT16( VOID *a, INT32 i, iccBufferCUNT16_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteCUNT32( VOID *a, INT32 i, iccBufferCUNT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteCUNT64( VOID *a, INT32 i, iccBufferCUNT64_t *b, INT32 j, UNT32 n );

VOID iccBufferVWriteVFLT32( VOID *a, INT32 i, iccBufferVFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteVFLT64( VOID *a, INT32 i, iccBufferVFLT64_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteVFLT96( VOID *a, INT32 i, iccBufferVFLT96_t *b, INT32 j, UNT32 n );

VOID iccBufferVWriteVINT08( VOID *a, INT32 i, iccBufferVINT08_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteVINT16( VOID *a, INT32 i, iccBufferVINT16_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteVINT32( VOID *a, INT32 i, iccBufferVINT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteVINT64( VOID *a, INT32 i, iccBufferVINT64_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteVUNT08( VOID *a, INT32 i, iccBufferVUNT08_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteVUNT16( VOID *a, INT32 i, iccBufferVUNT16_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteVUNT32( VOID *a, INT32 i, iccBufferVUNT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteVUNT64( VOID *a, INT32 i, iccBufferVUNT64_t *b, INT32 j, UNT32 n );

/* iccBufferVWrite with conversion ------------------------------------------------*/
VOID iccBufferVWriteFLT64FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteINT08FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteINT16FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteINT32FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteINT64FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteUNT08FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteUNT16FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteUNT32FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteUNT64FLT32( VOID *a, INT32 i, iccBufferFLT32_t *b, INT32 j, UNT32 n );

VOID iccBufferVWriteCFLT64CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteCINT08CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteCINT16CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteCINT32CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteCINT64CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteCUNT08CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteCUNT16CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteCUNT32CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n );
VOID iccBufferVWriteCUNT64CFLT32( VOID *a, INT32 i, iccBufferCFLT32_t *b, INT32 j, UNT32 n );

/* iccBufferTerm -----------------------------------------------------------------*/
VOID  iccBufferTermFLT32 ( VOID *a );
VOID  iccBufferTermFLT64 ( VOID *a );
VOID  iccBufferTermFLT96 ( VOID *a );
VOID  iccBufferTermINT08 ( VOID *a );
VOID  iccBufferTermINT16 ( VOID *a );
VOID  iccBufferTermINT32 ( VOID *a );
VOID  iccBufferTermINT64 ( VOID *a );
VOID  iccBufferTermUNT08 ( VOID *a );
VOID  iccBufferTermUNT16 ( VOID *a );
VOID  iccBufferTermUNT32 ( VOID *a );
VOID  iccBufferTermUNT64 ( VOID *a );
VOID  iccBufferTermVOIDP ( VOID *a );
VOID  iccBufferTermCFLT32( VOID *a );
VOID  iccBufferTermCFLT64( VOID *a );
VOID  iccBufferTermCFLT96( VOID *a );
VOID  iccBufferTermCINT08( VOID *a );
VOID  iccBufferTermCINT16( VOID *a );
VOID  iccBufferTermCINT32( VOID *a );
VOID  iccBufferTermCINT64( VOID *a );
VOID  iccBufferTermCUNT08( VOID *a );
VOID  iccBufferTermCUNT16( VOID *a );
VOID  iccBufferTermCUNT32( VOID *a );
VOID  iccBufferTermCUNT64( VOID *a );
VOID  iccBufferTermVFLT32( VOID *a );
VOID  iccBufferTermVFLT64( VOID *a );
VOID  iccBufferTermVFLT96( VOID *a );
VOID  iccBufferTermVINT08( VOID *a );
VOID  iccBufferTermVINT16( VOID *a );
VOID  iccBufferTermVINT32( VOID *a );
VOID  iccBufferTermVINT64( VOID *a );
VOID  iccBufferTermVUNT08( VOID *a );
VOID  iccBufferTermVUNT16( VOID *a );
VOID  iccBufferTermVUNT32( VOID *a );
VOID  iccBufferTermVUNT64( VOID *a );

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus 
} 
#endif 
 
#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/
