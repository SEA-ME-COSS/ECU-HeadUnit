#include "IPCManagerData.hpp"


uint16_t sensorRpm = 0;
uint16_t batteryLevel = 0;
uint16_t gearMode = 0;
uint16_t direction = 0;

bool setSensorRpmCalled = false;
bool setBatteryLevelCalled = false;
bool setGearModeCalled = false;
bool setDirectionCalled = false;

pthread_mutex_t IPCManagerDataMutex = PTHREAD_MUTEX_INITIALIZER;

