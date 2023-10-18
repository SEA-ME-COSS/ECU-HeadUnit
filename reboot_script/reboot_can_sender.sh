#!/bin/bash

process_name="CANSender"

if pgrep -x "$process_name" > /dev/null
then
  pkill -x "$process_name"
fi

sudo ip link set can0 up type can bitrate 500000
sudo ifconfig can0 txqueuelen 65536

cd ../build
./"$process_name" &

