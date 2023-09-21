// Include header
#include "ControllerClass.hpp"


PiracerController::PiracerController()
{
    Py_Initialize();
    pModule = PyImport_ImportModule("piracer.gamepads");
    pClass = PyObject_GetAttrString(pModule, "ShanWanGamepad");
    pInstance = PyObject_CallObject(pClass, NULL);
}

void PiracerController::readControl()
{
    pInput = PyObject_CallMethod(pInstance, "read_data", NULL);
    pThrottle = PyObject_GetAttrString(pInput, "analog_stick_right");
    pThrottle = PyObject_GetAttrString(pThrottle, "y");
    pSteering = PyObject_GetAttrString(pInput, "analog_stick_left");
    pSteering = PyObject_GetAttrString(pSteering, "x");
    
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

PiracerController::~PiracerController() {}


PiracerController controller;

