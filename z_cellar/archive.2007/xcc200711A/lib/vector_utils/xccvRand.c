/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccvRand.c
// Desc: This file contains the code for a uniform random number generator function.
// Hist: When       Who  What
//       07/06/2004 ptb  Initial Code.
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
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
// Rout: xccvRandFLTXX
// Desc: This routine performs a uniform noise generation for floating point values.
//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa = a;
PERL_PREPROCESS  register UNT32 k;
PERL_PREPROCESS  register FLT64 u1;
PERL_PREPROCESS  for(k=0; k<n; k++)
PERL_PREPROCESS  {                
PERL_PREPROCESS    *seed = ((*seed)*A1UNT64) + B1UNT64;           // Update the seed.
PERL_PREPROCESS    u1    = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; // Range to 0.0-1.0.
PERL_PREPROCESS    u1    = u1*2-1;                                // Range to +/-1.0.
PERL_PREPROCESS    u1    = u1*amp;                                // Multiply by amplitude.
PERL_PREPROCESS    *pa    = (XXXXX)(u1);                          // Cast.
PERL_PREPROCESS    pa += i;
PERL_PREPROCESS  }
#endif

VOID xccvRandFLT32(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32          START.
  FLT32 *pa = a;
  register UNT32 k;
  register FLT64 u1;
  for(k=0; k<n; k++)
  {                
    *seed = ((*seed)*A1UNT64) + B1UNT64;           // Update the seed.
    u1    = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; // Range to 0.0-1.0.
    u1    = u1*2-1;                                // Range to +/-1.0.
    u1    = u1*amp;                                // Multiply by amplitude.
    *pa    = (FLT32)(u1);                          // Cast.
    pa += i;
  }
//------------------------------- COMMON-CODE FLT32           STOP.
}

VOID xccvRandFLT64(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64          START.
  FLT64 *pa = a;
  register UNT32 k;
  register FLT64 u1;
  for(k=0; k<n; k++)
  {                
    *seed = ((*seed)*A1UNT64) + B1UNT64;           // Update the seed.
    u1    = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; // Range to 0.0-1.0.
    u1    = u1*2-1;                                // Range to +/-1.0.
    u1    = u1*amp;                                // Multiply by amplitude.
    *pa    = (FLT64)(u1);                          // Cast.
    pa += i;
  }
//------------------------------- COMMON-CODE FLT64           STOP.
}

VOID xccvRandFLT96(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96          START.
  FLT96 *pa = a;
  register UNT32 k;
  register FLT64 u1;
  for(k=0; k<n; k++)
  {                
    *seed = ((*seed)*A1UNT64) + B1UNT64;           // Update the seed.
    u1    = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; // Range to 0.0-1.0.
    u1    = u1*2-1;                                // Range to +/-1.0.
    u1    = u1*amp;                                // Multiply by amplitude.
    *pa    = (FLT96)(u1);                          // Cast.
    pa += i;
  }
//------------------------------- COMMON-CODE FLT96           STOP.
}

//------------------------------------------------------------------------------
// Rout: xccvRandINTXX
// Desc: This routine performs a uniform noise generation for integer values.
//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa = a;
PERL_PREPROCESS  register UNT32 k;
PERL_PREPROCESS  register FLT64 u1;
PERL_PREPROCESS  for(k=0; k<n; k++)
PERL_PREPROCESS  {                
PERL_PREPROCESS    *seed = ((*seed)*A1UNT64) + B1UNT64;           // Update the seed.
PERL_PREPROCESS    u1    = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; // Range to 0.0-1.0.
PERL_PREPROCESS    u1    = u1*2-1;                                // Range to +/-1.0.
PERL_PREPROCESS    u1    = u1*amp;                                // Multiply by amplitude.
PERL_PREPROCESS    if(u1>0) u1+=0.5;                              // Round properly so that > 0.5 is 1.0.
PERL_PREPROCESS    else     u1-=0.5;                              // Round properly so that < 0.5 is 0.0.
PERL_PREPROCESS    *pa    = (XXXXX)(u1);                          // Cast.
PERL_PREPROCESS    pa += i;
PERL_PREPROCESS  }
#endif

VOID xccvRandINT08(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE INT08          START.
  INT08 *pa = a;
  register UNT32 k;
  register FLT64 u1;
  for(k=0; k<n; k++)
  {                
    *seed = ((*seed)*A1UNT64) + B1UNT64;           // Update the seed.
    u1    = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; // Range to 0.0-1.0.
    u1    = u1*2-1;                                // Range to +/-1.0.
    u1    = u1*amp;                                // Multiply by amplitude.
    if(u1>0) u1+=0.5;                              // Round properly so that > 0.5 is 1.0.
    else     u1-=0.5;                              // Round properly so that < 0.5 is 0.0.
    *pa    = (INT08)(u1);                          // Cast.
    pa += i;
  }
//------------------------------- COMMON-CODE INT08           STOP.
}

VOID xccvRandINT16(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE INT16          START.
  INT16 *pa = a;
  register UNT32 k;
  register FLT64 u1;
  for(k=0; k<n; k++)
  {                
    *seed = ((*seed)*A1UNT64) + B1UNT64;           // Update the seed.
    u1    = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; // Range to 0.0-1.0.
    u1    = u1*2-1;                                // Range to +/-1.0.
    u1    = u1*amp;                                // Multiply by amplitude.
    if(u1>0) u1+=0.5;                              // Round properly so that > 0.5 is 1.0.
    else     u1-=0.5;                              // Round properly so that < 0.5 is 0.0.
    *pa    = (INT16)(u1);                          // Cast.
    pa += i;
  }
//------------------------------- COMMON-CODE INT16           STOP.
}

