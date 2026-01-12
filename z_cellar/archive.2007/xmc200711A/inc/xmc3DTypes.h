/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xmc3DTypes.h
// Desc: This file contains 3 dimensional data type definitions.
// Hist: When       Who  What
//       10/15/2006 ptb  Initial Port.                                                          -
/*---------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#ifndef XMC_3D_TYPES_H
#define XMC_3D_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  typedef struct
PERL_PREPROCESS  {
PERL_PREPROCESS    XXXXX x;
PERL_PREPROCESS    XXXXX y;
PERL_PREPROCESS    XXXXX z;
PERL_PREPROCESS  } VXXXXX;
#endif

//------------------------------- COMMON-CODE INT08  START.
  typedef struct
  {
    INT08 x;
    INT08 y;
    INT08 z;
  } VINT08;
//------------------------------- COMMON-CODE INT08   STOP.
//------------------------------- COMMON-CODE INT16  START.
  typedef struct
  {
    INT16 x;
    INT16 y;
    INT16 z;
  } VINT16;
//------------------------------- COMMON-CODE INT16   STOP.
//------------------------------- COMMON-CODE INT32  START.
  typedef struct
  {
    INT32 x;
    INT32 y;
    INT32 z;
  } VINT32;
//------------------------------- COMMON-CODE INT32   STOP.
//------------------------------- COMMON-CODE INT64  START.
  typedef struct
  {
    INT64 x;
    INT64 y;
    INT64 z;
  } VINT64;
//------------------------------- COMMON-CODE INT64   STOP.

//------------------------------- COMMON-CODE UNT08  START.
  typedef struct
  {
    UNT08 x;
    UNT08 y;
    UNT08 z;
  } VUNT08;
//------------------------------- COMMON-CODE UNT08   STOP.
//------------------------------- COMMON-CODE UNT16  START.
  typedef struct
  {
    UNT16 x;
    UNT16 y;
    UNT16 z;
  } VUNT16;
//------------------------------- COMMON-CODE UNT16   STOP.
//------------------------------- COMMON-CODE UNT32  START.
  typedef struct
  {
    UNT32 x;
    UNT32 y;
    UNT32 z;
  } VUNT32;
//------------------------------- COMMON-CODE UNT32   STOP.
//------------------------------- COMMON-CODE UNT64  START.
  typedef struct
  {
    UNT64 x;
    UNT64 y;
    UNT64 z;
  } VUNT64;
//------------------------------- COMMON-CODE UNT64   STOP.

//------------------------------- COMMON-CODE FLT32  START.
  typedef struct
  {
    FLT32 x;
    FLT32 y;
    FLT32 z;
  } VFLT32;
//------------------------------- COMMON-CODE FLT32   STOP.
//------------------------------- COMMON-CODE FLT64  START.
  typedef struct
  {
    FLT64 x;
    FLT64 y;
    FLT64 z;
  } VFLT64;
//------------------------------- COMMON-CODE FLT64   STOP.
//------------------------------- COMMON-CODE FLT96  START.
  typedef struct
  {
    FLT96 x;
    FLT96 y;
    FLT96 z;
  } VFLT96;
//------------------------------- COMMON-CODE FLT96   STOP.


#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  typedef struct
PERL_PREPROCESS  {
PERL_PREPROCESS    XXXXX lat;
PERL_PREPROCESS    XXXXX lon;
PERL_PREPROCESS    XXXXX alt;
PERL_PREPROCESS  } LLAXXXXX;
#endif

//------------------------------- COMMON-CODE INT08  START.
  typedef struct
  {
    INT08 lat;
    INT08 lon;
    INT08 alt;
  } LLAINT08;
//------------------------------- COMMON-CODE INT08   STOP.
//------------------------------- COMMON-CODE INT16  START.
  typedef struct
  {
    INT16 lat;
    INT16 lon;
    INT16 alt;
  } LLAINT16;
//------------------------------- COMMON-CODE INT16   STOP.
//------------------------------- COMMON-CODE INT32  START.
  typedef struct
  {
    INT32 lat;
    INT32 lon;
    INT32 alt;
  } LLAINT32;
//------------------------------- COMMON-CODE INT32   STOP.
//------------------------------- COMMON-CODE INT64  START.
  typedef struct
  {
    INT64 lat;
    INT64 lon;
    INT64 alt;
  } LLAINT64;
//------------------------------- COMMON-CODE INT64   STOP.

//------------------------------- COMMON-CODE UNT08  START.
  typedef struct
  {
    UNT08 lat;
    UNT08 lon;
    UNT08 alt;
  } LLAUNT08;
//------------------------------- COMMON-CODE UNT08   STOP.
//------------------------------- COMMON-CODE UNT16  START.
  typedef struct
  {
    UNT16 lat;
    UNT16 lon;
    UNT16 alt;
  } LLAUNT16;
//------------------------------- COMMON-CODE UNT16   STOP.
//------------------------------- COMMON-CODE UNT32  START.
  typedef struct
  {
    UNT32 lat;
    UNT32 lon;
    UNT32 alt;
  } LLAUNT32;
//------------------------------- COMMON-CODE UNT32   STOP.
//------------------------------- COMMON-CODE UNT64  START.
  typedef struct
  {
    UNT64 lat;
    UNT64 lon;
    UNT64 alt;
  } LLAUNT64;
//------------------------------- COMMON-CODE UNT64   STOP.

//------------------------------- COMMON-CODE FLT32  START.
  typedef struct
  {
    FLT32 lat;
    FLT32 lon;
    FLT32 alt;
  } LLAFLT32;
//------------------------------- COMMON-CODE FLT32   STOP.
//------------------------------- COMMON-CODE FLT64  START.
  typedef struct
  {
    FLT64 lat;
    FLT64 lon;
    FLT64 alt;
  } LLAFLT64;
//------------------------------- COMMON-CODE FLT64   STOP.
//------------------------------- COMMON-CODE FLT96  START.
  typedef struct
  {
    FLT96 lat;
    FLT96 lon;
    FLT96 alt;
  } LLAFLT96;
//------------------------------- COMMON-CODE FLT96   STOP.

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define SWAPVFLT32(a,b) {FLT32 temp = a; a = b; b = temp;} //===================
#define SWAPVFLT64(a,b) {FLT64 temp = a; a = b; b = temp;} //                  =
#define SWAPVFLT96(a,b) {FLT96 temp = a; a = b; b = temp;} //                  =
#define SWAPVINT08(a,b) {INT08 temp = a; a = b; b = temp;} //                  =
#define SWAPVINT16(a,b) {INT16 temp = a; a = b; b = temp;} //        XMC       =
#define SWAPVINT32(a,b) {INT32 temp = a; a = b; b = temp;} //      Swapping    =
#define SWAPVINT64(a,b) {INT64 temp = a; a = b; b = temp;} //       Macros     =
#define SWAPVUNT08(a,b) {UNT08 temp = a; a = b; b = temp;} //                  =
#define SWAPVUNT16(a,b) {UNT16 temp = a; a = b; b = temp;} //                  =
#define SWAPVUNT32(a,b) {UNT32 temp = a; a = b; b = temp;} //                  =
#define SWAPVUNT64(a,b) {UNT64 temp = a; a = b; b = temp;} //===================

#define SWAPLLAFLT32(a,b) {FLT32 temp = a; a = b; b = temp;} //=================
#define SWAPLLAFLT64(a,b) {FLT64 temp = a; a = b; b = temp;} //                =
#define SWAPLLAFLT96(a,b) {FLT96 temp = a; a = b; b = temp;} //                =
#define SWAPLLAINT08(a,b) {INT08 temp = a; a = b; b = temp;} //                =
#define SWAPLLAINT16(a,b) {INT16 temp = a; a = b; b = temp;} //      XMC       =
#define SWAPLLAINT32(a,b) {INT32 temp = a; a = b; b = temp;} //    Swapping    =
#define SWAPLLAINT64(a,b) {INT64 temp = a; a = b; b = temp;} //     Macros     =
#define SWAPLLAUNT08(a,b) {UNT08 temp = a; a = b; b = temp;} //                =
#define SWAPLLAUNT16(a,b) {UNT16 temp = a; a = b; b = temp;} //                =
#define SWAPLLAUNT32(a,b) {UNT32 temp = a; a = b; b = temp;} //                =
#define SWAPLLAUNT64(a,b) {UNT64 temp = a; a = b; b = temp;} //=================

/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
