/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: iccBufferInit.c
// Desc: This file contains the code for the iccBufferInit routine.
// Hist: When       Who  What
//       08/22/2003 ptb  Initial Code.  Copied from iccStackUtils.
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include "buffer_utils.h" 
 
/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS  /* Variables -----------------------------------------------------------------*/
PERL_PREPROCESS  iccBufferXXXXX_t *spec;
PERL_PREPROCESS
PERL_PREPROCESS  /* Check name length ---------------------------------------------------------*/
PERL_PREPROCESS  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
PERL_PREPROCESS  {
PERL_PREPROCESS    icc_ERROR_MESSAGE("icc_BUFFER NAME TOO LONG");
PERL_PREPROCESS    return(NULL);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  /* Allocate buffer structure -------------------------------------------------*/
PERL_PREPROCESS  if((spec = (iccBufferXXXXX_t *)malloc(sizeof(iccBufferXXXXX_t))) == NULL)
PERL_PREPROCESS  {
PERL_PREPROCESS    icc_ERROR_MESSAGE("MEMORY ALLOCATION ERROR");
PERL_PREPROCESS    return(NULL);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  /* Allocate the buffer -------------------------------------------------------*/
PERL_PREPROCESS  if((spec->theBuffer = (XXXXX *)malloc(size*sizeof(XXXXX))) == NULL)
PERL_PREPROCESS  {
PERL_PREPROCESS    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
PERL_PREPROCESS    return(NULL);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  /* Zero out the buffer -------------------------------------------------------*/
PERL_PREPROCESS  bzero(spec->theBuffer,size*sizeof(XXXXX));
PERL_PREPROCESS
PERL_PREPROCESS  /* Set the name, type, size, index and then return----------------------------*/
PERL_PREPROCESS  sprintf(spec->name,"%s",name);
PERL_PREPROCESS  sprintf(spec->type,"XXXXX");
PERL_PREPROCESS  spec->size  = size;
PERL_PREPROCESS  spec->index = 0;
PERL_PREPROCESS  spec->pndex = size-1;
PERL_PREPROCESS  bzero(&spec->theSum,sizeof(XXXXX));
PERL_PREPROCESS
PERL_PREPROCESS  return(spec);
#endif
/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/

iccBufferFLT32_t *iccBufferInitFLT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE FLT32      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferFLT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferFLT32_t *)malloc(sizeof(iccBufferFLT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (FLT32 *)malloc(size*sizeof(FLT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(FLT32));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"FLT32");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(FLT32));

  return(spec);
//------------------------------- COMMON-CODE FLT32       STOP.
}

iccBufferFLT64_t *iccBufferInitFLT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE FLT64      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferFLT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferFLT64_t *)malloc(sizeof(iccBufferFLT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (FLT64 *)malloc(size*sizeof(FLT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(FLT64));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"FLT64");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(FLT64));

  return(spec);
//------------------------------- COMMON-CODE FLT64       STOP.
}

iccBufferFLT96_t *iccBufferInitFLT96( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE FLT96      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferFLT96_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferFLT96_t *)malloc(sizeof(iccBufferFLT96_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (FLT96 *)malloc(size*sizeof(FLT96))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(FLT96));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"FLT96");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(FLT96));

  return(spec);
//------------------------------- COMMON-CODE FLT96       STOP.
}

// Initialize the INT08 buffer -------------------------------------------------
iccBufferINT08_t *iccBufferInitINT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE INT08      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferINT08_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferINT08_t *)malloc(sizeof(iccBufferINT08_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (INT08 *)malloc(size*sizeof(INT08))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(INT08));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"INT08");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(INT08));

  return(spec);
//------------------------------- COMMON-CODE INT08       STOP.
}

// Initialize the INT16 buffer -------------------------------------------------
iccBufferINT16_t *iccBufferInitINT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE INT16      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferINT16_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferINT16_t *)malloc(sizeof(iccBufferINT16_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (INT16 *)malloc(size*sizeof(INT16))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(INT16));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"INT16");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(INT16));

  return(spec);
//------------------------------- COMMON-CODE INT16       STOP.
}

// Initialize the INT32 buffer -------------------------------------------------
iccBufferINT32_t *iccBufferInitINT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE INT32      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferINT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferINT32_t *)malloc(sizeof(iccBufferINT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (INT32 *)malloc(size*sizeof(INT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(INT32));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"INT32");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(INT32));

  return(spec);
//------------------------------- COMMON-CODE INT32       STOP.
}

