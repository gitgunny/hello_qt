#include "hello_qt_20230801.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    hello_qt_20230801 w;
    w.show();
    return a.exec();
}
