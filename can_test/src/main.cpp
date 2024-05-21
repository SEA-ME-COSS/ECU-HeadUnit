#include "main.hpp"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);

    CanBusHandler handler;

    return app.exec();
}
