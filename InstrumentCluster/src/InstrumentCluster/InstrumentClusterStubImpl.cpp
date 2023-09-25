#include "InstrumentClusterStubImpl.hpp"
#include <iostream>

InstrumentClusterStubImpl::InstrumentClusterStubImpl() { }
InstrumentClusterStubImpl::~InstrumentClusterStubImpl() { }

void InstrumentClusterStubImpl::setSpeedRPM(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRPM, setSpeedRPMReply_t _reply) {
    pthread_mutex_lock(&CarInformationMutex);
    rpm = (uint16_t)((float)_sensorRPM / 2.6);
    speed = (uint16_t)((float)rpm * 3.4);
    pthread_mutex_unlock(&CarInformationMutex);
    
    std::cout<<rpm<<' '<<speed<<std::endl;
    _reply(":)");
};

void InstrumentClusterStubImpl::setBattery(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _battery, setBatteryReply_t _reply) {
    pthread_mutex_lock(&CarInformationMutex);
    battery = _battery;
    pthread_mutex_unlock(&CarInformationMutex);

    _reply(":)");
};    
    
void InstrumentClusterStubImpl::setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _reply) {
    pthread_mutex_lock(&CarInformationMutex);
    gear = _gear;
    pthread_mutex_unlock(&CarInformationMutex);
    
    _reply(":)");
};
    
void InstrumentClusterStubImpl::setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _reply) {
    pthread_mutex_lock(&CarInformationMutex);
    direction = _direction;
    pthread_mutex_unlock(&CarInformationMutex);

    _reply(":)");
};

