/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccStackFull.c
// Desc: This file contains the code for the xccStackFull routine.
// Hist: When       Who  What
//       08/11/2004 ptb  Initial Code.
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
PERL_PREPROCESS  INT32 index = p2Stack->index;
PERL_PREPROCESS
PERL_PREPROCESS  index++;
PERL_PREPROCESS
PERL_PREPROCESS  if     (index == p2Stack->size)return( 1);
PERL_PREPROCESS  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
PERL_PREPROCESS  else                           return( 0);
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
// Rout: xccStackFull
// Desc: These routines checks to see if a stack is full.
//------------------------------------------------------------------------------
INT32 xccStackFullFLT32( xccStackFLT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackFullFLT64( xccStackFLT64_t *p2Stack)
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullFLT96( xccStackFLT96_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackFullINT08( xccStackINT08_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackFullINT16( xccStackINT16_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullINT32( xccStackINT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullINT64( xccStackINT64_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullUNT08( xccStackUNT08_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullUNT16( xccStackUNT16_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullUNT32( xccStackUNT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullUNT64( xccStackUNT64_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

//------------------------------------------------------------------------------
// Rout: xccStackFullC
// Desc: These routines checks to see if a stack is full for complex data types.
//------------------------------------------------------------------------------
INT32 xccStackFullCFLT32( xccStackCFLT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackFullCFLT64( xccStackCFLT64_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullCFLT96( xccStackCFLT96_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackFullCINT08( xccStackCINT08_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackFullCINT16( xccStackCINT16_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullCINT32( xccStackCINT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullCINT64( xccStackCINT64_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
} 

INT32 xccStackFullCUNT08( xccStackCUNT08_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullCUNT16( xccStackCUNT16_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullCUNT32( xccStackCUNT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullCUNT64( xccStackCUNT64_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

//------------------------------------------------------------------------------
// Rout: xccStackFullC
// Desc: These routines checks to see if a stack is full for vector data types.
//------------------------------------------------------------------------------
INT32 xccStackFullVFLT32( xccStackVFLT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackFullVFLT64( xccStackVFLT64_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullVFLT96( xccStackVFLT96_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackFullVINT08( xccStackVINT08_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackFullVINT16( xccStackVINT16_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullVINT32( xccStackVINT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullVINT64( xccStackVINT64_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 xccStackFullVUNT08( xccStackVUNT08_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullVUNT16( xccStackVUNT16_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullVUNT32( xccStackVUNT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 xccStackFullVUNT64( xccStackVUNT64_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}


//------------------------------------------------------------------------------
// Rout: xccStackFullVOIDP
// Desc: These routines checks to see if a stack is full for the VOIDP  types.
//------------------------------------------------------------------------------
INT32 xccStackFullVOIDP( xccStackVOIDP_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

//------------------------------------------------------------------------------
// Rout: xccStringStackFull
// Desc: These routines checks to see if a stack is full for the string  types.
//------------------------------------------------------------------------------
INT32 xccStringStackFull( xccStackVOIDP_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
