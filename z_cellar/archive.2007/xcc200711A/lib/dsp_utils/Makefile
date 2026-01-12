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
          -I $(XMOPTS)/xcc/inc

#-------------------------------------------------------------------------------'
# Library directories requied.
#-------------------------------------------------------------------------------'
LIBDIRS = -L $(XMOPTS)/xcc/lib

#-------------------------------------------------------------------------------'
# Sources requied.
#-------------------------------------------------------------------------------'
SRCS =  xccBitDescision.c           \
	xccChebyshev.c              \
	xccCostasLoop.c             \
	xccDFT.c                    \
	xccFFT1.c                   \
	xccFFT2.c                   \
	xccFFT3.c                   \
	xccFIR.c                    \
        xccHandleHistory.c          \
	xccIIR.c                    \
        xccLinSpace.c               \
        xccLoopFilter.c             \
	xccNewRate.c                \
	xccPLL.c                    \
	xccvRandM.c                 \
	xccResample.c               \
	xccSigGen.c                 \
	xccSigSigGen.c              \
	xccUpSampleBuffer.c         \
	xccUpSampleBufferFlush.c    \
	xccUpSampleCircularBuffer.c \
        xccVCO.c                    \
	xccWindow.c                 \
        xccSinc.c

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
THESWD = $(XMOPTS)/xcc
-include $(XMOPTS)/xmc/dev/make.rules
