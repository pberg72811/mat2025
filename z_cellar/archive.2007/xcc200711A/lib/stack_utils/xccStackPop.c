/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccStackPop.c
// Desc: This file contains the code for the xccStackPop routine.
// Hist: When       Who  What
//       05/01/2001 ptb  Initial Code.
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
PERL_PREPROCESS_START
PERL_PREPROCESS  if(p2Stack->index < 0) /*Stack Empty*/
PERL_PREPROCESS  {
PERL_PREPROCESS    *p2value = 0;
PERL_PREPROCESS    return(-1);
PERL_PREPROCESS  }
PERL_PREPROCESS  else
PERL_PREPROCESS  {
PERL_PREPROCESS    *p2value = p2Stack->theStack[p2Stack->index];
PERL_PREPROCESS    p2Stack->theStack[p2Stack->index] = 0;
PERL_PREPROCESS    p2Stack->index--;
PERL_PREPROCESS    return(0);
PERL_PREPROCESS  }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
// Rout: xccStackPop
// Desc: These routines pop values from stacks.
//------------------------------------------------------------------------------
INT32 xccStackPopFLT32( xccStackFLT32_t *p2Stack, FLT32 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    *p2value = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index] = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackPopFLT64( xccStackFLT64_t *p2Stack, FLT64 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    *p2value = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index] = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopFLT96( xccStackFLT96_t *p2Stack, FLT96 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    *p2value = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index] = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackPopINT08( xccStackINT08_t *p2Stack, INT08 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    *p2value = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index] = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackPopINT16( xccStackINT16_t *p2Stack, INT16 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    *p2value = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index] = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopINT32( xccStackINT32_t *p2Stack, INT32 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    *p2value = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index] = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopINT64( xccStackINT64_t *p2Stack, INT64 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    *p2value = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index] = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopUNT08( xccStackUNT08_t *p2Stack, UNT08 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    *p2value = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index] = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopUNT16( xccStackUNT16_t *p2Stack, UNT16 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    *p2value = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index] = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopUNT32( xccStackUNT32_t *p2Stack, UNT32 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    *p2value = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index] = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopUNT64( xccStackUNT64_t *p2Stack, UNT64 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    *p2value = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index] = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}

//------------------------------------------------------------------------------
// Rout: xccStackPopVOIDP
// Desc: This routine pops VOID pointer values from a stack.
//------------------------------------------------------------------------------

INT32 xccStackPopVOIDP( xccStackVOIDP_t *p2Stack, VOID **p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    *p2value = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index] = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  if(p2Stack->index < 0) /*Stack Empty*/
PERL_PREPROCESS  {
PERL_PREPROCESS    p2value->r = 0;
PERL_PREPROCESS    p2value->i = 0;
PERL_PREPROCESS    return(-1);
PERL_PREPROCESS  }
PERL_PREPROCESS  else
PERL_PREPROCESS  {
PERL_PREPROCESS    *p2value = p2Stack->theStack[p2Stack->index];
PERL_PREPROCESS    p2Stack->theStack[p2Stack->index].r = 0;
PERL_PREPROCESS    p2Stack->theStack[p2Stack->index].i = 0;
PERL_PREPROCESS    p2Stack->index--;
PERL_PREPROCESS    return(0);
PERL_PREPROCESS  }
#endif
//------------------------------------------------------------------------------
// Rout: xccStackPop
// Desc: These routines pop complex values from complex stacks.
//------------------------------------------------------------------------------
INT32 xccStackPopCFLT32( xccStackCFLT32_t *p2Stack, CFLT32 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->r = 0;
    p2value->i = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].r = 0;
    p2Stack->theStack[p2Stack->index].i = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackPopCFLT64( xccStackCFLT64_t *p2Stack, CFLT64 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->r = 0;
    p2value->i = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].r = 0;
    p2Stack->theStack[p2Stack->index].i = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopCFLT96( xccStackCFLT96_t *p2Stack, CFLT96 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->r = 0;
    p2value->i = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].r = 0;
    p2Stack->theStack[p2Stack->index].i = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackPopCINT08( xccStackCINT08_t *p2Stack, CINT08 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->r = 0;
    p2value->i = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].r = 0;
    p2Stack->theStack[p2Stack->index].i = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackPopCINT16( xccStackCINT16_t *p2Stack, CINT16 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->r = 0;
    p2value->i = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].r = 0;
    p2Stack->theStack[p2Stack->index].i = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopCINT32( xccStackCINT32_t *p2Stack, CINT32 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->r = 0;
    p2value->i = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].r = 0;
    p2Stack->theStack[p2Stack->index].i = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopCINT64( xccStackCINT64_t *p2Stack, CINT64 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->r = 0;
    p2value->i = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].r = 0;
    p2Stack->theStack[p2Stack->index].i = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopCUNT08( xccStackCUNT08_t *p2Stack, CUNT08 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->r = 0;
    p2value->i = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].r = 0;
    p2Stack->theStack[p2Stack->index].i = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopCUNT16( xccStackCUNT16_t *p2Stack, CUNT16 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->r = 0;
    p2value->i = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].r = 0;
    p2Stack->theStack[p2Stack->index].i = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopCUNT32( xccStackCUNT32_t *p2Stack, CUNT32 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->r = 0;
    p2value->i = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].r = 0;
    p2Stack->theStack[p2Stack->index].i = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopCUNT64( xccStackCUNT64_t *p2Stack, CUNT64 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->r = 0;
    p2value->i = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].r = 0;
    p2Stack->theStack[p2Stack->index].i = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  if(p2Stack->index < 0) /*Stack Empty*/
