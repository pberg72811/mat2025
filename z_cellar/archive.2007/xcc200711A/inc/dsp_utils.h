/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: dsp_utils.h
// Desc: This is the header file for dsp_util.
// Hist: When       Who  What
//       07/08/2002 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifndef DSP_UTILS_H
#define DSP_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "xmc.h"
#include "malloc_utils.h"
#include "orbit_utils.h"
#include "stack_utils.h"
#include "vector_utils.h"
#include <stdarg.h>

/* Constants -----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#define IIRMAXPOLES 16

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
typedef struct               // Up Sampler SPECIFICATION.
{                            //
  FLT32 fb;                  // Baud Rate.  For lack of a better term.
  FLT32 fs;                  // Sample Rate.
  FLT32 phs;                 // Time phase.
  INT32 nb;                  // Total number of Baud.
  FLT32 delta;               // Calculated delta.
  FLT32 indexF;              // Index in floating format.
  UNT32 indexI;              // Index in integer format.
  INT32 doneFlag;            // Flag to let you know data bits are exhausted.
} xccUpSampleSpecFLT32;

typedef struct               // Up Sampler SPECIFICATION.
{                            //
  FLT64 fb;                  // Baud Rate.  For lack of a better term.
  FLT64 fs;                  // Sample Rate.
  FLT64 phs;                 // Time phase.
  INT32 nb;                  // Number of Baud.
  FLT64 delta;               // Calculated delta.
  FLT64 indexF;              // Index in floating format.
  UNT32 indexI;              // Index in integer format.
  INT32 doneFlag;            // Flag to let you know data bits are exhausted.
  UNT32 totalSamples;        //
} xccUpSampleSpecFLT64;

typedef struct               // Resampler SPECIFICATION.
{                            //
  FLT64 fb;                  // Baud Rate.  For lack of a better term.
  FLT64 fs;                  // Sample Rate.
  FLT64 phs;                 // Sample phase.
  FLT64 nb;                  // Number of Baud.
  FLT64 delta;               // Calculated delta.
  FLT64 indexF;              // Index in floating format.
  UNT32 indexI;              // Index in integer format.
} xccResampleSpec;

typedef struct               // BIT DESCISION SPECIFICATION.
{
  FLT64 fb;                  // Baud rate.
  FLT64 fs;                  // Sample rate.
  FLT64 delta;               // Delta.
  FLT64 clckPhi;             // Clock phase.
  FLT64 clckNew;             // Clock value for zero cross detection.
  FLT64 clckOld;             // Clock value for zero cross detection.
  FLT64 dataNew;             // Data value for zero cross detection.
  FLT64 dataOld;             // Data value for zero cross detection.
  INT32 batch;               // Batch index.
  INT32 decimation;          // Decimation value.
  INT32 dataZeroCrossOne;    // Flag to indicate first zero crossing of data.
  INT32 dataZeroCrossOld;    // Index of data value for zero cross detection.
  INT32 dataZeroCrossNew;    // Index of data value for zero cross detection.
  INT32 clckZeroCrossOld;    // Index of clock value for zero cross detection.
  INT32 clckZeroCrossNew;    // Index of clock value for zero cross detection.
  xccStackINT08_t *bitStack; // Bit stack to store the values.
} xccBitDescisionSpec;

typedef struct               // FIR FILTER SPECIFICATION.
{
  INT32 nTaps;               // Number of taps.
  INT32 nHist;               // Number of history points.  (nTaps-1).
  FLT32 *fw;                 // Filter weights array.
  FLT32 *fh;                 // Filter history array.
  FLT32 *fd;                 // Filter data array.
} xccFIRFilterSpecFLT32;

typedef struct               // FIR FILTER SPECIFICATION.
{
  INT32 nTaps;               // Number of taps.
  INT32 nHist;               // Number of history points.  (nTaps-1).
  FLT64 *fw;                 // Filter weights array.
  FLT64 *fh;                 // Filter history array.
  FLT64 *fd;                 // Filter data array.
} xccFIRFilterSpecFLT64;

typedef struct               // FIR FILTER SPECIFICATION.
{
  INT32 nTaps;               // Number of taps.
  INT32 nHist;               // Number of history points.  (nTaps-1).
  FLT96 *fw;                 // Filter weights array.
  FLT96 *fh;                 // Filter history array.
  FLT96 *fd;                 // Filter data array.
} xccFIRFilterSpecFLT96;

typedef struct               // IIR FILTER SPECIFICATION.
{
  FLT32 f;                   // Center frequency percent (fc/fs).
  FLT32 BW;                  // Bandwidth.
  FLT32 R;
  FLT32 K;
  INT32 NP;                  // Number of Poles.
  FLT32 a[IIRMAXPOLES+1];    // a coefficients.
  FLT32 b[IIRMAXPOLES+1];    // b coefficiets.
  FLT32 xii_[IIRMAXPOLES+1]; // x history.
  FLT32 yii_[IIRMAXPOLES+1]; // y history.
}xccIIRFilterSpec;

typedef struct               // SIGNAL GENERATOR SPECIFICATION.
{
  FLT32 fc;                  // Frequency.
  FLT32 fs;                  // Sample rate.
  FLT32 delta;               // Radians per sample. 2*pi*fc/fs.  
  FLT32 phi;                 // Phase.
  FLT32 amp;                 // Amplitude.
} xccSigGenSpecFLT32;

typedef struct               // SIGNAL GENERATOR SPECIFICATION.
{
  FLT64 fc;                  // Frequency.
  FLT64 fs;                  // Sample rate.
  FLT64 delta;               // Radians per sample. 2*pi*fc/fs.  
  FLT64 phi;                 // Phase.
  FLT64 amp;                 // Amplitude.
} xccSigGenSpecFLT64;

typedef struct               // SIGNAL GENERATOR SPECIFICATION.
{
  FLT96 fc;                  // Frequency.
  FLT96 fs;                  // Sample rate.
  FLT96 delta;               // Radians per sample. 2*pi*fc/fs.  
  FLT96 phi;                 // Phase.
  FLT96 amp;                 // Amplitude.
} xccSigGenSpecFLT96;

typedef struct               // SIGNAL GENERATOR SPECIFICATION.
{
  FLT32 fc;                  // Frequency.
  FLT32 fa;                  // Frequency acceleration.
  FLT32 fs;                  // Sample rate.
  FLT32 delta1;              // Radians per sample. 2*pi*fc/fs.  
  FLT32 delta2;              // Radians per sample per sample. 2*pi*fc/fs/fs.  
  FLT32 phi;                 // Phase.
  FLT32 amp;                 // Amplitude.
} xccSigSigGenSpecFLT32;

typedef struct               // SIGNAL GENERATOR SPECIFICATION.
{
  FLT64 fc;                  // Frequency.
  FLT64 fa;                  // Frequency acceleration.
  FLT64 fs;                  // Sample rate.
  FLT64 delta1;              // Radians per sample. 2*pi*fc/fs.  
  FLT64 delta2;              // Radians per sample per sample. 2*pi*fc/fs/fs.  
  FLT64 phi;                 // Phase.
  FLT64 amp;                 // Amplitude.
} xccSigSigGenSpecFLT64;

typedef struct               // SIGNAL GENERATOR SPECIFICATION.
{
  FLT96 fc;                  // Frequency.
  FLT96 fa;                  // Frequency acceleration.
  FLT96 fs;                  // Sample rate.
  FLT96 delta1;              // Radians per sample. 2*pi*fc/fs.  
  FLT96 delta2;              // Radians per sample per sample. 2*pi*fc/fs/fs.  
  FLT96 phi;                 // Phase.
  FLT96 amp;                 // Amplitude.
} xccSigSigGenSpecFLT96;

typedef struct               // COSTAS LOOP SPECIFICATION.
{
  FLT32 fc;                  // Frequency.
  FLT32 fs;                  // Sample rate.
  FLT32 delta;               // Radians per sample. 2*pi*fc/fs.
  FLT32 phi;                 // Phase.
  xccIIRFilterSpec *iirSpecI;    // I rail filter specification.
  xccIIRFilterSpec *iirSpecQ;    // Q rail filter specification
  xccIIRFilterSpec *iirSpecLoop; // Loop filter.
}xccCostasLoopSpec;

typedef struct             // RandM noise generation specification.
{
  UNT32 tableSize;         // Size of noise table.
  UNT64 seed;              // 64 bit seed.
  FLT32 *noiseTableFLT32;  // Noise table.
  FLT64 *noiseTableFLT64;  // Noise table.
  FLT96 *noiseTableFLT96;  // Noise table.
  INT08 *noiseTableINT08;  // Noise table.
  INT16 *noiseTableINT16;  // Noise table.
  INT32 *noiseTableINT32;  // Noise table.
  INT64 *noiseTableINT64;  // Noise table.
  VOID  *noiseTableVOID;   // Noise table.
} xccvRandMSpec;

typedef struct             // VCO SPECIFICATION.
{                          //
  FLT64 centerFrequency;   // Center frequency.
  FLT64 fs;                // Sample rate.
  FLT64 fc;                // Current frequency.
  FLT64 delta;             // Sample period.
  FLT64 phase;             // Phase.
} xccVCOSpec;

typedef struct             // VCO SPECIFICATION.
{                          //
  FLT64 lockInRange;       // Lock in range.
  FLT64 dampingFactor;     // Damping factor.
  FLT64 Kd;                //
  FLT64 Ko;                //
  FLT64 fs;                // Sample rate.
  FLT64 Kp;                // Proportional coefficient.
  FLT64 Ki;                // Integral coefficient.
  FLT64 samplePeriod;      // Sample period.
  FLT64 naturalFrequency;  // radians/sec.
  FLT64 noiseBW;           // radians/sec.
  FLT64 sum;               // Integrator sum.
  FLT64 integratorLimit;   // Integrator limit.
} xccLoopFilterSpec;

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

/* Signal generator functions ------------------------------------------------*/
xccSigGenSpecFLT32 *xccSigGenInitFLT32(FLT32 fc, FLT32 fs, FLT32 amp, FLT32 phs);
xccSigGenSpecFLT64 *xccSigGenInitFLT64(FLT64 fc, FLT64 fs, FLT64 amp, FLT64 phs);
xccSigGenSpecFLT96 *xccSigGenInitFLT96(FLT96 fc, FLT96 fs, FLT96 amp, FLT96 phs);

