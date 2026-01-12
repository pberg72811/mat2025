/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccDatagramSocketSend.c
// Desc: This file contains the code for the xccDatagramSocketSend routine.
// Hist: When       Who  What
//       05/20/2002 ptb  Initial Code.
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include "socket_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG 1

/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
//-----------------------------------------------------------------------------------------------
// Rout: xccDatagramSocketSendInit
// Desc: This routine initializes a datagram socket and the datagram spec.
//-----------------------------------------------------------------------------------------------
xccDatagramSocketSpec *xccDatagramSocketSendInit(const CHR08 *nameOrAddress, UNT16 thePort)
{
  xccDatagramSocketSpec *spec;

// Allocate memory for the datagram receive spec.
//-----------------------------------------------------------------------------------------------
  spec = (xccDatagramSocketSpec *) xccMallocINT08_Align032(sizeof(xccDatagramSocketSpec));

// Allocate and clear memory for the message portion of the datagram receive spec.
//-----------------------------------------------------------------------------------------------
  spec->msg = xccMallocINT08_Align032(XCC_MAX_MSG_LEN);
  //for(ii=0; ii<XCC_MAX_MSG_LEN; ii++) spec->msg[ii] =0;

// Set the port.
//-----------------------------------------------------------------------------------------------
  spec->thePort = thePort;
  spec->blockFlag = TRUE;
  spec->mcastFlag = -99;

// Send the data to where? 
//-----------------------------------------------------------------------------------------------
  spec->thatAddr.sin_family      = AF_INET;
  spec->thatAddr.sin_port        = htons(thePort);
  spec->thatAddr.sin_addr.s_addr = inet_addr(nameOrAddress);
  memset( &(spec->thatAddr.sin_zero),0, 8);

// Open a Datagram socket.
//-----------------------------------------------------------------------------------------------
  if( (spec->socketFD = socket(AF_INET, SOCK_DGRAM, 0))== -1)
  {
    perror("xccDatagramSocketSendInit:");
    printf("Could not perform socket command.");
    printf("Socket Error.\n");
    return(NULL);
  }

  return(spec);
}

//-----------------------------------------------------------------------------------------------
// Rout: xccDatagramSocketSend
// Desc: This routine sends data out a datagram socket.
//-----------------------------------------------------------------------------------------------
INT32 xccDatagramSocketSend(VOID *msg, INT32 msgSize, xccDatagramSocketSpec *spec)
{
  INT32 numBytes;

// Check message size.
//-----------------------------------------------------------------------------------------------
  if( msgSize > XCC_MAX_MSG_LEN)
  {
    XMC_ERROR_STDOUT("msgSize to greater then XCC_MAX_MSG_LEN (%d).\n",XCC_MAX_MSG_LEN);
  }


// Send the data.
//-----------------------------------------------------------------------------------------------
  numBytes = sendto(spec->socketFD, 
		    msg,
		    msgSize,
		    0, 
		    (struct sockaddr *)&spec->thatAddr,
		    sizeof(struct sockaddr) );

  if(numBytes == -1)
  {
    perror("xccDatagramSocketSend:");
    XMC_ERROR_STDOUT("Send Error.\n");
    return(-1);
  }

// Return number of bytes sent.
//-----------------------------------------------------------------------------------------------
  return(numBytes);
}

//-----------------------------------------------------------------------------------------------
// Rout: xccDatagramSocketTerm
// Desc: This routine terminates a datagram socket receiver.
//-----------------------------------------------------------------------------------------------
VOID xccDatagramSocketTerm(xccDatagramSocketSpec *spec )
{
  if(spec->mcastFlag >= 0)                    // Take care of possible multicast subscription.
  {                                           // 
    spec->mcastFlag =                         // 
      setsockopt(spec->socketFD,              // 
		 IPPROTO_IP,                  // 
		 IP_DROP_MEMBERSHIP,          // 
		 (VOID *)&spec->mcastRequest, // 
		 sizeof(spec->mcastRequest)); // 
  }                                           // 
  close(spec->socketFD);                      // Close the socket.
  xmcFree(spec);                              // Free allocated memory of spec.
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/

/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
