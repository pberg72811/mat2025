/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: orbit_utils.h
// Desc: This is the header file for orbit_utils.
// Hist: When       Who  What
//       08/10/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef ORBIT_UTILS_H
#define ORBIT_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "xmc.h"
#include "malloc_utils.h"
#include "stack_utils.h"
#include "vector_utils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define xcc_SECONDS_PER_SIDEREAL_DAY          86400.000
#define xcc_EARTH_REVS_PER_SIDEREAL_DAY           1.00273790934
#define IGREG1                         (15 + 31 * (10 + 12 * 1582))

//#define TOTHRD     0.6666666667

#define E6A        1.0E-6
#define PIO2       1.570796326794897
#define QO       120.0
#define SO        78.0
#define TOTHRD     0.6666666667
#define X3PIO2     4.712388980384690
#define XJ2        1.082616E-3
#define XJ3       -0.253881E-5
#define XJ4       -1.65597E-6
#define XKE        0.743669161E-1
#define XKMPER  6378.135
#define XMNPDA  1440.0
#define AE         1.0

#define CK2        5.413080e-4
#define CK4        0.62098875e-6
#define QOMS2T     1.88027916e-9
#define S          1.01222928

#define KEP        3.986008e5
#define J2         0.0010826

#define xcc_MAX_SATS 4096

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
typedef struct
{
  CHR08 satName[32]; // Satellite name.
  INT32 satNumb;     // Satellite number.
  INT32 epochYear;   // Epoch year.
  FLT32 epochDay;    // Epoch day.
  FLT64 XNDT20;      // First time derivative of Mean Motion.
  FLT64 XNDD60;      // Second time derivative of Mean Motion.
  FLT64 BSTAR;       // BSTAR drag term.
  FLT64 XINCL;       // Inclination.         Degrees.
  FLT64 XNODEO;      // Right Ascension.     Degrees.
  FLT64 EO;          // Eccentricity.
  FLT64 OMEGAO;      // Argument of Perigee. Degrees.
  FLT64 XMO;         // Mean Anomaly.        Degrees.
  FLT64 XNO;         // Mean Motion.         Degrees.
  FLT64 x;           // State Vector position x.
  FLT64 y;           // State Vector position y.
  FLT64 z;           // State Vector position z.
  FLT64 xDot;        // State Vector velocity x.
  FLT64 yDot;        // State Vector velocity y.
  FLT64 zDot;        // State Vector velocity z.
  FLT64 xDotDot;     // State Vector acceleration x.
  FLT64 yDotDot;     // State Vector acceleration y.
  FLT64 zDotDot;     // State Vector acceleration z.
  FLT64 lat;         // Latitude of sat.
  FLT64 lon;         // Longitude of sat.
  FLT64 alt;         // Altitude of sat.
  FLT64 epochTimeUTC;
  FLT64 currentTimeUTC;
}xccSatData_t;

typedef struct
{
  CHR08 statName[32]; // Station Name.
  FLT64 x;            // Station ECI X position.
  FLT64 y;            // Station ECI Y position.
  FLT64 z;            // Station ECI Z position.
  FLT64 xDot;         // Station ECI X velocity.
  FLT64 yDot;         // Station ECI Y velocity.
  FLT64 zDot;         // Station ECI Z velocity.
  FLT64 xDotDot;      // Station ECI X acceleration.
  FLT64 yDotDot;      // Station ECI Y acceleration.
  FLT64 zDotDot;      // Station ECI Z acceleration.
  FLT64 lat;          // Station latitude.
  FLT64 lon;          // Station longitude.
  FLT64 alt;          // Station altitude.
  FLT64 currentTimeUTC;
}xccStatData_t;

typedef struct
{
  INT32 nSats;
  xccSatData_t *theSat[xcc_MAX_SATS];
} xccSatDataList_t;

typedef struct
{
  INT32 nStats;
  xccStatData_t *theStat[xcc_MAX_SATS];
} xccStatDataList_t;

typedef struct
{
  CHR08 name[xcc_STACK_NAME_LENGTH];
  CHR08 type[xcc_STACK_TYPE_LENGTH];
  UNT32 size;
  INT64 index;  
  xccSatData_t *theStack;
} xccSatStack_t;

