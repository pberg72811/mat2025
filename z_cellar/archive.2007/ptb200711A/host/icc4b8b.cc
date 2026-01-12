/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: icc4b8b.cc                                                                             -
//                                                                                              -
// Desc: This primitive converts packed 4 bit data to 8 bit data.                               -
//                                                                                              -
// Args: iFileName - The name of the input  file.      <A:>                                     -
//       oFileName - The name of the output file.      <A:>                                     -
//       LSB_MSB   - Lower/Higher oder bits go first.  <A:>                                     -
//                                                                                              -
// Swch: TL        - Switch to set transfer length.                                             -
//       TS        - Switch to set transfer samples.                                            -
//                                                                                              -
// Hist: When       Who  What                                                                   -
//       12/22/2005 ptb  Initial Code.                                                          -
//                                                                                              -
//                           iFileName                                                          -
//                           oFileName                                                          -
//                           /TL                                                                -
//                           /TS                                                                -
//                             |                                                                -
//                             V                                                                -
//    :-----------:     :------------:     :-----------:                                        -
//    | FILE/PIPE |---> | icc4b8b.cc |---> | FILE/PIPE |                                        -
//    :-----------:     :------------:     :-----------:                                        -
//                             |                                                                -
//                             V                                                                -
//                      Debug Statements                                                        -
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
#include "malloc_utils.h"
#include "orbit_utils.h"
#include "socket_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG      TRUE
#define DEBUG_HOST  "192.9.214.113"
#define DEBUG_PORT  5001
#define DEBUG_TYPE  XMC_DEBUG_STDOUT
//#define DEBUG_TYPE DEBUG_STDOUT_FILE
#define XMC_DEBUG  if( DEBUG ) DEBUG_TYPE

