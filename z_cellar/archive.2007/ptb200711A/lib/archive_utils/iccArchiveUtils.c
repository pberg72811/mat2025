/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: iccArchiveUtils.c                                                                      -
// Desc: This file contains the code for the iccArchiveUtils routine.                           -
// Hist: When       Who  What                                                                   -
//       10/19/2004 ptb  Initial Code.                                                          -
//       04/03/06 ptb  Added iccArchiveRenameOldest function.  Faster then delete.              -
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include "archive_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG (1)

/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
//-----------------------------------------------------------------------------------------------
// Rout: iccArchiveInit
// Desc: This routine initializes the archive specification.
//-----------------------------------------------------------------------------------------------
iccArchiveSpec *iccArchiveInit( const CHR08 *baseFileName, const CHR08 *baseFileSuffix, UNT32 stackSize )
{
  iccArchiveSpec *spec;

  // Malloc the memory for the spec.
  //---------------------------------------------------------------------------------------------
  spec = (iccArchiveSpec *) iccMallocVOID_Align032( sizeof(iccArchiveSpec) );

  // Initialize the stack size.
  //---------------------------------------------------------------------------------------------
  spec->stackSize = stackSize;

  // Initialize the base file name.
  //---------------------------------------------------------------------------------------------
  iccStringInit( spec->baseFileName, ICCARCHIVE_STRING_SIZE );

  sprintf(spec->baseFileName,"%s",baseFileName);

  iccStringLower(spec->baseFileName);

  // Initialize the base file suffix.
  //---------------------------------------------------------------------------------------------
  iccStringInit( spec->baseFileSuffix, ICCARCHIVE_STRING_SIZE );
  
  sprintf(spec->baseFileSuffix, "%s", baseFileSuffix);

  iccStringLower(spec->baseFileSuffix);

  // Initialize the file name stack.
  //---------------------------------------------------------------------------------------------
  spec->fileNameStack = iccStackInitVOIDP( stackSize, "fileNameStack" );

  // Initialize the number of file cycled through.
  //---------------------------------------------------------------------------------------------
  spec->filesCycled = 0;

  // Initialize the time tag.
  //---------------------------------------------------------------------------------------------
  spec->timeTag = 0.0;

  return (spec);
}

//-----------------------------------------------------------------------------------------------
// Rout: iccArchiveReport
// Desc: This routine prints out information on the archive.
//-----------------------------------------------------------------------------------------------
VOID iccArchiveReport( iccArchiveSpec *spec )
{
  INT32 ii;
  if( spec->fileNameStack->index < 0)
  {
    printf("********************************************************************\n");
    printf("Empty stack.********************************************************\n");
    printf("********************************************************************\n");
  }
  else
  {
    printf("********************************************************************\n");
    printf("spec->stackSize      is %ld\n", spec->stackSize);
    printf("spec->filesCycled    is %ld\n", spec->filesCycled);
    printf("spec->baseFileName   is %s \n", spec->baseFileName);
    printf("spec->baseFileSuffix is %s \n", spec->baseFileSuffix);
    printf("spec->fileNameStack->name  is %s  \n", spec->fileNameStack->name);
    printf("spec->fileNameStack->type  is %s  \n", spec->fileNameStack->type);
    printf("spec->fileNameStack->size  is %ld \n", spec->fileNameStack->size);
    printf("spec->fileNameStack->index is %lld \n", spec->fileNameStack->index);
    for(ii=0; ii<(spec->fileNameStack->index+1); ii++)
    {
      printf("spec->fileNameStack->theStack[ii] is %s \n", (CHR08 *)spec->fileNameStack->theStack[ii]);
    }
    printf("********************************************************************\n");
  }
}

//-----------------------------------------------------------------------------------------------
// Rout: iccArchiveTerm
// Desc: This routine terminates the archive specification.
//-----------------------------------------------------------------------------------------------
VOID iccArchiveTerm( iccArchiveSpec *spec )
{
  iccStackTermVOIDP( spec->fileNameStack );
  xmcFree( spec );
}

//-----------------------------------------------------------------------------------------------
// Rout: iccArchiveReestablish
// Desc: This routine looks into the archive directory and reestablishes an 
//       archive file listing (stack) base on the files present that match the 
//       archive base file name.
//-----------------------------------------------------------------------------------------------
VOID iccArchiveReestablish(iccArchiveSpec *spec)
{
  CHR08 *p;
  CHR08 string2Parse[ICCARCHIVE_STRING_SIZE];
  CHR08 directoryName[ICCARCHIVE_STRING_SIZE];
  CHR08 fileName[ICCARCHIVE_STRING_SIZE];
  CHR08 oldFileName[ICCARCHIVE_STRING_SIZE];
  INT32 t=0;
  DIR   *dp;
  struct dirent *dirp;

  // String initialization.
  //---------------------------------------------------------------------------------------------
  iccStringInit(string2Parse,ICCARCHIVE_STRING_SIZE);
  iccStringInit(directoryName,ICCARCHIVE_STRING_SIZE);
  iccStringInit(fileName,ICCARCHIVE_STRING_SIZE);
  iccStringInit(oldFileName,ICCARCHIVE_STRING_SIZE);

  // Parse out directory name from "spec->baseFileName".
  // Parse out file name from "spec->baseFileName".
  //---------------------------------------------------------------------------------------------
  sprintf(string2Parse,"/%s",spec->baseFileName);
  p = strtok(string2Parse,"/");
  sprintf(fileName,"%s",p);
  p = strtok('\0',"/");
  while(p != NULL)
  {
    sprintf(&directoryName[t],"/%s",fileName);
    sprintf(fileName,"%s",p);
    t=strlen(directoryName);
    p = strtok('\0',"/");
  }
  if(t>1) sprintf(&directoryName[t],"/");

  // Open the directory where new archive file will be writen.
  //---------------------------------------------------------------------------------------------
  dp = opendir(directoryName);

  // Restablish file name stack.
  //---------------------------------------------------------------------------------------------
  while( (dirp = readdir(dp)) != NULL )                       // Read the directory.
  {                                                           //
    if( !strncmp(dirp->d_name, fileName, strlen(fileName)) )  // Compare file names.
    {                                                         //
      if( iccStringStackFull(spec->fileNameStack) )           // If the stack is full.
      {                                                       //
	iccArchiveDeleteOldest(spec);                         // Then delete the oldest file.
      }                                                       //
      sprintf(oldFileName,"%s",directoryName);                // Combined directory/file name.
      strcat(oldFileName,dirp->d_name);                       // 
      iccStringStackPush( spec->fileNameStack, oldFileName ); // Push file name to stack.
    }                                                         //
  }                                                           //
  closedir(dp);                                               // Close the directory.
}

