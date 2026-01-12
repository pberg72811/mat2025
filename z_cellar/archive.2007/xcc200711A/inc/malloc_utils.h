/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: malloc_utils.h
// Desc: This is the header file for xccMallocUtils.
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
INT08  *xccMallocINT08 (UNT32 size);
INT16  *xccMallocINT16 (UNT32 size);
INT32  *xccMallocINT32 (UNT32 size);
INT64  *xccMallocINT64 (UNT32 size);
UNT08  *xccMallocUNT08 (UNT32 size);
UNT16  *xccMallocUNT16 (UNT32 size);
UNT32  *xccMallocUNT32 (UNT32 size);
UNT64  *xccMallocUNT64 (UNT32 size);
FLT32  *xccMallocFLT32 (UNT32 size);
FLT64  *xccMallocFLT64 (UNT32 size);
FLT96  *xccMallocFLT96 (UNT32 size);
VOID   *xccMallocVOID  (UNT32 size);
CINT08 *xccMallocCINT08(UNT32 size);
CINT16 *xccMallocCINT16(UNT32 size);
CINT32 *xccMallocCINT32(UNT32 size);
CINT64 *xccMallocCINT64(UNT32 size);
CUNT08 *xccMallocCUNT08(UNT32 size);
CUNT16 *xccMallocCUNT16(UNT32 size);
CUNT32 *xccMallocCUNT32(UNT32 size);
CUNT64 *xccMallocCUNT64(UNT32 size);
CFLT32 *xccMallocCFLT32(UNT32 size);
CFLT64 *xccMallocCFLT64(UNT32 size);
CFLT96 *xccMallocCFLT96(UNT32 size);

// Align to 16 bits.
//------------------------------------------------------------------------------
INT08 *xccMallocINT08_Align016(UNT32 size);
INT16 *xccMallocINT16_Align016(UNT32 size);
INT32 *xccMallocINT32_Align016(UNT32 size);
INT64 *xccMallocINT64_Align016(UNT32 size);
UNT08 *xccMallocUNT08_Align016(UNT32 size);
UNT16 *xccMallocUNT16_Align016(UNT32 size);
UNT32 *xccMallocUNT32_Align016(UNT32 size);
UNT64 *xccMallocUNT64_Align016(UNT32 size);
FLT32 *xccMallocFLT32_Align016(UNT32 size);
FLT64 *xccMallocFLT64_Align016(UNT32 size);
FLT96 *xccMallocFLT96_Align016(UNT32 size);
VOID  *xccMallocVOID_Align016(UNT32 size);

// Align to 32 bits.
//------------------------------------------------------------------------------
INT08  *xccMallocINT08_Align032( UNT32 size);
INT16  *xccMallocINT16_Align032 (UNT32 size);
INT32  *xccMallocINT32_Align032 (UNT32 size);
INT64  *xccMallocINT64_Align032 (UNT32 size);
UNT08  *xccMallocUNT08_Align032 (UNT32 size);
UNT16  *xccMallocUNT16_Align032 (UNT32 size);
UNT32  *xccMallocUNT32_Align032 (UNT32 size);
UNT64  *xccMallocUNT64_Align032 (UNT32 size);
FLT32  *xccMallocFLT32_Align032 (UNT32 size);
FLT64  *xccMallocFLT64_Align032 (UNT32 size);
FLT96  *xccMallocFLT96_Align032 (UNT32 size);
VOID   *xccMallocVOID_Align032  (UNT32 size);
CINT08 *xccMallocCINT08_Align032(UNT32 size);
CINT16 *xccMallocCINT16_Align032(UNT32 size);
CINT32 *xccMallocCINT32_Align032(UNT32 size);
CINT64 *xccMallocCINT64_Align032(UNT32 size);
CUNT08 *xccMallocCUNT08_Align032(UNT32 size);
CUNT16 *xccMallocCUNT16_Align032(UNT32 size);
CUNT32 *xccMallocCUNT32_Align032(UNT32 size);
CUNT64 *xccMallocCUNT64_Align032(UNT32 size);
CFLT32 *xccMallocCFLT32_Align032(UNT32 size);
CFLT64 *xccMallocCFLT64_Align032(UNT32 size);
CFLT96 *xccMallocCFLT96_Align032(UNT32 size);

// Align to 64 bits.
//------------------------------------------------------------------------------
INT08 *xccMallocINT08_Align064(UNT32 size);
INT16 *xccMallocINT16_Align064(UNT32 size);
INT32 *xccMallocINT32_Align064(UNT32 size);
INT64 *xccMallocINT64_Align064(UNT32 size);
UNT08 *xccMallocUNT08_Align064(UNT32 size);
UNT16 *xccMallocUNT16_Align064(UNT32 size);
UNT32 *xccMallocUNT32_Align064(UNT32 size);
UNT64 *xccMallocUNT64_Align064(UNT32 size);
FLT32 *xccMallocFLT32_Align064(UNT32 size);
FLT64 *xccMallocFLT64_Align064(UNT32 size);
FLT96 *xccMallocFLT96_Align064(UNT32 size);
VOID  *xccMallocVOID_Align064(UNT32 size);

// Align to 128 bits.
//------------------------------------------------------------------------------
INT08 *xccMallocINT08_Align128(UNT32 size);
INT16 *xccMallocINT16_Align128(UNT32 size);
INT32 *xccMallocINT32_Align128(UNT32 size);
INT64 *xccMallocINT64_Align128(UNT32 size);
UNT08 *xccMallocUNT08_Align128(UNT32 size);
UNT16 *xccMallocUNT16_Align128(UNT32 size);
UNT32 *xccMallocUNT32_Align128(UNT32 size);
UNT64 *xccMallocUNT64_Align128(UNT32 size);
FLT32 *xccMallocFLT32_Align128(UNT32 size);
FLT64 *xccMallocFLT64_Align128(UNT32 size);
FLT96 *xccMallocFLT96_Align128(UNT32 size);
VOID  *xccMallocVOID_Align128(UNT32 size);

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/

