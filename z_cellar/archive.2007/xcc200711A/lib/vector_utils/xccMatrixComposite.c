/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccMatrixComposite.c
// Desc: This file contains the code for the xccMatrixComposite routine.
// Hist: When       Who  What
//       12/01/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "vector_utils.h"  

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS INT32 innerA=colsA;
PERL_PREPROCESS INT32 outerA=rowsA;
PERL_PREPROCESS INT32 innerB=rowsB;
PERL_PREPROCESS INT32 outerB=colsB;
PERL_PREPROCESS INT32 innerAB=colsA;
PERL_PREPROCESS INT32 ii,jj,kk;
PERL_PREPROCESS XXXXX temp;
PERL_PREPROCESS
PERL_PREPROCESS  // Check to see if Matrix A and Matrix B are conformable.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if      ( innerA != innerB )
PERL_PREPROCESS  {
PERL_PREPROCESS    xcc_ERROR_MESSAGE("MATRIX A and MATRIX B are not conformable.");
PERL_PREPROCESS    return;
PERL_PREPROCESS  }
PERL_PREPROCESS  else if ( rowsA != rowsC )
PERL_PREPROCESS  {
PERL_PREPROCESS    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
PERL_PREPROCESS    return;
PERL_PREPROCESS  }
PERL_PREPROCESS  else if ( colsB != colsC )
PERL_PREPROCESS  {
PERL_PREPROCESS    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
PERL_PREPROCESS    return;
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // REAL.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
PERL_PREPROCESS  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols*skip) + (jj*skip)];
PERL_PREPROCESS  for (ii=0; ii<outerA; ii++) // %outerA
PERL_PREPROCESS  {
PERL_PREPROCESS    for (jj=0; jj<outerB; jj++) // %outerB
PERL_PREPROCESS    {
PERL_PREPROCESS      temp=0;
PERL_PREPROCESS      for (kk=0; kk<innerAB; kk++)
PERL_PREPROCESS      {
PERL_PREPROCESS	       temp += MA[ (ii*colsA*si)+(kk*si) ] * MB[ (kk*colsB*sj)+(jj*sj) ];
PERL_PREPROCESS      }
PERL_PREPROCESS      MC[ (ii*colsC*sk) + (jj*sk)] = temp;
PERL_PREPROCESS    }
PERL_PREPROCESS  }
#endif


/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID xccMatrixCompositeFLT32(FLT32 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			     FLT32 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			     FLT32 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE FLT32   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 FLT32 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ] * MB[ (kk*colsB*sj)+(jj*sj) ];
      }
      MC[ (ii*colsC*sk) + (jj*sk)] = temp;
    }
  }
//------------------------------- COMMON-CODE FLT32    STOP.
}

VOID xccMatrixCompositeFLT64(FLT64 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			     FLT64 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			     FLT64 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE FLT64   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 FLT64 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ] * MB[ (kk*colsB*sj)+(jj*sj) ];
      }
      MC[ (ii*colsC*sk) + (jj*sk)] = temp;
    }
  }
//------------------------------- COMMON-CODE FLT64    STOP.
}

VOID xccMatrixCompositeFLT96(FLT96 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			     FLT96 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			     FLT96 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE FLT96   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 FLT96 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ] * MB[ (kk*colsB*sj)+(jj*sj) ];
      }
      MC[ (ii*colsC*sk) + (jj*sk)] = temp;
    }
  }
//------------------------------- COMMON-CODE FLT96    STOP.
}

VOID xccMatrixCompositeINT08(INT08 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			     INT08 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			     INT08 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE INT08   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 INT08 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ] * MB[ (kk*colsB*sj)+(jj*sj) ];
      }
      MC[ (ii*colsC*sk) + (jj*sk)] = temp;
    }
  }
//------------------------------- COMMON-CODE INT08    STOP.
}

VOID xccMatrixCompositeINT16(INT16 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			     INT16 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			     INT16 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE INT16   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 INT16 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ] * MB[ (kk*colsB*sj)+(jj*sj) ];
      }
      MC[ (ii*colsC*sk) + (jj*sk)] = temp;
    }
  }
//------------------------------- COMMON-CODE INT16    STOP.
}