// Initialize the INT64 buffer -------------------------------------------------
iccBufferINT64_t *iccBufferInitINT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE INT64      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferINT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferINT64_t *)malloc(sizeof(iccBufferINT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (INT64 *)malloc(size*sizeof(INT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(INT64));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"INT64");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(INT64));

  return(spec);
//------------------------------- COMMON-CODE INT64       STOP.
}
// Initialize the UNT08 buffer -------------------------------------------------
iccBufferUNT08_t *iccBufferInitUNT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE UNT08      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferUNT08_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferUNT08_t *)malloc(sizeof(iccBufferUNT08_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (UNT08 *)malloc(size*sizeof(UNT08))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(UNT08));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"UNT08");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(UNT08));

  return(spec);
//------------------------------- COMMON-CODE UNT08       STOP.
}

// Initialize the UNT16 buffer -------------------------------------------------
iccBufferUNT16_t *iccBufferInitUNT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE UNT16      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferUNT16_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferUNT16_t *)malloc(sizeof(iccBufferUNT16_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (UNT16 *)malloc(size*sizeof(UNT16))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(UNT16));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"UNT16");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(UNT16));

  return(spec);
//------------------------------- COMMON-CODE UNT16       STOP.
}

// Initialize the UNT32 buffer -------------------------------------------------
iccBufferUNT32_t *iccBufferInitUNT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE UNT32      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferUNT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferUNT32_t *)malloc(sizeof(iccBufferUNT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (UNT32 *)malloc(size*sizeof(UNT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(UNT32));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"UNT32");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(UNT32));

  return(spec);
//------------------------------- COMMON-CODE UNT32       STOP.
}

// Initialize the UNT64 buffer -------------------------------------------------
iccBufferUNT64_t *iccBufferInitUNT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE UNT64      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferUNT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferUNT64_t *)malloc(sizeof(iccBufferUNT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (UNT64 *)malloc(size*sizeof(UNT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(UNT64));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"UNT64");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(UNT64));

  return(spec);
//------------------------------- COMMON-CODE UNT64       STOP.
}

// Initialize the VOIDP buffer -------------------------------------------------
iccBufferVOIDP_t *iccBufferInitVOIDP( UNT32 size, CCHAR *name )
{
  // !! NEED TO CHANGE !!
  // if((spec->theBuffer= (VOIDP *)malloc(size*sizeof(VOIDP ))) == NULL)
  // if((spec->theBuffer= (VOID  *)malloc(size*sizeof(VOID *))) == NULL)
  // !! NEED TO CHANGE !!

//------------------------------- COMMON-CODE VOIDP      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferVOIDP_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferVOIDP_t *)malloc(sizeof(iccBufferVOIDP_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (VOID  *)malloc(size*sizeof(VOID *))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(VOID *));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"VOIDP");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;

  return(spec);
//------------------------------- COMMON-CODE VOIDP       STOP.
}

// Initialize the CFLT32 buffer -------------------------------------------------
iccBufferCFLT32_t *iccBufferInitCFLT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CFLT32      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferCFLT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferCFLT32_t *)malloc(sizeof(iccBufferCFLT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (CFLT32 *)malloc(size*sizeof(CFLT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(CFLT32));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"CFLT32");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(CFLT32));

  return(spec);
//------------------------------- COMMON-CODE CFLT32       STOP.
}

// Initialize the CFLT64 buffer -------------------------------------------------
iccBufferCFLT64_t *iccBufferInitCFLT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CFLT64      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferCFLT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferCFLT64_t *)malloc(sizeof(iccBufferCFLT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (CFLT64 *)malloc(size*sizeof(CFLT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(CFLT64));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"CFLT64");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(CFLT64));

  return(spec);
//------------------------------- COMMON-CODE CFLT64       STOP.
}

// Initialize the CFLT96 buffer -------------------------------------------------
iccBufferCFLT96_t *iccBufferInitCFLT96( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CFLT96      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferCFLT96_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferCFLT96_t *)malloc(sizeof(iccBufferCFLT96_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (CFLT96 *)malloc(size*sizeof(CFLT96))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(CFLT96));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"CFLT96");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(CFLT96));

  return(spec);
//------------------------------- COMMON-CODE CFLT96       STOP.
}

