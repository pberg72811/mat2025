# !/bin/tcsh
#------------------------------------------------------------------------------------------------

#------------------------------------------------------------------------------------------------
# Source globals.
#------------------------------------------------------------------------------------------------
if ( -e /etc/cshrc ) source /etc/cshrc

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

















#------------------------------------------------------------------------------------------------
# Define the Prompt. 
#------------------------------------------------------------------------------------------------
set prompt = "XM:%/>"

#------------------------------------------------------------------------------------------------
# Define the PATH
#------------------------------------------------------------------------------------------------
setenv PATH .
setenv PATH $PATH":.."
setenv PATH $PATH":/bin"
setenv PATH $PATH":/sbin"
setenv PATH $PATH":/usr/bin"
setenv PATH $PATH":/usr/sbin"
setenv PATH $PATH":/usr/exec"
setenv PATH $PATH":/usr/local/bin"
setenv PATH $PATH":/usr/X11R6/bin"



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
# Set up for Special Test Equipment Software Development (STESWD).
#------------------------------------------------------------------------------------------------
#if ( $USER == steswd ) then
#  setenv STESWD $HOME"/steswd"
#else
#  setenv STESWD /opt/xmidas/localopts/ste
#endif
#
#setenv PATH $PATH":"$STESWD"/bin"
#setenv PATH $PATH":"$STESWD"/dev"
#setenv LD_LIBRARY_PATH $LD_LIBRARY_PATH":"$STESWD"/lib"



#------------------------------------------------------------------------------------------------
# Define CVS root directory.
#------------------------------------------------------------------------------------------------
setenv CVSROOT /opt/cvs
setenv CVS_RSH ssh

#------------------------------------------------------------------------------------------------
# Define Java CLASSPATH environment variable.  Will require a link to specific jdk.
#------------------------------------------------------------------------------------------------
setenv PATH $PATH":/usr/java/jdk/bin"
setenv CLASSPATH .
setenv CLASSPATH $CLASSPATH":/usr/java/jdk/jre/lib/rt.jar"
setenv CLASSPATH $CLASSPATH":~/jev/jniOrbitUtilsJava"



#------------------------------------------------------------------------------------------------
# Define PYTHON PATH environment variable.
#------------------------------------------------------------------------------------------------
setenv PYTHONPATH .
setenv PYTHONPATH $PYTHONPATH":/usr/lib/lib-tk"
setenv PYTHONPATH $PYTHONPATH":/usr/lib/python2.2"
setenv PYTHONPATH $PYTHONPATH":/usr/lib/python2.2/plat-linux2"
setenv PYTHONPATH $PYTHONPATH":/usr/lib/python2.2/lib-dynload"
setenv PYTHONPATH $PYTHONPATH":/usr/lib/python2.2/site-packages"
setenv PYTHONPATH $PYTHONPATH":~/pyt"



#------------------------------------------------------------------------------------------------
# Define QT environment variables.
#------------------------------------------------------------------------------------------------
setenv QTDIR /usr/local/qt
setenv PATH $PATH":"$QTDIR"/bin"
setenv MANPATH $MANPATH":"$QTDIR"/doc/man"
setenv LD_LIBRARY_PATH $LD_LIBRARY_PATH":"$QTDIR"/lib"

#------------------------------------------------------------------------------------------------
# Define TMS environment variables.
#------------------------------------------------------------------------------------------------
setenv TMS /opt/tms/linux
setenv TMS_CONFIG $TMS/config
setenv PATH $PATH":"$TMS"/bin"
setenv PATH $PATH":"$TMS"/diags"
setenv LD_LIBRARY_PATH $LD_LIBRARY_PATH":"$TMS"/lib"



#------------------------------------------------------------------------------------------------
# Export the Emacs load path.  Will require a link to specific octave directory
#------------------------------------------------------------------------------------------------
setenv EMACSLOADPATH /usr/share/doc/octave/emacs

#------------------------------------------------------------------------------------------------
# XMIDAS.  Will require a link to specific xmidas directory.
#------------------------------------------------------------------------------------------------
setenv XMDISK /opt/xmidas
setenv XMOPTS ~/xmopts
alias xms "source $XMDISK/xm/unix/xmstart"
if(-e /etc/midas.cshrc) source /etc/midas.cshrc
setenv PATH $PATH":"$XMOPTS"/xmc/dev"



#------------------------------------------------------------------------------------------------
# Define ICE directory.  Will require a link to specific ice directory.
#------------------------------------------------------------------------------------------------
setenv ICEROOT /opt/xmidas/localopts/ice

#------------------------------------------------------------------------------------------------
# PGI FORTRAN.
#------------------------------------------------------------------------------------------------
##setenv PGI /opt/pgi
##setenv PATH $PATH":"$PGI"/linux86/6.0/bin"
##setenv LD_LIBRARY_PATH $LD_LIBRARY_PATH":"$PGI"/linux86/6.0/lib"



#------------------------------------------------------------------------------------------------
# INTEL C
#------------------------------------------------------------------------------------------------
setenv PATH $PATH":/opt/intel/cc/9.0/bin"
setenv LD_LIBRARY_PATH $LD_LIBRARY_PATH":/opt/intel/cc/9.0/lib"
setenv MANPATH $MANPATH":/opt/intel/cc/9.0/man"

#------------------------------------------------------------------------------------------------
# INTEL FORTRAN
#------------------------------------------------------------------------------------------------
setenv PATH $PATH":/opt/intel/fc/9.0/bin"
setenv LD_LIBRARY_PATH $LD_LIBRARY_PATH":/opt/intel/fc/9.0/lib"
setenv MANPATH $MANPATH":/opt/intel/fc/9.0/man"


#------------------------------------------------------------------------------------------------
# Kill the PYTHONPATH for XMidas' sake.
#------------------------------------------------------------------------------------------------
unsetenv PYTHONPATH

#echo $PATH | awk 'BEGIN{ FS=":"}{x=split($0,s,":");for(ii=1;ii<x;ii++){print s[ii];}}'
#echo $LD_LIBRARY_PATH | awk 'BEGIN{ FS=":"}{x=split($0,s,":");for(ii=1;ii<x;ii++){print s[ii];}}'
