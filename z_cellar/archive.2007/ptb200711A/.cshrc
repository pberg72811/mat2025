# !/bin/tcsh
#-----------------------------------------UNCLASSIFIED-------------------------------------------
# File: .cshrc                                                                                  -
#                                                                                               -
# Desc: This is the user start up script for a C-Shell (csh or tcsh).                           -
#                                                                                               -
# Hist: When       Who  What                                                                    -
#       06/27/2007 ptb  Initial start.                                                          -
#                                                                                               -
# Note:                                                                                         -
#                                                                                               -
#------------------------------------------------------------------------------------------------

#------------------------------------------------------------------------------------------------
# Source setup file.
#------------------------------------------------------------------------------------------------
unset file
set file="/etc/cshrc"
if ( -f $file ) then
  source $file
# else                                                      # This echo messes up any "scp" you
#   echo "No custom setup file... $file"                    # attempt to perform.
endif

#------------------------------------------------------------------------------------------------
# User specific aliases and functions
#------------------------------------------------------------------------------------------------
#echo C---------------------- Welcome to C-Shell at $HOST.
unalias ls
unalias ll
unalias vi

alias ll   'ls -l --color=tty'
alias llh  'ls -lh --color=tty'
alias lla  'ls -al --color=tty'
alias llha 'ls -alh --color=tty'
alias rm   'rm -i'
#echo C---------------------- Enjoy your stay.

set history=1024
set savehist=1024

#------------------------------------------------------------------------------------------------
# What is our $OPT environment?
#------------------------------------------------------------------------------------------------
setenv OPT /iex

#------------------------------------------------------------------------------------------------
# Define the Prompt. 
#------------------------------------------------------------------------------------------------
set prompt = "XM:%/>"

#------------------------------------------------------------------------------------------------
# Define the PATH
#------------------------------------------------------------------------------------------------
setenv PATH .
setenv PATH $PATH":.."
setenv PATH $PATH":/usr/local/bin"                          # Put custom application here.
setenv PATH $PATH":/bin"
setenv PATH $PATH":/sbin"
setenv PATH $PATH":/usr/bin"
setenv PATH $PATH":/usr/sbin"
setenv PATH $PATH":/usr/exec"
setenv PATH $PATH":/usr/X11R6/bin"
setenv PATH $PATH":$OPT/xmopts/xcc/bin"

#------------------------------------------------------------------------------------------------
# Define the LOAD LIBRARY PATH.
#------------------------------------------------------------------------------------------------
setenv LD_LIBRARY_PATH .
setenv LD_LIBRARY_PATH $LD_LIBRARY_PATH":/usr/local/lib"

#------------------------------------------------------------------------------------------------
# Define the MAN PATH.
#------------------------------------------------------------------------------------------------
setenv MANPATH

#------------------------------------------------------------------------------------------------
# CVS.
#------------------------------------------------------------------------------------------------
setenv CVSROOT $OPT/cvs
setenv CVS_RSH ssh

#------------------------------------------------------------------------------------------------
# Emacs.
#------------------------------------------------------------------------------------------------
setenv EMACSLOADPATH /usr/share/doc/octave/emacs

#------------------------------------------------------------------------------------------------
# JAVA.
#------------------------------------------------------------------------------------------------
setenv JAVAHOME $OPT/jdk
setenv PATH $PATH":$JAVAHOME/bin"
setenv CLASSPATH .
setenv CLASSPATH $CLASSPATH":/usr/java/jdk/jre/lib/rt.jar"
setenv CLASSPATH $CLASSPATH":~/jev/jniOrbitUtilsJava"

#------------------------------------------------------------------------------------------------
# PYTHON.
#------------------------------------------------------------------------------------------------
setenv PYTHONPATH .
setenv PYTHONPATH $PYTHONPATH":/usr/lib/lib-tk"
setenv PYTHONPATH $PYTHONPATH":/usr/lib/python2.2"
setenv PYTHONPATH $PYTHONPATH":/usr/lib/python2.2/plat-linux2"
setenv PYTHONPATH $PYTHONPATH":/usr/lib/python2.2/lib-dynload"
setenv PYTHONPATH $PYTHONPATH":/usr/lib/python2.2/site-packages"
setenv PYTHONPATH $PYTHONPATH":~/pyt"

#------------------------------------------------------------------------------------------------
# NeXtMidas.
#------------------------------------------------------------------------------------------------
setenv NMROOT $OPT/nextmidas
alias nms     'source $NMROOT/os/unix/nmstart'
alias nmstart 'source $NMROOT/os/unix/nmstart'

#------------------------------------------------------------------------------------------------
# XMIDAS.
#------------------------------------------------------------------------------------------------
setenv XMDISK $OPT/xmidas
setenv XMOPTS $OPT/xmidas/myopts
alias xms     "source $XMDISK/xm/unix/xmstart"
alias xmstart "source $XMDISK/xm/unix/xmstart"
#if(-e /etc/midas.cshrc) source /etc/midas.cshrc
setenv PATH $PATH":"$XMOPTS"/xmc/dev"

#------------------------------------------------------------------------------------------------
# ICE.
#------------------------------------------------------------------------------------------------
setenv ICEROOT $XMOPTS/ice

#------------------------------------------------------------------------------------------------
# PGI FORTRAN.
#------------------------------------------------------------------------------------------------
#setenv PGI $OPT/pgi
#setenv PATH $PATH":"$PGI"/linux86/6.0/bin"
#setenv LD_LIBRARY_PATH $LD_LIBRARY_PATH":"$PGI"/linux86/6.0/lib"
#setenv MANPATH $MANPATH":"$PGI"/linux86/6.0/man"
#LM_LICENCE_FILE $PGI/licence.dat

#------------------------------------------------------------------------------------------------
# INTEL C
#------------------------------------------------------------------------------------------------
#setenv INTELCC $OPT/intel/cc/9.0
#setenv PATH $PATH":$INTELCC/bin"
#setenv LD_LIBRARY_PATH $LD_LIBRARY_PATH":$INTELCC/lib"
#setenv MANPATH $MANPATH":$INTELCC/man"

#------------------------------------------------------------------------------------------------
# INTEL FORTRAN
#------------------------------------------------------------------------------------------------
#setenv INTELFC $OPT/intel/fc/9.0
#setenv PATH $PATH":$INTELFC/bin"
#setenv LD_LIBRARY_PATH $LD_LIBRARY_PATH":$INTELFC/lib"
#setenv MANPATH $MANPATH":$INTELFC/man"

#------------------------------------------------------------------------------------------------
# Kill the PYTHONPATH for XMidas' sake.
#------------------------------------------------------------------------------------------------
unsetenv PYTHONPATH

#echo $PATH | awk 'BEGIN{ FS=":"}{x=split($0,s,":");for(ii=1;ii<x;ii++){print s[ii];}}'
#echo $LD_LIBRARY_PATH | awk 'BEGIN{ FS=":"}{x=split($0,s,":");for(ii=1;ii<x;ii++){print s[ii];}}'
