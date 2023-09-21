#ifndef PIRACERCLASS_HPP
#define PIRACERCLASS_HPP


// Include necessary header
#include <stdint.h>

// Include multi thread header
#include <pthread.h>

// Include python header
#include <Python.h>


class PiracerClass
{
    private:
        PyObject *pModule, *pClass, *pInstance, *pVoltage, *pArgs;
        uint16_t gearMode;
        double voltageLevel;
        uint16_t batteryLevel;
        
    public:
        PiracerClass();
        void setGearMode(uint16_t _gearMode);
        uint16_t getGearMode();
        uint16_t getBatteryLevel();
        void applyThrottle(double throttle);
        void applySteering(double steering);
        ~PiracerClass();
};


extern PiracerClass piracer;

extern pthread_mutex_t piracerMutex;


#endif

