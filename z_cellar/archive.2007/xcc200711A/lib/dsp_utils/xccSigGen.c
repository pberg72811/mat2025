/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccSigGen.c
// Desc: This file contains the code for the xccSigGen.
// Hist: When       Who  What
//       11/21/2002 ptb  Initial Code.
//       09/24/2004 ptb  Added 0.0 delta provision.
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
PERL_PREPROCESS xccSigGenSpecXXXXX *spec;
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the spec.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec = (xccSigGenSpecXXXXX *) xccMallocINT08_Align032(sizeof(xccSigGenSpecXXXXX));
PERL_PREPROCESS
PERL_PREPROCESS  // Initialize the spec.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec->fc    = fc;
PERL_PREPROCESS  spec->fs    = fs;
PERL_PREPROCESS  spec->delta = 2*PI*fc/fs;
PERL_PREPROCESS  spec->phi   = phs-spec->delta;
PERL_PREPROCESS  spec->amp   = amp;
PERL_PREPROCESS  return( spec );
#endif

//------------------------------------------------------------------------------
// Rout: xccSigGenInit
// Desc: This routine initializes the signal generator spec.
//------------------------------------------------------------------------------
xccSigGenSpecFLT32 *xccSigGenInitFLT32(FLT32 fc, FLT32 fs, FLT32 amp, FLT32 phs)
{
//------------------------------- COMMON-CODE FLT32             START.
 xccSigGenSpecFLT32 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccSigGenSpecFLT32 *) xccMallocINT08_Align032(sizeof(xccSigGenSpecFLT32));

  // Initialize the spec.
  //----------------------------------------------------------------------------
  spec->fc    = fc;
  spec->fs    = fs;
  spec->delta = 2*PI*fc/fs;
  spec->phi   = phs-spec->delta;
  spec->amp   = amp;
  return( spec );
//------------------------------- COMMON-CODE FLT32              STOP.
}

xccSigGenSpecFLT64 *xccSigGenInitFLT64(FLT64 fc, FLT64 fs, FLT64 amp, FLT64 phs)
{
//------------------------------- COMMON-CODE FLT64             START.
 xccSigGenSpecFLT64 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccSigGenSpecFLT64 *) xccMallocINT08_Align032(sizeof(xccSigGenSpecFLT64));

  // Initialize the spec.
  //----------------------------------------------------------------------------
  spec->fc    = fc;
  spec->fs    = fs;
  spec->delta = 2*PI*fc/fs;
  spec->phi   = phs-spec->delta;
  spec->amp   = amp;
  return( spec );
//------------------------------- COMMON-CODE FLT64              STOP.
}

xccSigGenSpecFLT96 *xccSigGenInitFLT96(FLT96 fc, FLT96 fs, FLT96 amp, FLT96 phs)
{
//------------------------------- COMMON-CODE FLT96             START.
 xccSigGenSpecFLT96 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccSigGenSpecFLT96 *) xccMallocINT08_Align032(sizeof(xccSigGenSpecFLT96));

  // Initialize the spec.
  //----------------------------------------------------------------------------
  spec->fc    = fc;
  spec->fs    = fs;
  spec->delta = 2*PI*fc/fs;
  spec->phi   = phs-spec->delta;
  spec->amp   = amp;
  return( spec );
//------------------------------- COMMON-CODE FLT96              STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS
PERL_PREPROCESS  // Modify the spec.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec->fc    = fc;
PERL_PREPROCESS  spec->fs    = fs;
PERL_PREPROCESS  spec->delta = 2*PI*fc/fs;
PERL_PREPROCESS  spec->phi   = phs-spec->delta;
PERL_PREPROCESS  spec->amp   = amp;
#endif

