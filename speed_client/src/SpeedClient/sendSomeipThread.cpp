// Include header
#include "sendSomeipThread.hpp"


using namespace v1_0::commonapi;

/**
 * @brief Thread function that sends CAN data to SOMEIP. This thread operates independently with readCANThread.
 * 
 * @param arg Pointer to get own thread 
 * 
 * @return Returns NULL if it failed
 **/
void *sendSomeipThread(void *arg)
{
    std::shared_ptr<CommonAPI::Runtime> runtime = CommonAPI::Runtime::get();
    std::shared_ptr<ManagerProxy<>> myProxy = runtime->buildProxy<ManagerProxy>("local", "seame");
    
    std::cout << "Checking availability!" << std::endl;
    while (!myProxy->isAvailable())
        usleep(10);
    std::cout << "Available!" << std::endl;
    
    CommonAPI::CallStatus callStatus;
    std::string returnMessage;
    
    while (1)
    {
        // Lock the CANbuffer mutex to access safely
        pthread_mutex_lock(&CANbufferMutex);

        // Compute the most recent CANbuffer index
        int currentIndex = CANbufferIndex - 1;
        if (currentIndex < 0)    // If at the beginning, wrap around to the end
        {
            currentIndex = CANbuffer_SIZE - 1;
        }

        // Retrieve the most recent data from the CANbuffer
        uint16_t speed_sensor_rpm = CANbuffer[currentIndex];

        // Unlock the mutex after reading data
        pthread_mutex_unlock(&CANbufferMutex);
        
        uint16_t kf_speed_sensor_rpm = filter(speed_sensor_rpm);

	myProxy->setSensorRpm(kf_speed_sensor_rpm, callStatus, returnMessage);

        usleep(500000);
    }
    return NULL;
}

