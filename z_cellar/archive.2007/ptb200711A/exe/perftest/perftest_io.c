/****************************************************************************
 *  perftest_iotest.c 
 *
 *  Description:  Libraries for performing I/O tests using ANSI file routines
 *
 *  Author:       rdh
 *  Revisions:
 *  --------      ---   -----------------------------------------------------
 *  01/27/99      rdh   baseline
 *  08/20/00      rdh   modified to have MAX/MIN I/O rate reported also
 *
 ***************************************************************************/

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "perftest.h"

#define IO_BYTES  1024*1024

int_4 perftest_iotest (PerfTestInfo *inf)
{
  char   *bbuf;
  int_4  i,ii;
  int_4  iloopcnt;
  int_4  istat;
  real_8 dtmp, dnomrate;
  real_8 dtmsecA, dtmusecA;
  real_8 dtmsecB, dtmusecB;
  real_8 dtmsecC, dtmusecC;
  real_8 dtmsecD, dtmusecD;
  real_8 ddelta_min, ddelta_max;
  real_8 tdelta, tdelta_min, tdelta_max;
  real_8 dtotalbytes, dtimetotal, dratetotal, dratemin, dratemax;
  FILE   *fp;

  /* Create dummy buffer for output */
  bbuf = (void *) malloc(IO_BYTES);
  if (bbuf == NULL) {
    fprintf(stderr,"Insufficient memory for I/O TEST!\n");
    return (-1);
  }
  else { 
    for (i=0; i<IO_BYTES; i++) bbuf[i] = 1;
  }

  /* Calculate the major loop count */
  iloopcnt = (1024.0*1024.0*(real_8) inf->iofilesize)/((real_8) IO_BYTES);
  iloopcnt = (iloopcnt > 0) ? iloopcnt : 1;
  dtotalbytes = ((real_8) iloopcnt)*((real_8) IO_BYTES);

  /* Open output file */
  fp = fopen(inf->iofile,"wb");
  if (fp == NULL) {
    fprintf(stderr,"Error creating I/O TEST file!\n");
    if (bbuf != NULL) free(bbuf);
    return (-1);
  }
  fflush(fp);

  /* Output I/O test banner */
  fprintf(inf->fpout," \n");
  fprintf(inf->fpout,".....................%s......................\n",
          "...I/O Transfer..");
  fprintf(inf->fpout,"%12s %15s %15s %15s\n",
          "OPERATION","TOTAL OPS","SECONDS","MB/sec");
  fprintf(inf->fpout,"%12s %15s %15s %15s\n",
          "---------","---------","-------","------");
  if (inf->debug > 1) {
    fprintf(stderr,"I/O Test file size: %f \n",dtotalbytes);
    fprintf(stderr,"I/O Test loopcount: %ld \n",iloopcnt);
  } 

  /* Start write test */
  tdelta_min = 1.0e30;
  tdelta_max = 1.0e-30;
  ddelta_min  = 0.0;
  ddelta_max  = 0.0;
  dtotalbytes = 0.0;
  dnomrate = 1.0e6 * inf->estio;
  dtmp = 0.0;
  ii   = 0;
  istat = m_gettimeofday(&dtmsecA,&dtmusecA);
  for (i=0; i<iloopcnt; i++) {
    istat  = m_gettimeofday(&dtmsecC,&dtmusecC);
    dtmp  += (real_8) fwrite(bbuf,sizeof(char),IO_BYTES,fp);
    istat  = m_gettimeofday(&dtmsecD,&dtmusecD);
    tdelta = (dtmsecD-dtmsecC) + (dtmusecD-dtmusecC);
    if (tdelta < tdelta_min) {
      tdelta_min = tdelta;
      ddelta_min = dtotalbytes + dtmp;
    }
    if (tdelta > tdelta_max) {
      tdelta_max = tdelta;
      ddelta_max = dtotalbytes + dtmp;
    }
    if (dtmp >= dnomrate) {
      dtotalbytes += dtmp;
      dtmp = 0.0;
      fprintf(stderr,".");
      fflush(stderr);
    }
  }
  dtotalbytes += dtmp;
  fflush(fp);
  sync();
  fclose(fp);
  fprintf(stderr,".\n");
  m_gettimeofday(&dtmsecB,&dtmusecB);

  /* Output write results */
  dtimetotal = (dtmsecB-dtmsecA) + (dtmusecB-dtmusecA);
  dratetotal = (dtimetotal > 0.0) ? (dtotalbytes/dtimetotal) : 0.0;
  dratemax   = ((real_8) IO_BYTES)/tdelta_min;
  dratemin   = ((real_8) IO_BYTES)/tdelta_max;
  fprintf(inf->fpout,"Write Avg:   %15.1f %15.7f %15.1f %15.2f\n",
                  dtotalbytes,dtimetotal,0.0,(1.0e-6*dratetotal));
  fprintf(inf->fpout,"Write Max:   %15.1f %15.7f %15.1f %15.2f\n",
                  (real_8) IO_BYTES ,tdelta_min,ddelta_min,(1.0e-6*dratemax));
  fprintf(inf->fpout,"Write Min:   %15.1f %15.7f %15.1f %15.2f\n",
                  (real_8) IO_BYTES ,tdelta_max,ddelta_max,(1.0e-6*dratemin));

  /* Wait 2 seconds for system and buffered I/O system to recover */
  for (i=0;i<2;i++) usleep(999999);


  /* Open input file */ 
  fp = fopen(inf->iofile,"rb");
  if (fp == NULL) {
    fprintf(stderr,"Error locating I/O TEST file!\n");
    if (bbuf != NULL) free(bbuf);
    return (-1);
  }
  fflush(fp);

  /* Start read test */
  tdelta_min = 1.0e30;
  tdelta_max = 1.0e-30;
  ddelta_min  = 0.0;
  ddelta_max  = 0.0;
  dtotalbytes = 0.0;
  dnomrate = 1.0e6 * inf->estio;
  dtmp = 0.0;
  ii   = 0;
  istat = m_gettimeofday(&dtmsecA,&dtmusecA);
  for (i=0; i<iloopcnt; i++) {
    istat  = m_gettimeofday(&dtmsecC,&dtmusecC);
    dtmp  += (real_8) fread(bbuf,sizeof(char),IO_BYTES,fp);
    istat  = m_gettimeofday(&dtmsecD,&dtmusecD);
    tdelta = (dtmsecD-dtmsecC) + (dtmusecD-dtmusecC);
    if (tdelta < tdelta_min) {
      tdelta_min = tdelta;
      ddelta_min = dtotalbytes + dtmp;
    }
    if (tdelta > tdelta_max) {
      tdelta_max = tdelta;
      ddelta_max = dtotalbytes + dtmp;
    }
    if (dtmp >= dnomrate) {
      dtotalbytes += dtmp;
      dtmp = 0.0;
      fprintf(stderr,".");
      fflush(stderr);
    }
  }
  dtotalbytes += dtmp;
  fflush(fp);
  sync();
  fclose(fp);
  fprintf(stderr,".\n");
  m_gettimeofday(&dtmsecB,&dtmusecB);


  /* Output read results */
  dtimetotal = (dtmsecB-dtmsecA) + (dtmusecB-dtmusecA);
  dratetotal = (dtimetotal > 0.0) ? (dtotalbytes/dtimetotal) : 0.0;
  dratemax   = ((real_8) IO_BYTES)/tdelta_min;
  dratemin   = ((real_8) IO_BYTES)/tdelta_max;
  fprintf(inf->fpout,"Read Avg:    %15.1f %15.7f %15.1f %15.2f\n",
                  dtotalbytes,dtimetotal,0.0,(1.0e-6*dratetotal));
  fprintf(inf->fpout,"Read Max:    %15.1f %15.7f %15.1f %15.2f\n",
                  (real_8) IO_BYTES ,tdelta_min,ddelta_min,(1.0e-6*dratemax));
  fprintf(inf->fpout,"Read Min:    %15.1f %15.7f %15.1f %15.2f\n",
                  (real_8) IO_BYTES ,tdelta_max,ddelta_max,(1.0e-6*dratemin));

  /* Free the buffer */
  if (bbuf != NULL) free(bbuf);

  /* Remove the test file */
  if (inf->debug < 3) {
    if (fp != NULL) {
      if (remove(inf->iofile) != 0) 
        fprintf(stderr,"Unable to remove I/O TEST file: %s\n",inf->iofile);
    }
  }
  else {
    fprintf(stderr,"Debug mode. I/O TEST file not erased: %s\n",inf->iofile);
  }

  return(0);
}
