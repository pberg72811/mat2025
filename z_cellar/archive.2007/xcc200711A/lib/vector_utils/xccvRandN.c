/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccvRandN.c
// Desc: This file contains the code for a random number generator function.
// Hist: When       Who  What
//       08/12/2002 ptb  Initial Code.
//       04/28/2004 ptb  Positive log problem that leads to a floating point NAN.
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
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa = a;
PERL_PREPROCESS  INT32 whogi;
PERL_PREPROCESS  register UNT32 k;
PERL_PREPROCESS  register FLT64 u1; 
PERL_PREPROCESS  register FLT64 u2; 
PERL_PREPROCESS
PERL_PREPROCESS  whogi = (n-n%2)/2;
PERL_PREPROCESS
PERL_PREPROCESS  // Calculate noise.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(k=0; k<whogi; k++)
PERL_PREPROCESS  {                
PERL_PREPROCESS    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
PERL_PREPROCESS    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
PERL_PREPROCESS
PERL_PREPROCESS    *pa = (XXXXX)(std*sqrt(-2.0*log(u1))*cos(2*PI*u2)); pa += i;
PERL_PREPROCESS    *pa = (XXXXX)(std*sqrt(-2.0*log(u1))*sin(2*PI*u2)); pa += i;
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Handle odd number of elements.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if((n%2)==1)
PERL_PREPROCESS  {
PERL_PREPROCESS    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
PERL_PREPROCESS    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
PERL_PREPROCESS    *pa = (XXXXX)(std*sqrt(-2.0*log(u1))*cos(2*PI*u2));  pa +=i;
PERL_PREPROCESS  }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
// Rout: xccvRandNFLTXX
// Desc: This routine performs a normalized noise generation using the Box-Muller
//       method for floating point values.
//------------------------------------------------------------------------------
VOID xccvRandNFLT32(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32            START.
  FLT32 *pa = a;
  INT32 whogi;
  register UNT32 k;
  register FLT64 u1; 
  register FLT64 u2; 

  whogi = (n-n%2)/2;

  // Calculate noise.
  //----------------------------------------------------------------------------
  for(k=0; k<whogi; k++)
  {                
    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;

    *pa = (FLT32)(std*sqrt(-2.0*log(u1))*cos(2*PI*u2)); pa += i;
    *pa = (FLT32)(std*sqrt(-2.0*log(u1))*sin(2*PI*u2)); pa += i;
  }

  // Handle odd number of elements.
  //----------------------------------------------------------------------------
  if((n%2)==1)
  {
    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
    *pa = (FLT32)(std*sqrt(-2.0*log(u1))*cos(2*PI*u2));  pa +=i;
  }
//------------------------------- COMMON-CODE FLT32             STOP.
}

VOID xccvRandNFLT64(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64            START.
  FLT64 *pa = a;
  INT32 whogi;
  register UNT32 k;
  register FLT64 u1; 
  register FLT64 u2; 

  whogi = (n-n%2)/2;

  // Calculate noise.
  //----------------------------------------------------------------------------
  for(k=0; k<whogi; k++)
  {                
    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;

    *pa = (FLT64)(std*sqrt(-2.0*log(u1))*cos(2*PI*u2)); pa += i;
    *pa = (FLT64)(std*sqrt(-2.0*log(u1))*sin(2*PI*u2)); pa += i;
  }

  // Handle odd number of elements.
  //----------------------------------------------------------------------------
  if((n%2)==1)
  {
    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
    *pa = (FLT64)(std*sqrt(-2.0*log(u1))*cos(2*PI*u2));  pa +=i;
  }
//------------------------------- COMMON-CODE FLT64             STOP.
}

VOID xccvRandNFLT96(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96            START.
  FLT96 *pa = a;
  INT32 whogi;
  register UNT32 k;
  register FLT64 u1; 
  register FLT64 u2; 

  whogi = (n-n%2)/2;

  // Calculate noise.
  //----------------------------------------------------------------------------
  for(k=0; k<whogi; k++)
  {                
    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;

    *pa = (FLT96)(std*sqrt(-2.0*log(u1))*cos(2*PI*u2)); pa += i;
    *pa = (FLT96)(std*sqrt(-2.0*log(u1))*sin(2*PI*u2)); pa += i;
  }

  // Handle odd number of elements.
  //----------------------------------------------------------------------------
  if((n%2)==1)
  {
    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
    *pa = (FLT96)(std*sqrt(-2.0*log(u1))*cos(2*PI*u2));  pa +=i;
  }
//------------------------------- COMMON-CODE FLT96             STOP.
}

//------------------------------------------------------------------------------
// Rout: xccvRandNINTXX
// Desc: This routine performs a normalized noise generation using the Box-Muller
//       method for integer values.
//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa = a;
PERL_PREPROCESS  FLT32 temp1;
PERL_PREPROCESS  FLT32 temp2;
PERL_PREPROCESS  INT32 whogi;
PERL_PREPROCESS  register UNT32 k;
PERL_PREPROCESS  register FLT64 u1; 
PERL_PREPROCESS  register FLT64 u2;
PERL_PREPROCESS
PERL_PREPROCESS  whogi = (n-n%2)/2;
PERL_PREPROCESS
PERL_PREPROCESS  // Calculate noise.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(k=0; k<whogi; k++)
PERL_PREPROCESS  {                
PERL_PREPROCESS    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
PERL_PREPROCESS    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
PERL_PREPROCESS
PERL_PREPROCESS    temp1 = std*sqrt(-2.0*log(u1))*cos(2*PI*u2);
PERL_PREPROCESS    temp2 = std*sqrt(-2.0*log(u1))*sin(2*PI*u2);
PERL_PREPROCESS
PERL_PREPROCESS    if(temp1>0) temp1+=0.5; // Round properly so that > 0.5 is 1.0.
PERL_PREPROCESS    else        temp1-=0.5; // Round properly so that < 0.5 is 0.0.
PERL_PREPROCESS    if(temp2>0) temp2+=0.5; // Round properly so that > 0.5 is 1.0.
PERL_PREPROCESS    else        temp2-=0.5; // Round properly so that < 0.5 is 0.0.
PERL_PREPROCESS
PERL_PREPROCESS    *pa = (XXXXX)(temp1); pa += i;
PERL_PREPROCESS    *pa = (XXXXX)(temp2); pa += i;
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Handle odd number of elements.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if((n%2)==1)
PERL_PREPROCESS  {
PERL_PREPROCESS    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
PERL_PREPROCESS    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
PERL_PREPROCESS
PERL_PREPROCESS    temp1 = std*sqrt(-2.0*log(u1))*cos(2*PI*u2);
PERL_PREPROCESS
PERL_PREPROCESS    if(temp1>0) temp1+=0.5; // Round properly so that > 0.5 is 1.0.
PERL_PREPROCESS    else        temp1-=0.5; // Round properly so that < 0.5 is 0.0.
PERL_PREPROCESS
PERL_PREPROCESS    *pa = (XXXXX)(temp1); pa += i;
PERL_PREPROCESS  }
#endif

VOID xccvRandNINT08(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE INT08            START.
  INT08 *pa = a;
  FLT32 temp1;
  FLT32 temp2;
  INT32 whogi;
  register UNT32 k;
  register FLT64 u1; 
  register FLT64 u2;

  whogi = (n-n%2)/2;

  // Calculate noise.
  //----------------------------------------------------------------------------
  for(k=0; k<whogi; k++)
  {                
    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;

    temp1 = std*sqrt(-2.0*log(u1))*cos(2*PI*u2);
    temp2 = std*sqrt(-2.0*log(u1))*sin(2*PI*u2);

    if(temp1>0) temp1+=0.5; // Round properly so that > 0.5 is 1.0.
    else        temp1-=0.5; // Round properly so that < 0.5 is 0.0.
    if(temp2>0) temp2+=0.5; // Round properly so that > 0.5 is 1.0.
    else        temp2-=0.5; // Round properly so that < 0.5 is 0.0.

    *pa = (INT08)(temp1); pa += i;
    *pa = (INT08)(temp2); pa += i;
  }

  // Handle odd number of elements.
  //----------------------------------------------------------------------------
  if((n%2)==1)
  {
    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;

    temp1 = std*sqrt(-2.0*log(u1))*cos(2*PI*u2);

    if(temp1>0) temp1+=0.5; // Round properly so that > 0.5 is 1.0.
    else        temp1-=0.5; // Round properly so that < 0.5 is 0.0.

    *pa = (INT08)(temp1); pa += i;
  }
//------------------------------- COMMON-CODE INT08             STOP.
}

VOID xccvRandNINT16(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE INT16            START.
  INT16 *pa = a;
  FLT32 temp1;
  FLT32 temp2;
  INT32 whogi;
  register UNT32 k;
  register FLT64 u1; 
  register FLT64 u2;

  whogi = (n-n%2)/2;

  // Calculate noise.
  //----------------------------------------------------------------------------
  for(k=0; k<whogi; k++)
  {                
    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;

    temp1 = std*sqrt(-2.0*log(u1))*cos(2*PI*u2);
    temp2 = std*sqrt(-2.0*log(u1))*sin(2*PI*u2);

    if(temp1>0) temp1+=0.5; // Round properly so that > 0.5 is 1.0.
    else        temp1-=0.5; // Round properly so that < 0.5 is 0.0.
    if(temp2>0) temp2+=0.5; // Round properly so that > 0.5 is 1.0.
    else        temp2-=0.5; // Round properly so that < 0.5 is 0.0.

    *pa = (INT16)(temp1); pa += i;
    *pa = (INT16)(temp2); pa += i;
  }

  // Handle odd number of elements.
  //----------------------------------------------------------------------------
  if((n%2)==1)
  {
    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;

    temp1 = std*sqrt(-2.0*log(u1))*cos(2*PI*u2);

    if(temp1>0) temp1+=0.5; // Round properly so that > 0.5 is 1.0.
    else        temp1-=0.5; // Round properly so that < 0.5 is 0.0.

    *pa = (INT16)(temp1); pa += i;
  }
//------------------------------- COMMON-CODE INT16             STOP.
}

VOID xccvRandNINT32(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE INT32            START.
  INT32 *pa = a;
  FLT32 temp1;
  FLT32 temp2;
  INT32 whogi;
  register UNT32 k;
  register FLT64 u1; 
  register FLT64 u2;

  whogi = (n-n%2)/2;

  // Calculate noise.
  //----------------------------------------------------------------------------
  for(k=0; k<whogi; k++)
  {                
    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;

    temp1 = std*sqrt(-2.0*log(u1))*cos(2*PI*u2);
    temp2 = std*sqrt(-2.0*log(u1))*sin(2*PI*u2);

    if(temp1>0) temp1+=0.5; // Round properly so that > 0.5 is 1.0.
    else        temp1-=0.5; // Round properly so that < 0.5 is 0.0.
    if(temp2>0) temp2+=0.5; // Round properly so that > 0.5 is 1.0.
    else        temp2-=0.5; // Round properly so that < 0.5 is 0.0.

    *pa = (INT32)(temp1); pa += i;
    *pa = (INT32)(temp2); pa += i;
  }

  // Handle odd number of elements.
  //----------------------------------------------------------------------------
  if((n%2)==1)
  {
    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;

    temp1 = std*sqrt(-2.0*log(u1))*cos(2*PI*u2);

    if(temp1>0) temp1+=0.5; // Round properly so that > 0.5 is 1.0.
    else        temp1-=0.5; // Round properly so that < 0.5 is 0.0.

    *pa = (INT32)(temp1); pa += i;
  }
//------------------------------- COMMON-CODE INT32             STOP.
}

VOID xccvRandNINT64(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n )
{
//------------------------------- COMMON-CODE INT64            START.
  INT64 *pa = a;
  FLT32 temp1;
  FLT32 temp2;
  INT32 whogi;
  register UNT32 k;
  register FLT64 u1; 
  register FLT64 u2;

  whogi = (n-n%2)/2;

  // Calculate noise.
  //----------------------------------------------------------------------------
  for(k=0; k<whogi; k++)
  {                
    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;

    temp1 = std*sqrt(-2.0*log(u1))*cos(2*PI*u2);
    temp2 = std*sqrt(-2.0*log(u1))*sin(2*PI*u2);

    if(temp1>0) temp1+=0.5; // Round properly so that > 0.5 is 1.0.
    else        temp1-=0.5; // Round properly so that < 0.5 is 0.0.
    if(temp2>0) temp2+=0.5; // Round properly so that > 0.5 is 1.0.
    else        temp2-=0.5; // Round properly so that < 0.5 is 0.0.

    *pa = (INT64)(temp1); pa += i;
    *pa = (INT64)(temp2); pa += i;
  }

  // Handle odd number of elements.
  //----------------------------------------------------------------------------
  if((n%2)==1)
  {
    u1 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;
    u2 = ((FLT64)*seed)*invUNT64-EPSILON_FLT64; *seed = ((*seed)*A1UNT64) + B1UNT64;

    temp1 = std*sqrt(-2.0*log(u1))*cos(2*PI*u2);

    if(temp1>0) temp1+=0.5; // Round properly so that > 0.5 is 1.0.
    else        temp1-=0.5; // Round properly so that < 0.5 is 0.0.

    *pa = (INT64)(temp1); pa += i;
  }
//------------------------------- COMMON-CODE INT64             STOP.
}

//------------------------------------------------------------------------------
// Rout: xccvRandNUNTXX
// Desc: This routine performs a normalized noise generation using the Box-Muller
//       method for unsigned integer values.
//       CAN YOU DO THIS?? NEED TO THINK ABOUT THIS ONE.
//------------------------------------------------------------------------------
//VOID xccvRandNUNT08(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n )
//{
//    COMMON CODE UNT08 < Broken COMMON CODE line.
//}

//VOID xccvRandNUNT16(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n )
//{
//    COMMON CODE UNT16 < Broken COMMON CODE line.
//}

//VOID xccvRandNUNT32(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n )
//{
//    COMMON CODE UNT32 < Broken COMMON CODE line.
//}

//VOID xccvRandNUNT64(UNT64 *seed, FLT32 std, VOID  *a, INT32 i, UNT32 n )
//{
//    COMMON CODE UNT64 < Broken COMMON CODE line.
//}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
