#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_hello_qt.h"

class hello_qt : public QMainWindow
{
	Q_OBJECT

public:
	hello_qt(QWidget* parent = nullptr);
	~hello_qt();

private:
	Ui::hello_qtClass ui;
};