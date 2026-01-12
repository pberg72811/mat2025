/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccUpSampleBufferFlush.c
// Desc: This file contains the code for the iccUpSampleBufferFlush.
// Hist: When       Who  What
//       10/13/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "dsp_utils.h"
 
/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa=(XXXXX *)a;
PERL_PREPROCESS  XXXXX *pb=(XXXXX *)b;
PERL_PREPROCESS  INT32 indexES=0;
PERL_PREPROCESS  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
PERL_PREPROCESS  {
PERL_PREPROCESS    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
PERL_PREPROCESS    *pb = pa[spec->indexI*i];              // Set the output.
PERL_PREPROCESS    pb+=j;                                 // Increment the pointer.
PERL_PREPROCESS    indexES++;                             // Increment the counter.
PERL_PREPROCESS  }
PERL_PREPROCESS  return indexES;
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
// Rout: iccUpSampleBufferFlushXXXXX
// Desc: These routines flush out the final samples of the up sample process.
//------------------------------------------------------------------------------
INT32 iccUpSampleBufferFlushFLT32(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT32                 START.
  FLT32 *pa=(FLT32 *)a;
  FLT32 *pb=(FLT32 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE FLT32                  STOP.
}

INT32 iccUpSampleBufferFlushFLT64(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT64                 START.
  FLT64 *pa=(FLT64 *)a;
  FLT64 *pb=(FLT64 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE FLT64                  STOP.
}

INT32 iccUpSampleBufferFlushFLT96(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT96                 START.
  FLT96 *pa=(FLT96 *)a;
  FLT96 *pb=(FLT96 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE FLT96                  STOP.
}

INT32 iccUpSampleBufferFlushINT08(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT08                 START.
  INT08 *pa=(INT08 *)a;
  INT08 *pb=(INT08 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE INT08                  STOP.
}

INT32 iccUpSampleBufferFlushINT16(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT16                 START.
  INT16 *pa=(INT16 *)a;
  INT16 *pb=(INT16 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE INT16                  STOP.
}

INT32 iccUpSampleBufferFlushINT32(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT32                 START.
  INT32 *pa=(INT32 *)a;
  INT32 *pb=(INT32 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE INT32                  STOP.
}

INT32 iccUpSampleBufferFlushINT64(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT64                 START.
  INT64 *pa=(INT64 *)a;
  INT64 *pb=(INT64 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE INT64                  STOP.
}

INT32 iccUpSampleBufferFlushUNT08(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT08                 START.
  UNT08 *pa=(UNT08 *)a;
  UNT08 *pb=(UNT08 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE UNT08                  STOP.
}

INT32 iccUpSampleBufferFlushUNT16(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT16                 START.
  UNT16 *pa=(UNT16 *)a;
  UNT16 *pb=(UNT16 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE UNT16                  STOP.
}

INT32 iccUpSampleBufferFlushUNT32(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT32                 START.
  UNT32 *pa=(UNT32 *)a;
  UNT32 *pb=(UNT32 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE UNT32                  STOP.
}

INT32 iccUpSampleBufferFlushUNT64(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT64                 START.
  UNT64 *pa=(UNT64 *)a;
  UNT64 *pb=(UNT64 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE UNT64                  STOP.
}

//------------------------------------------------------------------------------
// Rout: iccUpSampleBufferFlushXXXXX
// Desc: These routines flush out the final samples of the up sample process
//       for complex types.
//------------------------------------------------------------------------------
INT32 iccUpSampleBufferFlushCFLT32(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CFLT32                 START.
  CFLT32 *pa=(CFLT32 *)a;
  CFLT32 *pb=(CFLT32 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE CFLT32                  STOP.
}

INT32 iccUpSampleBufferFlushCFLT64(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CFLT64                 START.
  CFLT64 *pa=(CFLT64 *)a;
  CFLT64 *pb=(CFLT64 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE CFLT64                  STOP.
}

INT32 iccUpSampleBufferFlushCFLT96(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CFLT96                 START.
  CFLT96 *pa=(CFLT96 *)a;
  CFLT96 *pb=(CFLT96 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE CFLT96                  STOP.
}

INT32 iccUpSampleBufferFlushCINT08(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT08                 START.
  CINT08 *pa=(CINT08 *)a;
  CINT08 *pb=(CINT08 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE CINT08                  STOP.
}

INT32 iccUpSampleBufferFlushCINT16(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT16                 START.
  CINT16 *pa=(CINT16 *)a;
  CINT16 *pb=(CINT16 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE CINT16                  STOP.
}

INT32 iccUpSampleBufferFlushCINT32(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT32                 START.
  CINT32 *pa=(CINT32 *)a;
  CINT32 *pb=(CINT32 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE CINT32                  STOP.
}

INT32 iccUpSampleBufferFlushCINT64(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT64                 START.
  CINT64 *pa=(CINT64 *)a;
  CINT64 *pb=(CINT64 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE CINT64                  STOP.
}

INT32 iccUpSampleBufferFlushCUNT08(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT08                 START.
  CUNT08 *pa=(CUNT08 *)a;
  CUNT08 *pb=(CUNT08 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE CUNT08                  STOP.
}

INT32 iccUpSampleBufferFlushCUNT16(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT16                 START.
  CUNT16 *pa=(CUNT16 *)a;
  CUNT16 *pb=(CUNT16 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE CUNT16                  STOP.
}

INT32 iccUpSampleBufferFlushCUNT32(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT32                 START.
  CUNT32 *pa=(CUNT32 *)a;
  CUNT32 *pb=(CUNT32 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE CUNT32                  STOP.
}

INT32 iccUpSampleBufferFlushCUNT64(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT64                 START.
  CUNT64 *pa=(CUNT64 *)a;
  CUNT64 *pb=(CUNT64 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE CUNT64                  STOP.
}

//------------------------------------------------------------------------------
// Rout: iccUpSampleBufferFlushXXXXX
// Desc: These routines flush out the final samples of the up sample process
//       for 3 element data types.
//------------------------------------------------------------------------------
INT32 iccUpSampleBufferFlushVFLT32(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VFLT32                 START.
  VFLT32 *pa=(VFLT32 *)a;
  VFLT32 *pb=(VFLT32 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE VFLT32                  STOP.
}

INT32 iccUpSampleBufferFlushVFLT64(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VFLT64                 START.
  VFLT64 *pa=(VFLT64 *)a;
  VFLT64 *pb=(VFLT64 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE VFLT64                  STOP.
}

INT32 iccUpSampleBufferFlushVFLT96(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VFLT96                 START.
  VFLT96 *pa=(VFLT96 *)a;
  VFLT96 *pb=(VFLT96 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE VFLT96                  STOP.
}

INT32 iccUpSampleBufferFlushVINT08(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VINT08                 START.
  VINT08 *pa=(VINT08 *)a;
  VINT08 *pb=(VINT08 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE VINT08                  STOP.
}

INT32 iccUpSampleBufferFlushVINT16(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VINT16                 START.
  VINT16 *pa=(VINT16 *)a;
  VINT16 *pb=(VINT16 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE VINT16                  STOP.
}

INT32 iccUpSampleBufferFlushVINT32(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VINT32                 START.
  VINT32 *pa=(VINT32 *)a;
  VINT32 *pb=(VINT32 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE VINT32                  STOP.
}

INT32 iccUpSampleBufferFlushVINT64(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VINT64                 START.
  VINT64 *pa=(VINT64 *)a;
  VINT64 *pb=(VINT64 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE VINT64                  STOP.
}

INT32 iccUpSampleBufferFlushVUNT08(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VUNT08                 START.
  VUNT08 *pa=(VUNT08 *)a;
  VUNT08 *pb=(VUNT08 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE VUNT08                  STOP.
}

INT32 iccUpSampleBufferFlushVUNT16(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VUNT16                 START.
  VUNT16 *pa=(VUNT16 *)a;
  VUNT16 *pb=(VUNT16 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE VUNT16                  STOP.
}

INT32 iccUpSampleBufferFlushVUNT32(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VUNT32                 START.
  VUNT32 *pa=(VUNT32 *)a;
  VUNT32 *pb=(VUNT32 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE VUNT32                  STOP.
}

INT32 iccUpSampleBufferFlushVUNT64(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VUNT64                 START.
  VUNT64 *pa=(VUNT64 *)a;
  VUNT64 *pb=(VUNT64 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE VUNT64                  STOP.
}

//------------------------------------------------------------------------------
// Rout: iccUpSampleBufferFlushXXXXX
// Desc: These routines flush out the final samples of the up sample process
//       for hybrid cases.
//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa=(XXXXX *)a;
PERL_PREPROCESS  YYYYY *pb=(YYYYY *)b;
PERL_PREPROCESS  INT32 indexES=0;
PERL_PREPROCESS  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
PERL_PREPROCESS  {
PERL_PREPROCESS    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
PERL_PREPROCESS    *pb = pa[spec->indexI*i];              // Set the output.
PERL_PREPROCESS    pb+=j;                                 // Increment the pointer.
PERL_PREPROCESS    indexES++;                             // Increment the counter.
PERL_PREPROCESS  }
PERL_PREPROCESS  return indexES;
#endif

INT32 iccUpSampleBufferFlushINT08FLT32(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT08 FLT32            START.
  INT08 *pa=(INT08 *)a;
  FLT32 *pb=(FLT32 *)b;
  INT32 indexES=0;
  while( ((INT32)(spec->indexF += spec->delta)) < spec->nb )
  {
    spec->indexI = (INT32) spec->indexF;   // Calculate the index.
    *pb = pa[spec->indexI*i];              // Set the output.
    pb+=j;                                 // Increment the pointer.
    indexES++;                             // Increment the counter.
  }
  return indexES;
//------------------------------- COMMON-CODE INT08 FLT32             STOP.
}



/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
