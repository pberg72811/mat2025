/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: sgp4.c
// Desc: This file contains the SGP4 model for orbits.
//
// Hist: When       Who  What
//       08/10/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "orbitUtils.h"

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

/*-------------------------------UNCLASSIFIED---------------------------------*/
// Rout: dint.c
// Desc: sgp4 part two.
// Hist: When       Who  What
//       08/10/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
FLT64 dint(FLT64 x)
{
	if (x >= 0) return floor(x);
	return ceil(x);
}

/*-------------------------------UNCLASSIFIED---------------------------------*/
// Rout: fmod2p.c
// Desc: sgp4 part two.
// Hist: When       Who  What
//       08/10/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
FLT64 fmod2p(FLT64 x)
{
	x /= TWOPI;
	x = (x - dint(x)) * TWOPI;
	if (x < 0)
		x += TWOPI;
	return x;
}

/*-------------------------------UNCLASSIFIED---------------------------------*/
// Rout: sgp4Calc.c
// Desc: sgp4 part two.
// Hist: When       Who  What
//       08/10/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
void sgp4Calc(INT16 IFLAG,
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
FLT64 DS50)
{

FLT64 A1;
FLT64 COSIO;
FLT64 THETA2;
FLT64 X3THM1;
FLT64 EOSQ;
FLT64 BETAO2;
FLT64 BETAO;
FLT64 DEL1;
FLT64 AO;
FLT64 DELO;
FLT64 XNODP;
FLT64 AODP;
INT16 ISIMP;
INT16 ii;
FLT64 PERIGE;
FLT64 S4;
FLT64 QOMS24;
FLT64 PINVSQ;
FLT64 TSI;
FLT64 ETA;
FLT64 ETASQ;
FLT64 EETA;
FLT64 PSISQ;
FLT64 COEF;
FLT64 COEF1;
FLT64 SINIO;
FLT64 A3OVK2;
FLT64 C1;
FLT64 C2;
FLT64 C3;
FLT64 C4;
FLT64 C5;
FLT64 X1MTH2;
FLT64 THETA4;
FLT64 TEMP;
FLT64 TEMP1;
FLT64 TEMP2;
FLT64 TEMP3;
FLT64 TEMP4;
FLT64 TEMP5;
FLT64 TEMP6;
FLT64 XMDOT;
FLT64 X1M5TH;
FLT64 OMGDOT;
FLT64 XHDOT1;
FLT64 XNODOT;
FLT64 OMGCOF;
FLT64 XMCOF;
FLT64 XNODCF;
FLT64 XLCOF;
FLT64 AYCOF;
FLT64 DELMO;
FLT64 SINMO;
FLT64 X7THM1;
FLT64 C1SQ;
FLT64 /*D1,*/ D2, D3, D4;
FLT64 /*T1COF,*/ T2COF, T3COF, T4COF, T5COF;
FLT64 XMDF;
FLT64 OMGADF;
FLT64 XNODDF;
FLT64 OMEGA;
FLT64 XMP;
FLT64 TSQ;
FLT64 XNODE;
FLT64 TEMPA;
FLT64 TEMPE;
FLT64 TEMPL;
FLT64 DELOMG;
FLT64 DELM;
FLT64 TCUBE;
FLT64 TFOUR;
FLT64 A;
FLT64 E;
FLT64 XL;
FLT64 BETA;
FLT64 XN;
FLT64 AXN;
FLT64 XLL;
FLT64 AYNL;
FLT64 XLT;
FLT64 AYN;
FLT64 CAPU;
FLT64 COSEPW;
FLT64 SINEPW;
FLT64 EPW;
FLT64 ECOSE;
FLT64 ESINE;
FLT64 ELSQ;
FLT64 PL;
FLT64 R;
FLT64 RDOT;
FLT64 RFDOT;
FLT64 BETAL;
FLT64 COSU;
FLT64 SINU;
FLT64 U;
FLT64 SIN2U;
FLT64 COS2U;
FLT64 RK;
FLT64 UK;
FLT64 XNODEK;
FLT64 XINCK;
FLT64 RDOTK;
FLT64 RFDOTK;
FLT64 SINUK, COSUK;
FLT64 SINIK, COSIK;
FLT64 SINNOK, COSNOK;
FLT64 XMX;
FLT64 XMY;
FLT64 UX, UY, UZ;
FLT64 VX, VY, VZ;

//mexPrintf("First Time Derivative is  %f\r",XNDT2O);
//mexPrintf("Second Time Derivative is %f\r",XNDD6O);
//mexPrintf("BSTAR drag term is        %f\r",BSTAR);
//mexPrintf("Inclination is            %f\r",XINCL);
//mexPrintf("R.A.A.N is                %f\r",XNODEO);
//mexPrintf("Eccentricity is           %f\r",EO);
//mexPrintf("Argument of Perigee is    %f\r",OMEGAO);
//mexPrintf("Mean Anomally is          %f\r",XMO);
//mexPrintf("Mean Motion is            %f\r",XNO);
//mexPrintf("Time since is             %f\r",TSINCE);

//------------------------------------------------------------------------------
//Not checking IFLAG now.  May want to later.
//------------------------------------------------------------------------------
//if (IFLAG != 0){

//* RECOVER ORIGINAL MEAN MOTION (XNODP) AND SEMIMAJOR AXIS (AODP)
//* FROM INPUT ELEMENTS
//------------------------------------------------------------------------------
A1= pow( (XKE/XNO),TOTHRD );
COSIO=cos(XINCL);
THETA2=COSIO*COSIO;
X3THM1=3.0*THETA2-1.0;
EOSQ=EO*EO;
BETAO2=1.0-EOSQ;
BETAO=sqrt(BETAO2);
DEL1=1.5*CK2*X3THM1/(A1*A1*BETAO*BETAO2);
AO=A1*(1.0-DEL1*(0.5*TOTHRD+DEL1*(1.0+134.0/81.0*DEL1)));
DELO=1.5*CK2*X3THM1/(AO*AO*BETAO*BETAO2);
XNODP=XNO/(1.0+DELO);
AODP=AO/(1.0-DELO);

//* INITIALIZATION
//* FOR PERIGEE LESS THAN 220 KILOMETERS, THE ISIMP FLAG IS SET AND
//* THE EQUATIONS ARE TRUNCATED TO LINEAR VARIATION IN sqrt A AND
//* QUADRATIC VARIATION IN MEAN ANOMALY. ALSO, THE C3 TERM, THE
//* DELTA OMEGA TERM, AND THE DELTA M TERM ARE DROPPED.
//------------------------------------------------------------------------------
if( (AODP*(1.0-EO)/AE) < (220./XKMPER+AE) ) ISIMP=1;
else ISIMP=0;

//* FOR PERIGEE BELOW 156 KM, THE VALUES OF
//* S AND QOMS2T ARE ALTERED
//------------------------------------------------------------------------------
S4=S;
QOMS24=QOMS2T;
PERIGE=(AODP*(1.0-EO)-AE)*XKMPER;
if( PERIGE < 156.0 ){
  if( PERIGE > 98.0)
    S4 = PERIGE - 78.0;
  else
    S4 = 20.0;
  QOMS24=pow( (120.0-S4)*AE/XKMPER, 4.0 );
  S4=S4/XKMPER+AE;
}  


//PERIGE=(AODP*(1.0-EO)-AE)*XKMPER;
//if( PERIGE >= 156.0 ){
//  S4=S;
//  QOMS24=QOMS2T;
//}
//else if( PERIGE > 98.0 ){
//  S4=PERIGE-78.0;
//  QOMS24=pow( (120.0-S4)*AE/XKMPER, 4 );
//  S4=S4/XKMPER+AE;
//}
//else{
//  S4=20.0;
//  QOMS24=pow( (120.0-S4)*AE/XKMPER, 4 );
//  S4=S4/XKMPER+AE;
//}


//S4=S;
//QOMS24=QOMS2T;
//PERIGE=(AODP*(1.-EO)-AE)*XKMPER;
//if(PERIGE >= 156.) GO TO 10
//S4=PERIGE-78.
//IF(PERIGE .GT. 98.) GO TO 9
//S4=20.
//9 QOMS24=((120.-S4)*AE/XKMPER)**4
//S4=S4/XKMPER+AE
//10 PINVSQ=1./(AODP*AODP*BETAO2*BETAO2)

PINVSQ=1.0/(AODP*AODP*BETAO2*BETAO2);
TSI=1.0/(AODP-S4);
ETA=AODP*EO*TSI;
ETASQ=ETA*ETA;
EETA=EO*ETA;
PSISQ=fabs(1.0-ETASQ);
COEF= QOMS24 * pow( TSI, 4);
COEF1= COEF/pow( PSISQ, 3.5 );
C2=COEF1*XNODP*(AODP*(1.0+1.5*ETASQ+EETA*(4.0+ETASQ))+0.75*CK2*TSI/PSISQ*
   X3THM1*(8.0+3.0*ETASQ*(8.0+ETASQ)));
C1=BSTAR*C2;
SINIO=sin(XINCL);
A3OVK2= -XJ3/CK2*pow( AE, 3 );
C3=COEF*TSI*A3OVK2*XNODP*AE*SINIO/EO;
X1MTH2=1.0-THETA2;
C4 = 2.0*XNODP*COEF1*AODP*BETAO2*
     ( 
       ETA * (2.0+0.5*ETASQ) + EO * (0.5+2.0*ETASQ) - 2.0 * CK2 * TSI/
       (AODP*PSISQ) *
       (
         -3.0 * X3THM1 * (1.0 - 2.0 * EETA + ETASQ * (1.5-0.5*EETA)) +
          0.75 * X1MTH2 * (2.0*ETASQ-EETA*(1.0+ETASQ)) * cos(2.0*OMEGAO)
       )
     );
C5=2.0*COEF1*AODP*BETAO2*(1.0+2.75*(ETASQ+EETA)+EETA*ETASQ);
THETA4=THETA2*THETA2;
TEMP1=3.0*CK2*PINVSQ*XNODP;
TEMP2=TEMP1*CK2*PINVSQ;
TEMP3=1.25*CK4*PINVSQ*PINVSQ*XNODP;
XMDOT=XNODP+0.5*TEMP1*BETAO*X3THM1+0.0625*TEMP2*BETAO*
(13.0-78.0*THETA2+137.0*THETA4);
X1M5TH=1.0-5.0*THETA2;
OMGDOT=-0.5*TEMP1*X1M5TH+0.0625*TEMP2*(7.0-114.0*THETA2+
395.0*THETA4)+TEMP3*(3.0-36.0*THETA2+49.0*THETA4);
XHDOT1=-TEMP1*COSIO;
XNODOT=XHDOT1+(0.5*TEMP2*(4.0-19.0*THETA2)+2.0*TEMP3*(3.0-7.0*THETA2))*COSIO;
OMGCOF=BSTAR*C3*cos(OMEGAO);
XMCOF=-TOTHRD*COEF*BSTAR*AE/EETA;
XNODCF=3.5*BETAO2*XHDOT1*C1;
T2COF=1.5*C1;
XLCOF=0.125*A3OVK2*SINIO*(3.0+5.0*COSIO)/(1.0+COSIO);
AYCOF=0.25*A3OVK2*SINIO;
DELMO=pow( (1.0+ETA*cos(XMO)), 3.0);
SINMO=sin(XMO);
X7THM1=7.0*THETA2-1.0;
if(!ISIMP){
  C1SQ=C1*C1;
  D2=4.0*AODP*TSI*C1SQ;
  TEMP=D2*TSI*C1/3.0;
  D3=(17.0*AODP+S4)*TEMP;
  D4=0.5*TEMP*AODP*TSI*(221.0*AODP+31.0*S4)*C1;
  T3COF=D2+2.*C1SQ;
  T4COF=0.25*(3.0*D3+C1*(12.0*D2+10.0*C1SQ));
  T5COF=0.2*(3.0*D4+12.0*C1*D3+6.*D2*D2+15.0*C1SQ*(2.0*D2+C1SQ));
}

//end if IFLAG

//* UPDATE FOR SECULAR GRAVITY AND ATMOSPHERIC DRAG
//------------------------------------------------------------------------------
XMDF=XMO+XMDOT*TSINCE;
OMGADF=OMEGAO+OMGDOT*TSINCE;
XNODDF=XNODEO+XNODOT*TSINCE;
OMEGA=OMGADF;
XMP=XMDF;
TSQ=TSINCE*TSINCE;
XNODE=XNODDF+XNODCF*TSQ;
TEMPA=1.-C1*TSINCE;
TEMPE=BSTAR*C4*TSINCE;
TEMPL=T2COF*TSQ;
if(!ISIMP){
  DELOMG=OMGCOF*TSINCE;
  DELM=XMCOF * ( pow(1.0+ETA*cos(XMDF), 3.0) - DELMO );
  TEMP=DELOMG+DELM;
  XMP=XMDF+TEMP;
  OMEGA=OMGADF-TEMP;
  TCUBE=TSQ*TSINCE;
  TFOUR=TSINCE*TCUBE;
  TEMPA=TEMPA-D2*TSQ-D3*TCUBE-D4*TFOUR;
  TEMPE=TEMPE+BSTAR*C5*(sin(XMP)-SINMO);
  TEMPL=TEMPL+T3COF*TCUBE+TFOUR*(T4COF+TSINCE*T5COF);
}
A= AODP * TEMPA * TEMPA;
E=EO-TEMPE;
XL=XMP+OMEGA+XNODE+XNODP*TEMPL;
BETA=sqrt(1.0-E*E);
XN= XKE / pow(A, 1.5);

//* LONG PERIOD PERIODICS
//------------------------------------------------------------------------------
AXN=E*cos(OMEGA);
TEMP=1./(A*BETA*BETA);
XLL=TEMP*XLCOF*AXN;
AYNL=TEMP*AYCOF;
XLT=XL+XLL;
AYN=E*sin(OMEGA)+AYNL;

//* SOLVE KEPLERS EQUATION
//------------------------------------------------------------------------------
CAPU=fmod2p(XLT-XNODE);
TEMP2=CAPU;
for( ii = -10; ii; ii++){
  SINEPW=sin(TEMP2);
  COSEPW=cos(TEMP2);
  TEMP3=AXN*SINEPW;
  TEMP4=AYN*COSEPW;
  TEMP5=AXN*COSEPW;
  TEMP6=AYN*SINEPW;
  EPW=(CAPU-TEMP4+TEMP3-TEMP2)/(1.-TEMP5-TEMP6)+TEMP2;
  if( fabs(EPW-TEMP2) <= E6A) break; //break out of loop;
  TEMP2=EPW;
}

//* SHORT PERIOD PRELIMINARY QUANTITIES
//------------------------------------------------------------------------------
ECOSE=TEMP5+TEMP6;
ESINE=TEMP3-TEMP4;
ELSQ=AXN*AXN+AYN*AYN;
TEMP=1.0-ELSQ;
PL=A*TEMP;
R=A*(1.0-ECOSE);
TEMP1=1.0/R;
RDOT=XKE*sqrt(A)*ESINE*TEMP1;
RFDOT=XKE*sqrt(PL)*TEMP1;
TEMP2=A*TEMP1;
BETAL=sqrt(TEMP);
TEMP3=1.0/(1.0+BETAL);
COSU=TEMP2*(COSEPW-AXN+AYN*ESINE*TEMP3);
SINU=TEMP2*(SINEPW-AYN-AXN*ESINE*TEMP3);
U=atan2(SINU,COSU);
SIN2U=2.0*SINU*COSU;
COS2U=2.0*COSU*COSU-1.0;
TEMP=1.0/PL;
TEMP1=CK2*TEMP;
TEMP2=TEMP1*TEMP;

//* UPDATE FOR SHORT PERIODICS
//------------------------------------------------------------------------------
RK=R*(1.0-1.5*TEMP2*BETAL*X3THM1)+0.5*TEMP1*X1MTH2*COS2U;
UK=U-0.25*TEMP2*X7THM1*SIN2U;
XNODEK=XNODE+1.5*TEMP2*COSIO*SIN2U;
XINCK=XINCL+1.5*TEMP2*COSIO*SINIO*COS2U;
RDOTK=RDOT-XN*TEMP1*X1MTH2*SIN2U;
RFDOTK=RFDOT+XN*TEMP1*(X1MTH2*COS2U+1.5*X3THM1);

//* ORIENTATION VECTORS
//------------------------------------------------------------------------------
SINUK=sin(UK);
COSUK=cos(UK);
SINIK=sin(XINCK);
COSIK=cos(XINCK);
SINNOK=sin(XNODEK);
COSNOK=cos(XNODEK);
XMX=-SINNOK*COSIK;
XMY=COSNOK*COSIK;
UX=XMX*SINUK+COSNOK*COSUK;
UY=XMY*SINUK+SINNOK*COSUK;
UZ=SINIK*SINUK;
VX=XMX*COSUK-COSNOK*SINUK;
VY=XMY*COSUK-SINNOK*SINUK;
VZ=SINIK*COSUK;

//* POSITION AND VELOCITY
//------------------------------------------------------------------------------
*p2X=RK*UX;
*p2Y=RK*UY;
*p2Z=RK*UZ;
*p2XDOT=RDOTK*UX+RFDOTK*VX;
*p2YDOT=RDOTK*UY+RFDOTK*VY;
*p2ZDOT=RDOTK*UZ+RFDOTK*VZ;
//RETURN
//END
}//end function


