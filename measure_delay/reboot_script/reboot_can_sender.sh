#!/bin/bash

process_name="CANSender"

if pgrep -x "$process_name" > /dev/null
then
  pkill -x "$process_name"
  sleep 1
fi

sudo ip link set can0 up type can bitrate 500000
sleep 1
sudo ifconfig can0 txqueuelen 65536
sleep 1

cd ../build
./"$process_name" &
sleep 1

