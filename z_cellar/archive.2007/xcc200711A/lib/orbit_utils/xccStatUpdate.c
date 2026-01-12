/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccStatUpdate.c
// Desc: This routine performs station ECI updates and uses SI units.
// Hist: When       Who  What
//       04/28/2003 ptb  Initial Code.
//       05/16/2006 ptb  SI unit update. (N,Kg,m,sec)
// Note: Need to flatten earth.
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include "orbit_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG 0

/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
//-----------------------------------------------------------------------------------------------
VOID xccStatUpdate(xccStatData_t *statData, FLT64 js)
{
  FLT64 w;
  FLT64 v;
  FLT64 re;
  FLT64 xy;
  FLT64 alt;
  FLT64 phiGrn;

// If 'js' is zero use current Julian seconds.
// else use the passed value of Julian seconds.
//-----------------------------------------------------------------------------------------------
  if(js==0)                                               // If input time is set to zero       -
  {                                                       // then                               -
    statData->currentTimeUTC = xccCurrentJulianSeconds(); // use the current Julian time.       -
  }                                                       //                                    -
  else                                                    //                                    -
  {                                                       //                                    -
    statData->currentTimeUTC = js;                        // Else use the input time.           -
  }                                                       //-------------------------------------

// Convert lat,lon,alt to ECI x,y,z,vx,vy,vz.
//-----------------------------------------------------------------------------------------------
  re     = XKMPER*1000.0;                                  // XKMPER is in kilometers.          -
  alt    = statData->alt+re;                               // Add radius of earth to alt.       -
  phiGrn = xccGetPhiGrn( statData->currentTimeUTC );       // Get the Greenwich hour angle.     -
                                                           //                                   -
  statData->z    = sin(DE2RA*statData->lat)*alt;           // Calculate Z position.             -
                                                           //                                   -
  xy             = cos(DE2RA*statData->lat)*alt;           //                                   -
                                                           //                                   -
  statData->x    = cos((DE2RA*statData->lon)+phiGrn)*xy;   // Calculate X position.             -
                                                           //                                   -
  statData->y    = sin((DE2RA*statData->lon)+phiGrn)*xy;   // Calculate Y position.             -
                                                           //                                   -
  w              = cos(DE2RA*statData->lat)*re;            //                                   -
                                                           //                                   -
  v              = 2*PI*w/86400;                           //                                   -
                                                           //                                   -
  statData->xDot = -v*sin((DE2RA*statData->lon)+phiGrn);   // Calculate X Velocity.             -
                                                           //                                   -
  statData->yDot = +v*cos((DE2RA*statData->lon)+phiGrn);   // Calculate Y Velocity.             -
                                                           //                                   -
  statData->zDot = 0.0;                                    // Calculate Z Velocity.             -
                                                           //------------------------------------
  return;

}
// End preprocessor directives
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
