#include <QGuiApplication>
#include <QQmlApplicationEngine>

//#include <QQmlContext>

#include "indicator.h"

int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    //    Indicator indicator;
    //    engine.rootContext()->setContextProperty("Indicator", &indicator);

    qmlRegisterType<Indicator>("Indicator", 1, 0, "Indicator");

    engine.load(QUrl("qrc:/main.qml"));

    return app.exec();
}
