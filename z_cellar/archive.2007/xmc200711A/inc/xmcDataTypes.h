/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xmcDataTypes.h
// Desc: This file contains data type definitions.
// Hist: When       Who  What
//       10/15/2006 ptb  Initial Port.                                                          -
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#ifndef XMC_DATA_TYPES_H
#define XMC_DATA_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define FLT32 float                                                        //====================
#define FLT64 double                                                       //                   =
#define FLT96 long double                                                  //                   =
#define INT08 signed char                                                  //                   =
#define INT16 short int                                                    //                   =
#define INT32 long int                                                     //       XMC         =
#define INT64 long long                                                    //       Data        =
#define UNT08 unsigned char                                                //       Types       =
#define UNT16 unsigned short int                                           //                   =
#define UNT32 unsigned long int                                            //                   =
#define UNT64 unsigned long long int                                       //                   =
#define CHR08 char                                                         //                   =
#define CCHAR const char                                                   //                   =
#define VOID  void                                                         //                   =
#define BOOLN unsigned char                                                //====================

#define TRUE  1                                                            //====================
#define FALSE 0                                                            //        XMC        =
#define REAL  1                                                            //      Boolean      =
#define CPLX  0                                                            //====================

/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define SWAPFLT32(a,b) {FLT32 temp = a; a = b; b = temp;}                  //====================
#define SWAPFLT64(a,b) {FLT64 temp = a; a = b; b = temp;}                  //                   =
#define SWAPFLT96(a,b) {FLT96 temp = a; a = b; b = temp;}                  //                   =
#define SWAPINT08(a,b) {INT08 temp = a; a = b; b = temp;}                  //                   =
#define SWAPINT16(a,b) {INT16 temp = a; a = b; b = temp;}                  //        XMC        =
#define SWAPINT32(a,b) {INT32 temp = a; a = b; b = temp;}                  //      Swapping     =
#define SWAPINT64(a,b) {INT64 temp = a; a = b; b = temp;}                  //       Macros      =
#define SWAPUNT08(a,b) {UNT08 temp = a; a = b; b = temp;}                  //                   =
#define SWAPUNT16(a,b) {UNT16 temp = a; a = b; b = temp;}                  //                   =
#define SWAPUNT32(a,b) {UNT32 temp = a; a = b; b = temp;}                  //                   =
#define SWAPUNT64(a,b) {UNT64 temp = a; a = b; b = temp;}                  //====================

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
