/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccSigGen.c
// Desc: This file contains the code for the iccSigGen.
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
PERL_PREPROCESS iccSigGenSpecXXXXX *spec;
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the spec.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec = (iccSigGenSpecXXXXX *) iccMallocINT08_Align032(sizeof(iccSigGenSpecXXXXX));
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
// Rout: iccSigGenInit
// Desc: This routine initializes the signal generator spec.
//------------------------------------------------------------------------------
iccSigGenSpecFLT32 *iccSigGenInitFLT32(FLT32 fc, FLT32 fs, FLT32 amp, FLT32 phs)
{
//------------------------------- COMMON-CODE FLT32             START.
 iccSigGenSpecFLT32 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (iccSigGenSpecFLT32 *) iccMallocINT08_Align032(sizeof(iccSigGenSpecFLT32));

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

iccSigGenSpecFLT64 *iccSigGenInitFLT64(FLT64 fc, FLT64 fs, FLT64 amp, FLT64 phs)
{
//------------------------------- COMMON-CODE FLT64             START.
 iccSigGenSpecFLT64 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (iccSigGenSpecFLT64 *) iccMallocINT08_Align032(sizeof(iccSigGenSpecFLT64));

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

iccSigGenSpecFLT96 *iccSigGenInitFLT96(FLT96 fc, FLT96 fs, FLT96 amp, FLT96 phs)
{
//------------------------------- COMMON-CODE FLT96             START.
 iccSigGenSpecFLT96 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (iccSigGenSpecFLT96 *) iccMallocINT08_Align032(sizeof(iccSigGenSpecFLT96));

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
// Rout: iccSigGenMod
// Desc: This routine modifies the signal generator spec.
//------------------------------------------------------------------------------
VOID iccSigGenModFLT32(FLT32 fc, FLT32 fs, FLT32 amp, FLT32 phs, iccSigGenSpecFLT32 *spec)
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

VOID iccSigGenModFLT64(FLT64 fc, FLT64 fs, FLT64 amp, FLT64 phs, iccSigGenSpecFLT64 *spec)
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

VOID iccSigGenModFLT96(FLT96 fc, FLT96 fs, FLT96 amp, FLT96 phs, iccSigGenSpecFLT96 *spec)
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
// Rout: iccSigGenCos
// Desc: This routine does a cosine signal generator.
//------------------------------------------------------------------------------
VOID iccSigGenCosFLT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosFLT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosFLT96(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosINT08(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosINT16(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosINT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosINT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosUNT08(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosUNT16(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosUNT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosUNT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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
// Rout: iccSigGenSin
// Desc: This routine does a sine signal generator.
//------------------------------------------------------------------------------
VOID iccSigGenSinFLT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenSinFLT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenSinFLT96(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenSinINT08(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenSinINT16(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenSinINT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenSinINT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenSinUNT08(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenSinUNT16(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenSinUNT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenSinUNT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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
// Rout: iccSigGenCosSin
// Desc: This routine does a complex cosine-sine signal generator.
//------------------------------------------------------------------------------
VOID iccSigGenCosSinCFLT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosSinCFLT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosSinCFLT96(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosSinCINT08(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosSinCINT16(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosSinCINT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosSinCINT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosSinCUNT08(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosSinCUNT16(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosSinCUNT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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

VOID iccSigGenCosSinCUNT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec )
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
// Rout: iccSigGenTermFLT32
// Desc: This routine terminates the iccSigGen spec.  Free allocated memory.
//------------------------------------------------------------------------------
VOID iccSigGenTermFLT32( iccSigGenSpecFLT32 *spec )
{
  xmcFree( spec );
}

VOID iccSigGenTermFLT64( iccSigGenSpecFLT64 *spec )
{
  xmcFree( spec );
}

VOID iccSigGenTermFLT96( iccSigGenSpecFLT96 *spec )
{
  xmcFree( spec );
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
