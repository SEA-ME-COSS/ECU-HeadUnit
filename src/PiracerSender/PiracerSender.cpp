#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>

#include "PiracerSenderStubImpl.hpp"
#include "PiracerClass.hpp"

using namespace v1_0::commonapi;

int main()
{
    // Create a CommonAPI runtime instance
    std::shared_ptr<CommonAPI::Runtime> runtime;
    runtime = CommonAPI::Runtime::get();

    // Create a PiracerSenderStubImpl service
    std::shared_ptr<PiracerSenderStubImpl> PiracerSenderService = std::make_shared<PiracerSenderStubImpl>();

    // Register the service with CommonAPI
    runtime->registerService("local", "PiracerSender", PiracerSenderService);

    // Create an IPCManagerProxy for communication with IPCManager
    std::shared_ptr<IPCManagerProxy<>> IPCManagerTargetProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");

    // Create a PiracerClass instance for battery level retrieval
    PiracerClass piracer;

    // Set up variables for CommonAPI call status and return messages
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;

    // Enter an infinite loop for continuous operation
    while (1)
    {
        // Use the IPCManager proxy to call the setBatteryLevel method and send the battery level to the IPCManager
        IPCManagerTargetProxy->setBatteryLevel(piracer.getBatteryLevel(), callStatus, returnMessage);

        // Sleep for 500,000 microseconds (500 ms) before the next iteration
        usleep(500000);
    }

    return 0;
}

