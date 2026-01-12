#include "xmc.h"
#include "malloc_utils.h"
#include "vector_utils.h"
#include "orbit_utils.h"

extern VOID  _xccAddINT32_i686(INT32 *a, INT32 *b, INT32 *c, UNT32 n, FLT64 test);
extern VOID  _xccvAddINT08_i686(INT08 *a, INT08 *b, INT08 *c, UNT32 n);
extern VOID  _xccvAddINT16_i686(INT16 *a, INT16 *b, INT16 *c, UNT32 n);

int main(void)
{
  //INT32 testA[4]={1,2,3,4};
  //INT32 testB[4]={5,6,7,8};
  //INT32 testC[4]={0,0,0,0};
  //INT08 ii=45;
  //FLT64 x1 =   19.00;
  //INT32 x =  9;
  //INT32 y = 10;
  //INT32 z = 0;
  INT16 *p2A;
  INT16 *p2B;
  INT16 *p2C;
  INT32 ii;
  INT64 tStart;
  INT64 tStop;
  INT32 diff1;
  INT32 diff2;

  p2A = xccMallocINT16_Align128(25600000);
  p2B = xccMallocINT16_Align128(25600000);
  p2C = xccMallocINT16_Align128(25600000);

  xccvFillINT16( p2A, 1, 3, 25600000);
  xccvFillINT16( p2B, 1, 4, 25600000);
  xccvFillINT16( p2C, 1, 0, 25600000);


  printf("START!\n");
  tStart = xccCurrentUNIXMicroSeconds();
  _xccvAddINT16_i686(p2A, p2B, p2C, 25600000);
  tStop = xccCurrentUNIXMicroSeconds();
  diff1 = tStop-tStart;
  printf("STOP! in %ld \n", diff1);

  xccvFillINT16( p2C, 1, 0, 25600000);

  printf("START!\n");
  tStart = xccCurrentUNIXMicroSeconds();
  for(ii = 0; ii < 25600000; ii++)
  {
    p2C[ii] = p2A[ii]+p2B[ii];
  }
  tStop = xccCurrentUNIXMicroSeconds();
  diff2 = tStop-tStart;
  printf("STOP! in %ld \n", diff2);

  printf("\n");
  printf("Times faster is %f\n", ((FLT32)diff2)/((FLT32)diff1));



  free(p2A);
  free(p2B);
  free(p2C);
 
  return(0);
}
