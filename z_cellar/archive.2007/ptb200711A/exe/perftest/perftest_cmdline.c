/****************************************************************************
 *  perftest_cmdline.c
 *
 *  Description:  Libraries for performing command line parsing and 
 *                  information extraction.
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

/* Defines */

/****************************************************************************
 *  get_cmdline () 
 *
 *  Description:  Extracts and reformats command line information into 
 *                  structure elements of PerfTestInfo struct.
 *
 *  Author:       rdh
 *  Revisions:
 *  --------      ---   -----------------------------------------------------
 *  01/27/00      rdh   baseline
 *
 ***************************************************************************/
int_4 get_cmdline (int inargc, char *inargv[], PerfTestInfo *inf)
{
  //char *scmpa; 
int_4  m,mo;
int_4  ilen;
bool_4 dbgout, usage; 

  /* First scan for debug and usage flags */
  for (m=0; m<inargc; ++m) {
    dbgout = (strstr(inargv[m],"debug=3") == NULL) ? FALSE : TRUE;
    usage  = (strstr(inargv[m],"usage")   == NULL) ? FALSE : TRUE;
  }
  if (dbgout) {
     fprintf(stderr, "Command Line Parameters: %i\n",inargc);
     for (m=0; m<inargc; ++m) {
        ilen = strlen(inargv[m]);
	fprintf(stderr, "%ld %5ld %s\n",m,ilen,inargv[m]);
     }
  }
  if (inargc == 1) usage = TRUE;

  /* Assign the defaults */
  inf->debug      = -1; 
  inf->state      = 0;
  inf->domath     = TRUE; 
  inf->domem      = TRUE; 
  inf->doio       = TRUE; 
  inf->iofilesize = 512;                  /* Default is 512MB */
  inf->estmath    = 100;                  /* Assume 100MFlops */
  inf->estio      = 10;                   /* Assume 10MB/sec  */
  inf->estmem     = 128;                  /* Assume 128MB/sec */
  inf->fpout      = NULL;
  strncpy(inf->iofile,  "perftest_file.tmp\0",sizeof(inf->iofile));
  strncpy(inf->outfile, "stdout\0",sizeof(inf->outfile));
  
  /* Get the options values */
  for (m=0; m<inargc; ++m) {
    if (strstr(inargv[m],"-debug")) {   
      inf->debug = 0;
      if (strstr(inargv[m],"-debug=1")) inf->debug = 1;
      if (strstr(inargv[m],"-debug=2")) inf->debug = 2;
      if (strstr(inargv[m],"-debug=3")) inf->debug = 3;
      if (strstr(inargv[m],"-debug=4")) inf->debug = 4;
    }
    if (strstr(inargv[m],"-out")) {   
      mo = ((m+1) < inargc) ? (m+1) : (inargc-1);
      strncpy(inf->outfile,"\0",sizeof(inf->outfile));
      strncpy(inf->outfile,inargv[mo],sizeof(inf->outfile));
    }
    if (strstr(inargv[m],"-test")) {  
      mo = ((m+1) < inargc) ? (m+1) : (inargc-1);
      inf->domath = FALSE;
      inf->domem  = FALSE;
      inf->doio   = FALSE;
      if (strstr(inargv[mo],"math")) inf->domath = TRUE;
      if (strstr(inargv[mo],"io"))   inf->doio   = TRUE;
      if (strstr(inargv[mo],"mem"))  inf->domem  = TRUE;
      if (strstr(inargv[mo],"all")) {
        inf->domath     = TRUE; 
        inf->domem      = TRUE; 
        inf->doio       = TRUE; 
      }
    }
    if (strstr(inargv[m],"-iofile")) {   
      mo = ((m+1) < inargc) ? (m+1) : (inargc-1);
      strncpy(inf->iofile,"\0",sizeof(inf->iofile));
      strncpy(inf->iofile,inargv[mo],sizeof(inf->iofile));
    }
    if (strstr(inargv[m],"-iosize")) {
      mo = ((m+1) < inargc) ? (m+1) : (inargc-1);
      inf->iofilesize = (atof(inargv[mo]) < (double) MAX_IOFILESIZE) ?
                         (int_4) atof(inargv[mo]) : (MAX_IOFILESIZE);
      inf->iofilesize = (inf->iofilesize > 0) ? (inf->iofilesize) : (1);
    }
    if (strstr(inargv[m],"-estmath")) {
      mo = ((m+1) < inargc) ? (m+1) : (inargc-1);
      inf->estmath = (atof(inargv[mo]) > 0.0) ? atof(inargv[mo]) : 1.0;
    }
    if (strstr(inargv[m],"-estio")) {
      mo = ((m+1) < inargc) ? (m+1) : (inargc-1);
      inf->estio = (atof(inargv[mo]) > 0.0) ? atof(inargv[mo]) : 1.0;
    }
    if (strstr(inargv[m],"-estmem")) {
      mo = ((m+1) < inargc) ? (m+1) : (inargc-1);
      inf->estmem = (atof(inargv[mo]) > 0.0) ? atof(inargv[mo]) : 1.0;
    }
  }

  if (inf->debug > 1) {
    fprintf(stderr, " \n");
    fprintf(stderr, "Command line selections: \n");
    fprintf(stderr, "debug       = %ld\n", inf->debug);
    fprintf(stderr, "Math Test   = %ld\n", inf->domath);   
    fprintf(stderr, "I/O  Test   = %ld\n", inf->doio);     
    fprintf(stderr, "MEM  Test   = %ld\n", inf->domem);  
    fprintf(stderr, "I/O FileSZ  = %ld\n", inf->iofilesize);
    fprintf(stderr, "Math Est    = %f\n", inf->estmath);
    fprintf(stderr, "I/O  Est    = %f\n", inf->estio);  
    fprintf(stderr, "MEM  Est    = %f\n", inf->estmem);  
    fprintf(stderr, "I/O File    = %s\n", inf->iofile);
    fprintf(stderr, "Output File = %s\n", inf->outfile);
    fprintf(stderr, " \n");
  }

  if (usage) {
    fprintf(stderr, " \n");
    fprintf(stderr, "Usage: \n");
    fprintf(stderr, "perftest -out <file> -test <options> -iofile <file> ");
    fprintf(stderr, "-iosize <n>\n");
    fprintf(stderr, "           -estmath <n> -estio <n> -estmem <n>\n");
    fprintf(stderr, "where: \n");
    fprintf(stderr, "\t-out     Output file (-out stdout for standard out)\n");
    fprintf(stderr, "\t-test    Test category list (math,memory,io,all)\n");
    fprintf(stderr, "\t-iofile  Name of I/O test file to create\n");
    fprintf(stderr, "\t-iosize  Size of I/O test file in MB\n");
    fprintf(stderr, "\t-estmath Best estimate of math rate (MFLOP/sec)\n");
    fprintf(stderr, "\t-estio   Best estimate of I/O rate (MB/sec)\n");
    fprintf(stderr, "\t-estmem  Best estimate of Memory transfer rate (MB/sec)\n");
    fprintf(stderr, "\t-debug=n Debug output level (results will be inaccurate)\n");
    fprintf(stderr, " \n");
    exit(0);
  }
  return (inargc);              
}
