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
} iccUpSampleSpecFLT32;

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
} iccUpSampleSpecFLT64;

typedef struct               // Resampler SPECIFICATION.
{                            //
  FLT64 fb;                  // Baud Rate.  For lack of a better term.
  FLT64 fs;                  // Sample Rate.
  FLT64 phs;                 // Sample phase.
  FLT64 nb;                  // Number of Baud.
  FLT64 delta;               // Calculated delta.
  FLT64 indexF;              // Index in floating format.
  UNT32 indexI;              // Index in integer format.
} iccResampleSpec;

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
  iccStackINT08_t *bitStack; // Bit stack to store the values.
} iccBitDescisionSpec;

typedef struct               // FIR FILTER SPECIFICATION.
{
  INT32 nTaps;               // Number of taps.
  INT32 nHist;               // Number of history points.  (nTaps-1).
  FLT32 *fw;                 // Filter weights array.
  FLT32 *fh;                 // Filter history array.
  FLT32 *fd;                 // Filter data array.
} iccFIRFilterSpecFLT32;

typedef struct               // FIR FILTER SPECIFICATION.
{
  INT32 nTaps;               // Number of taps.
  INT32 nHist;               // Number of history points.  (nTaps-1).
  FLT64 *fw;                 // Filter weights array.
  FLT64 *fh;                 // Filter history array.
  FLT64 *fd;                 // Filter data array.
} iccFIRFilterSpecFLT64;

typedef struct               // FIR FILTER SPECIFICATION.
{
  INT32 nTaps;               // Number of taps.
  INT32 nHist;               // Number of history points.  (nTaps-1).
  FLT96 *fw;                 // Filter weights array.
  FLT96 *fh;                 // Filter history array.
  FLT96 *fd;                 // Filter data array.
} iccFIRFilterSpecFLT96;

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
}iccIIRFilterSpec;

typedef struct               // SIGNAL GENERATOR SPECIFICATION.
{
  FLT32 fc;                  // Frequency.
  FLT32 fs;                  // Sample rate.
  FLT32 delta;               // Radians per sample. 2*pi*fc/fs.  
  FLT32 phi;                 // Phase.
  FLT32 amp;                 // Amplitude.
} iccSigGenSpecFLT32;

typedef struct               // SIGNAL GENERATOR SPECIFICATION.
{
  FLT64 fc;                  // Frequency.
  FLT64 fs;                  // Sample rate.
  FLT64 delta;               // Radians per sample. 2*pi*fc/fs.  
  FLT64 phi;                 // Phase.
  FLT64 amp;                 // Amplitude.
} iccSigGenSpecFLT64;

typedef struct               // SIGNAL GENERATOR SPECIFICATION.
{
  FLT96 fc;                  // Frequency.
  FLT96 fs;                  // Sample rate.
  FLT96 delta;               // Radians per sample. 2*pi*fc/fs.  
  FLT96 phi;                 // Phase.
  FLT96 amp;                 // Amplitude.
} iccSigGenSpecFLT96;

typedef struct               // SIGNAL GENERATOR SPECIFICATION.
{
  FLT32 fc;                  // Frequency.
  FLT32 fa;                  // Frequency acceleration.
  FLT32 fs;                  // Sample rate.
  FLT32 delta1;              // Radians per sample. 2*pi*fc/fs.  
  FLT32 delta2;              // Radians per sample per sample. 2*pi*fc/fs/fs.  
  FLT32 phi;                 // Phase.
  FLT32 amp;                 // Amplitude.
} iccSigSigGenSpecFLT32;

typedef struct               // SIGNAL GENERATOR SPECIFICATION.
{
  FLT64 fc;                  // Frequency.
  FLT64 fa;                  // Frequency acceleration.
  FLT64 fs;                  // Sample rate.
  FLT64 delta1;              // Radians per sample. 2*pi*fc/fs.  
  FLT64 delta2;              // Radians per sample per sample. 2*pi*fc/fs/fs.  
  FLT64 phi;                 // Phase.
  FLT64 amp;                 // Amplitude.
} iccSigSigGenSpecFLT64;

