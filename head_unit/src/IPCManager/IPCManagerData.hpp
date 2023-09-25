#ifndef IPCMANAGERDATA_HPP
#define IPCMANAGERDATA_HPP


#include <stdint.h>
#include <pthread.h>


extern uint16_t sensorRpm;
extern uint16_t batteryLevel;

extern bool setSensorRpmCalled;
extern bool setBatteryLevelCalled;

extern pthread_mutex_t IPCManagerDataMutex;


#endif

