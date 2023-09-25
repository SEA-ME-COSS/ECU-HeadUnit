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

