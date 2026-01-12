/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccSinc.c
// Desc: This file contains the code for the iccSinc.
// Hist: When       Who  What
//       04/26/2003 ptb  Initial Code.
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
#if 0
PERL_PREPROCESS  INT32 m = nTaps-1;
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS
PERL_PREPROCESS  for(ii =0; ii < nTaps; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    if( (ii-(m/2)) == 0 )
PERL_PREPROCESS    {
PERL_PREPROCESS      sinc[ii] = TWOPI*wc;
PERL_PREPROCESS    }
PERL_PREPROCESS    else sinc[ii] = sin(TWOPI*wc*(ii-(m/2)))/(ii-(m/2));
PERL_PREPROCESS  }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccSincFLT32( INT32 nTaps, FLT32 wc, FLT32 *sinc)
{
//COMMON-CODE START.
  INT32 m = nTaps-1;
  INT32 ii;

  for(ii =0; ii < nTaps; ii++)
  {
    if( (ii-(m/2)) == 0 )
    {
      sinc[ii] = TWOPI*wc;
    }
    else sinc[ii] = sin(TWOPI*wc*(ii-(m/2)))/(ii-(m/2));
  }
//COMMON-CODE  STOP.
}

VOID iccSincFLT64( INT32 nTaps, FLT64 wc, FLT32 *sinc)
{
//COMMON-CODE START.
  INT32 m = nTaps-1;
  INT32 ii;

  for(ii =0; ii < nTaps; ii++)
  {
    if( (ii-(m/2)) == 0 )
    {
      sinc[ii] = TWOPI*wc;
    }
    else sinc[ii] = sin(TWOPI*wc*(ii-(m/2)))/(ii-(m/2));
  }
//COMMON-CODE  STOP.
}

VOID iccSincFLT96( INT32 nTaps, FLT96 wc, FLT32 *sinc)
{
//COMMON-CODE START.
  INT32 m = nTaps-1;
  INT32 ii;

  for(ii =0; ii < nTaps; ii++)
  {
    if( (ii-(m/2)) == 0 )
    {
      sinc[ii] = TWOPI*wc;
    }
    else sinc[ii] = sin(TWOPI*wc*(ii-(m/2)))/(ii-(m/2));
  }
//COMMON-CODE  STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
