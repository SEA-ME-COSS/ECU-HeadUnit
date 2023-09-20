// Include header
#include "takeControlThread.hpp"
#include <iostream>


using namespace v1_0::commonapi;

void *takeControlThread(void *arg) {
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<PiracerOperatorStubImpl> PiracerOperatorService;
    
    runtime = CommonAPI::Runtime::get();
    PiracerOperatorService = std::make_shared<PiracerOperatorStubImpl>();
    runtime->registerService("local", "PiracerOperator", PiracerOperatorService);
    
    double throttle, steering;
    
    while (1)
    {
        controller.readControl();
        
        throttle = controller.getThrottle();
        steering = controller.getSteering();
        
        piracer.applyThrottle(throttle);
        piracer.applySteering(steering);
        
        std::cout << "hello world" << std::endl;
    }

    return NULL;
}

