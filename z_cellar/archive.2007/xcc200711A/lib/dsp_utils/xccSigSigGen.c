/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccSigSigGen.c
// Desc: This file contains the code for the xccSigSigGen.
// Hist: When       Who  What
//       11/21/2002 ptb  Initial Code.
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
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS xccSigSigGenSpecXXXXX *spec;
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the spec.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec = (xccSigSigGenSpecXXXXX *) xccMallocINT08_Align032(sizeof(xccSigSigGenSpecXXXXX));
PERL_PREPROCESS
PERL_PREPROCESS  // Initialize the spec.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec->fa     = fa;
PERL_PREPROCESS  spec->fs     = fs;
PERL_PREPROCESS  spec->delta2 = 2*PI*fa/fs/fs;
PERL_PREPROCESS  spec->delta1 = 2*PI*fc/fs;
PERL_PREPROCESS  spec->delta1 = spec->delta1-spec->delta2;
PERL_PREPROCESS  spec->phi    = phs-spec->delta1;
PERL_PREPROCESS  spec->amp    = amp;
PERL_PREPROCESS  return( spec );
#endif

//------------------------------------------------------------------------------
// Rout: xccSigSigGenInit
// Desc: This routine initializes the signal generator spec.
//------------------------------------------------------------------------------
xccSigSigGenSpecFLT32 *xccSigSigGenInitFLT32(FLT32 fc, FLT32 fa, FLT32 fs, FLT32 amp, FLT32 phs)
{
//------------------------------- COMMON-CODE FLT32      START.
 xccSigSigGenSpecFLT32 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccSigSigGenSpecFLT32 *) xccMallocINT08_Align032(sizeof(xccSigSigGenSpecFLT32));

  // Initialize the spec.
  //----------------------------------------------------------------------------
  spec->fa     = fa;
  spec->fs     = fs;
  spec->delta2 = 2*PI*fa/fs/fs;
  spec->delta1 = 2*PI*fc/fs;
  spec->delta1 = spec->delta1-spec->delta2;
  spec->phi    = phs-spec->delta1;
  spec->amp    = amp;
  return( spec );
//------------------------------- COMMON-CODE FLT32       STOP.
}

xccSigSigGenSpecFLT64 *xccSigSigGenInitFLT64(FLT64 fc, FLT64 fa, FLT64 fs, FLT64 amp, FLT64 phs)
{
//------------------------------- COMMON-CODE FLT64      START.
 xccSigSigGenSpecFLT64 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccSigSigGenSpecFLT64 *) xccMallocINT08_Align032(sizeof(xccSigSigGenSpecFLT64));

  // Initialize the spec.
  //----------------------------------------------------------------------------
  spec->fa     = fa;
  spec->fs     = fs;
  spec->delta2 = 2*PI*fa/fs/fs;
  spec->delta1 = 2*PI*fc/fs;
  spec->delta1 = spec->delta1-spec->delta2;
  spec->phi    = phs-spec->delta1;
  spec->amp    = amp;
  return( spec );
//------------------------------- COMMON-CODE FLT64       STOP.
}

xccSigSigGenSpecFLT96 *xccSigSigGenInitFLT96(FLT96 fc, FLT96 fa, FLT96 fs, FLT96 amp, FLT96 phs)
{
//------------------------------- COMMON-CODE FLT96      START.
 xccSigSigGenSpecFLT96 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccSigSigGenSpecFLT96 *) xccMallocINT08_Align032(sizeof(xccSigSigGenSpecFLT96));

  // Initialize the spec.
  //----------------------------------------------------------------------------
  spec->fa     = fa;
  spec->fs     = fs;
  spec->delta2 = 2*PI*fa/fs/fs;
  spec->delta1 = 2*PI*fc/fs;
  spec->delta1 = spec->delta1-spec->delta2;
  spec->phi    = phs-spec->delta1;
  spec->amp    = amp;
  return( spec );
//------------------------------- COMMON-CODE FLT96       STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *py=y;
PERL_PREPROCESS  INT32 kk;
PERL_PREPROCESS
PERL_PREPROCESS  for(kk = 0; kk < n; kk++)
PERL_PREPROCESS  {
PERL_PREPROCESS    spec->phi    += spec->delta1;
PERL_PREPROCESS    spec->delta1 += spec->delta2;
PERL_PREPROCESS    *py = spec->amp*cos(spec->phi);
PERL_PREPROCESS    py=py+i;
PERL_PREPROCESS  }
PERL_PREPROCESS  spec->phi = fmod(spec->phi, TWOPI);
#endif

//------------------------------------------------------------------------------
// Rout: xccSigSigGenCos
// Desc: This routine does a cosine signal generator.
//------------------------------------------------------------------------------
VOID xccSigSigGenCosFLT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT32      START.
  FLT32 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE FLT32       STOP.
}

VOID xccSigSigGenCosFLT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT64      START.
  FLT64 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE FLT64       STOP.
}

VOID xccSigSigGenCosFLT96(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT96      START.
  FLT96 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE FLT96       STOP.
}

VOID xccSigSigGenCosINT08(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT08      START.
  INT08 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE INT08       STOP.
}

VOID xccSigSigGenCosINT16(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT16      START.
  INT16 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE INT16       STOP.
}

VOID xccSigSigGenCosINT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT32      START.
  INT32 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE INT32       STOP.
}

