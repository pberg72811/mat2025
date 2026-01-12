/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccFFT.cc
// Desc: This is an Octave shared library for the iccFFT function.
// Hist: When       Who  What
//       03/26/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include <octave/oct.h>
#include "iccswd.h"
#include "iccDSPUtils.h"
#include "iccMallocUtils.h"
#include "iccStackUtils.h"
#include "iccVectorUtils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define iccFFT_FUNC_DESC \
"***************************************************************************\n"\
"iccFFT: This function will calculate an FFT.                               \n"\
"                  iccFFT(arg1, arg2);                                      \n"\
"Note:   Input needs to be a power of 2, as in 2,4,8,16,32,64,128,...       \n"\
"***************************************************************************\n"

#undef Complex

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
DEFUN_DLD(iccFFT, args, ,iccFFT_FUNC_DESC)
{
  INT32 ii;
  FLT32 *vectorFLT32;
  FLT32 *fftVectorFLT32;
  octave_value_list retval;
  INT32 nargin = args.length();
  ComplexColumnVector returnVector_C(1);

// Example argument check.  Is there a valid number of arguments.
//------------------------------------------------------------------------------
  if( (nargin != 1) && (nargin != 2) )
  {
    printf(iccFFT_FUNC_DESC);
    return retval;
  }

// Some examples on how to handoff arguments.
//------------------------------------------------------------------------------
  if(nargin==1)
  {
    if( args(0).is_complex_type() )
    {
      INT32 N = args(0).complex_vector_value().length();
      vectorFLT32    = iccMallocFLT32(2*N);
      fftVectorFLT32 = iccMallocFLT32(2*N);
      returnVector_C.resize(N);
      for(ii=0; ii<N; ii++) vectorFLT32[2*ii+0] = real(args(0).complex_vector_value().elem(ii));
      for(ii=0; ii<N; ii++) vectorFLT32[2*ii+1] = imag(args(0).complex_vector_value().elem(ii));
      iccFFTFLT32_C(vectorFLT32, fftVectorFLT32, N);
      for(ii=0; ii<N; ii++) returnVector_C(ii) = Complex(fftVectorFLT32[2*ii],fftVectorFLT32[2*ii+1]);
      retval(0) = returnVector_C;
      return retval;
      //ComplexColumnVector inData = ComplexColumnVector(args(0).complex_vector_value());
    }
    else
    {
      INT32 N = args(0).vector_value().length();
      vectorFLT32 = iccMallocFLT32(N);
      fftVectorFLT32 = iccMallocFLT32(2*N);
      returnVector_C.resize(N);
      for(ii=0; ii<N; ii++) vectorFLT32[ii] = real(args(0).vector_value().elem(ii));
      iccFFTFLT32_R(vectorFLT32, fftVectorFLT32, N);
      for(ii=0; ii<N; ii++) returnVector_C(ii) = Complex(fftVectorFLT32[2*ii],fftVectorFLT32[2*ii+1]);
      retval(0) = returnVector_C;
      return retval;
      //ColumnVector inData = ColumnVector(args(0).vector_value());
    }
  }
  else //IFFT
  {
    INT32 N = args(0).complex_vector_value().length();
    vectorFLT32    = iccMallocFLT32(2*N);
    fftVectorFLT32 = iccMallocFLT32(2*N);
    returnVector_C.resize(N);
    for(ii=0; ii<N; ii++) vectorFLT32[2*ii+0] = real(args(0).complex_vector_value().elem(ii));
    for(ii=0; ii<N; ii++) vectorFLT32[2*ii+1] = imag(args(0).complex_vector_value().elem(ii));
    iccIFFTFLT32_C(vectorFLT32, fftVectorFLT32, N);
    for(ii=0; ii<N; ii++) returnVector_C(ii) = Complex(fftVectorFLT32[2*ii],fftVectorFLT32[2*ii+1]);
    retval(0) = returnVector_C;
    return retval;
    //ComplexColumnVector inData = ComplexColumnVector(args(0).complex_vector_value());
  }
// Example return.  Return any values.
//------------------------------------------------------------------------------
  //returnVector(0) = 3;
  //returnVector(1) = 2;
  //returnVector(2) = 1;

  //retval(0) = returnVector;
  //return retval;

}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
