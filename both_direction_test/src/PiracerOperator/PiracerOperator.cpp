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
    
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::shared_ptr<IPCManagerProxy<>> myProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");
    std::shared_ptr<PiracerOperatorStubImpl> PiracerOperator = std::make_shared<PiracerOperatorStubImpl>();
    runtime->registerService("local", "PiracerOperator", PiracerOperator);
    
    std::cout << "Checking availability!" << std::endl;
    while (!myProxy->isAvailable())
        usleep(10);
    std::cout << "Available!" << std::endl;
    
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    
    while (1)
    {
	myProxy->setBatteryLevel(piracer.getBatteryLevel(), callStatus, returnMessage);
        usleep(500000);
    }

    return 0;
}

