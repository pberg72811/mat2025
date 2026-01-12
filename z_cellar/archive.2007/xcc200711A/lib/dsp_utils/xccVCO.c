/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccVCO.c
// Desc: This file contains the code for the voltage controlled oscillator (VCO).
// Hist: When       Who  What
//       02/28/2005 ptb  Initial Code.
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
// Gain of the VCO in radians/second/volt (2PI).
#define KO (6.28318530717959)

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

//------------------------------------------------------------------------------
// Rout: xccVCOInit
// Desc: This routine initializes the voltage controlled oscillator (VCO).
//------------------------------------------------------------------------------
xccVCOSpec *xccVCOInit(FLT64 centerFrequency, FLT64 fs, FLT64 phase)
{
  xccVCOSpec *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccVCOSpec *) xccMallocVOID_Align032(sizeof(xccVCOSpec));

  // Initialize the spec.
  //----------------------------------------------------------------------------
  spec->centerFrequency = centerFrequency;
  spec->fs              = fs;
  spec->fc              = centerFrequency;
  spec->delta           = 1.0/fs;
  spec->phase           = phase;

  // return
  //----------------------------------------------------------------------------
  return spec;
}


//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX output;
PERL_PREPROCESS  spec->fc    = spec->centerFrequency + input;
PERL_PREPROCESS  spec->phase = spec->phase + (spec->fc * spec->delta);
PERL_PREPROCESS  spec->phase = fmod(spec->phase, 1.0);
PERL_PREPROCESS  output.r    = cos(spec->phase*KO);
PERL_PREPROCESS  output.i    = sin(spec->phase*KO);
PERL_PREPROCESS  return output;
 #endif


//------------------------------------------------------------------------------
// Rout: xccVCOCXXXXX
// Desc: These routine produces a complex output from a VCO.
//------------------------------------------------------------------------------
CFLT32 xccVCOCFLT32( FLT32 input, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE CFLT32          START.
  CFLT32 output;
  spec->fc    = spec->centerFrequency + input;
  spec->phase = spec->phase + (spec->fc * spec->delta);
  spec->phase = fmod(spec->phase, 1.0);
  output.r    = cos(spec->phase*KO);
  output.i    = sin(spec->phase*KO);
  return output;
//------------------------------- COMMON-CODE CFLT32           STOP.
}

CFLT64 xccVCOCFLT64( FLT64 input, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE CFLT64          START.
  CFLT64 output;
  spec->fc    = spec->centerFrequency + input;
  spec->phase = spec->phase + (spec->fc * spec->delta);
  spec->phase = fmod(spec->phase, 1.0);
  output.r    = cos(spec->phase*KO);
  output.i    = sin(spec->phase*KO);
  return output;
//------------------------------- COMMON-CODE CFLT64           STOP.
}

CFLT96 xccVCOCFLT96( FLT96 input, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE CFLT96          START.
  CFLT96 output;
  spec->fc    = spec->centerFrequency + input;
  spec->phase = spec->phase + (spec->fc * spec->delta);
  spec->phase = fmod(spec->phase, 1.0);
  output.r    = cos(spec->phase*KO);
  output.i    = sin(spec->phase*KO);
  return output;
//------------------------------- COMMON-CODE CFLT96           STOP.
}


//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX output;
PERL_PREPROCESS  spec->fc    = spec->centerFrequency + input;
PERL_PREPROCESS  spec->phase = spec->phase + (spec->fc * spec->delta);
PERL_PREPROCESS  spec->phase = fmod(spec->phase, 1.0);
PERL_PREPROCESS  output      = YYYYY(spec->phase*KO);
PERL_PREPROCESS  return output;
#endif

//------------------------------------------------------------------------------
// Rout: xccVCOXXXXX
// Desc: These routine produces an output from a VCO.
//------------------------------------------------------------------------------
FLT32 xccVCOFLT32( FLT32 input, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT32 cos          START.
  FLT32 output;
  spec->fc    = spec->centerFrequency + input;
  spec->phase = spec->phase + (spec->fc * spec->delta);
  spec->phase = fmod(spec->phase, 1.0);
  output      = cos(spec->phase*KO);
  return output;
//------------------------------- COMMON-CODE FLT32 cos           STOP.
}

