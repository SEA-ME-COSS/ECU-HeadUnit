#include "ManagerStubImpl.hpp"


using namespace std;

int main() {
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::shared_ptr<ManagerStubImpl> myService = std::make_shared<ManagerStubImpl>();
    runtime->registerService("local", "seame", myService);

    while (true) {}
    
    return 0;
}

