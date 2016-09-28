#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Controller.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    //qmlRegisterType<Controller>("MyApp", 1, 0, "Controller");
    Controller controller;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("controller", &controller);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
