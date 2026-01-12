/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xmcComplexTypes.h
// Desc: This file contains complex data type definitions.
// Hist: When       Who  What
//       10/15/2006 ptb  Initial Port.                                                          -
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#ifndef XMC_COMPLEX_TYPES_H
#define XMC_COMPLEX_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS  typedef struct
PERL_PREPROCESS  {
PERL_PREPROCESS    XXXXX r;
PERL_PREPROCESS    XXXXX i;
PERL_PREPROCESS  } CXXXXX;
#endif

//COMMON-CODE INT08 START.
  typedef struct
  {
    INT08 r;
    INT08 i;
  } CINT08;
//COMMON-CODE INT08  STOP.
//COMMON-CODE INT16 START.
  typedef struct
  {
    INT16 r;
    INT16 i;
  } CINT16;
//COMMON-CODE INT16  STOP.
//COMMON-CODE INT32 START.
  typedef struct
  {
    INT32 r;
    INT32 i;
  } CINT32;
//COMMON-CODE INT32  STOP.
//COMMON-CODE INT64 START.
  typedef struct
  {
    INT64 r;
    INT64 i;
  } CINT64;
//COMMON-CODE INT64  STOP.

//COMMON-CODE UNT08 START.
  typedef struct
  {
    UNT08 r;
    UNT08 i;
  } CUNT08;
//COMMON-CODE UNT08  STOP.
//COMMON-CODE UNT16 START.
  typedef struct
  {
    UNT16 r;
    UNT16 i;
  } CUNT16;
//COMMON-CODE UNT16  STOP.
//COMMON-CODE UNT32 START.
  typedef struct
  {
    UNT32 r;
    UNT32 i;
  } CUNT32;
//COMMON-CODE UNT32  STOP.
//COMMON-CODE UNT64 START.
  typedef struct
  {
    UNT64 r;
    UNT64 i;
  } CUNT64;
//COMMON-CODE UNT64  STOP.

//COMMON-CODE FLT32 START.
  typedef struct
  {
    FLT32 r;
    FLT32 i;
  } CFLT32;
//COMMON-CODE FLT32  STOP.
//COMMON-CODE FLT64 START.
  typedef struct
  {
    FLT64 r;
    FLT64 i;
  } CFLT64;
//COMMON-CODE FLT64  STOP.
//COMMON-CODE FLT96 START.
  typedef struct
  {
    FLT96 r;
    FLT96 i;
  } CFLT96;
//COMMON-CODE FLT96  STOP.

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define SWAPCFLT32(a,b) {FLT32 temp = a; a = b; b = temp;} //===================
#define SWAPCFLT64(a,b) {FLT64 temp = a; a = b; b = temp;} //                  =
#define SWAPCFLT96(a,b) {FLT96 temp = a; a = b; b = temp;} //                  =
#define SWAPCINT08(a,b) {INT08 temp = a; a = b; b = temp;} //                  =
#define SWAPCINT16(a,b) {INT16 temp = a; a = b; b = temp;} //        XMC       =
#define SWAPCINT32(a,b) {INT32 temp = a; a = b; b = temp;} //      Swapping    =
#define SWAPCINT64(a,b) {INT64 temp = a; a = b; b = temp;} //       macros.    =
#define SWAPCUNT08(a,b) {UNT08 temp = a; a = b; b = temp;} //                  =
#define SWAPCUNT16(a,b) {UNT16 temp = a; a = b; b = temp;} //                  =
#define SWAPCUNT32(a,b) {UNT32 temp = a; a = b; b = temp;} //                  =
#define SWAPCUNT64(a,b) {UNT64 temp = a; a = b; b = temp;} //===================

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/
