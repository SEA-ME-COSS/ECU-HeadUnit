#!/bin/sh

echo "Setting for CAN"
ip link set can0 up type can bitrate 500000
echo "CAN setup complete"

echo "Start simple example"
cd /usr/bin/example
./simple -platform eglfs
echo "Simple is running"
