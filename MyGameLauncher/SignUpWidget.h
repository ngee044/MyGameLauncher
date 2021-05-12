#pragma once

#include <QWidget>
#include "ui_SignUpWidget.h"
#include "LoginPage.h"

class SignUpWidget : public QDialog
{
	Q_OBJECT

public:
	SignUpWidget(QWidget *parent = Q_NULLPTR);
	~SignUpWidget();

	void connections();
	User getUserInfo();
public slots:
	void slotSignUp();

private:
	Ui::SignUpWidget ui;
};