typedef struct               // SIGNAL GENERATOR SPECIFICATION.
{
  FLT96 fc;                  // Frequency.
  FLT96 fa;                  // Frequency acceleration.
  FLT96 fs;                  // Sample rate.
  FLT96 delta1;              // Radians per sample. 2*pi*fc/fs.  
  FLT96 delta2;              // Radians per sample per sample. 2*pi*fc/fs/fs.  
  FLT96 phi;                 // Phase.
  FLT96 amp;                 // Amplitude.
} iccSigSigGenSpecFLT96;

typedef struct               // COSTAS LOOP SPECIFICATION.
{
  FLT32 fc;                  // Frequency.
  FLT32 fs;                  // Sample rate.
  FLT32 delta;               // Radians per sample. 2*pi*fc/fs.
  FLT32 phi;                 // Phase.
  iccIIRFilterSpec *iirSpecI;    // I rail filter specification.
  iccIIRFilterSpec *iirSpecQ;    // Q rail filter specification
  iccIIRFilterSpec *iirSpecLoop; // Loop filter.
}iccCostasLoopSpec;

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
} iccvRandMSpec;

typedef struct             // VCO SPECIFICATION.
{                          //
  FLT64 centerFrequency;   // Center frequency.
  FLT64 fs;                // Sample rate.
  FLT64 fc;                // Current frequency.
  FLT64 delta;             // Sample period.
  FLT64 phase;             // Phase.
} iccVCOSpec;

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
} iccLoopFilterSpec;

/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/

/* Signal generator functions ------------------------------------------------*/
iccSigGenSpecFLT32 *iccSigGenInitFLT32(FLT32 fc, FLT32 fs, FLT32 amp, FLT32 phs);
iccSigGenSpecFLT64 *iccSigGenInitFLT64(FLT64 fc, FLT64 fs, FLT64 amp, FLT64 phs);
iccSigGenSpecFLT96 *iccSigGenInitFLT96(FLT96 fc, FLT96 fs, FLT96 amp, FLT96 phs);

VOID iccSigGenModFLT32(FLT32 fc, FLT32 fs, FLT32 amp, FLT32 phs, iccSigGenSpecFLT32 *spec);
VOID iccSigGenModFLT64(FLT64 fc, FLT64 fs, FLT64 amp, FLT64 phs, iccSigGenSpecFLT64 *spec);
VOID iccSigGenModFLT96(FLT96 fc, FLT96 fs, FLT96 amp, FLT96 phs, iccSigGenSpecFLT96 *spec);

