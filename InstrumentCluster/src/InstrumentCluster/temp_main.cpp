#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <iostream>
#include <string>
#include <unistd.h>

#include "InstrumentClusterStubImpl.hpp"
#include "CarInformation.hpp"


using namespace v1_0::commonapi;

int main(int argc, char *argv[])
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<InstrumentClusterStubImpl> InstrumentClusterService;
    
    runtime = CommonAPI::Runtime::get();
    InstrumentClusterService = std::make_shared<InstrumentClusterStubImpl>();
    runtime->registerService("local", "InstrumentCluster", InstrumentClusterService);
    
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    
    qmlRegisterType<CarInformation>("DataModule", 1, 0, "CarInformation");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
