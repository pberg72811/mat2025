/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccUpSampleCircularBuffer.c
// Desc: This file contains the code for the iccUpSampleCircularBuffer.
// Hist: When       Who  What
//       10/09/2003 ptb  Initial Code.
//       10/10/2003 ptb  Exchanged "trunc" function for "floor".  Weird problem.
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
PERL_PREPROCESS    spec->totalSamples++;                  //
PERL_PREPROCESS    spec->indexF += spec->delta;           // Update the floating index.
PERL_PREPROCESS    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
PERL_PREPROCESS    if(spec->indexI >= spec->nb){          // If index beyond boundary.
PERL_PREPROCESS      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
PERL_PREPROCESS      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
PERL_PREPROCESS      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
PERL_PREPROCESS    }                                      //
PERL_PREPROCESS    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
PERL_PREPROCESS    pb+=j;                                 // Increment output pointer.
PERL_PREPROCESS  }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
// Rout: iccUpSampleInit
// Desc: This routine initializes the upsample spec.
//------------------------------------------------------------------------------
iccUpSampleSpecFLT64 *iccUpSampleInitFLT64(FLT64 fb, FLT64 fs, FLT64 phs, INT32 nb)
{
  iccUpSampleSpecFLT64 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (iccUpSampleSpecFLT64 *) iccMallocINT08_Align032(sizeof(iccUpSampleSpecFLT64));

  // Initialize the spec.
  //----------------------------------------------------------------------------
  spec->fb       = fb;
  spec->fs       = fs;
  spec->phs      = phs;
  spec->nb       = nb;
  spec->delta    = fb/fs;
  spec->indexF   = spec->phs-spec->delta;
  spec->indexI   = 0;
  spec->doneFlag = FALSE; //For none circular buffers.
  spec->totalSamples=0;   //For circular buffers.
  return( spec );
}

//------------------------------------------------------------------------------
// Rout: iccUpSampleTerm
// Desc: This routine terminates the iccSigGen spec.  Free allocated memory.
//------------------------------------------------------------------------------
VOID iccUpSampleTerm( iccUpSampleSpecFLT64 *spec )
{
  xmcFree( spec );
}

//------------------------------------------------------------------------------
// Rout: iccUpSampleCircularBufferXXXXX
// Desc: These routines do the up sampling.
//------------------------------------------------------------------------------
VOID iccUpSampleCircularBufferFLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT32    START.
  INT32 k;
  FLT32 *pa=(FLT32 *)a;
  FLT32 *pb=(FLT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE FLT32     STOP.
}

VOID iccUpSampleCircularBufferFLT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT64    START.
  INT32 k;
  FLT64 *pa=(FLT64 *)a;
  FLT64 *pb=(FLT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE FLT64     STOP.
}

