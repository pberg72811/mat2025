/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccNewRate.c
// Desc: This file contains the code for the iccNewRate.
// Hist: When       Who  What
//       06/28/2005 ptb  Initial Code.
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
typedef struct
{
  FLT64 t;
  FLT64 T;
  FLT64 fs;
  FLT64 fsNew;
  FLT64 nTapT;
  INT32 nTaps;
  FLT64 delta;
  INT64 batchStrt;
  INT64 batchStop;
  INT64 sampleCount;
  FLT32 *w;
  FLT32 *data;
  FLT32 *hist;
}iccNewRateSpec;
#endif

//------------------------------------------------------------------------------
// Rout: iccNewRateInit.
// Desc: This routine initializes the specification for iccNewRate.
//------------------------------------------------------------------------------
iccNewRateSpec *iccNewRateInit(FLT32 fs, FLT32 fsNew, INT32 nTaps)
{
  iccNewRateSpec *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (iccNewRateSpec *) iccMallocVOID_Align032(sizeof(iccNewRateSpec));

  // Initialize and allocate.
  //----------------------------------------------------------------------------
  spec->fs          = fs;
  spec->fsNew       = fsNew;
  spec->nTaps       = nTaps;
  spec->batchStrt   = 0;
  spec->batchStop   = 0;
  spec->sampleCount = 0;
  spec->t           = 0.0;
  spec->T           = 1.0/fs;
  spec->delta       = 1.0/fsNew;
  spec->nTapT       = (nTaps/2)*spec->T;

  // Allocate buffers.
  //----------------------------------------------------------------------------
  spec->w           = iccMallocFLT64_Align032( spec->nTaps );
  spec->data        = iccMallocFLT64_Align032( spec->nTaps );
  spec->hist        = iccMallocFLT64_Align032( spec->nTaps );

  // Clear buffers.
  //----------------------------------------------------------------------------
  iccvZeroFLT64( spec->w,    1, spec->nTaps );
  iccvZeroFLT64( spec->data, 1, spec->nTaps );
  iccvZeroFLT64( spec->hist, 1, spec->nTaps );

  // Return the spec.
  //----------------------------------------------------------------------------
  return(spec);
}

//------------------------------------------------------------------------------
// Rout: iccNewRate
// Desc: This routine performs iccNewRate.
//------------------------------------------------------------------------------
INT32 iccNewRate(FLT32 *iData, FLT32 *oData, UNT32 n, iccNewRateSpec *spec)
{
  INT32 ii;
  INT32 jj;
  FLT64 dt;
  FLT64 tStrt;
  FLT64 tStop;
  INT64 nStrt;
  INT64 nStop;
  UNT32 nout=0;
  INT64 indexStrt;
  INT64 indexStop;

  // Handle very important condition.
  //----------------------------------------------------------------------------
  if(n < spec->nTaps) 
  {
    XMC_ERROR_STDOUT("Input samples \"n\" needs to be >= \"nTaps\"\n");
    exit(0);
  }

  // Calculate the sample number this batch ends with.
  //----------------------------------------------------------------------------
  spec->batchStop = spec->batchStrt+n-1;

  // 
  //----------------------------------------------------------------------------
  tStrt = spec->t-spec->nTapT;
  tStop = spec->t+spec->nTapT;

  // Calculate overall sample number.
  //----------------------------------------------------------------------------
  nStrt = tStrt * spec->fs;
  nStop = tStop * spec->fs;

  while(nStop <= spec->batchStop)
  {

    // Load the data segment.
    //----------------------------------------------------------------------------
    jj=0;
    indexStrt = nStrt - spec->batchStrt;
    indexStop = nStop - spec->batchStrt;
    for( ii = indexStrt; ii < indexStop; ii++)
    {
      if(ii<0) spec->data[jj] = spec->hist[spec->nTaps+ii];
      else     spec->data[jj] = iData[ii];
      jj++;
    }

    // Generate the sync. function.
    //----------------------------------------------------------------------------
    jj=0;
    for( ii = nStrt; ii < nStop; ii++)
    {
      dt = (FLT64)(ii);
      dt = 3.14159265358979L*(spec->t - (spec->T*ii))/spec->T;
      spec->w[jj] = sin(dt)/dt;
      jj++;
    }

    // Convolve data and sync and get one output.
    //----------------------------------------------------------------------------
    // Perform the convolution.
    nout++;

    spec->t+=spec->delta;
    tStrt = spec->t-spec->nTapT;
    tStop = spec->t+spec->nTapT;
    nStrt = tStrt * spec->fs;
    nStop = tStop * spec->fs;

  }

  // Get ready for next time.
  //----------------------------------------------------------------------------
  spec->batchStrt = spec->batchStop+n;

  // Manage history.
  //----------------------------------------------------------------------------
  iccvCopyFLT32( &iData[n-spec->nTaps], 1, spec->hist, 1, spec->nTaps );

  return(nout);
}

//------------------------------------------------------------------------------
// Rout: iccNewRateTerm
// Desc: This routine terminates the specification for iccNewRate.
//------------------------------------------------------------------------------
VOID iccNewRateTerm(iccNewRateSpec *spec)
{
  xmcFree(spec->w);
  xmcFree(spec->data);
  xmcFree(spec->hist);
  xmcFree(spec);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX wc = fc/fs;
PERL_PREPROCESS  XXXXX tt;
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS  iccFIRFilterSpecXXXXX *spec=NULL;
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the spec.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec = (iccFIRFilterSpecXXXXX *) iccMallocVOID_Align032(sizeof(iccFIRFilterSpecXXXXX));
PERL_PREPROCESS
PERL_PREPROCESS  // Initialize and allocate.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec->nTaps = nTaps;
PERL_PREPROCESS  spec->nHist = nTaps-1;
PERL_PREPROCESS  spec->fw    = iccMallocXXXXX_Align032( spec->nTaps );
PERL_PREPROCESS  spec->fd    = iccMallocXXXXX_Align032( spec->nTaps );
PERL_PREPROCESS  spec->fh    = iccMallocXXXXX_Align032( spec->nHist*2 );
PERL_PREPROCESS  
PERL_PREPROCESS  // Generate the filter weights.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(ii =0; ii < nTaps; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    tt = ii-((nTaps-(nTaps%2))/2.0);
PERL_PREPROCESS    if( ((INT32)tt) == 0) spec->fw[ii] = TWOPI*wc;
PERL_PREPROCESS    else                  spec->fw[ii] = sin(TWOPI*wc*tt)/tt;
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  //iccBlackmanWindowXXXXX( spec->fw, 1, spec->fw, 1, nTaps );
PERL_PREPROCESS
PERL_PREPROCESS  return(spec);
#endif
