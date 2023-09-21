// Include necessary header
#include <iostream>
#include <string>
#include <unistd.h>
#include <v1/commonapi/PiracerOperatorProxy.hpp>

// Include IPC manager service header
#include "IPCManagerStubImpl.hpp"


using namespace v1_0::commonapi;

int main(int argc, char *argv[]) {
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
    
    uint16_t gear = 0;
    while (1)
    {
	targetProxy->setGearMode(gear, callStatus, returnMessage);
        gear++;
        if(gear == 4)
            gear = 0;
        usleep(10000000);
    }
    
    return 0;
}

