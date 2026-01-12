/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccStackSort.c
// Desc: This file contains the code for the iccStackSort routines.
// Hist: When       Who  What
//       05/01/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "stack_utils.h" 
 
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

VOID iccStackSortFLT32( iccStackFLT32_t *p2Stack )
{
  iccvQuickSortFLT32(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortFLT64( iccStackFLT64_t *p2Stack )
{
  iccvQuickSortFLT64(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortFLT96( iccStackFLT96_t *p2Stack )
{
  iccvQuickSortFLT96(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortINT08( iccStackINT08_t *p2Stack )
{
  iccvQuickSortINT08(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortINT16( iccStackINT16_t *p2Stack )
{
  iccvQuickSortINT16(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortINT32( iccStackINT32_t *p2Stack )
{
  iccvQuickSortINT32(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID iccStackSortINT64( iccStackINT64_t *p2Stack )
{
  iccvQuickSortINT64(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID iccStackSortUNT08( iccStackUNT08_t *p2Stack )
{
  iccvQuickSortUNT08(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID iccStackSortUNT16( iccStackUNT16_t *p2Stack )
{
  iccvQuickSortUNT16(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortUNT32( iccStackUNT32_t *p2Stack )
{
  iccvQuickSortUNT32(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortUNT64( iccStackUNT64_t *p2Stack )
{
  iccvQuickSortUNT64(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortCFLT32( iccStackCFLT32_t *p2Stack )
{
  iccvQuickSortCFLT32r(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortCFLT64( iccStackCFLT64_t *p2Stack )
{
  iccvQuickSortCFLT64r(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortCFLT96( iccStackCFLT96_t *p2Stack )
{
  iccvQuickSortCFLT96r(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortCINT08( iccStackCINT08_t *p2Stack )
{
  iccvQuickSortCINT08r(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortCINT16( iccStackCINT16_t *p2Stack )
{
  iccvQuickSortCINT16r(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortCINT32( iccStackCINT32_t *p2Stack )
{
  iccvQuickSortCINT32r(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID iccStackSortCINT64( iccStackCINT64_t *p2Stack )
{
  iccvQuickSortCINT64r(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID iccStackSortCUNT08( iccStackCUNT08_t *p2Stack )
{
  iccvQuickSortCUNT08r(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID iccStackSortCUNT16( iccStackCUNT16_t *p2Stack )
{
  iccvQuickSortCUNT16r(p2Stack->theStack, 0, p2Stack->index);
}

 
VOID iccStackSortCUNT32( iccStackCUNT32_t *p2Stack )
{
  iccvQuickSortCUNT32r(p2Stack->theStack, 0, p2Stack->index);
}

 
VOID iccStackSortCUNT64( iccStackCUNT64_t *p2Stack )
{
  iccvQuickSortCUNT64r(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortVFLT32( iccStackVFLT32_t *p2Stack )
{
  //iccvQuickSortVFLT32(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortVFLT64( iccStackVFLT64_t *p2Stack )
{
  //iccvQuickSortVFLT64(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortVFLT96( iccStackVFLT96_t *p2Stack )
{
  //iccvQuickSortVFLT96(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortVINT08( iccStackVINT08_t *p2Stack )
{
  //iccvQuickSortVINT08(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortVINT16( iccStackVINT16_t *p2Stack )
{
  //iccvQuickSortVINT16(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortVINT32( iccStackVINT32_t *p2Stack )
{
  //iccvQuickSortVINT32(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID iccStackSortVINT64( iccStackVINT64_t *p2Stack )
{
  //iccvQuickSortVINT64(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID iccStackSortVUNT08( iccStackVUNT08_t *p2Stack )
{
  //iccvQuickSortVUNT08(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID iccStackSortVUNT16( iccStackVUNT16_t *p2Stack )
{
  //iccvQuickSortVUNT16(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortVUNT32( iccStackVUNT32_t *p2Stack )
{
  //iccvQuickSortVUNT32(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStackSortVUNT64( iccStackVUNT64_t *p2Stack )
{
  //iccvQuickSortVUNT64(p2Stack->theStack, 0, p2Stack->index);
}

VOID iccStringStackSort( iccStackVOIDP_t *p2Stack )
{
  iccvQuickSortString( (CHR08 **) p2Stack->theStack, 0, p2Stack->index);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
