//-----------------------------------------UNCLASSIFIED-------------------------------------------
// File: geodetic2ecf_.cc
//
// Desc: Mex function to convert from latitude, longitude, altitude to Earth centered Earth Fixed
//       coordinates.
//
// Note: mkoctfile -I$IEXHOME/xpp/inc --mex geodetic2ecf_.cc
//
// Hist: When       Who  What
//       10/11/2021 ptb  Initial version.
//------------------------------------------------------------------------------------------------
#include "mex.h"
#include <xpp.hh>
#include <xppQTM.hh>
#include <xppDEBUG.hh>
#include <xppDataTypes.hh>

void mexFunction (int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  xpp::RFLT64 x;
  xpp::RFLT64 y;
  xpp::RFLT64 z;

	//----------------------------------------------------------------------------------------------
	if (nrhs != 3)
	{
		mexErrMsgTxt ("Three input  arguments are needed by geodetic2ecf_.cc\n");
	}
  
	if (nlhs != 3)
	{
		mexErrMsgTxt ("Three output arguments are needed by geodetic2ecf_.cc\n");
	}
  
	//----------------------------------------------------------------------------------------------
	xpp::DEBUG DB (__FILE__);

	xpp::QTM QTMTest (9);
  //                     LAT                 LON                 ALT
	QTMTest.geodetic2ecf ( *mxGetPr (prhs[0]), *mxGetPr (prhs[1]), *mxGetPr (prhs[2]), &x, &y, &z );
  
	mwSize dims[2] = { 1, 1 };
	plhs[0] = mxCreateNumericArray (2, dims, mxDOUBLE_CLASS, mxREAL);
	plhs[1] = mxCreateNumericArray (2, dims, mxDOUBLE_CLASS, mxREAL);
	plhs[2] = mxCreateNumericArray (2, dims, mxDOUBLE_CLASS, mxREAL);
  
  xpp::RFLT64 *plhs_x = mxGetPr (plhs[0]);
  xpp::RFLT64 *plhs_y = mxGetPr (plhs[1]);
  xpp::RFLT64 *plhs_z = mxGetPr (plhs[2]);
  *plhs_x = x;
  *plhs_y = y;
  *plhs_z = z;

}

// xpp::DEBUG DB (__FILE__);
// DB.MESSAGE (__LINE__, "Chip number %04d is %d.\n", ii, prnObject.getChipB0 (ii));
// DB.MESSAGE (__LINE__, "Code size is %u.\n", prnObject.getCodeLength ());
