#!/usr/bin/make
#------------------------------------------------------------------------------------------------
# File: Makefile                                                                                -
# Desc: C library makefile.                                                                     -
# Hist: When       Who  What                                                                    -
#       07/11/2001 ptb  Initial Code.                                                           -
#       02/07/2006 ptb  Update for option trees.                                                -
#------------------------------------------------------------------------------------------------
SHELL      = /bin/sh
CC         = gcc
LIBRARY    = dsp_utils

#-------------------------------------------------------------------------------'
# Include directories requied.
#-------------------------------------------------------------------------------'
INCDIRS = -I $(XMOPTS)/xmc/inc  \
          -I $(XMOPTS)/ged/inc

#-------------------------------------------------------------------------------'
# Library directories requied.
#-------------------------------------------------------------------------------'
LIBDIRS = -L $(XMOPTS)/ged/lib

#-------------------------------------------------------------------------------'
# Sources requied.
#-------------------------------------------------------------------------------'
SRCS =  iccBitDescision.c           \
	iccChebyshev.c              \
	iccCostasLoop.c             \
	iccDFT.c                    \
	iccFFT1.c                   \
	iccFFT2.c                   \
	iccFFT3.c                   \
	iccFIR.c                    \
        iccHandleHistory.c          \
	iccIIR.c                    \
        iccLinSpace.c               \
        iccLoopFilter.c             \
	iccNewRate.c                \
	iccPLL.c                    \
	iccvRandM.c                 \
	iccResample.c               \
	iccSigGen.c                 \
	iccSigSigGen.c              \
	iccUpSampleBuffer.c         \
	iccUpSampleBufferFlush.c    \
	iccUpSampleCircularBuffer.c \
        iccVCO.c                    \
	iccWindow.c                 \
        iccSinc.c

#-------------------------------------------------------------------------------'
# Objects requied.
#-------------------------------------------------------------------------------'
OBJS = $(SRCS:.c=.o)

#-------------------------------------------------------------------------------'
# Libraries required. (Usually left blank for libraries).
#-------------------------------------------------------------------------------'
LIBS =

#-------------------------------------------------------------------------------'
# Flags and such.
#-------------------------------------------------------------------------------'
CCFLAGS    = -Wall -fPIC -g ##-mmmx -msse -mcpu=i686
DEFINES    =
DEPENDFLAG = -M 

#------------------------------------------------------------------------------------------------
# Include the common make file.
#------------------------------------------------------------------------------------------------
THESWD = $(XMOPTS)/ged
-include $(XMOPTS)/xmc/dev/make.rules
