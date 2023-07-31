#pragma once

#include <QtWidgets/QMainWindow>
#include <qmessagebox.h>
#include "ui_hello_qt.h"

#include <cstdlib>
#include <string>
#include <time.h>

class hello_qt : public QMainWindow
{
	Q_OBJECT

public:
	hello_qt(QWidget* parent = nullptr);
	~hello_qt();

private:
	Ui::hello_qtClass ui;

public:
	int answer;

public slots:
	void checkAnswer();
};