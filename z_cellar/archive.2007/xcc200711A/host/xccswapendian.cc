/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccswapendian.cc                                                                       -
//                                                                                              -
// Desc: This primitive performs big endian or little endian conversion.                        -
//                                                                                              -
// Args: iFileName  - The name of the input file.  <A:>                                         -
//       oFileName  - The name of the output file. <A:>                                         -
//                                                                                              -
// Swch: TL         - Switch to set transfer length.                                            -
//       TS         - Switch to set transfer samples.                                           -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       05/05/2005 ptb  Initial Code.                                                          -
//                                                                                              -
//                        iFileName                                                             -
//                        oFileName                                                             -
//                        /TL                                                                   -
//                        /TS                                                                   -
//                          |                                                                   -
//                          V                                                                   -
//    :---------:     :------------:     :---------:                                            -
//    |FILE/PIPE|---> |xccendian.cc|---> |FILE/PIPE|                                            -
//    :---------:     :------------:     :---------:                                            -
//                          |                                                                   -
//                          V                                                                   -
//                    Debug Statements                                                          -
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
#include "vector_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG      TRUE
#define DEBUG_TYPE XMC_DEBUG_STDOUT
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
  int_4 nGot;
  INT32 xferLngth;
  INT32 xferSamps;
  INT08 *iDataINT08;
  INT08 *oDataINT08;
  //CHR08 tempString[32];

  // File header structures.
  CPHEADER iHeader;
  CPHEADER oHeader;

  // File names.
  string iFileName;
  string oFileName;
  string direction;

  VOID (*genericEndian)(VOID *, INT32, VOID *, INT32, UNT32);

  INT32 complexFlag;

  // Get command line parameters.
  //---------------------------------------------------------------------------------------------
  iFileName  = m_apick(1);
  oFileName  = m_apick(2);
  XMC_DEBUG("iFileName  is %s\n", iFileName.c_str());
  XMC_DEBUG("oFileName  is %s\n", oFileName.c_str());

  // Set up the input file header.
  //---------------------------------------------------------------------------------------------
  iHeader.file_name    = iFileName;
  iHeader.type_allow   = "1000";
  iHeader.format_allow = "SI,SL,SF,SD,CB,CI,CL,CF,CD";
  m_inok(iHeader);

  // Get the transfer length (BYTES) or transfer samples.  Default to 256k if not present.
  //---------------------------------------------------------------------------------------------
  if(m_get_pswitch("TL"))                        // Test for Transfer length.                   -
  {                                              //                                             -
    xferLngth = m_get_switch("TL");              // Get transfer length (Bytes).                -
    xferSamps = xferLngth/iHeader.bpe;           // Calculate transfer samples.                 -
  }                                              //                                             -
  else if(m_get_pswitch("TS"))                   // Test for Transfer samples.                  -
  {                                              //                                             -
    xferSamps = m_get_switch("TS");              // Get transfer samples.                       -
    xferLngth = xferSamps*iHeader.bpe;           // Convert to transfer length (Bytes).         -
  }                                              //                                             -
  else                                           // Else                                        -
  {                                              //                                             -
    xferLngth = 262144;                          // Default to 256k bytes.                      -
    xferSamps = xferLngth/iHeader.bpe;           // Calculate transfer samples.                 -
  }                                              //                                             -
  nGot = xferSamps;                              // Prepare nGot for Processing loop.           -
  XMC_DEBUG("xferLngth   is %ld\n",xferLngth);   //                                             -
  XMC_DEBUG("xferSamps   is %ld\n",xferSamps);   //                                             -
  XMC_DEBUG("nGot        is %ld\n",xferSamps);   //                                             -
  XMC_DEBUG("iHeader.bpe is %d\n" ,iHeader.bpe); //                                             -

  // Set the transfer length variable in the input header.
  //---------------------------------------------------------------------------------------------
  iHeader.xfer_len = xferSamps;
  iHeader.cons_len = -1;

  // Propagate input header structure to output header structure.
  //---------------------------------------------------------------------------------------------
  m_propagate(iHeader,oHeader);
  oHeader.file_name = oFileName;
  m_allocate(oHeader);

  // Set the generic endian function.
  //---------------------------------------------------------------------------------------------
  if     ( strncmp(&iHeader.format.buf[0], "SI", 2)==0 )
  {
    genericEndian = xccvSwapEndianINT16;
    complexFlag=1;
  }
  else if( strncmp(&iHeader.format.buf[0], "SL", 2)==0 )
  {
    genericEndian = xccvSwapEndianINT32;
    complexFlag=1;
  }
  else if( strncmp(&iHeader.format.buf[0], "SF", 2)==0 )
  {
    genericEndian = xccvSwapEndianINT32;
    complexFlag=1;
  }
  else if( strncmp(&iHeader.format.buf[0], "SD", 2)==0 )
  {
    genericEndian = xccvSwapEndianINT64;
    complexFlag=1;
  }
  else if( strncmp(&iHeader.format.buf[0], "CI", 2)==0 )
  {
    genericEndian = xccvSwapEndianINT16;
    complexFlag=2;
  }
  else if( strncmp(&iHeader.format.buf[0], "CL", 2)==0 )
  {
    genericEndian = xccvSwapEndianINT32;
    complexFlag=2;
  }
  else if( strncmp(&iHeader.format.buf[0], "CF", 2)==0 )
  {
    genericEndian = xccvSwapEndianINT32;
    complexFlag=2;
  }
  else if( strncmp(&iHeader.format.buf[0], "CD", 2)==0 )
  {
    genericEndian = xccvSwapEndianINT64;
    complexFlag=2;
  }
  else
  {
    //We should never get here because of m_inok(iHeader);
    XMC_ERROR_STDERR("UNSUPPORTED DATA TYPE.");
    exit(0);
  }
  XMC_DEBUG("Input file format is %s\n", iHeader.format.buf);

  // xccendian init.
  //---------------------------------------------------------------------------------------------
  iDataINT08  = xccMallocINT08_Align032 ( xferLngth ); // Generic input  not just INT08.
  oDataINT08  = xccMallocINT08_Align032 ( xferLngth ); // Generic output not just INT08.

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

    // Perform Endian conversion.
    //-------------------------------------------------------------------------------------------
    genericEndian((VOID *)iDataINT08, 1, (VOID *)oDataINT08, 1, xferSamps*complexFlag);

    // Write out the output data.
    //-------------------------------------------------------------------------------------------
    m_filad(oHeader, oDataINT08, xferSamps);
  }

  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  xmcFree(iDataINT08);
  m_close(iHeader);
  m_close(oHeader);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
