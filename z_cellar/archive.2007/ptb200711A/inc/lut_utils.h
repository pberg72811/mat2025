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
#define ICC_LUT_NAME_LENGTH 64

/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  FLT32 *table;
} iccLUTSpecFLT32;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  FLT64 *table;
} iccLUTSpecFLT64;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  FLT96 *table;
} iccLUTSpecFLT96;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  INT08 *table;
} iccLUTSpecINT08;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  INT16 *table;
} iccLUTSpecINT16;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  INT32 *table;
} iccLUTSpecINT32;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  INT64 *table;
} iccLUTSpecINT64;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  UNT08 *table;
} iccLUTSpecUNT08;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  UNT16 *table;
} iccLUTSpecUNT16;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  UNT32 *table;
} iccLUTSpecUNT32;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  UNT64 *table;
} iccLUTSpecUNT64;

// Complex structures.
//-----------------------------------------------------------------------------------------------
typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  CFLT32 *table;
} iccLUTSpecCFLT32;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  CFLT64 *table;
} iccLUTSpecCFLT64;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  CFLT96 *table;
} iccLUTSpecCFLT96;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  CINT08 *table;
} iccLUTSpecCINT08;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  CINT16 *table;
} iccLUTSpecCINT16;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  CINT32 *table;
} iccLUTSpecCINT32;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  CINT64 *table;
} iccLUTSpecCINT64;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  CUNT08 *table;
} iccLUTSpecCUNT08;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  CUNT16 *table;
} iccLUTSpecCUNT16;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  CUNT32 *table;
} iccLUTSpecCUNT32;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  CUNT64 *table;
} iccLUTSpecCUNT64;

// Vector structures.
//-----------------------------------------------------------------------------------------------
typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  VFLT32 *table;
} iccLUTSpecVFLT32;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  VFLT64 *table;
} iccLUTSpecVFLT64;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  VFLT96 *table;
} iccLUTSpecVFLT96;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  VINT08 *table;
} iccLUTSpecVINT08;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  VINT16 *table;
} iccLUTSpecVINT16;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  VINT32 *table;
} iccLUTSpecVINT32;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  VINT64 *table;
} iccLUTSpecVINT64;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  VUNT08 *table;
} iccLUTSpecVUNT08;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  VUNT16 *table;
} iccLUTSpecVUNT16;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  VUNT32 *table;
} iccLUTSpecVUNT32;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  VUNT64 *table;
} iccLUTSpecVUNT64;

// Other structures.
//-----------------------------------------------------------------------------------------------

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  CHR08 *table;
} iccLUTSpecCHR08;

typedef struct
{
  CHR08 name[ICC_LUT_NAME_LENGTH];
  UNT32 size; 
  VOID **table;
} iccLUTSpecVOIDP;

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
iccLUTSpecFLT32 *iccGenSinLUTFLT32   (UNT32 size);
iccLUTSpecFLT64 *iccGenSinLUTFLT64   (UNT32 size);
iccLUTSpecFLT96 *iccGenSinLUTFLT96   (UNT32 size);
iccLUTSpecFLT32 *iccGenASinLUTFLT32  (UNT32 size);
iccLUTSpecFLT64 *iccGenASinLUTFLT64  (UNT32 size);
iccLUTSpecFLT96 *iccGenASinLUTFLT96  (UNT32 size);
iccLUTSpecFLT32 *iccGenCosLUTFLT32   (UNT32 size);
iccLUTSpecFLT64 *iccGenCosLUTFLT64   (UNT32 size);
iccLUTSpecFLT96 *iccGenCosLUTFLT96   (UNT32 size);
iccLUTSpecFLT32 *iccGenACosLUTFLT32  (UNT32 size);
iccLUTSpecFLT64 *iccGenACosLUTFLT64  (UNT32 size);
iccLUTSpecFLT96 *iccGenACosLUTFLT96  (UNT32 size);
iccLUTSpecFLT32 *iccGenTanLUTFLT32   (UNT32 size);
iccLUTSpecFLT64 *iccGenTanLUTFLT64   (UNT32 size);
iccLUTSpecFLT96 *iccGenTanLUTFLT96   (UNT32 size);
iccLUTSpecFLT32 *iccGenCosSinLUTFLT32(UNT32 size);
iccLUTSpecFLT64 *iccGenCosSinLUTFLT64(UNT32 size);
iccLUTSpecFLT96 *iccGenCosSinLUTFLT96(UNT32 size);


