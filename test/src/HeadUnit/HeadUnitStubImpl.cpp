#include "HeadUnitStubImpl.hpp"


HeadUnitStubImpl::HeadUnitStubImpl() { }
HeadUnitStubImpl::~HeadUnitStubImpl() { }

void HeadUnitStubImpl::setSensorRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSensorRpmReply_t _reply)
{
    std::cout << "********************" << std::endl;
    std::cout << "Sensor Rpm: " << _sensorRpm << std::endl;
    std::cout << "********************" << std::endl;

    pthread_mutex_lock(&HeadUnitDataMutex);
    sensorRpm = _sensorRpm;
    pthread_mutex_unlock(&HeadUnitDataMutex);

    _reply(":)");
    
    return;
}

