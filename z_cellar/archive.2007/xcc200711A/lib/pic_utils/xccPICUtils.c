/*----------------------------------------UNCLASSIFIED-----------------------------------------*/
// File: xccPICUtils.c
// Desc: This file contains the code for the xccPICUtils routine.
// Note: For possible hardware configuration entries see "~/steswd/cfg/itthwconfig.key"
// Hist: When       Who  What
//       06/26/2003 ptb  Initial Code.
/*---------------------------------------------------------------------------------------------*/
/* Preprocessor directives --------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
/* Include files ------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#include "pic_utils.h"

/* Constants ----------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------------*/
#define DEBUG      FALSE
#define DEBUG_TYPE XMC_DEBUG_STDOUT
#define XMC_DEBUG  if( DEBUG ) DEBUG_TYPE

#define PLAYBACK (+1)
#define RECORD   (-1)

/* Type defines --------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Macros --------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Prototypes ----------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Routines ------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
//------------------------------------------------------------------------------
// Rout: xccPICTerm
// Desc: This routine terminates the PIC card processing.
//------------------------------------------------------------------------------
VOID xccPICTerm(xccPICSpec *spec)
{
  INT32 ii;

  for(ii=0; ii< spec->nDMA; ii++)
  {
    spec->status = pic_dmafunc(&spec->picHandle, spec->dma[ii].ChannelNumber, DMA_CANCEL);
    XMC_DEBUG("DMA_CANCEL: Status is %ld\n",spec->status);

    //spec->status = pic_dmafunc(&spec->picHandle, spec->dmaChannelNumber, DMA_MISS);
    //XMC_DEBUG("DMA_MISS: Status is %ld\n",spec->status);

  // pic_map unmap.
  //----------------------------------------------------------------------------
  spec->status = 
    pic_mapmem (&spec->picHandle,      // Handle to PIC.
		&spec->dma[ii].dmaMap, // DMA data buffer map structure.
		spec->dma[ii].Bytes,   // Size of user buffer.
		-1);                   // Mode (-2=unmap, -1=unmap/dealloc, +1=alloc/map, +2=map)
    XMC_DEBUG("PIC_MAPMEM unmap: Status is %ld\n",spec->status);
  }

/*   spec->status = pic_reset(&spec->picHandle, FLG_BOOT); */
/*   XMC_DEBUG("PIC_RESET: Status is %ld\n",spec->status); */

  spec->status = pic_close(&spec->picHandle);
  XMC_DEBUG("PIC_CLOSE: Status is %ld\n",spec->status);

  xmcFree(spec);
}

//------------------------------------------------------------------------------
// Rout: xccPICReset
// Desc: This routine resets the PIC card.
//------------------------------------------------------------------------------
INT32 xccPICReset(xccPICSpec *spec)
{
  spec->status = pic_reset(&spec->picHandle, 0);
  XMC_DEBUG("PIC_RESET: Status is %ld\n",spec->status);
  return(spec->status);
}

//------------------------------------------------------------------------------
// Rout: xccPICResetFLGBoot
// Desc: This routine resets the PIC card.
//------------------------------------------------------------------------------
INT32 xccPICResetFLGBoot(xccPICSpec *spec)
{
  spec->status = pic_reset(&spec->picHandle, FLG_BOOT);
  XMC_DEBUG("PIC_RESET_FLG_BOOT: Status is %ld\n",spec->status);
  return(spec->status);
}

INT32 xccPICTC(FLT64 offset, FLT64 delta, INT32 flag, xccPICSpec *spec)
{
  INT32 status;
  FLT64 soy=0.0;
  FLT64 fsoy=0.0;

  status = 
    pic_tc (&spec->picHandle,
	    spec->dma[0].ChannelNumber,
	    &offset,
	    &delta,
	    &soy,
	    &fsoy,
	    0);
  printf("xccPICTC: status = %ld\n",status);
  printf("xccPICTC: offset = %f\n",offset);
  printf("xccPICTC: delta  = %f\n",delta);
  printf("xccPICTC: soy    = %f\n",soy);
  printf("xccPICTC: fsoy   = %f\n",fsoy);
  return status;
}
  
//------------------------------------------------------------------------------
// Rout: xccPICTunerRatio
// Desc: This sets the tuner ratio on the gc4016
//------------------------------------------------------------------------------
INT32 xccPICTunerRatio(FLT64 ratio, INT32 channelNumber, xccPICSpec *spec)
{
  INT32 c=channelNumber;
  spec->status = pic_setkeyd (&spec->picHandle, spec->dma[c].ChannelNumber, KEY_RATIO, ratio);
  XMC_DEBUG("KEY_RATIO_STATUS: Status is %ld\n",spec->status);
  return(spec->status);
}

