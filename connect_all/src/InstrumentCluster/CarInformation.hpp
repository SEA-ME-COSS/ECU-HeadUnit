#ifndef CARINFORMATION_HPP
#define CARINFORMATION_HPP


// Include necessary header
#include <stdint.h>

// Include Multi-thread header
#include <pthread.h>


extern uint16_t speed;
extern uint16_t rpm;
extern uint16_t battery;
extern uint16_t gear;
extern uint16_t direction;

extern pthread_mutex_t CarInformationMutex;


#endif

