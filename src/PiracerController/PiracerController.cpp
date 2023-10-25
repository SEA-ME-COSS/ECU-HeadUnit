#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>

#include "ControllerClass.hpp"
#include "PiracerControllerStubImpl.hpp"

using namespace v1_0::commonapi;

int main()
{
    // Initialize the CommonAPI runtime
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<PiracerControllerStubImpl> PiracerControllerService;
    std::shared_ptr<IPCManagerProxy<>> IPCManagertargetProxy;

    runtime = CommonAPI::Runtime::get();

    // Create the Piracer Controller service
    PiracerControllerService = std::make_shared<PiracerControllerStubImpl>();
    runtime->registerService("local", "PiracerController", PiracerControllerService);
    IPCManagertargetProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");

    // Initialize the controller class for interacting with the game controller
    ControllerClass controller;

    CommonAPI::CallStatus callStatus;
    std::string returnMessage;

    while (1)
    {
        // Read control input from the game controller
        controller.readControl();

	// Send control data to IPCManager
        IPCManagertargetProxy->setThrottle(controller.getThrottle(), callStatus, returnMessage);
	IPCManagertargetProxy->setSteering(controller.getSteering(), callStatus, returnMessage);
    }

    return 0;
}

