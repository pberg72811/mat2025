/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccMalloc.c
// Desc: This file contains the code for the iccMalloc routine.
// Hist: When       Who  What
//       03/06/2003 ptb  Initial Code.
//       08/12/2005 ptb  Add bzero line to clear memory.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "malloc_utils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS XXXXX *ptr;
PERL_PREPROCESS ptr =  (XXXXX * )memalign( YYYYY, size*sizeof(XXXXX) );
PERL_PREPROCESS bzero(ptr, sizeof(XXXXX)*size);
PERL_PREPROCESS if(ptr == NULL)
PERL_PREPROCESS {
PERL_PREPROCESS   XMC_ERROR_STDOUT("Memory allocation error.");
PERL_PREPROCESS   exit(0);
PERL_PREPROCESS }
PERL_PREPROCESS //if(G_iccMemoryEnable) G_iccMemoryAdd++;
PERL_PREPROCESS return(ptr);
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
// Align to 16 bits.
//------------------------------------------------------------------------------
INT08 *iccMallocINT08_Align016(UNT32 size)
{
//------------------------------- COMMON-CODE INT08 2       START.
 INT08 *ptr;
 ptr =  (INT08 * )memalign( 2, size*sizeof(INT08) );
 bzero(ptr, sizeof(INT08)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT08 2        STOP.
}

INT16 *iccMallocINT16_Align016(UNT32 size)
{
//------------------------------- COMMON-CODE INT16 2       START.
 INT16 *ptr;
 ptr =  (INT16 * )memalign( 2, size*sizeof(INT16) );
 bzero(ptr, sizeof(INT16)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT16 2        STOP.
}

INT32 *iccMallocINT32_Align016(UNT32 size)
{
//------------------------------- COMMON-CODE INT32 2       START.
 INT32 *ptr;
 ptr =  (INT32 * )memalign( 2, size*sizeof(INT32) );
 bzero(ptr, sizeof(INT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT32 2        STOP.
}

INT64 *iccMallocINT64_Align016(UNT32 size)
{
//------------------------------- COMMON-CODE INT64 2       START.
 INT64 *ptr;
 ptr =  (INT64 * )memalign( 2, size*sizeof(INT64) );
 bzero(ptr, sizeof(INT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT64 2        STOP.
}

UNT08 *iccMallocUNT08_Align016(UNT32 size)
{
//------------------------------- COMMON-CODE UNT08 2.       START.
 UNT08 *ptr;
 ptr =  (UNT08 * )memalign( 2., size*sizeof(UNT08) );
 bzero(ptr, sizeof(UNT08)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT08 2.        STOP.
}

UNT16 *iccMallocUNT16_Align016(UNT32 size)
{
//------------------------------- COMMON-CODE UNT16 2       START.
 UNT16 *ptr;
 ptr =  (UNT16 * )memalign( 2, size*sizeof(UNT16) );
 bzero(ptr, sizeof(UNT16)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT16 2        STOP.
}

UNT32 *iccMallocUNT32_Align016(UNT32 size)
{
//------------------------------- COMMON-CODE UNT32 2       START.
 UNT32 *ptr;
 ptr =  (UNT32 * )memalign( 2, size*sizeof(UNT32) );
 bzero(ptr, sizeof(UNT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT32 2        STOP.
}

UNT64 *iccMallocUNT64_Align016(UNT32 size)
{
//------------------------------- COMMON-CODE UNT64 2       START.
 UNT64 *ptr;
 ptr =  (UNT64 * )memalign( 2, size*sizeof(UNT64) );
 bzero(ptr, sizeof(UNT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT64 2        STOP.
}

FLT32 *iccMallocFLT32_Align016(UNT32 size)
{
//------------------------------- COMMON-CODE FLT32 2       START.
 FLT32 *ptr;
 ptr =  (FLT32 * )memalign( 2, size*sizeof(FLT32) );
 bzero(ptr, sizeof(FLT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE FLT32 2        STOP.
}

FLT96 *iccMallocFLT96_Align016(UNT32 size)
{
//------------------------------- COMMON-CODE FLT96 2       START.
 FLT96 *ptr;
 ptr =  (FLT96 * )memalign( 2, size*sizeof(FLT96) );
 bzero(ptr, sizeof(FLT96)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE FLT96 2        STOP.
}

VOID *iccMallocVOID_Align016(UNT32 size)
{
//------------------------------- COMMON-CODE VOID 2       START.
 VOID *ptr;
 ptr =  (VOID * )memalign( 2, size*sizeof(VOID) );
 bzero(ptr, sizeof(VOID)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE VOID 2        STOP.
}

// Align to 32 bits.
//------------------------------------------------------------------------------
INT08 *iccMallocINT08_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE INT08 4       START.
 INT08 *ptr;
 ptr =  (INT08 * )memalign( 4, size*sizeof(INT08) );
 bzero(ptr, sizeof(INT08)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT08 4        STOP.
}

INT16 *iccMallocINT16_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE INT16 4       START.
 INT16 *ptr;
 ptr =  (INT16 * )memalign( 4, size*sizeof(INT16) );
 bzero(ptr, sizeof(INT16)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT16 4        STOP.
}

INT32 *iccMallocINT32_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE INT32 4        START.
 INT32 *ptr;
 ptr =  (INT32 * )memalign( 4, size*sizeof(INT32) );
 bzero(ptr, sizeof(INT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT32 4         STOP.
}

INT64 *iccMallocINT64_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE INT64 4        START.
 INT64 *ptr;
 ptr =  (INT64 * )memalign( 4, size*sizeof(INT64) );
 bzero(ptr, sizeof(INT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT64 4         STOP.
}

UNT08 *iccMallocUNT08_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE UNT08 4        START.
 UNT08 *ptr;
 ptr =  (UNT08 * )memalign( 4, size*sizeof(UNT08) );
 bzero(ptr, sizeof(UNT08)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT08 4         STOP.
}

UNT16 *iccMallocUNT16_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE UNT16 4        START.
 UNT16 *ptr;
 ptr =  (UNT16 * )memalign( 4, size*sizeof(UNT16) );
 bzero(ptr, sizeof(UNT16)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT16 4         STOP.
}

UNT32 *iccMallocUNT32_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE UNT32 4        START.
 UNT32 *ptr;
 ptr =  (UNT32 * )memalign( 4, size*sizeof(UNT32) );
 bzero(ptr, sizeof(UNT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT32 4         STOP.
}

UNT64 *iccMallocUNT64_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE UNT64 4        START.
 UNT64 *ptr;
 ptr =  (UNT64 * )memalign( 4, size*sizeof(UNT64) );
 bzero(ptr, sizeof(UNT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT64 4         STOP.
}

FLT32 *iccMallocFLT32_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE FLT32 4        START.
 FLT32 *ptr;
 ptr =  (FLT32 * )memalign( 4, size*sizeof(FLT32) );
 bzero(ptr, sizeof(FLT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE FLT32 4         STOP.
}

FLT64 *iccMallocFLT64_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE FLT64 4        START.
 FLT64 *ptr;
 ptr =  (FLT64 * )memalign( 4, size*sizeof(FLT64) );
 bzero(ptr, sizeof(FLT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE FLT64 4         STOP.
}

FLT96 *iccMallocFLT96_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE FLT96 4        START.
 FLT96 *ptr;
 ptr =  (FLT96 * )memalign( 4, size*sizeof(FLT96) );
 bzero(ptr, sizeof(FLT96)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE FLT96 4         STOP.
}

VOID *iccMallocVOID_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE VOID 4        START.
 VOID *ptr;
 ptr =  (VOID * )memalign( 4, size*sizeof(VOID) );
 bzero(ptr, sizeof(VOID)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE VOID 4         STOP.
}

CINT08 *iccMallocCINT08_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE CINT08 4       START.
 CINT08 *ptr;
 ptr =  (CINT08 * )memalign( 4, size*sizeof(CINT08) );
 bzero(ptr, sizeof(CINT08)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CINT08 4        STOP.
}

CINT16 *iccMallocCINT16_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE CINT16 4       START.
 CINT16 *ptr;
 ptr =  (CINT16 * )memalign( 4, size*sizeof(CINT16) );
 bzero(ptr, sizeof(CINT16)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CINT16 4        STOP.
}

CINT32 *iccMallocCINT32_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE CINT32 4        START.
 CINT32 *ptr;
 ptr =  (CINT32 * )memalign( 4, size*sizeof(CINT32) );
 bzero(ptr, sizeof(CINT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CINT32 4         STOP.
}

CINT64 *iccMallocCINT64_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE CINT64 4        START.
 CINT64 *ptr;
 ptr =  (CINT64 * )memalign( 4, size*sizeof(CINT64) );
 bzero(ptr, sizeof(CINT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CINT64 4         STOP.
}

CUNT08 *iccMallocCUNT08_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE CUNT08 4        START.
 CUNT08 *ptr;
 ptr =  (CUNT08 * )memalign( 4, size*sizeof(CUNT08) );
 bzero(ptr, sizeof(CUNT08)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CUNT08 4         STOP.
}

CUNT16 *iccMallocCUNT16_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE CUNT16 4        START.
 CUNT16 *ptr;
 ptr =  (CUNT16 * )memalign( 4, size*sizeof(CUNT16) );
 bzero(ptr, sizeof(CUNT16)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CUNT16 4         STOP.
}

CUNT32 *iccMallocCUNT32_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE CUNT32 4        START.
 CUNT32 *ptr;
 ptr =  (CUNT32 * )memalign( 4, size*sizeof(CUNT32) );
 bzero(ptr, sizeof(CUNT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CUNT32 4         STOP.
}

CUNT64 *iccMallocCUNT64_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE CUNT64 4        START.
 CUNT64 *ptr;
 ptr =  (CUNT64 * )memalign( 4, size*sizeof(CUNT64) );
 bzero(ptr, sizeof(CUNT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CUNT64 4         STOP.
}

CFLT32 *iccMallocCFLT32_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE CFLT32 4        START.
 CFLT32 *ptr;
 ptr =  (CFLT32 * )memalign( 4, size*sizeof(CFLT32) );
 bzero(ptr, sizeof(CFLT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CFLT32 4         STOP.
}

CFLT64 *iccMallocCFLT64_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE CFLT64 4        START.
 CFLT64 *ptr;
 ptr =  (CFLT64 * )memalign( 4, size*sizeof(CFLT64) );
 bzero(ptr, sizeof(CFLT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CFLT64 4         STOP.
}

CFLT96 *iccMallocCFLT96_Align032(UNT32 size)
{
//------------------------------- COMMON-CODE CFLT96 4        START.
 CFLT96 *ptr;
 ptr =  (CFLT96 * )memalign( 4, size*sizeof(CFLT96) );
 bzero(ptr, sizeof(CFLT96)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CFLT96 4         STOP.
}

// Align to 64 bits.
//------------------------------------------------------------------------------
INT08 *iccMallocINT08_Align064(UNT32 size)
{
//------------------------------- COMMON-CODE INT08 8        START.
 INT08 *ptr;
 ptr =  (INT08 * )memalign( 8, size*sizeof(INT08) );
 bzero(ptr, sizeof(INT08)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT08 8         STOP.
}

INT16 *iccMallocINT16_Align064(UNT32 size)
{
//------------------------------- COMMON-CODE INT16 8        START.
 INT16 *ptr;
 ptr =  (INT16 * )memalign( 8, size*sizeof(INT16) );
 bzero(ptr, sizeof(INT16)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT16 8         STOP.
}

INT32 *iccMallocINT32_Align064(UNT32 size)
{
//------------------------------- COMMON-CODE INT32 8        START.
 INT32 *ptr;
 ptr =  (INT32 * )memalign( 8, size*sizeof(INT32) );
 bzero(ptr, sizeof(INT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT32 8         STOP.
}

INT64 *iccMallocINT64_Align064(UNT32 size)
{
//------------------------------- COMMON-CODE INT64 8        START.
 INT64 *ptr;
 ptr =  (INT64 * )memalign( 8, size*sizeof(INT64) );
 bzero(ptr, sizeof(INT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT64 8         STOP.
}

UNT08 *iccMallocUNT08_Align064(UNT32 size)
{
//------------------------------- COMMON-CODE UNT08 8        START.
 UNT08 *ptr;
 ptr =  (UNT08 * )memalign( 8, size*sizeof(UNT08) );
 bzero(ptr, sizeof(UNT08)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT08 8         STOP.
}

UNT16 *iccMallocUNT16_Align064(UNT32 size)
{
//------------------------------- COMMON-CODE UNT16 8        START.
 UNT16 *ptr;
 ptr =  (UNT16 * )memalign( 8, size*sizeof(UNT16) );
 bzero(ptr, sizeof(UNT16)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT16 8         STOP.
}

UNT32 *iccMallocUNT32_Align064(UNT32 size)
{
//------------------------------- COMMON-CODE UNT32 8        START.
 UNT32 *ptr;
 ptr =  (UNT32 * )memalign( 8, size*sizeof(UNT32) );
 bzero(ptr, sizeof(UNT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT32 8         STOP.
}

UNT64 *iccMallocUNT64_Align064(UNT32 size)
{
//------------------------------- COMMON-CODE UNT64 8        START.
 UNT64 *ptr;
 ptr =  (UNT64 * )memalign( 8, size*sizeof(UNT64) );
 bzero(ptr, sizeof(UNT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT64 8         STOP.
}

FLT32 *iccMallocFLT32_Align064(UNT32 size)
{
//------------------------------- COMMON-CODE FLT32 8        START.
 FLT32 *ptr;
 ptr =  (FLT32 * )memalign( 8, size*sizeof(FLT32) );
 bzero(ptr, sizeof(FLT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE FLT32 8         STOP.
}

FLT96 *iccMallocFLT96_Align064(UNT32 size)
{
//------------------------------- COMMON-CODE FLT96 8        START.
 FLT96 *ptr;
 ptr =  (FLT96 * )memalign( 8, size*sizeof(FLT96) );
 bzero(ptr, sizeof(FLT96)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE FLT96 8         STOP.
}

VOID *iccMallocVOID_Align064(UNT32 size)
{
//------------------------------- COMMON-CODE VOID 8        START.
 VOID *ptr;
 ptr =  (VOID * )memalign( 8, size*sizeof(VOID) );
 bzero(ptr, sizeof(VOID)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE VOID 8         STOP.
}

// Align to 128 bits.
//------------------------------------------------------------------------------
INT08 *iccMallocINT08_Align128(UNT32 size)
{
//------------------------------- COMMON-CODE INT08 16        START.
 INT08 *ptr;
 ptr =  (INT08 * )memalign( 16, size*sizeof(INT08) );
 bzero(ptr, sizeof(INT08)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT08 16         STOP.
}

INT16 *iccMallocINT16_Align128(UNT32 size)
{
//------------------------------- COMMON-CODE INT16 16        START.
 INT16 *ptr;
 ptr =  (INT16 * )memalign( 16, size*sizeof(INT16) );
 bzero(ptr, sizeof(INT16)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT16 16         STOP.
}

INT32 *iccMallocINT32_Align128(UNT32 size)
{
//------------------------------- COMMON-CODE INT32 16        START.
 INT32 *ptr;
 ptr =  (INT32 * )memalign( 16, size*sizeof(INT32) );
 bzero(ptr, sizeof(INT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT32 16         STOP.
}

INT64 *iccMallocINT64_Align128(UNT32 size)
{
//------------------------------- COMMON-CODE INT64 16        START.
 INT64 *ptr;
 ptr =  (INT64 * )memalign( 16, size*sizeof(INT64) );
 bzero(ptr, sizeof(INT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT64 16         STOP.
}

UNT08 *iccMallocUNT08_Align128(UNT32 size)
{
//------------------------------- COMMON-CODE UNT08 16        START.
 UNT08 *ptr;
 ptr =  (UNT08 * )memalign( 16, size*sizeof(UNT08) );
 bzero(ptr, sizeof(UNT08)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT08 16         STOP.
}

UNT16 *iccMallocUNT16_Align128(UNT32 size)
{
//------------------------------- COMMON-CODE UNT16 16        START.
 UNT16 *ptr;
 ptr =  (UNT16 * )memalign( 16, size*sizeof(UNT16) );
 bzero(ptr, sizeof(UNT16)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT16 16         STOP.
}

UNT32 *iccMallocUNT32_Align128(UNT32 size)
{
//------------------------------- COMMON-CODE UNT32 16        START.
 UNT32 *ptr;
 ptr =  (UNT32 * )memalign( 16, size*sizeof(UNT32) );
 bzero(ptr, sizeof(UNT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT32 16         STOP.
}

UNT64 *iccMallocUNT64_Align128(UNT32 size)
{
//------------------------------- COMMON-CODE UNT64 16        START.
 UNT64 *ptr;
 ptr =  (UNT64 * )memalign( 16, size*sizeof(UNT64) );
 bzero(ptr, sizeof(UNT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT64 16         STOP.
}

FLT32 *iccMallocFLT32_Align128(UNT32 size)
{
//------------------------------- COMMON-CODE FLT32 16        START.
 FLT32 *ptr;
 ptr =  (FLT32 * )memalign( 16, size*sizeof(FLT32) );
 bzero(ptr, sizeof(FLT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE FLT32 16         STOP.
}

FLT64 *iccMallocFLT64_Align128(UNT32 size)
{
//------------------------------- COMMON-CODE FLT64 16        START.
 FLT64 *ptr;
 ptr =  (FLT64 * )memalign( 16, size*sizeof(FLT64) );
 bzero(ptr, sizeof(FLT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE FLT64 16         STOP.
}

FLT96 *iccMallocFLT96_Align128(UNT32 size)
{
//------------------------------- COMMON-CODE FLT96 16        START.
 FLT96 *ptr;
 ptr =  (FLT96 * )memalign( 16, size*sizeof(FLT96) );
 bzero(ptr, sizeof(FLT96)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE FLT96 16         STOP.
}

VOID *iccMallocVOID_Align128(UNT32 size)
{
//------------------------------- COMMON-CODE VOID 16        START.
 VOID *ptr;
 ptr =  (VOID * )memalign( 16, size*sizeof(VOID) );
 bzero(ptr, sizeof(VOID)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_iccMemoryEnable) G_iccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE VOID 16         STOP.
}
/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
