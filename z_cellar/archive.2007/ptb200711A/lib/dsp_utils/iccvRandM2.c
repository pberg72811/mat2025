/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvRandNT.c
// Desc: This file contains the code for a few random number generator functions.
// Hist: When       Who  What
//       08/12/2002 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "iccDSPUtils.h" 
 
/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS
PERL_PREPROCESS  UNT32 seedFLT32;
PERL_PREPROCESS  iccvRandMSpec *spec=NULL;
PERL_PREPROCESS  
PERL_PREPROCESS  // Malloc the memory for the specification.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec = (iccvRandMSpec *) iccMallocINT08_Align032(sizeof(iccvRandMSpec));
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the noise table.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec->noiseTableVOID = (VOID *) iccMallocXXXXX_Align032(tableSize);
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
PERL_PREPROCESS  iccvRandNXXXXX( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );
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
// Rout: iccvRandMInitFLT32
// Desc: This routine initializes table lookup noise generator specification.
//------------------------------------------------------------------------------
iccvRandMSpec *iccvRandMInitFLT32(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE FLT32 START.

  UNT32 seedFLT32;
  iccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (iccvRandMSpec *) iccMallocINT08_Align032(sizeof(iccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) iccMallocFLT32_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  iccvRandNFLT32( &spec->seed, 1.0, spec->noiseTableVOID, 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE FLT32  STOP.
}

iccvRandMSpec *iccvRandMInitFLT64(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE FLT64 START.

  UNT32 seedFLT32;
  iccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (iccvRandMSpec *) iccMallocINT08_Align032(sizeof(iccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) iccMallocFLT64_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  iccvRandNFLT64( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE FLT64  STOP.
}

iccvRandMSpec *iccvRandMInitFLT96(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE FLT96 START.

  UNT32 seedFLT32;
  iccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (iccvRandMSpec *) iccMallocINT08_Align032(sizeof(iccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) iccMallocFLT96_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  iccvRandNFLT96( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE FLT96  STOP.
}

iccvRandMSpec *iccvRandMInitINT08(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE INT08 START.

  UNT32 seedFLT32;
  iccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (iccvRandMSpec *) iccMallocINT08_Align032(sizeof(iccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) iccMallocINT08_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  iccvRandNINT08( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE INT08  STOP.
}

iccvRandMSpec *iccvRandMInitINT16(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE INT16 START.

  UNT32 seedFLT32;
  iccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (iccvRandMSpec *) iccMallocINT08_Align032(sizeof(iccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) iccMallocINT16_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  iccvRandNINT16( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE INT16  STOP.
}

iccvRandMSpec *iccvRandMInitINT32(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE INT32 START.

  UNT32 seedFLT32;
  iccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (iccvRandMSpec *) iccMallocINT08_Align032(sizeof(iccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) iccMallocINT32_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  iccvRandNINT32( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE INT32  STOP.
}

iccvRandMSpec *iccvRandMInitINT64(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE INT64 START.

  UNT32 seedFLT32;
  iccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (iccvRandMSpec *) iccMallocINT08_Align032(sizeof(iccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) iccMallocINT64_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  iccvRandNINT64( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE INT64  STOP.
}

iccvRandMSpec *iccvRandMInitUNT08(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE UNT08 START.

  UNT32 seedFLT32;
  iccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (iccvRandMSpec *) iccMallocINT08_Align032(sizeof(iccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) iccMallocUNT08_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  iccvRandNUNT08( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE UNT08  STOP.
}

iccvRandMSpec *iccvRandMInitUNT16(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE UNT16 START.

  UNT32 seedFLT32;
  iccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (iccvRandMSpec *) iccMallocINT08_Align032(sizeof(iccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) iccMallocUNT16_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  iccvRandNUNT16( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE UNT16  STOP.
}

iccvRandMSpec *iccvRandMInitUNT32(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE UNT32 START.

  UNT32 seedFLT32;
  iccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (iccvRandMSpec *) iccMallocINT08_Align032(sizeof(iccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) iccMallocUNT32_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  iccvRandNUNT32( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE UNT32  STOP.
}

iccvRandMSpec *iccvRandMInitUNT64(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE UNT64 START.

  UNT32 seedFLT32;
  iccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (iccvRandMSpec *) iccMallocINT08_Align032(sizeof(iccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) iccMallocUNT64_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  iccvRandNUNT64( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE UNT64  STOP.
}


//------------------------------------------------------------------------------
// Rout: iccvRandMXXXXX
// Desc: These routines perform table lookup noise generation.
//------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS
PERL_PREPROCESS  XXXXX *pa=a;
PERL_PREPROCESS  XXXXX *noiseTableXXXXX = (XXXXX *) &spec->noiseTableVOID[0];
PERL_PREPROCESS  UNT32 k;
PERL_PREPROCESS  register FLT32 tmp1; 
PERL_PREPROCESS  register INT32 tmp2;
PERL_PREPROCESS  register INT32 size = spec->tableSize-1;
PERL_PREPROCESS  register UNT64 seed = spec->seed;
PERL_PREPROCESS  for(k=0; k<n; k++)
PERL_PREPROCESS  {                
PERL_PREPROCESS    tmp1 = ((FLT64)seed) * invUNT64;
PERL_PREPROCESS
PERL_PREPROCESS    tmp2 = (INT32)( size * tmp1);
PERL_PREPROCESS
PERL_PREPROCESS   *pa = noiseTableXXXXX[tmp2];
PERL_PREPROCESS
PERL_PREPROCESS    pa++;
PERL_PREPROCESS
PERL_PREPROCESS    seed = (seed*A1UNT64) + B1UNT64;
PERL_PREPROCESS  }
PERL_PREPROCESS  spec->seed = seed;
#endif

VOID iccvRandMFLT32(VOID  *a, INT32 i, UNT32 n, iccvRandMSpec *spec )
{
//------------------------------- COMMON-CODE FLT32 START.

  FLT32 *pa=a;
  FLT32 *noiseTableFLT32 = (FLT32 *) &spec->noiseTableVOID[0];
  UNT32 k;
  register FLT32 tmp1; 
  register INT32 tmp2;
  register INT32 size = spec->tableSize-1;
  register UNT64 seed = spec->seed;
  for(k=0; k<n; k++)
  {                
    tmp1 = ((FLT64)seed) * invUNT64;

    tmp2 = (INT32)( size * tmp1);

   *pa = noiseTableFLT32[tmp2];

    pa++;

    seed = (seed*A1UNT64) + B1UNT64;
  }
  spec->seed = seed;
//------------------------------- COMMON-CODE FLT32  STOP.
}

VOID iccvRandMFLT64(VOID  *a, INT32 i, UNT32 n, iccvRandMSpec *spec )
{
//------------------------------- COMMON-CODE FLT64 START.

  FLT64 *pa=a;
  FLT64 *noiseTableFLT64 = (FLT64 *) &spec->noiseTableVOID[0];
  UNT32 k;
  register FLT32 tmp1; 
  register INT32 tmp2;
  register INT32 size = spec->tableSize-1;
  register UNT64 seed = spec->seed;
  for(k=0; k<n; k++)
  {                
    tmp1 = ((FLT64)seed) * invUNT64;

    tmp2 = (INT32)( size * tmp1);

   *pa = noiseTableFLT64[tmp2];

    pa++;

    seed = (seed*A1UNT64) + B1UNT64;
  }
  spec->seed = seed;
//------------------------------- COMMON-CODE FLT64  STOP.
}

VOID iccvRandMFLT96(VOID  *a, INT32 i, UNT32 n, iccvRandMSpec *spec )
{
//------------------------------- COMMON-CODE FLT96 START.

  FLT96 *pa=a;
  FLT96 *noiseTableFLT96 = (FLT96 *) &spec->noiseTableVOID[0];
  UNT32 k;
  register FLT32 tmp1; 
  register INT32 tmp2;
  register INT32 size = spec->tableSize-1;
  register UNT64 seed = spec->seed;
  for(k=0; k<n; k++)
  {                
    tmp1 = ((FLT64)seed) * invUNT64;

    tmp2 = (INT32)( size * tmp1);

   *pa = noiseTableFLT96[tmp2];

    pa++;

    seed = (seed*A1UNT64) + B1UNT64;
  }
  spec->seed = seed;
//------------------------------- COMMON-CODE FLT96  STOP.
}

VOID iccvRandMINT08(VOID  *a, INT32 i, UNT32 n, iccvRandMSpec *spec )
{
//------------------------------- COMMON-CODE INT08 START.

  INT08 *pa=a;
  INT08 *noiseTableINT08 = (INT08 *) &spec->noiseTableVOID[0];
  UNT32 k;
  register FLT32 tmp1; 
  register INT32 tmp2;
  register INT32 size = spec->tableSize-1;
  register UNT64 seed = spec->seed;
  for(k=0; k<n; k++)
  {                
    tmp1 = ((FLT64)seed) * invUNT64;

    tmp2 = (INT32)( size * tmp1);

   *pa = noiseTableINT08[tmp2];

    pa++;

    seed = (seed*A1UNT64) + B1UNT64;
  }
  spec->seed = seed;
//------------------------------- COMMON-CODE INT08  STOP.
}

VOID iccvRandMINT16(VOID  *a, INT32 i, UNT32 n, iccvRandMSpec *spec )
{
//------------------------------- COMMON-CODE INT16 START.

  INT16 *pa=a;
  INT16 *noiseTableINT16 = (INT16 *) &spec->noiseTableVOID[0];
  UNT32 k;
  register FLT32 tmp1; 
  register INT32 tmp2;
  register INT32 size = spec->tableSize-1;
  register UNT64 seed = spec->seed;
  for(k=0; k<n; k++)
  {                
    tmp1 = ((FLT64)seed) * invUNT64;

    tmp2 = (INT32)( size * tmp1);

   *pa = noiseTableINT16[tmp2];

    pa++;

    seed = (seed*A1UNT64) + B1UNT64;
  }
  spec->seed = seed;
//------------------------------- COMMON-CODE INT16  STOP.
}

VOID iccvRandMINT32(VOID  *a, INT32 i, UNT32 n, iccvRandMSpec *spec )
{
//------------------------------- COMMON-CODE INT32 START.

  INT32 *pa=a;
  INT32 *noiseTableINT32 = (INT32 *) &spec->noiseTableVOID[0];
  UNT32 k;
  register FLT32 tmp1; 
  register INT32 tmp2;
  register INT32 size = spec->tableSize-1;
  register UNT64 seed = spec->seed;
  for(k=0; k<n; k++)
  {                
    tmp1 = ((FLT64)seed) * invUNT64;

    tmp2 = (INT32)( size * tmp1);

   *pa = noiseTableINT32[tmp2];

    pa++;

    seed = (seed*A1UNT64) + B1UNT64;
  }
  spec->seed = seed;
//------------------------------- COMMON-CODE INT32  STOP.
}

VOID iccvRandMINT64(VOID  *a, INT32 i, UNT32 n, iccvRandMSpec *spec )
{
//------------------------------- COMMON-CODE INT64 START.

  INT64 *pa=a;
  INT64 *noiseTableINT64 = (INT64 *) &spec->noiseTableVOID[0];
  UNT32 k;
  register FLT32 tmp1; 
  register INT32 tmp2;
  register INT32 size = spec->tableSize-1;
  register UNT64 seed = spec->seed;
  for(k=0; k<n; k++)
  {                
    tmp1 = ((FLT64)seed) * invUNT64;

    tmp2 = (INT32)( size * tmp1);

   *pa = noiseTableINT64[tmp2];

    pa++;

    seed = (seed*A1UNT64) + B1UNT64;
  }
  spec->seed = seed;
//------------------------------- COMMON-CODE INT64  STOP.
}

VOID iccvRandMUNT08(VOID  *a, INT32 i, UNT32 n, iccvRandMSpec *spec )
{
//------------------------------- COMMON-CODE INT08 START.

  INT08 *pa=a;
  INT08 *noiseTableINT08 = (INT08 *) &spec->noiseTableVOID[0];
  UNT32 k;
  register FLT32 tmp1; 
  register INT32 tmp2;
  register INT32 size = spec->tableSize-1;
  register UNT64 seed = spec->seed;
  for(k=0; k<n; k++)
  {                
    tmp1 = ((FLT64)seed) * invUNT64;

    tmp2 = (INT32)( size * tmp1);

   *pa = noiseTableINT08[tmp2];

    pa++;

    seed = (seed*A1UNT64) + B1UNT64;
  }
  spec->seed = seed;
//------------------------------- COMMON-CODE INT08  STOP.
}

VOID iccvRandMUNT16(VOID  *a, INT32 i, UNT32 n, iccvRandMSpec *spec )
{
//------------------------------- COMMON-CODE UNT16 START.

  UNT16 *pa=a;
  UNT16 *noiseTableUNT16 = (UNT16 *) &spec->noiseTableVOID[0];
  UNT32 k;
  register FLT32 tmp1; 
  register INT32 tmp2;
  register INT32 size = spec->tableSize-1;
  register UNT64 seed = spec->seed;
  for(k=0; k<n; k++)
  {                
    tmp1 = ((FLT64)seed) * invUNT64;

    tmp2 = (INT32)( size * tmp1);

   *pa = noiseTableUNT16[tmp2];

    pa++;

    seed = (seed*A1UNT64) + B1UNT64;
  }
  spec->seed = seed;
//------------------------------- COMMON-CODE UNT16  STOP.
}

VOID iccvRandMUNT32(VOID  *a, INT32 i, UNT32 n, iccvRandMSpec *spec )
{
//------------------------------- COMMON-CODE UNT32 START.

  UNT32 *pa=a;
  UNT32 *noiseTableUNT32 = (UNT32 *) &spec->noiseTableVOID[0];
  UNT32 k;
  register FLT32 tmp1; 
  register INT32 tmp2;
  register INT32 size = spec->tableSize-1;
  register UNT64 seed = spec->seed;
  for(k=0; k<n; k++)
  {                
    tmp1 = ((FLT64)seed) * invUNT64;

    tmp2 = (INT32)( size * tmp1);

   *pa = noiseTableUNT32[tmp2];

    pa++;

    seed = (seed*A1UNT64) + B1UNT64;
  }
  spec->seed = seed;
//------------------------------- COMMON-CODE UNT32  STOP.
}

VOID iccvRandMUNT64(VOID  *a, INT32 i, UNT32 n, iccvRandMSpec *spec )
{
//------------------------------- COMMON-CODE UNT64 START.

  UNT64 *pa=a;
  UNT64 *noiseTableUNT64 = (UNT64 *) &spec->noiseTableVOID[0];
  UNT32 k;
  register FLT32 tmp1; 
  register INT32 tmp2;
  register INT32 size = spec->tableSize-1;
  register UNT64 seed = spec->seed;
  for(k=0; k<n; k++)
  {                
    tmp1 = ((FLT64)seed) * invUNT64;

    tmp2 = (INT32)( size * tmp1);

   *pa = noiseTableUNT64[tmp2];

    pa++;

    seed = (seed*A1UNT64) + B1UNT64;
  }
  spec->seed = seed;
//------------------------------- COMMON-CODE UNT64  STOP.
}

//------------------------------------------------------------------------------
// Rout: iccvRandMTerm
// Desc: This routine termintates the table lookup noise generator specification.
//------------------------------------------------------------------------------
VOID iccvRandMTermFLT32(iccvRandMSpec *spec)
{
  iccFree(spec->noiseTableVOID);
  iccFree(spec);
  return;
}


/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
