#include <CommonAPI/CommonAPI.hpp>

#include "IPCManagerStubImpl.hpp"


using namespace v1_0::commonapi;

int main()
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<IPCManagerStubImpl> IPCManagerService;
    
    runtime = CommonAPI::Runtime::get();
    IPCManagerService = std::make_shared<IPCManagerStubImpl>();
    runtime->registerService("local", "IPCManager", IPCManagerService);
    
    while (1) { }
    
    return 0;
}

