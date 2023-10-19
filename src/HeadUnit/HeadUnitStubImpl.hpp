#ifndef HEADUNITSTUBIMPL_HPP
#define HEADUNITSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HeadUnitStubDefault.hpp>

#include "HeadUnitQtClass.hpp"

// Define the HeadUnitStubImpl class, which is derived from HeadUnitStubDefault
class HeadUnitStubImpl : public v1_0::commonapi::HeadUnitStubDefault
{
public:
    // Constructor for HeadUnitStubImpl
    HeadUnitStubImpl();

    // Destructor for HeadUnitStubImpl
    virtual ~HeadUnitStubImpl();

    // Override the setSensorRpm function to handle RPM value updates
    virtual void setSensorRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSensorRpmReply_t _return);

    // Override the setSteering function to handle steering value updates
    virtual void setSteering(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _steering, setSteeringReply_t _return);
};

#endif

