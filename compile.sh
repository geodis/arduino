#!/bin/bash

arduino="/home/ctaglia/src/arduino/arduino-1.8.13/arduino" 
--board esp8266:esp8266:nodemcuv2:xtal=80,vt=flash,exception=legacy,ssl=all,eesz=4M2M,led=2,ip=lm2f,dbg=Disabled,lvl=None____,wipe=none,baud=115200 \
--upload \
--port /dev/ttyUSB0 \
--verbose-build /home/ctaglia/current/my-examples/oled-rgb/clock.ino
