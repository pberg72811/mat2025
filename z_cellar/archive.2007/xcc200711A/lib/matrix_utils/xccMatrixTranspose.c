/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccMatrixTranspose.c
// Desc: This file contains the code for the xccMatrixTranspose routine.
// Hist: When       Who  What
//       05/30/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "xccMatrixUtils.h"  

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
PERL_PREPROCESS      xcc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
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
VOID xccMatrixTransposeINT08(xccMatrixINT08_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim > 2) )
  {
      xcc_ERROR_MESSAGE("MATRIX TRANSPOSE ONLY DEFINED FOR 1 or 2 DIMENSIONS.");
      return;
  }

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      xcc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
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

VOID xccMatrixTransposeINT16(xccMatrixINT16_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      xcc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
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

VOID xccMatrixTransposeINT32(xccMatrixINT32_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      xcc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
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

VOID xccMatrixTransposeINT64(xccMatrixINT64_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      xcc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
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

VOID xccMatrixTransposeUNT08(xccMatrixUNT08_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      xcc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
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

VOID xccMatrixTransposeUNT16(xccMatrixUNT16_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      xcc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
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

VOID xccMatrixTransposeUNT32(xccMatrixUNT32_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      xcc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
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

VOID xccMatrixTransposeUNT64(xccMatrixUNT64_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      xcc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
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

VOID xccMatrixTransposeFLT32(xccMatrixFLT32_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      xcc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
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

VOID xccMatrixTransposeFLT64(xccMatrixFLT64_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      xcc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
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

VOID xccMatrixTransposeFLT96(xccMatrixFLT96_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      xcc_ERROR_MESSAGE("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
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
