/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xmlTest.c
// Desc: This program tests handling an XML file.
// Hist: When       Who  What
//       07/20/2004 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "iccswd.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "/usr/include/libxml2/libxml/xmlmemory.h"
#include "/usr/include/libxml2/libxml/parser.h"

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define BLOCK_SIZE 2048
#define XMLTEST_FUNC_DESC						             \
"********************************************************************************\n" \
"                                                                                \n" \
"This program tests handling an XML file.                                        \n" \
"                                                                                \n" \
"Input : is from stdin.                                                          \n" \
"                                                                                \n" \
"Output: is to stdout.                                                           \n" \
"                                                                                \n" \
"Input parameters are:                                                           \n" \
"  None.                                                                         \n" \
"                                                                                \n" \
"                                                                                \n" \
"********************************************************************************\n" \
"\n"

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
// Convert a string to upper case.
//------------------------------------------------------------------------------

/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
int main(int argc, char **argv)
{
  INT32 ii;
  INT08 useNext=0;
  INT32 count=0;
  INT32 amountRead;
  INT08 iDataINT08[BLOCK_SIZE];

  xmlChar    *whogi;
  xmlDocPtr  doc;
  xmlNodePtr cur;
  xmlNodePtr tempNode;

  // Handle input parameters.
  //----------------------------------------------------------------------------
  for(ii = 0; ii<argc; ii++)
  {
    if( (!strncmp( argv[ii], "-h",     2)) || 
	(!strncmp( argv[ii], "--help", 6))   )
    {
      fprintf(stderr, XMLTEST_FUNC_DESC);
      exit(0);
    }

  }

  // Read in the data.
  //------------------------------------------------------------------------------
  amountRead = fread(iDataINT08, sizeof(iDataINT08[0]), BLOCK_SIZE, stdin);

  //doc = xmlParseFile(docname);

  doc = xmlParseMemory(iDataINT08, amountRead);

  cur = xmlDocGetRootElement(doc);

  while( (cur->parent != NULL) && (cur != NULL) )
  {
    if( !strcmp(cur->name,"LAT") )
    {
      FLT32 latFLT32;
      CHR08 tempString[256];
      tempNode = cur->children;
      printf("FOUND LAT %s\n", tempNode->content);
      sprintf(tempString,"  %s  ",tempNode->content);
      sscanf(tempString,"%f",&latFLT32);
      printf("Convert to FLT32 %f\n",latFLT32);
    }

    if( ( cur->children != NULL) && (useNext==0) )
    {
      cur = cur->children;
      useNext=0;
      printf("cur->name is %s\n",cur->name);
    }
    else if ( ( cur->next != NULL) && (useNext==1) )
    {
      cur = cur->next;
      useNext=0;
      printf("cur->name is %s\n",cur->name);
    }
    else
    {
      cur = cur->parent;
      useNext=1;
      printf("cur->name is %s\n",cur->name);
    }
  }


  xmlFreeDoc(doc);

  return(0);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/

#if 0

<?xml version="1.0" encoding="UTF-8"?>
<MESSAGE>
<HEADER>
<SOURCE>TBL1</SOURCE>
<DESTINATION>PSG</DESTINATION>
<MESSAGE_ID>0000000008</MESSAGE_ID>
<MESSAGE_TYPE>SNAPSHOT_REQUEST</MESSAGE_TYPE>
</HEADER>
<BODY>
<ACTION>EDS-PUSH-DELETE</ACTION>
<CONFIRMATION>NO</CONFIRMATION>
<ACKNAK>NO</ACKNAK>
<ANNOTATION>SHOULD FTP ALL 30 ELEMENTS + CD + SV DATA </ANNOTATION>
<INCLUDE_ELEMENT>ALL</INCLUDE_ELEMENT>
<START_TIME>2006-05-03T14:21:14Z</START_TIME>
<DURATION>60</DURATION>
<PARAMETERS>
<MODE>0</MODE>
<ELEMENT>3FFFFFFF</ELEMENT>
<CENTERFREQ>2284.400000</CENTERFREQ>
<PNCODE>101</PNCODE>
<LAT>76.9</LAT>
<LON>-101.2</LON>
<ALT>1000</ALT>
<MULTICAST_IP>239.200.1.213</MULTICAST_IP>
<SELF_TEST_DELAY></SELF_TEST_DELAY>
<SELF_TEST_SOURCE></SELF_TEST_SOURCE>
<MRU_OUTPUT>MBU</MRU_OUTPUT>
<MRU_INPUT>MBU</MRU_INPUT>
</PARAMETERS>
<BLOCK_ID>01</BLOCK_ID>
<CONFIG_ID>000008</CONFIG_ID>
</BODY>
</MESSAGE>

xmlNodeListGetString

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "/usr/include/libxml2/libxml/xmlmemory.h"
#include "/usr/include/libxml2/libxml/parser.h"



int main(int argc, char *argv[])
{
  xmlChar    *whogi;
  xmlDocPtr  doc;
  xmlNodePtr cur;
  char       xmlString[1024];

  //sprintf(xmlString,"<?xml version=/"1.0/"?><headline>This is the headline.</headline>");
  sprintf(xmlString,"\x3C?xml version=\"1.0\"?\x3E \x3Cheadline\x3EThis is the headline.\x3C/headline\x3E");

  doc = xmlParseMemory(xmlString,strlen(xmlString)-1);

  cur = xmlDocGetRootElement(doc);

  //whogi = xmlGetProp(cur,"headline");

  //printf("%s\n",whogi);

  xmlFreeDoc(doc);

  return(0);

}

xmlChar *uri;
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
	    if ((!xmlStrcmp(cur->name, (const xmlChar *)"reference"))) {
		   1 uri = xmlGetProp(cur, "uri");
		    printf("uri: %s\n", uri);
		    xmlFree(uri);

#endif