// Initialize the CINT08 buffer -------------------------------------------------
iccBufferCINT08_t *iccBufferInitCINT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CINT08      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferCINT08_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferCINT08_t *)malloc(sizeof(iccBufferCINT08_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (CINT08 *)malloc(size*sizeof(CINT08))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(CINT08));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"CINT08");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(CINT08));

  return(spec);
//------------------------------- COMMON-CODE CINT08       STOP.
}

// Initialize the CINT16 buffer -------------------------------------------------
iccBufferCINT16_t *iccBufferInitCINT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CINT16    START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferCINT16_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferCINT16_t *)malloc(sizeof(iccBufferCINT16_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (CINT16 *)malloc(size*sizeof(CINT16))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(CINT16));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"CINT16");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(CINT16));

  return(spec);
//------------------------------- COMMON-CODE CINT16     STOP.
}

// Initialize the CINT32 buffer -------------------------------------------------
iccBufferCINT32_t *iccBufferInitCINT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CINT32      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferCINT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferCINT32_t *)malloc(sizeof(iccBufferCINT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (CINT32 *)malloc(size*sizeof(CINT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(CINT32));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"CINT32");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(CINT32));

  return(spec);
//------------------------------- COMMON-CODE CINT32       STOP.
}

// Initialize the CINT64 buffer -------------------------------------------------
iccBufferCINT64_t *iccBufferInitCINT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CINT64      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferCINT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferCINT64_t *)malloc(sizeof(iccBufferCINT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (CINT64 *)malloc(size*sizeof(CINT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(CINT64));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"CINT64");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(CINT64));

  return(spec);
//------------------------------- COMMON-CODE CINT64       STOP.
}
// Initialize the CUNT08 buffer -------------------------------------------------
iccBufferCUNT08_t *iccBufferInitCUNT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CUNT08      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferCUNT08_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferCUNT08_t *)malloc(sizeof(iccBufferCUNT08_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (CUNT08 *)malloc(size*sizeof(CUNT08))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(CUNT08));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"CUNT08");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(CUNT08));

  return(spec);
//------------------------------- COMMON-CODE CUNT08       STOP.
}

// Initialize the CUNT16 buffer -------------------------------------------------
iccBufferCUNT16_t *iccBufferInitCUNT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CUNT16      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferCUNT16_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferCUNT16_t *)malloc(sizeof(iccBufferCUNT16_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (CUNT16 *)malloc(size*sizeof(CUNT16))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(CUNT16));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"CUNT16");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(CUNT16));

  return(spec);
//------------------------------- COMMON-CODE CUNT16       STOP.
}

// Initialize the CUNT32 buffer -------------------------------------------------
iccBufferCUNT32_t *iccBufferInitCUNT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CUNT32      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferCUNT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferCUNT32_t *)malloc(sizeof(iccBufferCUNT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (CUNT32 *)malloc(size*sizeof(CUNT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(CUNT32));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"CUNT32");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(CUNT32));

  return(spec);
//------------------------------- COMMON-CODE CUNT32       STOP.
}

// Initialize the CUNT64 buffer -------------------------------------------------
iccBufferCUNT64_t *iccBufferInitCUNT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CUNT64      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferCUNT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferCUNT64_t *)malloc(sizeof(iccBufferCUNT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (CUNT64 *)malloc(size*sizeof(CUNT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(CUNT64));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"CUNT64");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(CUNT64));

  return(spec);
//------------------------------- COMMON-CODE CUNT64       STOP.
}

// Initialize the VFLT32 buffer -------------------------------------------------
iccBufferVFLT32_t *iccBufferInitVFLT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VFLT32      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferVFLT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferVFLT32_t *)malloc(sizeof(iccBufferVFLT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (VFLT32 *)malloc(size*sizeof(VFLT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(VFLT32));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"VFLT32");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(VFLT32));

  return(spec);
//------------------------------- COMMON-CODE VFLT32       STOP.
}

// Initialize the VFLT64 buffer -------------------------------------------------
iccBufferVFLT64_t *iccBufferInitVFLT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VFLT64      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferVFLT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferVFLT64_t *)malloc(sizeof(iccBufferVFLT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (VFLT64 *)malloc(size*sizeof(VFLT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(VFLT64));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"VFLT64");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(VFLT64));

  return(spec);
//------------------------------- COMMON-CODE VFLT64       STOP.
}

