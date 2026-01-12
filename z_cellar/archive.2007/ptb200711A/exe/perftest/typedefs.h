/****************************************************************************
 *  typedefs.h
 *
 *  Description:  Simple type definitions to provide platform independence
 *  Author:	  RDH       
 *  Revisions:    
 *  --------      ---   -----------------------------------------------------
 *  01/27/00      rdh   baseline taken mostly from CLI and X-Midas cdefs.h
 *
 ***************************************************************************/

#ifndef _TYPEDEFS_H
#define _TYPEDEFS_H

#include <limits.h>         /* for data type ranges */
#include <stdlib.h>         /* for NULL */

/* 
 * ...Numeric representations 
 */
typedef signed   char   int_1;
typedef unsigned char   int_u1;
typedef short           int_2;
typedef unsigned short  int_u2;

#ifdef __alpha__
  typedef int             int_4;
  typedef unsigned int    int_u4;
  typedef long            int_8;
  typedef unsigned long   int_u8;
#else
  typedef long            int_4;
  typedef unsigned long   int_u4;
#endif 

typedef unsigned int    bool;
typedef int_u1          bool_1;
typedef int_u2          bool_2;
typedef int_u4          bool_4;
typedef float           real_4;
typedef double          real_8;
typedef struct {real_4 re; real_4 im;} cmplx_8;
typedef struct {real_8 re; real_8 im;} cmplx_16;

/*
 * ...Data Format Identifiers (mostly for reformat routines)
 */
#define DATATYPE_UNKNOWN    0 /* Unknown                             */

#define DATATYPE_CH_1B    101 /* Character, 1-byte                   */
#define DATATYPE_CH_2B    102 /* Character, 2-byte                   */

#define DATATYPE_I1_TC    201 /* Byte, 2's compliment                */
#define DATATYPE_I1_OB    202 /* Byte, offset binary                 */
#define DATATYPE_I1_UL    203 /* Byte, mu-law                        */
#define DATATYPE_I1_AL    204 /* Byte, A-law                         */
#define DATATYPE_I1_UM    205 /* Byte, unsigned magnitude            */
#define DATATYPE_CI1_TC   251 /* Complex Byte, 2's compliment        */
#define DATATYPE_CI1_OB   252 /* Complex Byte, offset binary         */
#define DATATYPE_CI1_UL   253 /* Complex Byte, mu-law                */
#define DATATYPE_CI1_AL   254 /* Complex Byte, A-law                 */
#define DATATYPE_CI1_UM   255 /* Complex Byte, unsigned magnitude    */

#define DATATYPE_I2_NA    301 /* Short (2-byte), native              */
#define DATATYPE_I2_VX    302 /* Short (2-byte), vax format          */
#define DATATYPE_I2_SN    303 /* Short (2-byte), sun format          */
#define DATATYPE_CI2_NA   351 /* Complex Short (2-byte), native      */
#define DATATYPE_CI2_VX   352 /* Complex Short (2-byte), vax format  */
#define DATATYPE_CI2_SN   353 /* Complex Short (2-byte), sun format  */

#define DATATYPE_I4_NA    401 /* Integer (4-byte) native             */
#define DATATYPE_I4_UM    402 /* Integer (4-byte), unsigned          */
#define DATATYPE_CI4_NA   451 /* Complex Integer (4-byte) native     */
#define DATATYPE_CI4_UM   452 /* Complex Integer (4-byte), unsigned  */

#define DATATYPE_I8_NA    501 /* Long int (8-byte), native           */
#define DATATYPE_I8_UM    502 /* Long int (8-byte), unsigned         */
#define DATATYPE_CI8_NA   551 /* Complex Long int (8-byte), native   */
#define DATATYPE_CI8_UM   552 /* Complex Long int (8-byte), unsigned */

#define DATATYPE_R4_NA    601 /* Float (4-byte), native              */
#define DATATYPE_R4_IE    602 /* Float (4-byte), IEEE                */
#define DATATYPE_R4_EI    603 /* Float (4-byte), EEEI                */
#define DATATYPE_R4_VX    604 /* Float (4-byte), VAX                 */
#define DATATYPE_CR4_NA   651 /* Complex Float (4-byte), native      */
#define DATATYPE_CR4_IE   652 /* Complex Float (4-byte), IEEE        */
#define DATATYPE_CR4_EI   653 /* Complex Float (4-byte), EEEI        */
#define DATATYPE_CR4_VX   654 /* Complex Float (4-byte), VAX         */

#define DATATYPE_R8_NA    701 /* Float (8-byte), native              */
#define DATATYPE_R8_IE    702 /* Float (8-byte), IEEE                */
#define DATATYPE_R8_EI    703 /* Float (8-byte), EEEI                */
#define DATATYPE_R8_VD    704 /* Float (8-byte), VAX-D               */
#define DATATYPE_R8_VG    705 /* Float (8-byte), VAX-G               */
#define DATATYPE_CR8_NA   751 /* Complex Float (8-byte), native      */
#define DATATYPE_CR8_IE   752 /* Complex Float (8-byte), IEEE        */
#define DATATYPE_CR8_EI   753 /* Complex Float (8-byte), EEEI        */
#define DATATYPE_CR8_VD   754 /* Complex Float (8-byte), VAX-D       */
#define DATATYPE_CR8_VG   755 /* Complex Float (8-byte), VAX-G       */

/* 
 * ...Constants 
 */
#ifndef FALSE
#  undef FALSE
#endif
#ifdef TRUE
#  undef TRUE
#endif
#define	FALSE	0
#define	TRUE 	1
#ifndef NULL 
#  define	NULL 	0
#endif

#define MAXINT_4	(int_4)INT_MAX
#define MININT_4	(int_4)INT_MIN
#define MAXINT_U4	(int_u4)UINT_MAX
#define MAXINT_2	(int_2)SHRT_MAX
#define MININT_2	(int_2)SHRT_MIN
#define MAXINT_U2	(int_u2)USHRT_MAX
#define MAX_BOUNDARY	sizeof(double)

/* 
 * ...Macro definitions 
 */
#ifndef MIN
#  define MIN(x,y)	(((x)<(y))? (x):(y))
#endif
#ifndef MAX
#  define MAX(x,y)	(((x)>(y))? (x):(y))
#endif

#define streq(s, t)	(strcmp(s, t) == 0)
#define strneq(s, t, n)	(strncmp(s, t, n) == 0)


#endif /* _TYPEDEFS_H */
