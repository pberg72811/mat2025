/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccMAReturnPN2.c
// Desc: This file contains the code for the xccMAReturnPN2 routine.
// Hist: When       Who  What
//       05/12/2003 ptb  Initial Code.
//       03/08/2004 ptb  There are cases were we want the Q channel to be zeros.
//                       Added a flag that triggers on 07777 seed in Reg C.
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

CFLT32 *xccMAReturnPN( UNT16 shiftRegisterA, UNT16 shiftRegisterC )
{
  CFLT32 *pnCode;
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

// Set flag to zero imaginary if 07777 code passed in.
//------------------------------------------------------------------------------
  if(shiftRegisterC==07777)
  {
    doNotZeroOutFlag    = FALSE;
  }
  else doNotZeroOutFlag = TRUE;

// Allocate memory for PN code array.
//------------------------------------------------------------------------------
//  pnCode = (xccArrayFLT32_t *) malloc(sizeof(xccArrayFLT32_t));

  pnCode = xccMallocCFLT32_Align032(MA_PN_LENGTH);

// Create an array to hold the PN code.
//------------------------------------------------------------------------------
//  pnCode = xccArrayInitFLT32(MA_PN_LENGTH,"pnCode",CPLX);

  for (ii=0; ii<MA_PN_LENGTH; ii++)
  {
// Get the LSB of each shift register (A,B,C).
//------------------------------------------------------------------------------
    shiftRegisterAResult = shiftRegisterA & 0x01;
    shiftRegisterBResult = shiftRegisterB & 0x01;
    shiftRegisterCResult = shiftRegisterC & 0x01;

// Calculate the real and imaginary PN chip based on shift registers (A,B,C) LSB.
//------------------------------------------------------------------------------
    pnCode[ii].r = (shiftRegisterAResult + shiftRegisterBResult)%2;
    pnCode[ii].i = (shiftRegisterCResult + shiftRegisterBResult)%2*doNotZeroOutFlag;
  
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

  return(pnCode);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
