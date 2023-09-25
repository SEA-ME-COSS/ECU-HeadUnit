// Include header
#include "CarInformation.hpp"


uint16_t speed = 0;
uint16_t rpm = 0;
uint16_t battery = 0;
uint16_t gear = 0;
uint16_t direction = 0;

pthread_mutex_t CarInformationMutex = PTHREAD_MUTEX_INITIALIZER;

