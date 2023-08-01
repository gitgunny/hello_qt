#include "hello_qt_20230801.h"

hello_qt_20230801::hello_qt_20230801(QWidget* parent)
	: QWidget(parent)
{
	//.ui을 통해 만든 객체 생성
	ui.setupUi(this);

	//Widget(this) 창 타이틀 설정
	setWindowTitle("Window Title");

	//Widget(this) 창 크기 설정
	this->setFixedSize(330, 100);

	//Widget(this)에 QTextBrowser 객체 생성
	textBrowser = new QTextBrowser(this);
	textBrowser->setGeometry(10, 10, 230, 50);

	//Widget(this)에 QPushBotton 객체 생성(총 2개)
	QString pushBottonText = QString("확인");
	pushButton_commit = new QPushButton(pushBottonText, this);
	pushButton_commit->move(245, 10);

	pushBottonText = QString("취소");
	pushButton_cancel = new QPushButton(pushBottonText, this);
	pushButton_cancel->move(245, 35);

	//Widget(this)에 QProgressBar 객체 생성
	progressBar = new QProgressBar(this);
	progressBar->setGeometry(10, 70, 350, 20);
	progressBar->setValue(40);
	progressBar->setFormat("");

	//pushButton 객체에 클릭(Clicked)이 발생하면 Widget(this)의 slot 함수 호출
	connect(pushButton_commit, &QPushButton::clicked, this, &hello_qt_20230801::slot);
	connect(pushButton_cancel, &QPushButton::clicked, this, &hello_qt_20230801::noSlot);
}

hello_qt_20230801::~hello_qt_20230801()
{}

void hello_qt_20230801::slot()
{
	//qDebug("PushButton Clicked");
	messageBox = new QMessageBox(this);
	messageBox->information(this, "MessageBox Title", "MessageBox Content");

	for (int i = progressBar->value(); i <= progressBar->maximum(); i++)
	{
		progressBar->setValue(i);
		_sleep(5);
	}
}

void hello_qt_20230801::noSlot()
{
	//qDebug("PushButton Clicked");
	messageBox = new QMessageBox(this);

	for (int i = progressBar->value(); i >= progressBar->minimum(); i--)
	{
		progressBar->setValue(i);
		_sleep(5);
	}

	messageBox->critical(this, "No Slot MessageBox Title", "No Slot MessageBox Content");
}
