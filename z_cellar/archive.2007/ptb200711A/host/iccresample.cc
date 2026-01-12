/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: iccresample.cc                                                                         -
//                                                                                              -
// Desc: This primitive does a non-interpolating resample of data.                              -
//                                                                                              -
// Args: iFileName    - The name of the input file.      <A:>                                   -
//       oFileName    - The name of the output file      <A:>                                   -
//       newSampRate  - New sample rate.                 <D:>                                   -
//                                                                                              -
// Swch: TL        - Switch to set transfer length.                                             -
//       TS        - Switch to set transfer samples.                                            -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       09/21/2006 ptb  Initial Code.                                                          -
//                                                                                              -
//                           iFileName                                                          -
//                           oFileName                                                          -
//                           newSampRate                                                        -
//                           /TL                                                                -
//                           /TS                                                                -
//                             |                                                                -
//                             V                                                                -
//    :-----------:     :----------------:     :-----------:                                    -
//    | FILE/PIPE |---> | iccresample.cc |---> | FILE/PIPE |                                    -
//    :-----------:     :----------------:     :-----------:                                    -
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
#include "dsp_utils.h"
#include "malloc_utils.h"
#include "orbit_utils.h"
#include "socket_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG      TRUE
#define DEBUG_HOST  "192.9.214.113"
#define DEBUG_PORT  5001
#define DEBUG_TYPE  XMC_DEBUG_STDOUT
//#define DEBUG_TYPE DEBUG_STDOUT_FILE
#define XMC_DEBUG  if( DEBUG ) DEBUG_TYPE

