#!/bin/bash

process_name="PiracerOperator"

if pgrep -x "$process_name" > /dev/null
then
  pkill -x "$process_name"
  sleep 1
fi

cd ../build
./"$process_name" &
sleep 3
