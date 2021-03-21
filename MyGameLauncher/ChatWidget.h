#pragma once

#include <QWidget>
#include "ui_ChatWidget.h"

class ChatWidget : public QWidget
{
	Q_OBJECT

public:
	ChatWidget(QWidget *parent = Q_NULLPTR);
	~ChatWidget();

private:
	Ui::ChatWidget ui;
};
