/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccRSEndcode255_233.c
// Desc: This file contains the code for the xccRSEndcode255_233 routine.
// Hist: When       Who  What
//       06/27/2002 ptb  Initial Code.
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
/*                                                                            */
/*----------------------------------------------------------------------------*/
xccRSEncoderSpec *xccRSEncoderInit255_223(UNT08 genPoly) //0x87 for CCSDS
{
  xccRSEncoderSpec *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccRSEncoderSpec *) xccMallocINT08_Align032(sizeof(xccRSEncoderSpec));

  spec->nParity = 32;

  // Copy the generator polynomial.
  //----------------------------------------------------------------------------
  spec->genPoly = genPoly;

  // Initialize the Galois field.
  //----------------------------------------------------------------------------
  xccGenGalois2_8( genPoly, spec->gf );

  // Initialize the parity field.
  //----------------------------------------------------------------------------
  xccvFillUNT08( spec->parity, 1, 0, 32 );

  // Initialize the alpha field.
  //----------------------------------------------------------------------------
  xccvRampINT32( spec->alpha, 1, -1, 1, 256);

  // Done.
  //----------------------------------------------------------------------------
  return(spec);
}
// Terminate the xccRSEncoder spec.
//------------------------------------------------------------------------------
VOID xccRSEncoderPrintGF(xccRSEncoderSpec *spec)
{
  INT32 ii,jj;
  for(ii = 0; ii < 256; ii++)
  {
    printf("Galois Field %03ld is %03d :",ii,spec->gf[ii]);
    for(jj=0;jj<8;jj++) printf("%1d",(spec->gf[ii]>>jj)&0x01);
    printf("  :");
    printf("Alpha is %03ld.", spec->alpha[ii]);
    printf("\n");
  }
}
  
// Terminate the xccRSEncoder spec.
//------------------------------------------------------------------------------
VOID xccRSEncoderTerm(xccRSEncoderSpec *spec)
{
  xmcFree(spec);
}


// gfFindAlpha2_8. Find the exponent for a given finite field value.
//------------------------------------------------------------------------------
UNT08 gfFindAlpha2_8(UNT08 x, xccRSEncoderSpec *spec)
{
  UNT08 jj=0;
  INT32 stopFlag=FALSE;

  while(!stopFlag)
  {
    if( x != spec->gf[jj] ){
      jj++;
    }
    else stopFlag=TRUE;
  }
  return( spec->alpha[jj] );
}

// Find the finite field value for a given exponent.
//------------------------------------------------------------------------------
UNT08 gfFindGF2_8(INT16 alpha, xccRSEncoderSpec *spec)
{
  if     (alpha< -1){
    XMC_ERROR_STDOUT("INVALID ALPHA! ALPHA <  -1. CHECK YOUR C CODE.");
    return(0);
  }
  else if(alpha>255){
    XMC_ERROR_STDOUT("INVALID ALPHA! ALPHA > 255. CHECK YOUR C CODE.");
    return(0);
  }
  else return(spec->gf[alpha+1]);
}

// Multiplying Galois Finite Fields:  Add exponents and modulo with GF size.
//------------------------------------------------------------------------------
UNT08 gmul2_8(UNT08 a, UNT08 b, xccRSEncoderSpec *spec)
{
  INT32 x;
  INT32 y;
  UNT08 z;
  if(a==0) {
    return(0);
  }
  if(b==0){
    return(0);
  }
  x=gfFindAlpha2_8(a,spec);
  y=gfFindAlpha2_8(b,spec);
  z = (x+y)%255;
  return(gfFindGF2_8(z,spec));
}
  

  //
  //      ---------------------------...-----------------------------[gate]
  //      |         |           |              |           |           ^
  //      v         v           v              v           v           |
  //c00->[*]  c01->[*]    c02->[*]    ...c30->[*]    c31->[*]          |
  //      |         |           |              |           |           |
  //      v         v           v              v           |           |
  //     p01----->[xor]->p02->[xor]->...p29->[xor]->p30->[xor]->p31->[xor]
  //                                                                   ^
  //                                                                   |
  //                                                                   d

