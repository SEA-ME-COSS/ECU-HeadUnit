// Include header
#include "piracerClass.hpp"


PiracerClass::PiracerClass()
{
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.vehicles");
    Py_INCREF(pModule);
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard");
    Py_INCREF(pClass);
    pInstance = PyObject_CallObject(pClass, NULL);
    Py_INCREF(pInstance);
}

uint16_t PiracerClass::getBatteryLevel()
{
    pResult = PyObject_CallMethod(pInstance, "get_battery_voltage", NULL);
    Py_INCREF(pResult);
    voltageLevel = PyFloat_AsDouble(pResult);
    Py_DECREF(pResult);
    batteryLevel = (uint16_t)((voltageLevel - 2.8 * 3.0) / (12.3 - 2.8 * 3.0) * 100.0);
    
    return batteryLevel;
}
       
PiracerClass::~PiracerClass()
{
    Py_DECREF(pInstance);
    Py_DECREF(pClass);
    Py_DECREF(pModule);
    Py_Finalize();
}

