#ifndef CONTROLLERCLASS_HPP
#define CONTROLLERCLASS_HPP

#include <Python.h>

class ControllerClass
{
private:
    PyObject *pModule, *pClass, *pInstance, *pInput, *pSteering;
    double steering;  // Stores the steering value

public:
    // Constructor for the ControllerClass
    ControllerClass();

    // Destructor for the ControllerClass
    ~ControllerClass();

    // Read control input from the gamepad
    void readControl();

    // Get the current steering value
    double getSteering();
};

#endif

