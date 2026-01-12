/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccPICInit.c
// Desc: This file contains the code for the xccPICInit routine.
// Note: For possible hardware configuration entries see "~/steswd/cfg/itthwconfig.key"
// Hist: When       Who  What
//       06/26/2003 ptb  Initial Code.
//       06/12/2006 ptb  Follow sourcepic more closely.  Values match at pic_io call.
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include "pic_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Type defines -------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Macros -------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Prototypes ---------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Routines -----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/

//-----------------------------------------------------------------------------------------------
// Rout: xccPICInit
// Desc: This routine initializes the PIC card.
//-----------------------------------------------------------------------------------------------
xccPICSpec *xccPICInit( const CHR08 *devString, FLT32 fs )
{
  xccPICSpec *spec;
  INT32 FLAGS=0;

  // Malloc the memory for the spec.
  //---------------------------------------------------------------------------------------------
  spec = (xccPICSpec *)xccMallocVOID_Align032(sizeof(xccPICSpec));

  // PIC OPEN.
  //---------------------------------------------------------------------------------------------
  sprintf(spec->devString, "%s", devString);
  spec->status = pic_open(&spec->picHandle, // Handle to PIC.
			  spec->devString,  // Device configuration string.
			  &spec->McBreak,   // Pointer to break flag.
			  FLAGS);           // Optional run-time behavior modifiers.

  if(spec->status <= 0)
  {
    XMC_ERROR_STDOUT("PIC OPEN FAILURE.");
    return(NULL);
  }

/*   // PIC sniff. */
/*   //--------------------------------------------------------------------------------------------- */
/*   spec->status = pic_sniff(&spec->picHandle,0); */

/*   // PIC reset. */
/*   //--------------------------------------------------------------------------------------------- */
/*   spec->status = pic_reset(&spec->picHandle, FLG_BOOT); */
/*   printf("HARD RESET!\n"); */

  // Initialize the number of DMA channels to zero.
  //---------------------------------------------------------------------------------------------
  spec->nDMA = 0;

  // Set the internal clock rate.
  //---------------------------------------------------------------------------------------------
  spec->ifs = fs;
  spec->irate = fs;

  // Return the spec.
  //---------------------------------------------------------------------------------------------
  return(spec);
}

