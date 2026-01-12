/****************************************************************************
 *  perftest_math.c   
 *
 *  Description:  Libraries for performing standard math tests
 *
 *  Author:       rdh
 *  Revisions:
 *  --------      ---   -----------------------------------------------------
 *  01/27/99      rdh   baseline
 *
 ***************************************************************************/

/* Includes */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> 
#include "typedefs.h"
#include "perftest.h"    

/* Defines  */
#define ARRAYSIZE    256 
#define COMPUTE_TIME 2.0

/* Performs math tests on byte data (integer*1) */
int_4 perftest_math_int_1 (PerfTestInfo *inf)
{
  int_1  sda[ARRAYSIZE];
  int_1  sdb[ARRAYSIZE];
  int_1  sdat[ARRAYSIZE];
  
  real_8 randval;
  int_u4 srandseed;
  int_4  idx[ARRAYSIZE];
  register int_4 i;
  register int_4 ii=0;
  register int_4 iii;
  int_4  iloopcnt;
  int_4  istat;
  real_8 dtimebgnA,dtimebgnB,dtimeendA,dtimeendB;
  real_8 doptjunk,dstop;
  real_8 dopscnt,dopstotal,dtimetotal,dratetotal;

  /* Initialize all arrays */
  for (i=0;i<ARRAYSIZE;i++) {sdat[i] = 0; sda[i] = 0; sdb[i] = 0; idx[i] = 0;}

  /* Create uniform random int_1 data and index vector*/
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  srandseed = 1000000.0 * dtimebgnB;
  srand(srandseed);
  for (i=0;i<ARRAYSIZE;i++){
    randval = ((real_8) rand())/((real_8) RAND_MAX);
    randval = 23.0*(randval - 0.5);
    sdat[i] = (fabs(randval) < 11.0) ? randval : (0.1*randval);
    randval = ((real_8) rand())/((real_8) RAND_MAX);
    randval = ((real_8) (ARRAYSIZE-1)) * randval;
    idx[i]  = (fabs(randval) < ARRAYSIZE) ? fabs(randval) : (ARRAYSIZE-1);
  }

  /* Now, compute master loop count */
  dopscnt  = 4.0*((real_8) ARRAYSIZE)*((real_8) ARRAYSIZE);  
  iloopcnt = (1.0e6 * inf->estmath) / dopscnt;
  iloopcnt = (iloopcnt > 0) ? iloopcnt : 1;

  if (inf->debug > 3) fprintf(stderr,"Math Loop Count: %ld\n",iloopcnt);

  /* Pause and print out banner */
  fprintf(inf->fpout," \n");
  fprintf(inf->fpout,".....................%s......................\n",
          "....Byte Math....");
  fprintf(inf->fpout,"%12s %15s %15s %15s\n",
          "OPERATION","TOTAL OPS","SECONDS","MOPS/sec");
  fprintf(inf->fpout,"%12s %15s %15s %15s\n",
          "---------","---------","-------","--------");
  
  /* Multiplications */
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]*sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]*sdat[ii];
          sdb[idx[iii]] = sdat[iii]*sdat[idx[ii]];
          sdb[iii]      = sdat[iii]*sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %i %i %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Multiply:    %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Additions */       
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]+sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]+sdat[ii];
          sdb[idx[iii]] = sdat[iii]+sdat[idx[ii]];
          sdb[iii]      = sdat[iii]+sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %i %i %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Add:         %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Subtractions */    
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]-sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]-sdat[ii];
          sdb[idx[iii]] = sdat[iii]-sdat[idx[ii]];
          sdb[iii]      = sdat[iii]-sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %i %i %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Subtract:    %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Divisions */   
  for (i=0;i<ARRAYSIZE;i++) sdat[i] = (sdat[i] == 0) ? 3 : sdat[i];
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]/sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]/sdat[ii];
          sdb[idx[iii]] = sdat[iii]/sdat[idx[ii]];
          sdb[iii]      = sdat[iii]/sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %i %i %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Divide:      %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Magnitude */   
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = abs(sdat[iii]);
          sda[iii]      = abs(sdat[idx[iii]]);
          sdb[idx[iii]] = abs(sdat[idx[ii]]);
          sdb[iii]      = abs(sdat[ii]);
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %i %i %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Magnitude:   %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Square Root */ 
  for (i=0;i<ARRAYSIZE;i++) sdat[i] = (sdat[i] < 0) ? abs(sdat[i]) : sdat[i];
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
#ifdef _DECUNIX_
          sda[idx[iii]] = sqrtf(sdat[iii]);
          sda[iii]      = sqrtf(sdat[idx[iii]]);
          sdb[idx[iii]] = sqrtf(sdat[idx[ii]]);
          sdb[iii]      = sqrtf(sdat[ii]);
