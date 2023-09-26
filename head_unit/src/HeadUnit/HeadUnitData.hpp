#ifndef HEADUNITDATA_HPP
#define HEADUNITDATA_HPP


#include <stdint.h>
#include <pthread.h>


extern uint16_t sensorRpm;
extern uint16_t gear;
extern uint16_t direction;

extern pthread_mutex_t HeadUnitDataMutex;


#endif

