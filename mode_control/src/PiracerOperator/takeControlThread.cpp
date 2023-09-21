// Include header
#include "takeControlThread.hpp"


enum gearName
{
    P = 0;
    R = 1;
    N = 2;
    D = 3;
};


using namespace v1_0::commonapi;

void *takeControlThread(void *arg) {
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
            case P:
                piracer.applyThrottle(0.0);
                piracer.applySteering(0.0);
                break;
                
            case R:
                if (throttle <= 0)
                    piracer.applyThrottle(throttle);
                    piracer.applySteering(steering);
                else
                    piracer.applyThrottle(0.0);
                    piracer.applySteering(steering);
                break;
                
            case N:
                piracer.applyThrottle(0.0);
                piracer.applySteering(steering);
                break;
                
            case D:
                if (throttle >= 0)
                    piracer.applyThrottle(throttle);
                    piracer.applySteering(steering);
                else
                    piracer.applyThrottle(0.0);
                    piracer.applySteering(steering);
                break;
        }
    }

    return NULL;
}

