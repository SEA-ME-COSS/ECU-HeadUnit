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

// Set turn signal value
void HeadUnitStubImpl::setTurnSignal(const std::shared_ptr<CommonAPI::ClientId> _client, double _turnSignal, setTurnSignalReply_t _reply)
{
    // Update the steering value in the 'carinfo' instance
    if (_turnSignal == 0.0) // straight
    {
        carinfo.setSteering((uint16_t)0);
    }
    else if (_turnSignal == -1.0) // left
    {
        carinfo.setSteering((uint16_t)1);
    }
    else if (_turnSignal == 1.0) // right
    {
        carinfo.setSteering((uint16_t)2);
    }

    // Send an empty reply
    _reply("");
    
    return;
}

void HeadUnitStubImpl::setGear(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _gear, setGearReply_t _reply)
{
    // Update the gear mode property in the carinfo object.
    carinfo.setGear(_gear);
    
    // Respond to the client's request by invoking the reply callback.
    _reply("");
    
    return;
}

void HeadUnitStubImpl::setDirection(const std::shared_ptr<CommonAPI::ClientId> _client, uint16_t _direction, setDirectionReply_t _reply)
{
    // Update the direction property in the carinfo object.
    carinfo.setDirection(_direction);

    // Respond to the client's request by invoking the reply callback.
    _reply("");

    return;
}

void HeadUnitStubImpl::setLight(const std::shared_ptr<CommonAPI::ClientId> _client, std::string _light, setLightReply_t _reply)
{
    // Update the light color property in the carinfo object.
    carinfo.setLight(QString::fromStdString(_light));

    // Respond to the client's request by invoking the reply callback.
    _reply("");

    return;
}

