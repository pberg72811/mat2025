/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: stack_utils.h
// Desc: This is the header file for stack_utils.
// Hist: When       Who  What
//       04/27/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef STACK_UTILS_H
#define STACK_UTILS_H
 
#ifdef __cplusplus 
extern "C" { 
#endif 
 
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "xmc.h"
#include "vector_utils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define xcc_STACK_NAME_LENGTH 64
#define xcc_STACK_TYPE_LENGTH  8

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define COMMON_STACK_ELEMENTS  CHR08 name[xcc_STACK_NAME_LENGTH]; \
                               CHR08 type[xcc_STACK_TYPE_LENGTH]; \
                               UNT32 size;                        \
                               INT64 index;

typedef struct
{
  COMMON_STACK_ELEMENTS
  FLT32 *theStack;
} xccStackFLT32_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  FLT64 *theStack;
} xccStackFLT64_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  FLT96 *theStack;
} xccStackFLT96_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  INT08 *theStack;
} xccStackINT08_t;
 
typedef struct
{
  COMMON_STACK_ELEMENTS
  INT16 *theStack;
} xccStackINT16_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  INT32 *theStack;
} xccStackINT32_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  INT64 *theStack;
} xccStackINT64_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  UNT08 *theStack;
} xccStackUNT08_t;
 
typedef struct
{
  COMMON_STACK_ELEMENTS
  UNT16 *theStack;
} xccStackUNT16_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  UNT32 *theStack;
} xccStackUNT32_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  UNT64 *theStack;
} xccStackUNT64_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  VOID **theStack;
} xccStackVOIDP_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  CFLT32 *theStack;
} xccStackCFLT32_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  CFLT64 *theStack;
} xccStackCFLT64_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  CFLT96 *theStack;
} xccStackCFLT96_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  CINT08 *theStack;
} xccStackCINT08_t;
 
typedef struct
{
  COMMON_STACK_ELEMENTS
  CINT16 *theStack;
} xccStackCINT16_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  CINT32 *theStack;
} xccStackCINT32_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  CINT64 *theStack;
} xccStackCINT64_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  CUNT08 *theStack;
} xccStackCUNT08_t;
 
typedef struct
{
  COMMON_STACK_ELEMENTS
  CUNT16 *theStack;
} xccStackCUNT16_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  CUNT32 *theStack;
} xccStackCUNT32_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  CUNT64 *theStack;
} xccStackCUNT64_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  VFLT32 *theStack;
} xccStackVFLT32_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  VFLT64 *theStack;
} xccStackVFLT64_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  VFLT96 *theStack;
} xccStackVFLT96_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  VINT08 *theStack;
} xccStackVINT08_t;
 
typedef struct
{
  COMMON_STACK_ELEMENTS
  VINT16 *theStack;
} xccStackVINT16_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  VINT32 *theStack;
} xccStackVINT32_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  VINT64 *theStack;
} xccStackVINT64_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  VUNT08 *theStack;
} xccStackVUNT08_t;
 
typedef struct
{
  COMMON_STACK_ELEMENTS
  VUNT16 *theStack;
} xccStackVUNT16_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  VUNT32 *theStack;
} xccStackVUNT32_t;

typedef struct
{
  COMMON_STACK_ELEMENTS
  VUNT64 *theStack;
} xccStackVUNT64_t;

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

