// Include necessary header
#include <iostream>
#include <string>
#include <unistd.h>
#include <v1/commonapi/IPCManagerProxy.hpp>

// Include piracer class header
#include "PiracerClass.hpp"

// Include piracer operator service header
#include "PiracerOperatorStubImpl.hpp"


using namespace v1_0::commonapi;

int main(int argc, char *argv[]) {
    PiracerClass piracer;
    
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<PiracerOperatorStubImpl> PiracerOperatorService;
    std::shared_ptr<IPCManagerProxy<>> targetPoxy;
    
    runtime = CommonAPI::Runtime::get();
    PiracerOperatorService = std::make_shared<PiracerOperatorStubImpl>();
    runtime->registerService("local", "PiracerOperator", PiracerOperatorService);
    targetPoxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");
    
    
    std::cout << "Checking availability!" << std::endl;
    while (!targetPoxy->isAvailable())
        usleep(10);
    std::cout << "Available!" << std::endl;
    
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    
    while (1)
    {
	targetPoxy->setBatteryLevel(piracer.getBatteryLevel(), callStatus, returnMessage);
        usleep(500000);
    }

    return 0;
}

