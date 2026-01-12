/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: sendM.c
// Desc: This file contains the code for the sendM binary.
// Hist: When       Who  What
//       12/31/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "iccswd.h"
#include "iccSocketUtils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define DEBUG 1

#define SEND_M_FUNC_DESC \
"********************************************************************************\n"\
"This program goes sends an e-mail message.                                      \n"\
"                                                                                \n"\
"Input  is command-line.                                                         \n"\
"                                                                                \n"\
"Output is to an e-mail address.                                                 \n"\
"                                                                                \n"\
"Input parmaters are:                                                            \n"\
"  Person to send e-mail to.                                                     \n"\
"  Message to send.                                                              \n"\
"                                                                                \n"\
"Optional parmaters are:                                                         \n"\
"  None.                                                                         \n"\
"                                                                                \n"\
"Examples:                                                                       \n"\
"sendM to_person@192.9.111.1 Message_to_Send                                     \n"\
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
  INT32 ii;
  INT32 status;
  INT16 IA1,IA2,IA3,IA4;
  CHR08 userEmailAddress[1024];
  CHR08 userName[1024];
  CHR08 userAddress[1024];
  CHR08 userMessage[1024];
  CHR08 *p2String1;
  CHR08 *p2String2;

// Handle command line arguments.
//------------------------------------------------------------------------------
  for(ii = 0; ii<argc; ii++) //argv[0] is program name.
  {
    if( (!strncmp( argv[ii], "-h",     2)) || 
	(!strncmp( argv[ii], "--help", 6))   )
    {
      fprintf(stderr, SEND_M_FUNC_DESC);
      exit(0);
    }
    else if( argc != 3 )
    {
      fprintf(stderr, SEND_M_FUNC_DESC);
      exit(0);
    }
    else
    {
      if(ii==1)
      {
	sscanf(argv[ii],"%s", userEmailAddress);
      }
      if(ii==2)
      {
	sprintf(userMessage, "%s", argv[ii]);
      }
    }
  }

  // 
  //--------------------------------------------------------------------------
  sprintf( userName, "%s", strtok(userEmailAddress,"@") );
  sprintf( userAddress, "%s", strtok('\0',"@") );

  // 
  //--------------------------------------------------------------------------
  status = iccSendMailMessage(userMessage, "ME", "HERE", userName, userAddress);


  return(0);
 
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
