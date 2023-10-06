#include "IPCManagerSenderClass.hpp"


using namespace v1_0::commonapi;

IPCManagerSenderClass::IPCManagerSenderClass()
{
    runtime = CommonAPI::Runtime::get();
    CANSenderTargetProxy = runtime->buildProxy<CANSenderProxy>("local", "CANSender");
    PiracerOperatorTargetProxy = runtime->buildProxy<PiracerOperatorProxy>("local", "PiracerOperator");
    InstrumentClusterTargetProxy = runtime->buildProxy<InstrumentClusterProxy>("local", "InstrumentCluster");
    HeadUnitTargetProxy = runtime->buildProxy<HeadUnitProxy>("local", "HeadUnit");
}
 
IPCManagerSenderClass::~IPCManagerSenderClass() { }

