/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccStackSort.c
// Desc: This file contains the code for the xccStackSort routines.
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

VOID xccStackSortFLT32( xccStackFLT32_t *p2Stack )
{
  xccvQuickSortFLT32(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortFLT64( xccStackFLT64_t *p2Stack )
{
  xccvQuickSortFLT64(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortFLT96( xccStackFLT96_t *p2Stack )
{
  xccvQuickSortFLT96(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortINT08( xccStackINT08_t *p2Stack )
{
  xccvQuickSortINT08(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortINT16( xccStackINT16_t *p2Stack )
{
  xccvQuickSortINT16(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortINT32( xccStackINT32_t *p2Stack )
{
  xccvQuickSortINT32(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID xccStackSortINT64( xccStackINT64_t *p2Stack )
{
  xccvQuickSortINT64(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID xccStackSortUNT08( xccStackUNT08_t *p2Stack )
{
  xccvQuickSortUNT08(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID xccStackSortUNT16( xccStackUNT16_t *p2Stack )
{
  xccvQuickSortUNT16(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortUNT32( xccStackUNT32_t *p2Stack )
{
  xccvQuickSortUNT32(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortUNT64( xccStackUNT64_t *p2Stack )
{
  xccvQuickSortUNT64(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortCFLT32( xccStackCFLT32_t *p2Stack )
{
  xccvQuickSortCFLT32r(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortCFLT64( xccStackCFLT64_t *p2Stack )
{
  xccvQuickSortCFLT64r(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortCFLT96( xccStackCFLT96_t *p2Stack )
{
  xccvQuickSortCFLT96r(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortCINT08( xccStackCINT08_t *p2Stack )
{
  xccvQuickSortCINT08r(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortCINT16( xccStackCINT16_t *p2Stack )
{
  xccvQuickSortCINT16r(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortCINT32( xccStackCINT32_t *p2Stack )
{
  xccvQuickSortCINT32r(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID xccStackSortCINT64( xccStackCINT64_t *p2Stack )
{
  xccvQuickSortCINT64r(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID xccStackSortCUNT08( xccStackCUNT08_t *p2Stack )
{
  xccvQuickSortCUNT08r(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID xccStackSortCUNT16( xccStackCUNT16_t *p2Stack )
{
  xccvQuickSortCUNT16r(p2Stack->theStack, 0, p2Stack->index);
}

 
VOID xccStackSortCUNT32( xccStackCUNT32_t *p2Stack )
{
  xccvQuickSortCUNT32r(p2Stack->theStack, 0, p2Stack->index);
}

 
VOID xccStackSortCUNT64( xccStackCUNT64_t *p2Stack )
{
  xccvQuickSortCUNT64r(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortVFLT32( xccStackVFLT32_t *p2Stack )
{
  //xccvQuickSortVFLT32(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortVFLT64( xccStackVFLT64_t *p2Stack )
{
  //xccvQuickSortVFLT64(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortVFLT96( xccStackVFLT96_t *p2Stack )
{
  //xccvQuickSortVFLT96(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortVINT08( xccStackVINT08_t *p2Stack )
{
  //xccvQuickSortVINT08(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortVINT16( xccStackVINT16_t *p2Stack )
{
  //xccvQuickSortVINT16(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortVINT32( xccStackVINT32_t *p2Stack )
{
  //xccvQuickSortVINT32(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID xccStackSortVINT64( xccStackVINT64_t *p2Stack )
{
  //xccvQuickSortVINT64(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID xccStackSortVUNT08( xccStackVUNT08_t *p2Stack )
{
  //xccvQuickSortVUNT08(p2Stack->theStack, 0, p2Stack->index);
}
 
VOID xccStackSortVUNT16( xccStackVUNT16_t *p2Stack )
{
  //xccvQuickSortVUNT16(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortVUNT32( xccStackVUNT32_t *p2Stack )
{
  //xccvQuickSortVUNT32(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStackSortVUNT64( xccStackVUNT64_t *p2Stack )
{
  //xccvQuickSortVUNT64(p2Stack->theStack, 0, p2Stack->index);
}

VOID xccStringStackSort( xccStackVOIDP_t *p2Stack )
{
  xccvQuickSortString( (CHR08 **) p2Stack->theStack, 0, p2Stack->index);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
