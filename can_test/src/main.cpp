#include <QCoreApplication>
#include "CANBusReceiver.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CANBusReceiver receiver;

    return a.exec();
}