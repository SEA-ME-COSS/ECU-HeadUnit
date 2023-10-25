#include <CommonAPI/CommonAPI.hpp>

#include "PiracerOperatorStubImpl.hpp"

using namespace v1_0::commonapi;

int main()
{
    // Initialize the CommonAPI runtime
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<PiracerOperatorStubImpl> PiracerOperatorService;

    runtime = CommonAPI::Runtime::get();

    // Create the Piracer Operator service
    PiracerOperatorService = std::make_shared<PiracerOperatorStubImpl>();
    runtime->registerService("local", "PiracerOperator", PiracerOperatorService);

    while (1) {}

    return 0;
}

