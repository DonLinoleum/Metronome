#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "MainState/MainState.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<MainState>("MainState",1,0,"MainState");

    const QUrl url(u"qrc:/Metronome/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);


    return app.exec();
}
