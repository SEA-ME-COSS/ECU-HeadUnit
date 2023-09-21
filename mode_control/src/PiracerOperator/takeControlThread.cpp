// Include header
#include "takeControlThread.hpp"


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
        pthread_mutex_lock(&piracerMutex);
    
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
        
        pthread_mutex_unlock(&piracerMutex);
    }

    return NULL;
}

