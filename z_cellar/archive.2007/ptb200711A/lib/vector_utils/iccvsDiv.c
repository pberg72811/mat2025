/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvsDiv.c
// Desc: This file contains the code for the vectorUtils routine iccvsDiv.
// Hist: When       Who  What
//       04/27/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "vector_utils.h" 
 
/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define COMMON_CODE_FLT UNT32 l;  \
                       pa = a;    \
                       pc = c;    \
                       b = 1.0/b; \
                       for(l=0; l<n; l++){*pc = (*pa) * b; pa+=i; pc+=k;}

#define COMMON_CODE UNT32 l; \
                    pa = a;  \
                    pc = c;  \
                    for(l=0; l<n; l++){*pc = (*pa) / b; pa+=i; pc+=k;}

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccvsDivFLT32( FLT32 *a, INT32 i, FLT32 b, FLT32 *c, INT32 k, UNT32 n)
{
  FLT32   *pa;
  FLT32   *pc;
  COMMON_CODE_FLT
}

VOID iccvsDivFLT64( FLT64 *a, INT32 i, FLT64 b, FLT64 *c, INT32 k, UNT32 n)
{
  FLT64 *pa;
  FLT64 *pc;
  COMMON_CODE_FLT
}

VOID iccvsDivFLT96( FLT96 *a, INT32 i, FLT96 b, FLT96 *c, INT32 k,UNT32 n)
{
  FLT96 *pa;
  FLT96 *pc;
  COMMON_CODE_FLT
}

VOID iccvsDivINT08( INT08 *a, INT32 i, INT08 b, INT08 *c, INT32 k, UNT32 n)
{
  INT08 *pa;
  INT08 *pc;
  COMMON_CODE
}

VOID iccvsDivINT16( INT16 *a, INT32 i, INT16 b, INT16 *c, INT32 k, UNT32 n)
{
  INT16 *pa;
  INT16 *pc;
  COMMON_CODE
}

VOID iccvsDivINT32( INT32 *a, INT32 i, INT32 b, INT32 *c, INT32 k, UNT32 n)
{
  INT32 *pa;
  INT32 *pc;
  COMMON_CODE
}

VOID iccvsDivINT64( INT64 *a, INT32 i, INT64 b, INT64 *c, INT32 k, UNT32 n)
{
  INT64 *pa;
  INT64 *pc;
  COMMON_CODE
}

VOID iccvsDivUNT08( UNT08 *a, INT32 i, UNT08 b, UNT08 *c, INT32 k, UNT32 n)
{
  UNT08 *pa;
  UNT08 *pc;
  COMMON_CODE
}

VOID iccvsDivUNT16( UNT16 *a, INT32 i, UNT16 b, UNT16 *c, INT32 k, UNT32 n)
{
  UNT16 *pa;
  UNT16 *pc;
  COMMON_CODE
}

VOID iccvsDivUNT32( UNT32 *a, INT32 i, UNT32 b, UNT32 *c, INT32 k, UNT32 n)
{
  UNT32 *pa;
  UNT32 *pc;
  COMMON_CODE
}

VOID iccvsDivUNT64( UNT64 *a, INT32 i, UNT64 b, UNT64 *c, INT32 k, UNT32 n)
{
  UNT64 *pa;
  UNT64 *pc;
  COMMON_CODE
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
