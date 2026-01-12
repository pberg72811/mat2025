/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: iccpattern.cc                                                                          -
//                                                                                              -
// Desc: This primitive takes the first N samples and looks for repetition.                     -
//                                                                                              -
// Args: iFileName  - The name of the input file.        <A:>                                   -
//       nSamples   - Number of samples of pattern.      <L:>                                   -
//       nSlipsRes  - Results label for number of slips. <A:>                                   -
//                                                                                              -
// Swch: TL        - Switch to set transfer length.                                             -
//       TS        - Switch to set transfer samples.                                            -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       12/22/2005 ptb  Initial Code.                                                          -
//                                                                                              -
//                           iFileName                                                          -
//                           nSamples                                                           -
//                           nSlipsRes                                                          -
//                           /TL                                                                -
//                           /TS                                                                -
//                             |                                                                -
//                             V                                                                -
//    :-----------:     :---------------:     :--------:                                        -
//    | FILE/PIPE |---> | iccpattern.cc |---> | RESULT |                                        -
//    :-----------:     :---------------:     :--------:                                        -
//                             |                                                                -
//                             V                                                                -
//                      Debug Statements                                                        -
//                                                                                              -
// Note:                                                                                        -
//                                                                                              -
// Examples: iccpattern test_data1 32   N_SLIPS                                                 -
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

#define WRITE_PREVIOUS 1
#define WRITE_ZEROS    2

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
  INT32 jj;
  int_4 nGot;
  INT32 nSlips=0;
  INT32 nLoops;
  INT32 nSamples;
  INT32 nChunks=0;
  INT32 sumINT32;
  INT32 firstTimeFlag=TRUE;
  INT08 *iDataINT08;
  INT08 *pDataINT08;

  // Switch variables.
  INT32 xferLngth;
  INT32 xferSamps;

  // Result variables.
  string nSlipsRes;

  // File name variables.
  string iFileName;
  string oFileName;

  // Get command line parameters.
  //---------------------------------------------------------------------------------------------
  iFileName = m_apick(1);
  nSamples  = (INT32)m_dpick(2);
  nSlipsRes = m_apick(3);
  XMC_DEBUG("iFileName is %s\n", iFileName.c_str());
  XMC_DEBUG("nSamples  is %d\n", nSamples);
  XMC_DEBUG("nSlipsRes is %s\n", nSlipsRes.c_str());

  // Set up the input file header.
  //---------------------------------------------------------------------------------------------
  CPHEADER iHeader;                                           //
  iHeader.file_name    = iFileName;                           //
  iHeader.type_allow   = "1000,2000,3000,5000";               //
  iHeader.format_allow = "SB,SI,SL,SF,SD,CB,CI,CL,CF,CD";     //
  m_inok(iHeader);                                            //

  // Get the transfer length (BYTES) or transfer samples.  Default to 256k if not present.
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
    xferLngth = 262144;                       // Default to 256k bytes.                         -
    xferSamps = xferLngth/iHeader.bpe;        // Calculate transfer samples.                    -
  }                                           //-------------------------------------------------
  if( (xferLngth%nSamples) != 0 )
  {
    xferLngth = xferLngth - (xferLngth%nSamples);
    xferLngth = xferLngth + nSamples*(xferLngth<0);
    xferSamps = xferLngth/iHeader.bpe;
    XMC_ERROR_STDOUT("xferLngth not multiple of nSamples\n");
    sleep(1);
  }
  nGot = xferSamps;
  XMC_DEBUG("nGot        is %d\n", nGot);
  XMC_DEBUG("xferLngth   is %ld\n",xferLngth);
  XMC_DEBUG("xferSamps   is %ld\n",xferSamps);
  XMC_DEBUG("iHeader.bpe is %d\n" ,iHeader.bpe);

  // Set the transfer length variable in the output header.
  //---------------------------------------------------------------------------------------------
  iHeader.xfer_len = xferSamps;
  iHeader.cons_len = -1;

  // Initialize input buffer.
  //---------------------------------------------------------------------------------------------
  iDataINT08 = iccMallocINT08_Align032(xferLngth);
  pDataINT08 = iccMallocINT08_Align032(nSamples*iHeader.bpe);
  iccvZeroINT08( iDataINT08, 1, xferLngth );
  iccvZeroINT08( pDataINT08, 1, nSamples*iHeader.bpe );
 
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

    // Calculate number of loops of nSamples to process.
    //-------------------------------------------------------------------------------------------
    nLoops = nGot/nSamples;

    // For each loop...
    //-------------------------------------------------------------------------------------------
    for(ii = 0; ii < nLoops; ii++)
    {

      // Handle first time case and initialize pattern.
      //-----------------------------------------------------------------------------------------
      if (firstTimeFlag)                                       // If first time                 -
      {                                                        //                               -
                                                               //                               -
	for(jj = 0; jj < nSamples*iHeader.bpe; jj++)           //                               -
	{                                                      //                               -
	  pDataINT08[jj] = iDataINT08[jj];                     // Initialize the pattern.       -
	}                                                      //                               -
                                                               //                               -
	firstTimeFlag = FALSE;                                 // Set first time flag to false. -
      }                                                        //--------------------------------

      // Perform the pattern check.
      //-----------------------------------------------------------------------------------------
      sumINT32 = 0;                                            // Clear the summation value,    -
      for(jj = 0; jj < nSamples*iHeader.bpe; jj++)             // loop for each 8 bit value     -
      {                                                        //                               -
	sumINT32 = sumINT32 + pDataINT08[jj] -                 //
	           iDataINT08[ii*nSamples*iHeader.bpe+jj];     // and check pattern.            -
      }                                                        //--------------------------------

      // Handle pattern slip.
      //-----------------------------------------------------------------------------------------
      if (sumINT32 != 0)                                       // If the summation value        -
      {                                                        // is not zero we have a slip.   -
	XMC_ERROR_STDOUT("Pattern slip in # %ld of %ld bytes or %ld samples.\n",           
			 nChunks,nSamples*iHeader.bpe,nSamples); // Print message.              -
	nSlips++;                                              // Increment the slip counter.   -
	m_lrslt(nSlipsRes, nSlips);                            // Post the slip result.         -
	firstTimeFlag = TRUE;                                  // Reset first time flag to      -
      }                                                        // sync up to pattern.           -     
      nChunks++;
    }
  }

  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  m_lrslt(nSlipsRes, nSlips);                                  // Post the slip result.         -
  m_close(iHeader);
  xmcFree(iDataINT08);
  xmcFree(pDataINT08);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/

