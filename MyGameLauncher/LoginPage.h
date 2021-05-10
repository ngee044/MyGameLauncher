#pragma once

#include <QWidget>
#include "ui_LoginPage.h"
#include "MyGameLauncher.h"

class LoginPage : public QWidget
{
	Q_OBJECT

public:
	LoginPage(QWidget *parent = Q_NULLPTR);
	~LoginPage();
	void connection();

public slots:
	void slotLogin();

protected:
	virtual void keyPressEvent(QKeyEvent* event) override;

private:
	Ui::LoginPage ui;
};
