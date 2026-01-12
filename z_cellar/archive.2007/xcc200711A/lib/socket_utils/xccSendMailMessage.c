/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccSendMailMessage.c
// Desc: This file contains the code for the xccSendMailMessage routine.
// Hist: When       Who  What
//       11/14/2004 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "socket_utils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define XCC_SEND_MAIL_PORT 25

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
INT32 xccSendMailMessage(CHR08 *message, CHR08 *fromWhom, CHR08 *fromWhere, CHR08 *toWhom, CHR08 *toWhere)
{

  INT32 numBytes;
  INT16 socketFDS;
  CHR08 theMessage[1024*1024];
  CHR08 theResponse[1024];

  // Open sockets.
  //----------------------------------------------------------------------------
  socketFDS = xccStreamSocketOpen( toWhere, XCC_SEND_MAIL_PORT);
  if(socketFDS==0) return(-1);
  
  // Build the SMTP message.
  //----------------------------------------------------------------------------
  sprintf(theMessage,
	  "HELO %s\n"
	  "MAIL FROM:<>\n"
	  "RCPT TO:<%s>\n"
	  "DATA\n"
	  "FROM: %s@%s\n"
	  "TO: %s@%s\n"
	  "SUBJECT: %s\n"
	  "\n %s \n"
	  "\n.\n"
	  "QUIT\n",
	  toWhere, toWhom, fromWhom, fromWhere, toWhom, toWhere, message, message);

  // Send the message.
  //----------------------------------------------------------------------------
  numBytes = xccStreamSocketSend(socketFDS, theMessage, strlen(theMessage));

  if(numBytes == -1)
  {
    XMC_ERROR_STDOUT("ERROR SENDING DATA OVER SOCKET");
    perror("xccStreamSocketSend: send");
    return(-1);
  }

  
  // Process the responses.
  //----------------------------------------------------------------------------
  while ( (numBytes = xccStreamSocketReceive(socketFDS, theResponse, 1024 )) > 0)
  {
    //check somethings.
  };

  // Close sockets and return.
  //----------------------------------------------------------------------------
  close(socketFDS);


  return(0);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