/* xccStackFull -------------------------------------------------------------*/
INT32 xccStackFullFLT32 ( xccStackFLT32_t  *p2Stack );
INT32 xccStackFullFLT64 ( xccStackFLT64_t  *p2Stack );
INT32 xccStackFullFLT96 ( xccStackFLT96_t  *p2Stack );
INT32 xccStackFullINT08 ( xccStackINT08_t  *p2Stack );
INT32 xccStackFullINT16 ( xccStackINT16_t  *p2Stack );
INT32 xccStackFullINT32 ( xccStackINT32_t  *p2Stack );
INT32 xccStackFullINT64 ( xccStackINT64_t  *p2Stack );
INT32 xccStackFullUNT08 ( xccStackUNT08_t  *p2Stack );
INT32 xccStackFullUNT16 ( xccStackUNT16_t  *p2Stack );
INT32 xccStackFullUNT32 ( xccStackUNT32_t  *p2Stack );
INT32 xccStackFullUNT64 ( xccStackUNT64_t  *p2Stack );
INT32 xccStackFullCFLT32( xccStackCFLT32_t *p2Stack );
INT32 xccStackFullCFLT64( xccStackCFLT64_t *p2Stack );
INT32 xccStackFullCFLT96( xccStackCFLT96_t *p2Stack );
INT32 xccStackFullCINT08( xccStackCINT08_t *p2Stack );
INT32 xccStackFullCINT16( xccStackCINT16_t *p2Stack );
INT32 xccStackFullCINT32( xccStackCINT32_t *p2Stack );
INT32 xccStackFullCINT64( xccStackCINT64_t *p2Stack );
INT32 xccStackFullCUNT08( xccStackCUNT08_t *p2Stack );
INT32 xccStackFullCUNT16( xccStackCUNT16_t *p2Stack );
INT32 xccStackFullCUNT32( xccStackCUNT32_t *p2Stack );
INT32 xccStackFullCUNT64( xccStackCUNT64_t *p2Stack );
INT32 xccStackFullVFLT32( xccStackVFLT32_t *p2Stack );
INT32 xccStackFullVFLT64( xccStackVFLT64_t *p2Stack );
INT32 xccStackFullVFLT96( xccStackVFLT96_t *p2Stack );
INT32 xccStackFullVINT08( xccStackVINT08_t *p2Stack );
INT32 xccStackFullVINT16( xccStackVINT16_t *p2Stack );
INT32 xccStackFullVINT32( xccStackVINT32_t *p2Stack );
INT32 xccStackFullVINT64( xccStackVINT64_t *p2Stack );
INT32 xccStackFullVUNT08( xccStackVUNT08_t *p2Stack );
INT32 xccStackFullVUNT16( xccStackVUNT16_t *p2Stack );
INT32 xccStackFullVUNT32( xccStackVUNT32_t *p2Stack );
INT32 xccStackFullVUNT64( xccStackVUNT64_t *p2Stack );
INT32 xccStackFullVOIDP ( xccStackVOIDP_t  *p2Stack );
INT32 xccStringStackFull( xccStackVOIDP_t  *p2Stack );

/* xccStackClear ----------------------------------------------------------------*/
VOID  xccStackClearFLT32( xccStackFLT32_t *p );
VOID  xccStackClearFLT64( xccStackFLT64_t *p );
VOID  xccStackClearFLT96( xccStackFLT96_t *p );
VOID  xccStackClearINT08( xccStackINT08_t *p );
VOID  xccStackClearINT16( xccStackINT16_t *p );
VOID  xccStackClearINT32( xccStackINT32_t *p );
VOID  xccStackClearINT64( xccStackINT64_t *p );
VOID  xccStackClearUNT08( xccStackUNT08_t *p );
VOID  xccStackClearUNT16( xccStackUNT16_t *p );
VOID  xccStackClearUNT32( xccStackUNT32_t *p );
VOID  xccStackClearUNT64( xccStackUNT64_t *p );
VOID  xccStackClearVOIDP( xccStackVOIDP_t *p );

