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
#include "SignUpWidget.h"

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
	connect(ui.pushButton_sign_up, &QPushButton::clicked, this, &LoginPage::slotSignUp);
	connect(ui.toolButton_exit, &QToolButton::clicked, this, [=]() { QApplication::exit(); });
}

void LoginPage::keyPressEvent(QKeyEvent* event)
{
	if (event->key() == Qt::Key_Enter || 
		event->key() == Qt::Key_Return)
	{
		slotLogin();
	}
	QWidget::keyPressEvent(event);
}

void LoginPage::slotSignUp()
{
	User user;
	user.Id_ = "nukle";
	user.pw_ = "1234";
	user.vip_level_ = 2;
	user.create_date_ = "2020-04-29";
	user.visit_date_ = "2020-04-30";
	user.has_games_ = QString("").split(",");
	user.friend_list_ = QString("").split(",");
	user.status_ = 0;
	UserDBManager::Instance()->updateUserInfo(user);
	return;
	SignUpWidget* dialog = new SignUpWidget(this);
	if (dialog->exec())
	{
		//todo.....
		auto user = dialog->getUserInfo();
		UserDBManager::Instance()->createUserSignUp(user);
	}
	else
	{

	}
	
	delete dialog;
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
		auto dlg = UIFactory::showMsgBox(_kor("로그인 실패"), _kor("비밀번호가 틀렸습니다"));
		dlg->exec();
		delete dlg;
	}
		break;
	case -1:
	{
		auto dlg = UIFactory::showMsgBox(_kor("로그인 실패"), _kor("아이디가 없습니다."));
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
