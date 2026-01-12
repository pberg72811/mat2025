/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccMatrixTerm.c
// Desc: This file contains the code for the xccMatrixTerm routine.
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
VOID xccMatrixTermINT08(xccMatrixINT08_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID xccMatrixTermINT16(xccMatrixINT16_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID xccMatrixTermINT32(xccMatrixINT32_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID xccMatrixTermINT64(xccMatrixINT64_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID xccMatrixTermUNT08(xccMatrixUNT08_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID xccMatrixTermUNT16(xccMatrixUNT16_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID xccMatrixTermUNT32(xccMatrixUNT32_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID xccMatrixTermUNT64(xccMatrixUNT64_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID xccMatrixTermFLT32(xccMatrixFLT32_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID xccMatrixTermFLT64(xccMatrixFLT64_t *p2Matrix)
{
//COMMON-CODE START.
  xmcFree(p2Matrix->pr);
  xmcFree(p2Matrix->pi);
  xmcFree(p2Matrix->dim);
  xmcFree(p2Matrix);
//COMMON-CODE  STOP.
}

VOID xccMatrixTermFLT96(xccMatrixFLT96_t *p2Matrix)
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
