#include "SendSomeipThread.hpp"


using namespace v1_0::commonapi;

void *SendSomeipThread(void *arg)
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<CANSenderStubImpl> CANSenderService;
    std::shared_ptr<IPCManagerProxy<>> IPCManagertargetProxy;
    
    runtime = CommonAPI::Runtime::get();
    CANSenderService = std::make_shared<CANSenderStubImpl>();
    runtime->registerService("local", "CANSender", CANSenderService);
    IPCManagertargetProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");
    
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    
    uint16_t temp = 0;
    
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
	//IPCManagertargetProxy->setSensorRpm(kf_speed_sensor_rpm, callStatus, returnMessage);
	IPCManagertargetProxy->setSensorRpm(temp, callStatus, returnMessage);
	temp += 100;
	if (temp == 200)
	    temp = 0;
        usleep(5000000);
    }
    
    return NULL;
}

