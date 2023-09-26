#include "HeadUnitData.hpp"


uint16_t sensorRpm = 0;
uint16_t gear = 0;
uint16_t direction = 0;

pthread_mutex_t HeadUnitDataMutex = PTHREAD_MUTEX_INITIALIZER;