/* xccStackCompare --------------------------------------------------------------*/
INT32 xccStackCompareFLT32 ( xccStackFLT32_t *p2Src, xccStackFLT32_t *p2Des );
INT32 xccStackCompareFLT64 ( xccStackFLT64_t *p2Src, xccStackFLT64_t *p2Des );
INT32 xccStackCompareFLT96 ( xccStackFLT96_t *p2Src, xccStackFLT96_t *p2Des );
INT32 xccStackCompareINT08 ( xccStackINT08_t *p2Src, xccStackINT08_t *p2Des );
INT32 xccStackCompareINT16 ( xccStackINT16_t *p2Src, xccStackINT16_t *p2Des );
INT32 xccStackCompareINT32 ( xccStackINT32_t *p2Src, xccStackINT32_t *p2Des );
INT32 xccStackCompareINT64 ( xccStackINT64_t *p2Src, xccStackINT64_t *p2Des );
INT32 xccStackCompareUNT08 ( xccStackUNT08_t *p2Src, xccStackUNT08_t *p2Des );
INT32 xccStackCompareUNT16 ( xccStackUNT16_t *p2Src, xccStackUNT16_t *p2Des );
INT32 xccStackCompareUNT32 ( xccStackUNT32_t *p2Src, xccStackUNT32_t *p2Des );
INT32 xccStackCompareUNT64 ( xccStackUNT64_t *p2Src, xccStackUNT64_t *p2Des );
INT32 xccStackCompareVOIDP ( xccStackVOIDP_t *p2Src, xccStackVOIDP_t *p2Des );

/* xccStackCopy -----------------------------------------------------------------*/
INT32 xccStackCopyFLT32 ( xccStackFLT32_t *p2Src, xccStackFLT32_t *p2Des );
INT32 xccStackCopyFLT64 ( xccStackFLT64_t *p2Src, xccStackFLT64_t *p2Des );
INT32 xccStackCopyFLT96 ( xccStackFLT96_t *p2Src, xccStackFLT96_t *p2Des );
INT32 xccStackCopyINT08 ( xccStackINT08_t *p2Src, xccStackINT08_t *p2Des );
INT32 xccStackCopyINT16 ( xccStackINT16_t *p2Src, xccStackINT16_t *p2Des );
INT32 xccStackCopyINT32 ( xccStackINT32_t *p2Src, xccStackINT32_t *p2Des );
INT32 xccStackCopyINT64 ( xccStackINT64_t *p2Src, xccStackINT64_t *p2Des );
INT32 xccStackCopyUNT08 ( xccStackUNT08_t *p2Src, xccStackUNT08_t *p2Des );
INT32 xccStackCopyUNT16 ( xccStackUNT16_t *p2Src, xccStackUNT16_t *p2Des );
INT32 xccStackCopyUNT32 ( xccStackUNT32_t *p2Src, xccStackUNT32_t *p2Des );
INT32 xccStackCopyUNT64 ( xccStackUNT64_t *p2Src, xccStackUNT64_t *p2Des );
INT32 xccStackCopyVOIDP ( xccStackVOIDP_t *p2Src, xccStackVOIDP_t *p2Des );