VOID xccSigSigGenCosINT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT64      START.
  INT64 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE INT64       STOP.
}

VOID xccSigSigGenCosUNT08(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT08      START.
  UNT08 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE UNT08       STOP.
}

VOID xccSigSigGenCosUNT16(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT16      START.
  UNT16 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE UNT16       STOP.
}

VOID xccSigSigGenCosUNT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT32      START.
  UNT32 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE UNT32       STOP.
}

VOID xccSigSigGenCosUNT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT64      START.
  UNT64 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE UNT64       STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *py=y;
PERL_PREPROCESS  INT32 kk;
PERL_PREPROCESS
PERL_PREPROCESS  for(kk = 0; kk < n; kk++)
PERL_PREPROCESS  {
PERL_PREPROCESS    spec->phi    += spec->delta1;
PERL_PREPROCESS    spec->delta1 += spec->delta2;
PERL_PREPROCESS    *py = spec->amp*sin(spec->phi);
PERL_PREPROCESS    py=py+i;
PERL_PREPROCESS  }
PERL_PREPROCESS  spec->phi = fmod(spec->phi, TWOPI);
#endif
//------------------------------------------------------------------------------
// Rout: xccSigSigGenSin
// Desc: This routine does a sine signal generator.
//------------------------------------------------------------------------------
VOID xccSigSigGenSinFLT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT32      START.
  FLT32 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE FLT32       STOP.
}

VOID xccSigSigGenSinFLT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT64      START.
  FLT64 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE FLT64       STOP.
}

VOID xccSigSigGenSinFLT96(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT96      START.
  FLT96 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE FLT96       STOP.
}

VOID xccSigSigGenSinINT08(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT08      START.
  INT08 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE INT08       STOP.
}

VOID xccSigSigGenSinINT16(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT16      START.
  INT16 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE INT16       STOP.
}

VOID xccSigSigGenSinINT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT32      START.
  INT32 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE INT32       STOP.
}

VOID xccSigSigGenSinINT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT64      START.
  INT64 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE INT64       STOP.
}

VOID xccSigSigGenSinUNT08(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT08      START.
  UNT08 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE UNT08       STOP.
}

VOID xccSigSigGenSinUNT16(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT16      START.
  UNT16 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE UNT16       STOP.
}

VOID xccSigSigGenSinUNT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT32      START.
  UNT32 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE UNT32       STOP.
}

VOID xccSigSigGenSinUNT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT64      START.
  UNT64 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE UNT64       STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *py=y;
PERL_PREPROCESS  INT32 kk;
PERL_PREPROCESS
PERL_PREPROCESS  for(kk = 0; kk < n; kk++)
PERL_PREPROCESS  {
PERL_PREPROCESS    spec->phi    += spec->delta1;
PERL_PREPROCESS    spec->delta1 += spec->delta2;
PERL_PREPROCESS    py->r = spec->amp*cos(spec->phi);
PERL_PREPROCESS    py->i = spec->amp*sin(spec->phi);
PERL_PREPROCESS    py=py+i;
PERL_PREPROCESS  }
PERL_PREPROCESS  spec->phi = fmod(spec->phi, TWOPI);
#endif

//------------------------------------------------------------------------------
// Rout: xccSigSigGenCosSin
// Desc: This routine does a complex cosine-sine signal generator.
//------------------------------------------------------------------------------
VOID xccSigSigGenCosSinCFLT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CFLT32      START.
  CFLT32 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CFLT32       STOP.
}

VOID xccSigSigGenCosSinCFLT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CFLT64      START.
  CFLT64 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CFLT64       STOP.
}

VOID xccSigSigGenCosSinCFLT96(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CFLT96      START.
  CFLT96 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CFLT96       STOP.
}

VOID xccSigSigGenCosSinCINT08(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT08      START.
  CINT08 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CINT08       STOP.
}

VOID xccSigSigGenCosSinCINT16(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT16      START.
  CINT16 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CINT16       STOP.
}

VOID xccSigSigGenCosSinCINT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT32      START.
  CINT32 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CINT32       STOP.
}

VOID xccSigSigGenCosSinCINT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT64      START.
  CINT64 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CINT64       STOP.
}

VOID xccSigSigGenCosSinCUNT08(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT08      START.
  CUNT08 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CUNT08       STOP.
}

VOID xccSigSigGenCosSinCUNT16(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT16      START.
  CUNT16 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CUNT16       STOP.
}

VOID xccSigSigGenCosSinCUNT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT32      START.
  CUNT32 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CUNT32       STOP.
}

VOID xccSigSigGenCosSinCUNT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT64      START.
  CUNT64 *py=y;
  INT32 kk;

  for(kk = 0; kk < n; kk++)
  {
    spec->phi    += spec->delta1;
    spec->delta1 += spec->delta2;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CUNT64       STOP.
}

//------------------------------------------------------------------------------
// Rout: xccSigSigGenTermFLT32
// Desc: This routine terminates the xccSigSigGen spec.  Free allocated memory.
//------------------------------------------------------------------------------
VOID xccSigSigGenTermFLT32( xccSigSigGenSpecFLT32 *spec )
{
  xmcFree( spec );
}

VOID xccSigSigGenTermFLT64( xccSigSigGenSpecFLT64 *spec )
{
  xmcFree( spec );
}

VOID xccSigSigGenTermFLT96( xccSigSigGenSpecFLT96 *spec )
{
  xmcFree( spec );
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
