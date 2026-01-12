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
LIBRARY    = vector_utils

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
SRCS = iccMatrixComposite.c \
       iccvAdd.c            \
       iccvBarrelShift.c    \
       iccvConj.c           \
       iccvConvert.c        \
       iccvConvertN.c       \
       iccvConvolve.c       \
       iccvCopy.c           \
       iccvCos.c            \
       iccvCrossProduct.c   \
       iccvDiv.c            \
       iccvSwapEndian.c     \
       iccvFill.c           \
       iccvFlip.c           \
       iccvMax.c            \
       iccvMean.c           \
       iccvMin.c            \
       iccvMul.c            \
       iccvMulSum.c         \
       iccvQuickSort.c      \
       iccvRamp.c           \
       iccvRand.c           \
       iccvRandN.c          \
       iccvRead.c           \
       iccvRound.c          \
       iccvSin.c            \
       iccvSinT.c           \
       iccvSub.c            \
       iccvSum.c            \
       iccvZero.c           \
       iccvsAdd.c           \
       iccvsDiv.c           \
       iccvsMul.c           \
       iccvsSub.c           \
       iccvWrite.c

#       iccvRandN64.c        \

#-------------------------------------------------------------------------------'
# Objects requied.
#-------------------------------------------------------------------------------'
OBJS = $(SRCS:.c=.o)

#-------------------------------------------------------------------------------'
# Libraries requied. (Usually left blank for libraries).
#-------------------------------------------------------------------------------'
LIBS =

#-------------------------------------------------------------------------------'
# Flags and such.
#-------------------------------------------------------------------------------'
CCFLAGS    = -Wall -fPIC -g
DEFINES    =
DEPENDFLAG = -M 

#------------------------------------------------------------------------------------------------
# Include the common make file.
#------------------------------------------------------------------------------------------------
THESWD = $(XMOPTS)/ged
-include $(XMOPTS)/xmc/dev/make.rules
