#pragma once

#include <QWidget>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <qdatetime.h>
#include <QDate>
#include <QLabel>
#include "ui_ChatWidget.h"

class TextContents : public QWidget
{
	Q_OBJECT
public:
	//User Info Class 추가하여 내용 추가해야함
	TextContents(QString text, bool mine) : text_(text), mine_(mine) { initLayout(); }
	~TextContents();

	void createTextLabel()
	{
		if (text_layout_ == nullptr)
			text_layout_ = new QVBoxLayout();

		auto text_label = new QLabel;
		text_label->setText(text_);
		text_label->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
		
		QFontMetrics fm(this->font());
		text_label->setBaseSize(QSize(fm.width(text_), text_label->height()));
		text_layout_->addWidget(text_label, 1);
	}
protected:
	void initLayout()
	{
		text_layout_ = new QVBoxLayout();
		auto main_lay = new QHBoxLayout;
		
		QString date;
		date.sprintf("%02d:%02d", QTime::currentTime().hour(), QTime::currentTime().minute());
		user_id_and_time_ = new QLabel;
		//user_id_and_time_->setText(user_info_.nick_name_ + " " + date);
		text_layout_->addWidget(user_id_and_time_);

		user_icon_image_ = new QLabel;
		//user_icon_image_->setPixmap(user_info_.icon_image_);

		main_lay->addWidget(user_icon_image_, 1);
		main_lay->addLayout(text_layout_, 1);
	}
	void addTextLabel()
	{

	}
private:
	bool mine_;
	QString text_;
	QVBoxLayout* text_layout_ = nullptr;
	QDate date_;

	QLabel* user_icon_image_ = nullptr;
	QPixmap icon_image_;
	QLabel* user_id_and_time_ = nullptr;
};

class FriendContents : public QWidget
{
	Q_OBJECT
public:
	FriendContents(const QString& name, const QPixmap& profile_pix, bool isMyPlayer) 
	{
		QString color = isMyPlayer ? "#5c55ad" : "#3b3299";
		this->setStyleSheet(QString("QLabel { color: white; background-color:#7671ad; } QWidget { background-color: %1; }").arg(color));
		this->setMinimumSize(125, 40);

		label_profile_ = new QLabel;
		label_profile_->setBaseSize(52, 52);
		label_profile_->setPixmap(profile_pix);

		label_name_ = new QLabel;
		label_name_->setText(name);
		
		QHBoxLayout* layout = new QHBoxLayout;

		layout->addWidget(label_profile_,1);
		layout->addWidget(label_name_,5);

		this->setLayout(layout);
	}
	~FriendContents() 
	{
		delete label_profile_;
		delete label_name_;
	}

private:
	QLabel* label_profile_ = nullptr;
	QLabel* label_name_ = nullptr;
};

class ChatWidget : public QWidget
{
	Q_OBJECT

public:
	ChatWidget(QWidget *parent = Q_NULLPTR);
	~ChatWidget();

	void initLayout();
	void connections();

	void setFriendWidgetList();
	void setTextEdit(const QString& txt);

public slots:
	void slotEnterKey();

private:
	Ui::ChatWidget ui;

	QVector<FriendContents*> v_friend_widget_;
	QVector<TextContents*> v_text_contents_;
};
