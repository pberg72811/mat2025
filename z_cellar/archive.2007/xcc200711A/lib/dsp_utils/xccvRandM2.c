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
#include "xccDSPUtils.h" 
 
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
//------------------------------- COMMON-CODE FLT32 START.

  UNT32 seedFLT32;
  xccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (xccvRandMSpec *) xccMallocINT08_Align032(sizeof(xccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) xccMallocFLT32_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  xccvRandNFLT32( &spec->seed, 1.0, spec->noiseTableVOID, 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE FLT32  STOP.
}

xccvRandMSpec *xccvRandMInitFLT64(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE FLT64 START.

  UNT32 seedFLT32;
  xccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (xccvRandMSpec *) xccMallocINT08_Align032(sizeof(xccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) xccMallocFLT64_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  xccvRandNFLT64( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE FLT64  STOP.
}

xccvRandMSpec *xccvRandMInitFLT96(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE FLT96 START.

  UNT32 seedFLT32;
  xccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (xccvRandMSpec *) xccMallocINT08_Align032(sizeof(xccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) xccMallocFLT96_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  xccvRandNFLT96( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE FLT96  STOP.
}

xccvRandMSpec *xccvRandMInitINT08(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE INT08 START.

  UNT32 seedFLT32;
  xccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (xccvRandMSpec *) xccMallocINT08_Align032(sizeof(xccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) xccMallocINT08_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  xccvRandNINT08( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE INT08  STOP.
}

xccvRandMSpec *xccvRandMInitINT16(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE INT16 START.

  UNT32 seedFLT32;
  xccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (xccvRandMSpec *) xccMallocINT08_Align032(sizeof(xccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) xccMallocINT16_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  xccvRandNINT16( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE INT16  STOP.
}

xccvRandMSpec *xccvRandMInitINT32(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE INT32 START.

  UNT32 seedFLT32;
  xccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (xccvRandMSpec *) xccMallocINT08_Align032(sizeof(xccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) xccMallocINT32_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  xccvRandNINT32( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE INT32  STOP.
}

xccvRandMSpec *xccvRandMInitINT64(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE INT64 START.

  UNT32 seedFLT32;
  xccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (xccvRandMSpec *) xccMallocINT08_Align032(sizeof(xccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) xccMallocINT64_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  xccvRandNINT64( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE INT64  STOP.
}

xccvRandMSpec *xccvRandMInitUNT08(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE UNT08 START.

  UNT32 seedFLT32;
  xccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (xccvRandMSpec *) xccMallocINT08_Align032(sizeof(xccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) xccMallocUNT08_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  xccvRandNUNT08( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE UNT08  STOP.
}

xccvRandMSpec *xccvRandMInitUNT16(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE UNT16 START.

  UNT32 seedFLT32;
  xccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (xccvRandMSpec *) xccMallocINT08_Align032(sizeof(xccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) xccMallocUNT16_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  xccvRandNUNT16( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE UNT16  STOP.
}

xccvRandMSpec *xccvRandMInitUNT32(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE UNT32 START.

  UNT32 seedFLT32;
  xccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (xccvRandMSpec *) xccMallocINT08_Align032(sizeof(xccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) xccMallocUNT32_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  xccvRandNUNT32( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE UNT32  STOP.
}

xccvRandMSpec *xccvRandMInitUNT64(UNT64 seed, FLT32 std, UNT32 tableSize)
{
//------------------------------- COMMON-CODE UNT64 START.

  UNT32 seedFLT32;
  xccvRandMSpec *spec=NULL;
  
  // Malloc the memory for the specification.
  //----------------------------------------------------------------------------
  spec = (xccvRandMSpec *) xccMallocINT08_Align032(sizeof(xccvRandMSpec));

  // Malloc the memory for the noise table.
  //----------------------------------------------------------------------------
  spec->noiseTableVOID = (VOID *) xccMallocUNT64_Align032(tableSize);

  // Initialize the seed.
  //----------------------------------------------------------------------------
  spec->seed = seed;

  // Set the table size.
  //----------------------------------------------------------------------------
  spec->tableSize = tableSize;

  // Generate the Gaussian numbers for the table.
  //----------------------------------------------------------------------------
  //time(&seedFLT32);

  xccvRandNUNT64( &spec->seed, 1.0, &spec->noiseTableVOID[0], 1, tableSize );

  // Return.
  //----------------------------------------------------------------------------
  return(spec);
//------------------------------- COMMON-CODE UNT64  STOP.
}


//------------------------------------------------------------------------------
// Rout: xccvRandMXXXXX
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

VOID xccvRandMFLT32(VOID  *a, INT32 i, UNT32 n, xccvRandMSpec *spec )
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

VOID xccvRandMFLT64(VOID  *a, INT32 i, UNT32 n, xccvRandMSpec *spec )
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

VOID xccvRandMFLT96(VOID  *a, INT32 i, UNT32 n, xccvRandMSpec *spec )
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

VOID xccvRandMINT08(VOID  *a, INT32 i, UNT32 n, xccvRandMSpec *spec )
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

VOID xccvRandMINT16(VOID  *a, INT32 i, UNT32 n, xccvRandMSpec *spec )
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

VOID xccvRandMINT32(VOID  *a, INT32 i, UNT32 n, xccvRandMSpec *spec )
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

VOID xccvRandMINT64(VOID  *a, INT32 i, UNT32 n, xccvRandMSpec *spec )
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

VOID xccvRandMUNT08(VOID  *a, INT32 i, UNT32 n, xccvRandMSpec *spec )
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

VOID xccvRandMUNT16(VOID  *a, INT32 i, UNT32 n, xccvRandMSpec *spec )
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

VOID xccvRandMUNT32(VOID  *a, INT32 i, UNT32 n, xccvRandMSpec *spec )
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

VOID xccvRandMUNT64(VOID  *a, INT32 i, UNT32 n, xccvRandMSpec *spec )
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
// Rout: xccvRandMTerm
// Desc: This routine termintates the table lookup noise generator specification.
//------------------------------------------------------------------------------
VOID xccvRandMTermFLT32(xccvRandMSpec *spec)
{
  xccFree(spec->noiseTableVOID);
  xccFree(spec);
  return;
}


/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
