/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: malloc_utils.h
// Desc: This is the header file for iccMallocUtils.
// Hist: When       Who  What
//       08/22/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef MALLOC_UTILS_H
#define MALLOC_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include <malloc.h>
#include "xmc.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

// Plain allocate.
//------------------------------------------------------------------------------
INT08  *iccMallocINT08 (UNT32 size);
INT16  *iccMallocINT16 (UNT32 size);
INT32  *iccMallocINT32 (UNT32 size);
INT64  *iccMallocINT64 (UNT32 size);
UNT08  *iccMallocUNT08 (UNT32 size);
UNT16  *iccMallocUNT16 (UNT32 size);
UNT32  *iccMallocUNT32 (UNT32 size);
UNT64  *iccMallocUNT64 (UNT32 size);
FLT32  *iccMallocFLT32 (UNT32 size);
FLT64  *iccMallocFLT64 (UNT32 size);
FLT96  *iccMallocFLT96 (UNT32 size);
VOID   *iccMallocVOID  (UNT32 size);
CINT08 *iccMallocCINT08(UNT32 size);
CINT16 *iccMallocCINT16(UNT32 size);
CINT32 *iccMallocCINT32(UNT32 size);
CINT64 *iccMallocCINT64(UNT32 size);
CUNT08 *iccMallocCUNT08(UNT32 size);
CUNT16 *iccMallocCUNT16(UNT32 size);
CUNT32 *iccMallocCUNT32(UNT32 size);
CUNT64 *iccMallocCUNT64(UNT32 size);
CFLT32 *iccMallocCFLT32(UNT32 size);
CFLT64 *iccMallocCFLT64(UNT32 size);
CFLT96 *iccMallocCFLT96(UNT32 size);

// Align to 16 bits.
//------------------------------------------------------------------------------
INT08 *iccMallocINT08_Align016(UNT32 size);
INT16 *iccMallocINT16_Align016(UNT32 size);
INT32 *iccMallocINT32_Align016(UNT32 size);
INT64 *iccMallocINT64_Align016(UNT32 size);
UNT08 *iccMallocUNT08_Align016(UNT32 size);
UNT16 *iccMallocUNT16_Align016(UNT32 size);
UNT32 *iccMallocUNT32_Align016(UNT32 size);
UNT64 *iccMallocUNT64_Align016(UNT32 size);
FLT32 *iccMallocFLT32_Align016(UNT32 size);
FLT64 *iccMallocFLT64_Align016(UNT32 size);
FLT96 *iccMallocFLT96_Align016(UNT32 size);
VOID  *iccMallocVOID_Align016(UNT32 size);

// Align to 32 bits.
//------------------------------------------------------------------------------
INT08  *iccMallocINT08_Align032( UNT32 size);
INT16  *iccMallocINT16_Align032 (UNT32 size);
INT32  *iccMallocINT32_Align032 (UNT32 size);
INT64  *iccMallocINT64_Align032 (UNT32 size);
UNT08  *iccMallocUNT08_Align032 (UNT32 size);
UNT16  *iccMallocUNT16_Align032 (UNT32 size);
UNT32  *iccMallocUNT32_Align032 (UNT32 size);
UNT64  *iccMallocUNT64_Align032 (UNT32 size);
FLT32  *iccMallocFLT32_Align032 (UNT32 size);
FLT64  *iccMallocFLT64_Align032 (UNT32 size);
FLT96  *iccMallocFLT96_Align032 (UNT32 size);
VOID   *iccMallocVOID_Align032  (UNT32 size);
CINT08 *iccMallocCINT08_Align032(UNT32 size);
CINT16 *iccMallocCINT16_Align032(UNT32 size);
CINT32 *iccMallocCINT32_Align032(UNT32 size);
CINT64 *iccMallocCINT64_Align032(UNT32 size);
CUNT08 *iccMallocCUNT08_Align032(UNT32 size);
CUNT16 *iccMallocCUNT16_Align032(UNT32 size);
CUNT32 *iccMallocCUNT32_Align032(UNT32 size);
CUNT64 *iccMallocCUNT64_Align032(UNT32 size);
CFLT32 *iccMallocCFLT32_Align032(UNT32 size);
CFLT64 *iccMallocCFLT64_Align032(UNT32 size);
CFLT96 *iccMallocCFLT96_Align032(UNT32 size);

// Align to 64 bits.
//------------------------------------------------------------------------------
INT08 *iccMallocINT08_Align064(UNT32 size);
INT16 *iccMallocINT16_Align064(UNT32 size);
INT32 *iccMallocINT32_Align064(UNT32 size);
INT64 *iccMallocINT64_Align064(UNT32 size);
UNT08 *iccMallocUNT08_Align064(UNT32 size);
UNT16 *iccMallocUNT16_Align064(UNT32 size);
UNT32 *iccMallocUNT32_Align064(UNT32 size);
UNT64 *iccMallocUNT64_Align064(UNT32 size);
FLT32 *iccMallocFLT32_Align064(UNT32 size);
FLT64 *iccMallocFLT64_Align064(UNT32 size);
FLT96 *iccMallocFLT96_Align064(UNT32 size);
VOID  *iccMallocVOID_Align064(UNT32 size);

// Align to 128 bits.
//------------------------------------------------------------------------------
INT08 *iccMallocINT08_Align128(UNT32 size);
INT16 *iccMallocINT16_Align128(UNT32 size);
INT32 *iccMallocINT32_Align128(UNT32 size);
INT64 *iccMallocINT64_Align128(UNT32 size);
UNT08 *iccMallocUNT08_Align128(UNT32 size);
UNT16 *iccMallocUNT16_Align128(UNT32 size);
UNT32 *iccMallocUNT32_Align128(UNT32 size);
UNT64 *iccMallocUNT64_Align128(UNT32 size);
FLT32 *iccMallocFLT32_Align128(UNT32 size);
FLT64 *iccMallocFLT64_Align128(UNT32 size);
FLT96 *iccMallocFLT96_Align128(UNT32 size);
VOID  *iccMallocVOID_Align128(UNT32 size);

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/

