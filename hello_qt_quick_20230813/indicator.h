#pragma once

#include <QObject>

#include <QDebug>

class Indicator : public QObject
{
	Q_OBJECT

public:
	Indicator(QObject* parent = nullptr);

public slots:
	void getLeftIndicatorVisible(bool visible);
	void getRightIndicatorVisible(bool visible);
	void sendLeftSignal();
	void sendRightSignal();

signals:
	void leftSignal();
	void rightSignal();

private:
	bool leftIndicatorVisible;
	bool rightIndicatorVisible;
};
