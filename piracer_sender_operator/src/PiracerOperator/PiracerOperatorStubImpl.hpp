#ifndef PIRACEROPERATORSTUBIMPL_H_
#define PIRACEROPERATORSTUBIMPL_H_


#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/PiracerOperatorStubDefault.hpp>

// Include piracer class header
#include "PiracerClass.hpp"


class PiracerOperatorStubImpl: public v1_0::commonapi::PiracerOperatorStubDefault {
public:
    PiracerOperatorStubImpl();
    virtual ~PiracerOperatorStubImpl();
    virtual void setGearMode(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gearMode, setGearModeReply_t _return);
};


#endif

