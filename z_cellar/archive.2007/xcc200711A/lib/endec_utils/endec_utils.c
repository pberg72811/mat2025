/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: endec_utils.c
// Desc: This file contains the code for the endec_utils routine.
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
// File: xccConvEncoder1_2.c
// Desc: This function does a convolutional encode of an array of one and zeros.
//       The constrait length is 7 and the rate is 1/2 (C7R1_2 notation).
//       For the example diagram below, poly1 = 0x79, and poly2 = 0x5B.
//           ----+-+---+-+-----|>o--->G2
//           |   | |   | |
//           - - - - - - -
// INPUT -->|0|1|2|3|4|5|6|             o-->S1
//           - - - - - - -             /
//           | | | |     |            /
//           --+-+-+-----+------------>G1
//
// Hist: When       Who  What
//       07/13/2001 ptb  Initial Code.
//----------------------------------------------------------------------------*/
VOID xccConvEncoder1_2(xccStackINT08_t *inStack, xccStackINT08_t *outStack, INT08 poly1, INT08 poly2)
{
  INT08 regVector[7]={0,0,0,0,0,0,0};
  INT08 result1;
  INT08 result2;
  INT08 tmp;
  INT32 status=0;
  
  while( (status = xccStackPopINT08( inStack, &tmp )) == 0 )
  {
    regVector[6] = regVector[5];
    regVector[5] = regVector[4];
    regVector[4] = regVector[3];
    regVector[3] = regVector[2];
    regVector[2] = regVector[1];
    regVector[1] = regVector[0];
    regVector[0] = tmp;

    result1 = regVector[0]*((0x40&poly1)>>6) +
              regVector[1]*((0x20&poly1)>>5) +
              regVector[2]*((0x10&poly1)>>4) +
              regVector[3]*((0x08&poly1)>>3) +
              regVector[4]*((0x04&poly1)>>2) +
              regVector[5]*((0x02&poly1)>>1) +
              regVector[6]*((0x01&poly1)>>0);

    result2 = regVector[0]*((0x40&poly2)>>6) +
              regVector[1]*((0x20&poly2)>>5) +
              regVector[2]*((0x10&poly2)>>4) +
              regVector[3]*((0x08&poly2)>>3) +
              regVector[4]*((0x04&poly2)>>2) +
              regVector[5]*((0x02&poly2)>>1) +
              regVector[6]*((0x01&poly2)>>0);

    result1 = result1%2;
    result2 = result2%2;
    result2 = !result2;

    xccStackPushINT08(outStack, result1);
    xccStackPushINT08(outStack, result2);

  }
}

VOID xccConvEncoderK4R1_2(xccStackINT08_t *inStack, xccStackINT08_t *outStack, INT08 poly1, INT08 poly2)
{
  INT08 regVector[4]={0,0,0,0};
  INT08 g1;
  INT08 g2;
  INT08 tmp;
  INT32 status=0;
  
  while( (status = xccStackPopINT08( inStack, &tmp )) == 0 )
  {
    regVector[3] = regVector[2];
    regVector[2] = regVector[1];
    regVector[1] = regVector[0];
    regVector[0] = tmp;

    g1 = regVector[0]*((0x08&poly1)>>3) +
         regVector[1]*((0x04&poly1)>>2) +
         regVector[2]*((0x02&poly1)>>1) +
         regVector[3]*((0x01&poly1)>>0);

    g2 = regVector[0]*((0x08&poly2)>>3) +
         regVector[1]*((0x04&poly2)>>2) +
         regVector[2]*((0x02&poly2)>>1) +
         regVector[3]*((0x01&poly2)>>0);

    g1 = g1%2;
    g2 = g2%2;
    //result2 = !result2; G2 inversion

    xccStackPushINT08(outStack, g1);
    xccStackPushINT08(outStack, g2);

  }
}

INT08 xccHammingWeightINT08(INT08 x, INT08 y)
{
  INT08 z;
  INT08 ii;
  INT08 sum=0;
  INT08 mask = 0x01;

  // XOR x and y. --------------------------------------------------------------
  z = x ^ y;

  // Run through the sum of the bits. ------------------------------------------
  for(ii = 0; ii < 8; ii++)
  {
    sum += z&mask;
    z=z>>1;
  }

  // Return the answer. --------------------------------------------------------
  return(sum);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
