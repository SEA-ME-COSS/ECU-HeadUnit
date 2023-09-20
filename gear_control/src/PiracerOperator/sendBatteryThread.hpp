#ifndef SENDBATTERYTHREAD_HPP
#define SENDBATTERYTHREAD_HPP


// Include necessary header
#include <iostream>
#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/IPCManagerProxy.hpp>

// Include piracer class header
#include "PiracerClass.hpp"


void *sendBatteryThread(void *arg);    // Function for thread


#endif

