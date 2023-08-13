#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>

#include "indicator.h"

int main(int argc, char* argv[])
{
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;

	Indicator indicator;
	engine.rootContext()->setContextProperty("Indicator", &indicator);

	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

	return app.exec();
}
