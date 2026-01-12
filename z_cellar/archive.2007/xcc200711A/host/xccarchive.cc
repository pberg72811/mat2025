/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccarchive.cc                                                                          -
//                                                                                              -
// Desc: This primitive is a generic data archiver.                                             -
//                                                                                              -
// Args: iFileName  - Base name of archive.              <A:>                                   -
//       oFileName  - Name of output pipe or file.       <A:>                                   -
//       nBytes     - File size in bytes.                <D:>                                   -
//       oDireName1 - Directory name.                    <A:>                                   -
//       nFiles     - Number of files is each directory. <D:>                                   -
//       oDireName2 - Directory name.                    <A:>                                   -
//       nFiles     - Number of files is each directory. <D:>                                   -
//       ...        - (Up to 16 directories).            <A:>                                   -
//                                                                                              -
// Swch: NRT        - Will read the hcb.xdelta value and keep track of samples                  -
//                    in order to calculate time tags and file names.                           -
//       TL         - Switch to set transfer length.                                            -
//       TS         - Switch to set transfer samples.                                           -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       01/25/2005 ptb  Initial Code.                                                          -
//       02/09/2006 ptb  Added non-real time mode.                                              -
//       05/16/2006 ptb  SI unit update. (N,Kg,m,sec)                                           -
//                                                                                              -
//                           iFileName                                                          -
//                           oFileName                                                          -
//                           nBytes                                                             -
//                           oDireName1                                                         -
//                           nFiles                                                             -
//                           oDireName2                                                         -
//                           nFiles                                                             -
//                           ... (Up to 16 directories)                                         -
//                             /NRT                                                             -
//                             /TL                                                              -
//                             /TS                                                              -
//                              |                                                               -
//                              V                                                               -
//     :-----------:    :---------------:     :---------:                                       -
//     | FILE/PIPE |--->| xccarchive.cc |---> | Archive |                                       -
//     :-----------:    :---------------:     :---------:-:                                     -
//                              |               | Archive |                                     -
//                              V               :---------:                                     -
//                        Debug Statements                                                      -
//                                                                                              -
// Note:                                                                                        -
//                                                                                              -
// Examples:                                                                                    -
// pipe on                                                                                      -
// xccpicrecord/cint16/replay=2 _stream(ps=32M) 10e6 PIC1_A2D_TUN1I 1e6 16 2                    -
// xccarchive _stream pictest 1024*1024*1024 /data12/steswd/ 10                                 -
// pipe off                                                                                     -
//                                                                                              -
// results PICFLAGS "ipaddr1=192.168.0.9|join1=224.2.2.2|ipdisc=224.2.2.2|ioc=iix|rxrawsdds"    -
// pipe on                                                                                      -
// xccpicrecord/replay=2/SI/flags=^PICFLAGS _stream(ps=32M) 1024*1024*4 10e6 pic1_sdds12a       -
// xccarchive _stream pictest1 1024*1024*1024*8 /data11/steswd/ 10                              -
// pipe off                                                                                     -
//                                                                                              -
// pipe on                                                                                      -
// xccsddsrecord/ts=1080*1024*4  _stream(ps=32M) "192.168.0.30" "224.3.3.3" 5000                -
// xccarchive _stream pictest2 1024*1024*1024*8 /data11/steswd/ 10                              -
// pipe off                                                                                     -
//                                                                                              -
// results PICFLAGS "ipaddr1=192.168.0.9|join1=224.2.2.2|ipdisc=224.2.2.2|ioc=iix|rxrawsdds"    -
// pipe on                                                                                      -
// xccpicrecord/Si/dmabytes=1024*1080*4/flags=^PICFLAGS _stream(ps=128M) 10e6 pic1_sdds12a      -
// xccarchive/tl=1024*1024*32 _stream(ps=128M) pictest1 1024*1024*1024 /data14/steswd/ 25       -
// pipe off                                                                                     -
//                                                                                              -
// results PICFLAGS "ipaddr1=192.168.0.9|join1=224.2.2.2|join=224.3.3.3|ipdisc=224.2.2.2|ioc=iix|rxrawsdds"
// pipe on                                                                                      -
// xccpicrecord/Si/dmabytes=1024*1080*4/flags=^PICFLAGS _stream(ps=128M) 10e6 pic1_sdds12a      -
// xccarchive/tl=1024*1024*32 _stream(ps=128M) pictest1 1024*1024*1024 /data14/steswd/ 25       -
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
#include <primitive.h>
#include "xmc.h"
#include "archive_utils.h"
#include "orbit_utils.h"
#include "socket_utils.h"
#include "stack_utils.h"
#include "string_utils.h"
#include "vector_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define NDIR       16

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
  UNT32 ii;
  int_4 nGot;
  UNT64 nBytes;
  INT32 argNum;
  INT32 archDex;
  CHR08 *p2String;
  CHR08 pathName[128];
  CHR08 theArchiveName[128];
  xccArchiveSpec *archiveSpec[NDIR];
  UNT64 nBatches;
  UNT64 samplesPerArchive;
  INT08 *iDataINT08;
  UNT64 nFiles[NDIR];
  UNT32 nDires=1;
  INT64 timeTag;
  INT32 realTimeFlag;
  UNT32 sampleCount=0;

  // Switch variables.
  INT32 xferLngth;
  INT32 xferSamps;

  // File name variables.
  string iFileName;
  string oFileName;
  string oDireName[NDIR];

  // File header variables.
  CPHEADER iHeader;
  CPHEADER oHeader;

  // Get command line parameters iFileName, oFileName, nBytes, oDireName, and nFiles.
  //---------------------------------------------------------------------------------------------
  iFileName    = m_apick(1);
  oFileName    = m_apick(2);
  nBytes       = (UNT64) m_dpick(3);
  oDireName[0] = m_apick(4);
  nFiles[0]    = (UNT64) m_dpick(5);

  XMC_DEBUG("iFileName  is %s\n",   iFileName.c_str());
  XMC_DEBUG("oFileName  is %s\n",   oFileName.c_str());
  XMC_DEBUG("nBytes     is %lld\n", nBytes);
  XMC_DEBUG("oDireName  is %s\n",   oDireName[0].c_str());
  XMC_DEBUG("nFiles     is %lld\n", nFiles[0]);

  // Get extra oDireName, and nFiles command line parameters if present.
  //---------------------------------------------------------------------------------------------
  for(ii=1; ii<NDIR; ii++)
  {
    argNum = 5+ii+(ii-1);
    if(m_ppick(argNum))
    {
      oDireName[ii] = m_apick(argNum);
      nFiles[ii]    = (UNT64) m_dpick(argNum+1);
      nDires++;
      XMC_DEBUG("direName is %s\n",  oDireName[ii].c_str());
      XMC_DEBUG("nFiles   is %lld\n",nFiles[ii]);
    }
  }

  // If the directory name does not end in a '/' character add one.
  //---------------------------------------------------------------------------------------------
  for(ii=0; ii<NDIR; ii++)
  {
    INT32 l;
    CHR08 tempString[1024];
    sprintf(tempString, "%s", oDireName[ii].c_str());
    l = strlen(tempString);
    if( tempString[l-1] != '/' )
    {
      oDireName[ii] = oDireName[ii] + "/";
    }
  }

  // Check for the not real time flag.
  //---------------------------------------------------------------------------------------------
  if(m_get_pswitch("NRT"))
  {
    realTimeFlag = 0;
  }
  else
  {
    realTimeFlag = 1;
  }

  // Specify input file name in input header control block. (iFileName).
  //---------------------------------------------------------------------------------------------
  iHeader.file_name    = iFileName;

  // Specify "type_allow" in input header control block. (1000 and 2000).
  //---------------------------------------------------------------------------------------------
  iHeader.type_allow   = "1000,2000";

  // Specify "format_allow" in input header control block. (SB,SI,SL,SF,SD,CB,CI,CL,CF,CD).
  //---------------------------------------------------------------------------------------------
  iHeader.format_allow = "SB,SI,SL,SF,SD,CB,CI,CL,CF,CD";

  // Check to see if input header control block is "OK". (m_inok).
  //---------------------------------------------------------------------------------------------
  m_inok(iHeader);
    
  // Check for transfer length (TL) or transfer samples (TS) switch.
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
  }                                              //----------------------------------------------
  nGot = xferSamps;

  XMC_DEBUG("xferLngth   is %ld\n",xferLngth);
  XMC_DEBUG("xferSamps   is %ld\n",xferSamps);
  XMC_DEBUG("nGot        is %ld\n",xferSamps);
  XMC_DEBUG("iHeader.bpe is %d\n", iHeader.bpe);

  // Set the transfer length variable in the input header control block.
  //---------------------------------------------------------------------------------------------
  iHeader.xfer_len = xferSamps;
  iHeader.cons_len = -1;

  // Calculate samples per archive file and number of batches from nBytes and input "bpe".
  //---------------------------------------------------------------------------------------------
  samplesPerArchive = nBytes/iHeader.bpe;
  samplesPerArchive = samplesPerArchive - (samplesPerArchive % xferSamps);
  nBatches          = samplesPerArchive/xferSamps;
  if(nBatches<1) XMC_ERROR_STDOUT("Transfer Length and Number of Bytes needs adjustment\n");

  // Initialize the input buffer to recieve data.
  //---------------------------------------------------------------------------------------------
  iDataINT08  = xccMallocINT08_Align032( xferLngth );

  // Initialize the archive. (xccArchiveInit).
  //---------------------------------------------------------------------------------------------
  for(ii=0; ii<nDires; ii++)
  {
    sprintf(pathName,"%s%s", oDireName[ii].c_str(), oFileName.c_str());
    archiveSpec[ii] = xccArchiveInit(pathName, "tmp", nFiles[ii] );
  }

  // Reestablish the archive(s). (xccArchiveReestablish).
  //---------------------------------------------------------------------------------------------
  for(ii=0; ii<nDires; ii++) 
  {
    xccArchiveReestablish(archiveSpec[ii]);
  }

  // Start with first archive.
  //---------------------------------------------------------------------------------------------
  archDex = 0;

  // "Synchronize" not "sink".
  //---------------------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG("Calling m_sync();\n");

  timeTag = xccCurrentJ1970Seconds();

  // Start the processing loop.
  //---------------------------------------------------------------------------------------------
  while( !Mc->break_ )
  {
    // Generate an archive file name "theArchiveName". (xccArchiveProcess).
    //-------------------------------------------------------------------------------------------
    p2String = xccArchiveProcess( archiveSpec[archDex] );
    sprintf(theArchiveName, "%s", p2String);

    // Create the archive file header control block.
    //-------------------------------------------------------------------------------------------
    m_initialize(oHeader);
    oHeader.file_name = theArchiveName;
    oHeader.type      = iHeader.type;
    oHeader.size      = samplesPerArchive;
    oHeader.xdelta    = iHeader.xdelta;
    oHeader.xstart    = 0;
    oHeader.xunits    = iHeader.xunits;
    if( !realTimeFlag )
    {
      oHeader.timecode  = timeTag + 
	                  ((INT64)(((FLT64)sampleCount) * iHeader.xdelta)) + 
	                  (xcc_JULIAN_SECONDS_JAN1_1970 - xcc_JULIAN_SECONDS_JAN1_1950);
    }
    else
    {
      oHeader.timecode = xccCurrentJ1950Seconds();
    }
    oHeader.format    = iHeader.format;

    oHeader.subsize   = iHeader.subsize;
    oHeader.ystart    = iHeader.ystart;
    oHeader.ydelta    = iHeader.ydelta;
    oHeader.yunits    = iHeader.yunits;
    oHeader.bpe       = iHeader.bpe;
    m_allocate(oHeader);
    XMC_DEBUG("Archive file is %s.\n",theArchiveName);
    XMC_DEBUG("File format is %c%c.\n",oHeader.format[0],oHeader.format[1]);

    // 
    //-------------------------------------------------------------------------------------------
    FLT32 nSecs;
    INT32 temp=1;
    struct timespec timespec1;
    struct timespec timespec2;

    // 
    //-------------------------------------------------------------------------------------------
    clock_gettime(CLOCK_REALTIME, &timespec1);

    // For each calculated batch bring in data and send to archive file.
    //-------------------------------------------------------------------------------------------
    for( ii=0; ii<nBatches; ii++)
    {
      m_grabx(iHeader, iDataINT08, nGot);

      m_filad(oHeader, iDataINT08, nGot);
   
      m_hcbfunc(oHeader, HCBF_FLUSH, (int_4 *) &temp);

      sampleCount += nGot;

      if(Mc->break_) break;
      if(nGot==0)    {Mc->break_=1; break;}
    }    

    clock_gettime(CLOCK_REALTIME, &timespec2);

    nSecs = timespec2.tv_sec-timespec1.tv_sec;

    XMC_DEBUG("nSecs is %f \n",nSecs );
    XMC_DEBUG("Bytes per second is %f \n", ((FLT32)nBytes)/nSecs );

    if( !realTimeFlag )
    {
      archiveSpec[archDex]->timeTag = timeTag + (INT64)(((FLT64)sampleCount) * iHeader.xdelta);
    }
    else
    {
      archiveSpec[archDex]->timeTag = 0;
    }

    // When done close this archive file.
    //-------------------------------------------------------------------------------------------
    m_close(oHeader);
    XMC_DEBUG("archDex currently at %ld\n",archDex);
    XMC_DEBUG("Number of files cycled through is %lu.\n",
		      archiveSpec[archDex]->filesCycled);
    XMC_DEBUG("Number of files mod stack size %lu.\n",
		      archiveSpec[archDex]->filesCycled%archiveSpec[archDex]->stackSize);
    XMC_DEBUG("Closing archive file.\n");

    // Is it time to switch archive directories?  If so, do it.
    //-------------------------------------------------------------------------------------------
    if((archiveSpec[archDex]->filesCycled % archiveSpec[archDex]->stackSize)==0)
    {
      xccArchiveReport( archiveSpec[archDex] );
      archDex++;
      archDex = archDex % nDires;
      xccArchiveReport( archiveSpec[archDex] );
    }

  }

  // When done terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  m_close(iHeader);
  for(ii=0; ii<nDires; ii++) 
  {
    xccArchiveTerm( archiveSpec[ii] );
  }
  XMC_DEBUG("Terminated\n");
  
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
