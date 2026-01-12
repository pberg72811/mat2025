/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccMalloc.c
// Desc: This file contains the code for the xccMalloc routine.
// Hist: When       Who  What
//       03/06/2003 ptb  Initial Code.
//       08/12/2005 ptb  Add bzero line to clear memory.
//       03/28/2006 ptb  Switch to XMC vs. STESWD.
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
PERL_PREPROCESS ptr = (XXXXX *)malloc(sizeof(XXXXX)*size);
PERL_PREPROCESS bzero(ptr, sizeof(XXXXX)*size);
PERL_PREPROCESS if(ptr == NULL)
PERL_PREPROCESS {
PERL_PREPROCESS   XMC_ERROR_STDOUT("Memory allocation error.");
PERL_PREPROCESS   exit(0);
PERL_PREPROCESS }
PERL_PREPROCESS //if(G_xccMemoryEnable) G_xccMemoryAdd++;
PERL_PREPROCESS return(ptr);
#endif
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

CHR08 *xccMallocCHR08(UNT32 size)
{
//------------------------------- COMMON-CODE CHR08       START.
 CHR08 *ptr;
 ptr = (CHR08 *)malloc(sizeof(CHR08)*size);
 bzero(ptr, sizeof(CHR08)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CHR08        STOP.
}

INT08 *xccMallocINT08(UNT32 size)
{
//------------------------------- COMMON-CODE INT08       START.
 INT08 *ptr;
 ptr = (INT08 *)malloc(sizeof(INT08)*size);
 bzero(ptr, sizeof(INT08)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT08        STOP.
}

INT16 *xccMallocINT16(UNT32 size)
{
//------------------------------- COMMON-CODE INT16       START.
 INT16 *ptr;
 ptr = (INT16 *)malloc(sizeof(INT16)*size);
 bzero(ptr, sizeof(INT16)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT16        STOP.
}

INT32 *xccMallocINT32(UNT32 size)
{
//------------------------------- COMMON-CODE INT32       START.
 INT32 *ptr;
 ptr = (INT32 *)malloc(sizeof(INT32)*size);
 bzero(ptr, sizeof(INT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT32        STOP.
}

INT64 *xccMallocINT64(UNT32 size)
{
//------------------------------- COMMON-CODE INT64       START.
 INT64 *ptr;
 ptr = (INT64 *)malloc(sizeof(INT64)*size);
 bzero(ptr, sizeof(INT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE INT64        STOP.
}

UNT08 *xccMallocUNT08(UNT32 size)
{
//------------------------------- COMMON-CODE UNT08       START.
 UNT08 *ptr;
 ptr = (UNT08 *)malloc(sizeof(UNT08)*size);
 bzero(ptr, sizeof(UNT08)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT08        STOP.
}

UNT16 *xccMallocUNT16(UNT32 size)
{
//------------------------------- COMMON-CODE UNT16       START.
 UNT16 *ptr;
 ptr = (UNT16 *)malloc(sizeof(UNT16)*size);
 bzero(ptr, sizeof(UNT16)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT16        STOP.
}

UNT32 *xccMallocUNT32(UNT32 size)
{
//------------------------------- COMMON-CODE UNT32       START.
 UNT32 *ptr;
 ptr = (UNT32 *)malloc(sizeof(UNT32)*size);
 bzero(ptr, sizeof(UNT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE UNT32        STOP.
}

UNT64 *xccMallocUNT64(UNT32 size)
{
//-------------------------------  COMMON-CODE UNT64       START.
 UNT64 *ptr;
 ptr = (UNT64 *)malloc(sizeof(UNT64)*size);
 bzero(ptr, sizeof(UNT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//-------------------------------  COMMON-CODE UNT64        STOP.
}

FLT32 *xccMallocFLT32(UNT32 size)
{
//------------------------------- COMMON-CODE FLT32       START.
 FLT32 *ptr;
 ptr = (FLT32 *)malloc(sizeof(FLT32)*size);
 bzero(ptr, sizeof(FLT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE FLT32        STOP.
}

FLT64 *xccMallocFLT64(UNT32 size)
{
//------------------------------- COMMON-CODE FLT64       START.
 FLT64 *ptr;
 ptr = (FLT64 *)malloc(sizeof(FLT64)*size);
 bzero(ptr, sizeof(FLT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE FLT64        STOP.
}

FLT96 *xccMallocFLT96(UNT32 size)
{
//------------------------------- COMMON-CODE FLT96       START.
 FLT96 *ptr;
 ptr = (FLT96 *)malloc(sizeof(FLT96)*size);
 bzero(ptr, sizeof(FLT96)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE FLT96        STOP.
}

VOID  *xccMallocVOID(UNT32 size)
{
//------------------------------- COMMON-CODE VOID       START.
 VOID *ptr;
 ptr = (VOID *)malloc(sizeof(VOID)*size);
 bzero(ptr, sizeof(VOID)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE VOID        STOP.
}

CINT08 *xccMallocCINT08(UNT32 size)
{
//------------------------------- COMMON-CODE CINT08       START.
 CINT08 *ptr;
 ptr = (CINT08 *)malloc(sizeof(CINT08)*size);
 bzero(ptr, sizeof(CINT08)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CINT08        STOP.
}

CINT16 *xccMallocCINT16(UNT32 size)
{
//------------------------------- COMMON-CODE CINT16       START.
 CINT16 *ptr;
 ptr = (CINT16 *)malloc(sizeof(CINT16)*size);
 bzero(ptr, sizeof(CINT16)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CINT16        STOP.
}

CINT32 *xccMallocCINT32(UNT32 size)
{
//------------------------------- COMMON-CODE CINT32       START.
 CINT32 *ptr;
 ptr = (CINT32 *)malloc(sizeof(CINT32)*size);
 bzero(ptr, sizeof(CINT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CINT32        STOP.
}

CINT64 *xccMallocCINT64(UNT32 size)
{
//------------------------------- COMMON-CODE CINT64       START.
 CINT64 *ptr;
 ptr = (CINT64 *)malloc(sizeof(CINT64)*size);
 bzero(ptr, sizeof(CINT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CINT64        STOP.
}

CUNT08 *xccMallocCUNT08(UNT32 size)
{
//------------------------------- COMMON-CODE CUNT08       START.
 CUNT08 *ptr;
 ptr = (CUNT08 *)malloc(sizeof(CUNT08)*size);
 bzero(ptr, sizeof(CUNT08)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CUNT08        STOP.
}

CUNT16 *xccMallocCUNT16(UNT32 size)
{
//------------------------------- COMMON-CODE CUNT16       START.
 CUNT16 *ptr;
 ptr = (CUNT16 *)malloc(sizeof(CUNT16)*size);
 bzero(ptr, sizeof(CUNT16)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CUNT16        STOP.
}

CUNT32 *xccMallocCUNT32(UNT32 size)
{
//------------------------------- COMMON-CODE CUNT32       START.
 CUNT32 *ptr;
 ptr = (CUNT32 *)malloc(sizeof(CUNT32)*size);
 bzero(ptr, sizeof(CUNT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CUNT32        STOP.
}

CUNT64 *xccMallocCUNT64(UNT32 size)
{
//-------------------------------  COMMON-CODE CUNT64       START.
 CUNT64 *ptr;
 ptr = (CUNT64 *)malloc(sizeof(CUNT64)*size);
 bzero(ptr, sizeof(CUNT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//-------------------------------  COMMON-CODE CUNT64        STOP.
}

CFLT32 *xccMallocCFLT32(UNT32 size)
{
//------------------------------- COMMON-CODE CFLT32       START.
 CFLT32 *ptr;
 ptr = (CFLT32 *)malloc(sizeof(CFLT32)*size);
 bzero(ptr, sizeof(CFLT32)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CFLT32        STOP.
}

CFLT64 *xccMallocCFLT64(UNT32 size)
{
//------------------------------- COMMON-CODE CFLT64       START.
 CFLT64 *ptr;
 ptr = (CFLT64 *)malloc(sizeof(CFLT64)*size);
 bzero(ptr, sizeof(CFLT64)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CFLT64        STOP.
}

CFLT96 *xccMallocCFLT96(UNT32 size)
{
//------------------------------- COMMON-CODE CFLT96       START.
 CFLT96 *ptr;
 ptr = (CFLT96 *)malloc(sizeof(CFLT96)*size);
 bzero(ptr, sizeof(CFLT96)*size);
 if(ptr == NULL)
 {
   XMC_ERROR_STDOUT("Memory allocation error.");
   exit(0);
 }
 //if(G_xccMemoryEnable) G_xccMemoryAdd++;
 return(ptr);
//------------------------------- COMMON-CODE CFLT96        STOP.
}


/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
