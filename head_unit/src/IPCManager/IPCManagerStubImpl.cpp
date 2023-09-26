#include "IPCManagerStubImpl.hpp"


IPCManagerStubImpl::IPCManagerStubImpl() { }
IPCManagerStubImpl::~IPCManagerStubImpl() { }

void IPCManagerStubImpl::setSensorRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSensorRpmReply_t _reply)
{
    std::cout << "********************" << std::endl;
    std::cout << "Sensor Rpm: " << _sensorRpm << std::endl;
    std::cout << "********************" << std::endl;

    pthread_mutex_lock(&IPCManagerDataMutex);
    sensorRpm = _sensorRpm;
    setSensorRpmCalled = true;
    pthread_mutex_unlock(&IPCManagerDataMutex);

    _reply(":)");

    return;
}

void IPCManagerStubImpl::setBatteryLevel(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _batteryLevel, setBatteryLevelReply_t _reply)
{
    std::cout << "********************" << std::endl;
    std::cout << "Battery Level: " << _batteryLevel << std::endl;
    std::cout << "********************" << std::endl;

    pthread_mutex_lock(&IPCManagerDataMutex);
    batteryLevel = _batteryLevel;
    setBatteryLevelCalled = true;
    pthread_mutex_unlock(&IPCManagerDataMutex);

    _reply(":)");

    return;
}

void IPCManagerStubImpl::setGearMode(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gearMode, setGearModeReply_t _reply)
{
    std::cout << "********************" << std::endl;
    std::cout << "Gear Mode: " << _gearMode << std::endl;
    std::cout << "********************" << std::endl;

    pthread_mutex_lock(&IPCManagerDataMutex);
    gearMode = _gearMode;
    setGearModeCalled = true;
    pthread_mutex_unlock(&IPCManagerDataMutex);

    _reply(":)");

    return;
}

void IPCManagerStubImpl::setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _reply)
{
    std::cout << "********************" << std::endl;
    std::cout << "Direction: " << _direction << std::endl;
    std::cout << "********************" << std::endl;

    pthread_mutex_lock(&IPCManagerDataMutex);
    direction = _direction;
    setDirectionCalled = true;
    pthread_mutex_unlock(&IPCManagerDataMutex);

    _reply(":)");

    return;
}

