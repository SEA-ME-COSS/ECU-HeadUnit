#ifndef READCANTHREAD_H
#define READCANTHREAD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <linux/can/raw.h>

#include "CANBuffer.h"

int open_port(const char *port);       // Function to open and configure the CAN port
void read_port(uint16_t *speed_sensor_rpm);  // Function to read data from the CAN port
int close_port();                      // Function to close the CAN port
void *ReadCANThread(void *arg);         // Thread function to read CAN data continuously

#ifdef __cplusplus
}
#endif

#endif

