#include "hello_qt.h"

hello_qt::hello_qt(QWidget* parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	srand(time(NULL));
	answer = rand() % 100 + 1;

	ui.lineEdit->setPlaceholderText("1 ~ 100 Input");
}

hello_qt::~hello_qt()
{}

void hello_qt::checkAnswer()
{
	QMessageBox msg_box;

	bool check_num;
	unsigned int input_num = ui.lineEdit->text().toInt(&check_num);

	if (check_num)
	{
		if (input_num < 1 || input_num > 100)
			msg_box.warning(nullptr, nullptr, "1 ~ 100 Input");
		else if (input_num < answer)
			msg_box.information(nullptr, nullptr, "Up");
		else if (input_num > answer)
			msg_box.information(nullptr, nullptr, "Down");
		else
			msg_box.information(nullptr, nullptr, "Collect!");
	}
	else
		msg_box.warning(nullptr, nullptr, "Is not Number");
}