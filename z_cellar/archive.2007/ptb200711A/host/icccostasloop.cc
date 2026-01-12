/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: icccostasloop.cc                                                                       -
//                                                                                              -
// Desc: This primitive performs a costas loop.                                                 -
//                                                                                              -
// Args: iFileName     - The name of the input file.                       <A:>                 -
//       oFileNameVCO  - The name of the vco output file.                  <A:>                 -
//       oFileNameERR  - The name of the error output file.                <A:>                 -
//       oFileNamePHSI - The name of the derotated I channel output file.  <A:>                 -
//       oFileNamePHSQ - The name of the derotated Q channel output file.  <A:>                 -
//       refFreq       - Reference frequency.                              <D:>                 -
//       lockInRange   - Lock in range (Hz).                               <D:>                 -
//       dampingFactor - Damping factor.                                   <D:>                 -
//                                                                                              -
// Swch: /TL - Transfer length.                                                                 -
//       /TS - Transfer samples.                                                                -
//       /FS - Force the sample rate to a given value.                                          -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       03/07/2005 ptb  Initial Code.                                                          -
//                                                                                              -
//                            iFileName                                                         -
//                            oFileNameVCO                                                      -
//                            oFileNameERR                                                      -
//                            oFileNamePHSI                                                     -
//                            oFileNamePHSQ                                                     -
//                            refFreq                                                           -
//                            lockInRange                                                       -
//                            dampingFactor                                                     -
//                               |                                                              -
//                               V                                                              -
//    :-----------:     :------------------:     :-----------:                                  -
//    | File/Pipe |---> | icccostasloop.cc |---> | File/Pipe |                                  -
//    :-----------:     :------------------:     :-----------:                                  -
//                               |                                                              -
//                               V                                                              -
//                       Debug Statements                                                       -
//                                                                                              -
// Note: This primitive takes only complex data types.  Use "CXCNVRT" on real                   -
//       data types first before sending/piping them to this primitive.                         -
//                                                                                              -
// Examples:                                                                                    -
// icccostasloop fTADPSOI_DESPREAD ovco oerr ophsi ophsq 25 10 .5 1024                          -
// icccostasloop ftadpsoi_20041201_022528_t6_short ovco oerr ophsi ophsq 20 10 .5 1024          -
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
  //INT32  jj;
  //INT32  kk;
  FLT64  fs;
  FLT64  phase0;
  FLT64  refFreq;
  //FLT64  refDelta;
  FLT64  lpfError=0.0;
  INT32  lpfErrorCount=0;
  FLT64  lockInRange;
  FLT64  dampingFactor;
  UNT64  integratCount=0;
  //INT32  sumCompleteFlag=0;
  INT08  *iDataINT08;
  CFLT64 *iDataCFLT64;
  CFLT32 *oVcoCFLT32;
  CFLT32 *oDroICFLT32;
  CFLT32 *oDroQCFLT32;
  FLT32  *oErrFLT32;
  CFLT64 vcoCFLT64;
  CFLT64 outICFLT64;
  CFLT64 outQCFLT64;
  CFLT64 ICFLT64;
  CFLT64 QCFLT64;
  CFLT64 foutICFLT64;
  CFLT64 foutQCFLT64;
  CFLT64 vcoICFLT64;
  CFLT64 vcoQCFLT64;
  CFLT64 qWeight={ 0.0,-1.0}; //cos(-pi/2), sin(-pi/2)
  string iFileName;
  string oFileNameVCO;
  string oFileNameERR;
  string oFileNameDROI;
  string oFileNameDROQ;
  int_4 nGot;
  INT32 xferLngth;
  INT32 xferSamps;

  iccVCOSpec        *vcoSpec;
  iccLoopFilterSpec *lpfSpec;

  iccBufferCFLT64_t *circularBufferI;
  iccBufferCFLT64_t *circularBufferQ;

  VOID (*genericToCFLT64)(VOID *, INT32, CFLT64 *, INT32, UNT32);

  // Get command line parameters.
  //---------------------------------------------------------------------------------------------
  iFileName     = m_apick(1);
  oFileNameVCO  = m_apick(2);
  oFileNameERR  = m_apick(3);
  oFileNameDROI = m_apick(4);
  oFileNameDROQ = m_apick(5);
  refFreq       = m_dpick(6);
  lockInRange   = m_dpick(7);
  dampingFactor = m_dpick(8);
  integratCount = (UNT64)m_dpick(9);
  
  XMC_DEBUG("iFileName     is %s\n", iFileName.c_str());
  XMC_DEBUG("oFileNameVCO  is %s\n", oFileNameVCO.c_str());
  XMC_DEBUG("oFileNameERR  is %s\n", oFileNameERR.c_str());
  XMC_DEBUG("oFileNameDROI is %s\n", oFileNameDROI.c_str());
  XMC_DEBUG("oFileNameDROQ is %s\n", oFileNameDROQ.c_str());
  XMC_DEBUG("refFreq       is %f\n", refFreq);
  XMC_DEBUG("lockInRange   is %f\n", lockInRange);
  XMC_DEBUG("dampingFactor is %f\n", dampingFactor);
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

  if(xferSamps > iHeader.size)                // Check to see if xferSamps is too big.
  {                                           //
    xferSamps = (INT32)iHeader.size;                 // Make adjustments to xferSamps
    xferLngth = xferSamps*iHeader.bpe;        // and xferLngth.
  }                                           //
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

  CPHEADER oHeaderDROI;
  m_initialize(oHeaderDROI);
  oHeaderDROI.file_name = oFileNameDROI;
  oHeaderDROI.type      = 1000;
  oHeaderDROI.format    = "CF";
  oHeaderDROI.size      = iHeader.size;
  oHeaderDROI.xstart    = iHeader.xstart;
  oHeaderDROI.xdelta    = iHeader.xdelta;
  oHeaderDROI.xunits    = 1;
  m_allocate(oHeaderDROI);

  CPHEADER oHeaderDROQ;
  m_initialize(oHeaderDROQ);
  oHeaderDROQ.file_name = oFileNameDROQ;
  oHeaderDROQ.type      = 1000;
  oHeaderDROQ.format    = "CF";
  oHeaderDROQ.size      = iHeader.size;
  oHeaderDROQ.xstart    = iHeader.xstart;
  oHeaderDROQ.xdelta    = iHeader.xdelta;
  oHeaderDROQ.xunits    = 1;
  m_allocate(oHeaderDROQ);

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
    genericToCFLT64 = iccvCINT32ToCFLT64;
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
  phase0   = 0.0;
  lpfError = 0.0;
  CPLXCLEAR(ICFLT64);
  CPLXCLEAR(QCFLT64);
  CPLXCLEAR(foutICFLT64);
  CPLXCLEAR(foutQCFLT64);
  if(integratCount==0)integratCount = (UNT64)round(fabs(fs/refFreq)/2.0);
  XMC_DEBUG("integratCount is %llu\n", integratCount);
  iDataINT08  = iccMallocINT08_Align032 ( xferLngth );
  iDataCFLT64 = iccMallocCFLT64_Align032( xferSamps );
  oVcoCFLT32  = iccMallocCFLT32_Align032( xferSamps );
  oDroICFLT32 = iccMallocCFLT32_Align032( xferSamps );
  oDroQCFLT32 = iccMallocCFLT32_Align032( xferSamps );
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
  			      fs);               // Sample rate for loop filter. (fs/integrate)
  //  			      fs/integratCount); // Sample rate for loop filter. (fs/integrate)

  XMC_DEBUG("lpfSpec->lockInRange   is %f\n", lpfSpec->lockInRange);
  XMC_DEBUG("lpfSpec->dampingFactor is %f\n", lpfSpec->dampingFactor);
  XMC_DEBUG("lpfSpec->Kd            is %f\n", lpfSpec->Kd);
  XMC_DEBUG("lpfSpec->Ko            is %f\n", lpfSpec->Ko);
  XMC_DEBUG("lpfSpec->fs            is %f\n", lpfSpec->fs);
  XMC_DEBUG("lpfSpec->sum           is %f\n", lpfSpec->sum);
  XMC_DEBUG("lpfSpec->samplePeriod  is %f\n", lpfSpec->samplePeriod);
  XMC_DEBUG("lpfSpec->naturalFrequency is %f\n", lpfSpec->naturalFrequency);
  XMC_DEBUG("lpfSpec->Ki            is %f\n", lpfSpec->Ki);
  XMC_DEBUG("lpfSpec->Kp            is %f\n", lpfSpec->Kp);
  XMC_DEBUG("lpfSpec->noiseBW       is %f\n", lpfSpec->noiseBW);
  XMC_DEBUG("lpfSpec->integratorLimit is %f\n", lpfSpec->integratorLimit);

  // Set up some circular buffers.
  //---------------------------------------------------------------------------------------------
  circularBufferI  = iccBufferInitCFLT64( integratCount, "Circular Buffer I" );
  circularBufferQ  = iccBufferInitCFLT64( integratCount, "Circular Buffer Q" );
  iccBufferClearCFLT64( circularBufferI );
  iccBufferClearCFLT64( circularBufferQ );

  XMC_DEBUG("Circular Buffer.\n");
  
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
      CFLT64 tempCFLT64;

                                                             //----------------------------------
      vcoCFLT64 = iccVCOCFLT64( lpfError, vcoSpec );         // Update the VCO.                 -
                                                             //                                 -
      CPLXCONJ(vcoCFLT64, vcoICFLT64);                       // Take vco I conj. for tuning.    -
      CPLXCONJ(vcoCFLT64, vcoQCFLT64);                       // Take vco Q conj. for tuning.    -
                                                             //                                 -
      CPLXMULT(vcoQCFLT64, qWeight, tempCFLT64);             // Make 90 degree adj. to vco Q.   -
      vcoQCFLT64 = tempCFLT64;                               //                                 -
                                                             //                                 -
                                                             //                                 -
      CPLXMULT(vcoICFLT64, iDataCFLT64[ii], outICFLT64);     // Tune (derotate) the I input.    -
      CPLXMULT(vcoQCFLT64, iDataCFLT64[ii], outQCFLT64);     // Tune (derotate) the Q input.    -
                                                             //                                 -
      if(ii==0)                                              //                                 -
      {                                                      //                                 -
	iccBufferWriteCFLT64( circularBufferI, &outICFLT64 );// Write data in circ. buffer.     -
	iccBufferWriteCFLT64( circularBufferQ, &outQCFLT64 );// Write data in circ. buffer.     -
	iccBufferSumCFLT64(circularBufferI);                 // Perform summation.              -
	iccBufferSumCFLT64(circularBufferQ);                 // Perform summation.              -
      }                                                      //                                 -
      else                                                   //                                 -
      {                                                      //                                 -
	iccBufferWriteSumCFLT64( circularBufferI, &outICFLT64 );// WriteSum data in circ. buffer.
	iccBufferWriteSumCFLT64( circularBufferQ, &outQCFLT64 );// WriteSum data in circ. buffer.
      }                                                      //                                 -
                                                             //----------------------------------
      foutICFLT64 = circularBufferI->theSum;
      foutQCFLT64 = circularBufferQ->theSum;

      CPLXMULT(foutICFLT64, foutQCFLT64, tempCFLT64);        // Mix I and Q.                   -
                                                             //                                -
      phase0    = atan2(tempCFLT64.i, tempCFLT64.r);         // Take phase.                    -
                                                             //                                -
      lpfError  = iccLoopFilterFLT64( phase0, lpfSpec );     // Run phase through the loop fltr.
      lpfError  = lpfError/(TWOPI);                          // Divide by VCO gain. (WHY?!).   -

                                                             //----------------------------------
      oVcoCFLT32[ii].r  = vcoCFLT64.r;                       // Save off VCO output.            -
      oVcoCFLT32[ii].i  = vcoCFLT64.i;                       //                                 -
      oDroICFLT32[ii].r = foutICFLT64.r;                     // Save off derotated I output.    -
      oDroICFLT32[ii].i = foutICFLT64.i;                     //                                 -
      oDroQCFLT32[ii].r = foutQCFLT64.r;                     // Save off derotated Q output.    -
      oDroQCFLT32[ii].i = foutQCFLT64.i;                     //                                 -
      oErrFLT32[ii]     = lpfError;                          // Save off loop error output.     -
                                                             //----------------------------------
    }

    // Write out the data.
    //-------------------------------------------------------------------------------------------
    m_filad(oHeaderVCO,  oVcoCFLT32,  nGot);
    m_filad(oHeaderERR,  oErrFLT32,   nGot);
    m_filad(oHeaderDROI, oDroICFLT32, nGot);
    m_filad(oHeaderDROQ, oDroQCFLT32, nGot);
    lpfErrorCount=0;
  }

  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  xmcFree(iDataINT08);
  xmcFree(iDataCFLT64);
  xmcFree(oVcoCFLT32);
  xmcFree(oDroICFLT32);
  xmcFree(oDroQCFLT32);
  xmcFree(oErrFLT32);

  m_close(iHeader);
  m_close(oHeaderVCO);
  m_close(oHeaderERR);
  m_close(oHeaderDROI);
  m_close(oHeaderDROQ);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
