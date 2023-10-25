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
void HeadUnitStubImpl::setSteering(const std::shared_ptr<CommonAPI::ClientId> _client, double _steering, setSteeringReply_t _reply)
{
    // Update the steering value in the 'carinfo' instance
    if (_steering == 0.0) // straight
    {
        carinfo.setSteering((uint16_t)0);
    }
    else if (_steering == -1.0) // left
    {
        carinfo.setSteering((uint16_t)1);
    }
    else if (_steering == 1.0) // right
    {
        carinfo.setSteering((uint16_t)2);
    }

    // Send an empty reply
    _reply("");
    
    return;
}


