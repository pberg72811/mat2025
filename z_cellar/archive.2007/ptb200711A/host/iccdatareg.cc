/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: iccdatareg.cc                                                                          -
//                                                                                              -
// Desc: This primitive regulates the data going through it.                                    -
//       This primitive will regulate relatively low rate data.  This routine                   -
//       will either write out previous data or zero fill depending on the mode                 -
//       chosen.                                                                                -
//       Mode equal one will write previous data.                                               -
//       Mode equal two will write out zeros                                                    -
//                                                                                              -
// Args: iFileName - The name of the input file.      <A:>                                      -
//       oFileName - The name of the output file      <A:>                                      -
//       mode      - Mode.                            <L:>                                      -
//                                                                                              -
// Swch: TL        - Switch to set transfer length.                                             -
//       TS        - Switch to set transfer samples.                                            -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       12/22/2005 ptb  Initial Code.                                                          -
//                                                                                              -
//                           iFileName                                                          -
//                           oFileName                                                          -
//                           mode                                                               -
//                           /TL                                                                -
//                           /TS                                                                -
//                             |                                                                -
//                             V                                                                -
//    :-----------:     :---------------:     :-----------:                                     -
//    | FILE/PIPE |---> | iccdatareg.cc |---> | FILE/PIPE |                                     -
//    :-----------:     :---------------:     :-----------:                                     -
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
  int_4 nGot;
  INT08 mode;
  UNT32 difTime;
  INT32 number1=1;
  INT08 *iDataINT08;
  INT08 *pDataINT08;
  INT08 *zDataINT08;
  FLT64 bytesPerSec=0.0;
  UNT64 realTotalBytes=0;
  UNT64 calcTotalBytes=0;
  struct timeval theTime;
  struct timeval lasTime;
  struct timeval startTime;
  struct timezone junk;

  // Switch variables.
  INT32 xferLngth;
  INT32 xferSamps;

  // File name variables.
  string iFileName;
  string oFileName;

  // Get command line parameters.
  //---------------------------------------------------------------------------------------------
  iFileName = m_apick(1);
  oFileName = m_apick(2);
  mode      = (INT08)m_dpick(3);
  XMC_DEBUG("iFileName is %s\n", iFileName.c_str());
  XMC_DEBUG("oFileName is %s\n", oFileName.c_str());
  XMC_DEBUG("Mode      is %d\n", mode);

  // Set up the input file header.
  //---------------------------------------------------------------------------------------------
  CPHEADER iHeader;                                           //
  iHeader.file_name    = iFileName;                           //
  iHeader.type_allow   = "1000,2000,3000,5000";               //
  iHeader.format_allow = "SB,SI,SL,SF,SD,CB,CI,CL,CF,CD";     //
  m_inok(iHeader);                                            //

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
    xferLngth = 262144;                       // Default to 256k bytes.                         -
    xferSamps = xferLngth/iHeader.bpe;        // Calculate transfer samples.                    -
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
  m_allocate(oHeader);

  // Initialize input buffer.
  //---------------------------------------------------------------------------------------------
  iDataINT08 = iccMallocINT08_Align032(xferLngth);
  pDataINT08 = iccMallocINT08_Align032(xferLngth);
  zDataINT08 = iccMallocINT08_Align032(xferLngth);
  iccvZeroINT08( iDataINT08, 1, xferLngth );
  iccvZeroINT08( pDataINT08, 1, xferLngth );
  iccvZeroINT08( zDataINT08, 1, xferLngth );

  // Calculate bytes per second.
  //---------------------------------------------------------------------------------------------
  bytesPerSec = iHeader.xdelta * ((FLT64)iHeader.bpe); 
 
  XMC_DEBUG("Done with init.\n");

  // "Synchronize" not "sink".
  //---------------------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG("Calling m_sync();\n");

  // Get start time.
  //---------------------------------------------------------------------------------------------
  gettimeofday(&startTime, &junk);

  // Processing loop.
  //---------------------------------------------------------------------------------------------
  while((nGot==xferSamps) && !Mc->break_)
  {

    // Copy the previous data.
    //-------------------------------------------------------------------------------------------
    iccvCopyINT08(iDataINT08, 1, pDataINT08, 1, nGot*iHeader.bpe);

    // Grab the new input data.
    //-------------------------------------------------------------------------------------------
    m_grabx(iHeader, iDataINT08, nGot);

    realTotalBytes += (UNT64)(nGot*iHeader.bpe);

    // Save time of last grab.
    //-------------------------------------------------------------------------------------------
    lasTime = theTime;

    // Get time of this grab.
    //-------------------------------------------------------------------------------------------
    gettimeofday(&theTime, &junk);

    difTime = theTime.tv_sec - startTime.tv_sec;

    calcTotalBytes = (UNT64)(difTime * bytesPerSec + nGot*iHeader.bpe);

    XMC_DEBUG("theTime.tv_sec   is %ld\n",theTime.tv_sec);
    XMC_DEBUG("startTime.tv_sec is %ld\n",startTime.tv_sec);
    XMC_DEBUG("calcTotalBytes   is %lld\n",calcTotalBytes);
    XMC_DEBUG("realTotalBytes   is %lld\n",realTotalBytes);
    XMC_DEBUG("bytesPerSec      is %f\n", bytesPerSec);
    XMC_DEBUG("iHeader.bpe      is %ld\n",iHeader.bpe);
    XMC_DEBUG("nGot             is %ld\n",nGot);

    // Write out the "previous" data.
    //-------------------------------------------------------------------------------------------
    while ((calcTotalBytes > realTotalBytes ) && (mode == WRITE_PREVIOUS))
    {
      m_filad(oHeader, pDataINT08, xferSamps);                   // Write out the previous data.-
                                                                 //                             -
      if(!oHeader.pipe)                                          // If not piped                -
      {                                                          //                             -
	m_hcbfunc(oHeader, HCBF_FLUSH, (int_4 *) &number1);      // Flush the HCB to update     -
      }                                                          // output file.                -
      realTotalBytes += (UNT64)(xferSamps*iHeader.bpe);          //                             -
      XMC_DEBUG("WRITE_PREVIOUS\n");
    }

    // Write out the "zero" data.
    //-------------------------------------------------------------------------------------------
    while ((calcTotalBytes > realTotalBytes ) && (mode == WRITE_ZEROS))
    {
      m_filad(oHeader, zDataINT08, nGot);                        // Write out the zero data.    -
                                                                 //                             -
      if(!oHeader.pipe)                                          // If not piped                -
      {                                                          //                             -
	m_hcbfunc(oHeader, HCBF_FLUSH, (int_4 *) &number1);      // Flush the HCB to update     -
      }                                                          // output file.                -
      realTotalBytes += (UNT64)(xferSamps*iHeader.bpe);
      XMC_DEBUG("WRITE_ZEROS\n");
    }

    // Write out the "normal" data.
    //-------------------------------------------------------------------------------------------
    m_filad(oHeader, iDataINT08, nGot);                          // Write out the normal data.  -
                                                                 //                             -
    if(!oHeader.pipe)                                            // If not piped                -
    {                                                            //                             -
      m_hcbfunc(oHeader, HCBF_FLUSH, (int_4 *) &number1);        // Flush the HCB to update     -
    }                                                            // output file.                -

  }

  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  m_close(iHeader);
  m_close(oHeader);
  xmcFree(iDataINT08);
  xmcFree(pDataINT08);
  xmcFree(zDataINT08);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/