VOID xccMatrixCompositeINT32(INT32 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			     INT32 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			     INT32 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE INT32   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 INT32 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ] * MB[ (kk*colsB*sj)+(jj*sj) ];
      }
      MC[ (ii*colsC*sk) + (jj*sk)] = temp;
    }
  }
//------------------------------- COMMON-CODE INT32    STOP.
}

VOID xccMatrixCompositeINT64(INT64 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			     INT64 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			     INT64 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE INT64   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 INT64 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ] * MB[ (kk*colsB*sj)+(jj*sj) ];
      }
      MC[ (ii*colsC*sk) + (jj*sk)] = temp;
    }
  }
//------------------------------- COMMON-CODE INT64    STOP.
}

VOID xccMatrixCompositeUNT08(UNT08 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			     UNT08 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			     UNT08 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE UNT08   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 UNT08 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ] * MB[ (kk*colsB*sj)+(jj*sj) ];
      }
      MC[ (ii*colsC*sk) + (jj*sk)] = temp;
    }
  }
//------------------------------- COMMON-CODE UNT08    STOP.
}

VOID xccMatrixCompositeUNT16(UNT16 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			     UNT16 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			     UNT16 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE UNT16   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 UNT16 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ] * MB[ (kk*colsB*sj)+(jj*sj) ];
      }
      MC[ (ii*colsC*sk) + (jj*sk)] = temp;
    }
  }
//------------------------------- COMMON-CODE UNT16    STOP.
}

VOID xccMatrixCompositeUNT32(UNT32 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			     UNT32 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			     UNT32 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE UNT32   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 UNT32 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ] * MB[ (kk*colsB*sj)+(jj*sj) ];
      }
      MC[ (ii*colsC*sk) + (jj*sk)] = temp;
    }
  }
//------------------------------- COMMON-CODE UNT32    STOP.
}

VOID xccMatrixCompositeUNT64(UNT64 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			     UNT64 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			     UNT64 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE UNT64   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 UNT64 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ] * MB[ (kk*colsB*sj)+(jj*sj) ];
      }
      MC[ (ii*colsC*sk) + (jj*sk)] = temp;
    }
  }
//------------------------------- COMMON-CODE UNT64    STOP.
}

// Handle complex.
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS INT32 innerA=colsA;
PERL_PREPROCESS INT32 outerA=rowsA;
PERL_PREPROCESS INT32 innerB=rowsB;
PERL_PREPROCESS INT32 outerB=colsB;
PERL_PREPROCESS INT32 innerAB=colsA;
PERL_PREPROCESS INT32 ii,jj,kk;
PERL_PREPROCESS XXXXX temp;
PERL_PREPROCESS
PERL_PREPROCESS  // Check to see if Matrix A and Matrix B are conformable.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if      ( innerA != innerB )
PERL_PREPROCESS  {
PERL_PREPROCESS    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
PERL_PREPROCESS    return;
PERL_PREPROCESS  }
PERL_PREPROCESS  else if ( rowsA != rowsC )
PERL_PREPROCESS  {
PERL_PREPROCESS    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
PERL_PREPROCESS    return;
PERL_PREPROCESS  }
PERL_PREPROCESS  else if ( colsB != colsC )
PERL_PREPROCESS  {
PERL_PREPROCESS    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
PERL_PREPROCESS    return;
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // REAL_REAL.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
PERL_PREPROCESS  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
PERL_PREPROCESS  for (ii=0; ii<outerA; ii++) // %outerA
PERL_PREPROCESS  {
PERL_PREPROCESS    for (jj=0; jj<outerB; jj++) // %outerB
PERL_PREPROCESS    {
PERL_PREPROCESS      temp=0;
PERL_PREPROCESS      for (kk=0; kk<innerAB; kk++)
PERL_PREPROCESS      {
PERL_PREPROCESS	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].r;
PERL_PREPROCESS      }
PERL_PREPROCESS      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
PERL_PREPROCESS    }
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // IMAG_IMAG.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
PERL_PREPROCESS  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
PERL_PREPROCESS  for (ii=0; ii<outerA; ii++) // %outerA
PERL_PREPROCESS  {
PERL_PREPROCESS    for (jj=0; jj<outerB; jj++) // %outerB
PERL_PREPROCESS    {
PERL_PREPROCESS      temp=MC[ (ii*colsC*sk) + (jj*sk)].r;
PERL_PREPROCESS      for (kk=0; kk<innerAB; kk++)
PERL_PREPROCESS      {
PERL_PREPROCESS	       temp -= MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].i; //Remember sqrt(-1)^2 is -1 
PERL_PREPROCESS      }
PERL_PREPROCESS      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
PERL_PREPROCESS    }
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // REAL_IMAG.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
PERL_PREPROCESS  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
PERL_PREPROCESS  for (ii=0; ii<outerA; ii++) // %outerA
PERL_PREPROCESS  {
PERL_PREPROCESS    for (jj=0; jj<outerB; jj++) // %outerB
PERL_PREPROCESS    {
PERL_PREPROCESS      temp=0;
PERL_PREPROCESS      for (kk=0; kk<innerAB; kk++)
PERL_PREPROCESS      {
PERL_PREPROCESS	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].i;
PERL_PREPROCESS      }
PERL_PREPROCESS      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
PERL_PREPROCESS    }
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // IMAG_REAL.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
PERL_PREPROCESS  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
PERL_PREPROCESS  for (ii=0; ii<outerA; ii++) // %outerA
PERL_PREPROCESS  {
PERL_PREPROCESS    for (jj=0; jj<outerB; jj++) // %outerB
PERL_PREPROCESS    {
PERL_PREPROCESS      temp=MC[ (ii*colsC*sk) + (jj*sk)].i;
PERL_PREPROCESS      for (kk=0; kk<innerAB; kk++)
PERL_PREPROCESS      {
PERL_PREPROCESS	       temp += MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].r;
PERL_PREPROCESS      }
PERL_PREPROCESS      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
PERL_PREPROCESS    }
PERL_PREPROCESS  }
#endif

