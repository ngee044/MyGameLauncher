#pragma once
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QtCore>
#include <QtGui>

#include <QMouseEvent>
#include <QToolButton>
#include <QPushButton>
#include <QSizePolicy>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "uicomponent_global.h"
//TODO Common Ui Component

class UICOMPONENT_EXPORT GameSelectorButton : public QToolButton
{
	Q_OBJECT
public:
	GameSelectorButton() 
	{ 
		initLayout();
	}
	~GameSelectorButton() {}

	void initLayout() 
	{
		this->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
		this->setMinimumSize(125,75);
		this->setCursor(Qt::PointingHandCursor);
		this->setStyleSheet(
			"QToolButton:hover{ color:white; background-color: orange; }"
			"QToolButton{ color:black; background-color: gray; font-size: 23px; font-weight: bold; }"
			);
	}

protected:

private:

};

class UICOMPONENT_EXPORT MyPushButton : public QPushButton
{
	Q_OBJECT
public:
	MyPushButton(QString name = "")
	{
		this->setText(name);
		this->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
		this->setCursor(Qt::PointingHandCursor);
		this->setMinimumHeight(35);
		this->setStyleSheet("QPushButton {font-size: 20px; font-weight: bold; color: white; background-color: #a0a0a0; }"
						    "QPushButton:hover {font-size: 20px; font-weight: bold; color: black; background-color: green;}");
		
		this->adjustSize();
	}
};

class UICOMPONENT_EXPORT FriendListWidgetItem : public QWidget
{
	Q_OBJECT

public:
	enum FriendStatus { NOCONNECT = 0, CONECTED, PLAY };
	FriendListWidgetItem(const QString id, FriendStatus status)
	{
		lb_id_ = new  QLabel();
		lb_id_->setText(id);

		status_label_ = new QLabel();

		profile_label_ = new QLabel();
		profile_label_->setPixmap(QPixmap(":/MyGameLauncher/resource/profile.png").scaled(52, 52));
		initLayout();
		setFriendStatus(status);
	}
	~FriendListWidgetItem() {}

	void setFriendStatus(FriendStatus status)
	{
		QString txt = "";
		switch (status)
		{
		case FriendListWidgetItem::NOCONNECT:
			txt = "No Connect";
			break;
		case FriendListWidgetItem::CONECTED:
			txt = "Connected";
			break;
		case FriendListWidgetItem::PLAY:
			txt = "play game";
			break;
		default:
			break;
		}
		if (status_label_ == nullptr)
			status_label_ = new QLabel;

		status_label_->setText(txt);

	}
	void initLayout()
	{
		this->setStyleSheet("font-size: 17px; background-color:gray; color:black; border: 1px solid orange;");
		this->setMinimumHeight(35);
		this->setAttribute(Qt::WA_Hover);
		this->setMouseTracking(true);

		QVBoxLayout* info_lay = new QVBoxLayout;
		info_lay->setContentsMargins(0,0,0,0);
		info_lay->setSpacing(0); //¿ì¼± 0
		
		info_lay->addWidget(lb_id_);
		info_lay->addWidget(status_label_);
		
		QHBoxLayout* main_lay = new QHBoxLayout;
		main_lay->setContentsMargins(0, 0, 0, 0);
		main_lay->setSpacing(0);
		main_lay->addWidget(profile_label_);
		main_lay->addLayout(info_lay);

		this->setLayout(main_lay);
	}
signals:
	void sigClicked();
protected:
	virtual void mouseDoubleClickEvent(QMouseEvent* event) 
	{
		QWidget::mouseDoubleClickEvent(event);
		if (event->button() == Qt::LeftButton)
		{
			emit sigClicked();
		}
	}
	virtual void mouseMoveEvent(QMouseEvent* event)
	{
	}
	virtual bool event(QEvent* event) override
	{
		if (event->type() == QEvent::HoverEnter)
		{
			this->setStyleSheet("font-size: 17px; background-color:#4287f5; color:black; border: 1px solid red; font-weight: bold;");
			this->setCursor(Qt::PointingHandCursor);
		}
		else if (event->type() == QEvent::HoverLeave)
		{
			this->setStyleSheet("font-size: 17px; background-color:gray; color:black; border: 1px solid orange;");
			this->setCursor(Qt::ArrowCursor);
		}
		return QWidget::event(event);
	}
private:
	QLabel* profile_label_ = nullptr;
	QLabel* status_label_ = nullptr;
	QLabel* lb_id_ = nullptr;
};

class UICOMPONENT_EXPORT MyMessageBox : public QDialog
{
	Q_OBJECT
	
public:
	enum MsgButtonType { ONE = 0, TWO, THREE };
	MyMessageBox(const QString& title, const QString& msg, MsgButtonType type = ONE) {
		this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
		this->setStyleSheet("QWidget {background-color: #2e2da6;}");
		auto titlebar_label = new QLabel();
		titlebar_label->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
		titlebar_label->setStyleSheet("font-size:38px; font-weight:bold; color:gray; background-color:#151482;");
		titlebar_label->setText(title);

		auto msg_label = new QLabel();
		msg_label->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
		msg_label->setStyleSheet("font-size:20px; font-weight:bold; color:white;");
		msg_label->setAlignment(Qt::AlignCenter);
		msg_label->setText(msg);

		auto button_lay = new QHBoxLayout;
		auto vbuttons = createButtonType(type);
		for (auto i : vbuttons)
		{
			button_lay->addWidget(i, 1);
		}
		button_widget_ = new QWidget;
		button_widget_->setLayout(button_lay);

		auto lay = new QVBoxLayout();
		lay->setContentsMargins(0, 0, 0, 0);
		lay->setSpacing(12);
		lay->addWidget(titlebar_label);
		lay->addWidget(msg_label);
		lay->addWidget(button_widget_);

		this->setLayout(lay);
		this->resize(275, 170);
	}
	void hideButton() { button_widget_->hide(); }
	QVector<MyPushButton*> createButtonType(MsgButtonType type)
	{
		QVector<MyPushButton*> vbts;
		vbts.reserve(3);

		for (int i = 0; i < static_cast<int>(type + 1); ++i)
		{
			auto button = new MyPushButton();
			if (i == 0)
			{
				button->setText("OK");
				connect(button, &MyPushButton::clicked, [=]() { this->accept(); });
			}
			else if (i == 1)
			{
				button->setText("Cancel");
				connect(button, &MyPushButton::clicked, [=]() { this->reject(); });
			}
			else
			{
				button->setText("Apply");
				connect(button, &MyPushButton::clicked, [=]() { this->accept(); });
			}
			vbts.push_back(button);
		}
		return vbts;
	}
	~MyMessageBox() {}

private:
	QWidget* button_widget_ = nullptr;
};