#else
          sda[idx[iii]] = sqrt(sdat[iii]);
          sda[iii]      = sqrt(sdat[idx[iii]]);
          sdb[idx[iii]] = sqrt(sdat[idx[ii]]);
          sdb[iii]      = sqrt(sdat[ii]);
#endif
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %i %i %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Square Root: %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  return (0);
}


/* Performs math tests on short integer data (integer*2) */
int_4 perftest_math_int_2 (PerfTestInfo *inf)
{
  int_2  sda[ARRAYSIZE];
  int_2  sdb[ARRAYSIZE];
  int_2  sdat[ARRAYSIZE];
  
  real_8 randval;
  int_u4 srandseed;
  int_4  idx[ARRAYSIZE];
  register int_4 i;
  register int_4 ii=0;
  register int_4 iii;
  int_4  iloopcnt;
  int_4  istat;
  real_8 dtimebgnA,dtimebgnB,dtimeendA,dtimeendB;
  real_8 doptjunk,dstop;
  real_8 dopscnt,dopstotal,dtimetotal,dratetotal;

  /* Initialize all arrays */
  for (i=0;i<ARRAYSIZE;i++) {sdat[i] = 0; sda[i] = 0; sdb[i] = 0; idx[i] = 0;}

  /* Create uniform random int_1 data and index vector*/
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  srandseed = 1000000.0 * dtimebgnB;
  srand(srandseed);
  for (i=0;i<ARRAYSIZE;i++){
    randval = ((real_8) rand())/((real_8) RAND_MAX);
    randval = 363.0*(randval - 0.5);
    sdat[i] = (fabs(randval) < 181.0) ? randval : (0.1*randval);
    randval = ((real_8) rand())/((real_8) RAND_MAX);
    randval = ((real_8) (ARRAYSIZE-1)) * randval;
    idx[i]  = (fabs(randval) < ARRAYSIZE) ? fabs(randval) : (ARRAYSIZE-1);
  }

  /* Now, compute master loop count */
  dopscnt  = 4.0*((real_8) ARRAYSIZE)*((real_8) ARRAYSIZE);  
  iloopcnt = (1.0e6 * inf->estmath) / dopscnt;
  iloopcnt = (iloopcnt > 0) ? iloopcnt : 1;

  if (inf->debug > 3) fprintf(stderr,"Math Loop Count: %ld\n",iloopcnt);

  /* Pause and print out banner */
  fprintf(inf->fpout," \n");
  fprintf(inf->fpout,".....................%s.....................\n",
          "Short Integer Math");
  fprintf(inf->fpout,"%12s %15s %15s %15s\n",
          "OPERATION","TOTAL OPS","SECONDS","MOPS/sec");
  fprintf(inf->fpout,"%12s %15s %15s %15s\n",
          "---------","---------","-------","--------");
  
  /* Multiplications */
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]*sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]*sdat[ii];
          sdb[idx[iii]] = sdat[iii]*sdat[idx[ii]];
          sdb[iii]      = sdat[iii]*sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %i %i %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Multiply:    %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Additions */       
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]+sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]+sdat[ii];
          sdb[idx[iii]] = sdat[iii]+sdat[idx[ii]];
          sdb[iii]      = sdat[iii]+sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %i %i %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Add:         %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Subtractions */    
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]-sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]-sdat[ii];
          sdb[idx[iii]] = sdat[iii]-sdat[idx[ii]];
          sdb[iii]      = sdat[iii]-sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %i %i %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Subtract:    %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Divisions */   
  for (i=0;i<ARRAYSIZE;i++) sdat[i] = (sdat[i] == 0) ? 3 : sdat[i];
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]/sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]/sdat[ii];
          sdb[idx[iii]] = sdat[iii]/sdat[idx[ii]];
          sdb[iii]      = sdat[iii]/sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %i %i %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Divide:      %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Magnitude */   
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = abs(sdat[iii]);
          sda[iii]      = abs(sdat[idx[iii]]);
          sdb[idx[iii]] = abs(sdat[idx[ii]]);
          sdb[iii]      = abs(sdat[ii]);
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %i %i %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Magnitude:   %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Square Root */ 
  for (i=0;i<ARRAYSIZE;i++) sdat[i] = (sdat[i] < 0) ? abs(sdat[i]) : sdat[i];
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
#ifdef _DECUNIX_
          sda[idx[iii]] = sqrtf(sdat[iii]);
          sda[iii]      = sqrtf(sdat[idx[iii]]);
          sdb[idx[iii]] = sqrtf(sdat[idx[ii]]);
          sdb[iii]      = sqrtf(sdat[ii]);
