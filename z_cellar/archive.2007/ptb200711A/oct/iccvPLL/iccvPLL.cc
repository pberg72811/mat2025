/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvPLL.cc
// Desc: This is an Octave shared library for the iccvPLL function.
// Hist: When       Who  What
//       09/09/2002 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include <octave/oct.h>
#include "iccswd.h"
#include "iccDSPUtils.h"
#include "iccMallocUtils.h"
#include "iccVectorUtils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define iccvPLL_FUNC_DESC \
"***************************************************************************\n"\
"iccvPLL: This routine performs a phase lock loop on the incoming data.     \n"\
"         The data is assumed to be sinusoidal.                             \n"\
"                  iccvPLL(data, fc, fs);                                   \n"\
"***************************************************************************\n"

#undef Complex

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
void iccvPLLDoNothing(void)
{
  int x;
  x = 1;
}

/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
DEFUN_DLD(iccvPLL, args, ,iccvPLL_FUNC_DESC)
{
  octave_value_list retval;
  INT32 nargin = args.length();
  ColumnVector iVector;
  ColumnVector oVector;
  FLT32 *ivPLL;
  FLT32 *ovPLL;
  FLT32 fs;
  FLT32 fc;
  INT32 ii;

// Example argument check.  Is there a valid number of arguments.
//------------------------------------------------------------------------------
  if( nargin != 3 )
  {
    printf(iccvPLL_FUNC_DESC);
    return retval;
  }

// Handoff arguments
//------------------------------------------------------------------------------
  iVector = ColumnVector( args(0).vector_value() );
  oVector = ColumnVector( iVector.length() );
  fc = args(1).double_value();
  fs = args(2).double_value();

// Allocated PLL vectors.
//------------------------------------------------------------------------------
  ivPLL = iccMallocFLT32(iVector.length());
  ovPLL = iccMallocFLT32(iVector.length());

// Copy input data to input PLL vector.
//------------------------------------------------------------------------------
  for(ii = 0; ii < iVector.length(); ii++) ivPLL[ii] = iVector(ii);

// Do the PLL.
//------------------------------------------------------------------------------
  iccvPLLFLT32(ivPLL, 1, ovPLL, 1, iVector.length(), fc, fs);
 
// Copy the output PLL vector to the output data.
//------------------------------------------------------------------------------
  for(ii = 0; ii < oVector.length(); ii++) oVector(ii) = ovPLL[ii];

// Return.
//------------------------------------------------------------------------------
  retval(0) = oVector;
  return retval;

}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/


