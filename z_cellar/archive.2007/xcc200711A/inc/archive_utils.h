/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: archive_utils.h
// Desc: This is the header file for xccArchiveUtils.
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
#define XCCARCHIVE_STRING_SIZE 128

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
typedef struct
{
  UNT32 stackSize;
  CHR08 baseFileName[XCCARCHIVE_STRING_SIZE];
  CHR08 baseFileSuffix[XCCARCHIVE_STRING_SIZE];
  xccStackVOIDP_t *fileNameStack;
  UNT32 filesCycled;
  INT64 timeTag;
}xccArchiveSpec;

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
xccArchiveSpec *xccArchiveInit( const CHR08 *baseFileName, const CHR08 *baseFileSuffix, UNT32 stackSize );
VOID            xccArchiveTerm( xccArchiveSpec *spec );
CHR08          *xccArchiveProcess(xccArchiveSpec *spec);
CHR08          *xccArchiveProcessNonRT(xccArchiveSpec *spec, INT32 timeTag);
VOID            xccArchiveReestablish(xccArchiveSpec *spec);
VOID            xccArchiveDeleteOldest(xccArchiveSpec *spec);
VOID            xccArchiveRenameOldest(xccArchiveSpec *spec, const CHR08 *newFileName);
VOID            xccArchiveReport( xccArchiveSpec *spec );

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/