FLT64 xccVCOFLT64( FLT64 input, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT64 cos          START.
  FLT64 output;
  spec->fc    = spec->centerFrequency + input;
  spec->phase = spec->phase + (spec->fc * spec->delta);
  spec->phase = fmod(spec->phase, 1.0);
  output      = cos(spec->phase*KO);
  return output;
//------------------------------- COMMON-CODE FLT64 cos           STOP.
}

FLT96 xccVCOFLT96( FLT96 input, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT96 cos          START.
  FLT96 output;
  spec->fc    = spec->centerFrequency + input;
  spec->phase = spec->phase + (spec->fc * spec->delta);
  spec->phase = fmod(spec->phase, 1.0);
  output      = cos(spec->phase*KO);
  return output;
//------------------------------- COMMON-CODE FLT96 cos           STOP.
}

FLT32 xccVCOFLT32Cos( FLT32 input, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT32 cos          START.
  FLT32 output;
  spec->fc    = spec->centerFrequency + input;
  spec->phase = spec->phase + (spec->fc * spec->delta);
  spec->phase = fmod(spec->phase, 1.0);
  output      = cos(spec->phase*KO);
  return output;
//------------------------------- COMMON-CODE FLT32 cos           STOP.
}

FLT64 xccVCOFLT64Cos( FLT64 input, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT64 cos          START.
  FLT64 output;
  spec->fc    = spec->centerFrequency + input;
  spec->phase = spec->phase + (spec->fc * spec->delta);
  spec->phase = fmod(spec->phase, 1.0);
  output      = cos(spec->phase*KO);
  return output;
//------------------------------- COMMON-CODE FLT64 cos           STOP.
}

FLT96 xccVCOFLT96Cos( FLT96 input, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT96 cos          START.
  FLT96 output;
  spec->fc    = spec->centerFrequency + input;
  spec->phase = spec->phase + (spec->fc * spec->delta);
  spec->phase = fmod(spec->phase, 1.0);
  output      = cos(spec->phase*KO);
  return output;
//------------------------------- COMMON-CODE FLT96 cos           STOP.
}

FLT32 xccVCOFLT32Sin( FLT32 input, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT32 sin          START.
  FLT32 output;
  spec->fc    = spec->centerFrequency + input;
  spec->phase = spec->phase + (spec->fc * spec->delta);
  spec->phase = fmod(spec->phase, 1.0);
  output      = sin(spec->phase*KO);
  return output;
//------------------------------- COMMON-CODE FLT32 sin           STOP.
}

FLT64 xccVCOFLT64Sin( FLT64 input, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT64 sin          START.
  FLT64 output;
  spec->fc    = spec->centerFrequency + input;
  spec->phase = spec->phase + (spec->fc * spec->delta);
  spec->phase = fmod(spec->phase, 1.0);
  output      = sin(spec->phase*KO);
  return output;
//------------------------------- COMMON-CODE FLT64 sin           STOP.
}

FLT96 xccVCOFLT96Sin( FLT96 input, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT96 sin          START.
  FLT96 output;
  spec->fc    = spec->centerFrequency + input;
  spec->phase = spec->phase + (spec->fc * spec->delta);
  spec->phase = fmod(spec->phase, 1.0);
  output      = sin(spec->phase*KO);
  return output;
//------------------------------- COMMON-CODE FLT96 sin           STOP.
}

//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS XXXXX *pb=b;
PERL_PREPROCESS UNT32 ii;
PERL_PREPROCESS for(ii=0;ii<n;ii++)
PERL_PREPROCESS {
PERL_PREPROCESS   spec->fc     = spec->centerFrequency + a;
PERL_PREPROCESS   spec->phase  = spec->phase + (spec->fc * spec->delta);
PERL_PREPROCESS   spec->phase  = fmod(spec->phase, 1.0);
PERL_PREPROCESS   pb->r = cos(spec->phase*KO);
PERL_PREPROCESS   pb->i = sin(spec->phase*KO);
PERL_PREPROCESS   pb = pb + i;
PERL_PREPROCESS }
#endif

