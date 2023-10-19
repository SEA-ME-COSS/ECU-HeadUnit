#ifndef CONTROLLERCLASS_HPP
#define CONTROLLERCLASS_HPP

#include <Python.h>

class ControllerClass
{
private:
    PyObject *pModule, *pClass, *pInstance, *pInput, *pThrottle, *pSteering;
    double throttle;  // Stores the throttle value
    double steering;  // Stores the steering value

public:
    // Constructor for the ControllerClass
    ControllerClass();

    // Destructor for the ControllerClass
    ~ControllerClass();

    // Read control input from the gamepad
    void readControl();

    // Get the current throttle value
    double getThrottle();

    // Get the current steering value
    double getSteering();
};

#endif

