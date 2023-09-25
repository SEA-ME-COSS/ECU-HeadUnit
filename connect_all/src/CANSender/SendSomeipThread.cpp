#include "SendSomeipThread.hpp"


using namespace v1_0::commonapi;

void *SendSomeipThread(void *arg)
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<IPCManagerProxy<>> IPCManagertargetProxy;
    
    runtime = CommonAPI::Runtime::get();
    IPCManagertargetProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");
    
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    
    while (1)
    {
        pthread_mutex_lock(&CANBufferMutex);
        int currentIndex = CANBufferIndex - 1;
        if (currentIndex < 0)
        {
            currentIndex = CANBuffer_SIZE - 1;
        }
        uint16_t speed_sensor_rpm = CANBuffer[currentIndex];
        pthread_mutex_unlock(&CANBufferMutex);
        
        uint16_t kf_speed_sensor_rpm = filter(speed_sensor_rpm);
	IPCManagertargetProxy->setSensorRpm(kf_speed_sensor_rpm, callStatus, returnMessage);
        usleep(500000);
    }
    
    return NULL;
}

