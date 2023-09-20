#ifndef PIRACERCLASS_HPP
#define PIRACERCLASS_HPP


// Include necessary header
#include <stdint.h>

// Include python header
#include <Python.h>


enum gearState
{
    P,
    R,
    N,
    D
};


class PiracerClass
{
    private:
        PyObject *pModule, *pClass, *pInstance, *pVoltage, *pArgs;
        uint16_t gearMode;
        double voltageLevel;
        uint16_t batteryLevel;
        
    public:
        PiracerClass();
        void setGearMode(uint16_t _gearMode);
        uint16_t getGearMode();
        uint16_t getBatteryLevel();
        void applyThrottle(double throttle);
        void applySteering(double steering);
        ~PiracerClass();
};


class PiracerController
{
    private:
        PyObject *pModule, *pClass, *pInstance, *pInput, *pThrottle, *pSteering;
        double throttle;
        double steering;
        
    public:
        PiracerController();
        void readControl();
        double getThrottle();
        double getSteering();
        ~PiracerController();
};


extern PiracerClass piracer;
extern PiracerController controller;


#endif

