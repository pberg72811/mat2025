/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: matrix_utils.h
// Desc: This is the header file for matrix_utils.
// Hist: When       Who  What
//       05/20/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "xmc.h"
#include "malloc_utils.h"
#include <stdarg.h>

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define icc_MATRIX_NAME_SIZE (32)
#define icc_MATRIX_NDIM      ( 8)
#define icc_MATRIX_CREATE    ( 1)

#define COMMON_MATRIX_ELEMENTS     \
  CHR08 name[icc_MATRIX_NAME_SIZE];\
  UNT32 dim[icc_MATRIX_NDIM];      \
  INT08 ndim;                      \
  UNT32 total;                     \
  INT08 cplx;

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
typedef struct
{
  COMMON_MATRIX_ELEMENTS
  INT08 *pr;
  INT08 *pi;
}iccMatrixINT08_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  INT16 *pr;
  INT16 *pi;
}iccMatrixINT16_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  INT32 *pr;
  INT32 *pi;
}iccMatrixINT32_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  INT64 *pr;
  INT64 *pi;
}iccMatrixINT64_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  UNT08 *pr;
  UNT08 *pi;
}iccMatrixUNT08_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  UNT16 *pr;
  UNT16 *pi;
}iccMatrixUNT16_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  UNT32 *pr;
  UNT32 *pi;
}iccMatrixUNT32_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  UNT64 *pr;
  UNT64 *pi;
}iccMatrixUNT64_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  FLT32 *pr;
  FLT32 *pi;
}iccMatrixFLT32_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  FLT64 *pr;
  FLT64 *pi;
}iccMatrixFLT64_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  FLT96 *pr;
  FLT96 *pi;
}iccMatrixFLT96_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  VOID  **pr;
  VOID  **pi;
}iccMatrixVOIDP_t;

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
iccMatrixINT08_t *iccMatrixInitINT08(CCHAR *name, INT08 realMatrix, INT32 ndim, ...);
iccMatrixINT16_t *iccMatrixInitINT16(CCHAR *name, INT16 realMatrix, INT32 ndim, ...);
iccMatrixINT32_t *iccMatrixInitINT32(CCHAR *name, INT32 realMatrix, INT32 ndim, ...);
iccMatrixINT64_t *iccMatrixInitINT64(CCHAR *name, INT64 realMatrix, INT32 ndim, ...);
iccMatrixUNT08_t *iccMatrixInitUNT08(CCHAR *name, UNT08 realMatrix, INT32 ndim, ...);
iccMatrixUNT16_t *iccMatrixInitUNT16(CCHAR *name, UNT16 realMatrix, INT32 ndim, ...);
iccMatrixUNT32_t *iccMatrixInitUNT32(CCHAR *name, UNT32 realMatrix, INT32 ndim, ...);
iccMatrixUNT64_t *iccMatrixInitUNT64(CCHAR *name, UNT64 realMatrix, INT32 ndim, ...);
iccMatrixFLT32_t *iccMatrixInitFLT32(CCHAR *name, FLT32 realMatrix, INT32 ndim, ...);
iccMatrixFLT64_t *iccMatrixInitFLT64(CCHAR *name, FLT64 realMatrix, INT32 ndim, ...);
iccMatrixFLT96_t *iccMatrixInitFLT96(CCHAR *name, FLT96 realMatrix, INT32 ndim, ...);
iccMatrixVOIDP_t *iccMatrixInitVOIDP(CCHAR *name, FLT96 realMatrix, INT32 ndim, ...);

VOID  iccMatrixTermINT08(iccMatrixINT08_t *MA);
VOID  iccMatrixTermINT16(iccMatrixINT16_t *MA);
VOID  iccMatrixTermINT32(iccMatrixINT32_t *MA);
VOID  iccMatrixTermINT64(iccMatrixINT64_t *MA);
VOID  iccMatrixTermUNT08(iccMatrixUNT08_t *MA);
VOID  iccMatrixTermUNT16(iccMatrixUNT16_t *MA);
VOID  iccMatrixTermUNT32(iccMatrixUNT32_t *MA);
VOID  iccMatrixTermUNT64(iccMatrixUNT64_t *MA);
VOID  iccMatrixTermFLT32(iccMatrixFLT32_t *MA);
VOID  iccMatrixTermFLT64(iccMatrixFLT64_t *MA);
VOID  iccMatrixTermFLT96(iccMatrixFLT96_t *MA);
VOID  iccMatrixTermVOIDP(iccMatrixVOIDP_t *MA);

VOID iccMatrixAddINT08(iccMatrixINT08_t *MA, iccMatrixINT08_t *MB, iccMatrixINT08_t *MC);
VOID iccMatrixAddINT16(iccMatrixINT16_t *MA, iccMatrixINT16_t *MB, iccMatrixINT16_t *MC);
VOID iccMatrixAddINT32(iccMatrixINT32_t *MA, iccMatrixINT32_t *MB, iccMatrixINT32_t *MC);
VOID iccMatrixAddINT64(iccMatrixINT64_t *MA, iccMatrixINT64_t *MB, iccMatrixINT64_t *MC);
VOID iccMatrixAddUNT08(iccMatrixUNT08_t *MA, iccMatrixUNT08_t *MB, iccMatrixUNT08_t *MC);
VOID iccMatrixAddUNT16(iccMatrixUNT16_t *MA, iccMatrixUNT16_t *MB, iccMatrixUNT16_t *MC);
VOID iccMatrixAddUNT32(iccMatrixUNT32_t *MA, iccMatrixUNT32_t *MB, iccMatrixUNT32_t *MC);
VOID iccMatrixAddUNT64(iccMatrixUNT64_t *MA, iccMatrixUNT64_t *MB, iccMatrixUNT64_t *MC);
VOID iccMatrixAddFLT32(iccMatrixFLT32_t *MA, iccMatrixFLT32_t *MB, iccMatrixFLT32_t *MC);
VOID iccMatrixAddFLT64(iccMatrixFLT64_t *MA, iccMatrixFLT64_t *MB, iccMatrixFLT64_t *MC);
VOID iccMatrixAddFLT96(iccMatrixFLT96_t *MA, iccMatrixFLT96_t *MB, iccMatrixFLT96_t *MC);

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/
