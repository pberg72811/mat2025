/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccUpSampleBuffer.c
// Desc: This file contains the code for the xccUpSampleBuffer.
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
PERL_PREPROCESS  INT32 k;
PERL_PREPROCESS  XXXXX *pa=(XXXXX *)a;
PERL_PREPROCESS  XXXXX *pb=(XXXXX *)b;
PERL_PREPROCESS  for(k = 0; k < n; k++)                   // For each output sample.
PERL_PREPROCESS  {                                        //
PERL_PREPROCESS    spec->indexF += spec->delta;           // Update the floating index.
PERL_PREPROCESS    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
PERL_PREPROCESS    if(spec->indexI >= spec->nb){          // If index beyond boundary.
PERL_PREPROCESS      *pb=0;                               // Set it to zero.
PERL_PREPROCESS    }                                      //
PERL_PREPROCESS    else{                                  // Else.
PERL_PREPROCESS      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
PERL_PREPROCESS    }                                      //
PERL_PREPROCESS    pb+=j;                                 // Increment output pointer.
PERL_PREPROCESS  }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
// Rout: xccUpSampleBufferXXXXX
// Desc: These routines do the up sampling.
//------------------------------------------------------------------------------
VOID xccUpSampleBufferFLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT32      START.
  INT32 k;
  FLT32 *pa=(FLT32 *)a;
  FLT32 *pb=(FLT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      *pb=0;                               // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE FLT32       STOP.
}

VOID xccUpSampleBufferFLT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT64      START.
  INT32 k;
  FLT64 *pa=(FLT64 *)a;
  FLT64 *pb=(FLT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      *pb=0;                               // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE FLT64       STOP.
}

