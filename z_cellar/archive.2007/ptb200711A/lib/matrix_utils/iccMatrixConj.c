/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccMatrixConj.c
// Desc: This file contains the code for the iccMatrixConj routine.
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
VOID iccMatrixConjINT08(iccMatrixINT08_t *MA)
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

VOID iccMatrixConjINT16(iccMatrixINT16_t *MA)
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

VOID iccMatrixConjINT32(iccMatrixINT32_t *MA)
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

VOID iccMatrixConjINT64(iccMatrixINT64_t *MA)
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

VOID iccMatrixConjUNT08(iccMatrixUNT08_t *MA)
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

VOID iccMatrixConjUNT16(iccMatrixUNT16_t *MA)
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

VOID iccMatrixConjUNT32(iccMatrixUNT32_t *MA)
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

VOID iccMatrixConjUNT64(iccMatrixUNT64_t *MA)
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

VOID iccMatrixConjFLT32(iccMatrixFLT32_t *MA)
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

VOID iccMatrixConjFLT64(iccMatrixFLT64_t *MA)
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

VOID iccMatrixConjFLT96(iccMatrixFLT96_t *MA)
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
