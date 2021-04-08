#include <QApplication>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QToolButton>

#include "TitleBar.h"

TitleBar::TitleBar(QWidget* parent)
	: QWidget(parent)
{
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

	if (parent != nullptr)
	{
		if (parent->isLeftToRight() && isRightToLeft())
		{
			setLayoutDirection(Qt::LeftToRight);
		}
		else if (parent->isRightToLeft() && isLeftToRight())
		{
			setLayoutDirection(Qt::RightToLeft);
		}
	}
}

TitleBar::~TitleBar()
{
}

void TitleBar::mousePressEvent(QMouseEvent* event)
{
	QWidget::mousePressEvent(event);
	mouse_pos_ = mapTo(window(), event->pos());
}

void TitleBar::mouseMoveEvent(QMouseEvent* event)
{
	QWidget::mouseMoveEvent(event);
	if (check_maximum_size_)
	{
		return;
	}

	QWidget* app = window();
	if (app->isMaximized())
	{
		app->showNormal();
	}
	app->move(event->globalPos() - mouse_pos_);
}

void TitleBar::mouseReleaseEvent(QMouseEvent* event)
{
}

void TitleBar::mouseDoubleClickEvent(QMouseEvent* event)
{
	QWidget* app = window();
	if (app->isMaximized())
	{
		app->showNormal();
		check_maximum_size_ = false;
	}
	else
	{
		app->showMaximized();
		check_maximum_size_ = true;
	}
}

void TitleBar::OnWindowsExitButtonClicked()
{
	QCoreApplication::quit();
}

void TitleBar::OnWindowsSizeButtonClicked(QToolButton* button)
{
	QWidget* app = window();
	if (app->isMaximized())
	{
		app->showNormal();
		//button->setIcon(QIcon(":/RealArch/Resources/Scanner/tob_none_btn04.png"));
		check_maximum_size_ = false;
	}
	else
	{
		app->showMaximized();
		//button->setIcon(QIcon(":/RealArch/Resources/Scanner/tob_none_btn02.png"));
		check_maximum_size_ = true;
	}
}

void TitleBar::OnWindowsHideButtonClicked()
{
	QWidget* app = window();
	app->showMinimized();
}

void TitleBar::SetButtonStyle(QToolButton* hide_button, QToolButton* resize_button, QToolButton* exit_button)
{
	hide_button->setCursor(Qt::PointingHandCursor);
	resize_button->setCursor(Qt::PointingHandCursor);
	exit_button->setCursor(Qt::PointingHandCursor);

	QString bar_style = QString::fromUtf8("QToolButton:hover { border:none; background-color:#e7e3e3;}"
		"QToolButton{border:none; background-color:#eeeeee;}");

	resize_button->setStyleSheet(bar_style);
	hide_button->setStyleSheet(bar_style);
	exit_button->setStyleSheet("QToolButton:hover { border:none; background-color:#e34949;}"
		"QToolButton{border:none; background-color:#eeeeee;}");

#if 0
	hide_button->setIcon(QIcon(":/RealArch/Resources/Scanner/tob_none_btn01.png"));
	resize_button->setIcon(QIcon(":/RealArch/Resources/Scanner/tob_none_btn02.png"));
	exit_button->setIcon(QIcon(":/RealArch/Resources/Scanner/tob_none_btn03.png"));
#endif
}