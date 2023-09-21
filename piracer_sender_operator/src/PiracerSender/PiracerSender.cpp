// Include necessary header
#include <iostream>
#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>

// Include piracer class header
#include "PiracerClass.hpp"


using namespace v1_0::commonapi;

int main (int argc, char **argv)
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<IPCManagerProxy<>> targetPoxy;
    
    runtime = CommonAPI::Runtime::get();
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