#define WRITE_PREVIOUS 1
#define WRITE_ZEROS    2

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
  INT32 jj;
  INT32 LSBMSBFlag;
  int_4 nGot;
  INT08 *iDataINT08;
  INT08 *oDataINT08;

  // Switch variables.
  INT32 xferLngth;
  INT32 xferSamps;

  // File name variables.
  string iFileName;
  string oFileName;
  string LSB_MSB;

  // Get command line parameters.
  //---------------------------------------------------------------------------------------------
  iFileName = m_apick(1);
  oFileName = m_apick(2);
  LSB_MSB   = m_apick(3);
  XMC_DEBUG("iFileName is %s\n", iFileName.c_str());
  XMC_DEBUG("oFileName is %s\n", oFileName.c_str());
  XMC_DEBUG("LSB_MSB   is %s\n", LSB_MSB.c_str());

  if( LSB_MSB == "MSB" || LSB_MSB == "msb")
  {
    LSBMSBFlag = 1; // Indicates higher order bits are to come first.
  }
  else
  {
    LSBMSBFlag = 0; // Indicates lower order bits are to come first.
  }


  // Set up the input file header.
  //---------------------------------------------------------------------------------------------
  CPHEADER iHeader;                                           //
  iHeader.file_name    = iFileName;                           //
  iHeader.type_allow   = "1000,2000,3000,5000";               //
  iHeader.format_allow = "SB,CB";                             //
  m_inok(iHeader);                                            //

  // Set up the output file header.
  //---------------------------------------------------------------------------------------------
  CPHEADER oHeader;
  m_propagate(iHeader, oHeader);
  oHeader.file_name = oFileName;
  m_allocate(oHeader);

  // Get the transfer length (BYTES) or transfer samples.  Default to 256k if not present.
  //---------------------------------------------------------------------------------------------
  if(m_get_pswitch("TL"))                     // Test for Transfer length.                      -
  {                                           //                                                -
    xferLngth = m_get_switch("TL");           // Get transfer length (Bytes).                   -
    xferSamps = xferLngth/iHeader.bpe;        // Calculate transfer samples.                    -
  }                                           //                                                -
  else if(m_get_pswitch("TS"))                // Test for Transfer samples.                     -
  {                                           //                                                -
    xferSamps = m_get_switch("TS");           // Get transfer samples.                          -
    xferLngth = xferSamps*iHeader.bpe;        // Convert to transfer length (Bytes).            -
  }                                           //                                                -
  else                                        // Else                                           -
  {                                           //                                                -
    xferLngth = 262144;                       // Default to 256k bytes.                         -
    xferSamps = xferLngth/iHeader.bpe;        // Calculate transfer samples.                    -
  }                                           //-------------------------------------------------
  nGot = xferSamps;
  XMC_DEBUG("nGot        is %d\n", nGot);
  XMC_DEBUG("xferLngth   is %ld\n",xferLngth);
  XMC_DEBUG("xferSamps   is %ld\n",xferSamps);
  XMC_DEBUG("iHeader.bpe is %d\n" ,iHeader.bpe);

  // Set the transfer length variable in the input header.
  //---------------------------------------------------------------------------------------------
  iHeader.xfer_len = xferSamps;
  iHeader.cons_len = -1;

  // Initialize input buffer.
  //---------------------------------------------------------------------------------------------
  iDataINT08 = iccMallocINT08_Align032(xferLngth);
  oDataINT08 = iccMallocINT08_Align032(xferLngth*2);
  iccvZeroINT08( iDataINT08, 1, xferLngth );
  iccvZeroINT08( oDataINT08, 1, xferLngth*2 );
 
  XMC_DEBUG("Done with init.\n");

  // "Synchronize" not "sink".
  //---------------------------------------------------------------------------------------------
  m_sync();
  XMC_DEBUG("Calling m_sync();\n");

  // Processing loop.
  //---------------------------------------------------------------------------------------------
  while((nGot==xferSamps) && !Mc->break_)
  {
    // Grab the new input data.
    //-------------------------------------------------------------------------------------------
    m_grabx(iHeader, iDataINT08, nGot);

    // Perform the conversion.
    //-------------------------------------------------------------------------------------------
    if(!LSBMSBFlag)
    {
      for (ii=0; ii<nGot; ii++)
      {
	oDataINT08[ii*2+0] = iDataINT08[ii]&0x0F;
	oDataINT08[ii*2+1] = (iDataINT08[ii]&0xF0)>>4;
	if (oDataINT08[ii*2+0] > 7) oDataINT08[ii*2+0]=oDataINT08[ii*2+0]-16;
	if (oDataINT08[ii*2+1] > 7) oDataINT08[ii*2+1]=oDataINT08[ii*2+1]-16;
      }
    }
    else
    {
      for (ii=0; ii<nGot; ii++)
      {
	oDataINT08[ii*2+0] = (iDataINT08[ii]&0xF0)>>4;
	oDataINT08[ii*2+1] = iDataINT08[ii]&0x0F;
	if (oDataINT08[ii*2+0] > 7) oDataINT08[ii*2+0]=oDataINT08[ii*2+0]-16;
	if (oDataINT08[ii*2+1] > 7) oDataINT08[ii*2+1]=oDataINT08[ii*2+1]-16;
      }
    }

    // Output the data.
    //-------------------------------------------------------------------------------------------
    m_filad(oHeader, oDataINT08, nGot*2);                        // Write out the zero data.    -

  }

  // Terminate and return.
  //---------------------------------------------------------------------------------------------
  XMC_DEBUG("Terminating\n");
  m_close(iHeader);
  m_close(oHeader);
  xmcFree(iDataINT08);
  xmcFree(oDataINT08);
  XMC_DEBUG("Terminated\n");
}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/*----------------------------------------UNCLASSIFIED-----------------------------------------*/

//    0    0  0000
//    1    1  0001
//    2    2  0010
//    3    3  0011
//    4    4  0100
//    5    5  0101
//    6    6  0110
//    7    7  0111
//    8   -8  1000
//    9   -7  1001
//   10   -6  1010
//   11   -5  1011
//   12   -4  1100
//   13   -3  1101
//   14   -2  1110
//   15   -1  1111
