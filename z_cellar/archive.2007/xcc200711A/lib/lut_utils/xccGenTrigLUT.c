/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccGenTrigLUT.c
// Desc: This file contains the code for the lookup table xccGenTrigLUT.
// Hist: When       Who  What
//       02/28/2005 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "lut_utils.h" 
 
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
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS  FLT64 delta=TWOPI/(FLT64)size;
PERL_PREPROCESS  xccLUTSpecXXXXX *spec;
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the spec.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec = (xccLUTSpecXXXXX *) xccMallocVOID_Align032(sizeof(xccLUTSpecXXXXX));
PERL_PREPROCESS
PERL_PREPROCESS  spec->table= (XXXXX *) xccMallocXXXXX_Align032(size);
PERL_PREPROCESS
PERL_PREPROCESS  // Initialize the spec.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  sprintf(spec->name,"YYYYY Lookup table (LUTXXXXX)");
PERL_PREPROCESS  spec->size = size;
PERL_PREPROCESS  for(ii=0; ii<size; ii++) spec->table[ii] = YYYYY(delta*ii);
PERL_PREPROCESS  
PERL_PREPROCESS  return spec;
#endif


xccLUTSpecFLT32 *xccGenSinLUTFLT32(UNT32 size)
{
//------------------------------- COMMON-CODE FLT32 sinf   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT32 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT32 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT32));

  spec->table= (FLT32 *) xccMallocFLT32_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"sinf Lookup table (LUTFLT32)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = sinf(delta*ii);
  
  return spec;
//------------------------------- COMMON-CODE FLT32 sinf    STOP.
}

xccLUTSpecFLT64 *xccGenSinLUTFLT64(UNT32 size)
{
//------------------------------- COMMON-CODE FLT64 sin   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT64 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT64 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT64));

  spec->table= (FLT64 *) xccMallocFLT64_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"sin Lookup table (LUTFLT64)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = sin(delta*ii);
  
  return spec;
//------------------------------- COMMON-CODE FLT64 sin    STOP.
}

xccLUTSpecFLT96 *xccGenSinLUTFLT96(UNT32 size)
{
//------------------------------- COMMON-CODE FLT96 sinl   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT96 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT96 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT96));

  spec->table= (FLT96 *) xccMallocFLT96_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"sinl Lookup table (LUTFLT96)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = sinl(delta*ii);
  
  return spec;
//------------------------------- COMMON-CODE FLT96 sinl    STOP.
}

xccLUTSpecFLT32 *xccGenASinLUTFLT32(UNT32 size)
{
//------------------------------- COMMON-CODE FLT32 asinf   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT32 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT32 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT32));

  spec->table= (FLT32 *) xccMallocFLT32_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"asinf Lookup table (LUTFLT32)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = asinf(delta*ii);
  
  return spec;
//------------------------------- COMMON-CODE FLT32 asinf    STOP.
}

xccLUTSpecFLT64 *xccGenASinLUTFLT64(UNT32 size)
{
//------------------------------- COMMON-CODE FLT64 asin   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT64 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT64 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT64));

  spec->table= (FLT64 *) xccMallocFLT64_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"asin Lookup table (LUTFLT64)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = asin(delta*ii);
  
  return spec;
//------------------------------- COMMON-CODE FLT64 asin    STOP.
}

xccLUTSpecFLT96 *xccGenASinLUTFLT96(UNT32 size)
{
//------------------------------- COMMON-CODE FLT96 asinl   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT96 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT96 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT96));

  spec->table= (FLT96 *) xccMallocFLT96_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"asinl Lookup table (LUTFLT96)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = asinl(delta*ii);
  
  return spec;
//------------------------------- COMMON-CODE FLT96 asinl    STOP.
}

xccLUTSpecFLT32 *xccGenCosLUTFLT32(UNT32 size)
{
//------------------------------- COMMON-CODE FLT32 cosf   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT32 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT32 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT32));

  spec->table= (FLT32 *) xccMallocFLT32_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"cosf Lookup table (LUTFLT32)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = cosf(delta*ii);
  
  return spec;
//------------------------------- COMMON-CODE FLT32 cosf    STOP.
}

xccLUTSpecFLT64 *xccGenCosLUTFLT64(UNT32 size)
{
//------------------------------- COMMON-CODE FLT64 cos   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT64 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT64 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT64));

  spec->table= (FLT64 *) xccMallocFLT64_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"cos Lookup table (LUTFLT64)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = cos(delta*ii);
  
  return spec;
//------------------------------- COMMON-CODE FLT64 cos    STOP.
}

xccLUTSpecFLT96 *xccGenCosLUTFLT96(UNT32 size)
{
//------------------------------- COMMON-CODE FLT96 cosl   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT96 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT96 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT96));

  spec->table= (FLT96 *) xccMallocFLT96_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"cosl Lookup table (LUTFLT96)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = cosl(delta*ii);
  
  return spec;
//------------------------------- COMMON-CODE FLT96 cosl    STOP.
}

xccLUTSpecFLT32 *xccGenACosLUTFLT32(UNT32 size)
{
//------------------------------- COMMON-CODE FLT32 acosf   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT32 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT32 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT32));

  spec->table= (FLT32 *) xccMallocFLT32_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"acosf Lookup table (LUTFLT32)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = acosf(delta*ii);
  
  return spec;
//------------------------------- COMMON-CODE FLT32 acosf    STOP.
}

