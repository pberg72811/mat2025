/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccrtgnoise.cc                                                                         -
// Desc: This primitive generates real-time guassian noise.                                     -
//       This primitive generates a buffer of gaussian noise and then indexes                   -
//       randomly (uniform random) into the buffer and sends out the data.                      -
//       This is basically a "trick" to speed up the apparent generation of                     -
//       gaussian noise which takes longer to generate then uniform random                      -
//       numbers.                                                                               -
// Args: oFileName   - The name of the output file.                  <A:>                       -
//       oFileType   - Data type of the output file.                 <A:>                       -
//       nSamples    - Number of samples to generate.                <D:>                       -
//       nBufferSize - Number of samples in internal noise buffer.   <D:>                       -
//       std         - Standard deviation of noise.                  <D:>                       -
//       fs          - Sample rate.                                  <D:>                       -
// Swch: /SEED       - Starting seed to use for noise.                                          -
//       /UNIFORM    - Generate uniform noise not guassian.                                     -
//       /CONTINUOUS - Keep generating data until Mc->break_ (CTL-C)                            -
// Hist: When       Who  What                                                                   -
//       04/29/2004 ptb  Initial Code.                                                          -
//                                                                                              -
//              iFileName                                                                       -
//              oFileName                                                                       -
//              nSamples                                                                        -
//              nBufferSize                                                                     -
//              std                                                                             -
//              fs                                                                              -
//               |                                                                              -
//               V                                                                              -
//         :--------------:     :---------:                                                     -
//         |xccrtgnoise.cc|---> |file/pipe|                                                     -
//         :--------------:     :---------:                                                     -
//               |                                                                              -
//               V                                                                              -
//         Debug Statements                                                                     -
// Note:                                                                                        -
//                                                                                              -
// Examples:                                                                                    -
// xccrtgnoise noisefile cb 1024*1024 1024*1024*4 5 8.5e6                                       -
// xccrtgnoise/CONTINUOUS/ts=1024*1024*128 noisefile cb 1024 1024*1024*4 5 8.5e6                -
// const v1 si 1024*1024 1                                                                      -
// const v2 si 1024*1024 100                                                                    -
// const v3 si 1024*1024 1000                                                                   -
// merge v2 v1                                                                                  -
// merge v3 v1                                                                                  -
// headermod v1 ,,,,, 1/8.5e6                                                                   -
// pipe on                                                                                      -
// sourcefile/replay=2/tl=2M v1 _s1(ps=4M)                                                      -
// xccrtgnoise/continuous/tl=2M _s2(ps=4M) si 1024*1024*1 1024*1024*4 20 8.5e6                  -
// fcalc/tl=2M _s3(ps=4M) _s1(ps=4M) _s2(ps=4M) +                                               -
// xccarchive/tl=2M _s3(ps=4M) src 1024*1024*128 /data11/steswd/ 10                             -
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

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID rcopyINT08(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n, UNT32 bufSize, UNT32 *seed);
VOID rcopyINT16(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n, UNT32 bufSize, UNT32 *seed);
VOID rcopyINT32(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n, UNT32 bufSize, UNT32 *seed);
VOID rcopyINT64(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n, UNT32 bufSize, UNT32 *seed);

