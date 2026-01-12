/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccHandleHistory.c
// Desc: This file contains the code for the handle history routines.
// Hist: When       Who  What
//       08/16/2002 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "dsp_utils.h" 
 
/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define COMMON_CODE INT32 ii;\
                    for(ii = 0; ii < histSize; ii++) new[ii] = hist[ii];\
                    for(ii = 0; ii < dataSize; ii++) new[ii+histSize] = data[ii];\
                    for(ii = 0; ii < histSize; ii++) hist[ii] = data[dataSize-histSize+ii];

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID handleHistoryFLT32(FLT32 *data, INT32 dataSize, FLT32 *hist, INT32 histSize, FLT32 *new)
{
  COMMON_CODE
}

VOID handleHistoryFLT64(FLT64 *data, INT32 dataSize, FLT64 *hist, INT32 histSize, FLT64 *new)
{
  COMMON_CODE
}

VOID handleHistoryFLT96(FLT96 *data, INT32 dataSize, FLT96 *hist, INT32 histSize, FLT96 *new)
{
  COMMON_CODE
}

VOID handleHistoryINT08(INT08 *data, INT32 dataSize, INT08 *hist, INT32 histSize, INT08 *new)
{
  COMMON_CODE
}

VOID handleHistoryINT16(INT16 *data, INT32 dataSize, INT16 *hist, INT32 histSize, INT16 *new)
{
  COMMON_CODE
}

VOID handleHistoryINT32(INT32 *data, INT32 dataSize, INT32 *hist, INT32 histSize, INT32 *new)
{
  COMMON_CODE
}

VOID handleHistoryINT64(INT64 *data, INT32 dataSize, INT64 *hist, INT32 histSize, INT64 *new)
{
  COMMON_CODE
}

VOID handleHistoryUNT08(UNT08 *data, INT32 dataSize, UNT08 *hist, INT32 histSize, UNT08 *new)
{
  COMMON_CODE
}

VOID handleHistoryUNT16(UNT16 *data, INT32 dataSize, UNT16 *hist, INT32 histSize, UNT16 *new)
{
  COMMON_CODE
}

VOID handleHistoryUNT32(UNT32 *data, INT32 dataSize, UNT32 *hist, INT32 histSize, UNT32 *new)
{
  COMMON_CODE
}

VOID handleHistoryUNT64(UNT64 *data, INT32 dataSize, UNT64 *hist, INT32 histSize, UNT64 *new)
{
  COMMON_CODE
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
