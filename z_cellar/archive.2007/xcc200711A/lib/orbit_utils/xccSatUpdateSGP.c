/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccSatUpdateSGP.c
// Desc: This routine performs satellite updates using the SGP algorithm.
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
#define DEBUG FALSE
#define DEBUG_TYPE  XMC_DEBUG_STDOUT
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
VOID xccSatUpdateSGP(xccSatData_t *satData, FLT64 js)
{
  FLT64 r;
  FLT64 re;
  FLT64 hyp;
  FLT64 phiGrn;
  FLT64 m;

// If 'js' is zero use current Julian seconds.
// else use the passed value of Julian seconds.
//-----------------------------------------------------------------------------------------------
  if(js==0)
  { 
    satData->currentTimeUTC = xccCurrentJulianSeconds();
  }
  else
  {
    satData->currentTimeUTC = js;
  }

// Print out verification data.
//-----------------------------------------------------------------------------------------------
  XMC_DEBUG("sat name is %s\n", satData->satName);
  XMC_DEBUG("Epoch year is %ld\n", satData->epochYear);
  XMC_DEBUG("Epoch day is %f\n", satData->epochDay);
  XMC_DEBUG("Requested Julian seconds is %f\n", js);
  XMC_DEBUG("Epoch Julian seconds is %f\n", satData->epochTimeUTC);
  XMC_DEBUG("Julian difference is %f\n",js-satData->epochTimeUTC);
  m = ((FLT64)(js-satData->epochTimeUTC)/60.0);
  XMC_DEBUG("difference in minutes is %f\n", m);
  XMC_DEBUG("satData->XNDT20 is %08.7f\n",satData->XNDT20);
  XMC_DEBUG("satData->XNDD60 is %08.7f\n",satData->XNDD60);
  XMC_DEBUG("satData->BSTAR  is %08.7f\n",satData->BSTAR);
  XMC_DEBUG("satData->XINCL  is %06.2f or %06.2f\n",satData->XINCL,satData->XINCL*RA2DE);
  XMC_DEBUG("satData->XNODEO is %06.2f or %06.2f\n",satData->XNODEO,satData->XNODEO*RA2DE);
  XMC_DEBUG("satData->EO     is %08.7f\n",satData->EO);
  XMC_DEBUG("satData->OMEGAO is %06.2f or %06.2f\n",satData->OMEGAO,satData->OMEGAO*RA2DE);
  XMC_DEBUG("satData->XMO    is %06.2f or %06.2f\n",satData->XMO,satData->XMO*RA2DE);
  XMC_DEBUG("satData->XNO    is %06.2f\n",satData->XNO);

// Do the propagation.
//-----------------------------------------------------------------------------------------------
  xccSGP( satData->XNDT20, //First Time Derivative
	  satData->XNDD60, //Second Time Derivative
	  satData->BSTAR,  //BSTAR drag term
	  satData->XINCL,  //Inclination
	  satData->XNODEO, //Right ascension of ascending node
	  satData->EO,     //Eccentricity
	  satData->OMEGAO, //Argument of Perigee
	  satData->XMO,    //Mean Anomally
	  satData->XNO,    //Mean Motion
	  m,               //Time since in minutes
	  &satData->x,     //X position returned in Km.
	  &satData->y,     //Y position returned in Km.
	  &satData->z,     //Z position returned in Km.
	  &satData->xDot,  //X velocity returned in Km/Sec.
	  &satData->yDot,  //Y velocity returned in Km/Sec.
	  &satData->zDot); //Z velocity returned in Km/Sec.

  satData->x    = satData->x*XKMPER/AE;
  satData->y    = satData->y*XKMPER/AE;
  satData->z    = satData->z*XKMPER/AE;
  satData->xDot = satData->xDot*XKMPER/AE*XMNPDA/86400;
  satData->yDot = satData->yDot*XKMPER/AE*XMNPDA/86400;
  satData->zDot = satData->zDot*XKMPER/AE*XMNPDA/86400;

// Convert to SI units.
//-----------------------------------------------------------------------------------------------
  satData->x    = satData->x    * 1000.0;   // SI units.
  satData->y    = satData->y    * 1000.0;   // SI units.
  satData->z    = satData->z    * 1000.0;   // SI units.
  satData->xDot = satData->xDot * 1000.0;   // SI units.
  satData->yDot = satData->yDot * 1000.0;   // SI units.
  satData->zDot = satData->zDot * 1000.0;   // SI units.

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
  re = XKMPER * 1000.0;                     // SI units.
  satData->alt = (r - re);

  return;

}
// End preprocessor directives
/*---------------------------------------------------------------------------------------------*/

/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
