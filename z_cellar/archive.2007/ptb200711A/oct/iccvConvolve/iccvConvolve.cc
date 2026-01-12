/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvConvolve.cc
// Desc: This is an Octave shared library for the iccvConvolve function.
// Hist: When       Who  What
//       11/13/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include <octave/oct.h>
#include "iccswd.h"
#include "iccMallocUtils.h"
#include "iccOctaveUtils.h"
#include "iccVectorUtils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define iccVCONVOLVE_FUNC_DESC \
"***************************************************************************\n"\
"iccvConvolve: vector convolution vout = iccvConvolve(vin1, vin2);\n"          \
"                                      = iccvConvolve('TEST');\n"              \
"***************************************************************************\n"

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
octave_value_list testIt(void);

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
DEFUN_DLD(iccvConvolve, arg, ,iccVCONVOLVE_FUNC_DESC)
{
  octave_value_list retval;
  INT32 nargin = arg.length();
  INT32 ii;
  INT32 N3;

// Is there a valid number of arguments.
//------------------------------------------------------------------------------
  if( (nargin != 1) && (nargin != 2) )
  {
    printf(iccVCONVOLVE_FUNC_DESC);
    return retval;
  }

// Check for the test option.
//------------------------------------------------------------------------------
  if( (nargin == 1) )
  {
    if( (arg(0).is_string()) && 
        (strncmp(arg(0).string_value().data(),"TEST",4) == 0 ) )
    {
      retval = testIt();
      return retval;
    }
    else
    {
      printf(iccVCONVOLVE_FUNC_DESC);
      return retval;
    }
  }

// "Get" the size of the first and second input vector.
//------------------------------------------------------------------------------
  INT32 N1 = arg(0).vector_value().length();
  INT32 N2 = arg(1).vector_value().length();

// Calculate the size of the output vector.
//------------------------------------------------------------------------------
  if      (N1 > N2) N3 = N1 - N2 + 1;
  else if (N1 < N2) N3 = N2 - N1 + 1;
  else              N3 = 1;

// Create the output vector.
//------------------------------------------------------------------------------
  ColumnVector vectorOut(N3);

// Create float arrays for processing.
//------------------------------------------------------------------------------
  FLT32 *vector1FLT32 = iccMallocFLT32(N1);
  FLT32 *vector2FLT32 = iccMallocFLT32(N2);
  FLT32 *vector3FLT32 = iccMallocFLT32(N3);

// Handoff input vector to first and second processing vector.
//------------------------------------------------------------------------------
  for(ii=0; ii<N1; ii++) vector1FLT32[ii] = arg(0).vector_value().elem(ii);
  for(ii=0; ii<N2; ii++) vector2FLT32[ii] = arg(1).vector_value().elem(ii);

// Call iccvConvolveFLT32
//------------------------------------------------------------------------------
  for(ii=0; ii<N3; ii++)
  {
    if      (N1 > N2) vector3FLT32[ii] = iccvConvolveFLT32(&vector1FLT32[ii], 1, vector2FLT32     , 1, N2);
    else if (N2 > N1 )vector3FLT32[ii] = iccvConvolveFLT32( vector1FLT32    , 1, &vector2FLT32[ii], 1, N1);
    else              vector3FLT32[ii] = iccvConvolveFLT32( vector1FLT32    , 1, vector2FLT32     , 1, N1);
  }

// Handoff second processing array to output vector.
//------------------------------------------------------------------------------
  for(ii=0; ii<N3; ii++) vectorOut(ii) = vector3FLT32[ii];

// Free up the processing arrays.
//------------------------------------------------------------------------------
  iccFree(vector1FLT32);
  iccFree(vector2FLT32);
  iccFree(vector3FLT32);

// Return the values.
//------------------------------------------------------------------------------
  retval(0) = vectorOut;
  return retval;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// TEST SECTION.
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
octave_value_list testIt(void)
{
  octave_value_list retval;
  ColumnVector testResult(1);
  FLT32 R = 0.0;
  INT32 N = 1024;
  FLT32 *vector1FLT32;
  FLT32 *vector2FLT32;
  FLT32 *vector3FLT32;
  FLT32 *vector4FLT32;
  INT32 ii;
  printf("TESTING!\n");
  
// Create float arrays for processing.
//------------------------------------------------------------------------------
  vector1FLT32 = iccMallocFLT32(N); for(ii = 0; ii < N; ii++) vector1FLT32[ii] = ii;
  vector2FLT32 = iccMallocFLT32(N); for(ii = 0; ii < N; ii++) vector2FLT32[ii] = 0;
  vector3FLT32 = iccMallocFLT32(N); for(ii = 0; ii < N; ii++) vector3FLT32[ii] = 0;
  vector4FLT32 = iccMallocFLT32(N); for(ii = 0; ii < N; ii++) vector4FLT32[ii] = 0;

// Perform test.
//------------------------------------------------------------------------------
//  iccvConvolveFLT32(&vector1FLT32[0], 2, 2.0, &vector2FLT32[0], 2, N/2);
//  iccvConvolveFLT32(&vector1FLT32[1], 2, 2.0, &vector2FLT32[1], 2, N/2);
//  iccvConvolveFLT32(vector2FLT32,     1, 0.5, vector3FLT32,     1, N);
//  iccvSubFLT32(vector3FLT32, 1, vector1FLT32, 1, vector4FLT32, 1, N);
//  R = iccvSumFLT32(vector4FLT32, 1, N);
  if(R==0.0)
  {
    testResult(0) = 1.0; printf("TEST SUCCESSFUL!!\n");
  }
  else
  {
    testResult(0) = 0.0; printf("TEST UNSUCCESSFUL!!\n");
  }
  
// Free up processing vectors.
//------------------------------------------------------------------------------
  iccFree(vector1FLT32); iccFree(vector2FLT32); iccFree(vector3FLT32); iccFree(vector4FLT32);

// Return with test result.
//------------------------------------------------------------------------------
  retval(0) = testResult;
  return retval;
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
