// Include header
#include "takeControlThread.hpp"


using namespace v1_0::commonapi;

void *takeControlThread(void *arg) {
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<PiracerOperatorStubImpl> PiracerOperatorService;
    
    runtime = CommonAPI::Runtime::get();
    PiracerOperatorService = std::make_shared<PiracerOperatorStubImpl>();
    runtime->registerService("local", "PiracerOperator", PiracerOperatorService);
    
    while (1) {}

    return NULL;
}

