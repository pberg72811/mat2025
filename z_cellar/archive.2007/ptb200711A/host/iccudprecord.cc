/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: iccudprecord.cc                                                                        -
//                                                                                              -
// Desc: This primitive records UDP packets.                                                    -
//       This primitive is designed to be a generic UDP packet catcher.  With                   -
//       the use of SDDS for transmiting signal data, bringing in UDP packets to                -
//       X-Midas has become of interest.                                                        -
//                                                                                              -
// Args: oFileName  - The name of the output file.    <A:>                                      -
//       fileType   - The file type of output file.   <D:>                                      -
//       dataType   - The data type of output file.   <A:>                                      -
//       packetSize - The packet size in bytes.       <L:>                                      -
//       thePort    - The UDP port to listen to.      <D:>                                      -
//       absInc     - The abscissa increment.         <D:>                                      -
//                                                                                              -
// Swch: CPSB=      - Switch to check the packet size of each packet arriving.                  -
//                    Data will be dropped if packet size does not match.                       -
//       PAUSE=     - Switch to pause "N" seconds between receives.                             -
//       BLOCK      - Switch to turn off non-blocking mode.                                     -
//       MCIP=      - Switch to set the multicast IP address  (multicast mode).                 -
//       LHIP=      - Switch to set the local host IP address (multicast mode).                 -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       01/06/2005 ptb  Initial Code.                                                          -
//       10/14/2005 ptb  Added the CPSB (check packet size bytes) capability.                   -
//       01/10/2006 ptb  Added type 2000 recording capability.                                  -
//       05/01/2006 ptb  Produce error message for incomplete packets.                          -
//                                                                                              -
//                        oFileName                                                             -
//                        fileType                                                              -
//                        dataType                                                              -
//                        packetSize                                                            -
//                        thePort                                                               -
//                        absInc                                                                -
//                        /CPSB                                                                 -
//                        /Pause                                                                -
//                        /Block                                                                -
//                        /MCIP                                                                 -
//                        /LHIP                                                                 -
//                          |                                                                   -
//                          V                                                                   -
//    :--------:     :---------------:     :---------:                                          -
//    |NIC CARD|---> |iccudprecord.cc|---> |FILE/PIPE|                                          -
//    :--------:     :---------------:     :---------:                                          -
//                          |                                                                   -
//                          V                                                                   -
//                    Debug Statements                                                          -
//                                                                                              -
// Note: SDDS data needs to be sent as packets of 1080 bytes.  This includes the                -
//       SDDS header and SDDS data.  Big endian or Network byte order needs to                  -
//       be kept track of.  This routine runs in a non-blocking mode by default.                -
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

