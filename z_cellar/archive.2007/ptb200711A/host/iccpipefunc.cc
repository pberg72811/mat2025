/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: iccpipefunc.cc                                                                         -
//                                                                                              -
// Desc: This primitive controls a data fan out from the input file/pipe to as                  -
//       many as 16 output files/pipes.  Data can be block decimated using the                  -
//       DTL switch.  Start blocks can be specified using the STL switch.                       -
//                                                                                              -
// Args: iFileName  - The name of the input file.                   <A:>                        -
//       oFileName1 - The name of the 1st output file.              <A:>                        -
//       oFileName2 - The name of the 2nd output file (if present). <A:>                        -
//       oFileName3 - The name of the 3rd output file (if present). <A:>                        -
//                                                                                              -
// Swch: /TL   - Transfer length.                                                               -
//       /TS   - Transfer samples.                                                              -
//       /DTL1 - Decimated transfer length 1.                                                   -
//       /DTL2 - Decimated transfer length 2.                                                   -
//       /DTL3 - Decimated transfer length 3.  (Keeps going up to 16.)                          -
//       /STL1 - Decimated transfer length 1.                                                   -
//       /STL2 - Decimated transfer length 2.                                                   -
//       /STL3 - Decimated transfer length 3.  (Keeps going up to 16.)                          -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       08/27/2003 ptb  Initial Code.  Used "pipefunc.for" from rdh 02/27/01 as example.       -
//       08/27/2003 ptb  Added staggard input/output.                                           -
//       05/15/2003 ptb  Moved to GED option tree.                                              -
//                                                                                              -
//                           iFileName                                                          -
//                           oFileName1                                                         -
//                           oFileName2                                                         -
//                           oFileName3                                                         -
//                           ... (Up to 16 files or pipes)                                      -
//                             /TL                                                              -
//                             /TS                                                              -
//                              |                                                               -
//                              V                                                               -
//     :-----------:    :----------------:     :-----------:                                    -
//     | FILE/PIPE |--->| iccpipefunc.cc |---> | FILE/PIPE |                                    -
//     :-----------:    :----------------:     :-----------:-:                                  -
//                              |                | FILE/PIPE |                                  -
//                              V                :-----------:                                  -
//                        Debug Statements                                                      -
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

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG      TRUE
#define DEBUG_TYPE  XMC_DEBUG_STDOUT
#define XMC_DEBUG  if( DEBUG ) DEBUG_TYPE

/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define MAX_FILES 16

