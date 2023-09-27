#include "HeadUnitStubImpl.hpp"


HeadUnitStubImpl::HeadUnitStubImpl() { }
HeadUnitStubImpl::~HeadUnitStubImpl() { }

void HeadUnitStubImpl::setSensorRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSensorRpmReply_t _reply)
{
    sensorRpm = _sensorRpm;

    _reply("");
    
    return;
}

