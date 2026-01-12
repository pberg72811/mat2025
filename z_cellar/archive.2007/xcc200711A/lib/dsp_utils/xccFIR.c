/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccFIR.c
// Desc: This file contains the code for the xccFIR.
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

//firLowPass.m 
//function h = firLowPass(n,wc)
//     N = floor(-n/2):floor(n/2);
//     h = sin(2.*pi.*wc.*N)./(N);
//     h(floor(0.6+n/2)+1)=2*pi*wc;
//
//firHighPass.m 
//function h = firHighPass(n,wc)
//     N = floor(-n/2):floor(n/2);
//     h = sin(2.*pi.*wc.*N)./(N);
//     h = -h;
//     h(floor(0.6+n/2)+1)=2*pi*wc;
//
//firBandPass.m 
//function h = firBandPass(n,wc1,wc2)
//     h1 = firLowPass(n,wc2);
//     h2 = firHighPass(n,wc1);
//     h = h1+h2;

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX wc = fc/fs;
PERL_PREPROCESS  XXXXX tt;
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS  xccFIRFilterSpecXXXXX *spec=NULL;
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the spec.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec = (xccFIRFilterSpecXXXXX *) xccMallocVOID_Align032(sizeof(xccFIRFilterSpecXXXXX));
PERL_PREPROCESS
PERL_PREPROCESS  // Initialize and allocate.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec->nTaps = nTaps;
PERL_PREPROCESS  spec->nHist = nTaps-1;
PERL_PREPROCESS  spec->fw    = xccMallocXXXXX_Align032( spec->nTaps );
PERL_PREPROCESS  spec->fd    = xccMallocXXXXX_Align032( spec->nTaps );
PERL_PREPROCESS  spec->fh    = xccMallocXXXXX_Align032( spec->nHist*2 );
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
PERL_PREPROCESS  //xccBlackmanWindowXXXXX( spec->fw, 1, spec->fw, 1, nTaps );
PERL_PREPROCESS
PERL_PREPROCESS  return(spec);
#endif

//------------------------------------------------------------------------------
// Rout: xccFIRFilterInitLPFLT32
// Desc: This routine initializes a low pass FIR filter spec.
//------------------------------------------------------------------------------
xccFIRFilterSpecFLT32 *xccFIRFilterInitLPFLT32(FLT32 fc, FLT32 fs, INT32 nTaps)
{
//------------------------------- COMMON-CODE FLT32         START.
  FLT32 wc = fc/fs;
  FLT32 tt;
  INT32 ii;
  xccFIRFilterSpecFLT32 *spec=NULL;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccFIRFilterSpecFLT32 *) xccMallocVOID_Align032(sizeof(xccFIRFilterSpecFLT32));

  // Initialize and allocate.
  //----------------------------------------------------------------------------
  spec->nTaps = nTaps;
  spec->nHist = nTaps-1;
  spec->fw    = xccMallocFLT32_Align032( spec->nTaps );
  spec->fd    = xccMallocFLT32_Align032( spec->nTaps );
  spec->fh    = xccMallocFLT32_Align032( spec->nHist*2 );
  
  // Generate the filter weights.
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    tt = ii-((nTaps-(nTaps%2))/2.0);
    if( ((INT32)tt) == 0) spec->fw[ii] = TWOPI*wc;
    else                  spec->fw[ii] = sin(TWOPI*wc*tt)/tt;
  }

  //xccBlackmanWindowFLT32( spec->fw, 1, spec->fw, 1, nTaps );

  return(spec);
//------------------------------- COMMON-CODE FLT32          STOP.
}

//------------------------------------------------------------------------------
// Rout: xccFIRFilterInitLPFLT64
// Desc: This routine initializes a low pass FIR filter spec.
//------------------------------------------------------------------------------
xccFIRFilterSpecFLT64 *xccFIRFilterInitLPFLT64(FLT64 fc, FLT64 fs, INT32 nTaps)
{
//------------------------------- COMMON-CODE FLT64         START.
  FLT64 wc = fc/fs;
  FLT64 tt;
  INT32 ii;
  xccFIRFilterSpecFLT64 *spec=NULL;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccFIRFilterSpecFLT64 *) xccMallocVOID_Align032(sizeof(xccFIRFilterSpecFLT64));

  // Initialize and allocate.
  //----------------------------------------------------------------------------
  spec->nTaps = nTaps;
  spec->nHist = nTaps-1;
  spec->fw    = xccMallocFLT64_Align032( spec->nTaps );
  spec->fd    = xccMallocFLT64_Align032( spec->nTaps );
  spec->fh    = xccMallocFLT64_Align032( spec->nHist*2 );
  
  // Generate the filter weights.
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    tt = ii-((nTaps-(nTaps%2))/2.0);
    if( ((INT32)tt) == 0) spec->fw[ii] = TWOPI*wc;
    else                  spec->fw[ii] = sin(TWOPI*wc*tt)/tt;
  }

  //xccBlackmanWindowFLT64( spec->fw, 1, spec->fw, 1, nTaps );

  return(spec);
