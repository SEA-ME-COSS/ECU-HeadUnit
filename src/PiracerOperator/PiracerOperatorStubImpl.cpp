#include "PiracerOperatorStubImpl.hpp"

// Constructor
PiracerOperatorStubImpl::PiracerOperatorStubImpl() { }

// Destructor
PiracerOperatorStubImpl::~PiracerOperatorStubImpl() { }

// Implementation of setting the gear mode based on client request
void PiracerOperatorStubImpl::setGearMode(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gearMode, setGearModeReply_t _reply)
{
    // Set the gear mode in the Piracer
    piracer.setGearMode(_gearMode);

    // Respond to the client request with an empty message
    _reply("");

    return;
}

