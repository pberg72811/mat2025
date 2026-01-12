/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: socket_iutils.h
// Desc: This is the header file for socket_utils.
// Hist: When       Who  What
//       05/20/2002 ptb  Initial Code.
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#ifndef SOCKET_UTILS_H
#define SOCKET_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "xmc.h"
#include "malloc_utils.h"
#include "orbit_utils.h"
#include "socket_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define iccSocketClose  close
#define ICC_MAX_MSG_LEN 81920

/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
typedef struct
{
  INT16 socketFD;
  UNT16 thePort;
  INT32 blockFlag;
  INT32 mcastFlag;
  INT08 *msg;
  struct sockaddr_in thisAddr;
  struct sockaddr_in thatAddr;
  struct in_addr mcastAddr;
  struct in_addr localAddr;
  struct ip_mreq mcastRequest;
} iccDatagramSocketSpec;

/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
INT16 iccStreamSocketOpen(const CHR08 *nameOrAddress, INT32 port);
INT32 iccStreamSocketSend(INT16 sockFD, VOID *msg, INT32 msgSize);
INT16 iccStreamSocketListen(INT32 port);
INT32 iccStreamSocketReceive(INT16 sockFD, VOID *msg, INT32 msgSize);
VOID  iccStreamSocketSetNB(INT16 socketFD);

iccDatagramSocketSpec *iccDatagramSocketReceiveInit(INT32 msgSize, UNT16 thePort);
VOID  iccDatagramSocketReceiveSetNB(iccDatagramSocketSpec *spec );
VOID  iccDatagramSocketReceiveSetMC(iccDatagramSocketSpec *spec, const CHR08 *localIP, const CHR08 *mcastIP );
INT32 iccDatagramSocketReceive(iccDatagramSocketSpec *spec);
VOID  iccDatagramSocketTerm(iccDatagramSocketSpec *spec );
iccDatagramSocketSpec *iccDatagramSocketSendInit(const CHR08 *nameOrAddress, UNT16 thePort);
INT32 iccDatagramSocketSend(VOID *msg, INT32 msgSize, iccDatagramSocketSpec *spec);

INT32 iccSendMailMessage( CHR08 *message, CHR08 *fromWhom, CHR08 *fromWhere, CHR08 *toWhom, CHR08 *toWhere );

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/

  //INT32 iccDatagramSocketReceive(VOID *msg, UNT16 thePort);
  //INT32 iccDatagramSocketReceiveNB(VOID *msg, UNT16 thePort);
  //INT32 iccDatagramSocketSendWithAck(VOID *msg, INT32 msgSize, const CHR08 *nameOrAddress, UNT16 port, UNT16 ackPort, INT32 ackWord);
  //VOID  iccDatagramSocketReceiveSetAck(iccDatagramSocketReceiveSpec *spec, UNT16 ackPort, INT32 ackWord );
