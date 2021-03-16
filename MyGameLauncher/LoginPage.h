#pragma once

#include <QWidget>
#include "ui_LoginPage.h"

class LoginPage : public QWidget
{
	Q_OBJECT

public:
	LoginPage(QWidget *parent = Q_NULLPTR);
	~LoginPage();

	void connection();

private:
	Ui::LoginPage ui;
};