/* xccStackFlip -----------------------------------------------------------------*/
INT32 xccStackFlipFLT32( xccStackFLT32_t *p );
INT32 xccStackFlipFLT64( xccStackFLT64_t *p );
INT32 xccStackFlipFLT96( xccStackFLT96_t *p );
INT32 xccStackFlipINT08( xccStackINT08_t *p );
INT32 xccStackFlipINT16( xccStackINT16_t *p );
INT32 xccStackFlipINT32( xccStackINT32_t *p );
INT32 xccStackFlipINT64( xccStackINT64_t *p );
INT32 xccStackFlipUNT08( xccStackUNT08_t *p );
INT32 xccStackFlipUNT16( xccStackUNT16_t *p );
INT32 xccStackFlipUNT32( xccStackUNT32_t *p );
INT32 xccStackFlipUNT64( xccStackUNT64_t *p );
INT32 xccStackFlipVOIDP( xccStackVOIDP_t *p );
INT32 xccStackFlipCFLT32( xccStackCFLT32_t *p2Stack );
INT32 xccStackFlipCFLT64( xccStackCFLT64_t *p2Stack );
INT32 xccStackFlipCFLT96( xccStackCFLT96_t *p2Stack );
INT32 xccStackFlipCINT08( xccStackCINT08_t *p2Stack );
INT32 xccStackFlipCINT16( xccStackCINT16_t *p2Stack );
INT32 xccStackFlipCINT32( xccStackCINT32_t *p2Stack );
INT32 xccStackFlipCINT64( xccStackCINT64_t *p2Stack );
INT32 xccStackFlipCUNT08( xccStackCUNT08_t *p2Stack );
INT32 xccStackFlipCUNT16( xccStackCUNT16_t *p2Stack );
INT32 xccStackFlipCUNT32( xccStackCUNT32_t *p2Stack );
INT32 xccStackFlipCUNT64( xccStackCUNT64_t *p2Stack );
INT32 xccStackFlipVFLT32( xccStackVFLT32_t *p2Stack );
INT32 xccStackFlipVFLT64( xccStackVFLT64_t *p2Stack );
INT32 xccStackFlipVFLT96( xccStackVFLT96_t *p2Stack );
INT32 xccStackFlipVINT08( xccStackVINT08_t *p2Stack );
INT32 xccStackFlipVINT16( xccStackVINT16_t *p2Stack );
INT32 xccStackFlipVINT32( xccStackVINT32_t *p2Stack );
INT32 xccStackFlipVINT64( xccStackVINT64_t *p2Stack );
INT32 xccStackFlipVUNT08( xccStackVUNT08_t *p2Stack );
INT32 xccStackFlipVUNT16( xccStackVUNT16_t *p2Stack );
INT32 xccStackFlipVUNT32( xccStackVUNT32_t *p2Stack );
INT32 xccStackFlipVUNT64( xccStackVUNT64_t *p2Stack );

/* xccStackInit -----------------------------------------------------------------*/
xccStackFLT32_t  *xccStackInitFLT32 (UNT32 size, CCHAR *name);
xccStackFLT64_t  *xccStackInitFLT64 (UNT32 size, CCHAR *name);
xccStackFLT96_t  *xccStackInitFLT96 (UNT32 size, CCHAR *name);
xccStackINT08_t  *xccStackInitINT08 (UNT32 size, CCHAR *name);
xccStackINT16_t  *xccStackInitINT16 (UNT32 size, CCHAR *name);
xccStackINT32_t  *xccStackInitINT32 (UNT32 size, CCHAR *name);
xccStackINT64_t  *xccStackInitINT64 (UNT32 size, CCHAR *name);
xccStackUNT08_t  *xccStackInitUNT08 (UNT32 size, CCHAR *name);
xccStackUNT16_t  *xccStackInitUNT16 (UNT32 size, CCHAR *name);
xccStackUNT32_t  *xccStackInitUNT32 (UNT32 size, CCHAR *name);
xccStackUNT64_t  *xccStackInitUNT64 (UNT32 size, CCHAR *name);
xccStackVOIDP_t  *xccStackInitVOIDP (UNT32 size, CCHAR *name);
xccStackCFLT32_t *xccStackInitCFLT32(UNT32 size, CCHAR *name);
xccStackCFLT64_t *xccStackInitCFLT64(UNT32 size, CCHAR *name);
xccStackCFLT96_t *xccStackInitCFLT96(UNT32 size, CCHAR *name);
xccStackCINT08_t *xccStackInitCINT08(UNT32 size, CCHAR *name);
xccStackCINT16_t *xccStackInitCINT16(UNT32 size, CCHAR *name);
xccStackCINT32_t *xccStackInitCINT32(UNT32 size, CCHAR *name);
xccStackCINT64_t *xccStackInitCINT64(UNT32 size, CCHAR *name);
xccStackCUNT08_t *xccStackInitCUNT08(UNT32 size, CCHAR *name);
xccStackCUNT16_t *xccStackInitCUNT16(UNT32 size, CCHAR *name);
xccStackCUNT32_t *xccStackInitCUNT32(UNT32 size, CCHAR *name);
xccStackCUNT64_t *xccStackInitCUNT64(UNT32 size, CCHAR *name);
xccStackVFLT32_t *xccStackInitVFLT32(UNT32 size, CCHAR *name);
xccStackVFLT64_t *xccStackInitVFLT64(UNT32 size, CCHAR *name);
xccStackVFLT96_t *xccStackInitVFLT96(UNT32 size, CCHAR *name);
xccStackVINT08_t *xccStackInitVINT08(UNT32 size, CCHAR *name);
xccStackVINT16_t *xccStackInitVINT16(UNT32 size, CCHAR *name);
xccStackVINT32_t *xccStackInitVINT32(UNT32 size, CCHAR *name);
xccStackVINT64_t *xccStackInitVINT64(UNT32 size, CCHAR *name);
xccStackVUNT08_t *xccStackInitVUNT08(UNT32 size, CCHAR *name);
xccStackVUNT16_t *xccStackInitVUNT16(UNT32 size, CCHAR *name);
xccStackVUNT32_t *xccStackInitVUNT32(UNT32 size, CCHAR *name);
xccStackVUNT64_t *xccStackInitVUNT64(UNT32 size, CCHAR *name);

