/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccConvEnc.cc
// Desc: This is an Octave shared library for the iccConvEnc function.
// Hist: When       Who  What
//       08/07/2002 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include <octave/oct.h>
#include "iccswd.h"
#include "iccVectorUtils.h"
#include "iccEndecUtils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define iccConvEnc_FUNC_DESC \
"***************************************************************************\n"\
"iccConvEnc: This function will run a rate 1/2 constraint length 7          \n"\
"            convolutional encoder.                                         \n"\
"iccConvEnc( binaryMsg );                                                   \n"\
"***************************************************************************\n"

#undef Complex

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
void doNothing( void )
{
  INT32 x;
  x = 1;
}

/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
DEFUN_DLD(iccConvEnc, args, ,iccConvEnc_FUNC_DESC)
{
  octave_value_list retval;
  INT32 nargin = args.length();
  ColumnVector returnVector;
  iccStackINT08_t *preEncodeMsg;
  iccStackINT08_t *postEncodeMsg;
  INT32 ii;

  doNothing();

// Example argument check.  Is there a valid number of arguments.
//------------------------------------------------------------------------------
  if( nargin != 1 )
  {
    printf(iccConvEnc_FUNC_DESC);
    return retval;
  }

// Handoff input and create output vectors.
//------------------------------------------------------------------------------
  ColumnVector binaryMsg = ColumnVector( args(0).vector_value() );
  ColumnVector outputMsg = ColumnVector( binaryMsg.length()*2 );

// Create stacks.
//------------------------------------------------------------------------------
  preEncodeMsg  = iccStackInitINT08(binaryMsg.length(),   "preEncodeMsg");
  postEncodeMsg = iccStackInitINT08(binaryMsg.length()*2, "postEncodeMsg");


// Push the input message onto the stack.
//------------------------------------------------------------------------------
  for( ii = 0; ii < binaryMsg.length(); ii++)
  {
    iccStackPushINT08( preEncodeMsg, (INT08)binaryMsg(ii) );
  }

// Convolutional encode.
//------------------------------------------------------------------------------
  iccStackFlipINT08(preEncodeMsg);

  iccConvEncoder1_2( preEncodeMsg, postEncodeMsg, 0x79, 0x5B);

  iccStackFlipINT08(postEncodeMsg);

// Copy to the output vector.
//------------------------------------------------------------------------------
  for( ii = 0; ii < outputMsg.length(); ii++)
  {
    INT08 tmp;
    iccStackPopINT08( postEncodeMsg, &tmp );
    outputMsg(ii) = tmp;
  }

// Terminate the stacks.
//------------------------------------------------------------------------------
  iccStackTermINT08(preEncodeMsg);
  iccStackTermINT08(postEncodeMsg);

// Return the encoded message.
//------------------------------------------------------------------------------
  retval(0) = outputMsg;
  return retval;

}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
