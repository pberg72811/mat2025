/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccSigSigGen.c
// Desc: This file contains the code for the iccSigSigGen.
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
PERL_PREPROCESS iccSigSigGenSpecXXXXX *spec;
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the spec.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec = (iccSigSigGenSpecXXXXX *) iccMallocINT08_Align032(sizeof(iccSigSigGenSpecXXXXX));
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
// Rout: iccSigSigGenInit
// Desc: This routine initializes the signal generator spec.
//------------------------------------------------------------------------------
iccSigSigGenSpecFLT32 *iccSigSigGenInitFLT32(FLT32 fc, FLT32 fa, FLT32 fs, FLT32 amp, FLT32 phs)
{
//------------------------------- COMMON-CODE FLT32      START.
 iccSigSigGenSpecFLT32 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (iccSigSigGenSpecFLT32 *) iccMallocINT08_Align032(sizeof(iccSigSigGenSpecFLT32));

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

iccSigSigGenSpecFLT64 *iccSigSigGenInitFLT64(FLT64 fc, FLT64 fa, FLT64 fs, FLT64 amp, FLT64 phs)
{
//------------------------------- COMMON-CODE FLT64      START.
 iccSigSigGenSpecFLT64 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (iccSigSigGenSpecFLT64 *) iccMallocINT08_Align032(sizeof(iccSigSigGenSpecFLT64));

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

iccSigSigGenSpecFLT96 *iccSigSigGenInitFLT96(FLT96 fc, FLT96 fa, FLT96 fs, FLT96 amp, FLT96 phs)
{
//------------------------------- COMMON-CODE FLT96      START.
 iccSigSigGenSpecFLT96 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (iccSigSigGenSpecFLT96 *) iccMallocINT08_Align032(sizeof(iccSigSigGenSpecFLT96));

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
// Rout: iccSigSigGenCos
// Desc: This routine does a cosine signal generator.
//------------------------------------------------------------------------------
VOID iccSigSigGenCosFLT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosFLT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosFLT96(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosINT08(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosINT16(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosINT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosINT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosUNT08(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosUNT16(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosUNT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosUNT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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
// Rout: iccSigSigGenSin
// Desc: This routine does a sine signal generator.
//------------------------------------------------------------------------------
VOID iccSigSigGenSinFLT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenSinFLT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenSinFLT96(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenSinINT08(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenSinINT16(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenSinINT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenSinINT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenSinUNT08(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenSinUNT16(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenSinUNT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenSinUNT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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
// Rout: iccSigSigGenCosSin
// Desc: This routine does a complex cosine-sine signal generator.
//------------------------------------------------------------------------------
VOID iccSigSigGenCosSinCFLT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosSinCFLT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosSinCFLT96(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosSinCINT08(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosSinCINT16(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosSinCINT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosSinCINT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosSinCUNT08(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosSinCUNT16(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosSinCUNT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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

VOID iccSigSigGenCosSinCUNT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec )
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
// Rout: iccSigSigGenTermFLT32
// Desc: This routine terminates the iccSigSigGen spec.  Free allocated memory.
//------------------------------------------------------------------------------
VOID iccSigSigGenTermFLT32( iccSigSigGenSpecFLT32 *spec )
{
  xmcFree( spec );
}

VOID iccSigSigGenTermFLT64( iccSigSigGenSpecFLT64 *spec )
{
  xmcFree( spec );
}

VOID iccSigSigGenTermFLT96( iccSigSigGenSpecFLT96 *spec )
{
  xmcFree( spec );
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