// Initialize the VFLT96 buffer -------------------------------------------------
iccBufferVFLT96_t *iccBufferInitVFLT96( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VFLT96      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferVFLT96_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferVFLT96_t *)malloc(sizeof(iccBufferVFLT96_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (VFLT96 *)malloc(size*sizeof(VFLT96))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(VFLT96));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"VFLT96");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(VFLT96));

  return(spec);
//------------------------------- COMMON-CODE VFLT96       STOP.
}

// Initialize the VINT08 buffer -------------------------------------------------
iccBufferVINT08_t *iccBufferInitVINT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VINT08      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferVINT08_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferVINT08_t *)malloc(sizeof(iccBufferVINT08_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (VINT08 *)malloc(size*sizeof(VINT08))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(VINT08));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"VINT08");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(VINT08));

  return(spec);
//------------------------------- COMMON-CODE VINT08       STOP.
}

// Initialize the VINT16 buffer -------------------------------------------------
iccBufferVINT16_t *iccBufferInitVINT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VINT16    START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferVINT16_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferVINT16_t *)malloc(sizeof(iccBufferVINT16_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (VINT16 *)malloc(size*sizeof(VINT16))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(VINT16));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"VINT16");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(VINT16));

  return(spec);
//------------------------------- COMMON-CODE VINT16     STOP.
}

// Initialize the VINT32 buffer -------------------------------------------------
iccBufferVINT32_t *iccBufferInitVINT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VINT32      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferVINT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferVINT32_t *)malloc(sizeof(iccBufferVINT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (VINT32 *)malloc(size*sizeof(VINT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(VINT32));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"VINT32");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(VINT32));

  return(spec);
//------------------------------- COMMON-CODE VINT32       STOP.
}

// Initialize the VINT64 buffer
//------------------------------------------------------------------------------
iccBufferVINT64_t *iccBufferInitVINT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VINT64      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferVINT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferVINT64_t *)malloc(sizeof(iccBufferVINT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (VINT64 *)malloc(size*sizeof(VINT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(VINT64));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"VINT64");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(VINT64));

  return(spec);
//------------------------------- COMMON-CODE VINT64       STOP.
}
// Initialize the VUNT08 buffer -------------------------------------------------
iccBufferVUNT08_t *iccBufferInitVUNT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VUNT08      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferVUNT08_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferVUNT08_t *)malloc(sizeof(iccBufferVUNT08_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (VUNT08 *)malloc(size*sizeof(VUNT08))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(VUNT08));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"VUNT08");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(VUNT08));

  return(spec);
//------------------------------- COMMON-CODE VUNT08       STOP.
}

// Initialize the VUNT16 buffer -------------------------------------------------
iccBufferVUNT16_t *iccBufferInitVUNT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VUNT16      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferVUNT16_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferVUNT16_t *)malloc(sizeof(iccBufferVUNT16_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (VUNT16 *)malloc(size*sizeof(VUNT16))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(VUNT16));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"VUNT16");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(VUNT16));

  return(spec);
//------------------------------- COMMON-CODE VUNT16       STOP.
}

// Initialize the VUNT32 buffer -------------------------------------------------
iccBufferVUNT32_t *iccBufferInitVUNT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VUNT32      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferVUNT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferVUNT32_t *)malloc(sizeof(iccBufferVUNT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (VUNT32 *)malloc(size*sizeof(VUNT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(VUNT32));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"VUNT32");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(VUNT32));

  return(spec);
//------------------------------- COMMON-CODE VUNT32       STOP.
}

// Initialize the VUNT64 buffer -------------------------------------------------
iccBufferVUNT64_t *iccBufferInitVUNT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VUNT64      START.
  /* Variables -----------------------------------------------------------------*/
  iccBufferVUNT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>icc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (iccBufferVUNT64_t *)malloc(sizeof(iccBufferVUNT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the buffer -------------------------------------------------------*/
  if((spec->theBuffer = (VUNT64 *)malloc(size*sizeof(VUNT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Zero out the buffer -------------------------------------------------------*/
  bzero(spec->theBuffer,size*sizeof(VUNT64));

  /* Set the name, type, size, index and then return----------------------------*/
  sprintf(spec->name,"%s",name);
  sprintf(spec->type,"VUNT64");
  spec->size  = size;
  spec->index = 0;
  spec->pndex = size-1;
  bzero(&spec->theSum,sizeof(VUNT64));

  return(spec);
//------------------------------- COMMON-CODE VUNT64       STOP.
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/

/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