//------------------------------- COMMON-CODE FLT64          STOP.
}

//------------------------------------------------------------------------------
// Rout: xccFIRFilterInitLPFLT96
// Desc: This routine initializes a low pass FIR filter spec.
//------------------------------------------------------------------------------
xccFIRFilterSpecFLT96 *xccFIRFilterInitLPFLT96(FLT96 fc, FLT96 fs, INT32 nTaps)
{
//------------------------------- COMMON-CODE FLT96         START.
  FLT96 wc = fc/fs;
  FLT96 tt;
  INT32 ii;
  xccFIRFilterSpecFLT96 *spec=NULL;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccFIRFilterSpecFLT96 *) xccMallocVOID_Align032(sizeof(xccFIRFilterSpecFLT96));

  // Initialize and allocate.
  //----------------------------------------------------------------------------
  spec->nTaps = nTaps;
  spec->nHist = nTaps-1;
  spec->fw    = xccMallocFLT96_Align032( spec->nTaps );
  spec->fd    = xccMallocFLT96_Align032( spec->nTaps );
  spec->fh    = xccMallocFLT96_Align032( spec->nHist*2 );
  
  // Generate the filter weights.
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    tt = ii-((nTaps-(nTaps%2))/2.0);
    if( ((INT32)tt) == 0) spec->fw[ii] = TWOPI*wc;
    else                  spec->fw[ii] = sin(TWOPI*wc*tt)/tt;
  }

  //xccBlackmanWindowFLT96( spec->fw, 1, spec->fw, 1, nTaps );

  return(spec);
//------------------------------- COMMON-CODE FLT96          STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX wc = fc/fs;
PERL_PREPROCESS  XXXXX tt;
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS  xccFIRFilterSpecXXXXX *spec=NULL;
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the spec.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec = (xccFIRFilterSpecXXXXX *) xccMallocVOID_Align032(sizeof(xccFIRFilterSpecXXXXX));
PERL_PREPROCESS
PERL_PREPROCESS  // Initialize and allocate.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec->nTaps = nTaps;
PERL_PREPROCESS  spec->nHist = nTaps-1;
PERL_PREPROCESS  spec->fw    = xccMallocXXXXX_Align032( spec->nTaps );
PERL_PREPROCESS  spec->fd    = xccMallocXXXXX_Align032( spec->nTaps );
PERL_PREPROCESS  spec->fh    = xccMallocXXXXX_Align032( spec->nHist*2 );
PERL_PREPROCESS
PERL_PREPROCESS  // Generate the filter weights.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(ii =0; ii < nTaps; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    tt = ii-((nTaps-(nTaps%2))/2.0);
PERL_PREPROCESS    if( ((INT32)tt) == 0) spec->fw[ii] = TWOPI*wc;
PERL_PREPROCESS    else                  spec->fw[ii] = -sin(TWOPI*wc*tt)/tt;
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  //xccBlackmanWindowXXXXX( spec->fw, 1, spec->fw, 1, nTaps );
PERL_PREPROCESS
PERL_PREPROCESS  return(spec);
#endif

//------------------------------------------------------------------------------
// Rout: xccFIRFilterInitHPFLT32
// Desc: This routine initializes a high pass FIR filter spec.
//------------------------------------------------------------------------------
xccFIRFilterSpecFLT32 *xccFIRFilterInitHPFLT32(FLT32 fc, FLT32 fs, INT32 nTaps)
{
//------------------------------- COMMON-CODE FLT32         START.
  FLT32 wc = fc/fs;
  FLT32 tt;
  INT32 ii;
  xccFIRFilterSpecFLT32 *spec=NULL;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccFIRFilterSpecFLT32 *) xccMallocVOID_Align032(sizeof(xccFIRFilterSpecFLT32));

  // Initialize and allocate.
  //----------------------------------------------------------------------------
  spec->nTaps = nTaps;
  spec->nHist = nTaps-1;
  spec->fw    = xccMallocFLT32_Align032( spec->nTaps );
  spec->fd    = xccMallocFLT32_Align032( spec->nTaps );
  spec->fh    = xccMallocFLT32_Align032( spec->nHist*2 );

  // Generate the filter weights.
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    tt = ii-((nTaps-(nTaps%2))/2.0);
    if( ((INT32)tt) == 0) spec->fw[ii] = TWOPI*wc;
    else                  spec->fw[ii] = -sin(TWOPI*wc*tt)/tt;
  }

  //xccBlackmanWindowFLT32( spec->fw, 1, spec->fw, 1, nTaps );

  return(spec);
