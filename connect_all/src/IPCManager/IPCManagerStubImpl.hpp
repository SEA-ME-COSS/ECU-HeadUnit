#ifndef IPCMANAGERSTUBIMPL_H_
#define IPCMANAGERSTUBIMPL_H_


#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerStubDefault.hpp>


class IPCManagerStubImpl: public v1_0::commonapi::IPCManagerStubDefault {
public:
    IPCManagerStubImpl();
    virtual ~IPCManagerStubImpl();
    virtual void setSensorRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSensorRpmReply_t _return);
    virtual void setBatteryLevel(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _batteryLevel, setBatteryLevelReply_t _return);
};


#endif