#else
          sda[idx[iii]] = sqrt(sdat[iii]);
          sda[iii]      = sqrt(sdat[idx[iii]]);
          sdb[idx[iii]] = sqrt(sdat[idx[ii]]);
          sdb[iii]      = sqrt(sdat[ii]);
#endif
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %i %i %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Square Root: %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  return (0);
}


/* Performs math tests on long integer data (integer*4) */
int_4 perftest_math_int_4 (PerfTestInfo *inf)
{
  int_4  sda[ARRAYSIZE];
  int_4  sdb[ARRAYSIZE];
  int_4  sdat[ARRAYSIZE];
  
  real_8 randval;
  int_u4 srandseed;
  int_4  idx[ARRAYSIZE];
  register int_4 i;
  register int_4 ii=0;
  register int_4 iii;
  int_4  iloopcnt;
  int_4  istat;
  real_8 dtimebgnA,dtimebgnB,dtimeendA,dtimeendB;
  real_8 doptjunk,dstop;
  real_8 dopscnt,dopstotal,dtimetotal,dratetotal;

  /* Initialize all arrays */
  for (i=0;i<ARRAYSIZE;i++) {sdat[i] = 0; sda[i] = 0; sdb[i] = 0; idx[i] = 0;}

  /* Create uniform random int_1 data and index vector*/
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  srandseed = 1000000.0 * dtimebgnB;
  srand(srandseed);
  for (i=0;i<ARRAYSIZE;i++){
    randval = ((real_8) rand())/((real_8) RAND_MAX);
    randval = 92681.0*(randval - 0.5);
    sdat[i] = (fabs(randval) < 46340.0) ? randval : (0.1*randval);
    randval = ((real_8) rand())/((real_8) RAND_MAX);
    randval = ((real_8) (ARRAYSIZE-1)) * randval;
    idx[i]  = (fabs(randval) < ARRAYSIZE) ? fabs(randval) : (ARRAYSIZE-1);
  }

  /* Now, compute master loop count */
  dopscnt  = 4.0*((real_8) ARRAYSIZE)*((real_8) ARRAYSIZE);  
  iloopcnt = (1.0e6 * inf->estmath) / dopscnt;
  iloopcnt = (iloopcnt > 0) ? iloopcnt : 1;

  if (inf->debug > 3) fprintf(stderr,"Math Loop Count: %ld\n",iloopcnt);

  /* Pause and print out banner */
  fprintf(inf->fpout," \n");
  fprintf(inf->fpout,".....................%s......................\n",
          "Long Integer Math");
  fprintf(inf->fpout,"%12s %15s %15s %15s\n",
          "OPERATION","TOTAL OPS","SECONDS","MOPS/sec");
  fprintf(inf->fpout,"%12s %15s %15s %15s\n",
          "---------","---------","-------","--------");
  
  /* Multiplications */
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]*sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]*sdat[ii];
          sdb[idx[iii]] = sdat[iii]*sdat[idx[ii]];
          sdb[iii]      = sdat[iii]*sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %ld %ld %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Multiply:    %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Additions */       
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]+sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]+sdat[ii];
          sdb[idx[iii]] = sdat[iii]+sdat[idx[ii]];
          sdb[iii]      = sdat[iii]+sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %ld %ld %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Add:         %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Subtractions */    
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]-sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]-sdat[ii];
          sdb[idx[iii]] = sdat[iii]-sdat[idx[ii]];
          sdb[iii]      = sdat[iii]-sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %ld %ld %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Subtract:    %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Divisions */   
  for (i=0;i<ARRAYSIZE;i++) sdat[i] = (sdat[i] == 0) ? 3 : sdat[i];
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]/sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]/sdat[ii];
          sdb[idx[iii]] = sdat[iii]/sdat[idx[ii]];
          sdb[iii]      = sdat[iii]/sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %ld %ld %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Divide:      %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Magnitude */   
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = labs(sdat[iii]);
          sda[iii]      = labs(sdat[idx[iii]]);
          sdb[idx[iii]] = labs(sdat[idx[ii]]);
          sdb[iii]      = labs(sdat[ii]);
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %ld %ld %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Magnitude:   %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Square Root */ 
  for (i=0;i<ARRAYSIZE;i++) sdat[i] = (sdat[i] < 0) ? abs(sdat[i]) : sdat[i];
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
#ifdef _DECUNIX_
          sda[idx[iii]] = sqrtf(sdat[iii]);
          sda[iii]      = sqrtf(sdat[idx[iii]]);
          sdb[idx[iii]] = sqrtf(sdat[idx[ii]]);
          sdb[iii]      = sqrtf(sdat[ii]);