#define LOOP_TOTAL  (1024)
#define BUFFER_SIZE (ICC_MAX_MSG_LEN)
#define MAX_PACKET_SIZE (ICC_MAX_MSG_LEN)

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
  INT32 nBytes;
  FLT32 absInc;
  INT32 thePort;
  INT32 nSamples;
  INT32 fileType;
  INT32 number1=1;

  INT32 loopTotal;
  INT32 packetSize;
  INT32 loopCounter;
  INT32 loopNoBytes;
  INT32 loopBeBytes;
  FLT32 loopPercent;
  iccDatagramSocketSpec *datagramSpec;

  // Switch variables.
  INT32 xferLngth;
  INT32 xferSamps;
  INT32 pauseFlag=FALSE;
  FLT32 pauseTime=0.000;
  INT32 multicastFlag=FALSE;
  INT32 nonBlockingFlag=TRUE;
  INT32 checkPacketSizeFlag=FALSE;

  // File name variables.
  string oFileName;
  string localIP;
  string mcastIP;
  string dataType;

  // Get command line parameters.
  //---------------------------------------------------------------------------------------------
  oFileName  = m_apick(1);
  fileType   = (INT32)m_dpick(2);
  dataType   = m_apick(3);
  packetSize = (INT32)m_dpick(4);
  thePort    = m_lpick(5);
  absInc     = m_dpick(6);
  XMC_DEBUG("oFileName  is %s\n",   oFileName.c_str());
  XMC_DEBUG("fileType   is %05ld\n",fileType);
  XMC_DEBUG("dataType   is %s\n",   dataType.c_str());
  XMC_DEBUG("packetSize is %05ld\n",packetSize);
  XMC_DEBUG("thePort    is %05ld\n",thePort);
  XMC_DEBUG("abscissa   is %f\n",   absInc);

  // Get the CPSB (Check Packet Size Bytes) switch if present.
  //---------------------------------------------------------------------------------------------
  if(m_get_pswitch("CPSB"))                                   // If there is a CPSB switch.     -
  {                                                           //                                -
    checkPacketSizeFlag=TRUE;                                 // Set check packet length flag.  -
    XMC_DEBUG("Going to check packet size.\n");               //                                -
    XMC_DEBUG("Expected packet length is %ld.\n",packetSize); //                                -
  }                                                           //                                -
  else                                                        // If there is no CPSB switch.    -
  {                                                           //                                -
    checkPacketSizeFlag=FALSE;                                // Clear checkPacketSizeFlag.     -
    XMC_DEBUG("No packet size check.\n");                     //                                -
  }                                                           //---------------------------------

  // Get the BLOCK switch if present.
  //---------------------------------------------------------------------------------------------
  if( m_get_pswitch("BLOCK") )                                // If there is a BLOCK switch.    -
  {                                                           //                                -
    nonBlockingFlag = FALSE;                                  // Clear the non-blocking Flag.   -
    XMC_DEBUG("Clearing nonBlockingFlag flag.\n");            //                                -
  }                                                           //                                -
  else                                                        // If no BLOCK switch.            -
  {                                                           //                                -
    nonBlockingFlag = TRUE;                                   // Set the non-blocking Flag.     -
    XMC_DEBUG("Setting nonBlockingFlag flag.\n");             //                                -
  }                                                           //---------------------------------

  // Get the PAUSE switch if present.
  //---------------------------------------------------------------------------------------------
  if( m_get_pswitch("PAUSE") )                                // If there is a PAUSE switch.    -
  {                                                           //                                -
    pauseFlag = TRUE;                                         // Set the pause flag.            -
    pauseTime = m_get_dswitch("PAUSE");                       // Get duration of pause.         -
    XMC_DEBUG("Setting pauseFlag flag.\n");                   //                                -
  }                                                           //                                -
  else                                                        // If no pause switch.            -
  {                                                           //                                -
    pauseFlag = FALSE;                                        // Clear pause flag.              -
    XMC_DEBUG("Clearing pauseFlag flag.\n");                  //                                -
  }                                                           //---------------------------------

  // Get the multicast IP address (MCIP) switch if present.
  //---------------------------------------------------------------------------------------------
  if(m_get_pswitch("MCIP"))                                   // If there is a MCIP switch.     -
  {                                                           //                                -
    m_get_uswitch("MCIP", mcastIP);                           // Get the multicast address.     -
    multicastFlag=TRUE;                                       // Set multicast flag to True.    -
    XMC_DEBUG("Setting multicast flag.\n");                   //                                -
    XMC_DEBUG("Multicast IP address is %s\n", mcastIP.c_str());//                               -
  }                                                           //                                -
  else                                                        // If there is no MCIP switch.    -
  {                                                           //                                -
    multicastFlag=FALSE;                                      // Clear the multicast flag.      -
    XMC_DEBUG("Clearing multicastFlag flag.\n");              //                                -
  }                                                           //---------------------------------

  // Get the local host IP address (LHIP) switch if present.
  //---------------------------------------------------------------------------------------------
  if(m_get_pswitch("LHIP"))                                   // If there is a LHIP switch.     -
  {                                                           //                                -
    m_get_uswitch("LHIP", localIP);                           // Get the local host address.    -
    XMC_DEBUG("Local IP address is %s\n", localIP.c_str());   //                                -
  }                                                           //                                -
  else                                                        // If there is no LHIP switch.    -
  {                                                           //                                -
    if(multicastFlag==TRUE)                                   // Check for multicast flag.      -
    {                                                         // There is a problem if TRUE.    -
      multicastFlag=FALSE;                                    // Clear the multicast flag.      -
      XMC_DEBUG("Hey!!!  Need local IP for multicast to work!\n");//                            -
      XMC_DEBUG("Clearing multicastFlag flag.\n");            //                                -
    }                                                         //                                -
  }                                                           //---------------------------------

  // Set up the output file header.
  //---------------------------------------------------------------------------------------------
  CPHEADER oHeader;
  m_initialize(oHeader);
  oHeader.file_name = oFileName;
  oHeader.type      = fileType;
  oHeader.size      = 1024;
  oHeader.xstart    = 0;
  oHeader.xunits    = 1;
  oHeader.xdelta    = absInc;
  oHeader.ystart    = 0;
  oHeader.yunits    = 0;
  oHeader.ydelta    = 1;
  oHeader.timecode  = iccCurrentJ1950Seconds();

  // In this case xferLngth gets set equal to packetSize.
  //---------------------------------------------------------------------------------------------
  xferLngth = packetSize;

  // Before you allocate oHeader, set oHeader.format and oHeader.subsize base on data type.
  //---------------------------------------------------------------------------------------------
  if     ( (dataType=="SB") || (dataType=="INT08") ) 
  {
    oHeader.format = "SB";
    oHeader.subsize = xferLngth/1;
  }
  else if( (dataType=="SI") || (dataType=="INT16") )
  {
    oHeader.format = "SI";
    oHeader.subsize = xferLngth/2;
  }
  else if( (dataType=="SL") || (dataType=="INT32") )
  {
    oHeader.format = "SL";
    oHeader.subsize = xferLngth/4;
  }
  else if( (dataType=="SF") || (dataType=="FLT32") )
  {
    oHeader.format = "SF";
    oHeader.subsize = xferLngth/4;
  }
  else if( (dataType=="SD") || (dataType=="FLT64") )
  {
    oHeader.format = "SD"; 
    oHeader.subsize = xferLngth/8;
  }
  else if( (dataType=="CB") || (dataType=="CINT08") )
  {
    oHeader.format = "CB";
    oHeader.subsize = xferLngth/2;
  }
  else if( (dataType=="CI") || (dataType=="CINT16") ) 
  {
    oHeader.format = "CI";
    oHeader.subsize = xferLngth/4;
  }
  else if( (dataType=="CL") || (dataType=="CINT32") ) 
  {
    oHeader.format = "CL";
    oHeader.subsize = xferLngth/8;
  }
  else if( (dataType=="CF") || (dataType=="CFLT32") ) 
  {
    oHeader.format = "CF";
    oHeader.subsize = xferLngth/8;
  }
  else if( (dataType=="CD") || (dataType=="CFLT64") ) 
  {
    oHeader.format = "CD"; 
    oHeader.subsize = xferLngth/16;
  }
  else
  {
    oHeader.format = "SB";
    oHeader.subsize = xferLngth/1;
  }

  // Now allocate oHeader
  //---------------------------------------------------------------------------------------------
  m_allocate(oHeader);

  // Calculate "xferSamps". "xferLngth" already set based on packet size
  //---------------------------------------------------------------------------------------------
  xferSamps = xferLngth/oHeader.bpe;               // Calculate transfer samples.               -
  XMC_DEBUG("xferLngth   is %ld\n",xferLngth);
  XMC_DEBUG("xferSamps   is %ld\n",xferSamps);
  XMC_DEBUG("oHeader.bpe is %d\n",oHeader.bpe);

  // Do not do the usual setting of "xferLngth" and "xferSamps".
  // Leave next section commented out.
  //---------------------------------------------------------------------------------------------
  // Get the transfer length (BYTES) or transfer samples.  Default to 256k if not present.
  //---------------------------------------------------------------------------------------------
  //   if(m_get_pswitch("TL"))                     // Test for Transfer length.                 -
  //   {                                           //                                           -
  //     xferLngth = m_get_switch("TL");           // Get transfer length (Bytes).              -
  //     xferSamps = xferLngth/oHeader.bpe;        // Calculate transfer samples.               -
  //   }                                           //                                           -
  //   else if(m_get_pswitch("TS"))                // Test for Transfer samples.                -
  //   {                                           //                                           -
  //     xferSamps = m_get_switch("TS");           // Get transfer samples.                     -
  //     xferLngth = xferSamps*oHeader.bpe;        // Convert to transfer length (Bytes).       -
  //   }                                           //                                           -
  //   else                                        // Else                                      -
  //   {                                           //                                           -
  //     xferLngth = 262144;                       // Default to 256k bytes.                    -
  //     xferSamps = xferLngth/oHeader.bpe;        // Calculate transfer samples.               -
  //   }                                           //--------------------------------------------

  // Set the transfer length variable in the output header.
  //---------------------------------------------------------------------------------------------
  oHeader.xfer_len = xferSamps;
  oHeader.cons_len = -1;

  // Initialize datagram socket.
  //---------------------------------------------------------------------------------------------
  datagramSpec = iccDatagramSocketReceiveInit(MAX_PACKET_SIZE+1024, thePort);

  // Initialize input buffer.  Do not do this.  The "msg" buffer in the datagramSpec will be 
  //                           the input buffer.
  //---------------------------------------------------------------------------------------------
  // oDataINT08 = iccMallocINT08_Align032(BUFFER_SIZE);  // Leave commented out.

  // Are we non-blocking?
  //---------------------------------------------------------------------------------------------
  if(nonBlockingFlag)
  {
    iccDatagramSocketReceiveSetNB(datagramSpec);
  }

  // Are we multicast?
  //---------------------------------------------------------------------------------------------
  if(multicastFlag) 
  {
    iccDatagramSocketReceiveSetMC(datagramSpec, localIP.c_str(), mcastIP.c_str());
  }
  
  // Initialize loop stats.
  //---------------------------------------------------------------------------------------------
  loopCounter = 0;
  loopNoBytes = 0;
  loopBeBytes = 0;
  loopPercent = 0.0;
  loopTotal   = LOOP_TOTAL;

  XMC_DEBUG("Expected packet length is %ld.\n",packetSize);
  XMC_DEBUG("Not able to do packet length of 1 and CPSB flag.\n");

  XMC_DEBUG("Done with init.\n");

  // "Synchronize" not "sink".
  //---------------------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG("Calling m_sync();\n");

  // Processing loop.
  //---------------------------------------------------------------------------------------------
  while(!Mc->break_)
  {
    // Keep stats on loop count.
    //-------------------------------------------------------------------------------------------
    loopCounter++;

    // Receive a packet.
    //-------------------------------------------------------------------------------------------
    nBytes = iccDatagramSocketReceive(datagramSpec);

    if( (nBytes > 0) && (nBytes != packetSize) )
    {
      XMC_ERROR_STDOUT("Incomplete packet received.");
    }

    // Take care of any data that came in.
    //-------------------------------------------------------------------------------------------
    if( (nBytes==packetSize) && checkPacketSizeFlag )            // CASE 1.                     -
    {                                                            //                             -
      loopBeBytes++;                                             // Keep stats.                 -
      nSamples = nBytes/oHeader.bpe;                             // Calculate number of samples.-
      m_filad(oHeader, &datagramSpec->msg[0], nSamples);         // Write out the packet data.  -
      if(!oHeader.pipe)                                          // If not piped                -
      {                                                          //                             -
	m_hcbfunc(oHeader, HCBF_FLUSH, (int_4 *) &number1);      // Flush the HCB to update     -
      }                                                          // output file.                -
    }                                                            //------------------------------

    else if( (nBytes > 0) && !checkPacketSizeFlag )              // CASE 2.                     -
    {                                                            //                             -
      loopBeBytes++;                                             // Keep stats.                 -
      nSamples = nBytes/oHeader.bpe;                             // Calculate number of samples.-
      m_filad(oHeader, &datagramSpec->msg[0], nSamples);         // Write out the packet data.  -
      if(!oHeader.pipe)                                          // If not piped                -
      {                                                          //                             -
	m_hcbfunc(oHeader, HCBF_FLUSH, (int_4 *) &number1);      // Flush the HCB to update     -
      }                                                          // output file.                -
    }                                                            //------------------------------

    else if( (nBytes>0) && checkPacketSizeFlag )                 // CASE 3.                     -
    {                                                            //                             -
      XMC_DEBUG("Incomplete packet based on CPSB.\n");           // Write out debug statement.  -
      XMC_DEBUG("No data written.\n");                           // Write out debug statement.  -
    }                                                            //------------------------------

    else /* nBytes == 0 */                                       // CASE LAST.                  -
    {                                                            //                             -
      loopNoBytes++;                                             // Keep stats.                 -
    }                                                            //------------------------------

    // Pause if need be.
    //-------------------------------------------------------------------------------------------
    if(pauseFlag)
    {
      usleep( (INT32)(pauseTime*1e6) );
    }

    // Calculate statistics when loopCounter reaches loopTotal.
    //-------------------------------------------------------------------------------------------
    if(loopCounter==loopTotal)
    {
      loopPercent = ((FLT32)loopNoBytes)/((FLT32)LOOP_TOTAL);
      XMC_DEBUG("NICLOOP:");
      XMC_DEBUG(" loopPercent is %05.2f.",loopPercent);
      XMC_DEBUG(" loopNoBytes is %08ld. ",loopNoBytes);
      XMC_DEBUG(" loopBeBytes is %08ld. ",loopBeBytes);
      XMC_DEBUG(" \n");
      loopCounter = 0;
      loopNoBytes = 0;
      loopBeBytes = 0;
    }
  }

  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  m_close(oHeader);
  //iccFree(oDataINT08);  // Not used.
  iccDatagramSocketTerm(datagramSpec);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
