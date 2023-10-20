// Include the header file for CANBuffer.
#include "CANBuffer.h"

// Define an array of unsigned 16-bit integers to represent the CAN buffer.
uint16_t CANBuffer[CANBuffer_SIZE] = {0};

// Initialize an integer variable to keep track of the current index in the CAN buffer.
int CANBufferIndex = 0;

// Initialize a mutex for thread synchronization to protect the CAN buffer.
pthread_mutex_t CANBufferMutex = PTHREAD_MUTEX_INITIALIZER;

