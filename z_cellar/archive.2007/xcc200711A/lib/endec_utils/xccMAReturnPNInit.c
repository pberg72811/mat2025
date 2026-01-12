/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccMAReturnPNInit.c
// Desc: This file contains the code for the xccMAReturnPNInit routine.
// Hist: When       Who  What
//       05/12/2003 ptb  Initial Code.
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
/*      _ _ _ _ _ _ _ _ _ _ _                                                 */
/*   -->|_|_|_|_|_|_|_|_|_|_|_|--\                  Register A                */
/*  |      |                 |    |                                           */
/*   <-----\------ + --------/    |                                           */
/*                                |                                           */
/*                                +---> I (real)                              */
/*       _ _ _ _ _ _ _ _ _ _ _    |                                           */
/*   -->|_|_|_|_|_|_|_|_|_|_|_|---|                 Register B                */
/*  |      |     |     |     |    |                                           */
/*   <-----\--+--|--+--|--+--/    +---> Q (imag)                              */
/*                                |                                           */
/*       _ _ _ _ _ _ _ _ _ _ _    |                                           */
/*   -->|_|_|_|_|_|_|_|_|_|_|_|--/                  Register C                */
/*  |      |                 |                                                */
/*   <-----\------ + --------/                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

xccPNSpec *xccMAReturnPNInit( UNT16 shiftRegisterA, UNT16 shiftRegisterC )
{
  UNT16 shiftRegisterB=0x1;
  UNT16 shiftRegisterATap1Mask = 0x001;
  UNT16 shiftRegisterATap2Mask = 0x200;
  UNT16 shiftRegisterBTap1Mask = 0x001;
  UNT16 shiftRegisterBTap2Mask = 0x008;
  UNT16 shiftRegisterBTap3Mask = 0x040;
  UNT16 shiftRegisterBTap4Mask = 0x200;
  UNT16 shiftRegisterCTap1Mask = 0x001;
  UNT16 shiftRegisterCTap2Mask = 0x200;
  UNT16 shiftRegisterAResult;
  UNT16 shiftRegisterBResult;
  UNT16 shiftRegisterCResult;
  UNT16 ii;
  UNT16 doNotZeroOutFlag;
  xccPNSpec *spec;

// Set flag to zero imaginary if 07777 code passed in.
//------------------------------------------------------------------------------
  if(shiftRegisterC==07777)
  {
    doNotZeroOutFlag    = FALSE;
  }
  else doNotZeroOutFlag = TRUE;

// Allocate memory for PN code array and initialize.
//------------------------------------------------------------------------------
  spec         = (xccPNSpec *) malloc(sizeof(xccPNSpec));
  spec->length = MA_PN_LENGTH;
  spec->seedi  = shiftRegisterA;
  spec->seedq  = shiftRegisterC;

// Loop for each chip.
//------------------------------------------------------------------------------
  for (ii=0; ii<MA_PN_LENGTH; ii++)
  {
// Get the LSB of each shift register (A,B,C).
//------------------------------------------------------------------------------
    shiftRegisterAResult = shiftRegisterA & 0x01;
    shiftRegisterBResult = shiftRegisterB & 0x01;
    shiftRegisterCResult = shiftRegisterC & 0x01;

// Calculate the real and imaginary PN chip based on shift registers (A,B,C) LSB.
//------------------------------------------------------------------------------
    spec->pr[ii] = (shiftRegisterAResult + shiftRegisterBResult)%2;
    spec->pi[ii] = (shiftRegisterCResult + shiftRegisterBResult)%2*doNotZeroOutFlag;
  
// Calculate the next feed back bit.
//------------------------------------------------------------------------------
    shiftRegisterAResult = (
			    ((shiftRegisterA&shiftRegisterATap1Mask)>0) + 
			    ((shiftRegisterA&shiftRegisterATap2Mask)>0)  )%2;

    shiftRegisterBResult = (
			    ((shiftRegisterB&shiftRegisterBTap1Mask)>0) + 
			    ((shiftRegisterB&shiftRegisterBTap2Mask)>0) +
			    ((shiftRegisterB&shiftRegisterBTap3Mask)>0) +
			    ((shiftRegisterB&shiftRegisterBTap4Mask)>0)  )%2;

    shiftRegisterCResult = (
			    ((shiftRegisterC&shiftRegisterCTap1Mask)>0) + 
			    ((shiftRegisterC&shiftRegisterCTap2Mask)>0)  )%2;

// Shift the registers.
//------------------------------------------------------------------------------
    shiftRegisterA = shiftRegisterA >> 1;
    shiftRegisterB = shiftRegisterB >> 1;
    shiftRegisterC = shiftRegisterC >> 1;

// Set the MSB of the shift registers based on the feed back bit.
//------------------------------------------------------------------------------
    if( shiftRegisterAResult == 0x01 ) shiftRegisterA |= 0x400;
    if( shiftRegisterBResult == 0x01 ) shiftRegisterB |= 0x400;
    if( shiftRegisterCResult == 0x01 ) shiftRegisterC |= 0x400;
  }

  return(spec);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
