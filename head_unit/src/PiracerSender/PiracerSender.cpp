#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>

#include "PiracerClass.hpp"


using namespace v1_0::commonapi;

int main ()
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<IPCManagerProxy<>> IPCManagerTargetProxy;
    
    runtime = CommonAPI::Runtime::get();
    IPCManagerTargetProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");
    
    PiracerClass piracer;
    
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    
    while (1)
    {
	IPCManagerTargetProxy->setBatteryLevel(piracer.getBatteryLevel(), callStatus, returnMessage);
        usleep(500000);
    }

    return 0;
}

