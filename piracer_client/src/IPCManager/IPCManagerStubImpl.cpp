#include "IPCManagerStubImpl.hpp"


IPCManagerStubImpl::IPCManagerStubImpl() { }
IPCManagerStubImpl::~IPCManagerStubImpl() { }

void IPCManagerStubImpl::setSensorRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSensorRpmReply_t _reply) {
		std::cout << "********************" << std::endl;
		std::cout << "Sensor Rpm: " << _sensorRpm << std::endl;
		std::cout << "********************" << std::endl;

		_reply(":)");
};

void IPCManagerStubImpl::setBatteryLevel(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _batteryLevel, setBatteryLevelReply_t _reply) {
		std::cout << "********************" << std::endl;
		std::cout << "Battery Level: " << _batteryLevel << std::endl;
		std::cout << "********************" << std::endl;

		_reply(":)");
};
