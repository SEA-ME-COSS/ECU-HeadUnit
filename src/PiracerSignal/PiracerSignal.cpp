#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HeadUnitProxy.hpp>

#include "ControllerClass.hpp"
#include "PiracerSignalStubImpl.hpp"

using namespace v1_0::commonapi;

int main()
{
    // Initialize the CommonAPI runtime
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<PiracerSignalStubImpl> PiracerSignalService;
    std::shared_ptr<HeadUnitProxy<>> HeadUnittargetProxy;

    runtime = CommonAPI::Runtime::get();

    // Create the Piracer Controller service
    PiracerSignalService = std::make_shared<PiracerSignalStubImpl>();
    runtime->registerService("local", "PiracerSignal", PiracerSignalService);
    HeadUnittargetProxy = runtime->buildProxy<HeadUnitProxy>("local", "HeadUnit");

    // Initialize the controller class for interacting with the game controller
    ControllerClass controller;

    CommonAPI::CallStatus callStatus;
    std::string returnMessage;

    while (1)
    {
        // Read control input from the game controller
        controller.readControl();

	// Send control data to HeadUnit
	HeadUnittargetProxy->setTurnSignal(controller.getSteering(), callStatus, returnMessage);
    }

    return 0;
}

