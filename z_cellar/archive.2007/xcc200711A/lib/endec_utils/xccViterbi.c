/*-------------------------------UNCLASSIFIED---------------------------------*/
// File: xccViterbi.c
// Desc: This file contains the code for the xccViterbi routine.
// Hist: When       Who  What
//       09/24/2001 ptb  Initial Code.
/*----------------------------------------------------------------------------*/
/* Preprocessor directives ---------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Include files -------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
#include "endec_utils.h"

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

// xccVerterbiInit
//------------------------------------------------------------------------------
xccViterbiSpec *xccViterbiInit(INT32 nStates)
{
  INT32 ii;
  INT32 jj;
  xccViterbiSpec *spec;

  // Malloc the memory for the spec.
  //----------------------------------------------------------------------------
  spec = (xccViterbiSpec *) malloc(sizeof(xccViterbiSpec));

  // Initialize the temporary metrics for each state.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < nStates; ii++)
    for(jj = 0; jj <2; jj++)
      spec->state[ii].tMetric[jj] = 999;

  // Initialize the metric, value, and bit stacks for each state.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < nStates; ii++)
  {
    spec->state[ii].metricStack = xccStackInitUNT32(128,"metricStack");
    xccStackPushUNT32(spec->state[ii].metricStack,0);
    spec->state[ii].valueStack = xccStackInitUNT32(128,"valueStack");
    spec->state[ii].bitStack = xccStackInitINT08(128,"bitStack");
  }

  // Initialize the bit and active stacks.
  //----------------------------------------------------------------------------
  spec->bitStack = xccStackInitINT08(1024*1024,"bitStack");
  spec->activeStack = xccStackInitINT08(64,"activeStack");

  // Set nStates.
  //----------------------------------------------------------------------------
  spec->nStates = nStates;

  // Assign numbers for each state.
  //----------------------------------------------------------------------------
  for(ii = 0; ii < nStates; ii++) spec->state[ii].number = ii;

  // Set state[0] to active and all other states to inactive.
  //----------------------------------------------------------------------------
  spec->state[0].active = TRUE;
  for(ii = 1; ii < nStates; ii++) spec->state[ii].active = FALSE;

  // Initialize next state pointers.  Values based on table. Specific during prototype.
  //----------------------------------------------------------------------------
  spec->state[0].p2ns[0] = &spec->state[0];
  spec->state[0].p2ns[1] = &spec->state[4];
  spec->state[1].p2ns[0] = &spec->state[0];
  spec->state[1].p2ns[1] = &spec->state[4];

  spec->state[2].p2ns[0] = &spec->state[1];
  spec->state[2].p2ns[1] = &spec->state[5];
  spec->state[3].p2ns[0] = &spec->state[1];
  spec->state[3].p2ns[1] = &spec->state[5];

  spec->state[4].p2ns[0] = &spec->state[2];
  spec->state[4].p2ns[1] = &spec->state[6];
  spec->state[5].p2ns[0] = &spec->state[2];
  spec->state[5].p2ns[1] = &spec->state[6];

  spec->state[6].p2ns[0] = &spec->state[3];
  spec->state[6].p2ns[1] = &spec->state[7];
  spec->state[7].p2ns[0] = &spec->state[3];
  spec->state[7].p2ns[1] = &spec->state[7];

  return(spec);
}

VOID xccViterbi(INT08 inValue, xccViterbiSpec *spec)
{
  INT32 ii;
  INT08 tempINT08;

  // Calculate metrics for next state.  Need "FOR LOOP".
  //----------------------------------------------------------------------------
  if (spec->state[0].active)
  {
    spec->state[0].p2ns[0]->tMetric[0] = xccStackTopUNT32(spec->state[0].metricStack) +
                                         xccHammingWeightINT08(0,inValue);//00
    spec->state[0].p2ns[1]->tMetric[0] = xccStackTopUNT32(spec->state[0].metricStack) + 
                                         xccHammingWeightINT08(3,inValue);//11
    spec->state[0].p2ns[0]->tBit[0] = 0;
    spec->state[0].p2ns[1]->tBit[0] = 1;
    xccStackPushINT08(spec->activeStack,spec->state[0].p2ns[0]->number);
    xccStackPushINT08(spec->activeStack,spec->state[0].p2ns[1]->number);
  }
  if (spec->state[1].active)
  {
    spec->state[1].p2ns[0]->tMetric[1] = xccStackTopUNT32(spec->state[1].metricStack) +
                                         xccHammingWeightINT08(3,inValue);//11
    spec->state[1].p2ns[1]->tMetric[1] = xccStackTopUNT32(spec->state[1].metricStack) +
                                         xccHammingWeightINT08(0,inValue);//00
    spec->state[1].p2ns[0]->tBit[1] = 0;
    spec->state[1].p2ns[1]->tBit[1] = 1;
    xccStackPushINT08(spec->activeStack,spec->state[1].p2ns[0]->number);
    xccStackPushINT08(spec->activeStack,spec->state[1].p2ns[1]->number);
  }

  //----------------------------------------------------------------------------
  if (spec->state[2].active)
  {
    spec->state[2].p2ns[0]->tMetric[0] = xccStackTopUNT32(spec->state[2].metricStack) +
                                         xccHammingWeightINT08(3,inValue);//11
    spec->state[2].p2ns[1]->tMetric[0] = xccStackTopUNT32(spec->state[2].metricStack) +
                                         xccHammingWeightINT08(0,inValue);//00
    spec->state[2].p2ns[0]->tBit[0] = 0;
    spec->state[2].p2ns[1]->tBit[0] = 1;
    xccStackPushINT08(spec->activeStack,spec->state[2].p2ns[0]->number);
    xccStackPushINT08(spec->activeStack,spec->state[2].p2ns[1]->number);
  }
  if (spec->state[3].active)
  {
    spec->state[3].p2ns[0]->tMetric[1] = xccStackTopUNT32(spec->state[3].metricStack) +
                                         xccHammingWeightINT08(0,inValue);//00
    spec->state[3].p2ns[1]->tMetric[1] = xccStackTopUNT32(spec->state[3].metricStack) +
                                         xccHammingWeightINT08(3,inValue);//11
    spec->state[3].p2ns[0]->tBit[1] = 0;
    spec->state[3].p2ns[1]->tBit[1] = 1;
    xccStackPushINT08(spec->activeStack,spec->state[3].p2ns[0]->number);
    xccStackPushINT08(spec->activeStack,spec->state[3].p2ns[1]->number);
  }

  //----------------------------------------------------------------------------
  if (spec->state[4].active)
  {
    spec->state[4].p2ns[0]->tMetric[0] = xccStackTopUNT32(spec->state[4].metricStack) +
                                         xccHammingWeightINT08(1,inValue);//01
    spec->state[4].p2ns[1]->tMetric[0] = xccStackTopUNT32(spec->state[4].metricStack) +
                                         xccHammingWeightINT08(2,inValue);//10
    spec->state[4].p2ns[0]->tBit[0] = 0;
    spec->state[4].p2ns[1]->tBit[0] = 1;
    xccStackPushINT08(spec->activeStack,spec->state[4].p2ns[0]->number);
    xccStackPushINT08(spec->activeStack,spec->state[4].p2ns[1]->number);
  }
  if (spec->state[5].active)
  {
    spec->state[5].p2ns[0]->tMetric[1] = xccStackTopUNT32(spec->state[5].metricStack) +
                                         xccHammingWeightINT08(2,inValue);//10
    spec->state[5].p2ns[1]->tMetric[1] = xccStackTopUNT32(spec->state[5].metricStack) +
                                         xccHammingWeightINT08(1,inValue);//01
    spec->state[5].p2ns[0]->tBit[1] = 0;
    spec->state[5].p2ns[1]->tBit[1] = 1;
    xccStackPushINT08(spec->activeStack,spec->state[5].p2ns[0]->number);
    xccStackPushINT08(spec->activeStack,spec->state[5].p2ns[1]->number);
  }

  //----------------------------------------------------------------------------
  if (spec->state[6].active)
  {
    spec->state[6].p2ns[0]->tMetric[0] = xccStackTopUNT32(spec->state[6].metricStack) +
                                         xccHammingWeightINT08(2,inValue);//10
    spec->state[6].p2ns[1]->tMetric[0] = xccStackTopUNT32(spec->state[6].metricStack) +
                                         xccHammingWeightINT08(1,inValue);//01
    spec->state[6].p2ns[0]->tBit[0] = 0;
    spec->state[6].p2ns[1]->tBit[0] = 1;
    xccStackPushINT08(spec->activeStack,spec->state[6].p2ns[0]->number);
    xccStackPushINT08(spec->activeStack,spec->state[6].p2ns[1]->number);
  }
  if (spec->state[7].active)
  {
    spec->state[7].p2ns[0]->tMetric[1] = xccStackTopUNT32(spec->state[7].metricStack) +
                                         xccHammingWeightINT08(1,inValue);//01
    spec->state[7].p2ns[1]->tMetric[1] = xccStackTopUNT32(spec->state[7].metricStack) +
                                         xccHammingWeightINT08(2,inValue);//10
    spec->state[7].p2ns[0]->tBit[1] = 0;
    spec->state[7].p2ns[1]->tBit[1] = 1;
    xccStackPushINT08(spec->activeStack,spec->state[7].p2ns[0]->number);
    xccStackPushINT08(spec->activeStack,spec->state[7].p2ns[1]->number);
  }

  // Activate states.
  //----------------------------------------------------------------------------
  while( xccStackPopINT08( spec->activeStack, &tempINT08 ) != -1 )
  {
    spec->state[(INT16)tempINT08].active=TRUE;
  }

  // Push the new metric, value, and bit.
  //----------------------------------------------------------------------------
  for( ii = 0; ii < spec->nStates; ii++)
  {
    if     ( spec->state[ii].tMetric[0] < spec->state[ii].tMetric[1] )
    {
      xccStackPushUNT32(spec->state[ii].metricStack, spec->state[ii].tMetric[0]);
      xccStackPushUNT32(spec->state[ii].valueStack,  spec->state[ii].tValue[0]);
      xccStackPushINT08(spec->state[ii].bitStack,    spec->state[ii].tBit[0]);
    }
    else if( spec->state[ii].tMetric[0] > spec->state[ii].tMetric[1] )
    {
      xccStackPushUNT32(spec->state[ii].metricStack, spec->state[ii].tMetric[1]);
      xccStackPushUNT32(spec->state[ii].valueStack,  spec->state[ii].tValue[1]);
      xccStackPushINT08(spec->state[ii].bitStack,    spec->state[ii].tBit[1]);
    }
    else
    {
      xccStackPushUNT32(spec->state[ii].metricStack, spec->state[ii].tMetric[0]);
      xccStackPushUNT32(spec->state[ii].valueStack,  spec->state[ii].tValue[0]);
      xccStackPushINT08(spec->state[ii].bitStack,    spec->state[ii].tBit[0]);
    }
  }


  // When metric stack gets big enough, dump some bits.
  //----------------------------------------------------------------------------
}

// Generate a Metric Report.
//------------------------------------------------------------------------------
VOID xccViterbiMetricReport(xccViterbiSpec *spec)
{
  INT32 ii;
  INT32 jj;
  CHR08 c[7] = {'M','E','T','R','I','C','='};

  for(ii = 0; ii < 1; ii++) //for(ii = 0; ii < sizeof(c); ii++)
  {
    for(jj = 0; jj <spec->nStates; jj++) printf("%5c",c[ii]);
    printf("\n");
  }
  
  for(ii = 0; ii < (spec->state[0].metricStack->index+1); ii++)
  {
    for(jj = 0; jj < spec->nStates; jj++)
    {
      printf("% 5ld", spec->state[jj].metricStack->theStack[ii]);
    }
    printf("\n");
  }
  printf("\n");
}

// Generate an Active Report.
//------------------------------------------------------------------------------
VOID xccViterbiActiveReport(xccViterbiSpec *spec)
{
  INT32 ii;
  INT32 jj;
  CHR08 c[7] = {'A','C','T','I','V','E','='};

  for(ii = 0; ii < 1; ii++) //for(ii = 0; ii < sizeof(c); ii++)
  {
    for(jj = 0; jj < spec->nStates; jj++) printf("%5c",c[ii]);
    printf("\n");
  }
  
  for(jj = 0; jj < spec->nStates; jj++)
  {
    printf("% 5d", spec->state[jj].active);
  }
  printf("\n");
  printf("\n");

}
    
// Generate a Bit Report.
//------------------------------------------------------------------------------
VOID xccViterbiBitReport(xccViterbiSpec *spec)
{
  INT32 ii;
  INT32 jj;
  CHR08 c[4] = {'B','I','T','='};

  for(ii = 0; ii < sizeof(c); ii++)
  {
    for(jj = 0; jj <spec->nStates; jj++) printf("%5c",c[ii]);
    printf("\n");
  }
  
  for(ii = 0; ii < (spec->state[0].bitStack->index+1); ii++)
  {
    for(jj = 0; jj < spec->nStates; jj++)
    {
      printf("% 5d", spec->state[jj].bitStack->theStack[ii]);
    }
    printf("\n");
  }
  printf("\n");
}

// Generate a Next State Report.
//------------------------------------------------------------------------------
VOID xccViterbiNextStateReport(xccViterbiSpec *spec)
{
  INT32 ii;

  printf("NEXT STATE REPORT\n");
  printf("=================\n");
  
  for(ii = 0; ii < spec->nStates; ii++)
  {
    printf("Current State %ld    Next State %d\n", ii, spec->state[ii].p2ns[0]->number);
    printf("Current State %ld    Next State %d\n", ii, spec->state[ii].p2ns[1]->number);
  }
  printf("\n");
}

/* End preprocessor directives -----------------------------------------------*/
/*----------------------------------------------------------------------------*/

/*-------------------------------UNCLASSIFIED---------------------------------*/
