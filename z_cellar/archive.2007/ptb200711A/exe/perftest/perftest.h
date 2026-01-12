/*
 * perftest.h --- includes for perftest main program
 */
#ifndef _PERFTEST_H    
#define _PERFTEST_H

/* Includes */
#include <stdio.h>
#include "typedefs.h"

/* Defininitions */
#ifndef TRUE
#  define TRUE  1
#endif
#ifndef FALSE
#  define FALSE 0
#endif

#define MAX_IOFILESIZE 2147483647           /*Maximum file size in MB */

/*
 * Functions  
 */
extern int_4 get_cmdline();
extern int_4 perftest_memtest();
extern int_4 perftest_iotest(); 
extern int_4 perftest_math_int_1();
extern int_4 perftest_math_int_2();
extern int_4 perftest_math_int_4();
extern int_4 perftest_math_real_4();
extern int_4 perftest_math_real_8();
extern int_4 m_gettimeofday();

/*
 * Structure definition for perftest processing    
 */
typedef struct {
    int_4  debug;
    int_4  state;
    bool_4 domath;
    bool_4 domem;
    bool_4 doio;
    int_4  iofilesize;
    real_8 estmath;
    real_8 estio;
    real_8 estmem;
    FILE   *fpout;
    char   iofile[128];
    char   outfile[128];
} PerfTestInfo;

//static char c_version[5] = "1.00";

#endif /* _PERFTEST_H */     