/*==================================================================*/


/*-------------------------------UNCLASSIFIED---------------------------------*/
// Rout: sgp4Calc.c
// Desc: sgp4 part two.
// Hist: When       Who  What
//       08/10/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
VOID sgp4( FLT64 XNDT2O, //First Time Derivative
           FLT64 XNDD6O, //Second Time Derivative
           FLT64 BSTAR , //BSTAR drag term
           FLT64 XINCL , //Inclination
           FLT64 XNODEO, //Right ascension of ascending node
           FLT64 EO    , //Eccentricity
           FLT64 OMEGAO, //Argument of Perigee
           FLT64 XMO   , //Mean Anomally
           FLT64 XNO   , //Mean Motion
           FLT64 TS    , //Time since in minutes.
           FLT64 *p2X    , //X position
           FLT64 *p2Y    , //Y position
           FLT64 *p2Z    , //Z position
           FLT64 *p2XDOT , //X velocity
           FLT64 *p2YDOT , //Y velocity
           FLT64 *p2ZDOT)  //Z velocity
{
FLT64 DS50;
FLT64 TEMP;
FLT64 AO;
FLT64 A1;
FLT64 DELO;
FLT64 DEL1;
FLT64 XNODP;
FLT64 TSINCE;
INT16 IDEEP = 0;
INT16 IFLAG = 0;

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
//mexPrintf("First Time Derivative is  %f\r",XNDT2O);
//mexPrintf("Second Time Derivative is %f\r",XNDD6O);
//mexPrintf("BSTAR drag term is        %f\r",BSTAR);
//mexPrintf("Inclination is            %f\r",XINCL);
//mexPrintf("R.A.A.N is                %f\r",XNODEO);
//mexPrintf("Eccentricity is           %f\r",EO);
//mexPrintf("Argument of Perigee is    %f\r",OMEGAO);
//mexPrintf("Mean Anomally is          %f\r",XMO);
//mexPrintf("Mean Motion is            %f\r",XNO);
//mexPrintf("Time since is             %f\r",TS);

//No need for exponent attachment ->  XNDD6O=XNDD6O*(10.**IEXP)
XNODEO=XNODEO*DE2RA;
OMEGAO=OMEGAO*DE2RA;
XMO=XMO*DE2RA;
XINCL=XINCL*DE2RA;
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
 sgp4Calc(IFLAG,
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
 DS50);
}
