#include <string>
#include <unistd.h>

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>

#include "RemoteSpeakerStubImpl.hpp"
#include "DataBuffer.hpp"

using namespace v1_0::commonapi;

int main()
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

    IPCManagerTargetProxy->getGearMode("RemoteSpeaker", callStatus, returnMessage);

    bool enable_sound = false;
    int sleep_time = 0;

    while (1)
    {
        enable_sound = false;
    
        if (GearBuffer == 1)
        {
            enable_sound = true;
            
            if (DistanceBuffer < 20)
            {
                sleep_time = 330000;
            }
            else if (DistanceBuffer < 40)
            {
                sleep_time = 660000;
            }
            else if (DistanceBuffer < 60)
            {
                sleep_time = 1000000;
            }
            else
            {
                enable_sound = false;
            }
            
        }
        
        if (enable_sound)
        {
            std::cout << '\a' << std::endl;
            usleep(sleep_time);
        }
    }

    return 0;
}

