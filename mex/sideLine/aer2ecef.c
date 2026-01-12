//-----------------------------------------UNCLASSIFIED-------------------------------------------
// File: mexFile01.c
//
// Desc: Mex function to ...
//
// Hist: When       Who  What
//       05/22/2025 ptb  Initial version.
//------------------------------------------------------------------------------------------------
#include "mex.h"
#include "xcc.h"
#include <string.h>

void mexFunction (int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  RFLT64 x;
  RINT08 y;

  if (nrhs != 0)
  {
    mwSize rows = mxGetM(prhs[0]);
    mwSize cols = mxGetN(prhs[0]);
    const char    *className;
    className = mxGetClassName(prhs[0]);
    printf("data type arg1 %s\n",className);
    printf("number of rows %d\n", rows);
    printf("number of cols %d\n", cols);
    printf("Number of right hand statements is: %d\n", nrhs);
    printf("Number of left  hand statements is: %d\n", nlhs);
  }

  printf("Size of RINT08 is %ld\n",  sizeof(RINT08));
  printf("Size of RINT16 is %ld\n",  sizeof(RINT16));
  printf("Size of RINT32 is %ld\n",  sizeof(RINT32));
  printf("Size of RINT64 is %ld\n",  sizeof(RINT64));
  printf("Size of RFLT32 is %ld\n",  sizeof(RFLT32));
  printf("Size of RFLT64 is %ld\n",  sizeof(RFLT64));
  printf("Size of RFLT128 is %ld\n", sizeof(RFLT128));
    
}

// #include <math.h>
// 
// typedef struct {
//     double x;
//     double y;
//     double z;
// } ECEF;
// 
// ECEF spherical_to_ecef(double azimuth, double elevation, double range,
//                        double lat_rad, double lon_rad, double alt_m) {
//     ECEF result;
// 
//     // Convert spherical to local ENU (East, North, Up) coordinates
//     double sin_az = sin(azimuth);
//     double cos_az = cos(azimuth);
//     double sin_el = sin(elevation);
//     double cos_el = cos(elevation);
// 
//     double x_enu = range * cos_el * sin_az;
//     double y_enu = range * cos_el * cos_az;
//     double z_enu = range * sin_el;
// 
//     // Convert ENU to ECEF
//     double sin_lat = sin(lat_rad);
//     double cos_lat = cos(lat_rad);
//     double sin_lon = sin(lon_rad);
//     double cos_lon = cos(lon_rad);
// 
//     result.x = -sin_lon * x_enu - cos_lon * sin_lat * y_enu + cos_lat * cos_lon * z_enu;
//     result.x += (alt_m + 6378137.0) * cos_lat * cos_lon; // WGS84 Earth radius + altitude
// 
//     result.y =  cos_lon * x_enu - sin_lon * sin_lat * y_enu + cos_lat * sin_lon * z_enu;
//     result.y += (alt_m + 6378137.0) * cos_lat * sin_lon;
// 
//     result.z =  cos_lat * y_enu + sin_lat * z_enu;
//     result.z += (alt_m * (1 - 6.69437999014e-3) + 6356752.314245); // WGS84 Earth radius at poles + altitude
// 
//     return result;
// }
