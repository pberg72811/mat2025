/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccHandleHistory.c
// Desc: This file contains the code for the DSP utils handle history routines.
// Hist: When       Who  What
//       04/27/2001 ptb  Initial Code.
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
#define BLACKMAN_COMMON_CODE1 UNT32 k;  \
                     for(k=0; k<n; k++) \
                     {                  \
                       *pa = 0.42 - 0.50*cos(TWOPI*k/M) + 0.08*cos(FOURPI*k/M); \
                       pa+=i;           \
		     }

#define BLACKMAN_COMMON_CODE2 UNT32 k;  \
                     for(k=0; k<n; k++) \
                     {                  \
                       r = 0.42 - 0.50*cos(TWOPI*k/M) + 0.08*cos(FOURPI*k/M); \
                       *pb = r * *pa;   \
                       pa+=i; pb+=j;    \
		     }

#define BOXCAR_COMMON_CODE1 UNT32 k;    \
                     for(k=0; k<n; k++) \
                     {                  \
                       *pa = 1.0;       \
                       pa+=i;           \
		     }

#define BOXCAR_COMMON_CODE2 UNT32 k;    \
                     for(k=0; k<n; k++) \
                     {                  \
                       r = 1.0;         \
                       *pb = r * *pa;   \
                       pa+=i; pb+=j;    \
		     }

#define HANNING_COMMON_CODE1 UNT32 k;   \
                     for(k=0; k<n; k++) \
                     {                  \
                       *pa = 0.50 - 0.50*cos(TWOPI*k/M); \
                       pa+=i;           \
		     }

#define HANNING_COMMON_CODE2 UNT32 k;   \
                     for(k=0; k<n; k++) \
                     {                  \
                       r = 0.50 - 0.50*cos(TWOPI*k/M); \
                       *pb = r * *pa;   \
                       pa+=i; pb+=j;    \
		     }

#define HAMMING_COMMON_CODE1 UNT32 k;   \
                     for(k=0; k<n; k++) \
                     {                  \
                       *pa = 0.54 - 0.46*cos(TWOPI*k/M); \
                       pa+=i;           \
		     }

#define HAMMING_COMMON_CODE2 UNT32 k;   \
                     for(k=0; k<n; k++) \
                     {                  \
                       r = 0.54 - 0.46*cos(TWOPI*k/M); \
                       *pb = r * *pa;   \
                       pa+=i; pb+=j;    \
		     }

/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Blackman window -----------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccBlackmanCreateWindowFLT32( FLT32 *a, INT32 i, UNT32 n )
{
  FLT32 *pa=a;
  FLT32 M=n-1;
  BLACKMAN_COMMON_CODE1
}

VOID iccBlackmanCreateWindowFLT64( FLT64 *a, INT32 i, UNT32 n )
{
  FLT64 *pa=a;
  FLT64 M=n-1;
  BLACKMAN_COMMON_CODE1
}

VOID iccBlackmanCreateWindowFLT96( FLT96 *a, INT32 i, UNT32 n )
{
  FLT96 *pa=a;
  FLT96 M=n-1;
  BLACKMAN_COMMON_CODE1
}

VOID iccBlackmanWindowFLT32( FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n )
{
  FLT32 *pa=a;
  FLT32 *pb=b;
  FLT32 M=n-1;
  FLT32 r;
  BLACKMAN_COMMON_CODE2
}

VOID iccBlackmanWindowFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
  FLT64 *pa=a;
  FLT64 *pb=b;
  FLT64 M=n-1;
  FLT64 r;
  BLACKMAN_COMMON_CODE2
}

VOID iccBlackmanWindowFLT96( FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n )
{
  FLT96 *pa=a;
  FLT96 *pb=b;
  FLT96 M=n-1;
  FLT96 r;
  BLACKMAN_COMMON_CODE2
}

