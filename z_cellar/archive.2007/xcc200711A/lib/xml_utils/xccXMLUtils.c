/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccXMLUtils.c                                                                          -
// Desc: This file contains the code for the xccXMLUtils routine.                               -
// Hist: When       Who  What                                                                   -
//       05/06/2006 ptb  Initial Code.                                                          -
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include "xml_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG      TRUE
#define DEBUG_TYPE XMC_DEBUG_STDOUT
#define XMC_DEBUG  if( DEBUG ) DEBUG_TYPE

/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
  //if ((!xmlStrcmp(cur->name, (const xmlChar *)"reference"))) {

  //uri = xmlGetProp(cur, "uri");
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  INT08 done=0;
PERL_PREPROCESS  INT32 useNext=0;
PERL_PREPROCESS  XXXXX value;
PERL_PREPROCESS  xmlNodePtr xmlCur;
PERL_PREPROCESS  xmlNodePtr tempNode;
PERL_PREPROCESS
PERL_PREPROCESS  xmlCur = xmlDocGetRootElement(xmlDoc);
PERL_PREPROCESS
PERL_PREPROCESS  while( (xmlCur->parent != NULL) && (xmlCur != NULL) && !done ) 
PERL_PREPROCESS  {
PERL_PREPROCESS    if( !strcmp((char *)xmlCur->name,tagString) )           // If we found what we are looking
PERL_PREPROCESS    {                                                       // for then
PERL_PREPROCESS      tempNode = xmlCur->children;                          //
PERL_PREPROCESS      sscanf((char *)tempNode->content,"%YYYYY",&value);       // get it and say we are
PERL_PREPROCESS      done=1;                                               // done.
PERL_PREPROCESS    }
PERL_PREPROCESS
PERL_PREPROCESS    if      ( ( xmlCur->children != NULL) && (useNext==0) ) // Search through all the nodes of 
PERL_PREPROCESS    {                                                       // this xml document.
PERL_PREPROCESS      xmlCur = xmlCur->children;                            //
PERL_PREPROCESS      useNext=0;                                            //
PERL_PREPROCESS      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
PERL_PREPROCESS    }                                                       //
PERL_PREPROCESS    else if ( ( xmlCur->next != NULL) && (useNext==1) )     //
PERL_PREPROCESS    {                                                       //
PERL_PREPROCESS      xmlCur = xmlCur->next;                                //
PERL_PREPROCESS      useNext=0;                                            //
PERL_PREPROCESS      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
PERL_PREPROCESS    }                                                       //
PERL_PREPROCESS    else                                                    //
PERL_PREPROCESS    {                                                       //
PERL_PREPROCESS      xmlCur = xmlCur->parent;                              //
PERL_PREPROCESS      useNext=1;                                            //
PERL_PREPROCESS      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
PERL_PREPROCESS    }                                                       //
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  return(value);
#endif

//-----------------------------------------------------------------------------------------------
// Rout: xmlGetContent
// Desc: This routine retreives XML content.
//-----------------------------------------------------------------------------------------------
FLT32 xmlGetContentFLT32(const CHR08 *tagString,  xmlDocPtr xmlDoc)
{
//------------------------------- COMMON-CODE FLT32 f START.
  INT08 done=0;
  INT32 useNext=0;
  FLT32 value;
  xmlNodePtr xmlCur;
  xmlNodePtr tempNode;

  xmlCur = xmlDocGetRootElement(xmlDoc);

  while( (xmlCur->parent != NULL) && (xmlCur != NULL) && !done ) 
  {
    if( !strcmp((char *)xmlCur->name,tagString) )           // If we found what we are looking
    {                                                       // for then
      tempNode = xmlCur->children;                          //
      sscanf((char *)tempNode->content,"%f",&value);        // get it and say we are
      done=1;                                               // done.
    }

    if      ( ( xmlCur->children != NULL) && (useNext==0) ) // Search through all the nodes of 
    {                                                       // this xml document.
      xmlCur = xmlCur->children;                            //
      useNext=0;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
    else if ( ( xmlCur->next != NULL) && (useNext==1) )     //
    {                                                       //
      xmlCur = xmlCur->next;                                //
      useNext=0;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
    else                                                    //
    {                                                       //
      xmlCur = xmlCur->parent;                              //
      useNext=1;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
  }

  return(value);
//------------------------------- COMMON-CODE FLT32 f  STOP.
}

FLT64 xmlGetContentFLT64(const CHR08 *tagString,  xmlDocPtr xmlDoc)
{
//------------------------------- COMMON-CODE FLT64 lf START.
  INT08 done=0;
  INT32 useNext=0;
  FLT64 value;
  xmlNodePtr xmlCur;
  xmlNodePtr tempNode;

  xmlCur = xmlDocGetRootElement(xmlDoc);

  while( (xmlCur->parent != NULL) && (xmlCur != NULL) && !done ) 
  {
    if( !strcmp((char *)xmlCur->name,tagString) )           // If we found what we are looking
    {                                                       // for then
      tempNode = xmlCur->children;                          //
      sscanf((char *)tempNode->content,"%lf",&value);       // get it and say we are
      done=1;                                               // done.
    }

    if      ( ( xmlCur->children != NULL) && (useNext==0) ) // Search through all the nodes of 
    {                                                       // this xml document.
      xmlCur = xmlCur->children;                            //
      useNext=0;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
    else if ( ( xmlCur->next != NULL) && (useNext==1) )     //
    {                                                       //
      xmlCur = xmlCur->next;                                //
      useNext=0;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
    else                                                    //
    {                                                       //
      xmlCur = xmlCur->parent;                              //
      useNext=1;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
  }

  return(value);
//------------------------------- COMMON-CODE FLT64 lf  STOP.
}

FLT96 xmlGetContentFLT96(const CHR08 *tagString,  xmlDocPtr xmlDoc)
{
//------------------------------- COMMON-CODE FLT96 Lf START.
  INT08 done=0;
  INT32 useNext=0;
  FLT96 value;
  xmlNodePtr xmlCur;
  xmlNodePtr tempNode;

  xmlCur = xmlDocGetRootElement(xmlDoc);

  while( (xmlCur->parent != NULL) && (xmlCur != NULL) && !done ) 
  {
    if( !strcmp((char *)xmlCur->name,tagString) )           // If we found what we are looking
    {                                                       // for then
      tempNode = xmlCur->children;                          //
      sscanf((char *)tempNode->content,"%Lf",&value);       // get it and say we are
      done=1;                                               // done.
    }

    if      ( ( xmlCur->children != NULL) && (useNext==0) ) // Search through all the nodes of 
    {                                                       // this xml document.
      xmlCur = xmlCur->children;                            //
      useNext=0;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
    else if ( ( xmlCur->next != NULL) && (useNext==1) )     //
    {                                                       //
      xmlCur = xmlCur->next;                                //
      useNext=0;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
    else                                                    //
    {                                                       //
      xmlCur = xmlCur->parent;                              //
      useNext=1;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
  }

  return(value);
//------------------------------- COMMON-CODE FLT96 Lf  STOP.
}

INT08 xmlGetContentINT08(const CHR08 *tagString,  xmlDocPtr xmlDoc)
{
//------------------------------- COMMON-CODE INT08 d START.
  INT08 done=0;
  INT32 useNext=0;
  INT08 value;
  xmlNodePtr xmlCur;
  xmlNodePtr tempNode;

  xmlCur = xmlDocGetRootElement(xmlDoc);

  while( (xmlCur->parent != NULL) && (xmlCur != NULL) && !done ) 
  {
    if( !strcmp((char *)xmlCur->name,tagString) )           // If we found what we are looking
    {                                                       // for then
      tempNode = xmlCur->children;                          //
      sscanf((char *)tempNode->content,"%d",&value);       // get it and say we are
      done=1;                                               // done.
    }

    if      ( ( xmlCur->children != NULL) && (useNext==0) ) // Search through all the nodes of 
    {                                                       // this xml document.
      xmlCur = xmlCur->children;                            //
      useNext=0;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
    else if ( ( xmlCur->next != NULL) && (useNext==1) )     //
    {                                                       //
      xmlCur = xmlCur->next;                                //
      useNext=0;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
    else                                                    //
    {                                                       //
      xmlCur = xmlCur->parent;                              //
      useNext=1;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
  }

  return(value);
//------------------------------- COMMON-CODE INT08 d  STOP.
}

INT16 xmlGetContentINT16(const CHR08 *tagString,  xmlDocPtr xmlDoc)
{
//------------------------------- COMMON-CODE INT16 d START.
  INT08 done=0;
  INT32 useNext=0;
  INT16 value;
  xmlNodePtr xmlCur;
  xmlNodePtr tempNode;

  xmlCur = xmlDocGetRootElement(xmlDoc);

  while( (xmlCur->parent != NULL) && (xmlCur != NULL) && !done ) 
  {
    if( !strcmp((char *)xmlCur->name,tagString) )           // If we found what we are looking
    {                                                       // for then
      tempNode = xmlCur->children;                          //
      sscanf((char *)tempNode->content,"%d",&value);        // get it and say we are
      done=1;                                               // done.
    }

    if      ( ( xmlCur->children != NULL) && (useNext==0) ) // Search through all the nodes of 
    {                                                       // this xml document.
      xmlCur = xmlCur->children;                            //
      useNext=0;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
    else if ( ( xmlCur->next != NULL) && (useNext==1) )     //
    {                                                       //
      xmlCur = xmlCur->next;                                //
      useNext=0;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
    else                                                    //
    {                                                       //
      xmlCur = xmlCur->parent;                              //
      useNext=1;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
  }

  return(value);
//------------------------------- COMMON-CODE INT16 d  STOP.
}

INT32 xmlGetContentINT32(const CHR08 *tagString,  xmlDocPtr xmlDoc)
{
//------------------------------- COMMON-CODE INT32 ld START.
  INT08 done=0;
  INT32 useNext=0;
  INT32 value;
  xmlNodePtr xmlCur;
  xmlNodePtr tempNode;

  xmlCur = xmlDocGetRootElement(xmlDoc);

  while( (xmlCur->parent != NULL) && (xmlCur != NULL) && !done ) 
  {
    if( !strcmp((char *)xmlCur->name,tagString) )           // If we found what we are looking
    {                                                       // for then
      tempNode = xmlCur->children;                          //
      sscanf((char *)tempNode->content,"%ld",&value);       // get it and say we are
      done=1;                                               // done.
    }

    if      ( ( xmlCur->children != NULL) && (useNext==0) ) // Search through all the nodes of 
    {                                                       // this xml document.
      xmlCur = xmlCur->children;                            //
      useNext=0;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
    else if ( ( xmlCur->next != NULL) && (useNext==1) )     //
    {                                                       //
      xmlCur = xmlCur->next;                                //
      useNext=0;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
    else                                                    //
    {                                                       //
      xmlCur = xmlCur->parent;                              //
      useNext=1;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
  }

  return(value);
//------------------------------- COMMON-CODE INT32 ld  STOP.
}

INT64 xmlGetContentINT64(const CHR08 *tagString,  xmlDocPtr xmlDoc)
{
//------------------------------- COMMON-CODE INT64 lld START.
  INT08 done=0;
  INT32 useNext=0;
  INT64 value;
  xmlNodePtr xmlCur;
  xmlNodePtr tempNode;

  xmlCur = xmlDocGetRootElement(xmlDoc);

  while( (xmlCur->parent != NULL) && (xmlCur != NULL) && !done ) 
  {
    if( !strcmp((char *)xmlCur->name,tagString) )           // If we found what we are looking
    {                                                       // for then
      tempNode = xmlCur->children;                          //
      sscanf((char *)tempNode->content,"%lld",&value);       // get it and say we are
      done=1;                                               // done.
    }

    if      ( ( xmlCur->children != NULL) && (useNext==0) ) // Search through all the nodes of 
    {                                                       // this xml document.
      xmlCur = xmlCur->children;                            //
      useNext=0;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
    else if ( ( xmlCur->next != NULL) && (useNext==1) )     //
    {                                                       //
      xmlCur = xmlCur->next;                                //
      useNext=0;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
    else                                                    //
    {                                                       //
      xmlCur = xmlCur->parent;                              //
      useNext=1;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
  }

  return(value);
//------------------------------- COMMON-CODE INT64 lld  STOP.
}

//-----------------------------------------------------------------------------------------------
// Rout: xmlGetContentString
// Desc: This routine retreives XML string content.
//-----------------------------------------------------------------------------------------------
VOID xmlGetContentString(const CHR08 *tagString, CHR08 *retString, xmlDocPtr xmlDoc)
{
  INT08 done=0;
  INT32 useNext=0;
  xmlNodePtr xmlCur;
  xmlNodePtr tempNode;

  xmlCur = xmlDocGetRootElement(xmlDoc);

  while( (xmlCur->parent != NULL) && (xmlCur != NULL) && !done ) 
  {
    if( !strcmp((char *)xmlCur->name,tagString) )           // If we found what we are looking
    {                                                       // for then
      tempNode = xmlCur->children;                          //
      sscanf((char *)tempNode->content,"%s",retString);     // get it and say we are
      done=1;                                               // done.
    }

    if      ( ( xmlCur->children != NULL) && (useNext==0) ) // Search through all the nodes of 
    {                                                       // this xml document.
      xmlCur = xmlCur->children;                            //
      useNext=0;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
    else if ( ( xmlCur->next != NULL) && (useNext==1) )     //
    {                                                       //
      xmlCur = xmlCur->next;                                //
      useNext=0;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
    else                                                    //
    {                                                       //
      xmlCur = xmlCur->parent;                              //
      useNext=1;                                            //
      XMC_DEBUG("xmlCur->name is %s\n",xmlCur->name);       //
    }                                                       //
  }
}


/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
 
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
