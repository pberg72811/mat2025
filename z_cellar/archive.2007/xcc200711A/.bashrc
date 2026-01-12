# !/bin/bash
#------------------------------------------------------------------------------------------------

#------------------------------------------------------------------------------------------------
# Source globals.
#------------------------------------------------------------------------------------------------
if [ -f /etc/bashrc ]; then . /etc/bashrc; fi

#------------------------------------------------------------------------------------------------
# User specific aliases and functions
#------------------------------------------------------------------------------------------------
#echo "C---------------------- Welcome to Bash-Shell at $HOSTNAME."
#if [ $(alias ls | grep -vq not) ]; then unalias ls; fi
#if [ $(alias ll | grep -vq not) ]; then unalias ll; fi
#if [ $(alias vi | grep -vq not) ]; then unalias vi; fi

if alias ls > /dev/null 2>&1
then
  unalias ls
fi

if alias ll > /dev/null 2>&1
then
  unalias ll
fi

if alias vi > /dev/null 2>&1
then
  unalias vi
fi


alias ll='ls -l --color=tty'
alias llh='ls -lh --color=tty'
alias lla='ls -al --color=tty'
alias llha='ls -alh --color=tty'
alias rm='rm -i'
#echo C---------------------- Enjoy your stay.

#------------------------------------------------------------------------------------------------
# Define the Prompt. 
#------------------------------------------------------------------------------------------------
PS1="\u:\w>"

#------------------------------------------------------------------------------------------------
# Define the PATH
#------------------------------------------------------------------------------------------------
PATH=.
PATH=$PATH:..
PATH=$PATH:/bin
PATH=$PATH:/sbin
PATH=$PATH:/usr/bin
PATH=$PATH:/usr/sbin
PATH=$PATH:/usr/exec
PATH=$PATH:/usr/local/bin
PATH=$PATH:/usr/X11R6/bin

export PATH

#------------------------------------------------------------------------------------------------
# Define the LOAD LIBRARY PATH.
#------------------------------------------------------------------------------------------------
LD_LIBRARY_PATH=.
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib

export LD_LIBRARY_PATH

#------------------------------------------------------------------------------------------------
# Define the MAN PATH.
#------------------------------------------------------------------------------------------------
MANPATH=

export MANPATH

#------------------------------------------------------------------------------------------------
# Set up for Special Test Equipment Software Development (STESWD).
#------------------------------------------------------------------------------------------------
#if [ $USER = steswd ]; then
#  STESWD=$HOME/steswd
#else
#  STESWD=/opt/xmidas/localopts/ste
#fi
#
#PATH=$PATH:$STESWD/bin
#PATH=$PATH:$STESWD/dev
#LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$STESWD/lib
#
#export STESWD
#
#------------------------------------------------------------------------------------------------
# Define CVS root directory.
#------------------------------------------------------------------------------------------------
export CVSROOT=/opt/cvs
export CVS_RSH=ssh

#------------------------------------------------------------------------------------------------
# Define Java CLASSPATH environment variable.  Will require a link to specific jdk.
#------------------------------------------------------------------------------------------------
PATH=$PATH:/usr/java/jdk/bin
CLASSPATH=.
CLASSPATH=$CLASSPATH:/usr/java/jdk/jre/lib/rt.jar
CLASSPATH=$CLASSPATH:$STESWD/jev/jniOrbitUtilsJava

export CLASSPATH

#------------------------------------------------------------------------------------------------
# Define PYTHON PATH environment variable.
#------------------------------------------------------------------------------------------------
PYTHONPATH=.
PYTHONPATH=$PYTHONPATH:/usr/local/lib/lib-tk
PYTHONPATH=$PYTHONPATH:/usr/lib/python
PYTHONPATH=$PYTHONPATH:/usr/lib/python/plat-linux2
PYTHONPATH=$PYTHONPATH:/usr/lib/python/lib-dynload
PYTHONPATH=$PYTHONPATH:/usr/lib/python/site-packages
PYTHONPATH=$PYTHONPATH:$STESWD/pyt

export PYTHONPATH

#------------------------------------------------------------------------------------------------
# Define QT environment variables.
#------------------------------------------------------------------------------------------------
QTDIR=/usr/local/qt
PATH=$PATH:$QTDIR/bin
MANPATH=$MANPATH:$QTDIR/doc/man
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$QTDIR/lib

#------------------------------------------------------------------------------------------------
# Define TMS environment variables.
#------------------------------------------------------------------------------------------------
TMS=/opt/tms/linux
TMS_CONFIG=$TMS/config
PATH=$PATH:$TMS/bin
PATH=$PATH:$TMS/diags
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$TMS/lib

export TMS TMS_CONFIG

#------------------------------------------------------------------------------------------------
# Export the Emacs load path.  Will require a link to specific emacs directory.
#------------------------------------------------------------------------------------------------
export EMACSLOADPATH=/usr/share/doc/octave/emacs

#------------------------------------------------------------------------------------------------
# XMIDAS.  Will require a link to specific xmidas directory.
#------------------------------------------------------------------------------------------------
export XMDISK=/opt/xmidas
export XMOPTS=~/xmopts
alias xms='source $XMDISK/xm/unix/xmstart'
#***BASH can not source this***
#if(-e /etc/midas.cshrc) source /etc/midas.cshrc
#***BASH can not source this***
PATH=$PATH:$XMOPTS/xmc/dev

#------------------------------------------------------------------------------------------------
# Define ICE directory.  Will require a link to specific ice directory.
#------------------------------------------------------------------------------------------------
export ICEROOT=/opt/xmidas/localopts/ice

#------------------------------------------------------------------------------------------------
# PGI FORTRAN.
#------------------------------------------------------------------------------------------------
##PGI=/opt/pgi
##PATH=$PATH:/opt/pgi/linux86/6.0/bin
##LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PGI/linux86/6.0/lib

##export PGI PATH LD_LIBRARY_PATH

#------------------------------------------------------------------------------------------------
# INTEL C
#------------------------------------------------------------------------------------------------
#PATH=$PATH:/opt/intel/cc/9.0/bin
#LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/intel/cc/9.0/lib
#MANPATH=$MANPATH:/opt/intel/cc/9.0/man

#------------------------------------------------------------------------------------------------
# INTEL FORTRAN
#------------------------------------------------------------------------------------------------
#PATH=$PATH:/opt/intel/fc/9.0/bin
#LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/intel/fc/9.0/lib
#MANPATH=$MANPATH:/opt/intel/fc/9.0/man

export MYFONT="-misc-fixed-medium-r-normal--14-130-75-75-c-70-iso8859-9"

#echo $PATH | awk 'BEGIN{ FS=":"}{x=split($0,s,":");for(ii=1;ii<x;ii++){print s[ii];}}'
#echo $LD_LIBRARY_PATH | awk 'BEGIN{ FS=":"}{x=split($0,s,":");for(ii=1;ii<x;ii++){print s[ii];}}'

set MOZ_PLUGIN_PATH=/home/steswd/.mozilla/plugins
