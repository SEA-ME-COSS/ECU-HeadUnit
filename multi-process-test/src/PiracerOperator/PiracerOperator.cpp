// Include necessary header
#include <iostream>
#include <string>
#include <unistd.h>

// Include controller class header
#include "ControllerClass.hpp"

// Include piracer operator service header
#include "PiracerOperatorStubImpl.hpp"


using namespace v1_0::commonapi;

int main (int argc, char **argv)
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<PiracerOperatorStubImpl> PiracerOperatorService;
    
    runtime = CommonAPI::Runtime::get();
    PiracerOperatorService = std::make_shared<PiracerOperatorStubImpl>();
    runtime->registerService("local", "PiracerOperator", PiracerOperatorService);
    
    double throttle, steering;
    uint16_t gearMode;
    
    while (1)
    {
        controller.readControl();
        throttle = controller.getThrottle();
        steering = controller.getSteering();

        gearMode = piracer.getGearMode();
        switch (gearMode)
        {
            case 0:    // P
                piracer.applyThrottle(0.0);
                piracer.applySteering(0.0);
                break;
                
            case 1:    // R
                if (throttle <= 0)
                {
                    piracer.applyThrottle(throttle);
                    piracer.applySteering(steering);
                }
                else
                {
                    piracer.applyThrottle(0.0);
                    piracer.applySteering(steering);
                }
                break;
                
            case 2:    // N
                piracer.applyThrottle(0.0);
                piracer.applySteering(steering);
                break;
                
            case 3:    // D
                if (throttle >= 0)
                {
                    piracer.applyThrottle(throttle);
                    piracer.applySteering(steering);
                }
                else
                {
                    piracer.applyThrottle(0.0);
                    piracer.applySteering(steering);
                }
                break;
        }
    }

    return;
}

