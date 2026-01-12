/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xcctle5000.cc                                                                          -
//                                                                                              -
// Desc: This primitive converts NORAD TLE file to a type 5000 files.                           -
//       This primitive will create a type 5000 file from a NORAD two line                      -
//       element (TLE) text file.                                                               -
//                                                                                              -
// Args: iFileName  - NORAD TLE file name.                     <A:>                             -
//       oFileName  - Output file name (type 5000).            <A:>                             -
//       satName    - Satellite name.                          <A:>                             -
//       startTime  - Start time for type 5000 file.           <T:>                             -
//       timeDur    - Time duration of the output file (Sec).  <L:>                             -
//       timeInc    - Time increment of the output file (Sec). <L:>                             -
//                                                                                              -
// Swch: None                                                                                   -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       06/15/2005 ptb  Initial Code.                                                          -
//       05/16/2006 ptb  SI unit update. (N,Kg,m,sec)                                           -
//                                                                                              -
//                              iFileName                                                       -
//                              oFileName                                                       -
//                              satName                                                         -
//                              startTime                                                       -
//                              timeDur                                                         -
//                              timeInc                                                         -
//                                 |                                                            -
//                                 V                                                            -
//    :--------------:     :----------------:     :-------------------:                         -
//    |ASCII TLE FILE|---> |xcctle25000.cc  |---> |Type 5000 file/pipe|                         -
//    :--------------:     :----------------:     :-------------------:                         -
//                                 |                                                            -
//                                 V                                                            -
//                          Debug Statements                                                    -
//                                                                                              -
// Note:                                                                                        -
// The epoch time of the satellite, that is the time for which the satellite                    -
// parameters are valid, is itself a parameter in the TLE file.  Therefore, the                 -
// epoch time is not needed on the command line of this primitive.  The user                    -
// should put a start time of 0.0 if the epoch time and start time are to be the                -
// same.  Otherwise, the user needs to put a clock time (not time since epoch)                  -
// as the intended start time of the output data.                                               -
//                                                                                              -
// Examples:                                                                                    -
// xcctle5000 /home/steswd/steswd/dat/tle.txt test1 "ERBS" 0.0 1 1                              -
// xcctle5000 /home/steswd/steswd/dat/tle.txt test1 "ERBS" 1751913549.76563 60*60*24 5          -
// xcctle5000 /home/steswd/steswd/dat/tle.txt test2 "HST"  2005:07:07::12:12:09 60*60*24*30 5   -
// xcctle5000 /home/steswd/steswd/dat/tle.txt test1 "ERBS" 1751913549.76563 60*60*24 5          -
// xcctle5000 /home/steswd/steswd/dat/tle.txt test2 "HST"  1751913549.76563 60*60*24 5          -
// dual5000 test1 test2 test3 R                                                                 -
// dual5000 test1 test2 test3 R RR                                                              -
// timex file=test1 quad=test1                                                                  -
// timex file=test2 quad=test2                                                                  -
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
  INT32 ii;
  INT32 status;
  INT32 timeDur;
  INT32 timeInc;
  INT32 nSamples;
  FLT64 posVel[32];
  FLT64 epochJ1950w;
  FLT64 epochJ1950f;
  FLT64 time2UseFLT64;
  xccSatData_t      theSat;
  xccSatDataList_t  satDataList;
  CHR08 satDataListFileName[128];
  INT32 satelliteFoundFlag=FALSE;

  // Switch variables.

  // File name variables.
  string satName;
  string iFileName;
  string oFileName;

  // Get command line arguments.
  //---------------------------------------------------------------------------------------------
  iFileName  = m_apick(1);                          // Input TLE ascii file.                    -
  oFileName  = m_apick(2);                          // Output Type 5000 file.                   -
  satName    = m_apick(3);                          // Which satellite to process.              -
               m_tpick(4,(real_8&)epochJ1950w,(real_8&)epochJ1950f); // Start time of file.     -
  timeDur    = (INT32)m_dpick(5);                   // Time duration of output file in seconds. -
  timeInc    = (INT32)m_dpick(6);                   // TIme increment of output file in seconds.-

  XMC_DEBUG("iFileName   is %s\n", iFileName.c_str());
  XMC_DEBUG("oFileName   is %s\n", oFileName.c_str());
  XMC_DEBUG("satName     is %s\n", satName.c_str());
  XMC_DEBUG("epochJ1950w is %f\n", epochJ1950w);
  XMC_DEBUG("epochJ1950f is %f\n", epochJ1950f);
  XMC_DEBUG("timeDur     is %ld\n", timeDur);
  XMC_DEBUG("timeInc     is %ld\n", timeInc);
  nSamples = MAX(1,timeDur/timeInc);
  XMC_DEBUG("nSamples    is %ld\n", nSamples);

  // Go read the NORAD TLE file and build the satellite list.
  //---------------------------------------------------------------------------------------------
  sprintf(satDataListFileName, "%s", iFileName.c_str());   // Copy the sat name to a C-string.  -
  xccStringLower( satDataListFileName );                   // Make the string lower case.       -
  satDataList  = xccSatDataListInit(satDataListFileName);  // Initialize the sat list.          -

  // Find the requested satellite.
  //---------------------------------------------------------------------------------------------
  for( ii = 0; ii < satDataList.nSats; ii++)
  {
    status = strcmp(satName.c_str(), satDataList.theSat[ii]->satName);

    if(status==0)
    {
      satelliteFoundFlag=TRUE;
      theSat = *satDataList.theSat[ii];
      XMC_DEBUG("FOUND %s\n",satDataList.theSat[ii]->satName);
    }
  }

  if(!satelliteFoundFlag)
  {
    XMC_ERROR_STDOUT("No satellite with name %s found!\n",satName.c_str());
    exit(0);
  }

  // 
  //---------------------------------------------------------------------------------------------
  if((epochJ1950w+epochJ1950f)==0.0) 
  {
    time2UseFLT64 = theSat.epochTimeUTC - XMC_JULIAN_SECONDS_JAN1_1950;
  }
  else
  {
    time2UseFLT64 = (epochJ1950w+epochJ1950f);
  }

  // Prepare the type 5000 output file.
  //---------------------------------------------------------------------------------------------
  CPHEADER oHeader;
  m_initialize(oHeader);                     // Initialize the header.
  oHeader.file_name = oFileName;             // File name
  oHeader.timecode  = time2UseFLT64;         // Set time code to epoch of satellite (J1950).
  oHeader.type      = 5001;                  // Set the data type to 5001.
  oHeader.format    = "SD";                  // 
  oHeader.xunits    = 1;
  oHeader.xstart    = 0;
  oHeader.xdelta    = timeInc;
  oHeader.size      = nSamples;
  oHeader.frame_of_ref = "ECI";              // Specify the frame of reference.
  m_addcomp (oHeader, "POS", "VD", 2, 5);    // Add Position vector record.
  m_addcomp (oHeader, "VEL", "VD", 2, 6);    // Add velocity vector record.
  m_addcomp (oHeader, "LAT", "SD", 1, 60);   // Add Latitude record.
  m_addcomp (oHeader, "LON", "SD", 1, 61);   // Add Longitude record.
  m_addcomp (oHeader, "ALT", "SD", 1, 63);   // Add Altitude record.
  m_addcomp (oHeader, "NAME","2A", 0, 0);    // Add satellite name record.
  m_allocate(oHeader);

  // Fill in the type 5000 epoch values.
  //---------------------------------------------------------------------------------------------
  m_put_epoch (oHeader, time2UseFLT64, 0, TRUE);

  // Convert from J1950 to Julian for rest of calculations.
  //---------------------------------------------------------------------------------------------
  time2UseFLT64 = time2UseFLT64 + (FLT64)XMC_JULIAN_SECONDS_JAN1_1950;

  // "Synchronize" not "sink".
  //---------------------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG("Calling m_sync().\n");

  // Processing loop.  Write propagation data to the output 5000 file.
  //---------------------------------------------------------------------------------------------
  for(ii=0; ii<nSamples; ii++)                                   // For each time segment       -
  {                                                              //                             -
    xccSatUpdateSGP( &theSat, time2UseFLT64+(ii*timeInc));       // Update/Propagate the sat.   -
    posVel[0] = theSat.x;                                        // X position in meters.       -
    posVel[1] = theSat.y;                                        // Y position in meters.       -
    posVel[2] = theSat.z;                                        // Z position in meters.       -
    posVel[3] = theSat.xDot;                                     // X velocity in meters/sec.   -
    posVel[4] = theSat.yDot;                                     // Y velocity in meters/sec.   -
    posVel[5] = theSat.zDot;                                     // Z velocity in meters/sec.   -
    posVel[6] = theSat.lat;                                      // Latitude in degrees.        -
    posVel[7] = theSat.lon;                                      // Longitude in degrees.       -
    posVel[8] = theSat.alt;                                      // Altitude in meters.         -
    sprintf((CHR08 *)&posVel[9],"% 16s",satName.c_str());        //                             -
                                                                 //                             -
    m_filad(oHeader, posVel, 1);                                 // Write out to the 5000 file. -
                                                                 //                             -
    if(Mc->break_) break;                                        // Check for a break.          -
  }                                                              //------------------------------

  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  m_close(oHeader);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/

/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
    //oHeader.epoch_seconds = oHeader.timecode;
    //FLT64 phiGrn;
    //phiGrn = xccGetPhiGrn(time2Use);
    //m_eci_to_ecr(posVel,2,1,&phiGrn);
