/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccVCO.c
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
// Rout: iccVCOInit
// Desc: This routine initializes the voltage controlled oscillator (VCO).
//------------------------------------------------------------------------------
iccVCOSpec *iccVCOInit(FLT64 centerFrequency, FLT64 fs, FLT64 phase)
{
  iccVCOSpec *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (iccVCOSpec *) iccMallocVOID_Align032(sizeof(iccVCOSpec));

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
// Rout: iccVCOCXXXXX
// Desc: These routine produces a complex output from a VCO.
//------------------------------------------------------------------------------
CFLT32 iccVCOCFLT32( FLT32 input, iccVCOSpec *spec )
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

CFLT64 iccVCOCFLT64( FLT64 input, iccVCOSpec *spec )
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

CFLT96 iccVCOCFLT96( FLT96 input, iccVCOSpec *spec )
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
// Rout: iccVCOXXXXX
// Desc: These routine produces an output from a VCO.
//------------------------------------------------------------------------------
FLT32 iccVCOFLT32( FLT32 input, iccVCOSpec *spec )
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

FLT64 iccVCOFLT64( FLT64 input, iccVCOSpec *spec )
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

FLT96 iccVCOFLT96( FLT96 input, iccVCOSpec *spec )
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

FLT32 iccVCOFLT32Cos( FLT32 input, iccVCOSpec *spec )
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

FLT64 iccVCOFLT64Cos( FLT64 input, iccVCOSpec *spec )
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

FLT96 iccVCOFLT96Cos( FLT96 input, iccVCOSpec *spec )
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

FLT32 iccVCOFLT32Sin( FLT32 input, iccVCOSpec *spec )
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

FLT64 iccVCOFLT64Sin( FLT64 input, iccVCOSpec *spec )
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

FLT96 iccVCOFLT96Sin( FLT96 input, iccVCOSpec *spec )
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
// Rout: iccvVCOCXXXXX
// Desc: These routine produces a complex vector output from a VCO.
//------------------------------------------------------------------------------
VOID iccvVCOCFLT32( FLT32 a, CFLT32 *b, INT32 i, UNT32 n, iccVCOSpec *spec )
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

VOID iccvVCOCFLT64( FLT64 a, CFLT64 *b, INT32 i, UNT32 n, iccVCOSpec *spec )
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

VOID iccvVCOCFLT96( FLT96 a, CFLT96 *b, INT32 i, UNT32 n, iccVCOSpec *spec )
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
// Rout: iccvVCOXXXXX
// Desc: These routine produces a complex vector output from a VCO.
//------------------------------------------------------------------------------
VOID iccvVCOFLT32( FLT32 a, FLT32 *b, INT32 i, UNT32 n, iccVCOSpec *spec )
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

VOID iccvVCOFLT64( FLT64 a, FLT64 *b, INT32 i, UNT32 n, iccVCOSpec *spec )
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

VOID iccvVCOFLT96( FLT96 a, FLT96 *b, INT32 i, UNT32 n, iccVCOSpec *spec )
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

VOID iccvVCOFLT32Cos( FLT32 a, FLT32 *b, INT32 i, UNT32 n, iccVCOSpec *spec )
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

VOID iccvVCOFLT64Cos( FLT64 a, FLT64 *b, INT32 i, UNT32 n, iccVCOSpec *spec )
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

VOID iccvVCOFLT96Cos( FLT96 a, FLT96 *b, INT32 i, UNT32 n, iccVCOSpec *spec )
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

VOID iccvVCOFLT32Sin( FLT32 a, FLT32 *b, INT32 i, UNT32 n, iccVCOSpec *spec )
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

VOID iccvVCOFLT64Sin( FLT64 a, FLT64 *b, INT32 i, UNT32 n, iccVCOSpec *spec )
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

VOID iccvVCOFLT96Sin( FLT96 a, FLT96 *b, INT32 i, UNT32 n, iccVCOSpec *spec )
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
// Rout: iccVCOUpdate
// Desc: This routine updates the VCO without output.
//------------------------------------------------------------------------------
VOID iccVCOUpdate( FLT64 input, iccVCOSpec *spec )
{
  spec->fc    = spec->centerFrequency + input;
  spec->phase = spec->phase + (spec->fc * spec->delta);
  spec->phase = fmod(spec->phase, 1.0);
}

//------------------------------------------------------------------------------
// Rout: iccVCOReset
// Desc: This routine resets the VCO.
//------------------------------------------------------------------------------
VOID iccVCOReset( iccVCOSpec *spec )
{
  spec->fc    = spec->centerFrequency;
  spec->phase = 0.0;
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
