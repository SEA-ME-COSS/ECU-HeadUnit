#ifndef SENDSOMEIPTHREAD_HPP
#define SENDSOMEIPTHREAD_HPP


#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>

#include "CANSenderStubImpl.hpp"
#include "CANBuffer.h"
#include "KalmanFilter.h"


void *SendSomeipThread(void *arg);


#endif

