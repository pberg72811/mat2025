/****************************************************************************
 *  perftest.c
 *
 *  Description:  Math, I/O, and memory performance tests 
 *                It's not clean and doesn't handle errors, but is accurate.
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
#include "perftest.h" 
    
static char c_version[5] = "1.00";

int main(int  argc, char *argv[])
{
  /* Global Variables */
  int_4 istat;
  PerfTestInfo info;

  /* Get command line parameters into global structure*/
  istat = get_cmdline(argc,argv,&info);

  /* Create output file or define stream */
  if (strstr(info.outfile,"stdout") == NULL) {
    info.fpout = fopen(info.outfile,"w");
    if (info.fpout == NULL) {
      fprintf(stderr,"Unable to open output: %s\n",info.outfile);
      exit(-1);

    }
  }
  else {
    info.fpout = stdout;
  }
  fprintf(info.fpout,"\n             *** PERFTEST Version: %s ***\n",c_version);

  /* Do math tests */
  if (info.domath == TRUE) {
    istat = perftest_math_int_1(&info);
    istat = perftest_math_int_2(&info);
    istat = perftest_math_int_4(&info);
    istat = perftest_math_real_4(&info);
    istat = perftest_math_real_8(&info);
  }

  /* Do memory move tests */
  if (info.domem == TRUE) {
    istat = perftest_memtest(&info);
  }

  /* Do I/O tests */
  if (info.doio == TRUE) {
    istat = perftest_iotest(&info);
  }

  /* Close up shop */
  fclose(info.fpout);

  return (0);
}
