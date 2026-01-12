/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccXXMLUtils.c                                                                         -
// Desc: This file contains the code for the xccXXMLUtils routine.                              -
// Hist: When       Who  What                                                                   -
//       07/27/2006 ptb  Initial Code.                                                          -
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include "xml_utils.h"
#include "malloc_utils.h"
#include "string_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG      TRUE
#define DEBUG_TYPE XMC_DEBUG_STDOUT
#define XMC_DEBUG  if( DEBUG ) DEBUG_TYPE

#define MAX_XML_MESSAGE_SIZE (1024*1024)

/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
//-----------------------------------------------------------------------------------------------
// Rout: xccXMLInit
// Desc: This routine opens up a XML file and reads it into a string buffer.
//-----------------------------------------------------------------------------------------------
xccXMLSpec_t * xccXMLInit(const CHR08 *fileName)
{

  FILE *fid;
  xccXMLSpec_t *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccXMLSpec_t *) xccMallocVOID_Align032(sizeof(xccXMLSpec_t));

  // Allocate memory for the XML message.
  //---------------------------------------------------------------------------------------------
  spec->xmlMessageBuffer  = (CHR08 *) xccMallocINT08_Align032( MAX_XML_MESSAGE_SIZE );
  spec->xmlMessageBuffer2 = (CHR08 *) xccMallocINT08_Align032( MAX_XML_MESSAGE_SIZE );

  // Open the file and read it.
  //---------------------------------------------------------------------------------------------
  fid = fopen((const char *)fileName,"r");         // Open the file.
  fseek(fid,0,SEEK_END);                           // Go to the end of the file.
  spec->nBytes = ftell(fid);                       // Determine the size of file in bytes.
  if(spec->nBytes > MAX_XML_MESSAGE_SIZE)          // Make sure message is not too big.
  {                                                //
    XMC_ERROR_STDOUT("XML message to big\n");      // If too big print error,
    fclose(fid);                                   // close file,
    exit(0);                                       // and exit.
  }                                                //
  else                                             // Other wise,
  {                                                //
    fseek(fid,0,SEEK_SET);                         // Go back to the begining
    fread(spec->xmlMessageBuffer, spec->nBytes, 1,fid); // and read the file.
  }

  // Close the file.
  //---------------------------------------------------------------------------------------------
  fclose(fid);

  return(spec);
}

//-----------------------------------------------------------------------------------------------
// Rout: xccXMLTerm
// Desc: This routine terminates the xccXMLSpec.
//-----------------------------------------------------------------------------------------------
VOID xccXMLTerm(xccXMLSpec_t *spec)
{
  xmcFree(spec->xmlMessageBuffer);
  xmcFree(spec->xmlMessageBuffer2);
  xmcFree(spec);
}

//-----------------------------------------------------------------------------------------------
// Rout: xccXMLGetContentFLT32
// Desc: This routine opens up a XML file and reads it into a string buffer.
//-----------------------------------------------------------------------------------------------
FLT32 xccXMLGetContentFLT32(const CHR08 *tagString, xccXMLSpec_t *spec)
{
  CHR08 *p;
  FLT32 valueFLT32=0.0;
  INT32 doneFlag=FALSE;

// Copy message to parsing buffer.
//-----------------------------------------------------------------------------------------------
  strncpy(spec->xmlMessageBuffer2, spec->xmlMessageBuffer, spec->nBytes);

// Token-ize.
//-----------------------------------------------------------------------------------------------
  p = strtok(spec->xmlMessageBuffer2," <>\n\r");   // Set up the token-izer.
  p = strtok('\0'," <>\n\r");                      // Get the first token.
  while((p != NULL) && !doneFlag)                  // Enter while loop.
  {                                                //
    xccStringUpper(p);                             // Make sure token is upper case
    //xccStringUpper(tagString);                   // Make sure tag is upper case
    if(!strncmp(p,tagString,strlen(tagString)))    // Is this the tag we are looking for?
    {                                              // If yes,
      p = strtok('\0'," <>\n\r");                  // the next token is the Content we want.
      sscanf(p,"%f",&valueFLT32);                  // Get the Content
      doneFlag = TRUE;                             // Set the done flag so we get out of here.
    }                                              //
    else                                           // Else
    {                                              //
      p = strtok('\0'," <>\n\r");                  // Read next token.
      doneFlag = FALSE;                            // Keep doneFlag false. (I know >:[ )
    }                                              //
  }
  return(valueFLT32);
}

