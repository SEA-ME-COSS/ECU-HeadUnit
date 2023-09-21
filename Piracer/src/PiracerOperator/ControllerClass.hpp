#ifndef CONTROLLERCLASS_HPP
#define CONTROLLERCLASS_HPP


// Include python header
#include <Python.h>


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


extern PiracerController controller;


#endif

