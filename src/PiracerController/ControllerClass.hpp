#ifndef CONTROLLERCLASS_HPP
#define CONTROLLERCLASS_HPP

#include <Python.h>

class ControllerClass
{
private:
    PyObject *pModule, *pClass, *pInstance, *pInput, *pThrottle, *pSteering;
    
    double throttle;  // Stores the throttle value
    double steering;  // Stores the steering value
    
    double pre_throttle;  // Stores the previous throttle value
    double pre_steering;  // Stores the previous steering value
    
    bool button_l1;
    bool button_l2;
    bool button_r1;
    bool button_r2;
    bool button_A;
    bool button_B;
    bool button_X;
    bool button_Y;
    bool button_select;
    bool button_start;
    bool button_home;
    
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
    
    // Get the previous throttle value
    double getPreThrottle();

    // Get the previous steering value
    double getPreSteering();
};

#endif

