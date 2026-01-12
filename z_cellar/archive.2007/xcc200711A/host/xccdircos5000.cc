/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccdircos5000.cc                                                                       -
//                                                                                              -
// Desc: This primitive takes position vectors and calculates direction cosines.                -
//                                                                                              -
// Args: iFileName1  - Source postion vector file (type 5000).        <A:>                      -
//       iFileName2  - Destination postion vector file (type 5000).   <A:>                      -
//       oFileName   - Direction cosines file (type 5000).            <A:>                      -
//                                                                                              -
// Swch: /TL                                                                                    -
//       /TS                                                                                    -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       06/15/2005 ptb  Initial Code.                                                          -
//                                                                                              -
//                                   iFileName1                                                 -
//                                   iFileName2                                                 -
//                                   oFileName                                                  -
//                                   satName                                                    -
//                                   timeDur                                                    -
//                                   timeInc                                                    -
//                                      |                                                       -
//                                      V                                                       -
//    :--------------:          :----------------:     :----------------------:                 -
//    |Src. Positions|--------> |xccdircos5000.cc|---> |Direction Cosine file.|                 -
//    :--------------:-:  |     :----------------:     :----------------------:                 -
//      |Des. Positions|--+             |                                                       -
//      :--------------:                V                                                       -
//                               Debug Statements                                               -
// Note:                                                                                        -
//                                                                                              -
// Examples:                                                                                    -
// xcctle5000 /home/steswd/steswd/dat/tle.txt test1 "ERBS" 2005:07:06::00:00:00 60*60*24 5      -
// xcclla5000 test2 38.0 -77.0 0.01 2005:07:06::00:00:00 60*60*24 5                             -
// xccdircos5000 test1 test2 test3                                                              -
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
#include "stack_utils.h"
#include "string_utils.h"
#include "vector_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG      TRUE
#define DEBUG_TYPE XMC_DEBUG_STDOUT
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
  int_4 nGot1;
  int_4 nGot2;
  FLT64 srcPosVel[32];
  FLT64 dstPosVel[32];
  FLT64 dirCosVal[3+2];
  FLT64 epochJ1950w_1;
  FLT64 epochJ1950w_2;
  FLT64 epochJ1950f_1;
  FLT64 epochJ1950f_2;
  FLT64 epochJ1950w;
  FLT64 epochJ1950f;
  FLT64 time2UseFLT64;

  INT32 xferLngth;
  INT32 xferSamps;

  // Switch variables.

  // File name variables.
  string iFileName1;
  string iFileName2;
  string oFileName;
  string formatString;

  // File header variables.
  CPHEADER iHeader1;
  CPHEADER iHeader2;
  CPHEADER oHeader;

  // Get command line arguments.
  //---------------------------------------------------------------------------------------------
  iFileName1 = m_apick(1);                          // Source position type 5000 file.          -
  iFileName2 = m_apick(2);                          // Destination position type 5000 file.     -
  oFileName  = m_apick(3);                          // Output direction cosine Type 5000 file.  -

  XMC_DEBUG("iFileName1 is %s\n", iFileName1.c_str());
  XMC_DEBUG("iFileName2 is %s\n", iFileName2.c_str());
  XMC_DEBUG("oFileName  is %s\n",  oFileName.c_str());

  // Specify input file name in input header control block. (iFileName).
  //---------------------------------------------------------------------------------------------
  iHeader1.file_name    = iFileName1;
  iHeader2.file_name    = iFileName2;
  iHeader1.type_allow   = "5000";
  iHeader2.type_allow   = "5000";
  iHeader1.format_allow = "SB,SI,SL,SF,SD,CB,CI,CL,CF,CD,NH";
  iHeader2.format_allow = "SB,SI,SL,SF,SD,CB,CI,CL,CF,CD,NH";

  // Check to see if input header control block is "OK". (m_inok).
  //---------------------------------------------------------------------------------------------
  m_inok(iHeader1);
  m_inok(iHeader2);
    
  // Check for transfer length (TL) or transfer samples (TS) switch.
  //---------------------------------------------------------------------------------------------
  //if(m_get_pswitch("TL"))                        // Test for Transfer length.                   -
  //{                                              //                                             -
  //  xferLngth = m_get_switch("TL");              // Get transfer length (Bytes).                -
  //  xferSamps = xferLngth/iHeader1.bpe;          // Calculate transfer samples.                 -
  //}                                              //                                             -
  //else if(m_get_pswitch("TS"))                   // Test for Transfer samples.                  -
  //{                                              //                                             -
  //  xferSamps = m_get_switch("TS");              // Get transfer samples.                       -
  //  xferLngth = xferSamps*iHeader1.bpe;          // Convert to transfer length (Bytes).         -
  //}                                              //                                             -
  //else                                           // Else                                        -
  //{                                              //                                             -
  //  xferLngth = 262144;                          // Default to 256k bytes.                      -
  //  xferSamps = xferLngth/iHeader1.bpe;          // Calculate transfer samples.                 -
  //}                                              //----------------------------------------------

  xferSamps = 1;                                   // Set transfer samples.                       -
  xferLngth = xferSamps*iHeader1.bpe;              // Calculate transfer length.                  -
  nGot1     = xferSamps;                           // Initialize "nGot1".                         -
  nGot2     = xferSamps;                           // Initialize "nGot2".                         -
  XMC_DEBUG("xferLngth   is %ld\n",xferLngth);
  XMC_DEBUG("xferSamps   is %ld\n",xferSamps);
  XMC_DEBUG("nGot        is %ld\n",xferSamps);
  XMC_DEBUG("iHeader.bpe is %d\n" ,iHeader1.bpe);

  // Set the transfer length variable in the input header control blocks.
  //---------------------------------------------------------------------------------------------
  iHeader1.xfer_len =  1;
  iHeader1.cons_len = -1;
  iHeader2.xfer_len =  1;
  iHeader2.cons_len = -1;

  // Get the epoch times from each of the input files.
  //---------------------------------------------------------------------------------------------
  m_get_epoch (iHeader1, epochJ1950w_1, epochJ1950f_1);
  m_get_epoch (iHeader2, epochJ1950w_2, epochJ1950f_2);
  
  // Pick the latest epoch time for the timecode and epoch of the file.
  //---------------------------------------------------------------------------------------------
  if     ( (epochJ1950w_1+epochJ1950f_1 ) > (epochJ1950w_1+epochJ1950f_1 ) )
  {
    time2UseFLT64 = epochJ1950w_1 + epochJ1950f_1;
    epochJ1950w   = epochJ1950w_1;
    epochJ1950f   = epochJ1950f_1;
  }
  else if( (epochJ1950w_1+epochJ1950f_1 ) < (epochJ1950w_1+epochJ1950f_1 ) )
  {
    time2UseFLT64 = epochJ1950w_2 + epochJ1950f_2;
    epochJ1950w   = epochJ1950w_2;
    epochJ1950f   = epochJ1950f_2;
  }
  else
  {
    time2UseFLT64 = epochJ1950w_1 + epochJ1950f_1;
    epochJ1950w   = epochJ1950w_1;
    epochJ1950f   = epochJ1950f_1;
  }

  // Prepare the type 5000 output file.
  //---------------------------------------------------------------------------------------------
  m_initialize(oHeader);                     // Initialize the header.
  oHeader.file_name = oFileName;             // File name
  oHeader.timecode  = time2UseFLT64;         // Set time code to epoch of satellite.
  oHeader.type      = 5001;                  // Set the data type to 5001.
  oHeader.format    = "SD";                  // 
  oHeader.xunits    = 29;                    // Unknown units.
  oHeader.xstart    = 0;                     //
  oHeader.xdelta    = iHeader1.xdelta;       //
  oHeader.size      = 4;                     //
  oHeader.frame_of_ref = "CAR";              // Specify the frame of reference.
  m_addcomp (oHeader, "ALPH", "SD", 2,  5);  // Add Alpha direction cosine.
  m_addcomp (oHeader, "BETA", "SD", 2,  6);  // Add Beta direction cosine.
  m_addcomp (oHeader, "GAMM", "SD", 1, 60);  // Add Gamma direction cosine.
  m_addcomp (oHeader, "AZ",   "SD", 1, 34);  // Add Azimuth record.
  m_addcomp (oHeader, "EL",   "SD", 1, 34);  // Add Elevation record.
  m_addcomp (oHeader, "NAME", "2A", 0,  0);  // Add Text space.
  m_allocate(oHeader);

  // Place epoch in header of output file.
  //---------------------------------------------------------------------------------------------
  m_put_epoch (oHeader, epochJ1950w, epochJ1950f, TRUE);

  // zero out arrays.
  //---------------------------------------------------------------------------------------------
  bzero(srcPosVel,32*sizeof(FLT64));
  bzero(dstPosVel,32*sizeof(FLT64));
  bzero(dirCosVal, 5*sizeof(FLT64));

  // "Synchronize" not "sink".
  //---------------------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG("Calling m_sync();\n");

  // Start the processing loop.
  //---------------------------------------------------------------------------------------------
  while( (nGot1==xferSamps) && (nGot2==xferSamps) && (!Mc->break_) )
  {
    m_grabx(iHeader1, srcPosVel, nGot1);
    m_grabx(iHeader2, dstPosVel, nGot2);

    // Calculate direction cosines.
    //-------------------------------------------------------------------------------------------
    xccCalcDirCos( srcPosVel[0],    srcPosVel[1],    srcPosVel[2], // Source satellite x,y,z.   -
		   srcPosVel[3],    srcPosVel[4],    srcPosVel[5], // Source satellite vx,vy,vz.-
		   dstPosVel[0],    dstPosVel[1],    dstPosVel[2], // Destination satellite x,y,z.
		  &dirCosVal[0],   &dirCosVal[1],   &dirCosVal[2]);// Direction Cosines         - 
                                                                   // alpha, beta, gamma.       -

    xccDirCos2AzEl(dirCosVal[0], dirCosVal[1], dirCosVal[2], &dirCosVal[3], &dirCosVal[4]);

    dirCosVal[3] = dirCosVal[3]*180.0/PI-90.0;
    dirCosVal[4] = dirCosVal[4]*180.0/PI-90.0;
    

    // Write out the weights.
    //-------------------------------------------------------------------------------------------
    m_filad(oHeader, dirCosVal, 1);

  }   
  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  m_close(iHeader1);
  m_close(iHeader2);
  m_close(oHeader);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/

/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