//------------------------------------------------------------------------------
// Rout: xccSigGenMod
// Desc: This routine modifies the signal generator spec.
//------------------------------------------------------------------------------
VOID xccSigGenModFLT32(FLT32 fc, FLT32 fs, FLT32 amp, FLT32 phs, xccSigGenSpecFLT32 *spec)
{
//------------------------------- COMMON-CODE FLT32             START.

  // Modify the spec.
  //----------------------------------------------------------------------------
  spec->fc    = fc;
  spec->fs    = fs;
  spec->delta = 2*PI*fc/fs;
  spec->phi   = phs-spec->delta;
  spec->amp   = amp;
//------------------------------- COMMON-CODE FLT32              STOP.
}

VOID xccSigGenModFLT64(FLT64 fc, FLT64 fs, FLT64 amp, FLT64 phs, xccSigGenSpecFLT64 *spec)
{
//------------------------------- COMMON-CODE FLT64             START.

  // Modify the spec.
  //----------------------------------------------------------------------------
  spec->fc    = fc;
  spec->fs    = fs;
  spec->delta = 2*PI*fc/fs;
  spec->phi   = phs-spec->delta;
  spec->amp   = amp;
//------------------------------- COMMON-CODE FLT64              STOP.
}

VOID xccSigGenModFLT96(FLT96 fc, FLT96 fs, FLT96 amp, FLT96 phs, xccSigGenSpecFLT96 *spec)
{
//------------------------------- COMMON-CODE FLT96             START.

  // Modify the spec.
  //----------------------------------------------------------------------------
  spec->fc    = fc;
  spec->fs    = fs;
  spec->delta = 2*PI*fc/fs;
  spec->phi   = phs-spec->delta;
  spec->amp   = amp;
//------------------------------- COMMON-CODE FLT96              STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *py=y;
PERL_PREPROCESS  INT32 kk;
PERL_PREPROCESS  XXXXX constCos;
PERL_PREPROCESS
PERL_PREPROCESS  if( (spec->delta <= +EPSILON_YYYYY) && (spec->delta >= -EPSILON_YYYYY) ) 
PERL_PREPROCESS  {
PERL_PREPROCESS    constCos = spec->amp*cos(spec->phi);
PERL_PREPROCESS    for(kk = 0; kk < n; kk++)
PERL_PREPROCESS    {
PERL_PREPROCESS      *py = constCos;
PERL_PREPROCESS      py=py+i;
PERL_PREPROCESS    }
PERL_PREPROCESS  }
PERL_PREPROCESS  else 
PERL_PREPROCESS  for(kk = 0; kk < n; kk++)
PERL_PREPROCESS  {
PERL_PREPROCESS    spec->phi += spec->delta;
PERL_PREPROCESS    *py = spec->amp*cos(spec->phi);
PERL_PREPROCESS    py=py+i;
PERL_PREPROCESS  }
PERL_PREPROCESS  spec->phi = fmod(spec->phi, TWOPI);
#endif

//------------------------------------------------------------------------------
// Rout: xccSigGenCos
// Desc: This routine does a cosine signal generator.
//------------------------------------------------------------------------------
VOID xccSigGenCosFLT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT32 FLT64           START.
  FLT32 *py=y;
  INT32 kk;
  FLT32 constCos;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constCos;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE FLT32 FLT64            STOP.
}

VOID xccSigGenCosFLT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT64 FLT64           START.
  FLT64 *py=y;
  INT32 kk;
  FLT64 constCos;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constCos;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE FLT64 FLT64            STOP.
}

VOID xccSigGenCosFLT96(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT96 FLT64           START.
  FLT96 *py=y;
  INT32 kk;
  FLT96 constCos;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constCos;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE FLT96 FLT64            STOP.
}

VOID xccSigGenCosINT08(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT08 FLT64           START.
  INT08 *py=y;
  INT32 kk;
  INT08 constCos;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constCos;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE INT08 FLT64            STOP.
}

VOID xccSigGenCosINT16(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT16 FLT64           START.
  INT16 *py=y;
  INT32 kk;
  INT16 constCos;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constCos;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE INT16 FLT64            STOP.
}

VOID xccSigGenCosINT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT32 FLT64           START.
  INT32 *py=y;
  INT32 kk;
  INT32 constCos;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constCos;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE INT32 FLT64            STOP.
}

