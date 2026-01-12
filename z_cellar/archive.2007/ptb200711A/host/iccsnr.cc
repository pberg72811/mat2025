/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: iccsnr.cc                                                                              -
//                                                                                              -
// Desc: This primitive performs a SNR calculation on input data.                               -
//                                                                                              -
// Args: iFileName  - The name of the input file.      <A:>                                     -
//       oFileName  - The name of the output file.     <A:>                                     -
//       fftSize    - The size of the fft to perform.  <L:>                                     -
//       snrRes     - Results label for the SNR.       <A:>                                     -
//                                                                                              -
// Swch: None.                                                                                  -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       04/22/2004 ptb  Initial Code.                                                          -
//                                                                                              -
//                          iFileName                                                           -
//                          oFileName                                                           -
//                          fftSize                                                             -
//                          snrRes                                                              -
//                          /TL                                                                 -
//                          /TS                                                                 -
//                            |                                                                 -
//                            V                                                                 -
//    :-----------:     :-----------:     :-----------:                                         -
//    | FILE/PIPE |---> | iccsnr.cc |---> | FILE/PIPE |                                         -
//    :-----------:     :-----------:     :-----------:                                         -
//                            |                                                                 -
//                            V                                                                 -
//                     Debug Statements                                                         -
//                                                                                              -
// Note:                                                                                        -
//                                                                                              -
// Examples:                                                                                    -
//                                                                                              -
//01.0 Description                                                                              -
//02.0 Requirements                                                                             -
//03.0 Interfaces                                                                               -
//04.0 Design Description                                                                       -
//05.0 Unit Code                                                                                -
//06.0 Unit Test Plan                                                                           -
//07.0 Test Results                                                                             -
//08.0 Build Procedures                                                                         -
//09.0 Notes                                                                                    -
//10.0 Reviewers.                                                                               -
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include <primitive.h>
#include "xmc.h"
#include "dsp_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG      TRUE
#define DEBUG_HOST  "192.9.214.113"
#define DEBUG_PORT  5001
#define DEBUG_TYPE  XMC_DEBUG_STDOUT
//#define DEBUG_TYPE DEBUG_STDOUT_FILE
#define XMC_DEBUG  if( DEBUG ) DEBUG_TYPE

