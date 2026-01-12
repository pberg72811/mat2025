/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccvXYZ2LatLonAlt.c
// Desc: This file contains the code for the xccOribitUtils routine xccvXYZ2LatLonAlt.
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
PERL_PREPROCESS VXXXXX   *pa=a;
PERL_PREPROCESS LLAXXXXX *pb=b;
PERL_PREPROCESS UNT32 k;
PERL_PREPROCESS FLT64 R;
PERL_PREPROCESS FLT64 hyp;
PERL_PREPROCESS for(k=0; k<n; k++)
PERL_PREPROCESS {
PERL_PREPROCESS   pb->lon = atan2(pa->y,pa->x)*RA2DE;                 // Calculate the longitude.
PERL_PREPROCESS  
PERL_PREPROCESS   hyp = sqrt(pa->x*pa->x + pa->y*pa->y);              // Calculate the latitude.
PERL_PREPROCESS   pb->lat = atan(pa->z/hyp)*RA2DE;
PERL_PREPROCESS
PERL_PREPROCESS   R = sqrt(pa->x*pa->x + pa->y*pa->y + pa->z*pa->z ); // Calculate the altitude.
PERL_PREPROCESS   pb->alt = (R - XKMPER);
PERL_PREPROCESS
PERL_PREPROCESS   pa+=i; 
PERL_PREPROCESS   pb+=j;
PERL_PREPROCESS }
#endif


