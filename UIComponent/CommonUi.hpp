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
class UICOMPONENT_EXPORT MyMessageBox : public QDialog
{
	Q_OBJECT
	
public:
	enum MsgButtonType { ONE, TWO, THREE };
	MyMessageBox(const QString& title, const QString& msg, MsgButtonType type = ONE) {
		this->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
		this->setStyleSheet("QLabel {background-color: #a0a0a0;}");
		auto titlebar_label = new QLabel();
		titlebar_label->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
		titlebar_label->setStyleSheet("font-size:38px; font-weight:bold; color:gray;");
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
		auto lay = new QVBoxLayout();
		lay->setContentsMargins(0, 0, 0, 0);
		lay->setSpacing(12);
		lay->addWidget(titlebar_label);
		lay->addWidget(msg_label);
		lay->addLayout(button_lay);

		this->setLayout(lay);
	}
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
};


