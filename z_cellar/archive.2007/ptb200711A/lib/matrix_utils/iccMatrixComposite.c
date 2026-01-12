/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccMatrixComposite.c
// Desc: This file contains the code for the iccMatrixAdd routine.
// Hist: When       Who  What
//       05/30/2003 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "matrix_utils.h"  

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#if 0
PERL_PREPROCESS  UNT32 ii;
PERL_PREPROCESS
PERL_PREPROCESS  // Check for mismatched number of dimensions.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
PERL_PREPROCESS  {
PERL_PREPROCESS      icc_ERROR_MESSAGE("MATRIX NUMBER OF DIMENSION ERROR.");
PERL_PREPROCESS      return;
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Check for mismatched real and complex matricies.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
PERL_PREPROCESS  {
PERL_PREPROCESS      icc_ERROR_MESSAGE("MATRIX COMPLEX/REAL MISMATCH.");
PERL_PREPROCESS      return;
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Check for mismatched dimension lengths.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(ii = 0; ii < MA->ndim; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
PERL_PREPROCESS    {
PERL_PREPROCESS      icc_ERROR_MESSAGE("MATRIX DIMENSION ERROR.");
PERL_PREPROCESS      return;
PERL_PREPROCESS    }
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Add the matricies.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for(ii = 0; ii < MA->total; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  // Add the complex part if present.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  if( MA->cplx == TRUE )
PERL_PREPROCESS  for(ii = 0; ii < MA->total; ii++)
PERL_PREPROCESS  {
PERL_PREPROCESS    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
PERL_PREPROCESS  }
PERL_PREPROCESS
PERL_PREPROCESS  return;

#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
iccMatrixCompositeINT08(INT08 *MA, INT32 si, INT32 rowsA, INT32 colsA,
                        INT08 *MB, INT32 sj, INT32 rowsB, INT32 colsB,
                        INT08 *MC, INT32 sk, INT32 rowsC, INT32 colsC)
{

  INT32 innerA=colsA;
  INT32 outerA=rowsA;
  INT32 innerB=rowsB;
  INT32 outerB=colsB;
  INT32 innerAB=colsA;


  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if      ( innerA != innerB )
  {
      icc_ERROR_MESSAGE("MATRIX A and MATRIX B are not conformable.");
      return;
  }
  else if ( rowsA != rowsC )
  {
      icc_ERROR_MESSAGE("MATRIX C needs same number of rows as MATRIX A.");
      return;
  }
  else if ( colsB != colsC )
  {
      icc_ERROR_MESSAGE("MATRIX C needs same number of cols as MATRIX B.");
      return;
  }


  // REAL.
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
	temp += MA[ (ii*colsA+ii*si)+(kk*si) ] * MB[ (kk*colsB+kk*sj)+(jj*sj) ];
      }
      MC[ (ii*colsC+sk*ii) + (jj*sk)] = temp;
    }
  }










  // REAL or REAL REAL.
  //----------------------------------------------------------------------------
  for( MAOuterIndex = 0; MAOuterIndex < rowsA; MAOuterIndex++ ) // ROWS of A
  {
    for( MBOuterIndex = 0; MBOuterIndex < colsB; MBOuterIndex++ ) // COLUMNS of B
    {
      MC[MAOuterIndex*rowsA+MBOuterIndex]=0;
      for(InnerIndex = 0; InnerIndex < colsA; InnerIndex++)
        MC[MAOuterIndex*rowsA+MBOuterIndex] += 
	  MA[MAOuterIndex*rowsA+InnerIdex]*MB[InnerIndex*rowsB+MBOuterIndex];
    }
  }

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

  for ii = 1:4, %outerA
    for jj = 1:4, %outerB
    MC2(ii,jj) = 0;
      for kk = 1:4, %innerAB
        MC2(ii,jj) = MC2(ii,jj) + MA(ii,kk).*MB(kk,jj);
      end;
    end;
  end;

  
  rowsA=3; colsA=2;
  rowsB=2; colsB=4;
  for MAOuterIndex = 0:rowsA,
    for MBOuterIndex = 0:colsB,
      for InnerIndex   = 0:colsA,
        MAIndex = MAOuterIndex*rowsA+InnerIdex
        MBIndex = InnerIdex*rowsB+MBOuterIndex
        MCIndex = MAOuterIndex*rowsA+MBOuterIndex
end
end
end




VOID iccMatrixCompositeINT08(iccMatrixINT08_t *MA, iccMatrixINT08_t *MB, iccMatrixINT08_t *MC, INT32 CREATE_FLAG)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check to see if Matrix A and Matrix B are conformable.
  //----------------------------------------------------------------------------
  if( (MA->dim[1] != MB->dim[0] )) // row=0, col=1;
  {
      icc_ERROR_MESSAGE("MATRIX A and MATRIX B are not conformable.");
      return;
  }
  
  // If the create flag is set, create the proper C Matrix for A and B.
  //----------------------------------------------------------------------------
  if( CREATE_FLAG != 0 )
  {
    INT32 row=MA->dim[0];
    INT32 col=MB->dim[1];
    INT08 realMatrix;

  // See if result needs to be complex. 
  //----------------------------------------------------------------------------
    if( (MA->realMatrix == CPLX) || (MB-realMatrix == CPLX) ) realMatrix = CPLX;

  // Create the matrix.
  //----------------------------------------------------------------------------
    MC = iccMatrixInitINT08("ANSWER", realMatrix, 2, row, col);
  }

  // ELSE check to see if Matrix C is of the correct shape.
  //----------------------------------------------------------------------------
  else
  { 
  // Check if Matrix C is dimensioned correctly for composition.
  //----------------------------------------------------------------------------
    if( (MA->dim[0] != MC->dim[0]) || (MB->dim[1] != MC->dim[1]) ) // row=0, col=1;
    {
      icc_ERROR_MESSAGE("MATRIX C is not dimensioned correctly for MATRIX A and MATRIX B composition.");
      return;
    }

  // See if Matrix C complex flag is set correctly.
  //----------------------------------------------------------------------------
    if( ((MA->realMatrix == CPLX) && (MC->realMatrix != CPLX) ) ||
	((MB->realMatrix == CPLX) && (MC->realMatrix != CPLX) )   )
    {
      icc_ERROR_MESSAGE("MATRIX C needs to be complex");
      return;
    }

  }

  // REAL or REAL_REAL
  //----------------------------------------------------------------------------
  for( MAOuterIndex = 0; MAOuterIndex < MA->dim[0]; MAOuterIndex++ ) // ROWS of A
  {
    for( MBOuterIndex = 0; MBOuterIndex < MB->dim[1]; MBOuterIndex++ ) // COLUMNS of B
    {
      MC->pr(MAOuterIndex*MA->dim[0]+MBOuterIndex)=0;
      for(InnerIndex = 0; InnerIndex < MA->dim[1]; InnerIndex++)
	MC->pr(MAOuterIndex*MA->dim[0]+MBOuterIndex) += 
	  MA->pr(MAOuterIndex*MA->dim[0]+InnerIndex)*MB->pr(InnerIndex*MB->dim[0]+MBOuterIndex);
    }
  }

  if(MC->realMatrix==CPLX)
  {
  // IMAGINARY IMAGINARY
  //----------------------------------------------------------------------------
    for( MAOuterIndex = 0; MAOuterIndex < MA->dim[0]; MAOuterIndex++ ) // ROWS of A
    {
      for( MBOuterIndex = 0; MBOuterIndex < MB->dim[1]; MBOuterIndex++ ) // COLUMNS of B
      {
	for(InnerIndex = 0; InnerIndex < MA->dim[1]; InnerIndex++)
	  MC->pr(MAOuterIndex*MA->dim[0]+MBOuterIndex) += 
	    MA->pi(MAOuterIndex*MA->dim[0]+InnerIndex)*MB->pi(InnerIndex*MB->dim[0]+MBOuterIndex);
      }
    }

  // REAL IMAGINARY
  //----------------------------------------------------------------------------
    for( MAOuterIndex = 0; MAOuterIndex < MA->dim[0]; MAOuterIndex++ ) // ROWS of A
    {
      for( MBOuterIndex = 0; MBOuterIndex < MB->dim[1]; MBOuterIndex++ ) // COLUMNS of B
      {
	MC->pi(MAOuterIndex*MA->dim[0]+MBOuterIndex)=0;
	for(InnerIndex = 0; InnerIndex < MA->dim[1]; InnerIndex++)
	  MC->pi(MAOuterIndex*MA->dim[0]+MBOuterIndex) += 
	    MA->pr(MAOuterIndex*MA->dim[0]+InnerIndex)*MB->pi(InnerIndex*MB->dim[0]+MBOuterIndex);
      }
    }

  // IMAGINARY REAL
  //----------------------------------------------------------------------------
    for( MAOuterIndex = 0; MAOuterIndex < MA->dim[0]; MAOuterIndex++ ) // ROWS of A
    {
      for( MBOuterIndex = 0; MBOuterIndex < MB->dim[1]; MBOuterIndex++ ) // COLUMNS of B
      {
	for(InnerIndex = 0; InnerIndex < MA->dim[1]; InnerIndex++)
	  MC->pi(MAOuterIndex*MA->dim[0]+MBOuterIndex) += 
	    MA->pi(MAOuterIndex*MA->dim[0]+InnerIndex)*MB->pr(InnerIndex*MB->dim[0]+MBOuterIndex);
      }
    }
  }

  return;
//COMMON-CODE STOP.
}






VOID iccMatrixAddINT16(iccMatrixINT16_t *MA, iccMatrixINT16_t *MB, iccMatrixINT16_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      icc_ERROR_MESSAGE("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      icc_ERROR_MESSAGE("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      icc_ERROR_MESSAGE("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixAddINT32(iccMatrixINT32_t *MA, iccMatrixINT32_t *MB, iccMatrixINT32_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      icc_ERROR_MESSAGE("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      icc_ERROR_MESSAGE("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      icc_ERROR_MESSAGE("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixAddINT64(iccMatrixINT64_t *MA, iccMatrixINT64_t *MB, iccMatrixINT64_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      icc_ERROR_MESSAGE("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      icc_ERROR_MESSAGE("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      icc_ERROR_MESSAGE("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixAddUNT08(iccMatrixUNT08_t *MA, iccMatrixUNT08_t *MB, iccMatrixUNT08_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      icc_ERROR_MESSAGE("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      icc_ERROR_MESSAGE("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      icc_ERROR_MESSAGE("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixAddUNT16(iccMatrixUNT16_t *MA, iccMatrixUNT16_t *MB, iccMatrixUNT16_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      icc_ERROR_MESSAGE("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      icc_ERROR_MESSAGE("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      icc_ERROR_MESSAGE("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixAddUNT32(iccMatrixUNT32_t *MA, iccMatrixUNT32_t *MB, iccMatrixUNT32_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      icc_ERROR_MESSAGE("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      icc_ERROR_MESSAGE("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      icc_ERROR_MESSAGE("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixAddUNT64(iccMatrixUNT64_t *MA, iccMatrixUNT64_t *MB, iccMatrixUNT64_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      icc_ERROR_MESSAGE("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      icc_ERROR_MESSAGE("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      icc_ERROR_MESSAGE("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixAddFLT32(iccMatrixFLT32_t *MA, iccMatrixFLT32_t *MB, iccMatrixFLT32_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      icc_ERROR_MESSAGE("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      icc_ERROR_MESSAGE("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      icc_ERROR_MESSAGE("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixAddFLT64(iccMatrixFLT64_t *MA, iccMatrixFLT64_t *MB, iccMatrixFLT64_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      icc_ERROR_MESSAGE("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      icc_ERROR_MESSAGE("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      icc_ERROR_MESSAGE("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

VOID iccMatrixAddFLT96(iccMatrixFLT96_t *MA, iccMatrixFLT96_t *MB, iccMatrixFLT96_t *MC)
{
//COMMON-CODE   START.
  UNT32 ii;

  // Check for mismatched number of dimensions.
  //----------------------------------------------------------------------------
  if( (MA->ndim  != MB->ndim ) && (MB->ndim  != MC->ndim ) )
  {
      icc_ERROR_MESSAGE("MATRIX NUMBER OF DIMENSION ERROR.");
      return;
  }

  // Check for mismatched real and complex matricies.
  //----------------------------------------------------------------------------
  if( (MA->cplx != MB->cplx) && (MB->cplx != MC->cplx) )
  {
      icc_ERROR_MESSAGE("MATRIX COMPLEX/REAL MISMATCH.");
      return;
  }

  // Check for mismatched dimension lengths.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->ndim; ii++)
  {
    if( (MA->dim[ii] != MB->dim[ii]) && (MB->dim[ii] != MC->dim[ii]) )
    {
      icc_ERROR_MESSAGE("MATRIX DIMENSION ERROR.");
      return;
    }
  }

  // Add the matricies.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pr[ii] = MA->pr[ii]+MB->pr[ii];
  }

  // Add the complex part if present.
  //----------------------------------------------------------------------------
  if( MA->cplx == TRUE )
  for(ii = 0; ii < MA->total; ii++)
  {
    MC->pi[ii] = MA->pi[ii]+MB->pi[ii];
  }

  return;
//COMMON-CODE    STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
