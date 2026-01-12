/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccReadTLE.c
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
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
xccSatData_t xccReadTLE(FILE *fp)
{
  CHR08 line1[72], line2[72], line3[72];
  CHR08 tempA[32], tempB[32], tempC[32];
  CHR08 subs1[32], subs2[32];
  xccSatData_t xccSatData;
  INT32 len,x,y;

  // Make sure strings is clean.
  //----------------------------------------------------------------------------
  memset(line1, 0, 72);
  memset(line2, 0, 72);
  memset(line3, 0, 72);
  memset(subs1, 0, 32);
  memset(subs2, 0, 32);

  // Read in Line 1 of NORAD two line elements
  //----------------------------------------------------------------------------
  fgets(line1, 999, fp);
  //len = strlen(line1);
  //printf("line1 is %s\n",line1);
  //printf("len is %ld\n",len);
  sscanf(line1, "%s %s", &subs1[0], &subs2[0]);
  if (strlen(subs2) > 0) sprintf(&xccSatData.satName[0],"%s %s", subs1, subs2);
  else                   sprintf(&xccSatData.satName[0],"%s", subs1);

  //printf("subs1 is %s and length is %d\n", subs1, strlen(subs1) );
  //printf("subs2 is %s and length is %d\n", subs2, strlen(subs2) );
  //sscanf(line1, "%s", &xccSatData.satName[0]);
  //strcpy(&xccSatData.satName[0],line1);

  // Read in Line 2 of NORAD two line elements
  //----------------------------------------------------------------------------
  fgets(line2, 999, fp);

  strncpy(tempA, &line2[ 3-1],  7- 3+1); strcpy(&tempA[ 7- 3+1], "\0");
  sscanf(&tempA[0], "%ld", &xccSatData.satNumb);
  
  strncpy(tempA, &line2[19-1], 20-19+1); strcpy(&tempA[20-19+1], "\0");
  sscanf(&tempA[0], "%ld", &xccSatData.epochYear);
  
  strncpy(tempA, &line2[21-1], 32-21+1); strcpy(&tempA[32-21+1], "\0");
  sscanf(&tempA[0], "%f",  &xccSatData.epochDay);
  
  strncpy(tempA, &line2[34-1], 43-34+1); strcpy(&tempA[43-34+1], "\0");
  sscanf(&tempA[0], "%lf", &xccSatData.XNDT20);
  
  strncpy(tempA, &line2[45-1], 52-45+1); strcpy(&tempA[52-45+1], "\0");
  len = strcspn(tempA,"+-");
  strncpy(tempB,tempA,len);strcpy(&tempB[len],"\0");
  sscanf(tempB,"%ld",&x);
  tempC[0] = tempA[len+1]; tempC[1] = '\0';
  sscanf(tempC,"%ld",&y);
  sprintf(&tempA[0],"0.%lde-%ld",x,y);
  sscanf(&tempA[0], "%lf", &xccSatData.XNDD60);
  //sscanf(&tempA[0], "%s",  &tempB[0]);
  //sprintf(&tempC[0],".%s", &tempB[0]);
  //sscanf(&tempC[0], "%lf", &xccSatData.XNDD60);
  
  strncpy(tempA, &line2[54-1], 61-54+1); strcpy(&tempA[61-54+1], "\0");
  len = strcspn(tempA,"+-");
  strncpy(tempB,tempA,len);strcpy(&tempB[len],"\0");
  sscanf(tempB,"%ld",&x);
  tempC[0] = tempA[len+1]; tempC[1] = '\0';
  sscanf(tempC,"%ld",&y);
  sprintf(&tempA[0],"0.%lde-%ld",x,y);
  sscanf(&tempA[0], "%lf", &xccSatData.BSTAR);
  //sscanf(&tempA[0], "%s",  &tempB[0]);
  //sprintf(&tempC[0],".%s", &tempB[0]);
  //sscanf(&tempC[0], "%lf", &xccSatData.BSTAR);

  // Read in Line 3 of NORAD two line elements (HUH?)
  //----------------------------------------------------------------------------
  fgets(line3, 999, fp);

  strncpy(tempA, &line3[ 9-1], 16- 9+1); strcpy(&tempA[16- 9+1], "\0");
  sscanf(&tempA[0], "%lf", &xccSatData.XINCL);
  
  strncpy(tempA, &line3[18-1], 25-18+1); strcpy(&tempA[25-18+1], "\0");
  sscanf(&tempA[0], "%lf", &xccSatData.XNODEO);

  strncpy(tempA, &line3[27-1], 33-27+1); strcpy(&tempA[33-27+1], "\0");
  sscanf(&tempA[0], "%s",  &tempB[0]);
  sprintf(&tempC[0],".%s", &tempB[0]);
  sscanf(&tempC[0], "%lf",  &xccSatData.EO);
  
  strncpy(tempA, &line3[35-1], 42-35+1); strcpy(&tempA[42-35+1], "\0");
  sscanf(&tempA[0], "%lf", &xccSatData.OMEGAO);

  strncpy(tempA, &line3[44-1], 51-44+1); strcpy(&tempA[51-44+1], "\0");
  sscanf(&tempA[0], "%lf", &xccSatData.XMO);
  
  strncpy(tempA, &line3[53-1], 63-53+1); strcpy(&tempA[63-53+1], "\0");
  sscanf(&tempA[0], "%lf", &xccSatData.XNO);

  // Convert from degrees to radians.
  //----------------------------------------------------------------------------
  xccSatData.XINCL  = DE2RA * xccSatData.XINCL;
  xccSatData.XNODEO = DE2RA * xccSatData.XNODEO;
  xccSatData.OMEGAO = DE2RA * xccSatData.OMEGAO;
  xccSatData.XMO    = DE2RA * xccSatData.XMO;

  // Convert NORAD epoch day and year to epoch julian seconds.
  //----------------------------------------------------------------------------
  xccSatData.epochTimeUTC = xccNORAD2JulianSeconds( xccSatData.epochYear,  xccSatData.epochDay);

  return(xccSatData);
  
}//End readTLE

// End preprocessor directives
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/


