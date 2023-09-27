#include "IPCManagerSenderClass.hpp"


using namespace v1_0::commonapi;

IPCManagerSenderClass::IPCManagerSenderClass()
{
    runtime = CommonAPI::Runtime::get();
    PiracerOperatorTargetProxy = runtime->buildProxy<PiracerOperatorProxy>("local", "PiracerOperator");
    InstrumentClusterTargetProxy = runtime->buildProxy<InstrumentClusterProxy>("local", "InstrumentCluster");
    HeadUnitTargetProxy = runtime->buildProxy<HeadUnitProxy>("local", "HeadUnit");
}
 
IPCManagerSenderClass::~IPCManagerSenderClass() { }