/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
VOID mainroutine()
{
  INT32 ii        =0;
  INT32 xferLngth =0;
  INT32 xferSamps =0;
  int_4 nGot      =0;
  INT32 nFiles    =0;
  INT32 dtlBlockCount[MAX_FILES];
  INT32 dtlBlockIndex[MAX_FILES];
  INT32 stlBlockStart[MAX_FILES];
  INT08 *inDataINT08;
  CHR08 switchString[16];

  string iFileName;
  string oFileName[MAX_FILES];

  CPHEADER iHeader;
  CPHEADER oHeader[MAX_FILES];

  // Get first command line parameter (input file name).
  //---------------------------------------------------------------------------------------------
  iFileName  = m_apick(1);
  XMC_DEBUG("iFileName  is %s\n", iFileName.c_str());

  // Set up the input file header.
  //---------------------------------------------------------------------------------------------
  iHeader.file_name    = iFileName;
  iHeader.type_allow   = "1000";
  iHeader.format_allow = "SB,SI,SL,SF,SD,CB,CI,CL,CF,CD";
  m_inok(iHeader);

  // Get the transfer length (BYTES) or transfer samples.  Default to 256k if not present.
  //---------------------------------------------------------------------------------------------
  if(m_get_pswitch("TL"))                     // Test for Transfer length.
  {                                           //
    xferLngth = m_get_switch("TL");           // Get transfer length (Bytes).
    xferSamps = xferLngth/iHeader.bpe;        // Calculate transfer samples.
  }
  else if(m_get_pswitch("TS"))                // Test for Transfer samples.
  {                                           //
    xferSamps = m_get_switch("TS");           // Get transfer samples.
    xferLngth = xferSamps*iHeader.bpe;        // Convert to transfer length (Bytes).
  }
  else                                        // Else
  {                                           //
    xferLngth = 262144;                       // Default to 256k bytes.
    xferSamps = xferLngth/iHeader.bpe;        // Calculate transfer samples.
  }
  nGot = xferSamps;
  XMC_DEBUG("xferLngth   is %ld\n",xferLngth);
  XMC_DEBUG("xferSamps   is %ld\n",xferSamps);
  XMC_DEBUG("nGot        is %ld\n",xferSamps);
  XMC_DEBUG("iHeader.bpe is %d\n" ,iHeader.bpe);

  // Set the transfer length variable in the input header.
  //---------------------------------------------------------------------------------------------
  iHeader.xfer_len = xferSamps;
  iHeader.cons_len = -1;

  // If present get the DTL# switch, get output file name, and setup output file.
  //---------------------------------------------------------------------------------------------
  for(ii = 0; ii < MAX_FILES; ii++)
  //for(ii = 0; ii < 1; ii++)
  {
    INT32 argNum = ii+2;
    sprintf(switchString, "DTL%ld", ii+1);     // Create switch string DTL1, DTL2, etc.
    dtlBlockCount[ii] = m_get_switch(switchString);
    if(m_ppick(argNum))
    {
      dtlBlockIndex[ii] = dtlBlockCount[ii]-1; // Use to be zero.  This way first block is output.
      m_propagate(iHeader, oHeader[ii]);
      oFileName[ii]         = m_apick(ii+2);
      oHeader[ii].file_name = oFileName[ii];
      oHeader[ii].xstart    = iHeader.xstart;
      oHeader[ii].xdelta    = iHeader.xdelta;  // Block decimation there for not change
      oHeader[ii].xunits    = 0;
      m_allocate(oHeader[ii]);
      nFiles++;
      XMC_DEBUG("oFileName[%ld] is %s\n",ii,oFileName[ii].c_str());
      XMC_DEBUG("switchString is %s\n",switchString);
      XMC_DEBUG("DTL%ld is %ld\n",ii+1,dtlBlockCount[ii]);
    }
  }
  XMC_DEBUG("Number of output files is %ld\n", nFiles);

  // If present get the STL# switch.  A way to stagger the output data.
  //---------------------------------------------------------------------------------------------
  for(ii = 0; ii < nFiles; ii++)
  {
    sprintf(switchString, "STL%ld", ii+1);      // Create switch string STL1, STL2, etc.
    stlBlockStart[ii] = m_get_switch(switchString);
    if( stlBlockStart[ii]  >= 0 )
      dtlBlockIndex[ii] = dtlBlockIndex[ii] - stlBlockStart[ii];
    XMC_DEBUG("STL%ld is %ld\n",ii+1,stlBlockStart[ii]);
  }

  // Initialize the input buffer.
  //-------------------------------------------------------------------------------
  inDataINT08  = iccMallocINT08_Align032( xferLngth +128 );
  XMC_DEBUG("Done with init.\n");

  // "Synchronize" not "sink".
  //-------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG("Calling m_sync();\n");

  // Start the processing loop.
  //-------------------------------------------------------------------------------
  while( (nGot==xferSamps) && (!Mc->break_) )
  {
    // Increment all the block index counters.  These need to be base 1 numbers.
    //-------------------------------------------------------------------------------
    for( ii = 0; ii < nFiles; ii++) dtlBlockIndex[ii]++;

    // Grab the input data.
    //-------------------------------------------------------------------------------
    m_grabx(iHeader, inDataINT08, nGot);

    // Write out the output data.
    //-------------------------------------------------------------------------------
    for( ii = 0; ii < nFiles; ii++)
    {
      if(dtlBlockCount[ii] == dtlBlockIndex[ii])
      {
	m_filad(oHeader[ii], inDataINT08, nGot);
	dtlBlockIndex[ii]=0;
      }
    }
  }

  // Terminate and return.
  //-------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  xmcFree(inDataINT08);

  m_close(iHeader);
  for( ii = 0; ii < nFiles; ii++) m_close(oHeader[ii]);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
