// Include Thread header
#include "readCANThread.h"
#include "sendSomeipThread.hpp"


int main (int argc, char **argv)
{
    // Create threads for CAN and SOMEIP
    pthread_t canThread, someipThread;
    pthread_create(&canThread, NULL, readCANThread, NULL);
    pthread_create(&someipThread, NULL, sendSomeipThread, NULL);

    pthread_join(canThread, NULL);
    pthread_join(someipThread, NULL);

    return 0;
}

