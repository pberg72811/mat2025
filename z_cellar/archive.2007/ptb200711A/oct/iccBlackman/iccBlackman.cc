/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: blackman.cc
// Desc: This is an Octave shared library for the blackman function.
// Hist: When       Who  What
//       10/29/2001 ptb  Initial Code.  Confirmed with Matlab.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include <octave/oct.h>
#include "iccswd.h"
#include "iccDSPUtils.h"
#include "iccMallocUtils.h"

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
DEFUN_DLD(blackman, args, ,
          "Blackman fixed shape window function.  v = blackman(N);")
{
  octave_value_list retval;
  octave_value arg;
  INT32 nargin = args.length();
  INT32 ii;

// Quck error check.
//------------------------------------------------------------------------------
  if( nargin != 1)
  {
    printf("blackman needs 1 input.\n");
    printf("Number of elements in window.\n");
    return retval;
  }

// "Get" the number of elements.
//------------------------------------------------------------------------------
  arg = args(0);
  INT32 N = (INT32)arg.double_value();
  //printf("Number of elements is %d\n",N);

// Create an output vector.
//------------------------------------------------------------------------------
  ColumnVector vectorOut(N);
  //printf("Length of vectorOut is %d\n",vectorOut.length());

// Allocate memory for the processing vectors.
//------------------------------------------------------------------------------
  FLT64 *vectorFLT64 = iccMallocFLT64(N);
  if( vectorFLT64 == NULL ) return retval;

// Create the window.
//------------------------------------------------------------------------------
  iccBlackmanCreateWindowFLT64(vectorFLT64, 1, N );

// Copy from processing vector to output vector.
//------------------------------------------------------------------------------
  for(ii = 0; ii < vectorOut.length(); ii++) vectorOut(ii) = vectorFLT64[ii];
  //printf("Doing handoff for output vector\n");

// Free up the processing vector memory.
//------------------------------------------------------------------------------
  iccFree(vectorFLT64);
  //printf("About to iccFree up memory\n");

// Return the output vector.
//------------------------------------------------------------------------------
  //printf("About to return value\n");
  retval(0) = vectorOut;
  return retval;

}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