/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
VOID mainroutine()
{
  INT32 ii;
  FLT64 fs;
  FLT64 hzPerBin;
  INT32 fftSize;
  INT32 fftSize2;
  INT32 xferLngth;
  INT32 xferSamps;
  FLT64 runningSum=0.0;
  FLT64 runningCnt=0.0;
  int_4 nGot;
  INT08 *iDataINT08;
  CFLT32 *oDataCFLT32;
  FLT32 *magFLT32;
  FLT32 peakValue;
  INT32 peakIndex;
  FLT32 sig;
  FLT32 nos;
  FLT32 snr;
  INT32 newDex;
  INT32 complexFlag=1;//                          fftSize                                   -

  // Switch variables.

  // Result variables.
  string snrRes;


  // File name variables.
  string iFileName;
  string oFileName;

  VOID (*genericFFT)(VOID *, FLT32 *, UNT32);

  // Get command line parameters.
  //---------------------------------------------------------------------------------------------
  iFileName  = m_apick(1);
  oFileName  = m_apick(2);
  fftSize    = m_lpick(3);
  snrRes     = m_apick(4);
  XMC_DEBUG("iFileName  is %s\n",  iFileName.c_str());
  XMC_DEBUG("oFileName  is %s\n",  oFileName.c_str());
  XMC_DEBUG("fftSize    is %ld\n", fftSize);
  XMC_DEBUG("snrRes     is %s\n",  snrRes.c_str());

  // Set up the input file header.
  //---------------------------------------------------------------------------------------------
  CPHEADER iHeader;
  iHeader.file_name    = iFileName;
  iHeader.type_allow   = "1000";
  iHeader.format_allow = "SB,SI,SL,SF,SD,CB,CI,CL,CF,CD";
  m_inok(iHeader);

  // Get the transfer length (BYTES) or transfer samples.
  //---------------------------------------------------------------------------------------------
  //if(m_get_pswitch("TL"))                     // Test for Transfer length.
  //{                                           //
  //  xferLngth = m_get_switch("TL");           // Get transfer length (Bytes).
  //  xferSamps = xferLngth/iHeader.bpe;        // Calculate transfer samples.
  //  fftSize   = xferSamps;
  //}
  //else if(m_get_pswitch("TS"))                // Test for Transfer samples.
  //{                                           //
  //  xferSamps = m_get_switch("TS");           // Get transfer samples.
  //  xferLngth = xferSamps*iHeader.bpe;        // Convert to transfer length (Bytes).
  //  fftSize   = xferSamps;
  //}
  //else if(m_get_pswitch("FFTSIZE"))           // Test for FFTSIZE samples.
  //{                                           //
  //  xferSamps = m_get_switch("FFTSIZE");      // Get transfer samples.
  //  xferLngth = xferSamps*iHeader.bpe;        // Convert to transfer length (Bytes).
  //  fftSize   = xferSamps;
  //}
  //else                                        // Else
  //{                                           //
  //  xferLngth = 16384;                        // Default to 16k bytes.
  //  xferSamps = xferLngth/iHeader.bpe;        // Calculate transfer samples.
  //  fftSize   = xferSamps;
  //}

  xferSamps = fftSize;                          // Transfer samples equals fftSize.
  xferLngth = xferSamps*iHeader.bpe;            // Convert to transfer length (Bytes).

  if( (xferSamps !=          2) &&
      (xferSamps !=          4) &&
      (xferSamps !=          8) &&
      (xferSamps !=         16) &&
      (xferSamps !=         32) &&
      (xferSamps !=         64) &&
      (xferSamps !=        128) &&
      (xferSamps !=        256) &&
      (xferSamps !=        512) &&
      (xferSamps !=       1024) &&
      (xferSamps !=       2048) &&
      (xferSamps !=       4096) &&
      (xferSamps !=       8192) &&
      (xferSamps !=      16384) &&
      (xferSamps !=      32768) &&
      (xferSamps !=      65536) &&
      (xferSamps !=     131072) &&
      (xferSamps !=     262144) &&
      (xferSamps !=     524288) &&
      (xferSamps !=    1048576) &&
      (xferSamps !=    2097152) &&
      (xferSamps !=    4194304) &&
      (xferSamps !=    8388608) &&
      (xferSamps !=   16777216) &&
      (xferSamps !=   33554432) &&
      (xferSamps !=   67108864) &&
      (xferSamps !=  134217728) &&
      (xferSamps !=  268435456) &&
      (xferSamps !=  536870912) &&
      (xferSamps != 1073741824)
      // int_4 nGot prevents this (xferSamps != 2147483648U)
      )
  {
    XMC_ERROR_STDOUT("UNSUPPORTED FFT size.");
    XMC_DEBUG("This primitive needs to add zero padding.\n");
    exit(0);
  }

  nGot = xferSamps;
  XMC_DEBUG("xferLngth   is %ld\n",xferLngth);
  XMC_DEBUG("xferSamps   is %ld\n",xferSamps);
  XMC_DEBUG("fftSize     is %ld \n",fftSize);
  XMC_DEBUG("nGot        is %ld\n",(INT32)nGot);
  XMC_DEBUG("iHeader.bpe is %d\n" ,iHeader.bpe);

  // Set the transfer length variable in the input header.
  //---------------------------------------------------------------------------------------------
  iHeader.xfer_len = xferSamps;
  iHeader.cons_len = -1;

  // Set up the output file header.
  //---------------------------------------------------------------------------------------------
  fs       = 1.0/iHeader.xdelta;
  hzPerBin = fs/fftSize;
  fftSize2 = fftSize/2;

  CPHEADER oHeader;
  m_initialize(oHeader);
  oHeader.file_name = oFileName;
  oHeader.type      = 2000;
  oHeader.format    = "CF";
  oHeader.size      = iHeader.size/xferSamps;
  oHeader.xstart    = -fs/2.0;
  oHeader.xdelta    = hzPerBin;
  oHeader.xunits    = 3;
  oHeader.subsize   = fftSize;
  oHeader.ystart    = iHeader.xstart;
  oHeader.ydelta    = iHeader.xdelta;
  oHeader.yunits    = 1;
  m_allocate(oHeader);

  // Treat output as type 1000 file for the GRAB and FILAD routines.
  //---------------------------------------------------------------------------------------------
  m_force1000(oHeader);

  // Set the generic fft function.
  //---------------------------------------------------------------------------------------------
  if      ( strncmp(&iHeader.format.buf[0], "SB", 2)==0 )
  {
    genericFFT = iccFFTINT08_R;
    complexFlag=2;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SI", 2)==0 )
  {
    genericFFT = iccFFTINT16_R;
    complexFlag=2;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SL", 2)==0 )
  {
    genericFFT = iccFFTINT32_R;
    complexFlag=2;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SF", 2)==0 )
  {
    genericFFT = iccFFTFLT32_R;
    complexFlag=2;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SD", 2)==0 )
  {
    genericFFT = iccFFTFLT64_R;
    complexFlag=2;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CB", 2)==0 )
  {
    genericFFT = iccFFTINT08_C;
    complexFlag=1;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CI", 2)==0 )
  {
    genericFFT = iccFFTINT16_C;
    complexFlag=1;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CL", 2)==0 )
  {
    genericFFT = iccFFTINT32_C;
    complexFlag=1;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CF", 2)==0 )
  {
    genericFFT = iccFFTFLT32_C;
    complexFlag=1;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CD", 2)==0 )
  {
    genericFFT = iccFFTFLT64_C;
    complexFlag=1;
  }
  else
  {
    //We should never get here because of m_inok(iHeader);
    XMC_ERROR_STDOUT("UNSUPPORTED DATA TYPE.");
    exit(0);
  }
  XMC_DEBUG("Input file format is %s\n", iHeader.format.buf);

  // iccfft init.
  //---------------------------------------------------------------------------------------------
  iDataINT08  = iccMallocINT08_Align032 ( xferLngth ); // Generic input not just INT08.
  oDataCFLT32 = iccMallocCFLT32_Align032( xferSamps );
  magFLT32    = iccMallocFLT32_Align032( xferSamps );

  XMC_DEBUG("Done with init.\n");

  // "Synchronize" not "sink".
  //---------------------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG("Calling m_sync();\n");

  // Start the processing loop.
  //---------------------------------------------------------------------------------------------
  while( (nGot==xferSamps) && (!Mc->break_) )
  {
    // Grab the input data.
    //-------------------------------------------------------------------------------------------
    m_grabx(iHeader, iDataINT08, nGot);

    // Perform FFT.
    //-------------------------------------------------------------------------------------------
    genericFFT((VOID *)iDataINT08, (FLT32 *)oDataCFLT32, xferSamps);

    // Calculate magnitude.
    //-------------------------------------------------------------------------------------------
    for(ii=0; ii< xferSamps/complexFlag; ii++)
    {
      magFLT32[ii] = oDataCFLT32[ii].r*oDataCFLT32[ii].r + oDataCFLT32[ii].i*oDataCFLT32[ii].i;
      magFLT32[ii] = sqrt(magFLT32[ii]);
    }

    // Look for highest peak.
    //-------------------------------------------------------------------------------------------
    peakValue = magFLT32[0];
    peakIndex = 0;
    for(ii=0; ii<xferSamps/complexFlag; ii++)
    {
      if(peakValue < magFLT32[ii]) 
      {
	peakValue = magFLT32[ii];
	peakIndex = ii;
      }
    }

    if(peakIndex > xferSamps/complexFlag) peakIndex = peakIndex - xferSamps;

    printf("Peak at bin %ld\n", peakIndex);
    printf("Peak at frq %f\n",  peakIndex*hzPerBin);
    printf("Peak value  %f\n",  peakValue);

    // Calculate signal level.
    //-------------------------------------------------------------------------------------------
    if(peakIndex==0)
    {
      sig = magFLT32[peakIndex-0] +
	magFLT32[peakIndex+1] + 
	magFLT32[peakIndex+2];
    }
    if(peakIndex==1)
    {
      sig = magFLT32[peakIndex-1] +
	magFLT32[peakIndex-0] +
	magFLT32[peakIndex+1] + 
	magFLT32[peakIndex+2];
    }
    else
    {
      sig = magFLT32[peakIndex-2] +
	magFLT32[peakIndex-1] +
	magFLT32[peakIndex-0] +
	magFLT32[peakIndex+1] + 
	magFLT32[peakIndex+2];
    }

    // Calculate noise level.
    //-------------------------------------------------------------------------------------------
    if( peakIndex > ((xferSamps/complexFlag)-1-16-128) )
    {
      newDex = peakIndex - 1 - 16 - 128;
    }
    else
    {
      newDex = peakIndex + 16;
    }

    nos = 0;

    for(ii=0; ii<128; ii++)
    {
      nos += magFLT32[newDex+ii];
    }
    
    nos = nos/128.0;

    if (nos < EPSILON_FLT32) nos = EPSILON_FLT32;

    printf("Noise is %f\n", nos);

    // Calculate SNR.
    //-------------------------------------------------------------------------------------------
    snr = 10.0 * log10(sig/nos); //MULT hzPerBin

    runningSum = runningSum + snr;
    runningCnt = runningCnt + 1.0;

    printf("SNR is %f\n", snr);

    m_frslt(snrRes, snr);

    // Write out the output data.
    //-------------------------------------------------------------------------------------------
    m_filad(oHeader, &oDataCFLT32[fftSize2], fftSize2);
    m_filad(oHeader, &oDataCFLT32[0], fftSize2);
  }

  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  xmcFree(iDataINT08);
  xmcFree(oDataCFLT32);
  m_frslt(snrRes, runningSum/runningCnt);
  m_close(iHeader);
  m_close(oHeader);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
