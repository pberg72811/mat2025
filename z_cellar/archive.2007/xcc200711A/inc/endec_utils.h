/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccEndecUtils.h
// Desc: This is the header file for xccEndecUtils.
// Hist: When       Who  What
//       09/24/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef xcc_ENDECUTILS_H
#define xcc_ENDECUTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "xmc.h"
#include "malloc_utils.h"
#include "stack_utils.h"
#include "vector_utils.h"


/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define MA_USER_CODES  160
#define MA_PN_LENGTH   2047
#define K_MAX          32

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
typedef struct
{
  INT32 k;              // Constraint length. Maximum is 32
  INT32 poly1;          // Taps for G1.
  INT32 poly2;          // Taps for G2.
  INT08 g1Invert;       // Invert flag for G1.
  INT08 g2Invert;       // Invert flag for G2.
  INT08 regVector[32];  // Register vector.
  INT08 g1Vector[32];   // G1 vector.
  INT08 g2Vector[32];   // G2 vector.
} xccConvEncoderSpec;

typedef struct
{
  INT16 seedi;            // Seed for I channel.
  INT16 seedq;            // Seed for Q channel.
  INT32 length;           // Length of code.
  INT08 pr[MA_PN_LENGTH]; // I channel code.
  INT08 pi[MA_PN_LENGTH]; // Q channel code.
} xccPNSpec;

typedef struct //Set up for 255_223 for now.
{
  UNT08 genPoly;    // Generator Polynomial.
  UNT08 nParity;    // Number of parity symbols. 
  UNT08 gf[256];    // Galois Field.
  INT32 alpha[256]; // Alpha table.
  UNT08 parity[32]; // Parity.
  UNT08 coef[32];
} xccRSEncoderSpec;

struct viterbiState
{
  INT16 number;
  INT08 active;
  UNT32 tMetric[2];
  UNT32 tValue[2];
  INT08 tBit[2];
  xccStackUNT32_t *metricStack;
  xccStackUNT32_t *valueStack;
  xccStackINT08_t *bitStack;
  struct viterbiState *p2ns[2];
}state;

typedef struct
{
  INT32 nStates;
  struct viterbiState state[8]; //Specific during prototype. k=7=>2^6=64
  xccStackINT08_t *bitStack;
  xccStackINT08_t *activeStack;
} xccViterbiSpec;

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
CHR08 xccBaudot(INT32 code);

VOID xccConvEncoder1_2(xccStackINT08_t *inStack, xccStackINT08_t *outStack, INT08 poly1, INT08 poly2);
VOID xccConvEncoderK4R1_2(xccStackINT08_t *inStack, xccStackINT08_t *outStack, INT08 poly1, INT08 poly2);

xccConvEncoderSpec *xccConvEncoder12Init(INT08 k, INT32 poly1, INT32 poly2, INT08 g1Invert, INT08 g2Invert);
VOID xccConv12Encoder(xccStackINT08_t *inStack, xccStackINT08_t *outStack, xccConvEncoderSpec *spec);
VOID xccvConvEncoder12(INT08 *a, INT32 i, INT08 *b, INT32 j, UNT32 n, xccConvEncoderSpec *spec);
VOID xccConvEncoder12Term(xccConvEncoderSpec *spec);
    

INT08 xccHammingWeightINT08(INT08 x, INT08 y);

VOID  xccGenGalois2_8( UNT08 genPoly, UNT08 *galoisField );

UNT16 xccMARCode2SeedI(INT32 userCodeIndex );
UNT16 xccMARCode2SeedQ(INT32 userCodeIndex );
CFLT32 *xccMAReturnPN(UNT16 shiftRegisterA, UNT16 shiftRegisterC );
xccPNSpec *xccMAReturnPNInit( UNT16 shiftRegisterA, UNT16 shiftRegisterC );
VOID xccMAReturnPNTerm( xccPNSpec *spec );

xccRSEncoderSpec *xccRSEncoderInit255_223(UNT08 genPoly);
VOID xccRSEncoderTerm(xccRSEncoderSpec *spec);
VOID xccRSEndcode255_223( UNT08 d, xccRSEncoderSpec *spec);
VOID xccRSEncoderPrintGF(xccRSEncoderSpec *spec);

xccViterbiSpec *xccViterbiInit(INT32 nStates);
VOID xccViterbi(INT08 inValue, xccViterbiSpec *spec);
VOID xccViterbiTerm( xccViterbiSpec *spec);
VOID xccViterbiMetricReport(xccViterbiSpec *spec);
VOID xccViterbiActiveReport(xccViterbiSpec *spec);
VOID xccViterbiBitReport(xccViterbiSpec *spec);
VOID xccViterbiNextStateReport(xccViterbiSpec *spec);

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/