/* xccStackPop ------------------------------------------------------------------*/
INT32 xccStackPopFLT32  ( xccStackFLT32_t *p, FLT32 *value );
INT32 xccStackPopFLT64  ( xccStackFLT64_t *p, FLT64 *value );
INT32 xccStackPopFLT96  ( xccStackFLT96_t *p, FLT96 *value );
INT32 xccStackPopINT08  ( xccStackINT08_t *p, INT08 *value );
INT32 xccStackPopINT16  ( xccStackINT16_t *p, INT16 *value );
INT32 xccStackPopINT32  ( xccStackINT32_t *p, INT32 *value );
INT32 xccStackPopINT64  ( xccStackINT64_t *p, INT64 *value );
INT32 xccStackPopUNT08  ( xccStackUNT08_t *p, UNT08 *value );
INT32 xccStackPopUNT16  ( xccStackUNT16_t *p, UNT16 *value );
INT32 xccStackPopUNT32  ( xccStackUNT32_t *p, UNT32 *value );
INT32 xccStackPopUNT64  ( xccStackUNT64_t *p, UNT64 *value );
INT32 xccStackPopCFLT32( xccStackCFLT32_t *p2Stack, CFLT32 *p2value );
INT32 xccStackPopCFLT64( xccStackCFLT64_t *p2Stack, CFLT64 *p2value );
INT32 xccStackPopCFLT96( xccStackCFLT96_t *p2Stack, CFLT96 *p2value );
INT32 xccStackPopCINT08( xccStackCINT08_t *p2Stack, CINT08 *p2value );
INT32 xccStackPopCINT16( xccStackCINT16_t *p2Stack, CINT16 *p2value );
INT32 xccStackPopCINT32( xccStackCINT32_t *p2Stack, CINT32 *p2value );
INT32 xccStackPopCINT64( xccStackCINT64_t *p2Stack, CINT64 *p2value );
INT32 xccStackPopCUNT08( xccStackCUNT08_t *p2Stack, CUNT08 *p2value );
INT32 xccStackPopCUNT16( xccStackCUNT16_t *p2Stack, CUNT16 *p2value );
INT32 xccStackPopCUNT32( xccStackCUNT32_t *p2Stack, CUNT32 *p2value );
INT32 xccStackPopCUNT64( xccStackCUNT64_t *p2Stack, CUNT64 *p2value );
INT32 xccStackPopVFLT32( xccStackVFLT32_t *p2Stack, VFLT32 *p2value );
INT32 xccStackPopVFLT64( xccStackVFLT64_t *p2Stack, VFLT64 *p2value );
INT32 xccStackPopVFLT96( xccStackVFLT96_t *p2Stack, VFLT96 *p2value );
INT32 xccStackPopVINT08( xccStackVINT08_t *p2Stack, VINT08 *p2value );
INT32 xccStackPopVINT16( xccStackVINT16_t *p2Stack, VINT16 *p2value );
INT32 xccStackPopVINT32( xccStackVINT32_t *p2Stack, VINT32 *p2value );
INT32 xccStackPopVINT64( xccStackVINT64_t *p2Stack, VINT64 *p2value );
INT32 xccStackPopVUNT08( xccStackVUNT08_t *p2Stack, VUNT08 *p2value );
INT32 xccStackPopVUNT16( xccStackVUNT16_t *p2Stack, VUNT16 *p2value );
INT32 xccStackPopVUNT32( xccStackVUNT32_t *p2Stack, VUNT32 *p2value );
INT32 xccStackPopVUNT64( xccStackVUNT64_t *p2Stack, VUNT64 *p2value );
INT32 xccStackPopVOIDP  ( xccStackVOIDP_t *p, VOID **value );
INT32 xccStringStackPop( xccStackVOIDP_t *p2Stack, CHR08 **stringPointer );

