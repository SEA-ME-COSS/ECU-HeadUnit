#include "IPCManagerStubImpl.hpp"

// Constructor for IPCManagerStubImpl
IPCManagerStubImpl::IPCManagerStubImpl() { }

// Destructor for IPCManagerStubImpl
IPCManagerStubImpl::~IPCManagerStubImpl() { }

// Set sensor RPM and relay it to appropriate services
void IPCManagerStubImpl::setSensorRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSensorRpmReply_t _reply)
{
    // Relay sensor RPM to InstrumentCluster and HeadUnit services
    sender.InstrumentClusterTargetProxy->setSpeedRpm(_sensorRpm, sender.callStatus, sender.returnMessage);
    sender.HeadUnitTargetProxy->setSensorRpm(_sensorRpm, sender.callStatus, sender.returnMessage);

    // Reply to the caller
    _reply("");

    return;
}

// Set battery level and relay it to the InstrumentCluster service
void IPCManagerStubImpl::setBatteryLevel(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _batteryLevel, setBatteryLevelReply_t _reply)
{
    // Relay battery level to the InstrumentCluster service
    sender.InstrumentClusterTargetProxy->setBattery(_batteryLevel, sender.callStatus, sender.returnMessage);
    
    // Reply to the caller
    _reply("");

    return;
}

// Set gear mode and relay it to the PiracerOperator and InstrumentCluster services
void IPCManagerStubImpl::setGearMode(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gearMode, setGearModeReply_t _reply)
{
    // Relay gear mode to the PiracerOperator and InstrumentCluster services
    sender.PiracerOperatorTargetProxy->setGearMode(_gearMode, sender.callStatus, sender.returnMessage);
    sender.InstrumentClusterTargetProxy->setGear(_gearMode, sender.callStatus, sender.returnMessage);

    // Reply to the caller
    _reply("");

    return;
}

// Set direction and relay it to the InstrumentCluster service
void IPCManagerStubImpl::setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _reply)
{
    // Relay direction to the InstrumentCluster service
    sender.InstrumentClusterTargetProxy->setDirection(_direction, sender.callStatus, sender.returnMessage);

    // Reply to the caller
    _reply("");

    return;
}

// Set light status and relay it to the InstrumentCluster service
void IPCManagerStubImpl::setLight(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _light, setLightReply_t _reply)
{
    // Relay light status to the InstrumentCluster service
    sender.InstrumentClusterTargetProxy->setLight(_light, sender.callStatus, sender.returnMessage);

    // Reply to the caller
    _reply("");

    return;
}

// Set steering and relay it to the HeadUnit service
void IPCManagerStubImpl::setSteering(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _steering, setSteeringReply_t _reply)
{
    // Relay steering to the HeadUnit service
    sender.HeadUnitTargetProxy->setSteering(_steering, sender.callStatus, sender.returnMessage);

    // Reply to the caller
    _reply("");

    return;
}

