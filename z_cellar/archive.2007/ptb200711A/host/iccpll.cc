/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: iccpll.cc                                                                              -
//                                                                                              -
// Desc: This primitive performs a phase lock loop.                                             -
//                                                                                              -
// Args: iFileName     - The name of the input file.             <A:>                           -
//       oFileNameVCO  - The name of the vco output file.        <A:>                           -
//       oFileNameERR  - The name of the error output file.      <A:>                           -
//       oFileNameDRO  - The name of the derotated output file.  <A:>                           -
//       refFreq       - Reference frequency.                    <D:>                           -
//       lockInRange   - Lock in range (Hz).                     <D:>                           -
//       dampingFactor - Damping factor.                         <D:>                           -
//                                                                                              -
// Swch: /TL - Transfer length.                                                                 -
//       /TS - Transfer samples.                                                                -
//       /FS - Force the sample rate to a given value.                                          -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       03/07/2005 ptb  Initial Code.                                                          -
//                                                                                              -
//                           oFileName                                                          -
//                           oFileNameVCO                                                       -
//                           oFileNameERR                                                       -
//                           oFileNameDRO                                                       -
//                           refFreq                                                            -
//                           lockInRange                                                        -
//                           dampingFactor                                                      -
//                           /FS                                                                -
//                            |                                                                 -
//                            V                                                                 -
//    :-----------:     :-----------:     :---------------:                                     -
//    | FILE/PIPE |---> | iccpll.cc |---> | VCO FILE/PIPE |                                     -
//    :-----------:     :-----------: |   :---------------:-:                                   -
//                            |       +---> | ERR FILE/PIPE |                                   -
//                            |       |     :---------------:-:                                 -
//                            |       +-----> | DRO FILE/PIPE |                                 -
//                            |               :---------------:                                 -
//                            V                                                                 -
//                       Debug Statements                                                       -
//                                                                                              -
// Note: This primitive takes only complex data types.  Use "CXCNVRT" on real                   -
//       data types first before sending/piping them to this primitive.                         -
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
#include "buffer_utils.h"
#include "dsp_utils.h"
#include "malloc_utils.h"
#include "orbit_utils.h"
#include "stack_utils.h"
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
  INT32  ii;
  FLT64  fs;
  FLT64  refFreq;
  FLT64  phaseDif;
  FLT64  lpfError=0.0;
  FLT64  lockInRange;
  FLT64  dampingFactor;
  UNT64  sampleCounter=1;
  UNT64  integratCount=1;
  INT08  *iDataINT08;
  CFLT64 *iDataCFLT64;
  CFLT32 *oVcoCFLT32;
  CFLT32 *oDroCFLT32;
  FLT32  *oErrFLT32;
  CFLT64 vcoCFLT64;
  CFLT64 outCFLT64;
  CFLT64 foutCFLT64;
  CFLT64 vcoCFLT64Conj;

  string iFileName;
  string oFileNameVCO;
  string oFileNameERR;
  string oFileNameDRO;

  int_4 nGot;
  INT32 xferLngth;
  INT32 xferSamps;

  iccVCOSpec        *vcoSpec;
  iccLoopFilterSpec *lpfSpec;

  VOID (*genericToCFLT64)(VOID *, INT32, CFLT64 *, INT32, UNT32);

  // Get command line parameters.
  //---------------------------------------------------------------------------------------------
  iFileName     = m_apick(1);
  oFileNameVCO  = m_apick(2);
  oFileNameERR  = m_apick(3);
  oFileNameDRO  = m_apick(4);
  refFreq       = m_dpick(5);
  lockInRange   = m_dpick(6);
  dampingFactor = m_dpick(7);
  integratCount = (INT32)m_dpick(8);
  
  XMC_DEBUG("iFileName     is %s\n" , iFileName.c_str());
  XMC_DEBUG("oFileNameVCO  is %s\n" , oFileNameVCO.c_str());
  XMC_DEBUG("oFileNameERR  is %s\n" , oFileNameERR.c_str());
  XMC_DEBUG("oFileNameDRO  is %s\n" , oFileNameDRO.c_str());
  XMC_DEBUG("refFreq       is %f\n" , refFreq);
  XMC_DEBUG("lockInRange   is %f\n" , lockInRange);
  XMC_DEBUG("dampingFactor is %f\n" , dampingFactor);
  XMC_DEBUG("integratCount is %llu\n", integratCount);

  // Set up the input file header.
  //---------------------------------------------------------------------------------------------
  CPHEADER iHeader;
  iHeader.file_name    = iFileName;
  iHeader.type_allow   = "1000";
  iHeader.format_allow = "CB,CI,CL,CF,CD";
  m_inok(iHeader);

  // Get the transfer length (BYTES) or transfer samples.  Default to 256k if not present.
  //---------------------------------------------------------------------------------------------
  if(m_get_pswitch("TL"))                     // Test for Transfer length.
  {                                           //
    xferLngth = m_get_switch("TL");           // Get transfer length (Bytes).
    xferSamps = xferLngth/iHeader.bpe;        // Calculate transfer samples.
  }
  else if(m_get_pswitch("TS"))                // Test for Transfer samples.
  {                                           //
    xferSamps = m_get_switch("TS");           // Get transfer samples.
    xferLngth = xferSamps*iHeader.bpe;        // Convert to transfer length (Bytes).
  }
  else                                        // Else
  {                                           //
    xferLngth = 262144;                       // Default to 256k bytes.
    xferSamps = xferLngth/iHeader.bpe;        // Calculate transfer samples.
  }
  nGot = xferSamps;
  XMC_DEBUG("xferLngth   is %ld\n",xferLngth);
  XMC_DEBUG("xferSamps   is %ld\n",xferSamps);
  XMC_DEBUG("nGot        is %ld\n",xferSamps);
  XMC_DEBUG("iHeader.bpe is %d\n" ,iHeader.bpe);

  // Set the transfer length variable in the input header.
  //---------------------------------------------------------------------------------------------
  iHeader.xfer_len = xferSamps;
  iHeader.cons_len = -1;

  // Set up the output file headers.
  //---------------------------------------------------------------------------------------------
  CPHEADER oHeaderVCO;
  m_initialize(oHeaderVCO);
  oHeaderVCO.file_name = oFileNameVCO;
  oHeaderVCO.type      = 1000;
  oHeaderVCO.format    = "CF";
  oHeaderVCO.size      = iHeader.size;
  oHeaderVCO.xstart    = iHeader.xstart;
  oHeaderVCO.xdelta    = iHeader.xdelta;
  oHeaderVCO.xunits    = 1;
  m_allocate(oHeaderVCO);

  CPHEADER oHeaderERR;
  m_initialize(oHeaderERR);
  oHeaderERR.file_name = oFileNameERR;
  oHeaderERR.type      = 1000;
  oHeaderERR.format    = "SF";
  oHeaderERR.size      = iHeader.size;
  oHeaderERR.xstart    = iHeader.xstart;
  oHeaderERR.xdelta    = iHeader.xdelta;
  oHeaderERR.xunits    = 1;
  m_allocate(oHeaderERR);

  CPHEADER oHeaderDRO;
  m_initialize(oHeaderDRO);
  oHeaderDRO.file_name = oFileNameDRO;
  oHeaderDRO.type      = 1000;
  oHeaderDRO.format    = "CF";
  oHeaderDRO.size      = iHeader.size;
  oHeaderDRO.xstart    = iHeader.xstart;
  oHeaderDRO.xdelta    = iHeader.xdelta;
  oHeaderDRO.xunits    = 1;
  m_allocate(oHeaderDRO);

  // Check for sample rate switch.
  //---------------------------------------------------------------------------------------------
  if(m_get_pswitch("FS"))
  {
    fs = m_get_switch("FS");
  }
  else
  {
    fs = 1.0/iHeader.xdelta;
  }

  // Set the generic conversion function based on input data type.
  //---------------------------------------------------------------------------------------------
  if      ( strncmp(&iHeader.format.buf[0], "CB", 2)==0 )
  {
    genericToCFLT64 = iccvCINT08ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CI", 2)==0 )
  {
    genericToCFLT64 = iccvCINT16ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CL", 2)==0 )
  {
    genericToCFLT64 = iccvCINT64ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CF", 2)==0 )
  {
    genericToCFLT64 = iccvCFLT32ToCFLT64;
  }
  else if ( strncmp(&iHeader.format.buf[0], "CD", 2)==0 )
  {
    genericToCFLT64 = iccvCFLT64ToCFLT64;
  }
  else
  {
    printf("UNSUPPORTED DATA TYPE.\n"); //We should never get here because of m_inok(iHeader);
    exit(0);
  }
  XMC_DEBUG("Input file format is %s\n", iHeader.format.buf);

  // iccpll init.
  //---------------------------------------------------------------------------------------------
  lpfError = 0.0;
  CPLXCLEAR(foutCFLT64);
  if(integratCount==0)integratCount = (INT32)round(fabs(fs/refFreq)/2.0);
  iDataINT08  = iccMallocINT08_Align032 ( xferLngth );
  iDataCFLT64 = iccMallocCFLT64_Align032( xferSamps );
  oVcoCFLT32  = iccMallocCFLT32_Align032( xferSamps );
  oDroCFLT32  = iccMallocCFLT32_Align032( xferSamps );
  oErrFLT32   = iccMallocFLT32_Align032 ( xferSamps );

  // iccpll VCO initialization.
  //---------------------------------------------------------------------------------------------
  vcoSpec = iccVCOInit(refFreq, fs, 0.0);

  // iccpll loop filter initialization.
  //---------------------------------------------------------------------------------------------
  lpfSpec = iccLoopFilterInit(lockInRange,       // Lock in range.
			      dampingFactor,     // Damping factor.
			      1.0/TWOPI,         // Kd. Usually (1.0/TWOPI).
			      TWOPI,             // Ko.  Usually (TWOPI).
			      fs/integratCount); // Sample rate for loop filter. (fs*integrate)

  // Start the processing loop.
  //---------------------------------------------------------------------------------------------
  while( (nGot==xferSamps) && (!Mc->break_) )
  {

    // Grab the input data.
    //-------------------------------------------------------------------------------------------
    m_grabx(iHeader, iDataINT08, nGot);

    // Convert to CFLT64.
    //-------------------------------------------------------------------------------------------
    genericToCFLT64((VOID *)iDataINT08, 1, iDataCFLT64, 1, xferSamps);

    // Process.
    //-------------------------------------------------------------------------------------------
    for(ii=0; ii<nGot; ii++)
    {
      vcoCFLT64 = iccVCOCFLT64( lpfError, vcoSpec );         // Update the VCO.
                                                             //
      CPLXCONJ(vcoCFLT64, vcoCFLT64Conj);                    // Take conj. to use as tuner.
                                                             //
      CPLXMULT(vcoCFLT64Conj, iDataCFLT64[ii], outCFLT64);   // Tune (derotate) the input.
                                                             //
      CPLXADD (foutCFLT64, outCFLT64, foutCFLT64);           // Integrate to increase SNR.
                                                             //
      if( (sampleCounter%integratCount)==0 )                 // If it is time to dump.
      {                                                      //
	phaseDif = atan2(foutCFLT64.i, foutCFLT64.r);        // Get the phase after Integration.
	lpfError = iccLoopFilterFLT64( phaseDif, lpfSpec );  // Run phase through the loop filter.
        lpfError = lpfError/TWOPI;                           // Divide by VCO gain. (WHY?!).
        CPLXCLEAR(foutCFLT64);                               // Clear out the Integrator.
      }                                                      //
                                                             //
      oVcoCFLT32[ii].r = vcoCFLT64.r;                        // Save off VCO output.
      oVcoCFLT32[ii].i = vcoCFLT64.i;                        //
      oDroCFLT32[ii].r = outCFLT64.r;                        // Save off derotated output.
      oDroCFLT32[ii].i = outCFLT64.i;                        //
      oErrFLT32[ii]    = lpfError;                           // Save off loop error output.
      sampleCounter++;
    }

    // Write out the data.
    //-------------------------------------------------------------------------------------------
    m_filad(oHeaderVCO, oVcoCFLT32, nGot);
    m_filad(oHeaderERR, oErrFLT32,  nGot);
    m_filad(oHeaderDRO, oDroCFLT32, nGot);

  }

  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  xmcFree(iDataINT08);
  xmcFree(iDataCFLT64);
  xmcFree(oVcoCFLT32);
  xmcFree(oDroCFLT32);
  xmcFree(oErrFLT32);

  m_close(iHeader);
  m_close(oHeaderVCO);
  m_close(oHeaderERR);
  m_close(oHeaderDRO);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
