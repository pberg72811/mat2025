/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccDatagramSocketSendWithAck.c
// Desc: This file contains the code for the iccDatagramSocketSendWithAck routine.
// Hist: When       Who  What
//       01/17/2004 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "socket_utils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define DEBUG 1
#define TIMEOUT 30

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
INT32 iccDatagramSocketSendWithAck(VOID *msg, INT32 msgSize, const CHR08 *nameOrAddress, UNT16 port, UNT16 ackPort, INT32 ackWord)
{
  INT32 ii;
  INT32 status;
  INT32 ackReceived;
  INT16 socketFD;
  INT32 numBytes;
  struct hostent *he;
  struct sockaddr_in theirAddr;
  iccDatagramSocketReceiveSpec *spec;

// Initialize the acknowledge receiver.
//------------------------------------------------------------------------------
  spec = iccDatagramSocketReceiveInit(sizeof(ackReceived), ackPort);

  iccDatagramSocketReceiveSetNB( spec );

// gethostbyname
//------------------------------------------------------------------------------
  if( (he=gethostbyname(nameOrAddress)) == NULL )
  {
    perror("iccDatagramSocketSend:");
    printf("Host name Error.\n");
    return(-1);
  }

// Open a socket.
//------------------------------------------------------------------------------
  if( (socketFD = socket(AF_INET, SOCK_DGRAM, 0))== -1)
  {
    perror("iccDatagramSocketSend:");
    printf("Socket Error.\n");
    return(-1);
  }
  
// Set parameters.
//------------------------------------------------------------------------------
  theirAddr.sin_family      = AF_INET;
  theirAddr.sin_port        = htons(port);
  theirAddr.sin_addr.s_addr = inet_addr(nameOrAddress);
  memset( &(theirAddr.sin_zero),0, 8);

// Send the data.
//------------------------------------------------------------------------------
  numBytes = sendto(socketFD, 
		    msg,
		    msgSize,
		    0, 
		    (struct sockaddr *)&theirAddr,
		    sizeof(struct sockaddr) );

  if(numBytes == -1)
  {
    perror("iccDatagramSocketSend:");
    printf("Send Error.\n");
    return(-1);
  }

// Look for the acknowledge.
//------------------------------------------------------------------------------
  for(ii=0; ii<TIMEOUT; ii++)
  {
    status = iccDatagramSocketReceive(spec);
    ackReceived = iccDatagramMsgExtractINT32(0, spec);
    if(status>1) ii=TIMEOUT;
    else         sleep(1);
    icc_DEBUG("iccDatagramSocketSendWithAck:  Waiting for acknowledge.\n");
  }

// Check to see what happened.
//------------------------------------------------------------------------------
  if     (status==-1)
  {
    //Connection timed out.
    icc_DEBUG("iccDatagramSocketSendWithAck:  Connection timed out.\n");
    iccDatagramSocketReceiveTerm( spec );
    return(-1);
  }
  else if(status==0)
  {
    //Goofyness happend.
    icc_DEBUG("iccDatagramSocketSendWithAck:  Network error of some kind..\n");
    iccDatagramSocketReceiveTerm( spec );
    return(-1);
  }

  if( ackReceived == ackWord )
  {
    //Acknowledge received.
    icc_DEBUG("iccDatagramSocketSendWithAck:  Received Acknowledge.\n");
    iccDatagramSocketReceiveTerm( spec );
    return(numBytes);
  }
  else
  {
    //Wrong acknowledge received.
    icc_DEBUG("iccDatagramSocketSendWithAck:  Received Wrong Acknowledge.\n");
    icc_DEBUG("iccDatagramSocketSendWithAck:  Received %ld.\n", ackReceived);
    icc_DEBUG("iccDatagramSocketSendWithAck:  Should have received %ld.\n", ackWord);
    iccDatagramSocketReceiveTerm( spec );
    return(-1);
  }

}
/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
