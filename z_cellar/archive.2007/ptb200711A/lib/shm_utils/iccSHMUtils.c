/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: iccSHMUtils.c
// Desc: This file contains the code for the iccSHMUtils routine.
// Hist: When       Who  What
//       01/27/2005 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "shm_utils.h"

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
iccSHMSpec *iccSHMInit( INT32 type,
			const CHR08 *format,
			FLT64 xstart,
			FLT64 xdelta,
			INT32 xunits,
			INT32 subsize,
			FLT64 ystart,
			FLT64 ydelta,
			INT32 yunits,
			INT32 bpe)
{
  iccSHMSpec *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (iccSHMSpec *) iccMallocVOID_Align032( sizeof(iccSHMSpec) );

  // Malloc the "shared" memory for the spec.
  //----------------------------------------------------------------------------
  spec->shmKey = ftok("/usr/.",'P');
  spec->shmID  = shmget(spec->shmKey, sizeof(shm_t), 0644|IPC_CREAT);
  spec->shm   = (shm_t *) shmat(spec->shmID, 0, 0);

  // Set buffer size and initialize variables.
  //----------------------------------------------------------------------------
  spec->shm->bSize  = BUFFER_SIZE;
  spec->shm->bIndx  = 0;
  spec->shm->bLndx  = 0;
  spec->shm->WDWRDR = 0;

  // Initialize XMidas variables.
  //----------------------------------------------------------------------------
  spec->shm->type    = type;
  sprintf(spec->shm->format,"%c%c",format[0],format[1]);
  spec->shm->xstart  = xstart;
  spec->shm->xdelta  = xdelta;
  spec->shm->xunits  = xunits;
  spec->shm->subsize = subsize;
  spec->shm->ystart  = ystart;
  spec->shm->ydelta  = ydelta;
  spec->shm->yunits  = yunits;
  spec->shm->bpe     = bpe;

  return( spec );
}

iccSHMSpec *iccSHMAttach( VOID )
{
  iccSHMSpec *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (iccSHMSpec *) iccMallocVOID_Align032( sizeof(iccSHMSpec) );

  // Attach the "shared" memory to the spec.
  //----------------------------------------------------------------------------
  spec->shmKey = ftok("/usr/.",'P');
  spec->shmID  = shmget(spec->shmKey, sizeof(shm_t), 0644|IPC_CREAT);
  spec->shm    = (shm_t *) shmat(spec->shmID, 0, 0);

  return(spec);
}


VOID iccSHMTerm( iccSHMSpec *spec )
{
  shmctl(spec->shmID,IPC_RMID,NULL);
  shmdt(spec->shm);
}


VOID iccSHMWrite1M(INT08 *iData, iccSHMSpec *spec)
{
  INT32 ii;

  // Write the data.
  //----------------------------------------------------------------------------
  for(ii=0; ii<1048576; ii++)
  {
    spec->shm->bufferINT08[spec->shm->bIndx+ii]=iData[ii];
  }

  // Lock access to the shared memory.
  //----------------------------------------------------------------------------
  while(spec->shm->WDWRDR==1) usleep(1);
  if(spec->shm->WDWRDR==0)
  {
    spec->shm->WDWRDR=1;
  }
  else 
  {
    XMC_DEBUG_STDOUT("Way uncool shared memory error!\n");
  }

  // Update the index.
  //----------------------------------------------------------------------------
  spec->shm->bIndx+=ii;
  spec->shm->bIndx = spec->shm->bIndx % BUFFER_SIZE;

  // Update the loop counter.
  //----------------------------------------------------------------------------
  if( spec->shm->bIndx == 0 ) spec->shm->bLndx++;

  // Release access to the shared memory.
  //----------------------------------------------------------------------------
  spec->shm->WDWRDR=0;
}

