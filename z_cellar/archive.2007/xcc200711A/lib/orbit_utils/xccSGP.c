/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: sgp.c
// Desc: This file contains the SGP orbit propagation model.
//
// Hist: When       Who  What
//       08/10/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "orbit_utils.h"

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
void sgpCalc(INT16 IFLAG,
	     FLT64 TSINCE,
	     FLT64 XMO,
	     FLT64 XNODEO,
	     FLT64 OMEGAO,
	     FLT64 EO,
	     FLT64 XINCL,
	     FLT64 XNO,
	     FLT64 XNDT2O,
	     FLT64 XNDD6O,
	     FLT64 BSTAR,
	     FLT64 *p2X,
	     FLT64 *p2Y,
	     FLT64 *p2Z,
	     FLT64 *p2XDOT,
	     FLT64 *p2YDOT,
	     FLT64 *p2ZDOT,
	     FLT64 DS5O)
{

FLT64 C1, C2, C3, C4, C5, C6;
FLT64 COSIO, SINIO;
FLT64 A1, AO;
FLT64 D1 /*,DO*/;
FLT64 PO;
FLT64 XLO;
FLT64 D1O, D2O, D3O, D4O;
FLT64 QpO;
FLT64 PO2NO;
FLT64 OMGDT;
FLT64 XNODOT;
FLT64 A;
FLT64 E;
FLT64 P;
FLT64 XNODES;
FLT64 OMGAS;
FLT64 XLS;
FLT64 AXNSL;
FLT64 AYNSL;
FLT64 XL;
FLT64 U;
FLT64 ITEM3;
FLT64 EO1;
FLT64 TEM2,TEM5;
FLT64 SINEO1, COSEO1;
FLT64 ECOSE, ESINE;
FLT64 EL2;
FLT64 PL, PL2;
FLT64 R;
FLT64 RDOT;
FLT64 RVDOT;
FLT64 TEMP;
FLT64 SINU, COSU, SIN2U, COS2U;
FLT64 SU;
FLT64 RK;
FLT64 XNODEK;
FLT64 XINCK;
FLT64 SINUK, COSUK;
FLT64 UK;
FLT64 SINNOK, COSNOK;
FLT64 SINIK, COSIK;
FLT64 XMX, XMY;
FLT64 UX, UY, UZ;
FLT64 VX, VY, VZ;

//* INITIALIZATION
C1= CK2*1.5;
C2= CK2/4.0;
C3= CK2/2.0;
C4= XJ3*pow(AE,3)/(4.0*CK2);
COSIO=cos(XINCL);
SINIO=sin(XINCL);
A1=pow( (XKE/XNO), TOTHRD );
D1= C1/A1/A1*(3.0*COSIO*COSIO-1.0)/pow( (1.0-EO*EO),1.5);
AO=A1*(1.0-1.0/3.0*D1-D1*D1-134.0/81.0*D1*D1*D1);
PO=AO*(1.0-EO*EO);
QpO=AO*(1.0-EO);
XLO=XMO+OMEGAO+XNODEO;
D1O= C3 *SINIO*SINIO;
D2O= C2 *(7.*COSIO*COSIO-1.);
D3O=C1*COSIO;
D4O=D3O*SINIO;
PO2NO=XNO/(PO*PO);
OMGDT=C1*PO2NO*(5.*COSIO*COSIO-1.);
XNODOT=-2.*D3O*PO2NO;
C5=.5*C4*SINIO*(3.+5.*COSIO)/(1.+COSIO);
C6=C4*SINIO;
IFLAG=0;

//* UPDATE FOR SECULAR GRAVITY AND ATMOSPHERIC DRAG
//------------------------------------------------------------------------------
A=XNO+(2.*XNDT2O+3.*XNDD6O*TSINCE)*TSINCE;
A=AO*pow((XNO/A),TOTHRD);
E=E6A;
if(A > QpO) E=1.0-QpO/A;
P=A*(1.-E*E);
XNODES= XNODEO+XNODOT*TSINCE;
OMGAS= OMEGAO+OMGDT*TSINCE;
XLS=fmod(XLO+(XNO+OMGDT+XNODOT+(XNDT2O+XNDD6O*TSINCE)*TSINCE)*TSINCE, TWOPI);

//* LONG PERIOD PERIODICS
//------------------------------------------------------------------------------
AXNSL=E*cos(OMGAS);
AYNSL=E*sin(OMGAS)-C6/P;
XL=fmod(XLS-C5/P*AXNSL, TWOPI);

//* SOLVE KEPLERS EQUATION
//------------------------------------------------------------------------------
U=fmod(XL-XNODES, TWOPI);
ITEM3=0;
EO1=U;
TEM5=1.0;

while ( (fabs(TEM5)>=E6A) || (ITEM3<10.0) )
{
  SINEO1=sin(EO1);
  COSEO1=cos(EO1);
  ITEM3=ITEM3+1.0;
  TEM5=1.0-COSEO1*AXNSL-SINEO1*AYNSL;
  TEM5=(U-AYNSL*COSEO1+AXNSL*SINEO1-EO1)/TEM5;
  TEM2=fabs(TEM5);
  if(TEM2 > 1.0) TEM5=TEM2/TEM5;
  EO1=EO1+TEM5;
}//end while

  
//------------------------------------------------------------------------------
// \/ \/ \/ \/ \/ \/ \/ TAKEN OUT OF ORIGINAL CODE \/ \/ \/ \/ \/ \/ \/
//                      REPLACED BY ABOVE CODE
//------------------------------------------------------------------------------
//20 SINEO1=sin(EO1)
//COSEO1=cos(EO1)
//IF(ABS(TEM5).LT.E6A) GO TO 30
//IF(ITEM3.GE.10) GO TO 30
//ITEM3=ITEM3+1
//TEM5=1.-COSEO1*AXNSL-SINEO1*AYNSL
//TEM5=(U-AYNSL*COSEO1+AXNSL*SINEO1-EO1)/TEM5
//TEM2=ABS(TEM5)
//IF(TEM2.GT.1.) TEM5=TEM2/TEM5
//EO1=EO1+TEM5
//GO TO 20
//------------------------------------------------------------------------------
// /| /| /| /| /| /| /| TAKEN OUT OF ORIGINAL CODE /| /| /| /| /| /| /|
//------------------------------------------------------------------------------

//* SHORT PERIOD PRELIMINARY QUANTITIES
//------------------------------------------------------------------------------
ECOSE = AXNSL*COSEO1 + AYNSL*SINEO1;
ESINE = AXNSL*SINEO1 - AYNSL*COSEO1;
EL2 = AXNSL*AXNSL + AYNSL*AYNSL;
PL = A*(1.0-EL2);
PL2 = PL*PL;
R = A*(1.0-ECOSE);
RDOT = XKE*sqrt(A)/R*ESINE;
RVDOT = XKE*sqrt(PL)/R;
TEMP = ESINE/(1.0 + sqrt(1.-EL2));
SINU = A/R*(SINEO1 - AYNSL - AXNSL*TEMP);
COSU = A/R*(COSEO1 - AXNSL + AYNSL*TEMP);
SU = atan2(SINU,COSU);

//* UPDATE FOR SHORT PERIODICS
//------------------------------------------------------------------------------
SIN2U = (COSU+COSU)*SINU;
COS2U = 1.0 - 2.0*SINU*SINU;
RK = R + D1O/PL*COS2U;
UK = SU - D2O/PL2*SIN2U;
XNODEK = XNODES + D3O*SIN2U/PL2;
XINCK = XINCL + D4O/PL2*COS2U;

//* ORIENTATION VECTORS
//------------------------------------------------------------------------------
SINUK  = sin(UK);
COSUK  = cos(UK);
SINNOK = sin(XNODEK);
COSNOK = cos(XNODEK);
SINIK  = sin(XINCK);
COSIK  = cos(XINCK);
XMX = -SINNOK * COSIK;
XMY = COSNOK * COSIK;
UX = XMX * SINUK + COSNOK * COSUK;
UY = XMY * SINUK + SINNOK * COSUK;
UZ = SINIK * SINUK;
VX = XMX * COSUK - COSNOK * SINUK;
VY = XMY * COSUK - SINNOK * SINUK;
VZ = SINIK * COSUK;

//* POSITION AND VELOCITY
//------------------------------------------------------------------------------
*p2X = RK * UX;
*p2Y = RK * UY;
*p2Z = RK * UZ;

*p2XDOT = RDOT * UX;
*p2YDOT = RDOT * UY;
*p2ZDOT = RDOT * UZ;

*p2XDOT = RVDOT * VX + *p2XDOT;
*p2YDOT = RVDOT * VY + *p2YDOT;
*p2ZDOT = RVDOT * VZ + *p2ZDOT;
//RETURN
//END
}//end fucntion

