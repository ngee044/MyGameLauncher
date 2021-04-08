#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QToolButton>
#include <QDebug>

#include "LoginPage.h"
#include "MyGameLauncher.h"

LoginPage::LoginPage(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
	connection();
}

LoginPage::~LoginPage()
{
}

void LoginPage::connection()
{
	connect(ui.pushButton_sign_in, &QPushButton::clicked, this, &LoginPage::slotLogin);
	connect(ui.pushButton_sign_up, &QPushButton::clicked, this, [=]() {qDebug() << "sign up"; });
	connect(ui.toolButton_exit, &QToolButton::clicked, this, [=]() { QApplication::exit(); });
}

void LoginPage::slotLogin()
{
	QString id = ui.lineEdit_id->text();
	QString pw = ui.lineEdit_pw->text();

	//TODO.. connects AWS DB
	if (id == "admin")
	{
		if (pw == "1234")
		{
			MyGameLauncher* main = new MyGameLauncher();
			main->show();

			this->hide();
		}
		else
		{
			//TODO MessageBox
		}
	}
	else
	{
		//TODO MessageBox;
	}

}
