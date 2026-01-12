/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccStreamSocketReceive.c
// Desc: This file contains the code for the iccStreamSocketReceive routine.
// Note: If msgSize is set to -1 then there are no expectations on the size of
//       the received message.
// Hist: When       Who  What
//       05/20/2002 ptb  Initial Code.
//       07/30/2004 ptb  Relaxed Error for numBytes != msgSize.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "socket_utils.h"

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
INT32 iccStreamSocketReceive(INT16 sockFD, VOID *msg, INT32 msgSize)
{
  INT32 numBytes;

  numBytes = recv(sockFD, msg, msgSize, 0);

  if( numBytes == -1 )
  {
    XMC_ERROR_STDOUT("ERROR RECEIVING DATA OVER SOCKET");
    perror("iccStreamSocketReceive: recv");
    return(-1);
  }
  else if ( (msgSize!=-1) && (numBytes > msgSize) )
  {
    XMC_ERROR_STDOUT("RETURNED NUMBER OF BYTES GREATER THEN MSGSIZE");
    return(numBytes);
  }
  else return(numBytes);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