#define BLOCK_SIZE_BYTES (256*1024)

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
  FLT64 fsNew;
  FLT64 fsOld;
  INT32 ii;
  int_4 nGot;
  INT32 nBlocks;
  FLT64 newSampRate;
  UNT32 oSampleTotl;
  INT08 *iDataINT08;
  INT08 *oDataINT08;
  INT32 oSampleLeft;
  INT32 blockSizeSamples;
  iccResampleSpec *spec;

  // Switch variables.
  INT32 xferLngth;
  INT32 xferSamps;

  // File name variables.
  string iFileName;
  string oFileName;

  // Generic function.
  VOID (*genericResample)(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );

  // Get command line parameters.
  //---------------------------------------------------------------------------------------------
  iFileName  = m_apick(1);
  oFileName  = m_apick(2);
  newSampRate = m_dpick(3);
  XMC_DEBUG("iFileName   is %s\n", iFileName.c_str());
  XMC_DEBUG("oFileName   is %s\n", oFileName.c_str());
  XMC_DEBUG("newSampRate is %f\n", newSampRate);

  // Set up the input file header.
  //---------------------------------------------------------------------------------------------
  CPHEADER iHeader;                                           //
  iHeader.file_name    = iFileName;                           //
  iHeader.type_allow   = "1000,2000,3000,5000";               //
  iHeader.format_allow = "SB,SI,SL,SF,SD,CB,CI,CL,CF,CD";     //
  m_inok(iHeader);                                            //

  // Get the sample rate of the input file.
  //---------------------------------------------------------------------------------------------
  fsOld = 1.0/iHeader.xdelta;
  fsNew = newSampRate;

  // Set the generic conversion function based on input data type.
  //-------------------------------------------------------------------------------
  if      ( strncmp(&iHeader.format.buf[0], "SB", 2)==0 )
  {
    genericResample = iccResampleINT08;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SI", 2)==0 )
  {
    genericResample = iccResampleINT16;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SL", 2)==0 )
  {
    genericResample = iccResampleINT32;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SF", 2)==0 )
  {
    genericResample = iccResampleFLT32;
  }
  else if ( strncmp(&iHeader.format.buf[0], "SD", 2)==0 )
  {
    genericResample = iccResampleFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CB", 2)==0 )
  {
    genericResample = iccResampleINT08;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CI", 2)==0 )
  {
    genericResample = iccResampleINT16;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CL", 2)==0 )
  {
    genericResample = iccResampleINT32;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CF", 2)==0 )
  {
    genericResample = iccResampleFLT32;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CD", 2)==0 )
  {
    genericResample = iccResampleFLT64;
  }
  else  //We should never get here because of m_inok(iHeader);
  {
    XMC_ERROR_STDOUT("UNSUPPORTED DATA TYPE.\n");
    exit(0);
  }
  XMC_DEBUG("Input file format is %s\n", iHeader.format.buf);

  // Look for transfer length (BYTES) or transfer samples switches.
  //---------------------------------------------------------------------------------------------
  if(m_get_pswitch("TL"))                     // Test for Transfer length.                      -
  {                                           //                                                -
    xferLngth = m_get_switch("TL");           // Get transfer length (Bytes).                   -
    xferSamps = xferLngth/iHeader.bpe;        // Calculate transfer samples.                    -
  }                                           //                                                -
  else if(m_get_pswitch("TS"))                // Test for Transfer samples.                     -
  {                                           //                                                -
    xferSamps = m_get_switch("TS");           // Get transfer samples.                          -
    xferLngth = xferSamps*iHeader.bpe;        // Convert to transfer length (Bytes).            -
  }                                           //                                                -
  else                                        // Else                                           -
  {                                           //                                                -
    if(iHeader.size<128*1024*1024)            // If input samples less then 128 Msamples,       -
    {                                         // Then                                           -
      xferSamps = iHeader.size;               // Set transfer samples to total input file size. -
      xferLngth = xferSamps*iHeader.bpe;      // Convert to transfer length (Bytes).            -
    }                                         //                                                -
    else                                      //                                                -
    {                                         //                                                -
      xferLngth = 262144;                     // Default to 256k bytes.                         -
      xferSamps = xferLngth/iHeader.bpe;      // Calculate transfer samples.                    -
    }                                         //                                                -
  }                                           //-------------------------------------------------
  XMC_DEBUG("xferLngth   is %ld\n",xferLngth);
  XMC_DEBUG("xferSamps   is %ld\n",xferSamps);
  XMC_DEBUG("iHeader.bpe is %d\n" ,iHeader.bpe);

  // Set the transfer length variable in the input header.
  //---------------------------------------------------------------------------------------------
  iHeader.xfer_len = xferSamps;
  iHeader.cons_len = -1;

  nGot = xferSamps;

  // Set up the output file header.
  //---------------------------------------------------------------------------------------------
  CPHEADER oHeader;
  m_propagate(iHeader, oHeader);
  oHeader.file_name = oFileName;
  oHeader.xdelta    = 1.0/fsNew;
  m_allocate(oHeader);

  // Initialize input and output buffers.
  //---------------------------------------------------------------------------------------------
  iDataINT08 = iccMallocINT08_Align032(xferLngth);
  oDataINT08 = iccMallocINT08_Align032(BLOCK_SIZE_BYTES);
  iccvZeroINT08( iDataINT08, 1, xferLngth );
  iccvZeroINT08( oDataINT08, 1, BLOCK_SIZE_BYTES );

  // Initialize the non-interpolating resampler.
  //---------------------------------------------------------------------------------------------
  spec = iccResampleInit(fsOld, fsNew, 0.0, xferSamps);

  oSampleTotl      = iHeader.size*fsNew/fsOld;
  blockSizeSamples = BLOCK_SIZE_BYTES/iHeader.bpe;
  nBlocks          = (INT32)(oSampleTotl/blockSizeSamples);
  oSampleLeft      = oSampleTotl - (nBlocks*blockSizeSamples);

  XMC_DEBUG("Done with init.\n");

  // "Synchronize" not "sink".
  //---------------------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG("Calling m_sync();\n");

  // Processing loop.
  //---------------------------------------------------------------------------------------------
  while((nGot==xferSamps) && !Mc->break_)
  {

    // Grab the new input data.
    //-------------------------------------------------------------------------------------------
    m_grabx(iHeader, iDataINT08, nGot);

    // Write out data.
    //-------------------------------------------------------------------------------------------
    for(ii=0; ii<nBlocks; ii++)
    {
      genericResample(iDataINT08, 1, oDataINT08, 1, blockSizeSamples, spec );
      m_filad(oHeader, oDataINT08, blockSizeSamples);
    }
    genericResample(iDataINT08, 1, oDataINT08, 1, oSampleLeft, spec );
    m_filad(oHeader, oDataINT08, oSampleLeft);

    nGot = 0;

  }

  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  m_close(iHeader);
  m_close(oHeader);
  xmcFree(iDataINT08);
  xmcFree(oDataINT08);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/

