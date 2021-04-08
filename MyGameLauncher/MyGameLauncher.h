#pragma once

#include <QtWidgets/QMainWindow>
#include "AccountManager.h"
#include "ChatWidget.h"

#include "ui_MyGameLauncher.h"

class TitleBar;

class MyGameLauncher : public QMainWindow
{
    Q_OBJECT

public:
    MyGameLauncher(QWidget *parent = Q_NULLPTR);

protected:
	void connection();
	void initLayout();

	virtual void resizeEvent(QResizeEvent * event) override;

private:
    Ui::MyGameLauncherClass ui;

	TitleBar* titlebar_ = nullptr;
	USER user_info_;
};
