/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccChebyshev.c
// Desc: This file contains the code for Chebyshev IIR filter design.
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
void subRoutine(FLT32 FC, INT32 NP, INT32 P, FLT32 PR, INT32 LH, FLT32 *A0, FLT32 *A1, FLT32 *A2, FLT32 *B1, FLT32 *B2)
{
  FLT32 ES,VX,KX;
  FLT32 X0,X1,X2,Y1,Y2;
  FLT32 T,W,M,D,K=0;
  FLT32 RP;
  FLT32 IP;

  // Calculate the pole location on the unit circle.
  //----------------------------------------------------------------------------
  RP = -cos( PI/(NP*2) + (P-1) * PI/NP );
  IP =  sin( PI/(NP*2) + (P-1) * PI/NP );

  // Warp the circle to an ellipse.
  //----------------------------------------------------------------------------
  if( PR != 0.0 )
  {
    ES = sqrt( (100.0/(100.0-PR))*(100.0/(100.0-PR)) - 1);
    VX = (1.0/NP) * log( (1.0/ES) + sqrt(1.0/(ES*ES)+1.0) );
    KX = (1.0/NP) * log( (1.0/ES) + sqrt(1.0/(ES*ES)-1.0) );
    KX = ( exp(KX)+exp(-KX) )/2.0;
    RP = RP * ( (exp(VX)-exp(-VX))/2.0 )/KX;
    IP = IP * ( (exp(VX)+exp(-VX))/2.0 )/KX;
  }

  // S-Domain to Z-Domain conversion.
  //----------------------------------------------------------------------------
  T = 2.0 * tan(0.5);
  W = 2.0*PI*FC;
  M = RP*RP+IP*IP;
  D = 4.0 - 4.0*RP*T + M*T*T;
  X0 = T*T/D;
  X1 = 2.0*T*T/D;
  X2 = T*T/D;
  Y1 = (8.0-2.0*M*T*T)/D;
  Y2 = (-4.0-4.0*RP*T-M*T*T)/D;

  // Low pass to low pass or low pass to high pass transform.
  //----------------------------------------------------------------------------
  if(LH==1) K = -cos(W/2.0+0.5)/cos(W/2.0-0.5);
  if(LH==0) K =  sin(0.5-W/2.0)/sin(0.5+W/2.0);

  D = 1 + Y1*K - Y2*K*K;
  *A0 = (X0 - X1*K + X2*K*K)/D;
  *A1 = (-2*X0*K + X1 + X1*K*K - 2.0*X2*K)/D;
  *A2 = (X0*K*K - X1*K + X2)/D;
  *B1 = (2.0*K + Y1 + Y1*K*K - 2.0*Y2*K)/D;
  *B2 = (-K*K - Y1*K + Y2)/D;
  
  if(LH == 1) *A1 = -*A1;
  if(LH == 1) *B1 = -*B1;
}

//
//------------------------------------------------------------------------------
xccIIRFilterSpec *xccChebyshevFilter(FLT32 fc, FLT32 fs, INT32 NP, FLT32 PR, INT32 LH)
{
  INT32 ii,jj;
  FLT32 TA[IIRMAXPOLES+1];
  FLT32 TB[IIRMAXPOLES+1];
  FLT32 A0,A1,A2,B1,B2;
  FLT32 SA,SB;
  FLT32 GAIN;
  xccIIRFilterSpec *spec;

  // Initialize.
  //----------------------------------------------------------------------------
  A0=A1=A2=B1=B2=0.0;

  spec = (xccIIRFilterSpec *) malloc(sizeof(xccIIRFilterSpec));
  spec->f = fc/fs;
  spec->BW = 0.0;
  spec->R = 0.0;
  spec->K = 0.0;
  spec->NP = NP;
  for(ii =0; ii < (IIRMAXPOLES+1); ii++)
  {
    spec->a[ii]    = spec->b[ii]    = 0.0;
    spec->xii_[ii] = spec->yii_[ii] = 0.0;
    TA[ii]         = TB[ii]         = 0.0;
  }

  spec->a[2] = 1;
  spec->b[2] = 1;

  // 
  //----------------------------------------------------------------------------
  for(ii = 1; ii <=NP/2; ii++)
  {
   
    subRoutine(spec->f, spec->NP, ii, PR, LH, &A0, &A1, &A2, &B1, &B2);

    for(jj = 0; jj < (IIRMAXPOLES+1); jj++)
    {
      TA[jj] = spec->a[jj];
      TB[jj] = spec->b[jj];
    }

    for(jj = 2; jj < (IIRMAXPOLES+1); jj++)
    {
      spec->a[jj] = A0*TA[jj]+A1*TA[jj-1]+A2*TA[jj-2];
      spec->b[jj] =    TB[jj]-B1*TB[jj-1]-B2*TB[jj-2];
    }
  }

  spec->b[2] = 0;
  for(ii = 0; ii < (IIRMAXPOLES-1); ii++)
  {
    spec->a[ii] = spec->a[ii+2];
    spec->b[ii] = -spec->b[ii+2];
  }

  // Normalize the gain.
  //----------------------------------------------------------------------------
  SA = 0;
  SB = 0;

  for(ii = 0; ii < (IIRMAXPOLES+1); ii++)
  {
    if( LH == 0 ) SA = SA + spec->a[ii];
    if( LH == 0 ) SB = SB + spec->b[ii];

    if( LH == 1 ) SA = SA + spec->a[ii]*(-1);
    if( LH == 1 ) SB = SB + spec->b[ii]*(-1);
  }

  GAIN = SA/(1-SB);

  for(ii = 0; ii < (IIRMAXPOLES+1); ii++) spec->a[ii] = spec->a[ii]/GAIN;

  return(spec);
}
