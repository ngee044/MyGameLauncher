#pragma once

#include <QWidget>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <qdatetime.h>
#include <QDate>
#include <QLabel>
#include "ui_ChatWidget.h"

#include "AccountManager.h"

class TextContents : public QWidget
{
	Q_OBJECT
public:
	//User Info Class 추가하여 내용 추가해야함
	TextContents(QString text, USER user) : text_(text), icon_image_(user.icon_image_) { initLayout(); }
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

		user_id_and_time_ = new QLabel;
		text_layout_->addWidget(user_id_and_time_);

		user_icon_image_ = new QLabel;
		user_icon_image_->setPixmap(icon_image_);

		main_lay->addWidget(user_icon_image_, 1);
		main_lay->addLayout(text_layout_, 1);
	}

private:
	QString text_;
	QVBoxLayout* text_layout_ = nullptr;
	QDate date_;

	QLabel* user_icon_image_ = nullptr;
	QPixmap icon_image_;
	QLabel* user_id_and_time_ = nullptr;
};

class ChatWidget : public QWidget
{
	Q_OBJECT

public:
	ChatWidget(QWidget *parent = Q_NULLPTR);
	~ChatWidget();

private:
	Ui::ChatWidget ui;
};
