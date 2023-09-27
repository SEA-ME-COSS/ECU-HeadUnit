#include "InstrumentClusterStubImpl.hpp"


InstrumentClusterStubImpl::InstrumentClusterStubImpl() { }
InstrumentClusterStubImpl::~InstrumentClusterStubImpl() { }

void InstrumentClusterStubImpl::setSpeedRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSpeedRpmReply_t _reply)
{
    rpm = (uint16_t)((float)_sensorRpm / 2.6);
    speed = (uint16_t)((float)rpm * 3.4);

    _reply("");
    
    return;
}

void InstrumentClusterStubImpl::setBattery(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _battery, setBatteryReply_t _reply)
{
    battery = _battery;

    _reply("");
    
    return;
} 
    
void InstrumentClusterStubImpl::setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _reply)
{
    gear = _gear;
    
    _reply("");
    
    return;
}
    
void InstrumentClusterStubImpl::setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _reply)
{
    direction = _direction;

    _reply("");
    
    return;
}

