#include "PiracerClass.hpp"

PiracerClass::PiracerClass()
{
    // Initialize the Python interpreter
    Py_Initialize();
    
    // Import the Python module "piracer.vehicles"
    pModule = PyImport_ImportModule("piracer.vehicles");
    
    // Get the Python class "PiRacerStandard" from the module
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard");
    
    // Create an instance of the Python class
    pInstance = PyObject_CallObject(pClass, NULL);
}

PiracerClass::~PiracerClass()
{
    // Release Python objects and finalize the Python interpreter
    Py_DECREF(pVoltage);
    Py_DECREF(pInstance);
    Py_DECREF(pClass);
    Py_DECREF(pModule);
    Py_Finalize();
}

uint16_t PiracerClass::getBatteryLevel()
{
    // Call the Python method "get_battery_voltage" on the Python instance
    pVoltage = PyObject_CallMethod(pInstance, "get_battery_voltage", NULL);
    
    // Convert the Python float to a C++ double
    voltageLevel = PyFloat_AsDouble(pVoltage);
    
    // Calculate the battery level as a percentage
    batteryLevel = (uint16_t) ((voltageLevel - 2.8 * 3.0) / (12.3 - 2.8 * 3.0) * 100.0);
    
    return batteryLevel;
}