VOID xccUpSampleBufferFLT96(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT96      START.
  INT32 k;
  FLT96 *pa=(FLT96 *)a;
  FLT96 *pb=(FLT96 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      *pb=0;                               // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE FLT96       STOP.
}

VOID xccUpSampleBufferINT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT08      START.
  INT32 k;
  INT08 *pa=(INT08 *)a;
  INT08 *pb=(INT08 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      *pb=0;                               // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE INT08       STOP.
}

VOID xccUpSampleBufferINT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT16      START.
  INT32 k;
  INT16 *pa=(INT16 *)a;
  INT16 *pb=(INT16 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      *pb=0;                               // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE INT16       STOP.
}

VOID xccUpSampleBufferINT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT32      START.
  INT32 k;
  INT32 *pa=(INT32 *)a;
  INT32 *pb=(INT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      *pb=0;                               // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE INT32       STOP.
}

VOID xccUpSampleBufferINT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT64      START.
  INT32 k;
  INT64 *pa=(INT64 *)a;
  INT64 *pb=(INT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      *pb=0;                               // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE INT64       STOP.
}

VOID xccUpSampleBufferUNT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT08      START.
  INT32 k;
  UNT08 *pa=(UNT08 *)a;
  UNT08 *pb=(UNT08 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      *pb=0;                               // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE UNT08       STOP.
}

VOID xccUpSampleBufferUNT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT16      START.
  INT32 k;
  UNT16 *pa=(UNT16 *)a;
  UNT16 *pb=(UNT16 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      *pb=0;                               // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE UNT16       STOP.
}

VOID xccUpSampleBufferUNT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT32      START.
  INT32 k;
  UNT32 *pa=(UNT32 *)a;
  UNT32 *pb=(UNT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      *pb=0;                               // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE UNT32       STOP.
}

VOID xccUpSampleBufferUNT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT64      START.
  INT32 k;
  UNT64 *pa=(UNT64 *)a;
  UNT64 *pb=(UNT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      *pb=0;                               // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE UNT64       STOP.
}

//------------------------------------------------------------------------------
// Rout: xccUpSampleBufferXXXXX
// Desc: These routines do the up sampling for complex types.
//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  INT32 k;
PERL_PREPROCESS  XXXXX *pa=(XXXXX *)a;
PERL_PREPROCESS  XXXXX *pb=(XXXXX *)b;
PERL_PREPROCESS  for(k = 0; k < n; k++)                   // For each output sample.
PERL_PREPROCESS  {                                        //
PERL_PREPROCESS    spec->indexF += spec->delta;           // Update the floating index.
PERL_PREPROCESS    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
PERL_PREPROCESS    if(spec->indexI >= spec->nb){          // If index beyond boundary.
PERL_PREPROCESS      pb->r=0; pb->i=0;                    // Set it to zero.
PERL_PREPROCESS    }                                      //
PERL_PREPROCESS    else{                                  // Else.
PERL_PREPROCESS      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
PERL_PREPROCESS    }                                      //
PERL_PREPROCESS    pb+=j;                                 // Increment output pointer.
PERL_PREPROCESS  }
#endif

VOID xccUpSampleBufferCFLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CFLT32      START.
  INT32 k;
  CFLT32 *pa=(CFLT32 *)a;
  CFLT32 *pb=(CFLT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->r=0; pb->i=0;                    // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CFLT32       STOP.
}

VOID xccUpSampleBufferCFLT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CFLT64      START.
  INT32 k;
  CFLT64 *pa=(CFLT64 *)a;
  CFLT64 *pb=(CFLT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->r=0; pb->i=0;                    // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CFLT64       STOP.
}

VOID xccUpSampleBufferCFLT96(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CFLT96      START.
  INT32 k;
  CFLT96 *pa=(CFLT96 *)a;
  CFLT96 *pb=(CFLT96 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->r=0; pb->i=0;                    // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CFLT96       STOP.
}

VOID xccUpSampleBufferCINT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT08      START.
  INT32 k;
  CINT08 *pa=(CINT08 *)a;
  CINT08 *pb=(CINT08 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->r=0; pb->i=0;                    // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CINT08       STOP.
}

VOID xccUpSampleBufferCINT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT16      START.
  INT32 k;
  CINT16 *pa=(CINT16 *)a;
  CINT16 *pb=(CINT16 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->r=0; pb->i=0;                    // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CINT16       STOP.
}

VOID xccUpSampleBufferCINT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT32      START.
  INT32 k;
  CINT32 *pa=(CINT32 *)a;
  CINT32 *pb=(CINT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->r=0; pb->i=0;                    // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CINT32       STOP.
}

VOID xccUpSampleBufferCINT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT64      START.
  INT32 k;
  CINT64 *pa=(CINT64 *)a;
  CINT64 *pb=(CINT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->r=0; pb->i=0;                    // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CINT64       STOP.
}

VOID xccUpSampleBufferCUNT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT08      START.
  INT32 k;
  CUNT08 *pa=(CUNT08 *)a;
  CUNT08 *pb=(CUNT08 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->r=0; pb->i=0;                    // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CUNT08       STOP.
}

VOID xccUpSampleBufferCUNT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT16      START.
  INT32 k;
  CUNT16 *pa=(CUNT16 *)a;
  CUNT16 *pb=(CUNT16 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->r=0; pb->i=0;                    // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CUNT16       STOP.
}

VOID xccUpSampleBufferCUNT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT32      START.
  INT32 k;
  CUNT32 *pa=(CUNT32 *)a;
  CUNT32 *pb=(CUNT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->r=0; pb->i=0;                    // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CUNT32       STOP.
}

VOID xccUpSampleBufferCUNT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT64      START.
  INT32 k;
  CUNT64 *pa=(CUNT64 *)a;
  CUNT64 *pb=(CUNT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->r=0; pb->i=0;                    // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CUNT64       STOP.
}

//------------------------------------------------------------------------------
// Rout: xccUpSampleBufferXXXXX
// Desc: These routines do the up sampling for 3 element data types.
//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  INT32 k;
PERL_PREPROCESS  XXXXX *pa=(XXXXX *)a;
PERL_PREPROCESS  XXXXX *pb=(XXXXX *)b;
PERL_PREPROCESS  for(k = 0; k < n; k++)                   // For each output sample.
PERL_PREPROCESS  {                                        //
PERL_PREPROCESS    spec->indexF += spec->delta;           // Update the floating index.
PERL_PREPROCESS    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
PERL_PREPROCESS    if(spec->indexI >= spec->nb){          // If index beyond boundary.
PERL_PREPROCESS      pb->x=0; pb->y=0; pb->z=0;           // Set it to zero.
PERL_PREPROCESS    }                                      //
PERL_PREPROCESS    else{                                  // Else.
PERL_PREPROCESS      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
PERL_PREPROCESS    }                                      //
PERL_PREPROCESS    pb+=j;                                 // Increment output pointer.
PERL_PREPROCESS  }
#endif

VOID xccUpSampleBufferVFLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VFLT32      START.
  INT32 k;
  VFLT32 *pa=(VFLT32 *)a;
  VFLT32 *pb=(VFLT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->x=0; pb->y=0; pb->z=0;           // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VFLT32       STOP.
}

VOID xccUpSampleBufferVFLT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VFLT64      START.
  INT32 k;
  VFLT64 *pa=(VFLT64 *)a;
  VFLT64 *pb=(VFLT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->x=0; pb->y=0; pb->z=0;           // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VFLT64       STOP.
}

VOID xccUpSampleBufferVFLT96(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VFLT96      START.
  INT32 k;
  VFLT96 *pa=(VFLT96 *)a;
  VFLT96 *pb=(VFLT96 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->x=0; pb->y=0; pb->z=0;           // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VFLT96       STOP.
}

VOID xccUpSampleBufferVINT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VINT08      START.
  INT32 k;
  VINT08 *pa=(VINT08 *)a;
  VINT08 *pb=(VINT08 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->x=0; pb->y=0; pb->z=0;           // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VINT08       STOP.
}

VOID xccUpSampleBufferVINT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VINT16      START.
  INT32 k;
  VINT16 *pa=(VINT16 *)a;
  VINT16 *pb=(VINT16 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->x=0; pb->y=0; pb->z=0;           // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VINT16       STOP.
}

VOID xccUpSampleBufferVINT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VINT32      START.
  INT32 k;
  VINT32 *pa=(VINT32 *)a;
  VINT32 *pb=(VINT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->x=0; pb->y=0; pb->z=0;           // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VINT32       STOP.
}

VOID xccUpSampleBufferVINT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VINT64      START.
  INT32 k;
  VINT64 *pa=(VINT64 *)a;
  VINT64 *pb=(VINT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->x=0; pb->y=0; pb->z=0;           // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VINT64       STOP.
}

VOID xccUpSampleBufferVUNT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VUNT08      START.
  INT32 k;
  VUNT08 *pa=(VUNT08 *)a;
  VUNT08 *pb=(VUNT08 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->x=0; pb->y=0; pb->z=0;           // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VUNT08       STOP.
}

VOID xccUpSampleBufferVUNT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VUNT16      START.
  INT32 k;
  VUNT16 *pa=(VUNT16 *)a;
  VUNT16 *pb=(VUNT16 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->x=0; pb->y=0; pb->z=0;           // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VUNT16       STOP.
}

VOID xccUpSampleBufferVUNT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VUNT32      START.
  INT32 k;
  VUNT32 *pa=(VUNT32 *)a;
  VUNT32 *pb=(VUNT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->x=0; pb->y=0; pb->z=0;           // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VUNT32       STOP.
}

VOID xccUpSampleBufferVUNT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VUNT64      START.
  INT32 k;
  VUNT64 *pa=(VUNT64 *)a;
  VUNT64 *pb=(VUNT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      pb->x=0; pb->y=0; pb->z=0;           // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VUNT64       STOP.
}

//------------------------------------------------------------------------------
// Rout: xccUpSampleBufferXXXXX
// Desc: These routines do the up sampling for hybrid cases.
//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  INT32 k;
PERL_PREPROCESS  XXXXX *pa=(XXXXX *)a;
PERL_PREPROCESS  YYYYY *pb=(YYYYY *)b;
PERL_PREPROCESS  for(k = 0; k < n; k++)                   // For each output sample.
PERL_PREPROCESS  {                                        //
PERL_PREPROCESS    spec->indexF += spec->delta;           // Update the floating index.
PERL_PREPROCESS    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
PERL_PREPROCESS    if(spec->indexI >= spec->nb){          // If index beyond boundary.
PERL_PREPROCESS      *pb=0;                               // Set it to zero.
PERL_PREPROCESS    }                                      //
PERL_PREPROCESS    else{                                  // Else.
PERL_PREPROCESS      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
PERL_PREPROCESS    }                                      //
PERL_PREPROCESS    pb+=j;                                 // Increment output pointer.
PERL_PREPROCESS  }
#endif

VOID xccUpSampleBufferINT08FLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT08 FLT32 START.
  INT32 k;
  INT08 *pa=(INT08 *)a;
  FLT32 *pb=(FLT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      *pb=0;                               // Set it to zero.
    }                                      //
    else{                                  // Else.
      *pb = pa[spec->indexI*i];            // Set this sample accordingly.
    }                                      //
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE INT08 FLT32  STOP.
}



/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
