#ifndef TAKECONTROLTHREAD_HPP
#define TAKECONTROLTHREAD_HPP


// Include necessary header
#include <iostream>
#include <string>
#include <unistd.h>

// Include piracer class header
#include "PiracerClass.hpp"

// Include piracer operator service header
#include "PiracerOperatorStubImpl.hpp"


void *takeContorlThread(void *arg);    // Function for thread


#endif

