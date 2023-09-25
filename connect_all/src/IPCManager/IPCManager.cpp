// Include necessary header
#include <iostream>
#include <string>
#include <unistd.h>
#include <v1/commonapi/PiracerOperatorProxy.hpp>
#include <v1/commonapi/InstrumentClusterProxy.hpp>

// Include IPC manager service header
#include "IPCManagerStubImpl.hpp"


using namespace v1_0::commonapi;

int main(int argc, char *argv[]) {
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<IPCManagerStubImpl> IPCManagerService;
    std::shared_ptr<PiracerOperatorProxy<>> targetProxy1;
    std::shared_ptr<InstrumentClusterProxy<>> targetProxy2;
    
    runtime = CommonAPI::Runtime::get();
    IPCManagerService = std::make_shared<IPCManagerStubImpl>();
    runtime->registerService("local", "IPCManager", IPCManagerService);
    targetProxy1 = runtime->buildProxy<PiracerOperatorProxy>("local", "PiracerOperator");
    targetProxy2 = runtime->buildProxy<InstrumentClusterProxy>("local", "InstrumentCluster");
    
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    
    uint16_t sensorRPM = 0;
    uint16_t gear = 0;
    while (1)
    {
        targetProxy1->setGearMode(gear, callStatus, returnMessage);
        gear++;
        if(gear == 4)
            gear = 0;
        usleep(5000000);
    }
    
    return 0;
}