VOID iccSigGenCosFLT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosFLT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosFLT96(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosINT08(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosINT16(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosINT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosINT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosUNT08(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosUNT16(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosUNT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosUNT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenSinFLT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenSinFLT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenSinFLT96(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenSinINT08(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenSinINT16(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenSinINT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenSinINT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenSinUNT08(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenSinUNT16(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenSinUNT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenSinUNT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosSinCFLT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosSinCFLT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosSinCFLT96(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosSinCINT08(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosSinCINT16(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosSinCINT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosSinCINT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosSinCUNT08(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosSinCUNT16(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosSinCUNT32(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );
VOID iccSigGenCosSinCUNT64(VOID *y, INT32 i, INT32 n, iccSigGenSpecFLT64 *spec );

VOID iccSigGenTermFLT32(iccSigGenSpecFLT32 *spec);
VOID iccSigGenTermFLT64(iccSigGenSpecFLT64 *spec);
VOID iccSigGenTermFLT96(iccSigGenSpecFLT96 *spec);

/* Signal generator functions ------------------------------------------------*/
iccSigSigGenSpecFLT32 *iccSigSigGenInitFLT32(FLT32 fc, FLT32 fa, FLT32 fs, FLT32 amp, FLT32 phs);
iccSigSigGenSpecFLT64 *iccSigSigGenInitFLT64(FLT64 fc, FLT64 fa, FLT64 fs, FLT64 amp, FLT64 phs);
iccSigSigGenSpecFLT96 *iccSigSigGenInitFLT96(FLT96 fc, FLT96 fa, FLT96 fs, FLT96 amp, FLT96 phs);

VOID iccSigSigGenCosFLT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosFLT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosFLT96(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosINT08(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosINT16(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosINT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosINT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosUNT08(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosUNT16(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosUNT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosUNT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenSinFLT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenSinFLT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenSinFLT96(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenSinINT08(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenSinINT16(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenSinINT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenSinINT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenSinUNT08(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenSinUNT16(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenSinUNT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenSinUNT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosSinCFLT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosSinCFLT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosSinCFLT96(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosSinCINT08(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosSinCINT16(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosSinCINT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosSinCINT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosSinCUNT08(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosSinCUNT16(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosSinCUNT32(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );
VOID iccSigSigGenCosSinCUNT64(VOID *y, INT32 i, INT32 n, iccSigSigGenSpecFLT64 *spec );

VOID iccSigSigGenTermFLT32(iccSigSigGenSpecFLT32 *spec);
VOID iccSigSigGenTermFLT64(iccSigSigGenSpecFLT64 *spec);
VOID iccSigSigGenTermFLT96(iccSigSigGenSpecFLT96 *spec);



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
VOID  iccDFTFLT32_R(FLT32 *iData, FLT32 *oData, UNT32 n );
VOID  iccDFTFLT32_C(FLT32 *iData, FLT32 *oData, UNT32 n );

/* FFT functions -------------------------------------------------------------*/
UNT32 iccFFTBitReverse(INT32 iidex, INT32 nBits);
VOID  icc2ptButterflyFLT32_R(FLT32 *iData0, FLT32 *iData1, FLT32 *oData);
VOID  icc2ptButterflyFLT32_C(FLT32 *iData0, FLT32 *iData1, FLT32 *oData);
VOID  iccNptButterflyFLT32 (FLT32 *iData, INT32 N, INT08 ifftFlag );
//VOID  iccIFFTFLT32 (FLT32 *iData, FLT32 *oData,  UNT32 N );
//VOID  iccFFTFLT32_X(FLT32 *iData, FLT32 *oData,  UNT32 N, INT08 realFlag, INT08 ifftFlag );

VOID  iccFFTINT08_R (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccFFTINT08_C (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccFFTINT16_R (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccFFTINT16_C (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccFFTINT32_R (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccFFTINT32_C (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccFFTUNT08_R (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccFFTUNT08_C (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccFFTUNT16_R (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccFFTUNT16_C (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccFFTUNT32_R (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccFFTUNT32_C (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccFFTFLT32_R (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccFFTFLT32_C (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccFFTFLT64_R (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccFFTFLT64_C (VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccIFFTINT08_R(VOID  *iData, FLT32 *oData, UNT32 N); //REAL IFFT?
VOID  iccIFFTINT08_C(VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccIFFTINT16_R(VOID  *iData, FLT32 *oData, UNT32 N); //REAL IFFT?
VOID  iccIFFTINT16_C(VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccIFFTINT32_R(VOID  *iData, FLT32 *oData, UNT32 N); //REAL IFFT?
VOID  iccIFFTINT32_C(VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccIFFTUNT08_R(VOID  *iData, FLT32 *oData, UNT32 N); //REAL IFFT?
VOID  iccIFFTUNT08_C(VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccIFFTUNT16_R(VOID  *iData, FLT32 *oData, UNT32 N); //REAL IFFT?
VOID  iccIFFTUNT16_C(VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccIFFTUNT32_R(VOID  *iData, FLT32 *oData, UNT32 N); //REAL IFFT?
VOID  iccIFFTUNT32_C(VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccIFFTFLT32_R(VOID  *iData, FLT32 *oData, UNT32 N); //REAL IFFT?
VOID  iccIFFTFLT32_C(VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccIFFTFLT64_R(VOID  *iData, FLT32 *oData, UNT32 N); //REAL IFFT?
VOID  iccIFFTFLT64_C(VOID  *iData, FLT32 *oData, UNT32 N);
VOID  iccFFTINT08_X(INT08 *iData, FLT32 *oData, UNT32 N, INT08 realFlag, INT08 ifftFlag);
VOID  iccFFTINT16_X(INT16 *iData, FLT32 *oData, UNT32 N, INT08 realFlag, INT08 ifftFlag);
VOID  iccFFTINT32_X(INT32 *iData, FLT32 *oData, UNT32 N, INT08 realFlag, INT08 ifftFlag);
VOID  iccFFTUNT08_X(UNT08 *iData, FLT32 *oData, UNT32 N, INT08 realFlag, INT08 ifftFlag);
VOID  iccFFTUNT16_X(UNT16 *iData, FLT32 *oData, UNT32 N, INT08 realFlag, INT08 ifftFlag);
VOID  iccFFTUNT32_X(UNT32 *iData, FLT32 *oData, UNT32 N, INT08 realFlag, INT08 ifftFlag);
VOID  iccFFTFLT32_X(FLT32 *iData, FLT32 *oData, UNT32 N, INT08 realFlag, INT08 ifftFlag);
VOID  iccFFTFLT64_X(FLT64 *iData, FLT32 *oData, UNT32 N, INT08 realFlag, INT08 ifftFlag);

/* FFT functions -------------------------------------------------------------*/
//VOID iccFFTrFLT32(FLT32 *inData, FLT32 *outData, UNT32 nElements);
//VOID iccFFTcFLT32(FLT32 *inData, FLT32 *outData, UNT32 nElements);
//VOID iccIFFTFLT32(FLT32 *inData, FLT32 *outData, UNT32 nElements);

/* FIR functions -------------------------------------------------------------*/
iccFIRFilterSpecFLT32 *iccFIRFilterInitLPFLT32(FLT32 fc, FLT32 fs, INT32 nTaps);
iccFIRFilterSpecFLT64 *iccFIRFilterInitLPFLT64(FLT64 fc, FLT64 fs, INT32 nTaps);
iccFIRFilterSpecFLT96 *iccFIRFilterInitLPFLT96(FLT96 fc, FLT96 fs, INT32 nTaps);
iccFIRFilterSpecFLT32 *iccFIRFilterInitHPFLT32(FLT32 fc, FLT32 fs, INT32 nTaps);
iccFIRFilterSpecFLT64 *iccFIRFilterInitHPFLT64(FLT64 fc, FLT64 fs, INT32 nTaps);
iccFIRFilterSpecFLT96 *iccFIRFilterInitHPFLT96(FLT96 fc, FLT96 fs, INT32 nTaps);
iccFIRFilterSpecFLT32 *iccFIRFilterInitBPFLT32(FLT32 fc, FLT32 bw, FLT32 fs, INT32 nTaps);
iccFIRFilterSpecFLT64 *iccFIRFilterInitBPFLT64(FLT64 fc, FLT64 bw, FLT64 fs, INT32 nTaps);
iccFIRFilterSpecFLT96 *iccFIRFilterInitBPFLT96(FLT96 fc, FLT96 bw, FLT96 fs, INT32 nTaps);
iccFIRFilterSpecFLT32 *iccFIRFilterInitAccFLT32(INT32 nTaps);
iccFIRFilterSpecFLT64 *iccFIRFilterInitAccFLT64(INT32 nTaps);
iccFIRFilterSpecFLT96 *iccFIRFilterInitAccFLT96(INT32 nTaps);
//VOID iccFIRFilterFLT32(FLT32 *dataI, FLT32 *dataO, INT32 n, iccFIRFilterSpec *spec);
VOID iccFIRFilterFLT32(FLT32 *dataI, INT32 ski, FLT32 *dataO, INT32 skj, INT32 n, iccFIRFilterSpecFLT32 *spec);
VOID iccFIRFilterFLT64(FLT64 *dataI, INT32 ski, FLT64 *dataO, INT32 skj, INT32 n, iccFIRFilterSpecFLT64 *spec);
VOID iccFIRFilterFLT96(FLT96 *dataI, INT32 ski, FLT96 *dataO, INT32 skj, INT32 n, iccFIRFilterSpecFLT96 *spec);

VOID iccFIRTermFLT32( iccFIRFilterSpecFLT32 *spec );
VOID iccFIRTermFLT64( iccFIRFilterSpecFLT64 *spec );
VOID iccFIRTermFLT96( iccFIRFilterSpecFLT96 *spec );

/* IIR functions -------------------------------------------------------------*/
iccIIRFilterSpec *iccIIRInitBPFLT32(FLT32 fc, FLT32 fs, FLT32 bw );
iccIIRFilterSpec *iccIIRInitHPFLT32(FLT32 fc, FLT32 fs );
iccIIRFilterSpec *iccIIRInitLPFLT32(FLT32 fc, FLT32 fs );
iccIIRFilterSpec *iccIIRInitFLT32(INT32 numberOfPoles, ... );
iccIIRFilterSpec *iccChebyshevFilter(FLT32 fc, FLT32 fs, INT32 NP, FLT32 PR, INT32 LH);
VOID iccIIRFLT32(FLT32 *x,  FLT32 *y, INT32 n, iccIIRFilterSpec *spec );
VOID iccIIRFLT64(FLT64 *x,  FLT64 *y, INT32 n, iccIIRFilterSpec *spec );
VOID iccIIRTermFLT32( iccIIRFilterSpec *spec );

/* Costas loop functions -----------------------------------------------------*/
iccCostasLoopSpec *iccCostasLoopInitFLT32(FLT32 fc, FLT32 fs, 
					  iccIIRFilterSpec *iirSpecI,
					  iccIIRFilterSpec *iirSpecQ,
					  iccIIRFilterSpec *iirSpecLoop);
VOID iccCostasLoopBPSKFLT32(FLT32 *x, FLT32 *y, INT32 n, iccCostasLoopSpec *spec );
VOID iccCostasLoopTermFLT32( iccCostasLoopSpec *spec );

/* PLL -----------------------------------------------------------------------*/
VOID iccvPLLFLT32(FLT32 *a, INT32 i, FLT32 *b, INT32 j, INT32 n, FLT32 fc, FLT32 fs );
VOID iccvPLLFLT64(FLT64 *a, INT32 i, FLT64 *b, INT32 j, INT32 n, FLT64 fc, FLT64 fs );
VOID iccvPLLFLT96(FLT96 *a, INT32 i, FLT96 *b, INT32 j, INT32 n, FLT96 fc, FLT96 fs );

/* Window functions ----------------------------------------------------------*/
VOID iccBlackmanCreateWindowFLT32(FLT32 *a, INT32 i, UNT32 n );
VOID iccBlackmanCreateWindowFLT64(FLT64 *a, INT32 i, UNT32 n );
VOID iccBlackmanCreateWindowFLT96(FLT96 *a, INT32 i, UNT32 n );
VOID iccBoxcarCreateWindowFLT32(  FLT32 *a, INT32 i, UNT32 n );
VOID iccBoxcarCreateWindowFLT64(  FLT64 *a, INT32 i, UNT32 n );
VOID iccBoxcarCreateWindowFLT96(  FLT96 *a, INT32 i, UNT32 n );
VOID iccHanningCreateWindowFLT32( FLT32 *a, INT32 i, UNT32 n );
VOID iccHanningCreateWindowFLT64( FLT64 *a, INT32 i, UNT32 n );
VOID iccHanningCreateWindowFLT96( FLT96 *a, INT32 i, UNT32 n );
VOID iccHammingCreateWindowFLT32( FLT32 *a, INT32 i, UNT32 n );
VOID iccHammingCreateWindowFLT64( FLT64 *a, INT32 i, UNT32 n );
VOID iccHammingCreateWindowFLT96( FLT96 *a, INT32 i, UNT32 n );
VOID iccBlackmanWindowFLT32(FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n );
VOID iccBlackmanWindowFLT64(FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n );
VOID iccBlackmanWindowFLT96(FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n );
VOID iccBoxcarWindowFLT32(  FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n );
VOID iccBoxcarWindowFLT64(  FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n );
VOID iccBoxcarWindowFLT96(  FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n );
VOID iccHanningWindowFLT32( FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n );
VOID iccHanningWindowFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n );
VOID iccHanningWindowFLT96( FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n );
VOID iccHammingWindowFLT32( FLT32 *a, INT32 i, FLT32 *b, INT32 j, UNT32 n );
VOID iccHammingWindowFLT64( FLT64 *a, INT32 i, FLT64 *b, INT32 j, UNT32 n );
VOID iccHammingWindowFLT96( FLT96 *a, INT32 i, FLT96 *b, INT32 j, UNT32 n );

/* Up Sampler functions ------------------------------------------------------*/
iccUpSampleSpecFLT64 *iccUpSampleInitFLT64(FLT64 fb, FLT64 fs, FLT64 phs, INT32 nb);
iccUpSampleSpecFLT32 *iccUpSampleInit(FLT32 fb, FLT32 fs, INT32 nb);
VOID iccUpSampleTerm( iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleINT08FLT32(INT08 *x, FLT32 *y, INT32 n, iccUpSampleSpecFLT64 *spec );

VOID iccUpSampleBufferINT08FLT32 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );

VOID iccUpSampleBufferFLT32 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferFLT64 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferFLT96 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferINT08 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferINT16 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferINT32 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferINT64 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferUNT08 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferUNT16 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferUNT32 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferUNT64 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferCFLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferCFLT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferCFLT96(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferCINT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferCINT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferCINT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferCINT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferCUNT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferCUNT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferCUNT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferCUNT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferVFLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferVFLT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferVFLT96(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferVINT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferVINT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferVINT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferVINT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferVUNT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferVUNT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferVUNT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleBufferVUNT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );

INT32 iccUpSampleBufferFlushFLT32 (VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushFLT64 (VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushFLT96 (VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushINT08 (VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushINT16 (VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushINT32 (VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushUNT08 (VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushUNT16 (VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushUNT32 (VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushUNT64 (VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushCFLT32(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushCFLT64(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushCFLT96(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushCINT08(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushCINT16(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushCINT32(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushCINT64(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushCUNT08(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushCUNT16(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushCUNT32(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushCUNT64(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushVFLT32(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushVFLT64(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushVFLT96(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushVINT08(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushVINT16(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushVINT32(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushVINT64(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushVUNT08(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushVUNT16(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushVUNT32(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushVUNT64(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );
INT32 iccUpSampleBufferFlushINT08FLT32(VOID *a, INT32 i, VOID *b, INT32 j, iccUpSampleSpecFLT64 *spec );

VOID iccUpSampleCircularBufferFLT32 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferFLT64 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferFLT96 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferINT08 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferINT16 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferINT32 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferINT64 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferUNT08 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferUNT16 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferUNT32 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferUNT64 (VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferCFLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferCFLT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferCFLT96(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferCINT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferCINT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferCINT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferCINT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferCUNT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferCUNT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferCUNT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferCUNT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferVFLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferVFLT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferVFLT96(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferVINT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferVINT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferVINT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferVINT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferVUNT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferVUNT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferVUNT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );
VOID iccUpSampleCircularBufferVUNT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccUpSampleSpecFLT64 *spec );

iccResampleSpec *iccResampleInit(FLT64 fb, FLT64 fs, FLT64 phs, INT32 nb);
VOID iccResampleTerm( iccUpSampleSpecFLT64 *spec );
VOID iccResampleFLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleFLT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleFLT96(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleINT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleINT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleINT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleINT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleUNT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleUNT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleUNT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleUNT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleCFLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleCFLT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleCFLT96(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleCINT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleCINT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleCINT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleCINT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleCUNT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleCUNT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleCUNT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleCUNT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleVFLT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleVFLT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleVFLT96(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleVINT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleVINT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleVINT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleVINT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleVUNT08(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleVUNT16(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleVUNT32(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );
VOID iccResampleVUNT64(VOID *a, INT32 i, VOID *b, INT32 j, INT32 n, iccResampleSpec *spec );

/* Bit Descision functions ---------------------------------------------------*/
iccBitDescisionSpec *iccBitDescisionInitFLT32(FLT64 fb, FLT64 fs, INT32 decimation);
VOID iccBitDescisionFLT32(FLT32 *x, INT32 n, iccBitDescisionSpec *spec);
VOID iccBitDescisionTermFLT32(iccBitDescisionSpec *spec);

/* RandM functions.  Memory table lookup for random noise. -------------------*/
iccvRandMSpec *iccvRandMInitFLT32(UNT64 seed, FLT32 std, UNT32 tableSize);
iccvRandMSpec *iccvRandMInitINT16(UNT64 seed, FLT32 std, UNT32 tableSize);
VOID iccvRandMFLT32(FLT32 *a, UNT32 n, iccvRandMSpec *spec );
VOID iccvRandMINT16(INT16 *a, UNT32 n, iccvRandMSpec *spec );
VOID iccvRandMTermFLT32(iccvRandMSpec *spec);

/* Linear spaced elements. ---------------------------------------------------*/
VOID iccLinSpaceINT08(INT08 x1, INT08 x2, INT08 *y, INT32 n);
VOID iccLinSpaceINT16(INT16 x1, INT16 x2, INT16 *y, INT32 n);
VOID iccLinSpaceINT32(INT32 x1, INT32 x2, INT32 *y, INT32 n);
VOID iccLinSpaceINT64(INT64 x1, INT64 x2, INT64 *y, INT32 n);
VOID iccLinSpaceUNT08(UNT08 x1, UNT08 x2, UNT08 *y, INT32 n);
VOID iccLinSpaceUNT16(UNT16 x1, UNT16 x2, UNT16 *y, INT32 n);
VOID iccLinSpaceUNT32(UNT32 x1, UNT32 x2, UNT32 *y, INT32 n);
VOID iccLinSpaceUNT64(UNT64 x1, UNT64 x2, UNT64 *y, INT32 n);
VOID iccLinSpaceFLT32(FLT32 x1, FLT32 x2, FLT32 *y, INT32 n);
VOID iccLinSpaceFLT64(FLT64 x1, FLT64 x2, FLT64 *y, INT32 n);
VOID iccLinSpaceFLT96(FLT96 x1, FLT96 x2, FLT96 *y, INT32 n);

/* Sinc function. ------------------------------------------------------------*/
VOID iccSincFLT32( INT32 nTaps, FLT32 wc, FLT32 *sinc);
VOID iccSincFLT64( INT32 nTaps, FLT64 wc, FLT32 *sinc);
VOID iccSincFLT96( INT32 nTaps, FLT96 wc, FLT32 *sinc);

/* VCO function. -------------------------------------------------------------*/
iccVCOSpec *iccVCOInit(FLT64 centerFrequency, FLT64 fs, FLT64 phase);
CFLT32 iccVCOCFLT32  ( FLT32 input, iccVCOSpec *spec );
CFLT64 iccVCOCFLT64  ( FLT64 input, iccVCOSpec *spec );
CFLT96 iccVCOCFLT96  ( FLT96 input, iccVCOSpec *spec );
FLT32  iccVCOFLT32   ( FLT32 input, iccVCOSpec *spec );
FLT64  iccVCOFLT64   ( FLT64 input, iccVCOSpec *spec );
FLT96  iccVCOFLT96   ( FLT96 input, iccVCOSpec *spec );
FLT32  iccVCOFLT32Cos( FLT32 input, iccVCOSpec *spec );
FLT64  iccVCOFLT64Cos( FLT64 input, iccVCOSpec *spec );
FLT96  iccVCOFLT96Cos( FLT96 input, iccVCOSpec *spec );
FLT32  iccVCOFLT32Sin( FLT32 input, iccVCOSpec *spec );
FLT64  iccVCOFLT64Sin( FLT64 input, iccVCOSpec *spec );
FLT96  iccVCOFLT96Sin( FLT96 input, iccVCOSpec *spec );
VOID   iccVCOUpdate  ( FLT64 input, iccVCOSpec *spec );
VOID   iccVCOReset   ( iccVCOSpec *spec );

/* Loop filter function. -----------------------------------------------------*/
iccLoopFilterSpec *iccLoopFilterInit(FLT64 lockInRange,
				     FLT64 dampingFactor,
				     FLT64 Kd,            // Usually (1.0/TWOPI).
				     FLT64 Ko,            // Usually (TWOPI).
				     FLT64 fs);
FLT32 iccLoopFilterFLT32( FLT32 input, iccLoopFilterSpec *spec );
FLT64 iccLoopFilterFLT64( FLT64 input, iccLoopFilterSpec *spec );
FLT96 iccLoopFilterFLT96( FLT96 input, iccLoopFilterSpec *spec );
INT08 iccLoopFilterINT08( INT08 input, iccLoopFilterSpec *spec );
INT16 iccLoopFilterINT16( INT16 input, iccLoopFilterSpec *spec );
INT32 iccLoopFilterINT32( INT32 input, iccLoopFilterSpec *spec );
INT64 iccLoopFilterINT64( INT64 input, iccLoopFilterSpec *spec );



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
}iccNewRateSpec;
  iccNewRateSpec *iccNewRateInit(FLT32 fs, FLT32 fsNew, INT32 nTaps);
  INT32 iccNewRate(FLT32 *iData, FLT32 *oData, UNT32 n, iccNewRateSpec *spec);
  VOID iccNewRateTerm(iccNewRateSpec *spec);





























/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif

#endif
/*-------------------------------UNCLASSIFIED---------------------------------*/
