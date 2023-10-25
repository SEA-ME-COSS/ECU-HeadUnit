#ifndef PIRACERSIGNALSTUBIMPL_HPP
#define PIRACERSIGNALSTUBIMPL_HPP

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/PiracerSignalStubDefault.hpp>

// Declaration of the PiracerSignalStubImpl class
class PiracerSignalStubImpl : public v1_0::commonapi::PiracerSignalStubDefault {
public:
    // Constructor for PiracerSignalStubImpl
    PiracerSignalStubImpl();

    // Destructor for PiracerSignalStubImpl
    virtual ~PiracerSignalStubImpl();
};

#endif