//------------------------------------------------------------------------------
// Rout: xccPICDumpGC4016
// Desc: This dumps the registers for the gc4016
//------------------------------------------------------------------------------
INT32 xccPICDumpGC4016(xccPICSpec *spec)
{
  spec->status = pic_test(&spec->picHandle, 101, 1); // Chip 1 Channel 0
  spec->status = pic_test(&spec->picHandle, 102, 1); // Chip 2 Channel 0
  spec->status = pic_test(&spec->picHandle, 103, 1); // Chip 1 Channel 1
  spec->status = pic_test(&spec->picHandle, 104, 1); // Chip 2 Channel 1
  spec->status = pic_test(&spec->picHandle, 105, 1); // Chip 1 Channel 2
  spec->status = pic_test(&spec->picHandle, 106, 1); // Chip 2 Channel 2
  spec->status = pic_test(&spec->picHandle, 107, 1); // Chip 1 Channel 3
  spec->status = pic_test(&spec->picHandle, 108, 1); // Chip 2 Channel 3
  XMC_DEBUG("PIC_DUMP_GC4016_STATUS: Status is %ld\n",spec->status);
  return(spec->status);
}
//------------------------------------------------------------------------------
// Rout: xccPICSniff
// Desc: This routine prints out information about the PIC card.
//------------------------------------------------------------------------------
INT32 xccPICSniff(xccPICSpec *spec)
{
  spec->status = pic_sniff(&spec->picHandle, 0);
  XMC_DEBUG("PIC_SNIFF: Status is %ld\n",spec->status);
  return(spec->status);
}

//------------------------------------------------------------------------------
// Rout: xccPIC_DMA_CONTINUOUS
// Desc: This routine starts DMA_CONTINUOUS
//------------------------------------------------------------------------------
INT32 xccPIC_DMA_CONTINUOUS(INT32 channelNumber, xccPICSpec *spec)
{
  INT32 c=channelNumber;
  spec->status = pic_dmafunc(&spec->picHandle, spec->dma[c].ChannelNumber, DMA_CONTINUOUS);
  XMC_DEBUG("DMA_CONTINUOUS: Status is %ld\n",spec->status);
  return(spec->status);
}

//------------------------------------------------------------------------------
// Rout: xccPIC_DMA_STATUS
// Desc: This routine reports back the DMA_STATUS
//------------------------------------------------------------------------------
INT32 xccPIC_DMA_STATUS(INT32 channelNumber, xccPICSpec *spec)
{
  INT32 c=channelNumber;
  spec->status = pic_dmafunc(&spec->picHandle, spec->dma[c].ChannelNumber, DMA_STATUS);
  XMC_DEBUG("DMA_STATUS: Status is %ld\n",spec->status);
  return(spec->status);
}

//------------------------------------------------------------------------------
// Rout: xccPIC_DMA_ONESHOT
// Desc: This routine starts a DMA_ONESHOT
//------------------------------------------------------------------------------
INT32 xccPIC_DMA_ONESHOT(INT32 channelNumber, xccPICSpec *spec)
{
  INT32 c=channelNumber;
  spec->status = pic_dmafunc(&spec->picHandle, spec->dma[c].ChannelNumber, DMA_ONESHOT);
  XMC_DEBUG("DMA_ONESHOT: Status is %ld\n",spec->status);
  return(spec->status);
}

//------------------------------------------------------------------------------
// Rout: xccPIC_DMA_WAIT
// Desc: This routine performs a DMA_WAIT
//------------------------------------------------------------------------------
INT32 xccPIC_DMA_WAIT(INT32 channelNumber, xccPICSpec *spec)
{
  INT32 c=channelNumber;
  spec->status = pic_dmafunc(&spec->picHandle, spec->dma[c].ChannelNumber, DMA_WAIT);
  XMC_DEBUG("DMA_WAIT: Status is %ld\n",spec->status);
  return(spec->status);
}

//------------------------------------------------------------------------------
// Rout: xccPIC_DMA_STOP
// Desc: This routine performs a DMA_STOP
//------------------------------------------------------------------------------
INT32 xccPIC_DMA_STOP(INT32 channelNumber, xccPICSpec *spec)
{
  INT32 c=channelNumber;
  spec->status = pic_dmafunc(&spec->picHandle, spec->dma[c].ChannelNumber, DMA_STOP);
  XMC_DEBUG("DMA_STOP: Status is %ld\n",spec->status);
  return(spec->status);
}

//------------------------------------------------------------------------------
// Rout: xccPIC_DMA_CYCLE
// Desc: This routine reports back the DMA_CYCLE
//------------------------------------------------------------------------------
INT32 xccPIC_DMA_CYCLE(INT32 channelNumber, xccPICSpec *spec)
{
  INT32 c=channelNumber;
  spec->status = pic_dmafunc(&spec->picHandle, spec->dma[c].ChannelNumber, DMA_CYCLE);
  XMC_DEBUG("DMA_CYCLE: Status is %ld\n",spec->status);
  return(spec->status);
}

//------------------------------------------------------------------------------
// Rout: xccPIC_DMA_RESET
// Desc: This routine performs a DMA_RESET
//------------------------------------------------------------------------------
INT32 xccPIC_DMA_RESET(INT32 channelNumber, xccPICSpec *spec)
{
  INT32 c=channelNumber;
  spec->status = pic_dmafunc(&spec->picHandle, spec->dma[c].ChannelNumber, DMA_RESET);
  XMC_DEBUG("DMA_RESET: Status is %ld\n",spec->status);
  return(spec->status);
}

//------------------------------------------------------------------------------
// Rout: xccPIC_DMA_CANCEL
// Desc: This routine performs a DMA_CANCEL
//------------------------------------------------------------------------------
INT32 xccPIC_DMA_CANCEL(INT32 channelNumber, xccPICSpec *spec)
{
  INT32 c=channelNumber;
  spec->status = pic_dmafunc(&spec->picHandle, spec->dma[c].ChannelNumber, DMA_CANCEL);
  XMC_DEBUG("DMA_CANCEL: Status is %ld\n",spec->status);
  return(spec->status);
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