#else
          sda[idx[iii]] = sqrt(sdat[iii]);
          sda[iii]      = sqrt(sdat[idx[iii]]);
          sdb[idx[iii]] = sqrt(sdat[idx[ii]]);
          sdb[iii]      = sqrt(sdat[ii]);
#endif
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %ld %ld %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Square Root: %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  return (0);
}


/* Performs math tests on float data (real*4) */           
int_4 perftest_math_real_4 (PerfTestInfo *inf)
{
  real_4  sda[ARRAYSIZE];
  real_4  sdb[ARRAYSIZE];
  real_4  sdat[ARRAYSIZE];
  
  real_8 randval;
  int_u4 srandseed;
  int_4  idx[ARRAYSIZE];
  register int_4 i;
  register int_4 ii=0;
  register int_4 iii;
  int_4  iloopcnt;
  int_4  istat;
  real_8 dtimebgnA,dtimebgnB,dtimeendA,dtimeendB;
  real_8 doptjunk,dstop;
  real_8 dopscnt,dopstotal,dtimetotal,dratetotal;

  /* Initialize all arrays */
  for (i=0;i<ARRAYSIZE;i++) {sdat[i] = 0; sda[i] = 0; sdb[i] = 0; idx[i] = 0;}

  /* Create uniform random int_1 data and index vector*/
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  srandseed = 1000000.0 * dtimebgnB;
  srand(srandseed);
  for (i=0;i<ARRAYSIZE;i++){
    randval = ((real_8) rand())/((real_8) RAND_MAX);
    randval = 1.0e10*(randval - 0.5);
    sdat[i] = (fabs(randval) < 1.0e10) ? randval : (0.1*randval);
    randval = ((real_8) rand())/((real_8) RAND_MAX);
    randval = ((real_8) (ARRAYSIZE-1)) * randval;
    idx[i]  = (fabs(randval) < ARRAYSIZE) ? fabs(randval) : (ARRAYSIZE-1);
  }

  /* Now, compute master loop count */
  dopscnt  = 4.0*((real_8) ARRAYSIZE)*((real_8) ARRAYSIZE);  
  iloopcnt = (1.0e6 * inf->estmath) / dopscnt;
  iloopcnt = (iloopcnt > 0) ? iloopcnt : 1;

  if (inf->debug > 3) fprintf(stderr,"Math Loop Count: %ld\n",iloopcnt);

  /* Pause and print out banner */
  fprintf(inf->fpout," \n");
  fprintf(inf->fpout,".....................%s......................\n",
          "....Float Math...");
  fprintf(inf->fpout,"%12s %15s %15s %15s\n",
          "OPERATION","TOTAL OPS","SECONDS","MOPS/sec");
  fprintf(inf->fpout,"%12s %15s %15s %15s\n",
          "---------","---------","-------","--------");
  
  /* Multiplications */
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]*sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]*sdat[ii];
          sdb[idx[iii]] = sdat[iii]*sdat[idx[ii]];
          sdb[iii]      = sdat[iii]*sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %f %f %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Multiply:    %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Additions */       
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]+sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]+sdat[ii];
          sdb[idx[iii]] = sdat[iii]+sdat[idx[ii]];
          sdb[iii]      = sdat[iii]+sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %f %f %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Add:         %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Subtractions */    
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]-sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]-sdat[ii];
          sdb[idx[iii]] = sdat[iii]-sdat[idx[ii]];
          sdb[iii]      = sdat[iii]-sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %f %f %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Subtract:    %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Divisions */   
  for (i=0;i<ARRAYSIZE;i++) sdat[i] = (sdat[i] == 0) ? 3 : sdat[i];
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]/sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]/sdat[ii];
          sdb[idx[iii]] = sdat[iii]/sdat[idx[ii]];
          sdb[iii]      = sdat[iii]/sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %f %f %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Divide:      %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Magnitude */   
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = fabs(sdat[iii]);
          sda[iii]      = fabs(sdat[idx[iii]]);
          sdb[idx[iii]] = fabs(sdat[idx[ii]]);
          sdb[iii]      = fabs(sdat[ii]);
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %f %f %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Magnitude:   %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Square Root */ 
  for (i=0;i<ARRAYSIZE;i++) sdat[i] = (sdat[i] < 0) ? fabs(sdat[i]) : sdat[i];
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
#ifdef _DECUNIX_
          sda[idx[iii]] = sqrtf(sdat[iii]);
          sda[iii]      = sqrtf(sdat[idx[iii]]);
          sdb[idx[iii]] = sqrtf(sdat[idx[ii]]);
          sdb[iii]      = sqrtf(sdat[ii]);