//------------------------------- COMMON-CODE FLT32          STOP.
}

//------------------------------------------------------------------------------
// Rout: xccFIRFilterInitHPFLT64
// Desc: This routine initializes a high pass FIR filter spec.
//------------------------------------------------------------------------------
xccFIRFilterSpecFLT64 *xccFIRFilterInitHPFLT64(FLT64 fc, FLT64 fs, INT32 nTaps)
{
//------------------------------- COMMON-CODE FLT64         START.
  FLT64 wc = fc/fs;
  FLT64 tt;
  INT32 ii;
  xccFIRFilterSpecFLT64 *spec=NULL;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccFIRFilterSpecFLT64 *) xccMallocVOID_Align032(sizeof(xccFIRFilterSpecFLT64));

  // Initialize and allocate.
  //----------------------------------------------------------------------------
  spec->nTaps = nTaps;
  spec->nHist = nTaps-1;
  spec->fw    = xccMallocFLT64_Align032( spec->nTaps );
  spec->fd    = xccMallocFLT64_Align032( spec->nTaps );
  spec->fh    = xccMallocFLT64_Align032( spec->nHist*2 );

  // Generate the filter weights.
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    tt = ii-((nTaps-(nTaps%2))/2.0);
    if( ((INT32)tt) == 0) spec->fw[ii] = TWOPI*wc;
    else                  spec->fw[ii] = -sin(TWOPI*wc*tt)/tt;
  }

  //xccBlackmanWindowFLT64( spec->fw, 1, spec->fw, 1, nTaps );

  return(spec);
//------------------------------- COMMON-CODE FLT64          STOP.
}

//------------------------------------------------------------------------------
// Rout: xccFIRFilterInitHPFLT96
// Desc: This routine initializes a high pass FIR filter spec.
//------------------------------------------------------------------------------
xccFIRFilterSpecFLT96 *xccFIRFilterInitHPFLT96(FLT96 fc, FLT96 fs, INT32 nTaps)
{
//------------------------------- COMMON-CODE FLT96         START.
  FLT96 wc = fc/fs;
  FLT96 tt;
  INT32 ii;
  xccFIRFilterSpecFLT96 *spec=NULL;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccFIRFilterSpecFLT96 *) xccMallocVOID_Align032(sizeof(xccFIRFilterSpecFLT96));

  // Initialize and allocate.
  //----------------------------------------------------------------------------
  spec->nTaps = nTaps;
  spec->nHist = nTaps-1;
  spec->fw    = xccMallocFLT96_Align032( spec->nTaps );
  spec->fd    = xccMallocFLT96_Align032( spec->nTaps );
  spec->fh    = xccMallocFLT96_Align032( spec->nHist*2 );

  // Generate the filter weights.
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    tt = ii-((nTaps-(nTaps%2))/2.0);
    if( ((INT32)tt) == 0) spec->fw[ii] = TWOPI*wc;
    else                  spec->fw[ii] = -sin(TWOPI*wc*tt)/tt;
  }

  //xccBlackmanWindowFLT96( spec->fw, 1, spec->fw, 1, nTaps );

  return(spec);
//------------------------------- COMMON-CODE FLT96          STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX wcl = (fc-0.5*bw)/fs;
PERL_PREPROCESS  XXXXX wch = (fc+0.5*bw)/fs;
PERL_PREPROCESS  XXXXX *fwt;
PERL_PREPROCESS  XXXXX tt;
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS  xccFIRFilterSpecXXXXX *spec=NULL;
PERL_PREPROCESS 
PERL_PREPROCESS  // Malloc the memory for the spec.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec = (xccFIRFilterSpecXXXXX *) xccMallocVOID_Align032(sizeof(xccFIRFilterSpecXXXXX));
PERL_PREPROCESS
PERL_PREPROCESS  // Initialize and allocate.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec->nTaps = nTaps;
PERL_PREPROCESS  spec->nHist = nTaps-1;
PERL_PREPROCESS  spec->fw    = xccMallocXXXXX_Align032( spec->nTaps );
PERL_PREPROCESS  spec->fd    = xccMallocXXXXX_Align032( spec->nTaps );
PERL_PREPROCESS  spec->fh    = xccMallocXXXXX_Align032( spec->nHist*2 );
PERL_PREPROCESS
PERL_PREPROCESS  // Temporary filter weights.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  fwt = xccMallocXXXXX_Align032( spec->nTaps );
PERL_PREPROCESS  
PERL_PREPROCESS  // Generate the filter weights.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(ii =0; ii < nTaps; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    tt = ii-((nTaps-(nTaps%2))/2.0);
PERL_PREPROCESS    if( ((INT32)tt) == 0) fwt[ii] = TWOPI*wch;
PERL_PREPROCESS    else                  fwt[ii] = sin(TWOPI*wch*tt)/tt;
PERL_PREPROCESS  }
PERL_PREPROCESS  
PERL_PREPROCESS  // Generate the filter weights.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(ii =0; ii < nTaps; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    tt = ii-((nTaps-(nTaps%2))/2.0);
PERL_PREPROCESS    if( ((INT32)tt) == 0) spec->fw[ii] = TWOPI*wcl;
PERL_PREPROCESS    else                  spec->fw[ii] = -sin(TWOPI*wcl*tt)/tt;
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  //
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(ii =0; ii < nTaps; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    spec->fw[ii] = spec->fw[ii]+fwt[ii];
PERL_PREPROCESS  }
PERL_PREPROCESS  
PERL_PREPROCESS  //xccBlackmanWindowXXXXX( spec->fw, 1,spec->fw, 1, nTaps );
PERL_PREPROCESS  free(fwt);
PERL_PREPROCESS  return(spec);
#endif

