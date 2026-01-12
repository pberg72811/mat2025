/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xcctSatDataList.c
// Desc: This routine will read a list of entries in a LLA (Lat, Lon, Alt) file.
//
//                               **SAMPLE**
// Ashburn Virginia
// +39.041400 -077.48100 +100.000000
// Herndon Virginia
// +38.969200 -077.38730 +99.0000000
// Centerville Virginia
// +38.846900 -077.44800 +60.0000000
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
#define DEBUG 0

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
// xccStatDataListInit.
//------------------------------------------------------------------------------
xccStatDataList_t xccStatDataListInit(const CHR08 *fileName)
{
  INT32 ii;
  FILE *fp;
  xccStatDataList_t statDataList;
  xccStatData_t statData;

  // Open the LLA file.
  //------------------------------------------------------------------------------
  XMC_DEBUG_STDOUT("The name of the file is %s\n", fileName);
  fp = fopen( fileName, "r");
  if( fp == NULL)
  {
    printf("Error in opening LLA file %s.\n", fileName);
    return(statDataList);
  }

  // Init the number of stats to zero.
  //------------------------------------------------------------------------------
  statDataList.nStats = 0;

  // For each entry in the LLA:
  // Allocate a statData structure.
  // Read in the LLA data and file in the statData structure.
  //------------------------------------------------------------------------------
  while( !feof(fp) )
  {
    ii = statDataList.nStats;
    statData = xccReadLLA(fp);
    statDataList.theStat[ii] = xccMallocVOID_Align032( sizeof(xccStatData_t) );
    *(statDataList.theStat[ii]) = statData;
    statDataList.nStats++;
  }

  // Close the file.
  //------------------------------------------------------------------------------
  fclose(fp);

  // Return the statDataList.
  //------------------------------------------------------------------------------
  return(statDataList);
}
    
// xccStatDataListTerm.
//------------------------------------------------------------------------------
VOID xccStatDataListTerm(xccStatDataList_t *statDataList)
{
  INT32 ii;

  for(ii = 0; ii < statDataList->nStats; ii++)
  {
    xmcFree(statDataList->theStat[ii]);
  }
}

// End preprocessor directives
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/


