/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccMatrixConj.c
// Desc: This file contains the code for the xccMatrixConj routine.
// Hist: When       Who  What
//       05/30/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "matrix_utils.h"  

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
PERL_PREPROCESS      XMC_ERROR_STDOUT("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
PERL_PREPROCESS      return;
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Conj the matricies.
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
VOID xccMatrixConjINT08(xccMatrixINT08_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      XMC_ERROR_STDOUT("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Conj the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID xccMatrixConjINT16(xccMatrixINT16_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      XMC_ERROR_STDOUT("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Conj the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID xccMatrixConjINT32(xccMatrixINT32_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      XMC_ERROR_STDOUT("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Conj the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID xccMatrixConjINT64(xccMatrixINT64_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      XMC_ERROR_STDOUT("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Conj the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID xccMatrixConjUNT08(xccMatrixUNT08_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      XMC_ERROR_STDOUT("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Conj the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID xccMatrixConjUNT16(xccMatrixUNT16_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      XMC_ERROR_STDOUT("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Conj the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID xccMatrixConjUNT32(xccMatrixUNT32_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      XMC_ERROR_STDOUT("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Conj the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID xccMatrixConjUNT64(xccMatrixUNT64_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      XMC_ERROR_STDOUT("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Conj the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID xccMatrixConjFLT32(xccMatrixFLT32_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      XMC_ERROR_STDOUT("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Conj the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID xccMatrixConjFLT64(xccMatrixFLT64_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      XMC_ERROR_STDOUT("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Conj the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MA->pi[ii] = -MA->pi[ii];
  }
//COMMON-CODE     STOP.
}

VOID xccMatrixConjFLT96(xccMatrixFLT96_t *MA)
{
//COMMON-CODE    START.
  UNT32 ii;

  // Check for real and complex.
  //----------------------------------------------------------------------------
  if( (MA->cplx != CPLX) )
  {
      XMC_ERROR_STDOUT("MATRIX NEEDS TO BE COMPLEX IN ORDER TO CONJUGATE IT.");
      return;
  }

  // Conj the matricies.
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
