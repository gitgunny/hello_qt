#pragma once

#include <QtWidgets/QWidget>
#include <QComboBox>
#include <QButtonGroup>
#include <QRadioButton>
#include <QCheckBox>
#include <QPushButton>
#include <QMessageBox>
#include "ui_hello_qt_20230802.h"

class hello_qt_20230802 : public QWidget
{
	Q_OBJECT

public:
	hello_qt_20230802(QWidget* parent = nullptr);
	~hello_qt_20230802();

private:
	Ui::hello_qt_20230802Class ui;

private:
	QComboBox* comboBox;
	QButtonGroup* radioButtonGroup, * checkBoxGroup[3];
	QRadioButton* radioButton[3];
	QCheckBox* checkBox[3][3];
	QPushButton* pushButton;
	QMessageBox* messageBox;

public slots:
	void initCheckBox();
	void check();
};
