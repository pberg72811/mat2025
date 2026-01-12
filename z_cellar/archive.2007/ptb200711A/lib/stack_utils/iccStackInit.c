/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccStackInit.c
// Desc: This file contains the code for the iccStackInit routine.
// Hist: When       Who  What
//       04/27/2001 ptb  Initial Code.
//       04/27/2001 ptb  Keep track of the VOIDP section..
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
#if 0
PERL_PREPROCESS  /* Variables ---------------------------------------------------------------*/
PERL_PREPROCESS  iccStackXXXXX_t *ws;
PERL_PREPROCESS
PERL_PREPROCESS  /* Check name length -------------------------------------------------------*/
PERL_PREPROCESS  if( strlen(name)>icc_STACK_NAME_LENGTH )
PERL_PREPROCESS  {
PERL_PREPROCESS    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
PERL_PREPROCESS    return(NULL);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  /* Allocate stack structure ------------------------------------------------*/
PERL_PREPROCESS  if((ws = (iccStackXXXXX_t *)malloc(sizeof(iccStackXXXXX_t))) == NULL)
PERL_PREPROCESS  {
PERL_PREPROCESS    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
PERL_PREPROCESS    return(NULL);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  /* Allocate the stack ------------------------------------------------------*/
PERL_PREPROCESS  if((ws->theStack = (XXXXX *)malloc(size*sizeof(XXXXX))) == NULL)
PERL_PREPROCESS  {
PERL_PREPROCESS    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
PERL_PREPROCESS    return(NULL);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  /* Set the name, type, size, index and then return--------------------------*/
PERL_PREPROCESS  sprintf(ws->name,"%s",name);
PERL_PREPROCESS  sprintf(ws->type,"XXXXX");
PERL_PREPROCESS  ws->size  = size;
PERL_PREPROCESS  ws->index = -1;
PERL_PREPROCESS
PERL_PREPROCESS  return(ws);
#endif
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

// Initialize the FLT32 stack
//-----------------------------------------------------------------------------
iccStackFLT32_t *iccStackInitFLT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE FLT32  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackFLT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackFLT32_t *)malloc(sizeof(iccStackFLT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (FLT32 *)malloc(size*sizeof(FLT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"FLT32");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE FLT32   STOP.
}

// Initialize the FLT64 stack
//-----------------------------------------------------------------------------
iccStackFLT64_t *iccStackInitFLT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE FLT64  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackFLT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackFLT64_t *)malloc(sizeof(iccStackFLT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (FLT64 *)malloc(size*sizeof(FLT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"FLT64");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE FLT64   STOP.
}

// Initialize the FLT96 stack
//-----------------------------------------------------------------------------
iccStackFLT96_t *iccStackInitFLT96( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE FLT96  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackFLT96_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackFLT96_t *)malloc(sizeof(iccStackFLT96_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (FLT96 *)malloc(size*sizeof(FLT96))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"FLT96");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE FLT96   STOP.
}

// Initialize the INT08 stack
//-----------------------------------------------------------------------------
iccStackINT08_t *iccStackInitINT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE INT08  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackINT08_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackINT08_t *)malloc(sizeof(iccStackINT08_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (INT08 *)malloc(size*sizeof(INT08))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"INT08");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE INT08   STOP.
}

// Initialize the INT16 stack
//-----------------------------------------------------------------------------
iccStackINT16_t *iccStackInitINT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE INT16  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackINT16_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackINT16_t *)malloc(sizeof(iccStackINT16_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (INT16 *)malloc(size*sizeof(INT16))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"INT16");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE INT16   STOP.

}

// Initialize the INT32 stack
//-----------------------------------------------------------------------------
iccStackINT32_t *iccStackInitINT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE INT32  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackINT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackINT32_t *)malloc(sizeof(iccStackINT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (INT32 *)malloc(size*sizeof(INT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"INT32");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE INT32   STOP.
}

// Initialize the INT64 stack
//-----------------------------------------------------------------------------
iccStackINT64_t *iccStackInitINT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE INT64  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackINT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackINT64_t *)malloc(sizeof(iccStackINT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (INT64 *)malloc(size*sizeof(INT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"INT64");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE INT64   STOP.
}
// Initialize the UNT08 stack
//-----------------------------------------------------------------------------
iccStackUNT08_t *iccStackInitUNT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE UNT08  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackUNT08_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackUNT08_t *)malloc(sizeof(iccStackUNT08_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (UNT08 *)malloc(size*sizeof(UNT08))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"UNT08");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE UNT08   STOP.
}

// Initialize the UNT16 stack
//-----------------------------------------------------------------------------
iccStackUNT16_t *iccStackInitUNT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE UNT16  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackUNT16_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackUNT16_t *)malloc(sizeof(iccStackUNT16_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (UNT16 *)malloc(size*sizeof(UNT16))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"UNT16");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE UNT16   STOP.
}

// Initialize the UNT32 stack
//-----------------------------------------------------------------------------
iccStackUNT32_t *iccStackInitUNT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE UNT32  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackUNT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackUNT32_t *)malloc(sizeof(iccStackUNT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (UNT32 *)malloc(size*sizeof(UNT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"UNT32");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE UNT32   STOP.
}

// Initialize the UNT64 stack
//-----------------------------------------------------------------------------
iccStackUNT64_t *iccStackInitUNT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE UNT64  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackUNT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackUNT64_t *)malloc(sizeof(iccStackUNT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (UNT64 *)malloc(size*sizeof(UNT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"UNT64");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE UNT64   STOP.
}

// Initialize the VOIDP stack
//-----------------------------------------------------------------------------
iccStackVOIDP_t *iccStackInitVOIDP( UNT32 size, CCHAR *name )
{
  // !! NEED TO CHANGE !!
  // if((ws->theStack = (VOIDP *)malloc(size*sizeof(VOIDP ))) == NULL)
  // if((ws->theStack = (VOID  *)malloc(size*sizeof(VOID *))) == NULL)
  // !! NEED TO CHANGE !!

//------------------------------- COMMON-CODE VOIDP  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackVOIDP_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackVOIDP_t *)malloc(sizeof(iccStackVOIDP_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (VOID *)malloc(size*sizeof(VOID *))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"VOIDP");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE VOIDP   STOP.
}

// Initialize the CFLT32 stack
//-----------------------------------------------------------------------------
iccStackCFLT32_t *iccStackInitCFLT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CFLT32  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackCFLT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackCFLT32_t *)malloc(sizeof(iccStackCFLT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (CFLT32 *)malloc(size*sizeof(CFLT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"CFLT32");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE CFLT32   STOP.
}

// Initialize the CFLT64 stack
//-----------------------------------------------------------------------------
iccStackCFLT64_t *iccStackInitCFLT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CFLT64  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackCFLT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackCFLT64_t *)malloc(sizeof(iccStackCFLT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (CFLT64 *)malloc(size*sizeof(CFLT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"CFLT64");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE CFLT64   STOP.
}

// Initialize the CFLT96 stack
//-----------------------------------------------------------------------------
iccStackCFLT96_t *iccStackInitCFLT96( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CFLT96  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackCFLT96_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackCFLT96_t *)malloc(sizeof(iccStackCFLT96_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (CFLT96 *)malloc(size*sizeof(CFLT96))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"CFLT96");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE CFLT96   STOP.
}

// Initialize the CINT08 stack
//-----------------------------------------------------------------------------
iccStackCINT08_t *iccStackInitCINT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CINT08  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackCINT08_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackCINT08_t *)malloc(sizeof(iccStackCINT08_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (CINT08 *)malloc(size*sizeof(CINT08))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"CINT08");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE CINT08   STOP.
}

// Initialize the CINT16 stack
//-----------------------------------------------------------------------------
iccStackCINT16_t *iccStackInitCINT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CINT16  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackCINT16_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackCINT16_t *)malloc(sizeof(iccStackCINT16_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (CINT16 *)malloc(size*sizeof(CINT16))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"CINT16");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE CINT16   STOP.
}

// Initialize the CINT32 stack
//-----------------------------------------------------------------------------
iccStackCINT32_t *iccStackInitCINT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CINT32  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackCINT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackCINT32_t *)malloc(sizeof(iccStackCINT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (CINT32 *)malloc(size*sizeof(CINT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"CINT32");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE CINT32   STOP.
}

// Initialize the CINT64 stack
//-----------------------------------------------------------------------------
iccStackCINT64_t *iccStackInitCINT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CINT64  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackCINT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackCINT64_t *)malloc(sizeof(iccStackCINT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (CINT64 *)malloc(size*sizeof(CINT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"CINT64");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE CINT64   STOP.
}
// Initialize the CUNT08 stack
//-----------------------------------------------------------------------------
iccStackCUNT08_t *iccStackInitCUNT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CUNT08  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackCUNT08_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackCUNT08_t *)malloc(sizeof(iccStackCUNT08_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (CUNT08 *)malloc(size*sizeof(CUNT08))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"CUNT08");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE CUNT08   STOP.
}

// Initialize the CUNT16 stack
//-----------------------------------------------------------------------------
iccStackCUNT16_t *iccStackInitCUNT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CUNT16  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackCUNT16_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackCUNT16_t *)malloc(sizeof(iccStackCUNT16_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (CUNT16 *)malloc(size*sizeof(CUNT16))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"CUNT16");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE CUNT16   STOP.
}

// Initialize the CUNT32 stack
//-----------------------------------------------------------------------------
iccStackCUNT32_t *iccStackInitCUNT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CUNT32  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackCUNT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackCUNT32_t *)malloc(sizeof(iccStackCUNT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (CUNT32 *)malloc(size*sizeof(CUNT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"CUNT32");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE CUNT32   STOP.
}

// Initialize the CUNT64 stack
//-----------------------------------------------------------------------------
iccStackCUNT64_t *iccStackInitCUNT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CUNT64  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackCUNT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackCUNT64_t *)malloc(sizeof(iccStackCUNT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (CUNT64 *)malloc(size*sizeof(CUNT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"CUNT64");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE CUNT64   STOP.
}

// Initialize the VFLT32 stack
//-----------------------------------------------------------------------------
iccStackVFLT32_t *iccStackInitVFLT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VFLT32  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackVFLT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackVFLT32_t *)malloc(sizeof(iccStackVFLT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (VFLT32 *)malloc(size*sizeof(VFLT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"VFLT32");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE VFLT32   STOP.
}

// Initialize the VFLT64 stack
//-----------------------------------------------------------------------------
iccStackVFLT64_t *iccStackInitVFLT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VFLT64  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackVFLT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackVFLT64_t *)malloc(sizeof(iccStackVFLT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (VFLT64 *)malloc(size*sizeof(VFLT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"VFLT64");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE VFLT64   STOP.
}

// Initialize the VFLT96 stack
//-----------------------------------------------------------------------------
iccStackVFLT96_t *iccStackInitVFLT96( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VFLT96  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackVFLT96_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackVFLT96_t *)malloc(sizeof(iccStackVFLT96_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (VFLT96 *)malloc(size*sizeof(VFLT96))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"VFLT96");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE VFLT96   STOP.
}

// Initialize the VINT08 stack
//-----------------------------------------------------------------------------
iccStackVINT08_t *iccStackInitVINT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VINT08  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackVINT08_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackVINT08_t *)malloc(sizeof(iccStackVINT08_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (VINT08 *)malloc(size*sizeof(VINT08))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"VINT08");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE VINT08   STOP.
}

// Initialize the VINT16 stack
//-----------------------------------------------------------------------------
iccStackVINT16_t *iccStackInitVINT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VINT16  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackVINT16_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackVINT16_t *)malloc(sizeof(iccStackVINT16_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (VINT16 *)malloc(size*sizeof(VINT16))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"VINT16");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE VINT16   STOP.
}

// Initialize the VINT32 stack
//-----------------------------------------------------------------------------
iccStackVINT32_t *iccStackInitVINT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VINT32  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackVINT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackVINT32_t *)malloc(sizeof(iccStackVINT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (VINT32 *)malloc(size*sizeof(VINT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"VINT32");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE VINT32   STOP.
}

// Initialize the VINT64 stack
//-----------------------------------------------------------------------------
iccStackVINT64_t *iccStackInitVINT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VINT64  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackVINT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackVINT64_t *)malloc(sizeof(iccStackVINT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (VINT64 *)malloc(size*sizeof(VINT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"VINT64");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE VINT64   STOP.
}
// Initialize the VUNT08 stack
//-----------------------------------------------------------------------------
iccStackVUNT08_t *iccStackInitVUNT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VUNT08  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackVUNT08_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackVUNT08_t *)malloc(sizeof(iccStackVUNT08_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (VUNT08 *)malloc(size*sizeof(VUNT08))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"VUNT08");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE VUNT08   STOP.
}

// Initialize the VUNT16 stack
//-----------------------------------------------------------------------------
iccStackVUNT16_t *iccStackInitVUNT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VUNT16  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackVUNT16_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackVUNT16_t *)malloc(sizeof(iccStackVUNT16_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (VUNT16 *)malloc(size*sizeof(VUNT16))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"VUNT16");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE VUNT16   STOP.
}

// Initialize the VUNT32 stack
//-----------------------------------------------------------------------------
iccStackVUNT32_t *iccStackInitVUNT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VUNT32  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackVUNT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackVUNT32_t *)malloc(sizeof(iccStackVUNT32_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (VUNT32 *)malloc(size*sizeof(VUNT32))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"VUNT32");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE VUNT32   STOP.
}

// Initialize the VUNT64 stack
//-----------------------------------------------------------------------------
iccStackVUNT64_t *iccStackInitVUNT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VUNT64  START.
  /* Variables ---------------------------------------------------------------*/
  iccStackVUNT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>icc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("icc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (iccStackVUNT64_t *)malloc(sizeof(iccStackVUNT64_t))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Allocate the stack ------------------------------------------------------*/
  if((ws->theStack = (VUNT64 *)malloc(size*sizeof(VUNT64))) == NULL)
  {
    XMC_ERROR_STDOUT("MEMORY ALLOCATION ERROR");
    return(NULL);
  }

  /* Set the name, type, size, index and then return--------------------------*/
  sprintf(ws->name,"%s",name);
  sprintf(ws->type,"VUNT64");
  ws->size  = size;
  ws->index = -1;

  return(ws);
//------------------------------- COMMON-CODE VUNT64   STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
