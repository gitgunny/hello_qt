#pragma once

#include <QtWidgets/QWidget>
#include <QDebug>
#include <QTextBrowser>
#include <QPushButton>
#include <QMessageBox>
#include <QProgressBar>
#include "ui_hello_qt_20230801.h"

class hello_qt_20230801 : public QWidget
{
	Q_OBJECT

public:
	hello_qt_20230801(QWidget* parent = nullptr);
	~hello_qt_20230801();

private:
	Ui::hello_qt_20230801Class ui;

private:
	QTextBrowser* textBrowser;
	QPushButton* pushButton_commit, * pushButton_cancel;
	QMessageBox* messageBox;
	QProgressBar* progressBar;

public slots:
	void slot();

public:
	void noSlot();
};