typedef struct
{
  CHR08 name[xcc_STACK_NAME_LENGTH];
  CHR08 type[xcc_STACK_TYPE_LENGTH];
  UNT32 size;
  INT64 index;  
  xccStatData_t *theStack;
} xccStatStack_t;

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
INT64 xccCurrentJulianSeconds (VOID);
INT64 xccCurrentUNIXSeconds   (VOID);
INT64 xccCurrentUNIXMicroSeconds(VOID);
INT64 xccCurrentJ1950Seconds  (VOID);
INT64 xccCurrentJ1970Seconds  (VOID);
FLT64 xccGetPhiGrn            (FLT64);
FLT64 xccRa2Lon               (FLT64, FLT64);
VOID  xccCurrentASCIITime     (CHR08 *timeString, const CHR08 *frmtString);
VOID  xccASCIITime(INT32 timeTag, CHR08 *timeString, const CHR08 *frmtString);
FLT64 xccDate2JulianSeconds   (UNT32, UNT32, UNT32,  UNT32,  UNT32,  FLT32);
INT64 xccDate2JulianDay       (UNT32, UNT32, UNT32);
FLT64 xccNORAD2JulianSeconds  (UNT32, FLT32);
FLT64 xccTrueToFromMeanAnomaly(FLT64, FLT64, INT16);
VOID  xccJ2(xccSatData_t *xccSatData, FLT64 dTint);

//
//------------------------------------------------------------------------------
xccSatData_t  xccReadTLE(FILE *);
xccStatData_t xccReadLLA(FILE *);

//
//------------------------------------------------------------------------------
xccSatDataList_t  xccSatDataListInit (const CHR08 *fileName);
VOID              xccSatDataListTerm (xccSatDataList_t *xccSatDataList);
xccStatDataList_t xccStatDataListInit(const CHR08 *fileName);
VOID              xccStatDataListTerm(xccStatDataList_t *xccStatDataList);
xccSatData_t      xccSatDataListPick(const CHR08 *satName, xccSatDataList_t satList);

VOID xccSatUpdateSGP(xccSatData_t  *xccSatData,  FLT64 js);
VOID xccSatUpdateJ2 (xccSatData_t  *xccSatData,  FLT64 js);
VOID xccStatUpdate  (xccStatData_t *xccStatData, FLT64 js);

//
//------------------------------------------------------------------------------
VOID xccSGP( FLT64 XNDT2O,  //First Time Derivative
             FLT64 XNDD6O,  //Second Time Derivative
             FLT64 BSTAR,   //BSTAR drag term
             FLT64 XINCL,   //Inclination
             FLT64 XNODEO,  //Right ascension of ascending node
             FLT64 EO,      //Eccentricity
             FLT64 OMEGAO,  //Argument of Perigee
             FLT64 XMO,     //Mean Anomaly
             FLT64 XNO,     //Mean Motion
             FLT64 TS,      //Time since in minutes
             FLT64 *p2X,    //X position
             FLT64 *p2Y,    //Y position
             FLT64 *p2Z,    //Z position
             FLT64 *p2XDOT, //X velocity
             FLT64 *p2YDOT, //Y velocity
             FLT64 *p2ZDOT); //Z velocity

//
//------------------------------------------------------------------------------
VOID xccDirCos2AzEl(FLT64 alpha, FLT64 beta, FLT64 gamma, FLT64 *az, FLT64 *el);
VOID xccAzEl2DirCos(FLT64 az, FLT64 el, FLT64 *alpha, FLT64 *beta, FLT64 *gamma);

VOID xccCalcDirCos(FLT64  x1, FLT64  y1, FLT64  z1,  // Source satellite x,y,z.
		   FLT64 vx1, FLT64 vy1, FLT64 vz1,  // Source satellite vx,vy,vz.
		   FLT64  x2, FLT64  y2, FLT64  z2,  // Destination satellite x,y,z.
		   FLT64  *a, FLT64  *b, FLT64  *g); // Direction Cosines alpha,beta,gamma.
