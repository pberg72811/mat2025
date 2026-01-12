/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xml_utils.h
// Desc: This is the header file for xml_utils.
// Hist: When       Who  What
//       05/06/2006 ptb  Initial Code.
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#ifndef XML_UTILS_H
#define XML_UTILS_H
 
#ifdef __cplusplus 
extern "C" { 
#endif 
 
/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include "xmc.h"
#include "libxml/xmlmemory.h"
#include "libxml/parser.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
typedef struct
{
  INT32 nBytes;
  CHR08 *xmlMessageBuffer;
  CHR08 *xmlMessageBuffer2;
} iccXMLSpec_t;

/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
FLT32 xmlGetContentFLT32(const CHR08 *tagString,  xmlDocPtr xmlDoc);
FLT64 xmlGetContentFLT64(const CHR08 *tagString,  xmlDocPtr xmlDoc);
FLT96 xmlGetContentFLT96(const CHR08 *tagString,  xmlDocPtr xmlDoc);
INT08 xmlGetContentINT08(const CHR08 *tagString,  xmlDocPtr xmlDoc);
INT16 xmlGetContentINT16(const CHR08 *tagString,  xmlDocPtr xmlDoc);
INT32 xmlGetContentINT32(const CHR08 *tagString,  xmlDocPtr xmlDoc);
INT64 xmlGetContentINT64(const CHR08 *tagString,  xmlDocPtr xmlDoc);
VOID  xmlGetContentString(const CHR08 *tagString, CHR08 *retString, xmlDocPtr xmlDoc);


INT32 xxmlReadFile(const CHR08 *fileName, CHR08 **stringBuffer);
FLT32 xxmlGetContentFLT32(const CHR08 *tagString, CHR08 *xmlMessageBuffer);
VOID  xxmlGetContentString(const CHR08 *tagString, CHR08 *contentString, CHR08 *xmlMessageBuffer);


iccXMLSpec_t *iccXMLInit(const CHR08 *fileName);
VOID iccXMLTerm(iccXMLSpec_t *spec);
FLT32 iccXMLGetContentFLT32(const CHR08 *tagString, iccXMLSpec_t *spec);
FLT32 iccXMLGetContentString(const CHR08 *tagString, CHR08 *contentString, iccXMLSpec_t *spec);


/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#ifdef __cplusplus
} 
#endif
 
#endif
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
