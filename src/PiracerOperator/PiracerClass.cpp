#include "PiracerClass.hpp"

PiracerClass::PiracerClass()
{
    Py_Initialize(); // Initialize the Python interpreter
    pModule = PyImport_ImportModule("piracer.vehicles"); // Import the Python module "piracer.vehicles"
    pClass = PyObject_GetAttrString(pModule, "PiRacerStandard"); // Get the Python class "PiRacerStandard" from the module
    pInstance = PyObject_CallObject(pClass, NULL); // Create an instance of the Python class

    gearMode = 0; // Initialize the gear mode to 0 (default)
}

PiracerClass::~PiracerClass()
{
    Py_DECREF(pArgs); // Release the Python arguments object
    Py_DECREF(pInstance); // Release the Python instance
    Py_DECREF(pClass); // Release the Python class
    Py_DECREF(pModule); // Release the Python module
    Py_Finalize(); // Finalize the Python interpreter to clean up resources
}

void PiracerClass::setGearMode(uint16_t _gearMode)
{
    gearMode = _gearMode; // Update the gear mode

    return;
}

uint16_t PiracerClass::getGearMode()
{
    return gearMode; // Retrieve and return the current gear mode
}

void PiracerClass::applyThrottle(double throttle)
{
    pArgs = PyTuple_Pack(1, PyFloat_FromDouble(throttle)); // Pack the throttle value as a Python tuple
    PyObject_CallMethod(pInstance, "set_throttle_percent", "O", pArgs); // Call the Python method "set_throttle_percent" with the throttle value

    return;
}

void PiracerClass::applySteering(double steering)
{
    pArgs = PyTuple_Pack(1, PyFloat_FromDouble(steering * -1.0)); // Pack the reversed steering value as a Python tuple
    PyObject_CallMethod(pInstance, "set_steering_percent", "O", pArgs); // Call the Python method "set_steering_percent" with the reversed steering value

    return;
}

PiracerClass piracer; // Create an instance of the PiracerClass, which initializes the Python interaction

