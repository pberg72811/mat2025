//-----------------------------------------UNCLASSIFIED-------------------------------------------
// File: blueWave.c
//
// Desc: Mex function to ...
//
// Hist: When       Who  What
//       05/22/2025 ptb  Initial version.
//------------------------------------------------------------------------------------------------
#include "mex.h"
#include "xcc.h"
#include <string.h>

/** Type 1000 adjunct header */
typedef struct {
  double xstart;  /**< abscissa start */
  double xdelta;  /**< abscissa delta */
  int xunits;     /**< abscissa units code */
  int fill1;      /**< fill */
  double fill2;   /**< fill */
  double fill3;   /**< fill */
  int fill4;      /**< fill */
  int bid;        /**< buffer id */
} BLUET1ADJ;

/** Type 2000 adjunct header */
typedef struct {
  double xstart;  /**< abscissa start */
  double xdelta;  /**< abscissa delta */
  int xunits;     /**< abscissa units code */
  int subsize;    /**< frame size */
  double ystart;  /**< secondary abscissa start */
  double ydelta;  /**< secondary abscissa delta */
  int yunits;     /**< secondary abscissa units code */
  int bid;        /**< buffer id */
} BLUET2ADJ;

typedef struct {
  char version[4];      /**< Header version */
  char head_rep[4];     /**< Header representation */
  char data_rep[4];     /**< Data representation */
  int detached;         /**< detached header */
  int protected_;       /**< "protected" reserved to C++ */
  int pipe;             /**< pipe mode */

  int ext_start;        /**< extended header start block */
  int ext_size;         /**< extended header size bytes */
  double data_start;    /**< data start in bytes */
  double data_size;     /**< data size in bytes */

  int type;             /**< file type code */
  char format[2];       /**< data format code */
  short flagmask;       /**< 16 bit flag mask (1=flagbit) */
  double timecode;      /**< time code field */
  short inlet;          /**< inlet owner */
  short outlets;        /**< number outlets */
  int outmask;          /**< outlet async mask */
  int pipeloc;          /**< pipe location */
  int pipesize;         /**< pipe size in bytes */
  double in_byte;       /**< next input byte */
  double out_byte;      /**< next out byte (cumulative) */
  double outbytes[8];   /**< next out byte (each outlet) */

  int keylength;        /**< length of keyword string */
  char keywords[92];    /**< user defined keyword string */
}BLUEHDRSTRUCT;

typedef struct{
    BLUEHDRSTRUCT hdr;
    BLUET1ADJ     adj;
} TYPE1000;

typedef struct{
    BLUEHDRSTRUCT hdr;
    BLUET1ADJ     adj;
} BLUET2ADJ;


void mexFunction (int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    TYPE1000 type1000;
    
    RFLT64 x;
    mwSize rows = mxGetM(prhs[0]);
    mwSize cols = mxGetN(prhs[0]);
    const char    *className;
    className = mxGetClassName(prhs[0]);
    printf("%s\n",className);
    printf("%d\n", rows);
    printf("%d\n", cols);
    printf("Number of right hand statements is: %d\n", nrhs);
    printf("Number of left  hand statements is: %d\n", nlhs);
}