#include "IPCManagerStubImpl.hpp"


using namespace std;

int main() {
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::shared_ptr<IPCManagerStubImpl> myService = std::make_shared<IPCManagerStubImpl>();
    runtime->registerService("local", "IPCManager", myService);

    while (true) {}
    
    return 0;
}

