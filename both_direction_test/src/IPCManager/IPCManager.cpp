// Include necessary header
#include <iostream>
#include <string>
#include <unistd.h>
#include <v1/commonapi/PiracerOperatorProxy.hpp>

// Include IPC manager service header
#include "IPCManagerStubImpl.hpp"


using namespace v1_0::commonapi;

int main() {
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<IPCManagerStubImpl> IPCManagerService;
    std::shared_ptr<PiracerOperatorProxy<>> targetProxy;
    
    runtime = CommonAPI::Runtime::get();
    IPCManagerService = std::make_shared<IPCManagerStubImpl>();
    runtime->registerService("local", "IPCManager", IPCManagerService);
    targetProxy = runtime->buildProxy<PiracerOperatorProxy>("local", "PiracerOperator");


    std::cout << "Checking availability!" << std::endl;
    while (!targetProxy->isAvailable())
        usleep(10);
    std::cout << "Available!" << std::endl;
    
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    
    while (1)
    {
	targetProxy->setGearMode(69, callStatus, returnMessage);
        usleep(500000);
    }
    
    return 0;
}

