/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccStackInit.c
// Desc: This file contains the code for the xccStackInit routine.
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
PERL_PREPROCESS  xccStackXXXXX_t *ws;
PERL_PREPROCESS
PERL_PREPROCESS  /* Check name length -------------------------------------------------------*/
PERL_PREPROCESS  if( strlen(name)>xcc_STACK_NAME_LENGTH )
PERL_PREPROCESS  {
PERL_PREPROCESS    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
PERL_PREPROCESS    return(NULL);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  /* Allocate stack structure ------------------------------------------------*/
PERL_PREPROCESS  if((ws = (xccStackXXXXX_t *)malloc(sizeof(xccStackXXXXX_t))) == NULL)
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
xccStackFLT32_t *xccStackInitFLT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE FLT32  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackFLT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackFLT32_t *)malloc(sizeof(xccStackFLT32_t))) == NULL)
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
xccStackFLT64_t *xccStackInitFLT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE FLT64  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackFLT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackFLT64_t *)malloc(sizeof(xccStackFLT64_t))) == NULL)
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
xccStackFLT96_t *xccStackInitFLT96( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE FLT96  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackFLT96_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackFLT96_t *)malloc(sizeof(xccStackFLT96_t))) == NULL)
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
xccStackINT08_t *xccStackInitINT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE INT08  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackINT08_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackINT08_t *)malloc(sizeof(xccStackINT08_t))) == NULL)
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
xccStackINT16_t *xccStackInitINT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE INT16  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackINT16_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackINT16_t *)malloc(sizeof(xccStackINT16_t))) == NULL)
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
xccStackINT32_t *xccStackInitINT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE INT32  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackINT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackINT32_t *)malloc(sizeof(xccStackINT32_t))) == NULL)
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
xccStackINT64_t *xccStackInitINT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE INT64  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackINT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackINT64_t *)malloc(sizeof(xccStackINT64_t))) == NULL)
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
xccStackUNT08_t *xccStackInitUNT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE UNT08  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackUNT08_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackUNT08_t *)malloc(sizeof(xccStackUNT08_t))) == NULL)
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
xccStackUNT16_t *xccStackInitUNT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE UNT16  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackUNT16_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackUNT16_t *)malloc(sizeof(xccStackUNT16_t))) == NULL)
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
xccStackUNT32_t *xccStackInitUNT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE UNT32  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackUNT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackUNT32_t *)malloc(sizeof(xccStackUNT32_t))) == NULL)
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
xccStackUNT64_t *xccStackInitUNT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE UNT64  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackUNT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackUNT64_t *)malloc(sizeof(xccStackUNT64_t))) == NULL)
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
xccStackVOIDP_t *xccStackInitVOIDP( UNT32 size, CCHAR *name )
{
  // !! NEED TO CHANGE !!
  // if((ws->theStack = (VOIDP *)malloc(size*sizeof(VOIDP ))) == NULL)
  // if((ws->theStack = (VOID  *)malloc(size*sizeof(VOID *))) == NULL)
  // !! NEED TO CHANGE !!

//------------------------------- COMMON-CODE VOIDP  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackVOIDP_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackVOIDP_t *)malloc(sizeof(xccStackVOIDP_t))) == NULL)
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
xccStackCFLT32_t *xccStackInitCFLT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CFLT32  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackCFLT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackCFLT32_t *)malloc(sizeof(xccStackCFLT32_t))) == NULL)
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
xccStackCFLT64_t *xccStackInitCFLT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CFLT64  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackCFLT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackCFLT64_t *)malloc(sizeof(xccStackCFLT64_t))) == NULL)
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
xccStackCFLT96_t *xccStackInitCFLT96( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CFLT96  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackCFLT96_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackCFLT96_t *)malloc(sizeof(xccStackCFLT96_t))) == NULL)
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
xccStackCINT08_t *xccStackInitCINT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CINT08  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackCINT08_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackCINT08_t *)malloc(sizeof(xccStackCINT08_t))) == NULL)
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
xccStackCINT16_t *xccStackInitCINT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CINT16  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackCINT16_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackCINT16_t *)malloc(sizeof(xccStackCINT16_t))) == NULL)
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
xccStackCINT32_t *xccStackInitCINT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CINT32  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackCINT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackCINT32_t *)malloc(sizeof(xccStackCINT32_t))) == NULL)
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
xccStackCINT64_t *xccStackInitCINT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CINT64  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackCINT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackCINT64_t *)malloc(sizeof(xccStackCINT64_t))) == NULL)
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
xccStackCUNT08_t *xccStackInitCUNT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CUNT08  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackCUNT08_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackCUNT08_t *)malloc(sizeof(xccStackCUNT08_t))) == NULL)
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
xccStackCUNT16_t *xccStackInitCUNT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CUNT16  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackCUNT16_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackCUNT16_t *)malloc(sizeof(xccStackCUNT16_t))) == NULL)
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
xccStackCUNT32_t *xccStackInitCUNT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CUNT32  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackCUNT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackCUNT32_t *)malloc(sizeof(xccStackCUNT32_t))) == NULL)
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
xccStackCUNT64_t *xccStackInitCUNT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE CUNT64  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackCUNT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackCUNT64_t *)malloc(sizeof(xccStackCUNT64_t))) == NULL)
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
xccStackVFLT32_t *xccStackInitVFLT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VFLT32  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackVFLT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackVFLT32_t *)malloc(sizeof(xccStackVFLT32_t))) == NULL)
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
xccStackVFLT64_t *xccStackInitVFLT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VFLT64  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackVFLT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackVFLT64_t *)malloc(sizeof(xccStackVFLT64_t))) == NULL)
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
xccStackVFLT96_t *xccStackInitVFLT96( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VFLT96  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackVFLT96_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackVFLT96_t *)malloc(sizeof(xccStackVFLT96_t))) == NULL)
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
xccStackVINT08_t *xccStackInitVINT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VINT08  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackVINT08_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackVINT08_t *)malloc(sizeof(xccStackVINT08_t))) == NULL)
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
xccStackVINT16_t *xccStackInitVINT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VINT16  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackVINT16_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackVINT16_t *)malloc(sizeof(xccStackVINT16_t))) == NULL)
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
xccStackVINT32_t *xccStackInitVINT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VINT32  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackVINT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackVINT32_t *)malloc(sizeof(xccStackVINT32_t))) == NULL)
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
xccStackVINT64_t *xccStackInitVINT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VINT64  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackVINT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackVINT64_t *)malloc(sizeof(xccStackVINT64_t))) == NULL)
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
xccStackVUNT08_t *xccStackInitVUNT08( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VUNT08  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackVUNT08_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackVUNT08_t *)malloc(sizeof(xccStackVUNT08_t))) == NULL)
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
xccStackVUNT16_t *xccStackInitVUNT16( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VUNT16  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackVUNT16_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackVUNT16_t *)malloc(sizeof(xccStackVUNT16_t))) == NULL)
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
xccStackVUNT32_t *xccStackInitVUNT32( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VUNT32  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackVUNT32_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackVUNT32_t *)malloc(sizeof(xccStackVUNT32_t))) == NULL)
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
xccStackVUNT64_t *xccStackInitVUNT64( UNT32 size, CCHAR *name )
{
//------------------------------- COMMON-CODE VUNT64  START.
  /* Variables ---------------------------------------------------------------*/
  xccStackVUNT64_t *ws;

  /* Check name length -------------------------------------------------------*/
  if( strlen(name)>xcc_STACK_NAME_LENGTH )
  {
    XMC_ERROR_STDOUT("xcc_STACK NAME TOO LONG");
    return(NULL);
  }

  /* Allocate stack structure ------------------------------------------------*/
  if((ws = (xccStackVUNT64_t *)malloc(sizeof(xccStackVUNT64_t))) == NULL)
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