//------------------------------------------------------------------------------
// Rout: xccvVCOCXXXXX
// Desc: These routine produces a complex vector output from a VCO.
//------------------------------------------------------------------------------
VOID xccvVCOCFLT32( FLT32 a, CFLT32 *b, INT32 i, UNT32 n, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE CFLT32        START.
 CFLT32 *pb=b;
 UNT32 ii;
 for(ii=0;ii<n;ii++)
 {
   spec->fc     = spec->centerFrequency + a;
   spec->phase  = spec->phase + (spec->fc * spec->delta);
   spec->phase  = fmod(spec->phase, 1.0);
   pb->r = cos(spec->phase*KO);
   pb->i = sin(spec->phase*KO);
   pb = pb + i;
 }
//------------------------------- COMMON-CODE CFLT32         STOP.
}

VOID xccvVCOCFLT64( FLT64 a, CFLT64 *b, INT32 i, UNT32 n, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE CFLT64        START.
 CFLT64 *pb=b;
 UNT32 ii;
 for(ii=0;ii<n;ii++)
 {
   spec->fc     = spec->centerFrequency + a;
   spec->phase  = spec->phase + (spec->fc * spec->delta);
   spec->phase  = fmod(spec->phase, 1.0);
   pb->r = cos(spec->phase*KO);
   pb->i = sin(spec->phase*KO);
   pb = pb + i;
 }
//------------------------------- COMMON-CODE CFLT64         STOP.
}

VOID xccvVCOCFLT96( FLT96 a, CFLT96 *b, INT32 i, UNT32 n, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE CFLT96        START.
 CFLT96 *pb=b;
 UNT32 ii;
 for(ii=0;ii<n;ii++)
 {
   spec->fc     = spec->centerFrequency + a;
   spec->phase  = spec->phase + (spec->fc * spec->delta);
   spec->phase  = fmod(spec->phase, 1.0);
   pb->r = cos(spec->phase*KO);
   pb->i = sin(spec->phase*KO);
   pb = pb + i;
 }
//------------------------------- COMMON-CODE CFLT96         STOP.
}

//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS XXXXX *pb=b;
PERL_PREPROCESS UNT32 ii;
PERL_PREPROCESS for(ii=0;ii<n;ii++)
PERL_PREPROCESS {
PERL_PREPROCESS   spec->fc     = spec->centerFrequency + a;
PERL_PREPROCESS   spec->phase  = spec->phase + (spec->fc * spec->delta);
PERL_PREPROCESS   spec->phase  = fmod(spec->phase, 1.0);
PERL_PREPROCESS   *pb = YYYYY(spec->phase*KO);
PERL_PREPROCESS   pb = pb + i;
PERL_PREPROCESS }
#endif

//------------------------------------------------------------------------------
// Rout: xccvVCOXXXXX
// Desc: These routine produces a complex vector output from a VCO.
//------------------------------------------------------------------------------
VOID xccvVCOFLT32( FLT32 a, FLT32 *b, INT32 i, UNT32 n, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT32 cos        START.
 FLT32 *pb=b;
 UNT32 ii;
 for(ii=0;ii<n;ii++)
 {
   spec->fc     = spec->centerFrequency + a;
   spec->phase  = spec->phase + (spec->fc * spec->delta);
   spec->phase  = fmod(spec->phase, 1.0);
   *pb = cos(spec->phase*KO);
   pb = pb + i;
 }
//------------------------------- COMMON-CODE FLT32 cos         STOP.
}

VOID xccvVCOFLT64( FLT64 a, FLT64 *b, INT32 i, UNT32 n, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT64 cos        START.
 FLT64 *pb=b;
 UNT32 ii;
 for(ii=0;ii<n;ii++)
 {
   spec->fc     = spec->centerFrequency + a;
   spec->phase  = spec->phase + (spec->fc * spec->delta);
   spec->phase  = fmod(spec->phase, 1.0);
   *pb = cos(spec->phase*KO);
   pb = pb + i;
 }
//------------------------------- COMMON-CODE FLT64 cos         STOP.
}

VOID xccvVCOFLT96( FLT96 a, FLT96 *b, INT32 i, UNT32 n, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT96 cos        START.
 FLT96 *pb=b;
 UNT32 ii;
 for(ii=0;ii<n;ii++)
 {
   spec->fc     = spec->centerFrequency + a;
   spec->phase  = spec->phase + (spec->fc * spec->delta);
   spec->phase  = fmod(spec->phase, 1.0);
   *pb = cos(spec->phase*KO);
   pb = pb + i;
 }
//------------------------------- COMMON-CODE FLT96 cos         STOP.
}

