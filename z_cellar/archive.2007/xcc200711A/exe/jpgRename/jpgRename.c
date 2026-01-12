/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: picRename.c                                                                            -
// Desc: This program renames JPEG pictures to a base name plus date, where the date is pulled  -
//       from the actual date field found in the JPEG file.  As an example if the base name is  -
//       "base" and the date of the JPEG file is January 1st at 10:22:00 then the file name     -
//       would come out to be:  base20050101_102200                                             -
// Args: iFileName     - The name of the input file.                                            -
//       oFileNameBase - The name of the output file.                                           -
// Hist: When       Who  What                                                                   -
//       03/05/2005 ptb  Initial Code.
//       09/17/2005 ptb  Initial Code.
/*---------------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include "xmc.h"
#include <sys/stat.h>

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG 1
#define BLOCK_SIZE 1000

#define PICRENAME_FUNC_DESC \
"**********************************************************************************************\n"\
"Desc: This program renames JPEG pictures to a base name plus date, where the date is pulled  -\n"\
"      from the actual date field found in the JPEG file.  As an example if the base name is  -\n"\
"      \"base\" and the date in the JPEG file is January 1st at 10:22:00 then the file name     -\n"\
"      would come out to be:  base20050101_102200                                             -\n"\
"                                                                                             -\n"\
"Args: iFileName     - The name of the input file.                                            -\n"\
"      oFileNameBase - The name of the output file.                                           -\n"\
"                                                                                             -\n"\
"Note:                                                                                        -\n"\
"      ll *.JPG | awk '{ printf(\"jpgRename %%s pic\\n\",$9) }'                                    -\n" \
"**********************************************************************************************\n"\
"\n"

/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
int main(int argc, char **argv)
{
  INT32 ii;
  UNT32 amountRead;
  INT08 inDataINT08A[BLOCK_SIZE];
  INT08 inDataINT08B[BLOCK_SIZE];
  INT08 inDataINT08C[BLOCK_SIZE];
  CHR08 dateYear[4+1];
  CHR08 dateMonth[2+1];
  CHR08 dateDay[2+1];
  CHR08 dateHour[2+1];
  CHR08 dateMinute[2+1];
  CHR08 dateSecond[2+1];
  CHR08 ifileName[128];
  CHR08 ofileName[128];
  CHR08 ofileNameBase[128];

  FILE *iFID=NULL;
  FILE *oFID=NULL;

  //INT32 fid;
  //struct stat buf;

  // Handle input parameters.
  //---------------------------------------------------------------------------------------------
  for(ii = 0; ii<argc; ii++)
  {
    if( (!strncmp( argv[ii], "-h",     2)) || 
	(!strncmp( argv[ii], "--help", 6))   )
    {
      fprintf(stderr, PICRENAME_FUNC_DESC);
      exit(0);
    }
    else if( argc != 3 )
    {
      fprintf(stderr, PICRENAME_FUNC_DESC);
      exit(0);
    }
    else
    {
     if(ii==1)
      {
	sscanf(argv[ii],"%s", ifileName);
      }
     if(ii==2)
      {
	sscanf(argv[ii],"%s", ofileNameBase);
      }

    }
  }

  // Open the input file.
  //---------------------------------------------------------------------------------------------
  iFID = fopen(ifileName,"r");

/*   // "fstat" the file. */
/*   //--------------------------------------------------------------------------------------------- */
/*   fid =  open(ifileName, O_RDONLY); */
/*   fstat(fid, &buf); */
/*   printf("%s", asctime(gmtime(&buf.st_atime))); */
/*   printf("%s", asctime(gmtime(&buf.st_mtime))); */
/*   printf("%s", asctime(gmtime(&buf.st_ctime))); */
/*   close(fid); */
/*   exit(0); */
/*   exit(0); */
  
  // Read in first block of data.
  //---------------------------------------------------------------------------------------------
  amountRead = fread(inDataINT08A, sizeof(inDataINT08A[0]), BLOCK_SIZE, iFID);
  if(amountRead != BLOCK_SIZE)
  {
    printf("RAN OUT OF DATA IN 1st READ\n");
    exit(0);
  }

  // Read in second block of data.
  //---------------------------------------------------------------------------------------------
  amountRead = fread(inDataINT08B, sizeof(inDataINT08B[0]), BLOCK_SIZE, iFID);
  if(amountRead != BLOCK_SIZE)
  {
    printf("RAN OUT OF DATA IN 2nd READ\n");
    exit(0);
  }

  // Search for the first colon character, then back up 4.
  //---------------------------------------------------------------------------------------------
  ii=0;
  while( inDataINT08B[ii] != ':' ) ii++;
  ii -=4;
    
  // Get the date and time.
  //---------------------------------------------------------------------------------------------
  dateYear[0]   = inDataINT08B[ii+ 0];
  dateYear[1]   = inDataINT08B[ii+ 1];
  dateYear[2]   = inDataINT08B[ii+ 2];
  dateYear[3]   = inDataINT08B[ii+ 3];
  dateYear[4]   = '\0';
  if(inDataINT08B[ii+ 4] != ':' ){printf("NOT SURE OF FORMAT\n"); exit(0);}

  dateMonth[0]  = inDataINT08B[ii+ 5];
  dateMonth[1]  = inDataINT08B[ii+ 6];
  dateMonth[2]  = '\0';
  if(inDataINT08B[ii+ 7] != ':' ){printf("NOT SURE OF FORMAT\n"); exit(0);}

  dateDay[0]    = inDataINT08B[ii+ 8];
  dateDay[1]    = inDataINT08B[ii+ 9];
  dateDay[2]    = '\0';
  if(inDataINT08B[ii+10] != ' ' ){printf("NOT SURE OF FORMAT\n"); exit(0);}

  dateHour[0]   = inDataINT08B[ii+11];
  dateHour[1]   = inDataINT08B[ii+12];
  dateHour[2]   = '\0';
  if(inDataINT08B[ii+13] != ':' ){printf("NOT SURE OF FORMAT\n"); exit(0);}

  dateMinute[0] = inDataINT08B[ii+14];
  dateMinute[1] = inDataINT08B[ii+15];
  dateMinute[2] = '\0';
  if(inDataINT08B[ii+16] != ':' ){printf("NOT SURE OF FORMAT\n"); exit(0);}

  dateSecond[0] = inDataINT08B[ii+17];
  dateSecond[1] = inDataINT08B[ii+18];
  dateSecond[2] = '\0';

  // Create a file name and open the file.
  //---------------------------------------------------------------------------------------------
  sprintf(ofileName, "%s%s%s%s_%s%s%s.jpg", ofileNameBase, dateYear, dateMonth, dateDay, 
	                                    dateHour, dateMinute, dateSecond);

  oFID = fopen(ofileName,"w");

  // Write out the first and second blocks.
  //---------------------------------------------------------------------------------------------
  fwrite(inDataINT08A, sizeof(INT08),BLOCK_SIZE, oFID);
  fwrite(inDataINT08B, sizeof(INT08),BLOCK_SIZE, oFID);

  // Read in the rest of the data and write it out.
  //---------------------------------------------------------------------------------------------
  while ( (amountRead = fread(inDataINT08C, sizeof(inDataINT08C[0]), BLOCK_SIZE, iFID)) == BLOCK_SIZE )
  {
    fwrite(inDataINT08C, sizeof(INT08),BLOCK_SIZE, oFID);
  }
  fwrite(inDataINT08C, sizeof(INT08),amountRead, oFID);

  // Close the file
  //---------------------------------------------------------------------------------------------
  fclose(iFID);
  fclose(oFID);

  return(0);

}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
