#ifndef PIRACERCLASS_HPP
#define PIRACERCLASS_HPP


// Include necessary header
#include <stdint.h>

// Include python header
#include <Python.h>


class PiracerClass
{
    private:
        PyObject *pModule, *pClass, *pInstance, *pValue;
        double voltageLevel;
        uint16_t batteryLevel;
        
    public:
        PiracerClass();
        uint16_t getBatteryLevel();
        ~PiracerClass();
};


extern PiracerClass piracer;


#endif

