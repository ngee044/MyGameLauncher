#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QToolButton>
#include <QDebug>

#include "../global_common.h"
#include "LoginPage.h"
#include "MyGameLauncher.h"
#include "../UIComponent/UIFactory.h"
#include "../LoginUserInfo/UserDBManager.h"

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
	// 0 pw error
	// -1 id error
	// 1 is login
	auto idx = UserDBManager::Instance()->setUserLogin(id, pw);
	switch (idx)
	{
	case 0:
	{
		auto dlg = UIFactory::showMsgBox(_kor("�α��� ����"), _kor("��й�ȣ�� Ʋ�Ƚ��ϴ�"));
		dlg->exec();
		delete dlg;
	}
		break;
	case -1:
	{
		auto dlg = UIFactory::showMsgBox(_kor("�α��� ����"), _kor("���̵� �����ϴ�."));
		dlg->exec();
		delete dlg;
	}
		break;
	case 1:
	{
		MyGameLauncher* main = new MyGameLauncher();
		main->setAccountInfo(UserDBManager::Instance()->getUserInfo(id));
		main->show();

		this->hide();
	}
		break;
	default:
		break;
	}

}
