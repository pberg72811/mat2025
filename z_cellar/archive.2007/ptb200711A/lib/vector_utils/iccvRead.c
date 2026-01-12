/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvRead.c
// Desc: This file contains the code for the vectorUtils routine iccvRead.
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
INT32 iccvReadFLT32(FILE *fid, FLT32 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(FLT32), n, fid);
  return(amountRead);
}

INT32 iccvReadFLT64(FILE *fid, FLT64 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(FLT64), n, fid);
  return(amountRead);
}

INT32 iccvReadFLT96(FILE *fid, FLT96 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(FLT96), n, fid);
  return(amountRead);
}

INT32 iccvReadINT08(FILE *fid, INT08 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(INT08), n, fid);
  return(amountRead);
}

INT32 iccvReadINT16(FILE *fid, INT16 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(INT16), n, fid);
  return(amountRead);
}

INT32 iccvReadINT32(FILE *fid, INT32 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(INT32), n, fid);
  return(amountRead);
}

INT32 iccvReadINT64(FILE *fid, INT64 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(INT32), n, fid);
  return(amountRead);
}

INT32 iccvReadUNT08(FILE *fid, UNT08 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(UNT08), n, fid);
  return(amountRead);
}

INT32 iccvReadUNT16(FILE *fid, UNT16 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(UNT16), n, fid);
  return(amountRead);
}

INT32 iccvReadUNT32(FILE *fid, UNT32 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(UNT32), n, fid);
  return(amountRead);
}

INT32 iccvReadUNT64(FILE *fid, UNT64 *data, UNT32 n)
{
  INT32 amountRead;
  amountRead = fread(data, sizeof(UNT32), n, fid);
  return(amountRead);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