VOID xccMatrixCompositeCFLT32(CFLT32 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CFLT32 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CFLT32 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE FLT32   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 FLT32 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // IMAG_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].r;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp -= MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].i; //Remember sqrt(-1)^2 is -1 
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // REAL_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].i;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }

  // IMAG_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].i;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }
//------------------------------- COMMON-CODE FLT32    STOP.
}

VOID xccMatrixCompositeCFLT64(CFLT64 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CFLT64 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CFLT64 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE FLT64   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 FLT64 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // IMAG_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].r;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp -= MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].i; //Remember sqrt(-1)^2 is -1 
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // REAL_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].i;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }

  // IMAG_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].i;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }
//------------------------------- COMMON-CODE FLT64    STOP.
}

VOID xccMatrixCompositeCFLT96(CFLT96 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CFLT96 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CFLT96 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE FLT96   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 FLT96 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // IMAG_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].r;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp -= MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].i; //Remember sqrt(-1)^2 is -1 
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // REAL_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].i;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }

  // IMAG_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].i;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }
//------------------------------- COMMON-CODE FLT96    STOP.
}

VOID xccMatrixCompositeCINT08(CINT08 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CINT08 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CINT08 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE INT08   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 INT08 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // IMAG_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].r;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp -= MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].i; //Remember sqrt(-1)^2 is -1 
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // REAL_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].i;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }

  // IMAG_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].i;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }
//------------------------------- COMMON-CODE INT08    STOP.
}

VOID xccMatrixCompositeCINT16(CINT16 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CINT16 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CINT16 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE INT16   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 INT16 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // IMAG_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].r;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp -= MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].i; //Remember sqrt(-1)^2 is -1 
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // REAL_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].i;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }

  // IMAG_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].i;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }
//------------------------------- COMMON-CODE INT16    STOP.
}

VOID xccMatrixCompositeCINT32(CINT32 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CINT32 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CINT32 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE INT32   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 INT32 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // IMAG_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].r;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp -= MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].i; //Remember sqrt(-1)^2 is -1 
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // REAL_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].i;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }

  // IMAG_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].i;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }
//------------------------------- COMMON-CODE INT32    STOP.
}

VOID xccMatrixCompositeCINT64(CINT64 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CINT64 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CINT64 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE INT64   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 INT64 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // IMAG_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].r;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp -= MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].i; //Remember sqrt(-1)^2 is -1 
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // REAL_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].i;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }

  // IMAG_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].i;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }
//------------------------------- COMMON-CODE INT64    STOP.
}

