#include "hello_qt_20230802.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    hello_qt_20230802 w;
    w.show();
    return a.exec();
}
