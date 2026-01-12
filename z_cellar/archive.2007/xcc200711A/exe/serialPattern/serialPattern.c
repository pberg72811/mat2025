/* ****************************************************************************
 * File: serialPattern.c
 * Description: This routine generates a bit pattern and passes it to the 
 *              serial port /dev/cua0.
 *
 * History:
 * yyyymmmdd pid    Description
 * ----------------------------------------------------------------------------
 * 2001Jul05 bergman Created
 * ****************************************************************************/
/* Include files: */
#include "iccswd.h"
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

#define INPUT_BLOCK_SIZE  (1024)
#define OUTPUT_BLOCK_SIZE (1024)

#define SERIAL_PATTERN_FUNC_DESC \
"********************************************************************************\n"\
"This routine generates a bit pattern and passes it to the serial port /dev/cua0.\n"\
"                                                                                \n"\
"Input : is from stdin.                                                          \n"\
"                                                                                \n"\
"Output: is to stdout.                                                           \n"\
"                                                                                \n"\
"Input parmaters are:                                                            \n"\
"  baudRate - Baud rate to transmit at.                                          \n"\
"  dataBits - Number of data bits.                                               \n"\
"  stopBits - Number of stop bits.                                               \n"\
"  pariBits - Number of parity bits.                                             \n"\
"                                                                                \n"\
"Optional parmaters are:                                                         \n"\
"  NONE                                                                          \n"\
"********************************************************************************\n"\
"\n"

/* Function: **********************************************************/
int main

/* Description: main() 
 *
 * Returns: (int)
 *
 * Notes: 
 *
 * Parameters:
 * Type      Name      Description
 * ------------------------------------------------------------------- */
 ( int    argc, /* */
   char **argv) /* */
{
  /* Variables:
   * Type      Name      Description
   * ---------------------------------------------------------------- */
  unsigned char ii;
  unsigned char jj;
  unsigned char kk;
  int32_t       ll;
  int32_t       baudRate;
  int32_t       dataBits;
  int32_t       stopBits;
  int32_t       pariBits;
  int           fd;
  struct termios options;

  /* Handle input parameters -------------------------------------------------*/
  for(ii = 1; ii<argc; ii++) //argv[0] is program name.
  {
    if( (!strncmp( argv[ii], "-h",     2)) || 
	(!strncmp( argv[ii], "--help", 6))   )
    {
      printf(SERIAL_PATTERN_FUNC_DESC);
      exit(0);
    }
    else if( (argc != 4+1) )
    {
      printf("serialPattern needs 4 and only 4 arguments.");
      printf(SERIAL_PATTERN_FUNC_DESC);
      exit(0);
    }
    else
    {
      if(ii==1) sscanf(argv[ii],"%d", &baudRate);
      if(ii==2) sscanf(argv[ii],"%d", &dataBits);
      if(ii==3) sscanf(argv[ii],"%d", &stopBits);
      if(ii==4) sscanf(argv[ii],"%d", &pariBits);
    }
  }

  /* Open the serial port for writing. ---------------------------------------*/
  fd = open("/dev/cua0", O_RDWR | O_NOCTTY | O_NDELAY);
  if( fd == -1 ) perror("open_port: Unable to open /dev/cua0\n");

  // 
  /* -------------------------------------------------------------------------*/
  fcntl(fd, F_SETFL, FNDELAY); // We want the no wait behavior for reading the serial buffer.
  //fcntl(fd, F_SETFL, 0);

  // Get the current arrtributes of the serial port.
  /* -------------------------------------------------------------------------*/
  tcgetattr(fd, &options);
 
  // Set the baud rate based on input parameter.
  /* -------------------------------------------------------------------------*/
  if(baudRate ==   75){ cfsetispeed(&options,   B75);cfsetospeed(&options,   B75); }
  if(baudRate ==  150){ cfsetispeed(&options,  B150);cfsetospeed(&options,  B150); }
  if(baudRate ==  300){ cfsetispeed(&options,  B300);cfsetospeed(&options,  B300); }
  if(baudRate ==  600){ cfsetispeed(&options,  B600);cfsetospeed(&options,  B600); }
  if(baudRate == 1200){ cfsetispeed(&options, B1200);cfsetospeed(&options, B1200); }
  if(baudRate == 2400){ cfsetispeed(&options, B2400);cfsetospeed(&options, B2400); }

  // 
  /* -------------------------------------------------------------------------*/
  options.c_cflag |= (CLOCAL | CREAD);

  // Set the data bit size based on input parameter.
  /* -------------------------------------------------------------------------*/
  options.c_cflag &= ~CSIZE;
  if(dataBits==5) options.c_cflag |= CS5;
  if(dataBits==6) options.c_cflag |= CS6;
  if(dataBits==7) options.c_cflag |= CS7;
  if(dataBits==8) options.c_cflag |= CS8;
  
  // Set the stop bit size based on input parameter.
  /* -------------------------------------------------------------------------*/
  options.c_cflag &= ~CSTOPB;
  if(stopBits==2) options.c_cflag |=  CSTOPB;
  else            options.c_cflag &= ~CSTOPB;
  
  // Set the parity bit based on input parameter.
  /* -------------------------------------------------------------------------*/
  options.c_cflag &= ~PARENB;
  if(pariBits==1) options.c_cflag |=  PARENB;
  else            options.c_cflag &= ~PARENB;
  
  // Set hardware flow control to RTS/CTS.
  /* -------------------------------------------------------------------------*/
  options.c_cflag |= CRTSCTS;

  // Choose raw output.
  /* -------------------------------------------------------------------------*/
  options.c_oflag &= ~OPOST;

  // Thats it, now set the serial port attributes.
  /* -------------------------------------------------------------------------*/
  tcsetattr(fd, TCSAFLUSH, &options);

  // Crank out the data.  Use 1<<dataBits to calc how high to count. 
  /* -------------------------------------------------------------------------*/
  ll=(((float)dataBits)/((float)baudRate))*1e6;
  printf("Hey about to send data at a rate of 1 char per %d microSeconds.\n",ll);
  for(ii = 0; ii < 450; ii++)
  {
    for(jj=0; jj < (1<<dataBits); jj++)
    {
      kk = jj;
      write(fd,&kk,1); 
      usleep(ll); 
    }
  }

  close(fd);

  return(0);
}
