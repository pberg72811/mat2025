/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccLoopFilter.c
// Desc: This file contains the code for the iccLoopFilter.
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
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
// Rout: iccLoopFilterInit
// Desc: This routine initializes the loop filter.
//------------------------------------------------------------------------------
iccLoopFilterSpec *iccLoopFilterInit(FLT64 lockInRange,
				     FLT64 dampingFactor,
				     FLT64 Kd,            // Usually (1.0/TWOPI).
				     FLT64 Ko,            // Usually (TWOPI).
				     FLT64 fs)
{
  iccLoopFilterSpec *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (iccLoopFilterSpec *) iccMallocVOID_Align032(sizeof(iccLoopFilterSpec));
 
  // 
  //----------------------------------------------------------------------------
  spec->lockInRange     = lockInRange;
  spec->dampingFactor   = dampingFactor;
  spec->Kd              = Kd;
  spec->Ko              = Ko;
  spec->fs              = fs;
  spec->sum             = 0.0;

  // The sample period as a function of sample rate (fs).
  //----------------------------------------------------------------------------
  spec->samplePeriod    = 1.0/fs;

  // The natural loop frequency (radians/second).
  //----------------------------------------------------------------------------
  spec->naturalFrequency = TWOPI * lockInRange / (2.0 * dampingFactor);

  // The integral coefficient.
  //----------------------------------------------------------------------------
  spec->Ki = (spec->naturalFrequency * spec->naturalFrequency) / (Kd * Ko);

  // The proportional coefficient.
  //----------------------------------------------------------------------------
  spec->Kp = 2.0 * dampingFactor / sqrt(Kd * Ko / spec->Ki);

  // The noise bandwidth.
  //----------------------------------------------------------------------------
  spec->noiseBW = (spec->naturalFrequency / 2.0) * (dampingFactor + (1.0/(4.0*dampingFactor)) );

  // Limit the integrator so it does not go crazy.
  //----------------------------------------------------------------------------
  spec->integratorLimit = XMCMIN(10.0*lockInRange, 1.0e20);

  return spec;
}


//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX output;
PERL_PREPROCESS
PERL_PREPROCESS  spec->sum = spec->sum + spec->Ki * input * spec->samplePeriod;
PERL_PREPROCESS
PERL_PREPROCESS  spec->sum = XMCMIN(spec->sum,  spec->integratorLimit);
PERL_PREPROCESS  spec->sum = XMCMAX(spec->sum, -spec->integratorLimit);
PERL_PREPROCESS  
PERL_PREPROCESS  output = spec->Kp * input + spec->sum;
PERL_PREPROCESS  
PERL_PREPROCESS  return output;
#endif

//------------------------------------------------------------------------------
// Rout: iccLoopFilterXXXXX
// Desc: Implements a loop filter to be used in second order control loops.
//       The filter function is of the form:
//           y(N) = Kp * x(N) + Ki * [x(N) + x(N-1) + x(N-2) +x(N-3) ...]
//       Where
//           y(N)    is the Nth output value.
//           x(N)    is the Nth input value.
//           x(N-1)  is the (N-1)th input value.
//           Kp, Ki  are the filter coefficients.
//------------------------------------------------------------------------------
FLT32 iccLoopFilterFLT32( FLT32 input, iccLoopFilterSpec *spec )
{
//------------------------------- COMMON-CODE FLT32 START.
  FLT32 output;

  spec->sum = spec->sum + spec->Ki * input * spec->samplePeriod;

  spec->sum = XMCMIN(spec->sum,  spec->integratorLimit);
  spec->sum = XMCMAX(spec->sum, -spec->integratorLimit);
  
  output = spec->Kp * input + spec->sum;
  
  return output;
//------------------------------- COMMON-CODE FLT32  STOP.
}

FLT64 iccLoopFilterFLT64( FLT64 input, iccLoopFilterSpec *spec )
{
//------------------------------- COMMON-CODE FLT64 START.
  FLT64 output;

  spec->sum = spec->sum + spec->Ki * input * spec->samplePeriod;

  spec->sum = XMCMIN(spec->sum,  spec->integratorLimit);
  spec->sum = XMCMAX(spec->sum, -spec->integratorLimit);
  
  output = spec->Kp * input + spec->sum;
  
  return output;
//------------------------------- COMMON-CODE FLT64  STOP.
}

FLT96 iccLoopFilterFLT96( FLT96 input, iccLoopFilterSpec *spec )
{
//------------------------------- COMMON-CODE FLT96 START.
  FLT96 output;

  spec->sum = spec->sum + spec->Ki * input * spec->samplePeriod;

  spec->sum = XMCMIN(spec->sum,  spec->integratorLimit);
  spec->sum = XMCMAX(spec->sum, -spec->integratorLimit);
  
  output = spec->Kp * input + spec->sum;
  
  return output;
//------------------------------- COMMON-CODE FLT96  STOP.
}

INT08 iccLoopFilterINT08( INT08 input, iccLoopFilterSpec *spec )
{
//------------------------------- COMMON-CODE INT08 START.
  INT08 output;

  spec->sum = spec->sum + spec->Ki * input * spec->samplePeriod;

  spec->sum = XMCMIN(spec->sum,  spec->integratorLimit);
  spec->sum = XMCMAX(spec->sum, -spec->integratorLimit);
  
  output = spec->Kp * input + spec->sum;
  
  return output;
//------------------------------- COMMON-CODE INT08  STOP.
}

INT16 iccLoopFilterINT16( INT16 input, iccLoopFilterSpec *spec )
{
//------------------------------- COMMON-CODE INT16 START.
  INT16 output;

  spec->sum = spec->sum + spec->Ki * input * spec->samplePeriod;

  spec->sum = XMCMIN(spec->sum,  spec->integratorLimit);
  spec->sum = XMCMAX(spec->sum, -spec->integratorLimit);
  
  output = spec->Kp * input + spec->sum;
  
  return output;
//------------------------------- COMMON-CODE INT16  STOP.
}

INT32 iccLoopFilterINT32( INT32 input, iccLoopFilterSpec *spec )
{
//------------------------------- COMMON-CODE INT32 START.
  INT32 output;

  spec->sum = spec->sum + spec->Ki * input * spec->samplePeriod;

  spec->sum = XMCMIN(spec->sum,  spec->integratorLimit);
  spec->sum = XMCMAX(spec->sum, -spec->integratorLimit);
  
  output = spec->Kp * input + spec->sum;
  
  return output;
//------------------------------- COMMON-CODE INT32  STOP.
}

INT64 iccLoopFilterINT64( INT64 input, iccLoopFilterSpec *spec )
{
//------------------------------- COMMON-CODE INT64 START.
  INT64 output;

  spec->sum = spec->sum + spec->Ki * input * spec->samplePeriod;

  spec->sum = XMCMIN(spec->sum,  spec->integratorLimit);
  spec->sum = XMCMAX(spec->sum, -spec->integratorLimit);
  
  output = spec->Kp * input + spec->sum;
  
  return output;
//------------------------------- COMMON-CODE INT64  STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
