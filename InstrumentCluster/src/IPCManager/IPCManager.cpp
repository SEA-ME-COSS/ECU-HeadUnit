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

    std::cout << "Checking availability!" << std::endl;
    while (!targetProxy2->isAvailable())
        usleep(10);
    std::cout << "Available!" << std::endl;
    
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    
    uint16_t sensorRPM = 0;
    while (1)
    {
        targetProxy2->setSpeedRPM(sensorRPM, callStatus, returnMessage);
        sensorRPM += 10;
        if(sensorRPM == 150)
            sensorRPM = 0;
        usleep(500000);
    }
    
    return 0;
}

