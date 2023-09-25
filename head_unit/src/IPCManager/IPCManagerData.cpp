#include "IPCManagerData.hpp"


uint16_t sensorRpm = 0;
uint16_t batteryLevel = 50;

bool setSensorRpmCalled = false;
bool setBatteryLevelCalled = false;

pthread_mutex_t IPCManagerDataMutex = PTHREAD_MUTEX_INITIALIZER;

