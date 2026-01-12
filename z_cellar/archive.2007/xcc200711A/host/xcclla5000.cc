/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xcclla5000.cc                                                                          -
//                                                                                              -
// Desc: This primitive converts a lat, lon, alt position to a type 5000 file.                  -
//       This primitive will create a type 5000 file containing X, Y, Z position                -
//       values and Vx,Vy,Vz velocity values from a latitude, longitude,                        -
//       and altitude (m) postion plus a start time.                                            -
//                                                                                              -
// Args: oFileName  - Output file name (type 5000).      <A:>                                   -
//       latitude   - Latitude of position.              <D:>                                   -
//       longitude  - Longitude of position.             <D:>                                   -
//       altitude   - Altitude of position (m).          <D:>                                   -
//       epochTime  - Start time for type 5000 file.     <T:>                                   -
//       timeDur    - Time duration of the output file.  <L:>                                   -
//       timeInc    - Time increment of the output file. <L:>                                   -
//                                                                                              -
// Swch: None                                                                                   -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       06/15/2005 ptb  Initial Code.                                                          -
//       05/16/2006 ptb  SI unit update. (N,Kg,m,sec)                                           -
//                                                                                              -
//                              oFileName                                                       -
//                              latitude                                                        -
//                              longitude                                                       -
//                              altitude (m)                                                    -
//                              epochTime                                                       -
//                              timeDur                                                         -
//                              timeInc                                                         -
//                                 |                                                            -
//                                 V                                                            -
//                         :---------------:     :-------------------:                          -
//                         |xcclla5000.cc  |---> |Type 5000 file/pipe|                          -
//                         :---------------:     :-------------------:                          -
//                                 |                                                            -
//                                 V                                                            -
//                          Debug Statements                                                    -
//                                                                                              -
// Note:                                                                                        -
// Setting epoch time to 0.0 will cause this primitive to use the current time.                 -
//                                                                                              -
// Examples:                                                                                    -
// xcclla5000 test1 38.0 77.0 0.0  0 1 1                                                        -
// xcclla5000 test1 38.0 77.0 0.0  0 60*60*24 1                                                 -
// xcclla5000 test1 38.0 77.0 0.0  1751913549.76563 60*60*24 1                                  -
// xcclla5000 test1 38.0 77.0 0.0  2005:06:20::00:00:00 60*60*24 1                              -
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
  INT32 timeDur;
  INT32 timeInc;
  INT32 nSamples;
  FLT32 latitude;
  FLT32 altitude;
  FLT32 longitude;
  FLT64 posVel[32];
  FLT64 epochJ1950w;
  FLT64 epochJ1950f;
  FLT64 time2UseFLT64;
  xccStatData_t theStat;

  // Switch variables.

  // File name variables.
  string iFileName;
  string oFileName;

  // Get command line arguments.
  //---------------------------------------------------------------------------------------------
  oFileName  = m_apick(1);                          // Output Type 5000 file.                   -
  latitude   = m_dpick(2);                          // Input latitude.                          -
  longitude  = m_dpick(3);                          // Input longitude.                         -
  altitude   = m_dpick(4);                          // Input altitude.                          -
               m_tpick(5,(real_8&)epochJ1950w,(real_8&)epochJ1950f);  // Start time of file.    -
  timeDur    = (INT32)m_dpick(6);                   // Time duration of output file in seconds. -
  timeInc    = (INT32)m_dpick(7);                   // TIme increment of output file in seconds.-

  XMC_DEBUG("oFileName    is %s\n" , oFileName.c_str());
  XMC_DEBUG("latitude     is %f\n" , latitude);
  XMC_DEBUG("longitude    is %f\n" , longitude);
  XMC_DEBUG("altitude (m) is %f\n" , altitude);
  XMC_DEBUG("epochJ1950w  is %f\n" , epochJ1950w);
  XMC_DEBUG("epochJ1950f  is %f\n" , epochJ1950f);
  XMC_DEBUG("timeDur      is %ld\n", timeDur);
  XMC_DEBUG("timeInc      is %ld\n", timeInc);
  nSamples = MAX(1,timeDur/timeInc);
  XMC_DEBUG("nSamples    is %ld\n", nSamples);

  // Get command line arguments.
  //---------------------------------------------------------------------------------------------
  theStat.lat = latitude;
  theStat.lon = longitude;
  theStat.alt = altitude;
  sprintf(theStat.statName,"HERE");

  // Add the whole and fractional seconds.
  //---------------------------------------------------------------------------------------------
  time2UseFLT64 = (epochJ1950w+epochJ1950f);

  // Prepare the type 5000 output file.
  //---------------------------------------------------------------------------------------------
  CPHEADER oHeader;                          //
  m_initialize(oHeader);                     // Initialize the header.
  oHeader.file_name = oFileName;             // File name
  oHeader.timecode  = time2UseFLT64;         // Set time code to epoch of satellite.
  oHeader.type      = 5001;                  // Set the data type to 5001.
  oHeader.format    = "SD";                  // 
  oHeader.xunits    = 1;                     //
  oHeader.xstart    = 0;                     //
  oHeader.xdelta    = timeInc;               //
  oHeader.size      = nSamples;              //
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

  // Convert time2Use from J1950 to Julian seconds for rest of calculations.
  //---------------------------------------------------------------------------------------------
  time2UseFLT64 = time2UseFLT64 + (FLT64)xcc_JULIAN_SECONDS_JAN1_1950;

  // "Synchronize" not "sink".
  //---------------------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG("Calling m_sync().\n");

  // Processing loop.  Write propagation data to the output 5000 file.
  //---------------------------------------------------------------------------------------------
  for(ii=0; ii<nSamples; ii++)                                   // For each time segment       -
  {                                                              //                             -
    xccStatUpdate( &theStat, time2UseFLT64+(ii*timeInc));        // Update the station position.-
    posVel[0] = theStat.x;                                       // X position in meters.       -
    posVel[1] = theStat.y;                                       // Y position in meters.       -
    posVel[2] = theStat.z;                                       // Z position in meters.       -
    posVel[3] = theStat.xDot;                                    // X velocity in meters/sec.   -
    posVel[4] = theStat.yDot;                                    // Y velocity in meters/sec.   -
    posVel[5] = theStat.zDot;                                    // Z velocity in meters/sec.   -
    posVel[6] = theStat.lat;                                     // Latitude in degrees.        -
    posVel[7] = theStat.lon;                                     // Longitude in degrees.       -
    posVel[8] = theStat.alt;                                     // Altitude in meters.         -
    sprintf((CHR08 *)&posVel[9],"% 16s",theStat.statName);       //                             -
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
