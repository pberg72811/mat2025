/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: iccphasedetect.cc                                                                      -
//                                                                                              -
// Desc: This primitive compares an input signal with a reference frequency.                    -
//                                                                                              -
// Args: iFileName  - The name of the input file.   <A:>                                        -
//       oFileName  - The name of the output file.  <A:>                                        -
//       refFreq    - Reference frequency.          <D:>                                        -
//                                                                                              -
// Swch: /TL - Transfer length.                                                                 -
//       /TS - Transfer samples.                                                                -
//       /FS - Force the sample rate to a given value.                                          -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       05/28/2003 ptb  Initial Code.                                                          -
//                                                                                              -
//                           iFileName                                                          -
//                           oFileName                                                          -
//                           refFreq                                                            -
//                               |                                                              -
//                               V                                                              -
//    :-----------:     :-------------------:     :-----------:                                 -
//    | FILE/PIPE |---> | iccphasedetect.cc |---> | FILE/PIPE |                                 -
//    :-----------:     :-------------------:     :-----------:                                 -
//                               |                                                              -
//                               V                                                              -
//                        Debug Statements                                                      -
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
#include "primitive.h"
#include "xmc.h"
#include "dsp_utils.h"
#include "malloc_utils.h"

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
  INT32 xferLngth;
  INT32 xferSamps;
  int_4 nGot;
  FLT64 refFreq;
  FLT64 fs;
  FLT64 phaseStep;
  FLT64 phaseValue;
  FLT64 phaseNoise;
  INT08 *inDataINT08;
  FLT32 oDataFLT32;
  CFLT64 *signalCFLT64;
  CFLT64 *inDataCFLT64;
  CFLT64 *tempCFLT64;
  CFLT64 meanValueCFLT64;
  CFLT64 xCFLT64;
  string iFileName;
  string oFileName;
  iccSigGenSpecFLT64 *signalSpec;

  VOID (*genericToCFLT64)(VOID *, INT32, CFLT64 *, INT32, UNT32);

  // Get command line parameters.
  //-------------------------------------------------------------------------------
  iFileName  = m_apick(1);
  oFileName  = m_apick(2);
  refFreq    = m_dpick(3);
  XMC_DEBUG("iFileName  is %s\n", iFileName.c_str());
  XMC_DEBUG("oFileName  is %s\n", oFileName.c_str());
  XMC_DEBUG("refFreq    is %f\n", refFreq);

  // Set up the input file header.
  //-------------------------------------------------------------------------------
  CPHEADER iHeader;
  iHeader.file_name    = iFileName;
  iHeader.type_allow   = "1000";
  iHeader.format_allow = "SB,SI,SL,SF,CB,CI,CL,CF,CD";
  m_inok(iHeader);

  // Set sample rate based on switch or header of input data.
  //-------------------------------------------------------------------------------
  if( m_get_pswitch("FS") )
  {
    fs = m_get_dswitch("FS");
  }
  else
  {
    fs = 1.0/iHeader.xdelta;
  }
  XMC_DEBUG("fs        is %f\n", fs);

  // Get the transfer length (BYTES) or transfer samples.  Default to 256k if not present.
  //-------------------------------------------------------------------------------
  if(m_get_pswitch("TL"))                     // Test for Transfer length.
  {                                           //
    xferLngth = m_get_switch("TL");           // Get transfer length (Bytes).
    xferSamps = xferLngth/iHeader.bpe;        // Calculate transfer samples.
  }
  else if(m_get_pswitch("TS"))                // Test for Transfer samples.
  {                                           //
    xferSamps = m_get_switch("TS");           // Get transfer samples.
    xferLngth = xferSamps*iHeader.bpe;        // Convert to transfer length (Bytes).
  }
  else                                        // Else
  {                                           //
    xferLngth = 262144;                       // Default to 256k bytes.
    xferSamps = xferLngth/iHeader.bpe;        // Calculate transfer samples.
  }
  nGot = xferSamps;
  XMC_DEBUG("xferLngth   is %ld\n",xferLngth);
  XMC_DEBUG("xferSamps   is %ld\n",xferSamps);
  XMC_DEBUG("nGot        is %ld\n",xferSamps);
  XMC_DEBUG("iHeader.bpe is %d\n" ,iHeader.bpe);

  // Set the transfer length variable in the input header.
  //-------------------------------------------------------------------------------
  iHeader.xfer_len = xferSamps;
  iHeader.cons_len = -1;

  // Set up the output file header.
  //-------------------------------------------------------------------------------
  CPHEADER oHeader;
  m_initialize(oHeader);
  oHeader.file_name = oFileName;
  oHeader.type      = 1000;
  oHeader.format    = "SF";
  oHeader.size      = iHeader.size;
  oHeader.xstart    = iHeader.xstart;
  oHeader.xdelta    = iHeader.xdelta*xferSamps;
  oHeader.xunits    = 1;
  m_allocate(oHeader);

  // Set the generic conversion function based on input data type.
  //-------------------------------------------------------------------------------
  if      ( strncmp(&iHeader.format.buf[0], "SB", 2)==0 )
  {
    genericToCFLT64 = iccvINT08ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SI", 2)==0 )
  {
    genericToCFLT64 = iccvINT16ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SL", 2)==0 )
  {
    genericToCFLT64 = iccvINT32ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SF", 2)==0 )
  {
    genericToCFLT64 = iccvFLT32ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CB", 2)==0 )
  {
    genericToCFLT64 = iccvCINT08ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CI", 2)==0 )
  {
    genericToCFLT64 = iccvCINT16ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CL", 2)==0 )
  {
    genericToCFLT64 = iccvCINT32ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CF", 2)==0 )
  {
    genericToCFLT64 = iccvCFLT32ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CD", 2)==0 )
  {
    genericToCFLT64 = iccvCFLT64ToCFLT64;
  }
  else//We should never get here because of m_inok(iHeader);
  {
    XMC_ERROR_STDOUT("UNSUPPORTED DATA TYPE.\n");
    exit(0);
  }
  XMC_DEBUG("Input file format is %s\n", iHeader.format.buf);

  // iccphasedetect init.
  //-------------------------------------------------------------------------------
  inDataINT08  = iccMallocINT08_Align032( xferLngth );
  inDataCFLT64 = iccMallocCFLT64_Align032( xferSamps );
  signalCFLT64 = iccMallocCFLT64_Align032( xferSamps );
  tempCFLT64   = iccMallocCFLT64_Align032( xferSamps );

  signalSpec = iccSigGenInitFLT64(refFreq, fs, 1.0, 0.04);
  iccSigGenCosSinCFLT64(signalCFLT64, 1, xferSamps, signalSpec );

  phaseStep  = signalSpec->delta * xferSamps;
  phaseValue = 0.0;
  XMC_DEBUG("Done with init.\n");

  // "Synchronize" not "sink".
  //-------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG("Calling m_sync();\n");

  // Start the processing loop.
  //-------------------------------------------------------------------------------
  while( (nGot==xferSamps) && (!Mc->break_) )
  {
    // Grab the input data.
    //-------------------------------------------------------------------------------
    m_grabx(iHeader, inDataINT08, nGot);

    // Convert to CFLT64.
    //-------------------------------------------------------------------------------
    genericToCFLT64((VOID *)inDataINT08, 1, inDataCFLT64, 1, xferSamps);

    // Normalize Data.
    //-------------------------------------------------------------------------------
    meanValueCFLT64 = iccvMeanCFLT64(inDataCFLT64, 1, xferSamps);
    iccvsSubCFLT64(inDataCFLT64, 1, meanValueCFLT64, inDataCFLT64, 1, xferSamps);

    // Multiply and sum with sin and cos.
    //-------------------------------------------------------------------------------
    //iccvMulCFLT64(signalCFLT64, 1, inDataCFLT64, 1,  tempCFLT64, 1, xferSamps);
    xCFLT64 = iccvMulSumCFLT64(signalCFLT64, 1, inDataCFLT64, 1,  xferSamps);

    // Calculate phase
    //-------------------------------------------------------------------------------
    phaseNoise = atan2(xCFLT64.i,xCFLT64.r);

    phaseNoise = phaseNoise + phaseValue;

    oDataFLT32 = phaseNoise*180.0/PI;

    phaseValue += phaseStep;
    phaseValue  = fmod(phaseValue, TWOPI);

    // Write out the output data.
    //-------------------------------------------------------------------------------
    m_filad(oHeader, &oDataFLT32,1);
  }

  // Terminate and return.
  //-------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  iccSigGenTermFLT64(signalSpec);
  xmcFree(signalCFLT64);
  xmcFree(inDataINT08);
  xmcFree(inDataCFLT64);

  m_close(iHeader);
  m_close(oHeader);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*-------------------------------UNCLASSIFIED---------------------------------*/
