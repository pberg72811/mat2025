/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccsiggen.cc                                                                           -
//                                                                                              -
// Desc: This primitive generates a sin wave.                                                   -
//                                                                                              -
// Args: oFileName - The name of the output file.  <A:>                                         -
//       dataType  - Format of data.               <A:>                                         -
//       nSamples  - Number of samples.            <L:>                                         -
//       fc        - Frequency of signal.          <D:>                                         -
//       amp       - Amplitude of signal.          <D:>                                         -
//       phs       - Phase of signal.              <D:>                                         -
//       fs        - Sample rate of signal.        <D:>                                         -
//                                                                                              -
// Swch: /TL    - Number of transfer bytes.                                                     -
//       /TS    - Number of transfer samples.                                                   -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       09/25/2003 ptb  Initial Code.                                                          -
//       06/07/2006 ptb  Code Modifications.                                                    -
//                                                                                              -
//                           oFileName                                                          -
//                           dataType                                                           -
//                           nSamples                                                           -
//                           fc                                                                 -
//                           amp                                                                -
//                           phs                                                                -
//                           fs                                                                 -
//                           /TL                                                                -
//                           /TS                                                                -
//                             |                                                                -
//                             V                                                                -
//    :-----------:     :--------------:     :-----------:                                      -
//    | FILE/PIPE |---> | xccsiggen.cc |---> | FILE/PIPE |                                      -
//    :-----------:     :--------------:     :-----------:                                      -
//                             |                                                                -
//                             V                                                                -
//                      Debug Statements                                                        -
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
#include "malloc_utils.h"
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
  int_4 nDo;
  INT32 nSamples;
  FLT64 fc;
  FLT64 fs;
  FLT64 amp;
  FLT64 phs;
  INT08 *oDataINT08;

  xccSigGenSpecFLT64 *sigSpec;

  // Switch variables.
  INT32 xferLngth;
  INT32 xferSamps;

  // File name variables.
  string oFileName;
  string dataType;

  // generic copy function pointer.
  VOID (*xccGenericSigGen)(VOID *, INT32, INT32, xccSigGenSpecFLT64 *);

  // Get command line arguments.
  //---------------------------------------------------------------------------------------------
  oFileName = m_apick(1);
  dataType  = m_apick(2);
  nSamples  = m_lpick(3);
  fc        = m_dpick(4);
  amp       = m_dpick(5);
  phs       = m_dpick(6);
  fs        = m_dpick(7);
  XMC_DEBUG("oFileName is %s\n", oFileName.c_str());
  XMC_DEBUG("dataType  is %s\n", dataType.c_str());
  XMC_DEBUG("nSamples  is %ld\n", nSamples);
  XMC_DEBUG("fc        is %f\n", fc);
  XMC_DEBUG("amp       is %f\n", amp);
  XMC_DEBUG("phs       is %f\n", phs);
  XMC_DEBUG("fs        is %f\n", fs);

  // Set up the output file header.
  //---------------------------------------------------------------------------------------------
  CPHEADER oHeader;
  m_initialize(oHeader);
  oHeader.file_name = oFileName;
  oHeader.type      = 1000;
  //oHeader.format    = "SF";
  oHeader.size      = nSamples;
  oHeader.xstart    = 0;
  oHeader.xdelta    = 1/fs;
  oHeader.xunits    = 1;
  if     ( (dataType == "SB") || (dataType == "INT08")  ) oHeader.format = "SB";
  else if( (dataType == "SI") || (dataType == "INT16")  ) oHeader.format = "SI";
  else if( (dataType == "SL") || (dataType == "INT32")  ) oHeader.format = "SL";
  else if( (dataType == "SF") || (dataType == "FLT32")  ) oHeader.format = "SF";
  else if( (dataType == "SD") || (dataType == "FLT64")  ) oHeader.format = "SD";
  else if( (dataType == "CB") || (dataType == "CINT08") ) oHeader.format = "CB";
  else if( (dataType == "CL") || (dataType == "CINT16") ) oHeader.format = "CI";
  else if( (dataType == "CD") || (dataType == "CINT32") ) oHeader.format = "CL";
  else if( (dataType == "CF") || (dataType == "CFLT32") ) oHeader.format = "CF";
  else if( (dataType == "CD") || (dataType == "CFLT64") ) oHeader.format = "CD";
  else                                                    oHeader.format = "SF";
  m_allocate(oHeader);

  // Get the transfer length (BYTES) or transfer samples.  Default to 256k if not present.
  //---------------------------------------------------------------------------------------------
  if(m_get_pswitch("TL"))                 // Test for Transfer length.
  {                                       //
    xferLngth = m_get_switch("TL");       // Get transfer length (Bytes).
    xferSamps = xferLngth/oHeader.bpe;    // Calculate transfer samples.
  }
  else if(m_get_pswitch("TS"))            // Test for Transfer samples.
  {                                       //
    xferSamps = m_get_switch("TS");       // Get transfer samples.
    xferLngth = xferSamps*oHeader.bpe;    // Convert to transfer length (Bytes).
  }
  else                                    // Else
  {                                       //
    xferLngth = 262144;                   // Default to 256k bytes.
    xferSamps = xferLngth/oHeader.bpe;    // Calculate transfer samples.
    if(xferSamps>nSamples)
    {
      xferSamps = nSamples;
      xferSamps = xferSamps;
      xferLngth = xferSamps*oHeader.bpe;
    }
  }
  XMC_DEBUG("xferLngth   is %ld\n",xferLngth);
  XMC_DEBUG("xferSamps   is %ld\n",xferSamps);
  XMC_DEBUG("oHeader.bpe is %d\n" ,oHeader.bpe);

  // Set the transfer length variable in the output header.
  //---------------------------------------------------------------------------------------------
  oHeader.xfer_len = xferSamps;
  oHeader.cons_len = -1;

  // Set the generic copy function based on input data type.
  //---------------------------------------------------------------------------------------------
  if      ( strncmp(&oHeader.format.buf[0], "SB", 2)==0 )
  {
    xccGenericSigGen = xccSigGenSinINT08;
  }
  else if ( strncmp(&oHeader.format.buf[0], "SI", 2)==0 )
  {
    xccGenericSigGen = xccSigGenSinINT16;
  }
  else if ( strncmp(&oHeader.format.buf[0], "SL", 2)==0 )
  {
    xccGenericSigGen = xccSigGenSinINT32;
  }
  else if ( strncmp(&oHeader.format.buf[0], "SF", 2)==0 )
  {
    xccGenericSigGen = xccSigGenSinFLT32;
  }
  else if ( strncmp(&oHeader.format.buf[0], "SD", 2)==0 )
  {
    xccGenericSigGen = xccSigGenSinFLT64;
  }
  else if ( strncmp(&oHeader.format.buf[0], "CB", 2)==0 )
  {
    xccGenericSigGen = xccSigGenCosSinCINT08;
  }
  else if ( strncmp(&oHeader.format.buf[0], "CI", 2)==0 )
  {
    xccGenericSigGen = xccSigGenCosSinCINT16;
  }
  else if ( strncmp(&oHeader.format.buf[0], "CL", 2)==0 )
  {
    xccGenericSigGen = xccSigGenCosSinCINT32;
  }
  else if ( strncmp(&oHeader.format.buf[0], "CF", 2)==0 )
  {
    xccGenericSigGen = xccSigGenCosSinCFLT32;
  }
  else if ( strncmp(&oHeader.format.buf[0], "CD", 2)==0 )
  {
    xccGenericSigGen = xccSigGenCosSinCFLT64;
  }
  else
  {
    XMC_ERROR_STDOUT("UNSUPPORTED DATA TYPE.\n"); //We should never get here because of m_inok(oHeader);
    exit(0);
  }
  XMC_DEBUG("Output file format is %s\n", oHeader.format.buf);

  // Setup the signal generation specs.
  //---------------------------------------------------------------------------------------------
  sigSpec = xccSigGenInitFLT64(fc, fs, amp, phs);
  
  // Allocate data buffer for signals.
  //---------------------------------------------------------------------------------------------
  oDataINT08 = (INT08 *) xccMallocINT08_Align032(xferLngth);

  // "Synchronize" not "sink".
  //---------------------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG("Calling m_sync();\n");

  // Process.
  //---------------------------------------------------------------------------------------------
  m_todo(oHeader.size);
  while( m_do(xferSamps, nDo) )
  {
    xccGenericSigGen(oDataINT08, 1, xferSamps, sigSpec );
    m_filad(oHeader, oDataINT08, nDo);
  }

  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  xmcFree(sigSpec);
  xmcFree(oDataINT08);
  m_close(oHeader);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/

/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
