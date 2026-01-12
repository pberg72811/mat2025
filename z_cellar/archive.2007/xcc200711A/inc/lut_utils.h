/*---------------------------------------UNCLASSIFIED------------------------------------------*/
// File: lut_utils.h                                                                          -
// Desc: This is the header file for lut_utils.                                               -
// Hist: When       Who  What                                                                   -
//       02/28/2005 ptb  Initial Code.                                                          -
/*---------------------------------------------------------------------------------------------*/

/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#ifndef LUT_UTILS_H
#define LUT_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include "xmc.h"
#include "malloc_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define XCC_LUT_NAME_LENGTH 64

/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  FLT32 *table;
} xccLUTSpecFLT32;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  FLT64 *table;
} xccLUTSpecFLT64;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  FLT96 *table;
} xccLUTSpecFLT96;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  INT08 *table;
} xccLUTSpecINT08;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  INT16 *table;
} xccLUTSpecINT16;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  INT32 *table;
} xccLUTSpecINT32;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  INT64 *table;
} xccLUTSpecINT64;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  UNT08 *table;
} xccLUTSpecUNT08;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  UNT16 *table;
} xccLUTSpecUNT16;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  UNT32 *table;
} xccLUTSpecUNT32;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  UNT64 *table;
} xccLUTSpecUNT64;

// Complex structures.
//-----------------------------------------------------------------------------------------------
typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  CFLT32 *table;
} xccLUTSpecCFLT32;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  CFLT64 *table;
} xccLUTSpecCFLT64;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  CFLT96 *table;
} xccLUTSpecCFLT96;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  CINT08 *table;
} xccLUTSpecCINT08;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  CINT16 *table;
} xccLUTSpecCINT16;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  CINT32 *table;
} xccLUTSpecCINT32;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  CINT64 *table;
} xccLUTSpecCINT64;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  CUNT08 *table;
} xccLUTSpecCUNT08;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  CUNT16 *table;
} xccLUTSpecCUNT16;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  CUNT32 *table;
} xccLUTSpecCUNT32;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  CUNT64 *table;
} xccLUTSpecCUNT64;

// Vector structures.
//-----------------------------------------------------------------------------------------------
typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  VFLT32 *table;
} xccLUTSpecVFLT32;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  VFLT64 *table;
} xccLUTSpecVFLT64;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  VFLT96 *table;
} xccLUTSpecVFLT96;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  VINT08 *table;
} xccLUTSpecVINT08;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  VINT16 *table;
} xccLUTSpecVINT16;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  VINT32 *table;
} xccLUTSpecVINT32;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  VINT64 *table;
} xccLUTSpecVINT64;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  VUNT08 *table;
} xccLUTSpecVUNT08;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  VUNT16 *table;
} xccLUTSpecVUNT16;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  VUNT32 *table;
} xccLUTSpecVUNT32;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  VUNT64 *table;
} xccLUTSpecVUNT64;

// Other structures.
//-----------------------------------------------------------------------------------------------

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  CHR08 *table;
} xccLUTSpecCHR08;

typedef struct
{
  CHR08 name[XCC_LUT_NAME_LENGTH];
  UNT32 size; 
  VOID **table;
} xccLUTSpecVOIDP;

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
xccLUTSpecFLT32 *xccGenSinLUTFLT32   (UNT32 size);
xccLUTSpecFLT64 *xccGenSinLUTFLT64   (UNT32 size);
xccLUTSpecFLT96 *xccGenSinLUTFLT96   (UNT32 size);
xccLUTSpecFLT32 *xccGenASinLUTFLT32  (UNT32 size);
xccLUTSpecFLT64 *xccGenASinLUTFLT64  (UNT32 size);
xccLUTSpecFLT96 *xccGenASinLUTFLT96  (UNT32 size);
xccLUTSpecFLT32 *xccGenCosLUTFLT32   (UNT32 size);
xccLUTSpecFLT64 *xccGenCosLUTFLT64   (UNT32 size);
xccLUTSpecFLT96 *xccGenCosLUTFLT96   (UNT32 size);
xccLUTSpecFLT32 *xccGenACosLUTFLT32  (UNT32 size);
xccLUTSpecFLT64 *xccGenACosLUTFLT64  (UNT32 size);
xccLUTSpecFLT96 *xccGenACosLUTFLT96  (UNT32 size);
xccLUTSpecFLT32 *xccGenTanLUTFLT32   (UNT32 size);
xccLUTSpecFLT64 *xccGenTanLUTFLT64   (UNT32 size);
xccLUTSpecFLT96 *xccGenTanLUTFLT96   (UNT32 size);
xccLUTSpecFLT32 *xccGenCosSinLUTFLT32(UNT32 size);
xccLUTSpecFLT64 *xccGenCosSinLUTFLT64(UNT32 size);
xccLUTSpecFLT96 *xccGenCosSinLUTFLT96(UNT32 size);


