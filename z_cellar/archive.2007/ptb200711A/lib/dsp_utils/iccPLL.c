/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvPLL.c
// Desc: This file contains the code for the iccvPLL.
// Hist: When       Who  What
//       08/16/2002 ptb  Initial Code.
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
#define COEF1 (+0.09996780000)
#define COEF2 (-0.73929610143)

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccvPLLFLT32(FLT32 *a, INT32 i, FLT32 *b, INT32 j, INT32 n, FLT32 fc, FLT32 fs )
{
  FLT32 uf  = TWOPI*fc/fs;
  FLT32 ud  = 0.0;
  FLT32 phi = 0.0;
  FLT32 xv0 = 0.0;
  FLT32 xv1 = 0.0;
  INT32 ii;

  for( ii = 0; ii < n; ii++)
  {
    phi = phi + uf;
    while(phi<-PI) phi = phi + TWOPI;
    while(phi>+PI) phi = phi - TWOPI;
    ud  = a[ii]*sin(phi);     // Mix input and NCO.
    xv0 = xv1;                // Filter, NCO combination.
    xv1 = COEF1*ud;           //
    uf  = uf+(xv1+COEF2*xv0); //
    b[ii]=sin(phi);           // Output.
  }
}

VOID iccvPLL2FLT32(FLT32 *a, FLT32 *valid, FLT32 *b, INT32 n, FLT32 *phi, FLT32 *delta )
{
  //FLT32 *delta  = TWOPI*fc/fs;
  FLT32 ud  = 0.0;
  //FLT32 *phi = 0.0;
  FLT32 xv0 = 0.0;
  FLT32 xv1 = 0.0;
  INT32 ii;

  for( ii = 0; ii < n; ii++)
  {
    *phi = *phi + *delta;
    while(*phi<-PI) *phi = *phi + TWOPI;
    while(*phi>+PI) *phi = *phi - TWOPI;
    if(valid[ii]) ud  = a[ii]*sin(*phi);     // Mix input and NCO.
    else          ud  = sin(*phi)*sin(*phi); // Mix input and NCO.
    xv0 = xv1;                               // Filter, NCO combination.
    xv1 = COEF1*ud;                          //
    *delta  = *delta+(xv1+COEF2*xv0);        //
    b[ii]=sin(*phi);                         // Output.
  }
}

VOID iccvPLLFLT64(FLT64 *a, INT32 i, FLT64 *b, INT32 j, INT32 n, FLT64 fc, FLT64 fs )
{
  FLT64 uf  = TWOPI*fc/fs;
  FLT64 ud  = 0.0;
  FLT64 phi = 0.0;
  FLT64 xv0 = 0.0;
  FLT64 xv1 = 0.0;
  INT32 ii;

  for( ii = 0; ii < n; ii++)
  {
    phi = phi + uf;
    while(phi<-PI) phi = phi + TWOPI;
    while(phi>+PI) phi = phi - TWOPI;
    ud  = a[ii]*sin(phi);     // Mix input and NCO.
    xv0 = xv1;                // Filter, NCO combination.
    xv1 = COEF1*ud;           //
    uf  = uf+(xv1+COEF2*xv0); //
    b[ii]=sin(phi);           // Output.
  }
}

VOID iccvPLLFLT96(FLT96 *a, INT32 i, FLT96 *b, INT32 j, INT32 n, FLT96 fc, FLT96 fs )
{
  FLT96 uf  = TWOPI*fc/fs;
  FLT96 ud  = 0.0;
  FLT96 phi = 0.0;
  FLT96 xv0 = 0.0;
  FLT96 xv1 = 0.0;
  INT32 ii;

  for( ii = 0; ii < n; ii++)
  {
    phi = phi + uf;
    while(phi<-PI) phi = phi + TWOPI;
    while(phi>+PI) phi = phi - TWOPI;
    ud  = a[ii]*sin(phi);     // Mix input and NCO.
    xv0 = xv1;                // Filter, NCO combination.
    xv1 = COEF1*ud;           //
    uf  = uf+(xv1+COEF2*xv0); //
    b[ii]=sin(phi);           // Output.
  }
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
