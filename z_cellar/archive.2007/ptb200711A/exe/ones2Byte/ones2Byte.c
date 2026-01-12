/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: ones2Bytes.c
// Desc: This file contains the code for the ones2Bytes binary.
// Hist: When       Who  What
//       03/03/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "iccswd.h"
#include "iccStackUtils.h"
#include "iccVectorUtils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define INPUT_BLOCK_SIZE 1024
#define MSB 0
#define LSB 1
#define ONES2BYTES_FUNC_DESC \
"********************************************************************************\n"\
"This program converts a series of ones and zeros to a    \n"\
"byte stream.                                             \n"\
"                                                         \n"\
"Input : is from stdin.                                   \n"\
"                                                         \n"\
"Output: is to stdout.                                    \n"\
"                                                         \n"\
"Input parmaters are:                                     \n"\
"  NONE                                                   \n"\
"                                                         \n"\
"Optional parmaters are:                                  \n"\
"  -h, or --help                                          \n"\
"********************************************************************************\n"\
"\n"

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
int main(int argc, char **argv)
{
  INT32 amountRead;
  INT32 ii;
  INT08 c;
  CHR08 inData[INPUT_BLOCK_SIZE];
  INT32 msblsbFlag=MSB;
  iccStackINT08_t *bitStack;

  // Handle input parameters.
  //----------------------------------------------------------------------------
  for(ii = 0; ii<argc; ii++)
  {
    if( (!strncmp( argv[ii], "-h",     2)) || 
	(!strncmp( argv[ii], "--help", 6))   )
    {
      fprintf(stderr, ONES2BYTES_FUNC_DESC);
      exit(0);
    }

    if( !strncmp(argv[ii], "-msb", 4) )
    {
      //fprintf(stderr,"I see lsb option.\n");
      msblsbFlag = MSB;
    }

    if( !strncmp(argv[ii], "-lsb", 4) )
    {
      //fprintf(stderr,"I see msb option.\n");
      msblsbFlag = LSB;
    }

  }

  // Initialize the stack.
  //----------------------------------------------------------------------------
  bitStack = iccStackInitINT08(INPUT_BLOCK_SIZE*8*1024, "bitStack");

  // While there is input data, read it in, push it to bitstack, pack, and output.
  //----------------------------------------------------------------------------
  while( (amountRead = iccvReadINT08(stdin, inData, INPUT_BLOCK_SIZE)) > 0 ) 
  {
    for(ii = 0; ii < amountRead; ii++) 
    {
      iccStackPushINT08 ( bitStack, inData[ii] );          // Push ones and zeros to stack.
    }

    iccStackFlipINT08(bitStack);                           // Flip the stack for output.

    if(msblsbFlag==LSB)
      while ( iccCHR08PackLSB_INT08( bitStack, &c ) == 0 ) // While there is LSB data pack it up.
      {
	fwrite( &c, sizeof(c), 1, stdout);                 // Write data out.
      }
    else
      while ( iccCHR08PackMSB_INT08( bitStack, &c ) == 0 ) // While there is MSB data pack it up.
      {
	fwrite( &c, sizeof(c), 1, stdout);                 // Write data out.
      }
  }

  // Terminate the stack and quit.
  //----------------------------------------------------------------------------
  iccStackTermINT08(bitStack);

  return(0);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
