// Include header
#include "piracerClass.hpp"


PiracerClass::PiracerClass()
{
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.vehicles");
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard");
    pInstance = PyObject_CallObject(pClass, NULL);
}

uint16_t PiracerClass::getBatteryLevel()
{
    pResult = PyObject_CallMethod(pInstance, "get_battery_voltage", NULL);
    voltageLevel = PyFloat_AsDouble(pResult);
    batteryLevel = (uint16_t)((voltageLevel - 2.8 * 3.0) / (12.3 - 2.8 * 3.0) * 100.0);
    
    return batteryLevel;
}

PiracerClass::~PiracerClass()
{
    Py_DECREF(pResult);
    Py_DECREF(pInstance);
    Py_DECREF(pClass);
    Py_DECREF(pModule);
    Py_Finalize();
}

