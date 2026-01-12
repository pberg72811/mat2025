/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccJ2.c
// Desc: This file contains the J2 orbit propagation model.
//
// Hist: When       Who  What
//       01/31/2003 ptb  Initial Code.
//       05/16/2006 ptb  SI unit update. (N,Kg,m,sec)
//       05/17/2006 ptb  SI unit update did not work.  Changes made in calling routines.
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include "orbit_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
//#define TINY 0.1
//#define OMEGA  (0.00007292115147167)
#define OMEGA  (0.0)
#define TINY   (1.0e-6)
#define ONE6TH (0.1666666666666667)

/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
VOID J2CGFECI(FLT64  x1,FLT64  x2,FLT64  x3,FLT64  x4,FLT64  x5,FLT64  x6,
	      FLT64 *d1,FLT64 *d2,FLT64 *d3,FLT64 *d4,FLT64 *d5,FLT64 *d6);
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
VOID xccJ2(xccSatData_t *satData, FLT64 dTint)
{
  FLT64 xt1,xi1;
  FLT64 xt2,xi2;
  FLT64 xt3,xi3;
  FLT64 xt4,xi4;
  FLT64 xt5,xi5;
  FLT64 xt6,xi6;
  FLT64 da1,db1,dc1,dd1;
  FLT64 da2,db2,dc2,dd2;
  FLT64 da3,db3,dc3,dd3;
  FLT64 da4,db4,dc4,dd4;
  FLT64 da5,db5,dc5,dd5;
  FLT64 da6,db6,dc6,dd6;
  FLT64 dT,h;

  FLT64 T0   = satData->epochTimeUTC;
  FLT64 TNew = satData->currentTimeUTC;

  // Initialize the state vectors
  //---------------------------------------------------------------------------------------------
  xt1= xi1= satData->x;
  xt2= xi2= satData->y;
  xt3= xi3= satData->z;
  xt4= xi4= satData->xDot;
  xt5= xi5= satData->yDot;
  xt6= xi6= satData->zDot;

  // Calculate and check time values.
  //---------------------------------------------------------------------------------------------
  dT = fabs(TNew - T0);

  if(dT < TINY)
  {
    return;
  }

  if (dT < dTint) 
  {
    h = dT;
  }
  else
  {
    h = dTint;
  }

  if (T0>TNew)
  {
    h = -h; //Allow for backward propagation.
  }

  // Do the processing loop.
  //---------------------------------------------------------------------------------------------
  while(dT>=TINY)
  {

    J2CGFECI( xi1,   xi2,   xi3,   xi4,   xi5,   xi6,
	      &da1,  &da2,  &da3,  &da4,  &da5,  &da6);

    xt1 = xi1+(0.5*h*da1);
    xt2 = xi2+(0.5*h*da2);
    xt3 = xi3+(0.5*h*da3);
    xt4 = xi4+(0.5*h*da4);
    xt5 = xi5+(0.5*h*da5);
    xt6 = xi6+(0.5*h*da6);

    J2CGFECI( xt1,   xt2,   xt3,   xt4,   xt5,   xt6,
	     &db1,  &db2,  &db3,  &db4,  &db5,  &db6);

    xt1 = xi1+(0.5*h*db1);
    xt2 = xi2+(0.5*h*db2);
    xt3 = xi3+(0.5*h*db3);
    xt4 = xi4+(0.5*h*db4);
    xt5 = xi5+(0.5*h*db5);
    xt6 = xi6+(0.5*h*db6);

    J2CGFECI( xt1,   xt2,   xt3,   xt4,   xt5,   xt6,
	     &dc1,  &dc2,  &dc3,  &dc4,  &dc5,  &dc6);

    xt1 = xi1+(h*dc1);
    xt2 = xi2+(h*dc2);
    xt3 = xi3+(h*dc3);
    xt4 = xi4+(h*dc4);
    xt5 = xi5+(h*dc5);
    xt6 = xi6+(h*dc6);
  
    J2CGFECI( xt1,   xt2,   xt3,   xt4,   xt5,   xt6,
	     &dd1,  &dd2,  &dd3,  &dd4,  &dd5,  &dd6);

    xi1 = xi1+( ONE6TH * h * (da1+(2.0*(db1+dc1))+dd1) );
    xi2 = xi2+( ONE6TH * h * (da2+(2.0*(db2+dc2))+dd2) );
    xi3 = xi3+( ONE6TH * h * (da3+(2.0*(db3+dc3))+dd3) );
    xi4 = xi4+( ONE6TH * h * (da4+(2.0*(db4+dc4))+dd4) );
    xi5 = xi5+( ONE6TH * h * (da5+(2.0*(db5+dc5))+dd5) );
    xi6 = xi6+( ONE6TH * h * (da6+(2.0*(db6+dc6))+dd6) );

    T0 = T0 + h;
    
    dT = TNew - T0;

    if(dT<fabs(h))
    {
      h = TNew-T0;
    }
  }

  satData->x    = xi1;
  satData->y    = xi2;
  satData->z    = xi3;
  satData->xDot = xi4;
  satData->yDot = xi5;
  satData->zDot = xi6;
  satData->xDotDot = da4;
  satData->yDotDot = da5;
  satData->zDotDot = da6;
  return;
}

VOID J2CGFECI(FLT64  x1,FLT64  x2,FLT64  x3,FLT64  x4,FLT64  x5,FLT64  x6,
	      FLT64 *d1,FLT64 *d2,FLT64 *d3,FLT64 *d4,FLT64 *d5,FLT64 *d6)
{
  FLT64 R;
  FLT64 R1;
  FLT64 Mur;
  FLT64 Zr;
  FLT64 Xg;
  FLT64 Zg;
  FLT64 xdotdot, ydotdot, zdotdot;

  // Define.
  //---------------------------------------------------------------------------------------------
  R   = sqrt(x1*x1 + x2*x2 + x3*x3);
  Mur = -KEP/(R*R*R);
  R1  = (XKMPER/R)*(XKMPER/R);
  Zr  = (x3/R)*(x3/R);
  Xg  = Mur*(1+J2*R1*(1.5)*(1.0-5.0*Zr));        // Geopotential in the XY plane.
  Zg  = Mur*(1+J2*R1*(1.5)*(3.0-5.0*Zr));        // Geopotential along the Z axis.

  // Compute the accelerations in the X,Y,and Z directions.
  //---------------------------------------------------------------------------------------------
  xdotdot = x1*Xg + x1*OMEGA*OMEGA + 2*x5*OMEGA; // The OMEGAs are 0.0
  ydotdot = x2*Xg + x2*OMEGA*OMEGA + 2*x4*OMEGA; // The OMEGAs are 0.0
  zdotdot = x3*Zg;

  // Compute the position and velocity dfferentials.
  //---------------------------------------------------------------------------------------------
  *d1 = x4;
  *d2 = x5;
  *d3 = x6;
  *d4 = xdotdot;
  *d5 = ydotdot;
  *d6 = zdotdot;
}

/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
