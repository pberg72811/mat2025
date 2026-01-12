/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccvPitchXYZ.c
// Desc: This file contains the code for the xccOribitUtils routine xccvPitchXYZ.
// Hist: When       Who  What
//       12/04/2003 ptb  Initial Code.
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

//FLT64 pitchXform[9] = { +cos(pitch), +0.0       , -sin(pitch),
//                        +0.0       , +1.0       , +0.0       ,
//                        +sin(pitch), +0.0       , +cos(pitch)};

//FLT64 rollXform[9]  = { +1.0       , +0.0       , +0.0       ,
//                        +0.0       , +cos(roll ), +sin(roll ),
//                        +0.0       , -sin(roll ), +cos(roll )};

//FLT64 yawXform[9]   = { +cos(yaw  ), +sin(yaw  ), +0.0       ,
//                        -sin(yaw  ), +cos(yaw  ), +0.0       ,
//                        +0.0       , +0.0       , +1.0       };


#if 0
PERL_PREPROCESS_START
PERL_PREPROCESS  UNT32 kk;
PERL_PREPROCESS  VXXXXX *pa=a;
PERL_PREPROCESS  VXXXXX *pb=b;
PERL_PREPROCESS  VFLT64 tempA;
PERL_PREPROCESS  VFLT64 tempB;
PERL_PREPROCESS  FLT64 pitchXform[9] = { +cos(pitch), +0.0       , -sin(pitch),
PERL_PREPROCESS                          +0.0       , +1.0       , +0.0       ,
PERL_PREPROCESS                          +sin(pitch), +0.0       , +cos(pitch)};
PERL_PREPROCESS
PERL_PREPROCESS  for(kk=0; kk < n; kk++)
PERL_PREPROCESS  {
PERL_PREPROCESS    tempA.x = pa->x;
PERL_PREPROCESS    tempA.y = pa->y;
PERL_PREPROCESS    tempA.z = pa->z;
PERL_PREPROCESS
PERL_PREPROCESS    xccMatrixCompositeFLT64( pitchXform, 1, 3, 3,
PERL_PREPROCESS                             &tempA.x,   1, 3, 1,
PERL_PREPROCESS                             &tempB.x,   1, 3, 1);
PERL_PREPROCESS
PERL_PREPROCESS    pb->x = tempB.x;
PERL_PREPROCESS    pb->y = tempB.y;
PERL_PREPROCESS    pb->z = tempB.z;
PERL_PREPROCESS
PERL_PREPROCESS    pa+=i;
PERL_PREPROCESS    pb+=j;
PERL_PREPROCESS  }
#endif

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID xccvPitchXYZFLT32( VFLT32 *a, INT32 i, VFLT32 *b, INT32 j, FLT64 pitch, UNT32 n )
{
//------------------------------- COMMON-CODE FLT32     START.
  UNT32 kk;
  VFLT32 *pa=a;
  VFLT32 *pb=b;
  VFLT64 tempA;
  VFLT64 tempB;
  FLT64 pitchXform[9] = { +cos(pitch), +0.0       , -sin(pitch),
                          +0.0       , +1.0       , +0.0       ,
                          +sin(pitch), +0.0       , +cos(pitch)};

  for(kk=0; kk < n; kk++)
  {
    tempA.x = pa->x;
    tempA.y = pa->y;
    tempA.z = pa->z;

    xccMatrixCompositeFLT64( pitchXform, 1, 3, 3,
                             &tempA.x,   1, 3, 1,
                             &tempB.x,   1, 3, 1);

    pb->x = tempB.x;
    pb->y = tempB.y;
    pb->z = tempB.z;

    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE FLT32      STOP.
}

VOID xccvPitchXYZFLT64( VFLT64 *a, INT32 i, VFLT64 *b, INT32 j, FLT64 pitch, UNT32 n )
{
//------------------------------- COMMON-CODE FLT64     START.
  UNT32 kk;
  VFLT64 *pa=a;
  VFLT64 *pb=b;
  VFLT64 tempA;
  VFLT64 tempB;
  FLT64 pitchXform[9] = { +cos(pitch), +0.0       , -sin(pitch),
                          +0.0       , +1.0       , +0.0       ,
                          +sin(pitch), +0.0       , +cos(pitch)};

  for(kk=0; kk < n; kk++)
  {
    tempA.x = pa->x;
    tempA.y = pa->y;
    tempA.z = pa->z;

    xccMatrixCompositeFLT64( pitchXform, 1, 3, 3,
                             &tempA.x,   1, 3, 1,
                             &tempB.x,   1, 3, 1);

    pb->x = tempB.x;
    pb->y = tempB.y;
    pb->z = tempB.z;

    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE FLT64      STOP.
}

VOID xccvPitchXYZFLT96( VFLT96 *a, INT32 i, VFLT96 *b, INT32 j, FLT64 pitch, UNT32 n )
{
//------------------------------- COMMON-CODE FLT96     START.
  UNT32 kk;
  VFLT96 *pa=a;
  VFLT96 *pb=b;
  VFLT64 tempA;
  VFLT64 tempB;
  FLT64 pitchXform[9] = { +cos(pitch), +0.0       , -sin(pitch),
                          +0.0       , +1.0       , +0.0       ,
                          +sin(pitch), +0.0       , +cos(pitch)};

  for(kk=0; kk < n; kk++)
  {
    tempA.x = pa->x;
    tempA.y = pa->y;
    tempA.z = pa->z;

    xccMatrixCompositeFLT64( pitchXform, 1, 3, 3,
                             &tempA.x,   1, 3, 1,
                             &tempB.x,   1, 3, 1);

    pb->x = tempB.x;
    pb->y = tempB.y;
    pb->z = tempB.z;

    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE FLT96      STOP.
}

VOID xccvPitchXYZINT08( VINT08 *a, INT32 i, VINT08 *b, INT32 j, FLT64 pitch, UNT32 n)
{
//------------------------------- COMMON-CODE INT08     START.
  UNT32 kk;
  VINT08 *pa=a;
  VINT08 *pb=b;
  VFLT64 tempA;
  VFLT64 tempB;
  FLT64 pitchXform[9] = { +cos(pitch), +0.0       , -sin(pitch),
                          +0.0       , +1.0       , +0.0       ,
                          +sin(pitch), +0.0       , +cos(pitch)};

  for(kk=0; kk < n; kk++)
  {
    tempA.x = pa->x;
    tempA.y = pa->y;
    tempA.z = pa->z;

    xccMatrixCompositeFLT64( pitchXform, 1, 3, 3,
                             &tempA.x,   1, 3, 1,
                             &tempB.x,   1, 3, 1);

    pb->x = tempB.x;
    pb->y = tempB.y;
    pb->z = tempB.z;

    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE INT08      STOP.
}

VOID xccvPitchXYZINT16( VINT16 *a, INT32 i, VINT16 *b, INT32 j, FLT64 pitch, UNT32 n)
{
//------------------------------- COMMON-CODE INT16          START.
  UNT32 kk;
  VINT16 *pa=a;
  VINT16 *pb=b;
  VFLT64 tempA;
  VFLT64 tempB;
  FLT64 pitchXform[9] = { +cos(pitch), +0.0       , -sin(pitch),
                          +0.0       , +1.0       , +0.0       ,
                          +sin(pitch), +0.0       , +cos(pitch)};

  for(kk=0; kk < n; kk++)
  {
    tempA.x = pa->x;
    tempA.y = pa->y;
    tempA.z = pa->z;

    xccMatrixCompositeFLT64( pitchXform, 1, 3, 3,
                             &tempA.x,   1, 3, 1,
                             &tempB.x,   1, 3, 1);

    pb->x = tempB.x;
    pb->y = tempB.y;
    pb->z = tempB.z;

    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE INT16           STOP.
}

VOID xccvPitchXYZINT32( VINT32 *a, INT32 i, VINT32 *b, INT32 j, FLT64 pitch, UNT32 n)
{
//------------------------------- COMMON-CODE INT32          START.
  UNT32 kk;
  VINT32 *pa=a;
  VINT32 *pb=b;
  VFLT64 tempA;
  VFLT64 tempB;
  FLT64 pitchXform[9] = { +cos(pitch), +0.0       , -sin(pitch),
                          +0.0       , +1.0       , +0.0       ,
                          +sin(pitch), +0.0       , +cos(pitch)};

  for(kk=0; kk < n; kk++)
  {
    tempA.x = pa->x;
    tempA.y = pa->y;
    tempA.z = pa->z;

    xccMatrixCompositeFLT64( pitchXform, 1, 3, 3,
                             &tempA.x,   1, 3, 1,
                             &tempB.x,   1, 3, 1);

    pb->x = tempB.x;
    pb->y = tempB.y;
    pb->z = tempB.z;

    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE INT32           STOP.
}

VOID xccvPitchXYZINT64( VINT64 *a, INT32 i, VINT64 *b, INT32 j, FLT64 pitch, UNT32 n)
{
//------------------------------- COMMON-CODE INT64          START.
  UNT32 kk;
  VINT64 *pa=a;
  VINT64 *pb=b;
  VFLT64 tempA;
  VFLT64 tempB;
  FLT64 pitchXform[9] = { +cos(pitch), +0.0       , -sin(pitch),
                          +0.0       , +1.0       , +0.0       ,
                          +sin(pitch), +0.0       , +cos(pitch)};

  for(kk=0; kk < n; kk++)
  {
    tempA.x = pa->x;
    tempA.y = pa->y;
    tempA.z = pa->z;

    xccMatrixCompositeFLT64( pitchXform, 1, 3, 3,
                             &tempA.x,   1, 3, 1,
                             &tempB.x,   1, 3, 1);

    pb->x = tempB.x;
    pb->y = tempB.y;
    pb->z = tempB.z;

    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE INT64           STOP.
}

VOID xccvPitchXYZUNT08( VUNT08 *a, INT32 i, VUNT08 *b, INT32 j, FLT64 pitch, UNT32 n)
{
//------------------------------- COMMON-CODE UNT08          START.
  UNT32 kk;
  VUNT08 *pa=a;
  VUNT08 *pb=b;
  VFLT64 tempA;
  VFLT64 tempB;
  FLT64 pitchXform[9] = { +cos(pitch), +0.0       , -sin(pitch),
                          +0.0       , +1.0       , +0.0       ,
                          +sin(pitch), +0.0       , +cos(pitch)};

  for(kk=0; kk < n; kk++)
  {
    tempA.x = pa->x;
    tempA.y = pa->y;
    tempA.z = pa->z;

    xccMatrixCompositeFLT64( pitchXform, 1, 3, 3,
                             &tempA.x,   1, 3, 1,
                             &tempB.x,   1, 3, 1);

    pb->x = tempB.x;
    pb->y = tempB.y;
    pb->z = tempB.z;

    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE UNT08           STOP.
}

VOID xccvPitchXYZUNT16( VUNT16 *a, INT32 i, VUNT16 *b, INT32 j, FLT64 pitch, UNT32 n)
{
//------------------------------- COMMON-CODE UNT16          START.
  UNT32 kk;
  VUNT16 *pa=a;
  VUNT16 *pb=b;
  VFLT64 tempA;
  VFLT64 tempB;
  FLT64 pitchXform[9] = { +cos(pitch), +0.0       , -sin(pitch),
                          +0.0       , +1.0       , +0.0       ,
                          +sin(pitch), +0.0       , +cos(pitch)};

  for(kk=0; kk < n; kk++)
  {
    tempA.x = pa->x;
    tempA.y = pa->y;
    tempA.z = pa->z;

    xccMatrixCompositeFLT64( pitchXform, 1, 3, 3,
                             &tempA.x,   1, 3, 1,
                             &tempB.x,   1, 3, 1);

    pb->x = tempB.x;
    pb->y = tempB.y;
    pb->z = tempB.z;

    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE UNT16           STOP.
}

VOID xccvPitchXYZUNT32( VUNT32 *a, INT32 i, VUNT32 *b, INT32 j, FLT64 pitch, UNT32 n)
{
//------------------------------- COMMON-CODE UNT32          START.
  UNT32 kk;
  VUNT32 *pa=a;
  VUNT32 *pb=b;
  VFLT64 tempA;
  VFLT64 tempB;
  FLT64 pitchXform[9] = { +cos(pitch), +0.0       , -sin(pitch),
                          +0.0       , +1.0       , +0.0       ,
                          +sin(pitch), +0.0       , +cos(pitch)};

  for(kk=0; kk < n; kk++)
  {
    tempA.x = pa->x;
    tempA.y = pa->y;
    tempA.z = pa->z;

    xccMatrixCompositeFLT64( pitchXform, 1, 3, 3,
                             &tempA.x,   1, 3, 1,
                             &tempB.x,   1, 3, 1);

    pb->x = tempB.x;
    pb->y = tempB.y;
    pb->z = tempB.z;

    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE UNT32           STOP.
}

VOID xccvPitchXYZUNT64( VUNT64 *a, INT32 i, VUNT64 *b, INT32 j, FLT64 pitch, UNT32 n)
{
//------------------------------- COMMON-CODE UNT64          START.
  UNT32 kk;
  VUNT64 *pa=a;
  VUNT64 *pb=b;
  VFLT64 tempA;
  VFLT64 tempB;
  FLT64 pitchXform[9] = { +cos(pitch), +0.0       , -sin(pitch),
                          +0.0       , +1.0       , +0.0       ,
                          +sin(pitch), +0.0       , +cos(pitch)};

  for(kk=0; kk < n; kk++)
  {
    tempA.x = pa->x;
    tempA.y = pa->y;
    tempA.z = pa->z;

    xccMatrixCompositeFLT64( pitchXform, 1, 3, 3,
                             &tempA.x,   1, 3, 1,
                             &tempB.x,   1, 3, 1);

    pb->x = tempB.x;
    pb->y = tempB.y;
    pb->z = tempB.z;

    pa+=i;
    pb+=j;
  }
//------------------------------- COMMON-CODE UNT64           STOP.
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