/* xccStackPush -----------------------------------------------------------------*/
INT32 xccStackPushFLT32 ( xccStackFLT32_t *p, FLT32  value );
INT32 xccStackPushFLT64 ( xccStackFLT64_t *p, FLT64  value );
INT32 xccStackPushFLT96 ( xccStackFLT96_t *p, FLT96  value );
INT32 xccStackPushINT08 ( xccStackINT08_t *p, INT08  value );
INT32 xccStackPushINT16 ( xccStackINT16_t *p, INT16  value );
INT32 xccStackPushINT32 ( xccStackINT32_t *p, INT32  value );
INT32 xccStackPushINT64 ( xccStackINT64_t *p, INT64  value );
INT32 xccStackPushUNT08 ( xccStackUNT08_t *p, UNT08  value );
INT32 xccStackPushUNT16 ( xccStackUNT16_t *p, UNT16  value );
INT32 xccStackPushUNT32 ( xccStackUNT32_t *p, UNT32  value );
INT32 xccStackPushUNT64 ( xccStackUNT64_t *p, UNT64  value );
INT32 xccStackPushCFLT32( xccStackCFLT32_t *p2Stack, CFLT32 value );
INT32 xccStackPushCFLT64( xccStackCFLT64_t *p2Stack, CFLT64 value );
INT32 xccStackPushCFLT96( xccStackCFLT96_t *p2Stack, CFLT96 value );
INT32 xccStackPushCINT08( xccStackCINT08_t *p2Stack, CINT08 value );
INT32 xccStackPushCINT16( xccStackCINT16_t *p2Stack, CINT16 value );
INT32 xccStackPushCINT32( xccStackCINT32_t *p2Stack, CINT32 value );
INT32 xccStackPushCINT64( xccStackCINT64_t *p2Stack, CINT64 value );
INT32 xccStackPushCUNT08( xccStackCUNT08_t *p2Stack, CUNT08 value );
INT32 xccStackPushCUNT16( xccStackCUNT16_t *p2Stack, CUNT16 value );
INT32 xccStackPushCUNT32( xccStackCUNT32_t *p2Stack, CUNT32 value );
INT32 xccStackPushCUNT64( xccStackCUNT64_t *p2Stack, CUNT64 value );
INT32 xccStackPushVFLT32( xccStackVFLT32_t *p2Stack, VFLT32 value );
INT32 xccStackPushVFLT64( xccStackVFLT64_t *p2Stack, VFLT64 value );
INT32 xccStackPushVINT08( xccStackVINT08_t *p2Stack, VINT08 value );
INT32 xccStackPushVINT16( xccStackVINT16_t *p2Stack, VINT16 value );
INT32 xccStackPushVINT32( xccStackVINT32_t *p2Stack, VINT32 value );
INT32 xccStackPushVINT64( xccStackVINT64_t *p2Stack, VINT64 value );
INT32 xccStackPushVUNT08( xccStackVUNT08_t *p2Stack, VUNT08 value );
INT32 xccStackPushVUNT16( xccStackVUNT16_t *p2Stack, VUNT16 value );
INT32 xccStackPushVUNT32( xccStackVUNT32_t *p2Stack, VUNT32 value );
INT32 xccStackPushVUNT64( xccStackVUNT64_t *p2Stack, VUNT64 value );
INT32 xccStackPushVOIDP ( xccStackVOIDP_t *p, VOID  *value );
INT32 xccStringStackPush( xccStackVOIDP_t *p, const CHR08 *string );
INT32 xccStringStackSearch( xccStackVOIDP_t *p, const CHR08 *stringToLookFor );

