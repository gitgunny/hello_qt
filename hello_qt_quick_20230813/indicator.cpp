#include "indicator.h"

Indicator::Indicator(QObject* parent) : QObject(parent)
{
}

void Indicator::getLeftIndicatorVisible(bool visible)
{
	leftIndicatorVisible = visible;

	qDebug() << "LeftIndicatorVisible Value : " << leftIndicatorVisible;
}

void Indicator::getRightIndicatorVisible(bool visible)
{
	rightIndicatorVisible = visible;

	qDebug() << "RightIndicatorVisible Value : " << rightIndicatorVisible;
}

void Indicator::sendLeftSignal()
{
	emit leftSignal();
}

void Indicator::sendRightSignal()
{
	emit rightSignal();
}
