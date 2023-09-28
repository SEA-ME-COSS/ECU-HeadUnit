#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <v1/commonapi/IPCManagerProxy.hpp>

#include "HeadUnitStubImpl.hpp"
#include "QtFunction.hpp"


using namespace v1_0::commonapi;

int main(int argc, char *argv[])
{
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<HeadUnitStubImpl> HeadUnitService;
    std::shared_ptr<IPCManagerProxy<>> IPCManagerTargetProxy;
    
    runtime = CommonAPI::Runtime::get();
    HeadUnitService = std::make_shared<HeadUnitStubImpl>();
    runtime->registerService("local", "HeadUnit", HeadUnitService);
    IPCManagerTargetProxy = runtime->buildProxy<IPCManagerProxy>("local", "IPCManager");
    
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    
    qmlRegisterType<QtFunction>("DataModule", 1, 0, "QtFunction");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl)
    {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