FLT32  xccLUTFLT32 (FLT32 whogi, xccLUTSpecFLT32  *spec);
FLT64  xccLUTFLT64 (FLT32 whogi, xccLUTSpecFLT64  *spec);
FLT96  xccLUTFLT96 (FLT32 whogi, xccLUTSpecFLT96  *spec);
INT08  xccLUTINT08 (FLT32 whogi, xccLUTSpecINT08  *spec);
INT16  xccLUTINT16 (FLT32 whogi, xccLUTSpecINT16  *spec);
INT32  xccLUTINT32 (FLT32 whogi, xccLUTSpecINT32  *spec);
INT64  xccLUTINT64 (FLT32 whogi, xccLUTSpecINT64  *spec);
UNT08  xccLUTUNT08 (FLT32 whogi, xccLUTSpecUNT08  *spec);
UNT16  xccLUTUNT16 (FLT32 whogi, xccLUTSpecUNT16  *spec);
UNT32  xccLUTUNT32 (FLT32 whogi, xccLUTSpecUNT32  *spec);
UNT64  xccLUTUNT64 (FLT32 whogi, xccLUTSpecUNT64  *spec);
CFLT32 xccLUTCFLT32(FLT32 whogi, xccLUTSpecCFLT32 *spec);
CFLT64 xccLUTCFLT64(FLT32 whogi, xccLUTSpecCFLT64 *spec);
CFLT96 xccLUTCFLT96(FLT32 whogi, xccLUTSpecCFLT96 *spec);
CINT08 xccLUTCINT08(FLT32 whogi, xccLUTSpecCINT08 *spec);
CINT16 xccLUTCINT16(FLT32 whogi, xccLUTSpecCINT16 *spec);
CINT32 xccLUTCINT32(FLT32 whogi, xccLUTSpecCINT32 *spec);
CINT64 xccLUTCINT64(FLT32 whogi, xccLUTSpecCINT64 *spec);
CUNT08 xccLUTCUNT08(FLT32 whogi, xccLUTSpecCUNT08 *spec);
CUNT16 xccLUTCUNT16(FLT32 whogi, xccLUTSpecCUNT16 *spec);
CUNT32 xccLUTCUNT32(FLT32 whogi, xccLUTSpecCUNT32 *spec);
CUNT64 xccLUTCUNT64(FLT32 whogi, xccLUTSpecCUNT64 *spec);
VFLT32 xccLUTVFLT32(FLT32 whogi, xccLUTSpecVFLT32 *spec);
VFLT64 xccLUTVFLT64(FLT32 whogi, xccLUTSpecVFLT64 *spec);
VFLT96 xccLUTVFLT96(FLT32 whogi, xccLUTSpecVFLT96 *spec);
VINT08 xccLUTVINT08(FLT32 whogi, xccLUTSpecVINT08 *spec);
VINT16 xccLUTVINT16(FLT32 whogi, xccLUTSpecVINT16 *spec);
VINT32 xccLUTVINT32(FLT32 whogi, xccLUTSpecVINT32 *spec);
VINT64 xccLUTVINT64(FLT32 whogi, xccLUTSpecVINT64 *spec);
VUNT08 xccLUTVUNT08(FLT32 whogi, xccLUTSpecVUNT08 *spec);
VUNT16 xccLUTVUNT16(FLT32 whogi, xccLUTSpecVUNT16 *spec);
VUNT32 xccLUTVUNT32(FLT32 whogi, xccLUTSpecVUNT32 *spec);
VUNT64 xccLUTVUNT64(FLT32 whogi, xccLUTSpecVUNT64 *spec);

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/
