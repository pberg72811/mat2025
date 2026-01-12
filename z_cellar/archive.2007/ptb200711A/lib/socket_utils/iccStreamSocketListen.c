/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccStreamSocketListen.c
// Desc: This file contains the code for the iccStreamSocketListen routine.
// Hist: When       Who  What
//       07/08/2004 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "socket_utils.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define BACKLOG 10

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
INT16 iccStreamSocketListen(INT32 port)
{
  INT16 socketFD;
  INT32 YES=1;
  struct sockaddr_in myAddr;

// Open a socket.
//------------------------------------------------------------------------------
  if( (socketFD = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {
    perror("ERROR iccStremSocketListen:  socket.");
    exit(1);
  }

// Set socket options.
//------------------------------------------------------------------------------
  if( setsockopt(socketFD, SOL_SOCKET, SO_REUSEADDR, &YES, sizeof(int)) == -1)
  {
    perror("ERROR iccStremSocketListen:  setsocketopt.");
    exit(1);
  }
  
// Set parameters.
//------------------------------------------------------------------------------
  myAddr.sin_family      = AF_INET;         //
  myAddr.sin_port        = htons(port);     // 
  myAddr.sin_addr.s_addr = INADDR_ANY;      // Automatically fill with servers IP.
  memset( &(myAddr.sin_zero),0, 8);         // Zero out this portion of structure.
  
// Bind to socket.
//------------------------------------------------------------------------------
  if( bind(socketFD, (struct sockaddr *)&myAddr, sizeof(struct sockaddr)) == -1 )
  {
    perror("ERROR iccStremSocketListen: bind.");
    exit(1);
  }

// Listen to socket.
//------------------------------------------------------------------------------
  if( listen(socketFD, BACKLOG) == -1)
  {
    perror("ERROR iccStremSocketListen:  listen");
    exit(1);
  }

// Return sock file descriptor "socketFD".
//------------------------------------------------------------------------------
  return(socketFD);
}

//------------------------------------------------------------------------------
// Rout: iccStreamSocketSetNB
// Desc: This routine sets up the "Non-Blocking" mechanism for steam sockets.
//       Not much to it.
//------------------------------------------------------------------------------
VOID iccStreamSocketSetNB(INT16 socketFD)
{
  fcntl(socketFD, F_SETFL, O_NONBLOCK);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
