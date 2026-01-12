/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: azel2dircos.cc                                                                         -
//                                                                                              -
// Desc: This primitive converts azimuth and elevation to direction cosines.                    -
//                                                                                              -
// Args: iFileName  - Input  file name (type 5000).      <A:>                                   -
//       oFileName  - Output file name (type 5000).      <A:>                                   -
//                                                                                              -
// Swch: None                                                                                   -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       05/25/2005 ptb  Initial Code.                                                          -
//                                                                                              -
//                               iFileName                                                      -
//                               oFileName                                                      -
//                                   |                                                          -
//                                   V                                                          -
//    :-----------------:     :----------------:     :-------------------:                      -
//    | Type 5000 Az/El |---> | azel2dircos.cc |---> | Type 5000 Dir-Cos |                      -
//    :-----------------:     :----------------:     :-------------------:                      -
//                                   |                                                          -
//                                   V                                                          -
//                            Debug Statements                                                  -
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
  int_4 nGot;
  FLT64 iAzEl[2];
  FLT64 oDirCos[3+2];
  FLT64 epochJ1950w;
  FLT64 epochJ1950f;
  FLT64 time2UseFLT64;

  INT32 xferLngth;
  INT32 xferSamps;

  // Switch variables.

  // File name variables.
  string iFileName;
  string oFileName;

  // File header variables.
  CPHEADER iHeader;
  CPHEADER oHeader;

  // Get command line arguments.
  //---------------------------------------------------------------------------------------------
  iFileName  = m_apick(1);                          // Input  Azimuth/Elevation Type 5000 file. -
  oFileName  = m_apick(2);                          // Output Direction Cosines Type 5000 file. -

  XMC_DEBUG("iFileName    is %s\n" , iFileName.c_str());
  XMC_DEBUG("oFileName    is %s\n" , oFileName.c_str());

  // Open the type 5000 input file.
  //---------------------------------------------------------------------------------------------
  iHeader.file_name    = iFileName;
  iHeader.type_allow   = "5000,5001";
  iHeader.format_allow = "SD,NH";
  m_inok(iHeader);

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
  xferLngth = xferSamps*iHeader.bpe;              // Calculate transfer length.                  -
  nGot      = xferSamps;                           // Initialize "nGot1".                         -
  XMC_DEBUG("xferLngth   is %ld\n", xferLngth);
  XMC_DEBUG("xferSamps   is %ld\n", xferSamps);
  XMC_DEBUG("nGot        is %ld\n", nGot);
  XMC_DEBUG("iHeader.bpe is %d\n" , iHeader.bpe);

  // Set the transfer length variable in the input header control blocks.
  //---------------------------------------------------------------------------------------------
  iHeader.xfer_len =  1;
  iHeader.cons_len = -1;

  // Get the epoch times from each of the input files.
  //---------------------------------------------------------------------------------------------
  m_get_epoch (iHeader, epochJ1950w, epochJ1950f);
  time2UseFLT64 = epochJ1950w + epochJ1950f;

  // Prepare the type 5000 output file.
  //---------------------------------------------------------------------------------------------
  m_initialize(oHeader);                     // Initialize the header.
  oHeader.file_name = oFileName;             // File name
  oHeader.timecode  = time2UseFLT64;         // Set time code to epoch of satellite.
  oHeader.type      = 5001;                  // Set the data type to 5001.
  oHeader.format    = "SD";                  // 
  oHeader.xunits    = 1;                     //
  oHeader.xstart    = 0;                     //
  oHeader.xdelta    = iHeader.xdelta;        //
  oHeader.size      = iHeader.size;          //
  oHeader.frame_of_ref = "ECI";              // Specify the frame of reference.
  m_addcomp (oHeader, "ALPH", "SD", 1, 33);  // Add Alpha direction cosine.
  m_addcomp (oHeader, "BETA", "SD", 1, 33);  // Add Beta direction cosine
  m_addcomp (oHeader, "GAMM", "SD", 1, 33);  // Add Gamma direction cosine.
  m_allocate(oHeader);

  // Place epoch in header of output file.
  //---------------------------------------------------------------------------------------------
  m_put_epoch (oHeader, epochJ1950w, epochJ1950f, TRUE);

  // "Synchronize" not "sink".
  //---------------------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG("Calling m_sync().\n");

  // Start the processing loop.
  //---------------------------------------------------------------------------------------------
  while( (nGot==xferSamps) && (!Mc->break_) )
  {
    FLT64 az;
    FLT64 el;

    // Grab Azimuth and Elevation.
    //-------------------------------------------------------------------------------------------
    m_grabx(iHeader, iAzEl, nGot);
    az = iAzEl[0];
    el = iAzEl[1];

    // Calculate direction cosines.
    //-------------------------------------------------------------------------------------------
    oDirCos[0] = sin(el)*cos(az);
    oDirCos[1] = sin(el)*sin(az);
    oDirCos[2] = cos(el);

    // Write out direction cosines.
    //-------------------------------------------------------------------------------------------
    m_filad(oHeader, oDirCos, 1);

  }   
  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  m_close(iHeader);
  m_close(oHeader);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/

/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
