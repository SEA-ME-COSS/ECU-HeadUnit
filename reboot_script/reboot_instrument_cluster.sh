#!/bin/bash

# Define the process name to be checked and controlled
process_name="InstrumentCluster"

# Check if a process with the specified name is running
if pgrep -x "$process_name" > /dev/null
then
  # If the process is running, gracefully terminate it using pkill
  pkill -x "$process_name"
fi

# Change the working directory
cd ../execute_files

# Run the specified process with '-platform linuxfb' and '&' to execute it in the background
./"$process_name" -platform linuxfb &

