/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccIIR.c
// Desc: This file contains the code for the xccIIR.
// Hist: When       Who  What
//       08/16/2002 ptb  Initial Code.
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
// Rout: xccIIRInitBPFLT32
// Desc: This routine creates an Band-Pass IIR filter specification based on 
//       center frequecy (fc), sample rate (fs), and desired bandwidth (bw).
//------------------------------------------------------------------------------
xccIIRFilterSpec *xccIIRInitBPFLT32(FLT32 fc, FLT32 fs, FLT32 bw )
{
  FLT64 f  = fc/fs;
  FLT64 BW = bw/fs;
  FLT64 R  = 1-3.0*BW;
  FLT64 K  = (1-(2.0*R*cos(TWOPI*f))+R*R)/(2.0-2.0*cos(TWOPI*f));
  FLT64 a0 = 1-K;
  FLT64 a1 = 2.0*(K-R)*cos(TWOPI*f);
  FLT64 a2 = R*R-K;
  FLT64 b1 = 2*R*cos(TWOPI*f);
  FLT64 b2 = -(R*R);
  INT32 ii;
  xccIIRFilterSpec *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccIIRFilterSpec *) xccMallocVOID_Align032(sizeof(xccIIRFilterSpec));

  // Clear out coefficeints and histories.
  //----------------------------------------------------------------------------
  for(ii = 0; ii<(IIRMAXPOLES+1); ii++) spec->a[ii] = spec->b[ii] = spec->xii_[ii] = spec->yii_[ii] = 0.0;
  
  // Set up the IIR specification.
  //----------------------------------------------------------------------------
  spec->f  = f;
  spec->BW = BW;
  spec->R  = R;
  spec->K  = K;
  spec->NP = 2;
  spec->a[0] = a0;
  spec->a[1] = a1;
  spec->a[2] = a2;
  spec->b[1] = b1;
  spec->b[2] = b2;

  return(spec);
}

//------------------------------------------------------------------------------
// Rout: xccIIRInitHPFLT32
// Desc: This routine creates an High-Pass IIR filter specification based on 
//       center frequecy (fc) and sample rate (fs).
//------------------------------------------------------------------------------
xccIIRFilterSpec *xccIIRInitHPFLT32(FLT32 fc, FLT32 fs )
{
  INT32 ii;
  xccIIRFilterSpec *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccIIRFilterSpec *) xccMallocVOID_Align032(sizeof(xccIIRFilterSpec));

  // Clear out coefficeints and histories.
  //----------------------------------------------------------------------------
  for(ii = 0; ii<(IIRMAXPOLES+1); ii++) spec->a[ii] = spec->b[ii] = spec->xii_[ii] = spec->yii_[ii] = 0.0;
  
  // Set up the IIR specification.
  //----------------------------------------------------------------------------
  spec->f  = fc/fs;
  spec->BW = 0.0;
  spec->R  = 0.0;
  spec->K  = 0.0;
  spec->NP = 1;
  spec->a[0] = +(1.0+exp(-TWOPI*spec->f))/2.0;
  spec->a[1] = -(1.0+exp(-TWOPI*spec->f))/2.0;
  spec->b[1] = exp(-TWOPI*spec->f);

  return(spec);
}

//------------------------------------------------------------------------------
// Rout: xccIIRInitLPFLT32
// Desc: This routine creates an Low-Pass IIR filter specification based on 
//       center frequecy (fc) and sample rate (fs).
//------------------------------------------------------------------------------
xccIIRFilterSpec *xccIIRInitLPFLT32(FLT32 fc, FLT32 fs )
{
  INT32 ii;
  xccIIRFilterSpec *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccIIRFilterSpec *) xccMallocVOID_Align032(sizeof(xccIIRFilterSpec));

  // Clear out coefficeints and histories.
  //----------------------------------------------------------------------------
  for(ii = 0; ii<(IIRMAXPOLES+1); ii++) spec->a[ii] = spec->b[ii] = spec->xii_[ii] = spec->yii_[ii] = 0.0;
  
  // Set up the IIR specification.
  //----------------------------------------------------------------------------
  spec->f  = fc/fs;
  spec->BW = 0.0;
  spec->R  = 0.0;
  spec->K  = 0.0;
  spec->NP = 1;
  spec->a[0] = 1.0-exp(-TWOPI*spec->f);
  spec->a[1] = 0.0;
  spec->b[1] = exp(-TWOPI*spec->f);

  return(spec);
}

