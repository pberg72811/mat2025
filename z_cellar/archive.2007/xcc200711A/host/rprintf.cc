/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: rprintf.cc                                                                             -
//                                                                                              -
// Desc: This primitive will take a result name, a format string, and args                      -
//       to produce a results string.                                                           -
//                                                                                              -
// Args: resLabel      - Results label.  <A:>                                                   -
//       formatString  - format string.  <A:>                                                   -
//       arg1          - argument 1.     <X:>                                                   -
//                                                                                              -
// Swch: None                                                                                   -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       06/09/2006 ptb  Initial Code.                                                          -
//                                                                                              -
//                            resLabel                                                          -
//                            formatString                                                      -
//                            arg1                                                              -
//                            arg2                                                              -
//                            arg3                                                              -
//                               |                                                              -
//                               V                                                              -
//                         :-------------:    :--------:                                        -
//                         | rprintf.cc  |--->| RESULT |                                        -
//                         :-------------:    :--------:                                        -
//                               |                                                              -
//                               V                                                              -
//                        Debug Statements                                                      -
//                                                                                              -
// Note:                                                                                        -
//                                                                                              -
// Examples:                                                                                    -
//                                                                                              -
//01.0 Description                                                                              -
//02.0 Requirements                                                                             -
//03.0 Interfaces                                                                               -
//04.0 Design Description                                                                       -
//05.0 Unit Code                                                                                -
//06.0 Unit Test Plan                                                                           -
//07.0 Test Results                                                                             -
//08.0 Build Procedures                                                                         -
//09.0 Notes                                                                                    -
//10.0 Reviewers.                                                                               -
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include "primitive.h"
#include "xmc.h"
#include "stack_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG      TRUE
#define DEBUG_HOST  "192.9.214.113"
#define DEBUG_PORT  5001
#define DEBUG_TYPE  XMC_DEBUG_STDOUT
//#define DEBUG_TYPE DEBUG_STDOUT_FILE
#define XMC_DEBUG  if( DEBUG ) DEBUG_TYPE

/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
VOID mainroutine()
{
  INT32 ii;
  INT32 argDex;
  string tempString1;
  string tempString2;
  string tempString3;
  INT32 argINT32;
  FLT64 argFLT64;
  CHR08 resultString[128];
  CHR08 formatString[128];
  CHR08 label_String[128];
  CHR08 subFormat[32];
  CHR08 ts[32];
  CHR08 *p;
  INT08 continuousFlag;
  INT32 continuousTime;

  // Switch variables.

  // File name variables.

  // Get command line arguments.
  //----------------------------------------------------------------------------
  tempString1 = m_apick(1);
  tempString2 = m_apick(2);

  // Get the CONT switch if present.
  //---------------------------------------------------------------------------------------------
  if( m_get_pswitch("CONT") )                                 // If there is a CONT switch.     -
  {                                                           //                                -
    continuousFlag = TRUE;                                    // Set the CONT flag.             -
    continuousTime = m_get_dswitch("CONT");                   // Get duration of CONT.          -
    if(continuousTime<1)continuousTime=1;                     //                                -
    XMC_DEBUG("Setting continuousFlag.\n");                   //                                -
  }                                                           //                                -
  else                                                        // If no CONT switch.             -
  {                                                           //                                -
    continuousFlag = FALSE;                                   // Clear CONT flag.               -
    XMC_DEBUG("Clearing continuousFlag.\n");                  //                                -
  }                                                           //---------------------------------

  // Prepare strings.
  //----------------------------------------------------------------------------
  sprintf(resultString, "%s", tempString1.c_str());
  sprintf(formatString, "%s", tempString2.c_str());
  sprintf(label_String, "%s", "\0NOTHING");
  sprintf(subFormat,    "%s", "\0NOTHING");

  XMC_DEBUG("rprintf:  resultString  is %s\n", resultString);
  XMC_DEBUG("rprintf:  formatString  is %s\n", formatString);

  // 
  //----------------------------------------------------------------------------
  p = strtok(formatString,"%");
  sprintf(label_String, "%s", p);
  argDex = 3;
  while( (p = strtok('\0'," %")) != NULL )
  {
    for(ii=0; ii<(INT32)strlen(p); ii++)
    {
      //printf("%c\n",p[ii]);
      if(p[ii] == 'S' || p[ii] == 's')
      {
	sprintf(subFormat,"%%%s",p);
	tempString1 = m_apick(argDex);
        sprintf(ts,subFormat,tempString1.c_str());
        strncat(label_String, ts, strlen(ts));
	argDex++;
      }
      else if(p[ii] == 'D' || p[ii] == 'd')
      {
	sprintf(subFormat,"%%%s",p);
	argINT32 = m_lpick(argDex);
        sprintf(ts,subFormat,argINT32);
        strncat(label_String, ts, strlen(ts));
	argDex++;
      }
      else if(p[ii] == 'F' || p[ii] == 'f')
      {
	sprintf(subFormat,"%%%s",p);
	argFLT64 = m_dpick(argDex);
        sprintf(ts,subFormat,tempString1.c_str());
        strncat(label_String, ts, strlen(ts));
	argDex++;
      }
	
    }
    //printf("+++++++\n");
  }

  // "Synchronize" not "sink".
  //---------------------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG("Calling m_sync();\n");

  // If continuous mode then send the message continually.
  //---------------------------------------------------------------------------------------------
  if(continuousFlag)
  {
    m_arslt(resultString, label_String);

    while(!Mc->break_)
    {
      XMC_DEBUG("%s\n",label_String);
      sleep(continuousTime);
    }
  }

  // Else send the message once.
  //---------------------------------------------------------------------------------------------
  else
  {
    m_arslt(resultString, label_String);
    XMC_DEBUG("%s\n",label_String);
  }

  // Get command line arguments.
  //----------------------------------------------------------------------------
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
