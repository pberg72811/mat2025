/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccSatUpdateJ2.c
// Desc: This routine performs satellite updates using the J2 algorithm.
// Hist: When       Who  What
//       04/28/2003 ptb  Initial Code.
//       05/16/2006 ptb  SI unit update. (N,Kg,m,sec)
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include "orbit_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG      FALSE
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
//-----------------------------------------------------------------------------------------------
VOID xccSatUpdateJ2(xccSatData_t *satData, FLT64 js)
{
  FLT64 r;
  FLT64 re;
  FLT64 hyp;
  FLT64 phiGrn;

// If 'js' is zero use current Julian seconds.
// else use the passed value of Julian seconds.
//-----------------------------------------------------------------------------------------------
  if(js==0)
  { 
    satData->currentTimeUTC = (FLT64) xccCurrentJulianSeconds();
  }
  else
  {
    satData->currentTimeUTC = js;
  }

// Print out verification data.
//-----------------------------------------------------------------------------------------------

// Convert from SI.
//-----------------------------------------------------------------------------------------------
  satData->x    /= 1000.0;
  satData->y    /= 1000.0;
  satData->z    /= 1000.0;
  satData->xDot /= 1000.0;
  satData->yDot /= 1000.0;
  satData->zDot /= 1000.0;

// Do the propagation.
//-----------------------------------------------------------------------------------------------
  xccJ2( satData, 1.0);

// Convert to SI.
//-----------------------------------------------------------------------------------------------
  satData->x    *= 1000.0;
  satData->y    *= 1000.0;
  satData->z    *= 1000.0;
  satData->xDot *= 1000.0;
  satData->yDot *= 1000.0;
  satData->zDot *= 1000.0;

// Calculate phiGrn.
//-----------------------------------------------------------------------------------------------
  phiGrn = xccGetPhiGrn( satData->currentTimeUTC );

// Calculating the longitude in radians for given Y and X values.
//-----------------------------------------------------------------------------------------------
  satData->lon = atan2(satData->y,satData->x)*RA2DE;
  XMC_DEBUG("tmpLon is %f\n",satData->lon);
  satData->lon = satData->lon - phiGrn*RA2DE;
  satData->lon = fmod(satData->lon, 360.0);

// Calculating the hypotenuse in terms of distance for given X and Y values.
//-----------------------------------------------------------------------------------------------
  hyp = sqrt(satData->x*satData->x + satData->y*satData->y);

// Calculating the Latitude in  radians for given Z and hypoteneus values.
//-----------------------------------------------------------------------------------------------
  satData->lat = atan(satData->z/hyp)*RA2DE;

// Calculating the Radius R (Including the Altitude from zero level of earth)
// in terms of distance for given Y and Z values.
//-----------------------------------------------------------------------------------------------
  r = sqrt(satData->x*satData->x + satData->y*satData->y + satData->z*satData->z);

// Calculating the Altitude in terms of distance for given R and Re values.
//-----------------------------------------------------------------------------------------------
  re = XKMPER*1000.0;                    // SI units.
  satData->alt = (r - re);

  return;

}
// End preprocessor directives
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
