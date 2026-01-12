/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccvBarrelShift.c
// Desc: This file contains the code for the vectorUtils routine iccvBarrelShift.
// Hist: When       Who  What
//       10/09/2003 ptb  Initial Code.
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
PERL_PREPROCESS  XXXXX *pa=(XXXXX *)a;
PERL_PREPROCESS  XXXXX t0;
PERL_PREPROCESS  XXXXX t1;
PERL_PREPROCESS  INT32 jj  =0;
PERL_PREPROCESS  INT32 ii  =0;
PERL_PREPROCESS  INT32 ni  =0;
PERL_PREPROCESS  INT32 add1Index =0;
PERL_PREPROCESS  //INT32 whogi=n*i; 
PERL_PREPROCESS
PERL_PREPROCESS  // Mod the shift and check.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  shiftBy = shiftBy % n;
PERL_PREPROCESS
PERL_PREPROCESS  if(shiftBy == 0)         // If there is no shift,
PERL_PREPROCESS  {                        //
PERL_PREPROCESS    return;                // This is a No-op.
PERL_PREPROCESS  }                        //
PERL_PREPROCESS  else if(shiftBy < 0)     // If shift is negative (to the left).
PERL_PREPROCESS  {                        //
PERL_PREPROCESS    shiftBy += n;          // Same as positive shift when you add "n".
PERL_PREPROCESS  }                        //
PERL_PREPROCESS
PERL_PREPROCESS  // Initialize a perform first pass of the shift loop.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  ii = 0;                  // Set the "index".
PERL_PREPROCESS  ni = (ii*i) + shiftBy*i; // Set the "next index"
PERL_PREPROCESS
PERL_PREPROCESS  t0     = pa[ii];         // Perform a one element shift.
PERL_PREPROCESS  t1     = pa[ni];         //
PERL_PREPROCESS  pa[ni] = t0;             //
PERL_PREPROCESS  t0     = t1;             //
PERL_PREPROCESS
PERL_PREPROCESS  ii = ni;                 // "index" should now equal "next index".
PERL_PREPROCESS  ni = (ii*i) + shiftBy*i; // Recalculate "next index".
PERL_PREPROCESS
PERL_PREPROCESS  ni = ni%(n*i);           // Make sure we wrap if we go to far.
PERL_PREPROCESS
PERL_PREPROCESS  // Perform the rest of the main shift loop.
PERL_PREPROCESS  //----------------------------------------------------------------------------
PERL_PREPROCESS  for (jj=1; jj < n; jj++)
PERL_PREPROCESS  {
PERL_PREPROCESS    t1     = pa[ni];       // Perform a one element shift.
PERL_PREPROCESS    pa[ni] = t0;           //
PERL_PREPROCESS    t0     = t1;           //
PERL_PREPROCESS
PERL_PREPROCESS    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
PERL_PREPROCESS    {                      // have already visited.
PERL_PREPROCESS      ni = ni + 1*i;
PERL_PREPROCESS      add1Index = ni;
PERL_PREPROCESS      ii = ni;
PERL_PREPROCESS      ni = (ii*i) + shiftBy*i;
PERL_PREPROCESS      t0 = pa[ii];
PERL_PREPROCESS    }
PERL_PREPROCESS    else                   // Else be "normal".
PERL_PREPROCESS    {
PERL_PREPROCESS      ii = ni;
PERL_PREPROCESS      ni = (ii*i) + shiftBy*i;
PERL_PREPROCESS    }
PERL_PREPROCESS
PERL_PREPROCESS    ni = ni%(n*i);         // Make sure we wrap if we go too far.
PERL_PREPROCESS  }
#endif


/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccvBarrelShiftFLT32(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE FLT32        START.
  FLT32 *pa=(FLT32 *)a;
  FLT32 t0;
  FLT32 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE FLT32         STOP.
}

VOID iccvBarrelShiftFLT64(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE FLT64        START.
  FLT64 *pa=(FLT64 *)a;
  FLT64 t0;
  FLT64 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE FLT64         STOP.
}

