#ifndef PIRACERCLASS_HPP
#define PIRACERCLASS_HPP

#include <stdint.h>
#include <Python.h>

class PiracerClass
{
private:
    PyObject *pModule, *pClass, *pInstance, *pVoltage;
    double voltageLevel;
    uint16_t batteryLevel;

public:
    // Constructor: Initializes the Python interpreter, imports a module, and creates an instance
    PiracerClass();

    // Destructor: Releases Python objects and finalizes the Python interpreter
    ~PiracerClass();

    // Method to get the battery level by calling a Python method
    uint16_t getBatteryLevel();
};

#endif

