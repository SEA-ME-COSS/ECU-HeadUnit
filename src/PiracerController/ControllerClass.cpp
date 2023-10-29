#include "ControllerClass.hpp"
#include <iostream>

// Constructor for the ControllerClass
ControllerClass::ControllerClass()
{
    // Initialize the Python interpreter
    Py_Initialize();
    
    // Import the "piracer.gamepads" module
    pModule = PyImport_ImportModule("piracer.gamepads");

    // Get the "ShanWanGamepad" class from the module
    pClass = PyObject_GetAttrString(pModule, "ShanWanGamepad");

    // Create an instance of the "ShanWanGamepad" class
    pInstance = PyObject_CallObject(pClass, NULL);
    
    throttle = 0.0;
    steering = 0.0;
    pre_throttle = 0.0;
    pre_steering = 0.0;
    
    button_l1 = false;
    button_l2 = false;
    button_r1 = false;
    button_r2 = false;
    button_A = false;
    button_B = false;
    button_X = false;
    button_Y = false;
    button_select = false;
    button_start = false;
    button_home = false;
}

// Destructor for the ControllerClass
ControllerClass::~ControllerClass()
{
    // Release Python objects to avoid memory leaks
    Py_DECREF(pThrottle);
    Py_DECREF(pSteering);
    Py_DECREF(pInput);
    Py_DECREF(pInstance);
    Py_DECREF(pClass);
    Py_DECREF(pModule);
    
    // Finalize the Python interpreter
    Py_Finalize();
}

// Read control input from the gamepad
void ControllerClass::readControl()
{
    pre_throttle = throttle;
    pre_steering = steering;

    // Call the "read_data" method on the gamepad instance
    pInput = PyObject_CallMethod(pInstance, "read_data", NULL);
    
    pThrottle = PyObject_GetAttrString(pInput, "analog_stick_right");
    pThrottle = PyObject_GetAttrString(pThrottle, "y");
    throttle = PyFloat_AsDouble(pThrottle);
    
    pSteering = PyObject_GetAttrString(pInput, "analog_stick_left");
    pSteering = PyObject_GetAttrString(pSteering, "x");
    steering = PyFloat_AsDouble(pSteering);
    
    button_l1 = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_l1"));
    button_l2 = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_l2"));
    button_r1 = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_r1"));
    button_r2 = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_r2"));
    button_A = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_a"));
    button_B = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_b"));
    button_X = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_x"));
    button_Y = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_y"));
    button_select = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_select"));
    button_start = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_start"));
    button_home = PyObject_IsTrue(PyObject_GetAttrString(pInput, "button_home"));
    
    /*if (button_A)
    {
        std::cout<<"\n"<<"A"<<std::endl;
    }
    if (button_B)
    {
        std::cout<<"\n"<<"B"<<std::endl;
    }
    if (button_X)
    {
        std::cout<<"\n"<<"X"<<std::endl;
    }
    if (button_Y)
    {
        std::cout<<"\n"<<"Y"<<std::endl;
    }*/
    
    return;
}

// Get the current throttle value
double ControllerClass::getThrottle()
{
    return throttle;
}

// Get the current steering value
double ControllerClass::getSteering()
{
    return steering;
}

// Get the previous throttle value
double ControllerClass::getPreThrottle()
{
    return pre_throttle;
}

// Get the previous steering value
double ControllerClass::getPreSteering()
{
    return pre_steering;
}

