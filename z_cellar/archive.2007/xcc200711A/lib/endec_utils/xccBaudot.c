/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccBaudot.c
// Desc: This file contains the code for the xccBaudot routine.  The baudot code
//       was used extensively in telegraph systems.  It is a five bit code 
//       invented by Emile Baudot (French) in 1870.  Using five bits allowed 32
//       different characters.  To accomodate all the letters of the alphabet and
//       numerals, two of the 32 combinations were used to select alternate 
//       character sets.  Each character is preceeded by a start bit, and followed
//       by a stop bit.  It is an asychronous code.
// Hist: When       Who  What
//       02/21/2005 ptb  Initial Code.
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
CHR08 xccBaudot(INT32 code)
{
  static INT32 figShift=0;

  if      ((code ==  0) && (figShift==0)) return ('_');
  else if ((code ==  1) && (figShift==0)) return ('T');
  else if ((code ==  2) && (figShift==0)) return ('\n');
  else if ((code ==  3) && (figShift==0)) return ('O');
  else if ((code ==  4) && (figShift==0)) return (' ');
  else if ((code ==  5) && (figShift==0)) return ('H');
  else if ((code ==  6) && (figShift==0)) return ('N');
  else if ((code ==  7) && (figShift==0)) return ('M');
  else if ((code ==  8) && (figShift==0)) return ('\n');
  else if ((code ==  9) && (figShift==0)) return ('L');
  else if ((code == 10) && (figShift==0)) return ('R');
  else if ((code == 11) && (figShift==0)) return ('G');
  else if ((code == 12) && (figShift==0)) return ('I');
  else if ((code == 13) && (figShift==0)) return ('P');
  else if ((code == 14) && (figShift==0)) return ('C');
  else if ((code == 15) && (figShift==0)) return ('V');
  else if ((code == 16) && (figShift==0)) return ('E');
  else if ((code == 17) && (figShift==0)) return ('Z');
  else if ((code == 18) && (figShift==0)) return ('D');
  else if ((code == 19) && (figShift==0)) return ('B');
  else if ((code == 20) && (figShift==0)) return ('S');
  else if ((code == 21) && (figShift==0)) return ('Y');
  else if ((code == 22) && (figShift==0)) return ('F');
  else if ((code == 23) && (figShift==0)) return ('X');
  else if ((code == 24) && (figShift==0)) return ('A');
  else if ((code == 25) && (figShift==0)) return ('W');
  else if ((code == 26) && (figShift==0)) return ('J');
  else if  (code == 27)    {figShift=1;   return ('\0');}
  else if ((code == 28) && (figShift==0)) return ('U');
  else if ((code == 29) && (figShift==0)) return ('Q');
  else if ((code == 30) && (figShift==0)) return ('K');
  else if  (code == 31)    {figShift=0;   return ('\0');}

  else if ((code ==  0) && (figShift==1)) return ('_');
  else if ((code ==  1) && (figShift==1)) return ('5');
  else if ((code ==  2) && (figShift==1)) return ('\n');
  else if ((code ==  3) && (figShift==1)) return ('9');
  else if ((code ==  4) && (figShift==1)) return (' ');
  else if ((code ==  5) && (figShift==1)) return ('\0');
  else if ((code ==  6) && (figShift==1)) return (',');
  else if ((code ==  7) && (figShift==1)) return ('.');
  else if ((code ==  8) && (figShift==1)) return ('\n');
  else if ((code ==  9) && (figShift==1)) return (')');
  else if ((code == 10) && (figShift==1)) return ('4');
  else if ((code == 11) && (figShift==1)) return ('&');
  else if ((code == 12) && (figShift==1)) return ('8');
  else if ((code == 13) && (figShift==1)) return ('0');
  else if ((code == 14) && (figShift==1)) return (':');
  else if ((code == 15) && (figShift==1)) return (';');
  else if ((code == 16) && (figShift==1)) return ('3');
  else if ((code == 17) && (figShift==1)) return ('"');
  else if ((code == 18) && (figShift==1)) return ('$');
  else if ((code == 19) && (figShift==1)) return ('?');
  else if ((code == 20) && (figShift==1)) return ('*');
  else if ((code == 21) && (figShift==1)) return ('6');
  else if ((code == 22) && (figShift==1)) return ('!');
  else if ((code == 23) && (figShift==1)) return ('/');
  else if ((code == 24) && (figShift==1)) return ('-');
  else if ((code == 25) && (figShift==1)) return ('2');
  else if ((code == 26) && (figShift==1)) return ('\'');
  else if ((code == 27) && (figShift==1)) return ('\0');
  else if ((code == 28) && (figShift==1)) return ('7');
  else if ((code == 29) && (figShift==1)) return ('1');
  else if ((code == 30) && (figShift==1)) return ('(');
  else if ((code == 31) && (figShift==1)) return ('\0');
  else return ('\0');
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
