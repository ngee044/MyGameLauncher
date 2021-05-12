#include <QDebug>
#include <QDateTime>
#include "SignUpWidget.h"
#include "AppManager.h"

SignUpWidget::SignUpWidget(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

	connections();
}

SignUpWidget::~SignUpWidget()
{
}

void SignUpWidget::connections()
{
	connect(ui.pushButton_ok_, &QPushButton::clicked, this, &SignUpWidget::slotSignUp);
	connect(ui.pushButton_close_, &QPushButton::clicked, [=]() { this->reject(); });
}

User SignUpWidget::getUserInfo()
{
	User user;
	user.Id_ = ui.lineEdit_id_->text();
	user.pw_ = ui.lineEdit_pw_->text();
	user.status_ = 0;
	user.vip_level_ = 1;
	user.create_date_ = AppManager::Instance()->getCurrentDate();
	user.visit_date_ = "";

	return user;
}

void SignUpWidget::slotSignUp()
{
	this->accept();
}