/* xccStackSort -----------------------------------------------------------------*/
VOID xccStackSortFLT32 ( xccStackFLT32_t  *p2Stack );
VOID xccStackSortFLT64 ( xccStackFLT64_t  *p2Stack );
VOID xccStackSortFLT96 ( xccStackFLT96_t  *p2Stack );
VOID xccStackSortINT08 ( xccStackINT08_t  *p2Stack );
VOID xccStackSortINT16 ( xccStackINT16_t  *p2Stack );
VOID xccStackSortINT32 ( xccStackINT32_t  *p2Stack );
VOID xccStackSortINT64 ( xccStackINT64_t  *p2Stack );
VOID xccStackSortUNT08 ( xccStackUNT08_t  *p2Stack );
VOID xccStackSortUNT16 ( xccStackUNT16_t  *p2Stack );
VOID xccStackSortUNT32 ( xccStackUNT32_t  *p2Stack );
VOID xccStackSortUNT64 ( xccStackUNT64_t  *p2Stack );
VOID xccStackSortCFLT32( xccStackCFLT32_t *p2Stack );
VOID xccStackSortCFLT64( xccStackCFLT64_t *p2Stack );
VOID xccStackSortCFLT96( xccStackCFLT96_t *p2Stack );
VOID xccStackSortCINT08( xccStackCINT08_t *p2Stack );
VOID xccStackSortCINT16( xccStackCINT16_t *p2Stack );
VOID xccStackSortCINT32( xccStackCINT32_t *p2Stack );
VOID xccStackSortCINT64( xccStackCINT64_t *p2Stack );
VOID xccStackSortCUNT08( xccStackCUNT08_t *p2Stack );
VOID xccStackSortCUNT16( xccStackCUNT16_t *p2Stack );
VOID xccStackSortCUNT32( xccStackCUNT32_t *p2Stack );
VOID xccStackSortCUNT64( xccStackCUNT64_t *p2Stack );
VOID xccStackSortVFLT32( xccStackVFLT32_t *p2Stack );
VOID xccStackSortVFLT64( xccStackVFLT64_t *p2Stack );
VOID xccStackSortVFLT96( xccStackVFLT96_t *p2Stack );
VOID xccStackSortVINT08( xccStackVINT08_t *p2Stack );
VOID xccStackSortVINT16( xccStackVINT16_t *p2Stack );
VOID xccStackSortVINT32( xccStackVINT32_t *p2Stack );
VOID xccStackSortVINT64( xccStackVINT64_t *p2Stack );
VOID xccStackSortVUNT08( xccStackVUNT08_t *p2Stack );
VOID xccStackSortVUNT16( xccStackVUNT16_t *p2Stack );
VOID xccStackSortVUNT32( xccStackVUNT32_t *p2Stack );
VOID xccStackSortVUNT64( xccStackVUNT64_t *p2Stack );
VOID xccStringStackSort( xccStackVOIDP_t  *p2Stack );