xccLUTSpecFLT64 *xccGenACosLUTFLT64(UNT32 size)
{
//------------------------------- COMMON-CODE FLT64 acos   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT64 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT64 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT64));

  spec->table= (FLT64 *) xccMallocFLT64_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"acos Lookup table (LUTFLT64)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = acos(delta*ii);
  
  return spec;
//------------------------------- COMMON-CODE FLT64 acos    STOP.
}

xccLUTSpecFLT96 *xccGenACosLUTFLT96(UNT32 size)
{
//------------------------------- COMMON-CODE FLT96 acosl   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT96 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT96 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT96));

  spec->table= (FLT96 *) xccMallocFLT96_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"acosl Lookup table (LUTFLT96)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = acosl(delta*ii);
  
  return spec;
//------------------------------- COMMON-CODE FLT96 acosl    STOP.
}

xccLUTSpecFLT32 *xccGenTanLUTFLT32(UNT32 size)
{
//------------------------------- COMMON-CODE FLT32 tanf   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT32 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT32 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT32));

  spec->table= (FLT32 *) xccMallocFLT32_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"tanf Lookup table (LUTFLT32)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = tanf(delta*ii);
  
  return spec;
//------------------------------- COMMON-CODE FLT32 tanf    STOP.
}

xccLUTSpecFLT64 *xccGenTanLUTFLT64(UNT32 size)
{
//------------------------------- COMMON-CODE FLT64 tan   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT64 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT64 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT64));

  spec->table= (FLT64 *) xccMallocFLT64_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"tan Lookup table (LUTFLT64)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = tan(delta*ii);
  
  return spec;
//------------------------------- COMMON-CODE FLT64 tan    STOP.
}

xccLUTSpecFLT96 *xccGenTanLUTFLT96(UNT32 size)
{
//------------------------------- COMMON-CODE FLT96 tanl   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT96 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT96 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT96));

  spec->table= (FLT96 *) xccMallocFLT96_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"tanl Lookup table (LUTFLT96)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = tanl(delta*ii);
  
  return spec;
//------------------------------- COMMON-CODE FLT96 tanl    STOP.
}

#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS  FLT64 delta=TWOPI/(FLT64)size;
PERL_PREPROCESS  xccLUTSpecXXXXX *spec;
PERL_PREPROCESS
PERL_PREPROCESS  // Malloc the memory for the spec.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  spec = (xccLUTSpecXXXXX *) xccMallocVOID_Align032(sizeof(xccLUTSpecXXXXX));
PERL_PREPROCESS
PERL_PREPROCESS  spec->table= (XXXXX *) xccMallocXXXXX_Align032(size);
PERL_PREPROCESS
PERL_PREPROCESS  // Initialize the spec.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  sprintf(spec->name,"YYYYY Lookup table (LUTXXXXX)");
PERL_PREPROCESS  spec->size = size;
PERL_PREPROCESS  for(ii=0; ii<size; ii++) spec->table[ii] = YYYYY(delta*ii);
PERL_PREPROCESS  for(ii=0; ii<size; ii++) spec->table[ii] = ZZZZZ(delta*ii);
PERL_PREPROCESS
PERL_PREPROCESS  return spec;
#endif

xccLUTSpecFLT32 *xccGenCosSinLUTFLT32(UNT32 size)
{
//------------------------------- COMMON-CODE FLT32 cosf sinf   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT32 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT32 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT32));

  spec->table= (FLT32 *) xccMallocFLT32_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"cosf Lookup table (LUTFLT32)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = cosf(delta*ii);
  for(ii=0; ii<size; ii++) spec->table[ii] = sinf(delta*ii);

  return spec;
//------------------------------- COMMON-CODE FLT32 cosf sinf    STOP.
}

xccLUTSpecFLT64 *xccGenCosSinLUTFLT64(UNT32 size)
{
//------------------------------- COMMON-CODE FLT64 cos sin   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT64 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT64 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT64));

  spec->table= (FLT64 *) xccMallocFLT64_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"cos Lookup table (LUTFLT64)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = cos(delta*ii);
  for(ii=0; ii<size; ii++) spec->table[ii] = sin(delta*ii);

  return spec;
//------------------------------- COMMON-CODE FLT64 cos sin    STOP.
}

xccLUTSpecFLT96 *xccGenCosSinLUTFLT96(UNT32 size)
{
//------------------------------- COMMON-CODE FLT96 cosl sinl   START.
  UNT32 ii;
  FLT64 delta=TWOPI/(FLT64)size;
  xccLUTSpecFLT96 *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccLUTSpecFLT96 *) xccMallocVOID_Align032(sizeof(xccLUTSpecFLT96));

  spec->table= (FLT96 *) xccMallocFLT96_Align032(size);

  // Initialize the spec.
  //----------------------------------------------------------------------------
  sprintf(spec->name,"cosl Lookup table (LUTFLT96)");
  spec->size = size;
  for(ii=0; ii<size; ii++) spec->table[ii] = cosl(delta*ii);
  for(ii=0; ii<size; ii++) spec->table[ii] = sinl(delta*ii);

  return spec;
//------------------------------- COMMON-CODE FLT96 cosl sinl    STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
