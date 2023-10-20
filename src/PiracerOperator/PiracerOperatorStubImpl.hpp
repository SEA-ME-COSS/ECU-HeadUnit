#ifndef PIRACEROPERATORSTUBIMPL_HPP
#define PIRACEROPERATORSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>                 // CommonAPI framework
#include <v1/commonapi/PiracerOperatorStubDefault.hpp> // Generated Stub header

#include "PiracerClass.hpp"                         // Including the PiracerClass for vehicle control

class PiracerOperatorStubImpl : public v1_0::commonapi::PiracerOperatorStubDefault
{
public:
    PiracerOperatorStubImpl();          // Constructor for PiracerOperatorStubImpl
    virtual ~PiracerOperatorStubImpl();  // Destructor for PiracerOperatorStubImpl
    virtual void setGearMode(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gearMode, setGearModeReply_t _return);
    // Implementation of setGearMode function, required by the PiracerOperatorStubDefault interface
};

#endif

