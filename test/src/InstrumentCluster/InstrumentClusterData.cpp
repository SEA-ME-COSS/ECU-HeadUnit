#include "InstrumentClusterData.hpp"


uint16_t speed = 0;
uint16_t rpm = 0;
uint16_t battery = 0;
uint16_t gear = 0;
uint16_t direction = 0;

bool setSpeedRpmCalled = false;
bool setBatteryCalled = false;
bool setGearCalled = false;
bool setDirectionCalled = false;

pthread_mutex_t InstrumentClusterDataMutex = PTHREAD_MUTEX_INITIALIZER;