VOID iccvBarrelShiftFLT96(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE FLT96        START.
  FLT96 *pa=(FLT96 *)a;
  FLT96 t0;
  FLT96 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE FLT96         STOP.
}

VOID iccvBarrelShiftINT08(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE INT08        START.
  INT08 *pa=(INT08 *)a;
  INT08 t0;
  INT08 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE INT08         STOP.
}

VOID iccvBarrelShiftINT16(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE INT16        START.
  INT16 *pa=(INT16 *)a;
  INT16 t0;
  INT16 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE INT16         STOP.
}

VOID iccvBarrelShiftINT32(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE INT32        START.
  INT32 *pa=(INT32 *)a;
  INT32 t0;
  INT32 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE INT32         STOP.
}

VOID iccvBarrelShiftINT64(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE INT64        START.
  INT64 *pa=(INT64 *)a;
  INT64 t0;
  INT64 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE INT64         STOP.
}

VOID iccvBarrelShiftUNT08(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE UNT08        START.
  UNT08 *pa=(UNT08 *)a;
  UNT08 t0;
  UNT08 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE UNT08         STOP.
}

VOID iccvBarrelShiftUNT16(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE UNT16        START.
  UNT16 *pa=(UNT16 *)a;
  UNT16 t0;
  UNT16 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE UNT16         STOP.
}

VOID iccvBarrelShiftUNT32(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE UNT32        START.
  UNT32 *pa=(UNT32 *)a;
  UNT32 t0;
  UNT32 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE UNT32         STOP.
}

VOID iccvBarrelShiftUNT64(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE UNT64        START.
  UNT64 *pa=(UNT64 *)a;
  UNT64 t0;
  UNT64 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE UNT64         STOP.
}

// Handle complex vectors.
//-------------------------------------------------------------------------------
VOID iccvBarrelShiftCFLT32(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE CFLT32        START.
  CFLT32 *pa=(CFLT32 *)a;
  CFLT32 t0;
  CFLT32 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE CFLT32         STOP.
}

VOID iccvBarrelShiftCFLT64(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE CFLT64        START.
  CFLT64 *pa=(CFLT64 *)a;
  CFLT64 t0;
  CFLT64 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE CFLT64         STOP.
}

VOID iccvBarrelShiftCFLT96(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE CFLT96        START.
  CFLT96 *pa=(CFLT96 *)a;
  CFLT96 t0;
  CFLT96 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE CFLT96         STOP.
}

VOID iccvBarrelShiftCINT08(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE CINT08        START.
  CINT08 *pa=(CINT08 *)a;
  CINT08 t0;
  CINT08 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE CINT08         STOP.
}

VOID iccvBarrelShiftCINT16(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE CINT16        START.
  CINT16 *pa=(CINT16 *)a;
  CINT16 t0;
  CINT16 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE CINT16         STOP.
}

VOID iccvBarrelShiftCINT32(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE CINT32        START.
  CINT32 *pa=(CINT32 *)a;
  CINT32 t0;
  CINT32 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE CINT32         STOP.
}

VOID iccvBarrelShiftCINT64(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE CINT64        START.
  CINT64 *pa=(CINT64 *)a;
  CINT64 t0;
  CINT64 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE CINT64         STOP.
}

VOID iccvBarrelShiftCUNT08(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT08        START.
  CUNT08 *pa=(CUNT08 *)a;
  CUNT08 t0;
  CUNT08 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE CUNT08         STOP.
}

VOID iccvBarrelShiftCUNT16(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT16        START.
  CUNT16 *pa=(CUNT16 *)a;
  CUNT16 t0;
  CUNT16 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE CUNT16         STOP.
}

VOID iccvBarrelShiftCUNT32(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT32        START.
  CUNT32 *pa=(CUNT32 *)a;
  CUNT32 t0;
  CUNT32 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE CUNT32         STOP.
}

VOID iccvBarrelShiftCUNT64(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE CUNT64        START.
  CUNT64 *pa=(CUNT64 *)a;
  CUNT64 t0;
  CUNT64 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE CUNT64         STOP.
}

