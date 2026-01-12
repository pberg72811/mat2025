/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: vector_utils.h
// Desc: This is the header file for vector_utils.
// Hist: When       Who  What
//       04/27/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef VECTOR_UTILS_H
#define VECTOR_UTILS_H
 
#ifdef __cplusplus 
extern "C" { 
#endif 
 
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "xmc.h"
 
/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define A1UNT64 1566083941L
#define A1UNT32 1566083941
#define B1UNT64 1234323L
#define B1UNT32 1234323
#define invUNT64 5.42101086242752e-20L
#define invINT64 1.08420217248550e-19L
#define invUNT32 2.32830643653870e-10
#define invINT32 4.65661287307739e-10

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

// xccMatrixComposite.
//------------------------------------------------------------------------------
VOID xccMatrixCompositeFLT32 ( FLT32 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			       FLT32 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			       FLT32 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeFLT64 ( FLT64 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			       FLT64 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			       FLT64 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeFLT96 ( FLT96 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			       FLT96 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			       FLT96 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeINT08 ( INT08 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			       INT08 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			       INT08 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeINT16 ( INT16 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			       INT16 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			       INT16 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeINT32 ( INT32 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			       INT32 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			       INT32 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeINT64 ( INT64 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			       INT64 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			       INT64 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeUNT08 ( UNT08 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			       UNT08 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			       UNT08 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeUNT16 ( UNT16 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			       UNT16 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			       UNT16 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeUNT32 ( UNT32 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			       UNT32 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			       UNT32 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeUNT64 ( UNT64 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			       UNT64 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			       UNT64 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeCFLT32(CFLT32 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CFLT32 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CFLT32 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeCFLT64(CFLT64 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CFLT64 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CFLT64 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeCFLT96(CFLT96 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CFLT96 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CFLT96 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeCINT08(CINT08 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CINT08 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CINT08 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeCINT16(CINT16 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CINT16 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CINT16 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeCINT32(CINT32 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CINT32 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CINT32 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeCINT64(CINT64 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CINT64 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CINT64 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeCUNT08(CUNT08 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CUNT08 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CUNT08 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeCUNT16(CUNT16 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CUNT16 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CUNT16 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeCUNT32(CUNT32 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CUNT32 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CUNT32 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
VOID xccMatrixCompositeCUNT64(CUNT64 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CUNT64 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CUNT64 *MC, INT32 sk, INT32 rowsC, INT32 colsC);
// xccvAdd functions.
//------------------------------------------------------------------------------
VOID xccvAddFLT32 (FLT32 *a, INT32 i,  FLT32 *b, INT32 j,  FLT32 *c, INT32 k, UNT32 n);
VOID xccvAddFLT64 (FLT64 *a, INT32 i,  FLT64 *b, INT32 j,  FLT64 *c, INT32 k, UNT32 n);
VOID xccvAddFLT96 (FLT96 *a, INT32 i,  FLT96 *b, INT32 j,  FLT96 *c, INT32 k, UNT32 n);
VOID xccvAddINT08 (INT08 *a, INT32 i,  INT08 *b, INT32 j,  INT08 *c, INT32 k, UNT32 n);
VOID xccvAddINT16 (INT16 *a, INT32 i,  INT16 *b, INT32 j,  INT16 *c, INT32 k, UNT32 n);
VOID xccvAddINT32 (INT32 *a, INT32 i,  INT32 *b, INT32 j,  INT32 *c, INT32 k, UNT32 n);
VOID xccvAddINT64 (INT64 *a, INT32 i,  INT64 *b, INT32 j,  INT64 *c, INT32 k, UNT32 n);
VOID xccvAddUNT08 (UNT08 *a, INT32 i,  UNT08 *b, INT32 j,  UNT08 *c, INT32 k, UNT32 n);
VOID xccvAddUNT16 (UNT16 *a, INT32 i,  UNT16 *b, INT32 j,  UNT16 *c, INT32 k, UNT32 n);
VOID xccvAddUNT32 (UNT32 *a, INT32 i,  UNT32 *b, INT32 j,  UNT32 *c, INT32 k, UNT32 n);
VOID xccvAddUNT64 (UNT64 *a, INT32 i,  UNT64 *b, INT32 j,  UNT64 *c, INT32 k, UNT32 n);
VOID xccvAddCFLT32(CFLT32 *a, INT32 i, CFLT32 *b, INT32 j, CFLT32 *c, INT32 k, UNT32 n);
VOID xccvAddCFLT64(CFLT64 *a, INT32 i, CFLT64 *b, INT32 j, CFLT64 *c, INT32 k, UNT32 n);
VOID xccvAddCFLT96(CFLT96 *a, INT32 i, CFLT96 *b, INT32 j, CFLT96 *c, INT32 k, UNT32 n);
VOID xccvAddCINT08(CINT08 *a, INT32 i, CINT08 *b, INT32 j, CINT08 *c, INT32 k, UNT32 n);
VOID xccvAddCINT16(CINT16 *a, INT32 i, CINT16 *b, INT32 j, CINT16 *c, INT32 k, UNT32 n);
VOID xccvAddCINT32(CINT32 *a, INT32 i, CINT32 *b, INT32 j, CINT32 *c, INT32 k, UNT32 n);
VOID xccvAddCINT64(CINT64 *a, INT32 i, CINT64 *b, INT32 j, CINT64 *c, INT32 k, UNT32 n);
VOID xccvAddCUNT08(CUNT08 *a, INT32 i, CUNT08 *b, INT32 j, CUNT08 *c, INT32 k, UNT32 n);
VOID xccvAddCUNT16(CUNT16 *a, INT32 i, CUNT16 *b, INT32 j, CUNT16 *c, INT32 k, UNT32 n);
VOID xccvAddCUNT32(CUNT32 *a, INT32 i, CUNT32 *b, INT32 j, CUNT32 *c, INT32 k, UNT32 n);
VOID xccvAddCUNT64(CUNT64 *a, INT32 i, CUNT64 *b, INT32 j, CUNT64 *c, INT32 k, UNT32 n);
VOID xccvAddVFLT32(VFLT32 *a, INT32 i, VFLT32 *b, INT32 j, VFLT32 *c, INT32 k, UNT32 n);
VOID xccvAddVFLT64(VFLT64 *a, INT32 i, VFLT64 *b, INT32 j, VFLT64 *c, INT32 k, UNT32 n);
VOID xccvAddVFLT96(VFLT96 *a, INT32 i, VFLT96 *b, INT32 j, VFLT96 *c, INT32 k, UNT32 n);
VOID xccvAddVINT08(VINT08 *a, INT32 i, VINT08 *b, INT32 j, VINT08 *c, INT32 k, UNT32 n);
VOID xccvAddVINT16(VINT16 *a, INT32 i, VINT16 *b, INT32 j, VINT16 *c, INT32 k, UNT32 n);
VOID xccvAddVINT32(VINT32 *a, INT32 i, VINT32 *b, INT32 j, VINT32 *c, INT32 k, UNT32 n);
VOID xccvAddVINT64(VINT64 *a, INT32 i, VINT64 *b, INT32 j, VINT64 *c, INT32 k, UNT32 n);
VOID xccvAddVUNT08(VUNT08 *a, INT32 i, VUNT08 *b, INT32 j, VUNT08 *c, INT32 k, UNT32 n);
VOID xccvAddVUNT16(VUNT16 *a, INT32 i, VUNT16 *b, INT32 j, VUNT16 *c, INT32 k, UNT32 n);
VOID xccvAddVUNT32(VUNT32 *a, INT32 i, VUNT32 *b, INT32 j, VUNT32 *c, INT32 k, UNT32 n);
VOID xccvAddVUNT64(VUNT64 *a, INT32 i, VUNT64 *b, INT32 j, VUNT64 *c, INT32 k, UNT32 n);

// xccBarrelShift functions.
//------------------------------------------------------------------------------
VOID xccvBarrelShiftFLT32 (VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftFLT64 (VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftFLT96 (VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftINT08 (VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftINT16 (VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftINT32 (VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftINT64 (VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftUNT08 (VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftUNT16 (VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftUNT32 (VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftUNT64 (VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftINT08 (VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftCFLT32(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftCFLT64(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftCFLT96(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftCINT16(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftCINT32(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftCINT64(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftCUNT08(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftCUNT16(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftCUNT32(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftCUNT64(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftVFLT32(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftVFLT64(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftVFLT96(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftVINT16(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftVINT32(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftVINT64(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftVUNT08(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftVUNT16(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftVUNT32(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);
VOID xccvBarrelShiftVUNT64(VOID *a, INT32 i, INT32 shiftBy, UNT32 n);

// xccConj functions
//------------------------------------------------------------------------------
VOID xccvConjCFLT32(CFLT32 *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n);
VOID xccvConjCFLT64(CFLT64 *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n);
VOID xccvConjCFLT96(CFLT96 *a, INT32 i, CFLT96 *b, INT32 j, UNT32 n);
VOID xccvConjCINT08(CINT08 *a, INT32 i, CINT08 *b, INT32 j, UNT32 n);
VOID xccvConjCINT16(CINT16 *a, INT32 i, CINT16 *b, INT32 j, UNT32 n);
VOID xccvConjCINT32(CINT32 *a, INT32 i, CINT32 *b, INT32 j, UNT32 n);
VOID xccvConjCINT64(CINT64 *a, INT32 i, CINT64 *b, INT32 j, UNT32 n);
VOID xccvConjCUNT08(CUNT08 *a, INT32 i, CUNT08 *b, INT32 j, UNT32 n);
VOID xccvConjCUNT16(CUNT16 *a, INT32 i, CUNT16 *b, INT32 j, UNT32 n);
VOID xccvConjCUNT32(CUNT32 *a, INT32 i, CUNT32 *b, INT32 j, UNT32 n);
VOID xccvConjCUNT64(CUNT64 *a, INT32 i, CUNT64 *b, INT32 j, UNT32 n);

/* vconvert functions --------------------------------------------------------*/
VOID xccvINT08ToFLT64(INT08 *a, INT32 ii, FLT64 *b, INT32 jj, UNT32 n );
VOID xccvINT16ToFLT64(INT16 *a, INT32 ii, FLT64 *b, INT32 jj, UNT32 n );
VOID xccvINT32ToFLT64(INT32 *a, INT32 ii, FLT64 *b, INT32 jj, UNT32 n );
VOID xccvINT64ToFLT64(INT64 *a, INT32 ii, FLT64 *b, INT32 jj, UNT32 n );
VOID xccvUNT08ToFLT64(UNT08 *a, INT32 ii, FLT64 *b, INT32 jj, UNT32 n );
VOID xccvUNT16ToFLT64(UNT16 *a, INT32 ii, FLT64 *b, INT32 jj, UNT32 n );
VOID xccvUNT32ToFLT64(UNT32 *a, INT32 ii, FLT64 *b, INT32 jj, UNT32 n );
VOID xccvUNT64ToFLT64(UNT64 *a, INT32 ii, FLT64 *b, INT32 jj, UNT32 n );
VOID xccvFLT32ToFLT64(VOID  *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );

VOID xccvINT08ToFLT32(VOID *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );
VOID xccvINT16ToFLT32(VOID *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );
VOID xccvINT32ToFLT32(VOID *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );
VOID xccvINT64ToFLT32(VOID *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );
VOID xccvUNT08ToFLT32(VOID *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );
VOID xccvUNT16ToFLT32(VOID *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );
VOID xccvUNT32ToFLT32(VOID *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );
VOID xccvUNT64ToFLT32(VOID *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );
VOID xccvFLT32ToFLT32(VOID *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );
VOID xccvFLT64ToFLT32(VOID *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );

VOID xccvFLT32ToINT08(VOID  *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );
VOID xccvFLT32ToINT16(VOID  *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );
VOID xccvFLT32ToINT32(VOID  *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );
VOID xccvFLT32ToINT64(VOID  *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );
VOID xccvFLT32ToUNT08(VOID  *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );
VOID xccvFLT32ToUNT16(VOID  *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );
VOID xccvFLT32ToUNT32(VOID  *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );
VOID xccvFLT32ToUNT64(VOID  *a, INT32 ii, VOID  *b, INT32 jj, UNT32 n );

VOID xccvINT08ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvINT16ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvINT32ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvINT64ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvUNT08ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvUNT16ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvUNT32ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvUNT64ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvFLT32ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvFLT64ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvINT08ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvINT16ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvINT32ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvINT64ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvUNT08ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvUNT16ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvUNT32ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvUNT64ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvFLT32ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvFLT64ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );

VOID xccvCINT08ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvCINT16ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvCINT32ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvCINT64ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvCUNT08ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvCUNT16ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvCUNT32ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvCUNT64ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvCFLT32ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvCFLT64ToCFLT32(VOID *a, INT32 ii, CFLT32 *b, INT32 jj, UNT32 n );
VOID xccvCINT08ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvCINT16ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvCINT32ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvCINT64ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvCUNT08ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvCUNT16ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvCUNT32ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvCUNT64ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvCFLT32ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );
VOID xccvCFLT64ToCFLT64(VOID *a, INT32 ii, CFLT64 *b, INT32 jj, UNT32 n );

/* xccvConvolve functions -----------------------------------------------------*/
FLT32 xccvConvolveFLT32(FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n );
FLT64 xccvConvolveFLT64(FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n );
FLT96 xccvConvolveFLT96(FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n );
INT08 xccvConvolveINT08(INT08 *a, INT32 i, INT08 *b, INT32 j, UNT32 n );
INT16 xccvConvolveINT16(INT16 *a, INT32 i, INT16 *b, INT32 j, UNT32 n );
INT32 xccvConvolveINT32(INT32 *a, INT32 i, INT32 *b, INT32 j, UNT32 n );
INT64 xccvConvolveINT64(INT64 *a, INT32 i, INT64 *b, INT32 j, UNT32 n );
UNT08 xccvConvolveUNT08(UNT08 *a, INT32 i, UNT08 *b, INT32 j, UNT32 n );
UNT16 xccvConvolveUNT16(UNT16 *a, INT32 i, UNT16 *b, INT32 j, UNT32 n );
UNT32 xccvConvolveUNT32(UNT32 *a, INT32 i, UNT32 *b, INT32 j, UNT32 n );
UNT64 xccvConvolveUNT64(UNT64 *a, INT32 i, UNT64 *b, INT32 j, UNT32 n );

FLT32 xccvConvolveFLT32FLT64(FLT32 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n );

/* xccvCopy functions --------------------------------------------------------*/
VOID xccvCopyFLT32 (VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyFLT64 (VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyFLT96 (VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyINT08 (VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyINT16 (VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyINT32 (VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyINT64 (VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyUNT08 (VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyUNT16 (VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyUNT32 (VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyUNT64 (VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyCFLT32(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyCFLT64(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyCFLT96(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyCINT08(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyCINT16(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyCINT32(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyCINT64(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyCUNT08(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyCUNT16(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyCUNT32(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyCUNT64(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyVFLT32(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyVFLT64(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyVFLT96(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyVINT08(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyVINT16(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyVINT32(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyVINT64(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyVUNT08(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyVUNT16(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyVUNT32(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );
VOID xccvCopyVUNT64(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n );

/* xccvCos functions --------------------------------------------------------*/
VOID xccvCosFLT32(FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n );
VOID xccvCosFLT64(FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n );
VOID xccvCosFLT96(FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n );

/* xccvCrossProduct functions -------------------------------------------------*/
VOID xccvCrossProductFLT32(FLT32 *a, FLT32 *b, FLT32 *c);
VOID xccvCrossProductFLT64(FLT64 *a, FLT64 *b, FLT64 *c);
VOID xccvCrossProductFLT96(FLT96 *a, FLT96 *b, FLT96 *c);
VOID xccvCrossProductINT08(INT08 *a, INT08 *b, INT08 *c);
VOID xccvCrossProductINT16(INT16 *a, INT16 *b, INT16 *c);
VOID xccvCrossProductINT32(INT32 *a, INT32 *b, INT32 *c);
VOID xccvCrossProductINT64(INT64 *a, INT64 *b, INT64 *c);
VOID xccvCrossProductUNT08(UNT08 *a, UNT08 *b, UNT08 *c);
VOID xccvCrossProductUNT16(UNT16 *a, UNT16 *b, UNT16 *c);
VOID xccvCrossProductUNT32(UNT32 *a, UNT32 *b, UNT32 *c);
VOID xccvCrossProductUNT64(UNT64 *a, UNT64 *b, UNT64 *c);
VFLT32 xccCrossProductVFLT32(VFLT32 a, VFLT32 b);
VFLT64 xccCrossProductVFLT64(VFLT64 a, VFLT64 b);
VFLT96 xccCrossProductVFLT96(VFLT96 a, VFLT96 b);
VINT08 xccCrossProductVINT08(VINT08 a, VINT08 b);
VINT16 xccCrossProductVINT16(VINT16 a, VINT16 b);
VINT32 xccCrossProductVINT32(VINT32 a, VINT32 b);
VINT64 xccCrossProductVINT64(VINT64 a, VINT64 b);
VUNT08 xccCrossProductVUNT08(VUNT08 a, VUNT08 b);
VUNT16 xccCrossProductVUNT16(VUNT16 a, VUNT16 b);
VUNT32 xccCrossProductVUNT32(VUNT32 a, VUNT32 b);
VUNT64 xccCrossProductVUNT64(VUNT64 a, VUNT64 b);
VOID xccCrossProductFLT32(FLT32  a0, FLT32  a1, FLT32  a2,
                          FLT32  b0, FLT32  b1, FLT32  b2,
                          FLT32 *c0, FLT32 *c1, FLT32 *c2);
VOID xccCrossProductFLT64(FLT64  a0, FLT64  a1, FLT64  a2,
                          FLT64  b0, FLT64  b1, FLT64  b2,
                          FLT64 *c0, FLT64 *c1, FLT64 *c2);
VOID xccCrossProductFLT96(FLT96  a0, FLT96  a1, FLT96  a2,
                          FLT96  b0, FLT96  b1, FLT96  b2,
                          FLT96 *c0, FLT96 *c1, FLT96 *c2);
VOID xccCrossProductINT08(INT08  a0, INT08  a1, INT08  a2,
                          INT08  b0, INT08  b1, INT08  b2,
                          INT08 *c0, INT08 *c1, INT08 *c2);
VOID xccCrossProductINT16(INT16  a0, INT16  a1, INT16  a2,
                          INT16  b0, INT16  b1, INT16  b2,
                          INT16 *c0, INT16 *c1, INT16 *c2);
VOID xccCrossProductINT32(INT32  a0, INT32  a1, INT32  a2,
                          INT32  b0, INT32  b1, INT32  b2,
                          INT32 *c0, INT32 *c1, INT32 *c2);
VOID xccCrossProductINT64(INT64  a0, INT64  a1, INT64  a2,
                          INT64  b0, INT64  b1, INT64  b2,
                          INT64 *c0, INT64 *c1, INT64 *c2);
VOID xccCrossProductUNT08(UNT08  a0, UNT08  a1, UNT08  a2,
                          UNT08  b0, UNT08  b1, UNT08  b2,
                          UNT08 *c0, UNT08 *c1, UNT08 *c2);
VOID xccCrossProductUNT16(UNT16  a0, UNT16  a1, UNT16  a2,
                          UNT16  b0, UNT16  b1, UNT16  b2,
                          UNT16 *c0, UNT16 *c1, UNT16 *c2);
VOID xccCrossProductUNT32(UNT32  a0, UNT32  a1, UNT32  a2,
                          UNT32  b0, UNT32  b1, UNT32  b2,
                          UNT32 *c0, UNT32 *c1, UNT32 *c2);
VOID xccCrossProductUNT64(UNT64  a0, UNT64  a1, UNT64  a2,
                          UNT64  b0, UNT64  b1, UNT64  b2,
                          UNT64 *c0, UNT64 *c1, UNT64 *c2);

/* xccvDiv functions --------------------------------------------------------------------------*/
VOID xccvDivFLT32( FLT32 *a, INT32 i, FLT32 *b, INT32 j, FLT32 *c, INT32 k, UNT32 n);
VOID xccvDivFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, FLT64 *c, INT32 k, UNT32 n);
VOID xccvDivFLT96( FLT96 *a, INT32 i, FLT96 *b, INT32 j,  FLT96 *c, INT32 k,UNT32 n);
VOID xccvDivINT08( INT08 *a, INT32 i, INT08 *b, INT32 j, INT08 *c, INT32 k, UNT32 n);
VOID xccvDivINT16( INT16 *a, INT32 i, INT16 *b, INT32 j, INT16 *c, INT32 k, UNT32 n);
VOID xccvDivINT32( INT32 *a, INT32 i, INT32 *b, INT32 j, INT32 *c, INT32 k, UNT32 n);
VOID xccvDivINT64( INT64 *a, INT32 i, INT64 *b, INT32 j, INT64 *c, INT32 k, UNT32 n);
VOID xccvDivUNT08( UNT08 *a, INT32 i, UNT08 *b, INT32 j, UNT08 *c, INT32 k, UNT32 n);
VOID xccvDivUNT16( UNT16 *a, INT32 i, UNT16 *b, INT32 j, UNT16 *c, INT32 k, UNT32 n);
VOID xccvDivUNT32( UNT32 *a, INT32 i, UNT32 *b, INT32 j, UNT32 *c, INT32 k, UNT32 n);
VOID xccvDivUNT64( UNT64 *a, INT32 i, UNT64 *b, INT32 j, UNT64 *c, INT32 k, UNT32 n);
VOID xccvDivCFLT32( CFLT32 *a, INT32 i, CFLT32 *b, INT32 j, CFLT32 *c, INT32 k, UNT32 n);
VOID xccvDivCFLT64( CFLT64 *a, INT32 i, CFLT64 *b, INT32 j, CFLT64 *c, INT32 k, UNT32 n);
VOID xccvDivCFLT96( CFLT96 *a, INT32 i, CFLT96 *b, INT32 j, CFLT96 *c, INT32 k, UNT32 n);
VOID xccvDivCINT08( CINT08 *a, INT32 i, CINT08 *b, INT32 j, CINT08 *c, INT32 k, UNT32 n);
VOID xccvDivCINT16( CINT16 *a, INT32 i, CINT16 *b, INT32 j, CINT16 *c, INT32 k, UNT32 n);
VOID xccvDivCINT32( CINT32 *a, INT32 i, CINT32 *b, INT32 j, CINT32 *c, INT32 k, UNT32 n);
VOID xccvDivCINT64( CINT64 *a, INT32 i, CINT64 *b, INT32 j, CINT64 *c, INT32 k, UNT32 n);
VOID xccvDivCUNT08( CUNT08 *a, INT32 i, CUNT08 *b, INT32 j, CUNT08 *c, INT32 k, UNT32 n);
VOID xccvDivCUNT16( CUNT16 *a, INT32 i, CUNT16 *b, INT32 j, CUNT16 *c, INT32 k, UNT32 n);
VOID xccvDivCUNT32( CUNT32 *a, INT32 i, CUNT32 *b, INT32 j, CUNT32 *c, INT32 k, UNT32 n);
VOID xccvDivCUNT64( CUNT64 *a, INT32 i, CUNT64 *b, INT32 j, CUNT64 *c, INT32 k, UNT32 n);

/* xccvSwapEndian functions -----------------------------------------------------------------------*/
VOID xccvSwapEndianINT16(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n);
VOID xccvSwapEndianINT32(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n);
VOID xccvSwapEndianINT64(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n);

/* xccvFill functions --------------------------------------------------------*/
VOID xccvFillFLT32 (FLT32 *a, INT32 i,  FLT32 b, UNT32 n);
VOID xccvFillFLT64 (FLT64 *a, INT32 i,  FLT64 b, UNT32 n);
VOID xccvFillFLT96 (FLT96 *a, INT32 i,  FLT96 b, UNT32 n);
VOID xccvFillINT08 (INT08 *a, INT32 i,  INT08 b, UNT32 n);
VOID xccvFillINT16 (INT16 *a, INT32 i,  INT16 b, UNT32 n);
VOID xccvFillINT32 (INT32 *a, INT32 i,  INT32 b, UNT32 n);
VOID xccvFillINT64 (INT64 *a, INT32 i,  INT64 b, UNT32 n);
VOID xccvFillUNT08 (UNT08 *a, INT32 i,  UNT08 b, UNT32 n);
VOID xccvFillUNT16 (UNT16 *a, INT32 i,  UNT16 b, UNT32 n);
VOID xccvFillUNT32 (UNT32 *a, INT32 i,  UNT32 b, UNT32 n);
VOID xccvFillUNT64 (UNT64 *a, INT32 i,  UNT64 b, UNT32 n);
VOID xccvFillCFLT32(CFLT32 *a, INT32 i, CFLT32 b, UNT32 n);
VOID xccvFillCFLT64(CFLT64 *a, INT32 i, CFLT64 b, UNT32 n);
VOID xccvFillCFLT96(CFLT96 *a, INT32 i, CFLT96 b, UNT32 n);
VOID xccvFillCINT08(CINT08 *a, INT32 i, CINT08 b, UNT32 n);
VOID xccvFillCINT16(CINT16 *a, INT32 i, CINT16 b, UNT32 n);
VOID xccvFillCINT32(CINT32 *a, INT32 i, CINT32 b, UNT32 n);
VOID xccvFillCINT64(CINT64 *a, INT32 i, CINT64 b, UNT32 n);
VOID xccvFillCUNT08(CUNT08 *a, INT32 i, CUNT08 b, UNT32 n);
VOID xccvFillCUNT16(CUNT16 *a, INT32 i, CUNT16 b, UNT32 n);
VOID xccvFillCUNT32(CUNT32 *a, INT32 i, CUNT32 b, UNT32 n);
VOID xccvFillCUNT64(CUNT64 *a, INT32 i, CUNT64 b, UNT32 n);
VOID xccvFillVFLT32(VFLT32 *a, INT32 i, VFLT32 b, UNT32 n);
VOID xccvFillVFLT64(VFLT64 *a, INT32 i, VFLT64 b, UNT32 n);
VOID xccvFillVFLT96(VFLT96 *a, INT32 i, VFLT96 b, UNT32 n);
VOID xccvFillVINT08(VINT08 *a, INT32 i, VINT08 b, UNT32 n);
VOID xccvFillVINT16(VINT16 *a, INT32 i, VINT16 b, UNT32 n);
VOID xccvFillVINT32(VINT32 *a, INT32 i, VINT32 b, UNT32 n);
VOID xccvFillVINT64(VINT64 *a, INT32 i, VINT64 b, UNT32 n);
VOID xccvFillVUNT08(VUNT08 *a, INT32 i, VUNT08 b, UNT32 n);
VOID xccvFillVUNT16(VUNT16 *a, INT32 i, VUNT16 b, UNT32 n);
VOID xccvFillVUNT32(VUNT32 *a, INT32 i, VUNT32 b, UNT32 n);
VOID xccvFillVUNT64(VUNT64 *a, INT32 i, VUNT64 b, UNT32 n);

/* xccvFlip functions --------------------------------------------------------*/
VOID xccvFlipFLT32 (VOID *a, VOID *b, UNT32 n);
VOID xccvFlipFLT64 (VOID *a, VOID *b, UNT32 n);
VOID xccvFlipFLT96 (VOID *a, VOID *b, UNT32 n);
VOID xccvFlipINT08 (VOID *a, VOID *b, UNT32 n);
VOID xccvFlipINT16 (VOID *a, VOID *b, UNT32 n);
VOID xccvFlipINT32 (VOID *a, VOID *b, UNT32 n);
VOID xccvFlipINT64 (VOID *a, VOID *b, UNT32 n);
VOID xccvFlipUNT08 (VOID *a, VOID *b, UNT32 n);
VOID xccvFlipUNT16 (VOID *a, VOID *b, UNT32 n);
VOID xccvFlipUNT32 (VOID *a, VOID *b, UNT32 n);
VOID xccvFlipUNT64 (VOID *a, VOID *b, UNT32 n);
VOID xccvFlipCFLT32(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipCFLT64(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipCFLT96(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipCINT08(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipCINT16(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipCINT32(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipCINT64(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipCUNT08(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipCUNT16(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipCUNT32(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipCUNT64(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipVFLT32(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipVFLT64(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipVFLT96(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipVINT08(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipVINT16(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipVINT32(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipVINT64(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipVUNT08(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipVUNT16(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipVUNT32(VOID *a, VOID *b, UNT32 n);
VOID xccvFlipVUNT64(VOID *a, VOID *b, UNT32 n);

/* xccvMulSum functions -------------------------------------------------------*/
FLT32  xccvMulSumFLT32 (FLT32 *a,  INT32 i, FLT32 *b,  INT32 j, UNT32 n );
FLT64  xccvMulSumFLT64 (FLT64 *a,  INT32 i, FLT64 *b,  INT32 j, UNT32 n );
FLT96  xccvMulSumFLT96 (FLT96 *a,  INT32 i, FLT96 *b,  INT32 j, UNT32 n );
INT08  xccvMulSumINT08 (INT08 *a,  INT32 i, INT08 *b,  INT32 j, UNT32 n );
INT16  xccvMulSumINT16 (INT16 *a,  INT32 i, INT16 *b,  INT32 j, UNT32 n );
INT32  xccvMulSumINT32 (INT32 *a,  INT32 i, INT32 *b,  INT32 j, UNT32 n );
INT64  xccvMulSumINT64 (INT64 *a,  INT32 i, INT64 *b,  INT32 j, UNT32 n );
UNT08  xccvMulSumUNT08 (UNT08 *a,  INT32 i, UNT08 *b,  INT32 j, UNT32 n );
UNT16  xccvMulSumUNT16 (UNT16 *a,  INT32 i, UNT16 *b,  INT32 j, UNT32 n );
UNT32  xccvMulSumUNT32 (UNT32 *a,  INT32 i, UNT32 *b,  INT32 j, UNT32 n );
UNT64  xccvMulSumUNT64 (UNT64 *a,  INT32 i, UNT64 *b,  INT32 j, UNT32 n );
CFLT32 xccvMulSumCFLT32(CFLT32 *a, INT32 i, CFLT32 *b, INT32 j, UNT32 n );
CFLT64 xccvMulSumCFLT64(CFLT64 *a, INT32 i, CFLT64 *b, INT32 j, UNT32 n );
CINT08 xccvMulSumCINT08(CINT08 *a, INT32 i, CINT08 *b, INT32 j, UNT32 n );
CINT16 xccvMulSumCINT16(CINT16 *a, INT32 i, CINT16 *b, INT32 j, UNT32 n );
CINT32 xccvMulSumCINT32(CINT32 *a, INT32 i, CINT32 *b, INT32 j, UNT32 n );
CINT64 xccvMulSumCINT64(CINT64 *a, INT32 i, CINT64 *b, INT32 j, UNT32 n );
CUNT08 xccvMulSumCUNT08(CUNT08 *a, INT32 i, CUNT08 *b, INT32 j, UNT32 n );
CUNT16 xccvMulSumCUNT16(CUNT16 *a, INT32 i, CUNT16 *b, INT32 j, UNT32 n );
CUNT32 xccvMulSumCUNT32(CUNT32 *a, INT32 i, CUNT32 *b, INT32 j, UNT32 n );
CUNT64 xccvMulSumCUNT64(CUNT64 *a, INT32 i, CUNT64 *b, INT32 j, UNT32 n );
FLT32 xccvMulSumFLT32FLT64(FLT32 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n );

// xccvMax functions.
//------------------------------------------------------------------------------
FLT32 xccvMaxFLT32( FLT32 *a, INT32 i, UNT32 n );
FLT64 xccvMaxFLT64( FLT64 *a, INT32 i, UNT32 n );
FLT96 xccvMaxFLT96( FLT96 *a, INT32 i, UNT32 n );
INT08 xccvMaxINT08( INT08 *a, INT32 i, UNT32 n );
INT16 xccvMaxINT16( INT16 *a, INT32 i, UNT32 n );
INT32 xccvMaxINT32( INT32 *a, INT32 i, UNT32 n );
INT64 xccvMaxINT64( INT64 *a, INT32 i, UNT32 n );
UNT08 xccvMaxUNT08( UNT08 *a, INT32 i, UNT32 n );
UNT16 xccvMaxUNT16( UNT16 *a, INT32 i, UNT32 n );
UNT32 xccvMaxUNT32( UNT32 *a, INT32 i, UNT32 n );
UNT64 xccvMaxUNT64( UNT64 *a, INT32 i, UNT32 n );

// xccvMean functions.
//------------------------------------------------------------------------------
FLT32  xccvMeanFLT32 (FLT32 *a,  INT32 i, UNT32 n );
FLT64  xccvMeanFLT64 (FLT64 *a,  INT32 i, UNT32 n );
FLT96  xccvMeanFLT96 (FLT96 *a,  INT32 i, UNT32 n );
INT08  xccvMeanINT08 (INT08 *a,  INT32 i, UNT32 n );
INT16  xccvMeanINT16 (INT16 *a,  INT32 i, UNT32 n );
INT32  xccvMeanINT32 (INT32 *a,  INT32 i, UNT32 n );
INT64  xccvMeanINT64 (INT64 *a,  INT32 i, UNT32 n );
UNT08  xccvMeanUNT08 (UNT08 *a,  INT32 i, UNT32 n );
UNT16  xccvMeanUNT16 (UNT16 *a,  INT32 i, UNT32 n );
UNT32  xccvMeanUNT32 (UNT32 *a,  INT32 i, UNT32 n );
UNT64  xccvMeanUNT64 (UNT64 *a,  INT32 i, UNT32 n );
CFLT32 xccvMeanCFLT32(CFLT32 *a, INT32 i, UNT32 n );
CFLT64 xccvMeanCFLT64(CFLT64 *a, INT32 i, UNT32 n );
CFLT96 xccvMeanCFLT96(CFLT96 *a, INT32 i, UNT32 n );
CINT08 xccvMeanCINT08(CINT08 *a, INT32 i, UNT32 n );
CINT16 xccvMeanCINT16(CINT16 *a, INT32 i, UNT32 n );
CINT32 xccvMeanCINT32(CINT32 *a, INT32 i, UNT32 n );
CINT64 xccvMeanCINT64(CINT64 *a, INT32 i, UNT32 n );
CUNT08 xccvMeanCUNT08(CUNT08 *a, INT32 i, UNT32 n );
CUNT16 xccvMeanCUNT16(CUNT16 *a, INT32 i, UNT32 n );
CUNT32 xccvMeanCUNT32(CUNT32 *a, INT32 i, UNT32 n );
CUNT64 xccvMeanCUNT64(CUNT64 *a, INT32 i, UNT32 n );

// xccvMin functions.
//------------------------------------------------------------------------------
FLT32 xccvMinFLT32( FLT32 *a, INT32 i, UNT32 n );
FLT64 xccvMinFLT64( FLT64 *a, INT32 i, UNT32 n );
FLT96 xccvMinFLT96( FLT96 *a, INT32 i, UNT32 n );
INT08 xccvMinINT08( INT08 *a, INT32 i, UNT32 n );
INT16 xccvMinINT16( INT16 *a, INT32 i, UNT32 n );
INT32 xccvMinINT32( INT32 *a, INT32 i, UNT32 n );
INT64 xccvMinINT64( INT64 *a, INT32 i, UNT32 n );
UNT08 xccvMinUNT08( UNT08 *a, INT32 i, UNT32 n );
UNT16 xccvMinUNT16( UNT16 *a, INT32 i, UNT32 n );
UNT32 xccvMinUNT32( UNT32 *a, INT32 i, UNT32 n );
UNT64 xccvMinUNT64( UNT64 *a, INT32 i, UNT32 n );

// xccvMul functions.
//------------------------------------------------------------------------------
VOID xccvMulFLT32 (FLT32  *a, INT32 i, FLT32  *b, INT32 j, FLT32  *c, INT32 k, UNT32 n);
VOID xccvMulFLT64 (FLT64  *a, INT32 i, FLT64  *b, INT32 j, FLT64  *c, INT32 k, UNT32 n);
VOID xccvMulFLT96 (FLT96  *a, INT32 i, FLT96  *b, INT32 j, FLT96  *c, INT32 k, UNT32 n);
VOID xccvMulINT08 (INT08  *a, INT32 i, INT08  *b, INT32 j, INT08  *c, INT32 k, UNT32 n);
VOID xccvMulINT16 (INT16  *a, INT32 i, INT16  *b, INT32 j, INT16  *c, INT32 k, UNT32 n);
VOID xccvMulINT32 (INT32  *a, INT32 i, INT32  *b, INT32 j, INT32  *c, INT32 k, UNT32 n);
VOID xccvMulINT64 (INT64  *a, INT32 i, INT64  *b, INT32 j, INT64  *c, INT32 k, UNT32 n);
VOID xccvMulUNT08 (UNT08  *a, INT32 i, UNT08  *b, INT32 j, UNT08  *c, INT32 k, UNT32 n);
VOID xccvMulUNT16 (UNT16  *a, INT32 i, UNT16  *b, INT32 j, UNT16  *c, INT32 k, UNT32 n);
VOID xccvMulUNT32 (UNT32  *a, INT32 i, UNT32  *b, INT32 j, UNT32  *c, INT32 k, UNT32 n);
VOID xccvMulUNT64 (UNT64  *a, INT32 i, UNT64  *b, INT32 j, UNT64  *c, INT32 k, UNT32 n);
VOID xccvMulCFLT32(CFLT32 *a, INT32 i, CFLT32 *b, INT32 j, CFLT32 *c, INT32 k, UNT32 n);
VOID xccvMulCFLT64(CFLT64 *a, INT32 i, CFLT64 *b, INT32 j, CFLT64 *c, INT32 k, UNT32 n);
VOID xccvMulCFLT96(CFLT96 *a, INT32 i, CFLT96 *b, INT32 j, CFLT96 *c, INT32 k, UNT32 n);
VOID xccvMulCINT08(CINT08 *a, INT32 i, CINT08 *b, INT32 j, CINT08 *c, INT32 k, UNT32 n);
VOID xccvMulCINT16(CINT16 *a, INT32 i, CINT16 *b, INT32 j, CINT16 *c, INT32 k, UNT32 n);
VOID xccvMulCINT32(CINT32 *a, INT32 i, CINT32 *b, INT32 j, CINT32 *c, INT32 k, UNT32 n);
VOID xccvMulCINT64(CINT64 *a, INT32 i, CINT64 *b, INT32 j, CINT64 *c, INT32 k, UNT32 n);
VOID xccvMulCUNT08(CUNT08 *a, INT32 i, CUNT08 *b, INT32 j, CUNT08 *c, INT32 k, UNT32 n);
VOID xccvMulCUNT16(CUNT16 *a, INT32 i, CUNT16 *b, INT32 j, CUNT16 *c, INT32 k, UNT32 n);
VOID xccvMulCUNT32(CUNT32 *a, INT32 i, CUNT32 *b, INT32 j, CUNT32 *c, INT32 k, UNT32 n);
VOID xccvMulCUNT64(CUNT64 *a, INT32 i, CUNT64 *b, INT32 j, CUNT64 *c, INT32 k, UNT32 n);

// xccvRand functions.
//------------------------------------------------------------------------------
VOID xccvRandFLT32(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n );
VOID xccvRandFLT64(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n );
VOID xccvRandFLT96(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n );
VOID xccvRandINT08(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n );
VOID xccvRandINT16(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n );
VOID xccvRandINT32(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n );
VOID xccvRandINT64(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n );
VOID xccvRandUNT08(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n );
VOID xccvRandUNT16(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n );
VOID xccvRandUNT32(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n );
VOID xccvRandUNT64(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n );

// xccvRandN functions.
//------------------------------------------------------------------------------
VOID xccvRandNFLT32(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n );
VOID xccvRandNFLT64(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n );
VOID xccvRandNFLT96(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n );
VOID xccvRandNINT08(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n );
VOID xccvRandNINT16(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n );
VOID xccvRandNINT32(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n );
VOID xccvRandNINT64(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n );
VOID xccvRandNUNT08(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n );
VOID xccvRandNUNT16(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n );
VOID xccvRandNUNT32(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n );
VOID xccvRandNUNT64(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n );

// xccvRamp functions.
//------------------------------------------------------------------------------
VOID xccvRampFLT32 (FLT32 *a, INT32 i,  FLT32 strt,  FLT32 inc, UNT32 n);
VOID xccvRampFLT64 (FLT64 *a, INT32 i,  FLT64 strt,  FLT64 inc, UNT32 n);
VOID xccvRampFLT96 (FLT96 *a, INT32 i,  FLT96 strt,  FLT96 inc, UNT32 n);
VOID xccvRampINT08 (INT08 *a, INT32 i,  INT08 strt,  INT08 inc, UNT32 n);
VOID xccvRampINT16 (INT16 *a, INT32 i,  INT16 strt,  INT16 inc, UNT32 n);
VOID xccvRampINT32 (INT32 *a, INT32 i,  INT32 strt,  INT32 inc, UNT32 n);
VOID xccvRampINT64 (INT64 *a, INT32 i,  INT64 strt,  INT64 inc, UNT32 n);
VOID xccvRampUNT08 (UNT08 *a, INT32 i,  UNT08 strt,  UNT08 inc, UNT32 n);
VOID xccvRampUNT16 (UNT16 *a, INT32 i,  UNT16 strt,  UNT16 inc, UNT32 n);
VOID xccvRampUNT32 (UNT32 *a, INT32 i,  UNT32 strt,  UNT32 inc, UNT32 n);
VOID xccvRampUNT64 (UNT64 *a, INT32 i,  UNT64 strt,  UNT64 inc, UNT32 n);
VOID xccvRampCFLT32(CFLT32 *a, INT32 i, CFLT32 strt, CFLT32 inc, UNT32 n);
VOID xccvRampCFLT64(CFLT64 *a, INT32 i, CFLT64 strt, CFLT64 inc, UNT32 n);
VOID xccvRampCFLT96(CFLT96 *a, INT32 i, CFLT96 strt, CFLT96 inc, UNT32 n);
VOID xccvRampCINT08(CINT08 *a, INT32 i, CINT08 strt, CINT08 inc, UNT32 n);
VOID xccvRampCINT16(CINT16 *a, INT32 i, CINT16 strt, CINT16 inc, UNT32 n);
VOID xccvRampCINT32(CINT32 *a, INT32 i, CINT32 strt, CINT32 inc, UNT32 n);
VOID xccvRampCINT64(CINT64 *a, INT32 i, CINT64 strt, CINT64 inc, UNT32 n);
VOID xccvRampCUNT08(CUNT08 *a, INT32 i, CUNT08 strt, CUNT08 inc, UNT32 n);
VOID xccvRampCUNT16(CUNT16 *a, INT32 i, CUNT16 strt, CUNT16 inc, UNT32 n);
VOID xccvRampCUNT32(CUNT32 *a, INT32 i, CUNT32 strt, CUNT32 inc, UNT32 n);
VOID xccvRampCUNT64(CUNT64 *a, INT32 i, CUNT64 strt, CUNT64 inc, UNT32 n);
VOID xccvRampVFLT32(VFLT32 *a, INT32 i, VFLT32 strt, VFLT32 inc, UNT32 n);
VOID xccvRampVFLT64(VFLT64 *a, INT32 i, VFLT64 strt, VFLT64 inc, UNT32 n);
VOID xccvRampVFLT96(VFLT96 *a, INT32 i, VFLT96 strt, VFLT96 inc, UNT32 n);
VOID xccvRampVINT08(VINT08 *a, INT32 i, VINT08 strt, VINT08 inc, UNT32 n);
VOID xccvRampVINT16(VINT16 *a, INT32 i, VINT16 strt, VINT16 inc, UNT32 n);
VOID xccvRampVINT32(VINT32 *a, INT32 i, VINT32 strt, VINT32 inc, UNT32 n);
VOID xccvRampVINT64(VINT64 *a, INT32 i, VINT64 strt, VINT64 inc, UNT32 n);
VOID xccvRampVUNT08(VUNT08 *a, INT32 i, VUNT08 strt, VUNT08 inc, UNT32 n);
VOID xccvRampVUNT16(VUNT16 *a, INT32 i, VUNT16 strt, VUNT16 inc, UNT32 n);
VOID xccvRampVUNT32(VUNT32 *a, INT32 i, VUNT32 strt, VUNT32 inc, UNT32 n);
VOID xccvRampVUNT64(VUNT64 *a, INT32 i, VUNT64 strt, VUNT64 inc, UNT32 n);

// xccvRound functions.
//------------------------------------------------------------------------------
VOID xccvRoundFLT32INT08( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT32INT16( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT32INT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT32INT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT32UNT08( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT32UNT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT32UNT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT32FLT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT32FLT96( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT64INT08( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT64INT16( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT64INT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT64INT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT64UNT08( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT64UNT16( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT64UNT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT64UNT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT64FLT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT64FLT96( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT96INT08( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT96INT16( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT96INT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT96INT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT96UNT08( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT96UNT16( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT96UNT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT96UNT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT96FLT32( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT96FLT64( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );
VOID xccvRoundFLT96( VOID  *a, INT32 i, VOID  *b, INT32 j, UNT32 n );

// xccvSin functions.
//------------------------------------------------------------------------------
VOID xccvSinFLT32(FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n );
VOID xccvSinFLT64(FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n );
VOID xccvSinFLT96(FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n );

// xccvSinT functions.
//------------------------------------------------------------------------------
VOID xccvSinTFLT32(FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n );
VOID xccvSinTFLT64(FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n );
VOID xccvSinTFLT96(FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n );

// xccvsSub functions.
//------------------------------------------------------------------------------
VOID xccvSubFLT32 ( FLT32 *a,  INT32 i, FLT32 *b,  INT32 j, FLT32 *c,  INT32 k, UNT32 n);
VOID xccvSubFLT64 ( FLT64 *a,  INT32 i, FLT64 *b,  INT32 j, FLT64 *c,  INT32 k, UNT32 n);
VOID xccvSubFLT96 ( FLT96 *a,  INT32 i, FLT96 *b,  INT32 j, FLT96 *c,  INT32 k, UNT32 n);
VOID xccvSubINT08 ( INT08 *a,  INT32 i, INT08 *b,  INT32 j, INT08 *c,  INT32 k, UNT32 n);
VOID xccvSubINT16 ( INT16 *a,  INT32 i, INT16 *b,  INT32 j, INT16 *c,  INT32 k, UNT32 n);
VOID xccvSubINT32 ( INT32 *a,  INT32 i, INT32 *b,  INT32 j, INT32 *c,  INT32 k, UNT32 n);
VOID xccvSubINT64 ( INT64 *a,  INT32 i, INT64 *b,  INT32 j, INT64 *c,  INT32 k, UNT32 n);
VOID xccvSubUNT08 ( UNT08 *a,  INT32 i, UNT08 *b,  INT32 j, UNT08 *c,  INT32 k, UNT32 n);
VOID xccvSubUNT16 ( UNT16 *a,  INT32 i, UNT16 *b,  INT32 j, UNT16 *c,  INT32 k, UNT32 n);
VOID xccvSubUNT32 ( UNT32 *a,  INT32 i, UNT32 *b,  INT32 j, UNT32 *c,  INT32 k, UNT32 n);
VOID xccvSubUNT64 ( UNT64 *a,  INT32 i, UNT64 *b,  INT32 j, UNT64 *c,  INT32 k, UNT32 n);
VOID xccvSubCFLT32( CFLT32 *a, INT32 i, CFLT32 *b, INT32 j, CFLT32 *c, INT32 k, UNT32 n);
VOID xccvSubCFLT64( CFLT64 *a, INT32 i, CFLT64 *b, INT32 j, CFLT64 *c, INT32 k, UNT32 n);
VOID xccvSubCFLT96( CFLT96 *a, INT32 i, CFLT96 *b, INT32 j, CFLT96 *c, INT32 k, UNT32 n);
VOID xccvSubCINT08( CINT08 *a, INT32 i, CINT08 *b, INT32 j, CINT08 *c, INT32 k, UNT32 n);
VOID xccvSubCINT16( CINT16 *a, INT32 i, CINT16 *b, INT32 j, CINT16 *c, INT32 k, UNT32 n);
VOID xccvSubCINT32( CINT32 *a, INT32 i, CINT32 *b, INT32 j, CINT32 *c, INT32 k, UNT32 n);
VOID xccvSubCINT64( CINT64 *a, INT32 i, CINT64 *b, INT32 j, CINT64 *c, INT32 k, UNT32 n);
VOID xccvSubCUNT08( CUNT08 *a, INT32 i, CUNT08 *b, INT32 j, CUNT08 *c, INT32 k, UNT32 n);
VOID xccvSubCUNT16( CUNT16 *a, INT32 i, CUNT16 *b, INT32 j, CUNT16 *c, INT32 k, UNT32 n);
VOID xccvSubCUNT32( CUNT32 *a, INT32 i, CUNT32 *b, INT32 j, CUNT32 *c, INT32 k, UNT32 n);
VOID xccvSubCUNT64( CUNT64 *a, INT32 i, CUNT64 *b, INT32 j, CUNT64 *c, INT32 k, UNT32 n);
VOID xccvSubVFLT32( VFLT32 *a, INT32 i, VFLT32 *b, INT32 j, VFLT32 *c, INT32 k, UNT32 n);
VOID xccvSubVFLT64( VFLT64 *a, INT32 i, VFLT64 *b, INT32 j, VFLT64 *c, INT32 k, UNT32 n);
VOID xccvSubVFLT96( VFLT96 *a, INT32 i, VFLT96 *b, INT32 j, VFLT96 *c, INT32 k, UNT32 n);
VOID xccvSubVINT08( VINT08 *a, INT32 i, VINT08 *b, INT32 j, VINT08 *c, INT32 k, UNT32 n);
VOID xccvSubVINT16( VINT16 *a, INT32 i, VINT16 *b, INT32 j, VINT16 *c, INT32 k, UNT32 n);
VOID xccvSubVINT32( VINT32 *a, INT32 i, VINT32 *b, INT32 j, VINT32 *c, INT32 k, UNT32 n);
VOID xccvSubVINT64( VINT64 *a, INT32 i, VINT64 *b, INT32 j, VINT64 *c, INT32 k, UNT32 n);
VOID xccvSubVUNT08( VUNT08 *a, INT32 i, VUNT08 *b, INT32 j, VUNT08 *c, INT32 k, UNT32 n);
VOID xccvSubVUNT16( VUNT16 *a, INT32 i, VUNT16 *b, INT32 j, VUNT16 *c, INT32 k, UNT32 n);
VOID xccvSubVUNT32( VUNT32 *a, INT32 i, VUNT32 *b, INT32 j, VUNT32 *c, INT32 k, UNT32 n);
VOID xccvSubVUNT64( VUNT64 *a, INT32 i, VUNT64 *b, INT32 j, VUNT64 *c, INT32 k, UNT32 n);

// xccvSum functions.
//------------------------------------------------------------------------------
FLT32  xccvSumFLT32 ( VOID  *a, INT32 i, UNT32 n );
FLT64  xccvSumFLT64 ( VOID  *a, INT32 i, UNT32 n );
FLT96  xccvSumFLT96 ( VOID  *a, INT32 i, UNT32 n );
INT08  xccvSumINT08 ( VOID  *a, INT32 i, UNT32 n );
INT16  xccvSumINT16 ( VOID  *a, INT32 i, UNT32 n );
INT32  xccvSumINT32 ( VOID  *a, INT32 i, UNT32 n );
INT64  xccvSumINT64 ( VOID  *a, INT32 i, UNT32 n );
UNT08  xccvSumUNT08 ( VOID  *a, INT32 i, UNT32 n );
UNT16  xccvSumUNT16 ( VOID  *a, INT32 i, UNT32 n );
UNT32  xccvSumUNT32 ( VOID  *a, INT32 i, UNT32 n );
UNT64  xccvSumUNT64 ( VOID  *a, INT32 i, UNT32 n );
CFLT32 xccvSumCFLT32( VOID  *a, INT32 i, UNT32 n );
CFLT64 xccvSumCFLT64( VOID  *a, INT32 i, UNT32 n );
CFLT96 xccvSumCFLT96( VOID  *a, INT32 i, UNT32 n );
CINT08 xccvSumCINT08( VOID  *a, INT32 i, UNT32 n );
CINT16 xccvSumCINT16( VOID  *a, INT32 i, UNT32 n );
CINT32 xccvSumCINT32( VOID  *a, INT32 i, UNT32 n );
CINT64 xccvSumCINT64( VOID  *a, INT32 i, UNT32 n );
CUNT08 xccvSumCUNT08( VOID  *a, INT32 i, UNT32 n );
CUNT16 xccvSumCUNT16( VOID  *a, INT32 i, UNT32 n );
CUNT32 xccvSumCUNT32( VOID  *a, INT32 i, UNT32 n );
CUNT64 xccvSumCUNT64( VOID  *a, INT32 i, UNT32 n );
VFLT32 xccvSumVFLT32( VOID  *a, INT32 i, UNT32 n );
VFLT64 xccvSumVFLT64( VOID  *a, INT32 i, UNT32 n );
VFLT96 xccvSumVFLT96( VOID  *a, INT32 i, UNT32 n );
VINT08 xccvSumVINT08( VOID  *a, INT32 i, UNT32 n );
VINT16 xccvSumVINT16( VOID  *a, INT32 i, UNT32 n );
VINT32 xccvSumVINT32( VOID  *a, INT32 i, UNT32 n );
VINT64 xccvSumVINT64( VOID  *a, INT32 i, UNT32 n );
VUNT08 xccvSumVUNT08( VOID  *a, INT32 i, UNT32 n );
VUNT16 xccvSumVUNT16( VOID  *a, INT32 i, UNT32 n );
VUNT32 xccvSumVUNT32( VOID  *a, INT32 i, UNT32 n );
VUNT64 xccvSumVUNT64( VOID  *a, INT32 i, UNT32 n );
INT32 xccvSumINT08INT32( VOID  *a, INT32 i, UNT32 n );
INT32 xccvSumINT16INT32( VOID  *a, INT32 i, UNT32 n );
CINT32 xccvSumCINT08CINT32( VOID  *a, INT32 i, UNT32 n );
CINT32 xccvSumCINT16CINT32( VOID  *a, INT32 i, UNT32 n );

// xccvZero functions.
//------------------------------------------------------------------------------
VOID xccvZeroFLT32(FLT32 *a, INT32 i, UNT32 n );
VOID xccvZeroFLT64(FLT64 *a, INT32 i, UNT32 n );
VOID xccvZeroFLT96(FLT96 *a, INT32 i, UNT32 n );
VOID xccvZeroINT08(INT08 *a, INT32 i, UNT32 n );
VOID xccvZeroINT16(INT16 *a, INT32 i, UNT32 n );
VOID xccvZeroINT32(INT32 *a, INT32 i, UNT32 n );
VOID xccvZeroINT64(INT64 *a, INT32 i, UNT32 n );
VOID xccvZeroUNT08(UNT08 *a, INT32 i, UNT32 n );
VOID xccvZeroUNT16(UNT16 *a, INT32 i, UNT32 n );
VOID xccvZeroUNT32(UNT32 *a, INT32 i, UNT32 n );
VOID xccvZeroUNT64(UNT64 *a, INT32 i, UNT32 n );

// xccvsAdd functions.
//------------------------------------------------------------------------------
VOID xccvsAddFLT32(FLT32 *a, INT32 i, FLT32 b, FLT32 *c, INT32 k, UNT32 n );
VOID xccvsAddFLT64(FLT64 *a, INT32 i, FLT64 b, FLT64 *c, INT32 k, UNT32 n );
VOID xccvsAddFLT96(FLT96 *a, INT32 i, FLT96 b, FLT96 *c, INT32 k, UNT32 n );
VOID xccvsAddINT08(INT08 *a, INT32 i, INT08 b, INT08 *c, INT32 k, UNT32 n );
VOID xccvsAddINT16(INT16 *a, INT32 i, INT16 b, INT16 *c, INT32 k, UNT32 n );
VOID xccvsAddINT32(INT32 *a, INT32 i, INT32 b, INT32 *c, INT32 k, UNT32 n );
VOID xccvsAddINT64(INT64 *a, INT32 i, INT64 b, INT64 *c, INT32 k, UNT32 n );
VOID xccvsAddUNT08(UNT08 *a, INT32 i, UNT08 b, UNT08 *c, INT32 k, UNT32 n );
VOID xccvsAddUNT16(UNT16 *a, INT32 i, UNT16 b, UNT16 *c, INT32 k, UNT32 n );
VOID xccvsAddUNT32(UNT32 *a, INT32 i, UNT32 b, UNT32 *c, INT32 k, UNT32 n );
VOID xccvsAddUNT64(UNT64 *a, INT32 i, UNT64 b, UNT64 *c, INT32 k, UNT32 n );

// xccvsDiv functions.
//------------------------------------------------------------------------------
VOID xccvsDivFLT32(FLT32 *a, INT32 i, FLT32 b, FLT32 *c, INT32 k, UNT32 n );
VOID xccvsDivFLT64(FLT64 *a, INT32 i, FLT64 b, FLT64 *c, INT32 k, UNT32 n );
VOID xccvsDivFLT96(FLT96 *a, INT32 i, FLT96 b, FLT96 *c, INT32 k, UNT32 n );
VOID xccvsDivINT08(INT08 *a, INT32 i, INT08 b, INT08 *c, INT32 k, UNT32 n );
VOID xccvsDivINT16(INT16 *a, INT32 i, INT16 b, INT16 *c, INT32 k, UNT32 n );
VOID xccvsDivINT32(INT32 *a, INT32 i, INT32 b, INT32 *c, INT32 k, UNT32 n );
VOID xccvsDivINT64(INT64 *a, INT32 i, INT64 b, INT64 *c, INT32 k, UNT32 n );
VOID xccvsDivUNT08(UNT08 *a, INT32 i, UNT08 b, UNT08 *c, INT32 k, UNT32 n );
VOID xccvsDivUNT16(UNT16 *a, INT32 i, UNT16 b, UNT16 *c, INT32 k, UNT32 n );
VOID xccvsDivUNT32(UNT32 *a, INT32 i, UNT32 b, UNT32 *c, INT32 k, UNT32 n );
VOID xccvsDivUNT64(UNT64 *a, INT32 i, UNT64 b, UNT64 *c, INT32 k, UNT32 n );

// xccvsMul functions.
//------------------------------------------------------------------------------
VOID xccvsMulFLT32(FLT32 *a, INT32 i, FLT32 b, FLT32 *c, INT32 k, UNT32 n );
VOID xccvsMulFLT64(FLT64 *a, INT32 i, FLT64 b, FLT64 *c, INT32 k, UNT32 n );
VOID xccvsMulFLT96(FLT96 *a, INT32 i, FLT96 b, FLT96 *c, INT32 k, UNT32 n );
VOID xccvsMulINT08(INT08 *a, INT32 i, INT08 b, INT08 *c, INT32 k, UNT32 n );
VOID xccvsMulINT16(INT16 *a, INT32 i, INT16 b, INT16 *c, INT32 k, UNT32 n );
VOID xccvsMulINT32(INT32 *a, INT32 i, INT32 b, INT32 *c, INT32 k, UNT32 n );
VOID xccvsMulINT64(INT64 *a, INT32 i, INT64 b, INT64 *c, INT32 k, UNT32 n );
VOID xccvsMulUNT08(UNT08 *a, INT32 i, UNT08 b, UNT08 *c, INT32 k, UNT32 n );
VOID xccvsMulUNT16(UNT16 *a, INT32 i, UNT16 b, UNT16 *c, INT32 k, UNT32 n );
VOID xccvsMulUNT32(UNT32 *a, INT32 i, UNT32 b, UNT32 *c, INT32 k, UNT32 n );
VOID xccvsMulUNT64(UNT64 *a, INT32 i, UNT64 b, UNT64 *c, INT32 k, UNT32 n );
VOID xccvsMulCFLT32( CFLT32 *a, INT32 i, CFLT32 b, CFLT32 *c, INT32 k, UNT32 n);
VOID xccvsMulCFLT64( CFLT64 *a, INT32 i, CFLT64 b, CFLT64 *c, INT32 k, UNT32 n);
VOID xccvsMulCFLT96( CFLT96 *a, INT32 i, CFLT96 b, CFLT96 *c, INT32 k, UNT32 n);
VOID xccvsMulCINT08( CINT08 *a, INT32 i, CINT08 b, CINT08 *c, INT32 k, UNT32 n);
VOID xccvsMulCINT16( CINT16 *a, INT32 i, CINT16 b, CINT16 *c, INT32 k, UNT32 n);
VOID xccvsMulCINT32( CINT32 *a, INT32 i, CINT32 b, CINT32 *c, INT32 k, UNT32 n);
VOID xccvsMulCINT64( CINT64 *a, INT32 i, CINT64 b, CINT64 *c, INT32 k, UNT32 n);
VOID xccvsMulCUNT08( CUNT08 *a, INT32 i, CUNT08 b, CUNT08 *c, INT32 k, UNT32 n);
VOID xccvsMulCUNT16( CUNT16 *a, INT32 i, CUNT16 b, CUNT16 *c, INT32 k, UNT32 n);
VOID xccvsMulCUNT32( CUNT32 *a, INT32 i, CUNT32 b, CUNT32 *c, INT32 k, UNT32 n);
VOID xccvsMulCUNT64( CUNT64 *a, INT32 i, CUNT64 b, CUNT64 *c, INT32 k, UNT32 n);
VOID xccvsMulCINT08CFLT32( CINT08 *a, INT32 i, CFLT32 b, CFLT32 *c, INT32 k, UNT32 n);

// xccvsSub functions.
//------------------------------------------------------------------------------
VOID xccvsSubFLT32 ( FLT32 *a,  INT32 i, FLT32 b,  FLT32 *c,  INT32 k, UNT32 n);
VOID xccvsSubFLT64 ( FLT64 *a,  INT32 i, FLT64 b,  FLT64 *c,  INT32 k, UNT32 n);
VOID xccvsSubFLT96 ( FLT96 *a,  INT32 i, FLT96 b,  FLT96 *c,  INT32 k, UNT32 n);
VOID xccvsSubINT08 ( INT08 *a,  INT32 i, INT08 b,  INT08 *c,  INT32 k, UNT32 n);
VOID xccvsSubINT16 ( INT16 *a,  INT32 i, INT16 b,  INT16 *c,  INT32 k, UNT32 n);
VOID xccvsSubINT32 ( INT32 *a,  INT32 i, INT32 b,  INT32 *c,  INT32 k, UNT32 n);
VOID xccvsSubINT64 ( INT64 *a,  INT32 i, INT64 b,  INT64 *c,  INT32 k, UNT32 n);
VOID xccvsSubUNT08 ( UNT08 *a,  INT32 i, UNT08 b,  UNT08 *c,  INT32 k, UNT32 n);
VOID xccvsSubUNT16 ( UNT16 *a,  INT32 i, UNT16 b,  UNT16 *c,  INT32 k, UNT32 n);
VOID xccvsSubUNT32 ( UNT32 *a,  INT32 i, UNT32 b,  UNT32 *c,  INT32 k, UNT32 n);
VOID xccvsSubUNT64 ( UNT64 *a,  INT32 i, UNT64 b,  UNT64 *c,  INT32 k, UNT32 n);
VOID xccvsSubCFLT32( CFLT32 *a, INT32 i, CFLT32 b, CFLT32 *c, INT32 k, UNT32 n);
VOID xccvsSubCFLT64( CFLT64 *a, INT32 i, CFLT64 b, CFLT64 *c, INT32 k, UNT32 n);
VOID xccvsSubCFLT96( CFLT96 *a, INT32 i, CFLT96 b, CFLT96 *c, INT32 k, UNT32 n);
VOID xccvsSubCINT08( CINT08 *a, INT32 i, CINT08 b, CINT08 *c, INT32 k, UNT32 n);
VOID xccvsSubCINT16( CINT16 *a, INT32 i, CINT16 b, CINT16 *c, INT32 k, UNT32 n);
VOID xccvsSubCINT32( CINT32 *a, INT32 i, CINT32 b, CINT32 *c, INT32 k, UNT32 n);
VOID xccvsSubCINT64( CINT64 *a, INT32 i, CINT64 b, CINT64 *c, INT32 k, UNT32 n);
VOID xccvsSubCUNT08( CUNT08 *a, INT32 i, CUNT08 b, CUNT08 *c, INT32 k, UNT32 n);
VOID xccvsSubCUNT16( CUNT16 *a, INT32 i, CUNT16 b, CUNT16 *c, INT32 k, UNT32 n);
VOID xccvsSubCUNT32( CUNT32 *a, INT32 i, CUNT32 b, CUNT32 *c, INT32 k, UNT32 n);
VOID xccvsSubCUNT64( CUNT64 *a, INT32 i, CUNT64 b, CUNT64 *c, INT32 k, UNT32 n);
VOID xccvsSubVFLT32( VFLT32 *a, INT32 i, VFLT32 b, VFLT32 *c, INT32 k, UNT32 n);
VOID xccvsSubVFLT64( VFLT64 *a, INT32 i, VFLT64 b, VFLT64 *c, INT32 k, UNT32 n);
VOID xccvsSubVFLT96( VFLT96 *a, INT32 i, VFLT96 b, VFLT96 *c, INT32 k, UNT32 n);
VOID xccvsSubVINT08( VINT08 *a, INT32 i, VINT08 b, VINT08 *c, INT32 k, UNT32 n);
VOID xccvsSubVINT16( VINT16 *a, INT32 i, VINT16 b, VINT16 *c, INT32 k, UNT32 n);
VOID xccvsSubVINT32( VINT32 *a, INT32 i, VINT32 b, VINT32 *c, INT32 k, UNT32 n);
VOID xccvsSubVINT64( VINT64 *a, INT32 i, VINT64 b, VINT64 *c, INT32 k, UNT32 n);
VOID xccvsSubVUNT08( VUNT08 *a, INT32 i, VUNT08 b, VUNT08 *c, INT32 k, UNT32 n);
VOID xccvsSubVUNT16( VUNT16 *a, INT32 i, VUNT16 b, VUNT16 *c, INT32 k, UNT32 n);
VOID xccvsSubVUNT32( VUNT32 *a, INT32 i, VUNT32 b, VUNT32 *c, INT32 k, UNT32 n);
VOID xccvsSubVUNT64( VUNT64 *a, INT32 i, VUNT64 b, VUNT64 *c, INT32 k, UNT32 n);

// xccvQuickSort functions.
//------------------------------------------------------------------------------
VOID xccvQuickSortFLT32  ( FLT32 *a,  INT32 left, INT32 rght);
VOID xccvQuickSortFLT64  ( FLT64 *a,  INT32 left, INT32 rght);
VOID xccvQuickSortFLT96  ( FLT96 *a,  INT32 left, INT32 rght);
VOID xccvQuickSortINT08  ( INT08 *a,  INT32 left, INT32 rght);
VOID xccvQuickSortINT16  ( INT16 *a,  INT32 left, INT32 rght);
VOID xccvQuickSortINT32  ( INT32 *a,  INT32 left, INT32 rght);
VOID xccvQuickSortINT64  ( INT64 *a,  INT32 left, INT32 rght);
VOID xccvQuickSortUNT08  ( UNT08 *a,  INT32 left, INT32 rght);
VOID xccvQuickSortUNT16  ( UNT16 *a,  INT32 left, INT32 rght);
VOID xccvQuickSortUNT32  ( UNT32 *a,  INT32 left, INT32 rght);
VOID xccvQuickSortUNT64  ( UNT64 *a,  INT32 left, INT32 rght);
VOID xccvQuickSortCFLT32r( CFLT32 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCFLT64r( CFLT64 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCFLT96r( CFLT96 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCINT08r( CINT08 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCINT16r( CINT16 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCINT32r( CINT32 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCINT64r( CINT64 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCUNT08r( CUNT08 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCUNT16r( CUNT16 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCUNT32r( CUNT32 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCUNT64r( CUNT64 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCFLT32i( CFLT32 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCFLT64i( CFLT64 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCFLT96i( CFLT96 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCINT08i( CINT08 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCINT16i( CINT16 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCINT32i( CINT32 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCINT64i( CINT64 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCUNT08i( CUNT08 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCUNT16i( CUNT16 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCUNT32i( CUNT32 *a, INT32 left, INT32 rght);
VOID xccvQuickSortCUNT64i( CUNT64 *a, INT32 left, INT32 rght);
VOID xccvQuickSortString( CHR08 **string, INT32 left, INT32 rght);

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus 
} 
#endif 
 
#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/
