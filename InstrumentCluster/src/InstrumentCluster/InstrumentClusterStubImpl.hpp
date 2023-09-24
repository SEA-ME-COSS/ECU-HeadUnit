#ifndef INSTRUMENTCLUSTERSTUBIMPL_HPP
#define INSTRUMENTCLUSTERSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/InstrumentClusterStubDefault.hpp>


class InstrumentClusterStubImpl : public v1_0::commonapi::InstrumentClusterStubDefault
{
public:
    InstrumentClusterStubImpl();
    virtual ~InstrumentClusterStubImpl();
    virtual void setSpeedRPM(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRPM, setSpeedRPMReply_t _return);
    virtual void setBattery(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _battery, setBatteryReply_t _return);
    virtual void setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _return);
    virtual void setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _return);
    
    uint16_t getSpeed();
    uint16_t getRPM();
    uint16_t getBattery();
    uint16_t getGear();
    uint16_t getDirection();
    
private:
    uint16_t speed;
    uint16_t rpm;
    uint16_t battery;
    uint16_t gear;
    uint16_t direction;
};


#endif

