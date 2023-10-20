#include "ReadCANThread.h"
#include "SendSomeipThread.hpp"

int main ()
{
    // Declare pthread variables for the CAN thread and SomeIP thread.
    pthread_t canThread, someipThread;
    
    // Create a new thread for the ReadCANThread, which is responsible for reading from CAN.
    pthread_create(&canThread, NULL, ReadCANThread, NULL);

    // Create a new thread for the SendSomeipThread, which sends data using the SomeIP protocol.
    pthread_create(&someipThread, NULL, SendSomeipThread, NULL);

    // Wait for the CAN thread and SomeIP thread to finish execution.
    pthread_join(canThread, NULL);
    pthread_join(someipThread, NULL);

    // Return 0 to indicate successful execution of the program.
    return 0;
}

