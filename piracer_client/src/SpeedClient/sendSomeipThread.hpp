#ifndef SEND_SOMEIP_THREAD_HPP
#define SEND_SOMEIP_THREAD_HPP


// Include necessary header
#include <iostream>
#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>

// Include CANbuffer header
#include "CANbuffer.h"

// Include kalmanFilter header
#include "kalmanFilter.h"


void *sendSomeipThread(void *arg);    // Function for thread


#endif

