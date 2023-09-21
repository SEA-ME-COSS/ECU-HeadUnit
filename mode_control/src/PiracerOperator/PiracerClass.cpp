// Include header
#include "PiracerClass.hpp"


PiracerClass::PiracerClass()
{
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.vehicles");
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard");
    pInstance = PyObject_CallObject(pClass, NULL);
    
    gearMode = 3;    // P
}

void PiracerClass::setGearMode(uint16_t _gearMode)
{
    gearMode = _gearMode;
    return;
}

uint16_t PiracerClass::getGearMode()
{
    return gearMode;
}

uint16_t PiracerClass::getBatteryLevel()
{
    pVoltage = PyObject_CallMethod(pInstance, "get_battery_voltage", NULL);
    voltageLevel = PyFloat_AsDouble(pVoltage);
    batteryLevel = (uint16_t)((voltageLevel - 2.8 * 3.0) / (12.3 - 2.8 * 3.0) * 100.0);
    
    return batteryLevel;
}

void PiracerClass::applyThrottle(double throttle)
{
    pArgs = PyTuple_Pack(1, PyFloat_FromDouble(throttle));
    PyObject_CallMethod(pInstance, "set_throttle_percent", "O", pArgs);
    return;
}

void PiracerClass::applySteering(double steering)
{
    pArgs = PyTuple_Pack(1, PyFloat_FromDouble(steering * -1.0));
    PyObject_CallMethod(pInstance, "set_steering_percent", "O", pArgs);
    return;
}

PiracerClass::~PiracerClass() {}


PiracerClass piracer;

pthread_mutex_t piracerMutex = PTHREAD_MUTEX_INITIALIZER;