VOID iccUpSampleCircularBufferFLT96(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT96    START.
  INT32 k;
  FLT96 *pa=(FLT96 *)a;
  FLT96 *pb=(FLT96 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE FLT96     STOP.
}

VOID iccUpSampleCircularBufferINT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
  //printf("k = %ld  ",k);
  //printf("spec->indexF = %lf  ",spec->indexF);
  //printf("spec->indexI = %ld\n",spec->indexI);
//------------------------------- COMMON-CODE INT08    START.
  INT32 k;
  INT08 *pa=(INT08 *)a;
  INT08 *pb=(INT08 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE INT08     STOP.
}

VOID iccUpSampleCircularBufferINT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT16    START.
  INT32 k;
  INT16 *pa=(INT16 *)a;
  INT16 *pb=(INT16 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE INT16     STOP.
}

VOID iccUpSampleCircularBufferINT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT32    START.
  INT32 k;
  INT32 *pa=(INT32 *)a;
  INT32 *pb=(INT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE INT32     STOP.
}

VOID iccUpSampleCircularBufferINT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT64    START.
  INT32 k;
  INT64 *pa=(INT64 *)a;
  INT64 *pb=(INT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE INT64     STOP.
}

VOID iccUpSampleCircularBufferUNT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT08    START.
  INT32 k;
  UNT08 *pa=(UNT08 *)a;
  UNT08 *pb=(UNT08 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE UNT08     STOP.
}

VOID iccUpSampleCircularBufferUNT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT16    START.
  INT32 k;
  UNT16 *pa=(UNT16 *)a;
  UNT16 *pb=(UNT16 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE UNT16     STOP.
}

VOID iccUpSampleCircularBufferUNT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT32    START.
  INT32 k;
  UNT32 *pa=(UNT32 *)a;
  UNT32 *pb=(UNT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE UNT32     STOP.
}

VOID iccUpSampleCircularBufferUNT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT64    START.
  INT32 k;
  UNT64 *pa=(UNT64 *)a;
  UNT64 *pb=(UNT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE UNT64     STOP.
}

VOID iccUpSampleCircularBufferCFLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CFLT32    START.
  INT32 k;
  CFLT32 *pa=(CFLT32 *)a;
  CFLT32 *pb=(CFLT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CFLT32     STOP.
}

VOID iccUpSampleCircularBufferCFLT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CFLT64    START.
  INT32 k;
  CFLT64 *pa=(CFLT64 *)a;
  CFLT64 *pb=(CFLT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CFLT64     STOP.
}

VOID iccUpSampleCircularBufferCFLT96(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CFLT96    START.
  INT32 k;
  CFLT96 *pa=(CFLT96 *)a;
  CFLT96 *pb=(CFLT96 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CFLT96     STOP.
}

VOID iccUpSampleCircularBufferCINT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT08    START.
  INT32 k;
  CINT08 *pa=(CINT08 *)a;
  CINT08 *pb=(CINT08 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CINT08     STOP.
}

VOID iccUpSampleCircularBufferCINT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT16    START.
  INT32 k;
  CINT16 *pa=(CINT16 *)a;
  CINT16 *pb=(CINT16 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CINT16     STOP.
}

VOID iccUpSampleCircularBufferCINT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT32    START.
  INT32 k;
  CINT32 *pa=(CINT32 *)a;
  CINT32 *pb=(CINT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CINT32     STOP.
}

VOID iccUpSampleCircularBufferCINT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT64    START.
  INT32 k;
  CINT64 *pa=(CINT64 *)a;
  CINT64 *pb=(CINT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CINT64     STOP.
}

VOID iccUpSampleCircularBufferCUNT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT08    START.
  INT32 k;
  CUNT08 *pa=(CUNT08 *)a;
  CUNT08 *pb=(CUNT08 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CUNT08     STOP.
}

VOID iccUpSampleCircularBufferCUNT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT16    START.
  INT32 k;
  CUNT16 *pa=(CUNT16 *)a;
  CUNT16 *pb=(CUNT16 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CUNT16     STOP.
}

VOID iccUpSampleCircularBufferCUNT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT32    START.
  INT32 k;
  CUNT32 *pa=(CUNT32 *)a;
  CUNT32 *pb=(CUNT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CUNT32     STOP.
}

VOID iccUpSampleCircularBufferCUNT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT64    START.
  INT32 k;
  CUNT64 *pa=(CUNT64 *)a;
  CUNT64 *pb=(CUNT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE CUNT64     STOP.
}

VOID iccUpSampleCircularBufferVFLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VFLT32    START.
  INT32 k;
  VFLT32 *pa=(VFLT32 *)a;
  VFLT32 *pb=(VFLT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VFLT32     STOP.
}

VOID iccUpSampleCircularBufferVFLT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VFLT64    START.
  INT32 k;
  VFLT64 *pa=(VFLT64 *)a;
  VFLT64 *pb=(VFLT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VFLT64     STOP.
}

VOID iccUpSampleCircularBufferVFLT96(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VFLT96    START.
  INT32 k;
  VFLT96 *pa=(VFLT96 *)a;
  VFLT96 *pb=(VFLT96 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VFLT96     STOP.
}

VOID iccUpSampleCircularBufferVINT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VINT08    START.
  INT32 k;
  VINT08 *pa=(VINT08 *)a;
  VINT08 *pb=(VINT08 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VINT08     STOP.
}

VOID iccUpSampleCircularBufferVINT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VINT16    START.
  INT32 k;
  VINT16 *pa=(VINT16 *)a;
  VINT16 *pb=(VINT16 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VINT16     STOP.
}

VOID iccUpSampleCircularBufferVINT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VINT32    START.
  INT32 k;
  VINT32 *pa=(VINT32 *)a;
  VINT32 *pb=(VINT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VINT32     STOP.
}

VOID iccUpSampleCircularBufferVINT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VINT64    START.
  INT32 k;
  VINT64 *pa=(VINT64 *)a;
  VINT64 *pb=(VINT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VINT64     STOP.
}

VOID iccUpSampleCircularBufferVUNT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VUNT08    START.
  INT32 k;
  VUNT08 *pa=(VUNT08 *)a;
  VUNT08 *pb=(VUNT08 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VUNT08     STOP.
}

VOID iccUpSampleCircularBufferVUNT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VUNT16    START.
  INT32 k;
  VUNT16 *pa=(VUNT16 *)a;
  VUNT16 *pb=(VUNT16 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VUNT16     STOP.
}

VOID iccUpSampleCircularBufferVUNT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VUNT32    START.
  INT32 k;
  VUNT32 *pa=(VUNT32 *)a;
  VUNT32 *pb=(VUNT32 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VUNT32     STOP.
}

VOID iccUpSampleCircularBufferVUNT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE VUNT64    START.
  INT32 k;
  VUNT64 *pa=(VUNT64 *)a;
  VUNT64 *pb=(VUNT64 *)b;
  for(k = 0; k < n; k++)                   // For each output sample.
  {                                        //
    spec->totalSamples++;                  //
    spec->indexF += spec->delta;           // Update the floating index.
    spec->indexI = (INT32) spec->indexF;   // Calculate the integer index.
    if(spec->indexI >= spec->nb){          // If index beyond boundary.
      spec->indexF =  ((FLT64)spec->totalSamples)*spec->delta;
      spec->indexF -= floor(spec->indexF); // Recalc the floating index.
      spec->indexI = (INT32) spec->indexF; // Recalc the integer index.
    }                                      //
    *pb = pa[spec->indexI*i];              // Set this sample accordingly.
    pb+=j;                                 // Increment output pointer.
  }
//------------------------------- COMMON-CODE VUNT64     STOP.
}


/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
