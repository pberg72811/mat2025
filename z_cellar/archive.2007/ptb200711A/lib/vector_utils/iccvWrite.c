/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvWrite.c
// Desc: This file contains the code for the vectorUtils routine iccvWrite.
// Hist: When       Who  What
//       05/14/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "vector_utils.h" 
 
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
INT32 iccvWriteFLT32(FILE *fid, FLT32 *data, UNT32 n)
{
  INT32 amountWritten;
  amountWritten = fread(data, sizeof(FLT32), n, fid);
  return(amountWritten);
}

INT32 iccvWriteFLT64(FILE *fid, FLT64 *data, UNT32 n)
{
  INT32 amountWritten;
  amountWritten = fread(data, sizeof(FLT64), n, fid);
  return(amountWritten);
}

INT32 iccvWriteFLT96(FILE *fid, FLT96 *data, UNT32 n)
{
  INT32 amountWritten;
  amountWritten = fread(data, sizeof(FLT96), n, fid);
  return(amountWritten);
}

INT32 iccvWriteINT08(FILE *fid, INT08 *data, UNT32 n)
{
  INT32 amountWritten;
  amountWritten = fread(data, sizeof(INT08), n, fid);
  return(amountWritten);
}

INT32 iccvWriteINT16(FILE *fid, INT16 *data, UNT32 n)
{
  INT32 amountWritten;
  amountWritten = fread(data, sizeof(INT16), n, fid);
  return(amountWritten);
}

INT32 iccvWriteINT32(FILE *fid, INT32 *data, UNT32 n)
{
  INT32 amountWritten;
  amountWritten = fread(data, sizeof(INT32), n, fid);
  return(amountWritten);
}

INT32 iccvWriteINT64(FILE *fid, INT64 *data, UNT32 n)
{
  INT32 amountWritten;
  amountWritten = fread(data, sizeof(INT32), n, fid);
  return(amountWritten);
}

INT32 iccvWriteUNT08(FILE *fid, UNT08 *data, UNT32 n)
{
  INT32 amountWritten;
  amountWritten = fread(data, sizeof(UNT08), n, fid);
  return(amountWritten);
}

INT32 iccvWriteUNT16(FILE *fid, UNT16 *data, UNT32 n)
{
  INT32 amountWritten;
  amountWritten = fread(data, sizeof(UNT16), n, fid);
  return(amountWritten);
}

INT32 iccvWriteUNT32(FILE *fid, UNT32 *data, UNT32 n)
{
  INT32 amountWritten;
  amountWritten = fread(data, sizeof(UNT32), n, fid);
  return(amountWritten);
}

INT32 iccvWriteUNT64(FILE *fid, UNT64 *data, UNT32 n)
{
  INT32 amountWritten;
  amountWritten = fread(data, sizeof(UNT32), n, fid);
  return(amountWritten);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
