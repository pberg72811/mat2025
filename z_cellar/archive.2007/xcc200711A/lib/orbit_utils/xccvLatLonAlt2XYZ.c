/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccvLatLonAlt2XYZ.c
// Desc: This file contains the code for the xccOribitUtils routine xccvLatLonAlt2XYZ.
// Hist: When       Who  What
//       12/04/2003 ptb  Initial Code.
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
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS LLAXXXXX *pa=a;
PERL_PREPROCESS VXXXXX   *pb=b;
PERL_PREPROCESS UNT32 k;
PERL_PREPROCESS FLT64 latDE2RA, lonDE2RA;
PERL_PREPROCESS FLT64 R;
PERL_PREPROCESS for(k=0; k<n; k++)
PERL_PREPROCESS {
PERL_PREPROCESS   latDE2RA=pa->lat*DE2RA;               // Convert from degrees to radians for latitude.
PERL_PREPROCESS   lonDE2RA=pa->lon*DE2RA;               // Convert from degrees to radians for longitude.
PERL_PREPROCESS   R=pa->alt+XKMPER;                     // Add Radius of earth to altitude.
PERL_PREPROCESS   pb->x=cos(latDE2RA)*cos(lonDE2RA)*R;  // Calculate x.
PERL_PREPROCESS   pb->y=cos(latDE2RA)*sin(lonDE2RA)*R;  // Calculate y.
PERL_PREPROCESS   pb->z=sin(latDE2RA*R);                // Calculate z.
PERL_PREPROCESS
PERL_PREPROCESS   pa+=i; 
PERL_PREPROCESS   pb+=j;
PERL_PREPROCESS }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID xccvLatLonAlt2XYZFLT32( LLAFLT32 *a, INT32 i, VFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32     START.
 LLAFLT32 *pa=a;
 VFLT32   *pb=b;
 UNT32 k;
 FLT64 latDE2RA, lonDE2RA;
 FLT64 R;
 for(k=0; k<n; k++)
 {
   latDE2RA=pa->lat*DE2RA;               // Convert from degrees to radians for latitude.
   lonDE2RA=pa->lon*DE2RA;               // Convert from degrees to radians for longitude.
   R=pa->alt+XKMPER;                     // Add Radius of earth to altitude.
   pb->x=cos(latDE2RA)*cos(lonDE2RA)*R;  // Calculate x.
   pb->y=cos(latDE2RA)*sin(lonDE2RA)*R;  // Calculate y.
   pb->z=sin(latDE2RA*R);                // Calculate z.

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE FLT32      STOP.
}

VOID xccvLatLonAlt2XYZFLT64( LLAFLT64 *a, INT32 i, VFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64     START.
 LLAFLT64 *pa=a;
 VFLT64   *pb=b;
 UNT32 k;
 FLT64 latDE2RA, lonDE2RA;
 FLT64 R;
 for(k=0; k<n; k++)
 {
   latDE2RA=pa->lat*DE2RA;               // Convert from degrees to radians for latitude.
   lonDE2RA=pa->lon*DE2RA;               // Convert from degrees to radians for longitude.
   R=pa->alt+XKMPER;                     // Add Radius of earth to altitude.
   pb->x=cos(latDE2RA)*cos(lonDE2RA)*R;  // Calculate x.
   pb->y=cos(latDE2RA)*sin(lonDE2RA)*R;  // Calculate y.
   pb->z=sin(latDE2RA*R);                // Calculate z.

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE FLT64      STOP.
}

VOID xccvLatLonAlt2XYZFLT96( LLAFLT96 *a, INT32 i, VFLT96 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96     START.
 LLAFLT96 *pa=a;
 VFLT96   *pb=b;
 UNT32 k;
 FLT64 latDE2RA, lonDE2RA;
 FLT64 R;
 for(k=0; k<n; k++)
 {
   latDE2RA=pa->lat*DE2RA;               // Convert from degrees to radians for latitude.
   lonDE2RA=pa->lon*DE2RA;               // Convert from degrees to radians for longitude.
   R=pa->alt+XKMPER;                     // Add Radius of earth to altitude.
   pb->x=cos(latDE2RA)*cos(lonDE2RA)*R;  // Calculate x.
   pb->y=cos(latDE2RA)*sin(lonDE2RA)*R;  // Calculate y.
   pb->z=sin(latDE2RA*R);                // Calculate z.

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE FLT96      STOP.
}

VOID xccvLatLonAlt2XYZINT08( LLAINT08 *a, INT32 i, VINT08 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT08     START.
 LLAINT08 *pa=a;
 VINT08   *pb=b;
 UNT32 k;
 FLT64 latDE2RA, lonDE2RA;
 FLT64 R;
 for(k=0; k<n; k++)
 {
   latDE2RA=pa->lat*DE2RA;               // Convert from degrees to radians for latitude.
   lonDE2RA=pa->lon*DE2RA;               // Convert from degrees to radians for longitude.
   R=pa->alt+XKMPER;                     // Add Radius of earth to altitude.
   pb->x=cos(latDE2RA)*cos(lonDE2RA)*R;  // Calculate x.
   pb->y=cos(latDE2RA)*sin(lonDE2RA)*R;  // Calculate y.
   pb->z=sin(latDE2RA*R);                // Calculate z.

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE INT08      STOP.
}

VOID xccvLatLonAlt2XYZINT16( LLAINT16 *a, INT32 i, VINT16 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT16     START.
 LLAINT16 *pa=a;
 VINT16   *pb=b;
 UNT32 k;
 FLT64 latDE2RA, lonDE2RA;
 FLT64 R;
 for(k=0; k<n; k++)
 {
   latDE2RA=pa->lat*DE2RA;               // Convert from degrees to radians for latitude.
   lonDE2RA=pa->lon*DE2RA;               // Convert from degrees to radians for longitude.
   R=pa->alt+XKMPER;                     // Add Radius of earth to altitude.
   pb->x=cos(latDE2RA)*cos(lonDE2RA)*R;  // Calculate x.
   pb->y=cos(latDE2RA)*sin(lonDE2RA)*R;  // Calculate y.
   pb->z=sin(latDE2RA*R);                // Calculate z.

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE INT16      STOP.
}

VOID xccvLatLonAlt2XYZINT32( LLAINT32 *a, INT32 i, VINT32 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT32     START.
 LLAINT32 *pa=a;
 VINT32   *pb=b;
 UNT32 k;
 FLT64 latDE2RA, lonDE2RA;
 FLT64 R;
 for(k=0; k<n; k++)
 {
   latDE2RA=pa->lat*DE2RA;               // Convert from degrees to radians for latitude.
   lonDE2RA=pa->lon*DE2RA;               // Convert from degrees to radians for longitude.
   R=pa->alt+XKMPER;                     // Add Radius of earth to altitude.
   pb->x=cos(latDE2RA)*cos(lonDE2RA)*R;  // Calculate x.
   pb->y=cos(latDE2RA)*sin(lonDE2RA)*R;  // Calculate y.
   pb->z=sin(latDE2RA*R);                // Calculate z.

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE INT32      STOP.
}

VOID xccvLatLonAlt2XYZINT64( LLAINT64 *a, INT32 i, VINT64 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT64     START.
 LLAINT64 *pa=a;
 VINT64   *pb=b;
 UNT32 k;
 FLT64 latDE2RA, lonDE2RA;
 FLT64 R;
 for(k=0; k<n; k++)
 {
   latDE2RA=pa->lat*DE2RA;               // Convert from degrees to radians for latitude.
   lonDE2RA=pa->lon*DE2RA;               // Convert from degrees to radians for longitude.
   R=pa->alt+XKMPER;                     // Add Radius of earth to altitude.
   pb->x=cos(latDE2RA)*cos(lonDE2RA)*R;  // Calculate x.
   pb->y=cos(latDE2RA)*sin(lonDE2RA)*R;  // Calculate y.
   pb->z=sin(latDE2RA*R);                // Calculate z.

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE INT64      STOP.
}

VOID xccvLatLonAlt2XYZUNT08( LLAUNT08 *a, INT32 i, VUNT08 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT08     START.
 LLAUNT08 *pa=a;
 VUNT08   *pb=b;
 UNT32 k;
 FLT64 latDE2RA, lonDE2RA;
 FLT64 R;
 for(k=0; k<n; k++)
 {
   latDE2RA=pa->lat*DE2RA;               // Convert from degrees to radians for latitude.
   lonDE2RA=pa->lon*DE2RA;               // Convert from degrees to radians for longitude.
   R=pa->alt+XKMPER;                     // Add Radius of earth to altitude.
   pb->x=cos(latDE2RA)*cos(lonDE2RA)*R;  // Calculate x.
   pb->y=cos(latDE2RA)*sin(lonDE2RA)*R;  // Calculate y.
   pb->z=sin(latDE2RA*R);                // Calculate z.

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE UNT08      STOP.
}

VOID xccvLatLonAlt2XYZUNT16( LLAUNT16 *a, INT32 i, VUNT16 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT16     START.
 LLAUNT16 *pa=a;
 VUNT16   *pb=b;
 UNT32 k;
 FLT64 latDE2RA, lonDE2RA;
 FLT64 R;
 for(k=0; k<n; k++)
 {
   latDE2RA=pa->lat*DE2RA;               // Convert from degrees to radians for latitude.
   lonDE2RA=pa->lon*DE2RA;               // Convert from degrees to radians for longitude.
   R=pa->alt+XKMPER;                     // Add Radius of earth to altitude.
   pb->x=cos(latDE2RA)*cos(lonDE2RA)*R;  // Calculate x.
   pb->y=cos(latDE2RA)*sin(lonDE2RA)*R;  // Calculate y.
   pb->z=sin(latDE2RA*R);                // Calculate z.

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE UNT16      STOP.
}

VOID xccvLatLonAlt2XYZUNT32( LLAUNT32 *a, INT32 i, VUNT32 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT32     START.
 LLAUNT32 *pa=a;
 VUNT32   *pb=b;
 UNT32 k;
 FLT64 latDE2RA, lonDE2RA;
 FLT64 R;
 for(k=0; k<n; k++)
 {
   latDE2RA=pa->lat*DE2RA;               // Convert from degrees to radians for latitude.
   lonDE2RA=pa->lon*DE2RA;               // Convert from degrees to radians for longitude.
   R=pa->alt+XKMPER;                     // Add Radius of earth to altitude.
   pb->x=cos(latDE2RA)*cos(lonDE2RA)*R;  // Calculate x.
   pb->y=cos(latDE2RA)*sin(lonDE2RA)*R;  // Calculate y.
   pb->z=sin(latDE2RA*R);                // Calculate z.

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE UNT32      STOP.
}

VOID xccvLatLonAlt2XYZUNT64( LLAUNT64 *a, INT32 i, VUNT64 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT64     START.
 LLAUNT64 *pa=a;
 VUNT64   *pb=b;
 UNT32 k;
 FLT64 latDE2RA, lonDE2RA;
 FLT64 R;
 for(k=0; k<n; k++)
 {
   latDE2RA=pa->lat*DE2RA;               // Convert from degrees to radians for latitude.
   lonDE2RA=pa->lon*DE2RA;               // Convert from degrees to radians for longitude.
   R=pa->alt+XKMPER;                     // Add Radius of earth to altitude.
   pb->x=cos(latDE2RA)*cos(lonDE2RA)*R;  // Calculate x.
   pb->y=cos(latDE2RA)*sin(lonDE2RA)*R;  // Calculate y.
   pb->z=sin(latDE2RA*R);                // Calculate z.

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE UNT64      STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
