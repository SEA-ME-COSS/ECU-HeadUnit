#!/bin/bash

# Define the process name to be checked and controlled
process_name="CANSender"

# Check if a process with the specified name is running
if pgrep -x "$process_name" > /dev/null
then
  # If the process is running, gracefully terminate it using pkill
  pkill -x "$process_name"
fi

# Set up and configure the CAN interface 'can0'
# Bring the 'can0' interface up and set its bitrate to 500,000 bits per second
sudo ip link set can0 up type can bitrate 500000

# Set the transmit queue length of 'can0' to 65,536 (maximum value)
sudo ifconfig can0 txqueuelen 65536

# Change the working directory to '../build'
cd ../build

# Run the specified process with '&' to execute it in the background
./"$process_name" &

