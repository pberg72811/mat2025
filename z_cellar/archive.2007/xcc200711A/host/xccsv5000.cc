/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccsv5000.cc                                                                           -
//                                                                                              -
// Desc: This primitive creates a type 5000 ephemeris from a single State Vector.               -
//                                                                                              -
// Args: oFileName   - Output file name (type 5000).  <A:>                                      -
//       x           - X position (m) in ECI.         <D:>                                      -
//       y           - Y position (m) in ECI.         <D:>                                      -
//       z           - Z position (m) in ECI.         <D:>                                      -
//       xdot        - X velocity (m/s).              <D:>                                      -
//       ydot        - Y velocity (m/s).              <D:>                                      -
//       zdot        - Z velocity (m/s).              <D:>                                      -
//       svEpoch     - Epoch of state vector          <T:>                                      -
//       svStart     - Start time for sv file         <T:>                                      -
//       svDuration  - Duration of sv file            <D:>                                      -
//       svIncrement - Time increment for sv file     <D:>                                      -
//                                                                                              -
// Swch: None                                                                                   -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       06/15/2005 ptb  Initial Code.                                                          -
//       05/16/2006 ptb  SI unit update. (N,Kg,m,sec)                                           -
//                                                                                              -
//                          oFileName                                                           -
//                          x           (Meters)                                                -
//                          y           (Meters)                                                -
//                          z           (Meters)                                                -
//                          xdot        (Meters/Second)                                         -
//                          ydot        (Meters/Second)                                         -
//                          zdot        (Meters/Second)                                         -
//                          svEpoch                                                             -
//                          svStart                                                             -
//                          svDuration  (Seconds.)                                              -
//                          svIncrement (Seconds.)                                              -
//                              |                                                               -
//                              V                                                               -
//                        :------------:     :-------------------:                              -
//                        |xccsv5000.cc|---> |Type 5000 file/pipe|                              -
//                        :------------:     :-------------------:                              -
//                              |                                                               -
//                              V                                                               -
//                        Debug Statements                                                      -
//                                                                                              -
// Note:                                                                                        -
//                                                                                              -
// Examples:                                                                                    -
// res temp testsv(1;~pos)                                                                      -
// res x1 temp(1)                                                                               -
// res x2 temp(2)                                                                               -
// res x3 temp(3)                                                                               -
// res temp testsv(1;~vel)                                                                      -
// res vx1 temp(1)                                                                              -
// res vx2 temp(2)                                                                              -
// res vx3 temp(3)                                                                              -
// timecode testsv ,, epoch                                                                     -
// xccsv5000 ephem x1 x2 x3 vx1 vx2 vx3 epoch epoch 24*60*60 60                                 -
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
  UNT32 ii;
  int_4 nGot;
  INT32 timeDur;
  INT32 timeInc;
  UNT64 nSamples;
  FLT64 time2UseFLT64;
  FLT64 posVel[32];
  FLT64 epochJ1950w;
  FLT64 epochJ1950f;
  FLT64 startJ1950w;
  FLT64 startJ1950f;
  xccSatData_t theSat;

  // Switch variables.

  // File name variables.
  string satName;
  string oFileName;
  string subRecordName;
  string subRecordFormat;

  // Get command line arguments.
  //---------------------------------------------------------------------------------------------
  oFileName  = m_apick(1);                          // Output Type 5000 file.                   -
  posVel[ 0] = m_dpick( 2);                         // X position of state vector.              -
  posVel[ 1] = m_dpick( 3);                         // Y position of state vector.              -
  posVel[ 2] = m_dpick( 4);                         // Z position of state vector.              -
  posVel[ 3] = m_dpick( 5);                         // X velocity of state vector.              -
  posVel[ 4] = m_dpick( 6);                         // Y velocity of state vector.              -
  posVel[ 5] = m_dpick( 7);                         // Z velocity of state vector.              -
  timeDur    = (INT32)m_dpick(10);                  // Time duration of output file in seconds. -
  timeInc    = (INT32)m_dpick(11);                  // TIme increment of output file in seconds.-
  m_tpick(8,(real_8&)epochJ1950w,(real_8&)epochJ1950f); // Epoch time of state vector.          -
  m_tpick(9,(real_8&)startJ1950w,(real_8&)startJ1950f); // Start time of output file.           -

  XMC_DEBUG("oFileName   is %s\n",  oFileName.c_str());
  XMC_DEBUG("x           is %f\n", posVel[ 0]);
  XMC_DEBUG("y           is %f\n", posVel[ 1]);
  XMC_DEBUG("z           is %f\n", posVel[ 2]);
  XMC_DEBUG("xdot        is %f\n", posVel[ 3]);
  XMC_DEBUG("ydot        is %f\n", posVel[ 4]);
  XMC_DEBUG("zdot        is %f\n", posVel[ 5]);
  XMC_DEBUG("epochJ1950w is %f\n" , epochJ1950w);
  XMC_DEBUG("epochJ1950f is %f\n" , epochJ1950f);
  XMC_DEBUG("startJ1950w is %f\n" , startJ1950w);
  XMC_DEBUG("startJ1950f is %f\n" , startJ1950f);
  XMC_DEBUG("timeDur     is %ld\n", timeDur);
  XMC_DEBUG("timeInc     is %ld\n", timeInc);
  nSamples = MAX(1,timeDur/timeInc);
  XMC_DEBUG("nSamples  is %llu\n", nSamples);

  // Set up position, velocity, and acceleration vectors in the satellite structure.
  //---------------------------------------------------------------------------------------------
  theSat.x       = posVel[0]; // X position m -> m for J2.                     SI units.
  theSat.y       = posVel[1]; // Y position m -> m for J2.                     SI units.
  theSat.z       = posVel[2]; // Z position m -> m for J2.                     SI units.
  theSat.xDot    = posVel[3]; // X velocity m/sec -> m/sec for J2.             SI units.
  theSat.yDot    = posVel[4]; // Y velocity m/sec -> m/sec for J2.             SI units.
  theSat.zDot    = posVel[5]; // Z velocity m/sec -> m/sec for J2.             SI units.
  theSat.xDotDot = 0.0;       // X acceleration m/sec*sec -> m/sec*sec for J2. SI units.
  theSat.yDotDot = 0.0;       // Y acceleration m/sec*sec -> m/sec*sec for J2. SI units.
  theSat.zDotDot = 0.0;       // Z acceleration m/sec*sec -> m/sec*sec for J2. SI units.
  theSat.epochTimeUTC = epochJ1950w + epochJ1950f + (FLT64)xcc_JULIAN_SECONDS_JAN1_1950;

  // Add the whole and fractional seconds.
  //---------------------------------------------------------------------------------------------
  time2UseFLT64 = epochJ1950w + epochJ1950f;

  // Prepare the type 5000 output file.
  //---------------------------------------------------------------------------------------------
  CPHEADER oHeader;
  m_initialize(oHeader);                     // Initialize the header.
  oHeader.file_name = oFileName;             // File name
  oHeader.timecode  = time2UseFLT64;         // Set time code to epoch of satellite (J1950).
  oHeader.type      = 5001;                  // Set the data type to 5001.
  oHeader.format    = "SD";                  // 
  oHeader.xunits    = 1;                     //
  oHeader.xstart    = 0;                     //
  oHeader.xdelta    = timeInc;               //
  oHeader.size      = nSamples;              //
  oHeader.frame_of_ref = "ECI";              // Specify the frame of reference.
  m_addcomp (oHeader, "POS", "VD", 2, 5);    // Add Position vector record.
  m_addcomp (oHeader, "VEL", "VD", 2, 6);    // Add velocity vector record.
  m_addcomp (oHeader, "ACC", "VD", 2, 7);    // Add acceleration vector record.
  m_addcomp (oHeader, "LAT", "SD", 1, 60);   // Add Latitude record.
  m_addcomp (oHeader, "LON", "SD", 1, 61);   // Add Longitude record.
  m_addcomp (oHeader, "ALT", "SD", 1, 63);   // Add Altitude record.
  m_addcomp (oHeader, "NAME","2A", 0, 0);    // Add satellite name record.
  m_allocate(oHeader);

  // Set the file epoch value to the start time of the ephemeris.
  //---------------------------------------------------------------------------------------------
  m_put_epoch (oHeader, startJ1950w, startJ1950f, TRUE);

  // Convert from J1950 to Julian for rest of calculations.
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
    xccSatUpdateJ2( &theSat, time2UseFLT64+(FLT64)(ii*timeInc)); // Update/Propagate the sat.   -
    posVel[ 0] = theSat.x;                                       // X position in meters.       -
    posVel[ 1] = theSat.y;                                       // Y position in meters.       -
    posVel[ 2] = theSat.z;                                       // Z position in meters.       -
    posVel[ 3] = theSat.xDot;                                    // X velocity in meters/sec.   -
    posVel[ 4] = theSat.yDot;                                    // Y velocity in meters/sec.   -
    posVel[ 5] = theSat.zDot;                                    // Z velocity in meters/sec.   -
    posVel[ 6] = theSat.xDotDot;                                 // X acceleration in m/(s*s).  -
    posVel[ 7] = theSat.yDotDot;                                 // Y acceleration in m/(s*s).  -
    posVel[ 8] = theSat.zDotDot;                                 // Z acceleration in m/(s*s).  -
    posVel[ 9] = theSat.lat;                                     // Latitude in degrees.        -
    posVel[10] = theSat.lon;                                     // Longitude in degrees.       -
    posVel[11] = theSat.alt;                                     // Altitude in meters.         -
    sprintf((CHR08 *)&posVel[12],"NONE");                        //                             -
                                                                 //                             -
    m_filad(oHeader, posVel, 1);                                 // Write out to the 5000 file. -
                                                                 //                             -
    if(Mc->break_) break;                                        // Check for a break.          -
    theSat.epochTimeUTC = theSat.currentTimeUTC;                 //                             -
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
