/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: archive_utils.h
// Desc: This is the header file for iccArchiveUtils.
// Hist: When       Who  What
//       10/19/2004 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef ARCHIVE_UTILS_H
#define ARCHIVE_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "xmc.h"
#include "malloc_utils.h"
#include "orbit_utils.h"
#include "stack_utils.h"
#include "string_utils.h"
#include "vector_utils.h"
#include <dirent.h>

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define ICCARCHIVE_STRING_SIZE 128

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
typedef struct
{
  UNT32 stackSize;
  CHR08 baseFileName[ICCARCHIVE_STRING_SIZE];
  CHR08 baseFileSuffix[ICCARCHIVE_STRING_SIZE];
  iccStackVOIDP_t *fileNameStack;
  UNT32 filesCycled;
  INT64 timeTag;
}iccArchiveSpec;

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
iccArchiveSpec *iccArchiveInit( const CHR08 *baseFileName, const CHR08 *baseFileSuffix, UNT32 stackSize );
VOID            iccArchiveTerm( iccArchiveSpec *spec );
CHR08          *iccArchiveProcess(iccArchiveSpec *spec);
CHR08          *iccArchiveProcessNonRT(iccArchiveSpec *spec, INT32 timeTag);
VOID            iccArchiveReestablish(iccArchiveSpec *spec);
VOID            iccArchiveDeleteOldest(iccArchiveSpec *spec);
VOID            iccArchiveRenameOldest(iccArchiveSpec *spec, const CHR08 *newFileName);
VOID            iccArchiveReport( iccArchiveSpec *spec );

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/
