/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccBufferInit.c
// Desc: This file contains the code for the xccBufferInit routine.
// Hist: When       Who  What
//       08/22/2003 ptb  Initial Code.  Copied from xccStackUtils.
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
PERL_PREPROCESS  xccBufferXXXXX_t *spec;
PERL_PREPROCESS
PERL_PREPROCESS  /* Check name length ---------------------------------------------------------*/
PERL_PREPROCESS  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
PERL_PREPROCESS  {
PERL_PREPROCESS    xcc_ERROR_MESSAGE("xcc_BUFFER NAME TOO LONG");
PERL_PREPROCESS    return(NULL);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  /* Allocate buffer structure -------------------------------------------------*/
PERL_PREPROCESS  if((spec = (xccBufferXXXXX_t *)malloc(sizeof(xccBufferXXXXX_t))) == NULL)
PERL_PREPROCESS  {
PERL_PREPROCESS    xcc_ERROR_MESSAGE("MEMORY ALLOCATION ERROR");
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

xccBufferFLT32_t *xccBufferInitFLT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE FLT32      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferFLT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferFLT32_t *)malloc(sizeof(xccBufferFLT32_t))) == NULL)
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

xccBufferFLT64_t *xccBufferInitFLT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE FLT64      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferFLT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferFLT64_t *)malloc(sizeof(xccBufferFLT64_t))) == NULL)
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