//------------------------------------------------------------------------------
// Rout: xccFIRFilterInitBPFLT32
// Desc: This routine initializes a band pass FIR filter spec.
//------------------------------------------------------------------------------
xccFIRFilterSpecFLT32 *xccFIRFilterInitBPFLT32(FLT32 fc, FLT32 bw, FLT32 fs, INT32 nTaps)
{
//------------------------------- COMMON-CODE FLT32         START.
  FLT32 wcl = (fc-0.5*bw)/fs;
  FLT32 wch = (fc+0.5*bw)/fs;
  FLT32 *fwt;
  FLT32 tt;
  INT32 ii;
  xccFIRFilterSpecFLT32 *spec=NULL;
 
  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccFIRFilterSpecFLT32 *) xccMallocVOID_Align032(sizeof(xccFIRFilterSpecFLT32));

  // Initialize and allocate.
  //----------------------------------------------------------------------------
  spec->nTaps = nTaps;
  spec->nHist = nTaps-1;
  spec->fw    = xccMallocFLT32_Align032( spec->nTaps );
  spec->fd    = xccMallocFLT32_Align032( spec->nTaps );
  spec->fh    = xccMallocFLT32_Align032( spec->nHist*2 );

  // Temporary filter weights.
  //----------------------------------------------------------------------------
  fwt = xccMallocFLT32_Align032( spec->nTaps );
  
  // Generate the filter weights.
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    tt = ii-((nTaps-(nTaps%2))/2.0);
    if( ((INT32)tt) == 0) fwt[ii] = TWOPI*wch;
    else                  fwt[ii] = sin(TWOPI*wch*tt)/tt;
  }
  
  // Generate the filter weights.
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    tt = ii-((nTaps-(nTaps%2))/2.0);
    if( ((INT32)tt) == 0) spec->fw[ii] = TWOPI*wcl;
    else                  spec->fw[ii] = -sin(TWOPI*wcl*tt)/tt;
  }

  //
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    spec->fw[ii] = spec->fw[ii]+fwt[ii];
  }
  
  //xccBlackmanWindowFLT32( spec->fw, 1,spec->fw, 1, nTaps );
  free(fwt);
  return(spec);
//------------------------------- COMMON-CODE FLT32          STOP.
}

//------------------------------------------------------------------------------
// Rout: xccFIRFilterInitBPFLT64
// Desc: This routine initializes a band pass FIR filter spec.
//------------------------------------------------------------------------------
xccFIRFilterSpecFLT64 *xccFIRFilterInitBPFLT64(FLT64 fc, FLT64 bw, FLT64 fs, INT32 nTaps)
{
//------------------------------- COMMON-CODE FLT64         START.
  FLT64 wcl = (fc-0.5*bw)/fs;
  FLT64 wch = (fc+0.5*bw)/fs;
  FLT64 *fwt;
  FLT64 tt;
  INT32 ii;
  xccFIRFilterSpecFLT64 *spec=NULL;
 
  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccFIRFilterSpecFLT64 *) xccMallocVOID_Align032(sizeof(xccFIRFilterSpecFLT64));

  // Initialize and allocate.
  //----------------------------------------------------------------------------
  spec->nTaps = nTaps;
  spec->nHist = nTaps-1;
  spec->fw    = xccMallocFLT64_Align032( spec->nTaps );
  spec->fd    = xccMallocFLT64_Align032( spec->nTaps );
  spec->fh    = xccMallocFLT64_Align032( spec->nHist*2 );

  // Temporary filter weights.
  //----------------------------------------------------------------------------
  fwt = xccMallocFLT64_Align032( spec->nTaps );
  
  // Generate the filter weights.
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    tt = ii-((nTaps-(nTaps%2))/2.0);
    if( ((INT32)tt) == 0) fwt[ii] = TWOPI*wch;
    else                  fwt[ii] = sin(TWOPI*wch*tt)/tt;
  }
  
  // Generate the filter weights.
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    tt = ii-((nTaps-(nTaps%2))/2.0);
    if( ((INT32)tt) == 0) spec->fw[ii] = TWOPI*wcl;
    else                  spec->fw[ii] = -sin(TWOPI*wcl*tt)/tt;
  }

  //
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    spec->fw[ii] = spec->fw[ii]+fwt[ii];
  }
  
  //xccBlackmanWindowFLT64( spec->fw, 1,spec->fw, 1, nTaps );
  free(fwt);
  return(spec);
