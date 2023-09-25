#ifndef INSTRUMENTCLUSTERDATA_HPP
#define INSTRUMENTCLUSTERDATA_HPP


#include <stdint.h>
#include <pthread.h>


extern uint16_t speed;
extern uint16_t rpm;
extern uint16_t battery;
extern uint16_t gear;
extern uint16_t direction;

extern bool setSpeedRpmCalled;
extern bool setBatteryCalled;
extern bool setGearCalled;
extern bool setDirectionCalled;

extern pthread_mutex_t InstrumentClusterDataMutex;


#endif

