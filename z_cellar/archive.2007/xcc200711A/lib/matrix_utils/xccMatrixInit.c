/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccMatrixInit.c
// Desc: This file contains the code for the xccMatrixInit routine.
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
PERL_PREPROCESS  xccMatrixXXXXX_t *p2Matrix;
PERL_PREPROCESS
PERL_PREPROCESS  // Check name length.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if( strlen(name) > xcc_MATRIX_NAME_SIZE )
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
PERL_PREPROCESS  p2Matrix = (xccMatrixXXXXX_t *) xccMallocVOID_Align032(sizeof(xccMatrixXXXXX_t));
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
PERL_PREPROCESS  if(p2Matrix->ndim > xcc_MATRIX_NDIM)
PERL_PREPROCESS  {
PERL_PREPROCESS    printf("To many dimesions.  Only allowed %d.\n", xcc_MATRIX_NDIM);
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
PERL_PREPROCESS  p2Matrix->pr = xccMallocXXXXX_Align032(p2Matrix->total);
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the imag pointer (if complex(CPLX)).
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if(realMatrix != REAL)
PERL_PREPROCESS  {
PERL_PREPROCESS    p2Matrix->cplx = TRUE;
PERL_PREPROCESS    p2Matrix->pi = xccMallocXXXXX_Align032(p2Matrix->total);
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
xccMatrixINT08_t *xccMatrixInitINT08(CCHAR *name, INT08 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE INT08     START.
  UNT32 ii;
  va_list argptr;
  xccMatrixINT08_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > xcc_MATRIX_NAME_SIZE )
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
  p2Matrix = (xccMatrixINT08_t *) xccMallocVOID_Align032(sizeof(xccMatrixINT08_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > xcc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", xcc_MATRIX_NDIM);
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
  p2Matrix->pr = xccMallocINT08_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = xccMallocINT08_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE INT08      STOP.
}

xccMatrixINT16_t *xccMatrixInitINT16(CCHAR *name, INT16 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE INT16     START.
  UNT32 ii;
  va_list argptr;
  xccMatrixINT16_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > xcc_MATRIX_NAME_SIZE )
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
  p2Matrix = (xccMatrixINT16_t *) xccMallocVOID_Align032(sizeof(xccMatrixINT16_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > xcc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", xcc_MATRIX_NDIM);
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
  p2Matrix->pr = xccMallocINT16_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = xccMallocINT16_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE INT16      STOP.
}

xccMatrixINT32_t *xccMatrixInitINT32(CCHAR *name, INT32 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE INT32     START.
  UNT32 ii;
  va_list argptr;
  xccMatrixINT32_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > xcc_MATRIX_NAME_SIZE )
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
  p2Matrix = (xccMatrixINT32_t *) xccMallocVOID_Align032(sizeof(xccMatrixINT32_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > xcc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", xcc_MATRIX_NDIM);
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
  p2Matrix->pr = xccMallocINT32_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = xccMallocINT32_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE INT32      STOP.
}

xccMatrixINT64_t *xccMatrixInitINT64(CCHAR *name, INT64 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE INT64     START.
  UNT32 ii;
  va_list argptr;
  xccMatrixINT64_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > xcc_MATRIX_NAME_SIZE )
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
  p2Matrix = (xccMatrixINT64_t *) xccMallocVOID_Align032(sizeof(xccMatrixINT64_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > xcc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", xcc_MATRIX_NDIM);
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
  p2Matrix->pr = xccMallocINT64_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = xccMallocINT64_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE INT64      STOP.
}

xccMatrixUNT08_t *xccMatrixInitUNT08(CCHAR *name, UNT08 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE UNT08     START.
  UNT32 ii;
  va_list argptr;
  xccMatrixUNT08_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > xcc_MATRIX_NAME_SIZE )
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
  p2Matrix = (xccMatrixUNT08_t *) xccMallocVOID_Align032(sizeof(xccMatrixUNT08_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > xcc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", xcc_MATRIX_NDIM);
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
  p2Matrix->pr = xccMallocUNT08_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = xccMallocUNT08_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE UNT08      STOP.
}

xccMatrixUNT16_t *xccMatrixInitUNT16(CCHAR *name, UNT16 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE UNT16     START.
  UNT32 ii;
  va_list argptr;
  xccMatrixUNT16_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > xcc_MATRIX_NAME_SIZE )
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
  p2Matrix = (xccMatrixUNT16_t *) xccMallocVOID_Align032(sizeof(xccMatrixUNT16_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > xcc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", xcc_MATRIX_NDIM);
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
  p2Matrix->pr = xccMallocUNT16_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = xccMallocUNT16_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE UNT16      STOP.
}

xccMatrixUNT32_t *xccMatrixInitUNT32(CCHAR *name, UNT32 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE UNT32     START.
  UNT32 ii;
  va_list argptr;
  xccMatrixUNT32_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > xcc_MATRIX_NAME_SIZE )
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
  p2Matrix = (xccMatrixUNT32_t *) xccMallocVOID_Align032(sizeof(xccMatrixUNT32_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > xcc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", xcc_MATRIX_NDIM);
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
  p2Matrix->pr = xccMallocUNT32_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = xccMallocUNT32_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE UNT32      STOP.
}

xccMatrixUNT64_t *xccMatrixInitUNT64(CCHAR *name, UNT64 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE UNT64     START.
  UNT32 ii;
  va_list argptr;
  xccMatrixUNT64_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > xcc_MATRIX_NAME_SIZE )
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
  p2Matrix = (xccMatrixUNT64_t *) xccMallocVOID_Align032(sizeof(xccMatrixUNT64_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > xcc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", xcc_MATRIX_NDIM);
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
  p2Matrix->pr = xccMallocUNT64_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = xccMallocUNT64_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE UNT64      STOP.
}

xccMatrixFLT32_t *xccMatrixInitFLT32(CCHAR *name, FLT32 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE FLT32     START.
  UNT32 ii;
  va_list argptr;
  xccMatrixFLT32_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > xcc_MATRIX_NAME_SIZE )
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
  p2Matrix = (xccMatrixFLT32_t *) xccMallocVOID_Align032(sizeof(xccMatrixFLT32_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > xcc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", xcc_MATRIX_NDIM);
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
  p2Matrix->pr = xccMallocFLT32_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = xccMallocFLT32_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE FLT32      STOP.
}

xccMatrixFLT64_t *xccMatrixInitFLT64(CCHAR *name, FLT64 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE FLT64     START.
  UNT32 ii;
  va_list argptr;
  xccMatrixFLT64_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > xcc_MATRIX_NAME_SIZE )
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
  p2Matrix = (xccMatrixFLT64_t *) xccMallocVOID_Align032(sizeof(xccMatrixFLT64_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > xcc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", xcc_MATRIX_NDIM);
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
  p2Matrix->pr = xccMallocFLT64_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = xccMallocFLT64_Align032(p2Matrix->total);
  }

  // Shutdown variable arguments and return the Matrix.
  //----------------------------------------------------------------------------
  va_end(argptr);
  return(p2Matrix);
//COMMON-CODE FLT64      STOP.
}

xccMatrixFLT96_t *xccMatrixInitFLT96(CCHAR *name, FLT96 realMatrix, INT32 ndim, ...)
{
//COMMON-CODE FLT96     START.
  UNT32 ii;
  va_list argptr;
  xccMatrixFLT96_t *p2Matrix;

  // Check name length.
  //----------------------------------------------------------------------------
  if( strlen(name) > xcc_MATRIX_NAME_SIZE )
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
  p2Matrix = (xccMatrixFLT96_t *) xccMallocVOID_Align032(sizeof(xccMatrixFLT96_t));
  if(p2Matrix==NULL)
  {
    XMC_ERROR_STDOUT("Could not allocate memory for Matrix.");
    return(NULL);
  }

  // Malloc the memory for the Matrix dimensions.
  //----------------------------------------------------------------------------
  p2Matrix->ndim = ndim;

  if(p2Matrix->ndim > xcc_MATRIX_NDIM)
  {
    printf("To many dimesions.  Only allowed %d.\n", xcc_MATRIX_NDIM);
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
  p2Matrix->pr = xccMallocFLT96_Align032(p2Matrix->total);

  // Malloc the memory for the imag pointer (if complex(CPLX)).
  //----------------------------------------------------------------------------
  if(realMatrix != REAL)
  {
    p2Matrix->cplx = TRUE;
    p2Matrix->pi = xccMallocFLT96_Align032(p2Matrix->total);
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
