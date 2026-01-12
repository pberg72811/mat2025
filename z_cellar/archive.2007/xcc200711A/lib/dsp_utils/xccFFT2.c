/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccFFT2.c
// Desc: This file contains the code for the DSPUtils routine xccFFT2.
// Hist: When       Who  What
//       07/27/2001 ptb  Initial Code.
//       03/27/2003 ptb  Cleaned up Code.
//       04/06/2004 ptb  FFT1, FFT2, FFT3.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "dsp_utils.h" 
 
/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
// Rout: xccFFTINT08_R
// Desc: This routine performs a real FFT on INT08 data stream.
//------------------------------------------------------------------------------
VOID xccFFTINT08_R(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  
  xccFFTINT08_X((INT08 *)iData,oData,N,TRUE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: xccFFTINT08_C
// Desc: This routine performs a complex FFT on INT08 data stream.
//------------------------------------------------------------------------------
VOID xccFFTINT08_C(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  xccFFTINT08_X((INT08 *)iData,oData,N,FALSE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: xccFFTINT16_R
// Desc: This routine performs a real FFT on INT16 data stream.
//------------------------------------------------------------------------------
VOID xccFFTINT16_R(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  xccFFTINT16_X((INT16 *)iData,oData,N,TRUE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: xccFFTINT16_C
// Desc: This routine performs a complex FFT on INT16 data stream.
//------------------------------------------------------------------------------
VOID xccFFTINT16_C(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  xccFFTINT16_X((INT16 *)iData,oData,N,FALSE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: xccFFTINT32_R
// Desc: This routine performs a real FFT on INT32 data stream.
//------------------------------------------------------------------------------
VOID xccFFTINT32_R(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  xccFFTINT32_X((INT32 *)iData,oData,N,TRUE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: xccFFTINT32_C
// Desc: This routine performs a complex FFT on INT32 data stream.
//------------------------------------------------------------------------------
VOID xccFFTINT32_C(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  xccFFTINT32_X((INT32 *)iData,oData,N,FALSE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: xccFFTUNT08_R
// Desc: This routine performs a real FFT on UNT08 data stream.
//------------------------------------------------------------------------------
VOID xccFFTUNT08_R(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  xccFFTUNT08_X((UNT08 *)iData,oData,N,TRUE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: xccFFTUNT08_C
// Desc: This routine performs a complex FFT on UNT08 data stream.
//------------------------------------------------------------------------------
VOID xccFFTUNT08_C(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  xccFFTUNT08_X((UNT08 *)iData,oData,N,FALSE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: xccFFTUNT16_R
// Desc: This routine performs a real FFT on UNT16 data stream.
//------------------------------------------------------------------------------
VOID xccFFTUNT16_R(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  xccFFTUNT16_X((UNT16 *)iData,oData,N,TRUE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: xccFFTUNT16_C
// Desc: This routine performs a complex FFT on UNT16 data stream.
//------------------------------------------------------------------------------
VOID xccFFTUNT16_C(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  xccFFTUNT16_X((UNT16 *)iData,oData,N,FALSE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: xccFFTUNT32_R
// Desc: This routine performs a real FFT on UNT32 data stream.
//------------------------------------------------------------------------------
VOID xccFFTUNT32_R(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  xccFFTUNT32_X((UNT32 *)iData,oData,N,TRUE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: xccFFTUNT32_C
// Desc: This routine performs a complex FFT on UNT32 data stream.
//------------------------------------------------------------------------------
VOID xccFFTUNT32_C(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  xccFFTUNT32_X((UNT32 *)iData,oData,N,FALSE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: xccFFTFLT32_R
// Desc: This routine performs a real FFT on FLT32 data stream.
//------------------------------------------------------------------------------
VOID xccFFTFLT32_R(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  xccFFTFLT32_X((FLT32 *)iData,oData,N,TRUE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: xccFFTFLT32_C
// Desc: This routine performs a complex FFT on FLT32 data stream.
//------------------------------------------------------------------------------
VOID xccFFTFLT32_C(VOID  *iData, // Complex Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  xccFFTFLT32_X((FLT32 *)iData,oData,N,FALSE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: xccFFTFLT64_R
// Desc: This routine performs a real FFT on FLT64 data stream.
//------------------------------------------------------------------------------
VOID xccFFTFLT64_R(VOID  *iData, // Real Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  xccFFTFLT64_X((FLT64 *)iData,oData,N,TRUE,FALSE);
}

//------------------------------------------------------------------------------
// Rout: xccFFTFLT64_C
// Desc: This routine performs a complex FFT on FLT64 data stream.
//------------------------------------------------------------------------------
VOID xccFFTFLT64_C(VOID  *iData, // Complex Input.
		   FLT32 *oData, // Complex output.
		   UNT32 N)
{
  xccFFTFLT64_X((FLT64 *)iData,oData,N,FALSE,FALSE);
}


//------------------------------------------------------------------------------
// Rout: xccIFFTINT08_R
// Desc: This routine performs a real IFFT on INT08 data stream.  REAL IFFT?
//------------------------------------------------------------------------------
VOID xccIFFTINT08_R(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  xccFFTINT08_X((INT08 *)iData,oData,N,TRUE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: xccIFFTINT08_C
// Desc: This routine performs a complex IFFT on INT08 data stream.
//------------------------------------------------------------------------------
VOID xccIFFTINT08_C(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  xccFFTINT08_X((INT08 *)iData,oData,N,FALSE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: xccIFFTINT16_R
// Desc: This routine performs a real IFFT on INT16 data stream.  REAL IFFT?
//------------------------------------------------------------------------------
VOID xccIFFTINT16_R(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  xccFFTINT16_X((INT16 *)iData,oData,N,TRUE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: xccIFFTINT16_C
// Desc: This routine performs a complex IFFT on INT16 data stream.
//------------------------------------------------------------------------------
VOID xccIFFTINT16_C(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  xccFFTINT16_X((INT16 *)iData,oData,N,FALSE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: xccIFFTINT32_R
// Desc: This routine performs a real IFFT on INT32 data stream.  REAL IFFT?
//------------------------------------------------------------------------------
VOID xccIFFTINT32_R(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  xccFFTINT32_X((INT32 *)iData,oData,N,TRUE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: xccIFFTINT32_C
// Desc: This routine performs a complex IFFT on INT32 data stream.
//------------------------------------------------------------------------------
VOID xccIFFTINT32_C(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  xccFFTINT32_X((INT32 *)iData,oData,N,FALSE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: xccIFFTUNT08_R
// Desc: This routine performs a real IFFT on UNT08 data stream.  REAL IFFT?
//------------------------------------------------------------------------------
VOID xccIFFTUNT08_R(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  xccFFTUNT08_X((UNT08 *)iData,oData,N,TRUE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: xccIFFTUNT08_C
// Desc: This routine performs a complex IFFT on UNT08 data stream.
//------------------------------------------------------------------------------
VOID xccIFFTUNT08_C(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  xccFFTUNT08_X((UNT08 *)iData,oData,N,FALSE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: xccIFFTUNT16_R
// Desc: This routine performs a real IFFT on UNT16 data stream.  REAL IFFT?
//------------------------------------------------------------------------------
VOID xccIFFTUNT16_R(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  xccFFTUNT16_X((UNT16 *)iData,oData,N,TRUE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: xccIFFTUNT16_C
// Desc: This routine performs a complex IFFT on UNT16 data stream.
//------------------------------------------------------------------------------
VOID xccIFFTUNT16_C(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  xccFFTUNT16_X((UNT16 *)iData,oData,N,FALSE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: xccIFFTUNT32_R
// Desc: This routine performs a real IFFT on UNT32 data stream.  REAL IFFT?
//------------------------------------------------------------------------------
VOID xccIFFTUNT32_R(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  xccFFTUNT32_X((UNT32 *)iData,oData,N,TRUE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: xccIFFTUNT32_C
// Desc: This routine performs a complex IFFT on UNT32 data stream.
//------------------------------------------------------------------------------
VOID xccIFFTUNT32_C(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  xccFFTUNT32_X((UNT32 *)iData,oData,N,FALSE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: xccIFFTFLT32_R
// Desc: This routine performs a real IFFT on FLT32 data stream.  REAL IFFT?
//------------------------------------------------------------------------------
VOID xccIFFTFLT32_R(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  xccFFTFLT32_X((FLT32 *)iData,oData,N,TRUE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: xccIFFTFLT32_C
// Desc: This routine performs a complex IFFT on FLT32 data stream.
//------------------------------------------------------------------------------
VOID xccIFFTFLT32_C(VOID  *iData, // Complex Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  xccFFTFLT32_X((FLT32 *)iData,oData,N,FALSE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: xccIFFTFLT64_R
// Desc: This routine performs a real IFFT on FLT64 data stream.  REAL IFFT?
//------------------------------------------------------------------------------
VOID xccIFFTFLT64_R(VOID  *iData, // Real Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  xccFFTFLT64_X((FLT64 *)iData,oData,N,TRUE,TRUE);
}

//------------------------------------------------------------------------------
// Rout: xccIFFTFLT64_C
// Desc: This routine performs a complex IFFT on FLT64 data stream.
//------------------------------------------------------------------------------
VOID xccIFFTFLT64_C(VOID  *iData, // Complex Input.
		    FLT32 *oData, // Complex output.
		    UNT32 N)
{
  xccFFTFLT64_X((FLT64 *)iData,oData,N,FALSE,TRUE);
}
                        
/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*-------------------------------UNCLASSIFIED---------------------------------*/