#else
          sda[idx[iii]] = sqrt(sdat[iii]);
          sda[iii]      = sqrt(sdat[idx[iii]]);
          sdb[idx[iii]] = sqrt(sdat[idx[ii]]);
          sdb[iii]      = sqrt(sdat[ii]);
#endif
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %f %f %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Square Root: %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  return (0);
}


/* Performs math tests on double data (real*8) */           
int_4 perftest_math_real_8 (PerfTestInfo *inf)
{
  real_8  sda[ARRAYSIZE];
  real_8  sdb[ARRAYSIZE];
  real_8  sdat[ARRAYSIZE];
  
  real_8 randval;
  int_u4 srandseed;
  int_4  idx[ARRAYSIZE];
  register int_4 i;
  register int_4 ii=0;
  register int_4 iii;
  int_4  iloopcnt;
  int_4  istat;
  real_8 dtimebgnA,dtimebgnB,dtimeendA,dtimeendB;
  real_8 doptjunk,dstop;
  real_8 dopscnt,dopstotal,dtimetotal,dratetotal;

  /* Initialize all arrays */
  for (i=0;i<ARRAYSIZE;i++) {sdat[i] = 0; sda[i] = 0; sdb[i] = 0; idx[i] = 0;}

  /* Create uniform random int_1 data and index vector*/
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  srandseed = 1000000.0 * dtimebgnB;
  srand(srandseed);
  for (i=0;i<ARRAYSIZE;i++){
    randval = ((real_8) rand())/((real_8) RAND_MAX);
    randval = 1.0e10*(randval - 0.5);
    sdat[i] = (fabs(randval) < 1.0e10) ? randval : (0.1*randval);
    randval = ((real_8) rand())/((real_8) RAND_MAX);
    randval = ((real_8) (ARRAYSIZE-1)) * randval;
    idx[i]  = (fabs(randval) < ARRAYSIZE) ? fabs(randval) : (ARRAYSIZE-1);
  }

  /* Now, compute master loop count */
  dopscnt  = 4.0*((real_8) ARRAYSIZE)*((real_8) ARRAYSIZE);  
  iloopcnt = (1.0e6 * inf->estmath) / dopscnt;
  iloopcnt = (iloopcnt > 0) ? iloopcnt : 1;

  if (inf->debug > 3) fprintf(stderr,"Math Loop Count: %ld\n",iloopcnt);

  /* Pause and print out banner */
  fprintf(inf->fpout," \n");
  fprintf(inf->fpout,".....................%s......................\n",
          "...Double Math...");
  fprintf(inf->fpout,"%12s %15s %15s %15s\n",
          "OPERATION","TOTAL OPS","SECONDS","MOPS/sec");
  fprintf(inf->fpout,"%12s %15s %15s %15s\n",
          "---------","---------","-------","--------");
  
  /* Multiplications */
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]*sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]*sdat[ii];
          sdb[idx[iii]] = sdat[iii]*sdat[idx[ii]];
          sdb[iii]      = sdat[iii]*sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %f %f %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Multiply:    %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Additions */       
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]+sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]+sdat[ii];
          sdb[idx[iii]] = sdat[iii]+sdat[idx[ii]];
          sdb[iii]      = sdat[iii]+sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %f %f %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Add:         %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Subtractions */    
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]-sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]-sdat[ii];
          sdb[idx[iii]] = sdat[iii]-sdat[idx[ii]];
          sdb[iii]      = sdat[iii]-sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %f %f %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Subtract:    %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Divisions */   
  for (i=0;i<ARRAYSIZE;i++) sdat[i] = (sdat[i] == 0) ? 3 : sdat[i];
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sdat[idx[iii]]/sdat[idx[ii]];
          sda[iii]      = sdat[idx[iii]]/sdat[ii];
          sdb[idx[iii]] = sdat[iii]/sdat[idx[ii]];
          sdb[iii]      = sdat[iii]/sdat[ii];
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %f %f %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Divide:      %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Magnitude */   
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = fabs(sdat[iii]);
          sda[iii]      = fabs(sdat[idx[iii]]);
          sdb[idx[iii]] = fabs(sdat[idx[ii]]);
          sdb[iii]      = fabs(sdat[ii]);
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %f %f %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Magnitude:   %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  /* Square Root */ 
  for (i=0;i<ARRAYSIZE;i++) sdat[i] = (sdat[i] < 0) ? fabs(sdat[i]) : sdat[i];
  doptjunk  = 0.0;
  dopstotal = 0.0;
  istat = m_gettimeofday(&dtimebgnA,&dtimebgnB);
  dtimeendA = dtimebgnA;
  dstop = dtimebgnA + COMPUTE_TIME;
  while (dtimeendA < dstop) {
    for (i=0;i<iloopcnt;i++) {
      for (ii=0;ii<ARRAYSIZE;ii++) {
        for (iii=0;iii<ARRAYSIZE;iii++) {
          sda[idx[iii]] = sqrt(sdat[iii]);
          sda[iii]      = sqrt(sdat[idx[iii]]);
          sdb[idx[iii]] = sqrt(sdat[idx[ii]]);
          sdb[iii]      = sqrt(sdat[ii]);
        }
      }
      ii --;
      doptjunk += sda[idx[ii]] + sda[ii] + sdb[idx[ii]] + sdb[ii];
    }
    dopstotal += ((real_8) iloopcnt) * dopscnt;
    istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  }
  istat = m_gettimeofday(&dtimeendA,&dtimeendB);
  if (inf->debug >10) fprintf(stderr," %f %f %f\n",sda[ii],sdb[ii],doptjunk);
  dtimetotal = (dtimeendA-dtimebgnA) + (dtimeendB-dtimebgnB);
  dratetotal = (dtimetotal > 0.0) ? (dopstotal/dtimetotal) : 0.0;
  fprintf(inf->fpout,"Square Root: %15.1f %15.7f %15.2f\n",
                  dopstotal,dtimetotal,(1.0e-6*dratetotal));

  return (0);
}