// Handle 3 element vectors.
//-------------------------------------------------------------------------------
VOID iccvBarrelShiftVFLT32(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE VFLT32        START.
  VFLT32 *pa=(VFLT32 *)a;
  VFLT32 t0;
  VFLT32 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE VFLT32         STOP.
}

VOID iccvBarrelShiftVFLT64(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE VFLT64        START.
  VFLT64 *pa=(VFLT64 *)a;
  VFLT64 t0;
  VFLT64 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE VFLT64         STOP.
}

VOID iccvBarrelShiftVFLT96(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE VFLT96        START.
  VFLT96 *pa=(VFLT96 *)a;
  VFLT96 t0;
  VFLT96 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE VFLT96         STOP.
}

VOID iccvBarrelShiftVINT08(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE VINT08     START.
  VINT08 *pa=(VINT08 *)a;
  VINT08 t0;
  VINT08 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE VINT08      STOP.
}

VOID iccvBarrelShiftVINT16(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE VINT16        START.
  VINT16 *pa=(VINT16 *)a;
  VINT16 t0;
  VINT16 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE VINT16         STOP.
}

VOID iccvBarrelShiftVINT32(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE VINT32        START.
  VINT32 *pa=(VINT32 *)a;
  VINT32 t0;
  VINT32 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE VINT32         STOP.
}

VOID iccvBarrelShiftVINT64(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE VINT64        START.
  VINT64 *pa=(VINT64 *)a;
  VINT64 t0;
  VINT64 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE VINT64         STOP.
}

VOID iccvBarrelShiftVUNT08(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT08        START.
  VUNT08 *pa=(VUNT08 *)a;
  VUNT08 t0;
  VUNT08 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE VUNT08         STOP.
}

VOID iccvBarrelShiftVUNT16(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT16        START.
  VUNT16 *pa=(VUNT16 *)a;
  VUNT16 t0;
  VUNT16 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE VUNT16         STOP.
}

VOID iccvBarrelShiftVUNT32(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT32        START.
  VUNT32 *pa=(VUNT32 *)a;
  VUNT32 t0;
  VUNT32 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE VUNT32         STOP.
}