PERL_PREPROCESS  {
PERL_PREPROCESS    p2value->x = 0;
PERL_PREPROCESS    p2value->y = 0;
PERL_PREPROCESS    p2value->z = 0;
PERL_PREPROCESS    return(-1);
PERL_PREPROCESS  }
PERL_PREPROCESS  else
PERL_PREPROCESS  {
PERL_PREPROCESS    *p2value = p2Stack->theStack[p2Stack->index];
PERL_PREPROCESS    p2Stack->theStack[p2Stack->index].x = 0;
PERL_PREPROCESS    p2Stack->theStack[p2Stack->index].y = 0;
PERL_PREPROCESS    p2Stack->theStack[p2Stack->index].z = 0;
PERL_PREPROCESS    p2Stack->index--;
PERL_PREPROCESS    return(0);
PERL_PREPROCESS  }
#endif
//------------------------------------------------------------------------------
// Rout: xccStackPop
// Desc: These routines pop Vector values from Vector stacks.
//------------------------------------------------------------------------------
INT32 xccStackPopVFLT32( xccStackVFLT32_t *p2Stack, VFLT32 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->x = 0;
    p2value->y = 0;
    p2value->z = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].x = 0;
    p2Stack->theStack[p2Stack->index].y = 0;
    p2Stack->theStack[p2Stack->index].z = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackPopVFLT64( xccStackVFLT64_t *p2Stack, VFLT64 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->x = 0;
    p2value->y = 0;
    p2value->z = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].x = 0;
    p2Stack->theStack[p2Stack->index].y = 0;
    p2Stack->theStack[p2Stack->index].z = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopVFLT96( xccStackVFLT96_t *p2Stack, VFLT96 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->x = 0;
    p2value->y = 0;
    p2value->z = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].x = 0;
    p2Stack->theStack[p2Stack->index].y = 0;
    p2Stack->theStack[p2Stack->index].z = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackPopVINT08( xccStackVINT08_t *p2Stack, VINT08 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->x = 0;
    p2value->y = 0;
    p2value->z = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].x = 0;
    p2Stack->theStack[p2Stack->index].y = 0;
    p2Stack->theStack[p2Stack->index].z = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackPopVINT16( xccStackVINT16_t *p2Stack, VINT16 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->x = 0;
    p2value->y = 0;
    p2value->z = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].x = 0;
    p2Stack->theStack[p2Stack->index].y = 0;
    p2Stack->theStack[p2Stack->index].z = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopVINT32( xccStackVINT32_t *p2Stack, VINT32 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->x = 0;
    p2value->y = 0;
    p2value->z = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].x = 0;
    p2Stack->theStack[p2Stack->index].y = 0;
    p2Stack->theStack[p2Stack->index].z = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopVINT64( xccStackVINT64_t *p2Stack, VINT64 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->x = 0;
    p2value->y = 0;
    p2value->z = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].x = 0;
    p2Stack->theStack[p2Stack->index].y = 0;
    p2Stack->theStack[p2Stack->index].z = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopVUNT08( xccStackVUNT08_t *p2Stack, VUNT08 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->x = 0;
    p2value->y = 0;
    p2value->z = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].x = 0;
    p2Stack->theStack[p2Stack->index].y = 0;
    p2Stack->theStack[p2Stack->index].z = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopVUNT16( xccStackVUNT16_t *p2Stack, VUNT16 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->x = 0;
    p2value->y = 0;
    p2value->z = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].x = 0;
    p2Stack->theStack[p2Stack->index].y = 0;
    p2Stack->theStack[p2Stack->index].z = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopVUNT32( xccStackVUNT32_t *p2Stack, VUNT32 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->x = 0;
    p2value->y = 0;
    p2value->z = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].x = 0;
    p2Stack->theStack[p2Stack->index].y = 0;
    p2Stack->theStack[p2Stack->index].z = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackPopVUNT64( xccStackVUNT64_t *p2Stack, VUNT64 *p2value )
{
//------------------------------- COMMON-CODE       START.
  if(p2Stack->index < 0) /*Stack Empty*/
  {
    p2value->x = 0;
    p2value->y = 0;
    p2value->z = 0;
    return(-1);
  }
  else
  {
    *p2value = p2Stack->theStack[p2Stack->index];
    p2Stack->theStack[p2Stack->index].x = 0;
    p2Stack->theStack[p2Stack->index].y = 0;
    p2Stack->theStack[p2Stack->index].z = 0;
    p2Stack->index--;
    return(0);
  }
//------------------------------- COMMON-CODE        STOP.
}  

//------------------------------------------------------------------------------
// Rout: xccStringStackPop
// Desc: This routine pops a string pointer from a VOID pointer stack.
//------------------------------------------------------------------------------
INT32 xccStringStackPop( xccStackVOIDP_t *p2Stack, CHR08 **stringPointer )
{

  // Return if stack is empty.
  //----------------------------------------------------------------------------
  if( p2Stack->index < 0 ) return(-1);

  // Decrement the stack index.
  //----------------------------------------------------------------------------
  p2Stack->index--;

  // Return the string.
  //----------------------------------------------------------------------------
  *stringPointer = (CHR08 *)p2Stack->theStack[p2Stack->index+1];
  return (0);
}


/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
