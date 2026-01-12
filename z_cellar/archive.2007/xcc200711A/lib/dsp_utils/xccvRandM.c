/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccvRandNT.c
// Desc: This file contains the code for a few random number generator functions.
// Hist: When       Who  What
//       08/12/2002 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "dsp_utils.h" 
 
/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS
PERL_PREPROCESS  xccvRandMSpec *spec=NULL;
PERL_PREPROCESS  
PERL_PREPROCESS  // Malloc the memory for the specification.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec = (xccvRandMSpec *) xccMallocINT08_Align032(sizeof(xccvRandMSpec));
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the noise table.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec->noiseTableVOID = (VOID *) xccMallocXXXXX_Align032(tableSize);
PERL_PREPROCESS
PERL_PREPROCESS  // Initialize the seed.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec->seed = seed;
PERL_PREPROCESS
PERL_PREPROCESS  // Set the table size.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec->tableSize = tableSize;
PERL_PREPROCESS
PERL_PREPROCESS  // Generate the Gaussian numbers for the table.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  //time(&seedFLT32);
PERL_PREPROCESS
PERL_PREPROCESS  xccvRandNXXXXX( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );
PERL_PREPROCESS
PERL_PREPROCESS  // Return.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  return(spec);
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
// Rout: xccvRandMInitFLT32
// Desc: This routine initializes table lookup noise generator specification.
//------------------------------------------------------------------------------
xccvRandMSpec *xccvRandMInitFLT32(UNT64 seed, FLT32 std, UNT32 tableSize)
{
  UNT64 seedUNT64;
  UNT32 seedUNT32;

  xccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (xccvRandMSpec *) xccMallocVOID_Align032(sizeof(xccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = xccMallocFLT32_Align032(tableSize);
  //(FLT32 *) malloc(sizeof(FLT32)*tableSize);
  //spec->noiseTableFLT64 = NULL; //(FLT64 *) malloc(sizeof(FLT64));
  //spec->noiseTableFLT96 = NULL; //(FLT96 *) malloc(sizeof(FLT96));
  //spec->noiseTableINT08 = NULL; //(INT08 *) malloc(sizeof(INT08));
  //spec->noiseTableINT16 = NULL; //(INT16 *) malloc(sizeof(INT16));
  //spec->noiseTableINT32 = NULL; //(INT32 *) malloc(sizeof(INT32));
  //spec->noiseTableINT64 = NULL; //(INT64 *) malloc(sizeof(INT64));

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  time(&seedUNT32);

  seedUNT64=seedUNT32;

  xccvRandNFLT32( &seedUNT64, 1.0, &spec->noiseTableFLT32[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
}

xccvRandMSpec *xccvRandMInitINT16(UNT64 seed, FLT32 std, UNT32 tableSize)
{
  UNT64 seedUNT64;
  UNT32 seedUNT32;
  xccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (xccvRandMSpec *) malloc(sizeof(xccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableFLT32 =  NULL; //(FLT32 *) malloc(sizeof(FLT32));
  spec->noiseTableFLT64 =  NULL; //(FLT64 *) malloc(sizeof(FLT64));
  spec->noiseTableFLT96 =  NULL; //(FLT96 *) malloc(sizeof(FLT96));
  spec->noiseTableINT08 =  NULL; //(INT08 *) malloc(sizeof(INT08));
  spec->noiseTableINT16 = xccMallocINT16_Align032(tableSize); //(INT16 *) malloc(sizeof(INT16)*tableSize);
  spec->noiseTableINT32 =  NULL; //(INT32 *) malloc(sizeof(INT32));
  spec->noiseTableINT64 =  NULL; //(INT64 *) malloc(sizeof(INT64));

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  time(&seedUNT32);

  seedUNT64=seedUNT32;

  xccvRandNINT16( &seedUNT64, std, &spec->noiseTableINT16[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
}

//------------------------------------------------------------------------------
// Rout: xccvRandMFLT32
// Desc: This routine performs table lookup noise generation.
//------------------------------------------------------------------------------
VOID xccvRandMFLT32(FLT32 *a, UNT32 n, xccvRandMSpec *spec )
{
  FLT32 *pa=a;
  UNT32 k;
  register FLT32 tmp1; 
  register INT32 tmp2;
  register INT32 size = spec->tableSize-1;
  register UNT64 seed = spec->seed;
  for(k=0; k<n; k++)
  {                
    tmp1 = ((FLT64)seed) * invUNT64;

    tmp2 = (INT32)( size * tmp1);

    *pa = spec->noiseTableFLT32[tmp2];

    pa++;

    seed = (seed*A1UNT64) + B1UNT64;
  }
  spec->seed = seed;
}

VOID xccvRandMINT16(INT16 *a, UNT32 n, xccvRandMSpec *spec )
{
  INT16 *pa=a;
  register UNT32 k;
  register UNT64 seed1;

  //register FLT32 tmp1; 
  //register INT32 tmp2;
  //register INT32 size = spec->tableSize-1;
  typedef union
  {
    UNT64 seed64;
    INT32 seed32[2];
    INT32 seed16[4];
    INT08 seed08[8];
  }seed_t;

  register seed_t seed2;

  seed1 = spec->seed;
  for(k=0; k<n; k++)
  {                
    //tmp1 = ((FLT64)seed1) * invUNT64;

    //tmp2 = (INT32)( size * tmp1);

    //*pa = spec->noiseTableINT16[tmp2];

    seed2.seed64 = seed1;
    seed2.seed08[7] = 0;
    seed2.seed08[6] = 0x06;
    *pa = spec->noiseTableINT16[seed2.seed32[1]];

    pa++;

    seed1 = (seed1*A1UNT64) + B1UNT64;
  }
  spec->seed = seed1;
}

//------------------------------------------------------------------------------
// Rout: xccvRandMTermFLT32
// Desc: This routine termintates the table lookup noise generator specification.
//------------------------------------------------------------------------------
VOID xccvRandMTermFLT32(xccvRandMSpec *spec)
{
  xmcFree(spec->noiseTableFLT32);
  xmcFree(spec->noiseTableFLT64);
  xmcFree(spec->noiseTableFLT96);
  xmcFree(spec->noiseTableINT08);
  xmcFree(spec->noiseTableINT16);
  xmcFree(spec->noiseTableINT32);
  xmcFree(spec->noiseTableINT64);
  xmcFree(spec);
  return;
}


/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
