/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccDatagramSocketReceive.c
// Desc: This file contains the code for the iccDatagramSocketReceive routine.
// Hist: When       Who  What
//       05/20/2002 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "socket_utils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define DEBUG        FALSE

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
// Rout: iccDatagramSocketReceiveInit
// Desc: This routine initializes a datagram socket receiver.
//------------------------------------------------------------------------------
iccDatagramSocketSpec *iccDatagramSocketReceiveInit(INT32 msgSize, UNT16 thePort)
{
  INT32 ii;
  iccDatagramSocketSpec *spec;

// Allocate memory for the datagram receive spec.
//------------------------------------------------------------------------------
  spec = (iccDatagramSocketSpec *) iccMallocINT08_Align032(sizeof(iccDatagramSocketSpec));

// Allocate and clear memory for the message portion of the datagram receive spec.
//------------------------------------------------------------------------------
  spec->msg = iccMallocINT08_Align032(msgSize);
  for(ii=0; ii<msgSize; ii++) spec->msg[ii] =0;

// 
//------------------------------------------------------------------------------
  spec->thePort = thePort;
  spec->blockFlag = TRUE;
  spec->mcastFlag = -99;

// 
//------------------------------------------------------------------------------
  spec->thisAddr.sin_family      = AF_INET;
  spec->thisAddr.sin_port        = htons(thePort);
  spec->thisAddr.sin_addr.s_addr = INADDR_ANY;
  memset(&(spec->thisAddr.sin_zero), '\0', 8);

// Open a Datagram socket.
//------------------------------------------------------------------------------
  if( (spec->socketFD = socket(AF_INET, SOCK_DGRAM, 0))== -1)
  {
    perror("iccDatagramSocketReceive:");
    printf("Could not perform socket command.");
    printf("Socket Error.\n");
    return(NULL);
  }

// Bind the socket.
//------------------------------------------------------------------------------
  if( bind(spec->socketFD, (struct sockaddr *)&spec->thisAddr, sizeof(struct sockaddr)) == -1)
  {
    perror("iccDatagramSocketReceive:");
    printf("Could not perform bind command.");
    printf("Socket Error.\n");
    return(NULL);
  }

  return(spec);
}

//------------------------------------------------------------------------------
// Rout: iccDatagramSocketReceiveSetNB
// Desc: This routine sets up the "Non-Blocking" mechanism for datagram sockets.
//------------------------------------------------------------------------------
VOID iccDatagramSocketReceiveSetNB(iccDatagramSocketSpec *spec )
{
  spec->blockFlag = FALSE;
  fcntl(spec->socketFD, F_SETFL, O_NONBLOCK);
}

//------------------------------------------------------------------------------
// Rout: iccDatagramSocketReceiveSetMC
// Desc: This routine sets up the "Multicast" mechanism for datagram sockets.
//------------------------------------------------------------------------------
VOID iccDatagramSocketReceiveSetMC(iccDatagramSocketSpec *spec, const CHR08 *localIP, const CHR08 *mcastIP )
{
  struct hostent *h;

  // Set up and check local IP.
  //----------------------------------------------------------------------------
  if((inet_aton(localIP, &spec->localAddr)) == 0)
  {
    XMC_ERROR_STDOUT("Goofy local Address.");
  }

  // Set up and check multcast IP.
  //----------------------------------------------------------------------------
  if( (h = gethostbyname(mcastIP)) == NULL)
  {
    XMC_ERROR_STDOUT("Unknown multicast group.");
  }
  memcpy(&spec->mcastAddr, h->h_addr_list[0], h->h_length);

  if(!IN_MULTICAST(ntohl(spec->mcastAddr.s_addr)))
  {
    XMC_ERROR_STDOUT("Not a multicast address.");
  }

  // Negotiate multcast.
  //----------------------------------------------------------------------------
  spec->mcastRequest.imr_multiaddr.s_addr = spec->mcastAddr.s_addr;
  spec->mcastRequest.imr_interface.s_addr = spec->localAddr.s_addr;
  spec->mcastFlag = setsockopt(spec->socketFD, 
			       IPPROTO_IP,
			       IP_ADD_MEMBERSHIP,
			       (VOID *)&spec->mcastRequest,
			       sizeof(spec->mcastRequest));

  if (spec->mcastFlag < 0)
  {
    XMC_ERROR_STDOUT("Can not join multicast group.");
  }
  else
  {
    XMC_DEBUG_STDOUT("Multcast group joined.\n");
  }
}

//------------------------------------------------------------------------------
// Rout: iccDatagramSocketReceive
// Desc: This routine receives data over a datagram socket.
//------------------------------------------------------------------------------
INT32 iccDatagramSocketReceive(iccDatagramSocketSpec *spec)
{
  INT32 numBytes;
  socklen_t addr_len = sizeof(struct sockaddr);

// Try to receive the data.
//--------------------------------------------------------------------------
  numBytes = recvfrom(spec->socketFD, 
		      spec->msg,
		      ICC_MAX_MSG_LEN-1,
		      0,
		      (struct sockaddr *)&spec->thatAddr,
		      &addr_len);

// Check what happened.
//--------------------------------------------------------------------------
  if      (  spec->blockFlag && ((numBytes  == -1) || (numBytes  ==  1)) )
  {
    XMC_DEBUG_STDOUT("ERROR\n");
    return(-1);
  }
  else if ( !spec->blockFlag && ((numBytes  ==  0) || (numBytes  ==  1)) )
  {
    XMC_DEBUG_STDOUT("ERROR\n");
    return(-1);
  }
  else if ( !spec->blockFlag && (numBytes  == -1) )
  {
    if(DEBUG) XMC_DEBUG_STDOUT("No data yet.  Check back later.\n");
    return(0);
  }
  else // (numBytes > 1 )
  {
    //icc_DEBUG("Got packet from %s.  ", inet_ntoa(spec->thatAddr.sin_addr));
    //icc_DEBUG("Packet is %ld bytes long.\n",numBytes);
  }

// Done.  Return numBytes.  Close done by OS.
//--------------------------------------------------------------------------
  return(numBytes);

}

#if 0
//------------------------------------------------------------------------------
// Rout: iccDatagramSocketReceiveTerm
// Desc: This routine terminates a datagram socket receiver.
//------------------------------------------------------------------------------
VOID iccDatagramSocketReceiveTerm(iccDatagramSocketSpec *spec )
{
  if(spec->mcastFlag >= 0) // Take care of possible multicast subscription.
  {
    spec->mcastFlag = setsockopt(spec->socketFD, 
				 IPPROTO_IP,
				 IP_DROP_MEMBERSHIP,
				 (VOID *)&spec->mcastRequest,
				 sizeof(spec->mcastRequest));
  }
  close(spec->socketFD);
  xmcFree(spec);
  sleep(1);
}
#endif

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/

//------------------------------------------------------------------------------
// Rout: iccDatagramSocketReceiveSetAck
// Desc: This routine sets up the "Acknowledge" mechanism for datagram sockets.
//------------------------------------------------------------------------------
//VOID iccDatagramSocketReceiveSetAck(iccDatagramSocketReceiveSpec *spec, UNT16 ackPort, INT32 ackWord )
//{
//  spec->ackFlag = TRUE;
//  spec->ackPort = ackPort;
//  spec->ackWord = htonl(ackWord);
//}
