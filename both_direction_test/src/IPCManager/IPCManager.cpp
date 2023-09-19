// Include necessary header
#include <iostream>
#include <string>
#include <unistd.h>
#include <v1/commonapi/PiracerOperatorProxy.hpp>

// Include IPC manager service header
#include "IPCManagerStubImpl.hpp"


using namespace v1_0::commonapi;

int main() {
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::shared_ptr<PiracerOperatorProxy<>> myProxy = runtime->buildProxy<PiracerOperatorProxy>("local", "PiracerOperator");
    std::shared_ptr<IPCManagerStubImpl> IPCManager = std::make_shared<IPCManagerStubImpl>();
    runtime->registerService("local", "IPCManager", IPCManager);

    std::cout << "Checking availability!" << std::endl;
    while (!myProxy->isAvailable())
        usleep(10);
    std::cout << "Available!" << std::endl;
    
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    
    while (1)
    {
	myProxy->setGearMode(6974, callStatus, returnMessage);
        usleep(500000);
    }
    
    return 0;
}