/* xccStackTop ------------------------------------------------------------------*/
FLT32  xccStackTopFLT32( xccStackFLT32_t *p );
FLT64  xccStackTopFLT64( xccStackFLT64_t *p );
FLT96  xccStackTopFLT96( xccStackFLT96_t *p );
INT08  xccStackTopINT08( xccStackINT08_t *p );
INT16  xccStackTopINT16( xccStackINT16_t *p );
INT32  xccStackTopINT32( xccStackINT32_t *p );
INT64  xccStackTopINT64( xccStackINT64_t *p );
UNT08  xccStackTopUNT08( xccStackUNT08_t *p );
UNT16  xccStackTopUNT16( xccStackUNT16_t *p );
UNT32  xccStackTopUNT32( xccStackUNT32_t *p );
UNT64  xccStackTopUNT64( xccStackUNT64_t *p );
VOID  *xccStackTopVOIDP( xccStackVOIDP_t *p );

/* xccStackTerm -----------------------------------------------------------------*/
VOID  xccStackTermFLT32( xccStackFLT32_t *p );
VOID  xccStackTermFLT64( xccStackFLT64_t *p );
VOID  xccStackTermFLT96( xccStackFLT96_t *p );
VOID  xccStackTermINT08( xccStackINT08_t *p );
VOID  xccStackTermINT16( xccStackINT16_t *p );
VOID  xccStackTermINT32( xccStackINT32_t *p );
VOID  xccStackTermINT64( xccStackINT64_t *p );
VOID  xccStackTermUNT08( xccStackUNT08_t *p );
VOID  xccStackTermUNT16( xccStackUNT16_t *p );
VOID  xccStackTermUNT32( xccStackUNT32_t *p );
VOID  xccStackTermUNT64( xccStackUNT64_t *p );
VOID  xccStackTermVOIDP( xccStackVOIDP_t *p );
VOID xccStackTermCFLT32(xccStackCFLT32_t *p2WS);
VOID xccStackTermCFLT64(xccStackCFLT64_t *p2WS);
VOID xccStackTermCFLT96(xccStackCFLT96_t *p2WS);
VOID xccStackTermCINT08(xccStackCINT08_t *p2WS);
VOID xccStackTermCINT16(xccStackCINT16_t *p2WS);
VOID xccStackTermCINT32(xccStackCINT32_t *p2WS);
VOID xccStackTermCINT64(xccStackCINT64_t *p2WS);
VOID xccStackTermCUNT08(xccStackCUNT08_t *p2WS);
VOID xccStackTermCUNT16(xccStackCUNT16_t *p2WS);
VOID xccStackTermCUNT32(xccStackCUNT32_t *p2WS);
VOID xccStackTermCUNT64(xccStackCUNT64_t *p2WS);
VOID xccStackTermVFLT32(xccStackVFLT32_t *p2WS);
VOID xccStackTermVFLT64(xccStackVFLT64_t *p2WS);
VOID xccStackTermVFLT96(xccStackVFLT96_t *p2WS);
VOID xccStackTermVINT08(xccStackVINT08_t *p2WS);
VOID xccStackTermVINT16(xccStackVINT16_t *p2WS);
VOID xccStackTermVINT32(xccStackVINT32_t *p2WS);
VOID xccStackTermVINT64(xccStackVINT64_t *p2WS);
VOID xccStackTermVUNT08(xccStackVUNT08_t *p2WS);
VOID xccStackTermVUNT16(xccStackVUNT16_t *p2WS);
VOID xccStackTermVUNT32(xccStackVUNT32_t *p2WS);
VOID xccStackTermVUNT64(xccStackVUNT64_t *p2WS);

/* Packing routines -------------------------------------------------------------*/
INT32 xccCHR08UnpackMSB_INT08( xccStackINT08_t *p, INT08 c );
INT32 xccCHR08UnpackLSB_INT08( xccStackINT08_t *p, INT08 c );
INT32 xccCHR08PackMSB_INT08(   xccStackINT08_t *p, INT08 *c);
INT32 xccCHR08PackLSB_INT08(   xccStackINT08_t *p, INT08 *c);

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus 
} 
#endif 
 
#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/
