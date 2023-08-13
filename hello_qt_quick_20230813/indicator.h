#pragma once

#include <QObject>

#include <QDebug>

class Indicator : public QObject
{
    Q_OBJECT

public:
    Indicator(QObject* parent = nullptr);

signals:
    void leftSignalSent();
    void rightSignalSent();

public slots:
    void sendLeftSignal();
    void sendRightSignal();
    void getLeftIndicatorVisible(bool visible);
    void getRightIndicatorVisible(bool visible);

private:
    bool leftIndicatorVisible;
    bool rightIndicatorVisible;
};
