//-----------------------------------------UNCLASSIFIED-------------------------------------------
// File: mexVMul.c
//
// Desc: Mex function to multiply to vectors.
//
// Hist: When       Who  What
//       10/25/2025 ptb  Initial version.
//------------------------------------------------------------------------------------------------
#include "mex.h"
#include "xcc.h"
#include <string.h>

void mexFunction (int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  RFLT64 x;
  RINT08 y;

  if (nrhs == 2)
  {
    mwSize rows = mxGetM(prhs[0]);
    mwSize cols = mxGetN(prhs[0]);
    const char    *className;
    className = mxGetClassName(prhs[0]);
    printf("data type arg1 %s\n",className);
    printf("number of rows %d\n", rows);
    printf("number of cols %d\n", cols);
    printf("Number of right hand statements is: %d\n", nrhs);
    printf("Number of left  hand statements is: %d\n", nlhs);
  }
  else
  {
    return();
  }

    

  printf("Size of RINT08  is %ld\n",  sizeof(RINT08));
  printf("Size of RINT16  is %ld\n",  sizeof(RINT16));
  printf("Size of RINT32  is %ld\n",  sizeof(RINT32));
  printf("Size of RINT64  is %ld\n",  sizeof(RINT64));
  printf("Size of RFLT32  is %ld\n",  sizeof(RFLT32));
  printf("Size of RFLT64  is %ld\n",  sizeof(RFLT64));
  printf("Size of RFLT128 is %ld\n", sizeof(RFLT128));
}