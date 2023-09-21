#include "PiracerOperatorStubImpl.hpp"


char gearName[] = "PRND";


PiracerOperatorStubImpl::PiracerOperatorStubImpl() { }
PiracerOperatorStubImpl::~PiracerOperatorStubImpl() { }

void PiracerOperatorStubImpl::setGearMode(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gearMode, setGearModeReply_t _reply) {
		std::cout << "********************" << std::endl;
		std::cout << "Gear Mode: " << gearName[_gearMode] << std::endl;
		std::cout << "********************" << std::endl;

                pthread_mutex_lock(&piracerMutex);
		piracer.setGearMode(_gearMode);
		pthread_mutex_unlock(&piracerMutex);

		_reply(":)");
};