//-----------------------------------------------------------------------------------------------
// Rout: xccPICIOInit
// Desc: This routine initializes the PIC card.
//-----------------------------------------------------------------------------------------------
VOID xccPICIOInit(INT32 dmaBytes,
		  INT32 dmaBits,
		  INT32 dmaDirection,
		  FLT64 tfreq,
		  INT32 tdeci,
		  INT32 tgain,
		  xccPICSpec *spec)
{
  INT32 cn;
  //  FLT32 delta;
  INT32 FLAGS;
  //INT32 status;
  INT32 tempINT32;

  FLAGS = 0;

  // Increment the number of DMA channels by one.
  //---------------------------------------------------------------------------------------------
  spec->nDMA++;
  cn = spec->nDMA-1;

  // Check the type (tuner or no tuner).
  //---------------------------------------------------------------------------------------------
  //spec->status = pic_getkey(&spec->picHandle,0,KEY_PTYPE,&spec->type,4);

  // Check "tdeci".
  //---------------------------------------------------------------------------------------------
  tempINT32 = tdeci;
  tdeci     = pic_tuner_dec(&spec->picHandle,tdeci,-1,0);
  if(tdeci != tempINT32)
  {
    XMC_ERROR_STDOUT("DECIMATION CHANGED FROM %ld to %ld\n",tempINT32,tdeci);
  }

  // Check the type for tunner and reset the rate.
  //---------------------------------------------------------------------------------------------
  //if(spec->type == IOPT_TUNER)
  //{
  //  spec->ifs = tdeci * 2.0 * spec->ifs;
  //  spec->irate = spec->ifs;
  //}

  // Check "tfreq".
  //---------------------------------------------------------------------------------------------
  tfreq = (spec->ifs/2.0) * pic_tuner_freq(&spec->picHandle, 2.0*tfreq/spec->ifs, 0);

  // Initialize some parts of the spec.
  //---------------------------------------------------------------------------------------------
  //delta = 2.0*tfreq/spec->internalClkRate;
  spec->dma[cn].Bits            = dmaBits;
  spec->dma[cn].Bytes           = dmaBytes;
  spec->dma[cn].Samples         = dmaBytes*8/dmaBits;
  spec->dma[cn].Direction       = dmaDirection;
  spec->dma[cn].tunerFreq       = 2.0*(tfreq)/spec->ifs;//pic_tuner_freq(&spec->picHandle, delta, 0);
  spec->dma[cn].tunerDeci       = tdeci;
  spec->dma[cn].tunerGain       = tgain;

  if( spec->dma[cn].Bits ==  -8 ) spec->dma[cn].Samples = spec->dma[cn].Bytes*8/16; // This is a complex cases.
  if( spec->dma[cn].Bits == -16 ) spec->dma[cn].Samples = spec->dma[cn].Bytes*8/32; // This is a complex cases.

  // pic_ioport.
  //---------------------------------------------------------------------------------------------
  spec->dma[cn].ChannelNumber = 
    pic_ioport(&spec->picHandle,        // Handle to PIC.
	       -1,                      // Type of I/O port to use  (-1=use default from pic_open).
	       -1,                      // Index of I/O port to use (-1=use default from pic_open).
	       -1,                      // DMA channel              (-1=use default, 0 = no DMA).
	       spec->dma[cn].Direction, // Transfer direction       (-1=record, +1=playback).
	       spec->dma[cn].Bits,      // Number of bits per data sample.
	       spec->irate,             // Internal clock rate.
	       spec->dma[cn].tunerFreq, // Tuner frequency.
	       spec->dma[cn].tunerDeci, // Tuner decimation.
	       spec->dma[cn].tunerGain, // Tuner gain.
	       FLAGS);                  // Flags.

  XMC_DEBUG_STDOUT("tfreq %f\n", tfreq);
  XMC_DEBUG_STDOUT("spec->ifs %f\n", spec->ifs);
  XMC_DEBUG_STDOUT("spec->dma[cn].tunerFreq %f\n", spec->dma[cn].tunerFreq);
  XMC_DEBUG_STDOUT("spec->dma[cn].tunerDeci %ld\n", spec->dma[cn].tunerDeci);
  XMC_DEBUG_STDOUT("spec->dma[cn].tunerGain %ld\n", spec->dma[cn].tunerGain);
  if(spec->dma[cn].ChannelNumber <= 0)
  {
    XMC_ERROR_STDOUT("PIC IOPORT FAILURE.");
    printf("DMAC - %ld \n", spec->dma[cn].ChannelNumber);
    return;
  }
  XMC_DEBUG_STDOUT("DMAC - %ld \n", spec->dma[cn].ChannelNumber);

  // pic_map.
  //---------------------------------------------------------------------------------------------
  spec->status = 
    pic_mapmem (&spec->picHandle,      // Handle to PIC.
		&spec->dma[cn].dmaMap, // DMA data buffer map structure.
		spec->dma[cn].Bytes,   // Size of user buffer.
		1);                    // Mode (-2=unmap, -1=unmap/dealloc, +1=alloc/map, +2=map)


  //  spec->status = 
  //  pic_map(&spec->picHandle,        // Handle to PIC.
  //	    &spec->dma[cn].DataINT32,  // DMA data buffer Address.
  //	    &spec->dma[cn].PCIAddress, // Physical PCI address of DMA buffer.
  //	    spec->dma[cn].Bytes,       // Size of user buffer.
  //	    +1);                       // Mode (-2=unmap, -1=unmap/dealloc, +1=alloc/map, +2=map)
  //spec->dma[cn].DataINT16 = (INT16 *) spec->dma[cn].DataINT32;
  //spec->dma[cn].DataINT08 = (INT08 *) spec->dma[cn].DataINT32; //Weird problem here.

  if(spec->status <= 0)
  {
    XMC_ERROR_STDOUT("PIC MAP FAILURE.");
    return;
  }

  // pic_dma
  //---------------------------------------------------------------------------------------------
  spec->status = 
    pic_dmasetup (&spec->picHandle,            // Handle to PIC.
		  spec->dma[cn].ChannelNumber, // DMA channel.
		  spec->dma[cn].Direction,     // Transfer direction (-1=record, +1=playback).
		  &spec->dma[cn].dmaMap,       // DMA data buffer map structure.
		  -1,                          // DMA transfer size (-1=internal default.)
		  FLAGS);                      // Flags.



  // spec->status = pic_dma(&spec->picHandle,         // Handle to PIC.
  //			 spec->dma[cn].ChannelNumber, // DMA channel.
  //			 spec->dma[cn].Direction,     // Transfer direction (-1=record, +1=playback).
  //			 spec->dma[cn].DataINT32,     // User buffer.
  //			 spec->dma[cn].PCIAddress,    // PCI address of DMA buffer.
  //			 spec->dma[cn].Bytes,         // DMA buffer size.
  //			 -1,                          // DMA transfer size (-1=internal default.)
  //			 FLAGS);                      // Flags.
  if(spec->status <= 0)
  {
    XMC_ERROR_STDOUT("PIC DMA FAILURE.");
    printf("PIC DMA - status = %ld\n", spec->status);
    return;
  }
  XMC_DEBUG_STDOUT("PIC DMA - status = %ld\n", spec->status);

}

/* End preprocessor directives ----------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/

/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
