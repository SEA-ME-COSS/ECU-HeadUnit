#ifndef READCANTHREAD_H
#define READCANTHREAD_H


#ifdef __cplusplus
extern "C" {
#endif


// Include necessary header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include CAN header
#include <fcntl.h>
#include <net/if.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/can.h>
#include <linux/can/raw.h>

// Include CANbuffer header
#include "CANbuffer.h"


extern int soc;    // Variable for can socket

int open_port(const char *port);    // Function for open socket
void read_port(uint16_t *speed_sensor_rpm);   // Function for read CAN socket
int close_port();   // Function for close socket
void *readCANThread(void *arg);    // Function for thread


#ifdef __cplusplus
}
#endif


#endif

