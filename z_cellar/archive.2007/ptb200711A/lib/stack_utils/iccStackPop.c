/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccStackPop.c
// Desc: This file contains the code for the iccStackPop routine.
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
// Rout: iccStackPop
// Desc: These routines pop values from stacks.
//------------------------------------------------------------------------------
INT32 iccStackPopFLT32( iccStackFLT32_t *p2Stack, FLT32 *p2value )
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

INT32 iccStackPopFLT64( iccStackFLT64_t *p2Stack, FLT64 *p2value )
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
 
INT32 iccStackPopFLT96( iccStackFLT96_t *p2Stack, FLT96 *p2value )
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

INT32 iccStackPopINT08( iccStackINT08_t *p2Stack, INT08 *p2value )
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

INT32 iccStackPopINT16( iccStackINT16_t *p2Stack, INT16 *p2value )
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
 
INT32 iccStackPopINT32( iccStackINT32_t *p2Stack, INT32 *p2value )
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
 
INT32 iccStackPopINT64( iccStackINT64_t *p2Stack, INT64 *p2value )
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
 
INT32 iccStackPopUNT08( iccStackUNT08_t *p2Stack, UNT08 *p2value )
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
 
INT32 iccStackPopUNT16( iccStackUNT16_t *p2Stack, UNT16 *p2value )
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
 
INT32 iccStackPopUNT32( iccStackUNT32_t *p2Stack, UNT32 *p2value )
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
 
INT32 iccStackPopUNT64( iccStackUNT64_t *p2Stack, UNT64 *p2value )
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
// Rout: iccStackPopVOIDP
// Desc: This routine pops VOID pointer values from a stack.
//------------------------------------------------------------------------------

INT32 iccStackPopVOIDP( iccStackVOIDP_t *p2Stack, VOID **p2value )
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
// Rout: iccStackPop
// Desc: These routines pop complex values from complex stacks.
//------------------------------------------------------------------------------
INT32 iccStackPopCFLT32( iccStackCFLT32_t *p2Stack, CFLT32 *p2value )
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

INT32 iccStackPopCFLT64( iccStackCFLT64_t *p2Stack, CFLT64 *p2value )
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
 
INT32 iccStackPopCFLT96( iccStackCFLT96_t *p2Stack, CFLT96 *p2value )
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

INT32 iccStackPopCINT08( iccStackCINT08_t *p2Stack, CINT08 *p2value )
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

INT32 iccStackPopCINT16( iccStackCINT16_t *p2Stack, CINT16 *p2value )
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
 
INT32 iccStackPopCINT32( iccStackCINT32_t *p2Stack, CINT32 *p2value )
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
 
INT32 iccStackPopCINT64( iccStackCINT64_t *p2Stack, CINT64 *p2value )
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
 
INT32 iccStackPopCUNT08( iccStackCUNT08_t *p2Stack, CUNT08 *p2value )
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
 
INT32 iccStackPopCUNT16( iccStackCUNT16_t *p2Stack, CUNT16 *p2value )
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
 
INT32 iccStackPopCUNT32( iccStackCUNT32_t *p2Stack, CUNT32 *p2value )
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
 
INT32 iccStackPopCUNT64( iccStackCUNT64_t *p2Stack, CUNT64 *p2value )
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
// Rout: iccStackPop
// Desc: These routines pop Vector values from Vector stacks.
//------------------------------------------------------------------------------
INT32 iccStackPopVFLT32( iccStackVFLT32_t *p2Stack, VFLT32 *p2value )
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

INT32 iccStackPopVFLT64( iccStackVFLT64_t *p2Stack, VFLT64 *p2value )
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
 
INT32 iccStackPopVFLT96( iccStackVFLT96_t *p2Stack, VFLT96 *p2value )
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

INT32 iccStackPopVINT08( iccStackVINT08_t *p2Stack, VINT08 *p2value )
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

INT32 iccStackPopVINT16( iccStackVINT16_t *p2Stack, VINT16 *p2value )
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
 
INT32 iccStackPopVINT32( iccStackVINT32_t *p2Stack, VINT32 *p2value )
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
 
INT32 iccStackPopVINT64( iccStackVINT64_t *p2Stack, VINT64 *p2value )
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
 
INT32 iccStackPopVUNT08( iccStackVUNT08_t *p2Stack, VUNT08 *p2value )
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
 
INT32 iccStackPopVUNT16( iccStackVUNT16_t *p2Stack, VUNT16 *p2value )
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
 
INT32 iccStackPopVUNT32( iccStackVUNT32_t *p2Stack, VUNT32 *p2value )
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
 
INT32 iccStackPopVUNT64( iccStackVUNT64_t *p2Stack, VUNT64 *p2value )
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
// Rout: iccStringStackPop
// Desc: This routine pops a string pointer from a VOID pointer stack.
//------------------------------------------------------------------------------
INT32 iccStringStackPop( iccStackVOIDP_t *p2Stack, CHR08 **stringPointer )
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