VOID xccSigGenModFLT32(FLT32 fc, FLT32 fs, FLT32 amp, FLT32 phs, xccSigGenSpecFLT32 *spec);
VOID xccSigGenModFLT64(FLT64 fc, FLT64 fs, FLT64 amp, FLT64 phs, xccSigGenSpecFLT64 *spec);
VOID xccSigGenModFLT96(FLT96 fc, FLT96 fs, FLT96 amp, FLT96 phs, xccSigGenSpecFLT96 *spec);

VOID xccSigGenCosFLT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosFLT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosFLT96(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosINT08(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosINT16(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosINT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosINT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosUNT08(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosUNT16(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosUNT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosUNT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenSinFLT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenSinFLT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenSinFLT96(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenSinINT08(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenSinINT16(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenSinINT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenSinINT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenSinUNT08(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenSinUNT16(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenSinUNT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenSinUNT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosSinCFLT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosSinCFLT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosSinCFLT96(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosSinCINT08(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosSinCINT16(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosSinCINT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosSinCINT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosSinCUNT08(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosSinCUNT16(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosSinCUNT32(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );
VOID xccSigGenCosSinCUNT64(VOID *y, INT32 i, INT32 n, xccSigGenSpecFLT64 *spec );

VOID xccSigGenTermFLT32(xccSigGenSpecFLT32 *spec);
VOID xccSigGenTermFLT64(xccSigGenSpecFLT64 *spec);
VOID xccSigGenTermFLT96(xccSigGenSpecFLT96 *spec);

/* Signal generator functions ------------------------------------------------*/
xccSigSigGenSpecFLT32 *xccSigSigGenInitFLT32(FLT32 fc, FLT32 fa, FLT32 fs, FLT32 amp, FLT32 phs);
xccSigSigGenSpecFLT64 *xccSigSigGenInitFLT64(FLT64 fc, FLT64 fa, FLT64 fs, FLT64 amp, FLT64 phs);
xccSigSigGenSpecFLT96 *xccSigSigGenInitFLT96(FLT96 fc, FLT96 fa, FLT96 fs, FLT96 amp, FLT96 phs);

VOID xccSigSigGenCosFLT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosFLT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosFLT96(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosINT08(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosINT16(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosINT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosINT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosUNT08(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosUNT16(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosUNT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosUNT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenSinFLT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenSinFLT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenSinFLT96(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenSinINT08(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenSinINT16(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenSinINT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenSinINT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenSinUNT08(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenSinUNT16(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenSinUNT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenSinUNT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosSinCFLT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosSinCFLT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosSinCFLT96(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosSinCINT08(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosSinCINT16(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosSinCINT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosSinCINT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosSinCUNT08(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosSinCUNT16(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosSinCUNT32(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );
VOID xccSigSigGenCosSinCUNT64(VOID *y, INT32 i, INT32 n, xccSigSigGenSpecFLT64 *spec );

VOID xccSigSigGenTermFLT32(xccSigSigGenSpecFLT32 *spec);
VOID xccSigSigGenTermFLT64(xccSigSigGenSpecFLT64 *spec);
VOID xccSigSigGenTermFLT96(xccSigSigGenSpecFLT96 *spec);



/* Handle history functions --------------------------------------------------*/
VOID handleHistoryFLT32(FLT32 *data, INT32 dataSize, FLT32 *hist, INT32 histSize, FLT32 *newbuf);
VOID handleHistoryFLT64(FLT64 *data, INT32 dataSize, FLT64 *hist, INT32 histSize, FLT64 *newbuf);
VOID handleHistoryFLT96(FLT96 *data, INT32 dataSize, FLT96 *hist, INT32 histSize, FLT96 *newbuf);
VOID handleHistoryINT08(INT08 *data, INT32 dataSize, INT08 *hist, INT32 histSize, INT08 *newbuf);
VOID handleHistoryINT16(INT16 *data, INT32 dataSize, INT16 *hist, INT32 histSize, INT16 *newbuf);
VOID handleHistoryINT32(INT32 *data, INT32 dataSize, INT32 *hist, INT32 histSize, INT32 *newbuf);
VOID handleHistoryINT64(INT64 *data, INT32 dataSize, INT64 *hist, INT32 histSize, INT64 *newbuf);
VOID handleHistoryUNT08(UNT08 *data, INT32 dataSize, UNT08 *hist, INT32 histSize, UNT08 *newbuf);
VOID handleHistoryUNT16(UNT16 *data, INT32 dataSize, UNT16 *hist, INT32 histSize, UNT16 *newbuf);
VOID handleHistoryUNT32(UNT32 *data, INT32 dataSize, UNT32 *hist, INT32 histSize, UNT32 *newbuf);
VOID handleHistoryUNT64(UNT64 *data, INT32 dataSize, UNT64 *hist, INT32 histSize, UNT64 *newbuf);

/* vdft functions ------------------------------------------------------------*/
VOID  xccDFTFLT32_R(FLT32 *iData, FLT32 *oData, UNT32 n );
VOID  xccDFTFLT32_C(FLT32 *iData, FLT32 *oData, UNT32 n );

/* FFT functions -------------------------------------------------------------*/
UNT32 xccFFTBitReverse(INT32 iidex, INT32 nBits);
VOID  xcc2ptButterflyFLT32_R(FLT32 *iData0, FLT32 *iData1, FLT32 *oData);
VOID  xcc2ptButterflyFLT32_C(FLT32 *iData0, FLT32 *iData1, FLT32 *oData);
VOID  xccNptButterflyFLT32 (FLT32 *iData, INT32 N, INT08 ifftFlag );
//VOID  xccIFFTFLT32 (FLT32 *iData, FLT32 *oData,  UNT32 N );
//VOID  xccFFTFLT32_X(FLT32 *iData, FLT32 *oData,  UNT32 N, INT08 realFlag, INT08 ifftFlag );

VOID  xccFFTINT08_R (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccFFTINT08_C (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccFFTINT16_R (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccFFTINT16_C (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccFFTINT32_R (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccFFTINT32_C (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccFFTUNT08_R (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccFFTUNT08_C (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccFFTUNT16_R (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccFFTUNT16_C (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccFFTUNT32_R (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccFFTUNT32_C (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccFFTFLT32_R (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccFFTFLT32_C (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccFFTFLT64_R (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccFFTFLT64_C (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccIFFTINT08_R(VOID  *iData, FLT32 *oData, UNT32 N); //REAL IFFT?
VOID  xccIFFTINT08_C(VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccIFFTINT16_R(VOID  *iData, FLT32 *oData, UNT32 N); //REAL IFFT?
VOID  xccIFFTINT16_C(VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccIFFTINT32_R(VOID  *iData, FLT32 *oData, UNT32 N); //REAL IFFT?
VOID  xccIFFTINT32_C(VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccIFFTUNT08_R(VOID  *iData, FLT32 *oData, UNT32 N); //REAL IFFT?
VOID  xccIFFTUNT08_C(VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccIFFTUNT16_R(VOID  *iData, FLT32 *oData, UNT32 N); //REAL IFFT?
VOID  xccIFFTUNT16_C(VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccIFFTUNT32_R(VOID  *iData, FLT32 *oData, UNT32 N); //REAL IFFT?
VOID  xccIFFTUNT32_C(VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccIFFTFLT32_R(VOID  *iData, FLT32 *oData, UNT32 N); //REAL IFFT?
VOID  xccIFFTFLT32_C(VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccIFFTFLT64_R(VOID  *iData, FLT32 *oData, UNT32 N); //REAL IFFT?
VOID  xccIFFTFLT64_C(VOID  *iData, FLT32 *oData, UNT32 N);
VOID  xccFFTINT08_X(INT08 *iData, FLT32 *oData, UNT32 N, INT08 realFlag, INT08 ifftFlag);
VOID  xccFFTINT16_X(INT16 *iData, FLT32 *oData, UNT32 N, INT08 realFlag, INT08 ifftFlag);
VOID  xccFFTINT32_X(INT32 *iData, FLT32 *oData, UNT32 N, INT08 realFlag, INT08 ifftFlag);
VOID  xccFFTUNT08_X(UNT08 *iData, FLT32 *oData, UNT32 N, INT08 realFlag, INT08 ifftFlag);
VOID  xccFFTUNT16_X(UNT16 *iData, FLT32 *oData, UNT32 N, INT08 realFlag, INT08 ifftFlag);
VOID  xccFFTUNT32_X(UNT32 *iData, FLT32 *oData, UNT32 N, INT08 realFlag, INT08 ifftFlag);
VOID  xccFFTFLT32_X(FLT32 *iData, FLT32 *oData, UNT32 N, INT08 realFlag, INT08 ifftFlag);
VOID  xccFFTFLT64_X(FLT64 *iData, FLT32 *oData, UNT32 N, INT08 realFlag, INT08 ifftFlag);

/* FFT functions -------------------------------------------------------------*/
//VOID xccFFTrFLT32(FLT32 *inData, FLT32 *outData, UNT32 nElements);
//VOID xccFFTcFLT32(FLT32 *inData, FLT32 *outData, UNT32 nElements);
//VOID xccIFFTFLT32(FLT32 *inData, FLT32 *outData, UNT32 nElements);

/* FIR functions -------------------------------------------------------------*/
xccFIRFilterSpecFLT32 *xccFIRFilterInitLPFLT32(FLT32 fc, FLT32 fs, INT32 nTaps);
xccFIRFilterSpecFLT64 *xccFIRFilterInitLPFLT64(FLT64 fc, FLT64 fs, INT32 nTaps);
xccFIRFilterSpecFLT96 *xccFIRFilterInitLPFLT96(FLT96 fc, FLT96 fs, INT32 nTaps);
xccFIRFilterSpecFLT32 *xccFIRFilterInitHPFLT32(FLT32 fc, FLT32 fs, INT32 nTaps);
xccFIRFilterSpecFLT64 *xccFIRFilterInitHPFLT64(FLT64 fc, FLT64 fs, INT32 nTaps);
xccFIRFilterSpecFLT96 *xccFIRFilterInitHPFLT96(FLT96 fc, FLT96 fs, INT32 nTaps);
xccFIRFilterSpecFLT32 *xccFIRFilterInitBPFLT32(FLT32 fc, FLT32 bw, FLT32 fs, INT32 nTaps);
xccFIRFilterSpecFLT64 *xccFIRFilterInitBPFLT64(FLT64 fc, FLT64 bw, FLT64 fs, INT32 nTaps);
xccFIRFilterSpecFLT96 *xccFIRFilterInitBPFLT96(FLT96 fc, FLT96 bw, FLT96 fs, INT32 nTaps);
xccFIRFilterSpecFLT32 *xccFIRFilterInitAccFLT32(INT32 nTaps);
xccFIRFilterSpecFLT64 *xccFIRFilterInitAccFLT64(INT32 nTaps);
xccFIRFilterSpecFLT96 *xccFIRFilterInitAccFLT96(INT32 nTaps);
//VOID xccFIRFilterFLT32(FLT32 *dataI, FLT32 *dataO, INT32 n, xccFIRFilterSpec *spec);
VOID xccFIRFilterFLT32(FLT32 *dataI, INT32 ski, FLT32 *dataO, INT32 skj, INT32 n, xccFIRFilterSpecFLT32 *spec);
VOID xccFIRFilterFLT64(FLT64 *dataI, INT32 ski, FLT64 *dataO, INT32 skj, INT32 n, xccFIRFilterSpecFLT64 *spec);
VOID xccFIRFilterFLT96(FLT96 *dataI, INT32 ski, FLT96 *dataO, INT32 skj, INT32 n, xccFIRFilterSpecFLT96 *spec);

VOID xccFIRTermFLT32( xccFIRFilterSpecFLT32 *spec );
VOID xccFIRTermFLT64( xccFIRFilterSpecFLT64 *spec );
VOID xccFIRTermFLT96( xccFIRFilterSpecFLT96 *spec );

/* IIR functions -------------------------------------------------------------*/
xccIIRFilterSpec *xccIIRInitBPFLT32(FLT32 fc, FLT32 fs, FLT32 bw );
xccIIRFilterSpec *xccIIRInitHPFLT32(FLT32 fc, FLT32 fs );
xccIIRFilterSpec *xccIIRInitLPFLT32(FLT32 fc, FLT32 fs );
xccIIRFilterSpec *xccIIRInitFLT32(INT32 numberOfPoles, ... );
xccIIRFilterSpec *xccChebyshevFilter(FLT32 fc, FLT32 fs, INT32 NP, FLT32 PR, INT32 LH);
VOID xccIIRFLT32(FLT32 *x,  FLT32 *y, INT32 n, xccIIRFilterSpec *spec );
VOID xccIIRFLT64(FLT64 *x,  FLT64 *y, INT32 n, xccIIRFilterSpec *spec );
VOID xccIIRTermFLT32( xccIIRFilterSpec *spec );

/* Costas loop functions -----------------------------------------------------*/
xccCostasLoopSpec *xccCostasLoopInitFLT32(FLT32 fc, FLT32 fs, 
					  xccIIRFilterSpec *iirSpecI,
					  xccIIRFilterSpec *iirSpecQ,
					  xccIIRFilterSpec *iirSpecLoop);
VOID xccCostasLoopBPSKFLT32(FLT32 *x, FLT32 *y, INT32 n, xccCostasLoopSpec *spec );
VOID xccCostasLoopTermFLT32( xccCostasLoopSpec *spec );

/* PLL -----------------------------------------------------------------------*/
VOID xccvPLLFLT32(FLT32 *a, INT32 i, FLT32 *b, INT32 j, INT32 n, FLT32 fc, FLT32 fs );
VOID xccvPLLFLT64(FLT64 *a, INT32 i, FLT64 *b, INT32 j, INT32 n, FLT64 fc, FLT64 fs );
VOID xccvPLLFLT96(FLT96 *a, INT32 i, FLT96 *b, INT32 j, INT32 n, FLT96 fc, FLT96 fs );

/* Window functions ----------------------------------------------------------*/
VOID xccBlackmanCreateWindowFLT32(FLT32 *a, INT32 i, UNT32 n );
VOID xccBlackmanCreateWindowFLT64(FLT64 *a, INT32 i, UNT32 n );
VOID xccBlackmanCreateWindowFLT96(FLT96 *a, INT32 i, UNT32 n );
VOID xccBoxcarCreateWindowFLT32(  FLT32 *a, INT32 i, UNT32 n );
VOID xccBoxcarCreateWindowFLT64(  FLT64 *a, INT32 i, UNT32 n );
VOID xccBoxcarCreateWindowFLT96(  FLT96 *a, INT32 i, UNT32 n );
VOID xccHanningCreateWindowFLT32( FLT32 *a, INT32 i, UNT32 n );
VOID xccHanningCreateWindowFLT64( FLT64 *a, INT32 i, UNT32 n );
VOID xccHanningCreateWindowFLT96( FLT96 *a, INT32 i, UNT32 n );
VOID xccHammingCreateWindowFLT32( FLT32 *a, INT32 i, UNT32 n );
VOID xccHammingCreateWindowFLT64( FLT64 *a, INT32 i, UNT32 n );
VOID xccHammingCreateWindowFLT96( FLT96 *a, INT32 i, UNT32 n );
VOID xccBlackmanWindowFLT32(FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n );
VOID xccBlackmanWindowFLT64(FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n );
VOID xccBlackmanWindowFLT96(FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n );
VOID xccBoxcarWindowFLT32(  FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n );
VOID xccBoxcarWindowFLT64(  FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n );
VOID xccBoxcarWindowFLT96(  FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n );
VOID xccHanningWindowFLT32( FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n );
VOID xccHanningWindowFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n );
VOID xccHanningWindowFLT96( FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n );
VOID xccHammingWindowFLT32( FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n );
VOID xccHammingWindowFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n );
VOID xccHammingWindowFLT96( FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n );

/* Up Sampler functions ------------------------------------------------------*/
xccUpSampleSpecFLT64 *xccUpSampleInitFLT64(FLT64 fb, FLT64 fs, FLT64 phs, INT32 nb);
xccUpSampleSpecFLT32 *xccUpSampleInit(FLT32 fb, FLT32 fs, INT32 nb);
VOID xccUpSampleTerm( xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleINT08FLT32(INT08 *x, FLT32 *y, INT32 n, xccUpSampleSpecFLT64 *spec );

VOID xccUpSampleBufferINT08FLT32 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );

VOID xccUpSampleBufferFLT32 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferFLT64 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferFLT96 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferINT08 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferINT16 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferINT32 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferINT64 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferUNT08 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferUNT16 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferUNT32 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferUNT64 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferCFLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferCFLT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferCFLT96(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferCINT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferCINT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferCINT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferCINT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferCUNT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferCUNT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferCUNT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferCUNT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferVFLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferVFLT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferVFLT96(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferVINT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferVINT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferVINT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferVINT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferVUNT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferVUNT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferVUNT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleBufferVUNT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );

INT32 xccUpSampleBufferFlushFLT32 (VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushFLT64 (VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushFLT96 (VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushINT08 (VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushINT16 (VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushINT32 (VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushUNT08 (VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushUNT16 (VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushUNT32 (VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushUNT64 (VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushCFLT32(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushCFLT64(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushCFLT96(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushCINT08(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushCINT16(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushCINT32(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushCINT64(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushCUNT08(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushCUNT16(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushCUNT32(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushCUNT64(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushVFLT32(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushVFLT64(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushVFLT96(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushVINT08(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushVINT16(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushVINT32(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushVINT64(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushVUNT08(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushVUNT16(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushVUNT32(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushVUNT64(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );
INT32 xccUpSampleBufferFlushINT08FLT32(VOID *a, INT32 i, VOID *b, INT32 j, xccUpSampleSpecFLT64 *spec );

VOID xccUpSampleCircularBufferFLT32 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferFLT64 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferFLT96 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferINT08 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferINT16 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferINT32 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferINT64 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferUNT08 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferUNT16 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferUNT32 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferUNT64 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferCFLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferCFLT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferCFLT96(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferCINT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferCINT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferCINT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferCINT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferCUNT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferCUNT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferCUNT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferCUNT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferVFLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferVFLT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferVFLT96(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferVINT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferVINT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferVINT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferVINT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferVUNT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferVUNT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferVUNT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );
VOID xccUpSampleCircularBufferVUNT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, xccUpSampleSpecFLT64 *spec );

/* Bit Descision functions ---------------------------------------------------*/
xccBitDescisionSpec *xccBitDescisionInitFLT32(FLT64 fb, FLT64 fs, INT32 decimation);
VOID xccBitDescisionFLT32(FLT32 *x, INT32 n, xccBitDescisionSpec *spec);
VOID xccBitDescisionTermFLT32(xccBitDescisionSpec *spec);

/* RandM functions.  Memory table lookup for random noise. -------------------*/
xccvRandMSpec *xccvRandMInitFLT32(UNT64 seed, FLT32 std, UNT32 tableSize);
xccvRandMSpec *xccvRandMInitINT16(UNT64 seed, FLT32 std, UNT32 tableSize);
VOID xccvRandMFLT32(FLT32 *a, UNT32 n, xccvRandMSpec *spec );
VOID xccvRandMINT16(INT16 *a, UNT32 n, xccvRandMSpec *spec );
VOID xccvRandMTermFLT32(xccvRandMSpec *spec);

/* Linear spaced elements. ---------------------------------------------------*/
VOID xccLinSpaceINT08(INT08 x1, INT08 x2, INT08 *y, INT32 n);
VOID xccLinSpaceINT16(INT16 x1, INT16 x2, INT16 *y, INT32 n);
VOID xccLinSpaceINT32(INT32 x1, INT32 x2, INT32 *y, INT32 n);
VOID xccLinSpaceINT64(INT64 x1, INT64 x2, INT64 *y, INT32 n);
VOID xccLinSpaceUNT08(UNT08 x1, UNT08 x2, UNT08 *y, INT32 n);
VOID xccLinSpaceUNT16(UNT16 x1, UNT16 x2, UNT16 *y, INT32 n);
VOID xccLinSpaceUNT32(UNT32 x1, UNT32 x2, UNT32 *y, INT32 n);
VOID xccLinSpaceUNT64(UNT64 x1, UNT64 x2, UNT64 *y, INT32 n);
VOID xccLinSpaceFLT32(FLT32 x1, FLT32 x2, FLT32 *y, INT32 n);
VOID xccLinSpaceFLT64(FLT64 x1, FLT64 x2, FLT64 *y, INT32 n);
VOID xccLinSpaceFLT96(FLT96 x1, FLT96 x2, FLT96 *y, INT32 n);

/* Sinc function. ------------------------------------------------------------*/
VOID xccSincFLT32( INT32 nTaps, FLT32 wc, FLT32 *sinc);
VOID xccSincFLT64( INT32 nTaps, FLT64 wc, FLT32 *sinc);
VOID xccSincFLT96( INT32 nTaps, FLT96 wc, FLT32 *sinc);

/* VCO function. -------------------------------------------------------------*/
xccVCOSpec *xccVCOInit(FLT64 centerFrequency, FLT64 fs, FLT64 phase);
CFLT32 xccVCOCFLT32  ( FLT32 input, xccVCOSpec *spec );
CFLT64 xccVCOCFLT64  ( FLT64 input, xccVCOSpec *spec );
CFLT96 xccVCOCFLT96  ( FLT96 input, xccVCOSpec *spec );
FLT32  xccVCOFLT32   ( FLT32 input, xccVCOSpec *spec );
FLT64  xccVCOFLT64   ( FLT64 input, xccVCOSpec *spec );
FLT96  xccVCOFLT96   ( FLT96 input, xccVCOSpec *spec );
FLT32  xccVCOFLT32Cos( FLT32 input, xccVCOSpec *spec );
FLT64  xccVCOFLT64Cos( FLT64 input, xccVCOSpec *spec );
FLT96  xccVCOFLT96Cos( FLT96 input, xccVCOSpec *spec );
FLT32  xccVCOFLT32Sin( FLT32 input, xccVCOSpec *spec );
FLT64  xccVCOFLT64Sin( FLT64 input, xccVCOSpec *spec );
FLT96  xccVCOFLT96Sin( FLT96 input, xccVCOSpec *spec );
VOID   xccVCOUpdate  ( FLT64 input, xccVCOSpec *spec );
VOID   xccVCOReset   ( xccVCOSpec *spec );

/* Loop filter function. -----------------------------------------------------*/
xccLoopFilterSpec *xccLoopFilterInit(FLT64 lockInRange,
				     FLT64 dampingFactor,
				     FLT64 Kd,            // Usually (1.0/TWOPI).
				     FLT64 Ko,            // Usually (TWOPI).
				     FLT64 fs);
FLT32 xccLoopFilterFLT32( FLT32 input, xccLoopFilterSpec *spec );
FLT64 xccLoopFilterFLT64( FLT64 input, xccLoopFilterSpec *spec );
FLT96 xccLoopFilterFLT96( FLT96 input, xccLoopFilterSpec *spec );
INT08 xccLoopFilterINT08( INT08 input, xccLoopFilterSpec *spec );
INT16 xccLoopFilterINT16( INT16 input, xccLoopFilterSpec *spec );
INT32 xccLoopFilterINT32( INT32 input, xccLoopFilterSpec *spec );
INT64 xccLoopFilterINT64( INT64 input, xccLoopFilterSpec *spec );



typedef struct
{
  FLT64 t;
  FLT64 T;
  FLT64 fs;
  FLT64 fsNew;
  FLT64 nTapT;
  INT32 nTaps;
  FLT64 delta;
  INT64 batchStrt;
  INT64 batchStop;
  INT64 sampleCount;
  FLT64 *w;
  FLT64 *data;
  FLT64 *hist;
}xccNewRateSpec;
  xccNewRateSpec *xccNewRateInit(FLT32 fs, FLT32 fsNew, INT32 nTaps);
  INT32 xccNewRate(FLT32 *iData, FLT32 *oData, UNT32 n, xccNewRateSpec *spec);
  VOID xccNewRateTerm(xccNewRateSpec *spec);





























/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/