//
//------------------------------------------------------------------------------
VOID xccvLatLonAlt2XYZFLT32( LLAFLT32 *a, INT32 i, VFLT32 *b, INT32 j, UNT32 n );
VOID xccvLatLonAlt2XYZFLT64( LLAFLT64 *a, INT32 i, VFLT64 *b, INT32 j, UNT32 n );
VOID xccvLatLonAlt2XYZFLT96( LLAFLT96 *a, INT32 i, VFLT96 *b, INT32 j, UNT32 n );
VOID xccvLatLonAlt2XYZINT08( LLAINT08 *a, INT32 i, VINT08 *b, INT32 j, UNT32 n );
VOID xccvLatLonAlt2XYZINT16( LLAINT16 *a, INT32 i, VINT16 *b, INT32 j, UNT32 n );
VOID xccvLatLonAlt2XYZINT32( LLAINT32 *a, INT32 i, VINT32 *b, INT32 j, UNT32 n );
VOID xccvLatLonAlt2XYZINT64( LLAINT64 *a, INT32 i, VINT64 *b, INT32 j, UNT32 n );
VOID xccvLatLonAlt2XYZUNT08( LLAUNT08 *a, INT32 i, VUNT08 *b, INT32 j, UNT32 n );
VOID xccvLatLonAlt2XYZUNT16( LLAUNT16 *a, INT32 i, VUNT16 *b, INT32 j, UNT32 n );
VOID xccvLatLonAlt2XYZUNT32( LLAUNT32 *a, INT32 i, VUNT32 *b, INT32 j, UNT32 n );
VOID xccvLatLonAlt2XYZUNT64( LLAUNT64 *a, INT32 i, VUNT64 *b, INT32 j, UNT32 n );

//
//------------------------------------------------------------------------------
VOID xccvXYZ2LatLonAltFLT32( VFLT32 *a, INT32 i, LLAFLT32 *b, INT32 j, UNT32 n );
VOID xccvXYZ2LatLonAltFLT64( VFLT64 *a, INT32 i, LLAFLT64 *b, INT32 j, UNT32 n );
VOID xccvXYZ2LatLonAltFLT96( VFLT96 *a, INT32 i, LLAFLT96 *b, INT32 j, UNT32 n );
VOID xccvXYZ2LatLonAltINT08( VINT08 *a, INT32 i, LLAINT08 *b, INT32 j, UNT32 n );
VOID xccvXYZ2LatLonAltINT16( VINT16 *a, INT32 i, LLAINT16 *b, INT32 j, UNT32 n );
VOID xccvXYZ2LatLonAltINT32( VINT32 *a, INT32 i, LLAINT32 *b, INT32 j, UNT32 n );
VOID xccvXYZ2LatLonAltINT64( VINT64 *a, INT32 i, LLAINT64 *b, INT32 j, UNT32 n );
VOID xccvXYZ2LatLonAltUNT08( VUNT08 *a, INT32 i, LLAUNT08 *b, INT32 j, UNT32 n );
VOID xccvXYZ2LatLonAltUNT16( VUNT16 *a, INT32 i, LLAUNT16 *b, INT32 j, UNT32 n );
VOID xccvXYZ2LatLonAltUNT32( VUNT32 *a, INT32 i, LLAUNT32 *b, INT32 j, UNT32 n );
VOID xccvXYZ2LatLonAltUNT64( VUNT64 *a, INT32 i, LLAUNT64 *b, INT32 j, UNT32 n );

//
//------------------------------------------------------------------------------
VOID xccvPitchXYZFLT32( VFLT32 *a, INT32 i, VFLT32 *b, INT32 j, FLT64 pitch, UNT32 n );
VOID xccvPitchXYZFLT64( VFLT64 *a, INT32 i, VFLT64 *b, INT32 j, FLT64 pitch, UNT32 n );
VOID xccvPitchXYZFLT96( VFLT96 *a, INT32 i, VFLT96 *b, INT32 j, FLT64 pitch, UNT32 n );
VOID xccvPitchXYZINT08( VINT08 *a, INT32 i, VINT08 *b, INT32 j, FLT64 pitch, UNT32 n );
VOID xccvPitchXYZINT16( VINT16 *a, INT32 i, VINT16 *b, INT32 j, FLT64 pitch, UNT32 n );
VOID xccvPitchXYZINT32( VINT32 *a, INT32 i, VINT32 *b, INT32 j, FLT64 pitch, UNT32 n );
VOID xccvPitchXYZINT64( VINT64 *a, INT32 i, VINT64 *b, INT32 j, FLT64 pitch, UNT32 n );
VOID xccvPitchXYZUNT08( VUNT08 *a, INT32 i, VUNT08 *b, INT32 j, FLT64 pitch, UNT32 n );
VOID xccvPitchXYZUNT16( VUNT16 *a, INT32 i, VUNT16 *b, INT32 j, FLT64 pitch, UNT32 n );
VOID xccvPitchXYZUNT32( VUNT32 *a, INT32 i, VUNT32 *b, INT32 j, FLT64 pitch, UNT32 n );
VOID xccvPitchXYZUNT64( VUNT64 *a, INT32 i, VUNT64 *b, INT32 j, FLT64 pitch, UNT32 n );

