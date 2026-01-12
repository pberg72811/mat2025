#!/bin/bash

# IF clause for MacOS
if [[ $OSTYPE == 'darwin'* ]];
then
  myip=$(ifconfig en0 | grep inet | awk '$1=="inet" {print $2}' | head -n 1)
  echo $myip
  export DISPLAY=$myip:0
  echo $DISPLAY
fi

# DISPLAY assumed to be set for remainder of script.
xhost +
if [ -e /dev/dri ]; then
  docker run --name=xm-training -ti --rm \
    --network=host \
    -e DISPLAY=$DISPLAY \
    -e SHELL=/bin/tcsh \
    -p "8333:8333" \
    -p "8444:8444" \
    -p "8445:8445" \
    -p "8446:8446" \
    -p "8447:8447" \
    -p "8448:8448" \
    -h "training" \
    -e "QT_X11_NO_MITSHM=1" \
    -e "XDG_RUNTIME_DIR=/tmp/runtime-xmmgr" \
    --device=/dev/dri \
    -v "/tmp/.X11-unix:/tmp/.X11-unix" \
    -v "xmidas:/opt/xmidas" \
    -v "midas:/data/midas" \
    -v "home:/home/xmmgr" \
    xmidas:xm-training-5_10_0-ubuntu22
else
  docker run --name=xm-training -ti --rm \
    --network=host \
    -e DISPLAY=$DISPLAY \
    -e SHELL=/bin/tcsh \
    -p "8080:8080" \
    -p "8333:8333" \
    -p "8444:8444" \
    -p "8445:8445" \
    -p "8446:8446" \
    -p "8447:8447" \
    -p "8448:8448" \
    -h "training" \
    -e "QT_X11_NO_MITSHM=1" \
    -e "XDG_RUNTIME_DIR=/tmp/runtime-xmmgr" \
    -v "/tmp/.X11-unix:/tmp/.X11-unix" \
    -v "xmidas:/opt/xmidas" \
    -v "midas:/data/midas" \
    -v "home:/home/xmmgr" \
    xmidas:xm-training-5_10_0-ubuntu22
fi
