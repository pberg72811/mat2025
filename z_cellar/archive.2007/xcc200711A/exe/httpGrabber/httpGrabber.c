/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: httpGrabber.c
// Desc: This file contains the code for the httpGrabber binary.
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

#define THE_PORT      80
#define MAX_BUF_LEN  (1024*64)
#define DEFAULT_TIME (60*60*24)
#define HTTP_GRABBER_FUNC_DESC \
"********************************************************************************\n"\
"This program goes out and grabs internet http files.                            \n"\
"                                                                                \n"\
"Input  is from a socket to a http server.                                       \n"\
"                                                                                \n"\
"Output is to a stdout.                                                          \n"\
"                                                                                \n"\
"Input parmaters are:                                                            \n"\
"  Host URL (minus the ""http://"")                                              \n"\
"  File name to grab                                                             \n"\
"                                                                                \n"\
"Optional parmaters are:                                                         \n"\
"  None.                                                                         \n"\
"                                                                                \n"\
"Examples:                                                                       \n"\
"httpGrabber image.weather.com /images/maps/current/curwx_600x405.jpg > test.jpg   \n"\
"httpGrabber www.celestrak.com /NORAD/elements/tdrss.txt > test.txt              \n"\
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
  INT16 socketFD;
  INT32 numBytes;
  CHR08 *messageToSend;
  CHR08 *messageToRecv;
  INT32 messageToSendSize;
  INT32 messageToRecvSize;
  CHR08 siteName[1024];
  CHR08 siteFile[1024];

// Handle command line arguments.
//------------------------------------------------------------------------------
  for(ii = 0; ii<argc; ii++) //argv[0] is program name.
  {
    if( (!strncmp( argv[ii], "-h",     2)) || 
	(!strncmp( argv[ii], "--help", 6))   )
    {
      fprintf(stderr, HTTP_GRABBER_FUNC_DESC);
      exit(0);
    }
    else if( argc != 3 )
    {
      fprintf(stderr, HTTP_GRABBER_FUNC_DESC);
      exit(0);
    }
    else
    {
      if(ii==1)
      {
	sscanf(argv[ii],"%s", siteName);
      }
      if(ii==2)
      {
	sscanf(argv[ii],"%s", siteFile);
      }
    }
  }

  // Size some buffers.
  //--------------------------------------------------------------------------
  messageToSend = (CHR08 *) iccMallocINT08_Align032(MAX_BUF_LEN);
  messageToRecv = (CHR08 *) iccMallocINT08_Align032(MAX_BUF_LEN);

  // Construct the request.
  //--------------------------------------------------------------------------
  sprintf(messageToSend,
	  "GET %s HTTP/1.0\n"
	  "Host: %s\n"
	  "From: anonymous@bink.com\n"
	  "User-Agent: HTTPTool/1.1\n"
	  "\n",
	  siteFile, siteName
	  );

  // 
  //--------------------------------------------------------------------------
  messageToSendSize = strlen(messageToSend);
  messageToRecvSize = MAX_BUF_LEN;

  // Open the socket.
  //--------------------------------------------------------------------------
  socketFD = iccStreamSocketOpen(siteName, THE_PORT);

  // Send the request.
  //--------------------------------------------------------------------------
  status   = iccStreamSocketSend(socketFD, messageToSend, messageToSendSize);
  
  // First grab is the header.  Need to make this more intelligent.
  //--------------------------------------------------------------------------
  numBytes = iccStreamSocketReceive(socketFD, messageToRecv, messageToRecvSize);

  // Get the reply and save it off to file.
  //--------------------------------------------------------------------------
  while( (numBytes = iccStreamSocketReceive(socketFD, messageToRecv, messageToRecvSize)) > 0 )
  {
    fwrite( messageToRecv, sizeof(CHR08), numBytes, stdout); // Output the data.
    fprintf(stderr,"BYTES %ld\n",numBytes);
  }

  // Close the socket.
  //--------------------------------------------------------------------------
  close(socketFD);


  return(0);
 
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
