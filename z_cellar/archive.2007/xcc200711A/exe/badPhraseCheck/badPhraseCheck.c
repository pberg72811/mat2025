/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: badPhraseCheck.c
// Desc: This program checks for bad phases.
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
  CHR08 *p0;
  CHR08 p1[512];
  CHR08 p2[512];
  CHR08 p3[512];
  CHR08 p4[512];
  CHR08 p5[512];
  CHR08 p6[512];
  CHR08 p7[512];
  CHR08 p8[512];
  CHR08 p9[512];
  CHR08 bp1[512];
  CHR08 bp2[512];
  CHR08 bp3[512];
  CHR08 bp4[512];
  CHR08 bp5[512];
  INT32 ii;
  INT32 amountRead;
  INT08 *iDataINT08;
  CHR08 theDelimiters[128];
  INT32 nWordsInPhrase;
    
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
    if(ii == 1)	sscanf(argv[ii],"%s", bp1);                     // Get word 1 of phrase.
    if(ii == 2)	sscanf(argv[ii],"%s", bp2);                     // Get word 2 of phrase.
    if(ii == 3)	sscanf(argv[ii],"%s", bp3);                     // Get word 3 of phrase.
    if(ii == 4)	sscanf(argv[ii],"%s", bp4);                     // Get word 4 of phrase.
    if(ii == 5)	sscanf(argv[ii],"%s", bp5);                     // Get word 5 of phrase.
  }                                                             //-------------------------------

  nWordsInPhrase = ii-1;

  // Allocate memory for the output buffer.
  //---------------------------------------------------------------------------------------------
  iDataINT08 = iccMallocINT08_Align032( BLOCK_SIZE );

  // Set up the delemiters.
  //---------------------------------------------------------------------------------------------
  sprintf(theDelimiters," _-()[]{}<>.\n\t\"");

  // Initialize the tolken holders.
  //---------------------------------------------------------------------------------------------
  sprintf(p9,"NONE");
  sprintf(p8,"NONE");
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
      if ( nWordsInPhrase==2 && p1 && !strcmp(p2,bp1) && !strcmp(p1,bp2) ) 
      {
	printf("HIT on %s %s: ",bp1,bp2);
	printf("CONTEXT: %s %s %s %s %s %s %s %s %s %s\n",p9,p8,p7,p6,p5,p4,p3,p2,p1,p0);
      }
      if ( nWordsInPhrase==3 && p1 && !strcmp(p3,bp1) && !strcmp(p2,bp2) && !strcmp(p1,bp3) ) 
      {
	printf("HIT on %s %s %s: ",bp1,bp2,bp3);
	printf("CONTEXT: %s %s %s %s %s %s %s %s %s %s\n",p9,p8,p7,p6,p5,p4,p3,p2,p1,p0);
      }
      if ( nWordsInPhrase==4 && p1 && !strcmp(p4,bp1) && !strcmp(p3,bp2) && !strcmp(p2,bp3) && !strcmp(p1,bp4) ) 
      {
	printf("HIT on %s %s %s %s: ",bp1,bp2,bp3,bp4);
	printf("CONTEXT: %s %s %s %s %s %s %s %s %s %s\n",p9,p8,p7,p6,p5,p4,p3,p2,p1,p0);
      }
      if ( nWordsInPhrase==5 && p1 && !strcmp(p5,bp1) && !strcmp(p4,bp2) && !strcmp(p3,bp3) && !strcmp(p2,bp4) && !strcmp(p1,bp5) ) 
      {
	printf("HIT on %s %s %s %s %s: ",bp1,bp2,bp3,bp4,bp5);
	printf("CONTEXT: %s %s %s %s %s %s %s %s %s %s\n",p9,p8,p7,p6,p5,p4,p3,p2,p1,p0);
      }
      sprintf(p9,"%s",p8);
      sprintf(p8,"%s",p7);
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
