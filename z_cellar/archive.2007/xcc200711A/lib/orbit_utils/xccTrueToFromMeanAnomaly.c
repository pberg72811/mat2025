/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccTrueToFromMeanAnomaly.c
// Desc: This converts from MeanAnomaly to TrueAnomaly and back again
//       assumes eccentricity of satellite correctly set.  Converts from
//       mean to true anomaly when doToTrue is True
//
// Hist: When       Who  What
//       08/10/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "orbit_utils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
FLT64  xccTrueToFromMeanAnomaly(FLT64 inAnomaly, FLT64 eccentricity, INT16 doToTrue)
{
  FLT64 ans;
  FLT64 eccPhi0; // Eccentric anomaly
  FLT64 phi0;    // True anomaly
  FLT64 meanPhi0;// Mean anomaly
  FLT64 eccPhi1; // Eccentric anomaly at next step

  if (doToTrue)  // Input is mean, convert to true
  {
    meanPhi0 = inAnomaly;
    if (eccentricity != 0.0)
    {
      eccPhi0 = meanPhi0;
      do  //  keplers equation
      {
        eccPhi1 = eccPhi0;
        eccPhi0 = eccPhi1 + (meanPhi0 - eccPhi1 + eccentricity * sin(eccPhi1))/
                (1.0 - eccentricity * cos(eccPhi1));
      }  while (fabs(eccPhi0 - eccPhi1) > 1.0e-08);

      phi0 = atan2(sin(eccPhi0) * sqrt(1.0 - eccentricity * eccentricity),
            cos(eccPhi0) - eccentricity );
      ans = phi0;
    }
    else ans = inAnomaly;
  }
  else  //  Input is true, convert to mean
  {
    phi0 = inAnomaly;;
    if (eccentricity != 0.0)
    {
      eccPhi0 = atan2(sin(phi0) * sqrt(1.0 - eccentricity * eccentricity),
              cos(phi0) + eccentricity );
      meanPhi0 = eccPhi0 - eccentricity * sin(eccPhi0);
      ans = meanPhi0;
    }
    else ans = inAnomaly;
  }
  return ans;
}