//-----------------------------------------------------------------------------------------------
// Rout: iccArchiveDeleteOldest
// Desc: This routine deletes the oldest entry in the "fileNameStack".
//-----------------------------------------------------------------------------------------------
VOID iccArchiveDeleteOldest(iccArchiveSpec *spec)
{
  CHR08 *p2String;
  CHR08 tempString[ICCARCHIVE_STRING_SIZE];
  //CHR08 tempString2[ICCARCHIVE_STRING_SIZE];
  pid_t pid=0;

  iccStackFlipVOIDP( spec->fileNameStack );
  iccStringStackPop( spec->fileNameStack, &p2String );
  sprintf(tempString,"%s",p2String);
  //sprintf(tempString2,"rm %s &",tempString);
  pid = fork();
  if      (pid <  0) XMC_ERROR_STDOUT("Command fork() failed.\n")
  else if (pid == 0) // This will execute in the child process.
  {
    printf("CHILD- ABOUT TO REMOVE FILE.\n");
    remove(tempString);
    printf("CHILD- DONE REMOVING FILE.\n");
    exit(0);
  }
  else if (pid > 0) // This will execute in the parent process.
  {
    printf("PARENT- MOVING ON TO NEXT FILE\n");
  }
  xmcFree(p2String);
  iccStackFlipVOIDP( spec->fileNameStack );
}

//-----------------------------------------------------------------------------------------------
// Rout: iccArchiveRenameOldest
// Desc: This routine renames the oldest entry in the "fileNameStack".
//-----------------------------------------------------------------------------------------------
VOID iccArchiveRenameOldest(iccArchiveSpec *spec, const CHR08 *newFileName)
{
  CHR08 *oldFileName;

  iccStackFlipVOIDP( spec->fileNameStack );
  iccStringStackPop( spec->fileNameStack, &oldFileName );

  rename( oldFileName, newFileName);

  iccStackFlipVOIDP( spec->fileNameStack );
  iccStringStackPush( spec->fileNameStack, newFileName );

  xmcFree(oldFileName);
}

//-----------------------------------------------------------------------------------------------
// Rout: iccArchiveProcess
// Desc: This routine does the basic archive process of creating new file names
//       for the "fileNameStack" and calls "iccDeleteOldest" if the stack is full.
//-----------------------------------------------------------------------------------------------
CHR08 *iccArchiveProcess(iccArchiveSpec *spec)
{
  CHR08 tempString[ICCARCHIVE_STRING_SIZE];
  CHR08 timeString[ICCARCHIVE_STRING_SIZE];
  CHR08 newFileName[ICCARCHIVE_STRING_SIZE];

  iccStringInit( tempString, ICCARCHIVE_STRING_SIZE );

  // Create new file name.
  //---------------------------------------------------------------------------------------------
  iccStringInit( timeString, ICCARCHIVE_STRING_SIZE );

  if( spec->timeTag != 0 )
  {
    iccASCIITime(spec->timeTag, timeString, "%G%m%d_%H%M%S");
  }
  else
  {
    iccCurrentASCIITime( timeString, "%G%m%d_%H%M%S" );
  }

  sprintf(newFileName,"%s_%s.%s",spec->baseFileName, timeString, spec->baseFileSuffix);

  iccStringLower(newFileName);

  // If stack is not full just push the new file name onto the filename stack.
  //---------------------------------------------------------------------------------------------
  if( !iccStringStackFull(spec->fileNameStack) )
  {
    iccStringStackPush( spec->fileNameStack, newFileName );
    spec->filesCycled ++;
  }

  // Else the stack is full.  So pop old file, remove old file, push new file name.
  //---------------------------------------------------------------------------------------------
  else
  {
    //iccArchiveDeleteOldest(spec);
    iccArchiveRenameOldest(spec,newFileName);
    //iccStringStackPush( spec->fileNameStack, newFileName );
    spec->filesCycled ++;
  }
  XMC_DEBUG_STDOUT("File name is %s.\n", newFileName );

  // Return a pointer to the new file name string.
  //---------------------------------------------------------------------------------------------
  return(spec->fileNameStack->theStack[spec->fileNameStack->index]);
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
 
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
