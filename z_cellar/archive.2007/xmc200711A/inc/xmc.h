/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xmc.h
// Desc: This file contains header references for X-Midas Common.
// Hist: When       Who  What
//       10/15/2006 ptb  Initial Port.                                                          -
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#ifndef XMC_H
#define XMC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#include <X11/Xlib.h> 
#include <X11/Xutil.h> 
#include <X11/Xos.h> 
#include <X11/Xatom.h>

#include "xmcDataTypes.h"

#include "xmcDebug.h"
#include "xmc3DTypes.h"
#include "xmcMathStuff.h"
#include "xmcTimeStuff.h"
#include "xmcComplexTypes.h"
#include "xmcPhysicsStuff.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define xmcFree(ptr)                                            /*============================*/\
if( ptr == NULL )                                               /*                            */\
{                                                               /*                            */\
  XMC_ERROR_STDOUT("Pointer Already Free.");                    /*                            */\
}                                                               /* Free allocated memory.     */\
else                                                            /*                            */\
{                                                               /*                            */\
  free(ptr);                                                    /*                            */\
}                                                               /*============================*/

/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/

//extern INT32 G_xmcMemoryEnable;
//extern INT32 G_xmcMemoryAdd;
//extern INT32 G_xmcMemorySub;

//#define ICC_GLOBAL_INIT() 
//INT32 G_xmcMemoryEnable=TRUE; 
//INT32 G_xmcMemoryAdd=0;       
//INT32 G_xmcMemorySub=0;

//#define ICC_GLOBAL_TERM()                                     
//fprintf(stderr, "The number of memory    allocates was %09ld\n", G_xmcMemoryAdd);
//fprintf(stderr, "The number of memory de-allocates was %09ld\n", G_xmcMemorySub);
//fprintf(stderr, "The net result of memory allocates is %09ld\n", G_xmcMemoryAdd-G_xmcMemorySub);
