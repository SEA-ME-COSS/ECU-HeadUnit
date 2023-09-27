#include "IPCManagerStubImpl.hpp"
#include <iostream>


IPCManagerStubImpl::IPCManagerStubImpl() { }
IPCManagerStubImpl::~IPCManagerStubImpl() { }

int temp = 0;
int wait = 0;

void IPCManagerStubImpl::setSensorRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSensorRpmReply_t _reply)
{
    std::cout<<"sensorRpm: "<<_sensorRpm<<std::endl;
    sender.InstrumentClusterTargetProxy->setSpeedRpm(_sensorRpm, sender.callStatus, sender.returnMessage);
    sender.HeadUnitTargetProxy->setSensorRpm(_sensorRpm, sender.callStatus, sender.returnMessage);
    sender.PiracerOperatorTargetProxy->setGearMode(temp, sender.callStatus, sender.returnMessage);
    
    wait++;
    if (wait == 10)
    {
        temp++;
        wait = 0;
    }
    if (temp == 4)
        temp = 0;

    _reply("");

    return;
}

void IPCManagerStubImpl::setBatteryLevel(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _batteryLevel, setBatteryLevelReply_t _reply)
{
    std::cout<<"batteryLevel: "<<_batteryLevel<<std::endl;
    sender.InstrumentClusterTargetProxy->setBattery(_batteryLevel, sender.callStatus, sender.returnMessage);
    
    _reply("");

    return;
}

void IPCManagerStubImpl::setGearMode(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gearMode, setGearModeReply_t _reply)
{
    sender.PiracerOperatorTargetProxy->setGearMode(_gearMode, sender.callStatus, sender.returnMessage);
    sender.InstrumentClusterTargetProxy->setGear(_gearMode, sender.callStatus, sender.returnMessage);

    _reply("");

    return;
}

void IPCManagerStubImpl::setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _reply)
{
    sender.InstrumentClusterTargetProxy->setDirection(_direction, sender.callStatus, sender.returnMessage);

    _reply("");

    return;
}