VOID xccMatrixCompositeCUNT08(CUNT08 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CUNT08 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CUNT08 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE UNT08   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 UNT08 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // IMAG_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].r;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp -= MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].i; //Remember sqrt(-1)^2 is -1 
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // REAL_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].i;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }

  // IMAG_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].i;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }
//------------------------------- COMMON-CODE UNT08    STOP.
}

VOID xccMatrixCompositeCUNT16(CUNT16 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CUNT16 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CUNT16 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE UNT16   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 UNT16 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // IMAG_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].r;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp -= MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].i; //Remember sqrt(-1)^2 is -1 
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // REAL_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].i;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }

  // IMAG_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].i;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }
//------------------------------- COMMON-CODE UNT16    STOP.
}

VOID xccMatrixCompositeCUNT32(CUNT32 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CUNT32 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CUNT32 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE UNT32   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 UNT32 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // IMAG_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].r;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp -= MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].i; //Remember sqrt(-1)^2 is -1 
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // REAL_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].i;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }

  // IMAG_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].i;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }
//------------------------------- COMMON-CODE UNT32    STOP.
}

VOID xccMatrixCompositeCUNT64(CUNT64 *MA, INT32 si, INT32 rowsA, INT32 colsA,
			      CUNT64 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
			      CUNT64 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{
//------------------------------- COMMON-CODE UNT64   START.
 INT32 innerA=colsA;
 INT32 outerA=rowsA;
 INT32 innerB=rowsB;
 INT32 outerB=colsB;
 INT32 innerAB=colsA;
 INT32 ii,jj,kk;
 UNT64 temp;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
    XMC_ERROR_STDOUT("MATRIX A and MATRIX B are not conformable.");
    return;
  }
  else if ( rowsA != rowsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of rows as MATRIX A.");
    return;
  }
  else if ( colsB != colsC )
  {
    XMC_ERROR_STDOUT("MATRIX C needs same number of cols as MATRIX B.");
    return;
  }

  // REAL_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // IMAG_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].r;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp -= MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].i; //Remember sqrt(-1)^2 is -1 
      }
      MC[ (ii*colsC*sk) + (jj*sk)].r = temp;
    }
  }

  // REAL_IMAG.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=0;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].r * MB[ (kk*colsB*sj)+(jj*sj) ].i;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }

  // IMAG_REAL.
  //----------------------------------------------------------------------------
  //To convert 2 dimensional array notation:           [ii][jj] => [ii*ncols+jj];
  //To convert 2 dimensional array notation with skip: [ii][jj] => [(ii*ncols+ii*skip) + (jj*skip)];
  for (ii=0; ii<outerA; ii++) // %outerA
  {
    for (jj=0; jj<outerB; jj++) // %outerB
    {
      temp=MC[ (ii*colsC*sk) + (jj*sk)].i;
      for (kk=0; kk<innerAB; kk++)
      {
	       temp += MA[ (ii*colsA*si)+(kk*si) ].i * MB[ (kk*colsB*sj)+(jj*sj) ].r;
      }
      MC[ (ii*colsC*sk) + (jj*sk)].i = temp;
    }
  }
//------------------------------- COMMON-CODE UNT64    STOP.
}


/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/

#if 0
MA=[1 1 0 0; 1 1 0 0; 1 1 0 0; 0 0 0 0];
MB=[1 1 1 1; 1 1 1 1; 0 0 0 0; 0 0 0 0];
MC=[0 0 0 0; 0 0 0 0; 0 0 0 0; 0 0 0 0];

MA2=[1 1 0 0 1 1 0 0 1 1 0 0 0 0 0 0];
MB2=[1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0];
MC2=[0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0];

MAP=[1 2 3 4; 5 6 7 8; 9 10 11 12; 13 14 15 16]


rowsA=4;
colsA=4;
rowsB=4;
colsB=4;
rowsC=rowsA;
colsC=colsB;
outerA = rowsA;
innerA = colsA;
outerB = colsB;
innerB = rowsB;
innerAB=innerA;
si = 1;
sj = 1;
sk = 1;
for ii=0:(outerA-1),
for jj=0:(outerB-1),
  linIndexC = (ii*colsC*sk) + (jj*sk)+1;
  MC2( linIndexC )=0;