// xccRSEndcode255_223
//------------------------------------------------------------------------------
VOID xccRSEndcode255_223( UNT08 d, xccRSEncoderSpec *spec)
{
  UNT08 gate;
  UNT08 temp[32];

  gate = spec->parity[31] ^ d;

  temp[31] = (gmul2_8(gate, spec->gf[249+1], spec));
  temp[30] = (gmul2_8(gate, spec->gf[ 59+1], spec));
  temp[29] = (gmul2_8(gate, spec->gf[ 66+1], spec));
  temp[28] = (gmul2_8(gate, spec->gf[  4+1], spec));
  temp[27] = (gmul2_8(gate, spec->gf[ 43+1], spec));
  temp[26] = (gmul2_8(gate, spec->gf[126+1], spec));
  temp[25] = (gmul2_8(gate, spec->gf[251+1], spec));
  temp[24] = (gmul2_8(gate, spec->gf[ 97+1], spec));
  temp[23] = (gmul2_8(gate, spec->gf[ 30+1], spec));
  temp[22] = (gmul2_8(gate, spec->gf[  3+1], spec));
  temp[21] = (gmul2_8(gate, spec->gf[213+1], spec));
  temp[20] = (gmul2_8(gate, spec->gf[ 50+1], spec));
  temp[19] = (gmul2_8(gate, spec->gf[ 66+1], spec));
  temp[18] = (gmul2_8(gate, spec->gf[170+1], spec));
  temp[17] = (gmul2_8(gate, spec->gf[  5+1], spec));
  temp[16] = (gmul2_8(gate, spec->gf[ 24+1], spec));
  temp[15] = (gmul2_8(gate, spec->gf[  5+1], spec));
  temp[14] = (gmul2_8(gate, spec->gf[170+1], spec));
  temp[13] = (gmul2_8(gate, spec->gf[ 66+1], spec));
  temp[12] = (gmul2_8(gate, spec->gf[ 50+1], spec));
  temp[11] = (gmul2_8(gate, spec->gf[213+1], spec));
  temp[10] = (gmul2_8(gate, spec->gf[  3+1], spec));
  temp[ 9] = (gmul2_8(gate, spec->gf[ 30+1], spec));
  temp[ 8] = (gmul2_8(gate, spec->gf[ 97+1], spec));
  temp[ 7] = (gmul2_8(gate, spec->gf[251+1], spec));
  temp[ 6] = (gmul2_8(gate, spec->gf[126+1], spec));
  temp[ 5] = (gmul2_8(gate, spec->gf[ 43+1], spec));
  temp[ 4] = (gmul2_8(gate, spec->gf[  4+1], spec));
  temp[ 3] = (gmul2_8(gate, spec->gf[ 66+1], spec));
  temp[ 2] = (gmul2_8(gate, spec->gf[ 59+1], spec));
  temp[ 1] = (gmul2_8(gate, spec->gf[249+1], spec));
  temp[ 0] = (gmul2_8(gate, spec->gf[  0+1], spec));

  spec->parity[31] = temp[31] ^ spec->parity[30];
  spec->parity[30] = temp[30] ^ spec->parity[29];
  spec->parity[29] = temp[29] ^ spec->parity[28];
  spec->parity[28] = temp[28] ^ spec->parity[27];
  spec->parity[27] = temp[27] ^ spec->parity[26];
  spec->parity[26] = temp[26] ^ spec->parity[25];
  spec->parity[25] = temp[25] ^ spec->parity[24];
  spec->parity[24] = temp[24] ^ spec->parity[23];
  spec->parity[23] = temp[23] ^ spec->parity[22];
  spec->parity[22] = temp[22] ^ spec->parity[21];
  spec->parity[21] = temp[21] ^ spec->parity[20];
  spec->parity[20] = temp[20] ^ spec->parity[19];
  spec->parity[19] = temp[19] ^ spec->parity[18];
  spec->parity[18] = temp[18] ^ spec->parity[17];
  spec->parity[17] = temp[17] ^ spec->parity[16];
  spec->parity[16] = temp[16] ^ spec->parity[15];
  spec->parity[15] = temp[15] ^ spec->parity[14];
  spec->parity[14] = temp[14] ^ spec->parity[13];
  spec->parity[13] = temp[13] ^ spec->parity[12];
  spec->parity[12] = temp[12] ^ spec->parity[11];
  spec->parity[11] = temp[11] ^ spec->parity[10];
  spec->parity[10] = temp[10] ^ spec->parity[ 9];
  spec->parity[ 9] = temp[ 9] ^ spec->parity[ 8];
  spec->parity[ 8] = temp[ 8] ^ spec->parity[ 7];
  spec->parity[ 7] = temp[ 7] ^ spec->parity[ 6];
  spec->parity[ 6] = temp[ 6] ^ spec->parity[ 5];
  spec->parity[ 5] = temp[ 5] ^ spec->parity[ 4];
  spec->parity[ 4] = temp[ 4] ^ spec->parity[ 3];
  spec->parity[ 3] = temp[ 3] ^ spec->parity[ 2];
  spec->parity[ 2] = temp[ 2] ^ spec->parity[ 1];
  spec->parity[ 1] = temp[ 1] ^ spec->parity[ 0];
  spec->parity[ 0] = temp[ 0];

}


/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
