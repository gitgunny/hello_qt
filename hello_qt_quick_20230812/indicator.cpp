#include "indicator.h"

Indicator::Indicator(QObject* parent) : QObject(parent)
{
}

void Indicator::sendLeftSignal()
{
    emit leftSignalSent();
}

void Indicator::sendRightSignal()
{
    emit rightSignalSent();
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