/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID mainroutine()
{
  FLT32 fs;
  int_4 nDo;
  FLT32 std;
  UNT32 nSamples;
  UNT32 nBufferSize;
  INT32 xferLngth;
  INT32 xferSamps;
  INT08 *oDataINT08;
  INT08 *nBufferINT08;
  INT32 uniformFlag=0;
  INT32 complexFlag=0;
  INT32 continuousFlag=0;

  // generic function pointers.
  VOID (*generic_rcopy) (VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n, UNT32 bufSize, UNT32 *seed);

  // Switch variables.
  UNT64 seedUNT64=999888765797ULL;
  UNT32 seedUNT32=99988;

  // File name variables.
  string oFileName;
  string oFileType;

  // Get command line parameters.
  //-------------------------------------------------------------------------------
  oFileName   = m_apick(1);
  oFileType   = m_apick(2);
  nSamples    = (INT32)m_dpick(3);
  nBufferSize = (INT32)m_dpick(4);
  std         = m_dpick(5);
  fs          = m_dpick(6);
  XMC_DEBUG("oFileName   is %s\n",  oFileName.c_str());
  XMC_DEBUG("oFileType   is %s\n",  oFileType.c_str());
  XMC_DEBUG("nSamples    is %ld\n", nSamples);
  XMC_DEBUG("nBufferSize is %ld\n", nBufferSize);
  XMC_DEBUG("std/amp     is %f\n",  std);
  XMC_DEBUG("fs          is %f\n",  fs);

  // Check for "seed" switch.
  //-------------------------------------------------------------------------------
  if(m_get_pswitch("SEED")) 
  {
    seedUNT64 = (UNT64) m_get_dswitch("SEED");
  }
  else seedUNT64=999888765797ULL;
  XMC_DEBUG("seedUNT64   is %lld\n", seedUNT64);

  // Check for "uniform" switch.
  //-------------------------------------------------------------------------------
  if( m_get_pswitch("UNIFORM") )
  {
    uniformFlag = 1;
  }
  else uniformFlag = 0;
  XMC_DEBUG("uniformFlag is %ld\n", uniformFlag);

  // Check for "continuous" switch or number of samples set to zero.
  //-------------------------------------------------------------------------------
  if( m_get_pswitch("CONTINUOUS") ||  nSamples == 0 )
  {
    continuousFlag = 1;
  }
  else continuousFlag = 0;
  XMC_DEBUG("continuousFlag is %ld\n", continuousFlag);

  // Set up the output file header.
  //-------------------------------------------------------------------------------
  CPHEADER oHeader;
  m_initialize(oHeader);
  oHeader.file_name = oFileName;
  oHeader.type      = 1000;
  oHeader.format    = oFileType;
  oHeader.size      = nSamples;
  oHeader.xstart    = 0;
  oHeader.xdelta    = 1/fs;
  oHeader.xunits    = 1;
  oHeader.timecode  = xccCurrentJ1950Seconds();
  m_allocate(oHeader);

  // Set up based on output data type.
  //-------------------------------------------------------------------------------
  if     ( oHeader.format == "SB" ) {
    complexFlag   = 1;
    generic_rcopy = rcopyINT08;
    nBufferINT08  = xccMallocINT08_Align032(nBufferSize*oHeader.bpe);
    if(uniformFlag) xccvRandINT08 (&seedUNT64, std, (INT08 *)nBufferINT08, 1, nBufferSize);
    else            xccvRandNINT08(&seedUNT64, std, (INT08 *)nBufferINT08, 1, nBufferSize);
  }
  else if( oHeader.format == "SI" ) {
    complexFlag   = 1;
    generic_rcopy = rcopyINT16;
    nBufferINT08  = xccMallocINT08_Align032(nBufferSize*oHeader.bpe);
    if(uniformFlag) xccvRandINT16 (&seedUNT64, std, (INT16 *)nBufferINT08, 1, nBufferSize);
    else            xccvRandNINT16(&seedUNT64, std, (INT16 *)nBufferINT08, 1, nBufferSize);
  }
  else if( oHeader.format == "SL" ) {
    complexFlag   = 1;
    generic_rcopy = rcopyINT32;
    nBufferINT08  = xccMallocINT08_Align032(nBufferSize*oHeader.bpe);
    if(uniformFlag) xccvRandINT32 (&seedUNT64, std, (INT32 *)nBufferINT08, 1, nBufferSize);
    else            xccvRandNINT32(&seedUNT64, std, (INT32 *)nBufferINT08, 1, nBufferSize);
  }
  else if( oHeader.format == "SF" ) {
    complexFlag   = 1;
    generic_rcopy = rcopyINT32;
    nBufferINT08  = xccMallocINT08_Align032(nBufferSize*oHeader.bpe);
    if(uniformFlag) xccvRandFLT32 (&seedUNT64, std, (FLT32 *)nBufferINT08, 1, nBufferSize);
    else            xccvRandNFLT32(&seedUNT64, std, (FLT32 *)nBufferINT08, 1, nBufferSize);
  }
  else if( oHeader.format == "SD" ) {
    complexFlag   = 1;
    generic_rcopy = rcopyINT64;
    nBufferINT08  = xccMallocINT08_Align032(nBufferSize*oHeader.bpe);
    if(uniformFlag) xccvRandFLT64 (&seedUNT64, std, (FLT64 *)nBufferINT08, 1, nBufferSize);
    else            xccvRandNFLT64(&seedUNT64, std, (FLT64 *)nBufferINT08, 1, nBufferSize);
  }
  else if( oHeader.format == "CB" ) {
    complexFlag   = 2;
    generic_rcopy = rcopyINT08;
    nBufferINT08  = xccMallocINT08_Align032(nBufferSize*oHeader.bpe);
    if(uniformFlag) xccvRandINT08 (&seedUNT64, std, (INT08 *)nBufferINT08, 1, nBufferSize*2);
    else            xccvRandNINT08(&seedUNT64, std, (INT08 *)nBufferINT08, 1, nBufferSize*2);
  }
  else if( oHeader.format == "CI" ) {
    complexFlag   = 2;
    generic_rcopy = rcopyINT16;
    nBufferINT08  = xccMallocINT08_Align032(nBufferSize*oHeader.bpe);
    if(uniformFlag) xccvRandINT16 (&seedUNT64, std, (INT16 *)nBufferINT08, 1, nBufferSize*2);
    else            xccvRandNINT16(&seedUNT64, std, (INT16 *)nBufferINT08, 1, nBufferSize*2);
  }
  else if( oHeader.format == "CL" ) {
    complexFlag   = 2;
    generic_rcopy = rcopyINT32;
    nBufferINT08  = xccMallocINT08_Align032(nBufferSize*oHeader.bpe);
    if(uniformFlag) xccvRandINT32 (&seedUNT64, std, (INT32 *)nBufferINT08, 1, nBufferSize*2);
    else            xccvRandNINT32(&seedUNT64, std, (INT32 *)nBufferINT08, 1, nBufferSize*2);
  }
  else if( oHeader.format == "CF" ) {
    complexFlag   = 2;
    generic_rcopy = rcopyINT32;
    nBufferINT08  = xccMallocINT08_Align032(nBufferSize*oHeader.bpe);
    if(uniformFlag) xccvRandFLT32 (&seedUNT64, std, (FLT32 *)nBufferINT08, 1, nBufferSize*2);
    else            xccvRandNFLT32(&seedUNT64, std, (FLT32 *)nBufferINT08, 1, nBufferSize*2);
  }
  else if( oHeader.format == "CD" ) {
    complexFlag   = 2;
    generic_rcopy = rcopyINT64;
    nBufferINT08  = xccMallocINT08_Align032(nBufferSize*oHeader.bpe);
    if(uniformFlag) xccvRandFLT64 (&seedUNT64, std, (FLT64 *)nBufferINT08, 1, nBufferSize*2);
    else            xccvRandNFLT64(&seedUNT64, std, (FLT64 *)nBufferINT08, 1, nBufferSize*2);
  }
  else {
    complexFlag   = 2;
    generic_rcopy = rcopyINT32;
    nBufferINT08  = xccMallocINT08_Align032(nBufferSize*oHeader.bpe);
    if(uniformFlag) xccvRandFLT32 (&seedUNT64, std, (FLT32 *)nBufferINT08, 1, nBufferSize);
    else            xccvRandNFLT32(&seedUNT64, std, (FLT32 *)nBufferINT08, 1, nBufferSize);
  }

  XMC_DEBUG("Output file format is %s\n", oHeader.format.buf);

  // Get the transfer length (BYTES) or transfer samples.  Default to 256k if not present.
  //-------------------------------------------------------------------------------
  if(m_get_pswitch("TL"))                     // Test for Transfer length.
  {                                           //
    xferLngth = m_get_switch("TL");           // Get transfer length (Bytes).
    xferSamps = xferLngth/oHeader.bpe;        // Calculate transfer samples.
  }
  else if(m_get_pswitch("TS"))                // Test for Transfer samples.
  {                                           //
    xferSamps = m_get_switch("TS");           // Get transfer samples.
    xferLngth = xferSamps*oHeader.bpe;        // Convert to transfer length (Bytes).
  }
  else                                        // Else
  {                                           //
    xferLngth = 262144;                       // Default to 256k bytes.
    xferSamps = xferLngth/oHeader.bpe;        // Calculate transfer samples.
    if((UNT32)xferSamps>nSamples)
    {
      xferSamps = nSamples;
      xferLngth = xferSamps*oHeader.bpe;
    }
  }
  XMC_DEBUG("xferLngth   is %ld\n",xferLngth);
  XMC_DEBUG("xferSamps   is %ld\n",xferSamps);
  XMC_DEBUG("oHeader.bpe is %d\n" ,oHeader.bpe);

  // Set the transfer length variable in the output header.
  //-------------------------------------------------------------------------------
  oHeader.xfer_len = xferSamps;
  oHeader.cons_len = -1;

  // Initialize output buffer.
  //-------------------------------------------------------------------------------
  XMC_DEBUG("Initialize xccrtnplay.\n");
  oDataINT08 = xccMallocINT08_Align032(xferLngth);

  // "Synchronize" not "sink".
  //-------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG("Calling m_sync();\n");

  // If continuous then process continuous.
  //-------------------------------------------------------------------------------
  if(continuousFlag)
  {
    nDo = xferSamps;
    while( !Mc->break_ )
    {
      generic_rcopy(nBufferINT08, 1, oDataINT08, 1, nDo*complexFlag, nBufferSize*complexFlag, &seedUNT32);

      XMC_DEBUG("The seed is %lu\n",seedUNT32);
      m_filad(oHeader, oDataINT08, nDo);
    }
  }

  // Else process non-continuous.
  //-------------------------------------------------------------------------------
  else
  {
    m_todo(oHeader.size);
    while( m_do(xferSamps, nDo) )
    {
      generic_rcopy(nBufferINT08, 1, oDataINT08, 1, nDo*complexFlag, nBufferSize*complexFlag, &seedUNT32);

      XMC_DEBUG("The seed is %lu\n",seedUNT32);
      m_filad(oHeader, oDataINT08, nDo);
    }
  }

  // Terminate and return.
  //-------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  m_close(oHeader);
  xmcFree(oDataINT08);
  xmcFree(nBufferINT08);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*-------------------------------UNCLASSIFIED---------------------------------*/

VOID rcopyINT08(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n, UNT32 bufSize, UNT32 *seed)
{
  INT08 *pa = (INT08 *)a;
  INT08 *pb = (INT08 *)b;
  UNT32 ii;
  UNT32 index;
  
  for(ii=0; ii < n; ii++)
  {
    *seed = (*seed*A1UNT32) + B1UNT32;
    index = *seed%bufSize;
    *pb = pa[index];
    pb = pb+=j;
  }
}

VOID rcopyINT16(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n, UNT32 bufSize, UNT32 *seed)
{
  INT16 *pa = (INT16 *)a;
  INT16 *pb = (INT16 *)b;
  UNT32 ii;
  UNT32 index;
  
  for(ii=0; ii < n; ii++)
  {
    *seed = (*seed*A1UNT32) + B1UNT32;
    index = *seed%bufSize;
    *pb = pa[index];
    pb = pb+=j;
  }
}

VOID rcopyINT32(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n, UNT32 bufSize, UNT32 *seed)
{
  INT32 *pa = (INT32 *)a;
  INT32 *pb = (INT32 *)b;
  UNT32 ii;
  UNT32 index;
  
  for(ii=0; ii < n; ii++)
  {
    *seed = (*seed*A1UNT32) + B1UNT32;
    index = *seed%bufSize;
    *pb = pa[index];
    pb = pb+=j;
  }
}

VOID rcopyINT64(VOID *a, INT32 i, VOID *b, INT32 j, UNT32 n, UNT32 bufSize, UNT32 *seed)
{
  INT64 *pa = (INT64 *)a;
  INT64 *pb = (INT64 *)b;
  UNT32 ii;
  UNT32 index;
  
  for(ii=0; ii < n; ii++)
  {
    *seed = (*seed*A1UNT32) + B1UNT32;
    index = *seed%bufSize;
    *pb = pa[index];
    pb = pb+=j;
  }
}
