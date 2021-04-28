#pragma once

#include <QWidget>
#include "ui_FriendWidgetItem.h"

class FriendWidgetItem : public QWidget
{
	Q_OBJECT

public:
	FriendWidgetItem(QWidget *parent = Q_NULLPTR);
	~FriendWidgetItem();

private:
	Ui::FriendWidgetItem ui;
};
