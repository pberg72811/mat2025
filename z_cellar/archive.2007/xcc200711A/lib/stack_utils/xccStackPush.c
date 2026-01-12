/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccStackPush.c
// Desc: This file contains the code for the xccStackPush routine.
// Hist: When       Who  What
//       05/01/2001 ptb  Initial Code.
//       12/13/2003 ptb  Added complex and Vector data types.
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
PERL_PREPROCESS  p2Stack->index++;
PERL_PREPROCESS
PERL_PREPROCESS  if(p2Stack->index >= p2Stack->size)
PERL_PREPROCESS  {
PERL_PREPROCESS    p2Stack->index--;
PERL_PREPROCESS    printf("%s\n",p2Stack->name);
PERL_PREPROCESS    XMC_ERROR_STDOUT("xccStack Overflow");
PERL_PREPROCESS    return(-1);
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  else
PERL_PREPROCESS  {
PERL_PREPROCESS    p2Stack->theStack[p2Stack->index] = value;
PERL_PREPROCESS    return(0);
PERL_PREPROCESS  }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
// Rout: xccStackPush
// Desc: These routines push values onto stacks.
//------------------------------------------------------------------------------
INT32 xccStackPushFLT32( xccStackFLT32_t *p2Stack, FLT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 xccStackPushFLT64( xccStackFLT64_t *p2Stack, FLT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushFLT96( xccStackFLT96_t *p2Stack, FLT96 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 xccStackPushINT08( xccStackINT08_t *p2Stack, INT08 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 xccStackPushINT16( xccStackINT16_t *p2Stack, INT16 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushINT32( xccStackINT32_t *p2Stack, INT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushINT64( xccStackINT64_t *p2Stack, INT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushUNT08( xccStackUNT08_t *p2Stack, UNT08 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushUNT16( xccStackUNT16_t *p2Stack, UNT16 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushUNT32( xccStackUNT32_t *p2Stack, UNT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushUNT64( xccStackUNT64_t *p2Stack, UNT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

//------------------------------------------------------------------------------
// Rout: xccStackPushC
// Desc: These routines push values onto complex data stacks.
//------------------------------------------------------------------------------
INT32 xccStackPushCFLT32( xccStackCFLT32_t *p2Stack, CFLT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 xccStackPushCFLT64( xccStackCFLT64_t *p2Stack, CFLT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushCFLT96( xccStackCFLT96_t *p2Stack, CFLT96 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 xccStackPushCINT08( xccStackCINT08_t *p2Stack, CINT08 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 xccStackPushCINT16( xccStackCINT16_t *p2Stack, CINT16 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushCINT32( xccStackCINT32_t *p2Stack, CINT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushCINT64( xccStackCINT64_t *p2Stack, CINT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
} 

INT32 xccStackPushCUNT08( xccStackCUNT08_t *p2Stack, CUNT08 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushCUNT16( xccStackCUNT16_t *p2Stack, CUNT16 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushCUNT32( xccStackCUNT32_t *p2Stack, CUNT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushCUNT64( xccStackCUNT64_t *p2Stack, CUNT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

//------------------------------------------------------------------------------
// Rout: xccStackPushC
// Desc: These routines push values onto Vector data stacks.
//------------------------------------------------------------------------------
INT32 xccStackPushVFLT32( xccStackVFLT32_t *p2Stack, VFLT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 xccStackPushVFLT64( xccStackVFLT64_t *p2Stack, VFLT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushVFLT96( xccStackVFLT96_t *p2Stack, VFLT96 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 xccStackPushVINT08( xccStackVINT08_t *p2Stack, VINT08 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 xccStackPushVINT16( xccStackVINT16_t *p2Stack, VINT16 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushVINT32( xccStackVINT32_t *p2Stack, VINT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushVINT64( xccStackVINT64_t *p2Stack, VINT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 xccStackPushVUNT08( xccStackVUNT08_t *p2Stack, VUNT08 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushVUNT16( xccStackVUNT16_t *p2Stack, VUNT16 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushVUNT32( xccStackVUNT32_t *p2Stack, VUNT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 xccStackPushVUNT64( xccStackVUNT64_t *p2Stack, VUNT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}


//------------------------------------------------------------------------------
// Rout: xccStackPushVOIDP
// Desc: This routine pushes a value onto a VOID pointer stack.
//------------------------------------------------------------------------------
INT32 xccStackPushVOIDP( xccStackVOIDP_t *p2Stack, VOID *value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

//------------------------------------------------------------------------------
// Rout: xccStringStackPush
// Desc: This routine pushes a string pointer onto a VOID pointer stack.
// Note: Add one to the string length to account for the "\0".
//------------------------------------------------------------------------------
INT32 xccStringStackPush( xccStackVOIDP_t *p2Stack, const CHR08 *string )
{
  CHR08 *stringToPush;

  p2Stack->index++;  // Increment the stack index.
                                                        
  // If there is not a stack overflow.
  //----------------------------------------------------------------------------
  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("xccStack Overflow");
    return(-1);
  }

  // Then push the string onto the stack.
  //----------------------------------------------------------------------------
  else
  {
    stringToPush = (CHR08 *)malloc( strlen(string) + 1 ); // Create space for the string.
    sprintf(stringToPush,"%s",string);                    // Copy the input string.
    p2Stack->theStack[p2Stack->index] = stringToPush;     // Push the string onto the stack.
    return(0);                                            // Return;
  }
}

//------------------------------------------------------------------------------
// Rout: xccStringStackSearch
// Desc: This routine searches for a specified string in a string stack.
// Rtrn: Returns 1 if string found and 0 if not found.
//------------------------------------------------------------------------------
INT32 xccStringStackSearch( xccStackVOIDP_t *p2Stack, const CHR08 *stringToLookFor )
{
  INT32 ii;
  INT32 stringFound=0;

  // Check for empty stack.
  //----------------------------------------------------------------------------
  if(p2Stack->index < 0)
  {
    printf("%s\n", p2Stack->name);
    XMC_ERROR_STDOUT("Searching on empty stack.");
    return(-1);
  }

  // Look for the string.
  //----------------------------------------------------------------------------
  for( ii=0; ii<=p2Stack->index; ii++)                    // For each item in stack.
  {                                                       //
    if( !strcmp(p2Stack->theStack[ii], stringToLookFor) ) // strcmp returns 0 on match.
    {                                                     //
      stringFound++;                                      // Increment found counter.
    }                                                     //
  }                                                       //
  return( (stringFound > 0) );                            // Return 1 if > 0.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