FLT32  iccLUTFLT32 (FLT32 whogi, iccLUTSpecFLT32  *spec);
FLT64  iccLUTFLT64 (FLT32 whogi, iccLUTSpecFLT64  *spec);
FLT96  iccLUTFLT96 (FLT32 whogi, iccLUTSpecFLT96  *spec);
INT08  iccLUTINT08 (FLT32 whogi, iccLUTSpecINT08  *spec);
INT16  iccLUTINT16 (FLT32 whogi, iccLUTSpecINT16  *spec);
INT32  iccLUTINT32 (FLT32 whogi, iccLUTSpecINT32  *spec);
INT64  iccLUTINT64 (FLT32 whogi, iccLUTSpecINT64  *spec);
UNT08  iccLUTUNT08 (FLT32 whogi, iccLUTSpecUNT08  *spec);
UNT16  iccLUTUNT16 (FLT32 whogi, iccLUTSpecUNT16  *spec);
UNT32  iccLUTUNT32 (FLT32 whogi, iccLUTSpecUNT32  *spec);
UNT64  iccLUTUNT64 (FLT32 whogi, iccLUTSpecUNT64  *spec);
CFLT32 iccLUTCFLT32(FLT32 whogi, iccLUTSpecCFLT32 *spec);
CFLT64 iccLUTCFLT64(FLT32 whogi, iccLUTSpecCFLT64 *spec);
CFLT96 iccLUTCFLT96(FLT32 whogi, iccLUTSpecCFLT96 *spec);
CINT08 iccLUTCINT08(FLT32 whogi, iccLUTSpecCINT08 *spec);
CINT16 iccLUTCINT16(FLT32 whogi, iccLUTSpecCINT16 *spec);
CINT32 iccLUTCINT32(FLT32 whogi, iccLUTSpecCINT32 *spec);
CINT64 iccLUTCINT64(FLT32 whogi, iccLUTSpecCINT64 *spec);
CUNT08 iccLUTCUNT08(FLT32 whogi, iccLUTSpecCUNT08 *spec);
CUNT16 iccLUTCUNT16(FLT32 whogi, iccLUTSpecCUNT16 *spec);
CUNT32 iccLUTCUNT32(FLT32 whogi, iccLUTSpecCUNT32 *spec);
CUNT64 iccLUTCUNT64(FLT32 whogi, iccLUTSpecCUNT64 *spec);
VFLT32 iccLUTVFLT32(FLT32 whogi, iccLUTSpecVFLT32 *spec);
VFLT64 iccLUTVFLT64(FLT32 whogi, iccLUTSpecVFLT64 *spec);
VFLT96 iccLUTVFLT96(FLT32 whogi, iccLUTSpecVFLT96 *spec);
VINT08 iccLUTVINT08(FLT32 whogi, iccLUTSpecVINT08 *spec);
VINT16 iccLUTVINT16(FLT32 whogi, iccLUTSpecVINT16 *spec);
VINT32 iccLUTVINT32(FLT32 whogi, iccLUTSpecVINT32 *spec);
VINT64 iccLUTVINT64(FLT32 whogi, iccLUTSpecVINT64 *spec);
VUNT08 iccLUTVUNT08(FLT32 whogi, iccLUTSpecVUNT08 *spec);
VUNT16 iccLUTVUNT16(FLT32 whogi, iccLUTSpecVUNT16 *spec);
VUNT32 iccLUTVUNT32(FLT32 whogi, iccLUTSpecVUNT32 *spec);
VUNT64 iccLUTVUNT64(FLT32 whogi, iccLUTSpecVUNT64 *spec);

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/
