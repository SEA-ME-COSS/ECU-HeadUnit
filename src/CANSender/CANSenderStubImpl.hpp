#ifndef CANSENDERSTUBIMPL_HPP
#define CANSENDERSTUBIMPL_HPP

// Include necessary headers for CommonAPI
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/CANSenderStubDefault.hpp>

// Define a class called CANSenderStubImpl
class CANSenderStubImpl: public v1_0::commonapi::CANSenderStubDefault
{
public:
    // Constructor for CANSenderStubImpl.
    CANSenderStubImpl();

    // Destructor for CANSenderStubImpl.
    virtual ~CANSenderStubImpl();
};

#endif

