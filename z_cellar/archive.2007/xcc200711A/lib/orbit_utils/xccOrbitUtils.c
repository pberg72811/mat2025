/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: orbit_utils.c
// Desc: 
//
// Hist: When       Who  What
//       09/17/2001 ptb  Initial Code.
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
VOID xccASCIITime(INT32 timeTag, CHR08 *timeString, const CHR08 *frmtString)
{
  struct tm *p2tm;
  time_t givenTime=timeTag;

  p2tm = gmtime(&givenTime);
  strftime(timeString, strlen(timeString), frmtString, p2tm);
  return ;
}

VOID xccCurrentASCIITime( CHR08 *timeString, const CHR08 *frmtString)
{
  time_t getTime;
  struct tm *p2tm;

  getTime = time(NULL);
  p2tm = gmtime(&getTime);
  strftime(timeString, strlen(timeString), frmtString, p2tm);
  return ;
}

// Get/calculate current julian seconds.
//------------------------------------------------------------------------------
INT64 xccCurrentJulianSeconds(VOID)
{
  INT64 js=0;
  time_t getTime;

  getTime = time(NULL);
  js      = (INT64)getTime + XMC_JULIAN_SECONDS_JAN1_1970;

  return js;
}

// Get/calculate current UNIX seconds.
//------------------------------------------------------------------------------
INT64 xccCurrentUNIXSeconds(VOID)
{
  INT64 js=0;
  time_t getTime;

  getTime = time(NULL);
  js      = (INT64)getTime;

  return js;
}

// Get/calculate current UNIX micro seconds.
//------------------------------------------------------------------------------
INT64 xccCurrentUNIXMicroSeconds(VOID)
{
  INT64 t;
  struct timeval tt;
  gettimeofday(&tt, NULL);
  t = ((INT64)tt.tv_sec)*1000000+((INT64)tt.tv_usec);
  return(t);
}

// Get/calculate current J1950 seconds.
//------------------------------------------------------------------------------
INT64 xccCurrentJ1950Seconds(VOID)
{
  INT64 js=0;
  time_t getTime;

  getTime = time(NULL);
  js      = (INT64)getTime + (XMC_JULIAN_SECONDS_JAN1_1970-XMC_JULIAN_SECONDS_JAN1_1950);

  return js;
}

// Get/calculate current J1970 seconds. same as xccCurrentUNIXSeconds
//------------------------------------------------------------------------------
INT64 xccCurrentJ1970Seconds(VOID)
{
  INT64 js=0;
  time_t getTime;

  getTime = time(NULL);
  js      = (INT64)getTime;

  return js;
}

// Convert input mm/dd/yyyy hr:mm:ss to output julian seconds (double).
//------------------------------------------------------------------------------
FLT64 xccDate2JulianSeconds(UNT32 mm, UNT32 id,  UNT32 iyyy,  UNT32 hr,  UNT32 min,  FLT32 sec)
{
  INT64 theDate;
  FLT64 js;
  
  theDate = xccDate2JulianDay(mm, id, iyyy);
  js = 86400.0 * theDate + 3600.0 * hr + 60.0 * min + sec - 43200.0;
  
  return js;
}

// Convert NORAD time to Julian seconds.
//------------------------------------------------------------------------------
FLT64 xccNORAD2JulianSeconds( UNT32 year,  FLT32 day)
{
  double temp;
  double js;

  if( year < 1950 ) year = year + 2000;

  temp = xccDate2JulianSeconds( 1, 1, year, 0, 0, 0);
  js = temp + (day - 1) * 86400;
  return js;
}

// Convert input mm/dd/yyyy to output julian day (long).
//------------------------------------------------------------------------------
INT64 xccDate2JulianDay(UNT32 mm, UNT32 id, UNT32 iyyy)
 {
   INT32 jul;
   INT32 ja, jy, jm;

   if (iyyy < 0)
   {
     ++iyyy;
   }

   if (mm > 2)
   {
     jy = iyyy;
     jm = mm + 1;
   }
   else
   {
     jy = iyyy - 1;
     jm = mm + 13;
   }

   jul = floor( floor(365.25 * jy) + floor(30.6001 * jm) + id + 1720995 + 0.5);

   if ( (id + 31 * (mm + 12 * iyyy)) >= IGREG1)
   {
     ja = floor( 0.01 * jy + 0.5 );
     jul = jul + 2 - ja + floor( 0.25 * ja + 0.5 );
   }

   return jul;
 }

