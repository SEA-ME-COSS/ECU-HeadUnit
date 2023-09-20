#include "PiracerOperatorStubImpl.hpp"


char gearName[4] = {'P', 'R', 'N', 'D'};


PiracerOperatorStubImpl::PiracerOperatorStubImpl() { }
PiracerOperatorStubImpl::~PiracerOperatorStubImpl() { }

void PiracerOperatorStubImpl::setGearMode(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gearMode, setGearModeReply_t _reply) {
		std::cout << "********************" << std::endl;
		std::cout << "Gear Mode: " << gearName[_gearMode] << std::endl;
		std::cout << "********************" << std::endl;

		piracer.setGearMode(_gearMode);

		_reply(":)");
};

