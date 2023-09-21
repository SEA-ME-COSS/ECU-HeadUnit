// Include header
#include "readCANThread.h"


int soc;    // Variable for can socket


/**
 * @brief Opens the CAN port.
 * 
 * @param port The name of the port to be opened.
 *
 * @return Returns 0 on success, -1 on failure.
 **/
int open_port(const char *port)
{
    struct ifreq ifr;
    struct sockaddr_can addr;
    struct can_filter rfilter[1];

    // Open the socket
    soc = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (soc < 0) 
    {
        printf("Error opening socket!");
        return (-1);
    }

    addr.can_family = AF_CAN;
    strcpy(ifr.ifr_name, port);

    // Retrieve the interface index for the interface name
    if (ioctl(soc, SIOCGIFINDEX, &ifr) < 0) 
    {
        printf("Error retrieving interface index!");
        return (-1);
    }

    addr.can_ifindex = ifr.ifr_ifindex;

    // Set the socket to non-blocking mode
    fcntl(soc, F_SETFL, O_NONBLOCK);

    // Bind the socket to the CAN interface
    if (bind(soc, (struct sockaddr *)&addr, sizeof(addr)) < 0) 
    {
        printf("Error binding to the socket!");
        return (-1);
    }

    // Set the filter for CAN ID 0xF6
    rfilter[0].can_id   = 0x0F6;
    rfilter[0].can_mask = CAN_SFF_MASK;  // Use standard filter mask

    // Apply the filter to the socket
    if (setsockopt(soc, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter)) < 0)
    {
        printf("Error setting CAN filter!");
        return (-1);
    }

    return 0;
}


/**
 * @brief Reads data from the CAN port.
 * 
 * @param speed_sensor_rpm Pointer to a variable where the speed sensor rpm data will be store.
 **/
void read_port(uint16_t *speed_sensor_rpm)
{
    struct can_frame frame;
    int recvbytes = 0;

    struct timeval timeout = {1, 0};
    fd_set readSet;
    FD_ZERO(&readSet);
    FD_SET(soc, &readSet);

    // Wait for data to be ready to read
    if (select((soc + 1), &readSet, NULL, NULL, &timeout) >= 0)
    {
        if (FD_ISSET(soc, &readSet))
        {
            recvbytes = read(soc, &frame, sizeof(struct can_frame));
    
            if (recvbytes)
            {
                if (frame.can_id == 0x0F6) 
                {
                    // Change to actual data by bit shift
                    *speed_sensor_rpm = (frame.data[0] << 8) + frame.data[1];
                }
            }
        }
    }
}


/**
 * @brief Closes the CAN port.
 * 
 * @return Returns 0 on success.
 **/
int close_port()
{
    close(soc);
    return 0;
}


/**
 * @brief Thread function that reads CAN data and put to CANbuffer. This thread operates independently with sendSomeipThread
 * 
 * @param arg Pointer to get own thread 
 * 
 * @return Returns NULL if it failed
 **/
void *readCANThread(void *arg) 
{
    // Open the CAN port name "can0"
    open_port("can0");

    while (1) 
    {
        uint16_t speed_sensor_rpm;
        
        read_port(&speed_sensor_rpm);    // Read speed and RPM values from the port

        // Lock the CANbuffer mutex before writing
        pthread_mutex_lock(&CANbufferMutex);

        CANbuffer[CANbufferIndex] = speed_sensor_rpm;    // Write speed value to CANbuffer
        CANbufferIndex = (CANbufferIndex + 1) % CANbuffer_SIZE;    // Update the CANbuffer index

	// Unlock the CANbuffer mutex after writing
        pthread_mutex_unlock(&CANbufferMutex);
    }
    
    close_port();
    return NULL;
}

