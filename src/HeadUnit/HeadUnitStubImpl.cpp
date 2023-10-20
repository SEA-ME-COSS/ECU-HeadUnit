#include "HeadUnitStubImpl.hpp"

// Constructor for HeadUnitStubImpl
HeadUnitStubImpl::HeadUnitStubImpl() { }

// Destructor for HeadUnitStubImpl
HeadUnitStubImpl::~HeadUnitStubImpl() { }

// Set sensor RPM value
void HeadUnitStubImpl::setSensorRpm(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _sensorRpm, setSensorRpmReply_t _reply)
{
    // Calculate the sensor RPM based on a formula
    uint16_t calculatedRpm = (uint16_t)((float)((uint16_t)((float)_sensorRpm / 2.6)) * 3.4);
    
    // Update the sensor RPM value in the 'carinfo' instance
    carinfo.setSensorRpm(calculatedRpm);

    // Send an empty reply
    _reply("");
    
    return;
}

// Set steering value
void HeadUnitStubImpl::setSteering(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _steering, setSteeringReply_t _reply)
{
    // Update the steering value in the 'carinfo' instance
    carinfo.setSteering(_steering);

    // Send an empty reply
    _reply("");
    
    return;
}

