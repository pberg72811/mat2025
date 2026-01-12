/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccMatrixTranspose.c
// Desc: This file contains the code for the iccMatrixTranspose routine.
// Hist: When       Who  What
//       05/30/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "iccMatrixUtils.h"  

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS
PERL_PREPROCESS  // Check for real and complex.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if( (MA->cplx != CPLX) )
PERL_PREPROCESS  {
PERL_PREPROCESS      icc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
PERL_PREPROCESS      return;
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Transpose the matricies.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(ii = 0; ii < MA->total; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    MA->pi[ii] = -MA->pi[ii];
PERL_PREPROCESS  }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccMatrixTransposeINT08(iccMatrixINT08_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim > 2) )
  {
      icc_ERROR_MESSAGE("MATRIX TRANSPOSE ONLY DEFINED FOR 1 or 2 DIMENSIONS.");
      return;
  }

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      icc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Transpose the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->dim[0]; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID iccMatrixTransposeINT16(iccMatrixINT16_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      icc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Transpose the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID iccMatrixTransposeINT32(iccMatrixINT32_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      icc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Transpose the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID iccMatrixTransposeINT64(iccMatrixINT64_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      icc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Transpose the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID iccMatrixTransposeUNT08(iccMatrixUNT08_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      icc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Transpose the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID iccMatrixTransposeUNT16(iccMatrixUNT16_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      icc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Transpose the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID iccMatrixTransposeUNT32(iccMatrixUNT32_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      icc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Transpose the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID iccMatrixTransposeUNT64(iccMatrixUNT64_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      icc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Transpose the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID iccMatrixTransposeFLT32(iccMatrixFLT32_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      icc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Transpose the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID iccMatrixTransposeFLT64(iccMatrixFLT64_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      icc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Transpose the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID iccMatrixTransposeFLT96(iccMatrixFLT96_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      icc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Transpose the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
