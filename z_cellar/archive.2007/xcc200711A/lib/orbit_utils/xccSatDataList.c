/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccSatDataList.c
// Desc: This routine will read one entry in a NORAD two line element file.
//
//                               **SAMPLE**
// LANDSAT 4               
// 1 13367U 82072A   02002.24829717  .00010514  00000-0  97138-3 0   479
// 2 13367  98.2461  77.7885 0011120  39.4968 320.7052 14.94749384 36177
// TDRS 1                  
// 1 13969U 83026B   02003.11757492 -.00000297  00000-0  10000-3 0  4367
// 2 13969  11.1816  27.0948 0003798 247.6963 181.1677  1.00266613 41700
// LANDSAT 5               
// 1 14780U 84021A   02003.12666303  .00002980  00000-0  67056-3 0  4088
// 2 14780  98.1833  70.4034 0002116  71.9732 288.1708 14.57158682948980
// ERBS                    
// 1 15354U 84108B   02003.10436914  .00003894  00000-0  33504-3 0   298
// 2 15354  56.9915 185.5191 0004265 139.2451 220.8924 14.99427957940060
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
// xccSatDataListInit.
//------------------------------------------------------------------------------
xccSatDataList_t xccSatDataListInit(const CHR08 *fileName)
{
  INT32 ii;
  FILE *fp;
  xccSatDataList_t satDataList;
  xccSatData_t satData;

  // Open the TLE file.
  //------------------------------------------------------------------------------
  XMC_DEBUG_STDOUT("The name of the file is %s\n", fileName);
  fp = fopen( fileName, "r");
  if( fp == NULL)
  {
    printf("Error in opening TLE file %s.\n", fileName);
    return(satDataList);
  }

  // Init the number of sats to zero.
  //------------------------------------------------------------------------------
  satDataList.nSats = 0;

  // For each entry in the TLE:
  // Allocate a satData structure.
  // Read in the TLE data and file in the satData structure.
  // Test for to many sats.
  //------------------------------------------------------------------------------
  while( !feof(fp) )
  {
    ii = satDataList.nSats;
    satData = xccReadTLE(fp);
    satDataList.theSat[ii] = xccMallocVOID_Align032( sizeof(xccSatData_t) );
    *(satDataList.theSat[ii]) = satData;
    satDataList.nSats++;
    if(satDataList.nSats>=xcc_MAX_SATS)
    {
      XMC_ERROR_STDOUT("ERROR: To many entries in satDataList.");
      exit(0);
    }
  }

  // Close the file.
  //------------------------------------------------------------------------------
  fclose(fp);

  // Return the satDataList.
  //------------------------------------------------------------------------------
  return(satDataList);
}
    
// xccSatDataListPick.
//------------------------------------------------------------------------------
xccSatData_t xccSatDataListPick(const CHR08 *satName, xccSatDataList_t satList)
{
  INT32 ii=0;
  INT32 status;
  xccSatData_t theSat;

  for( ii = 0; ii < satList.nSats; ii++)
  {
    status = strcmp(satName, satList.theSat[ii]->satName);
    if(status==0)
    {
      XMC_DEBUG_STDOUT("FOUND %s\n",satList.theSat[ii]->satName);
      theSat = *satList.theSat[ii];
    }
      
  }
  return( theSat );
}

// xccSatDataListTerm.
//------------------------------------------------------------------------------
VOID xccSatDataListTerm(xccSatDataList_t *satDataList)
{
  INT32 ii;

  for(ii = 0; ii < satDataList->nSats; ii++)
  {
    xmcFree(satDataList->theSat[ii]);
  }
}

// End preprocessor directives
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
