/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccMatrixAdd.c
// Desc: This file contains the code for the xccMatrixAdd routine.
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
PERL_PREPROCESS  // Check for mismatched number of dimensions.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
PERL_PREPROCESS  {
PERL_PREPROCESS      XMC_ERROR_STDOUT("MATRIX NUMBER OF DIMENSION ERROR.");
PERL_PREPROCESS      return;
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Check for mismatched real and complex matricies.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
PERL_PREPROCESS  {
PERL_PREPROCESS      XMC_ERROR_STDOUT("MATRIX COMPLEX/REAL MISMATCH.");
PERL_PREPROCESS      return;
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Check for mismatched dimension lengths.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(ii = 0; ii < MA->ndim; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
PERL_PREPROCESS    {
PERL_PREPROCESS      XMC_ERROR_STDOUT("MATRIX DIMENSION ERROR.");
PERL_PREPROCESS      return;
PERL_PREPROCESS    }
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Add the matricies.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(ii = 0; ii < MA->total; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Add the complex part if present.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if( MA->cplx == TRUE )
PERL_PREPROCESS  for(ii = 0; ii < MA->total; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  return;

#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID xccMatrixAddINT08(xccMatrixINT08_t *MA, xccMatrixINT08_t *MB, xccMatrixINT08_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      XMC_ERROR_STDOUT("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      XMC_ERROR_STDOUT("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      XMC_ERROR_STDOUT("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID xccMatrixAddINT16(xccMatrixINT16_t *MA, xccMatrixINT16_t *MB, xccMatrixINT16_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      XMC_ERROR_STDOUT("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      XMC_ERROR_STDOUT("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      XMC_ERROR_STDOUT("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID xccMatrixAddINT32(xccMatrixINT32_t *MA, xccMatrixINT32_t *MB, xccMatrixINT32_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      XMC_ERROR_STDOUT("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      XMC_ERROR_STDOUT("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      XMC_ERROR_STDOUT("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID xccMatrixAddINT64(xccMatrixINT64_t *MA, xccMatrixINT64_t *MB, xccMatrixINT64_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      XMC_ERROR_STDOUT("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      XMC_ERROR_STDOUT("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      XMC_ERROR_STDOUT("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID xccMatrixAddUNT08(xccMatrixUNT08_t *MA, xccMatrixUNT08_t *MB, xccMatrixUNT08_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      XMC_ERROR_STDOUT("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      XMC_ERROR_STDOUT("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      XMC_ERROR_STDOUT("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID xccMatrixAddUNT16(xccMatrixUNT16_t *MA, xccMatrixUNT16_t *MB, xccMatrixUNT16_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      XMC_ERROR_STDOUT("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      XMC_ERROR_STDOUT("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      XMC_ERROR_STDOUT("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID xccMatrixAddUNT32(xccMatrixUNT32_t *MA, xccMatrixUNT32_t *MB, xccMatrixUNT32_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      XMC_ERROR_STDOUT("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      XMC_ERROR_STDOUT("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      XMC_ERROR_STDOUT("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID xccMatrixAddUNT64(xccMatrixUNT64_t *MA, xccMatrixUNT64_t *MB, xccMatrixUNT64_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      XMC_ERROR_STDOUT("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      XMC_ERROR_STDOUT("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      XMC_ERROR_STDOUT("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID xccMatrixAddFLT32(xccMatrixFLT32_t *MA, xccMatrixFLT32_t *MB, xccMatrixFLT32_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      XMC_ERROR_STDOUT("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      XMC_ERROR_STDOUT("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      XMC_ERROR_STDOUT("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID xccMatrixAddFLT64(xccMatrixFLT64_t *MA, xccMatrixFLT64_t *MB, xccMatrixFLT64_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      XMC_ERROR_STDOUT("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      XMC_ERROR_STDOUT("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      XMC_ERROR_STDOUT("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID xccMatrixAddFLT96(xccMatrixFLT96_t *MA, xccMatrixFLT96_t *MB, xccMatrixFLT96_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      XMC_ERROR_STDOUT("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      XMC_ERROR_STDOUT("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      XMC_ERROR_STDOUT("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
