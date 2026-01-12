/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccpicplay.cc                                                                          -
//                                                                                              -
// Desc: This primitive plays out buffered data to a PIC card.                                  -
//       This primitive configures a Peripheral Interconnect Component (PIC)                    -
//       card and sends the contents of a file or pipe to a DMA buffer to be                    -
//       played out.  The PIC card can have numerous types of Input/Output                      -
//       Modules (IOMs) to allow for the playback of, to name a few, analog,                    -
//       TTL, ECL, PECL, LHVDS, fibre, and ethernet data.  Clocking of data can                 -
//       come from an on board clock or external source through a connector on                  -
//       the back of the card.  In the case of digital data the input cable                     -
//       usually has the clock line on it.  These different configuration are                   -
//       controlled by a command line input string or an entry in the ICE option                -
//       tree's hardware configuration file "hwconfig.key".                                     -
//                                                                                              -
// Args: iFileName - The name of the input file or pipe. <A:>                                   -
//       iPICName  - Which PIC to use for output.        <A:>                                   -
//       fs        - Sample rate.                        <N:>                                   -
//       nSamples  - Number of Samples to playback.      <D:>                                   -
//                                                                                              -
// Swch: /DMABYTES                                                                              -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       06/10/2005 ptb  Taken from xccpicrecord.                                               -
//       08/04/2005 ptb  Updates.                                                               -
//                                                                                              -
//                           oFileName                                                          -
//                           iPICName                                                           -
//                           fs                                                                 -
//                           nSamples                                                           -
//                           /DMABYTES                                                          -
//                              |                                                               -
//                              V                                                               -
//    :-----------:     :----------------:     :----------:                                     -
//    | file/pipe |---> | xccpicplay.cc  |---> | PIC Card |                                     -
//    :-----------:     :----------------:     :----------:                                     -
//                               |                                                              -
//                               V                                                              -
//                        Debug Statements                                                      -
// Note:                                                                                        -
//                                                                                              -
// Examples:                                                                                    -
// sincos sin08 ,, 32 5e6 0 1024*1024*128 0 1/20e6                                              -
// reformat sin08 sin08 sb                                                                      -
// pipe off                                                                                     -
// sourcefile/replay=2 sin08 _s1(ps=64M)                                                        -
// xccpicplay _s1 pic1_d2a2i 20e6                                                               -
// pipe off                                                                                     -
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
#define _icedefs_h                  // Kluges for ice stuff.                                    -
typedef long int_x;                 // Kluges for ice stuff.                                    -

#include "primitive.h"
#include "xmc.h"
#include "malloc_utils.h"
#include "orbit_utils.h"
#include "pic_utils.h"
#include "socket_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define PLAYBACK (+1)
#define DMABYTES (32*1024*1024)
#define LOOPCOUNT (1048576)

#define DEBUG0      TRUE
#define DEBUG1      FALSE
#define DEBUG2      FALSE
#define DEBUG_HOST  "192.9.214.113"
#define DEBUG_PORT  5000
//#define DEBUG_TYPE  XMC_DEBUG_DATAGRAM
#define DEBUG_TYPE XMC_DEBUG_STDOUT
#define XMC_DEBUG0  if( DEBUG0 ) DEBUG_TYPE
#define XMC_DEBUG1  if( DEBUG1 ) DEBUG_TYPE
#define XMC_DEBUG2  if( DEBUG2 ) DEBUG_TYPE

/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
VOID handle08Bit(INT32 dmaDex01, INT32 dmaDex02, VOID *a, VOID *b, CPHEADER *iHeader);
VOID handle16Bit(INT32 dmaDex01, INT32 dmaDex02, VOID *a, VOID *b, CPHEADER *iHeader);


