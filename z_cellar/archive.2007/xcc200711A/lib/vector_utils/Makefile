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
          -I $(XMOPTS)/xcc/inc

#-------------------------------------------------------------------------------'
# Library directories requied.
#-------------------------------------------------------------------------------'
LIBDIRS = -L $(XMOPTS)/xcc/lib

#-------------------------------------------------------------------------------'
# Sources requied.
#-------------------------------------------------------------------------------'
SRCS = xccMatrixComposite.c \
       xccvAdd.c            \
       xccvBarrelShift.c    \
       xccvConj.c           \
       xccvConvert.c        \
       xccvConvertN.c       \
       xccvConvolve.c       \
       xccvCopy.c           \
       xccvCos.c            \
       xccvCrossProduct.c   \
       xccvDiv.c            \
       xccvSwapEndian.c     \
       xccvFill.c           \
       xccvFlip.c           \
       xccvMax.c            \
       xccvMean.c           \
       xccvMin.c            \
       xccvMul.c            \
       xccvMulSum.c         \
       xccvQuickSort.c      \
       xccvRamp.c           \
       xccvRand.c           \
       xccvRandN.c          \
       xccvRead.c           \
       xccvRound.c          \
       xccvSin.c            \
       xccvSinT.c           \
       xccvSub.c            \
       xccvSum.c            \
       xccvZero.c           \
       xccvsAdd.c           \
       xccvsDiv.c           \
       xccvsMul.c           \
       xccvsSub.c           \
       xccvWrite.c

#       xccvRandN64.c        \

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
THESWD = $(XMOPTS)/xcc
-include $(XMOPTS)/xmc/dev/make.rules
