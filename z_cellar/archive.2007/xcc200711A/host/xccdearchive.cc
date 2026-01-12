/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccdearchive.cc                                                                        -
//                                                                                              -
// Desc: This primitive is a generic data de-archiver.                                          -
//                                                                                              -
// Args: iFileName  - Base name of archive.             <A:>                                    -
//       oFileName  - Name of output pipe or file.      <A:>                                    -
//       startTime  - Desired start time (0=Beginning). <T:>                                    -
//       duration   - Desired duration (0=all).         <T:>                                    -
//       oDireName1 - Directory name.                   <A:>                                    -
//       oDireName2 - Directory name.                   <A:>                                    -
//       ...        - (Up to 16 directories).           <A:>                                    -
//                                                                                              -
// Swch: TL         - Switch to set transfer length.                                            -
//       TS         - Switch to set transfer samples.                                           -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       08/12/2005 ptb  Initial Code.                                                          -
//                                                                                              -
//                           iFileName                                                          -
//                           oFileName                                                          -
//                           oDireName1                                                         -
//                           oDireName2                                                         -
//                           ... (Up to 16 directories)                                         -
//                            /TL                                                               -
//                            /TS                                                               -
//                             |                                                                -
//                             V                                                                -
//     :---------:     :-----------------:     :-----------:                                    -
//     | Archive |---> | xccdearchive.cc |---> | FILE/PIPE |                                    -
//     :---------:-:   :-----------------:     :-----------:                                    -
//       | Archive |           |                                                                -
//       :---------:           V                                                                -
//                        Debug Statements                                                      -
//                                                                                              -
// Note:                                                                                        -
//                                                                                              -
// Examples:                                                                                    -
// pipe on                                                                                      -
// XCCDEARCHIVE/tl=1080*1024 test1 _s1(ps=1080*1024*4) /data11/win2_20050831/test01/            -
// XCCUDPPLAY/tl=1080/pause=0.25 _s1 "192.168.1.200" 5000                                       -
// pipe off                                                                                     -
// pipe on                                                                                      -
// xccdearchive pictest _s1(ps=32M) /data11/steswd/                                             -
// ubi _s1 psdfile 1024*32 hamm                                                                 -
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
#include "stack_utils.h"
#include "string_utils.h"
#include "vector_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define NDIR       16
#define MAXFILES   512

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
VOID xccvQuickSortStringLast19( CHR08 **string, INT32 left, INT32 rght);
INT32 strcmpLast19(  char **s1,   char **s2);