//------------------------------- COMMON-CODE FLT64          STOP.
}

//------------------------------------------------------------------------------
// Rout: xccFIRFilterInitBPFLT96
// Desc: This routine initializes a band pass FIR filter spec.
//------------------------------------------------------------------------------
xccFIRFilterSpecFLT96 *xccFIRFilterInitBPFLT96(FLT96 fc, FLT96 bw, FLT96 fs, INT32 nTaps)
{
//------------------------------- COMMON-CODE FLT96         START.
  FLT96 wcl = (fc-0.5*bw)/fs;
  FLT96 wch = (fc+0.5*bw)/fs;
  FLT96 *fwt;
  FLT96 tt;
  INT32 ii;
  xccFIRFilterSpecFLT96 *spec=NULL;
 
  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccFIRFilterSpecFLT96 *) xccMallocVOID_Align032(sizeof(xccFIRFilterSpecFLT96));

  // Initialize and allocate.
  //----------------------------------------------------------------------------
  spec->nTaps = nTaps;
  spec->nHist = nTaps-1;
  spec->fw    = xccMallocFLT96_Align032( spec->nTaps );
  spec->fd    = xccMallocFLT96_Align032( spec->nTaps );
  spec->fh    = xccMallocFLT96_Align032( spec->nHist*2 );

  // Temporary filter weights.
  //----------------------------------------------------------------------------
  fwt = xccMallocFLT96_Align032( spec->nTaps );
  
  // Generate the filter weights.
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    tt = ii-((nTaps-(nTaps%2))/2.0);
    if( ((INT32)tt) == 0) fwt[ii] = TWOPI*wch;
    else                  fwt[ii] = sin(TWOPI*wch*tt)/tt;
  }
  
  // Generate the filter weights.
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    tt = ii-((nTaps-(nTaps%2))/2.0);
    if( ((INT32)tt) == 0) spec->fw[ii] = TWOPI*wcl;
    else                  spec->fw[ii] = -sin(TWOPI*wcl*tt)/tt;
  }

  //
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    spec->fw[ii] = spec->fw[ii]+fwt[ii];
  }
  
  //xccBlackmanWindowFLT96( spec->fw, 1,spec->fw, 1, nTaps );
  free(fwt);
  return(spec);
//------------------------------- COMMON-CODE FLT96          STOP.
}


#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS  xccFIRFilterSpecXXXXX *spec=NULL;
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the spec.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec = (xccFIRFilterSpecXXXXX *) xccMallocVOID_Align032(sizeof(xccFIRFilterSpecXXXXX));
PERL_PREPROCESS
PERL_PREPROCESS  // Initialize and allocate.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec->nTaps = nTaps;
PERL_PREPROCESS  spec->nHist = nTaps-1;
PERL_PREPROCESS  spec->fw    = xccMallocXXXXX_Align032( spec->nTaps );
PERL_PREPROCESS  spec->fd    = xccMallocXXXXX_Align032( spec->nTaps );
PERL_PREPROCESS  spec->fh    = xccMallocXXXXX_Align032( spec->nHist*2 );
PERL_PREPROCESS
PERL_PREPROCESS  // Generate the filter weights.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(ii =0; ii < nTaps; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    spec->fw[ii] = 1.0/((FLT32)nTaps);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  return(spec);
#endif

//------------------------------------------------------------------------------
// Rout: xccFIRFilterInitAccFLT32
// Desc: This routine initializes an accumulator.
//------------------------------------------------------------------------------
xccFIRFilterSpecFLT32 *xccFIRFilterInitAccFLT32(INT32 nTaps)
{
//------------------------------- COMMON-CODE FLT32       START.
  INT32 ii;
  xccFIRFilterSpecFLT32 *spec=NULL;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccFIRFilterSpecFLT32 *) xccMallocVOID_Align032(sizeof(xccFIRFilterSpecFLT32));

  // Initialize and allocate.
  //----------------------------------------------------------------------------
  spec->nTaps = nTaps;
  spec->nHist = nTaps-1;
  spec->fw    = xccMallocFLT32_Align032( spec->nTaps );
  spec->fd    = xccMallocFLT32_Align032( spec->nTaps );
  spec->fh    = xccMallocFLT32_Align032( spec->nHist*2 );

  // Generate the filter weights.
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    spec->fw[ii] = 1.0/((FLT32)nTaps);
  }

  return(spec);
