#include "hello_qt.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	hello_qt w;
	w.show();
	return a.exec();
}