/*-------------------------------UNCLASSIFIED---------------------------------*/
// Rout: xccSGP.c
// Desc: sgp.
// Hist: When       Who  What
//       08/10/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
VOID xccSGP( FLT64 XNDT2O,  //First Time Derivative
             FLT64 XNDD6O,  //Second Time Derivative
             FLT64 BSTAR,   //BSTAR drag term
             FLT64 XINCL,   //Inclination
             FLT64 XNODEO,  //Right ascension of ascending node
             FLT64 EO,      //Eccentricity
             FLT64 OMEGAO,  //Argument of Perigee
             FLT64 XMO,     //Mean Anomaly
             FLT64 XNO,     //Mean Motion
             FLT64 TS,      //Time since in minutes
             FLT64 *p2X,    //X position
             FLT64 *p2Y,    //Y position
             FLT64 *p2Z,    //Z position
             FLT64 *p2XDOT, //X velocity
             FLT64 *p2YDOT, //Y velocity
             FLT64 *p2ZDOT) //Z velocity
{
FLT64 DS5O;
//------------------------------------------------------------------------------
// \/ \/ \/ \/ \/ \/ \/ TAKEN OUT OF ORIGINAL CODE \/ \/ \/ \/ \/ \/ \/
//------------------------------------------------------------------------------
//FLT64 CK2;
//FLT64 CK4;
//FLT64 QOMS2T;
//FLT64 S;
//------------------------------------------------------------------------------
// /| /| /| /| /| /| /| TAKEN OUT OF ORIGINAL CODE /| /| /| /| /| /| /|
//------------------------------------------------------------------------------

FLT64 TEMP;
FLT64 AO;
FLT64 A1;
FLT64 DELO;
FLT64 DEL1;
FLT64 XNODP;
FLT64 TSINCE;
INT16 IDEEP = 0;
INT16 IFLAG = 0;

//------------------------------------------------------------------------------
// \/ \/ \/ \/ \/ \/ \/ TAKEN OUT OF ORIGINAL CODE \/ \/ \/ \/ \/ \/ \/
//------------------------------------------------------------------------------
//CK2 = 0.5 * XJ2 * (AE*AE);
//CK4 = -0.375 * XJ4 * pow(AE,4);
//QOMS2T = pow( (QO-SO)*AE/XKMPER, 4);
//S = AE * (1.+SO/XKMPER);

//IEPT is which model to use
//TS   is time since
//TF   is time to Finish
//DELT is time steps.
//2 READ (5,700) IEPT, TS,TF,DELT
//IF(IEPT.LE.0) STOP
//IDEEP=0


//No need for exponent attachment ->  XNDD6O=XNDD6O*(10.**IEXP)
//XNODEO=XNODEO*DE2RA;
//OMEGAO=OMEGAO*DE2RA;
//XMO=XMO*DE2RA;
//XINCL=XINCL*DE2RA;
//------------------------------------------------------------------------------
// /| /| /| /| /| /| /| TAKEN OUT OF ORIGINAL CODE /| /| /| /| /| /| /|
//------------------------------------------------------------------------------
TEMP=TWOPI/XMNPDA/XMNPDA;
XNO=XNO*TEMP*XMNPDA;
XNDT2O=XNDT2O*TEMP;
XNDD6O=XNDD6O*TEMP/XMNPDA;

//------------------------------------------------------------------------------
//INPUT CHECK FOR PERIOD VS EPHEMERIS SELECTED
//PERIOD GE 225 MINUTES IS DEEP SPACE
//------------------------------------------------------------------------------
A1= pow( (XKE/XNO),TOTHRD);
TEMP = 1.5*CK2*(3.*cos(XINCL)*cos(XINCL)-1.)/( pow(1.0-EO*EO,1.5));
DEL1=TEMP/(A1*A1);
AO=A1*(1.-DEL1*(.5*TOTHRD+DEL1*(1.+134./81.*DEL1)));
DELO=TEMP/(AO*AO);
XNODP=XNO/(1.+DELO);
if( (TWOPI/XNODP/XMNPDA) >= 0.15625) IDEEP=1;
//No need for exponent attachment ->  BSTAR=BSTAR*(10.**IBEXP)/AE
TSINCE=TS;
IFLAG=1;

//------------------------------------------------------------------------------
/* !!!!!!!!!!  SGP gets called here !!!!!!!!!!!!!!! */
//------------------------------------------------------------------------------
 sgpCalc(IFLAG,
 TSINCE,
 XMO,
 XNODEO,
 OMEGAO,
 EO,
 XINCL,
 XNO,
 XNDT2O,
 XNDD6O,
 BSTAR,
 p2X,
 p2Y,
 p2Z,
 p2XDOT,
 p2YDOT,
 p2ZDOT,
 DS5O);

}
