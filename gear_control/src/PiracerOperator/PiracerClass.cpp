// Include header
#include "PiracerClass.hpp"
#include <iostream>


PiracerClass::PiracerClass()
{
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.vehicles");
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard");
    pInstance = PyObject_CallObject(pClass, NULL);
    
    gearMode = 0;    // P
    
    std::cout << "Hello World" << std::endl;
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
    pArgs = PyTuple_Pack(1, PyFloat_FromDouble(steering));
    PyObject_CallMethod(pInstance, "set_steering_percent", "O", pArgs);
    return;
}

PiracerClass::~PiracerClass()
{
    //Py_DECREF(pArgs);
    //Py_DECREF(pVoltage);
    //Py_DECREF(pInstance);
    //Py_DECREF(pClass);
    Py_DECREF(pModule);
    Py_Finalize();
    
    std::cout << "Goodbye piracer" << std::endl;
}


PiracerController::PiracerController()
{
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.gamepads");
    pClass = PyObject_GetAttrString(pModule, "ShanWanGamepad");
    pInstance = PyObject_CallObject(pClass, NULL);
    
    std::cout << "Hello World" << std::endl;
}

void PiracerController::readControl()
{
    pInput = PyObject_CallMethod(pInstance, "read_data", NULL);
    pThrottle = PyObject_GetAttrString(pInput, "analog_stick_right.y");
    pSteering = PyObject_GetAttrString(pInput, "analog_stick_left.x");
    
    throttle = PyFloat_AsDouble(pThrottle) * 0.5;
    steering = PyFloat_AsDouble(pSteering);
    return;
}

double PiracerController::getThrottle()
{
    return throttle;
}

double PiracerController::getSteering()
{
    return steering;
}

PiracerController::~PiracerController()
{
    //Py_DECREF(pThrottle);
    //Py_DECREF(pSteering);
    //Py_DECREF(pInput);
    //Py_DECREF(pInstance);
    //Py_DECREF(pClass);
    Py_DECREF(pModule);
    Py_Finalize();
    
    std::cout << "Goodbye controller" << std::endl;
}


PiracerClass piracer;
PiracerController controller;

