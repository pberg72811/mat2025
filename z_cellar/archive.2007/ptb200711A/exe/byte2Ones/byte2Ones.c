/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: byte2Ones.c
// Desc: This file contains the code for the byte2Ones binary.
// Hist: When       Who  What
//       11/05/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "iccswd.h"
#include "iccStackUtils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define INPUT_BLOCK_SIZE 1024
#define MSB 0
#define LSB 1
#define BYTE2ONES_FUNC_DESC \
"********************************************************************************\n"\
"This program converts a byte stream to a series of ones  \n"\
"and zeros.                                               \n"\
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
"  -lsb for Least significant bit first.                  \n"\
"  -msb for Most  significant bit first. (Default).       \n"\
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
  INT08 oneOrZero;
  CHR08 inData[INPUT_BLOCK_SIZE];
  INT32 msblsbFlag=MSB;
  iccStackINT08_t *bitStack;

  // Handle input parameters.
  //----------------------------------------------------------------------------
  for(ii = 1; ii<argc; ii++)
  {
    if( (!strncmp( argv[ii], "-h",     2)) || 
	(!strncmp( argv[ii], "--help", 6))   )
    {
      printf(BYTE2ONES_FUNC_DESC);
      exit(0);
    }
    if( !strncmp(argv[ii], "-msb", 4) )
    {
      msblsbFlag = MSB; //fprintf(stderr,"I see msb option.\n");
    }

    if( !strncmp(argv[ii], "-lsb", 4) )
    {
      msblsbFlag = LSB; //fprintf(stderr,"I see lsb option.\n");
    }
    //else if(cmIndx == 0) {sscanf(argv[ii],"%f", &fb); cmIndx++;}
    //else if(cmIndx == 1) {sscanf(argv[ii],"%f", &fc); cmIndx++;}
    //else if(cmIndx == 2) {sscanf(argv[ii],"%f", &fs); cmIndx++;}
    //else if(cmIndx == 3) {sscanf(argv[ii],"%ld",&ns); cmIndx++;}
    else
    {
      printf(BYTE2ONES_FUNC_DESC);
      exit(0);
    }
  }

  //if( cmIndx <= 0 )
  //{
  //  icc_NOT_ENOUGH_ARGS_MESSAGE();
  //  printf(BYTE2ONES_FUNC_DESC);
  //  exit(0);
  //}

  // Initialize the stack.
  //----------------------------------------------------------------------------
  bitStack = iccStackInitINT08(INPUT_BLOCK_SIZE*8*1024, "bitStack");

  // While there is input data, read it in, unpack and write it out.
  //----------------------------------------------------------------------------
  while ( (amountRead = fread(inData, sizeof(inData[0]), INPUT_BLOCK_SIZE, stdin)) == INPUT_BLOCK_SIZE )
  {
    if( msblsbFlag==LSB )
      for(ii = 0; ii < amountRead; ii++) 
      {
	iccCHR08UnpackLSB_INT08( bitStack, inData[ii] ); // Unpack LSB data.
      }
    else
      for(ii = 0; ii < amountRead; ii++) 
      {
	iccCHR08UnpackMSB_INT08( bitStack, inData[ii] ); // Unpack MSB data.
      }

    iccStackFlipINT08(bitStack);                         // Flip the stack for output

    while ( iccStackPopINT08( bitStack, &oneOrZero ) == 0 )
    {
      fwrite( &oneOrZero, sizeof(oneOrZero), 1, stdout); // Output the data.
    }
  }

  // Take care of the rest of the data.
  //----------------------------------------------------------------------------
  if( msblsbFlag==LSB )
    for(ii = 0; ii < amountRead; ii++) 
    {
      iccCHR08UnpackLSB_INT08( bitStack, inData[ii] ); // Unpack LSB data.
    }
  else
    for(ii = 0; ii < amountRead; ii++) 
    {
      iccCHR08UnpackMSB_INT08( bitStack, inData[ii] ); // Unpack MSB data.
    }

  iccStackFlipINT08(bitStack);                         // Flip the stack for output

  while ( iccStackPopINT08( bitStack, &oneOrZero ) == 0 )
  {
    fwrite( &oneOrZero, sizeof(oneOrZero), 1, stdout); // Output the data.
  }

  // Terminate the stack and quit.
  //----------------------------------------------------------------------------
  iccStackTermINT08(bitStack);

  return(0);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