VOID xccvVCOFLT32Cos( FLT32 a, FLT32 *b, INT32 i, UNT32 n, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT32 cos        START.
 FLT32 *pb=b;
 UNT32 ii;
 for(ii=0;ii<n;ii++)
 {
   spec->fc     = spec->centerFrequency + a;
   spec->phase  = spec->phase + (spec->fc * spec->delta);
   spec->phase  = fmod(spec->phase, 1.0);
   *pb = cos(spec->phase*KO);
   pb = pb + i;
 }
//------------------------------- COMMON-CODE FLT32 cos         STOP.
}

VOID xccvVCOFLT64Cos( FLT64 a, FLT64 *b, INT32 i, UNT32 n, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT64 cos        START.
 FLT64 *pb=b;
 UNT32 ii;
 for(ii=0;ii<n;ii++)
 {
   spec->fc     = spec->centerFrequency + a;
   spec->phase  = spec->phase + (spec->fc * spec->delta);
   spec->phase  = fmod(spec->phase, 1.0);
   *pb = cos(spec->phase*KO);
   pb = pb + i;
 }
//------------------------------- COMMON-CODE FLT64 cos         STOP.
}

VOID xccvVCOFLT96Cos( FLT96 a, FLT96 *b, INT32 i, UNT32 n, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT96 cos        START.
 FLT96 *pb=b;
 UNT32 ii;
 for(ii=0;ii<n;ii++)
 {
   spec->fc     = spec->centerFrequency + a;
   spec->phase  = spec->phase + (spec->fc * spec->delta);
   spec->phase  = fmod(spec->phase, 1.0);
   *pb = cos(spec->phase*KO);
   pb = pb + i;
 }
//------------------------------- COMMON-CODE FLT96 cos         STOP.
}

VOID xccvVCOFLT32Sin( FLT32 a, FLT32 *b, INT32 i, UNT32 n, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT32 sin        START.
 FLT32 *pb=b;
 UNT32 ii;
 for(ii=0;ii<n;ii++)
 {
   spec->fc     = spec->centerFrequency + a;
   spec->phase  = spec->phase + (spec->fc * spec->delta);
   spec->phase  = fmod(spec->phase, 1.0);
   *pb = sin(spec->phase*KO);
   pb = pb + i;
 }
//------------------------------- COMMON-CODE FLT32 sin         STOP.
}

VOID xccvVCOFLT64Sin( FLT64 a, FLT64 *b, INT32 i, UNT32 n, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT64 sin        START.
 FLT64 *pb=b;
 UNT32 ii;
 for(ii=0;ii<n;ii++)
 {
   spec->fc     = spec->centerFrequency + a;
   spec->phase  = spec->phase + (spec->fc * spec->delta);
   spec->phase  = fmod(spec->phase, 1.0);
   *pb = sin(spec->phase*KO);
   pb = pb + i;
 }
//------------------------------- COMMON-CODE FLT64 sin         STOP.
}

VOID xccvVCOFLT96Sin( FLT96 a, FLT96 *b, INT32 i, UNT32 n, xccVCOSpec *spec )
{
//------------------------------- COMMON-CODE FLT96 sin        START.
 FLT96 *pb=b;
 UNT32 ii;
 for(ii=0;ii<n;ii++)
 {
   spec->fc     = spec->centerFrequency + a;
   spec->phase  = spec->phase + (spec->fc * spec->delta);
   spec->phase  = fmod(spec->phase, 1.0);
   *pb = sin(spec->phase*KO);
   pb = pb + i;
 }
//------------------------------- COMMON-CODE FLT96 sin         STOP.
}


//------------------------------------------------------------------------------
// Rout: xccVCOUpdate
// Desc: This routine updates the VCO without output.
//------------------------------------------------------------------------------
VOID xccVCOUpdate( FLT64 input, xccVCOSpec *spec )
{
  spec->fc    = spec->centerFrequency + input;
  spec->phase = spec->phase + (spec->fc * spec->delta);
  spec->phase = fmod(spec->phase, 1.0);
}

//------------------------------------------------------------------------------
// Rout: xccVCOReset
// Desc: This routine resets the VCO.
//------------------------------------------------------------------------------
VOID xccVCOReset( xccVCOSpec *spec )
{
  spec->fc    = spec->centerFrequency;
  spec->phase = 0.0;
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
