/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: badWordCheck.c
// Desc: This program checks for bad words.
// Hist: When       Who  What
//       07/20/2004 ptb  Initial Code.
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include "iccswd.h"
#include "iccMallocUtils.h"
#include "iccOrbitUtils.h"
#include "iccStackUtils.h"
#include "iccStringUtils.h"
#include "iccVectorUtils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG      (1)
#define BLOCK_SIZE (1024*8)
#define NSTACKS  (32)
#define BADWORDCHECK_FUNC_DESC \
"********************************************************************************\n"\
"                                                                                \n"\
"This program checks for \"bad\" words using a \"bad\" word list file.  The file \n"\
"name is given as the first argument to this program.                            \n"\
"                                                                                \n"\
"Input : is from stdin.                                                          \n"\
"                                                                                \n"\
"Output: is to stdout.                                                           \n"\
"                                                                                \n"\
"Input parameters are:                                                           \n"\
"  fileName  -Name of \"bad\" word list file.                                    \n"\
"                                                                                \n"\
"********************************************************************************\n"\
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
  CHR08 *p;
  CHR08 *p0;
  CHR08 p1[512];
  CHR08 p2[512];
  CHR08 p3[512];
  CHR08 p4[512];
  CHR08 p5[512];
  CHR08 p6[512];
  CHR08 p7[512];
  INT32 ii;
  UNT32 fileLength;
  INT32 amountRead;
  INT08 *iDataINT08;
  CHR08 theDelimiters[128];
  CHR08 badWordFile[128];

  FILE *fp;

  INT32 stackStatus=0;
  iccStackVOIDP_t *badWordStack[NSTACKS];
    
  // Handle input parameters.
  //---------------------------------------------------------------------------------------------
  for(ii = 0; ii<argc; ii++)                                    // Check each command line arg.
  {                                                             // 
    if( (!strncmp( argv[ii], "-h",     2)) ||                   // See if they ask for help.
	(!strncmp( argv[ii], "--help", 6))   )                  //
    {                                                           // 
      fprintf(stderr, BADWORDCHECK_FUNC_DESC);                  // If so print help message.
      exit(0);                                                  // 
    }                                                           // 
                                                                // 
    if(ii == 1)	sscanf(argv[ii],"%s", badWordFile);             // Get name of bad word file.
  }                                                             //-------------------------------

  icc_DEBUG("The bad word file is %s\n", badWordFile);


  // Initialize the Stacks.
  //---------------------------------------------------------------------------------------------
  for(ii=0; ii<NSTACKS; ii++)
  {
    badWordStack[ii] = iccStackInitVOIDP( 1024, "Bad Word Stack" );
  }

  // Allocate memory for the bad word buffer. 64 meg.
  //---------------------------------------------------------------------------------------------
  iDataINT08 = iccMallocINT08_Align032( 1024*1024*64 );

  // Open and read the bad word file.
  //---------------------------------------------------------------------------------------------
  fp = fopen(badWordFile,"r");                                  // Open the bad word file.
  fseek(fp,0,SEEK_END);                                         // Go to the end of the file
  fileLength = ftell(fp);                                       // and see how big the file is.
  rewind(fp);                                                   // "Rewind" file to the begining
  fread(iDataINT08, sizeof(CHR08), fileLength, fp);             // and read all the data at once.
  fclose(fp);                                                   // Close the bad word file.
                                                                //-------------------------------
  // Convert lower to upper case.
  //---------------------------------------------------------------------------------------------
  for(ii=0; ii<fileLength; ii++)
  {
    if( (iDataINT08[ii]>96) && (iDataINT08[ii]<123) ) iDataINT08[ii]-=32;
  }

  // Load up the bad word stacks.
  //---------------------------------------------------------------------------------------------
  sprintf(theDelimiters," ,\n\r");

  p = strtok(iDataINT08, theDelimiters);

  do
  {
   for(ii=0; ii<NSTACKS; ii++)
   {
     if     ( p && (strlen(p)==(ii+2)) ) 
     {
       stackStatus = iccStringStackPush( badWordStack[ii], p );
     }
   }
   p = strtok('\0', theDelimiters);
  }
  while(p);

  // Free up the memory.
  //---------------------------------------------------------------------------------------------
  iccFree(iDataINT08);

  // Allocate memory for the output buffer.
  //---------------------------------------------------------------------------------------------
  iDataINT08 = iccMallocINT08_Align032( BLOCK_SIZE );

  // Set up the delemiters.
  //---------------------------------------------------------------------------------------------
  sprintf(theDelimiters," _-()[]{}<>.\n\t\"");

  // Initialize the tolken holders.
  //---------------------------------------------------------------------------------------------
  sprintf(p7,"NONE");
  sprintf(p6,"NONE");
  sprintf(p5,"NONE");
  sprintf(p4,"NONE");
  sprintf(p3,"NONE");
  sprintf(p2,"NONE");
  sprintf(p1,"NONE");

  // Read in the data and write it out.
  //---------------------------------------------------------------------------------------------
  while ( (amountRead = fread(iDataINT08, sizeof(CHR08), BLOCK_SIZE, stdin)) > 0 )
  {
    // Convert lower to upper case.
    //-------------------------------------------------------------------------------------------
    for(ii=0; ii<amountRead; ii++)
    {
      if( (iDataINT08[ii]>96) && (iDataINT08[ii]<123) ) iDataINT08[ii]-=32;
    }

    // Convert control characters to a space.
    //-------------------------------------------------------------------------------------------
    for(ii=0; ii<amountRead; ii++)
    {
      if( (iDataINT08[ii]< 32) | (iDataINT08[ii]>126) )
      {
	iDataINT08[ii]=' ';
      }     
    }

    // 
    //-------------------------------------------------------------------------------------------
    p0 = strtok(iDataINT08, theDelimiters);

    do
    {
      for(ii=0; ii<NSTACKS; ii++)
      {
	if ( p1 && (strlen(p1)==(ii+2)) && (badWordStack[ii]->index > -1) ) 
	{
	  stackStatus = iccStringStackSearch( badWordStack[ii], p1 );
	  if( stackStatus == 1) 
	  {
	    printf("HIT on %10s: ",p1);
	    printf("CONTEXT: %s %s %s %s %s %s %s %s\n",p7,p6,p5,p4,p3,p2,p1,p0);
	  }
	}
      }
      sprintf(p7,"%s",p6);
      sprintf(p6,"%s",p5);
      sprintf(p5,"%s",p4);
      sprintf(p4,"%s",p3);
      sprintf(p3,"%s",p2);
      sprintf(p2,"%s",p1);
      sprintf(p1,"%s",p0);
      p0 = strtok('\0', theDelimiters);
    }
    while(p0);
  }

  // Done.
  //---------------------------------------------------------------------------------------------
  return(0);
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/

/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
