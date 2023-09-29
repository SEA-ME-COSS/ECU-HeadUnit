#ifndef INSTRUMENTCLUSTERSTUBIMPL_HPP
#define INSTRUMENTCLUSTERSTUBIMPL_HPP


#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/InstrumentClusterStubDefault.hpp>

#include "InstrumentClusterQtClass.hpp"


class InstrumentClusterStubImpl : public v1_0::commonapi::InstrumentClusterStubDefault
{
private:
    uint16_t temp;

public:
    InstrumentClusterStubImpl();
    virtual ~InstrumentClusterStubImpl();
    virtual void setSpeedRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSpeedRpmReply_t _return);
    virtual void setBattery(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _battery, setBatteryReply_t _return);
    virtual void setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _return);
    virtual void setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _return);
};


#endif

