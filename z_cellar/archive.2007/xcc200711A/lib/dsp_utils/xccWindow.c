/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccHandleHistory.c
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
VOID xccBlackmanCreateWindowFLT32( FLT32 *a, INT32 i, UNT32 n )
{
  FLT32 *pa=a;
  FLT32 M=n-1;
  BLACKMAN_COMMON_CODE1
}

VOID xccBlackmanCreateWindowFLT64( FLT64 *a, INT32 i, UNT32 n )
{
  FLT64 *pa=a;
  FLT64 M=n-1;
  BLACKMAN_COMMON_CODE1
}

VOID xccBlackmanCreateWindowFLT96( FLT96 *a, INT32 i, UNT32 n )
{
  FLT96 *pa=a;
  FLT96 M=n-1;
  BLACKMAN_COMMON_CODE1
}

VOID xccBlackmanWindowFLT32( FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n )
{
  FLT32 *pa=a;
  FLT32 *pb=b;
  FLT32 M=n-1;
  FLT32 r;
  BLACKMAN_COMMON_CODE2
}

VOID xccBlackmanWindowFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
  FLT64 *pa=a;
  FLT64 *pb=b;
  FLT64 M=n-1;
  FLT64 r;
  BLACKMAN_COMMON_CODE2
}

VOID xccBlackmanWindowFLT96( FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n )
{
  FLT96 *pa=a;
  FLT96 *pb=b;
  FLT96 M=n-1;
  FLT96 r;
  BLACKMAN_COMMON_CODE2
}

/* Boxcar window -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID xccBoxcarCreateWindowFLT32( FLT32 *a, INT32 i, UNT32 n )
{
  FLT32 *pa=a;
  BOXCAR_COMMON_CODE1
}

VOID xccBoxcarCreateWindowFLT64( FLT64 *a, INT32 i, UNT32 n )
{
  FLT64 *pa=a;
  BOXCAR_COMMON_CODE1
}

VOID xccBoxcarCreateWindowFLT96( FLT96 *a, INT32 i, UNT32 n )
{
  FLT96 *pa=a;
  BOXCAR_COMMON_CODE1
}

VOID xccBoxcarWindowFLT32( FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n )
{
  FLT32 *pa=a;
  FLT32 *pb=b;
  FLT32 r;
  BOXCAR_COMMON_CODE2
}

VOID xccBoxcarWindowFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
  FLT64 *pa=a;
  FLT64 *pb=b;
  FLT64 r;
  BOXCAR_COMMON_CODE2
}

VOID xccBoxcarWindowFLT96( FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n )
{
  FLT96 *pa=a;
  FLT96 *pb=b;
  FLT96 r;
  BOXCAR_COMMON_CODE2
}

/* Hanning window  -----------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID xccHanningCreateWindowFLT32( FLT32 *a, INT32 i, UNT32 n )
{
  FLT32 *pa=a;
  FLT32 M=n-1;
  HANNING_COMMON_CODE1
}

VOID xccHanningCreateWindowFLT64( FLT64 *a, INT32 i, UNT32 n )
{
  FLT64 *pa=a;
  FLT64 M=n-1;
  HANNING_COMMON_CODE1
}

VOID xccHanningCreateWindowFLT96( FLT96 *a, INT32 i, UNT32 n )
{
  FLT96 *pa=a;
  FLT96 M=n-1;
  HANNING_COMMON_CODE1
}

VOID xccHanningWindowFLT32( FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n )
{
  FLT32 *pa=a;
  FLT32 *pb=b;
  FLT32 M=n-1;
  FLT32 r;
  HANNING_COMMON_CODE2
}

VOID xccHanningWindowFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
  FLT64 *pa=a;
  FLT64 *pb=b;
  FLT64 M=n-1;
  FLT64 r;
  HANNING_COMMON_CODE2
}

VOID xccHanningWindowFLT96( FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n )
{
  FLT96 *pa=a;
  FLT96 *pb=b;
  FLT96 M=n-1;
  FLT96 r;
  HANNING_COMMON_CODE2
}

/* Hamming window  -----------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
VOID xccHammingCreateWindowFLT32( FLT32 *a, INT32 i, UNT32 n )
{
  FLT32 *pa=a;
  FLT32 M=n-1;
  HAMMING_COMMON_CODE1
}

VOID xccHammingCreateWindowFLT64( FLT64 *a, INT32 i, UNT32 n )
{
  FLT64 *pa=a;
  FLT64 M=n-1;
  HAMMING_COMMON_CODE1
}

VOID xccHammingCreateWindowFLT96( FLT96 *a, INT32 i, UNT32 n )
{
  FLT96 *pa=a;
  FLT96 M=n-1;
  HAMMING_COMMON_CODE1
}

VOID xccHammingWindowFLT32( FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n )
{
  FLT32 *pa=a;
  FLT32 *pb=b;
  FLT32 M=n-1;
  FLT32 r;
  HAMMING_COMMON_CODE2
}

VOID xccHammingWindowFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n )
{
  FLT64 *pa=a;
  FLT64 *pb=b;
  FLT64 M=n-1;
  FLT64 r;
  HAMMING_COMMON_CODE2
}

VOID xccHammingWindowFLT96( FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n )
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