/* Boxcar window -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccBoxcarCreateWindowFLT32( FLT32 *a, INT32 i, UNT32 n )
{
  FLT32 *pa=a;
  BOXCAR_COMMON_CODE1
}

VOID iccBoxcarCreateWindowFLT64( FLT64 *a, INT32 i, UNT32 n )
{
  FLT64 *pa=a;
  BOXCAR_COMMON_CODE1
}

VOID iccBoxcarCreateWindowFLT96( FLT96 *a, INT32 i, UNT32 n )
{
  FLT96 *pa=a;
  BOXCAR_COMMON_CODE1
}

VOID iccBoxcarWindowFLT32( FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n )
{
  FLT32 *pa=a;
  FLT32 *pb=b;
  FLT32 r;
  BOXCAR_COMMON_CODE2
}

VOID iccBoxcarWindowFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
  FLT64 *pa=a;
  FLT64 *pb=b;
  FLT64 r;
  BOXCAR_COMMON_CODE2
}

VOID iccBoxcarWindowFLT96( FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n )
{
  FLT96 *pa=a;
  FLT96 *pb=b;
  FLT96 r;
  BOXCAR_COMMON_CODE2
}

/* Hanning window  -----------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccHanningCreateWindowFLT32( FLT32 *a, INT32 i, UNT32 n )
{
  FLT32 *pa=a;
  FLT32 M=n-1;
  HANNING_COMMON_CODE1
}

VOID iccHanningCreateWindowFLT64( FLT64 *a, INT32 i, UNT32 n )
{
  FLT64 *pa=a;
  FLT64 M=n-1;
  HANNING_COMMON_CODE1
}

VOID iccHanningCreateWindowFLT96( FLT96 *a, INT32 i, UNT32 n )
{
  FLT96 *pa=a;
  FLT96 M=n-1;
  HANNING_COMMON_CODE1
}

VOID iccHanningWindowFLT32( FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n )
{
  FLT32 *pa=a;
  FLT32 *pb=b;
  FLT32 M=n-1;
  FLT32 r;
  HANNING_COMMON_CODE2
}

VOID iccHanningWindowFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
  FLT64 *pa=a;
  FLT64 *pb=b;
  FLT64 M=n-1;
  FLT64 r;
  HANNING_COMMON_CODE2
}

VOID iccHanningWindowFLT96( FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n )
{
  FLT96 *pa=a;
  FLT96 *pb=b;
  FLT96 M=n-1;
  FLT96 r;
  HANNING_COMMON_CODE2
}

/* Hamming window  -----------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID iccHammingCreateWindowFLT32( FLT32 *a, INT32 i, UNT32 n )
{
  FLT32 *pa=a;
  FLT32 M=n-1;
  HAMMING_COMMON_CODE1
}

VOID iccHammingCreateWindowFLT64( FLT64 *a, INT32 i, UNT32 n )
{
  FLT64 *pa=a;
  FLT64 M=n-1;
  HAMMING_COMMON_CODE1
}

VOID iccHammingCreateWindowFLT96( FLT96 *a, INT32 i, UNT32 n )
{
  FLT96 *pa=a;
  FLT96 M=n-1;
  HAMMING_COMMON_CODE1
}

VOID iccHammingWindowFLT32( FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n )
{
  FLT32 *pa=a;
  FLT32 *pb=b;
  FLT32 M=n-1;
  FLT32 r;
  HAMMING_COMMON_CODE2
}

VOID iccHammingWindowFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
  FLT64 *pa=a;
  FLT64 *pb=b;
  FLT64 M=n-1;
  FLT64 r;
  HAMMING_COMMON_CODE2
}

VOID iccHammingWindowFLT96( FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n )
{
  FLT96 *pa=a;
  FLT96 *pb=b;
  FLT96 M=n-1;
  FLT96 r;
  HAMMING_COMMON_CODE2
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/ 
/*-------------------------------UNCLASSIFIED---------------------------------*/
