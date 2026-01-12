/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccSatStack.c
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
xccSatData_t xccNullSat = {
  {'N','U','L', 'L'}, // Satellite name.
  0,   // Satellite number.
  0,   // Epoch year.
  0,   // Epoch day.
  0,   // First time derivative of Mean Motion.
  0,   // Second time derivative of Mean Motion.
  0,   // BSTAR drag term.
  0,   // Inclination.         Degrees.
  0,   // Right Ascension.     Degrees.
  0,   // Eccentricity.
  0,   // Argument of Perigee. Degrees.
  0,   // Mean Anomaly.        Degrees.
  0,   // Mean Motion.         Degrees.
  0,   // State Vector position x.
  0,   // State Vector position y.
  0,   // State Vector position z.
  0,   // State Vector velocity x.
  0,   // State Vector velocity y.
  0,   // State Vector velocity z.
  0,   // Latitude of sat.
  0,   // Longitude of sat.
  0,   // Altitude of sat.
  0,   // EpochTimeUTC
  0 }; // Julian Seconds.

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

// xccSatStackInit
//-----------------------------------------------------------------------------
xccSatStack_t *xccSatStackInit( UNT32 size, CCHAR *name )
{
  /* Variables ---------------------------------------------------------------*/
  xccSatStack_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)> xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_SAT_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccSatStack_t *)malloc(sizeof(xccSatStack_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (xccSatData_t *)malloc(size*sizeof(xccSatData_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"SAT");
  ws->size  = size;
  ws->index = -1;

  return(ws);
}

// xccSatStackPush
//-----------------------------------------------------------------------------
INT32 xccSatStackPush( xccSatStack_t *p2Stack, xccSatData_t value )
{
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
}

// xccSatStackPop
//-----------------------------------------------------------------------------
INT32 xccSatStackPop( xccSatStack_t *p2Stack, xccSatData_t *p2value )
{
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value = NULL;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index] = xccNullSat;
    p2Stack->index--;
    return(0);
  }
}

// xccSatStackClear
//------------------------------------------------------------------------------
VOID xccSatStackClear( xccSatStack_t *p2Stack )
{
  INT32 ii;

  p2Stack->index = -1;

  for(ii=0; ii<p2Stack->size; ii++)
  {
    p2Stack->theStack[ii]=xccNullSat;
  }
}

// Terminate the FLT32 stack
//------------------------------------------------------------------------------
VOID xccSatStackTerm(xccSatStack_t *p2WS)
{
  xmcFree( p2WS->theStack ); 
  xmcFree( p2WS ); 
}

// End preprocessor directives
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/


