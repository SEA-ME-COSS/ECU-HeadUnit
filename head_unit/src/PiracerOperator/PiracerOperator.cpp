#include "ControllerClass.hpp"
#include "PiracerClass.hpp"
#include "PiracerOperatorStubImpl.hpp"


using namespace v1_0::commonapi;

int main ()
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<PiracerOperatorStubImpl> PiracerOperatorService;
    
    runtime = CommonAPI::Runtime::get();
    PiracerOperatorService = std::make_shared<PiracerOperatorStubImpl>();
    runtime->registerService("local", "PiracerOperator", PiracerOperatorService);
    
    ControllerClass controller;
    
    double throttle, steering;
    
    while (1)
    {
        controller.readControl();
        throttle = controller.getThrottle();
        steering = controller.getSteering();

        switch (piracer.getGearMode())
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

    return 0;
}

