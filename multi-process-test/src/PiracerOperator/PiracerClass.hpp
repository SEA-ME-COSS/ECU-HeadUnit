#ifndef PIRACERCLASS_HPP
#define PIRACERCLASS_HPP


// Include necessary header
#include <stdint.h>

// Include python header
#include <Python.h>


class PiracerClass
{
    private:
        PyObject *pModule, *pClass, *pInstance, *pArgs;
        uint16_t gearMode;
        
    public:
        PiracerClass();
        void setGearMode(uint16_t _gearMode);
        uint16_t getGearMode();
        void applyThrottle(double throttle);
        void applySteering(double steering);
        ~PiracerClass();
};


extern PiracerClass piracer;


#endif

