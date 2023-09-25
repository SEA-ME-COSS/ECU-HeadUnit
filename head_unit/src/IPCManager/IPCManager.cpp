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

        PiracerOperatorTargetProxy->setGearMode(3, callStatus, returnMessage);
        InstrumentClusterTargetProxy->setGear(3, callStatus, returnMessage);
        usleep(500000);
    }
    
    return 0;
}

