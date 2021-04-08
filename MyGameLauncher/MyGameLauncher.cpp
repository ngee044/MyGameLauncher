#include <QApplication>
#include <QDebug>
#include <TitleBar.h>
#include "MyGameLauncher.h"

MyGameLauncher::MyGameLauncher(QWidget *parent)
	: QMainWindow(parent)
{
	setWindowFlags(Qt::FramelessWindowHint);

	ui.setupUi(this);

	initLayout();
	connection();
}

void MyGameLauncher::connection()
{
	connect(ui.toolButton_hide, &QToolButton::clicked, this, [=]() { titlebar_->OnWindowsHideButtonClicked(); });
	connect(ui.toolButton_resize, &QToolButton::clicked, this, [=]() { titlebar_->OnWindowsSizeButtonClicked(ui.toolButton_resize); });
	connect(ui.toolButton_exit, &QToolButton::clicked, this, [=]() {QApplication::exit(); });
}

void MyGameLauncher::initLayout()
{
	titlebar_ = new TitleBar();
	titlebar_->SetButtonStyle(ui.toolButton_hide, ui.toolButton_resize, ui.toolButton_exit);
	QHBoxLayout* layout = static_cast<QHBoxLayout*>(ui.titlebar_widget_->layout());
	layout->insertWidget(0, titlebar_);

	ui.login_status_widget_->setStyleSheet("border:1px solid red;");
	ui.game_list_widget_->setStyleSheet("border:1px solid green;");
	ui.main_widget_->setStyleSheet("border:1px solid blue;");
}

void MyGameLauncher::resizeEvent(QResizeEvent* event)
{
	QMainWindow::resizeEvent(event);
	int a = 0, b = 0, c = 0;
	if (this->isMaximized() == false)
	{
		a = 2;
		b = 8;
		c = 2;
	}
	else
	{
		a = 2;
		b = 7;
		c = 2;
	}

	QHBoxLayout* main_lay = static_cast<QHBoxLayout*>(ui.main_application_widget->layout());
	main_lay->setStretch(0, a);
	main_lay->setStretch(1, b);
	main_lay->setStretch(2, c);
}
