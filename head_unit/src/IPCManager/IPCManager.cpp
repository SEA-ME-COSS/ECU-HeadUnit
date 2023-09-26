#include <string>
#include <unistd.h>
#include <v1/commonapi/PiracerOperatorProxy.hpp>
#include <v1/commonapi/InstrumentClusterProxy.hpp>
#include <v1/commonapi/HeadUnitProxy.hpp>

#include "IPCManagerStubImpl.hpp"
#include "IPCManagerData.hpp"


using namespace v1_0::commonapi;

int main()
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<IPCManagerStubImpl> IPCManagerService;
    std::shared_ptr<PiracerOperatorProxy<>> PiracerOperatorTargetProxy;
    std::shared_ptr<InstrumentClusterProxy<>> InstrumentClusterTargetProxy;
    std::shared_ptr<HeadUnitProxy<>> HeadUnitTargetProxy;
    
    runtime = CommonAPI::Runtime::get();
    IPCManagerService = std::make_shared<IPCManagerStubImpl>();
    runtime->registerService("local", "IPCManager", IPCManagerService);
    PiracerOperatorTargetProxy = runtime->buildProxy<PiracerOperatorProxy>("local", "PiracerOperator");
    InstrumentClusterTargetProxy = runtime->buildProxy<InstrumentClusterProxy>("local", "InstrumentCluster");
    HeadUnitTargetProxy = runtime->buildProxy<HeadUnitProxy>("local", "HeadUnit");
    
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    
    while (1)
    {
        pthread_mutex_lock(&IPCManagerDataMutex);
        if (setSensorRpmCalled)
        {
            InstrumentClusterTargetProxy->setSpeedRpm(sensorRpm, callStatus, returnMessage);
            HeadUnitTargetProxy->setSensorRpm(sensorRpm, callStatus, returnMessage);
            setSensorRpmCalled = false;
        }
        if (setBatteryLevelCalled)
        {
            InstrumentClusterTargetProxy->setBattery(batteryLevel, callStatus, returnMessage);
            setBatteryLevelCalled = false;
        }
        if (setGearModeCalled)
        {
            PiracerOperatorTargetProxy->setGearMode(gearMode, callStatus, returnMessage);
            InstrumentClusterTargetProxy->setGear(gearMode, callStatus, returnMessage);
            setGearModeCalled = false;
        }
        if (setDirectionCalled)
        {
            InstrumentClusterTargetProxy->setDirection(direction, callStatus, returnMessage);
            setDirectionCalled = false;
        }
        pthread_mutex_unlock(&IPCManagerDataMutex);
    }
    
    return 0;
}