INT32 iccSHMRead(INT08 *iData, iccSHMSpec *spec)
{
  UNT32 ii;
  INT08 *pa=iData;
  UNT32 shmDifference;
  UNT32 loopStrt1;
  UNT32 loopStop1;
  UNT32 loopStrt2;
  UNT32 loopStop2;
  static UNT32 bIndx00=0;
  static UNT32 bIndx01=0;
  static UNT32 bIndx02=0;
  static UNT32 bLndx00=0;
  static UNT32 bLndx01=0;

  // Lock access to the shared memory.
  //----------------------------------------------------------------------------
  while(spec->shm->WDWRDR==1) usleep(1);
  if(spec->shm->WDWRDR==0)
  {
    spec->shm->WDWRDR=1;
  }
  else 
  {
    XMC_DEBUG_STDOUT("Way uncool shared memory error!\n");
  }

  // Update the buffer index status.
  //--------------------------------------------------------------------------
  bIndx02 = bIndx01;
  bIndx01 = bIndx00;
  bIndx00 = spec->shm->bIndx;

  // Update the buffer cycle status.
  //--------------------------------------------------------------------------
  bLndx01   = bLndx00;
  bLndx00   = spec->shm->bLndx;

  // Release access to the shared memory.
  //----------------------------------------------------------------------------
  spec->shm->WDWRDR=0;

  // Calculate the difference in the buffer.
  //--------------------------------------------------------------------------
  if( bIndx01 < bIndx02 )
  {
    shmDifference = bIndx01 - bIndx02 + BUFFER_SIZE;
  }
  else 
  {
    shmDifference = bIndx01 - bIndx02;
  }

  // Calculate start and stop of the loops.
  //--------------------------------------------------------------------------
  if( bIndx01 < bIndx02 )    // Are we in a buffer wrap situation?
  {                          // 
    loopStrt1 = bIndx02;     // Loop 1 will go from bIndx02
    loopStop1 = BUFFER_SIZE; // to the end of the shm buffer.
    loopStrt2 = 0;           // Loop 2 will go from start of shm buffer
    loopStop2 = bIndx01;     // to bIndx01.
  }
  else                        // If not.
  {                           //
    loopStrt1 = bIndx02;      // Loop 1 will go from bIndx02
    loopStop1 = bIndx01;      // to bIndx01.
    loopStrt2 = 0;            // Loop 2 will bet set so that it does
    loopStop2 = 0;            // not execute.
  }

  // Perform the read loops.
  //--------------------------------------------------------------------------
  for( ii=loopStrt1; ii<loopStop1; ii++)
  {
    *pa = spec->shm->bufferINT08[spec->shm->bIndx+ii];
    pa++;
  }
  for( ii=loopStrt2; ii<loopStop2; ii++)
  {
    *pa = spec->shm->bufferINT08[spec->shm->bIndx+ii];
    pa++;
  }

  return(shmDifference);
}

VOID iccSHMWrite(INT08 *iData, UNT32 nSamples, iccSHMSpec *spec)
{
  UNT32 ii;
  INT08 *pa=iData;
  UNT32 shmDifference;
  UNT32 loopStrt1;
  UNT32 loopStop1;
  UNT32 loopStrt2;
  UNT32 loopStop2;
  static UNT32 bIndx00=0;
  static UNT32 bIndx01=0;
  static UNT32 bIndx02=0;
  static UNT32 bLndx00=0;
  static UNT32 bLndx01=0;

  // Lock access to the shared memory.
  //----------------------------------------------------------------------------
  while(spec->shm->WDWRDR==1) usleep(1);
  if(spec->shm->WDWRDR==0)
  {
    spec->shm->WDWRDR=1;
  }
  else 
  {
    XMC_DEBUG_STDOUT("Way uncool shared memory error!\n");
  }

  // Update the buffer index status.
  //--------------------------------------------------------------------------
  bIndx02 = bIndx01;
  bIndx01 = bIndx00;
  bIndx00 = spec->shm->bIndx;

  // Update the buffer cycle status.
  //--------------------------------------------------------------------------
  bLndx01   = bLndx00;
  bLndx00   = spec->shm->bLndx;

  // Release access to the shared memory.
  //----------------------------------------------------------------------------
  spec->shm->WDWRDR=0;

  // Calculate the difference in the buffer.
  //--------------------------------------------------------------------------
  if( bIndx01 < bIndx02 )
  {
    shmDifference = bIndx01 - bIndx02 + BUFFER_SIZE;
  }
  else 
  {
    shmDifference = bIndx01 - bIndx02;
  }

  // Calculate start and stop of the loops.
  //--------------------------------------------------------------------------
  if( bIndx01 < bIndx02 )    // Are we in a buffer wrap situation?
  {                          // 
    loopStrt1 = bIndx02;     // Loop 1 will go from bIndx02
    loopStop1 = BUFFER_SIZE; // to the end of the shm buffer.
    loopStrt2 = 0;           // Loop 2 will go from start of shm buffer
    loopStop2 = bIndx01;     // to bIndx01.
  }
  else                        // If not.
  {                           //
    loopStrt1 = bIndx02;      // Loop 1 will go from bIndx02
    loopStop1 = bIndx01;      // to bIndx01.
    loopStrt2 = 0;            // Loop 2 will bet set so that it does
    loopStop2 = 0;            // not execute.
  }

  // Perform the read loops.
  //--------------------------------------------------------------------------
  for( ii=loopStrt1; ii<loopStop1; ii++)
  {
    *pa = spec->shm->bufferINT08[spec->shm->bIndx+ii];
    pa++;
  }
  for( ii=loopStrt2; ii<loopStop2; ii++)
  {
    *pa = spec->shm->bufferINT08[spec->shm->bIndx+ii];
    pa++;
  }

}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/
/*-------------------------------UNCLASSIFIED---------------------------------*/
