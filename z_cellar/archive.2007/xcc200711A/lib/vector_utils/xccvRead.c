/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccvRead.c
// Desc: This file contains the code for the vectorUtils routine xccvRead.
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
INT32 xccvReadFLT32(FILE *fid, FLT32 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(FLT32), n, fid);
  return(amountRead);
}

INT32 xccvReadFLT64(FILE *fid, FLT64 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(FLT64), n, fid);
  return(amountRead);
}

INT32 xccvReadFLT96(FILE *fid, FLT96 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(FLT96), n, fid);
  return(amountRead);
}

INT32 xccvReadINT08(FILE *fid, INT08 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(INT08), n, fid);
  return(amountRead);
}

INT32 xccvReadINT16(FILE *fid, INT16 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(INT16), n, fid);
  return(amountRead);
}

INT32 xccvReadINT32(FILE *fid, INT32 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(INT32), n, fid);
  return(amountRead);
}

INT32 xccvReadINT64(FILE *fid, INT64 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(INT32), n, fid);
  return(amountRead);
}

INT32 xccvReadUNT08(FILE *fid, UNT08 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(UNT08), n, fid);
  return(amountRead);
}

INT32 xccvReadUNT16(FILE *fid, UNT16 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(UNT16), n, fid);
  return(amountRead);
}

INT32 xccvReadUNT32(FILE *fid, UNT32 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(UNT32), n, fid);
  return(amountRead);
}

INT32 xccvReadUNT64(FILE *fid, UNT64 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(UNT32), n, fid);
  return(amountRead);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