/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
VOID mainroutine()
{
  INT32 status;
  INT32 nChar;
  FLT64 nSamples;
  INT32 dmaBytes;
  INT32 dmaBits;
  FLT32 fs=20e6;
  //FLT64 tfreq;
  //INT32 tdeci;
  //INT32 tgain;
  //FLT64 ratio;
  xccPICSpec *picSpec;

  //INT32 ratioFlag;

  CHR08 devString[120];
  string dataType;

  // Switch variables.

  // File name variables.
  string iFileName;
  string oPICName;
  string flagString;
  string hwfString;

  INT08 *pINT08;
  INT08 *oDataINT08;
  INT16 *pINT16;
  INT16 *oDataINT16;

  // Generic data handler.
  VOID (*genericHandleData)(INT32, INT32, VOID *, VOID *, CPHEADER *iHeader);

  // Get command line parameters.
  //---------------------------------------------------------------------------------------------
  iFileName  = m_apick(1);
  oPICName   = m_apick(2);
  fs         = m_dpick(3);
  // ---
  nSamples   = m_dpick(4);
  // ---
  // ---
  // ---
  // ---
  // ---
  // ---
  XMC_DEBUG0("iFileName is %s\n", iFileName.c_str());
  XMC_DEBUG0("oPICName  is %s\n", oPICName.c_str());
  XMC_DEBUG0("fs        is %f\n", fs);
  // ---
  XMC_DEBUG0("nSamples  is %f\n", nSamples);
  // ---
  // ---
  // ---
  // ---

  // Check results for PIC device string.
  //---------------------------------------------------------------------------------------------
  CHR08 rtype;
  int_4 rattrib;

  //if( m_get_pswitch("RESULT") )
  //{
  //  oPICName = "A:" + oPICName;
  //  m_uppercase(oPICName);
  //  status = m_get_result( oPICName, devString, 256, 0, rtype, rattrib);
  //}

  if( m_get_pswitch("RESULT") )
  {
    oPICName = "A:" + oPICName;
    m_uppercase(oPICName);
    nChar = m_get_result( oPICName, devString, 120, 0, rtype, rattrib);
    devString[120-1]='S';
    devString[nChar]='\0';
    
    XMC_DEBUG0("Number of bytes returned from m_get_result is %ld\n", nChar);
  }
  // Else, search the hardware configuration file for PIC device string.
  //---------------------------------------------------------------------------------------------
  else
  {
    CPHEADER hwfHeader;
    status = m_hwf_open (hwfHeader);
    status = m_hwf_alias(hwfHeader, oPICName, hwfString);
    status = m_hwf_close(hwfHeader);
    sprintf(devString,"%s",hwfString.c_str());
  }

  XMC_DEBUG0("devString  is %s\n", devString);

  // Get additional flag settings.
  //---------------------------------------------------------------------------------------------
  if( m_get_pswitch("FLAGS") )
  {
    m_get_uswitch("FLAGS",flagString);
  }
  XMC_DEBUG0("Additional Flags are %s\n", flagString.c_str());

  // Take "ratio > 0.0" as indication for desire to resample.
  //---------------------------------------------------------------------------------------------
  //if(ratio > 0.0 )                                            //                              -
  //{                                                           //                              -
  //  ratioFlag  = 1;                                           //                              -
  //  flagString = flagString + "|RESAMP";                      //                              -
  //  XMC_DEBUG0("Resampling is ON.  Adding RESAMP flag.\n");   //                              -
  //}                                                           //                              -
  //else                                                        //                              -
  //{                                                           //                              -
  //  ratioFlag = 0;                                            //                              -
  //  XMC_DEBUG0("Resampling is OFF.\n");                       //                              -
  //}                                                           //                              -

  // Create the final device string to pass to PIC card.
  //---------------------------------------------------------------------------------------------
  sprintf(devString,"%s|%s",devString,flagString.c_str());

  XMC_DEBUG0("devString  is %s\n", devString);

  // Get the DMABytes flag if present.
  //---------------------------------------------------------------------------------------------
  if( m_get_pswitch("DMABYTES") )                             //---------------------------------
  {                                                           // For SDDS data make the buffer  -
    dmaBytes = (INT32)m_get_dswitch("DMABYTES");              // a multiple of 1080.            -
  }                                                           //                                -
  else dmaBytes  = DMABYTES;                                  //                                -
  XMC_DEBUG0("DMA buffer size in bytes is %ld\n", dmaBytes);  //---------------------------------


  // Set up the input file header.
  //---------------------------------------------------------------------------------------------
  CPHEADER iHeader;
  iHeader.file_name    = iFileName;
  iHeader.type_allow   = "1000";
  iHeader.format_allow = "SB,SI";
  m_inok(iHeader);

  // Set the transfer length variable in the input header.
  //---------------------------------------------------------------------------------------------
  iHeader.xfer_len = 8192;
  iHeader.cons_len = -1;

  // Handle the possible different data types (SB, SI).
  //---------------------------------------------------------------------------------------------
  if     ( iHeader.format == "SB" )                              // If data type is scalar byte.-
  {                                                              //                             -
    dmaBits = 8;                                                 // "dmaBits" needs to be 8.    -
    genericHandleData = handle08Bit;                             //                             -
  }                                                              //                             -
  else if( iHeader.format == "SI" )                              // If data type scalar integer.-
  {                                                              //                             -
    dmaBits = 16;                                                // "dmaBits" needs to be 16.   -
    genericHandleData = handle16Bit;                             //                             -
  }                                                              //                             -
  else                                                           // Else                        -
  {                                                              //                             -
    dmaBits = 8;                                                 // "dmaBits" needs to be 8.    -
    genericHandleData = handle08Bit;                             //                             -
  }                                                              //------------------------------

  // Initialize the PIC card.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG0("About  to initialize PIC card.\n");
  picSpec = xccPICInit( devString, fs );
  XMC_DEBUG0("Done with initialize PIC card.\n");

  // Initialize the PIC IO for playback.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG0("About  to initialize PIC IO channel.\n");
  xccPICIOInit(dmaBytes,
	       dmaBits,
	       PLAYBACK,
	       0,
	       0,
	       0,
	       picSpec);

  pINT08 = (INT08 *) picSpec->dma[0].dmaMap.vaddr;
  pINT16 = (INT16 *) picSpec->dma[0].dmaMap.vaddr;
  XMC_DEBUG0("Done with initialize PIC IO channel.\n");

  // Initialize the output buffer.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG0("About to malloc memory.\n");
  oDataINT08 = (INT08 *) xccMallocINT08_Align032( dmaBytes );
  oDataINT16 = (INT16 *) oDataINT08;
  XMC_DEBUG0("Done with malloc memory.\n");

  XMC_DEBUG0("Done with init.\n");

  // "Synchronize" not "sink".
  //---------------------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG0("Calling m_sync();\n");

  // Grab the first "dmaBytes" worth of data and fill the dma buffer.
  //---------------------------------------------------------------------------------------------
  genericHandleData(0, dmaBytes, oDataINT08, pINT08, &iHeader);

  // Get the PIC DMA rolling (xccPIC_DMA_CONTINUOUS).
  //---------------------------------------------------------------------------------------------
  xccPIC_DMA_CONTINUOUS(0, picSpec);

  INT32 temp       = 0;
  INT32 dmaDex00   = 0;
  INT32 dmaDex01   = 0;
  INT32 dmaDex02   = 0;
  INT32 bufSize    = dmaBytes;
  INT32 dmaCyc00   = 0;
  INT32 dmaCyc01   = 0;

  INT32 loopCounter= 0;
  //INT32 loopNoBytes= 0;
  //INT32 loopBeBytes= 0;
  //FLT32 loopPercent= 0;
  //INT32 loopSleep  = 0;
  //INT32 loopTotal  = 0;
  INT32 whogi      = 0;

  // Processing loop.
  //---------------------------------------------------------------------------------------------
  while( !Mc->break_ )
  {
    loopCounter++;
                                                                 //------------------------------
    dmaCyc01 = dmaCyc00;                                         // Update DMA Cycle counter 1. -
    dmaCyc00 = xccPIC_DMA_CYCLE (0, picSpec);                    // Update DMA Cycle counter 0. -
                                                                 //------------------------------
    if     ( (dmaCyc00-dmaCyc01) > 1)                            // If difference > 1           -
    {                                                            // Let everyone know that we   -
      XMC_ERROR_STDOUT("LOST DMA CYCLE!");                       // lost a DMA cycle.           -
    }                                                            //------------------------------
                                                                 //------------------------------
    temp = xccPIC_DMA_STATUS(0, picSpec);                        // Check the DMA Status.       -
                                                                 //------------------------------
    if(temp != dmaDex00)                                         // If there is a change in DMA.-
    {                                                            //                             -
      whogi++;                                                   // Update whogi counter.       -
                                                                 //                             -
      dmaDex02 = dmaDex01;                                       // Update DMA index counter 2. -
      dmaDex01 = dmaDex00;                                       // Update DMA index counter 1. -
      dmaDex00 = temp;                                           // Update DMA index counter 0. -
      XMC_DEBUG2("DMA STATUS is %ld",dmaDex00);                   // Debug status.              -
      XMC_DEBUG2(" DMA VADDR is %p",picSpec->dma[0].dmaMap.vaddr);//                            -
      XMC_DEBUG2(" DMA ADDRESS is %p",oDataINT08);                //                            -
      XMC_DEBUG2(" \n");                                          //-----------------------------
                                                                 //------------------------------
      if     (dmaDex02<dmaDex01)                                 // If normal condition.        -
      {                                                          //                             -
	genericHandleData(dmaDex01, dmaDex02, oDataINT08, pINT08, &iHeader);//                  -
      }                                                          //------------------------------
                                                                 //------------------------------
      else if(dmaDex02>dmaDex01 )                                // If wrapping condition.      -
      {                                                          //                             -
	genericHandleData(bufSize, dmaDex02, oDataINT08, pINT08, &iHeader);//                   -
                                                                 //                             -
	genericHandleData(dmaDex01, 0, oDataINT08, pINT08, &iHeader);//                         -
      }                                                          //------------------------------
    }

    if( loopCounter>(1024*2) )                                   //------------------------------
    {                                                            // Print out stats on how much -
      FLT32 pv = 100.0*((FLT32)whogi)/((FLT32)loopCounter);      // of the time we output data. -
      XMC_DEBUG0("loopPercent is %f\n", pv);                     //                             -
      XMC_DEBUG0(" \n");                                          //                             -
      loopCounter=0;                                             //                             -
      whogi=0;                                                   //                             -
      if(!(nSamples<1) && (iHeader.offset > nSamples))Mc->break_=1;
      XMC_DEBUG0("offset is %f\n",iHeader.offset);
    }                                                            //------------------------------

  }

  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG0("Terminating\n");
  xccPIC_DMA_STOP(0, picSpec);
  xccPIC_DMA_CANCEL(0, picSpec);
  xccPICTerm(picSpec);
  xmcFree(oDataINT08);
  m_close(iHeader);
  XMC_DEBUG0("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/

VOID handle08Bit(INT32 dmaDex01, INT32 dmaDex02, VOID *a, VOID *b, CPHEADER *iHeader)
{
  INT32 ii;
  INT32 jj;
  int_4 nGot;
  INT32 strt;
  INT32 stop;
  INT32 diff;
  INT08 *pINT08=(INT08 *)b;
  INT08 *oDataINT08=(INT08 *)a;                                  //------------------------------
  strt = dmaDex02/sizeof(INT08);                                 // Calculate start.            -
  stop = dmaDex01/sizeof(INT08);                                 // Calculate stop.             -
  diff = stop-strt;                                              // Calculate difference.       -
  XMC_DEBUG2("strt is %08ld ",strt);                             //                             -
  XMC_DEBUG2(" stop is %08ld ",stop);                            //                             -
  XMC_DEBUG2(" diff is %08ld ",diff);                            //                             -
  XMC_DEBUG2(" \n");                                             //                             -
  if( (diff%8192) != 0 )                                         // It looks like the PIC gets  -
  {                                                              // a minimum of 8kb at a time. -
    XMC_ERROR_STDOUT("MINIMUM 8kb assumption not TRUE.");        // Notify if this is not the   -
    XMC_ERROR_STDOUT("DESIGN FLAW TELL PTB.");                   // case.                       -
  }                                                              //                             -
  jj = (diff/8192);                                              // Calc. how many 8kb buffers. -
  for(ii=0;ii<jj;ii++)                                           //                             -
  {                                                              //                             -
    m_grabx(*iHeader, &oDataINT08[strt+(ii*8192)], nGot);        // Grab that much data.        -
  }                                                              //                             -
  XMC_DEBUG2("diff %ld", diff);                                  //                             -
  XMC_DEBUG2(" nGot %ld", (INT32)nGot);                          //                             -
  XMC_DEBUG2(" mod  %ld\n", diff%nGot);                          //                             -
  XMC_DEBUG2(" \n");                                             //                             -
  for(ii=strt; ii<stop; ii++)                                    //                             -
  {                                                              //                             -
    pINT08[ii]=oDataINT08[ii];                                   // Copy the data into DMA.     -
  }                                                              //                             -
}                                                                //------------------------------


VOID handle16Bit(INT32 dmaDex01, INT32 dmaDex02, VOID *a, VOID *b, CPHEADER *iHeader)
{
  INT32 ii;
  INT32 jj;
  int_4 nGot;
  INT32 strt;
  INT32 stop;
  INT32 diff;
  INT16 *pINT16=(INT16 *)b;
  INT16 *oDataINT16=(INT16 *)a;                                  //------------------------------
  strt = dmaDex02/sizeof(INT16);                                 // Calculate start.            -
  stop = dmaDex01/sizeof(INT16);                                 // Calculate stop.             -
  diff = stop-strt;                                              // Calculate difference.       -
  XMC_DEBUG2("strt is %08ld ",strt);                             //                             -
  XMC_DEBUG2(" stop is %08ld ",stop);                            //                             -
  XMC_DEBUG2(" diff is %08ld ",diff);                            //                             -
  XMC_DEBUG2(" \n");                                             //                             -
  if( (diff%4096) != 0 )                                         // It looks like the PIC gets  -
  {                                                              // a minimum of 8kb at a time. -
    XMC_ERROR_STDOUT("MINIMUM 8kb assumption not TRUE.");        // Notify if this is not the   -
    XMC_ERROR_STDOUT("DESIGN FLAW TELL PTB.");                   // case.                       -
  }                                                              //                             -
  jj = (diff/4096);                                              // Calc. how many 8kb buffers. -
  for(ii=0;ii<jj;ii++)                                           //                             -
  {                                                              //                             -
    m_grabx(*iHeader, &oDataINT16[strt+(ii*4096)], nGot);        // Grab that much data.        -
  }                                                              //                             -
  XMC_DEBUG2("diff %ld", diff);                                  //                             -
  XMC_DEBUG2(" nGot %ld", (INT32)nGot);                          //                             -
  XMC_DEBUG2(" mod  %ld\n", diff%nGot);                          //                             -
  XMC_DEBUG2(" \n");                                             //                             -
  for(ii=strt; ii<stop; ii++)                                    //                             -
  {                                                              //                             -
    pINT16[ii]=oDataINT16[ii];                                   // Copy the data into DMA.     -
  }                                                              //                             -
}                                                                //------------------------------