//-----------------------------------------------------------------------------------------------
// Rout: xccXMLGetContentString
// Desc: This routine searches a XML spec for a certain content string.
//-----------------------------------------------------------------------------------------------
FLT32 xccXMLGetContentString(const CHR08 *tagString, CHR08 *contentString, xccXMLSpec_t *spec)
{
  CHR08 *p;
  FLT32 valueFLT32=0.0;
  INT32 doneFlag=FALSE;

// Copy message to parsing buffer.
//-----------------------------------------------------------------------------------------------
  strncpy(spec->xmlMessageBuffer2, spec->xmlMessageBuffer, spec->nBytes);

// Token-ize.
//-----------------------------------------------------------------------------------------------
  p = strtok(spec->xmlMessageBuffer2," <>\n\r");   // Set up the token-izer.
  p = strtok('\0'," <>\n\r");                      // Get the first token.
  while((p != NULL) && !doneFlag)                  // Enter while loop.
  {                                                //
    xccStringUpper(p);                             // Make sure token is upper case
    //xccStringUpper(tagString);                   // Make sure tag is upper case
    if(!strncmp(p,tagString,strlen(tagString)))    // Is this the tag we are looking for?
    {                                              // If yes,
      p = strtok('\0'," <>\n\r");                  // the next token is the Content we want.
      sscanf(p,"%s",contentString);                // Get the Content
      doneFlag = TRUE;                             // Set the done flag so we get out of here.
    }                                              //
    else                                           // Else
    {                                              //
      p = strtok('\0'," <>\n\r");                  // Read next token.
      doneFlag = FALSE;                            // Keep doneFlag false. (I know >:[ )
    }                                              //
  }
  return(valueFLT32);
}

//-----------------------------------------------------------------------------------------------
// Rout: xxmlReadFile
// Desc: This routine opens up a XML file and reads it into a string buffer.
//-----------------------------------------------------------------------------------------------
INT32 xxmlReadFile(const CHR08 *fileName, CHR08 **stringBuffer)
{

  FILE *fid;
  INT32 nBytes;

  // Allocate memory for the XML message.  Needs to be freed!
  //---------------------------------------------------------------------------------------------
  *stringBuffer = (CHR08 *) xccMallocINT08_Align032( 1024*1024 );

  // Open the file and read it.
  //---------------------------------------------------------------------------------------------
  fid = fopen((const char *)fileName,"r");         // Open the file based on filen name.
  fseek(fid,0,SEEK_END);                           // Go to the end of the file.
  nBytes = ftell(fid);                             // Determine the size of file in bytes.
  fseek(fid,0,SEEK_SET);                           // Go back to the begining
  fread(*stringBuffer, nBytes, 1,fid);             // and read the file.

  // Close the file.
  //---------------------------------------------------------------------------------------------
  fclose(fid);

  return(nBytes);
}


//-----------------------------------------------------------------------------------------------
// Rout: xxmlReadFile
// Desc: This routine opens up a XML file and reads it into a string buffer.
//-----------------------------------------------------------------------------------------------
FLT32 xxmlGetContentFLT32(const CHR08 *tagString, CHR08 *xmlMessageBuffer)
{
  CHR08 *p;
  FLT32 valueFLT32=0.0;
  INT32 doneFlag=FALSE;
  CHR08 *xmlMessageBuffer2;

  xmlMessageBuffer2 = (CHR08 *) xccMallocINT08_Align032( 1024*1024 );

  p = strtok(xmlMessageBuffer," <>\n\r");          // Set up the token-izer.
  p = strtok('\0'," <>\n\r");                      // Get the first token.
  while((p != NULL) && !doneFlag)                  // Enter while loop.
  {                                                //
    xccStringUpper(p);                             // Make sure token is upper case
    //xccStringUpper(tagString);                     // Make sure tag is upper case
    if(!strncmp(p,tagString,strlen(tagString)))    // Is this the tag we are looking for?
    {                                              // If yes,
      p = strtok('\0'," <>\n\r");                  // the next token is the Content we want.
      sscanf(p,"%f",&valueFLT32);                  // Get the Content
      doneFlag = TRUE;                             // Set the done flag so we get out of here.
    }                                              //
    else                                           // Else
    {                                              //
      p = strtok('\0'," <>\n\r");                  // Read next token.
      doneFlag = FALSE;                            // Keep doneFlag false. (I know >:[ )
    }                                              //
  }
  return(valueFLT32);
}

//-----------------------------------------------------------------------------------------------
// Rout: xxmlReadFile
// Desc: This routine opens up a XML file and reads it into a string buffer.
//-----------------------------------------------------------------------------------------------
VOID xxmlGetContentString(const CHR08 *tagString, CHR08 *contentString, CHR08 *xmlMessageBuffer)
{
  CHR08 *p;
  INT32 doneFlag=FALSE;

  p = strtok(xmlMessageBuffer," <>\n\r");          // Set up the token-izer.
  p = strtok('\0'," <>\n\r");                      // Get the first token.
  while((p != NULL) && !doneFlag)                  // Enter while loop.
  {                                                //
    xccStringUpper(p);                             // Make sure token is upper case
    //xccStringUpper(tagString);                   // Make sure tag is upper case
    if(!strncmp(p,tagString,strlen(tagString)))    // Is this the tag we are looking for?
    {                                              // If yes,
      p = strtok('\0'," <>\n\r");                  // the next token is the Content we want.
      sscanf(p,"%s",contentString);                   // Get the Content
      doneFlag = TRUE;                             // Set the done flag so we get out of here.
    }                                              //
    else                                           // Else
    {                                              //
      p = strtok('\0'," <>\n\r");                  // Read next token.
      doneFlag = FALSE;                            // Keep doneFlag false. (I know >:[ )
    }                                              //
  }
}


/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
 
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
