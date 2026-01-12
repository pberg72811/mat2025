/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccawgnoise.cc                                                                         -
// Desc: This primitive generates uniform or gaussian noise.                                    -
// Args: oFileName   - The name of the output file.       <A:>                                  -
//       oDataType   - Data type of the output file.      <A:>                                  -
//       nSamples    - Number of samples to generate.     <L:>                                  -
//       std         - Standard deviation of noise.       <D:>                                  -
//       fs          - Sample rate.                       <D:>                                  -
// Swch: /SEED       - Starting seed to use for noise.                                          -
//       /UNIFORM    - Generate uniform noise not guassian.                                     -
//       /CONTINUOUS - Keep generating data until Mc->break_ (CTL-C)                            -
// Hist: When       Who  What                                                                   -
//       04/29/2004 ptb  Initial Code.                                                          -
//                                                                                              -
//           oFileName                                                                          -
//           oDataType                                                                          -
//           nSamples                                                                           -
//           std                                                                                -
//           fs                                                                                 -
//          /SEED                                                                               -
//          /UNIFORM                                                                            -
//          /CONTINUOUS                                                                         -
//            |                                                                                 -
//            V                                                                                 -
//    :----------------:     :-----------:                                                      -
//    | xccawnoise.cc  |---> | file/pipe |                                                      -
//    :----------------:     :-----------:                                                      -
//            |                                                                                 -
//            V                                                                                 -
//      Debug Statements                                                                        -
// Note:                                                                                        -
//                                                                                              -
// Examples:                                                                                    -
// pipe on                                                                                      -
// xccawgnoise/continuous _stream(ps=32M) si 10e6 3000 8.5e6                                    -
// xccarchive _stream awgtest 1024*1024*1024 /data11/steswd/ 10                                 -
// pipe off                                                                                     -
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
#include "malloc_utils.h"
#include "orbit_utils.h"
#include "vector_utils.h"

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
  //INT32 ii;
  FLT32 fs;
  int_4 nDo;
  FLT32 std;
  //INT32 status;
  //UNT32 index;
  UNT32 nSamples;
  //UNT32 nBufferSize;
  UNT32 xferLngth;
  UNT32 xferSamps;
  INT08 *oDataINT08;
  //INT08 *nBufferINT08;
  INT32 uniformFlag=0;
  INT32 complexFlag=0;
  INT32 continuousFlag=0;

  // generic function pointers.
  VOID (*generic_noise) (UNT64 *seed, FLT32 amp, VOID *a, INT32 i, UNT32 n );

  // Switch variables.
  UNT64 seedUNT64=999888765797ULL;

  // File name variables.
  string oFileName;
  string oDataType;

  // Get command line parameters.
  //---------------------------------------------------------------------------------------------
  oFileName   = m_apick(1);
  oDataType   = m_apick(2);
  nSamples    = (UNT32)m_dpick(3);
  std         = m_dpick(4);
  fs          = m_dpick(5);
  XMC_DEBUG("oFileName   is %s\n",  oFileName.c_str());
  XMC_DEBUG("oDataType   is %s\n",  oDataType.c_str());
  XMC_DEBUG("nSamples    is %ld\n", nSamples);
  XMC_DEBUG("std/amp     is %f\n",  std);
  XMC_DEBUG("fs          is %f\n",  fs);

  // Check for "seed" switches.
  //---------------------------------------------------------------------------------------------
  if(m_get_pswitch("SEED")) 
  {
    seedUNT64 = (UNT64) m_get_dswitch("SEED");
  }
  else seedUNT64=999888765797ULL;
  XMC_DEBUG("seedUNT64   is %lld\n", seedUNT64);

  // Check for "uniform" switches.
  //---------------------------------------------------------------------------------------------
  if( m_get_pswitch("UNIFORM") )
  {
    uniformFlag = 1;
  }
  else uniformFlag = 0;
  XMC_DEBUG("uniformFlag is %ld\n", uniformFlag);

  // Check for "continuous" switch.
  //---------------------------------------------------------------------------------------------
  if( m_get_pswitch("CONTINUOUS") )
  {
    continuousFlag = 1;
  }
  else continuousFlag = 0;
  XMC_DEBUG("continuousFlag is %ld\n", continuousFlag);

  // Set up the output file header.
  //---------------------------------------------------------------------------------------------
  CPHEADER oHeader;
  m_initialize(oHeader);
  oHeader.file_name = oFileName;
  oHeader.type      = 1000;
  oHeader.format    = oDataType;
  oHeader.size      = nSamples;
  oHeader.xstart    = 0;
  oHeader.xdelta    = 1/fs;
  oHeader.xunits    = 1;
  oHeader.timecode  = xccCurrentJ1950Seconds();
  m_allocate(oHeader);

  // Set up based on output data type.
  //---------------------------------------------------------------------------------------------
  if     ( oHeader.format == "SB" ) {
    complexFlag   = 1;
    if(uniformFlag) generic_noise = xccvRandINT08;
    else            generic_noise = xccvRandNINT08;
  }
  else if( oHeader.format == "SI" ) {
    complexFlag   = 1;
    if(uniformFlag) generic_noise = xccvRandINT16;
    else            generic_noise = xccvRandNINT16;
  }
  else if( oHeader.format == "SL" ) {
    complexFlag   = 1;
    if(uniformFlag) generic_noise = xccvRandINT32;
    else            generic_noise = xccvRandNINT32;
  }
  else if( oHeader.format == "SF" ) {
    complexFlag   = 1;
    if(uniformFlag) generic_noise = xccvRandFLT32;
    else            generic_noise = xccvRandNFLT32;
  }
  else if( oHeader.format == "SD" ) {
    complexFlag   = 1;
    if(uniformFlag) generic_noise = xccvRandFLT64;
    else            generic_noise = xccvRandNFLT64;
  }
  else if( oHeader.format == "CB" ) {
    complexFlag   = 2;
    if(uniformFlag) generic_noise = xccvRandINT08;
    else            generic_noise = xccvRandNINT08;
  }
  else if( oHeader.format == "CI" ) {
    complexFlag   = 2;
    if(uniformFlag) generic_noise = xccvRandINT16;
    else            generic_noise = xccvRandNINT16;
  }
  else if( oHeader.format == "CL" ) {
    complexFlag   = 2;
    if(uniformFlag) generic_noise = xccvRandINT32;
    else            generic_noise = xccvRandNINT32;
  }
  else if( oHeader.format == "CF" ) {
    complexFlag   = 2;
    if(uniformFlag) generic_noise = xccvRandFLT32;
    else            generic_noise = xccvRandNFLT32;
  }
  else if( oHeader.format == "CD" ) {
    complexFlag   = 2;
    if(uniformFlag) generic_noise = xccvRandFLT64;
    else            generic_noise = xccvRandNFLT64;
  }
  else {
    complexFlag   = 2;
    if(uniformFlag) generic_noise = xccvRandFLT32;
    else            generic_noise = xccvRandNFLT32;
  }

  XMC_DEBUG("Output file format is %s\n", oHeader.format.buf);

  // Get the transfer length (BYTES) or transfer samples.  Default to 256k if not present.
  //---------------------------------------------------------------------------------------------
  if(m_get_pswitch("TL"))                     // Test for Transfer length.
  {                                           //
    xferLngth = m_get_switch("TL");           // Get transfer length (Bytes).
    xferSamps = xferLngth/oHeader.bpe;        // Calculate transfer samples.
  }                                           //
  else if(m_get_pswitch("TS"))                // Test for Transfer samples.
  {                                           //
    xferSamps = m_get_switch("TS");           // Get transfer samples.
    xferLngth = xferSamps*oHeader.bpe;        // Convert to transfer length (Bytes).
  }                                           //
  else                                        // Else
  {                                           //
    xferLngth = 262144;                       // Default to 256k bytes.
    xferSamps = xferLngth/oHeader.bpe;        // Calculate transfer samples.
    if(xferSamps>nSamples)                    //
    {                                         //
      xferSamps = nSamples;                   //
      xferLngth = xferSamps*oHeader.bpe;      //
    }                                         //
  }                                           //-------------------------------------------------
  XMC_DEBUG("xferLngth   is %ld\n",xferLngth);
  XMC_DEBUG("xferSamps   is %ld\n",xferSamps);
  XMC_DEBUG("oHeader.bpe is %d\n" ,oHeader.bpe);

  // Set the transfer length variable in the output header.
  //---------------------------------------------------------------------------------------------
  oHeader.xfer_len = xferSamps;
  oHeader.cons_len = -1;

  // Initialize output buffer.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Initialize xccawgnoise.\n");
  oDataINT08 = xccMallocINT08_Align032(xferLngth);

  // "Synchronize" not "sink".
  //---------------------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG("Calling m_sync();\n");

  // Process continuous.
  //---------------------------------------------------------------------------------------------
  if(continuousFlag)
  {
    nDo = xferSamps;
    while( !Mc->break_ )
    {
      generic_noise(&seedUNT64, std, oDataINT08, 1, nDo*complexFlag );

      m_filad(oHeader, oDataINT08, nDo);
    }
  }

  // Process non-continuous.
  //---------------------------------------------------------------------------------------------
  else
  {
    m_todo(oHeader.size);
    while( m_do(xferSamps, nDo) )
    {
      generic_noise(&seedUNT64, std, oDataINT08, 1, nDo*complexFlag );
      
      m_filad(oHeader, oDataINT08, nDo);
    }
  }

  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  m_close(oHeader);
  xmcFree(oDataINT08);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
