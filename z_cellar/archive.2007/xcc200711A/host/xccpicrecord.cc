/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccpicrecord.cc                                                                        -
//                                                                                              -
// Desc: This primitive records buffered data from a PIC card.                                  -
//       This primitive configures a Peripheral Interconnect Component (PIC)                    -
//       card and sends the contents of the DMA buffer to a file or pipe.  The                  -
//       PIC card can have numerous types of Input/Output Modules (IOMs) to                     -
//       allow for the acquisition of, to name a few, analog, TTL, ECL, PECL,                   -
//       LHVDS, fibre, and ethernet data.  In the case of the PIC 4T there are                  -
//       two on board Gray Chip Tuners (GC4016).  Each GC4016 is capable of                     -
//       producing 4 channels of tuned output for a total of 8 channels of tuned                -
//       output for the PIC 4T.  Clocking of data can come from an on board clock               -
//       or external source through a connector on the back of the card.  In the                -
//       case of digital data the input cable usually has the clock line on it.                 -
//       These different configuration are controlled by a command line input                   -
//       string or an entry in the ICE option tree's hardware configuration file.               -
//                                                                                              -
// Args: oFileName - The name of the output file.         <A:>                                  -
//       iPICName  - Which PIC to use for input.          <A:>                                  -
//       fs        - Sample rate.                         <D:>                                  -
//       dataType  - Data type (sb,si,ci).                <A:>                                  -
//       nSamples  - Number of Samples to record.         <D:>                                  -
//       tfreq     - Frequency for tuner     (Optional).  <D:>                                  -
//       tdeci     - Decimation after tuner  (Optional).  <L:>                                  -
//       tgain     - Gain of tuner           (Optional).  <L:>                                  -
//       ratio     - Resampler ratio.                     <L:>                                  -
//                                                                                              -
// Swch: /DMABYTES                                                                              -
//       /FLAGS                                                                                 -
//       /RESULT                                                                                -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       12/23/2003 ptb  Initial Code.                                                          -
//       04/28/2004 ptb  Added no reset option.                                                 -
//       09/13/2004 ptb  Added tuner option.                                                    -
//       02/03/2005 ptb  Added dubble buffer thread scheme.                                     -
//       02/24/2005 ptb  Yellowfin inspired changes.                                            -
//       03/24/2005 ptb  Massive rewrite.                                                       -
//       01/20/2006 ptb  Use flag OVSR=X for oversample now. No input parm.                     -
//       02/20/2006 ptb  Added results parm for creating "devstring".                           -
//       05/15/2006 ptb  Added complex byte conversion (DOES NOT WORK YET).                     -
//                                                                                              -
//                            oFileName                                                         -
//                            iPICName                                                          -
//                            fs                                                                -
//                            dataType                                                          -
//                            nSamples                                                          -
//                            tfreq                                                             -
//                            tdec                                                              -
//                            tgain                                                             -
//                            tovrs                                                             -
//                            ratio                                                             -
//                            /DMABYTES                                                         -
//                            /FLAGS                                                            -
//                            /RESULT                                                           -
//                              |                                                               -
//                              V                                                               -
//    :----------:     :------------------:     :-----------:                                   -
//    | PIC Card |---> | xccpicrecord.cc  |---> | file/pipe |                                   -
//    :----------:     :------------------:     :-----------:                                   -
//                              |                                                               -
//                              V                                                               -
//                       Debug Statements                                                       -
//                                                                                              -
// Note:                                                                                        -
//                                                                                              -
// Examples:                                                                                    -
// pipe on                                                                                      -
// xccpicrec/dmabytes=8M _s1 PIC1_A2D_TUN2I 10e6 ci 0 2e6 32 20                                 -
// xccarchive _s1 pictest 1024*1024*32 /data11/steswd 10                                        -
// pipe off                                                                                     -
// pipe on                                                                                      -
// xccpicrecord/dmabytes=16M _stream(ps=32M) PIC1_A2D_TUN1I 10e6 ci 0 1e6 32 2                  -
// xccarchive _stream(ps=32M) pictest 1024*1024*1024 /data11/steswd/ 10                         -
// pipe off                                                                                     -
// xccpicrecord/dmabytes=16M test PIC1_A2D_TUN1I 10e6 ci 0 1e6 32 2                             -
// xccpicrecord/tl=1080*10/flags=ioc=iix|ipaddr1=192.168.1.202|rxrawsdds test PIC1_SDDS1 1e6 si -
// xccpicrecord/flags=ipaddr1=192.168.1.75 test PIC1_RXICESDDS1 10e6 si                         -
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
#define RECORD    (-1)
#define DMABYTES  (32*1024*1024)
#define LOOPCOUNT (32768)

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
VOID handle08Bit(INT32 dmaDex01, INT32 dmaDex02, VOID *a, VOID *b, CPHEADER *oHeader);
VOID handle16Bit(INT32 dmaDex01, INT32 dmaDex02, VOID *a, VOID *b, CPHEADER *oHeader);
VOID handle32Bit(INT32 dmaDex01, INT32 dmaDex02, VOID *a, VOID *b, CPHEADER *oHeader);
VOID handle16Bit8Bit(INT32 dmaDex01, INT32 dmaDex02, VOID *aINT08, VOID *bINT16, CPHEADER *oHeader);

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
  FLT64 tfreq;
  INT32 tdeci;
  INT32 tgain;
  FLT64 ratio;
  xccPICSpec *picSpec;

  INT32 ratioFlag;

  CHR08 devString[120];
  string dataType;

  // Switch variables.

  // File name variables.
  string oFileName;
  string iPICName;
  string flagString;
  string hwfString;

  INT08 *pINT08;
  INT08 *oDataINT08;

  // Generic data handler.
  VOID (*genericHandleData)(INT32, INT32, VOID *, VOID *, CPHEADER *oHeader);

  // Get command line parameters.
  //---------------------------------------------------------------------------------------------
  oFileName  = m_apick(1);
  iPICName   = m_apick(2);
  fs         = m_dpick(3);
  dataType   = m_apick(4);
  nSamples   = m_dpick(5);
  tfreq      = m_dpick(6);
  tdeci      = m_lpick(7);
  tgain      = m_lpick(8);
  ratio      = m_dpick(9);
  if(tdeci == 0) tdeci = 1;
  XMC_DEBUG0("oFileName is %s\n" , oFileName.c_str());
  XMC_DEBUG0("iPICName  is %s\n" , iPICName.c_str());
  XMC_DEBUG0("fs        is %f\n" , fs);
  XMC_DEBUG0("dataType  is %s\n" , dataType.c_str());
  XMC_DEBUG0("nSamples  is %f\n" , nSamples);
  XMC_DEBUG0("tfreq     is %f\n" , tfreq);
  XMC_DEBUG0("tdeci     is %ld\n", tdeci);
  XMC_DEBUG0("tgain     is %ld\n", tgain);
  XMC_DEBUG0("ratio     is %f\n",  ratio);

  // Check results for PIC device string.
  //---------------------------------------------------------------------------------------------
  CHR08 rtype;
  int_4 rattrib;
  bzero(devString,120);

  if( m_get_pswitch("RESULT") )
  {
    iPICName = "A:" + iPICName;
    m_uppercase(iPICName);
    nChar = m_get_result( iPICName, devString, 120, 0, rtype, rattrib);
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
    status = m_hwf_alias(hwfHeader, iPICName, hwfString);
    status = m_hwf_close(hwfHeader);
    sprintf(devString,"%s",hwfString.c_str());
    nChar = strlen(devString);
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
  if(ratio > 0.0000001 )                                      //                                -
  {                                                           //                                -
    ratioFlag  = 1;                                           //                                -
    flagString = flagString + "|RESAMP";                      //                                -
    XMC_DEBUG0("Resampling is ON.  Adding RESAMP flag.\n");   //                                -
  }                                                           //                                -
  else                                                        //                                -
  {                                                           //                                -
    ratioFlag = 0;                                            //                                -
    XMC_DEBUG0("Resampling is OFF.\n");                       //                                -
  }                                                           //                                -

  // Create the final device string to pass to PIC card.
  //---------------------------------------------------------------------------------------------
  sprintf(&devString[nChar],"|%s",flagString.c_str());

  XMC_DEBUG0("devString  is %s\n", devString);

  // Get the DMABytes flag if present.
  //---------------------------------------------------------------------------------------------
  if( m_get_pswitch("DMABYTES") )                             //---------------------------------
  {                                                           // For SDDS data make the buffer  -
    dmaBytes = (INT32)m_get_dswitch("DMABYTES");              // a multiple of 1080.            -
  }                                                           //                                -
  else dmaBytes  = DMABYTES;                                  //                                -
  XMC_DEBUG0("DMA buffer size in bytes is %ld\n", dmaBytes);  //---------------------------------


  // Set up the output file header control block.
  //---------------------------------------------------------------------------------------------
  CPHEADER oHeader;
  m_initialize(oHeader);
  oHeader.file_name = oFileName;
  oHeader.type      = 1000;
  oHeader.size      = 1024;
  oHeader.xdelta    = 1/fs;
  oHeader.xstart    = 0;
  oHeader.xunits    = 1;
  oHeader.timecode  = xccCurrentJ1950Seconds();

  // Handle the possible different data types (SB, SI, CI, CL).
  //---------------------------------------------------------------------------------------------
  if     ( (dataType=="SB") || (dataType=="INT08") )             // If data type scalar byte.
  {                                                              //
    dmaBits = 8;                                                 //
    oHeader.format = "SB";                                       // Handle as scalar byte.
    genericHandleData = handle08Bit;                             //
  }                                                              //
  else if( (dataType=="SI") || (dataType=="INT16") )             // If data type scalar integer.
  {                                                              //
    dmaBits = 16;                                                //
    oHeader.format = "SI";                                       // Handle as scalar integer.
    genericHandleData = handle16Bit;                             //
  }                                                              //
  else if( (dataType=="CB") || (dataType=="CINT08") )            // If complex scalar integer.
  {                                                              //
    XMC_ERROR_STDOUT("PIC DOES NOT HANDLE CB DATA.\n");          //
    XMC_ERROR_STDOUT("SWITCHING TO CI DATA.\n");                 //
    XMC_ERROR_STDOUT("SWITCHING TO 8 bit conversion.\n");        //
    dmaBits = -16;                                               //
    oHeader.format = "CB";                                       // Handle complex scalar integer.
    genericHandleData = handle16Bit8Bit;                         //
  }                                                              //
  else if( (dataType=="CI") || (dataType=="CINT16") )            // If complex scalar integer.
  {                                                              //
    dmaBits = -16;                                               //
    oHeader.format = "CI";                                       // Handle complex scalar integer.
    genericHandleData = handle16Bit;                             //
  }                                                              //
  else if( (dataType=="CL") || (dataType=="CINT32") )            // If complex scalar long.
  {                                                              //
    dmaBits = -32;                                               //
    oHeader.format = "CL";                                       // Handle complex scalar long.
    genericHandleData = handle32Bit;                             //
  }                                                              //
  else                                                           // Else 
  {                                                              //
    dmaBits = 8;                                                 // Handle as scalar byte.
    oHeader.format = "SB";                                       //
    genericHandleData = handle08Bit;                             //
  }                                                              //------------------------------

  // Deal with decimation.
  //---------------------------------------------------------------------------------------------
  if(tdeci>1)                                                    //------------------------------
  {                                                              //
    oHeader.xdelta = oHeader.xdelta*tdeci;                       // Account for decimation.
    oHeader.xdelta = oHeader.xdelta*2.0;                         // Account for Gray Chip.
  }                                                              //------------------------------

  if(ratioFlag == 1)                                             //------------------------------
  {                                                              //
    oHeader.xdelta = oHeader.xdelta/ratio;                       // Account for Resampler.
  }                                                              //------------------------------

  m_allocate(oHeader);

  // Initialize the PIC card.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG0("About  to initialize PIC card.\n");
  picSpec = xccPICInit( devString, fs );
  XMC_DEBUG0("Done with initialize PIC card.\n");

  // Initialize the PIC IO for record.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG0("About  to initialize PIC IO channel.\n");
  xccPICIOInit(dmaBytes,
	       dmaBits,
	       RECORD,
	       tfreq,
	       tdeci,
	       tgain,
	       picSpec);

  // Resampler.  Goodnight! This was hard to figure out!
  //---------------------------------------------------------------------------------------------
  if(ratioFlag == 1 )                                            //------------------------------
  {                                                              //
    pic_loadfile (&picSpec->picHandle, "res_8x64_60", FLG_FC);   //
    status = pic_setkey( &picSpec->picHandle,                    //
			 picSpec->dma[0].ChannelNumber,          //
			 KEY_RATIO,                              //
			 &ratio,8);                              //
    XMC_DEBUG0("Status of pic_setkey KEY_RATIO is %ld\n",status);//
  }                                                              //------------------------------

  // Get the DMA address.
  //---------------------------------------------------------------------------------------------
  pINT08 = (INT08 *) picSpec->dma[0].dmaMap.vaddr;
  XMC_DEBUG0("Done with initialize PIC IO channel.\n");

  // Initialize the input buffer.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG0("About  to malloc memory.\n");
  oDataINT08 = (INT08 *) xccMallocINT08_Align032( dmaBytes );
  XMC_DEBUG0("Done with malloc memory.\n");

  // Various status.
  //---------------------------------------------------------------------------------------------
  INT32 rate;
  FLT64 freq;
  INT32 ovsr;
  INT32 cn;
  cn = picSpec->nDMA-1;
  rate  = pic_getkeyl(&picSpec->picHandle, picSpec->dma[cn].ChannelNumber, KEY_RATE);
  freq  = pic_getkeyd(&picSpec->picHandle, picSpec->dma[cn].ChannelNumber, KEY_FREQ);
  ovsr  = pic_getkeyl(&picSpec->picHandle, picSpec->dma[cn].ChannelNumber, KEY_OVSR);
  printf("cn is %ld\n",cn);
  printf("picSpec->dma[cn].ChannelNumber is %ld\n", picSpec->dma[cn].ChannelNumber);
  printf("KEY_RATE is %ld\n",rate);
  printf("KEY_FREQ is %f\n",freq);
  printf("KEY_OVSR is %ld\n",ovsr);
  printf("KEY_RATIO is NOT support for pic_getkeyd\n");

  XMC_DEBUG0("Done with init.\n");

  // "Synchronize" the primitive.
  //---------------------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG0("Calling m_sync();\n");

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
  INT32 whogi      = 0;

  INT32 done       = 0;

  // Processing loop.
  //---------------------------------------------------------------------------------------------
  while( !Mc->break_ && !done )
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
      XMC_DEBUG1("DMA STATUS is %ld",dmaDex00);                  // Debug status.               -
      XMC_DEBUG1(" DMA VADDR is %p",picSpec->dma[0].dmaMap.vaddr);//                            -
      XMC_DEBUG1(" DMA ADDRESS is %p",oDataINT08);               //                             -
      XMC_DEBUG1(" \n");                                         //------------------------------
                                                                 //------------------------------
      if     (dmaDex02<dmaDex01)                                 // If normal condition.        -
      {                                                          //                             -
	genericHandleData(dmaDex01, dmaDex02, oDataINT08, pINT08, &oHeader);//                  -
      }                                                          //------------------------------
                                                                 //------------------------------
      else if(dmaDex02>dmaDex01 )                                // If wrapping condition.      -
      {                                                          //                             -
	genericHandleData(bufSize, dmaDex02, oDataINT08, pINT08, &oHeader);//                   -
                                                                 //                             -
	genericHandleData(dmaDex01, 0, oDataINT08, pINT08, &oHeader);//                         -
      }                                                          //------------------------------
    }

    if( loopCounter>(LOOPCOUNT) )                                //------------------------------
    {                                                            // Print out stats on how much -
      FLT32 pv;                                                  // of the time we output data. -
      pv = 100.0*((FLT32)whogi)/((FLT32)loopCounter);            //
      XMC_DEBUG0("loopPercent is %f%%\n", pv);                   //                             -
      XMC_DEBUG0(" \n");                                         //                             -
      loopCounter=0;                                             //                             -
      whogi=0;                                                   //                             -
      if(!(nSamples<1) && (oHeader.offset > nSamples)) done = 1;
      XMC_DEBUG1("offset is %f\n",oHeader.offset);
      //FLT64 tempOffset=oHeader.offset;
      //FLT64 tempDelta=oHeader.xdelta/2;
      //xccPICTC(tempOffset, tempDelta, 0, picSpec);             // FLG_TCINTERP, FLG_TCDELTA
    }                                                            //------------------------------

    if( !(loopCounter % 512) ) usleep( 10000 );
  }

  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG0("Terminating\n");
  xccPIC_DMA_STOP(0, picSpec);
  xccPIC_DMA_CANCEL(0, picSpec);
  xccPICTerm(picSpec);
  xmcFree(oDataINT08);
  m_close(oHeader);
  XMC_DEBUG0("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/


VOID handle08Bit(INT32 dmaDex01, INT32 dmaDex02, VOID *a, VOID *b, CPHEADER *oHeader)
{
  INT32 ii;
  INT32 strt;
  INT32 stop;
  INT32 diff;
  INT08 *pINT08=(INT08 *)b;
  INT08 *oDataINT08=(INT08 *)a;                            //------------------------------
  strt = dmaDex02/sizeof(INT08);                           // Calculate start.            -
  stop = dmaDex01/sizeof(INT08);                           // Calculate stop.             -
  diff = stop-strt;                                        // Calculate difference.       -
  XMC_DEBUG2("strt is %08ld ",strt);                       //                             -
  XMC_DEBUG2(" stop is %08ld ",stop);                      //                             -
  XMC_DEBUG2(" diff is %08ld ",diff);                      //                             -
  XMC_DEBUG2(" \n");                                       //                             -
  for(ii=strt; ii<stop; ii++)                              //                             -
  {                                                        //                             -
    oDataINT08[ii]=pINT08[ii];                             // Copy the data out of DMA.   -
  }                                                        //                             -
  m_filad(*oHeader, &oDataINT08[strt], diff);              // Write the data to file/pipe.-
}                                                          //------------------------------

VOID handle16Bit(INT32 dmaDex01, INT32 dmaDex02, VOID *a, VOID *b, CPHEADER *oHeader)
{
  INT32 ii;
  INT32 strt;
  INT32 stop;
  INT32 diff;
  INT32 cmplxDiv;
  INT16 *pINT16=(INT16 *)b;
  INT16 *oDataINT16=(INT16 *)a;                            //------------------------------
  if( oHeader->format == "CI" )                            // Need to be conscious of 
  {                                                        // complex mode.  Data is 16 
    cmplxDiv = 2;                                          // bits handled in groups of 
  }                                                        // two in "m_filad".
  else                                                     //
  {                                                        //
    cmplxDiv = 1;                                          //
  }                                                        //
  strt = dmaDex02/sizeof(INT16);                           // Calculate start.            -
  stop = dmaDex01/sizeof(INT16);                           // Calculate stop.             -
  diff = stop-strt;                                        // Calculate difference.       -
  XMC_DEBUG2("strt is %08ld ",strt);                       //                             -
  XMC_DEBUG2(" stop is %08ld ",stop);                      //                             -
  XMC_DEBUG2(" diff is %08ld ",diff);                      //                             -
  XMC_DEBUG2(" \n");                                       //                             -
  for(ii=strt; ii<stop; ii++)                              //                             -
  {                                                        //                             -
    oDataINT16[ii]=pINT16[ii];                             // Copy the data out of DMA.   -
  }                                                        //                             -
  m_filad(*oHeader, &oDataINT16[strt], diff/cmplxDiv);     // Write the data to file/pipe.-
}                                                          //------------------------------

VOID handle32Bit(INT32 dmaDex01, INT32 dmaDex02, VOID *a, VOID *b, CPHEADER *oHeader)
{
  INT32 ii;
  INT32 strt;
  INT32 stop;
  INT32 diff;
  INT32 cmplxDiv;
  INT32 *pINT32=(INT32 *)b;
  INT32 *oDataINT32=(INT32 *)a;                            //------------------------------
  if( oHeader->format == "CL" )                            // Need to be conscious of 
  {                                                        // complex mode.  Data is 32
    cmplxDiv = 2;                                          // bits handled in groups of
  }                                                        // two in "m_filad".
  else                                                     //
  {                                                        //
    cmplxDiv = 1;                                          //
  }                                                        //
  strt = dmaDex02/sizeof(INT32);                           // Calculate start.            -
  stop = dmaDex01/sizeof(INT32);                           // Calculate stop.             -
  diff = stop-strt;                                        // Calculate difference.       -
  XMC_DEBUG2("strt is %08ld ",strt);                       //                             -
  XMC_DEBUG2(" stop is %08ld ",stop);                      //                             -
  XMC_DEBUG2(" diff is %08ld ",diff);                      //                             -
  XMC_DEBUG2(" \n");                                       //                             -
  for(ii=strt; ii<stop; ii++)                              //                             -
  {                                                        //                             -
    oDataINT32[ii]=pINT32[ii];                             // Copy the data out of DMA.   -
  }                                                        //                             -
  m_filad(*oHeader, &oDataINT32[strt], diff/cmplxDiv);     // Write the data to file/pipe.-
}                                                          //------------------------------


VOID handle16Bit8Bit(INT32 dmaDex01, INT32 dmaDex02, VOID *aINT08, VOID *bINT16, CPHEADER *oHeader)
{
  INT32 ii;
  INT32 jj;
  INT32 strt;
  INT32 stop;
  INT32 diff;
  INT32 cmplxDiv;
  INT08 *pINT08=(INT08 *)bINT16;
  INT08 *oDataINT08=(INT08 *)aINT08;                       //------------------------------
  if( (oHeader->format == "CB") )                          // Need to be conscious of     -
  {                                                        // complex mode.  Data is 16   -
    cmplxDiv = 2;                                          // bits converted to 8 bits    -
  }                                                        // and handled in groups of    -
  else                                                     // two in "m_filad"            -
  {                                                        //                             -
    cmplxDiv = 1;                                          //                             -
  }                                                        //                             -
  strt = dmaDex02/sizeof(INT08);                           // Calculate start.            -
  stop = dmaDex01/sizeof(INT08);                           // Calculate stop.             -
  diff = stop-strt;                                        // Calculate difference.       -
  XMC_DEBUG2("strt is %08ld ",strt);                       //                             -
  XMC_DEBUG2(" stop is %08ld ",stop);                      //                             -
  XMC_DEBUG2(" diff is %08ld ",diff);                      //                             -
  XMC_DEBUG2(" \n");                                       //                             -
  jj = strt/2;                                             // 8 bit data start.           -
  for(ii=strt; ii<stop; ii+=2)                             //                             -
  {                                                        //                             -
    oDataINT08[jj]=pINT08[ii];                             // Copy the data out of DMA.   -
    jj++;                                                  // 8 bit data increment.       -
  }                                                        //                             -
  m_filad(*oHeader, &oDataINT08[strt/2], diff/cmplxDiv);   // Write the data to file/pipe.-
}                                                          //------------------------------
