/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: iccudpplay.cc                                                                          -
//                                                                                              -
// Desc: This primitive plays back UDP packets from type 1000 or 2000 files.                    -
//                                                                                              -
// Args: iFileName  - The name of the input file.                  <A:>                         -
//       packetSize - The packet size in bytes to be sent.         <D:>                         -
//       ipAddress  - The IP address to send the UDP packets to.   <A:>                         -
//       thePort    - The UDP port to send the UDP packets to.     <D:>                         -
//                                                                                              -
// Swch: PAUSE      - Switch to pause "N" seconds between sends.                                -
//       Replay     - Replay=2 causes play continous.  See "sourcefile".                        -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       06/13/2005 ptb  Initial Code.                                                          -
//       05/01/2006 ptb  Perform check on type 2000 files between packet size                   -
//                       and the frame length number of bytes (BPE).                            -
//       05/02/2006 ptb  Added play continuous mode.  Use /replay=2 switch.                     -
//                                                                                              -
//                        iFileName                                                             -
//                        packetSize                                                            -
//                        ipAddress                                                             -
//                        thePort                                                               -
//                        /Pause                                                                -
//                        /Replay                                                               -
//                          |                                                                   -
//                          V                                                                   -
//    :---------:     :-------------:     :--------:                                            -
//    |FILE/PIPE|---> |iccudpplay.cc|---> |NIC CARD|                                            -
//    :---------:     :-------------:     :--------:                                            -
//                          |                                                                   -
//                          V                                                                   -
//                    Debug Statements                                                          -
//                                                                                              -
// Note: SDDS data needs to be sent as packets of 1080 bytes.                                   -
//       Big endian little endian issues need to be delt with before this routine is called.    -
//       This routine runs in a non-blocking mode by default.                                   -
//       BFG common data is 7572 bytes per packet.                                              -
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
#define DEBUG1      TRUE
#define DEBUG2      TRUE
#define DEBUG_TYPE XMC_DEBUG_STDOUT
#define XMC_DEBUG1  if( DEBUG1 ) DEBUG_TYPE
#define XMC_DEBUG2  if( DEBUG2 ) DEBUG_TYPE

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
  INT32 nBytes;
  INT32 thePort;
  INT32 xferLngth;
  INT32 xferSamps;
  INT32 packetSize;
  INT08 *iDataINT08;

  iccDatagramSocketSpec *datagramSpec;

  // Switch variables.
  INT32 pauseFlag=FALSE;
  FLT32 pauseTime=0.000;
  INT32 replayValue=0;

  // File name variables.
  string iFilename;
  string ipAddress;

  // Get command line parameters.
  //---------------------------------------------------------------------------------------------
  iFilename  = m_apick(1);
  packetSize = m_lpick(2);
  ipAddress  = m_apick(3);
  thePort    = m_lpick(4);
  XMC_DEBUG1("iFilename  is %s\n",   iFilename.c_str());
  XMC_DEBUG1("packetSize is %ld\n", packetSize);
  XMC_DEBUG1("ipAddress  is %s\n",   ipAddress.c_str());
  XMC_DEBUG1("thePort    is %05ld\n",thePort);

  // Get the PAUSE switch if present.
  //---------------------------------------------------------------------------------------------
  if( m_get_pswitch("PAUSE") )                                // If there is a PAUSE switch.    -
  {                                                           //                                -
    pauseFlag = TRUE;                                         // Set the pause flag.            -   
    pauseTime = m_get_dswitch("PAUSE");                       // Get duration of pause          -
    XMC_DEBUG1("Setting pauseFlag flag.\n");                  //                                -
  }                                                           //                                -
  else                                                        // If no pause switch.            -
  {                                                           //                                -
    pauseFlag = False;                                        // Clear pause flag.              -
    XMC_DEBUG1("Clearing pauseFlag flag.\n");                 //                                -
  }                                                           //---------------------------------

  // Get the REPLAY switch if present.
  //---------------------------------------------------------------------------------------------
  if( m_get_pswitch("REPLAY") )                               // If there is a REPLAY switch.   -
  {                                                           //                                -
    replayValue = m_get_dswitch("REPLAY");                    // Get replay setting.            -
    XMC_DEBUG1("replayValue equal to %ld.\n",replayValue);    //                                -
    if(replayValue==2)                                        // We are only handling           -
    {                                                         // replayValue equals 2.          -
      XMC_DEBUG1("Replay continuous\n");                      //                                -
    }                                                         //                                -
    else                                                      //                                -
    {                                                         //                                -
      XMC_DEBUG1("Replay once\n");                            //                                -
    }                                                         //                                -
  }                                                           //                                -
  else                                                        // If no REPLAY switch.           -
  {                                                           //                                -
    replayValue = 0;                                          // Set replayValue to zero.       -
    XMC_DEBUG1("replayValue equal to %ld.\n",replayValue);    //                                -
    XMC_DEBUG1("Replay once\n");                              //                                -
  }                                                           //---------------------------------

  // Set up the input file header.
  //---------------------------------------------------------------------------------------------
  CPHEADER iHeader;
  iHeader.file_name    = iFilename;
  iHeader.type_allow   = "1000,2000";
  iHeader.format_allow = "SB,SI,SL,SF,SD,CB,CI,CL,CF,CD";
  m_inok(iHeader);

  // Do a comparison of type 2000 frame length byte size and the intended packet size.
  // Frame length byte size is actually "bpe".
  //---------------------------------------------------------------------------------------------
  if(iHeader.type == 2000)
  {
    if(iHeader.bpe != packetSize)
    {
      XMC_ERROR_STDOUT("Type 2000 Bytes Per Element (BPE) does not match UDP Play packet size.");
    }
  }

  // Get the transfer length (BYTES) or transfer samples.  Default to 256k if not present.
  //---------------------------------------------------------------------------------------------
  //  if(m_get_pswitch("TL"))                     // Test for Transfer length.                  -
  //  {                                           //                                            -
  //    xferLngth = m_get_switch("TL");           // Get transfer length (Bytes).               -
  //    xferSamps = xferLngth/iHeader.bpe;        // Calculate transfer samples.                -
  //  }                                           //                                            -
  //  else if(m_get_pswitch("TS"))                // Test for Transfer samples.                 -
  //  {                                           //                                            -
  //    xferSamps = m_get_switch("TS");           // Get transfer samples.                      -
  //    xferLngth = xferSamps*iHeader.bpe;        // Convert to transfer length (Bytes).        -
  //  }                                           //                                            -
  //  else                                        // Else                                       -
  //  {                                           //                                            -
  //    xferLngth = ICC_MAX_MSG_LEN;              // Default to ICC_MAX_MSG_LEN bytes.          -
  //    xferSamps = xferLngth/iHeader.bpe;        // Calculate transfer samples.                -
  //  }                                           //---------------------------------------------

  // Actually in this case set "xferLngth" to packet size.
  //---------------------------------------------------------------------------------------------
  xferLngth = packetSize;
  xferSamps = xferLngth/iHeader.bpe;
  nGot      = xferSamps;
  XMC_DEBUG1("xferLngth   is %ld\n",xferLngth);
  XMC_DEBUG1("xferSamps   is %ld\n",xferSamps);
  XMC_DEBUG1("iHeader.bpe is %d\n",iHeader.bpe);

  // Set the transfer length variable in the output header.
  //---------------------------------------------------------------------------------------------
  iHeader.xfer_len = xferSamps;
  iHeader.cons_len = -1;

  // Initialize datagram socket.
  //---------------------------------------------------------------------------------------------
  datagramSpec = iccDatagramSocketSendInit(ipAddress.c_str(), thePort);
  xmcFree(datagramSpec->msg);

  // Initialize input buffer.
  //---------------------------------------------------------------------------------------------
  iDataINT08 = iccMallocINT08_Align032(xferLngth);
  
  XMC_DEBUG1("Done with init.\n");

  // "Synchronize" not "sink".
  //---------------------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG1("Calling m_sync();\n");

  // Processing loop.
  //---------------------------------------------------------------------------------------------
  while( (nGot==xferSamps) && !Mc->break_ )
  {

    // Grab some input data.
    //-------------------------------------------------------------------------------------------
    m_grabx(iHeader, iDataINT08, nGot);

    // Send the packets.
    //-------------------------------------------------------------------------------------------
    nBytes = iccDatagramSocketSend(iDataINT08, nGot*iHeader.bpe, datagramSpec);

    // Indicate error if not all bytes sent.
    //-------------------------------------------------------------------------------------------
    if(nBytes != (nGot*iHeader.bpe))
    {
      XMC_ERROR_STDOUT("WAS NOT ABLE TO SEND ALL BYTES IF ANY.");
    }
    else
    {
      XMC_DEBUG2("UDP data sent.\n");
    }

    // Pause if need be.
    //-------------------------------------------------------------------------------------------
    if(pauseFlag) 
    {
      usleep( (INT32)(pauseTime*1.0e6) );
    }

    // Handle the play continuous mode.
    //-------------------------------------------------------------------------------------------
    if ( (nGot != xferSamps) && (replayValue == 2) )
    {
      nGot = xferSamps;
      m_seek(iHeader,1.0);
    }

  }

  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG1("Terminating\n");
  m_close(iHeader);
  xmcFree(iDataINT08);
  iccDatagramSocketTerm(datagramSpec);
  XMC_DEBUG1("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/

