// Include header
#include "CANbuffer.h"


uint16_t CANbuffer[CANbuffer_SIZE] = {0};    // CANbuffer
int CANbufferIndex = 0;    // Index for the CANbuffer
pthread_mutex_t CANbufferMutex = PTHREAD_MUTEX_INITIALIZER;    // Mutex for the CANbuffer

