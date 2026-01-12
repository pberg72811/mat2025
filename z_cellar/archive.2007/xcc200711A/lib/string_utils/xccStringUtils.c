/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccStringUtils.c
// Desc: This file contains the code for the xccArrayInit routine.
// Hist: When       Who  What
//       06/30/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "string_utils.h"

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

VOID xccStringUpper( CHR08 *string )
{
  INT32 ii;
  INT32 len;
  len = strlen(string);
  for(ii=0; ii<len; ii++)
  {
    string[ii] = toupper(string[ii]);
  }
}

VOID xccStringLower( CHR08 *string )
{
  INT32 ii;
  INT32 len;
  len = strlen(string);
  for(ii=0; ii<len; ii++)
  {
    string[ii] = tolower(string[ii]);
  }
}

VOID xccStringInit( CHR08 *string, INT32 length )
{
  INT32 ii;
  for(ii=0;ii<(length-1);ii++) string[ii]='S';
  string[length-1] = '\0';
  return;
}

INT32 xccStringNotEqual(const char *str1, const char *str2, INT32 n)
{
  if( strncmp( str1, str2, n ) != 0 ) return(TRUE );
  else                                return(FALSE);
}

INT32 xccStringEqual(const char *str1, const char *str2, INT32 n)
{
  if( strncmp( str1, str2, n ) == 0 ) return(TRUE );
  else                                return(FALSE);
}

INT32 xccStringsANumber(CHR08 *string)
{
  INT32 x=0;
  INT32 ii=0;
  INT32 l=strlen(string);
  
  for(ii=0; ii<l; ii++)
  {
    x += (isdigit(string[ii]) > 0);
  }
  if(x==l) return(1);
  else     return(0);
}

INT32 xccStringsAHexNumber(CHR08 *string)
{
  INT32 x=0;
  INT32 ii=0;
  INT32 l=strlen(string);
  
  for(ii=0; ii<l; ii++)
  {
    x += isxdigit(string[ii]);
  }
  if(x==l) return(1);
  else     return(0);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
 
/*-------------------------------UNCLASSIFIED---------------------------------*/
