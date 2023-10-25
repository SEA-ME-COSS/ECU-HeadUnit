#ifndef PIRACERCLASS_HPP
#define PIRACERCLASS_HPP

#include <stdint.h>
#include <Python.h>

// Define the PiracerClass class
class PiracerClass
{
    private:
        PyObject *pModule, *pClass, *pInstance; // Private Python objects and gearMode variable

        uint16_t gearMode; // Private member variable to store gear mode
        
    public:
        PiracerClass(); // Constructor for PiracerClass
        ~PiracerClass(); // Destructor for PiracerClass

        // Method to set the gear mode
        void setGearMode(uint16_t _gearMode);
        
        // Method to apply throttle to the PiRacer vehicle
        void applyThrottle(double throttle);
        
        // Method to apply steering to the PiRacer vehicle
        void applySteering(double steering);
};

#endif

