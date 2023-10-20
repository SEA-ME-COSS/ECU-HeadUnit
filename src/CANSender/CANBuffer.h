#ifndef CANBUFFER_H
#define CANBUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <pthread.h>

// Define the size of the CAN buffer as 10.
#define CANBuffer_SIZE 10

// Declare an array of unsigned 16-bit integers to represent the CAN buffer.
extern uint16_t CANBuffer[CANBuffer_SIZE];

// Declare an integer variable to keep track of the current index in the CAN buffer.
extern int CANBufferIndex;

// Declare a mutex for thread synchronization to protect the CAN buffer.
extern pthread_mutex_t CANBufferMutex;

#ifdef __cplusplus
}
#endif

#endif

