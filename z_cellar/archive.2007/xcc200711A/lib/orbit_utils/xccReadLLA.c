/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccReadLLA.c
// Desc: This routine will read one entry in a latitude-longitude-altitude file.
//       Latitude and Longitude are in degrees.  Altitude is in meters.
//
//                               **SAMPLE**
//Ashburn Virginia
//+39.041400 -077.48100 +100.000000
//Herndon Virginia
//+38.969200 -077.38730 +99.0000000
//Fort Mede
//+39.108000 -076.74200 +50.0000000
//Centerville Virginia
//+38.846900 -077.44800 +60.0000000
//
// Hist: When       Who  What
//       08/30/2001 ptb  Initial Code.
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
xccStatData_t xccReadLLA(FILE *fp)
{
  CHR08 line1[72], line2[72];
  CHR08 tempA[32];
  CHR08 subs1[32], subs2[32], subs3[32];
  xccStatData_t xccStatData;

  // Make sure strings are clean.
  //------------------------------------------------------------------------------
  memset(line1, 0, 72);
  memset(line2, 0, 72);
  memset(subs1, 0, 32);
  memset(subs2, 0, 32);
  memset(subs3, 0, 32);

  // Initialize the station data.
  //------------------------------------------------------------------------------
  xccStatData.x    = xccStatData.y    = xccStatData.z    = 0.0;
  xccStatData.xDot = xccStatData.yDot = xccStatData.zDot = 0.0;
  xccStatData.lat  = xccStatData.lon  = xccStatData.alt  = 0.0;

  // Read in Line 1 of LLA file.  Handles up to three word name.
  /*--------------------------------------------------------------------------*/
  fgets(line1, 999, fp);
  sscanf(line1, "%s %s %s", &subs1[0], &subs2[0], &subs3[0]);
  if      (strlen(subs3) > 0) sprintf(&xccStatData.statName[0],"%s %s %s", subs1, subs2, subs3);
  else if (strlen(subs2) > 0) sprintf(&xccStatData.statName[0],"%s %s", subs1, subs2);
  else                        sprintf(&xccStatData.statName[0],"%s", subs1);

  // Read in Line 2 of LLA file.
  /*--------------------------------------------------------------------------*/
  fgets(line2, 999, fp);

  strncpy(tempA, &line2[ 0], 10); strcpy(&tempA[10], "\0");
  sscanf(&tempA[0], "%lf", &xccStatData.lat);

  strncpy(tempA, &line2[10], 10); strcpy(&tempA[10], "\0");
  sscanf(&tempA[0], "%lf", &xccStatData.lon);

  strncpy(tempA, &line2[21], 10); strcpy(&tempA[10], "\0");
  sscanf(&tempA[0], "%lf", &xccStatData.alt);
  
  return(xccStatData);
  
}//End readTLE

// End preprocessor directives
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/


