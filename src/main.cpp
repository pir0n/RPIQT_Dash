#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>
#include <include/middlebar.h>
#include <include/serialInfo.h>






int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    MiddleBar m_middlebarHandler;

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/AlphaDash/qml_main/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    QQmlContext * context (engine.rootContext() );
    context -> setContextProperty("middlebarHandler", &m_middlebarHandler);
    engine.load(url);

    printSerialInfo();


    return app.exec();
}
