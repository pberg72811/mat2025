/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccCHR08PackUnPack.c
// Desc: This file contains the code for the xccCHR08PackUnPack routine.
// Hist: When       Who  What
//       09/27/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "stack_utils.h" 
 
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
INT32 xccCHR08UnpackMSB_INT08( xccStackINT08_t *p2Stack, INT08 c )
{
  INT32 status;
  status = xccStackPushINT08( p2Stack, (((INT08)c) & 0x80) >> 7);
  status = xccStackPushINT08( p2Stack, (((INT08)c) & 0x40) >> 6);
  status = xccStackPushINT08( p2Stack, (((INT08)c) & 0x20) >> 5);
  status = xccStackPushINT08( p2Stack, (((INT08)c) & 0x10) >> 4);
  status = xccStackPushINT08( p2Stack, (((INT08)c) & 0x08) >> 3);
  status = xccStackPushINT08( p2Stack, (((INT08)c) & 0x04) >> 2);
  status = xccStackPushINT08( p2Stack, (((INT08)c) & 0x02) >> 1);
  status = xccStackPushINT08( p2Stack, (((INT08)c) & 0x01) >> 0);
  return(status);
}

INT32 xccCHR08UnpackLSB_INT08( xccStackINT08_t *p2Stack, INT08 c )
{
  INT32 status;
  status = xccStackPushINT08( p2Stack, (((INT08)c) & 0x01) >> 0);
  status = xccStackPushINT08( p2Stack, (((INT08)c) & 0x02) >> 1);
  status = xccStackPushINT08( p2Stack, (((INT08)c) & 0x04) >> 2);
  status = xccStackPushINT08( p2Stack, (((INT08)c) & 0x08) >> 3);
  status = xccStackPushINT08( p2Stack, (((INT08)c) & 0x10) >> 4);
  status = xccStackPushINT08( p2Stack, (((INT08)c) & 0x20) >> 5);
  status = xccStackPushINT08( p2Stack, (((INT08)c) & 0x40) >> 6);
  status = xccStackPushINT08( p2Stack, (((INT08)c) & 0x80) >> 7);
  return(status);
}

INT32 xccCHR08PackMSB_INT08( xccStackINT08_t *p, INT08 *c )
{
  INT08 temp;
  INT32 status;
  *c = 0;
  status = xccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<7);
  status = xccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<6);
  status = xccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<5);
  status = xccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<4);
  status = xccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<3);
  status = xccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<2);
  status = xccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<1);
  status = xccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<0);
  return(status);
}

INT32 xccCHR08PackLSB_INT08( xccStackINT08_t *p, INT08 *c )
{
  INT08 temp;
  INT32 status;
  *c = 0;
  status = xccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<0);
  status = xccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<1);
  status = xccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<2);
  status = xccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<3);
  status = xccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<4);
  status = xccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<5);
  status = xccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<6);
  status = xccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<7);
  return(status);
}
