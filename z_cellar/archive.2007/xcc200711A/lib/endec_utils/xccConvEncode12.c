/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccConvEncoder12.c
// Desc: This file contains the code for the xccConvEncoder12 routine.
// Hist: When       Who  What
//       09/24/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "endec_utils.h"

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
//-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccConvEncoder12.c
// Desc: This function does a generic convolutional encode of an array of ones 
//       and zeros.  The constraint length is variable and the rate is 1/2.
//       For the example diagram below, k = 7, poly1 = 0x79, poly2 = 0x5B, and
//       G2 is inverted.
//
//           ----+-+---+-+-----|>o--->G2
//           |   | |   | |
//           - - - - - - -
// INPUT -->|0|1|2|3|4|5|6|             o-->S1
//           - - - - - - -             /
//           | | | |     |            /
//           --+-+-+-----+------------>G1
//
// Hist: When       Who  What
//       04/09/2003 ptb  Initial Code.
//----------------------------------------------------------------------------*/
xccConvEncoderSpec *xccConvEncoder12Init(INT08 k, INT32 poly1, INT32 poly2, INT08 g1Invert, INT08 g2Invert)
{
  INT32 ii;
  INT32 jj;
  xccConvEncoderSpec *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccConvEncoderSpec *) malloc(sizeof(xccConvEncoderSpec));

  // Handoff variables.
  //----------------------------------------------------------------------------
  spec->k = k;               // Constraint length.
  spec->poly1 = poly1;       // Taps for G1.
  spec->poly2 = poly2;       // Taps for G2.
  spec->g1Invert = g1Invert; // Invert flag for G1.
  spec->g2Invert = g2Invert; // Invert flag for G2.

  // Zero out registers.
  //----------------------------------------------------------------------------
  for( ii = 0; ii < K_MAX; ii++)
  {
    spec->regVector[ii] = 0; // Register Vector.
    spec->g1Vector[ii]  = 0; // G1 vector.
    spec->g2Vector[ii]  = 0; // G2 vector.
  }

  // Set up the G1 and G2 vectors.
  //----------------------------------------------------------------------------
  jj = 0;
  for( ii = (k-1); ii >=0; ii--)
  {
    spec->g1Vector[jj] = ((0x01<<ii)&poly1)>>ii;
    spec->g2Vector[jj] = ((0x01<<ii)&poly2)>>ii;
    jj++;
  }

  return(spec);
}

    
// xccConvEncoder12.
//------------------------------------------------------------------------------
VOID xccConvEncoder12(xccStackINT08_t *inStack, xccStackINT08_t *outStack, xccConvEncoderSpec *spec)
{
  INT08 g1;
  INT08 g2;
  INT08 tmp;
  INT32 status=0;
  INT32 ii;
  
  while( (status = xccStackPopINT08( inStack, &tmp )) == 0 )
  {
    for( ii = (spec->k-1); ii > 0; ii--)
    {
      spec->regVector[ii] = spec->regVector[ii-1];
    }
    spec->regVector[0] = tmp;

    g1 = g2 = 0;

    for(ii = 0; ii < spec->k; ii++)
    {
      g1 = g1 + spec->regVector[ii]*spec->g1Vector[ii];
      g2 = g2 + spec->regVector[ii]*spec->g2Vector[ii];
    }
    g1 = g1%2;
    g2 = g2%2;
    if(spec->g1Invert==TRUE) g1 = (!g1);
    if(spec->g2Invert==TRUE) g2 = (!g2);
    xccStackPushINT08(outStack, g1);
    xccStackPushINT08(outStack, g2);
  }
}

// xccConvEncoder12.
//------------------------------------------------------------------------------
VOID xccvConvEncoder12(INT08 *a, INT32 i, INT08 *b, INT32 j, UNT32 n, xccConvEncoderSpec *spec)
{
  INT08 g1;
  INT08 g2;
  INT32 ii,jj;
  INT08 *pa=a;
  INT08 *pb=b;
  
  for(ii = 0; ii < n; ii++)
  {
    for( jj = (spec->k-1); jj > 0; jj--)
    {
      spec->regVector[jj] = spec->regVector[jj-1];
    }
    spec->regVector[0] = *pa;

    g1 = g2 = 0;

    for(jj = 0; jj < spec->k; jj++)
    {
      g1 = g1 + spec->regVector[jj]*spec->g1Vector[jj];
      g2 = g2 + spec->regVector[jj]*spec->g2Vector[jj];
    }
    g1 = g1%2;
    g2 = g2%2;
    if(spec->g1Invert==TRUE) g1 = (!g1);
    if(spec->g2Invert==TRUE) g2 = (!g2);
    *pb=g1; pb+=j;
    *pb=g2; pb+=j;
    pa+=i;
  }
}

//
//------------------------------------------------------------------------------
VOID xccConvEncoder12Term(xccConvEncoderSpec *spec)
{
  xmcFree( spec );
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
