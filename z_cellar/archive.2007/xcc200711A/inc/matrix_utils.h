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
#define xcc_MATRIX_NAME_SIZE (32)
#define xcc_MATRIX_NDIM      ( 8)
#define xcc_MATRIX_CREATE    ( 1)

#define COMMON_MATRIX_ELEMENTS     \
  CHR08 name[xcc_MATRIX_NAME_SIZE];\
  UNT32 dim[xcc_MATRIX_NDIM];      \
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
}xccMatrixINT08_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  INT16 *pr;
  INT16 *pi;
}xccMatrixINT16_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  INT32 *pr;
  INT32 *pi;
}xccMatrixINT32_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  INT64 *pr;
  INT64 *pi;
}xccMatrixINT64_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  UNT08 *pr;
  UNT08 *pi;
}xccMatrixUNT08_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  UNT16 *pr;
  UNT16 *pi;
}xccMatrixUNT16_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  UNT32 *pr;
  UNT32 *pi;
}xccMatrixUNT32_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  UNT64 *pr;
  UNT64 *pi;
}xccMatrixUNT64_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  FLT32 *pr;
  FLT32 *pi;
}xccMatrixFLT32_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  FLT64 *pr;
  FLT64 *pi;
}xccMatrixFLT64_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  FLT96 *pr;
  FLT96 *pi;
}xccMatrixFLT96_t;

typedef struct
{
  COMMON_MATRIX_ELEMENTS
  VOID  **pr;
  VOID  **pi;
}xccMatrixVOIDP_t;

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
xccMatrixINT08_t *xccMatrixInitINT08(CCHAR *name, INT08 realMatrix, INT32 ndim, ...);
xccMatrixINT16_t *xccMatrixInitINT16(CCHAR *name, INT16 realMatrix, INT32 ndim, ...);
xccMatrixINT32_t *xccMatrixInitINT32(CCHAR *name, INT32 realMatrix, INT32 ndim, ...);
xccMatrixINT64_t *xccMatrixInitINT64(CCHAR *name, INT64 realMatrix, INT32 ndim, ...);
xccMatrixUNT08_t *xccMatrixInitUNT08(CCHAR *name, UNT08 realMatrix, INT32 ndim, ...);
xccMatrixUNT16_t *xccMatrixInitUNT16(CCHAR *name, UNT16 realMatrix, INT32 ndim, ...);
xccMatrixUNT32_t *xccMatrixInitUNT32(CCHAR *name, UNT32 realMatrix, INT32 ndim, ...);
xccMatrixUNT64_t *xccMatrixInitUNT64(CCHAR *name, UNT64 realMatrix, INT32 ndim, ...);
xccMatrixFLT32_t *xccMatrixInitFLT32(CCHAR *name, FLT32 realMatrix, INT32 ndim, ...);
xccMatrixFLT64_t *xccMatrixInitFLT64(CCHAR *name, FLT64 realMatrix, INT32 ndim, ...);
xccMatrixFLT96_t *xccMatrixInitFLT96(CCHAR *name, FLT96 realMatrix, INT32 ndim, ...);
xccMatrixVOIDP_t *xccMatrixInitVOIDP(CCHAR *name, FLT96 realMatrix, INT32 ndim, ...);

VOID  xccMatrixTermINT08(xccMatrixINT08_t *MA);
VOID  xccMatrixTermINT16(xccMatrixINT16_t *MA);
VOID  xccMatrixTermINT32(xccMatrixINT32_t *MA);
VOID  xccMatrixTermINT64(xccMatrixINT64_t *MA);
VOID  xccMatrixTermUNT08(xccMatrixUNT08_t *MA);
VOID  xccMatrixTermUNT16(xccMatrixUNT16_t *MA);
VOID  xccMatrixTermUNT32(xccMatrixUNT32_t *MA);
VOID  xccMatrixTermUNT64(xccMatrixUNT64_t *MA);
VOID  xccMatrixTermFLT32(xccMatrixFLT32_t *MA);
VOID  xccMatrixTermFLT64(xccMatrixFLT64_t *MA);
VOID  xccMatrixTermFLT96(xccMatrixFLT96_t *MA);
VOID  xccMatrixTermVOIDP(xccMatrixVOIDP_t *MA);

VOID xccMatrixAddINT08(xccMatrixINT08_t *MA, xccMatrixINT08_t *MB, xccMatrixINT08_t *MC);
VOID xccMatrixAddINT16(xccMatrixINT16_t *MA, xccMatrixINT16_t *MB, xccMatrixINT16_t *MC);
VOID xccMatrixAddINT32(xccMatrixINT32_t *MA, xccMatrixINT32_t *MB, xccMatrixINT32_t *MC);
VOID xccMatrixAddINT64(xccMatrixINT64_t *MA, xccMatrixINT64_t *MB, xccMatrixINT64_t *MC);
VOID xccMatrixAddUNT08(xccMatrixUNT08_t *MA, xccMatrixUNT08_t *MB, xccMatrixUNT08_t *MC);
VOID xccMatrixAddUNT16(xccMatrixUNT16_t *MA, xccMatrixUNT16_t *MB, xccMatrixUNT16_t *MC);
VOID xccMatrixAddUNT32(xccMatrixUNT32_t *MA, xccMatrixUNT32_t *MB, xccMatrixUNT32_t *MC);
VOID xccMatrixAddUNT64(xccMatrixUNT64_t *MA, xccMatrixUNT64_t *MB, xccMatrixUNT64_t *MC);
VOID xccMatrixAddFLT32(xccMatrixFLT32_t *MA, xccMatrixFLT32_t *MB, xccMatrixFLT32_t *MC);
VOID xccMatrixAddFLT64(xccMatrixFLT64_t *MA, xccMatrixFLT64_t *MB, xccMatrixFLT64_t *MC);
VOID xccMatrixAddFLT96(xccMatrixFLT96_t *MA, xccMatrixFLT96_t *MB, xccMatrixFLT96_t *MC);

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/
