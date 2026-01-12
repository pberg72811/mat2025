/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccStackPush.c
// Desc: This file contains the code for the iccStackPush routine.
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
PERL_PREPROCESS    XMC_ERROR_STDOUT("iccStack Overflow");
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
// Rout: iccStackPush
// Desc: These routines push values onto stacks.
//------------------------------------------------------------------------------
INT32 iccStackPushFLT32( iccStackFLT32_t *p2Stack, FLT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 iccStackPushFLT64( iccStackFLT64_t *p2Stack, FLT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushFLT96( iccStackFLT96_t *p2Stack, FLT96 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 iccStackPushINT08( iccStackINT08_t *p2Stack, INT08 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 iccStackPushINT16( iccStackINT16_t *p2Stack, INT16 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushINT32( iccStackINT32_t *p2Stack, INT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushINT64( iccStackINT64_t *p2Stack, INT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushUNT08( iccStackUNT08_t *p2Stack, UNT08 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushUNT16( iccStackUNT16_t *p2Stack, UNT16 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushUNT32( iccStackUNT32_t *p2Stack, UNT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushUNT64( iccStackUNT64_t *p2Stack, UNT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
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
// Rout: iccStackPushC
// Desc: These routines push values onto complex data stacks.
//------------------------------------------------------------------------------
INT32 iccStackPushCFLT32( iccStackCFLT32_t *p2Stack, CFLT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 iccStackPushCFLT64( iccStackCFLT64_t *p2Stack, CFLT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushCFLT96( iccStackCFLT96_t *p2Stack, CFLT96 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 iccStackPushCINT08( iccStackCINT08_t *p2Stack, CINT08 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 iccStackPushCINT16( iccStackCINT16_t *p2Stack, CINT16 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushCINT32( iccStackCINT32_t *p2Stack, CINT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushCINT64( iccStackCINT64_t *p2Stack, CINT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
} 

INT32 iccStackPushCUNT08( iccStackCUNT08_t *p2Stack, CUNT08 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushCUNT16( iccStackCUNT16_t *p2Stack, CUNT16 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushCUNT32( iccStackCUNT32_t *p2Stack, CUNT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushCUNT64( iccStackCUNT64_t *p2Stack, CUNT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
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
// Rout: iccStackPushC
// Desc: These routines push values onto Vector data stacks.
//------------------------------------------------------------------------------
INT32 iccStackPushVFLT32( iccStackVFLT32_t *p2Stack, VFLT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 iccStackPushVFLT64( iccStackVFLT64_t *p2Stack, VFLT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushVFLT96( iccStackVFLT96_t *p2Stack, VFLT96 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 iccStackPushVINT08( iccStackVINT08_t *p2Stack, VINT08 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 iccStackPushVINT16( iccStackVINT16_t *p2Stack, VINT16 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushVINT32( iccStackVINT32_t *p2Stack, VINT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushVINT64( iccStackVINT64_t *p2Stack, VINT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}

INT32 iccStackPushVUNT08( iccStackVUNT08_t *p2Stack, VUNT08 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushVUNT16( iccStackVUNT16_t *p2Stack, VUNT16 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushVUNT32( iccStackVUNT32_t *p2Stack, VUNT32 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
    return(-1);
  }

  else
  {
    p2Stack->theStack[p2Stack->index] = value;
    return(0);
  }
//------------------------------- COMMON-CODE    STOP.
}
 
INT32 iccStackPushVUNT64( iccStackVUNT64_t *p2Stack, VUNT64 value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
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
// Rout: iccStackPushVOIDP
// Desc: This routine pushes a value onto a VOID pointer stack.
//------------------------------------------------------------------------------
INT32 iccStackPushVOIDP( iccStackVOIDP_t *p2Stack, VOID *value )
{
//------------------------------- COMMON-CODE   START.
  p2Stack->index++;

  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
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
// Rout: iccStringStackPush
// Desc: This routine pushes a string pointer onto a VOID pointer stack.
// Note: Add one to the string length to account for the "\0".
//------------------------------------------------------------------------------
INT32 iccStringStackPush( iccStackVOIDP_t *p2Stack, const CHR08 *string )
{
  CHR08 *stringToPush;

  p2Stack->index++;  // Increment the stack index.
                                                        
  // If there is not a stack overflow.
  //----------------------------------------------------------------------------
  if(p2Stack->index >= p2Stack->size)
  {
    p2Stack->index--;
    printf("%s\n",p2Stack->name);
    XMC_ERROR_STDOUT("iccStack Overflow");
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
// Rout: iccStringStackSearch
// Desc: This routine searches for a specified string in a string stack.
// Rtrn: Returns 1 if string found and 0 if not found.
//------------------------------------------------------------------------------
INT32 iccStringStackSearch( iccStackVOIDP_t *p2Stack, const CHR08 *stringToLookFor )
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
