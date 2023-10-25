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

// Implementation of setting the throttle based on client request
void PiracerOperatorStubImpl::setThrottle(const std::shared_ptr<CommonAPI::ClientId> _client, double _throttle, setThrottleReply_t _reply)
{
    // Apply the throttle in the Piracer
    piracer.applyThrottle(_throttle);

    // Respond to the client request with an empty message
    _reply("");

    return;
}

// Implementation of setting the steering based on client request
void PiracerOperatorStubImpl::setSteering(const std::shared_ptr<CommonAPI::ClientId> _client, double _steering, setSteeringReply_t _reply)
{
    // Apply the steering in the Piracer
    piracer.applySteering(_steering);

    // Respond to the client request with an empty message
    _reply("");

    return;
}