//------------------------------- COMMON-CODE FLT32        STOP.
}

xccFIRFilterSpecFLT64 *xccFIRFilterInitAccFLT64(INT32 nTaps)
{
//------------------------------- COMMON-CODE FLT64       START.
  INT32 ii;
  xccFIRFilterSpecFLT64 *spec=NULL;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccFIRFilterSpecFLT64 *) xccMallocVOID_Align032(sizeof(xccFIRFilterSpecFLT64));

  // Initialize and allocate.
  //----------------------------------------------------------------------------
  spec->nTaps = nTaps;
  spec->nHist = nTaps-1;
  spec->fw    = xccMallocFLT64_Align032( spec->nTaps );
  spec->fd    = xccMallocFLT64_Align032( spec->nTaps );
  spec->fh    = xccMallocFLT64_Align032( spec->nHist*2 );

  // Generate the filter weights.
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    spec->fw[ii] = 1.0/((FLT32)nTaps);
  }

  return(spec);
//------------------------------- COMMON-CODE FLT64        STOP.
}

xccFIRFilterSpecFLT96 *xccFIRFilterInitAccFLT96(INT32 nTaps)
{
//------------------------------- COMMON-CODE FLT96       START.
  INT32 ii;
  xccFIRFilterSpecFLT96 *spec=NULL;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccFIRFilterSpecFLT96 *) xccMallocVOID_Align032(sizeof(xccFIRFilterSpecFLT96));

  // Initialize and allocate.
  //----------------------------------------------------------------------------
  spec->nTaps = nTaps;
  spec->nHist = nTaps-1;
  spec->fw    = xccMallocFLT96_Align032( spec->nTaps );
  spec->fd    = xccMallocFLT96_Align032( spec->nTaps );
  spec->fh    = xccMallocFLT96_Align032( spec->nHist*2 );

  // Generate the filter weights.
  //----------------------------------------------------------------------------
  for(ii =0; ii < nTaps; ii++)
  {
    spec->fw[ii] = 1.0/((FLT32)nTaps);
  }

  return(spec);
//------------------------------- COMMON-CODE FLT96        STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  INT32 ii,jj;
PERL_PREPROCESS
PERL_PREPROCESS  if(n==0)                 {printf("Data length zero\n");return;};
PERL_PREPROCESS  if(n==1)                 {printf("Data length 1\n");return;};
PERL_PREPROCESS  if( (n%spec->nTaps!=0) ) {printf("Data length mismatch\n");return;}
PERL_PREPROCESS
PERL_PREPROCESS  // Move new data into the back end of the extended history buffer.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(ii = 0; ii < spec->nHist; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    spec->fh[spec->nHist+ii] = dataI[ii*ski];
PERL_PREPROCESS    //xcc_DEBUG("ii = %04ld  ", ii);
PERL_PREPROCESS    //xcc_DEBUG("spec->nHist+ii = %04ld  ", spec->nHist+ii);
PERL_PREPROCESS    //xcc_DEBUG("ii*ski = %04ld\n",ii*ski);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Convolve filter weights with the extended history buffer.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(ii = 0; ii < spec->nHist; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    dataO[ii*skj] = xccvConvolveXXXXX( &spec->fh[ii], 1, &spec->fw[0], 1, spec->nTaps );
PERL_PREPROCESS    //xcc_DEBUG("ii = %04ld  ", ii);
PERL_PREPROCESS    //xcc_DEBUG("ii*skj = %04ld\n",ii*ski);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Now clear of the history.  Just do a straight Convolve through the data.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(jj = 0; jj < (n-spec->nTaps+1); jj++)
PERL_PREPROCESS  {
PERL_PREPROCESS    dataO[ii*skj] = xccvConvolveXXXXX( &dataI[jj*ski], ski, &spec->fw[0], 1, spec->nTaps );// 1 to ski
PERL_PREPROCESS    //xcc_DEBUG("ii = %04ld  ", ii);
PERL_PREPROCESS    //xcc_DEBUG("jj = %04ld  ", jj);
PERL_PREPROCESS    //xcc_DEBUG("ii*skj = %04ld  ", ii*skj);
PERL_PREPROCESS    //xcc_DEBUG("jj*ski = %04ld\n",jj*ski);
PERL_PREPROCESS    ii++;
PERL_PREPROCESS  }
PERL_PREPROCESS 
PERL_PREPROCESS  // Save off the last of dataI for history next time.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(ii = 0; ii < spec->nHist; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    spec->fh[ii] = dataI[(n-spec->nHist+ii)*ski];
PERL_PREPROCESS    //xcc_DEBUG("ii = %04ld  ", ii);
PERL_PREPROCESS    //xcc_DEBUG("n  = %04ld  ", n);
PERL_PREPROCESS    //xcc_DEBUG("spec->nHist  = %04ld  ", spec->nHist);
PERL_PREPROCESS    //xcc_DEBUG("(n-spec->nHist+ii)*ski = %04ld\n",(n-spec->nHist+ii)*ski);
PERL_PREPROCESS  }
#endif

