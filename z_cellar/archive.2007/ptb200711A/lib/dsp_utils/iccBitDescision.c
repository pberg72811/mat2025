/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: bpskDemod.c
// Desc: This file contains the code for the bpskDemod binary.
// Hist: When       Who  What
//       11/08/2002 ptb  Initial Code.
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
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
// Rout: iccBitDescisionInitFLT32
// Desc: This routine initializes the bit descision spec.
//------------------------------------------------------------------------------
iccBitDescisionSpec *iccBitDescisionInitFLT32(FLT64 fb, FLT64 fs, INT32 decimation)
{
  iccBitDescisionSpec *spec;

  spec = (iccBitDescisionSpec *) malloc(sizeof(iccBitDescisionSpec));

  spec->fb               = fb;
  spec->fs               = fs;
  spec->delta            = 2*PI*fb/fs;
  spec->clckPhi          = -spec->delta;
  spec->clckNew          = 0.0;
  spec->clckOld          = 0.0;
  spec->dataNew          = 0.0;
  spec->dataOld          = 0.0;
  spec->batch            = 0;
  spec->decimation       = decimation;
  spec->dataZeroCrossOne = FALSE;
  spec->dataZeroCrossOld = 0;
  spec->dataZeroCrossNew = 0;
  spec->clckZeroCrossOld = 0;
  spec->clckZeroCrossNew = 0;
  spec->bitStack         = iccStackInitINT08( 1024*64, "BitStack" );

  return( spec );
}

//------------------------------------------------------------------------------
// Rout: iccBitDescisionFLT32
// Desc: This routine does bit descision on the input data stream.
//------------------------------------------------------------------------------
VOID iccBitDescisionFLT32(FLT32 *x, INT32 n, iccBitDescisionSpec *spec)
{
  INT32 ii;

  INT32 diffClockData;
  INT32 samplesPerSym;
  FLT32 percentOff;
  //FLT32 clockHist[1024*1024];

  // Loop over the data (decimate if spec says to).
  //----------------------------------------------------------------------------
  for( ii = 0; ii < n; ii+=spec->decimation)
  {
    spec->clckOld = spec->clckNew;
    spec->clckPhi += spec->delta*spec->decimation;
    spec->clckPhi = fmod(spec->clckPhi,TWOPI);
    spec->clckNew = sin( spec->clckPhi );
    spec->dataOld = spec->dataNew;
    spec->dataNew = x[ii];

    //clockHist[ii] = spec->clckNew;

  // Positive data crossing.
  //----------------------------------------------------------------------------
    if( (spec->dataNew >= 0) && (spec->dataOld < 0) )
    {
      spec->dataZeroCrossOld = spec->dataZeroCrossNew;
      spec->dataZeroCrossNew = spec->batch*n+ii;
      //printf("Zero cross at %ld\n",spec->dataZeroCrossNew);
      if( spec->dataZeroCrossOne == FALSE )
      {
	spec->dataZeroCrossOne=TRUE;
	spec->clckPhi = -spec->delta;
      }
    } 

  // Negative data crossing.
  //----------------------------------------------------------------------------
    if( (spec->dataNew <= 0) && (spec->dataOld > 0) )
    {
      spec->dataZeroCrossOld = spec->dataZeroCrossNew;
      spec->dataZeroCrossNew = spec->batch*n+ii;
      //printf("Zero cross at %ld\n",spec->dataZeroCrossNew);
      if( spec->dataZeroCrossOne == FALSE )
      {
	spec->dataZeroCrossOne=TRUE;
	spec->clckPhi = -spec->delta;
      }
    }

  // Positive clock crossing.  Good place to check distance away from data transition.
  //----------------------------------------------------------------------------
    if( (spec->clckNew >= 0.0) && (spec->clckOld < 0.0) )
    {
      spec->clckZeroCrossOld = spec->clckZeroCrossNew;
      spec->clckZeroCrossNew = spec->batch*n+ii;
      diffClockData = abs(spec->clckZeroCrossNew-spec->dataZeroCrossNew);
      samplesPerSym = spec->fs/spec->fb;
      percentOff    = ((FLT32)diffClockData)/((FLT32)samplesPerSym);

      printf("Clockcrossing at %ld\n", spec->clckZeroCrossNew);
      printf("lastDataCross at %ld\n", spec->dataZeroCrossNew);
      printf("Samples per symbol is %ld\n", samplesPerSym);
      printf("Percent off is %f\n", percentOff);
      if( (0.35 < percentOff) && (percentOff < 0.65) )
      {
	spec->dataZeroCrossOne = FALSE;
	//iccOctaveWriteFileFLT32( "debugData", "debugData", x, 1, ii );
	//iccOctaveWriteFileFLT32( "debugClck", "debugClck", clockHist, 1, ii );
      }
    }

  // Negative clock crossing.  This is where we want to take the bit.
  //----------------------------------------------------------------------------
    if( (spec->clckNew <= 0.0) && (spec->clckOld > 0.0) )
    {
      spec->clckZeroCrossOld = spec->clckZeroCrossNew;
      spec->clckZeroCrossNew = spec->batch*n+ii;
      //Take the bit;
      if(spec->dataNew > 0) 
      {
	iccStackPushINT08 ( spec->bitStack, 1 );
	printf("Bit = 1\n");
      }
      else
      {            
	iccStackPushINT08 ( spec->bitStack, 0 );
	printf("Bit = 0\n");
      }
    }
  }

  // Update the batchcount on the way out.
  //----------------------------------------------------------------------------
  spec->batch++;
  spec->batch = spec->batch%1000;
}

//------------------------------------------------------------------------------
// Rout: iccBitDescisionTermFLT32
// Desc: This routine terminates the bit descision spec.  Frees memory.
//------------------------------------------------------------------------------
VOID iccBitDescisionTermFLT32(iccBitDescisionSpec *spec)
{
  iccStackTermINT08(spec->bitStack);
  xmcFree(spec);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