VOID xccvRandINT32(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE INT32          START.
  INT32 *pa = a;
  register UNT32 k;
  register FLT64 u1;
  for(k=0; k<n; k++)
  {                
    *seed = ((*seed)*A1UNT64) + B1UNT64;           // Update the seed.
    u1    = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; // Range to 0.0-1.0.
    u1    = u1*2-1;                                // Range to +/-1.0.
    u1    = u1*amp;                                // Multiply by amplitude.
    if(u1>0) u1+=0.5;                              // Round properly so that > 0.5 is 1.0.
    else     u1-=0.5;                              // Round properly so that < 0.5 is 0.0.
    *pa    = (INT32)(u1);                          // Cast.
    pa += i;
  }
//------------------------------- COMMON-CODE INT32           STOP.
}

VOID xccvRandINT64(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE INT64          START.
  INT64 *pa = a;
  register UNT32 k;
  register FLT64 u1;
  for(k=0; k<n; k++)
  {                
    *seed = ((*seed)*A1UNT64) + B1UNT64;           // Update the seed.
    u1    = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; // Range to 0.0-1.0.
    u1    = u1*2-1;                                // Range to +/-1.0.
    u1    = u1*amp;                                // Multiply by amplitude.
    if(u1>0) u1+=0.5;                              // Round properly so that > 0.5 is 1.0.
    else     u1-=0.5;                              // Round properly so that < 0.5 is 0.0.
    *pa    = (INT64)(u1);                          // Cast.
    pa += i;
  }
//------------------------------- COMMON-CODE INT64           STOP.
}

//------------------------------------------------------------------------------
// Rout: xccvRandUNTXX
// Desc: This routine performs a uniform noise generation for unsigned integer values.
//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa = a;
PERL_PREPROCESS  register UNT32 k;
PERL_PREPROCESS  register FLT64 u1;
PERL_PREPROCESS  for(k=0; k<n; k++)
PERL_PREPROCESS  {                
PERL_PREPROCESS    *seed = ((*seed)*A1UNT64) + B1UNT64;           // Update the seed.
PERL_PREPROCESS    u1    = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; // Range to 0.0-1.0.
PERL_PREPROCESS    u1    = u1*amp;                                // Multiply by amplitude.
PERL_PREPROCESS    if(u1>0) u1+=0.5;                              // Round properly so that > 0.5 is 1.0.
PERL_PREPROCESS    else     u1-=0.5;                              // Round properly so that < 0.5 is 0.0.
PERL_PREPROCESS    *pa    = (XXXXX)(u1);                          // Cast.
PERL_PREPROCESS    pa += i;
PERL_PREPROCESS  }
#endif


VOID xccvRandUNT08(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE UNT08          START.
  UNT08 *pa = a;
  register UNT32 k;
  register FLT64 u1;
  for(k=0; k<n; k++)
  {                
    *seed = ((*seed)*A1UNT64) + B1UNT64;           // Update the seed.
    u1    = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; // Range to 0.0-1.0.
    u1    = u1*amp;                                // Multiply by amplitude.
    if(u1>0) u1+=0.5;                              // Round properly so that > 0.5 is 1.0.
    else     u1-=0.5;                              // Round properly so that < 0.5 is 0.0.
    *pa    = (UNT08)(u1);                          // Cast.
    pa += i;
  }
//------------------------------- COMMON-CODE UNT08           STOP.
}

VOID xccvRandUNT16(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE UNT16          START.
  UNT16 *pa = a;
  register UNT32 k;
  register FLT64 u1;
  for(k=0; k<n; k++)
  {                
    *seed = ((*seed)*A1UNT64) + B1UNT64;           // Update the seed.
    u1    = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; // Range to 0.0-1.0.
    u1    = u1*amp;                                // Multiply by amplitude.
    if(u1>0) u1+=0.5;                              // Round properly so that > 0.5 is 1.0.
    else     u1-=0.5;                              // Round properly so that < 0.5 is 0.0.
    *pa    = (UNT16)(u1);                          // Cast.
    pa += i;
  }
//------------------------------- COMMON-CODE UNT16           STOP.
}

VOID xccvRandUNT32(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE UNT32          START.
  UNT32 *pa = a;
  register UNT32 k;
  register FLT64 u1;
  for(k=0; k<n; k++)
  {                
    *seed = ((*seed)*A1UNT64) + B1UNT64;           // Update the seed.
    u1    = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; // Range to 0.0-1.0.
    u1    = u1*amp;                                // Multiply by amplitude.
    if(u1>0) u1+=0.5;                              // Round properly so that > 0.5 is 1.0.
    else     u1-=0.5;                              // Round properly so that < 0.5 is 0.0.
    *pa    = (UNT32)(u1);                          // Cast.
    pa += i;
  }
//------------------------------- COMMON-CODE UNT32           STOP.
}

VOID xccvRandUNT64(UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE UNT64          START.
  UNT64 *pa = a;
  register UNT32 k;
  register FLT64 u1;
  for(k=0; k<n; k++)
  {                
    *seed = ((*seed)*A1UNT64) + B1UNT64;           // Update the seed.
    u1    = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; // Range to 0.0-1.0.
    u1    = u1*amp;                                // Multiply by amplitude.
    if(u1>0) u1+=0.5;                              // Round properly so that > 0.5 is 1.0.
    else     u1-=0.5;                              // Round properly so that < 0.5 is 0.0.
    *pa    = (UNT64)(u1);                          // Cast.
    pa += i;
  }
//------------------------------- COMMON-CODE UNT64           STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
