#ifndef CANBUFFER_H
#define CANBUFFER_H


#ifdef __cplusplus
extern "C" {
#endif


// Include necessary header
#include <stdint.h>

// Include Multi-thread header
#include <pthread.h>


#define CANbuffer_SIZE 10


extern uint16_t CANbuffer[CANbuffer_SIZE];    // CANbuffer
extern int CANbufferIndex;    // Index for the CANbuffer
extern pthread_mutex_t CANbufferMutex;    // Mutex for the CANbuffer


#ifdef __cplusplus
}
#endif


#endif

