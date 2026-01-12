/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccMatrixTerm.c
// Desc: This file contains the code for the iccMatrixTerm routine.
// Hist: When       Who  What
//       05/20/2003 ptb  Initial Code.
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
PERL_PREPROCESS  xmcFree(p2Matrix->pr);
PERL_PREPROCESS  xmcFree(p2Matrix->pi);
PERL_PREPROCESS  xmcFree(p2Matrix->dim);
PERL_PREPROCESS  xmcFree(p2Matrix);
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccMatrixTermINT08(iccMatrixINT08_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID iccMatrixTermINT16(iccMatrixINT16_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID iccMatrixTermINT32(iccMatrixINT32_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID iccMatrixTermINT64(iccMatrixINT64_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID iccMatrixTermUNT08(iccMatrixUNT08_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID iccMatrixTermUNT16(iccMatrixUNT16_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID iccMatrixTermUNT32(iccMatrixUNT32_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID iccMatrixTermUNT64(iccMatrixUNT64_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID iccMatrixTermFLT32(iccMatrixFLT32_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID iccMatrixTermFLT64(iccMatrixFLT64_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID iccMatrixTermFLT96(iccMatrixFLT96_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