VOID iccvBarrelShiftVUNT64(VOID *a, INT32 i, INT32 shiftBy, UNT32 n)
{
//------------------------------- COMMON-CODE VUNT64        START.
  VUNT64 *pa=(VUNT64 *)a;
  VUNT64 t0;
  VUNT64 t1;
  INT32 jj  =0;
  INT32 ii  =0;
  INT32 ni  =0;
  INT32 add1Index =0;
  //INT32 whogi=n*i; 

  // Mod the shift and check.
  //----------------------------------------------------------------------------
  shiftBy = shiftBy % n;

  if(shiftBy == 0)         // If there is no shift,
  {                        //
    return;                // This is a No-op.
  }                        //
  else if(shiftBy < 0)     // If shift is negative (to the left).
  {                        //
    shiftBy += n;          // Same as positive shift when you add "n".
  }                        //

  // Initialize a perform first pass of the shift loop.
  //----------------------------------------------------------------------------
  ii = 0;                  // Set the "index".
  ni = (ii*i) + shiftBy*i; // Set the "next index"

  t0     = pa[ii];         // Perform a one element shift.
  t1     = pa[ni];         //
  pa[ni] = t0;             //
  t0     = t1;             //

  ii = ni;                 // "index" should now equal "next index".
  ni = (ii*i) + shiftBy*i; // Recalculate "next index".

  ni = ni%(n*i);           // Make sure we wrap if we go to far.

  // Perform the rest of the main shift loop.
  //----------------------------------------------------------------------------
  for (jj=1; jj < n; jj++)
  {
    t1     = pa[ni];       // Perform a one element shift.
    pa[ni] = t0;           //
    t0     = t1;           //

    if (ni ==add1Index)    // Handle the cases where we wrap to an index we
    {                      // have already visited.
      ni = ni + 1*i;
      add1Index = ni;
      ii = ni;
      ni = (ii*i) + shiftBy*i;
      t0 = pa[ii];
    }
    else                   // Else be "normal".
    {
      ii = ni;
      ni = (ii*i) + shiftBy*i;
    }

    ni = ni%(n*i);         // Make sure we wrap if we go too far.
  }
//------------------------------- COMMON-CODE VUNT64         STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/

#if 0

%-------------------------------------------------------------------------------
% Prototype code.  Matlab/Octave.
%-------------------------------------------------------------------------------
clear;

a = zeros(1,1024*3);

a(1:3:1024*3) = 1:1024;            %% Input
i           = 3;                   %% Input
shiftBy     = 998;                 %% Input
n           = 1024; %% Input

ta   = 0;
tb   = 0;
strt = 1; %% Zero for "C"
idx  = (shiftBy*i)+strt;
k    = 0;

ta = tb;
tb=a(idx);
a(idx) = a(strt);
k=k+1;

while(k < n),
  idx=idx+(shiftBy*i);

  if(idx > (n*i)) 
    idx = idx - (n*i);
    ta=tb;
    tb=a(idx);
    a(idx)=ta;
    k=k+1;
  else,
    ta=tb;
    tb=a(idx);
    a(idx)=ta;
    k=k+1;
  end

  if((idx==strt) && (k < n)), 
    ta=0;
    tb=0;
    strt=strt+i;
    idx=(shiftBy*i)+strt;
    ta = tb;
    tb=a(idx);
    a(idx) = a(strt);
    k=k+1;
  end
end

b = shift(1:1024,shiftBy);

sum((a(1:3:1024*3)-b)>0)

#endif


#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa=(XXXXX *)a;
PERL_PREPROCESS  XXXXX ta  =0;
PERL_PREPROCESS  XXXXX tb  =0;
PERL_PREPROCESS  INT32 strt=0;
PERL_PREPROCESS  INT32 idx =(shiftBy*i)+strt;
PERL_PREPROCESS  INT32 k   =0;
PERL_PREPROCESS
PERL_PREPROCESS  ta      = tb;
PERL_PREPROCESS  tb      = pa[idx];
PERL_PREPROCESS  pa[idx] = pa[strt];
PERL_PREPROCESS  k++;
PERL_PREPROCESS
PERL_PREPROCESS  while(k < n)
PERL_PREPROCESS  {
PERL_PREPROCESS    idx = idx+(shiftBy*i);
PERL_PREPROCESS
PERL_PREPROCESS    if(idx > (n*i))
PERL_PREPROCESS    { 
PERL_PREPROCESS      idx    = idx - (n*i);
PERL_PREPROCESS      ta     = tb;
PERL_PREPROCESS      tb     = pa[idx];
PERL_PREPROCESS      pa[idx]= ta;
PERL_PREPROCESS      k++;
PERL_PREPROCESS    }
PERL_PREPROCESS    else
PERL_PREPROCESS    {
PERL_PREPROCESS      ta     = tb;
PERL_PREPROCESS      tb     = pa[idx];
PERL_PREPROCESS      pa[idx]= ta;
PERL_PREPROCESS      k++;
PERL_PREPROCESS    }
PERL_PREPROCESS
PERL_PREPROCESS    if((idx==strt) && (k < n))
PERL_PREPROCESS    {
PERL_PREPROCESS      ta=0;
PERL_PREPROCESS      tb=0;
PERL_PREPROCESS      strt=strt+i;
PERL_PREPROCESS      idx=(shiftBy*i)+strt;
PERL_PREPROCESS      ta = tb;
PERL_PREPROCESS      tb=pa[idx];
PERL_PREPROCESS      pa[idx] = pa[strt];
PERL_PREPROCESS      k++;
PERL_PREPROCESS    }
PERL_PREPROCESS  }
#endif


// Handle complex vectors.
//-------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa=(XXXXX *)a;
PERL_PREPROCESS  XXXXX ta  ={0,0};
PERL_PREPROCESS  XXXXX tb  ={0,0};
PERL_PREPROCESS  INT32 strt=0;
PERL_PREPROCESS  INT32 idx =(shiftBy*i)+strt;
PERL_PREPROCESS  INT32 k   =0;
PERL_PREPROCESS
PERL_PREPROCESS  ta      = tb;
PERL_PREPROCESS  tb      = pa[idx];
PERL_PREPROCESS  pa[idx] = pa[strt];
PERL_PREPROCESS  k++;
PERL_PREPROCESS
PERL_PREPROCESS  while(k < n)
PERL_PREPROCESS  {
PERL_PREPROCESS    idx = idx+(shiftBy*i);
PERL_PREPROCESS
PERL_PREPROCESS    if(idx > (n*i))
PERL_PREPROCESS    { 
PERL_PREPROCESS      idx    = idx - (n*i);
PERL_PREPROCESS      ta     = tb;
PERL_PREPROCESS      tb     = pa[idx];
PERL_PREPROCESS      pa[idx]= ta;
PERL_PREPROCESS      k++;
PERL_PREPROCESS    }
PERL_PREPROCESS    else
PERL_PREPROCESS    {
PERL_PREPROCESS      ta     = tb;
PERL_PREPROCESS      tb     = pa[idx];
PERL_PREPROCESS      pa[idx]= ta;
PERL_PREPROCESS      k++;
PERL_PREPROCESS    }
PERL_PREPROCESS
PERL_PREPROCESS    if((idx==strt) && (k < n))
PERL_PREPROCESS    {
PERL_PREPROCESS      ta.r=0; ta.i=0;
PERL_PREPROCESS      tb.r=0; tb.i=0;
PERL_PREPROCESS      strt=strt+i;
PERL_PREPROCESS      idx=(shiftBy*i)+strt;
PERL_PREPROCESS      ta = tb;
PERL_PREPROCESS      tb=pa[idx];
PERL_PREPROCESS      pa[idx] = pa[strt];
PERL_PREPROCESS      k++;
PERL_PREPROCESS    }
PERL_PREPROCESS  }
#endif

// Handle 3 element vectors.
//-------------------------------------------------------------------------------
#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  XXXXX *pa=(XXXXX *)a;
PERL_PREPROCESS  XXXXX ta  ={0,0,0};
PERL_PREPROCESS  XXXXX tb  ={0,0,0};
PERL_PREPROCESS  INT32 strt=0;
PERL_PREPROCESS  INT32 idx =(shiftBy*i)+strt;
PERL_PREPROCESS  INT32 k   =0;
PERL_PREPROCESS
PERL_PREPROCESS  ta      = tb;
PERL_PREPROCESS  tb      = pa[idx];
PERL_PREPROCESS  pa[idx] = pa[strt];
PERL_PREPROCESS  k++;
PERL_PREPROCESS
PERL_PREPROCESS  while(k < n)
PERL_PREPROCESS  {
PERL_PREPROCESS    idx = idx+(shiftBy*i);
PERL_PREPROCESS
PERL_PREPROCESS    if(idx > (n*i))
PERL_PREPROCESS    { 
PERL_PREPROCESS      idx    = idx - (n*i);
PERL_PREPROCESS      ta     = tb;
PERL_PREPROCESS      tb     = pa[idx];
PERL_PREPROCESS      pa[idx]= ta;
PERL_PREPROCESS      k++;
PERL_PREPROCESS    }
PERL_PREPROCESS    else
PERL_PREPROCESS    {
PERL_PREPROCESS      ta     = tb;
PERL_PREPROCESS      tb     = pa[idx];
PERL_PREPROCESS      pa[idx]= ta;
PERL_PREPROCESS      k++;
PERL_PREPROCESS    }
PERL_PREPROCESS
PERL_PREPROCESS    if((idx==strt) && (k < n))
PERL_PREPROCESS    {
PERL_PREPROCESS      ta.x=0; ta.y=0; ta.z=0;
PERL_PREPROCESS      tb.x=0; tb.y=0; tb.z=0;
PERL_PREPROCESS      strt=strt+i;
PERL_PREPROCESS      idx=(shiftBy*i)+strt;
PERL_PREPROCESS      ta = tb;
PERL_PREPROCESS      tb=pa[idx];
PERL_PREPROCESS      pa[idx] = pa[strt];
PERL_PREPROCESS      k++;
PERL_PREPROCESS    }
PERL_PREPROCESS  }
#endif
