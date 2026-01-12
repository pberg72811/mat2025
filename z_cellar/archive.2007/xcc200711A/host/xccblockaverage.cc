/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccblockaverage.cc                                                                     -
//                                                                                              -
// Desc: This primitive averages blocks of data.                                                -
//                                                                                              -
// Args: iFileName  - The name of the input file.                                               -
//       oFileName  - The name of the output file.                                              -
//                                                                                              -
// Swch: /TL - Transfer length.                                                                 -
//       /TS - Transfer samples.                                                                -
//                                                                                              - 
// Hist: When       Who  What                                                                   -
//       05/12/2004 ptb  Initial Code.                                                          -
//                                                                                              -
//                             iFileName                                                        -
//                             oFileName                                                        -
//                             /TL                                                              -
//                             /TS                                                              -
//                               |                                                              -
//                               V                                                              -
//    :-----------:     :--------------------:     :-----------:                                -
//    | FILE/PIPE |---> | xccblockaverage.cc |---> | FILE/PIPE |                                -
//    :-----------:     :--------------------:     :-----------:                                -
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
  UNT32 xferLngth;
  UNT32 xferSamps;
  int_4 nGot;
  UNT32 blockSize;
  INT08 *inDataINT08;
  CFLT64 *inDataCFLT64;
  CFLT64 meanValueCFLT64;
  string iFileName;
  string oFileName;
  string stringTemp;

  VOID (*genericToCFLT64)(VOID *, INT32, CFLT64 *, INT32, UNT32);

  // Get command line parameters.
  //-------------------------------------------------------------------------------
  iFileName  = m_apick(1);
  oFileName  = m_apick(2);
  blockSize  = (UNT32) m_dpick(3);
  XMC_DEBUG("iFileName  is %s\n", iFileName.c_str());
  XMC_DEBUG("oFileName  is %s\n", oFileName.c_str());
  XMC_DEBUG("blockSize  is %ld\n", blockSize);

  // Set up the input file header.
  //-------------------------------------------------------------------------------
  CPHEADER iHeader;
  iHeader.file_name    = iFileName;
  iHeader.type_allow   = "1000";
  iHeader.format_allow = "SB,SI,SL,SF,CB,CI,CL,CF,CD";
  m_inok(iHeader);

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
  xferSamps = blockSize;
  xferLngth = xferSamps*iHeader.bpe;
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
  oHeader.format    = "SD";
  oHeader.size      = iHeader.size/blockSize;
  oHeader.xstart    = iHeader.xstart;
  oHeader.xdelta    = iHeader.xdelta*xferSamps;
  oHeader.xunits    = 1;
  if( strncmp(&iHeader.format.buf[0], "C", 1)==0 ) oHeader.format = "CD";
  m_allocate(oHeader);

  // Set the generic conversion function based on input data type.
  //-------------------------------------------------------------------------------
  if      ( strncmp(&iHeader.format.buf[0], "SB", 2)==0 )
  {
    genericToCFLT64 = xccvINT08ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SI", 2)==0 )
  {
    genericToCFLT64 = xccvINT16ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SL", 2)==0 )
  {
    genericToCFLT64 = xccvINT32ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SF", 2)==0 )
  {
    genericToCFLT64 = xccvFLT32ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CB", 2)==0 )
  {
    genericToCFLT64 = xccvCINT08ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CI", 2)==0 )
  {
    genericToCFLT64 = xccvCINT16ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CL", 2)==0 )
  {
    genericToCFLT64 = xccvCINT32ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CF", 2)==0 )
  {
    genericToCFLT64 = xccvCFLT32ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CD", 2)==0 )
  {
    genericToCFLT64 = xccvCFLT64ToCFLT64;
  }
  else
  {
    printf("UNSUPPORTED DATA TYPE.\n"); //We should never get here because of m_inok(iHeader);
    exit(0);
  }
  XMC_DEBUG("Input file format is %s\n", iHeader.format.buf);

  // xccphasedetect init.
  //-------------------------------------------------------------------------------
  inDataINT08  = xccMallocINT08_Align032( xferLngth );
  inDataCFLT64 = xccMallocCFLT64_Align032( xferSamps );

  XMC_DEBUG("Done with init.\n");

  // "Synchronize" not "sink".
  //-------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG("Calling m_sync();\n");

  // Start the processing loop.
  //-------------------------------------------------------------------------------
  while( (nGot==(INT32)xferSamps) && (!Mc->break_) )
  {
    // Grab the input data.
    //-------------------------------------------------------------------------------
    m_grabx(iHeader, inDataINT08, nGot);

    // Convert to CFLT64.
    //-------------------------------------------------------------------------------
    genericToCFLT64((VOID *)inDataINT08, 1, inDataCFLT64, 1, xferSamps);

    // Average.
    //-------------------------------------------------------------------------------
    meanValueCFLT64 = xccvMeanCFLT64( inDataCFLT64, 1, xferSamps );

    // Write out the output data.
    //-------------------------------------------------------------------------------
    m_filad(oHeader, &meanValueCFLT64, 1);
  }

  // Terminate and return.
  //-------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  xmcFree(inDataINT08);
  xmcFree(inDataCFLT64);

  m_close(iHeader);
  m_close(oHeader);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*-------------------------------UNCLASSIFIED---------------------------------*/
