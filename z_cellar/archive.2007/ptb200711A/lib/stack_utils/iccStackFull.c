/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccStackFull.c
// Desc: This file contains the code for the iccStackFull routine.
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
// Rout: iccStackFull
// Desc: These routines checks to see if a stack is full.
//------------------------------------------------------------------------------
INT32 iccStackFullFLT32( iccStackFLT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 iccStackFullFLT64( iccStackFLT64_t *p2Stack)
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullFLT96( iccStackFLT96_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 iccStackFullINT08( iccStackINT08_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 iccStackFullINT16( iccStackINT16_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullINT32( iccStackINT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullINT64( iccStackINT64_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullUNT08( iccStackUNT08_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullUNT16( iccStackUNT16_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullUNT32( iccStackUNT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullUNT64( iccStackUNT64_t *p2Stack )
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
// Rout: iccStackFullC
// Desc: These routines checks to see if a stack is full for complex data types.
//------------------------------------------------------------------------------
INT32 iccStackFullCFLT32( iccStackCFLT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 iccStackFullCFLT64( iccStackCFLT64_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullCFLT96( iccStackCFLT96_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 iccStackFullCINT08( iccStackCINT08_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 iccStackFullCINT16( iccStackCINT16_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullCINT32( iccStackCINT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullCINT64( iccStackCINT64_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
} 

INT32 iccStackFullCUNT08( iccStackCUNT08_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullCUNT16( iccStackCUNT16_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullCUNT32( iccStackCUNT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullCUNT64( iccStackCUNT64_t *p2Stack )
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
// Rout: iccStackFullC
// Desc: These routines checks to see if a stack is full for vector data types.
//------------------------------------------------------------------------------
INT32 iccStackFullVFLT32( iccStackVFLT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 iccStackFullVFLT64( iccStackVFLT64_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullVFLT96( iccStackVFLT96_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 iccStackFullVINT08( iccStackVINT08_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 iccStackFullVINT16( iccStackVINT16_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullVINT32( iccStackVINT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullVINT64( iccStackVINT64_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}

INT32 iccStackFullVUNT08( iccStackVUNT08_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullVUNT16( iccStackVUNT16_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullVUNT32( iccStackVUNT32_t *p2Stack )
{
//------------------------------- COMMON-CODE       START.
  INT32 index = p2Stack->index;

  index++;

  if     (index == p2Stack->size)return( 1);
  else if(index == p2Stack->size){XMC_ERROR_STDOUT("DISCOVERED STACK OVERFLOW:");return(-1);}
  else                           return( 0);
//------------------------------- COMMON-CODE        STOP.
}
 
INT32 iccStackFullVUNT64( iccStackVUNT64_t *p2Stack )
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
// Rout: iccStackFullVOIDP
// Desc: These routines checks to see if a stack is full for the VOIDP  types.
//------------------------------------------------------------------------------
INT32 iccStackFullVOIDP( iccStackVOIDP_t *p2Stack )
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
// Rout: iccStringStackFull
// Desc: These routines checks to see if a stack is full for the string  types.
//------------------------------------------------------------------------------
INT32 iccStringStackFull( iccStackVOIDP_t *p2Stack )
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
