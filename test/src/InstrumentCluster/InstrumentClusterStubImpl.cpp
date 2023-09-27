#include "InstrumentClusterStubImpl.hpp"


InstrumentClusterStubImpl::InstrumentClusterStubImpl() { }
InstrumentClusterStubImpl::~InstrumentClusterStubImpl() { }

void InstrumentClusterStubImpl::setSpeedRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSpeedRpmReply_t _reply)
{
    pthread_mutex_lock(&InstrumentClusterDataMutex);
    rpm = (uint16_t)((float)_sensorRpm / 2.6);
    speed = (uint16_t)((float)rpm * 3.4);
    pthread_mutex_unlock(&InstrumentClusterDataMutex);

    _reply(":)");
    
    return;
}

void InstrumentClusterStubImpl::setBattery(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _battery, setBatteryReply_t _reply)
{
    pthread_mutex_lock(&InstrumentClusterDataMutex);
    battery = _battery;
    pthread_mutex_unlock(&InstrumentClusterDataMutex);

    _reply(":)");
    
    return;
} 
    
void InstrumentClusterStubImpl::setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _reply)
{
    pthread_mutex_lock(&InstrumentClusterDataMutex);
    gear = _gear;
    pthread_mutex_unlock(&InstrumentClusterDataMutex);
    
    _reply(":)");
    
    return;
}
    
void InstrumentClusterStubImpl::setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _reply)
{
    pthread_mutex_lock(&InstrumentClusterDataMutex);
    direction = _direction;
    pthread_mutex_unlock(&InstrumentClusterDataMutex);

    _reply(":)");
    
    return;
}