xccBufferFLT96_t *xccBufferInitFLT96( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE FLT96      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferFLT96_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferFLT96_t *)malloc(sizeof(xccBufferFLT96_t))) == NULL)
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
xccBufferINT08_t *xccBufferInitINT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE INT08      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferINT08_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferINT08_t *)malloc(sizeof(xccBufferINT08_t))) == NULL)
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
xccBufferINT16_t *xccBufferInitINT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE INT16      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferINT16_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferINT16_t *)malloc(sizeof(xccBufferINT16_t))) == NULL)
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
xccBufferINT32_t *xccBufferInitINT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE INT32      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferINT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferINT32_t *)malloc(sizeof(xccBufferINT32_t))) == NULL)
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
xccBufferINT64_t *xccBufferInitINT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE INT64      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferINT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferINT64_t *)malloc(sizeof(xccBufferINT64_t))) == NULL)
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
xccBufferUNT08_t *xccBufferInitUNT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE UNT08      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferUNT08_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferUNT08_t *)malloc(sizeof(xccBufferUNT08_t))) == NULL)
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
xccBufferUNT16_t *xccBufferInitUNT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE UNT16      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferUNT16_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferUNT16_t *)malloc(sizeof(xccBufferUNT16_t))) == NULL)
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
xccBufferUNT32_t *xccBufferInitUNT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE UNT32      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferUNT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferUNT32_t *)malloc(sizeof(xccBufferUNT32_t))) == NULL)
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
xccBufferUNT64_t *xccBufferInitUNT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE UNT64      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferUNT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferUNT64_t *)malloc(sizeof(xccBufferUNT64_t))) == NULL)
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
xccBufferVOIDP_t *xccBufferInitVOIDP( UNT32 size, CCHAR *name )
{
  // !! NEED TO CHANGE !!
  // if((spec->theBuffer= (VOIDP *)malloc(size*sizeof(VOIDP ))) == NULL)
  // if((spec->theBuffer= (VOID  *)malloc(size*sizeof(VOID *))) == NULL)
  // !! NEED TO CHANGE !!

//------------------------------- COMMON-CODE VOIDP      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferVOIDP_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferVOIDP_t *)malloc(sizeof(xccBufferVOIDP_t))) == NULL)
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
xccBufferCFLT32_t *xccBufferInitCFLT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CFLT32      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferCFLT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferCFLT32_t *)malloc(sizeof(xccBufferCFLT32_t))) == NULL)
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
xccBufferCFLT64_t *xccBufferInitCFLT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CFLT64      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferCFLT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferCFLT64_t *)malloc(sizeof(xccBufferCFLT64_t))) == NULL)
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
xccBufferCFLT96_t *xccBufferInitCFLT96( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CFLT96      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferCFLT96_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferCFLT96_t *)malloc(sizeof(xccBufferCFLT96_t))) == NULL)
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
xccBufferCINT08_t *xccBufferInitCINT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CINT08      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferCINT08_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferCINT08_t *)malloc(sizeof(xccBufferCINT08_t))) == NULL)
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
xccBufferCINT16_t *xccBufferInitCINT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CINT16    START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferCINT16_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferCINT16_t *)malloc(sizeof(xccBufferCINT16_t))) == NULL)
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
xccBufferCINT32_t *xccBufferInitCINT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CINT32      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferCINT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferCINT32_t *)malloc(sizeof(xccBufferCINT32_t))) == NULL)
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
xccBufferCINT64_t *xccBufferInitCINT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CINT64      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferCINT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferCINT64_t *)malloc(sizeof(xccBufferCINT64_t))) == NULL)
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
xccBufferCUNT08_t *xccBufferInitCUNT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CUNT08      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferCUNT08_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferCUNT08_t *)malloc(sizeof(xccBufferCUNT08_t))) == NULL)
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
xccBufferCUNT16_t *xccBufferInitCUNT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CUNT16      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferCUNT16_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferCUNT16_t *)malloc(sizeof(xccBufferCUNT16_t))) == NULL)
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
xccBufferCUNT32_t *xccBufferInitCUNT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CUNT32      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferCUNT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferCUNT32_t *)malloc(sizeof(xccBufferCUNT32_t))) == NULL)
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
xccBufferCUNT64_t *xccBufferInitCUNT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CUNT64      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferCUNT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferCUNT64_t *)malloc(sizeof(xccBufferCUNT64_t))) == NULL)
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
xccBufferVFLT32_t *xccBufferInitVFLT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VFLT32      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferVFLT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferVFLT32_t *)malloc(sizeof(xccBufferVFLT32_t))) == NULL)
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
xccBufferVFLT64_t *xccBufferInitVFLT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VFLT64      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferVFLT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferVFLT64_t *)malloc(sizeof(xccBufferVFLT64_t))) == NULL)
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
xccBufferVFLT96_t *xccBufferInitVFLT96( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VFLT96      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferVFLT96_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferVFLT96_t *)malloc(sizeof(xccBufferVFLT96_t))) == NULL)
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
xccBufferVINT08_t *xccBufferInitVINT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VINT08      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferVINT08_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferVINT08_t *)malloc(sizeof(xccBufferVINT08_t))) == NULL)
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
xccBufferVINT16_t *xccBufferInitVINT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VINT16    START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferVINT16_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferVINT16_t *)malloc(sizeof(xccBufferVINT16_t))) == NULL)
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
xccBufferVINT32_t *xccBufferInitVINT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VINT32      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferVINT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferVINT32_t *)malloc(sizeof(xccBufferVINT32_t))) == NULL)
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
xccBufferVINT64_t *xccBufferInitVINT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VINT64      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferVINT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferVINT64_t *)malloc(sizeof(xccBufferVINT64_t))) == NULL)
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
xccBufferVUNT08_t *xccBufferInitVUNT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VUNT08      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferVUNT08_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferVUNT08_t *)malloc(sizeof(xccBufferVUNT08_t))) == NULL)
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
xccBufferVUNT16_t *xccBufferInitVUNT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VUNT16      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferVUNT16_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferVUNT16_t *)malloc(sizeof(xccBufferVUNT16_t))) == NULL)
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
xccBufferVUNT32_t *xccBufferInitVUNT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VUNT32      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferVUNT32_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferVUNT32_t *)malloc(sizeof(xccBufferVUNT32_t))) == NULL)
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
xccBufferVUNT64_t *xccBufferInitVUNT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VUNT64      START.
  /* Variables -----------------------------------------------------------------*/
  xccBufferVUNT64_t *spec;

  /* Check name length ---------------------------------------------------------*/
  if( strlen(name)>xcc_BUFFER_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_BUFFER NAME TOO LONG");
    return(NULL);
  }

  /* Allocate buffer structure -------------------------------------------------*/
  if((spec = (xccBufferVUNT64_t *)malloc(sizeof(xccBufferVUNT64_t))) == NULL)
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