/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
VOID mainroutine()
{
  INT32 ii;
  FLT64 dt;
  int_4 nGot;
  UNT64 nBytes;
  INT32 argNum;
  INT32 theIndex;
  INT32 nDires=1;
  INT32 xferLngth;
  INT32 xferSamps;
  UNT64 strtSample;
  UNT64 stopSample;
  UNT64 currSample;
  INT32 stackStatus;
  INT08 *iDataINT08;
  CHR08 *tempString;
  INT32 fileCounter=0;
  CHR08 pathName[128];
  CHR08 theArchiveName[128];
  CHR08 theArchiveNamePrevious[128];
  xccArchiveSpec *archiveSpec[NDIR];

  FLT64 durationW,  durationF;
  FLT64 startTimeW, startTimeF;

  // Switch variables.

  // File name variables.
  string iFileName;
  string oFileName;
  string iDireName[NDIR];

  // File header variables.
  CPHEADER iHeader;
  CPHEADER oHeader;

  // Get command line parameters iFileName, oFileName, iDireName.
  //---------------------------------------------------------------------------------------------
  iFileName    = m_apick(1);
  oFileName    = m_apick(2);
  /*---------*/  m_tpick(3,startTimeW,startTimeF);
  /*---------*/  m_tpick(4,durationW,durationF);
  iDireName[0] = m_apick(5);

  XMC_DEBUG("iFileName  is %s\n",   iFileName.c_str());
  XMC_DEBUG("oFileName  is %s\n",   oFileName.c_str());
  XMC_DEBUG("startTimeW is %f\n",   startTimeW);
  XMC_DEBUG("startTimeF is %f\n",   startTimeF);
  XMC_DEBUG("durationW  is %f\n",   durationW);
  XMC_DEBUG("durationF  is %f\n",   durationF);
  XMC_DEBUG("iDireName  is %s\n",   iDireName[0].c_str());

  // Get extra iDireName command line parameters if present.
  //---------------------------------------------------------------------------------------------
  for(ii=1; ii<NDIR; ii++)                                // For all possible directories execpt
  {                                                       // the first.
    argNum = 5+ii;                                        // We currently have a base of 5 
                                                          // arguments.
    if(m_ppick(argNum))                                   // If there is a directory argument for
    {                                                     // this argument number then
      iDireName[ii] = m_apick(argNum);                    // go get it and 
      nDires++;                                           // increment our directory counter.
      XMC_DEBUG("iDireName  is %s\n", iDireName[ii].c_str());//----------------------------------
    }
  }
    
  // If the directory name does not end in a '/' character add one.
  //---------------------------------------------------------------------------------------------
  for(ii=0; ii<NDIR; ii++)                                 // For each possible directory.
  {                                                        //
    INT32 l;                                               //
    CHR08 tempString[1024];                                //
    sprintf(tempString, "%s", iDireName[ii].c_str());      // Create a temporary string
    l = strlen(tempString);                                // Get the length of the string.
    if( tempString[l-1] != '/' )                           // If the last character is not an "/"
    {                                                      // Then
      iDireName[ii] = iDireName[ii] + "/";                 // Add one to the end of the 
    }                                                      // end of the "iDireName[ii]" string.
  }                                                        //------------------------------------

  // Initialize the archive specifications.
  //---------------------------------------------------------------------------------------------
  sprintf(pathName,"%s%s", iDireName[0].c_str(), iFileName.c_str());    // Make the first archive
  archiveSpec[0] = xccArchiveInit(pathName, "tmp", MAXFILES*NDIR);      // spec really big.
                                                                        //
  for(ii=1; ii<nDires; ii++)                                            // Create the other
  {                                                                     // archive specs.
    sprintf(pathName,"%s%s", iDireName[ii].c_str(), iFileName.c_str()); // 
    archiveSpec[ii] = xccArchiveInit(pathName, "tmp", MAXFILES );       //
  }                                                                     //-----------------------

  // Reestablish the archive(s). (xccArchiveReestablish).
  //---------------------------------------------------------------------------------------------
  for(ii=0; ii<nDires; ii++) 
  {
    xccArchiveReestablish(archiveSpec[ii]);
  }

  // Consolidate all the entries to one archive specification.
  //---------------------------------------------------------------------------------------------
  for(ii=1; ii<nDires; ii++)                                                 // Pop the filename
  {                                                                          // for all possible
    while(xccStringStackPop(archiveSpec[ii]->fileNameStack, &tempString)==0) // directories
    {                                                                        // except the first.
      xccStringStackPush(archiveSpec[ 0]->fileNameStack, tempString);        // Push the
    }                                                                        // filename to the
                                                                             // first spec.
    xccArchiveTerm( archiveSpec[ii] );                                       // Terminate
  }                                                                          // unneeded spec.

  // Check for -1 index
  //---------------------------------------------------------------------------------------------
  if(archiveSpec[ 0]->fileNameStack->index == -1)
  {
    XMC_ERROR_STDERR("STACK INDEX IS -1.  EMPTY STACK!");
  }

  // Need to sort stack based on file name only.  Do not sort based on path name.
  //---------------------------------------------------------------------------------------------
  xccvQuickSortStringLast19( (CHR08 **)archiveSpec[ 0]->fileNameStack->theStack,
			     0,
			     archiveSpec[0]->fileNameStack->index );

  // Flip stack to prepare for poping.
  //---------------------------------------------------------------------------------------------
  xccStackFlipVOIDP( archiveSpec[ 0]->fileNameStack );

  // Search for the archive file segment that contains the start time.
  //---------------------------------------------------------------------------------------------
  theIndex = archiveSpec[0]->fileNameStack->index;
  for(ii=0; ii<=theIndex; ii++)
  {
    CHR08 *p2CHR08;

    // Get each archive file segment name.
    //-------------------------------------------------------------------------------------------
    p2CHR08 = (char *)archiveSpec[0]->fileNameStack->theStack[theIndex-ii];
    sprintf(theArchiveName,"%s",p2CHR08);
    //XMC_DEBUG("%d %d %s\n",ii, theIndex-ii, theArchiveName);

    // Specify input file name in input header control block. (iFileName).
    //-------------------------------------------------------------------------------------------
    iHeader.file_name  = theArchiveName;

    // Specify "type_allow" in input header control block. (1000 and 2000).
    //-------------------------------------------------------------------------------------------
    iHeader.type_allow = "1000,2000,5001";

    // Specify "format_allow" in input header control block. (SB,SI,SL,SF,SD,CB,CI,CL,CF,CD).
    //-------------------------------------------------------------------------------------------
    iHeader.format_allow = "SB,SI,SL,SF,SD,CB,CI,CL,CF,CD,NH";

    // Open file and check to see if input header control block is "OK". (m_inok).
    //-------------------------------------------------------------------------------------------
    m_inok(iHeader);

    // Close the file.
    //-------------------------------------------------------------------------------------------
    m_close(iHeader);

    // Check timecode of archive file segment with requested start time. 
    //-------------------------------------------------------------------------------------------
    if( iHeader.timecode < (startTimeW+startTimeF) )   // If the time code is less then the 
    {                                                  // start time then increment the
      CHR08 s[256];
      string timeString;
      fileCounter++;                                   // fileCounter variable.
      m_times2str(iHeader.timecode, 0.0, ' ', timeString);
      sprintf(s,"%s",timeString.c_str());
      XMC_DEBUG("File with time code %s may be popped off the stack.\n",s);
    }                                                  //
  }

  XMC_DEBUG("fileCounter is %d\n",fileCounter);

  // Pop unneeded archive file segments.
  //---------------------------------------------------------------------------------------------
  for(ii=0; ii<(fileCounter-1); ii++)
  {
    CHR08 s[256];
    string timeString;
    m_times2str(iHeader.timecode, 0.0, ' ', timeString);
    sprintf(s,"%s",timeString.c_str());
    stackStatus = xccStringStackPop(archiveSpec[0]->fileNameStack, &tempString);
    XMC_DEBUG("Popping file %s.\n",tempString);
  }

  // Proceed with the dearchive process by poping the first archive file name.
  //---------------------------------------------------------------------------------------------
  stackStatus = xccStringStackPop(archiveSpec[0]->fileNameStack, &tempString);

  sprintf(theArchiveName,"%s",tempString);

  // Specify input file name in input header control block. (iFileName).
  //---------------------------------------------------------------------------------------------
  iHeader.file_name  = theArchiveName;

  // Specify "type_allow" in input header control block. (1000 and 2000).
  //---------------------------------------------------------------------------------------------
  iHeader.type_allow = "1000,2000,5001";

  // Specify "format_allow" in input header control block. (SB,SI,SL,SF,SD,CB,CI,CL,CF,CD).
  //---------------------------------------------------------------------------------------------
  iHeader.format_allow = "SB,SI,SL,SF,SD,CB,CI,CL,CF,CD,NH";

  // Open file and check to see if input header control block is "OK". (m_inok).
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
  XMC_DEBUG("iHeader.bpe is %d\n" ,iHeader.bpe);

  // Set the transfer length variable in the input header control block.
  //---------------------------------------------------------------------------------------------
  iHeader.xfer_len = xferSamps;
  iHeader.cons_len = -1;

  // Initialize the input buffer to recieve data.
  //---------------------------------------------------------------------------------------------
  iDataINT08 = xccMallocINT08_Align032( xferLngth );

  // Calculate start sample and stop sample
  //---------------------------------------------------------------------------------------------
                                                                // Calculate the difference 
  dt         = startTimeW + startTimeF - iHeader.timecode;      // between the start of the 
                                                                // archive and the start time
                                                                // to de-archive. 
                                                                //
  if( dt < 0.0 )                                                // If this difference is
  {                                                             // negative, make differnce zero.
    dt = 0.0;                                                   //
  }                                                             //
  strtSample = (UNT64) ( dt * (1.0/iHeader.xdelta) );           // Calc. start sample,
  stopSample = (UNT64) ( (dt + durationW + durationF) * (1.0/iHeader.xdelta) ); // stop sample,
  currSample = 0;                                               // and set current samp. to zero.

                                                                //-------------------------------
  if(m_get_pswitch("SDDS"))                                     // Test for SDDS switch         -
  {                                                             //                              -
    strtSample  = strtSample - (strtSample%540) + 540;          // Make strt on packet Boundry. -
    stopSample  = stopSample - (stopSample%540) + 540;          // Make stop on packet Boundry. -
  }                                                             //-------------------------------

  // Set up the output file header.
  //---------------------------------------------------------------------------------------------
  m_propagate(iHeader, oHeader);
  oHeader.file_name = oFileName;
  oHeader.timecode = iHeader.timecode + dt;
  m_allocate(oHeader);

  // "Synchronize" not "sink".
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Calling m_sync();\n");
  m_sync();

  // Start the processing loop.
  //---------------------------------------------------------------------------------------------
  while( !Mc->break_ )
  {

    // Bring in the data and write out the data.
    // Coarse sample percision because it is based on input block size (nGot and xferSamps).
    // Fine tune later.
    //-------------------------------------------------------------------------------------------
    while(nGot==xferSamps)                                 //
    {                                                      //
      m_grabx(iHeader, iDataINT08, nGot);                  // Grab data from archive file.
                                                           //
      if     ( strtSample == 0 && stopSample == 0 )        // If de-archiving the entire archive.
      {                                                    //
	m_filad(oHeader, iDataINT08, nGot);                // Write out the data
      }                                                    //
      else if( (currSample >= strtSample) && (currSample < stopSample) ) // If making a cut
      {                                                    //
	m_filad(oHeader, iDataINT08, nGot);                // Write out the data
      }                                                    //
      else if(currSample > stopSample)                     // If done
      {                                                    //
	nGot = 0;                                          // Set nGot to zero for falling out.
      }                                                    //
                                                           //
      currSample += nGot;                                  // Increment current sample.
                                                           //
    }    

    // When done close this input archive file.
    //-------------------------------------------------------------------------------------------
    m_close(iHeader);
    XMC_DEBUG("Closing input archive file.\n");

    // Pop the the next filename off the stack.
    //-------------------------------------------------------------------------------------------
    stackStatus = xccStringStackPop(archiveSpec[0]->fileNameStack, &tempString);
    sprintf(theArchiveName,"%s",tempString);

    xccArchiveReport( archiveSpec[0] );

    // Break out if we are done.
    //-------------------------------------------------------------------------------------------
    if( (stackStatus < 0) )
    {
      Mc->break_ = 1;
      XMC_DEBUG("stackStatus is %ld\n", stackStatus);
    }

    // Or just keep going.
    //-------------------------------------------------------------------------------------------
    else
    {
      // Specify input file name in input header control block. (iFileName).
      //-------------------------------------------------------------------------------------------
      iHeader.file_name  = theArchiveName;

      // Specify "type_allow" in input header control block. (1000 and 2000).
      //-------------------------------------------------------------------------------------------
      iHeader.type_allow = "1000,2000,5001";
      
      // Specify "format_allow" in input header control block. (SB,SI,SL,SF,SD,CB,CI,CL,CF,CD).
      //-------------------------------------------------------------------------------------------
      iHeader.format_allow = "SB,SI,SL,SF,SD,CB,CI,CL,CF,CD,NH";
      
      // Check to see if input header control block is "OK". (m_inok).
      //-------------------------------------------------------------------------------------------
      m_inok(iHeader);

      // Reset nGot to equal xferSamps.
      //-------------------------------------------------------------------------------------------
      nGot = xferSamps;
      
      XMC_DEBUG("xferLngth   is %ld\n",xferLngth);
      XMC_DEBUG("xferSamps   is %ld\n",xferSamps);
      XMC_DEBUG("nGot        is %ld\n",xferSamps);
      XMC_DEBUG("iHeader.bpe is %d\n" ,iHeader.bpe);

      // Set the transfer length variable in the input header control block.
      //-------------------------------------------------------------------------------------------
      iHeader.xfer_len = xferSamps;
      iHeader.cons_len = -1;
    }
  }

  // When done terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  m_close(oHeader);
  xmcFree(iDataINT08);
  xccArchiveTerm( archiveSpec[0] );
  XMC_DEBUG("Terminated\n");

  // Having Mc->break = 1 will kill a calling Macro in non-pipe mode.
  // Provide better fix later. 
  //---------------------------------------------------------------------------------------------
  sleep(2);
  Mc->break_ = 0;
  
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/

VOID xccvQuickSortStringLast19( CHR08 **string, INT32 left, INT32 rght)
{
  CHR08 *x;
  CHR08 *y;
  INT32 ii;
  INT32 jj;

  ii = left;
  jj = rght;
  x = string[(left+rght)/2];

  do
  {
    while( (strcmpLast19(&string[ii], &x) < 0) && (ii < rght) ) ii++; 
    while( (strcmpLast19(&string[jj], &x) > 0) && (jj > left) ) jj--;

    if(ii<=jj)
    {
      y = string[ii];
      string[ii] = string[jj];
      string[jj] = y;
      ii++;
      jj--;
    }
  }while(ii<=jj);

  if(left < jj) 
  {
    xccvQuickSortStringLast19(string, left, jj);
  }
  if(ii < rght)
  {
    xccvQuickSortStringLast19(string, ii, rght);
  }
}


INT32 strcmpLast19(  char **s1,   char **s2)
{
  INT32 l1=strlen(*s1);
  INT32 l2=strlen(*s2);

  INT32 bIndex1=l1-19;
  INT32 bIndex2=l2-19;

  printf("Comparing %s and %s \n", &s1[0][bIndex1], &s2[0][bIndex2]);

  return(strcmp(&s1[0][bIndex1],&s2[0][bIndex2]));
}
