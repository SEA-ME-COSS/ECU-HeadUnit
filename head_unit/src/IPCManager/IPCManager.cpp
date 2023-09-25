#include <string>
#include <unistd.h>
#include <v1/commonapi/PiracerOperatorProxy.hpp>
#include <v1/commonapi/InstrumentClusterProxy.hpp>

#include "IPCManagerStubImpl.hpp"
#include "IPCManagerData.hpp"


using namespace v1_0::commonapi;

int main()
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<IPCManagerStubImpl> IPCManagerService;
    std::shared_ptr<PiracerOperatorProxy<>> PiracerOperatorTargetProxy;
    std::shared_ptr<InstrumentClusterProxy<>> InstrumentClusterTargetProxy;
    
    runtime = CommonAPI::Runtime::get();
    IPCManagerService = std::make_shared<IPCManagerStubImpl>();
    runtime->registerService("local", "IPCManager", IPCManagerService);
    PiracerOperatorTargetProxy = runtime->buildProxy<PiracerOperatorProxy>("local", "PiracerOperator");
    InstrumentClusterTargetProxy = runtime->buildProxy<InstrumentClusterProxy>("local", "InstrumentCluster");
    
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    
    uint16_t temp = 0;
    int wait = 0;
    
    while (1)
    {
        pthread_mutex_lock(&IPCManagerDataMutex);
        if (setSensorRpmCalled)
        {
            InstrumentClusterTargetProxy->setSpeedRpm(sensorRpm, callStatus, returnMessage);
            setSensorRpmCalled = false;
        }
        if (setBatteryLevelCalled)
        {
            InstrumentClusterTargetProxy->setBattery(batteryLevel, callStatus, returnMessage);
            setBatteryLevelCalled = false;
        }
        pthread_mutex_unlock(&IPCManagerDataMutex);

        PiracerOperatorTargetProxy->setGearMode(temp, callStatus, returnMessage);
        InstrumentClusterTargetProxy->setGear(temp, callStatus, returnMessage);
        wait++;
        if (wait == 4)
        {
            temp++;
            wait = 0;
        }
        if (temp == 4)
            temp = 0;
        usleep(500000);
    }
    
    return 0;
}

