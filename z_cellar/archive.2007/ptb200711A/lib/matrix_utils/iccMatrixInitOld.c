/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccMatrixInit.c
// Desc: This file contains the code for the iccMatrixInit routine.
// Hist: When       Who  What
//       06/30/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "iccMatrixUtils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS  INT32 ii;
PERL_PREPROCESS  va_list argptr;
PERL_PREPROCESS  iccMatrixXXXXX_t *p2Matrix;
PERL_PREPROCESS
PERL_PREPROCESS  // Check name length.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if( strlen(name) > icc_MATRIX_NAME_SIZE )
PERL_PREPROCESS  {
PERL_PREPROCESS    icc_ERROR_MESSAGE("MATRIX NAME TOO LONG");
PERL_PREPROCESS    return(NULL);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Check real or imaginary flag.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if( (realMatrix != 1) && (realMatrix != 0)  )
PERL_PREPROCESS  {
PERL_PREPROCESS    icc_ERROR_MESSAGE("BAD REAL_MATRIX VALUE");
PERL_PREPROCESS    return(NULL);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Allocate memory for the matrix.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  p2Matrix = ((iccMatrixXXXXX_t *) iccMallocVOID_Align032(sizeof(iccMatrixXXXXX_t));
PERL_PREPROCESS  if(p2Matrix==NULL)
PERL_PREPROCESS  {
PERL_PREPROCESS    icc_ERROR_MESSAGE("Could not allocate memory for Matrix.");
PERL_PREPROCESS    return(NULL);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the Matrix dimensions.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  p2Matrix->ndim = ndim;
PERL_PREPROCESS
PERL_PREPROCESS  p2Matrix->dim = iccMallocINT32_Align032(ndim);
PERL_PREPROCESS
PERL_PREPROCESS  // Get the dimensions of the matrix.  Start the variable arguments.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  p2Matrix->total = 1;
PERL_PREPROCESS  va_start(argptr, ndim);
PERL_PREPROCESS  for(ii = 0; ii < ndim; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    p2Matrix->dim[ii] = va_arg(argptr, INT32);
PERL_PREPROCESS    p2Matrix->total = p2Matrix->total*p2Matrix->dim[ii];
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the real pointer.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  p2Matrix->pr = iccMallocXXXXX_Align032(p2Matrix->total);
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the imag pointer (if complex(CPLX)).
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if(realMatrix != REAL) p2Matrix->pi = iccMallocXXXXX_Align032(p2Matrix->total);
PERL_PREPROCESS
PERL_PREPROCESS  // Shutdown variable arguments and return the Matrix.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  va_end(argptr);
PERL_PREPROCESS  return(p2Matrix);
#endif
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
iccMatrixINT08_t iccMatrixInitINT08(CCHAR *name, INT08 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE INT08 START.
  INT32 ii;
  va_list argptr;
  iccMatrixINT08_t Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    icc_ERROR_MESSAGE("MATRIX NAME TOO LONG");
    return(Matrix);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    icc_ERROR_MESSAGE("BAD REAL_MATRIX VALUE");
    return(Matrix);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  Matrix.ndim = ndim;

  Matrix.dim = iccMallocINT32_Align032(ndim);

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  Matrix.total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    Matrix.dim[ii] = va_arg(argptr, INT32);
    Matrix.total = Matrix.total*Matrix.dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  Matrix.pr = iccMallocINT08_Align032(Matrix.total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL) Matrix.pi = iccMallocINT08_Align032(Matrix.total);

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(Matrix);
//COMMON-CODE INT08  STOP.
}

iccMatrixINT16_t iccMatrixInitINT16(CCHAR *name, INT16 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE INT16 START.
  INT32 ii;
  va_list argptr;
  iccMatrixINT16_t Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    icc_ERROR_MESSAGE("MATRIX NAME TOO LONG");
    return(Matrix);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    icc_ERROR_MESSAGE("BAD REAL_MATRIX VALUE");
    return(Matrix);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  Matrix.ndim = ndim;

  Matrix.dim = iccMallocINT32_Align032(ndim);

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  Matrix.total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    Matrix.dim[ii] = va_arg(argptr, INT32);
    Matrix.total = Matrix.total*Matrix.dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  Matrix.pr = iccMallocINT16_Align032(Matrix.total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL) Matrix.pi = iccMallocINT16_Align032(Matrix.total);

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(Matrix);
//COMMON-CODE INT16  STOP.
}

iccMatrixINT32_t iccMatrixInitINT32(CCHAR *name, INT32 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE INT32 START.
  INT32 ii;
  va_list argptr;
  iccMatrixINT32_t Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    icc_ERROR_MESSAGE("MATRIX NAME TOO LONG");
    return(Matrix);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    icc_ERROR_MESSAGE("BAD REAL_MATRIX VALUE");
    return(Matrix);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  Matrix.ndim = ndim;

  Matrix.dim = iccMallocINT32_Align032(ndim);

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  Matrix.total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    Matrix.dim[ii] = va_arg(argptr, INT32);
    Matrix.total = Matrix.total*Matrix.dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  Matrix.pr = iccMallocINT32_Align032(Matrix.total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL) Matrix.pi = iccMallocINT32_Align032(Matrix.total);

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(Matrix);
//COMMON-CODE INT32  STOP.
}

iccMatrixINT64_t iccMatrixInitINT64(CCHAR *name, INT64 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE INT64 START.
  INT32 ii;
  va_list argptr;
  iccMatrixINT64_t Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    icc_ERROR_MESSAGE("MATRIX NAME TOO LONG");
    return(Matrix);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    icc_ERROR_MESSAGE("BAD REAL_MATRIX VALUE");
    return(Matrix);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  Matrix.ndim = ndim;

  Matrix.dim = iccMallocINT32_Align032(ndim);

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  Matrix.total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    Matrix.dim[ii] = va_arg(argptr, INT32);
    Matrix.total = Matrix.total*Matrix.dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  Matrix.pr = iccMallocINT64_Align032(Matrix.total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL) Matrix.pi = iccMallocINT64_Align032(Matrix.total);

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(Matrix);
//COMMON-CODE INT64  STOP.
}

iccMatrixUNT08_t iccMatrixInitUNT08(CCHAR *name, UNT08 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE UNT08 START.
  INT32 ii;
  va_list argptr;
  iccMatrixUNT08_t Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    icc_ERROR_MESSAGE("MATRIX NAME TOO LONG");
    return(Matrix);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    icc_ERROR_MESSAGE("BAD REAL_MATRIX VALUE");
    return(Matrix);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  Matrix.ndim = ndim;

  Matrix.dim = iccMallocINT32_Align032(ndim);

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  Matrix.total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    Matrix.dim[ii] = va_arg(argptr, INT32);
    Matrix.total = Matrix.total*Matrix.dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  Matrix.pr = iccMallocUNT08_Align032(Matrix.total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL) Matrix.pi = iccMallocUNT08_Align032(Matrix.total);

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(Matrix);
//COMMON-CODE UNT08  STOP.
}

iccMatrixUNT16_t iccMatrixInitUNT16(CCHAR *name, UNT16 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE UNT16 START.
  INT32 ii;
  va_list argptr;
  iccMatrixUNT16_t Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    icc_ERROR_MESSAGE("MATRIX NAME TOO LONG");
    return(Matrix);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    icc_ERROR_MESSAGE("BAD REAL_MATRIX VALUE");
    return(Matrix);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  Matrix.ndim = ndim;

  Matrix.dim = iccMallocINT32_Align032(ndim);

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  Matrix.total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    Matrix.dim[ii] = va_arg(argptr, INT32);
    Matrix.total = Matrix.total*Matrix.dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  Matrix.pr = iccMallocUNT16_Align032(Matrix.total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL) Matrix.pi = iccMallocUNT16_Align032(Matrix.total);

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(Matrix);
//COMMON-CODE UNT16  STOP.
}

iccMatrixUNT32_t iccMatrixInitUNT32(CCHAR *name, UNT32 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE UNT32 START.
  INT32 ii;
  va_list argptr;
  iccMatrixUNT32_t Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    icc_ERROR_MESSAGE("MATRIX NAME TOO LONG");
    return(Matrix);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    icc_ERROR_MESSAGE("BAD REAL_MATRIX VALUE");
    return(Matrix);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  Matrix.ndim = ndim;

  Matrix.dim = iccMallocINT32_Align032(ndim);

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  Matrix.total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    Matrix.dim[ii] = va_arg(argptr, INT32);
    Matrix.total = Matrix.total*Matrix.dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  Matrix.pr = iccMallocUNT32_Align032(Matrix.total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL) Matrix.pi = iccMallocUNT32_Align032(Matrix.total);

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(Matrix);
//COMMON-CODE UNT32  STOP.
}

iccMatrixUNT64_t iccMatrixInitUNT64(CCHAR *name, UNT64 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE UNT64 START.
  INT32 ii;
  va_list argptr;
  iccMatrixUNT64_t Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    icc_ERROR_MESSAGE("MATRIX NAME TOO LONG");
    return(Matrix);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    icc_ERROR_MESSAGE("BAD REAL_MATRIX VALUE");
    return(Matrix);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  Matrix.ndim = ndim;

  Matrix.dim = iccMallocINT32_Align032(ndim);

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  Matrix.total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    Matrix.dim[ii] = va_arg(argptr, INT32);
    Matrix.total = Matrix.total*Matrix.dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  Matrix.pr = iccMallocUNT64_Align032(Matrix.total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL) Matrix.pi = iccMallocUNT64_Align032(Matrix.total);

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(Matrix);
//COMMON-CODE UNT64  STOP.
}

iccMatrixFLT32_t iccMatrixInitFLT32(CCHAR *name, FLT32 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE FLT32 START.
  INT32 ii;
  va_list argptr;
  iccMatrixFLT32_t Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    icc_ERROR_MESSAGE("MATRIX NAME TOO LONG");
    return(Matrix);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    icc_ERROR_MESSAGE("BAD REAL_MATRIX VALUE");
    return(Matrix);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  Matrix.ndim = ndim;

  Matrix.dim = iccMallocINT32_Align032(ndim);

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  Matrix.total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    Matrix.dim[ii] = va_arg(argptr, INT32);
    Matrix.total = Matrix.total*Matrix.dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  Matrix.pr = iccMallocFLT32_Align032(Matrix.total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL) Matrix.pi = iccMallocFLT32_Align032(Matrix.total);

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(Matrix);
//COMMON-CODE FLT32  STOP.
}

iccMatrixFLT64_t iccMatrixInitFLT64(CCHAR *name, FLT64 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE FLT64 START.
  INT32 ii;
  va_list argptr;
  iccMatrixFLT64_t Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    icc_ERROR_MESSAGE("MATRIX NAME TOO LONG");
    return(Matrix);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    icc_ERROR_MESSAGE("BAD REAL_MATRIX VALUE");
    return(Matrix);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  Matrix.ndim = ndim;

  Matrix.dim = iccMallocINT32_Align032(ndim);

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  Matrix.total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    Matrix.dim[ii] = va_arg(argptr, INT32);
    Matrix.total = Matrix.total*Matrix.dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  Matrix.pr = iccMallocFLT64_Align032(Matrix.total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL) Matrix.pi = iccMallocFLT64_Align032(Matrix.total);

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(Matrix);
//COMMON-CODE FLT64  STOP.
}

iccMatrixFLT96_t iccMatrixInitFLT96(CCHAR *name, FLT96 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE FLT96 START.
  INT32 ii;
  va_list argptr;
  iccMatrixFLT96_t Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    icc_ERROR_MESSAGE("MATRIX NAME TOO LONG");
    return(Matrix);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    icc_ERROR_MESSAGE("BAD REAL_MATRIX VALUE");
    return(Matrix);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  Matrix.ndim = ndim;

  Matrix.dim = iccMallocINT32_Align032(ndim);

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  Matrix.total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    Matrix.dim[ii] = va_arg(argptr, INT32);
    Matrix.total = Matrix.total*Matrix.dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  Matrix.pr = iccMallocFLT96_Align032(Matrix.total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL) Matrix.pi = iccMallocFLT96_Align032(Matrix.total);

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(Matrix);
//COMMON-CODE FLT96  STOP.
}



/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
