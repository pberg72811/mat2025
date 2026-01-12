/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccCalcDirCos.c
// Desc: This routine performs a direction cosine calculation.
// Hist: When       Who  What
//       08/01/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "orbit_utils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define DEBUG 0

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
VOID xccCalcDirCos(FLT64  x1, FLT64  y1, FLT64  z1, // Source satellite x,y,z.
		   FLT64 vx1, FLT64 vy1, FLT64 vz1, // Source satellite vx,vy,vz.
		   FLT64  x2, FLT64  y2, FLT64  z2, // Destination satellite x,y,z.
		   FLT64  *a, FLT64  *b, FLT64  *g) // Direction Cosines alpha,beta,gamma.
{
  FLT64 diffx, diffy, diffz;
  FLT64 magTemp;
  FLT64 normDiffx, normDiffy, normDiffz;
  FLT64 normSat1x, normSat1y, normSat1z;
  FLT64 xAxisx, xAxisy, xAxisz;
  FLT64 yAxisx, yAxisy, yAxisz;
  FLT64 zAxisx, zAxisy, zAxisz;
  FLT64 temp;

  // Difference Vector between the two sats.
  //------------------------------------------------------------------------------
  diffx = x2-x1;
  diffy = y2-y1;
  diffz = z2-z1;

  magTemp = sqrt(diffx*diffx+diffy*diffy+diffz*diffz);

  normDiffx = diffx/magTemp;
  normDiffy = diffy/magTemp;
  normDiffz = diffz/magTemp;

  // zAxis is pointed at center of earth (NADIR).
  //------------------------------------------------------------------------------
  magTemp = sqrt(x1*x1 + y1*y1 + z1*z1);

  normSat1x = x1/magTemp;
  normSat1y = y1/magTemp;
  normSat1z = z1/magTemp;

  zAxisx = -normSat1x;
  zAxisy = -normSat1y;
  zAxisz = -normSat1z;

  // xAxis.  Velocity vector minus a pinch.
  //------------------------------------------------------------------------------
  temp = vx1*zAxisx + vy1*zAxisy + vz1*zAxisz;

  xAxisx = vx1-temp*zAxisx;
  xAxisy = vy1-temp*zAxisy;
  xAxisz = vz1-temp*zAxisz;
  
  magTemp = sqrt(xAxisx*xAxisx + xAxisy*xAxisy + xAxisz*xAxisz);

  xAxisx = xAxisx/magTemp;
  xAxisy = xAxisy/magTemp;
  xAxisz = xAxisz/magTemp;

  // yAxis is cross product of zAxis and xAxis.
  //------------------------------------------------------------------------------
  xccCrossProductFLT64( zAxisx,  zAxisy,  zAxisz,
                        xAxisx,  xAxisy,  xAxisz,
                        &yAxisx, &yAxisy, &yAxisz);

  magTemp = sqrt(yAxisx*yAxisx + yAxisy*yAxisy + yAxisz*yAxisz);

  yAxisx = yAxisx/magTemp;
  yAxisy = yAxisy/magTemp;
  yAxisz = yAxisz/magTemp;

  // Calculate direction cosines.  Dot product of difference vector and each axis.
  //------------------------------------------------------------------------------
  *a = normDiffx*xAxisx + normDiffy*xAxisy + normDiffz*xAxisz;
  *b = normDiffx*yAxisx + normDiffy*yAxisy + normDiffz*yAxisz;
  *g = normDiffx*zAxisx + normDiffy*zAxisy + normDiffz*zAxisz;

  return;
}
// End preprocessor directives
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
