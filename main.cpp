#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "receptor.hpp"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Receptor receiver;
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("_receiver", &receiver);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}
