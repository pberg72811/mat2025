/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccCHR08PackUnPack.c
// Desc: This file contains the code for the iccCHR08PackUnPack routine.
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
INT32 iccCHR08UnpackMSB_INT08( iccStackINT08_t *p2Stack, INT08 c )
{
  INT32 status;
  status = iccStackPushINT08( p2Stack, (((INT08)c) & 0x80) >> 7);
  status = iccStackPushINT08( p2Stack, (((INT08)c) & 0x40) >> 6);
  status = iccStackPushINT08( p2Stack, (((INT08)c) & 0x20) >> 5);
  status = iccStackPushINT08( p2Stack, (((INT08)c) & 0x10) >> 4);
  status = iccStackPushINT08( p2Stack, (((INT08)c) & 0x08) >> 3);
  status = iccStackPushINT08( p2Stack, (((INT08)c) & 0x04) >> 2);
  status = iccStackPushINT08( p2Stack, (((INT08)c) & 0x02) >> 1);
  status = iccStackPushINT08( p2Stack, (((INT08)c) & 0x01) >> 0);
  return(status);
}

INT32 iccCHR08UnpackLSB_INT08( iccStackINT08_t *p2Stack, INT08 c )
{
  INT32 status;
  status = iccStackPushINT08( p2Stack, (((INT08)c) & 0x01) >> 0);
  status = iccStackPushINT08( p2Stack, (((INT08)c) & 0x02) >> 1);
  status = iccStackPushINT08( p2Stack, (((INT08)c) & 0x04) >> 2);
  status = iccStackPushINT08( p2Stack, (((INT08)c) & 0x08) >> 3);
  status = iccStackPushINT08( p2Stack, (((INT08)c) & 0x10) >> 4);
  status = iccStackPushINT08( p2Stack, (((INT08)c) & 0x20) >> 5);
  status = iccStackPushINT08( p2Stack, (((INT08)c) & 0x40) >> 6);
  status = iccStackPushINT08( p2Stack, (((INT08)c) & 0x80) >> 7);
  return(status);
}

INT32 iccCHR08PackMSB_INT08( iccStackINT08_t *p, INT08 *c )
{
  INT08 temp;
  INT32 status;
  *c = 0;
  status = iccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<7);
  status = iccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<6);
  status = iccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<5);
  status = iccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<4);
  status = iccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<3);
  status = iccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<2);
  status = iccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<1);
  status = iccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<0);
  return(status);
}

INT32 iccCHR08PackLSB_INT08( iccStackINT08_t *p, INT08 *c )
{
  INT08 temp;
  INT32 status;
  *c = 0;
  status = iccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<0);
  status = iccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<1);
  status = iccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<2);
  status = iccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<3);
  status = iccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<4);
  status = iccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<5);
  status = iccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<6);
  status = iccStackPopINT08  ( p, &temp );
  *c = *c | (temp<<7);
  return(status);
}
