/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: corDataDemo.c
// Desc: This was used for a demo and its sole purpose is to dump buffers of
//       data to disk.
// Hist: When       Who  What
//       09/19/2004 ptb  Initial Code.  Original code less formal.
//       /* NEED TO GET MODIFIED CODE FROM MATTHEW SPENCER. */
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "iccswd.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define INPUT_BLOCK_SIZE (1024*1024)
#define N_BLOCKS         (1024*9)
#define CORDATADEMO_FUNC_DESC \
"********************************************************************************\n"\
"                                                           \n"\
"This program dumps data to disk.                           \n"\
"                                                           \n"\
"Input : is from stdin.                                     \n"\
"                                                           \n"\
"Output: is to stdout.                                      \n"\
"                                                           \n"\
"Input parameters are:                                      \n"\
"  None.                                                    \n"\
"                                                           \n"\
"                                                                                \n"\
"********************************************************************************\n"\
"\n"
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/

int main(void)
{
  INT32 ii;
  INT32 amountRead;
  INT08 iData[INPUT_BLOCK_SIZE];
  INT08 oData[INPUT_BLOCK_SIZE];
  
  for(ii=0; ii<INPUT_BLOCK_SIZE; ii++) oData[ii] = rand();

  for(ii=0; ii<N_BLOCKS; ii++)
  {

    fwrite(oData, sizeof(oData[0])*INPUT_BLOCK_SIZE, 1, stdout);
    
    if( (ii%16) == 0 )
    {
      fread(iData, sizeof(iData[0]), INPUT_BLOCK_SIZE, stdin);
    }
  }

  return(0);

}


/*
# Create at least 576 Meg of data for itest.
# itest needs to be on the SAN.
# otest needs to be on the SAN.
#-------------------------------------------
cat < /dev/zero >/data12/itest
gcc corDataDemo.c -o corDataDemo
date +%s
corDataDemo < /data12/itest > /data12/otest
date +%s
*/
