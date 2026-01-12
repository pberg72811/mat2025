/*
 * m_gettimeofday --- wrapper for gettimeofday function
 */

/* Includes */
#include <sys/time.h>  
#include "typedefs.h"

int_4 m_gettimeofday(real_8 *timesec, real_8 *timeusec)
{
    struct voidtimezone { unsigned long dumm[4]; } timezne;
    struct timeval  timenow;
    int    istat;
    double dbltmp;
    void   *ptr_timezne;

    ptr_timezne = &timezne;
    istat  = gettimeofday(&timenow,ptr_timezne);          
    dbltmp = (double) timenow.tv_sec;  *timesec  = dbltmp;
    dbltmp = (double) timenow.tv_usec; *timeusec = 1.0e-6*dbltmp;

    return(istat);
}