/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID xccvXYZ2LatLonAltFLT32( VFLT32 *a, INT32 i, LLAFLT32 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32        START.
 VFLT32   *pa=a;
 LLAFLT32 *pb=b;
 UNT32 k;
 FLT64 R;
 FLT64 hyp;
 for(k=0; k<n; k++)
 {
   pb->lon = atan2(pa->y,pa->x)*RA2DE;                 // Calculate the longitude.
  
   hyp = sqrt(pa->x*pa->x + pa->y*pa->y);              // Calculate the latitude.
   pb->lat = atan(pa->z/hyp)*RA2DE;

   R = sqrt(pa->x*pa->x + pa->y*pa->y + pa->z*pa->z ); // Calculate the altitude.
   pb->alt = (R - XKMPER);

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE FLT32         STOP.
}

VOID xccvXYZ2LatLonAltFLT64( VFLT64 *a, INT32 i, LLAFLT64 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64        START.
 VFLT64   *pa=a;
 LLAFLT64 *pb=b;
 UNT32 k;
 FLT64 R;
 FLT64 hyp;
 for(k=0; k<n; k++)
 {
   pb->lon = atan2(pa->y,pa->x)*RA2DE;                 // Calculate the longitude.
  
   hyp = sqrt(pa->x*pa->x + pa->y*pa->y);              // Calculate the latitude.
   pb->lat = atan(pa->z/hyp)*RA2DE;

   R = sqrt(pa->x*pa->x + pa->y*pa->y + pa->z*pa->z ); // Calculate the altitude.
   pb->alt = (R - XKMPER);

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE FLT64         STOP.
}

VOID xccvXYZ2LatLonAltFLT96( VFLT96 *a, INT32 i, LLAFLT96 *b, INT32 j, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96        START.
 VFLT96   *pa=a;
 LLAFLT96 *pb=b;
 UNT32 k;
 FLT64 R;
 FLT64 hyp;
 for(k=0; k<n; k++)
 {
   pb->lon = atan2(pa->y,pa->x)*RA2DE;                 // Calculate the longitude.
  
   hyp = sqrt(pa->x*pa->x + pa->y*pa->y);              // Calculate the latitude.
   pb->lat = atan(pa->z/hyp)*RA2DE;

   R = sqrt(pa->x*pa->x + pa->y*pa->y + pa->z*pa->z ); // Calculate the altitude.
   pb->alt = (R - XKMPER);

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE FLT96         STOP.
}

VOID xccvXYZ2LatLonAltINT08( VINT08 *a, INT32 i, LLAINT08 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT08        START.
 VINT08   *pa=a;
 LLAINT08 *pb=b;
 UNT32 k;
 FLT64 R;
 FLT64 hyp;
 for(k=0; k<n; k++)
 {
   pb->lon = atan2(pa->y,pa->x)*RA2DE;                 // Calculate the longitude.
  
   hyp = sqrt(pa->x*pa->x + pa->y*pa->y);              // Calculate the latitude.
   pb->lat = atan(pa->z/hyp)*RA2DE;

   R = sqrt(pa->x*pa->x + pa->y*pa->y + pa->z*pa->z ); // Calculate the altitude.
   pb->alt = (R - XKMPER);

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE INT08         STOP.
}

VOID xccvXYZ2LatLonAltINT16( VINT16 *a, INT32 i, LLAINT16 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT16        START.
 VINT16   *pa=a;
 LLAINT16 *pb=b;
 UNT32 k;
 FLT64 R;
 FLT64 hyp;
 for(k=0; k<n; k++)
 {
   pb->lon = atan2(pa->y,pa->x)*RA2DE;                 // Calculate the longitude.
  
   hyp = sqrt(pa->x*pa->x + pa->y*pa->y);              // Calculate the latitude.
   pb->lat = atan(pa->z/hyp)*RA2DE;

   R = sqrt(pa->x*pa->x + pa->y*pa->y + pa->z*pa->z ); // Calculate the altitude.
   pb->alt = (R - XKMPER);

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE INT16         STOP.
}

VOID xccvXYZ2LatLonAltINT32( VINT32 *a, INT32 i, LLAINT32 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT32        START.
 VINT32   *pa=a;
 LLAINT32 *pb=b;
 UNT32 k;
 FLT64 R;
 FLT64 hyp;
 for(k=0; k<n; k++)
 {
   pb->lon = atan2(pa->y,pa->x)*RA2DE;                 // Calculate the longitude.
  
   hyp = sqrt(pa->x*pa->x + pa->y*pa->y);              // Calculate the latitude.
   pb->lat = atan(pa->z/hyp)*RA2DE;

   R = sqrt(pa->x*pa->x + pa->y*pa->y + pa->z*pa->z ); // Calculate the altitude.
   pb->alt = (R - XKMPER);

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE INT32         STOP.
}

VOID xccvXYZ2LatLonAltINT64( VINT64 *a, INT32 i, LLAINT64 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE INT64        START.
 VINT64   *pa=a;
 LLAINT64 *pb=b;
 UNT32 k;
 FLT64 R;
 FLT64 hyp;
 for(k=0; k<n; k++)
 {
   pb->lon = atan2(pa->y,pa->x)*RA2DE;                 // Calculate the longitude.
  
   hyp = sqrt(pa->x*pa->x + pa->y*pa->y);              // Calculate the latitude.
   pb->lat = atan(pa->z/hyp)*RA2DE;

   R = sqrt(pa->x*pa->x + pa->y*pa->y + pa->z*pa->z ); // Calculate the altitude.
   pb->alt = (R - XKMPER);

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE INT64         STOP.
}

VOID xccvXYZ2LatLonAltUNT08( VUNT08 *a, INT32 i, LLAUNT08 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT08        START.
 VUNT08   *pa=a;
 LLAUNT08 *pb=b;
 UNT32 k;
 FLT64 R;
 FLT64 hyp;
 for(k=0; k<n; k++)
 {
   pb->lon = atan2(pa->y,pa->x)*RA2DE;                 // Calculate the longitude.
  
   hyp = sqrt(pa->x*pa->x + pa->y*pa->y);              // Calculate the latitude.
   pb->lat = atan(pa->z/hyp)*RA2DE;

   R = sqrt(pa->x*pa->x + pa->y*pa->y + pa->z*pa->z ); // Calculate the altitude.
   pb->alt = (R - XKMPER);

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE UNT08         STOP.
}

VOID xccvXYZ2LatLonAltUNT16( VUNT16 *a, INT32 i, LLAUNT16 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT16        START.
 VUNT16   *pa=a;
 LLAUNT16 *pb=b;
 UNT32 k;
 FLT64 R;
 FLT64 hyp;
 for(k=0; k<n; k++)
 {
   pb->lon = atan2(pa->y,pa->x)*RA2DE;                 // Calculate the longitude.
  
   hyp = sqrt(pa->x*pa->x + pa->y*pa->y);              // Calculate the latitude.
   pb->lat = atan(pa->z/hyp)*RA2DE;

   R = sqrt(pa->x*pa->x + pa->y*pa->y + pa->z*pa->z ); // Calculate the altitude.
   pb->alt = (R - XKMPER);

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE UNT16         STOP.
}

VOID xccvXYZ2LatLonAltUNT32( VUNT32 *a, INT32 i, LLAUNT32 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT32        START.
 VUNT32   *pa=a;
 LLAUNT32 *pb=b;
 UNT32 k;
 FLT64 R;
 FLT64 hyp;
 for(k=0; k<n; k++)
 {
   pb->lon = atan2(pa->y,pa->x)*RA2DE;                 // Calculate the longitude.
  
   hyp = sqrt(pa->x*pa->x + pa->y*pa->y);              // Calculate the latitude.
   pb->lat = atan(pa->z/hyp)*RA2DE;

   R = sqrt(pa->x*pa->x + pa->y*pa->y + pa->z*pa->z ); // Calculate the altitude.
   pb->alt = (R - XKMPER);

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE UNT32         STOP.
}

VOID xccvXYZ2LatLonAltUNT64( VUNT64 *a, INT32 i, LLAUNT64 *b, INT32 j, UNT32 n)
{
//------------------------------- COMMON-CODE UNT64        START.
 VUNT64   *pa=a;
 LLAUNT64 *pb=b;
 UNT32 k;
 FLT64 R;
 FLT64 hyp;
 for(k=0; k<n; k++)
 {
   pb->lon = atan2(pa->y,pa->x)*RA2DE;                 // Calculate the longitude.
  
   hyp = sqrt(pa->x*pa->x + pa->y*pa->y);              // Calculate the latitude.
   pb->lat = atan(pa->z/hyp)*RA2DE;

   R = sqrt(pa->x*pa->x + pa->y*pa->y + pa->z*pa->z ); // Calculate the altitude.
   pb->alt = (R - XKMPER);

   pa+=i; 
   pb+=j;
 }
//------------------------------- COMMON-CODE UNT64         STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
