/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: movRename.c                                                                            -
// Desc: This program renames JPEG movtures to a base name plus date, where the date is pulled  -
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
#include "iccswd.h"
#include <sys/stat.h>

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG 1
#define BLOCK_SIZE 1000

#define MOVRENAME_FUNC_DESC \
"**********************************************************************************************\n"\
"Desc: This program renames JPEG movtures to a base name plus date, where the date is pulled  -\n"\
"      from the actual date field found in the JPEG file.  As an example if the base name is  -\n"\
"      \"base\" and the date of the JPEG file is January 1st at 10:22:00 then the file name   -\n"\
"      would come out to be:  base20050101_102200                                             -\n"\
"                                                                                              \n"\
"Args: iFileName     - The name of the input file.                                            -\n"\
"      oFileNameBase - The name of the output file.                                           -\n"\
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
  INT08 inDataINT08[BLOCK_SIZE];
  CHR08 ifileName[128];
  CHR08 ofileName[128];
  CHR08 ofileNameBase[128];
  struct tm *p2tm;

  FILE *iFID=NULL;
  FILE *oFID=NULL;

  INT32 fid;
  struct stat buf;

  // Handle input parameters.
  //---------------------------------------------------------------------------------------------
  for(ii = 0; ii<argc; ii++)
  {
    if( (!strncmp( argv[ii], "-h",     2)) || 
	(!strncmp( argv[ii], "--help", 6))   )
    {
      fprintf(stderr, MOVRENAME_FUNC_DESC);
      exit(0);
    }
    else if( argc != 3 )
    {
      fprintf(stderr, MOVRENAME_FUNC_DESC);
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

  // "fstat" the file.
  //---------------------------------------------------------------------------------------------
  fid =  open(ifileName, O_RDONLY);
  fstat(fid, &buf);
  printf("%s", asctime(gmtime(&buf.st_atime)));
  printf("%s", asctime(gmtime(&buf.st_ctime)));
  printf("%s", asctime(gmtime(&buf.st_mtime)));
  close(fid);

  // Get the creation time.
  //---------------------------------------------------------------------------------------------
  p2tm = gmtime(&buf.st_atime);
  p2tm = gmtime(&buf.st_ctime);
  p2tm = gmtime(&buf.st_mtime);
    
  // Create a file name and open the file.
  //---------------------------------------------------------------------------------------------
  sprintf(ofileName, "%s%04d%02d%02d_%02d%02d%02d.mov", 
	  ofileNameBase, 
	  p2tm->tm_year+1900,
	  p2tm->tm_mon+1,
	  p2tm->tm_mday,
	  p2tm->tm_hour,
	  p2tm->tm_min,
	  p2tm->tm_sec);

  oFID = fopen(ofileName,"w");

  // Open the input file.
  //---------------------------------------------------------------------------------------------
  iFID = fopen(ifileName,"r");

  // Read in the rest of the data and write it out.
  //---------------------------------------------------------------------------------------------
  while ( (amountRead = fread(inDataINT08, sizeof(inDataINT08[0]), BLOCK_SIZE, iFID)) == BLOCK_SIZE )
  {
    fwrite(inDataINT08, sizeof(INT08),BLOCK_SIZE, oFID);
  }
  fwrite(inDataINT08, sizeof(INT08),amountRead, oFID);

  // Close the file
  //---------------------------------------------------------------------------------------------
  fclose(iFID);
  fclose(oFID);

  return(0);

}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
