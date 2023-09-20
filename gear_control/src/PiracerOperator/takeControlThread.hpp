#ifndef TAKECONTROLTHREAD_HPP
#define TAKECONTROLTHREAD_HPP


// Include necessary header
#include <iostream>
#include <string>
#include <unistd.h>

// Include piracer operator service header
#include "PiracerOperatorStubImpl.hpp"


void *takeControlThread(void *arg);    // Function for thread


#endif

