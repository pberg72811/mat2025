/****************************************************************************
 *  perftest_memtest.c
 *
 *  Description:  Libraries for performing memory tests
 *
 *  Author:       rdh
 *  Revisions:
 *  --------      ---   -----------------------------------------------------
 *  01/27/00      rdh   baseline
 *
 ***************************************************************************/

/* Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "perftest.h"    

int_4 perftest_memtest (PerfTestInfo *inf)
{
  char   *bufA, *bufB;
  int_4  memtestbytes = 16777216;    /* Start with 16MB */
  int_4  i,ii;
  int_4  iloopcnt;
  int_4  istat;
  real_8 dtimebgnA,dtimebgnB,dtimeendA,dtimeendB;
  real_8 doptjunk,dstop;
  real_8 dtotalbytes,dtimetotal,dratetotal;

  /* First, malloc two buffers larger than on-chip cache */
  bufA = NULL;
  bufB = NULL;

  while ((bufA == NULL)&&(bufB == NULL)&&(memtestbytes > 0)) {
    bufA = (void *) malloc(memtestbytes);
    bufB = (void *) malloc(memtestbytes);
    if ((bufA == NULL)||(bufB == NULL)) {
      memtestbytes -= 1048576;
      if (bufA != NULL) free(bufA);
      if (bufB != NULL) free(bufB);
      bufA = NULL;
      bufB = NULL;
    }
  }

  if (memtestbytes <= 0) {
    fprintf(stderr,"Insufficient memory for MEMTEST!\n");
    return (-1);
  }  

  /* Estimate number of bytes/second we can move and compute loopcnt */
  iloopcnt = ((1.0e6 * inf->estmem) / ((real_8) memtestbytes)) + 0.5;
  iloopcnt = (iloopcnt > 0) ? iloopcnt : 1;

  /* Output Memory Test Banner */
  fprintf(inf->fpout," \n");
  fprintf(inf->fpout,".....................%s......................\n",
          ".Memory Transfer.");
  fprintf(inf->fpout,"%12s %15s %15s %15s\n",
          "OPERATION","TOTAL OPS","SECONDS","MB/sec");
  fprintf(inf->fpout,"%12s %15s %15s %15s\n",
          "---------","---------","-------","------");
  if (inf->debug > 1) {
    fprintf(stderr,"Memory Test buffer size: %ld \n",memtestbytes);
    fprintf(stderr,"Master Loop count is:    %ld \n",iloopcnt);
  }  

  /* Run the test for 5 seconds */
  doptjunk    = 0.0;
  dtotalbytes = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + 5.0;

  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      memcpy(bufA,bufB,memtestbytes);
      ii = (i < memtestbytes) ? i : 0;
      bufA[ii] = bufB[ii];
    }
    doptjunk += bufA[ii] + bufB[ii];
    dtotalbytes += ((real_8) iloopcnt) * ((real_8) memtestbytes);
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);

  /* Dummy statement to keep compiler from optimizing loop out */
  if (inf->debug >10) fprintf(stderr," %i %i\n",bufA[ii],bufB[ii]);

  /* Free the buffers */
  if (bufA != NULL) free(bufA);
  if (bufB != NULL) free(bufB);

  /* Print the results */
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dtotalbytes/dtimetotal) : 0.0;

  fprintf(inf->fpout,"MEM Moves:   %15.1f %15.7f %15.2f\n",
                  dtotalbytes,dtimetotal,(1.0e-6*dratetotal));

  return (0);
}
