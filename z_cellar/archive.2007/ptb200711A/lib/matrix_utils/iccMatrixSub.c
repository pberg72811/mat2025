/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccMatrixSub.c
// Desc: This file contains the code for the iccMatrixSub routine.
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
PERL_PREPROCESS  // Sub the matricies.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(ii = 0; ii < MA->total; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    MC->pr[ii] = MA->pr[ii]-MB->pr[ii];
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Sub the complex part if present.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if( MA->cplx == TRUE )
PERL_PREPROCESS  for(ii = 0; ii < MA->total; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    MC->pi[ii] = MA->pi[ii]-MB->pi[ii];
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  return;

#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccMatrixSubINT08(iccMatrixINT08_t *MA, iccMatrixINT08_t *MB, iccMatrixINT08_t *MC)
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

  // Sub the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]-MB->pr[ii];
  }

  // Sub the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]-MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixSubINT16(iccMatrixINT16_t *MA, iccMatrixINT16_t *MB, iccMatrixINT16_t *MC)
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

  // Sub the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]-MB->pr[ii];
  }

  // Sub the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]-MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixSubINT32(iccMatrixINT32_t *MA, iccMatrixINT32_t *MB, iccMatrixINT32_t *MC)
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

  // Sub the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]-MB->pr[ii];
  }

  // Sub the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]-MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixSubINT64(iccMatrixINT64_t *MA, iccMatrixINT64_t *MB, iccMatrixINT64_t *MC)
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

  // Sub the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]-MB->pr[ii];
  }

  // Sub the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]-MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixSubUNT08(iccMatrixUNT08_t *MA, iccMatrixUNT08_t *MB, iccMatrixUNT08_t *MC)
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

  // Sub the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]-MB->pr[ii];
  }

  // Sub the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]-MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixSubUNT16(iccMatrixUNT16_t *MA, iccMatrixUNT16_t *MB, iccMatrixUNT16_t *MC)
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

  // Sub the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]-MB->pr[ii];
  }

  // Sub the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]-MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixSubUNT32(iccMatrixUNT32_t *MA, iccMatrixUNT32_t *MB, iccMatrixUNT32_t *MC)
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

  // Sub the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]-MB->pr[ii];
  }

  // Sub the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]-MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixSubUNT64(iccMatrixUNT64_t *MA, iccMatrixUNT64_t *MB, iccMatrixUNT64_t *MC)
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

  // Sub the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]-MB->pr[ii];
  }

  // Sub the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]-MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixSubFLT32(iccMatrixFLT32_t *MA, iccMatrixFLT32_t *MB, iccMatrixFLT32_t *MC)
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

  // Sub the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]-MB->pr[ii];
  }

  // Sub the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]-MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixSubFLT64(iccMatrixFLT64_t *MA, iccMatrixFLT64_t *MB, iccMatrixFLT64_t *MC)
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

  // Sub the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]-MB->pr[ii];
  }

  // Sub the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]-MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixSubFLT96(iccMatrixFLT96_t *MA, iccMatrixFLT96_t *MB, iccMatrixFLT96_t *MC)
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

  // Sub the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]-MB->pr[ii];
  }

  // Sub the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]-MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