VOID xccSigGenCosINT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT64 FLT64           START.
  INT64 *py=y;
  INT32 kk;
  INT64 constCos;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constCos;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE INT64 FLT64            STOP.
}

VOID xccSigGenCosUNT08(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT08 FLT64           START.
  UNT08 *py=y;
  INT32 kk;
  UNT08 constCos;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constCos;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE UNT08 FLT64            STOP.
}

VOID xccSigGenCosUNT16(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT16 FLT64           START.
  UNT16 *py=y;
  INT32 kk;
  UNT16 constCos;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constCos;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE UNT16 FLT64            STOP.
}

VOID xccSigGenCosUNT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT32 FLT64           START.
  UNT32 *py=y;
  INT32 kk;
  UNT32 constCos;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constCos;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE UNT32 FLT64            STOP.
}

VOID xccSigGenCosUNT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT64 FLT64           START.
  UNT64 *py=y;
  INT32 kk;
  UNT64 constCos;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constCos;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*cos(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE UNT64 FLT64            STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *py=y;
PERL_PREPROCESS  INT32 kk;
PERL_PREPROCESS  XXXXX constSin;
PERL_PREPROCESS
PERL_PREPROCESS  if( (spec->delta <= +EPSILON_YYYYY) && (spec->delta >= -EPSILON_YYYYY) ) 
PERL_PREPROCESS  {
PERL_PREPROCESS    constSin = spec->amp*sin(spec->phi);
PERL_PREPROCESS    for(kk = 0; kk < n; kk++)
PERL_PREPROCESS    {
PERL_PREPROCESS      *py = constSin;
PERL_PREPROCESS      py=py+i;
PERL_PREPROCESS    }
PERL_PREPROCESS  }
PERL_PREPROCESS  else 
PERL_PREPROCESS  for(kk = 0; kk < n; kk++)
PERL_PREPROCESS  {
PERL_PREPROCESS    spec->phi += spec->delta;
PERL_PREPROCESS    *py = spec->amp*sin(spec->phi);
PERL_PREPROCESS    py=py+i;
PERL_PREPROCESS  }
PERL_PREPROCESS  spec->phi = fmod(spec->phi, TWOPI);
#endif
//------------------------------------------------------------------------------
// Rout: xccSigGenSin
// Desc: This routine does a sine signal generator.
//------------------------------------------------------------------------------
VOID xccSigGenSinFLT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT32 FLT64           START.
  FLT32 *py=y;
  INT32 kk;
  FLT32 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constSin = spec->amp*sin(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE FLT32 FLT64            STOP.
}

VOID xccSigGenSinFLT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT64 FLT64           START.
  FLT64 *py=y;
  INT32 kk;
  FLT64 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constSin = spec->amp*sin(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE FLT64 FLT64            STOP.
}

VOID xccSigGenSinFLT96(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE FLT96 FLT64           START.
  FLT96 *py=y;
  INT32 kk;
  FLT96 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constSin = spec->amp*sin(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE FLT96 FLT64            STOP.
}

VOID xccSigGenSinINT08(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT08 FLT64           START.
  INT08 *py=y;
  INT32 kk;
  INT08 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constSin = spec->amp*sin(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE INT08 FLT64            STOP.
}

VOID xccSigGenSinINT16(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT16 FLT64           START.
  INT16 *py=y;
  INT32 kk;
  INT16 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constSin = spec->amp*sin(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE INT16 FLT64            STOP.
}

VOID xccSigGenSinINT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT32 FLT64           START.
  INT32 *py=y;
  INT32 kk;
  INT32 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constSin = spec->amp*sin(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE INT32 FLT64            STOP.
}

VOID xccSigGenSinINT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE INT64 FLT64           START.
  INT64 *py=y;
  INT32 kk;
  INT64 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constSin = spec->amp*sin(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE INT64 FLT64            STOP.
}

VOID xccSigGenSinUNT08(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT08 FLT64           START.
  UNT08 *py=y;
  INT32 kk;
  UNT08 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constSin = spec->amp*sin(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE UNT08 FLT64            STOP.
}

VOID xccSigGenSinUNT16(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT16 FLT64           START.
  UNT16 *py=y;
  INT32 kk;
  UNT16 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constSin = spec->amp*sin(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE UNT16 FLT64            STOP.
}

VOID xccSigGenSinUNT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT32 FLT64           START.
  UNT32 *py=y;
  INT32 kk;
  UNT32 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constSin = spec->amp*sin(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE UNT32 FLT64            STOP.
}

VOID xccSigGenSinUNT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE UNT64 FLT64           START.
  UNT64 *py=y;
  INT32 kk;
  UNT64 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constSin = spec->amp*sin(spec->phi);
    for(kk = 0; kk < n; kk++)
    {
      *py = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    *py = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE UNT64 FLT64            STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  INT32 kk;
PERL_PREPROCESS  XXXXX *py=y;
PERL_PREPROCESS  ZZZZZ constCos;
PERL_PREPROCESS  ZZZZZ constSin;
PERL_PREPROCESS
PERL_PREPROCESS  if( (spec->delta <= +EPSILON_YYYYY) && (spec->delta >= -EPSILON_YYYYY) ) 
PERL_PREPROCESS  {
PERL_PREPROCESS    constCos = spec->amp*cos(spec->phi); 
PERL_PREPROCESS    constSin = spec->amp*sin(spec->phi); 
PERL_PREPROCESS    for(kk = 0; kk < n; kk++)
PERL_PREPROCESS    {
PERL_PREPROCESS      py->r = constCos;
PERL_PREPROCESS      py->i = constSin;
PERL_PREPROCESS      py=py+i;
PERL_PREPROCESS    }
PERL_PREPROCESS  }
PERL_PREPROCESS  else 
PERL_PREPROCESS  for(kk = 0; kk < n; kk++)
PERL_PREPROCESS  {
PERL_PREPROCESS    spec->phi += spec->delta;
PERL_PREPROCESS    py->r = spec->amp*cos(spec->phi);
PERL_PREPROCESS    py->i = spec->amp*sin(spec->phi);
PERL_PREPROCESS    py=py+i;
PERL_PREPROCESS  }
PERL_PREPROCESS  spec->phi = fmod(spec->phi, TWOPI);
#endif

//------------------------------------------------------------------------------
// Rout: xccSigGenCosSin
// Desc: This routine does a complex cosine-sine signal generator.
//------------------------------------------------------------------------------
VOID xccSigGenCosSinCFLT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CFLT32 FLT64 FLT32      START.
  INT32 kk;
  CFLT32 *py=y;
  FLT32 constCos;
  FLT32 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi); 
    constSin = spec->amp*sin(spec->phi); 
    for(kk = 0; kk < n; kk++)
    {
      py->r = constCos;
      py->i = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CFLT32 FLT64 FLT32       STOP.
}

VOID xccSigGenCosSinCFLT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CFLT64 FLT64 FLT64      START.
  INT32 kk;
  CFLT64 *py=y;
  FLT64 constCos;
  FLT64 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi); 
    constSin = spec->amp*sin(spec->phi); 
    for(kk = 0; kk < n; kk++)
    {
      py->r = constCos;
      py->i = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CFLT64 FLT64 FLT64       STOP.
}

VOID xccSigGenCosSinCFLT96(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CFLT96 FLT64 FLT96      START.
  INT32 kk;
  CFLT96 *py=y;
  FLT96 constCos;
  FLT96 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi); 
    constSin = spec->amp*sin(spec->phi); 
    for(kk = 0; kk < n; kk++)
    {
      py->r = constCos;
      py->i = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CFLT96 FLT64 FLT96       STOP.
}

VOID xccSigGenCosSinCINT08(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT08 FLT64 INT08      START.
  INT32 kk;
  CINT08 *py=y;
  INT08 constCos;
  INT08 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi); 
    constSin = spec->amp*sin(spec->phi); 
    for(kk = 0; kk < n; kk++)
    {
      py->r = constCos;
      py->i = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CINT08 FLT64 INT08       STOP.
}

VOID xccSigGenCosSinCINT16(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT16 FLT64 INT16      START.
  INT32 kk;
  CINT16 *py=y;
  INT16 constCos;
  INT16 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi); 
    constSin = spec->amp*sin(spec->phi); 
    for(kk = 0; kk < n; kk++)
    {
      py->r = constCos;
      py->i = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CINT16 FLT64 INT16       STOP.
}

VOID xccSigGenCosSinCINT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT32 FLT64 INT32      START.
  INT32 kk;
  CINT32 *py=y;
  INT32 constCos;
  INT32 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi); 
    constSin = spec->amp*sin(spec->phi); 
    for(kk = 0; kk < n; kk++)
    {
      py->r = constCos;
      py->i = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CINT32 FLT64 INT32       STOP.
}

VOID xccSigGenCosSinCINT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CINT64 FLT64 INT64      START.
  INT32 kk;
  CINT64 *py=y;
  INT64 constCos;
  INT64 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi); 
    constSin = spec->amp*sin(spec->phi); 
    for(kk = 0; kk < n; kk++)
    {
      py->r = constCos;
      py->i = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CINT64 FLT64 INT64       STOP.
}

VOID xccSigGenCosSinCUNT08(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT08 FLT64 UNT08      START.
  INT32 kk;
  CUNT08 *py=y;
  UNT08 constCos;
  UNT08 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi); 
    constSin = spec->amp*sin(spec->phi); 
    for(kk = 0; kk < n; kk++)
    {
      py->r = constCos;
      py->i = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CUNT08 FLT64 UNT08       STOP.
}

VOID xccSigGenCosSinCUNT16(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT16 FLT64 UNT16      START.
  INT32 kk;
  CUNT16 *py=y;
  UNT16 constCos;
  UNT16 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi); 
    constSin = spec->amp*sin(spec->phi); 
    for(kk = 0; kk < n; kk++)
    {
      py->r = constCos;
      py->i = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CUNT16 FLT64 UNT16       STOP.
}

VOID xccSigGenCosSinCUNT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT32 FLT64 UNT32      START.
  INT32 kk;
  CUNT32 *py=y;
  UNT32 constCos;
  UNT32 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi); 
    constSin = spec->amp*sin(spec->phi); 
    for(kk = 0; kk < n; kk++)
    {
      py->r = constCos;
      py->i = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CUNT32 FLT64 UNT32       STOP.
}

VOID xccSigGenCosSinCUNT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec )
{
//------------------------------- COMMON-CODE CUNT64 FLT64 UNT64      START.
  INT32 kk;
  CUNT64 *py=y;
  UNT64 constCos;
  UNT64 constSin;

  if( (spec->delta <= +EPSILON_FLT64) && (spec->delta >= -EPSILON_FLT64) ) 
  {
    constCos = spec->amp*cos(spec->phi); 
    constSin = spec->amp*sin(spec->phi); 
    for(kk = 0; kk < n; kk++)
    {
      py->r = constCos;
      py->i = constSin;
      py=py+i;
    }
  }
  else 
  for(kk = 0; kk < n; kk++)
  {
    spec->phi += spec->delta;
    py->r = spec->amp*cos(spec->phi);
    py->i = spec->amp*sin(spec->phi);
    py=py+i;
  }
  spec->phi = fmod(spec->phi, TWOPI);
//------------------------------- COMMON-CODE CUNT64 FLT64 UNT64       STOP.
}

//------------------------------------------------------------------------------
// Rout: xccSigGenTermFLT32
// Desc: This routine terminates the xccSigGen spec.  Free allocated memory.
//------------------------------------------------------------------------------
VOID xccSigGenTermFLT32( xccSigGenSpecFLT32 *spec )
{
  xmcFree( spec );
}

VOID xccSigGenTermFLT64( xccSigGenSpecFLT64 *spec )
{
  xmcFree( spec );
}

VOID xccSigGenTermFLT96( xccSigGenSpecFLT96 *spec )
{
  xmcFree( spec );
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
