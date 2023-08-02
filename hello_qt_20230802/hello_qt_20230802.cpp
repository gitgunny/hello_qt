#include "hello_qt_20230802.h"

hello_qt_20230802::hello_qt_20230802(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowTitle("ComboBox RadioButton CheckBox ButtonGroup Check");
	setFixedSize(500, 280);

	QString comboBoxText[3] = { "ComboBox1", "Combobox2", "ComboBox3" };
	int addxPos = 150;
	int addyPos = 40;
	QString radioButtonText[3] = { "RadioButton1", "RadioButton2", "RadioButton3" };
	QString checkBoxText[3][3] = {
		{"CheckBox1_1", "CheckBox1_2", "CheckBox1_3"},
		{"CheckBox2_1", "CheckBox2_2", "CheckBox2_3"},
		{"CheckBox3_1", "CheckBox3_2", "CheckBox3_3"} };

	comboBox = new QComboBox(this);
	comboBox->setGeometry(30, 20, 440, 20);
	for (int i = 0; i < sizeof(comboBoxText) / sizeof(comboBoxText[0]); i++)
		comboBox->addItem(comboBoxText[i]);

	radioButtonGroup = new QButtonGroup(this);
	for (int i = 0; i < sizeof(radioButton) / sizeof(radioButton[0]); i++)
	{
		radioButton[i] = new QRadioButton(this);
		radioButton[i]->move(40 + (addxPos * i), 60);
		radioButton[i]->setText(radioButtonText[i]);

		radioButtonGroup->addButton(radioButton[i]);
		checkBoxGroup[i] = new QButtonGroup(this);

		for (int j = 0; j < sizeof(checkBox[0]) / sizeof(checkBox[0][0]); j++)
		{
			checkBox[i][j] = new QCheckBox(this);
			checkBox[i][j]->move(60 + (addxPos * i), 100 + (addyPos * j));
			checkBox[i][j]->setText(checkBoxText[i][j]);

			checkBoxGroup[i]->addButton(checkBox[i][j]);
		}
		checkBoxGroup[i]->setExclusive(false);
	}
	radioButtonGroup->setExclusive(true);
	radioButton[0]->setChecked(true);
	initCheckBox();

	pushButton = new QPushButton(this);
	pushButton->setGeometry(30, 220, 440, 50);
	pushButton->setText("확인");

	for (int i = 0; i < sizeof(radioButton) / sizeof(radioButton[0]); i++)
		connect(radioButton[i], &QRadioButton::clicked, this, &hello_qt_20230802::initCheckBox);

	connect(pushButton, &QPushButton::clicked, this, &hello_qt_20230802::check);
}

hello_qt_20230802::~hello_qt_20230802()
{}

void hello_qt_20230802::initCheckBox()
{
	for (int i = 0; i < sizeof(radioButton) / sizeof(radioButton[0]); i++)
	{
		for (int j = 0; j < sizeof(checkBox[0]) / sizeof(checkBox[0][0]); j++)
		{
			checkBox[i][j]->setChecked(false);
			if (radioButton[i]->isChecked() == true)
				checkBox[i][j]->setEnabled(true);
			else
				checkBox[i][j]->setEnabled(false);
		}
	}
}

void hello_qt_20230802::check()
{
	QString checkComboBox = QString("CheckComboBox : ") + comboBox->currentText();
	QString checkRadioButton = QString("CheckRadioButton : ");
	QString checkCheckBox = QString("CheckCheckBox : ");

	for (int i = 0; i < sizeof(radioButton) / sizeof(radioButton[0]); i++)
	{
		if (radioButton[i]->isChecked() == true)
			checkRadioButton += QString::number(i + 1) + QString(" ");
		for (int j = 0; j < sizeof(checkBox[0]) / sizeof(checkBox[0][0]); j++)
		{
			if (checkBox[i][j]->isChecked() == true)
				checkCheckBox += QString::number(j + 1) + QString(" ");
		}
	}

	messageBox->information(this, "Check", checkComboBox + QString("\n") + checkRadioButton + QString("\n") + checkCheckBox);
}