//------------------------------------------------------------------------------
// Rout: xccFIRFilterFLT32
// Desc: This routine performs an FIR filter based on the spec.
//------------------------------------------------------------------------------
VOID xccFIRFilterFLT32(FLT32 *dataI, INT32 ski, FLT32 *dataO, INT32 skj, INT32 n, xccFIRFilterSpecFLT32 *spec)
{
//------------------------------- COMMON-CODE FLT32          START.
  INT32 ii,jj;

  if(n==0)                 {printf("Data length zero\n");return;};
  if(n==1)                 {printf("Data length 1\n");return;};
  if( (n%spec->nTaps!=0) ) {printf("Data length mismatch\n");return;}

  // Move new data into the back end of the extended history buffer.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < spec->nHist; ii++)
  {
    spec->fh[spec->nHist+ii] = dataI[ii*ski];
    //xcc_DEBUG("ii = %04ld  ", ii);
    //xcc_DEBUG("spec->nHist+ii = %04ld  ", spec->nHist+ii);
    //xcc_DEBUG("ii*ski = %04ld\n",ii*ski);
  }

  // Convolve filter weights with the extended history buffer.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < spec->nHist; ii++)
  {
    dataO[ii*skj] = xccvConvolveFLT32( &spec->fh[ii], 1, &spec->fw[0], 1, spec->nTaps );
    //xcc_DEBUG("ii = %04ld  ", ii);
    //xcc_DEBUG("ii*skj = %04ld\n",ii*ski);
  }

  // Now clear of the history.  Just do a straight Convolve through the data.
  //----------------------------------------------------------------------------
  for(jj = 0; jj < (n-spec->nTaps+1); jj++)
  {
    dataO[ii*skj] = xccvConvolveFLT32( &dataI[jj*ski], ski, &spec->fw[0], 1, spec->nTaps );// 1 to ski
    //xcc_DEBUG("ii = %04ld  ", ii);
    //xcc_DEBUG("jj = %04ld  ", jj);
    //xcc_DEBUG("ii*skj = %04ld  ", ii*skj);
    //xcc_DEBUG("jj*ski = %04ld\n",jj*ski);
    ii++;
  }
 
  // Save off the last of dataI for history next time.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < spec->nHist; ii++)
  {
    spec->fh[ii] = dataI[(n-spec->nHist+ii)*ski];
    //xcc_DEBUG("ii = %04ld  ", ii);
    //xcc_DEBUG("n  = %04ld  ", n);
    //xcc_DEBUG("spec->nHist  = %04ld  ", spec->nHist);
    //xcc_DEBUG("(n-spec->nHist+ii)*ski = %04ld\n",(n-spec->nHist+ii)*ski);
  }
//------------------------------- COMMON-CODE FLT32           STOP.
}

//------------------------------------------------------------------------------
// Rout: xccFIRFilterFLT64
// Desc: This routine performs an FIR filter based on the spec.
//------------------------------------------------------------------------------
VOID xccFIRFilterFLT64(FLT64 *dataI, INT32 ski, FLT64 *dataO, INT32 skj, INT32 n, xccFIRFilterSpecFLT64 *spec)
{
//------------------------------- COMMON-CODE FLT64          START.
  INT32 ii,jj;

  if(n==0)                 {printf("Data length zero\n");return;};
  if(n==1)                 {printf("Data length 1\n");return;};
  if( (n%spec->nTaps!=0) ) {printf("Data length mismatch\n");return;}

  // Move new data into the back end of the extended history buffer.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < spec->nHist; ii++)
  {
    spec->fh[spec->nHist+ii] = dataI[ii*ski];
    //xcc_DEBUG("ii = %04ld  ", ii);
    //xcc_DEBUG("spec->nHist+ii = %04ld  ", spec->nHist+ii);
    //xcc_DEBUG("ii*ski = %04ld\n",ii*ski);
  }

  // Convolve filter weights with the extended history buffer.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < spec->nHist; ii++)
  {
    dataO[ii*skj] = xccvConvolveFLT64( &spec->fh[ii], 1, &spec->fw[0], 1, spec->nTaps );
    //xcc_DEBUG("ii = %04ld  ", ii);
    //xcc_DEBUG("ii*skj = %04ld\n",ii*ski);
  }

  // Now clear of the history.  Just do a straight Convolve through the data.
  //----------------------------------------------------------------------------
  for(jj = 0; jj < (n-spec->nTaps+1); jj++)
  {
    dataO[ii*skj] = xccvConvolveFLT64( &dataI[jj*ski], ski, &spec->fw[0], 1, spec->nTaps );// 1 to ski
    //xcc_DEBUG("ii = %04ld  ", ii);
    //xcc_DEBUG("jj = %04ld  ", jj);
    //xcc_DEBUG("ii*skj = %04ld  ", ii*skj);
    //xcc_DEBUG("jj*ski = %04ld\n",jj*ski);
    ii++;
  }
 
  // Save off the last of dataI for history next time.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < spec->nHist; ii++)
  {
    spec->fh[ii] = dataI[(n-spec->nHist+ii)*ski];
    //xcc_DEBUG("ii = %04ld  ", ii);
    //xcc_DEBUG("n  = %04ld  ", n);
    //xcc_DEBUG("spec->nHist  = %04ld  ", spec->nHist);
    //xcc_DEBUG("(n-spec->nHist+ii)*ski = %04ld\n",(n-spec->nHist+ii)*ski);
  }
//------------------------------- COMMON-CODE FLT64           STOP.
}

