/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: 16t2Wav.c
// Desc: This file contains the code for the 16t2Wav binary.
// Hist: When       Who  What
//       06/14/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "iccswd.h"
#include "iccVectorUtils.h"

#define INPUT_BLOCK_SIZE  (1024)

#define T2Wav_FUNC_DESC \
"********************************************************************************\n"\
"This program converts 16t data to \".Wav\" data.                                \n"\
"                                                                                \n"\
"Input : is from stdin.                                                          \n"\
"                                                                                \n"\
"Output: is to stdout.                                                           \n"\
"                                                                                \n"\
"Input parmaters are:                                                            \n"\
"  NONE                                                                          \n"\
"                                                                                \n"\
"Optional parmaters are:                                                         \n"\
"  -h, or --help                                                                 \n"\
"  -16t                                                                          \n"\
"  -32t                                                                          \n"\
"  -64t                                                                          \n"\
"********************************************************************************\n"\
"\n"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
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
  UNT16 inData16[INPUT_BLOCK_SIZE];
  UNT32 amountRead;
  UNT32 ii;
  BOOLN flag16t=FALSE;
  BOOLN flag32t=FALSE;
  BOOLN flag64t=FALSE;
  BOOLN firstTime = TRUE;

  CHR08 riffID[4] = "RIFF";//4
  INT32 riffSize =5701632+36 ;//dataSize+36 <<< NEED TO FIX
  CHR08 waveID[4] = "WAVE";//4
  CHR08 chunkID[4] = "fmt ";//4
  INT32 chunkSize = 16;//4
  INT16 wFormatTag = 1;//2
  UNT16 nChannels = 1;//2
  UNT32 nSamplesPerSec = 8000;//4
  UNT32 nAvgBytesPerSec = 16000;//4
  UNT16 nBlockAlign = 2;//2
  UNT16 nBitsPerSample = 16;//2
  CHR08 dataID[4] = "data";//4
  INT32 dataSize = 5701632;//4 <<< NEED TO FIX
  
  /* Handle input parameters -------------------------------------------------*/
  for(ii = 0; ii<argc; ii++)
  {
    if( (!strncmp( argv[ii], "-h",     2)) || 
	(!strncmp( argv[ii], "--help", 6))   )
    {
      printf(T2Wav_FUNC_DESC);
      exit(0);
    }
    if( !strncmp( argv[ii], "-16t", 4) ) flag16t = TRUE;
    if( !strncmp( argv[ii], "-32t", 4) ) flag32t = TRUE;
    if( !strncmp( argv[ii], "-64t", 4) ) flag64t = TRUE;

  }
  //vzeroINT08(&inData16[0],  1, INPUT_BLOCK_SIZE);

  /* While there is input data, read it in -----------------------------------*/
  while ( (amountRead = fread(inData16, sizeof(inData16[0]), INPUT_BLOCK_SIZE, stdin)) == INPUT_BLOCK_SIZE )
  {
    if(firstTime)
    {
      fwrite(&riffID,         4,                      1, stdout);
      fwrite(&riffSize,       sizeof(riffSize),       1, stdout);
      fwrite(&waveID ,        4,                      1, stdout);
      fwrite(&chunkID,        4,                      1, stdout);
      fwrite(&chunkSize,      sizeof(chunkSize),      1, stdout);
      fwrite(&wFormatTag,     sizeof(wFormatTag),     1, stdout);
      fwrite(&nChannels,      sizeof(nChannels),      1, stdout);
      fwrite(&nSamplesPerSec, sizeof(nSamplesPerSec), 1, stdout);
      fwrite(&nAvgBytesPerSec,sizeof(nAvgBytesPerSec),1, stdout);
      fwrite(&nBlockAlign,    sizeof(nBlockAlign),    1, stdout);
      fwrite(&nBitsPerSample, sizeof(nBitsPerSample), 1, stdout);
      fwrite(&dataID,         4,                      1, stdout);
      fwrite(&dataSize, sizeof(dataSize), 1, stdout);
      firstTime = FALSE;
    }

    for(ii = 0; ii < amountRead; ii++) fwrite( &inData16[ii], sizeof(inData16[0]), 1, stdout);
  }

  for(ii=0; ii<amountRead; ii++)
  {
    for(ii = 0; ii < amountRead; ii++) fwrite( &inData16[ii], sizeof(inData16[0]), 1, stdout);
  }

  /* OK, we're done. Terminate -----------------------------------------------*/
  return(0);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
