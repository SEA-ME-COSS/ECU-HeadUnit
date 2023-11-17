#include <string>
#include <unistd.h>

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>
#include <string>

#include "RemoteSpeakerStubImpl.hpp"
#include "DataBuffer.hpp"

using namespace v1_0::commonapi;

int main(int argc, char *argv[])
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<RemoteSpeakerStubImpl> RemoteSpeakerService;
    
    runtime = CommonAPI::Runtime::get();
    RemoteSpeakerService = std::make_shared<RemoteSpeakerStubImpl>();
    runtime->registerService("local", "RemoteSpeaker", RemoteSpeakerService);
    
    std::shared_ptr<IPCManagerProxy<>> IPCManagerTargetProxy;
    IPCManagerTargetProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    
    usleep(1000000);

    IPCManagerTargetProxy->getGearMode("RemoteSpeaker", callStatus, returnMessage);

    while (1)
    {
        if (GearBuffer == 1)
        {
            if (DistanceBuffer < 20)
            {
                std::cout << '\a' << std::endl;
                usleep(330000);
            }
            else if (DistanceBuffer < 40)
            {
                std::cout << '\a' << std::endl;
                usleep(660000);
            }
            else if (DistanceBuffer < 60)
            {
                std::cout << '\a' << std::endl;
                usleep(1000000);
            }  
        }
    }

    return 0;
}

