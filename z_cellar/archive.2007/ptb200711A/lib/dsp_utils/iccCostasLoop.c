/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccCostasLoop.c
// Desc: This file contains the code for the iccCostasLoop.
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
#define COSTAS_COEFF (0.00000002)

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
// Rout: iccCostasLoopInitFLT32
// Desc: This routine initializes the Costas loop spec.
//------------------------------------------------------------------------------
iccCostasLoopSpec *iccCostasLoopInitFLT32(FLT32 fc, FLT32 fs, 
					  iccIIRFilterSpec *iirSpecI, 
					  iccIIRFilterSpec *iirSpecQ,
					  iccIIRFilterSpec *iirSpecLoop)
{
  iccCostasLoopSpec *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (iccCostasLoopSpec *) iccMallocVOID_Align032(sizeof(iccCostasLoopSpec));

  // Initialize the spec.
  //----------------------------------------------------------------------------
  spec->fc          = fc;
  spec->fs          = fs;
  spec->delta       = 2*PI*fc/fs;
  spec->phi         = -spec->delta;
  spec->iirSpecI    = iirSpecI;
  spec->iirSpecQ    = iirSpecQ;
  spec->iirSpecLoop = iirSpecLoop;

  return( spec );
}

//------------------------------------------------------------------------------
// Rout: iccCostasLoopBPSKFLT32
// Desc: This routine does Costas loop tracking for bpsk signals.
//------------------------------------------------------------------------------
VOID iccCostasLoopBPSKFLT32(FLT32 *x, FLT32 *y, INT32 n, iccCostasLoopSpec *spec )
{
  INT32 ii,jj;
  FLT64 a,b;
  FLT64 ncoi;
  FLT64 ncoq;
  FLT64 yI,yQ,yL;
  FLT64 yAmp = 1.0;

  for(ii = 0; ii < n; ii++)
  {
    spec->phi += spec->delta;
    spec->phi  = fmod(spec->phi, TWOPI);
    ncoi = 2 * cos(spec->phi);
    ncoq = 2 * sin(spec->phi);

    // IIR for I channel.  (Not QPSK I)
    //--------------------------------------------------------------------------
    for(jj = spec->iirSpecI->NP; jj >0; jj--)spec->iirSpecI->xii_[jj] = spec->iirSpecI->xii_[jj-1];
    for(jj = spec->iirSpecI->NP; jj >0; jj--)spec->iirSpecI->yii_[jj] = spec->iirSpecI->yii_[jj-1];
    spec->iirSpecI->xii_[0] = x[ii]*ncoi;

    a = b = 0;
    for(jj = 0; jj < (spec->iirSpecI->NP+1); jj++) a = a + spec->iirSpecI->a[jj]*spec->iirSpecI->xii_[jj];
    for(jj = 1; jj < (spec->iirSpecI->NP+1); jj++) b = b + spec->iirSpecI->b[jj]*spec->iirSpecI->yii_[jj];
  
    yI = spec->iirSpecI->yii_[0] = a + b;

    // IIR for Q channel.  (Not QPSK Q)
    //--------------------------------------------------------------------------
    for(jj = spec->iirSpecQ->NP; jj >0; jj--)spec->iirSpecQ->xii_[jj] = spec->iirSpecQ->xii_[jj-1];
    for(jj = spec->iirSpecQ->NP; jj >0; jj--)spec->iirSpecQ->yii_[jj] = spec->iirSpecQ->yii_[jj-1];
    spec->iirSpecQ->xii_[0] = x[ii]*ncoq;

    a = b = 0;
    for(jj = 0; jj < (spec->iirSpecQ->NP+1); jj++) a = a + spec->iirSpecQ->a[jj]*spec->iirSpecQ->xii_[jj];
    for(jj = 1; jj < (spec->iirSpecQ->NP+1); jj++) b = b + spec->iirSpecQ->b[jj]*spec->iirSpecQ->yii_[jj];
  
    yQ = spec->iirSpecQ->yii_[0] = a + b;

    // IIR for Loop channel.
    //--------------------------------------------------------------------------
    for(jj = spec->iirSpecLoop->NP; jj >0; jj--)spec->iirSpecLoop->xii_[jj] = spec->iirSpecLoop->xii_[jj-1];
    for(jj = spec->iirSpecLoop->NP; jj >0; jj--)spec->iirSpecLoop->yii_[jj] = spec->iirSpecLoop->yii_[jj-1];
    spec->iirSpecLoop->xii_[0] = yI*yQ;

    a = b = 0;
    for(jj = 0; jj < (spec->iirSpecLoop->NP+1); jj++) a = a + spec->iirSpecLoop->a[jj]*spec->iirSpecLoop->xii_[jj];
    for(jj = 1; jj < (spec->iirSpecLoop->NP+1); jj++) b = b + spec->iirSpecLoop->b[jj]*spec->iirSpecLoop->yii_[jj];
  
    yL = spec->iirSpecLoop->yii_[0] = a + b;

    y[ii] = yI;

    //
    //--------------------------------------------------------------------------
    yAmp = XMCMAX( yAmp, fabs(yL) ) - XMCMAX(yAmp/(32.5e6*0.5),1); //Amplitude control.
    yL = yL/yAmp;                                            //Amplitude control.
    spec->delta -= yL*COSTAS_COEFF*(spec->delta);

  }
  //spec->phi += spec->delta*ii;
  //spec->phi  = fmod(spec->phi,TWOPI);
}

//------------------------------------------------------------------------------
// Rout: iccCostasLoopTermFLT32
// Desc: This routine terminates the costas spec.  Free allocated memory.
//------------------------------------------------------------------------------
VOID iccCostasLoopTermFLT32( iccCostasLoopSpec *spec )
{
  //iccFree( spec->iirSpecI );
  //iccFree( spec->iirSpecQ );
  //iccFree( spec->iirSpecLoop );
  xmcFree( spec );
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
