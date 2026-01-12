/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccMatrixInit.c
// Desc: This file contains the code for the iccMatrixInit routine.
// Hist: When       Who  What
//       05/30/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "matrix_utils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS  va_list argptr;
PERL_PREPROCESS  iccMatrixXXXXX_t *p2Matrix;
PERL_PREPROCESS
PERL_PREPROCESS  // Check name length.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if( strlen(name) > icc_MATRIX_NAME_SIZE )
PERL_PREPROCESS  {
PERL_PREPROCESS    XMC_ERROR_STDOUT("MATRIX NAME TOO LONG");
PERL_PREPROCESS    return(NULL);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Check real or imaginary flag.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if( (realMatrix != 1) && (realMatrix != 0)  )
PERL_PREPROCESS  {
PERL_PREPROCESS    XMC_ERROR_STDOUT("BAD REAL_MATRIX VALUE");
PERL_PREPROCESS    return(NULL);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Allocate memory for the matrix.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  p2Matrix = (iccMatrixXXXXX_t *) iccMallocVOID_Align032(sizeof(iccMatrixXXXXX_t));
PERL_PREPROCESS  if(p2Matrix==NULL)
PERL_PREPROCESS  {
PERL_PREPROCESS    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
PERL_PREPROCESS    return(NULL);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the Matrix dimensions.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  p2Matrix->ndim = ndim;
PERL_PREPROCESS
PERL_PREPROCESS  if(p2Matrix->ndim > icc_MATRIX_NDIM)
PERL_PREPROCESS  {
PERL_PREPROCESS    printf("To many dimesions.  Only allowed %d.\n", icc_MATRIX_NDIM);
PERL_PREPROCESS    XMC_ERROR_STDOUT("To many dimesions.");
PERL_PREPROCESS    return(NULL);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Get the dimensions of the matrix.  Start the variable arguments.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  p2Matrix->total = 1;
PERL_PREPROCESS  va_start(argptr, ndim);
PERL_PREPROCESS  for(ii = 0; ii < ndim; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    p2Matrix->dim[ii] = va_arg(argptr, UNT32);
PERL_PREPROCESS    p2Matrix->total = p2Matrix->total*p2Matrix->dim[ii];
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the real pointer.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  p2Matrix->pr = iccMallocXXXXX_Align032(p2Matrix->total);
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the imag pointer (if complex(CPLX)).
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if(realMatrix != REAL)
PERL_PREPROCESS  {
PERL_PREPROCESS    p2Matrix->cplx = TRUE;
PERL_PREPROCESS    p2Matrix->pi = iccMallocXXXXX_Align032(p2Matrix->total);
PERL_PREPROCESS  }
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
iccMatrixINT08_t *iccMatrixInitINT08(CCHAR *name, INT08 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE INT08     START.
  UNT32 ii;
  va_list argptr;
  iccMatrixINT08_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    XMC_ERROR_STDOUT("MATRIX NAME TOO LONG");
    return(NULL);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    XMC_ERROR_STDOUT("BAD REAL_MATRIX VALUE");
    return(NULL);
  }

  // Allocate memory for the matrix.
  //----------------------------------------------------------------------------
  p2Matrix = (iccMatrixINT08_t *) iccMallocVOID_Align032(sizeof(iccMatrixINT08_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > icc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", icc_MATRIX_NDIM);
    XMC_ERROR_STDOUT("To many dimesions.");
    return(NULL);
  }

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  p2Matrix->total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    p2Matrix->dim[ii] = va_arg(argptr, UNT32);
    p2Matrix->total = p2Matrix->total*p2Matrix->dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  p2Matrix->pr = iccMallocINT08_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = iccMallocINT08_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE INT08      STOP.
}

iccMatrixINT16_t *iccMatrixInitINT16(CCHAR *name, INT16 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE INT16     START.
  UNT32 ii;
  va_list argptr;
  iccMatrixINT16_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    XMC_ERROR_STDOUT("MATRIX NAME TOO LONG");
    return(NULL);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    XMC_ERROR_STDOUT("BAD REAL_MATRIX VALUE");
    return(NULL);
  }

  // Allocate memory for the matrix.
  //----------------------------------------------------------------------------
  p2Matrix = (iccMatrixINT16_t *) iccMallocVOID_Align032(sizeof(iccMatrixINT16_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > icc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", icc_MATRIX_NDIM);
    XMC_ERROR_STDOUT("To many dimesions.");
    return(NULL);
  }

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  p2Matrix->total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    p2Matrix->dim[ii] = va_arg(argptr, UNT32);
    p2Matrix->total = p2Matrix->total*p2Matrix->dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  p2Matrix->pr = iccMallocINT16_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = iccMallocINT16_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE INT16      STOP.
}

iccMatrixINT32_t *iccMatrixInitINT32(CCHAR *name, INT32 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE INT32     START.
  UNT32 ii;
  va_list argptr;
  iccMatrixINT32_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    XMC_ERROR_STDOUT("MATRIX NAME TOO LONG");
    return(NULL);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    XMC_ERROR_STDOUT("BAD REAL_MATRIX VALUE");
    return(NULL);
  }

  // Allocate memory for the matrix.
  //----------------------------------------------------------------------------
  p2Matrix = (iccMatrixINT32_t *) iccMallocVOID_Align032(sizeof(iccMatrixINT32_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > icc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", icc_MATRIX_NDIM);
    XMC_ERROR_STDOUT("To many dimesions.");
    return(NULL);
  }

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  p2Matrix->total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    p2Matrix->dim[ii] = va_arg(argptr, UNT32);
    p2Matrix->total = p2Matrix->total*p2Matrix->dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  p2Matrix->pr = iccMallocINT32_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = iccMallocINT32_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE INT32      STOP.
}

iccMatrixINT64_t *iccMatrixInitINT64(CCHAR *name, INT64 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE INT64     START.
  UNT32 ii;
  va_list argptr;
  iccMatrixINT64_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    XMC_ERROR_STDOUT("MATRIX NAME TOO LONG");
    return(NULL);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    XMC_ERROR_STDOUT("BAD REAL_MATRIX VALUE");
    return(NULL);
  }

  // Allocate memory for the matrix.
  //----------------------------------------------------------------------------
  p2Matrix = (iccMatrixINT64_t *) iccMallocVOID_Align032(sizeof(iccMatrixINT64_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > icc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", icc_MATRIX_NDIM);
    XMC_ERROR_STDOUT("To many dimesions.");
    return(NULL);
  }

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  p2Matrix->total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    p2Matrix->dim[ii] = va_arg(argptr, UNT32);
    p2Matrix->total = p2Matrix->total*p2Matrix->dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  p2Matrix->pr = iccMallocINT64_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = iccMallocINT64_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE INT64      STOP.
}

iccMatrixUNT08_t *iccMatrixInitUNT08(CCHAR *name, UNT08 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE UNT08     START.
  UNT32 ii;
  va_list argptr;
  iccMatrixUNT08_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    XMC_ERROR_STDOUT("MATRIX NAME TOO LONG");
    return(NULL);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    XMC_ERROR_STDOUT("BAD REAL_MATRIX VALUE");
    return(NULL);
  }

  // Allocate memory for the matrix.
  //----------------------------------------------------------------------------
  p2Matrix = (iccMatrixUNT08_t *) iccMallocVOID_Align032(sizeof(iccMatrixUNT08_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > icc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", icc_MATRIX_NDIM);
    XMC_ERROR_STDOUT("To many dimesions.");
    return(NULL);
  }

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  p2Matrix->total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    p2Matrix->dim[ii] = va_arg(argptr, UNT32);
    p2Matrix->total = p2Matrix->total*p2Matrix->dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  p2Matrix->pr = iccMallocUNT08_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = iccMallocUNT08_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE UNT08      STOP.
}

iccMatrixUNT16_t *iccMatrixInitUNT16(CCHAR *name, UNT16 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE UNT16     START.
  UNT32 ii;
  va_list argptr;
  iccMatrixUNT16_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    XMC_ERROR_STDOUT("MATRIX NAME TOO LONG");
    return(NULL);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    XMC_ERROR_STDOUT("BAD REAL_MATRIX VALUE");
    return(NULL);
  }

  // Allocate memory for the matrix.
  //----------------------------------------------------------------------------
  p2Matrix = (iccMatrixUNT16_t *) iccMallocVOID_Align032(sizeof(iccMatrixUNT16_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > icc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", icc_MATRIX_NDIM);
    XMC_ERROR_STDOUT("To many dimesions.");
    return(NULL);
  }

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  p2Matrix->total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    p2Matrix->dim[ii] = va_arg(argptr, UNT32);
    p2Matrix->total = p2Matrix->total*p2Matrix->dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  p2Matrix->pr = iccMallocUNT16_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = iccMallocUNT16_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE UNT16      STOP.
}

iccMatrixUNT32_t *iccMatrixInitUNT32(CCHAR *name, UNT32 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE UNT32     START.
  UNT32 ii;
  va_list argptr;
  iccMatrixUNT32_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    XMC_ERROR_STDOUT("MATRIX NAME TOO LONG");
    return(NULL);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    XMC_ERROR_STDOUT("BAD REAL_MATRIX VALUE");
    return(NULL);
  }

  // Allocate memory for the matrix.
  //----------------------------------------------------------------------------
  p2Matrix = (iccMatrixUNT32_t *) iccMallocVOID_Align032(sizeof(iccMatrixUNT32_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > icc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", icc_MATRIX_NDIM);
    XMC_ERROR_STDOUT("To many dimesions.");
    return(NULL);
  }

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  p2Matrix->total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    p2Matrix->dim[ii] = va_arg(argptr, UNT32);
    p2Matrix->total = p2Matrix->total*p2Matrix->dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  p2Matrix->pr = iccMallocUNT32_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = iccMallocUNT32_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE UNT32      STOP.
}

iccMatrixUNT64_t *iccMatrixInitUNT64(CCHAR *name, UNT64 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE UNT64     START.
  UNT32 ii;
  va_list argptr;
  iccMatrixUNT64_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    XMC_ERROR_STDOUT("MATRIX NAME TOO LONG");
    return(NULL);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    XMC_ERROR_STDOUT("BAD REAL_MATRIX VALUE");
    return(NULL);
  }

  // Allocate memory for the matrix.
  //----------------------------------------------------------------------------
  p2Matrix = (iccMatrixUNT64_t *) iccMallocVOID_Align032(sizeof(iccMatrixUNT64_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > icc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", icc_MATRIX_NDIM);
    XMC_ERROR_STDOUT("To many dimesions.");
    return(NULL);
  }

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  p2Matrix->total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    p2Matrix->dim[ii] = va_arg(argptr, UNT32);
    p2Matrix->total = p2Matrix->total*p2Matrix->dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  p2Matrix->pr = iccMallocUNT64_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = iccMallocUNT64_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE UNT64      STOP.
}

iccMatrixFLT32_t *iccMatrixInitFLT32(CCHAR *name, FLT32 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE FLT32     START.
  UNT32 ii;
  va_list argptr;
  iccMatrixFLT32_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    XMC_ERROR_STDOUT("MATRIX NAME TOO LONG");
    return(NULL);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    XMC_ERROR_STDOUT("BAD REAL_MATRIX VALUE");
    return(NULL);
  }

  // Allocate memory for the matrix.
  //----------------------------------------------------------------------------
  p2Matrix = (iccMatrixFLT32_t *) iccMallocVOID_Align032(sizeof(iccMatrixFLT32_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > icc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", icc_MATRIX_NDIM);
    XMC_ERROR_STDOUT("To many dimesions.");
    return(NULL);
  }

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  p2Matrix->total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    p2Matrix->dim[ii] = va_arg(argptr, UNT32);
    p2Matrix->total = p2Matrix->total*p2Matrix->dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  p2Matrix->pr = iccMallocFLT32_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = iccMallocFLT32_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE FLT32      STOP.
}

iccMatrixFLT64_t *iccMatrixInitFLT64(CCHAR *name, FLT64 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE FLT64     START.
  UNT32 ii;
  va_list argptr;
  iccMatrixFLT64_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    XMC_ERROR_STDOUT("MATRIX NAME TOO LONG");
    return(NULL);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    XMC_ERROR_STDOUT("BAD REAL_MATRIX VALUE");
    return(NULL);
  }

  // Allocate memory for the matrix.
  //----------------------------------------------------------------------------
  p2Matrix = (iccMatrixFLT64_t *) iccMallocVOID_Align032(sizeof(iccMatrixFLT64_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > icc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", icc_MATRIX_NDIM);
    XMC_ERROR_STDOUT("To many dimesions.");
    return(NULL);
  }

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  p2Matrix->total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    p2Matrix->dim[ii] = va_arg(argptr, UNT32);
    p2Matrix->total = p2Matrix->total*p2Matrix->dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  p2Matrix->pr = iccMallocFLT64_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = iccMallocFLT64_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE FLT64      STOP.
}

iccMatrixFLT96_t *iccMatrixInitFLT96(CCHAR *name, FLT96 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE FLT96     START.
  UNT32 ii;
  va_list argptr;
  iccMatrixFLT96_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > icc_MATRIX_NAME_SIZE )
  {
    XMC_ERROR_STDOUT("MATRIX NAME TOO LONG");
    return(NULL);
  }

  // Check real or imaginary flag.
  //----------------------------------------------------------------------------
  if( (realMatrix != 1) && (realMatrix != 0)  )
  {
    XMC_ERROR_STDOUT("BAD REAL_MATRIX VALUE");
    return(NULL);
  }

  // Allocate memory for the matrix.
  //----------------------------------------------------------------------------
  p2Matrix = (iccMatrixFLT96_t *) iccMallocVOID_Align032(sizeof(iccMatrixFLT96_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > icc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", icc_MATRIX_NDIM);
    XMC_ERROR_STDOUT("To many dimesions.");
    return(NULL);
  }

  // Get the dimensions of the matrix.  Start the variable arguments.
  //----------------------------------------------------------------------------
  p2Matrix->total = 1;
  va_start(argptr, ndim);
  for(ii = 0; ii < ndim; ii++)
  {
    p2Matrix->dim[ii] = va_arg(argptr, UNT32);
    p2Matrix->total = p2Matrix->total*p2Matrix->dim[ii];
  }

  // Malloc the memory for the real pointer.
  //----------------------------------------------------------------------------
  p2Matrix->pr = iccMallocFLT96_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = iccMallocFLT96_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE FLT96      STOP.
}



/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