//
//------------------------------------------------------------------------------
VOID xccvRollXYZFLT32( VFLT32 *a, INT32 i, VFLT32 *b, INT32 j, FLT64 roll, UNT32 n );
VOID xccvRollXYZFLT64( VFLT64 *a, INT32 i, VFLT64 *b, INT32 j, FLT64 roll, UNT32 n );
VOID xccvRollXYZFLT96( VFLT96 *a, INT32 i, VFLT96 *b, INT32 j, FLT64 roll, UNT32 n );
VOID xccvRollXYZINT08( VINT08 *a, INT32 i, VINT08 *b, INT32 j, FLT64 roll, UNT32 n );
VOID xccvRollXYZINT16( VINT16 *a, INT32 i, VINT16 *b, INT32 j, FLT64 roll, UNT32 n );
VOID xccvRollXYZINT32( VINT32 *a, INT32 i, VINT32 *b, INT32 j, FLT64 roll, UNT32 n );
VOID xccvRollXYZINT64( VINT64 *a, INT32 i, VINT64 *b, INT32 j, FLT64 roll, UNT32 n );
VOID xccvRollXYZUNT08( VUNT08 *a, INT32 i, VUNT08 *b, INT32 j, FLT64 roll, UNT32 n );
VOID xccvRollXYZUNT16( VUNT16 *a, INT32 i, VUNT16 *b, INT32 j, FLT64 roll, UNT32 n );
VOID xccvRollXYZUNT32( VUNT32 *a, INT32 i, VUNT32 *b, INT32 j, FLT64 roll, UNT32 n );
VOID xccvRollXYZUNT64( VUNT64 *a, INT32 i, VUNT64 *b, INT32 j, FLT64 roll, UNT32 n );

//
//------------------------------------------------------------------------------
VOID xccvYawXYZFLT32( VFLT32 *a, INT32 i, VFLT32 *b, INT32 j, FLT64 yaw, UNT32 n );
VOID xccvYawXYZFLT64( VFLT64 *a, INT32 i, VFLT64 *b, INT32 j, FLT64 yaw, UNT32 n );
VOID xccvYawXYZFLT96( VFLT96 *a, INT32 i, VFLT96 *b, INT32 j, FLT64 yaw, UNT32 n );
VOID xccvYawXYZINT08( VINT08 *a, INT32 i, VINT08 *b, INT32 j, FLT64 yaw, UNT32 n );
VOID xccvYawXYZINT16( VINT16 *a, INT32 i, VINT16 *b, INT32 j, FLT64 yaw, UNT32 n );
VOID xccvYawXYZINT32( VINT32 *a, INT32 i, VINT32 *b, INT32 j, FLT64 yaw, UNT32 n );
VOID xccvYawXYZINT64( VINT64 *a, INT32 i, VINT64 *b, INT32 j, FLT64 yaw, UNT32 n );
VOID xccvYawXYZUNT08( VUNT08 *a, INT32 i, VUNT08 *b, INT32 j, FLT64 yaw, UNT32 n );
VOID xccvYawXYZUNT16( VUNT16 *a, INT32 i, VUNT16 *b, INT32 j, FLT64 yaw, UNT32 n );
VOID xccvYawXYZUNT32( VUNT32 *a, INT32 i, VUNT32 *b, INT32 j, FLT64 yaw, UNT32 n );
VOID xccvYawXYZUNT64( VUNT64 *a, INT32 i, VUNT64 *b, INT32 j, FLT64 yaw, UNT32 n );

// Satellite stack routines.
//------------------------------------------------------------------------------
xccSatStack_t *xccSatStackInit( UNT32 size, CCHAR *name );
INT32          xccSatStackPush( xccSatStack_t *p2Stack, xccSatData_t value );
INT32          xccSatStackPop( xccSatStack_t *p2Stack, xccSatData_t *p2value );
VOID           xccSatStackClear( xccSatStack_t *p2Stack );
VOID           xccSatStackTerm(xccSatStack_t *p2WS);

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/
