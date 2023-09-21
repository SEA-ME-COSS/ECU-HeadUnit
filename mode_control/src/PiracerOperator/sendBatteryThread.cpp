// Include header
#include "sendBatteryThread.hpp"


using namespace v1_0::commonapi;

void *sendBatteryThread(void *arg)
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
        pthread_mutex_lock(&piracer);
	targetPoxy->setBatteryLevel(piracer.getBatteryLevel(), callStatus, returnMessage);
	pthread_mutex_unlock(&piracer);
	
        usleep(500000);
    }

    return NULL;
}