//------------------------------------------------------------------------------
// Rout: xccIIRInitFLT32
// Desc: This routine creates an IIR filter specification setup based on hardcoded
//       coefficients that are passed in using va_arg.  Coefficients are passed
//       in as a0, a1, a2, ... aN, b1, b2, ... bN, where N is the number 
//       of "poles".  Maximum number of "poles" is 16.
//------------------------------------------------------------------------------
xccIIRFilterSpec *xccIIRInitFLT32(INT32 numberOfPoles, ... )
{
  INT32 ii;
  va_list argptr;
  xccIIRFilterSpec *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccIIRFilterSpec *) xccMallocVOID_Align032(sizeof(xccIIRFilterSpec));

  // Get and check the number of "Poles".
  //----------------------------------------------------------------------------
  spec->NP = numberOfPoles;
  if(spec->NP > IIRMAXPOLES)
  {
    XMC_ERROR_STDOUT("To Many Poles specified in IIR specification.");
    return(spec);
  }

  // Clear out coefficeints and histories.  Zero out x and y histories.
  //----------------------------------------------------------------------------
  for(ii = 0; ii<(IIRMAXPOLES+1); ii++) spec->a[ii] = spec->b[ii] = spec->xii_[ii] = spec->yii_[ii] = 0.0;

  // Handoff the "a" coefficients.
  //----------------------------------------------------------------------------
  va_start(argptr, numberOfPoles);
  for(ii = 0; ii<(spec->NP+1); ii++)
  {
    spec->a[ii] = va_arg(argptr, FLT64);
    spec->xii_[ii] = 0;
    spec->yii_[ii] = 0;
  }
  
  // Handoff the "b" coefficients.
  //----------------------------------------------------------------------------
  for(ii = 1; ii<(spec->NP+1); ii++)
  {
    spec->b[ii] = va_arg(argptr, FLT64);
  }

  // Set enverything else to zero.
  //----------------------------------------------------------------------------
  spec->f  = 0.0;
  spec->BW = 0.0;
  spec->R  = 0.0;
  spec->K  = 0.0;

  va_end(argptr);
  return(spec);
}

//------------------------------------------------------------------------------
// Rout: xccIIRFLT32
// Desc: This routine performs IIR filtering given an input array, an output
//       array, and an IIR filter specification.  The IIR filter specification is
//       created using one of "xccIRRInit" functions.
//------------------------------------------------------------------------------
VOID xccIIRFLT32(FLT32 *x,  FLT32 *y, INT32 n, xccIIRFilterSpec *spec )
{
  INT32 ii,jj;
  FLT64 a,b;

  for(ii = 0; ii < n; ii++)
  {
    for(jj = spec->NP; jj >0; jj--)spec->xii_[jj] = spec->xii_[jj-1];
    for(jj = spec->NP; jj >0; jj--)spec->yii_[jj] = spec->yii_[jj-1];
    spec->xii_[0] = x[ii];

    a = b = 0;
    for(jj = 0; jj < (spec->NP+1); jj++) a = a + spec->a[jj]*spec->xii_[jj];
    for(jj = 1; jj < (spec->NP+1); jj++) b = b + spec->b[jj]*spec->yii_[jj];
  
    y[ii] = spec->yii_[0] = a + b;
  }
}

//------------------------------------------------------------------------------
// Rout: xccIIRFLT64
// Desc: This routine performs IIR filtering given an input array, an output
//       array, and an IIR filter specification.  The IIR filter specification is
//       created using one of "xccIRRInit" functions.
//------------------------------------------------------------------------------
VOID xccIIRFLT64(FLT64 *x,  FLT64 *y, INT32 n, xccIIRFilterSpec *spec )
{
  INT32 ii,jj;
  FLT64 a,b;

  for(ii = 0; ii < n; ii++)
  {
    for(jj = spec->NP; jj >0; jj--)spec->xii_[jj] = spec->xii_[jj-1];
    for(jj = spec->NP; jj >0; jj--)spec->yii_[jj] = spec->yii_[jj-1];
    spec->xii_[0] = x[ii];

    a = b = 0;
    for(jj = 0; jj < (spec->NP+1); jj++) a = a + spec->a[jj]*spec->xii_[jj];
    for(jj = 1; jj < (spec->NP+1); jj++) b = b + spec->b[jj]*spec->yii_[jj];
  
    y[ii] = spec->yii_[0] = a + b;
  }
}

//------------------------------------------------------------------------------
// Rout: xccIIRTermFLT32
// Desc: This routine terminates the iir spec.  Free allocated memory.
//------------------------------------------------------------------------------
VOID xccIIRTermFLT32( xccIIRFilterSpec *spec )
{
  xmcFree(spec);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
