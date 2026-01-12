/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: phaseDetect.c
// Desc: This file contains the code for the phaseDetect program.
// Hist: When       Who  What
//       09/04/2002 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "iccswd.h"
#include "iccVectorUtils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define INPUT_BLOCK_SIZE 1024
#define XMIDAS_HEADER_SIZE 512
#define PHASEDETECT_FUNC_DESC \
"********************************************************************************\n"\
"This program will calculate phase noise based on the input data and a given     \n"\
"reference frequency.                                                            \n"\
"                                                                                \n"\
"Input : is from stdin and is assumed to be a scalar byte (8bit) XMidas file.    \n"\
"                                                                                \n"\
"Output: is to stdout.                                                           \n"\
"                                                                                \n"\
"Input parmaters are:                                                            \n"\
"  Reference frequency.                                                          \n"\
"  Sample rate.                                                                  \n"\
"                                                                                \n"\
"Optional parmaters are:                                                         \n"\
"  -h, or --help                                                                 \n"\
"********************************************************************************\n"\
"\n"

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
int main(int argc, char **argv)
{
  INT08 inDataINT08[INPUT_BLOCK_SIZE];
  FLT32 inDataFLT32[INPUT_BLOCK_SIZE];
  FLT32 cosFLT32[INPUT_BLOCK_SIZE];
  FLT32 sinFLT32[INPUT_BLOCK_SIZE];
  FLT32 refFreq    =  1.0e6;
  FLT32 sampleRate = 32.5e6;
  FLT32 d,x,y;
  FLT32 phaseNoise;
  FLT32 meanValue;
  FLT32 phaseStep;
  INT32 amountRead;
  INT32 ii;
  INT32 batchNumber=0;

  // Handle input parameters.
  //----------------------------------------------------------------------------
  for(ii = 0; ii<argc; ii++)
  {
    if( (!strncmp( argv[ii], "-h",     2)) || 
	(!strncmp( argv[ii], "--help", 6))   )
    {
      fprintf(stderr, PHASEDETECT_FUNC_DESC);
      exit(0);
    }
 
    if(ii == 1)	sscanf(argv[ii],"%f", &refFreq);
    if(ii == 2)	sscanf(argv[ii],"%f", &sampleRate);
  }

  // Calculate Radians per sample.  Calculate Radians per batch.
  //----------------------------------------------------------------------------
  d = 2*PI*refFreq/sampleRate;
  phaseStep = d*INPUT_BLOCK_SIZE;

  // Create sin and cos.
  //----------------------------------------------------------------------------
  iccvRampFLT32( cosFLT32, 1, 0, d, INPUT_BLOCK_SIZE );
  iccvRampFLT32( sinFLT32, 1, 0, d, INPUT_BLOCK_SIZE );
  iccvCosFLT32(  cosFLT32, 1, cosFLT32, 1, INPUT_BLOCK_SIZE );
  iccvSinFLT32(  sinFLT32, 1, sinFLT32, 1, INPUT_BLOCK_SIZE );

  // Read in the XMidas header.
  //----------------------------------------------------------------------------
  fread(inDataINT08, sizeof(inDataINT08[0]), XMIDAS_HEADER_SIZE, stdin);

  // While there is input data, read it in.
  //----------------------------------------------------------------------------
  while ( (amountRead = fread(inDataINT08, sizeof(inDataINT08[0]), INPUT_BLOCK_SIZE, stdin)) == INPUT_BLOCK_SIZE )
  {

  // Convert from INT08 to FLT32.
  //----------------------------------------------------------------------------
    iccvINT08ToFLT32( inDataINT08, 1, inDataFLT32, 1, INPUT_BLOCK_SIZE );

  // Normalize the data.
  //----------------------------------------------------------------------------
    meanValue = iccvMeanFLT32(inDataFLT32, 1, INPUT_BLOCK_SIZE);
    iccvsSubFLT32(inDataFLT32, 1, meanValue, inDataFLT32, 1, INPUT_BLOCK_SIZE);

  // Convolve with cos and sin.
  //----------------------------------------------------------------------------
    x = iccvConvolveFLT32(cosFLT32, 1, inDataFLT32, 1, INPUT_BLOCK_SIZE);
    y = iccvConvolveFLT32(sinFLT32, 1, inDataFLT32, 1, INPUT_BLOCK_SIZE);

  // Calculate phase noise.
  //----------------------------------------------------------------------------
    //batchNumber++;
    phaseNoise = atan2(y,x) + batchNumber*phaseStep;
    phaseNoise = fmod(phaseNoise, TWOPI);
    phaseNoise = phaseNoise*180/PI;

  // Write out the data.
  //----------------------------------------------------------------------------
    fwrite( &phaseNoise, sizeof(phaseNoise), 1, stdout );
    //printf("%f\n",phaseNoise);
  }

  return(0);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
