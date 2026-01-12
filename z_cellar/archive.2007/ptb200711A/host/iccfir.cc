/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: iccfir.cc                                                                              -
//                                                                                              -
// Desc: This primitive performs a Finite Impulse Response filter on input data.                -
//                                                                                              -
// Args: iFileName  - The name of the input  file.   <A:>                                       -
//       oFileName  - The name of the output file.   <A:>                                       -
//       fc         - Cutoff frequency for lowpass and highpass filters. *Note.                 -
//       bw         - Bandwidth for bandpass filter. *Note.                                     -
//       nTaps      - Number of filter taps to use.                                             -
//                                                                                              -
// Swch: /TL - Transfer length.                                                                 -
//       /TS - Transfer samples.                                                                -
//       /HP - Perform highpass filter.                                                         -
//       /LP - Perform lowpass  filter.                                                         -
//       /BP - Perform bandpass filter.                                                         -
//       /AC - Perform Accumulation filter.                                                     -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       04/21/2004 ptb  Initial Code.                                                          -
//                                                                                              -
//                       iFileName                                                              -
//                       oFileName                                                              -
//                          /TL                                                                 -
//                          /TS                                                                 -
//                          /HP                                                                 -
//                          /LP                                                                 -
//                          /BP                                                                 -
//                          /AC                                                                 -
//                           |                                                                  -
//                           V                                                                  -
//    :-----------:     :-----------:     :-----------:                                         -
//    | File/Pipe |---> | iccFIR.cc |---> | File/Pipe |                                         -
//    :-----------:     :-----------:     :-----------:                                         -
//                           |                                                                  -
//                           V                                                                  -
//                    Debug Statements                                                          -
//                                                                                              -
// Note: "fc" becomes the center frequency for bandpassfilters.                                 -
//       "bw" is ignored for lowpass and highpass filters.                                      -
//                                                                                              -
// Examples:                                                                                    -
// ramp test1 sd 128 0 1                                                                        -
// iccflip test1 test2                                                                          -
// xplot test1|test2                                                                            -
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
#include "primitive.h"
#include "iccswd.h"
#include "iccDSPUtils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG      TRUE
#define DEBUG_TYPE DEBUG_STDERR
#define ICC_DEBUG  if( DEBUG ) DEBUG_TYPE

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
  INT32 xferLngth;
  INT32 xferSamps;
  INT32 CMPLX=1;
  int_4 nGot;
  FLT64 fc;
  FLT64 bw;
  INT32 nTaps;
  FLT64 fs;
  INT08 *iDataINT08;
  FLT32 *iDataFLT32;
  FLT32 *oDataFLT32;

  iccFIRFilterSpecFLT32 *firSpecI;
  iccFIRFilterSpecFLT32 *firSpecQ;

  string iFileName;
  string oFileName;

  VOID (*genericToFLT32)(VOID *, INT32, VOID *, INT32, UNT32);

  // Get command line parameters.
  //---------------------------------------------------------------------------------------------
  iFileName  = m_apick(1);
  oFileName  = m_apick(2);
  fc         = m_dpick(3);
  bw         = m_dpick(4);
  nTaps      = m_lpick(5);
  ICC_DEBUG("iFileName  is %s\n", iFileName.c_str());
  ICC_DEBUG("oFileName  is %s\n", oFileName.c_str());
  ICC_DEBUG("fc         is %f\n", fc);
  ICC_DEBUG("bw         is %f\n", bw);
  ICC_DEBUG("nTaps      is %ld\n",nTaps);

  // Set up the input file header.
  //---------------------------------------------------------------------------------------------
  CPHEADER iHeader;
  iHeader.file_name    = iFileName;
  iHeader.type_allow   = "1000";
  iHeader.format_allow = "SB,SI,SL,SF,SD,CB,CI,CL,CF,CD";
  m_inok(iHeader);

  // Calculate fs based on header.
  //---------------------------------------------------------------------------------------------
  fs = 1.0/iHeader.xdelta;
  ICC_DEBUG("iHeader.xdelta is %f\n",iHeader.xdelta);
  ICC_DEBUG("fs             is %f\n",iHeader.xdelta);

  // Get the transfer length (BYTES) or transfer samples.  Default to 256k if not present.
  //---------------------------------------------------------------------------------------------
  if(m_get_pswitch("TL"))                     // Test for Transfer length.
  {                                           //
    xferLngth = m_get_switch("TL");           // Get transfer length (Bytes).
    xferSamps = xferLngth/iHeader.bpe;        // Calculate transfer samples.
  }                                           //
  else if(m_get_pswitch("TS"))                // Test for Transfer samples.
  {                                           //
    xferSamps = m_get_switch("TS");           // Get transfer samples.
    xferLngth = xferSamps*iHeader.bpe;        // Convert to transfer length (Bytes).
  }                                           //
  else                                        // Else
  {                                           //
    xferLngth = 262144;                       // Default to 256k bytes.
    xferSamps = xferLngth/iHeader.bpe;        // Calculate transfer samples.
  }                                           //--------------------------------------
  nGot = xferSamps;
  ICC_DEBUG("xferLngth   is %ld\n",xferLngth);
  ICC_DEBUG("xferSamps   is %ld\n",xferSamps);
  ICC_DEBUG("nGot        is %ld\n",xferSamps);
  ICC_DEBUG("iHeader.bpe is %d\n" ,iHeader.bpe);

  // Set the transfer length variable in the input header.
  //---------------------------------------------------------------------------------------------
  iHeader.xfer_len = xferSamps;
  iHeader.cons_len = -1;

  // Set up the output file header.
  //---------------------------------------------------------------------------------------------
  CPHEADER oHeader;
  m_initialize(oHeader);
  oHeader.file_name = oFileName;
  oHeader.type      = 1000;
  oHeader.format    = "SF";
  oHeader.size      = iHeader.size;
  oHeader.xstart    = iHeader.xstart;
  oHeader.xdelta    = iHeader.xdelta;
  oHeader.xunits    = 1;
  if ( strncmp(&iHeader.format.buf[0], "C", 1)==0 ) oHeader.format    = "CF";
  m_allocate(oHeader);

  // Set the generic conversion function based on input data type.
  //---------------------------------------------------------------------------------------------
  if      ( strncmp(&iHeader.format.buf[0], "SB", 2)==0 )
  {
    genericToFLT32 = iccvINT08ToFLT32;
    CMPLX=1;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SI", 2)==0 )
  {
    genericToFLT32 = iccvINT16ToFLT32;
    CMPLX=1;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SL", 2)==0 )
  {
    genericToFLT32 = iccvINT32ToFLT32;
    CMPLX=1;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SF", 2)==0 )
  {
    genericToFLT32 = iccvFLT32ToFLT32;
    CMPLX=1;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SD", 2)==0 )
  {
    genericToFLT32 = iccvFLT64ToFLT32;
    CMPLX=1;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CB", 2)==0 )
  {
    genericToFLT32 = iccvINT08ToFLT32;
    CMPLX=2;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CI", 2)==0 )
  {
    genericToFLT32 = iccvINT16ToFLT32;
    CMPLX=2;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CL", 2)==0 )
  {
    genericToFLT32 = iccvINT32ToFLT32;
    CMPLX=2;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CF", 2)==0 )
  {
    genericToFLT32 = iccvFLT32ToFLT32;
    CMPLX=2;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CD", 2)==0 )
  {
    genericToFLT32 = iccvFLT64ToFLT32;
    CMPLX=2;
  }
  else
  {
    printf("UNSUPPORTED DATA TYPE.\n"); //We should never get here because of m_inok(iHeader);
    exit(0);
  }
  ICC_DEBUG("Input file format is %s\n", iHeader.format.buf);

  // iccfir init.
  //---------------------------------------------------------------------------------------------
  iDataINT08 = iccMallocINT08_Align032( xferLngth ); // Generic input not just INT08.
  iDataFLT32 = iccMallocFLT32_Align032( xferSamps * CMPLX);
  oDataFLT32 = iccMallocFLT32_Align032( xferSamps * CMPLX);

  if     (m_get_pswitch("BP"))
  { 
    firSpecI = iccFIRFilterInitBPFLT32(fc, bw, fs, nTaps);
    firSpecQ = iccFIRFilterInitBPFLT32(fc, bw, fs, nTaps);
    ICC_DEBUG("Band Pass Filter.\n");
  }
  else if(m_get_pswitch("HP"))
  {
    firSpecI = iccFIRFilterInitHPFLT32(fc, fs, nTaps);
    firSpecQ = iccFIRFilterInitHPFLT32(fc, fs, nTaps);
    ICC_DEBUG("High Pass Filter.\n");
  }
  else if(m_get_pswitch("LP"))
  {
    firSpecI = iccFIRFilterInitLPFLT32(fc, fs, nTaps);
    firSpecQ = iccFIRFilterInitLPFLT32(fc, fs, nTaps);
    ICC_DEBUG("Low Pass Filter.\n");
  }
  else if(m_get_pswitch("AC"))
  {
    firSpecI = iccFIRFilterInitAccFLT32(nTaps);
    firSpecQ = iccFIRFilterInitAccFLT32(nTaps);
    ICC_DEBUG("Accumulator Filter.\n");
  }
  else   // Treat as lowpass filter (LP).
  {
    firSpecI = iccFIRFilterInitLPFLT32(fc, fs, nTaps);
    firSpecQ = iccFIRFilterInitLPFLT32(fc, fs, nTaps);
    ICC_DEBUG("Low Pass Filter.\n");
  }
  ICC_DEBUG("Done with init.\n");

  // "Synchronize" not "sink".
  //---------------------------------------------------------------------------------------------
  m_sync();
  ICC_DEBUG("Calling m_sync();\n");

  // Start the processing loop.
  //---------------------------------------------------------------------------------------------
  while( (nGot==xferSamps) && (!Mc->break_) )
  {
    // Grab the input data.
    //-------------------------------------------------------------------------------------------
    m_grabx(iHeader, iDataINT08, nGot);

    // Convert to FLT32.
    //-------------------------------------------------------------------------------------------
    genericToFLT32((VOID *)iDataINT08, 1, iDataFLT32, 1, nGot*CMPLX);

    // Filter the data.
    //-------------------------------------------------------------------------------------------
    if(CMPLX==2)
    {
      iccFIRFilterFLT32(&iDataFLT32[0], 2, &oDataFLT32[0], 2, nGot, firSpecI);
      iccFIRFilterFLT32(&iDataFLT32[1], 2, &oDataFLT32[1], 2, nGot, firSpecQ);
    }
    else
    {
      iccFIRFilterFLT32(iDataFLT32, 1, oDataFLT32, 1, nGot, firSpecI);
    }

    // Write out the output data.
    //-------------------------------------------------------------------------------------------
    m_filad(oHeader, oDataFLT32, nGot);
  }

  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  ICC_DEBUG("Terminating\n");
  iccFree(iDataINT08);
  iccFree(iDataFLT32);
  iccFree(oDataFLT32);
  iccFIRTermFLT32(firSpecI);
  iccFIRTermFLT32(firSpecQ);

  m_close(iHeader);
  m_close(oHeader);
  ICC_DEBUG("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
