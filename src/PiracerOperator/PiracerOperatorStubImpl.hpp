#ifndef PIRACEROPERATORSTUBIMPL_HPP
#define PIRACEROPERATORSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>                 // CommonAPI framework
#include <v1/commonapi/PiracerOperatorStubDefault.hpp> // Generated Stub header

#include "PiracerClass.hpp"                         // Including the PiracerClass for vehicle control

class PiracerOperatorStubImpl : public v1_0::commonapi::PiracerOperatorStubDefault
{
private:
    PiracerClass piracer;
    
public:
    PiracerOperatorStubImpl();          // Constructor for PiracerOperatorStubImpl
    virtual ~PiracerOperatorStubImpl();  // Destructor for PiracerOperatorStubImpl
    virtual void setGearMode(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gearMode, setGearModeReply_t _return);
    // Implementation of setGearMode function, required by the PiracerOperatorStubDefault interface
    virtual void setThrottle(const std::shared_ptr<CommonAPI::ClientId> _client, double _throttle, setThrottleReply_t _return);
    // Implementation of setThrottle function, required by the PiracerOperatorStubDefault interface
    virtual void setSteering(const std::shared_ptr<CommonAPI::ClientId> _client, double _steering, setSteeringReply_t _return);
    // Implementation of setSteering function, required by the PiracerOperatorStubDefault interface
};

#endif

