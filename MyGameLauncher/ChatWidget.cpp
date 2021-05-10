#include <QDebug>
#include "ChatWidget.h"

ChatWidget::ChatWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	initLayout();
	connections();
}

ChatWidget::~ChatWidget()
{
	for (auto i : v_friend_widget_)
	{
		delete i;
	}
	v_friend_widget_.clear();

	for (auto i : v_text_contents_)
	{
		delete i;
	}
	v_text_contents_.clear();
}

void ChatWidget::initLayout()
{
	this->setStyleSheet("#ChatWidget { background-color:#42a1f5; }");
	ui.main_chat_widget_->setStyleSheet("#main_chat_widget_ { border:1px solid #2b2299; background-color: #4334eb; }");
	ui.friend_list_widget_->setStyleSheet("#friend_list_widget_ { border:1px solid #2b2299; background-color: #4334eb;}");
	ui.pushButton_enter_->setStyleSheet("QPushButton:hover{ color:white; background-color: orange; }"
		"QPushButton{ color:black; background-color: gray; font-size: 23px; font-weight: bold; }");

}

void ChatWidget::connections()
{
	connect(ui.toolButton, &QToolButton::clicked, this, [=]() { this->close(); });
	connect(ui.pushButton_enter_, &QPushButton::clicked, this, &ChatWidget::slotEnterKey);
}

void ChatWidget::slotEnterKey()
{
	qDebug() << __func__;
}

void ChatWidget::setFriendWidgetList()
{
	//TODO.....
	//친구창 리스트 셋
}

void ChatWidget::setTextEdit(const QString& txt)
{
	//TODO .......
	//텍스트 창에 채팅 기존 내용 채우기
}

