/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccGetPhiGrn.c
// Desc: Get phigrn at given epoch (in sec). Routine from kn translation
//       of SGP4 Also Ast. Almanac pB6.  From R.McOmber's code. Julian seconds.
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
FLT64 xccGetPhiGrn(FLT64 inEpoch)
/*  Get phigrn at given epoch (in sec)   */
/*  Routine from kn translation of SGP4  */
/*  Also Ast. Almanac pB6                */
{
  FLT64 UT;
  FLT64 TU;
  FLT64 GMST;
  FLT64 truePhigrn; /* phigrn at epoch of planet  */

  const FLT64 secPerDay = xcc_SECONDS_PER_SIDEREAL_DAY;
  const FLT64 omegaEarth = xcc_EARTH_REVS_PER_SIDEREAL_DAY;

  /*  convert input epoch from secs to days  */
  inEpoch = inEpoch/secPerDay;
  UT      = (inEpoch + 0.5) - floor(inEpoch + 0.5);
  inEpoch = inEpoch - UT;
  TU      = (inEpoch - 2451545.0) / 36525.0;
  GMST    = 24110.54841 + TU * (8640184.812866 + TU * (0.093104 - TU * 6.2E-06));
  GMST    = fmod(GMST + secPerDay * omegaEarth * UT, secPerDay);
  truePhigrn = TWOPI * GMST / secPerDay;

  return truePhigrn;
}