for kk=0:(innerAB-1),
  linIndexA = (ii*colsA*si) + (kk*si)+1;
  linIndexB = (kk*colsB*sj) + (jj*sj)+1;
  printf("MC %03d  ", linIndexC);
  printf("MA %03d  ", linIndexA);
  printf("MB %03d  ", linIndexB);
  [a,b]=find(MAP==linIndexC); printf("MC(%03d %03d)  ", a,b);
  [a,b]=find(MAP==linIndexA); printf("MA(%03d %03d)  ", a,b);
  [a,b]=find(MAP==linIndexB); printf("MB(%03d %03d)\n", a,b);

  MC2( linIndexC ) =  MC2( linIndexC ) + ...
                      MA2( linIndexA ) * ...
                      MB2( linIndexB );
end
end
end

break


 %Matlab test.
  MA=[1 1 0 0; 1 1 0 0; 1 1 0 0; 0 0 0 0];
  MB=[1 1 1 1; 1 1 1 1; 0 0 0 0; 0 0 0 0];
  MC=[0 0 0 0; 0 0 0 0; 0 0 0 0; 0 0 0 0];

  MC(1,1) = MA(1,1).*MB(1,1) + MA(1,2).*MB(2,1) + MA(1,3).*MB(3,1) + MA(1,4)*MB(4,1);
  MC(2,1) = MA(2,1).*MB(1,1) + MA(2,2).*MB(2,1) + MA(2,3).*MB(3,1) + MA(2,4)*MB(4,1);
  MC(3,1) = MA(3,1).*MB(1,1) + MA(3,2).*MB(2,1) + MA(3,3).*MB(3,1) + MA(3,4)*MB(4,1);
  MC(4,1) = MA(4,1).*MB(1,1) + MA(4,2).*MB(2,1) + MA(4,3).*MB(3,1) + MA(4,4)*MB(4,1);

  MC(1,2) = MA(1,1).*MB(1,2) + MA(1,2).*MB(2,2) + MA(1,3).*MB(3,2) + MA(1,4)*MB(4,2);
  MC(2,2) = MA(2,1).*MB(1,2) + MA(2,2).*MB(2,2) + MA(2,3).*MB(3,2) + MA(2,4)*MB(4,2);
  MC(3,2) = MA(3,1).*MB(1,2) + MA(3,2).*MB(2,2) + MA(3,3).*MB(3,2) + MA(3,4)*MB(4,2);
  MC(4,2) = MA(4,1).*MB(1,2) + MA(4,2).*MB(2,2) + MA(4,3).*MB(3,2) + MA(4,4)*MB(4,2);

  MC(1,3) = MA(1,1).*MB(1,3) + MA(1,2).*MB(2,3) + MA(1,3).*MB(3,3) + MA(1,4)*MB(4,3);
  MC(2,3) = MA(2,1).*MB(1,3) + MA(2,2).*MB(2,3) + MA(2,3).*MB(3,3) + MA(2,4)*MB(4,3);
  MC(3,3) = MA(3,1).*MB(1,3) + MA(3,2).*MB(2,3) + MA(3,3).*MB(3,3) + MA(3,4)*MB(4,3);
  MC(4,3) = MA(4,1).*MB(1,3) + MA(4,2).*MB(2,3) + MA(4,3).*MB(3,3) + MA(4,4)*MB(4,3);

  MC(1,4) = MA(1,1).*MB(1,4) + MA(1,2).*MB(2,4) + MA(1,3).*MB(3,4) + MA(1,4)*MB(4,4);
  MC(2,4) = MA(2,1).*MB(1,4) + MA(2,2).*MB(2,4) + MA(2,3).*MB(3,4) + MA(2,4)*MB(4,4);
  MC(3,4) = MA(3,1).*MB(1,4) + MA(3,2).*MB(2,4) + MA(3,3).*MB(3,4) + MA(3,4)*MB(4,4);
  MC(4,4) = MA(4,1).*MB(1,4) + MA(4,2).*MB(2,4) + MA(4,3).*MB(3,4) + MA(4,4)*MB(4,4);

  MA
  MB
  MC
#endif
