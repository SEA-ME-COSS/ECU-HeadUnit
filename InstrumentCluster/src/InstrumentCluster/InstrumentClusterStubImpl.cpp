#include "InstrumentClusterStubImpl.hpp"


InstrumentClusterStubImpl::InstrumentClusterStubImpl() {
    speed = 0;
    rpm = 0;
    battery = 0;
    gear = 0;
    direction = 0;
}
InstrumentClusterStubImpl::~InstrumentClusterStubImpl() { }

void InstrumentClusterStubImpl::setSpeedRPM(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRPM, setSpeedRPMReply_t _reply) {
    rpm = (uint16_t)((float)_sensorRPM / 2.6);
    speed = (uint16_t)((float)rpm * 3.4);

    _reply(":)");
};

void InstrumentClusterStubImpl::setBattery(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _battery, setBatteryReply_t _reply) {
    battery = _battery;

    _reply(":)");
};    
    
void InstrumentClusterStubImpl::setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _reply) {
    gear = _gear;

    _reply(":)");
};
    
void InstrumentClusterStubImpl::setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _reply) {
    direction = _direction;

    _reply(":)");
};


uint16_t InstrumentClusterStubImpl::getSpeed() {
    return speed;
}

uint16_t InstrumentClusterStubImpl::getRPM() {
    return rpm;
}

uint16_t InstrumentClusterStubImpl::getBattery() {
    return battery;
}

uint16_t InstrumentClusterStubImpl::getGear() {
    return gear;
}

uint16_t InstrumentClusterStubImpl::getDirection() {
    return direction;
}

