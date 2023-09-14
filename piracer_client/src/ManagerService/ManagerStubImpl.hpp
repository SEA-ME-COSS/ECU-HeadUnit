#ifndef MANAGERSTUBIMPL_H_
#define MANAGERSTUBIMPL_H_


#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/ManagerStubDefault.hpp>


class ManagerStubImpl: public v1_0::commonapi::ManagerStubDefault {
public:
    ManagerStubImpl();
    virtual ~ManagerStubImpl();
    virtual void setSensorRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSensorRpmReply_t _return);
    virtual void setBatteryLevel(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _batteryLevel, setBatteryLevelReply_t _return);
};


#endif