//------------------------------------------------------------------------------
// Rout: xccFIRFilterFLT96
// Desc: This routine performs an FIR filter based on the spec.
//------------------------------------------------------------------------------
VOID xccFIRFilterFLT96(FLT96 *dataI, INT32 ski, FLT96 *dataO, INT32 skj, INT32 n, xccFIRFilterSpecFLT96 *spec)
{
//------------------------------- COMMON-CODE FLT96          START.
  INT32 ii,jj;

  if(n==0)                 {printf("Data length zero\n");return;};
  if(n==1)                 {printf("Data length 1\n");return;};
  if( (n%spec->nTaps!=0) ) {printf("Data length mismatch\n");return;}

  // Move new data into the back end of the extended history buffer.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < spec->nHist; ii++)
  {
    spec->fh[spec->nHist+ii] = dataI[ii*ski];
    //xcc_DEBUG("ii = %04ld  ", ii);
    //xcc_DEBUG("spec->nHist+ii = %04ld  ", spec->nHist+ii);
    //xcc_DEBUG("ii*ski = %04ld\n",ii*ski);
  }

  // Convolve filter weights with the extended history buffer.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < spec->nHist; ii++)
  {
    dataO[ii*skj] = xccvConvolveFLT96( &spec->fh[ii], 1, &spec->fw[0], 1, spec->nTaps );
    //xcc_DEBUG("ii = %04ld  ", ii);
    //xcc_DEBUG("ii*skj = %04ld\n",ii*ski);
  }

  // Now clear of the history.  Just do a straight Convolve through the data.
  //----------------------------------------------------------------------------
  for(jj = 0; jj < (n-spec->nTaps+1); jj++)
  {
    dataO[ii*skj] = xccvConvolveFLT96( &dataI[jj*ski], ski, &spec->fw[0], 1, spec->nTaps );// 1 to ski
    //xcc_DEBUG("ii = %04ld  ", ii);
    //xcc_DEBUG("jj = %04ld  ", jj);
    //xcc_DEBUG("ii*skj = %04ld  ", ii*skj);
    //xcc_DEBUG("jj*ski = %04ld\n",jj*ski);
    ii++;
  }
 
  // Save off the last of dataI for history next time.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < spec->nHist; ii++)
  {
    spec->fh[ii] = dataI[(n-spec->nHist+ii)*ski];
    //xcc_DEBUG("ii = %04ld  ", ii);
    //xcc_DEBUG("n  = %04ld  ", n);
    //xcc_DEBUG("spec->nHist  = %04ld  ", spec->nHist);
    //xcc_DEBUG("(n-spec->nHist+ii)*ski = %04ld\n",(n-spec->nHist+ii)*ski);
  }
//------------------------------- COMMON-CODE FLT96           STOP.
}

//------------------------------------------------------------------------------
// Rout: xccFIRTermFLT32
// Desc: This routine terminates the FIR spec.  Free allocated memory.
//------------------------------------------------------------------------------
VOID xccFIRTermFLT32( xccFIRFilterSpecFLT32 *spec )
{
  xmcFree(spec->fw);
  xmcFree(spec->fd);
  xmcFree(spec->fh);
  xmcFree(spec);
}

VOID xccFIRTermFLT64( xccFIRFilterSpecFLT64 *spec )
{
  xmcFree(spec->fw);
  xmcFree(spec->fd);
  xmcFree(spec->fh);
  xmcFree(spec);
}

VOID xccFIRTermFLT96( xccFIRFilterSpecFLT96 *spec )
{
  xmcFree(spec->fw);
  xmcFree(spec->fd);
  xmcFree(spec->fh);
  xmcFree(spec);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
