/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccEndecUtils.h
// Desc: This is the header file for iccEndecUtils.
// Hist: When       Who  What
//       09/24/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef icc_ENDECUTILS_H
#define icc_ENDECUTILS_H

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
} iccConvEncoderSpec;

typedef struct
{
  INT16 seedi;            // Seed for I channel.
  INT16 seedq;            // Seed for Q channel.
  INT32 length;           // Length of code.
  INT08 pr[MA_PN_LENGTH]; // I channel code.
  INT08 pi[MA_PN_LENGTH]; // Q channel code.
} iccPNSpec;

typedef struct //Set up for 255_223 for now.
{
  UNT08 genPoly;    // Generator Polynomial.
  UNT08 nParity;    // Number of parity symbols. 
  UNT08 gf[256];    // Galois Field.
  INT32 alpha[256]; // Alpha table.
  UNT08 parity[32]; // Parity.
  UNT08 coef[32];
} iccRSEncoderSpec;

struct viterbiState
{
  INT16 number;
  INT08 active;
  UNT32 tMetric[2];
  UNT32 tValue[2];
  INT08 tBit[2];
  iccStackUNT32_t *metricStack;
  iccStackUNT32_t *valueStack;
  iccStackINT08_t *bitStack;
  struct viterbiState *p2ns[2];
}state;

typedef struct
{
  INT32 nStates;
  struct viterbiState state[8]; //Specific during prototype. k=7=>2^6=64
  iccStackINT08_t *bitStack;
  iccStackINT08_t *activeStack;
} iccViterbiSpec;

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
CHR08 iccBaudot(INT32 code);

VOID iccConvEncoder1_2(iccStackINT08_t *inStack, iccStackINT08_t *outStack, INT08 poly1, INT08 poly2);
VOID iccConvEncoderK4R1_2(iccStackINT08_t *inStack, iccStackINT08_t *outStack, INT08 poly1, INT08 poly2);

iccConvEncoderSpec *iccConvEncoder12Init(INT08 k, INT32 poly1, INT32 poly2, INT08 g1Invert, INT08 g2Invert);
VOID iccConv12Encoder(iccStackINT08_t *inStack, iccStackINT08_t *outStack, iccConvEncoderSpec *spec);
VOID iccvConvEncoder12(INT08 *a, INT32 i, INT08 *b, INT32 j, UNT32 n, iccConvEncoderSpec *spec);
VOID iccConvEncoder12Term(iccConvEncoderSpec *spec);
    

INT08 iccHammingWeightINT08(INT08 x, INT08 y);

VOID  iccGenGalois2_8( UNT08 genPoly, UNT08 *galoisField );

UNT16 iccMARCode2SeedI(INT32 userCodeIndex );
UNT16 iccMARCode2SeedQ(INT32 userCodeIndex );
CFLT32 *iccMAReturnPN(UNT16 shiftRegisterA, UNT16 shiftRegisterC );
iccPNSpec *iccMAReturnPNInit( UNT16 shiftRegisterA, UNT16 shiftRegisterC );
VOID iccMAReturnPNTerm( iccPNSpec *spec );

iccRSEncoderSpec *iccRSEncoderInit255_223(UNT08 genPoly);
VOID iccRSEncoderTerm(iccRSEncoderSpec *spec);
VOID iccRSEndcode255_223( UNT08 d, iccRSEncoderSpec *spec);
VOID iccRSEncoderPrintGF(iccRSEncoderSpec *spec);

iccViterbiSpec *iccViterbiInit(INT32 nStates);
VOID iccViterbi(INT08 inValue, iccViterbiSpec *spec);
VOID iccViterbiTerm( iccViterbiSpec *spec);
VOID iccViterbiMetricReport(iccViterbiSpec *spec);
VOID iccViterbiActiveReport(iccViterbiSpec *spec);
VOID iccViterbiBitReport(iccViterbiSpec *spec);
VOID iccViterbiNextStateReport(iccViterbiSpec *spec);

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/

