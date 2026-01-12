!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Macro to initialize system specific settings.
! @author Jeff Schoen
! @version $Id: nmstartup.mm,v 1.2 2008/06/22 19:55:28 steswd Exp $
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
startmacro

info "DEPRECATION warnings ON, to turn off edit nmstartup.mm in SYS->CFG"
debug on DEPRECATE

set U:AUX.1 "/data11/+/"

set U:AUX.9 "ramd:/midas/icedisk/,RAM,372M,128M"

set U:AUX.99 "/opt/xmidas/xm/dat/"

set U:AUX.WEB "http://alice.techma.com/nm/nxm/sys/dat/"

aux 1 1 cwd dat 99 ram

path set audio
path add+ database
path add+ dsp
path add+ hwc
path add+ map
path add+ nmpost
path add+ servlet
path add+ ucl
path add+ vnc
path add+ xbc

env set "HWFILE" nxm.sys.dat.hwconfig



!if env.ostype eqs "UNIX"
! set U:AUX.1 "/data11/+/"
! set U:AUX.9 "ramd:/midas/icedisk/,RAM,372M,128M"
! set U:AUX.99 "/opt/xmidas/xm/dat/"
!elseif env.ostype eqs "DOS"
! set U:AUX.1 "\midas\data1\+\"
! set U:AUX.9 "\midas\icedisk\"
! set U:AUX.99 "\midas\opt\xmxxx\xm\dat\"
!elseif env.ostype eqs "VMS"
! set U:AUX.1 "MIDAS$DISK:[data1.+]"
! set U:AUX.9 "MIDAS$DISK:[icedisk]"
! set U:AUX.99 "MIDAS$DISK:[opt.xmxxx.xm.dat]"
!endif
!set U:AUX.WEB "http://alice.techma.com/nm/nxm/sys/dat/"
!aux 1 1 cwd dat 99 ram
!path set dsp hwc
!env set "HWFILE" nxm.sys.dat.hwconfig

endmacro

!make all audio
!make all database
!make all dsp
!make all hwc
!make all map
!make all nmpost
!make all servlet
!make all ucl
!make all vnc
!make all xbc


