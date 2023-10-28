#include "ControllerClass.hpp"
#include "iostream"

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
    
    button_A = false;
    button_B = false;
    button_X = false;
    button_Y = false;
}

// Destructor for the ControllerClass
ControllerClass::~ControllerClass()
{
    // Release Python objects to avoid memory leaks
    Py_DECREF(pButtonA);
    Py_DECREF(pButtonB);
    Py_DECREF(pButtonX);
    Py_DECREF(pButtonY);
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
    
    pButtonA = PyObject_GetAttrString(pInput, "button_a");
    if (pButtonA != NULL)
    {
        button_A = PyObject_IsTrue(pButtonA);
        std::cout<<"000"<<std::endl;
    }
        
        
        
        //button_A = PyObject_IsTrue(pButtonA);
    
    
    
    
        /*if (pButton_A == Py_True)
        {
            std::cout<<"\n"<<"A"<<std::endl;
        }
        if (pButton_B == Py_True)
        {
            std::cout<<"\n"<<"B"<<std::endl;
        }
        if (pButton_X == Py_True)
        {
            std::cout<<"\n"<<"X"<<std::endl;
        }
        if (pButton_Y == Py_True)
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

